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
     NAME = 1707,
     UMINUS = 1708,
     COMMA = 1613,
     KW_OR = 1653,
     KW_AND = 1608,
     KW_USING = 1545,
     NOT = 1628,
     MATCHES = 1425,
     POWER = 1531,
     LESS_THAN = 1527,
     GREATER_THAN = 1442,
     EQUAL = 1603,
     GREATER_THAN_EQ = 1343,
     LESS_THAN_EQ = 1400,
     NOT_EQUAL = 1473,
     PLUS = 1639,
     MINUS = 1626,
     MULTIPLY = 1532,
     DIVIDE = 1559,
     MOD = 1627,
     COMMAND = 1407,
     NUMBER_VALUE = 1709,
     CHAR_VALUE = 1710,
     INT_VALUE = 1711,
     NAMED_GEN = 1712,
     CLINE = 1713,
     SQLLINE = 1714,
     KW_CSTART = 1715,
     KW_CEND = 1716,
     USER_DTYPE = 1717,
     SQL_TEXT = 1718,
     KW_WHENEVER_SET = 1719,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     BEFORE_INSERT = 1004,
     CONCAT_PIPES = 1005,
     BEFORE_DELETE = 1006,
     DROP_TRIGGER = 1007,
     AFTER_INSERT = 1008,
     AFTER_DELETE = 1009,
     EXECUTE_IMMEDIATE = 1010,
     DELETE_ROW_EQUAL_TRUE = 1011,
     INSERT_ROW_EQUAL_TRUE = 1012,
     DELETE_ROW_EQUAL_FALSE = 1013,
     INSERT_ROW_EQUAL_FALSE = 1014,
     CURRENT_ROW_DISPLAY_EQUAL = 1015,
     MAXCOUNT = 1016,
     ALTER_TABLE = 1017,
     ALTER_INDEX = 1018,
     NEXT_SIZE = 1019,
     DISPLAY_ATTR_FORM = 1020,
     DISPLAY_ATTR_WINDOW = 1021,
     INPUT_ATTR_FORM = 1022,
     INPUT_ATTR_WINDOW = 1023,
     WHENEVER_ERROR_CONTINUE = 1024,
     WHENEVER_ANY_ERROR_CONTINUE = 1025,
     WHENEVER_WARNING_CONTINUE = 1026,
     WHENEVER_SQLSUCCESS_CONTINUE = 1027,
     WHENEVER_SQLWARNING_CONTINUE = 1028,
     WHENEVER_NOT_FOUND_CONTINUE = 1029,
     WHENEVER_SQLERROR_CONTINUE = 1030,
     WHENEVER_SUCCESS_CONTINUE = 1031,
     WHENEVER_ERROR_GOTO = 1032,
     WHENEVER_ANY_ERROR_GOTO = 1033,
     WHENEVER_WARNING_GOTO = 1034,
     WHENEVER_SQLSUCCESS_GOTO = 1035,
     WHENEVER_SQLWARNING_GOTO = 1036,
     WHENEVER_NOT_FOUND_GOTO = 1037,
     WHENEVER_SQLERROR_GOTO = 1038,
     WHENEVER_SUCCESS_GOTO = 1039,
     WHENEVER_ERROR_CALL = 1040,
     WHENEVER_ANY_ERROR_CALL = 1041,
     WHENEVER_WARNING_CALL = 1042,
     WHENEVER_SQLSUCCESS_CALL = 1043,
     WHENEVER_SQLWARNING_CALL = 1044,
     WHENEVER_NOT_FOUND_CALL = 1045,
     WHENEVER_SQLERROR_CALL = 1046,
     WHENEVER_SUCCESS_CALL = 1047,
     WHENEVER_ERROR_STOP = 1048,
     WHENEVER_ANY_ERROR_STOP = 1049,
     WHENEVER_WARNING_STOP = 1050,
     WHENEVER_SQLSUCCESS_STOP = 1051,
     WHENEVER_SQLWARNING_STOP = 1052,
     WHENEVER_NOT_FOUND_STOP = 1053,
     WHENEVER_SQLERROR_STOP = 1054,
     WHENEVER_SUCCESS_STOP = 1055,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1056,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1057,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1058,
     XSET_MULTIPLY_EQUAL = 1059,
     XSET_OPEN_BRACKET = 1060,
     NEWFORMATSHARED = 1061,
     CREATE_DATABASE = 1062,
     DROP_DATABASE = 1063,
     IMPORT_LEGACY_FUNCTION = 1064,
     ADD_CONSTRAINT = 1065,
     DROP_CONSTRAINT = 1066,
     DROP_SYNONYM = 1067,
     CONSTRAINT = 1068,
     AS_STATIC = 1069,
     NOT_FIELD_TOUCHED = 1070,
     LOCAL_FUNCTION = 1071,
     EVERY_ROW = 1072,
     ELIF = 1073,
     DOUBLE_PRECISION = 1074,
     COUNT_MULTIPLY = 1075,
     WAIT_FOR_KEY = 1076,
     AT_TERMINATION_CALL = 1077,
     TERMINATE_REPORT = 1078,
     TO_MAIN_CAPTION = 1079,
     CLEARSTAT = 1080,
     TO_MENUITEM = 1081,
     ID_TO_INT = 1082,
     TO_STATUSBOX = 1083,
     ASCII_HEIGHT_ALL = 1084,
     ASCII_WIDTH_ALL = 1085,
     IMPORT_DATATYPE = 1086,
     PAGE_TRAILER_SIZE = 1087,
     PAGE_HEADER_SIZE = 1088,
     FIRST_PAGE_HEADER_SIZE = 1089,
     BYTES_USE_AS_IMAGE = 1090,
     BYTES_USE_AS_ASCII = 1091,
     KWUP_BY = 1092,
     KWDOWN_BY = 1093,
     CLOSE_STATUSBOX = 1094,
     MODIFY_NEXT_SIZE = 1095,
     LOCK_MODE_PAGE = 1096,
     LOCK_MODE_ROW = 1097,
     TO_PIPE = 1098,
     TO_PRINTER = 1099,
     STATUSBOX = 1100,
     FORMHANDLER_INPUT = 1101,
     UNITS_YEAR = 1102,
     UNITS_MONTH = 1103,
     UNITS_DAY = 1104,
     UNITS_HOUR = 1105,
     UNITS_MINUTE = 1106,
     UNITS_SECOND = 1107,
     NO_NEW_LINES = 1108,
     FIELDTOWIDGET = 1109,
     WITH_HOLD = 1110,
     SHOW_MENU = 1111,
     TO_CLUSTER = 1112,
     TO_NOT_CLUSTER = 1113,
     CWIS = 1114,
     CREATE_IDX = 1115,
     FORM_IS_COMPILED = 1116,
     PDF_REPORT = 1117,
     IMPORT_FUNCTION = 1118,
     PROMPT_MANY = 1119,
     POINTS = 1120,
     MM = 1121,
     INCHES = 1122,
     PREPEND = 1123,
     MEMBER_OF = 1124,
     MEMBER_FUNCTION = 1125,
     APPEND = 1126,
     TEMPLATE = 1127,
     END_TEMPLATE = 1128,
     SQLSICS = 1129,
     CREATE_SCHEMA = 1130,
     SQLSIRR = 1131,
     UPDATESTATS_T = 1132,
     SQLSICR = 1133,
     WHENEVER_SQLSUCCESS = 1134,
     WHENEVER_SQLWARNING = 1135,
     WHENEVER_ANY_ERROR = 1136,
     WHENEVER_NOT_FOUND = 1137,
     WHENEVER_SQLERROR = 1138,
     WHENEVER_SUCCESS = 1139,
     WHENEVER_ERROR = 1140,
     START_EXTERN = 1141,
     CONTINUE_CONSTRUCT = 1142,
     FOUNCONSTR = 1143,
     SQLSIDR = 1144,
     CREATE_TEMP_TABLE = 1145,
     CURRENT_WINDOW_IS = 1146,
     FIRST_PAGE_HEADER = 1147,
     ORDER_EXTERNAL_BY = 1148,
     SCROLL_CURSOR_FOR = 1149,
     SCROLL_CURSOR = 1150,
     SQL_INTERRUPT_OFF = 1151,
     STOP_ALL_EXTERNAL = 1152,
     WITH_CHECK_OPTION = 1153,
     WITH_GRANT_OPTION = 1154,
     SQLSLMNW = 1155,
     ADDCONSTUNIQ = 1156,
     CONTINUE_DISPLAY = 1157,
     CONTINUE_FOREACH = 1158,
     OUTPUT_TO_REPORT = 1159,
     SQL_INTERRUPT_ON = 1160,
     WHERE_CURRENT_OF = 1161,
     WITHOUT_DEFAULTS = 1162,
     FOCONSTR = 1163,
     SCALED_BY = 1164,
     CONTINUE_PROMPT = 1165,
     PDF_FUNCTION = 1166,
     DEFER_INTERRUPT = 1167,
     DISPLAY_BY_NAME = 1168,
     NOT_NULL_UNIQUE = 1169,
     SKIP_TO_TOP = 1170,
     TOP_OF_PAGE = 1171,
     SKIP_TO = 1172,
     SKIP_BY = 1173,
     WITHOUT_WAITING = 1174,
     BEFCONSTRUCT = 1175,
     SQLSLMW = 1176,
     AFTCONSTRUCT = 1177,
     ALL_PRIVILEGES = 1178,
     CLOSE_DATABASE = 1179,
     CONTINUE_INPUT = 1180,
     CONTINUE_WHILE = 1181,
     CREATE_SYNONYM = 1182,
     DROP_TABLE = 1183,
     EXIT_CONSTRUCT = 1184,
     INEXCLUSIVE = 1185,
     REPORT_TO_PRINTER = 1186,
     REPORT_TO_PIPE = 1187,
     RETURN = 1188,
     SET_SESSION_TO = 1189,
     UPDATESTATS = 1190,
     WITHOUT_HEAD = 1191,
     CLEARSCR = 1192,
     WITH_B_LOG = 1193,
     AUTHORIZATION = 1194,
     BOTTOM_MARGIN = 1195,
     CLOSE_SESSION = 1196,
     CONTINUE_CASE = 1197,
     CONTINUE_MENU = 1198,
     DISPLAY_ARRAY = 1199,
     END_SQL = 1200,
     DOLLAR = 1201,
     END_CONSTRUCT = 1202,
     FIELD_TOUCHED = 1203,
     FINISH_REPORT = 1204,
     INFACC = 1205,
     INPUT_NO_WRAP = 1206,
     SETPMOFF = 1207,
     UNCONSTRAINED = 1208,
     PAGE_TRAILER = 1209,
     SETPMON = 1210,
     BEFGROUP = 1211,
     CLOSE_WINDOW = 1212,
     COMMENT_LINE = 1213,
     CONTINUE_FOR = 1214,
     CREATE_DB = 1215,
     CREATE_TABLE = 1216,
     DEFAULT_NULL = 1217,
     DEFAULT_TODAY = 1218,
     DEFAULT_USER = 1219,
     DELETE_USING = 1220,
     DISPLAY_FORM = 1221,
     END_FUNCTION = 1222,
     EXIT_DISPLAY = 1223,
     EXIT_FOREACH = 1224,
     EXIT_PROGRAM = 1225,
     INFCOLS = 1226,
     ON_EVERY_ROW = 1227,
     OPEN_SESSION = 1228,
     RIGHT_MARGIN = 1229,
     SELECT_USING = 1230,
     START_REPORT = 1231,
     UNLOCK_TABLE = 1232,
     UPDATE_USING = 1233,
     ACL_BUILTIN = 1234,
     AFTGROUP = 1235,
     INFIDX = 1236,
     INFSTAT = 1237,
     LEFT_MARGIN = 1238,
     PAGE_HEADER = 1239,
     ROLLBACK_W = 1240,
     SET_SESSION = 1241,
     SQLSEOFF = 1242,
     WITH_A_LOG = 1243,
     BEFDISP = 1244,
     BEFORE_MENU = 1245,
     CREATE_VIEW = 1246,
     DEFINE_TYPE = 1247,
     DELETE_FROM = 1248,
     END_DISPLAY = 1249,
     END_REPORT = 1250,
     END_FOREACH = 1251,
     END_FOR = 1252,
     END_GLOBALS = 1253,
     EXIT_PROMPT = 1254,
     EXTENT_SIZE = 1255,
     FOREIGN_KEY = 1256,
     HIDE_OPTION = 1257,
     HIDE_WINDOW = 1258,
     INSERT_INTO = 1259,
     IS_NOT_NULL = 1260,
     MOVE_WINDOW = 1261,
     NEXT_OPTION = 1262,
     NOT_MATCHES = 1263,
     ON_LAST_ROW = 1264,
     OPEN_WINDOW = 1265,
     OPEN_STATUSBOX = 1266,
     PAGE_LENGTH = 1267,
     PAGE_WIDTH = 1268,
     PRIMARY_KEY = 1269,
     PROMPT_LINE = 1270,
     RECORD_LIKE = 1271,
     ROLLFORWARD = 1272,
     SETBL = 1273,
     SHOW_OPTION = 1274,
     SHOW_WINDOW = 1275,
     SQLSEON = 1276,
     TO_DATABASE = 1277,
     USE_SESSION = 1278,
     WITH_NO_LOG = 1279,
     AFTDISP = 1280,
     BEFFIELD = 1281,
     INSHARE = 1282,
     UNLOCKTAB = 1283,
     AFTFIELD = 1284,
     ATTRIBUTES = 1285,
     BEFINP = 1286,
     BEGIN_WORK = 1287,
     CLEARWIN = 1288,
     CLOSE_FORM = 1289,
     DEFER_QUIT = 1290,
     DESCENDING = 1291,
     DROP_INDEX = 1292,
     END_PROMPT = 1293,
     END_RECORD = 1294,
     ERROR_LINE = 1295,
     EXIT_INPUT = 1296,
     EXIT_WHILE = 1297,
     FOR_UPDATE_OF = 1298,
     FOR_UPDATE = 1299,
     GET_FLDBUF = 1300,
     INITIALIZE = 1301,
     INPUT_WRAP = 1302,
     LOCK_TABLE = 1303,
     MSG_LINE = 1304,
     NOT_EXISTS = 1305,
     ON_ANY_KEY = 1306,
     REFERENCES = 1307,
     RENCOL = 1308,
     SET_CURSOR = 1309,
     SMALLFLOAT = 1310,
     SQLSUCCESS = 1311,
     TOP_MARGIN = 1312,
     WITH_ARRAY = 1313,
     ACCEPTKEY = 1314,
     ACCEPT = 1315,
     AFTINP = 1316,
     CLEARFORMTODEFAULTS = 1317,
     CLEARFORM = 1318,
     CLEAR_X_FORM = 1319,
     COMMIT_W = 1320,
     NEXTPAGE = 1321,
     PREVPAGE = 1322,
     CTRL_KEY = 1323,
     INFTABS = 1324,
     NEXTFIELD = 1325,
     NEXTFORM = 1326,
     RENTAB = 1327,
     ASCENDING = 1328,
     ASSOCIATE = 1329,
     CHAR = 1330,
     NCHAR = 1331,
     NVARCHAR = 1332,
     CONSTRUCT = 1333,
     DELIMITER = 1334,
     DOWNSHIFT = 1335,
     DROP_VIEW = 1336,
     END_INPUT = 1337,
     END_WHILE = 1338,
     EXCLUSIVE = 1339,
     EXIT_CASE = 1340,
     EXIT_MENU = 1341,
     FORM_LINE = 1342,
     INTERRUPT = 1344,
     INTO_TEMP = 1345,
     INVISIBLE = 1346,
     IN_MEMORY = 1347,
     LINKED_TO = 1348,
     LOAD_FROM = 1349,
     LOCKTAB = 1350,
     MENU_LINE = 1351,
     OPEN_FORM = 1352,
     OTHERWISE = 1353,
     PRECISION = 1354,
     PRIOR = 1355,
     PROCEDURE = 1356,
     REPORT_TO = 1357,
     RETURNING = 1358,
     UNDERLINE = 1359,
     UNLOAD_TO = 1360,
     BEFROW = 1361,
     UNLOAD_T = 1362,
     VARIABLE = 1363,
     ABSOLUTE = 1364,
     AFTROW = 1365,
     BUFFERED = 1366,
     CONSTANT = 1367,
     CONST = 1368,
     DATABASE = 1369,
     DATETIME = 1370,
     DEFAULTS = 1371,
     DISTINCT = 1372,
     END_CASE = 1373,
     END_MAIN = 1374,
     END_MENU = 1375,
     END_TYPE = 1376,
     EXIT_FOR = 1377,
     EXTERNAL = 1378,
     FRACTION = 1379,
     FUNCTION = 1380,
     GROUP_BY = 1381,
     INTERVAL = 1382,
     KWMESSAGE = 1383,
     NOT_LIKE = 1384,
     NOT_ILIKE = 1385,
     NOT_NULL = 1386,
     PASSWORD = 1387,
     PREVIOUS = 1388,
     READONLY = 1389,
     REGISTER = 1390,
     RELATIVE = 1391,
     RESOURCE = 1392,
     SMALLINT = 1393,
     VALIDATE = 1394,
     WITH_LOG = 1395,
     WORDWRAP = 1396,
     BY_NAME = 1397,
     IN_FILE = 1398,
     IS_NULL = 1399,
     AVERAGE = 1401,
     BETWEEN = 1402,
     CAPTION = 1403,
     CLIPPED = 1404,
     CLOSE_BRACKET = 1405,
     COLUMNS = 1406,
     COMMENT = 1408,
     CONNECT = 1409,
     CURRENT = 1410,
     DBYNAME = 1411,
     DECIMAL = 1412,
     DECLARE = 1413,
     DEFAULT = 1414,
     DISPLAY = 1415,
     ENDCODE = 1416,
     EXECUTE = 1417,
     FOREACH = 1418,
     FOREIGN = 1419,
     GLOBALS = 1420,
     INFIELD = 1421,
     INTEGER = 1422,
     KWWINDOW = 1423,
     MAGENTA = 1424,
     OPTIONS = 1426,
     PERCENT = 1427,
     PREPARE = 1428,
     PROGRAM = 1429,
     RECOVER = 1430,
     REVERSE = 1431,
     SECTION = 1432,
     SESSION = 1433,
     SYNONYM = 1434,
     THRU = 1435,
     TRAILER = 1436,
     UPSHIFT = 1437,
     VARCHAR = 1438,
     WAITING = 1439,
     CLOSE_SHEV = 1440,
     CLOSE_SQUARE = 1441,
     KW_FALSE = 1443,
     NOT_IN = 1444,
     ONKEY = 1445,
     OPEN_BRACKET = 1446,
     BORDER = 1447,
     BOTTOM = 1448,
     COLUMN = 1449,
     COMMIT = 1450,
     CREATE = 1451,
     CURSOR = 1452,
     DEFINE = 1453,
     DELETE = 1454,
     DOUBLE = 1455,
     END_IF = 1456,
     ESCAPE = 1457,
     EXISTS = 1458,
     EXTEND = 1459,
     EXTENT = 1460,
     FINISH = 1461,
     FORMAT = 1462,
     HAVING = 1463,
     HEADER = 1464,
     INSERT = 1465,
     LOCATE = 1466,
     MARGIN = 1467,
     MEMORY = 1468,
     MINUTE = 1469,
     MODIFY = 1470,
     NORMAL = 1471,
     EQUAL_EQUAL = 1472,
     OPEN_SHEV = 1474,
     OPEN_SQUARE = 1475,
     OPTION = 1476,
     OUTPUT = 1477,
     PROMPT = 1478,
     PUBLIC = 1479,
     RECORD = 1480,
     REPORT = 1481,
     REVOKE = 1482,
     SCHEMA = 1483,
     SCROLL_USING = 1484,
     SCROLL = 1485,
     SECOND = 1486,
     SELECT = 1487,
     SERIAL = 1488,
     SETL = 1489,
     SHARED = 1490,
     SPACES = 1491,
     UNIQUE = 1492,
     UNLOCK = 1493,
     UPDATE = 1494,
     VALUES = 1495,
     YELLOW = 1496,
     AFTER = 1497,
     KWLINE = 1498,
     KW_NULL = 1499,
     KW_TRUE = 1500,
     SINGLE_KEY = 1501,
     ALTER = 1502,
     ARRAY = 1503,
     ASCII = 1504,
     AUDIT = 1505,
     BLACK = 1506,
     BLINK = 1507,
     CHECK = 1508,
     CLEAR = 1509,
     CLOSE = 1510,
     CODE_C = 1511,
     COUNT = 1512,
     DEFER = 1513,
     ERROR = 1514,
     EVERY = 1515,
     FETCH = 1516,
     FIRST = 1517,
     FLOAT = 1518,
     FLUSH = 1519,
     FOUND = 1520,
     GRANT = 1521,
     GREEN = 1522,
     GROUP = 1523,
     INDEX = 1524,
     KWFORM = 1525,
     LABEL = 1526,
     LOCAL = 1528,
     MONEY = 1529,
     MONTH = 1530,
     ORDER = 1533,
     OUTER = 1534,
     PAUSE = 1535,
     PRINT_IMAGE = 1536,
     PRINT_FILE = 1537,
     PRINT = 1538,
     RIGHT = 1539,
     DOUBLE_COLON = 1540,
     SEMICOLON = 1541,
     SLEEP = 1542,
     TUPLE = 1543,
     UNION = 1544,
     WHERE = 1546,
     WHILE = 1547,
     WHITE = 1548,
     CCODE = 1549,
     ANSI = 1550,
     BLUE = 1551,
     BOLD = 1552,
     BYTE = 1553,
     FCALL = 1554,
     CASE = 1555,
     CYAN = 1556,
     DATE = 1557,
     DESC = 1558,
     KWDOWN = 1560,
     TAB = 1561,
     DROP = 1562,
     ELSE = 1563,
     EXEC = 1564,
     EXIT = 1565,
     FREE = 1566,
     FROM = 1567,
     GOTO = 1568,
     HELP_FILE = 1569,
     LANG_FILE = 1570,
     HELP = 1571,
     HIDE = 1572,
     HOUR = 1573,
     INTO = 1574,
     LAST = 1575,
     LEFT = 1576,
     LIKE = 1577,
     MAIN = 1578,
     MENU = 1579,
     MODE = 1580,
     NEED = 1581,
     NEXT = 1582,
     NOCR = 1583,
     OPEN = 1584,
     QUIT = 1585,
     REAL = 1586,
     ROWS = 1587,
     SHOW = 1588,
     SIZE = 1589,
     SKIP = 1590,
     SOME = 1591,
     STEP = 1592,
     STOP = 1593,
     TEMP = 1594,
     TEXT = 1595,
     THEN = 1596,
     USER = 1597,
     WAIT = 1598,
     WHEN = 1599,
     WITH = 1600,
     WORK = 1601,
     YEAR = 1602,
     KW_IS = 1604,
     XSET = 1605,
     ADD = 1606,
     ALL = 1607,
     ANY = 1609,
     ASC = 1610,
     AVG = 1611,
     COLON = 1612,
     DAY = 1614,
     DBA = 1615,
     DEC = 1616,
     DIM = 1617,
     FKEY = 1618,
     FOR = 1619,
     KEY = 1620,
     KWNO = 1621,
     LET = 1622,
     LOG = 1623,
     XMAX = 1624,
     XMIN = 1625,
     PAD = 1629,
     PUT = 1630,
     RED = 1631,
     ROW = 1632,
     RUN = 1633,
     SQL = 1634,
     SUM = 1635,
     TOP = 1636,
     USE = 1637,
     ATSIGN = 1638,
     AS_TIFF = 1640,
     AS_GIF = 1641,
     AS_PNG = 1642,
     AS_JPEG = 1643,
     AS = 1644,
     AT = 1645,
     BY = 1646,
     DOT = 1647,
     GO = 1648,
     IF = 1649,
     IN = 1650,
     OF = 1651,
     ON = 1652,
     TO = 1654,
     KWUP = 1655,
     FONT_NAME = 1656,
     FONT_SIZE = 1657,
     PAPER_SIZE_IS_LETTER = 1658,
     PAPER_SIZE_IS_LEGAL = 1659,
     PAPER_SIZE_IS_A5 = 1660,
     PAPER_SIZE_IS_A4 = 1661,
     PAPER_SIZE_IS_LETTER_L = 1662,
     PAPER_SIZE_IS_LEGAL_L = 1663,
     PAPER_SIZE_IS_A5_L = 1664,
     PAPER_SIZE_IS_A4_L = 1665,
     FORMHANDLER = 1666,
     END_FORMHANDLER = 1667,
     BEFORE_EVENT = 1668,
     BEFORE_OPEN_FORM = 1669,
     AFTER_EVENT = 1670,
     BEFORE_CLOSE_FORM = 1671,
     BEFORE_ANY = 1672,
     AFTER_ANY = 1673,
     MENUHANDLER = 1674,
     END_MENUHANDLER = 1675,
     BEFORE_SHOW_MENU = 1676,
     DISABLE_PROGRAM = 1677,
     DISABLE_ALL = 1678,
     BUTTONS = 1679,
     CHECK_MENUITEM = 1680,
     DISABLE_FORM = 1681,
     DISABLE_MENUITEMS = 1682,
     DISABLE = 1683,
     ENABLE_FORM = 1684,
     ENABLE_MENUITEMS = 1685,
     ENABLE = 1686,
     KWFIELD = 1687,
     ICON = 1688,
     MESSAGEBOX = 1689,
     TO_DEFAULTS = 1690,
     UNCHECK_MENUITEM = 1691,
     BEFORE = 1692,
     INPUT = 1693,
     END = 1694,
     INT_TO_ID = 1695,
     TIMEOUT = 1696,
     OFF = 1697,
     WITH_1_DIMENSION = 1698,
     WITH_2_DIMENSION = 1699,
     WITH_3_DIMENSION = 1700,
     TILDE = 1701,
     ILIKE = 1702,
     FGL_ISDYNARR_ALLOCATED = 1703,
     FGL_DYNARR_EXTENTSIZE = 1704,
     FILLFACTOR = 1705
   };
#endif
#define NAME 1707
#define UMINUS 1708
#define COMMA 1613
#define KW_OR 1653
#define KW_AND 1608
#define KW_USING 1545
#define NOT 1628
#define MATCHES 1425
#define POWER 1531
#define LESS_THAN 1527
#define GREATER_THAN 1442
#define EQUAL 1603
#define GREATER_THAN_EQ 1343
#define LESS_THAN_EQ 1400
#define NOT_EQUAL 1473
#define PLUS 1639
#define MINUS 1626
#define MULTIPLY 1532
#define DIVIDE 1559
#define MOD 1627
#define COMMAND 1407
#define NUMBER_VALUE 1709
#define CHAR_VALUE 1710
#define INT_VALUE 1711
#define NAMED_GEN 1712
#define CLINE 1713
#define SQLLINE 1714
#define KW_CSTART 1715
#define KW_CEND 1716
#define USER_DTYPE 1717
#define SQL_TEXT 1718
#define KW_WHENEVER_SET 1719
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define BEFORE_INSERT 1004
#define CONCAT_PIPES 1005
#define BEFORE_DELETE 1006
#define DROP_TRIGGER 1007
#define AFTER_INSERT 1008
#define AFTER_DELETE 1009
#define EXECUTE_IMMEDIATE 1010
#define DELETE_ROW_EQUAL_TRUE 1011
#define INSERT_ROW_EQUAL_TRUE 1012
#define DELETE_ROW_EQUAL_FALSE 1013
#define INSERT_ROW_EQUAL_FALSE 1014
#define CURRENT_ROW_DISPLAY_EQUAL 1015
#define MAXCOUNT 1016
#define ALTER_TABLE 1017
#define ALTER_INDEX 1018
#define NEXT_SIZE 1019
#define DISPLAY_ATTR_FORM 1020
#define DISPLAY_ATTR_WINDOW 1021
#define INPUT_ATTR_FORM 1022
#define INPUT_ATTR_WINDOW 1023
#define WHENEVER_ERROR_CONTINUE 1024
#define WHENEVER_ANY_ERROR_CONTINUE 1025
#define WHENEVER_WARNING_CONTINUE 1026
#define WHENEVER_SQLSUCCESS_CONTINUE 1027
#define WHENEVER_SQLWARNING_CONTINUE 1028
#define WHENEVER_NOT_FOUND_CONTINUE 1029
#define WHENEVER_SQLERROR_CONTINUE 1030
#define WHENEVER_SUCCESS_CONTINUE 1031
#define WHENEVER_ERROR_GOTO 1032
#define WHENEVER_ANY_ERROR_GOTO 1033
#define WHENEVER_WARNING_GOTO 1034
#define WHENEVER_SQLSUCCESS_GOTO 1035
#define WHENEVER_SQLWARNING_GOTO 1036
#define WHENEVER_NOT_FOUND_GOTO 1037
#define WHENEVER_SQLERROR_GOTO 1038
#define WHENEVER_SUCCESS_GOTO 1039
#define WHENEVER_ERROR_CALL 1040
#define WHENEVER_ANY_ERROR_CALL 1041
#define WHENEVER_WARNING_CALL 1042
#define WHENEVER_SQLSUCCESS_CALL 1043
#define WHENEVER_SQLWARNING_CALL 1044
#define WHENEVER_NOT_FOUND_CALL 1045
#define WHENEVER_SQLERROR_CALL 1046
#define WHENEVER_SUCCESS_CALL 1047
#define WHENEVER_ERROR_STOP 1048
#define WHENEVER_ANY_ERROR_STOP 1049
#define WHENEVER_WARNING_STOP 1050
#define WHENEVER_SQLSUCCESS_STOP 1051
#define WHENEVER_SQLWARNING_STOP 1052
#define WHENEVER_NOT_FOUND_STOP 1053
#define WHENEVER_SQLERROR_STOP 1054
#define WHENEVER_SUCCESS_STOP 1055
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1056
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1057
#define XSET_ident_DOT_MULTIPLY_EQUAL 1058
#define XSET_MULTIPLY_EQUAL 1059
#define XSET_OPEN_BRACKET 1060
#define NEWFORMATSHARED 1061
#define CREATE_DATABASE 1062
#define DROP_DATABASE 1063
#define IMPORT_LEGACY_FUNCTION 1064
#define ADD_CONSTRAINT 1065
#define DROP_CONSTRAINT 1066
#define DROP_SYNONYM 1067
#define CONSTRAINT 1068
#define AS_STATIC 1069
#define NOT_FIELD_TOUCHED 1070
#define LOCAL_FUNCTION 1071
#define EVERY_ROW 1072
#define ELIF 1073
#define DOUBLE_PRECISION 1074
#define COUNT_MULTIPLY 1075
#define WAIT_FOR_KEY 1076
#define AT_TERMINATION_CALL 1077
#define TERMINATE_REPORT 1078
#define TO_MAIN_CAPTION 1079
#define CLEARSTAT 1080
#define TO_MENUITEM 1081
#define ID_TO_INT 1082
#define TO_STATUSBOX 1083
#define ASCII_HEIGHT_ALL 1084
#define ASCII_WIDTH_ALL 1085
#define IMPORT_DATATYPE 1086
#define PAGE_TRAILER_SIZE 1087
#define PAGE_HEADER_SIZE 1088
#define FIRST_PAGE_HEADER_SIZE 1089
#define BYTES_USE_AS_IMAGE 1090
#define BYTES_USE_AS_ASCII 1091
#define KWUP_BY 1092
#define KWDOWN_BY 1093
#define CLOSE_STATUSBOX 1094
#define MODIFY_NEXT_SIZE 1095
#define LOCK_MODE_PAGE 1096
#define LOCK_MODE_ROW 1097
#define TO_PIPE 1098
#define TO_PRINTER 1099
#define STATUSBOX 1100
#define FORMHANDLER_INPUT 1101
#define UNITS_YEAR 1102
#define UNITS_MONTH 1103
#define UNITS_DAY 1104
#define UNITS_HOUR 1105
#define UNITS_MINUTE 1106
#define UNITS_SECOND 1107
#define NO_NEW_LINES 1108
#define FIELDTOWIDGET 1109
#define WITH_HOLD 1110
#define SHOW_MENU 1111
#define TO_CLUSTER 1112
#define TO_NOT_CLUSTER 1113
#define CWIS 1114
#define CREATE_IDX 1115
#define FORM_IS_COMPILED 1116
#define PDF_REPORT 1117
#define IMPORT_FUNCTION 1118
#define PROMPT_MANY 1119
#define POINTS 1120
#define MM 1121
#define INCHES 1122
#define PREPEND 1123
#define MEMBER_OF 1124
#define MEMBER_FUNCTION 1125
#define APPEND 1126
#define TEMPLATE 1127
#define END_TEMPLATE 1128
#define SQLSICS 1129
#define CREATE_SCHEMA 1130
#define SQLSIRR 1131
#define UPDATESTATS_T 1132
#define SQLSICR 1133
#define WHENEVER_SQLSUCCESS 1134
#define WHENEVER_SQLWARNING 1135
#define WHENEVER_ANY_ERROR 1136
#define WHENEVER_NOT_FOUND 1137
#define WHENEVER_SQLERROR 1138
#define WHENEVER_SUCCESS 1139
#define WHENEVER_ERROR 1140
#define START_EXTERN 1141
#define CONTINUE_CONSTRUCT 1142
#define FOUNCONSTR 1143
#define SQLSIDR 1144
#define CREATE_TEMP_TABLE 1145
#define CURRENT_WINDOW_IS 1146
#define FIRST_PAGE_HEADER 1147
#define ORDER_EXTERNAL_BY 1148
#define SCROLL_CURSOR_FOR 1149
#define SCROLL_CURSOR 1150
#define SQL_INTERRUPT_OFF 1151
#define STOP_ALL_EXTERNAL 1152
#define WITH_CHECK_OPTION 1153
#define WITH_GRANT_OPTION 1154
#define SQLSLMNW 1155
#define ADDCONSTUNIQ 1156
#define CONTINUE_DISPLAY 1157
#define CONTINUE_FOREACH 1158
#define OUTPUT_TO_REPORT 1159
#define SQL_INTERRUPT_ON 1160
#define WHERE_CURRENT_OF 1161
#define WITHOUT_DEFAULTS 1162
#define FOCONSTR 1163
#define SCALED_BY 1164
#define CONTINUE_PROMPT 1165
#define PDF_FUNCTION 1166
#define DEFER_INTERRUPT 1167
#define DISPLAY_BY_NAME 1168
#define NOT_NULL_UNIQUE 1169
#define SKIP_TO_TOP 1170
#define TOP_OF_PAGE 1171
#define SKIP_TO 1172
#define SKIP_BY 1173
#define WITHOUT_WAITING 1174
#define BEFCONSTRUCT 1175
#define SQLSLMW 1176
#define AFTCONSTRUCT 1177
#define ALL_PRIVILEGES 1178
#define CLOSE_DATABASE 1179
#define CONTINUE_INPUT 1180
#define CONTINUE_WHILE 1181
#define CREATE_SYNONYM 1182
#define DROP_TABLE 1183
#define EXIT_CONSTRUCT 1184
#define INEXCLUSIVE 1185
#define REPORT_TO_PRINTER 1186
#define REPORT_TO_PIPE 1187
#define RETURN 1188
#define SET_SESSION_TO 1189
#define UPDATESTATS 1190
#define WITHOUT_HEAD 1191
#define CLEARSCR 1192
#define WITH_B_LOG 1193
#define AUTHORIZATION 1194
#define BOTTOM_MARGIN 1195
#define CLOSE_SESSION 1196
#define CONTINUE_CASE 1197
#define CONTINUE_MENU 1198
#define DISPLAY_ARRAY 1199
#define END_SQL 1200
#define DOLLAR 1201
#define END_CONSTRUCT 1202
#define FIELD_TOUCHED 1203
#define FINISH_REPORT 1204
#define INFACC 1205
#define INPUT_NO_WRAP 1206
#define SETPMOFF 1207
#define UNCONSTRAINED 1208
#define PAGE_TRAILER 1209
#define SETPMON 1210
#define BEFGROUP 1211
#define CLOSE_WINDOW 1212
#define COMMENT_LINE 1213
#define CONTINUE_FOR 1214
#define CREATE_DB 1215
#define CREATE_TABLE 1216
#define DEFAULT_NULL 1217
#define DEFAULT_TODAY 1218
#define DEFAULT_USER 1219
#define DELETE_USING 1220
#define DISPLAY_FORM 1221
#define END_FUNCTION 1222
#define EXIT_DISPLAY 1223
#define EXIT_FOREACH 1224
#define EXIT_PROGRAM 1225
#define INFCOLS 1226
#define ON_EVERY_ROW 1227
#define OPEN_SESSION 1228
#define RIGHT_MARGIN 1229
#define SELECT_USING 1230
#define START_REPORT 1231
#define UNLOCK_TABLE 1232
#define UPDATE_USING 1233
#define ACL_BUILTIN 1234
#define AFTGROUP 1235
#define INFIDX 1236
#define INFSTAT 1237
#define LEFT_MARGIN 1238
#define PAGE_HEADER 1239
#define ROLLBACK_W 1240
#define SET_SESSION 1241
#define SQLSEOFF 1242
#define WITH_A_LOG 1243
#define BEFDISP 1244
#define BEFORE_MENU 1245
#define CREATE_VIEW 1246
#define DEFINE_TYPE 1247
#define DELETE_FROM 1248
#define END_DISPLAY 1249
#define END_REPORT 1250
#define END_FOREACH 1251
#define END_FOR 1252
#define END_GLOBALS 1253
#define EXIT_PROMPT 1254
#define EXTENT_SIZE 1255
#define FOREIGN_KEY 1256
#define HIDE_OPTION 1257
#define HIDE_WINDOW 1258
#define INSERT_INTO 1259
#define IS_NOT_NULL 1260
#define MOVE_WINDOW 1261
#define NEXT_OPTION 1262
#define NOT_MATCHES 1263
#define ON_LAST_ROW 1264
#define OPEN_WINDOW 1265
#define OPEN_STATUSBOX 1266
#define PAGE_LENGTH 1267
#define PAGE_WIDTH 1268
#define PRIMARY_KEY 1269
#define PROMPT_LINE 1270
#define RECORD_LIKE 1271
#define ROLLFORWARD 1272
#define SETBL 1273
#define SHOW_OPTION 1274
#define SHOW_WINDOW 1275
#define SQLSEON 1276
#define TO_DATABASE 1277
#define USE_SESSION 1278
#define WITH_NO_LOG 1279
#define AFTDISP 1280
#define BEFFIELD 1281
#define INSHARE 1282
#define UNLOCKTAB 1283
#define AFTFIELD 1284
#define ATTRIBUTES 1285
#define BEFINP 1286
#define BEGIN_WORK 1287
#define CLEARWIN 1288
#define CLOSE_FORM 1289
#define DEFER_QUIT 1290
#define DESCENDING 1291
#define DROP_INDEX 1292
#define END_PROMPT 1293
#define END_RECORD 1294
#define ERROR_LINE 1295
#define EXIT_INPUT 1296
#define EXIT_WHILE 1297
#define FOR_UPDATE_OF 1298
#define FOR_UPDATE 1299
#define GET_FLDBUF 1300
#define INITIALIZE 1301
#define INPUT_WRAP 1302
#define LOCK_TABLE 1303
#define MSG_LINE 1304
#define NOT_EXISTS 1305
#define ON_ANY_KEY 1306
#define REFERENCES 1307
#define RENCOL 1308
#define SET_CURSOR 1309
#define SMALLFLOAT 1310
#define SQLSUCCESS 1311
#define TOP_MARGIN 1312
#define WITH_ARRAY 1313
#define ACCEPTKEY 1314
#define ACCEPT 1315
#define AFTINP 1316
#define CLEARFORMTODEFAULTS 1317
#define CLEARFORM 1318
#define CLEAR_X_FORM 1319
#define COMMIT_W 1320
#define NEXTPAGE 1321
#define PREVPAGE 1322
#define CTRL_KEY 1323
#define INFTABS 1324
#define NEXTFIELD 1325
#define NEXTFORM 1326
#define RENTAB 1327
#define ASCENDING 1328
#define ASSOCIATE 1329
#define CHAR 1330
#define NCHAR 1331
#define NVARCHAR 1332
#define CONSTRUCT 1333
#define DELIMITER 1334
#define DOWNSHIFT 1335
#define DROP_VIEW 1336
#define END_INPUT 1337
#define END_WHILE 1338
#define EXCLUSIVE 1339
#define EXIT_CASE 1340
#define EXIT_MENU 1341
#define FORM_LINE 1342
#define INTERRUPT 1344
#define INTO_TEMP 1345
#define INVISIBLE 1346
#define IN_MEMORY 1347
#define LINKED_TO 1348
#define LOAD_FROM 1349
#define LOCKTAB 1350
#define MENU_LINE 1351
#define OPEN_FORM 1352
#define OTHERWISE 1353
#define PRECISION 1354
#define PRIOR 1355
#define PROCEDURE 1356
#define REPORT_TO 1357
#define RETURNING 1358
#define UNDERLINE 1359
#define UNLOAD_TO 1360
#define BEFROW 1361
#define UNLOAD_T 1362
#define VARIABLE 1363
#define ABSOLUTE 1364
#define AFTROW 1365
#define BUFFERED 1366
#define CONSTANT 1367
#define CONST 1368
#define DATABASE 1369
#define DATETIME 1370
#define DEFAULTS 1371
#define DISTINCT 1372
#define END_CASE 1373
#define END_MAIN 1374
#define END_MENU 1375
#define END_TYPE 1376
#define EXIT_FOR 1377
#define EXTERNAL 1378
#define FRACTION 1379
#define FUNCTION 1380
#define GROUP_BY 1381
#define INTERVAL 1382
#define KWMESSAGE 1383
#define NOT_LIKE 1384
#define NOT_ILIKE 1385
#define NOT_NULL 1386
#define PASSWORD 1387
#define PREVIOUS 1388
#define READONLY 1389
#define REGISTER 1390
#define RELATIVE 1391
#define RESOURCE 1392
#define SMALLINT 1393
#define VALIDATE 1394
#define WITH_LOG 1395
#define WORDWRAP 1396
#define BY_NAME 1397
#define IN_FILE 1398
#define IS_NULL 1399
#define AVERAGE 1401
#define BETWEEN 1402
#define CAPTION 1403
#define CLIPPED 1404
#define CLOSE_BRACKET 1405
#define COLUMNS 1406
#define COMMENT 1408
#define CONNECT 1409
#define CURRENT 1410
#define DBYNAME 1411
#define DECIMAL 1412
#define DECLARE 1413
#define DEFAULT 1414
#define DISPLAY 1415
#define ENDCODE 1416
#define EXECUTE 1417
#define FOREACH 1418
#define FOREIGN 1419
#define GLOBALS 1420
#define INFIELD 1421
#define INTEGER 1422
#define KWWINDOW 1423
#define MAGENTA 1424
#define OPTIONS 1426
#define PERCENT 1427
#define PREPARE 1428
#define PROGRAM 1429
#define RECOVER 1430
#define REVERSE 1431
#define SECTION 1432
#define SESSION 1433
#define SYNONYM 1434
#define THRU 1435
#define TRAILER 1436
#define UPSHIFT 1437
#define VARCHAR 1438
#define WAITING 1439
#define CLOSE_SHEV 1440
#define CLOSE_SQUARE 1441
#define KW_FALSE 1443
#define NOT_IN 1444
#define ONKEY 1445
#define OPEN_BRACKET 1446
#define BORDER 1447
#define BOTTOM 1448
#define COLUMN 1449
#define COMMIT 1450
#define CREATE 1451
#define CURSOR 1452
#define DEFINE 1453
#define DELETE 1454
#define DOUBLE 1455
#define END_IF 1456
#define ESCAPE 1457
#define EXISTS 1458
#define EXTEND 1459
#define EXTENT 1460
#define FINISH 1461
#define FORMAT 1462
#define HAVING 1463
#define HEADER 1464
#define INSERT 1465
#define LOCATE 1466
#define MARGIN 1467
#define MEMORY 1468
#define MINUTE 1469
#define MODIFY 1470
#define NORMAL 1471
#define EQUAL_EQUAL 1472
#define OPEN_SHEV 1474
#define OPEN_SQUARE 1475
#define OPTION 1476
#define OUTPUT 1477
#define PROMPT 1478
#define PUBLIC 1479
#define RECORD 1480
#define REPORT 1481
#define REVOKE 1482
#define SCHEMA 1483
#define SCROLL_USING 1484
#define SCROLL 1485
#define SECOND 1486
#define SELECT 1487
#define SERIAL 1488
#define SETL 1489
#define SHARED 1490
#define SPACES 1491
#define UNIQUE 1492
#define UNLOCK 1493
#define UPDATE 1494
#define VALUES 1495
#define YELLOW 1496
#define AFTER 1497
#define KWLINE 1498
#define KW_NULL 1499
#define KW_TRUE 1500
#define SINGLE_KEY 1501
#define ALTER 1502
#define ARRAY 1503
#define ASCII 1504
#define AUDIT 1505
#define BLACK 1506
#define BLINK 1507
#define CHECK 1508
#define CLEAR 1509
#define CLOSE 1510
#define CODE_C 1511
#define COUNT 1512
#define DEFER 1513
#define ERROR 1514
#define EVERY 1515
#define FETCH 1516
#define FIRST 1517
#define FLOAT 1518
#define FLUSH 1519
#define FOUND 1520
#define GRANT 1521
#define GREEN 1522
#define GROUP 1523
#define INDEX 1524
#define KWFORM 1525
#define LABEL 1526
#define LOCAL 1528
#define MONEY 1529
#define MONTH 1530
#define ORDER 1533
#define OUTER 1534
#define PAUSE 1535
#define PRINT_IMAGE 1536
#define PRINT_FILE 1537
#define PRINT 1538
#define RIGHT 1539
#define DOUBLE_COLON 1540
#define SEMICOLON 1541
#define SLEEP 1542
#define TUPLE 1543
#define UNION 1544
#define WHERE 1546
#define WHILE 1547
#define WHITE 1548
#define CCODE 1549
#define ANSI 1550
#define BLUE 1551
#define BOLD 1552
#define BYTE 1553
#define FCALL 1554
#define CASE 1555
#define CYAN 1556
#define DATE 1557
#define DESC 1558
#define KWDOWN 1560
#define TAB 1561
#define DROP 1562
#define ELSE 1563
#define EXEC 1564
#define EXIT 1565
#define FREE 1566
#define FROM 1567
#define GOTO 1568
#define HELP_FILE 1569
#define LANG_FILE 1570
#define HELP 1571
#define HIDE 1572
#define HOUR 1573
#define INTO 1574
#define LAST 1575
#define LEFT 1576
#define LIKE 1577
#define MAIN 1578
#define MENU 1579
#define MODE 1580
#define NEED 1581
#define NEXT 1582
#define NOCR 1583
#define OPEN 1584
#define QUIT 1585
#define REAL 1586
#define ROWS 1587
#define SHOW 1588
#define SIZE 1589
#define SKIP 1590
#define SOME 1591
#define STEP 1592
#define STOP 1593
#define TEMP 1594
#define TEXT 1595
#define THEN 1596
#define USER 1597
#define WAIT 1598
#define WHEN 1599
#define WITH 1600
#define WORK 1601
#define YEAR 1602
#define KW_IS 1604
#define XSET 1605
#define ADD 1606
#define ALL 1607
#define ANY 1609
#define ASC 1610
#define AVG 1611
#define COLON 1612
#define DAY 1614
#define DBA 1615
#define DEC 1616
#define DIM 1617
#define FKEY 1618
#define FOR 1619
#define KEY 1620
#define KWNO 1621
#define LET 1622
#define LOG 1623
#define XMAX 1624
#define XMIN 1625
#define PAD 1629
#define PUT 1630
#define RED 1631
#define ROW 1632
#define RUN 1633
#define SQL 1634
#define SUM 1635
#define TOP 1636
#define USE 1637
#define ATSIGN 1638
#define AS_TIFF 1640
#define AS_GIF 1641
#define AS_PNG 1642
#define AS_JPEG 1643
#define AS 1644
#define AT 1645
#define BY 1646
#define DOT 1647
#define GO 1648
#define IF 1649
#define IN 1650
#define OF 1651
#define ON 1652
#define TO 1654
#define KWUP 1655
#define FONT_NAME 1656
#define FONT_SIZE 1657
#define PAPER_SIZE_IS_LETTER 1658
#define PAPER_SIZE_IS_LEGAL 1659
#define PAPER_SIZE_IS_A5 1660
#define PAPER_SIZE_IS_A4 1661
#define PAPER_SIZE_IS_LETTER_L 1662
#define PAPER_SIZE_IS_LEGAL_L 1663
#define PAPER_SIZE_IS_A5_L 1664
#define PAPER_SIZE_IS_A4_L 1665
#define FORMHANDLER 1666
#define END_FORMHANDLER 1667
#define BEFORE_EVENT 1668
#define BEFORE_OPEN_FORM 1669
#define AFTER_EVENT 1670
#define BEFORE_CLOSE_FORM 1671
#define BEFORE_ANY 1672
#define AFTER_ANY 1673
#define MENUHANDLER 1674
#define END_MENUHANDLER 1675
#define BEFORE_SHOW_MENU 1676
#define DISABLE_PROGRAM 1677
#define DISABLE_ALL 1678
#define BUTTONS 1679
#define CHECK_MENUITEM 1680
#define DISABLE_FORM 1681
#define DISABLE_MENUITEMS 1682
#define DISABLE 1683
#define ENABLE_FORM 1684
#define ENABLE_MENUITEMS 1685
#define ENABLE 1686
#define KWFIELD 1687
#define ICON 1688
#define MESSAGEBOX 1689
#define TO_DEFAULTS 1690
#define UNCHECK_MENUITEM 1691
#define BEFORE 1692
#define INPUT 1693
#define END 1694
#define INT_TO_ID 1695
#define TIMEOUT 1696
#define OFF 1697
#define WITH_1_DIMENSION 1698
#define WITH_2_DIMENSION 1699
#define WITH_3_DIMENSION 1700
#define TILDE 1701
#define ILIKE 1702
#define FGL_ISDYNARR_ALLOCATED 1703
#define FGL_DYNARR_EXTENTSIZE 1704
#define FILLFACTOR 1705




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
#line 213 "fgl.yacc"
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
#line 1692 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1704 "y.tab.c"

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
#define YYLAST   10500

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  722
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  855
/* YYNRULES -- Number of rules. */
#define YYNRULES  2315
/* YYNRULES -- Number of states. */
#define YYNSTATES  3665

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1719

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,    15,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
      16,   434,   435,   436,   437,   438,   439,    23,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,    10,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,    13,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,    17,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,    12,   556,   557,
     558,    11,    20,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,     8,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,    21,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,    14,   627,   628,   629,   630,     7,   631,
     632,   633,   634,     5,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,    19,    22,     9,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,    18,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,     6,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,     2,     3,     4,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
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
    1486,  1492,  1500,  1505,  1512,  1513,  1517,  1519,  1521,  1526,
    1531,  1536,  1541,  1546,  1551,  1553,  1555,  1557,  1559,  1564,
    1569,  1572,  1575,  1578,  1581,  1584,  1586,  1588,  1591,  1593,
    1595,  1597,  1600,  1605,  1612,  1619,  1623,  1629,  1635,  1639,
    1641,  1643,  1647,  1649,  1653,  1655,  1659,  1660,  1661,  1673,
    1674,  1677,  1678,  1679,  1680,  1690,  1691,  1695,  1696,  1697,
    1708,  1709,  1711,  1712,  1714,  1716,  1719,  1720,  1724,  1725,
    1729,  1730,  1732,  1734,  1737,  1738,  1742,  1743,  1747,  1751,
    1753,  1758,  1762,  1764,  1768,  1770,  1774,  1776,  1780,  1782,
    1785,  1786,  1790,  1791,  1795,  1796,  1801,  1802,  1807,  1808,
    1813,  1816,  1820,  1822,  1826,  1828,  1830,  1832,  1834,  1836,
    1838,  1840,  1844,  1846,  1848,  1853,  1860,  1865,  1869,  1876,
    1880,  1887,  1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,
    1904,  1907,  1909,  1911,  1913,  1918,  1920,  1922,  1924,  1929,
    1933,  1940,  1944,  1951,  1953,  1955,  1958,  1961,  1963,  1966,
    1969,  1971,  1975,  1977,  1980,  1983,  1986,  1991,  1994,  1997,
    2002,  2003,  2012,  2013,  2015,  2017,  2019,  2020,  2022,  2025,
    2026,  2028,  2031,  2032,  2034,  2037,  2038,  2040,  2044,  2045,
    2048,  2049,  2050,  2059,  2060,  2061,  2065,  2066,  2067,  2075,
    2081,  2084,  2087,  2088,  2094,  2099,  2101,  2105,  2109,  2113,
    2115,  2116,  2119,  2121,  2122,  2124,  2126,  2129,  2130,  2135,
    2136,  2141,  2142,  2146,  2147,  2151,  2152,  2156,  2157,  2161,
    2162,  2166,  2167,  2171,  2172,  2176,  2177,  2181,  2182,  2186,
    2188,  2192,  2194,  2198,  2201,  2206,  2208,  2210,  2212,  2213,
    2218,  2224,  2231,  2232,  2243,  2247,  2250,  2253,  2255,  2257,
    2258,  2261,  2263,  2266,  2270,  2274,  2278,  2282,  2284,  2286,
    2288,  2290,  2291,  2295,  2297,  2298,  2302,  2305,  2308,  2310,
    2314,  2316,  2320,  2322,  2324,  2326,  2328,  2330,  2332,  2334,
    2336,  2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,
    2356,  2358,  2360,  2361,  2362,  2370,  2372,  2374,  2377,  2380,
    2383,  2387,  2392,  2393,  2397,  2398,  2400,  2402,  2405,  2407,
    2409,  2411,  2413,  2415,  2417,  2418,  2420,  2422,  2425,  2428,
    2430,  2432,  2434,  2436,  2438,  2440,  2442,  2444,  2446,  2448,
    2450,  2452,  2453,  2455,  2457,  2459,  2461,  2462,  2463,  2464,
    2465,  2479,  2481,  2482,  2483,  2490,  2493,  2495,  2498,  2501,
    2504,  2506,  2508,  2511,  2513,  2514,  2518,  2521,  2523,  2525,
    2527,  2528,  2529,  2530,  2545,  2546,  2552,  2554,  2555,  2559,
    2560,  2568,  2569,  2575,  2577,  2580,  2581,  2583,  2585,  2587,
    2588,  2590,  2592,  2595,  2598,  2601,  2603,  2605,  2607,  2609,
    2613,  2615,  2617,  2618,  2619,  2627,  2629,  2632,  2633,  2637,
    2638,  2643,  2646,  2647,  2650,  2652,  2654,  2656,  2658,  2660,
    2662,  2664,  2668,  2669,  2671,  2673,  2675,  2677,  2680,  2683,
    2686,  2692,  2701,  2703,  2705,  2707,  2712,  2717,  2719,  2721,
    2723,  2725,  2728,  2731,  2735,  2742,  2744,  2748,  2750,  2752,
    2754,  2758,  2765,  2775,  2777,  2779,  2781,  2783,  2786,  2787,
    2789,  2791,  2795,  2797,  2801,  2803,  2807,  2809,  2813,  2815,
    2817,  2819,  2821,  2825,  2827,  2831,  2833,  2837,  2839,  2841,
    2843,  2847,  2850,  2851,  2853,  2855,  2860,  2862,  2866,  2868,
    2872,  2880,  2881,  2889,  2890,  2897,  2901,  2903,  2907,  2909,
    2912,  2918,  2919,  2927,  2928,  2931,  2932,  2934,  2940,  2943,
    2949,  2950,  2956,  2963,  2968,  2969,  2971,  2973,  2979,  2980,
    2983,  2984,  2990,  2995,  2998,  3000,  3004,  3007,  3010,  3013,
    3016,  3019,  3022,  3024,  3027,  3030,  3033,  3036,  3039,  3042,
    3045,  3047,  3049,  3051,  3053,  3056,  3059,  3061,  3063,  3065,
    3067,  3069,  3071,  3077,  3079,  3081,  3084,  3089,  3096,  3099,
    3101,  3102,  3114,  3115,  3118,  3124,  3125,  3127,  3128,  3131,
    3133,  3136,  3137,  3141,  3143,  3144,  3149,  3150,  3153,  3155,
    3159,  3161,  3163,  3167,  3172,  3177,  3180,  3182,  3184,  3186,
    3187,  3189,  3197,  3200,  3203,  3206,  3209,  3212,  3214,  3217,
    3218,  3222,  3223,  3227,  3228,  3232,  3233,  3237,  3238,  3242,
    3243,  3248,  3249,  3254,  3256,  3258,  3260,  3262,  3264,  3266,
    3267,  3272,  3273,  3275,  3276,  3281,  3283,  3286,  3289,  3292,
    3293,  3295,  3297,  3300,  3303,  3304,  3307,  3308,  3313,  3317,
    3323,  3324,  3327,  3332,  3334,  3336,  3338,  3340,  3342,  3343,
    3345,  3347,  3351,  3354,  3360,  3363,  3369,  3375,  3381,  3387,
    3393,  3399,  3400,  3403,  3405,  3408,  3411,  3414,  3417,  3420,
    3423,  3425,  3428,  3431,  3434,  3437,  3439,  3442,  3445,  3448,
    3451,  3453,  3455,  3457,  3458,  3461,  3464,  3467,  3470,  3473,
    3476,  3479,  3482,  3485,  3487,  3489,  3491,  3493,  3495,  3497,
    3499,  3501,  3504,  3507,  3510,  3513,  3516,  3518,  3520,  3522,
    3523,  3527,  3530,  3531,  3532,  3533,  3534,  3535,  3536,  3552,
    3553,  3556,  3559,  3560,  3562,  3563,  3564,  3565,  3566,  3567,
    3568,  3584,  3587,  3588,  3589,  3590,  3601,  3602,  3604,  3608,
    3612,  3615,  3620,  3624,  3628,  3632,  3634,  3637,  3640,  3643,
    3646,  3648,  3650,  3651,  3652,  3661,  3662,  3663,  3673,  3674,
    3676,  3678,  3681,  3684,  3687,  3690,  3692,  3694,  3696,  3697,
    3699,  3701,  3704,  3707,  3710,  3719,  3722,  3725,  3730,  3733,
    3734,  3736,  3738,  3742,  3745,  3748,  3750,  3752,  3756,  3758,
    3760,  3763,  3765,  3769,  3773,  3777,  3779,  3783,  3785,  3787,
    3789,  3791,  3793,  3795,  3797,  3800,  3805,  3807,  3811,  3813,
    3817,  3820,  3825,  3827,  3831,  3833,  3836,  3841,  3843,  3847,
    3849,  3851,  3853,  3856,  3860,  3865,  3868,  3873,  3874,  3877,
    3880,  3885,  3887,  3891,  3893,  3895,  3897,  3900,  3902,  3904,
    3906,  3908,  3910,  3913,  3920,  3927,  3928,  3930,  3931,  3933,
    3936,  3938,  3939,  3945,  3946,  3952,  3954,  3955,  3959,  3961,
    3965,  3967,  3971,  3973,  3975,  3976,  3981,  3983,  3986,  3988,
    3989,  3990,  3994,  3995,  3996,  4000,  4002,  4004,  4006,  4008,
    4010,  4012,  4015,  4018,  4023,  4027,  4031,  4033,  4037,  4040,
    4042,  4044,  4045,  4047,  4049,  4051,  4053,  4054,  4056,  4060,
    4062,  4066,  4068,  4069,  4073,  4075,  4077,  4079,  4081,  4083,
    4085,  4087,  4089,  4091,  4093,  4095,  4097,  4105,  4112,  4117,
    4122,  4124,  4126,  4128,  4129,  4131,  4134,  4136,  4138,  4140,
    4142,  4146,  4149,  4151,  4153,  4156,  4158,  4160,  4161,  4165,
    4167,  4171,  4173,  4177,  4179,  4181,  4188,  4189,  4193,  4195,
    4199,  4200,  4202,  4207,  4213,  4216,  4218,  4220,  4225,  4227,
    4231,  4236,  4241,  4246,  4248,  4252,  4254,  4256,  4258,  4261,
    4263,  4265,  4267,  4272,  4273,  4275,  4276,  4278,  4280,  4283,
    4286,  4288,  4290,  4292,  4294,  4296,  4301,  4303,  4307,  4309,
    4311,  4313,  4316,  4318,  4320,  4323,  4326,  4328,  4332,  4335,
    4338,  4340,  4344,  4346,  4349,  4354,  4356,  4359,  4361,  4365,
    4370,  4371,  4373,  4374,  4376,  4377,  4379,  4381,  4385,  4387,
    4391,  4393,  4396,  4398,  4402,  4405,  4408,  4409,  4412,  4414,
    4416,  4422,  4426,  4432,  4436,  4438,  4442,  4444,  4446,  4447,
    4449,  4453,  4457,  4461,  4468,  4473,  4478,  4483,  4488,  4494,
    4496,  4498,  4500,  4502,  4504,  4506,  4508,  4510,  4512,  4514,
    4516,  4518,  4519,  4521,  4523,  4525,  4527,  4529,  4531,  4533,
    4538,  4539,  4541,  4546,  4548,  4554,  4560,  4562,  4564,  4566,
    4568,  4570,  4575,  4577,  4582,  4589,  4594,  4596,  4601,  4603,
    4611,  4613,  4615,  4617,  4622,  4629,  4630,  4633,  4638,  4640,
    4642,  4644,  4646,  4648,  4650,  4652,  4656,  4658,  4660,  4664,
    4670,  4674,  4680,  4688,  4692,  4694,  4696,  4700,  4706,  4710,
    4716,  4724,  4726,  4727,  4731,  4737,  4739,  4742,  4745,  4750,
    4754,  4756,  4758,  4760,  4762,  4764,  4767,  4770,  4771,  4775,
    4776,  4780,  4782,  4784,  4786,  4788,  4790,  4792,  4794,  4799,
    4801,  4803,  4805,  4807,  4809,  4811,  4813,  4818,  4820,  4822,
    4824,  4826,  4828,  4830,  4832,  4834,  4836,  4838,  4840,  4842,
    4844,  4846,  4851,  4853,  4857,  4859,  4863,  4864,  4872,  4873,
    4882,  4883,  4890,  4891,  4900,  4901,  4903,  4906,  4908,  4912,
    4914,  4918,  4924,  4926,  4928,  4930,  4932,  4934,  4935,  4936,
    4946,  4952,  4954,  4956,  4963,  4964,  4968,  4970,  4974,  4979,
    4981,  4982,  4985,  4990,  4997,  4998,  5000,  5002,  5004,  5006,
    5010,  5012,  5015,  5017,  5019,  5022,  5025,  5027,  5029,  5031,
    5034,  5037,  5040,  5043,  5048,  5052,  5055,  5059,  5063,  5067,
    5069,  5071,  5073,  5075,  5077,  5079,  5085,  5091,  5097,  5103,
    5109,  5114,  5119,  5123,  5128,  5130,  5134,  5136,  5142,  5150,
    5156,  5157,  5160,  5162,  5164,  5165,  5169,  5171,  5175,  5177,
    5179,  5181,  5182,  5186,  5188,  5190,  5192,  5194,  5199,  5206,
    5208,  5210,  5213,  5217,  5219,  5221,  5223,  5225,  5227,  5229,
    5231,  5233,  5239,  5245,  5250,  5251,  5256,  5258,  5261,  5263,
    5265,  5267,  5269,  5271,  5273,  5275,  5277,  5279,  5281,  5283,
    5285,  5287,  5289,  5291,  5293,  5295,  5297,  5299,  5301,  5303,
    5305,  5307,  5309,  5311,  5313,  5315,  5317,  5319,  5321,  5323,
    5325,  5327,  5329,  5331,  5333,  5335,  5337,  5339,  5341,  5343,
    5345,  5347,  5349,  5351,  5353,  5355,  5357,  5359,  5361,  5363,
    5365,  5367,  5369,  5371,  5373,  5375,  5377,  5379,  5381,  5383,
    5385,  5387,  5389,  5391,  5393,  5395,  5397,  5399,  5401,  5403,
    5405,  5407,  5409,  5411,  5413,  5415,  5417,  5419,  5421,  5423,
    5425,  5427,  5429,  5431,  5433,  5435,  5437,  5439,  5441,  5443,
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
    5885,  5887,  5889,  5891,  5893,  5895,  5897,  5899,  5900,  5904,
    5905,  5909,  5910,  5911,  5918,  5919,  5922,  5925,  5933,  5937,
    5941,  5944,  5947,  5950,  5952,  5956,  5958,  5962,  5964,  5968,
    5970,  5974,  5976,  5978,  5980,  5983,  5986,  5988,  5990,  5993,
    5998,  6000,  6002,  6004,  6006,  6008,  6010,  6014,  6017,  6021,
    6025,  6029,  6035,  6041,  6047,  6053,  6059,  6064,  6069,  6073,
    6078,  6080,  6082,  6086,  6087,  6093,  6095,  6099,  6103,  6107,
    6109,  6112,  6114,  6116,  6118,  6122,  6128,  6130,  6132,  6134,
    6136,  6140,  6142,  6143,  6144,  6151,  6152,  6155,  6156,  6158,
    6160,  6163,  6166,  6168,  6170,  6175,  6179,  6181,  6184,  6190,
    6193,  6196,  6202,  6203,  6206,  6208,  6210,  6213,  6220,  6227,
    6229,  6230,  6232,  6235,  6237,  6240,  6241,  6244,  6246,  6248,
    6250,  6252,  6254,  6256,  6258,  6260,  6262,  6264,  6266,  6268,
    6270,  6272,  6274,  6276,  6278,  6280,  6282,  6284,  6286,  6288,
    6290,  6292,  6294,  6296,  6298,  6300,  6302,  6304,  6306,  6308,
    6310,  6312,  6314,  6316,  6318,  6320,  6322,  6324,  6326,  6328,
    6330,  6332,  6334,  6336,  6338,  6340,  6342,  6344,  6346,  6348,
    6350,  6352,  6354,  6356,  6358,  6360,  6362,  6364,  6366,  6368,
    6370,  6372,  6374,  6376,  6378,  6380,  6382,  6384,  6386,  6388,
    6390,  6392,  6394,  6396,  6398,  6400,  6402,  6404,  6406,  6408,
    6410,  6412,  6414,  6416,  6418,  6420
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1093,     0,    -1,   245,    -1,   242,    -1,   176,   727,   472,
     640,   728,    -1,   187,    -1,  1158,    -1,    26,    -1,   729,
      -1,   728,     5,   729,    -1,  1003,    -1,   476,   730,   438,
      -1,   730,   731,   730,    -1,    26,    -1,   732,    26,    -1,
    1158,    -1,   943,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   734,
      -1,    -1,   320,   476,   735,   736,   438,    -1,   613,   476,
      26,     5,    26,   438,    -1,   737,    -1,   736,     5,   737,
      -1,   535,    -1,   576,    -1,   581,    -1,   551,    -1,   456,
      -1,   649,    -1,   573,    -1,   525,    -1,   462,    -1,   536,
      -1,   393,    -1,   577,    -1,   501,    -1,   380,    -1,   638,
      -1,   143,    -1,  1072,    -1,    -1,   739,    -1,    -1,   320,
     476,   740,   741,   438,    -1,   742,    -1,   741,     5,   742,
      -1,   737,    -1,   477,    -1,   647,    25,    -1,   248,   989,
      -1,   377,   989,    -1,   330,   989,    -1,   385,   989,    -1,
     339,   989,    -1,   305,   989,    -1,   579,   744,    -1,   932,
     392,  1158,    -1,    -1,   335,   476,   951,   438,   392,   745,
    1177,    -1,   151,   476,  1003,     5,    25,     5,    25,   438,
      -1,   453,   476,   995,   438,   392,  1158,    -1,  1297,    -1,
     238,   476,   951,   438,   392,  1158,    -1,    -1,    -1,  1158,
     634,  1003,   476,   746,   760,   438,   747,   758,    -1,    -1,
      -1,    -1,  1003,   476,   748,   760,   749,   438,   750,   758,
      -1,    -1,    -1,   519,  1506,   667,  1506,   476,   751,   760,
     752,   438,   758,    -1,    -1,    -1,  1003,   566,  1003,   476,
     753,   760,   754,   438,   758,    -1,    -1,    -1,    -1,   412,
     763,   634,   764,   504,   727,   472,   476,   755,   760,   756,
     438,   757,   759,    -1,    -1,   392,  1177,    -1,    -1,   392,
    1177,    -1,   209,    -1,    -1,   761,    -1,   762,    -1,   761,
       5,   762,    -1,   901,    -1,    25,    -1,  1003,    -1,  1003,
      -1,  1003,   664,  1003,    -1,    -1,   580,   908,   766,   769,
     773,   770,    -1,    -1,   580,   767,   768,   771,   770,    -1,
     775,    -1,   768,   775,    -1,   777,    -1,   769,   777,    -1,
     407,    -1,    -1,    -1,   387,   772,  1571,    -1,    -1,    -1,
     387,   774,  1571,    -1,    -1,   623,   908,   776,  1571,    -1,
      -1,   623,   908,   778,  1571,    -1,   324,  1000,    -1,   247,
     998,    -1,   129,   998,    -1,   214,    -1,   231,  1512,    -1,
     539,   997,    -1,    30,   781,    31,    -1,   782,    -1,   784,
      -1,   783,    -1,   782,   783,    -1,    29,    -1,   785,    -1,
     784,   785,    -1,    28,    -1,   440,    -1,    -1,    -1,   368,
     788,   790,   789,   791,    -1,   431,  1158,   669,   792,  1046,
    1071,   733,    -1,  1158,   669,   792,  1046,   591,   951,  1071,
     733,    -1,    -1,   794,   237,    -1,   793,    -1,   792,     5,
     793,    -1,  1003,    -1,  1003,   664,  1003,    -1,  1003,   664,
      20,    -1,   795,    -1,   794,   795,    -1,    -1,   316,   801,
     796,  1571,    -1,    -1,   319,   802,   797,  1571,    -1,    -1,
    1074,   798,  1571,    -1,    -1,   212,   799,  1571,    -1,    -1,
     210,   800,  1571,    -1,  1007,    -1,   801,     5,  1007,    -1,
    1007,    -1,   802,     5,  1007,    -1,   137,    -1,   138,    -1,
     139,    -1,   140,    -1,   141,    -1,   142,    -1,   476,   901,
     805,   438,    -1,    -1,     5,   852,   670,   855,    -1,   202,
      -1,   325,    -1,    -1,   808,    -1,   809,    -1,   808,   809,
      -1,    -1,    -1,   483,   810,   812,   811,  1266,    -1,   865,
      -1,   815,    -1,   812,     5,   815,    -1,    -1,   814,  1003,
      -1,   401,   813,   864,    25,    -1,   401,   813,   864,  1003,
      -1,   401,   813,   864,  1009,    -1,   401,   813,   864,    26,
      -1,   819,   837,    -1,    -1,   813,   401,   816,   817,    -1,
      26,    -1,    25,    -1,  1009,    -1,    19,    26,    -1,   813,
      -1,   818,    -1,   819,     5,   818,    -1,    -1,   365,    -1,
      -1,   714,    -1,   715,    -1,   716,    -1,    -1,   532,   504,
     829,   472,   823,   668,   837,    -1,    -1,    35,   821,   824,
     668,   837,    -1,    -1,   364,   820,   826,    26,   827,   348,
     504,   828,   472,   825,   668,   837,    -1,   476,    -1,   503,
      -1,   438,    -1,   471,    -1,    26,    -1,   830,     5,   830,
       5,   830,    -1,   830,     5,   830,    -1,   830,    -1,    26,
      -1,    -1,   509,   832,   812,   329,    -1,    -1,   306,   833,
     813,   664,    20,    -1,    -1,   382,   834,   813,   304,   476,
     835,   438,    -1,   836,    -1,   835,     5,   836,    -1,   813,
      -1,   839,    -1,    -1,   104,    -1,    -1,    -1,   840,   842,
     841,   838,    -1,   822,    -1,   831,    -1,   365,    -1,   366,
      -1,   365,   476,    26,   438,    -1,   366,   476,    26,   438,
      -1,   469,   476,    26,   438,    -1,   469,   476,    26,     5,
      26,   438,    -1,   367,   476,    26,   438,    -1,   367,   476,
      26,     5,    26,   438,    -1,   454,    -1,   661,   813,    -1,
     427,    -1,   554,    -1,   135,    -1,   444,    -1,   444,   476,
      26,   438,    -1,   444,   476,    26,     5,    26,   438,    -1,
     557,    -1,   557,   476,    26,   438,    -1,   557,   476,    26,
       5,    26,   438,    -1,    -1,   547,   843,   846,    -1,    -1,
     109,   844,   846,    -1,    -1,   345,   845,   846,    -1,   582,
      -1,   578,    -1,   125,    -1,   126,    -1,   619,    -1,   404,
     850,    -1,   416,   851,    -1,   847,    -1,    32,    -1,    -1,
     476,    26,   438,    -1,   601,   848,   664,   849,    -1,   813,
      -1,   813,    -1,    -1,   852,   670,   855,    -1,   860,   670,
     863,    -1,    -1,   853,   854,    -1,   626,    -1,   558,    -1,
     635,    -1,   597,    -1,   499,    -1,   515,    -1,   413,   857,
      -1,    -1,   856,   854,    -1,    -1,   476,   859,   438,    -1,
      -1,   476,    26,   438,    -1,    26,    -1,    -1,   861,   862,
     858,    -1,   626,    -1,   558,    -1,   635,    -1,   597,    -1,
     499,    -1,   515,    -1,   413,   857,    -1,   862,    -1,    -1,
      14,    -1,    -1,   282,  1003,   866,   661,   867,    -1,   869,
      -1,   872,    -1,   365,    -1,   365,   476,    26,   438,    -1,
     469,   476,    26,   438,    -1,   469,   476,    26,     5,    26,
     438,    -1,   454,    -1,   427,    -1,   554,    -1,   444,    -1,
     444,   476,    26,   438,    -1,   444,   476,    26,     5,    26,
     438,    -1,   557,    -1,   557,   476,    26,   438,    -1,   557,
     476,    26,     5,    26,   438,    -1,   547,    -1,   345,    -1,
     582,    -1,   578,    -1,   619,    -1,   404,   850,    -1,   416,
     851,    -1,   868,    -1,   601,   848,   664,   849,    -1,    -1,
     532,   504,   829,   472,   870,   668,   867,    -1,    -1,   364,
     820,   826,    26,   827,   348,   504,   828,   472,   871,   668,
     867,    -1,    -1,   509,   873,   875,   329,    -1,    -1,   306,
     874,  1003,   664,    20,    -1,   876,    -1,   875,     5,   876,
      -1,   877,   867,    -1,   878,    -1,   877,     5,   878,    -1,
    1003,    -1,    -1,   662,   993,    -1,   116,  1003,    -1,   114,
      -1,   670,   951,    -1,   670,   554,  1003,   703,   951,    -1,
     670,   554,  1003,   436,    -1,   118,  1003,    -1,   203,   926,
    1177,   887,    -1,   447,   926,   906,   879,   887,    -1,   256,
    1000,   887,    -1,    -1,    -1,   234,   884,  1184,   670,  1003,
     664,    20,   886,   733,   885,   888,    -1,    -1,   513,   994,
      -1,   733,    -1,    -1,   889,   284,    -1,   284,    -1,   890,
      -1,   889,   890,    -1,    -1,   399,   891,  1571,    -1,    -1,
     395,   892,  1571,    -1,    -1,  1074,   893,  1571,    -1,    37,
    1158,    -1,    38,  1158,    -1,    36,  1158,    -1,   543,   926,
     907,   733,    -1,   543,   926,   907,   733,   111,    -1,   332,
      -1,   331,    -1,   259,    -1,   411,    -1,   219,    -1,   258,
      -1,   376,    -1,   375,    -1,   289,    -1,   216,    -1,   215,
      -1,   193,    -1,   249,    -1,   177,    -1,   192,    -1,   233,
      -1,   200,    -1,   260,    -1,   260,   908,    -1,   911,    -1,
     910,    -1,   915,    -1,   943,    -1,   901,   902,    -1,   944,
      -1,   946,    -1,   912,    -1,    19,   901,    -1,    18,   901,
      -1,   917,    -1,   925,    -1,   919,    -1,   520,    -1,   803,
      -1,   920,    -1,   921,    -1,   922,    -1,   923,    -1,   924,
      -1,    40,   901,    -1,   926,    -1,   926,   905,    -1,   908,
      -1,   528,    -1,   904,    -1,   905,     5,   904,    -1,   908,
      -1,   906,     5,   908,    -1,   908,    -1,   907,     5,   908,
      -1,   901,    -1,    18,    -1,    19,    -1,     9,   901,    -1,
     529,    -1,   473,    -1,   476,   901,   438,    -1,   488,   476,
    1486,   438,    -1,   340,   476,  1486,   438,    -1,   909,  1009,
      -1,   909,    26,    -1,    25,    -1,  1009,    -1,    26,    -1,
     914,    -1,  1158,    -1,  1158,   466,  1158,    -1,   913,    -1,
     479,   901,    -1,   439,   901,    -1,  1269,    -1,    -1,   552,
     916,  1269,    -1,     7,   901,    -1,     6,   901,    -1,   901,
      -1,   918,     5,   901,    -1,   667,   476,  1486,   438,    -1,
     474,   476,  1486,   438,    -1,   667,   476,   926,   918,   438,
      -1,   474,   476,   926,   918,   438,    -1,   433,    -1,   295,
      -1,    10,   901,    -1,   298,   901,    -1,    10,   901,   487,
      25,    -1,   298,   901,   487,    25,    -1,   601,   901,    -1,
     418,   901,    -1,   601,   901,   487,    25,    -1,   418,   901,
     487,    25,    -1,   437,    -1,     8,   901,    -1,    18,   901,
      -1,    19,   901,    -1,    20,   901,    -1,    21,   901,    -1,
      22,   901,    -1,    11,   901,    -1,    14,   901,    -1,   502,
     901,    -1,    12,   901,    -1,    13,   901,    -1,    17,   901,
      -1,    16,   901,    -1,    15,   901,    -1,    -1,    -1,    -1,
    1003,   476,   928,   760,   929,   438,    -1,    -1,    -1,  1003,
     566,  1003,   476,   930,   760,   931,   438,    -1,    -1,    -1,
     582,   476,   933,   901,   934,   438,    -1,    -1,    -1,   558,
     476,   935,   901,   936,   438,    -1,    -1,    -1,   635,   476,
     937,   901,   938,   438,    -1,    -1,    -1,   626,   476,   939,
     901,   940,   438,    -1,   416,   476,   947,   438,   942,    -1,
     404,   476,    25,   438,   941,    -1,   404,   476,    26,   438,
     941,    -1,   404,   476,    26,   634,    26,   438,   941,    -1,
     719,   476,  1158,   438,    -1,   720,   476,  1158,     5,    26,
     438,    -1,    -1,  1466,   670,  1467,    -1,   851,    -1,   932,
      -1,   335,   476,   951,   438,    -1,   144,   476,   994,   438,
      -1,   117,   476,   994,   438,    -1,   453,   476,   952,   438,
      -1,   238,   476,   951,   438,    -1,   105,   476,   951,   438,
      -1,   945,    -1,   927,    -1,  1462,    -1,   582,    -1,   468,
     476,   901,   438,    -1,   370,   476,   901,   438,    -1,   533,
     901,    -1,   489,   804,    -1,   901,   155,    -1,   901,   156,
      -1,   901,   157,    -1,    25,    -1,   948,    -1,    19,   948,
      -1,   950,    -1,   949,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   634,    26,    -1,    26,    26,   634,    26,   634,
      26,    -1,    26,    26,   634,    26,   634,    24,    -1,    26,
     634,    26,    -1,    26,   634,    26,   634,    26,    -1,    26,
     634,    26,   634,    24,    -1,    26,   634,    24,    -1,    24,
      -1,    26,    -1,    26,    19,    26,    -1,   994,    -1,   951,
       5,   994,    -1,   995,    -1,   952,     5,   995,    -1,    -1,
      -1,   640,  1158,    14,   908,   670,   908,   956,   954,  1571,
     955,   287,    -1,    -1,   616,   908,    -1,    -1,    -1,    -1,
     450,   958,   997,   959,   961,  1364,   960,  1571,   286,    -1,
      -1,     8,   926,   906,    -1,    -1,    -1,   682,  1003,   963,
     807,   964,  1103,   966,   965,   971,   683,    -1,    -1,   976,
      -1,    -1,   967,    -1,   968,    -1,   967,   968,    -1,    -1,
     684,   969,  1571,    -1,    -1,   685,   970,  1571,    -1,    -1,
     972,    -1,   973,    -1,   972,   973,    -1,    -1,   686,   974,
    1571,    -1,    -1,   687,   975,  1571,    -1,   977,   981,   372,
      -1,   136,    -1,   136,   978,   591,   979,    -1,   136,   431,
     980,    -1,  1158,    -1,   978,     5,  1158,    -1,  1003,    -1,
     979,     5,  1003,    -1,  1158,    -1,   980,     5,  1158,    -1,
     982,    -1,   981,   982,    -1,    -1,   688,   983,  1571,    -1,
      -1,   689,   984,  1571,    -1,    -1,   708,   979,   985,  1571,
      -1,    -1,   526,   979,   986,  1571,    -1,    -1,   669,   979,
     987,  1571,    -1,   590,   996,    -1,   599,    19,    26,    -1,
     599,    -1,   546,    18,    26,    -1,   546,    -1,    26,    -1,
    1158,    -1,   713,    -1,    25,    -1,  1008,    -1,   908,    -1,
     991,     5,   991,    -1,   992,    -1,  1003,    -1,   711,   476,
    1003,   438,    -1,  1003,   664,   711,   476,  1003,   438,    -1,
    1003,   504,   730,   472,    -1,  1003,   664,    20,    -1,  1003,
     504,   730,   472,   664,    20,    -1,  1003,   664,  1003,    -1,
    1003,   504,   730,   472,   664,  1003,    -1,   994,    -1,    25,
      -1,  1004,    -1,  1004,    -1,  1004,    -1,  1004,    -1,  1004,
      -1,  1004,    -1,    -1,   595,    26,    -1,  1570,    -1,  1005,
      -1,  1570,    -1,   397,   476,  1006,   438,    -1,  1161,    -1,
      25,    -1,  1003,    -1,  1003,   504,   730,   472,    -1,  1003,
     664,    20,    -1,  1003,   504,   730,   472,   664,    20,    -1,
    1003,   664,  1003,    -1,  1003,   504,   730,   472,   664,  1003,
      -1,  1158,    -1,    24,    -1,   664,    26,    -1,   592,  1011,
      -1,  1003,    -1,   634,  1003,    -1,   696,  1013,    -1,  1014,
      -1,  1013,     5,  1014,    -1,  1003,    -1,   707,  1013,    -1,
     698,  1013,    -1,   699,   951,    -1,   697,  1000,   703,   951,
      -1,   701,  1013,    -1,   702,   951,    -1,   700,  1000,   703,
     951,    -1,    -1,   705,  1019,   906,  1024,  1026,  1028,  1020,
    1022,    -1,    -1,  1021,    -1,   693,    -1,   694,    -1,    -1,
    1023,    -1,   392,  1158,    -1,    -1,  1025,    -1,   436,   906,
      -1,    -1,  1027,    -1,   704,    26,    -1,    -1,  1029,    -1,
     695,    26,  1030,    -1,    -1,   446,    26,    -1,    -1,    -1,
     666,   908,   620,  1032,  1571,  1033,  1034,   486,    -1,    -1,
      -1,   587,  1035,  1571,    -1,    -1,    -1,   108,  1036,   908,
     620,  1037,  1571,  1034,    -1,   153,  1003,   476,    26,   438,
      -1,    99,  1003,    -1,   121,  1003,    -1,    -1,   336,  1189,
    1041,   670,   528,    -1,   336,  1189,   601,  1042,    -1,  1043,
      -1,  1042,     5,  1043,    -1,  1044,   664,  1458,    -1,  1044,
     664,    20,    -1,  1454,    -1,    -1,  1047,   372,    -1,   372,
      -1,    -1,   197,    -1,  1048,    -1,  1047,  1048,    -1,    -1,
     316,  1060,  1049,  1571,    -1,    -1,   319,  1061,  1050,  1571,
      -1,    -1,   399,  1051,  1571,    -1,    -1,   395,  1052,  1571,
      -1,    -1,  1074,  1053,  1571,    -1,    -1,   351,  1054,  1571,
      -1,    -1,   321,  1055,  1571,    -1,    -1,    41,  1056,  1571,
      -1,    -1,    39,  1057,  1571,    -1,    -1,    44,  1058,  1571,
      -1,    -1,    43,  1059,  1571,    -1,   994,    -1,  1060,     5,
     994,    -1,   994,    -1,  1061,     5,   994,    -1,   360,  1064,
      -1,   361,  1003,   703,  1064,    -1,   606,    -1,   422,    -1,
     994,    -1,    -1,   709,  1067,  1066,  1045,    -1,   431,  1177,
    1046,  1002,   733,    -1,  1177,  1046,   591,   951,  1002,   733,
      -1,    -1,   532,  1184,  1046,   591,  1003,   664,    20,  1002,
    1068,   733,    -1,   514,   951,  1070,    -1,   127,    26,    -1,
     128,    26,    -1,   671,    -1,   584,    -1,    -1,   595,    26,
      -1,  1073,    -1,    50,    25,    -1,   541,    14,    26,    -1,
     541,    14,  1158,    -1,    51,    14,    26,    -1,    51,    14,
    1158,    -1,    47,    -1,    49,    -1,    46,    -1,    48,    -1,
      -1,   475,  1075,  1080,    -1,   341,    -1,    -1,   641,  1077,
    1080,    -1,   349,  1082,    -1,   641,  1080,    -1,  1082,    -1,
     476,  1081,   438,    -1,  1082,    -1,  1081,     5,  1082,    -1,
    1083,    -1,   639,    -1,   358,    -1,   378,    -1,   350,    -1,
     530,    -1,   487,    -1,   671,    -1,   595,    -1,   584,    -1,
     223,    -1,   484,    -1,   495,    -1,   585,    -1,   600,    -1,
     565,    -1,   356,    -1,   357,    -1,    25,    -1,   555,    -1,
      -1,    -1,   643,  1086,  1182,  1087,    14,   926,  1088,    -1,
     528,    -1,   907,    -1,   265,  1158,    -1,   255,  1158,    -1,
     268,  1158,    -1,   496,  1180,   381,    -1,   496,  1180,   432,
     990,    -1,    -1,  1095,  1094,  1098,    -1,    -1,  1096,    -1,
    1097,    -1,  1096,  1097,    -1,  1039,    -1,  1102,    -1,  1555,
      -1,  1118,    -1,  1104,    -1,  1117,    -1,    -1,  1099,    -1,
    1101,    -1,  1099,  1101,    -1,   112,  1003,    -1,  1106,    -1,
    1112,    -1,  1124,    -1,  1279,    -1,  1289,    -1,  1145,    -1,
     962,    -1,   780,    -1,  1038,    -1,   786,    -1,  1555,    -1,
     780,    -1,    -1,   780,    -1,   808,    -1,   414,    -1,   106,
      -1,    -1,    -1,    -1,    -1,  1105,  1107,  1003,   476,  1108,
    1175,   438,  1109,   807,  1110,  1103,  1571,  1111,    -1,   257,
      -1,    -1,    -1,   602,  1113,   807,  1114,  1571,   408,    -1,
     223,   903,    -1,   926,    -1,   926,   906,    -1,   403,  1470,
      -1,   512,  1470,    -1,  1119,    -1,  1120,    -1,  1119,  1120,
      -1,  1121,    -1,    -1,   452,  1122,  1123,    -1,   807,   288,
      -1,   990,    -1,  1102,    -1,  1117,    -1,    -1,    -1,    -1,
     160,  1003,   159,  1003,   476,  1125,  1175,   438,  1126,   807,
    1127,  1103,  1571,  1111,    -1,    -1,   603,  1129,  1144,  1135,
    1130,    -1,   409,    -1,    -1,   280,  1132,  1571,    -1,    -1,
      23,  1136,  1137,  1138,  1002,  1133,  1571,    -1,    -1,    23,
    1136,  1002,  1134,  1571,    -1,  1131,    -1,  1135,  1131,    -1,
      -1,  1076,    -1,    25,    -1,  1158,    -1,    -1,  1158,    -1,
      25,    -1,   297,  1142,    -1,   309,  1143,    -1,   292,  1143,
      -1,   630,    -1,    25,    -1,  1158,    -1,  1142,    -1,  1143,
       5,  1142,    -1,  1158,    -1,    25,    -1,    -1,    -1,   690,
    1003,  1146,   807,  1147,  1148,   691,    -1,  1149,    -1,  1148,
    1149,    -1,    -1,   692,  1150,  1571,    -1,    -1,   669,  1003,
    1151,  1571,    -1,  1155,  1153,    -1,    -1,   734,  1156,    -1,
    1157,    -1,  1154,    -1,  1025,    -1,  1027,    -1,  1029,    -1,
    1021,    -1,  1023,    -1,   417,   926,   906,    -1,    -1,   111,
      -1,   111,    -1,  1159,    -1,  1161,    -1,   236,  1161,    -1,
    1161,   664,    -1,  1160,  1165,    -1,  1160,  1003,   504,  1169,
     472,    -1,  1160,  1003,   504,  1169,   472,   504,  1169,   472,
      -1,  1166,    -1,  1003,    -1,  1162,    -1,  1003,   503,  1164,
     471,    -1,  1003,   503,  1164,   471,    -1,  1158,    -1,    25,
      -1,    20,    -1,  1003,    -1,  1003,  1168,    -1,  1003,  1168,
      -1,   504,  1169,   472,    -1,   504,  1169,   472,   504,  1169,
     472,    -1,  1170,    -1,  1169,     5,  1170,    -1,   730,    -1,
    1172,    -1,  1174,    -1,  1172,   664,  1173,    -1,  1172,   664,
    1003,   504,  1169,   472,    -1,  1172,   664,  1003,   504,  1169,
     472,   504,  1169,   472,    -1,  1003,    -1,  1163,    -1,    20,
      -1,  1003,    -1,  1003,  1168,    -1,    -1,  1176,    -1,  1178,
      -1,  1176,     5,  1178,    -1,  1179,    -1,  1177,     5,  1179,
      -1,  1003,    -1,  1003,   664,  1003,    -1,  1158,    -1,  1158,
     466,  1158,    -1,    25,    -1,  1009,    -1,    26,    -1,  1181,
      -1,  1180,     5,  1181,    -1,  1158,    -1,  1158,   466,  1158,
      -1,  1183,    -1,  1182,     5,  1183,    -1,  1171,    -1,  1158,
      -1,  1186,    -1,  1185,     5,  1186,    -1,  1158,  1187,    -1,
      -1,   632,    -1,   583,    -1,  1003,   504,  1169,   472,    -1,
    1190,    -1,  1189,     5,  1190,    -1,  1158,    -1,  1158,   466,
    1158,    -1,   300,   999,   662,   992,   624,  1563,   738,    -1,
      -1,   662,   476,   908,     5,   908,   438,  1193,    -1,    -1,
     613,   476,   908,     5,   908,   438,    -1,   301,  1003,  1192,
      -1,  1003,    -1,   386,  1001,  1197,    -1,  1198,    -1,   591,
     908,    -1,  1199,  1200,  1205,     8,  1195,    -1,    -1,   662,
    1201,   476,   908,     5,   908,   438,    -1,    -1,   601,  1004,
      -1,    -1,   398,    -1,   263,  1512,   312,  1550,  1204,    -1,
     608,   996,    -1,   608,   996,     8,   926,   906,    -1,    -1,
     661,   621,  1506,   421,  1506,    -1,   661,   621,  1506,     5,
     421,  1506,    -1,   661,  1506,     5,  1506,    -1,    -1,   693,
      -1,   694,    -1,   441,   670,  1550,  1207,  1208,    -1,    -1,
     661,  1550,    -1,    -1,   661,   621,  1506,     8,  1506,    -1,
     621,  1506,     8,  1506,    -1,   457,  1210,    -1,  1211,    -1,
    1210,     5,  1211,    -1,   248,   989,    -1,   330,   989,    -1,
     377,   989,    -1,   385,   989,    -1,   339,   989,    -1,   305,
     989,    -1,  1078,    -1,   484,  1079,    -1,   495,  1079,    -1,
     606,  1079,    -1,   422,  1079,    -1,   595,  1079,    -1,   593,
     990,    -1,   594,   990,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,   447,   734,    -1,   709,   734,    -1,   337,
      -1,   241,    -1,   198,    -1,   178,    -1,   195,    -1,   186,
      -1,  1511,   459,  1215,   591,  1213,    -1,  1158,    -1,    25,
      -1,   449,  1215,    -1,   449,  1215,     8,  1177,    -1,   449,
    1215,   598,  1180,     8,  1177,    -1,    45,  1213,    -1,  1004,
      -1,    -1,   507,  1225,   733,   640,  1220,  1158,  1218,  1002,
     733,  1217,  1221,    -1,    -1,   712,    26,    -1,   507,  1225,
     733,   392,  1158,    -1,    -1,   365,    -1,    -1,  1222,   328,
      -1,  1223,    -1,  1222,  1223,    -1,    -1,  1074,  1224,  1571,
      -1,   907,    -1,    -1,   648,   996,  1227,  1228,    -1,    -1,
     591,  1229,    -1,  1230,    -1,  1229,     5,  1230,    -1,  1498,
      -1,   528,    -1,   266,  1233,   134,    -1,   266,  1233,   670,
    1232,    -1,   266,  1233,   133,  1232,    -1,   266,  1233,    -1,
      25,    -1,  1008,    -1,  1003,    -1,    -1,   524,    -1,   194,
    1233,  1234,   476,   926,  1116,   438,    -1,   239,  1233,    -1,
     113,  1233,    -1,  1270,  1278,    -1,   492,   107,    -1,   492,
    1240,    -1,  1241,    -1,  1240,  1241,    -1,    -1,   182,  1242,
    1571,    -1,    -1,   244,  1243,  1571,    -1,    -1,   274,  1244,
    1571,    -1,    -1,   262,  1245,  1571,    -1,    -1,   299,  1246,
    1571,    -1,    -1,   246,  1158,  1247,  1571,    -1,    -1,   270,
    1158,  1248,  1571,    -1,  1259,    -1,  1262,    -1,  1261,    -1,
    1250,    -1,  1287,    -1,  1253,    -1,    -1,   605,   908,  1251,
     527,    -1,    -1,   527,    -1,    -1,   614,    26,  1254,  1252,
      -1,   205,    -1,   673,  1274,    -1,   208,  1274,    -1,   207,
    1274,    -1,    -1,  1256,    -1,  1257,    -1,  1256,  1257,    -1,
    1267,  1258,    -1,    -1,   662,  1274,    -1,    -1,   564,  1260,
    1255,  1266,    -1,   563,  1506,  1266,    -1,   562,  1265,  1264,
    1263,  1266,    -1,    -1,   199,   901,    -1,   199,   901,     5,
     901,    -1,   657,    -1,   658,    -1,   659,    -1,   660,    -1,
    1158,    -1,    -1,   567,    -1,  1268,    -1,  1267,     5,  1268,
      -1,   908,  1301,    -1,   653,   476,   901,   438,  1286,    -1,
     110,  1286,    -1,   541,   476,    20,   438,  1286,    -1,   458,
     476,    20,   438,  1286,    -1,   434,   476,   901,   438,  1286,
      -1,   633,   476,   901,   438,  1286,    -1,   646,   476,   901,
     438,  1286,    -1,   645,   476,   901,   438,  1286,    -1,    -1,
     506,  1271,    -1,  1272,    -1,  1271,  1272,    -1,   273,    26,
      -1,   264,    26,    -1,   347,    26,    -1,   230,    26,    -1,
     302,    26,    -1,   221,    -1,   391,    25,    -1,   391,  1158,
      -1,   222,    25,    -1,   206,    25,    -1,  1277,    -1,  1273,
    1277,    -1,  1275,   155,    -1,  1275,   157,    -1,  1275,   156,
      -1,  1275,    -1,  1009,    -1,    26,    -1,    -1,   506,  1273,
      -1,   273,  1274,    -1,   264,  1274,    -1,   347,  1274,    -1,
     230,  1274,    -1,   302,  1274,    -1,   303,  1274,    -1,   672,
      25,    -1,   673,  1274,    -1,   677,    -1,   674,    -1,   675,
      -1,   676,    -1,   681,    -1,   678,    -1,   679,    -1,   680,
      -1,   122,  1274,    -1,   123,  1274,    -1,   124,  1274,    -1,
     391,    25,    -1,   222,    25,    -1,   446,    -1,   119,    -1,
     120,    -1,    -1,   559,   663,  1185,    -1,   183,  1185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   510,  1280,  1003,   476,
    1281,  1175,   438,  1282,   807,  1283,  1238,  1284,  1239,  1285,
     285,    -1,    -1,   571,   901,    -1,   561,  1288,    -1,    -1,
    1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,  1290,
    1003,   476,  1291,  1175,   438,  1292,   807,  1293,  1296,  1294,
    1239,  1295,   285,    -1,  1276,  1278,    -1,    -1,    -1,    -1,
     201,   476,    25,     5,  1298,   760,  1299,   438,  1300,   758,
      -1,    -1,   430,    -1,   430,   264,    26,    -1,   430,   264,
    1158,    -1,   651,   908,    -1,   651,   908,   392,  1158,    -1,
     651,   908,   209,    -1,   651,   908,   622,    -1,   651,   908,
     589,    -1,  1304,    -1,   218,  1454,    -1,   371,  1454,    -1,
     327,  1455,    -1,    42,  1003,    -1,  1318,    -1,  1306,    -1,
      -1,    -1,   251,  1307,  1454,   476,  1308,  1322,   438,  1311,
      -1,    -1,    -1,   180,  1309,  1454,   476,  1310,  1322,   438,
    1311,  1319,    -1,    -1,  1312,    -1,  1313,    -1,  1312,  1313,
      -1,   667,  1314,    -1,   290,    26,    -1,    54,    26,    -1,
     131,    -1,   132,    -1,  1570,    -1,    -1,  1316,    -1,  1317,
      -1,  1316,  1317,    -1,   667,  1314,    -1,   721,    26,    -1,
     150,  1455,   669,  1454,   476,  1320,   438,  1315,    -1,    97,
    1004,    -1,    98,  1004,    -1,   217,  1454,   640,  1454,    -1,
     102,  1454,    -1,    -1,   314,    -1,  1321,    -1,  1320,     5,
    1321,    -1,  1003,   632,    -1,  1003,   583,    -1,  1003,    -1,
    1323,    -1,  1322,     5,  1323,    -1,  1406,    -1,  1404,    -1,
     167,  1003,    -1,   225,    -1,    52,  1003,  1326,    -1,    53,
    1455,   147,    -1,    53,  1455,   148,    -1,  1327,    -1,  1326,
       5,  1327,    -1,  1328,    -1,  1331,    -1,  1334,    -1,  1339,
      -1,  1342,    -1,  1338,    -1,  1337,    -1,   629,  1329,    -1,
     629,   476,  1330,   438,    -1,  1323,    -1,  1323,   708,  1003,
      -1,  1329,    -1,  1330,     5,  1329,    -1,   586,  1333,    -1,
     586,   476,  1332,   438,    -1,  1333,    -1,  1332,     5,  1333,
      -1,  1003,    -1,   500,  1336,    -1,   500,   476,  1335,   438,
      -1,  1336,    -1,  1335,     5,  1336,    -1,  1323,    -1,   131,
      -1,   132,    -1,   130,    26,    -1,   100,  1404,  1341,    -1,
     100,   476,  1340,   438,    -1,  1404,  1341,    -1,  1340,     5,
    1404,  1341,    -1,    -1,   103,  1003,    -1,   101,  1343,    -1,
     101,   476,  1343,   438,    -1,  1344,    -1,  1343,     5,  1344,
      -1,  1003,    -1,   311,    -1,   277,    -1,   211,  1347,    -1,
     190,    -1,   179,    -1,   166,    -1,   164,    -1,   168,    -1,
     224,  1512,    -1,   276,  1346,   505,  1506,   670,  1506,    -1,
     344,   996,   505,  1506,   670,  1506,    -1,    -1,  1512,    -1,
      -1,   908,    -1,   568,   908,    -1,   275,    -1,    -1,   294,
    1351,  1454,  1354,  1352,    -1,    -1,   524,  1353,   476,  1356,
     438,    -1,  1492,    -1,    -1,   476,  1355,   438,    -1,  1458,
      -1,  1355,     5,  1458,    -1,  1357,    -1,  1356,     5,  1357,
      -1,  1498,    -1,   528,    -1,    -1,   545,  1359,  1361,  1362,
      -1,  1004,    -1,  1366,   997,    -1,   997,    -1,    -1,    -1,
     598,  1363,  1180,    -1,    -1,    -1,   598,  1365,  1180,    -1,
     546,    -1,   599,    -1,   606,    -1,   422,    -1,   389,    -1,
     442,    -1,   425,   908,    -1,   398,   908,    -1,   283,  1454,
     196,   997,    -1,   283,  1454,  1427,    -1,   559,   663,  1370,
      -1,  1371,    -1,  1370,     5,  1371,    -1,  1372,  1373,    -1,
      26,    -1,  1458,    -1,    -1,   632,    -1,   583,    -1,   322,
      -1,   355,    -1,    -1,   374,    -1,   403,  1378,  1376,    -1,
    1550,    -1,  1550,   656,  1003,    -1,    25,    -1,    -1,  1511,
    1380,  1381,    -1,  1412,    -1,  1416,    -1,  1375,    -1,  1513,
      -1,  1374,    -1,  1367,    -1,  1368,    -1,  1358,    -1,  1350,
      -1,  1349,    -1,  1482,    -1,  1530,    -1,   550,  1385,   669,
    1454,   670,  1390,  1384,    -1,   511,  1385,   669,  1454,   591,
    1390,    -1,   550,  1383,   670,  1390,    -1,   511,  1383,   591,
    1390,    -1,   441,    -1,   426,    -1,   636,    -1,    -1,   189,
      -1,   661,  1003,    -1,   213,    -1,   630,    -1,  1386,    -1,
    1387,    -1,  1386,     5,  1387,    -1,   516,  1388,    -1,   495,
      -1,   484,    -1,   523,  1388,    -1,   531,    -1,   553,    -1,
      -1,   476,  1389,   438,    -1,  1458,    -1,  1389,     5,  1458,
      -1,  1391,    -1,  1390,     5,  1391,    -1,   508,    -1,  1456,
      -1,   281,  1454,  1393,   661,  1492,  1395,    -1,    -1,   476,
    1394,   438,    -1,  1458,    -1,  1394,     5,  1458,    -1,    -1,
     188,    -1,   537,   476,  1430,   438,    -1,   291,   476,  1399,
     438,  1398,    -1,   342,  1400,    -1,  1401,    -1,  1454,    -1,
    1454,   476,  1401,   438,    -1,  1458,    -1,  1401,     5,  1458,
      -1,   521,   476,  1403,   438,    -1,   406,   476,  1403,   438,
      -1,   304,   476,  1403,   438,    -1,  1458,    -1,  1403,     5,
    1458,    -1,  1402,    -1,  1397,    -1,  1396,    -1,   446,  1461,
      -1,   254,    -1,   253,    -1,   252,    -1,  1003,  1446,  1407,
    1408,    -1,    -1,  1405,    -1,    -1,  1409,    -1,  1410,    -1,
    1409,  1410,    -1,  1411,  1341,    -1,   420,    -1,   204,    -1,
     521,    -1,   406,    -1,  1398,    -1,   537,   476,  1430,   438,
      -1,   304,    -1,   165,  1413,  1415,    -1,  1414,    -1,  1456,
      -1,  1416,    -1,  1415,  1416,    -1,  1392,    -1,  1382,    -1,
     493,  1430,    -1,   415,  1419,    -1,  1497,    -1,  1419,     5,
    1497,    -1,   571,  1430,    -1,   591,  1422,    -1,  1423,    -1,
    1422,     5,  1423,    -1,  1424,    -1,   560,  1424,    -1,   560,
     476,  1425,   438,    -1,  1454,    -1,  1454,  1460,    -1,  1423,
      -1,  1425,     5,  1423,    -1,  1421,  1427,  1428,  1429,    -1,
      -1,  1420,    -1,    -1,  1418,    -1,    -1,  1417,    -1,  1431,
      -1,  1430,     6,  1431,    -1,  1432,    -1,  1431,     7,  1432,
      -1,  1433,    -1,     9,  1433,    -1,  1444,    -1,   476,  1430,
     438,    -1,   488,  1493,    -1,   340,  1493,    -1,    -1,   487,
    1437,    -1,  1499,    -1,  1502,    -1,  1498,   667,   476,  1439,
     438,    -1,  1498,   667,  1493,    -1,  1498,   474,   476,  1439,
     438,    -1,  1498,   474,  1493,    -1,  1440,    -1,  1439,     5,
    1440,    -1,  1554,    -1,  1461,    -1,    -1,     9,    -1,  1498,
    1441,   433,    -1,  1498,  1441,   295,    -1,  1498,  1443,  1498,
      -1,  1498,  1441,   435,  1498,     7,  1498,    -1,  1498,   601,
    1436,  1435,    -1,  1498,   418,  1436,  1435,    -1,  1498,   718,
    1436,  1435,    -1,  1498,   419,  1436,  1435,    -1,  1498,  1441,
      10,  1436,  1435,    -1,    14,    -1,    17,    -1,    12,    -1,
      13,    -1,   298,    -1,    10,    -1,   717,    -1,    16,    -1,
      15,    -1,  1442,    -1,  1438,    -1,  1434,    -1,    -1,   630,
      -1,   406,    -1,   521,    -1,  1447,    -1,  1448,    -1,  1450,
      -1,   365,    -1,   365,   476,  1451,   438,    -1,    -1,   517,
      -1,   517,   476,    26,   438,    -1,   444,    -1,   444,   476,
    1452,  1449,   438,    -1,   557,   476,  1452,  1449,   438,    -1,
     557,    -1,   582,    -1,   454,    -1,   427,    -1,   366,    -1,
     366,   476,  1451,   438,    -1,   367,    -1,   367,   476,    26,
     438,    -1,   367,   476,    26,     5,    26,   438,    -1,   404,
    1468,   670,  1469,    -1,   404,    -1,   416,  1468,   670,  1469,
      -1,   416,    -1,   416,  1468,   476,    26,   438,   670,  1469,
      -1,   619,    -1,   578,    -1,   469,    -1,   469,   476,    26,
     438,    -1,   469,   476,    26,     5,    26,   438,    -1,    -1,
       5,  1453,    -1,   547,   476,  1452,   438,    -1,   610,    -1,
     345,    -1,   547,    -1,   109,    -1,    26,    -1,    26,    -1,
      26,    -1,    25,   664,  1003,    -1,    25,    -1,  1003,    -1,
    1003,   634,  1003,    -1,  1003,   634,    25,   664,  1003,    -1,
    1003,   656,  1003,    -1,  1003,   656,  1003,   634,  1003,    -1,
    1003,   656,  1003,   634,    25,   664,  1003,    -1,    25,   664,
    1003,    -1,    25,    -1,  1003,    -1,  1003,   634,  1003,    -1,
    1003,   634,    25,   664,  1003,    -1,  1003,   656,  1003,    -1,
    1003,   656,  1003,   634,  1003,    -1,  1003,   656,  1003,   634,
      25,   664,  1003,    -1,  1003,    -1,    -1,   504,    26,   472,
      -1,   504,    26,     5,    26,   472,    -1,  1459,    -1,   656,
    1459,    -1,  1003,  1457,    -1,  1454,   664,  1003,  1457,    -1,
    1454,   664,    20,    -1,  1003,    -1,    25,    -1,  1009,    -1,
      26,    -1,  1463,    -1,   442,  1465,    -1,   442,  1464,    -1,
      -1,  1468,   670,  1469,    -1,    -1,  1466,   670,  1466,    -1,
     626,    -1,   558,    -1,   635,    -1,   597,    -1,   499,    -1,
     515,    -1,   413,    -1,   413,   476,    26,   438,    -1,   626,
      -1,   558,    -1,   635,    -1,   597,    -1,   499,    -1,   515,
      -1,   413,    -1,   413,   476,    26,   438,    -1,   626,    -1,
     558,    -1,   635,    -1,   597,    -1,   499,    -1,   515,    -1,
     413,    -1,   626,    -1,   558,    -1,   635,    -1,   597,    -1,
     499,    -1,   515,    -1,   413,    -1,   413,   476,    26,   438,
      -1,  1003,    -1,  1003,   656,  1003,    -1,    25,    -1,  1511,
     548,   997,    -1,    -1,  1511,   445,  1360,   482,   640,  1480,
    1473,    -1,    -1,  1511,   445,  1360,   482,   145,   640,  1481,
    1474,    -1,    -1,  1511,   445,  1360,   184,  1481,  1475,    -1,
      -1,  1511,   445,  1360,   185,   145,   640,  1481,  1476,    -1,
      -1,   334,    -1,   333,  1478,    -1,  1479,    -1,  1478,     5,
    1479,    -1,  1003,    -1,  1003,   664,  1003,    -1,    25,   664,
    1003,   664,  1003,    -1,  1481,    -1,  1350,    -1,  1215,    -1,
    1483,    -1,  1483,    -1,    -1,    -1,   516,  1494,  1484,  1495,
    1485,  1491,  1426,  1489,  1477,    -1,   516,  1494,  1495,  1426,
    1489,    -1,  1488,    -1,  1506,    -1,   516,  1494,  1495,  1491,
    1426,  1489,    -1,    -1,   570,  1445,  1487,    -1,  1369,    -1,
     379,  1490,  1319,    -1,  1369,   379,  1490,  1319,    -1,  1003,
      -1,    -1,   598,  1180,    -1,   516,  1494,  1495,  1426,    -1,
     476,   516,  1494,  1495,  1426,   438,    -1,    -1,   630,    -1,
     406,    -1,   521,    -1,  1496,    -1,  1495,     5,  1496,    -1,
    1498,    -1,  1498,  1003,    -1,  1498,    -1,  1499,    -1,    19,
    1499,    -1,    18,  1499,    -1,  1500,    -1,  1554,    -1,  1493,
      -1,   630,  1493,    -1,   631,  1493,    -1,   615,  1493,    -1,
     656,  1003,    -1,   656,  1003,   664,  1003,    -1,  1499,    21,
    1498,    -1,  1499,  1520,    -1,  1499,    20,  1498,    -1,  1499,
      18,  1498,    -1,  1499,    19,  1498,    -1,  1461,    -1,   529,
      -1,   473,    -1,   621,    -1,    20,    -1,   110,    -1,   633,
     476,  1445,  1498,   438,    -1,   645,   476,  1445,  1498,   438,
      -1,   646,   476,  1445,  1498,   438,    -1,   653,   476,  1445,
    1498,   438,    -1,   541,   476,  1445,  1498,   438,    -1,  1003,
     476,  1501,   438,    -1,   582,   476,  1501,   438,    -1,   476,
    1498,   438,    -1,   489,   476,  1521,   438,    -1,  1498,    -1,
    1501,     5,  1498,    -1,  1461,    -1,  1511,   394,  1510,  1505,
    1487,    -1,  1511,   383,  1510,  1505,   294,  1454,  1507,    -1,
    1511,   383,  1510,  1505,  1158,    -1,    -1,   369,  1506,    -1,
      25,    -1,  1158,    -1,    -1,   476,  1508,   438,    -1,  1509,
      -1,  1508,     5,  1509,    -1,  1003,    -1,    25,    -1,  1158,
      -1,    -1,   313,  1512,   640,    -1,  1004,    -1,  1518,    -1,
    1517,    -1,  1514,    -1,   362,  1515,   670,  1515,    -1,   343,
    1454,   664,  1516,   670,  1516,    -1,  1003,    -1,  1003,    -1,
     267,  1454,    -1,   338,  1454,  1519,    -1,   317,    -1,   220,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,
      -1,   142,    -1,   442,     5,  1468,   670,  1469,    -1,  1554,
       5,  1468,   670,  1469,    -1,   442,  1468,   670,  1469,    -1,
      -1,   652,  1523,  1524,   235,    -1,  1525,    -1,  1524,  1525,
      -1,    33,    -1,  1526,    -1,  1528,    -1,   398,    -1,   350,
      -1,   269,    -1,   629,    -1,   526,    -1,   630,    -1,   531,
      -1,   575,    -1,   631,    -1,   161,    -1,   532,    -1,   661,
      -1,   632,    -1,   363,    -1,   533,    -1,   364,    -1,   662,
      -1,   656,    -1,   320,    -1,   534,    -1,   229,    -1,   434,
      -1,   633,    -1,   708,    -1,   435,    -1,   535,    -1,   536,
      -1,   576,    -1,   577,    -1,   477,    -1,   478,    -1,   400,
      -1,   695,    -1,   663,    -1,   578,    -1,   436,    -1,   580,
      -1,   574,    -1,   365,    -1,   537,    -1,   538,    -1,   437,
      -1,   539,    -1,   438,    -1,   472,    -1,   540,    -1,   634,
      -1,   479,    -1,   439,    -1,     5,    -1,    23,    -1,   440,
      -1,   480,    -1,   441,    -1,   402,    -1,   401,    -1,   368,
      -1,   541,    -1,   481,    -1,   442,    -1,   482,    -1,   581,
      -1,   403,    -1,   582,    -1,   404,    -1,   635,    -1,   636,
      -1,   443,    -1,   637,    -1,   444,    -1,   445,    -1,   446,
      -1,   405,    -1,   542,    -1,   483,    -1,   484,    -1,   369,
      -1,   583,    -1,   326,    -1,   638,    -1,   699,    -1,   447,
      -1,   406,    -1,    21,    -1,   664,    -1,   485,    -1,   370,
      -1,   586,    -1,   108,    -1,   587,    -1,   702,    -1,   448,
      -1,    14,    -1,   543,    -1,   487,    -1,   544,    -1,   374,
      -1,   588,    -1,   449,    -1,   488,    -1,   589,    -1,   489,
      -1,   490,    -1,   412,    -1,   579,    -1,   545,    -1,   144,
      -1,   238,    -1,   491,    -1,   546,    -1,   639,    -1,   547,
      -1,   548,    -1,   640,    -1,   450,    -1,   451,    -1,   492,
      -1,   682,    -1,   136,    -1,   151,    -1,   549,    -1,   413,
      -1,   590,    -1,   591,    -1,   414,    -1,   335,    -1,   452,
      -1,   665,    -1,   592,    -1,   550,    -1,    13,    -1,   551,
      -1,   552,    -1,   493,    -1,   494,    -1,   595,    -1,   596,
      -1,   597,    -1,   704,    -1,   117,    -1,   666,    -1,   667,
      -1,   157,    -1,   553,    -1,   453,    -1,   336,    -1,   709,
      -1,   495,    -1,   454,    -1,   378,    -1,   416,    -1,   711,
      -1,   380,    -1,   641,    -1,   584,    -1,   703,    -1,   554,
      -1,   527,    -1,   417,    -1,   642,    -1,   671,    -1,   455,
      -1,     7,    -1,   473,    -1,   627,    -1,   528,    -1,     6,
      -1,   529,    -1,     8,    -1,   599,    -1,   600,    -1,    12,
      -1,   643,    -1,   601,    -1,   556,    -1,   496,    -1,   644,
      -1,   456,    -1,   602,    -1,   497,    -1,    10,    -1,    51,
      -1,   498,    -1,   603,    -1,   690,    -1,   705,    -1,    19,
      -1,   499,    -1,   156,    -1,    22,    -1,   604,    -1,   500,
      -1,   557,    -1,   558,    -1,    20,    -1,   605,    -1,   606,
      -1,   356,    -1,   607,    -1,   501,    -1,     9,    -1,   668,
      -1,   713,    -1,   669,    -1,   608,    -1,   476,    -1,   504,
      -1,   505,    -1,   457,    -1,   559,    -1,   387,    -1,   560,
      -1,   506,    -1,   647,    -1,   421,    -1,   561,    -1,   201,
      -1,   152,    -1,   458,    -1,    18,    -1,   155,    -1,   388,
      -1,   459,    -1,   158,    -1,   422,    -1,   357,    -1,   564,
      -1,   389,    -1,   390,    -1,   460,    -1,   507,    -1,   508,
      -1,   648,    -1,   609,    -1,   423,    -1,   610,    -1,   509,
      -1,   461,    -1,   649,    -1,   342,    -1,   424,    -1,   425,
      -1,   510,    -1,   426,    -1,   223,    -1,   392,    -1,   462,
      -1,   511,    -1,   565,    -1,   307,    -1,   650,    -1,   611,
      -1,   651,    -1,   512,    -1,   514,    -1,   515,    -1,   463,
      -1,   516,    -1,   567,    -1,   517,    -1,   464,    -1,   519,
      -1,   612,    -1,   530,    -1,   613,    -1,   614,    -1,   568,
      -1,   345,    -1,   427,    -1,   615,    -1,   520,    -1,   652,
      -1,   346,    -1,   135,    -1,   616,    -1,   617,    -1,   653,
      -1,   465,    -1,   585,    -1,   618,    -1,   162,    -1,   619,
      -1,   620,    -1,   466,    -1,   712,    -1,   670,    -1,   654,
      -1,   467,    -1,   569,    -1,   243,    -1,   393,    -1,   570,
      -1,   521,    -1,   522,    -1,   523,    -1,   468,    -1,   655,
      -1,   621,    -1,   428,    -1,   524,    -1,   469,    -1,   397,
      -1,   622,    -1,   470,    -1,   623,    -1,   571,    -1,   572,
      -1,   573,    -1,   624,    -1,   430,    -1,   625,    -1,   645,
      -1,   646,    -1,   628,    -1,   626,    -1,   525,    -1,    -1,
     236,  1527,  1554,    -1,    -1,   598,  1529,  1180,    -1,    -1,
      -1,   523,  1454,  1531,  1534,  1532,  1533,    -1,    -1,   196,
     997,    -1,   571,  1430,    -1,    95,  1538,   438,    14,   476,
    1539,   438,    -1,    91,  1539,   438,    -1,    92,  1539,   438,
      -1,   628,  1535,    -1,    94,  1539,    -1,    93,  1539,    -1,
    1537,    -1,  1535,     5,  1537,    -1,  1458,    -1,  1536,    14,
    1540,    -1,  1536,    -1,  1538,     5,  1536,    -1,  1540,    -1,
    1539,     5,  1540,    -1,   528,    -1,  1541,    -1,  1542,    -1,
      19,  1542,    -1,    18,  1542,    -1,  1544,    -1,  1493,    -1,
     656,  1003,    -1,   656,  1003,   664,  1003,    -1,  1543,    -1,
    1461,    -1,   529,    -1,   473,    -1,   621,    -1,   110,    -1,
    1542,    21,  1541,    -1,  1542,  1520,    -1,  1542,    20,  1541,
      -1,  1542,    18,  1541,    -1,  1542,    19,  1541,    -1,   633,
     476,  1445,  1541,   438,    -1,   645,   476,  1445,  1541,   438,
      -1,   646,   476,  1445,  1541,   438,    -1,   653,   476,  1445,
    1541,   438,    -1,   541,   476,  1445,  1541,   438,    -1,  1003,
     476,  1545,   438,    -1,   582,   476,  1545,   438,    -1,   476,
    1541,   438,    -1,   489,   476,  1521,   438,    -1,  1554,    -1,
    1541,    -1,  1545,     5,  1541,    -1,    -1,   428,  1189,   601,
    1547,  1548,    -1,  1549,    -1,  1548,     5,  1549,    -1,  1454,
     664,  1458,    -1,  1454,   664,    20,    -1,  1551,    -1,   236,
    1552,    -1,  1552,    -1,  1167,    -1,  1003,    -1,  1552,   664,
    1553,    -1,    25,   664,  1552,   664,  1553,    -1,    20,    -1,
    1188,    -1,  1003,    -1,  1551,    -1,  1551,   466,  1551,    -1,
      34,    -1,    -1,    -1,   572,  1557,   908,  1558,  1571,   373,
      -1,    -1,   703,   951,    -1,    -1,   706,    -1,   227,    -1,
     323,   998,    -1,   115,   998,    -1,   353,    -1,   352,    -1,
     354,  1000,  1559,  1560,    -1,   538,   951,  1560,    -1,   149,
      -1,   181,   998,    -1,   908,   611,     5,   908,   439,    -1,
     554,   908,    -1,   310,   998,    -1,   146,  1566,     8,  1567,
    1565,    -1,    -1,   591,   908,    -1,  1003,    -1,  1003,    -1,
     293,   998,    -1,   296,   998,   670,   908,     5,   908,    -1,
     296,   998,   663,   908,     5,   908,    -1,    27,    -1,    -1,
    1573,    -1,  1574,  1266,    -1,  1572,    -1,  1573,  1572,    -1,
      -1,  1575,  1576,    -1,   723,    -1,   724,    -1,   725,    -1,
     726,    -1,   743,    -1,   765,    -1,   779,    -1,   780,    -1,
     786,    -1,   787,    -1,   806,    -1,   880,    -1,   881,    -1,
     882,    -1,   883,    -1,   894,    -1,   895,    -1,   896,    -1,
     897,    -1,   898,    -1,   899,    -1,   900,    -1,   953,    -1,
     957,    -1,   988,    -1,  1010,    -1,  1012,    -1,  1015,    -1,
    1016,    -1,  1017,    -1,  1018,    -1,  1031,    -1,  1040,    -1,
    1062,    -1,  1063,    -1,  1065,    -1,  1069,    -1,  1084,    -1,
    1085,    -1,  1089,    -1,  1090,    -1,  1091,    -1,  1092,    -1,
    1100,    -1,  1115,    -1,  1128,    -1,  1139,    -1,  1140,    -1,
    1141,    -1,  1152,    -1,  1191,    -1,  1194,    -1,  1196,    -1,
    1202,    -1,  1203,    -1,  1206,    -1,  1209,    -1,  1212,    -1,
    1214,    -1,  1216,    -1,  1219,    -1,  1226,    -1,  1231,    -1,
    1235,    -1,  1236,    -1,  1237,    -1,  1249,    -1,  1302,    -1,
    1303,    -1,  1305,    -1,  1324,    -1,  1325,    -1,  1345,    -1,
    1348,    -1,  1377,    -1,  1379,    -1,  1471,    -1,  1472,    -1,
    1503,    -1,  1504,    -1,  1522,    -1,  1546,    -1,  1555,    -1,
    1556,    -1,  1561,    -1,  1562,    -1,  1564,    -1,  1568,    -1,
    1569,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   990,   990,   993,   996,  1002,  1008,  1015,  1019,  1019,
    1025,  1048,  1049,  1050,  1051,  1052,  1063,  1069,  1070,  1071,
    1072,  1073,  1078,  1079,  1090,  1093,  1096,  1096,  1100,  1103,
    1104,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,
    1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1129,  1130,
    1133,  1133,  1148,  1149,  1152,  1158,  1160,  1171,  1173,  1175,
    1177,  1181,  1183,  1245,  1249,  1253,  1253,  1263,  1267,  1270,
    1271,  1278,  1284,  1278,  1297,  1302,  1306,  1297,  1318,  1322,
    1318,  1330,  1335,  1330,  1354,  1361,  1365,  1353,  1391,  1391,
    1395,  1396,  1397,  1402,  1405,  1410,  1414,  1422,  1425,  1425,
    1431,  1435,  1450,  1448,  1466,  1466,  1481,  1481,  1484,  1484,
    1488,  1491,  1491,  1491,  1498,  1499,  1498,  1506,  1506,  1517,
    1517,  1536,  1539,  1542,  1545,  1548,  1551,  1564,  1569,  1569,
    1570,  1570,  1573,  1578,  1578,  1582,  1592,  1606,  1611,  1605,
    1622,  1628,  1636,  1637,  1640,  1640,  1643,  1647,  1652,  1659,
    1659,  1663,  1663,  1664,  1664,  1665,  1665,  1666,  1666,  1667,
    1667,  1675,  1679,  1685,  1689,  1704,  1707,  1710,  1713,  1716,
    1719,  1725,  1736,  1741,  1754,  1758,  1773,  1774,  1778,  1778,
    1782,  1782,  1782,  1783,  1788,  1788,  1791,  1791,  1800,  1801,
    1802,  1805,  1809,  1810,  1810,  1827,  1827,  1827,  1827,  1831,
    1838,  1839,  1842,  1842,  1846,  1847,  1848,  1849,  1854,  1854,
    1860,  1860,  1869,  1866,  1882,  1882,  1884,  1884,  1886,  1888,
    1890,  1892,  1895,  1899,  1899,  1900,  1900,  1904,  1904,  1916,
    1916,  1921,  1925,  1927,  1928,  1931,  1931,  1931,  1935,  1936,
    1937,  1938,  1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,
    1949,  1950,  1951,  1952,  1956,  1961,  1966,  1970,  1973,  1977,
    1977,  1978,  1978,  1979,  1979,  1980,  1981,  1982,  1983,  1984,
    1985,  1988,  1989,  1990,  2020,  2020,  2025,  2029,  2031,  2033,
    2033,  2040,  2044,  2044,  2048,  2049,  2050,  2051,  2052,  2053,
    2054,  2060,  2060,  2063,  2065,  2071,  2073,  2079,  2087,  2087,
    2090,  2091,  2092,  2093,  2094,  2095,  2096,  2102,  2105,  2105,
    2118,  2118,  2125,  2126,  2127,  2129,  2130,  2132,  2134,  2135,
    2136,  2137,  2142,  2148,  2154,  2155,  2157,  2159,  2160,  2161,
    2162,  2163,  2164,  2167,  2168,  2175,  2183,  2183,  2191,  2188,
    2203,  2203,  2205,  2205,  2213,  2213,  2216,  2219,  2220,  2225,
    2237,  2241,  2244,  2247,  2248,  2249,  2250,  2251,  2256,  2263,
    2269,  2274,  2279,  2274,  2292,  2294,  2299,  2304,  2304,  2304,
    2308,  2308,  2311,  2311,  2318,  2318,  2325,  2325,  2336,  2354,
    2360,  2384,  2387,  2401,  2403,  2405,  2407,  2409,  2411,  2413,
    2419,  2421,  2425,  2427,  2429,  2431,  2433,  2435,  2437,  2443,
    2458,  2461,  2474,  2475,  2476,  2477,  2478,  2482,  2483,  2484,
    2488,  2493,  2500,  2501,  2502,  2503,  2504,  2505,  2506,  2507,
    2508,  2509,  2510,  2517,  2517,  2522,  2522,  2525,  2531,  2539,
    2545,  2555,  2556,  2564,  2571,  2575,  2585,  2589,  2594,  2599,
    2601,  2604,  2610,  2618,  2631,  2636,  2642,  2647,  2652,  2653,
    2659,  2730,  2741,  2750,  2758,  2758,  2773,  2777,  2784,  2787,
    2795,  2799,  2802,  2808,  2817,  2822,  2830,  2833,  2836,  2841,
    2848,  2853,  2858,  2863,  2873,  2881,  2889,  2894,  2898,  2903,
    2907,  2911,  2918,  2921,  2924,  2928,  2932,  2936,  2940,  2948,
    2958,  2963,  2956,  2979,  2984,  2979,  3001,  3001,  3001,  3004,
    3004,  3004,  3008,  3008,  3008,  3012,  3012,  3012,  3016,  3022,
    3028,  3034,  3040,  3046,  3056,  3056,  3060,  3064,  3065,  3076,
    3077,  3083,  3093,  3103,  3113,  3114,  3117,  3122,  3128,  3132,
    3136,  3139,  3145,  3148,  3151,  3168,  3171,  3177,  3178,  3179,
    3183,  3184,  3185,  3186,  3187,  3189,  3190,  3191,  3193,  3194,
    3198,  3199,  3204,  3208,  3213,  3217,  3232,  3236,  3231,  3244,
    3247,  3261,  3265,  3271,  3260,  3284,  3285,  3297,  3303,  3297,
    3317,  3317,  3319,  3320,  3324,  3324,  3328,  3328,  3333,  3333,
    3340,  3341,  3345,  3345,  3349,  3349,  3354,  3354,  3361,  3365,
    3366,  3367,  3372,  3372,  3375,  3375,  3379,  3379,  3383,  3383,
    3387,  3387,  3392,  3392,  3397,  3397,  3402,  3402,  3407,  3407,
    3423,  3440,  3441,  3442,  3443,  3444,  3445,  3446,  3449,  3449,
    3452,  3454,  3457,  3460,  3463,  3468,  3473,  3476,  3481,  3486,
    3491,  3498,  3499,  3506,  3513,  3515,  3521,  3526,  3531,  3536,
    3536,  3539,  3545,  3550,  3553,  3560,  3560,  3562,  3565,  3568,
    3573,  3578,  3583,  3590,  3599,  3599,  3661,  3669,  3670,  3678,
    3685,  3685,  3689,  3694,  3700,  3704,  3708,  3714,  3718,  3722,
    3728,  3728,  3736,  3737,  3741,  3741,  3745,  3746,  3749,  3752,
    3752,  3755,  3757,  3757,  3760,  3762,  3762,  3763,  3765,  3765,
    3774,  3781,  3772,  3802,  3802,  3802,  3805,  3807,  3805,  3814,
    3817,  3823,  3834,  3834,  3838,  3844,  3844,  3848,  3849,  3853,
    3863,  3864,  3865,  3868,  3870,  3875,  3875,  3879,  3878,  3886,
    3885,  3892,  3892,  3898,  3898,  3905,  3905,  3911,  3911,  3917,
    3917,  3923,  3923,  3927,  3927,  3931,  3931,  3935,  3935,  3946,
    3950,  3956,  3960,  3965,  3970,  3975,  3976,  3977,  3981,  3980,
    3993,  3998,  4003,  4003,  4019,  4025,  4026,  4027,  4028,  4031,
    4031,  4034,  4041,  4042,  4043,  4044,  4045,  4046,  4047,  4048,
    4049,  4054,  4054,  4056,  4059,  4059,  4061,  4065,  4068,  4069,
    4072,  4072,  4077,  4080,  4081,  4082,  4083,  4084,  4085,  4086,
    4087,  4088,  4089,  4090,  4091,  4092,  4093,  4094,  4095,  4096,
    4097,  4101,  4119,  4119,  4119,  4146,  4157,  4164,  4170,  4176,
    4182,  4194,  4219,  4218,  4235,  4235,  4239,  4240,  4248,  4249,
    4250,  4251,  4252,  4253,  4260,  4261,  4263,  4264,  4268,  4273,
    4274,  4275,  4276,  4277,  4278,  4279,  4280,  4281,  4282,  4283,
    4286,  4288,  4288,  4290,  4294,  4294,  4303,  4308,  4324,  4330,
    4302,  4344,  4358,  4368,  4357,  4381,  4388,  4388,  4393,  4399,
    4407,  4412,  4413,  4416,  4419,  4419,  4427,  4433,  4444,  4445,
    4449,  4453,  4466,  4448,  4484,  4484,  4498,  4509,  4508,  4520,
    4516,  4533,  4530,  4543,  4543,  4545,  4546,  4548,  4549,  4552,
    4553,  4554,  4556,  4561,  4566,  4572,  4574,  4575,  4578,  4579,
    4582,  4584,  4592,  4598,  4592,  4609,  4610,  4614,  4614,  4621,
    4621,  4630,  4633,  4636,  4639,  4643,  4647,  4648,  4649,  4650,
    4651,  4655,  4660,  4660,  4663,  4690,  4748,  4748,  4751,  4755,
    4759,  4802,  4844,  4845,  4846,  4849,  4863,  4875,  4875,  4880,
    4881,  4887,  4947,  5004,  5009,  5016,  5021,  5029,  5035,  5068,
    5071,  5072,  5113,  5156,  5157,  5161,  5162,  5166,  5219,  5223,
    5226,  5232,  5243,  5250,  5258,  5258,  5261,  5262,  5263,  5264,
    5265,  5268,  5271,  5277,  5280,  5284,  5289,  5297,  5302,  5309,
    5312,  5318,  5320,  5320,  5320,  5324,  5344,  5351,  5358,  5361,
    5375,  5382,  5383,  5386,  5387,  5391,  5397,  5402,  5408,  5409,
    5414,  5418,  5418,  5422,  5423,  5426,  5427,  5431,  5439,  5442,
    5448,  5449,  5451,  5453,  5457,  5457,  5458,  5463,  5471,  5472,
    5477,  5478,  5480,  5493,  5495,  5496,  5498,  5501,  5504,  5507,
    5511,  5514,  5517,  5521,  5522,  5523,  5524,  5525,  5526,  5527,
    5529,  5530,  5532,  5533,  5535,  5536,  5537,  5540,  5543,  5546,
    5549,  5552,  5568,  5576,  5576,  5578,  5585,  5589,  5593,  5598,
    5613,  5611,  5631,  5632,  5636,  5641,  5642,  5646,  5647,  5649,
    5650,  5652,  5652,  5661,  5670,  5670,  5680,  5681,  5686,  5687,
    5690,  5703,  5717,  5722,  5727,  5732,  5742,  5742,  5746,  5749,
    5749,  5751,  5761,  5770,  5777,  5779,  5783,  5786,  5786,  5790,
    5789,  5797,  5796,  5807,  5806,  5813,  5812,  5816,  5815,  5818,
    5818,  5834,  5833,  5855,  5856,  5857,  5858,  5859,  5860,  5863,
    5863,  5869,  5869,  5872,  5872,  5888,  5889,  5890,  5899,  5911,
    5912,  5915,  5916,  5919,  5922,  5922,  5927,  5927,  5948,  5953,
    5959,  5960,  5961,  5965,  5966,  5967,  5968,  5972,  5982,  5984,
    5989,  5992,  5997,  6003,  6010,  6017,  6026,  6033,  6040,  6047,
    6054,  6063,  6063,  6065,  6065,  6068,  6069,  6070,  6071,  6072,
    6073,  6074,  6075,  6076,  6077,  6080,  6080,  6083,  6084,  6085,
    6086,  6089,  6089,  6092,  6092,  6095,  6096,  6097,  6098,  6099,
    6100,  6101,  6102,  6104,  6105,  6106,  6107,  6109,  6110,  6111,
    6112,  6114,  6115,  6116,  6117,  6118,  6119,  6120,  6121,  6125,
    6132,  6141,  6153,  6162,  6173,  6177,  6181,  6187,  6152,  6200,
    6203,  6211,  6223,  6225,  6230,  6238,  6248,  6251,  6255,  6263,
    6229,  6272,  6276,  6280,  6284,  6276,  6294,  6295,  6296,  6297,
    6302,  6304,  6307,  6311,  6314,  6321,  6326,  6327,  6328,  6329,
    6334,  6335,  6341,  6341,  6341,  6346,  6346,  6346,  6354,  6355,
    6359,  6360,  6365,  6366,  6367,  6368,  6369,  6372,  6374,  6374,
    6377,  6378,  6382,  6383,  6386,  6387,  6390,  6393,  6396,  6402,
    6403,  6415,  6416,  6421,  6422,  6423,  6427,  6430,  6436,  6439,
    6447,  6448,  6454,  6458,  6462,  6468,  6471,  6480,  6483,  6486,
    6489,  6492,  6495,  6498,  6505,  6508,  6515,  6518,  6524,  6527,
    6534,  6537,  6544,  6545,  6550,  6554,  6557,  6563,  6566,  6572,
    6579,  6580,  6584,  6594,  6597,  6603,  6605,  6610,  6611,  6615,
    6617,  6623,  6624,  6637,  6649,  6650,  6651,  6652,  6653,  6654,
    6655,  6656,  6657,  6660,  6663,  6669,  6669,  6675,  6675,  6686,
    6699,  6709,  6709,  6714,  6714,  6718,  6722,  6723,  6729,  6730,
    6735,  6739,  6746,  6749,  6756,  6755,  6766,  6770,  6774,  6781,
    6784,  6784,  6797,  6801,  6801,  6816,  6818,  6820,  6822,  6824,
    6826,  6828,  6830,  6836,  6846,  6853,  6858,  6859,  6863,  6866,
    6867,  6870,  6871,  6872,  6875,  6880,  6887,  6888,  6894,  6906,
    6907,  6908,  6911,  6911,  6916,  6921,  6926,  6927,  6930,  6931,
    6936,  6941,  6945,  6950,  6951,  6955,  6962,  6963,  6964,  6965,
    6970,  6971,  6972,  6975,  6976,  6977,  6981,  6982,  6983,  6987,
    6988,  6992,  6993,  6994,  6995,  6996,  6997,  7000,  7001,  7006,
    7007,  7012,  7013,  7018,  7019,  7024,  7029,  7030,  7035,  7036,
    7040,  7041,  7046,  7053,  7058,  7063,  7067,  7068,  7073,  7074,
    7080,  7081,  7082,  7087,  7088,  7094,  7097,  7100,  7107,  7108,
    7109,  7110,  7124,  7129,  7130,  7133,  7135,  7142,  7145,  7151,
    7159,  7163,  7167,  7171,  7175,  7178,  7181,  7188,  7195,  7200,
    7204,  7205,  7211,  7214,  7225,  7232,  7238,  7241,  7248,  7255,
    7261,  7262,  7268,  7269,  7270,  7273,  7274,  7279,  7279,  7283,
    7291,  7292,  7295,  7298,  7303,  7304,  7309,  7312,  7318,  7321,
    7327,  7330,  7336,  7339,  7346,  7347,  7376,  7377,  7382,  7390,
    7395,  7398,  7401,  7404,  7410,  7411,  7415,  7418,  7421,  7422,
    7427,  7430,  7433,  7436,  7439,  7442,  7445,  7448,  7453,  7459,
    7460,  7461,  7462,  7463,  7465,  7466,  7468,  7469,  7474,  7477,
    7481,  7487,  7488,  7489,  7490,  7502,  7503,  7504,  7508,  7509,
    7513,  7514,  7515,  7516,  7517,  7519,  7521,  7522,  7523,  7524,
    7525,  7526,  7527,  7528,  7530,  7532,  7534,  7535,  7537,  7538,
    7540,  7541,  7542,  7543,  7545,  7549,  7550,  7556,  7558,  7559,
    7560,  7561,  7566,  7570,  7574,  7578,  7585,  7589,  7590,  7591,
    7599,  7600,  7601,  7612,  7619,  7624,  7625,  7626,  7634,  7635,
    7636,  7653,  7662,  7663,  7664,  7668,  7671,  7676,  7681,  7686,
    7694,  7698,  7703,  7704,  7712,  7715,  7718,  7732,  7746,  7759,
    7760,  7764,  7764,  7764,  7764,  7764,  7764,  7765,  7768,  7773,
    7773,  7773,  7773,  7773,  7773,  7775,  7778,  7784,  7784,  7784,
    7784,  7784,  7784,  7784,  7785,  7785,  7785,  7785,  7785,  7785,
    7785,  7785,  7788,  7789,  7790,  7793,  7802,  7802,  7808,  7808,
    7815,  7815,  7821,  7821,  7829,  7830,  7831,  7834,  7834,  7837,
    7838,  7839,  7850,  7853,  7859,  7864,  7871,  7884,  7885,  7882,
    7903,  7914,  7917,  7922,  7934,  7937,  7941,  7944,  7945,  7951,
    7954,  7955,  7964,  7973,  7978,  7979,  7980,  7981,  7988,  7991,
    7997,  8000,  8010,  8019,  8022,  8025,  8031,  8037,  8040,  8041,
    8042,  8043,  8044,  8047,  8053,  8055,  8057,  8059,  8061,  8063,
    8064,  8065,  8066,  8067,  8068,  8069,  8071,  8073,  8075,  8077,
    8079,  8081,  8083,  8084,  8089,  8090,  8097,  8100,  8109,  8113,
    8120,  8120,  8124,  8124,  8129,  8129,  8133,  8133,  8137,  8143,
    8143,  8146,  8146,  8152,  8159,  8160,  8161,  8165,  8166,  8169,
    8170,  8174,  8180,  8190,  8191,  8199,  8200,  8201,  8202,  8203,
    8204,  8208,  8209,  8210,  8214,  8214,  8226,  8227,  8231,  8232,
    8233,  8234,  8235,  8236,  8237,  8238,  8239,  8240,  8241,  8242,
    8243,  8244,  8245,  8246,  8247,  8248,  8249,  8250,  8251,  8252,
    8253,  8254,  8255,  8256,  8257,  8258,  8259,  8260,  8261,  8262,
    8263,  8264,  8265,  8266,  8267,  8268,  8269,  8270,  8271,  8272,
    8273,  8274,  8275,  8276,  8277,  8278,  8279,  8280,  8281,  8282,
    8283,  8284,  8285,  8286,  8287,  8288,  8289,  8290,  8291,  8292,
    8293,  8294,  8295,  8296,  8297,  8298,  8299,  8300,  8301,  8302,
    8303,  8304,  8305,  8306,  8307,  8308,  8309,  8310,  8311,  8312,
    8313,  8314,  8315,  8316,  8317,  8318,  8319,  8320,  8321,  8322,
    8323,  8324,  8325,  8326,  8327,  8328,  8329,  8330,  8331,  8332,
    8333,  8334,  8335,  8336,  8337,  8338,  8339,  8340,  8341,  8342,
    8343,  8344,  8345,  8346,  8347,  8348,  8349,  8350,  8351,  8352,
    8353,  8354,  8355,  8356,  8357,  8358,  8359,  8360,  8361,  8362,
    8363,  8364,  8365,  8366,  8367,  8368,  8369,  8370,  8371,  8372,
    8373,  8374,  8375,  8376,  8377,  8378,  8379,  8380,  8381,  8382,
    8383,  8384,  8385,  8386,  8387,  8388,  8389,  8390,  8391,  8392,
    8393,  8394,  8395,  8396,  8397,  8398,  8399,  8400,  8401,  8402,
    8403,  8404,  8405,  8406,  8407,  8408,  8409,  8410,  8411,  8412,
    8413,  8414,  8415,  8416,  8417,  8418,  8419,  8420,  8421,  8422,
    8423,  8424,  8425,  8426,  8427,  8428,  8429,  8430,  8431,  8432,
    8433,  8434,  8436,  8437,  8438,  8439,  8440,  8441,  8442,  8443,
    8444,  8445,  8446,  8447,  8448,  8449,  8450,  8451,  8452,  8453,
    8454,  8455,  8456,  8457,  8458,  8459,  8460,  8461,  8462,  8463,
    8464,  8465,  8466,  8467,  8468,  8469,  8470,  8471,  8472,  8473,
    8474,  8475,  8476,  8477,  8478,  8479,  8480,  8481,  8482,  8483,
    8484,  8485,  8486,  8487,  8488,  8489,  8490,  8491,  8492,  8493,
    8494,  8495,  8496,  8497,  8498,  8499,  8500,  8501,  8502,  8503,
    8504,  8505,  8506,  8507,  8508,  8509,  8510,  8511,  8512,  8513,
    8514,  8515,  8516,  8517,  8518,  8519,  8520,  8521,  8522,  8523,
    8524,  8525,  8526,  8527,  8528,  8529,  8530,  8531,  8532,  8533,
    8534,  8535,  8536,  8537,  8538,  8539,  8540,  8541,  8542,  8543,
    8544,  8545,  8546,  8547,  8548,  8549,  8550,  8558,  8558,  8565,
    8565,  8653,  8657,  8653,  8666,  8670,  8676,  8684,  8694,  8704,
    8716,  8719,  8738,  8764,  8767,  8773,  8776,  8781,  8784,  8792,
    8800,  8813,  8816,  8824,  8827,  8830,  8838,  8842,  8845,  8848,
    8851,  8855,  8856,  8857,  8858,  8859,  8865,  8866,  8867,  8868,
    8869,  8870,  8871,  8872,  8873,  8874,  8875,  8876,  8877,  8878,
    8882,  8888,  8889,  8897,  8897,  8905,  8905,  8909,  8913,  8928,
    8948,  8950,  8956,  8957,  8958,  8959,  8969,  8970,  8971,  8976,
    9002,  9058,  9072,  9075,  9071,  9094,  9094,  9100,  9101,  9104,
    9105,  9106,  9107,  9108,  9109,  9110,  9121,  9124,  9129,  9133,
    9138,  9142,  9147,  9151,  9154,  9158,  9161,  9166,  9170,  9181,
    9187,  9187,  9188,  9189,  9196,  9206,  9206,  9208,  9209,  9210,
    9211,  9212,  9213,  9214,  9215,  9216,  9217,  9218,  9219,  9220,
    9221,  9222,  9223,  9224,  9225,  9226,  9227,  9228,  9229,  9230,
    9231,  9232,  9233,  9234,  9235,  9236,  9237,  9238,  9239,  9240,
    9241,  9242,  9243,  9244,  9245,  9246,  9247,  9248,  9249,  9250,
    9251,  9252,  9253,  9254,  9255,  9256,  9257,  9258,  9259,  9260,
    9261,  9262,  9263,  9264,  9265,  9266,  9267,  9268,  9269,  9270,
    9271,  9272,  9273,  9274,  9275,  9276,  9277,  9278,  9279,  9280,
    9281,  9282,  9283,  9284,  9285,  9286,  9287,  9288,  9289,  9290,
    9291,  9292,  9293,  9294,  9295,  9296
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "KW_WHENEVER_SET", "DYNAMIC_ARRAY", 
  "RESIZE_ARRAY", "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "BEFORE_INSERT", 
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
  "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "COMMENT", "CONNECT", "CURRENT", 
  "DBYNAME", "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", 
  "EXECUTE", "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", 
  "KWWINDOW", "MAGENTA", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", 
  "RECOVER", "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", 
  "TRAILER", "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", 
  "CLOSE_SQUARE", "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", 
  "BOTTOM", "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", 
  "DOUBLE", "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", 
  "FORMAT", "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", 
  "MINUTE", "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", 
  "OPTION", "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "REVOKE", 
  "SCHEMA", "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", 
  "SETL", "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", 
  "YELLOW", "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", 
  "ALTER", "ARRAY", "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", 
  "CLOSE", "CODE_C", "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", 
  "FLOAT", "FLUSH", "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", 
  "LABEL", "LOCAL", "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", 
  "PRINT_IMAGE", "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", 
  "SEMICOLON", "SLEEP", "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", 
  "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", "FCALL", "CASE", "CYAN", 
  "DATE", "DESC", "KWDOWN", "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", 
  "FROM", "GOTO", "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", 
  "INTO", "LAST", "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", 
  "NOCR", "OPEN", "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", 
  "STEP", "STOP", "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", 
  "WORK", "YEAR", "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", 
  "COLON", "DAY", "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", 
  "LET", "LOG", "XMAX", "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", 
  "SUM", "TOP", "USE", "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", 
  "AS", "AT", "BY", "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "KWUP", 
  "FONT_NAME", "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
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
  "c_code_part", "comment_cmd", "construct_cmd", "@22", "@23", 
  "constr_rest", "end_constr", "constr_col_list", "constr_col", 
  "constr_extra_commands", "constr_extra_command", "@24", "@25", "@26", 
  "@27", "@28", "bef_c_field_list_as_struct", 
  "aft_c_field_list_as_struct", "interval_expr", "extend_parameters", 
  "op_datetime_qual", "defer_cmd", "define_section", "define_multiple", 
  "define_set", "@29", "@30", "def_part", "define_ident", "@31", 
  "def_part2", "@32", "constant_value", "var_def_name", "var_def_list", 
  "op_char", "ranking", "array_variable", "@33", "@34", "@35", 
  "assoc_open_bracket", "assoc_close_bracket", "number_arr_assoc", 
  "number_arr_list", "number_value_arr", "record_variable", "@36", "@37", 
  "@38", "link_to_pk_list", "link_to_pk", "dtype_ident", "op_as_static", 
  "dtype2", "@39", "@40", "dtype", "@41", "@42", "@43", "op_prec", 
  "like_var", "tab_name", "col_name", "datetime_qual", "interval_qual", 
  "dtime_start", "@44", "dtime_val", "dtime_end", "@45", "opt_frac", 
  "opt_unit_size", "dtfrac", "int_start", "@46", "int_start_unit", 
  "int_end", "op_equal", "dim_section", "@47", "dim_dtype", 
  "dim_like_var", "dim_array_variable", "@48", "@49", 
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
  "@100", "@101", "@102", "@103", "bef_field_list_as_struct", 
  "aft_field_list_as_struct", "next_field_cmd", "next_form_cmd", 
  "next_field", "input_cmd", "@104", "inp_rest", "@105", "scroll_cmd", 
  "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@106", "key_val", 
  "@107", "accept_key", "single_key_val", "key_do", "key_value_list", 
  "key_value", "key_value_1", "label_cmd", "let_cmd", "@108", "@109", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@110", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@111", "@112", "@113", "@114", 
  "end_func_command", "main_def", "@115", "@116", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@117", 
  "glob_section", "mem_func_def", "@118", "@119", "@120", "menu_cmd", 
  "@121", "end_menu_command", "menu_block_command", "@122", "@123", 
  "@124", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@125", "@126", "menu_handler_elements", 
  "menu_handler_element", "@127", "@128", "message_cmd", "msg_next", 
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
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@129", 
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@130", "prompt_title", 
  "put_cmd", "@131", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@132", "@133", "@134", "@135", "@136", "@137", "@138", 
  "report_cmd", "need_command", "@139", "op_lines", "skip_command", 
  "@140", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "@141", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@142", "@143", "@144", "@145", "@146", 
  "@147", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@148", "@149", "@150", "@151", "@152", "@153", "pdf_report_section", 
  "pdf_functions", "@154", "@155", "@156", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@157", "@158", 
  "@159", "@160", "opt_cr_table_extra", "cr_table_extra", 
  "cr_table_extra_entry", "space_name", "op_cr_index_extra", 
  "cr_index_extra", "cr_index_extra_entry", "create_c_1", "op_no_log", 
  "idx_column_list", "idx_column", "table_element_list_ss", 
  "table_element_ss", "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", 
  "alter_clause_ss", "alter_add_clause_ss", "add_column_clause_ss", 
  "add_column_clauses_ss", "alter_drop_clause", "drop_column_list", 
  "drop_column", "alter_modify_clause_ss", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "table_constraint_definition_list_ss", 
  "opt_constraint_name", "alter_drop_constraint_clause", 
  "constraint_names", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@161", "ins_2_ss", "@162", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@163", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@164", "opt_foreach_into_fetch_part", "@165", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@166", 
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
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@167", 
  "@168", "@169", "@170", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@171", "@172", 
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
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@173", "sql_block", 
  "sql_block_entry", "in_var", "@174", "sql_block_into", "@175", 
  "update_statement_ss", "@176", "@177", "where_upd_ss", 
  "set_clause_list_ss", "upd_columns_ss", "upd_column_name", "col_1_ss", 
  "upd_col_list", "upd_val_list_ss", "upd_val_ss", 
  "upd_value_expression_ss", "upd_value_expression_initial_ss", 
  "upd_value_expression_complex_ss", "upd_var_ident_ibind_ss", 
  "upd_value_expr_list_ss", "validate_cmd", "@178", "validate_tab_list", 
  "validate_tab", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "whenever_cmd", "while_cmd", "@179", "@180", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "current_win_cmd", 
  "window_type", "show_cmd", "op_mnfile", "menu_name", "menu_handler", 
  "hide_cmd", "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@181", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1706,  1707,  1708,  1613,  1653,  1608,  1545,  1628,
    1425,  1531,  1527,  1442,  1603,  1343,  1400,  1473,  1639,  1626,
    1532,  1559,  1627,  1407,  1709,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
    1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,
    1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,  1344,  1345,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,
    1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,
    1396,  1397,  1398,  1399,  1401,  1402,  1403,  1404,  1405,  1406,
    1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,  1416,  1417,
    1418,  1419,  1420,  1421,  1422,  1423,  1424,  1426,  1427,  1428,
    1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1440,  1441,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,
    1470,  1471,  1472,  1474,  1475,  1476,  1477,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,
    1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,  1520,
    1521,  1522,  1523,  1524,  1525,  1526,  1528,  1529,  1530,  1533,
    1534,  1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,  1543,
    1544,  1546,  1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,
    1555,  1556,  1557,  1558,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,
    1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,
    1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1596,  1597,  1598,  1599,  1600,  1601,  1602,  1604,  1605,  1606,
    1607,  1609,  1610,  1611,  1612,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1629,  1630,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1640,  1641,  1642,
    1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,
    1704,  1705
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   722,   723,   724,   725,   726,   727,   727,   728,   728,
     729,   730,   730,   730,   730,   730,   730,   731,   731,   731,
     731,   731,   732,   732,   733,   733,   735,   734,   734,   736,
     736,   737,   737,   737,   737,   737,   737,   737,   737,   737,
     737,   737,   737,   737,   737,   737,   737,   737,   738,   738,
     740,   739,   741,   741,   742,   742,   742,   742,   742,   742,
     742,   742,   742,   743,   744,   745,   744,   744,   744,   744,
     744,   746,   747,   744,   748,   749,   750,   744,   751,   752,
     744,   753,   754,   744,   755,   756,   757,   744,   758,   758,
     759,   759,   759,   760,   760,   761,   761,   762,   763,   763,
     764,   764,   766,   765,   767,   765,   768,   768,   769,   769,
     770,   771,   772,   771,   773,   774,   773,   776,   775,   778,
     777,   779,   779,   779,   779,   779,   779,   780,   781,   781,
     782,   782,   783,   784,   784,   785,   786,   788,   789,   787,
     790,   790,   791,   791,   792,   792,   793,   793,   793,   794,
     794,   796,   795,   797,   795,   798,   795,   799,   795,   800,
     795,   801,   801,   802,   802,   803,   803,   803,   803,   803,
     803,   804,   805,   805,   806,   806,   807,   807,   808,   808,
     810,   811,   809,   809,   812,   812,   814,   813,   815,   815,
     815,   815,   815,   816,   815,   817,   817,   817,   817,   818,
     819,   819,   820,   820,   821,   821,   821,   821,   823,   822,
     824,   822,   825,   822,   826,   826,   827,   827,   828,   829,
     829,   829,   830,   832,   831,   833,   831,   834,   831,   835,
     835,   836,   837,   838,   838,   840,   841,   839,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   843,
     842,   844,   842,   845,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   846,   846,   847,   848,   849,   850,
     850,   851,   853,   852,   854,   854,   854,   854,   854,   854,
     854,   856,   855,   857,   857,   858,   858,   859,   861,   860,
     862,   862,   862,   862,   862,   862,   862,   863,   864,   864,
     866,   865,   867,   867,   867,   867,   867,   867,   867,   867,
     867,   867,   867,   867,   867,   867,   867,   867,   867,   867,
     867,   867,   867,   867,   867,   868,   870,   869,   871,   869,
     873,   872,   874,   872,   875,   875,   876,   877,   877,   878,
     879,   879,   879,   879,   879,   879,   879,   879,   880,   881,
     882,   884,   885,   883,   886,   886,   887,   888,   888,   888,
     889,   889,   891,   890,   892,   890,   893,   890,   894,   895,
     896,   897,   897,   898,   898,   898,   898,   898,   898,   898,
     898,   898,   899,   899,   899,   899,   899,   899,   899,   899,
     900,   900,   901,   901,   901,   901,   901,   901,   901,   901,
     901,   901,   902,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   902,   903,   903,   904,   904,   905,   905,   906,
     906,   907,   907,   908,   909,   909,   910,   910,   910,   910,
     910,   910,   911,   911,   912,   912,   912,   912,   913,   913,
     914,   915,   915,   915,   916,   915,   917,   917,   918,   918,
     919,   919,   919,   919,   920,   920,   921,   921,   921,   921,
     921,   921,   921,   921,   922,   923,   924,   924,   924,   924,
     924,   924,   925,   925,   925,   925,   925,   925,   925,   926,
     928,   929,   927,   930,   931,   927,   933,   934,   932,   935,
     936,   932,   937,   938,   932,   939,   940,   932,   932,   932,
     932,   932,   932,   932,   941,   941,   942,   943,   943,   943,
     943,   943,   943,   943,   943,   943,   944,   944,   945,   945,
     945,   945,   946,   946,   946,   947,   947,   948,   948,   948,
     949,   949,   949,   949,   949,   949,   949,   949,   949,   949,
     950,   950,   951,   951,   952,   952,   954,   955,   953,   956,
     956,   958,   959,   960,   957,   961,   961,   963,   964,   962,
     965,   965,   966,   966,   967,   967,   969,   968,   970,   968,
     971,   971,   972,   972,   974,   973,   975,   973,   976,   977,
     977,   977,   978,   978,   979,   979,   980,   980,   981,   981,
     983,   982,   984,   982,   985,   982,   986,   982,   987,   982,
     988,   989,   989,   989,   989,   989,   989,   989,   990,   990,
     991,   992,   993,   994,   994,   994,   994,   994,   994,   994,
     994,   995,   995,   996,   997,   998,   999,  1000,  1001,  1002,
    1002,  1003,  1004,  1005,  1005,  1006,  1006,  1007,  1007,  1007,
    1007,  1007,  1007,  1008,  1009,  1009,  1010,  1011,  1011,  1012,
    1013,  1013,  1014,  1015,  1016,  1016,  1016,  1017,  1017,  1017,
    1019,  1018,  1020,  1020,  1021,  1021,  1022,  1022,  1023,  1024,
    1024,  1025,  1026,  1026,  1027,  1028,  1028,  1029,  1030,  1030,
    1032,  1033,  1031,  1034,  1035,  1034,  1036,  1037,  1034,  1038,
    1038,  1039,  1041,  1040,  1040,  1042,  1042,  1043,  1043,  1044,
    1045,  1045,  1045,  1046,  1046,  1047,  1047,  1049,  1048,  1050,
    1048,  1051,  1048,  1052,  1048,  1053,  1048,  1054,  1048,  1055,
    1048,  1056,  1048,  1057,  1048,  1058,  1048,  1059,  1048,  1060,
    1060,  1061,  1061,  1062,  1063,  1064,  1064,  1064,  1066,  1065,
    1067,  1067,  1068,  1067,  1069,  1070,  1070,  1070,  1070,  1071,
    1071,  1072,  1073,  1073,  1073,  1073,  1073,  1073,  1073,  1073,
    1073,  1075,  1074,  1074,  1077,  1076,  1078,  1079,  1080,  1080,
    1081,  1081,  1082,  1083,  1083,  1083,  1083,  1083,  1083,  1083,
    1083,  1083,  1083,  1083,  1083,  1083,  1083,  1083,  1083,  1083,
    1083,  1084,  1086,  1087,  1085,  1088,  1088,  1089,  1090,  1091,
    1092,  1092,  1094,  1093,  1095,  1095,  1096,  1096,  1097,  1097,
    1097,  1097,  1097,  1097,  1098,  1098,  1099,  1099,  1100,  1101,
    1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,
    1102,  1103,  1103,  1104,  1105,  1105,  1107,  1108,  1109,  1110,
    1106,  1111,  1113,  1114,  1112,  1115,  1116,  1116,  1117,  1117,
    1118,  1119,  1119,  1120,  1122,  1121,  1123,  1123,  1123,  1123,
    1125,  1126,  1127,  1124,  1129,  1128,  1130,  1132,  1131,  1133,
    1131,  1134,  1131,  1135,  1135,  1136,  1136,  1137,  1137,  1138,
    1138,  1138,  1139,  1140,  1141,  1142,  1142,  1142,  1143,  1143,
    1144,  1144,  1146,  1147,  1145,  1148,  1148,  1150,  1149,  1151,
    1149,  1152,  1153,  1153,  1153,  1153,  1154,  1154,  1154,  1154,
    1154,  1155,  1156,  1156,  1157,  1158,  1159,  1159,  1160,  1161,
    1161,  1161,  1161,  1161,  1161,  1162,  1163,  1164,  1164,  1165,
    1165,  1166,  1167,  1168,  1168,  1169,  1169,  1170,  1171,  1172,
    1172,  1172,  1172,  1172,  1172,  1173,  1173,  1174,  1175,  1175,
    1176,  1176,  1177,  1177,  1178,  1178,  1179,  1179,  1179,  1179,
    1179,  1180,  1180,  1181,  1181,  1182,  1182,  1183,  1184,  1185,
    1185,  1186,  1187,  1187,  1187,  1188,  1189,  1189,  1190,  1190,
    1191,  1192,  1192,  1193,  1193,  1194,  1195,  1196,  1197,  1197,
    1198,  1199,  1199,  1200,  1200,  1201,  1201,  1202,  1203,  1203,
    1204,  1204,  1204,  1204,  1205,  1205,  1205,  1206,  1207,  1207,
    1208,  1208,  1208,  1209,  1210,  1210,  1211,  1211,  1211,  1211,
    1211,  1211,  1211,  1211,  1211,  1211,  1211,  1211,  1211,  1211,
    1211,  1211,  1211,  1211,  1211,  1211,  1211,  1211,  1211,  1211,
    1211,  1211,  1212,  1213,  1213,  1214,  1214,  1214,  1214,  1215,
    1217,  1216,  1218,  1218,  1219,  1220,  1220,  1221,  1221,  1222,
    1222,  1224,  1223,  1225,  1227,  1226,  1228,  1228,  1229,  1229,
    1230,  1230,  1231,  1231,  1231,  1231,  1232,  1232,  1233,  1234,
    1234,  1235,  1236,  1237,  1238,  1239,  1239,  1240,  1240,  1242,
    1241,  1243,  1241,  1244,  1241,  1245,  1241,  1246,  1241,  1247,
    1241,  1248,  1241,  1249,  1249,  1249,  1249,  1249,  1249,  1251,
    1250,  1252,  1252,  1254,  1253,  1253,  1253,  1253,  1253,  1255,
    1255,  1256,  1256,  1257,  1258,  1258,  1260,  1259,  1261,  1262,
    1263,  1263,  1263,  1264,  1264,  1264,  1264,  1265,  1266,  1266,
    1267,  1267,  1268,  1269,  1269,  1269,  1269,  1269,  1269,  1269,
    1269,  1270,  1270,  1271,  1271,  1272,  1272,  1272,  1272,  1272,
    1272,  1272,  1272,  1272,  1272,  1273,  1273,  1274,  1274,  1274,
    1274,  1275,  1275,  1276,  1276,  1277,  1277,  1277,  1277,  1277,
    1277,  1277,  1277,  1277,  1277,  1277,  1277,  1277,  1277,  1277,
    1277,  1277,  1277,  1277,  1277,  1277,  1277,  1277,  1277,  1278,
    1278,  1278,  1280,  1281,  1282,  1283,  1284,  1285,  1279,  1286,
    1286,  1287,  1288,  1288,  1290,  1291,  1292,  1293,  1294,  1295,
    1289,  1296,  1298,  1299,  1300,  1297,  1301,  1301,  1301,  1301,
    1302,  1302,  1302,  1302,  1302,  1303,  1304,  1304,  1304,  1304,
    1305,  1305,  1307,  1308,  1306,  1309,  1310,  1306,  1311,  1311,
    1312,  1312,  1313,  1313,  1313,  1313,  1313,  1314,  1315,  1315,
    1316,  1316,  1317,  1317,  1318,  1318,  1318,  1318,  1318,  1319,
    1319,  1320,  1320,  1321,  1321,  1321,  1322,  1322,  1323,  1323,
    1324,  1324,  1325,  1325,  1325,  1326,  1326,  1327,  1327,  1327,
    1327,  1327,  1327,  1327,  1328,  1328,  1329,  1329,  1330,  1330,
    1331,  1331,  1332,  1332,  1333,  1334,  1334,  1335,  1335,  1336,
    1337,  1337,  1338,  1339,  1339,  1340,  1340,  1341,  1341,  1342,
    1342,  1343,  1343,  1344,  1345,  1345,  1345,  1345,  1345,  1345,
    1345,  1345,  1345,  1345,  1345,  1346,  1346,  1347,  1347,  1348,
    1349,  1351,  1350,  1353,  1352,  1352,  1354,  1354,  1355,  1355,
    1356,  1356,  1357,  1357,  1359,  1358,  1360,  1361,  1361,  1362,
    1363,  1362,  1364,  1365,  1364,  1366,  1366,  1366,  1366,  1366,
    1366,  1366,  1366,  1367,  1368,  1369,  1370,  1370,  1371,  1372,
    1372,  1373,  1373,  1373,  1374,  1375,  1376,  1376,  1377,  1378,
    1378,  1378,  1380,  1379,  1381,  1381,  1381,  1381,  1381,  1381,
    1381,  1381,  1381,  1381,  1381,  1381,  1382,  1382,  1382,  1382,
    1383,  1383,  1383,  1384,  1384,  1384,  1385,  1385,  1385,  1386,
    1386,  1387,  1387,  1387,  1387,  1387,  1387,  1388,  1388,  1389,
    1389,  1390,  1390,  1391,  1391,  1392,  1393,  1393,  1394,  1394,
    1395,  1395,  1396,  1397,  1398,  1399,  1400,  1400,  1401,  1401,
    1402,  1402,  1402,  1403,  1403,  1404,  1404,  1404,  1405,  1405,
    1405,  1405,  1406,  1407,  1407,  1408,  1408,  1409,  1409,  1410,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1412,  1413,  1414,
    1415,  1415,  1416,  1416,  1417,  1418,  1419,  1419,  1420,  1421,
    1422,  1422,  1423,  1423,  1423,  1424,  1424,  1425,  1425,  1426,
    1427,  1427,  1428,  1428,  1429,  1429,  1430,  1430,  1431,  1431,
    1432,  1432,  1433,  1433,  1434,  1434,  1435,  1435,  1436,  1437,
    1438,  1438,  1438,  1438,  1439,  1439,  1440,  1440,  1441,  1441,
    1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,  1443,
    1443,  1443,  1443,  1443,  1443,  1443,  1443,  1443,  1444,  1444,
    1444,  1445,  1445,  1445,  1445,  1446,  1446,  1446,  1447,  1447,
    1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,
    1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,
    1448,  1448,  1448,  1448,  1448,  1449,  1449,  1450,  1450,  1450,
    1450,  1450,  1451,  1452,  1453,  1454,  1454,  1454,  1454,  1454,
    1454,  1454,  1454,  1455,  1455,  1455,  1455,  1455,  1455,  1455,
    1455,  1456,  1457,  1457,  1457,  1458,  1458,  1459,  1459,  1459,
    1460,  1461,  1461,  1461,  1461,  1462,  1463,  1464,  1464,  1465,
    1465,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1467,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1469,  1469,  1469,  1469,  1469,  1469,
    1469,  1469,  1470,  1470,  1470,  1471,  1473,  1472,  1474,  1472,
    1475,  1472,  1476,  1472,  1477,  1477,  1477,  1478,  1478,  1479,
    1479,  1479,  1480,  1480,  1481,  1481,  1482,  1484,  1485,  1483,
    1486,  1487,  1487,  1488,  1489,  1489,  1489,  1489,  1489,  1490,
    1491,  1491,  1492,  1493,  1494,  1494,  1494,  1494,  1495,  1495,
    1496,  1496,  1497,  1498,  1498,  1498,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1500,  1500,  1500,  1500,  1500,  1500,
    1500,  1500,  1500,  1500,  1500,  1500,  1500,  1500,  1500,  1500,
    1500,  1500,  1500,  1500,  1501,  1501,  1502,  1503,  1504,  1504,
    1505,  1505,  1506,  1506,  1507,  1507,  1508,  1508,  1509,  1510,
    1510,  1511,  1511,  1512,  1513,  1513,  1513,  1514,  1514,  1515,
    1516,  1517,  1518,  1519,  1519,  1520,  1520,  1520,  1520,  1520,
    1520,  1521,  1521,  1521,  1523,  1522,  1524,  1524,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1527,  1526,  1529,
    1528,  1531,  1532,  1530,  1533,  1533,  1533,  1534,  1534,  1534,
    1534,  1534,  1534,  1535,  1535,  1536,  1537,  1538,  1538,  1539,
    1539,  1540,  1540,  1541,  1541,  1541,  1542,  1542,  1542,  1542,
    1542,  1542,  1542,  1542,  1542,  1542,  1543,  1543,  1543,  1543,
    1543,  1543,  1543,  1543,  1543,  1543,  1543,  1543,  1543,  1543,
    1544,  1545,  1545,  1547,  1546,  1548,  1548,  1549,  1549,  1550,
    1551,  1551,  1552,  1552,  1552,  1552,  1553,  1553,  1553,  1554,
    1554,  1555,  1557,  1558,  1556,  1559,  1559,  1560,  1560,  1561,
    1561,  1561,  1561,  1561,  1561,  1561,  1562,  1562,  1563,  1563,
    1564,  1564,  1565,  1565,  1566,  1567,  1568,  1569,  1569,  1570,
    1571,  1571,  1572,  1573,  1573,  1575,  1574,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576
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
       5,     7,     4,     6,     0,     3,     1,     1,     4,     4,
       4,     4,     4,     4,     1,     1,     1,     1,     4,     4,
       2,     2,     2,     2,     2,     1,     1,     2,     1,     1,
       1,     2,     4,     6,     6,     3,     5,     5,     3,     1,
       1,     3,     1,     3,     1,     3,     0,     0,    11,     0,
       2,     0,     0,     0,     9,     0,     3,     0,     0,    10,
       0,     1,     0,     1,     1,     2,     0,     3,     0,     3,
       0,     1,     1,     2,     0,     3,     0,     3,     3,     1,
       4,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       0,     3,     0,     3,     0,     4,     0,     4,     0,     4,
       2,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     4,     6,     4,     3,     6,     3,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     4,     1,     1,     1,     4,     3,
       6,     3,     6,     1,     1,     2,     2,     1,     2,     2,
       1,     3,     1,     2,     2,     2,     4,     2,     2,     4,
       0,     8,     0,     1,     1,     1,     0,     1,     2,     0,
       1,     2,     0,     1,     2,     0,     1,     3,     0,     2,
       0,     0,     8,     0,     0,     3,     0,     0,     7,     5,
       2,     2,     0,     5,     4,     1,     3,     3,     3,     1,
       0,     2,     1,     0,     1,     1,     2,     0,     4,     0,
       4,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     1,
       3,     1,     3,     2,     4,     1,     1,     1,     0,     4,
       5,     6,     0,    10,     3,     2,     2,     1,     1,     0,
       2,     1,     2,     3,     3,     3,     3,     1,     1,     1,
       1,     0,     3,     1,     0,     3,     2,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     7,     1,     1,     2,     2,     2,
       3,     4,     0,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     0,     0,     0,     0,
      13,     1,     0,     0,     6,     2,     1,     2,     2,     2,
       1,     1,     2,     1,     0,     3,     2,     1,     1,     1,
       0,     0,     0,    14,     0,     5,     1,     0,     3,     0,
       7,     0,     5,     1,     2,     0,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     0,     0,     7,     1,     2,     0,     3,     0,
       4,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     2,     2,     2,
       5,     8,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     2,     2,     3,     6,     1,     3,     1,     1,     1,
       3,     6,     9,     1,     1,     1,     1,     2,     0,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     2,     0,     1,     1,     4,     1,     3,     1,     3,
       7,     0,     7,     0,     6,     3,     1,     3,     1,     2,
       5,     0,     7,     0,     2,     0,     1,     5,     2,     5,
       0,     5,     6,     4,     0,     1,     1,     5,     0,     2,
       0,     5,     4,     2,     1,     3,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     5,     1,     1,     2,     4,     6,     2,     1,
       0,    11,     0,     2,     5,     0,     1,     0,     2,     1,
       2,     0,     3,     1,     0,     4,     0,     2,     1,     3,
       1,     1,     3,     4,     4,     2,     1,     1,     1,     0,
       1,     7,     2,     2,     2,     2,     2,     1,     2,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       4,     0,     4,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     1,     0,     4,     1,     2,     2,     2,     0,
       1,     1,     2,     2,     0,     2,     0,     4,     3,     5,
       0,     2,     4,     1,     1,     1,     1,     1,     0,     1,
       1,     3,     2,     5,     2,     5,     5,     5,     5,     5,
       5,     0,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       1,     1,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     0,
       3,     2,     0,     0,     0,     0,     0,     0,    15,     0,
       2,     2,     0,     1,     0,     0,     0,     0,     0,     0,
      15,     2,     0,     0,     0,    10,     0,     1,     3,     3,
       2,     4,     3,     3,     3,     1,     2,     2,     2,     2,
       1,     1,     0,     0,     8,     0,     0,     9,     0,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     0,     1,
       1,     2,     2,     2,     8,     2,     2,     4,     2,     0,
       1,     1,     3,     2,     2,     1,     1,     3,     1,     1,
       2,     1,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     1,     3,     1,     3,
       2,     4,     1,     3,     1,     2,     4,     1,     3,     1,
       1,     1,     2,     3,     4,     2,     4,     0,     2,     2,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     6,     6,     0,     1,     0,     1,     2,
       1,     0,     5,     0,     5,     1,     0,     3,     1,     3,
       1,     3,     1,     1,     0,     4,     1,     2,     1,     0,
       0,     3,     0,     0,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     4,     3,     3,     1,     3,     2,     1,
       1,     0,     1,     1,     1,     1,     0,     1,     3,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     6,     4,     4,
       1,     1,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     2,     1,     1,     2,     1,     1,     0,     3,     1,
       3,     1,     3,     1,     1,     6,     0,     3,     1,     3,
       0,     1,     4,     5,     2,     1,     1,     4,     1,     3,
       4,     4,     4,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     4,     0,     1,     0,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     4,     1,     3,     1,     1,
       1,     2,     1,     1,     2,     2,     1,     3,     2,     2,
       1,     3,     1,     2,     4,     1,     2,     1,     3,     4,
       0,     1,     0,     1,     0,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     2,     2,     0,     2,     1,     1,
       5,     3,     5,     3,     1,     3,     1,     1,     0,     1,
       3,     3,     3,     6,     4,     4,     4,     4,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     1,     4,     1,     5,     5,     1,     1,     1,     1,
       1,     4,     1,     4,     6,     4,     1,     4,     1,     7,
       1,     1,     1,     4,     6,     0,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     5,
       3,     5,     7,     3,     1,     1,     3,     5,     3,     5,
       7,     1,     0,     3,     5,     1,     2,     2,     4,     3,
       1,     1,     1,     1,     1,     2,     2,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     3,     0,     7,     0,     8,
       0,     6,     0,     8,     0,     1,     2,     1,     3,     1,
       3,     5,     1,     1,     1,     1,     1,     0,     0,     9,
       5,     1,     1,     6,     0,     3,     1,     3,     4,     1,
       0,     2,     4,     6,     0,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     4,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     5,     5,     5,     5,     5,
       4,     4,     3,     4,     1,     3,     1,     5,     7,     5,
       0,     2,     1,     1,     0,     3,     1,     3,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     0,     4,     1,     2,     1,     1,
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
       3,     1,     0,     0,     6,     0,     2,     0,     1,     1,
       2,     2,     1,     1,     4,     3,     1,     2,     5,     2,
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
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     814,     0,  2191,     0,     0,     0,   864,   180,     0,   840,
     843,   178,   183,   818,     0,   812,   815,   816,   819,   822,
     823,   821,   860,   861,   863,   820,   135,   132,     0,   128,
     130,   129,   133,  2219,   701,   641,   310,  1674,  1672,   858,
     176,   186,   859,   179,     1,   824,   817,   862,   127,   131,
     134,     0,     0,   618,     0,     0,   177,   867,   933,   619,
     868,   869,   865,   653,   925,     0,   926,   934,   932,   186,
     181,   199,     0,   184,   200,   235,     0,   845,  1224,     0,
       0,   844,   136,  1212,   852,     0,     0,   836,   838,   835,
     837,   813,   825,   826,   846,   829,   830,   831,   834,   832,
     833,   839,     0,  1673,   927,   866,     0,     0,   941,   939,
     940,   929,   928,   308,   186,  1148,   193,   187,   186,   192,
     232,     0,   700,     0,     0,     0,     0,   176,   567,   902,
     827,     0,   342,   328,   202,   314,   279,   298,   319,   321,
     318,     0,   340,     0,   327,   320,   324,   330,   329,   186,
     331,   311,   334,   312,   313,   938,   937,     0,    22,    23,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     947,     0,   525,   517,    16,   524,   933,    15,     0,   945,
       0,   309,     0,   185,  1149,   182,     0,   199,   201,   273,
     204,   261,   267,   268,   252,   225,   263,   202,   240,   241,
       0,   227,   279,   298,   250,   253,   248,     0,   223,     0,
     259,   251,   256,   266,   265,   186,   269,   186,   238,   239,
     236,   272,     0,     0,     0,     0,   853,   176,   176,     0,
       0,   203,     0,     0,   332,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,   277,     0,   935,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     531,     0,     0,     0,   654,   444,   446,  1219,     0,     0,
       0,  1639,     0,   438,     0,     0,     0,   437,     0,   454,
     527,     0,     0,     0,     0,     0,   530,     0,   403,   402,
     409,   450,   447,   404,   405,   407,   408,   445,   448,   453,
     526,   499,   496,   505,   502,     0,     0,    17,    18,    19,
      20,    21,     0,    14,   490,     0,     0,   943,     0,   188,
     191,   189,   190,     0,   196,   195,   194,   197,   205,   206,
     207,   210,   274,   186,   274,     0,     0,     0,     0,   186,
     270,   271,     0,     0,   186,     0,   274,     0,     0,   249,
     233,  1225,     0,     0,  1213,  2225,   568,   903,   847,     0,
     214,   215,     0,     0,   291,   293,   288,   289,   285,   287,
     284,   286,   283,     0,   293,   304,   305,   301,   303,   300,
     302,   295,     0,     0,     0,   344,     0,   347,   349,   222,
       0,   221,     0,   186,     0,     0,   552,   623,     0,     0,
       0,     0,     0,     0,     0,     0,   549,   535,   540,     0,
     536,   539,   538,   632,     0,   631,   554,     0,    11,   172,
     436,   411,   410,     0,  1154,     0,     0,   452,  1647,  1645,
    1646,  1642,  1644,  1641,  1643,  1635,     0,     0,     0,   451,
       0,     0,     0,     0,     0,     0,     0,   655,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   532,   533,   534,   465,     0,     0,   464,   474,     0,
       0,   415,     0,     0,   416,   406,   412,   414,   417,   418,
     419,   420,   421,   413,   443,   442,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   946,     0,   930,   198,
       0,     0,   262,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,   186,   234,   237,   958,
     699,   870,   958,     0,  2223,  2225,  1148,  1771,   841,     0,
     958,     0,     0,   315,   280,     0,     0,   290,   307,   281,
     306,     0,   299,     0,   322,     0,   316,     0,   341,     0,
     346,   336,     0,     0,   325,   278,   335,     0,     0,   523,
       0,     0,   520,   519,   522,   518,   529,   514,   514,     0,
     537,     0,   541,     0,   298,     0,   521,   528,   282,     0,
    1220,  1714,     0,     0,     0,     0,     0,   439,     0,     0,
     455,     0,     0,     0,     0,   457,   456,   475,   466,   481,
     484,   485,   482,   488,   487,   486,   476,   477,   478,   479,
     480,   422,   467,   471,   489,   483,   470,   489,   449,   500,
     497,   506,   503,   512,     0,   491,    94,    95,    97,   493,
       0,     0,   235,     0,     0,     0,   242,   243,     0,   246,
       0,     0,   254,     0,   244,   224,   208,     0,   257,   276,
     964,     0,   959,   960,   958,     0,   854,  2224,  2222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2206,     0,  1340,  1339,     0,  1341,
       0,   396,  1338,  1255,     0,     5,  1337,   397,   394,     0,
     399,   174,   489,  1125,     0,     0,  1347,   124,   393,   392,
       0,     0,   387,   489,     0,  1291,  2199,     0,   398,   361,
       0,     3,     2,     0,   395,  1252,     0,     0,   388,   385,
     400,     0,     0,     0,     0,  1345,  1335,   391,     0,     0,
       0,     0,     0,     0,     0,     0,  1334,     0,     0,     0,
     175,     0,   384,   383,     0,     0,  2203,  2202,     0,     0,
       0,   137,     0,   390,   389,     0,     0,   386,   489,     0,
       0,   489,     0,   561,     0,     0,     0,     0,     0,     0,
     489,   801,  1222,     0,     0,  1136,     0,  2192,     0,   104,
       0,     0,   874,     0,     0,     0,     0,   802,     0,     0,
    1794,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     670,     0,     0,  2227,  2228,  2229,  2230,  2231,  2232,  2233,
    2234,  2235,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,
    2244,  2245,  2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,
    2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,
    2264,  2265,  2266,  2267,  2268,  2269,  2270,  2271,  2272,  2273,
    2274,  2275,  2276,   912,  2277,  2278,  2279,  2280,  2281,  2282,
    2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,  2292,
    2293,  1116,  1118,  1113,  1115,  1114,  1117,  2294,  2295,  1245,
    2296,  1251,  1250,  2297,  2298,  2299,  2300,  2301,  2302,  2303,
    2304,  2305,  2306,  1402,  2307,  2308,  2309,  2310,  2311,  2312,
    2313,  2314,  2315,  2226,   842,   572,     0,   907,     0,   905,
       0,   343,   216,   217,     0,   292,   297,     0,     0,     0,
       0,   345,   348,     0,   220,     0,     0,   553,     0,   627,
       0,   629,   509,     0,   510,     0,   551,     0,   548,   545,
     516,   508,   555,     0,   171,  1716,  1717,  1715,     0,   441,
    1219,     0,  1640,  1219,   440,  1219,  1219,  1219,  1219,  1219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   944,     0,   211,   275,
     226,     0,     0,   186,     0,     0,     0,     0,     0,  1226,
       0,     0,  1214,   380,   378,   379,  1249,  1054,  1053,  1058,
       0,  1614,  1615,     0,     0,  1275,   642,   643,  1276,  1606,
    1607,  1278,   828,  1088,  1093,  2201,   635,   123,  2214,     0,
       0,  1290,     7,     0,     6,     0,  2207,  1089,     0,  1182,
    1181,  1128,  1180,  1127,   433,  1348,  1336,     0,  1246,   855,
     423,  1773,  1342,   125,     0,  1092,   122,     0,   808,    24,
     637,   401,     0,   807,  1085,   809,     0,  1346,   896,   895,
     898,   894,   897,  2216,     0,   892,     0,   636,   991,   893,
    2210,     0,  2200,   121,  1248,   988,   702,   986,     0,   633,
    2195,   746,   745,   747,   743,     0,     0,  1247,  1001,   638,
    1401,     0,  2183,  2182,  1396,  1399,  2179,  2181,     0,     0,
       0,     0,  1059,  1055,     0,  1040,  1041,  1042,  1043,  1049,
    1051,  1050,  1048,  1047,     0,     0,     0,  1046,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1032,  1023,  1024,   973,     0,   971,  1073,   431,    24,
       0,  2197,   126,   634,     0,  1223,  1221,  1147,     0,  1762,
    1763,  1148,  1129,  1349,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,   933,     0,    69,     0,   102,   610,
       0,   657,   656,     0,  1119,  1008,  1123,     0,     0,  1074,
    1240,     0,     0,  1126,   662,   659,   660,     0,   664,   665,
       0,   667,   668,     0,   663,   968,   970,     0,     0,   969,
     748,   966,   713,   962,   924,     0,     0,     0,     0,   674,
     675,     0,     0,   922,   919,   920,   916,   917,   918,   911,
     915,   914,     0,     0,     0,     0,     0,     0,   576,   578,
     570,   573,   574,   909,  2225,   904,   906,   848,     0,   294,
     296,   323,   317,     0,     0,   326,   624,   626,     0,     0,
     514,   542,     0,   291,     0,     0,  1743,  1631,  1633,  1744,
    1637,  1741,     0,     0,  1740,     0,     0,     0,  1742,     0,
       0,     0,     0,     0,     0,     0,  2183,  1632,  1739,  1634,
    1728,     0,  1718,  1720,  1723,  1726,  2189,  1727,  1157,  1648,
    1156,  1155,  1158,  1160,  1159,  1153,   468,   469,   473,   458,
       0,   461,   472,     0,   460,   501,   498,   507,   504,   513,
     492,    96,   494,   931,     0,   247,   231,     0,   229,   255,
     245,   235,   258,   965,   176,   961,   871,   176,     0,     0,
       0,  1320,  1321,     0,     0,     0,  1292,  1295,  1297,  1298,
    1299,  1303,  1302,  1300,  1301,     0,     0,     0,  1293,  1294,
       0,     0,     0,     0,     0,     0,     0,     0,  1090,     0,
      24,  1177,  1179,  1178,     0,   426,   427,   424,   425,   978,
       0,     0,   366,    25,   360,     0,     0,  1082,     0,     0,
       0,     0,     0,     0,     0,   995,  1772,     0,     0,     0,
       0,     0,     0,  2197,     0,     0,   138,     0,     0,  1005,
     997,   998,  1003,     0,     0,  2180,   942,  1397,  1398,     0,
       0,   921,   429,  2173,  1018,   350,     0,     0,   562,   615,
     614,   612,   617,  1026,   616,  1031,  1027,  1030,   800,   792,
     786,   798,   799,   784,   785,   793,   788,   794,   787,   797,
     791,   795,   790,   796,   783,   789,   776,   782,  1028,  1029,
       0,  1036,  1044,  1033,  1034,  1038,  1039,  1037,  1035,  1045,
       0,     0,     0,   810,     0,     0,     0,     0,     0,   758,
     757,   754,  2198,  2205,    24,  1143,  1144,  1145,  1146,  1140,
    1138,  1236,  1148,  1130,  1131,  1134,  1150,  2193,     0,     0,
       0,     0,    98,     0,    99,     0,     0,     0,    74,     0,
       0,     0,   111,   106,     0,   658,   901,     0,   900,     0,
     489,  1121,     0,   953,   954,   977,   948,   949,   803,   975,
    1076,  1242,     0,  1244,  1243,  1850,  1967,  1963,  1969,  2001,
    1981,  1972,  1931,  1893,  2020,  1987,  1995,  1884,  1990,  1851,
    1798,  1982,  1889,  1940,  2074,  1919,  1907,  1920,  2018,  2021,
    1989,  1943,  2024,  1810,  2081,  2017,  2045,  1821,  2117,  1908,
    2090,  1803,  2050,  1819,  1879,  1926,  1946,  2040,  2068,  2073,
    1802,  1998,  2026,  1814,  1816,  1839,  1857,  1877,  1887,  1897,
    1950,  1953,  2011,  2022,  2028,  2029,  2046,  2091,  2102,  1801,
    1832,  1856,  1855,  1863,  1865,  1873,  1883,  1904,  1922,  1925,
    1951,  1959,  2015,  2025,  2035,  2041,  2042,  2044,  2069,  2099,
    2110,  1822,  1825,  1836,  1842,  1844,  1849,  1852,  1854,  1860,
    1868,  1870,  1871,  1872,  1882,  1892,  1899,  1915,  1916,  1927,
    1945,  1949,  1962,  1978,  2009,  2019,  2023,  2030,  2038,  2047,
    2057,  2061,  2078,  2084,  2088,  2096,  2101,  2104,  1845,  1964,
    2006,  1830,  1831,  1848,  1853,  1859,  1861,  1875,  1876,  1886,
    1895,  1900,  1902,  1903,  1909,  1917,  1934,  1935,  1948,  1976,
    1980,  1983,  1988,  1992,  2000,  2007,  2008,  2013,  2031,  2032,
    2037,  2043,  2048,  2054,  2055,  2056,  2058,  2060,  2062,  2071,
    2093,  2094,  2095,  2100,  2116,  1805,  1958,  1966,  1968,  2064,
    1807,  1811,  1815,  1820,  1826,  1827,  1840,  1841,  1843,  1846,
    1858,  1874,  1894,  1896,  1906,  1910,  1912,  1913,  1921,  1930,
    1932,  1933,  1944,  1957,  1975,  1993,  1994,  2010,  2012,  2016,
    2027,  2049,  2059,  2067,  2089,  2092,  2106,  2107,  2108,  1838,
    1808,  1828,  1829,  1835,  1905,  1837,  1862,  1864,  1878,  1955,
    2079,  1888,  1890,  1898,  1901,  1923,  1924,  1929,  1936,  1937,
    1938,  2119,  1970,  1971,  1974,  1979,  1984,  1991,  1996,  1997,
    1999,  2005,  2034,  2036,  2052,  2063,  2065,  2066,  2070,  2075,
    2076,  2080,  2082,  2083,  2098,  2103,  2105,  2109,  2111,  2115,
    1965,  2114,  1804,  1806,  1809,  1813,  1823,  1847,  1866,  1867,
    1869,  1880,  1911,  1914,  1954,  1960,  1973,  1977,  2112,  2113,
    2014,  2033,  2039,  2051,  2053,  2072,  2077,  2087,  2097,  1818,
    1812,  1817,  1834,  1885,  1928,  1941,  1942,  2002,  2004,  2086,
    1961,  1918,  1985,  1833,  1881,  1891,  1956,  1939,  1986,  1824,
    1947,  1952,  2085,  2003,     0,  1796,  1799,  1800,   690,     0,
       0,     0,   679,   713,   713,   710,     0,     0,   714,     0,
      26,   678,   681,     0,   688,   684,   923,   913,  1769,  1770,
    1760,  1760,  1366,     0,     0,  1675,     0,     0,  1350,     0,
       0,  1351,  1394,     0,     0,  1395,     0,     0,  1714,     0,
    1364,     0,  1413,  1412,  1411,  1409,  1410,  1408,  1406,  1403,
    1493,  1492,  1404,  1405,  1414,  1696,  1407,  1776,  1775,  1774,
    1415,  2225,  2225,   589,   580,   571,     0,   575,  2225,   908,
     176,     0,   337,   219,     0,     0,  1655,  1653,  1654,  1650,
    1652,  1649,  1651,   515,   511,     0,   547,   546,   173,  1725,
    1724,  1663,  1661,  1662,  1658,  1660,  1657,  1659,  1636,     0,
    1714,     0,     0,  1561,     0,     0,  1731,  1729,  1730,  1561,
    1561,  1561,  1561,  1732,     0,     0,     0,  1510,  1704,  1721,
       0,     0,     0,     0,  1785,  1786,  1787,  1788,  1789,  1790,
    1735,     0,     0,   463,   462,     0,     0,   186,   228,   209,
    1227,   176,  1215,     0,     0,     0,     0,     0,     0,  1467,
    1466,  1465,  1327,     0,  1333,  1329,  1331,  1322,     0,  1570,
    1319,  1315,  1289,  1288,     0,  1314,  1310,     0,  1306,  1304,
       0,  1613,     0,  1616,  1618,   646,     0,   645,  1605,     0,
    1608,  1610,  2215,  2212,     0,     0,  1256,   489,   358,  1277,
       0,     0,  1253,  1010,  1086,  1087,  1084,  1083,     0,   899,
       0,     0,   620,     0,     0,     0,   989,   987,   704,   705,
       0,   709,     0,     0,  2196,  2204,   744,     0,   142,     0,
     999,  1006,     0,     0,  1014,     0,  1400,  2186,  2188,  2187,
    2184,     0,     0,     0,  1020,   353,     0,     0,     0,     0,
      24,  1056,     0,   565,     0,     0,     0,   777,   778,  1025,
     974,   972,   811,   432,     0,  1065,   755,   756,   381,     0,
    1148,  1237,  1152,  1137,  1132,     0,     0,  1133,  2225,     0,
       0,     0,     0,     0,     0,     0,    64,    93,     0,     0,
     117,   112,     0,   107,     0,   114,   108,   885,   877,   883,
       0,  1120,     0,  1122,  1124,     0,     0,   957,     0,     0,
       0,     0,  1075,  1241,     0,     0,  1795,  1797,  2225,   661,
     666,   669,   682,   680,   639,     0,   733,   731,   737,   735,
       0,     0,   729,   773,   727,   712,   723,   721,   771,   749,
       0,   715,   725,   967,   963,     0,     0,     0,     0,   687,
       0,     0,     0,     0,     0,     0,     0,  1621,     0,  1488,
    1489,  1781,  1446,  1510,     0,     0,     0,  1779,     0,  1426,
    1421,  1420,  1433,  1432,  1437,  1437,  1435,  1436,  1427,  1422,
       0,     0,  1428,  1429,  1697,  2121,     0,     0,     0,   577,
     579,     0,     0,   592,   584,   586,     0,   581,   582,     0,
       0,   600,   602,     0,     0,   598,   910,   849,   218,     0,
     628,   630,   625,     0,   544,   543,     0,     0,  1752,     0,
       0,     0,  1563,  1564,  1562,     0,  1754,     0,     0,     0,
       0,     0,     0,     0,  1719,     0,  1499,  1500,  1502,  1505,
       0,  1511,  1512,     0,     0,  1561,  1706,  1700,  1737,  1738,
    1736,  1734,  2190,   459,   495,     0,   230,  1183,   872,  1161,
       0,     0,     0,     0,  1327,     0,     0,     0,  1323,     0,
       0,     0,  1317,  1601,  1599,  1568,  1580,  1582,  1586,  1588,
    1579,  1573,  1578,  1592,  1571,  1600,  1576,  1591,  1577,  1598,
    1590,  1473,  1565,  1566,  1567,     0,  1312,  1308,     0,     0,
    1296,     0,     0,   644,     0,     0,     0,  2211,     0,     4,
       8,    10,     0,   489,   428,     0,     0,     0,  1007,     0,
       0,     0,     0,     0,     0,     0,     0,   703,     0,     0,
     159,   157,     0,     0,   139,     0,   149,   155,   713,   144,
     146,     0,  1004,  1015,  1016,     0,     0,     0,   430,     0,
    2174,  2175,  1019,     0,     0,  1017,   352,   357,   622,   351,
       0,   354,   359,     0,   489,  1372,   613,   611,     0,   780,
    1064,  1066,     0,   382,  1141,  1139,     0,  1151,  1135,     0,
       0,  1232,     0,     0,     0,   100,     0,     0,    75,    81,
      71,  2225,  2225,   110,   105,   119,   115,     0,   109,   774,
     886,   639,  2225,   876,   875,   884,  1009,     0,     0,   955,
     956,   950,   976,   489,  1081,  1077,  1078,  1080,  2118,  2120,
     691,   685,   683,     0,    24,     0,  2225,  2225,  2225,  2225,
     739,   717,   741,   719,  2225,  2225,  2225,  2225,     0,   711,
     716,  2225,   639,   769,   767,   770,   768,     0,     0,    46,
      44,    41,    35,    39,    43,    38,    31,    40,     0,    34,
      37,    32,    42,    33,    45,    36,     0,    29,    47,   761,
       0,   689,  1761,     0,  1759,  1714,  1757,  1701,  1702,  1694,
    1680,  1695,     0,     0,     0,  1052,  1487,  1490,     0,     0,
       0,  1384,  1356,  1784,  1783,  1782,     0,     0,     0,  1431,
    1434,     0,     0,     0,     0,     0,  1379,     0,  1378,     0,
    1380,  1375,  1376,  1377,  1368,  1369,     0,     0,     0,   591,
     596,     0,     0,  2225,  2225,   569,   583,   606,   594,   608,
    2225,  2225,   604,   588,   599,   841,   338,     0,  1670,  1668,
    1669,  1665,  1667,  1664,  1666,  1638,     0,     0,     0,  1753,
       0,     0,     0,  1751,     0,     0,     0,     0,  1733,  1750,
       0,  1503,     0,  1630,  1506,     0,     0,     0,     0,  1498,
    1516,  1518,  1520,  1560,  1559,  1558,  1522,  1538,     0,  1513,
    1514,  1709,  1279,     0,     0,     0,   212,     0,  1209,  1228,
     841,     0,  1216,  1209,     0,  1622,     0,  1455,     0,  1458,
    1625,     0,  1463,     0,     0,  1324,  1325,     0,     0,  1328,
    1330,  1332,     0,  1316,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1471,  1470,  1469,     0,  1474,  1475,
       0,  1311,     0,  1305,  1307,  1617,     0,  1619,  1609,     0,
    1611,  2213,  1285,     0,  1281,     0,     0,  1286,   856,     0,
       0,     0,     0,     0,  1343,  2218,  2217,   621,     0,     0,
      48,     0,   706,   708,   707,  1344,   713,  2225,  2225,   151,
     647,   161,   153,   163,   143,   150,  2225,     0,     0,     0,
       0,     0,  2185,     0,     0,     0,     0,     0,     0,  1057,
       0,  1373,   563,     0,   779,  1062,     0,  1238,  1239,  2194,
       0,    93,     0,    65,     0,     0,     0,    78,     0,    93,
      93,   118,   113,  2225,  2225,   103,     0,   887,   881,   889,
     888,   878,   559,   936,     0,     0,     0,   693,   672,   686,
     640,   750,     0,   734,   732,   738,   736,     0,  2225,     0,
    2225,   730,   728,   724,   722,   772,   726,    24,   762,     0,
       0,     0,    27,     0,  1764,     0,  1681,     0,     0,  1693,
    1676,  1692,  1491,     0,  1448,     0,  1383,     0,     0,  1780,
       0,  1777,     0,  1439,  1443,  1419,  1441,  1444,     0,  1430,
    1698,     0,     0,     0,     0,     0,     0,  2122,  1382,  1381,
    1370,  1365,  1367,  1418,     0,     0,   593,   590,   585,   587,
       0,  2225,  2225,   601,   603,  2225,  2225,     0,  1656,     0,
       0,     0,     0,     0,  1749,  1755,  1745,  1746,  1747,  1748,
    1507,     0,  1501,  1521,  1525,     0,  1538,  1524,     0,     0,
    1539,  1554,  1551,  1552,  1549,  1557,  1556,  1550,  1553,     0,
       0,     0,     0,     0,  1555,     0,     0,     0,  1495,  1496,
    1722,     0,  1515,  1509,  1280,  1707,  1389,  1385,  1386,  1391,
    1390,  1705,  1279,     0,  1207,  1208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1206,     0,     0,
    1194,  1195,  1196,  1193,  1198,  1199,  1200,  1197,  1184,  1175,
       0,     0,  1231,     0,  2225,     0,  1170,     0,     0,     0,
       0,     0,     0,     0,  1162,  1163,     0,  1094,  1626,     0,
    1627,     0,     0,     0,     0,  1462,  1461,  1327,  1460,  1452,
    1318,  1602,     0,     0,     0,     0,     0,     0,  1603,  1595,
       0,     0,     0,  1595,  1631,  1468,  1481,  1486,     0,  1483,
    1480,  1482,     0,  1484,  1472,  1476,  1477,  1327,  1313,  1309,
       0,     0,  1284,  1283,     0,  1268,     9,     0,  1258,   857,
    1091,   364,  1258,     0,     0,  2209,     0,     0,   990,    49,
       0,   759,   160,   158,     0,  2225,     0,     0,     0,  2225,
     156,   145,     0,   148,   147,     0,   996,  1000,   985,  2178,
    2177,  2176,     0,     0,   356,     0,   566,     0,  2225,   781,
       0,   639,  1142,     0,  1233,    70,     0,     0,   101,    68,
      93,    76,    82,     0,   120,   116,   775,  2225,   891,   639,
     890,     0,   556,     0,   805,   806,   804,  1079,   696,   694,
       0,   676,   673,     0,   740,   718,   742,   720,   751,   765,
     766,   763,   764,    30,    28,     0,  1758,  1710,  1682,  1678,
    1677,     0,  1447,  1714,  1450,     0,  1358,  1353,  1352,  1355,
       0,     0,  1438,     0,     0,  1710,     0,     0,  2155,  2153,
       0,     0,  2141,  2152,     0,     0,  2154,     0,     0,     0,
       0,     0,  2183,  2151,  2147,     0,  2139,  2142,  2143,  2150,
    2146,  2170,     0,  2132,  2131,  2135,  2137,     0,  2130,     0,
    2133,  2124,     0,     0,   597,   595,   607,   609,   605,     0,
       0,     0,  1713,     0,  1793,     0,     0,  1504,  1523,  1517,
    1519,  1526,  1528,  1526,     0,  1533,  1526,     0,  1531,  1526,
       0,  1541,  1540,     0,  1542,     0,  1494,     0,  1393,  1392,
    1388,  1708,   235,  1201,  1202,  1203,  1205,  1188,  1186,  1185,
    1189,  1190,  1187,  1204,  1191,  1192,  1176,   982,  1211,   979,
       0,     0,  1229,     0,  1174,  1173,  1168,  1166,  1165,  1169,
    1167,  1171,  1172,  1164,  1217,     0,  1453,  1459,  1629,  1622,
    1464,  1326,  1569,  1581,     0,  1583,  1585,     0,  1587,     0,
       0,     0,  1593,  1572,  1597,     0,  1454,  1456,     0,  1478,
    1479,  1620,  1612,  1282,     0,     0,  1274,  1269,  1270,  1287,
       0,  1265,  1266,     0,     0,  1279,  1259,  1260,     0,    24,
    1254,     0,     0,  1013,     0,    50,   993,     0,    24,   162,
     152,     0,   649,   651,   164,   154,   759,     0,  1022,     0,
     355,  1374,     0,  1063,    24,     0,     0,    66,     0,    79,
      88,     0,    72,   882,   879,   560,  2225,   951,     0,  2225,
     692,   671,   677,   639,  1768,     0,  1766,     0,     0,  1683,
    1679,  1449,     0,  1451,  1445,     0,  1357,     0,  1778,  1440,
    1442,  1417,     0,  2145,  2144,     0,     0,  1561,     0,  1561,
    1561,  1561,  1561,  2148,     0,     0,  2128,     0,     0,     0,
       0,  2157,  2129,     0,     0,     0,     0,     0,     0,  2123,
    1371,  1423,   851,   850,   339,  1671,  1791,  1792,  1508,     0,
    1545,  1547,     0,  1534,  1537,  1536,  1544,     0,  1546,  1526,
       0,  1497,  1387,   213,   984,   983,   981,     0,  1210,  1095,
    1099,  1101,     0,  1105,     0,  1103,  1107,  1096,  1097,     0,
     873,     0,     0,  1623,  1628,     0,     0,  1604,  1596,  1574,
       0,  1575,     0,     0,  1272,  1267,  1273,  1271,  1264,  1263,
    1262,  1257,  1261,   365,   362,     0,  1011,     0,     0,     0,
     992,   760,   140,   648,    24,  1002,  1021,   564,  1060,    67,
    1234,    84,     0,     0,    77,    88,    88,  2225,   557,     0,
       0,   695,   752,     0,  1765,  1711,  1704,     0,  1359,     0,
    1704,  2168,     0,     0,  2171,     0,     0,     0,     0,     0,
       0,     0,  2140,  2159,  2160,  2158,  2156,  2138,     0,  2134,
    2136,  2125,  2126,  1424,     0,  1416,  1527,  1756,  1529,     0,
    1532,  1530,  1548,     0,   980,  2225,  2225,  1109,  2225,  1111,
    2225,  2225,  1098,  1230,  1218,     0,  1584,     0,  1594,     0,
    1485,   367,  1012,  2208,     0,     0,     0,     0,     0,     0,
      55,     0,    54,     0,    52,     0,     0,   141,  1067,    88,
      93,    88,    89,    83,    73,   880,     0,     0,   697,    24,
    1767,  1703,  1712,  1363,     0,  1360,  1362,  1684,  2169,     0,
       0,  2167,     0,     0,     0,     0,  2149,  2166,     0,  1425,
    1535,  1543,  1100,  1102,  2225,  1106,  2225,  1104,  1108,  1624,
    1589,  1457,   369,   374,   372,   363,     0,   370,   376,    57,
      62,    59,    61,    58,    60,    56,     0,    51,     0,   650,
     652,  1071,  1061,     0,  1069,  1235,    85,    80,   558,   952,
    2225,   753,     0,  1354,     0,  1685,  1699,  2165,  2172,  2161,
    2162,  2163,  2164,     0,  1110,  1112,  2225,  2225,   368,   371,
    2225,    53,     0,  2225,  1068,  1070,     0,   693,  1361,     0,
    1689,  1686,  1687,  2127,   375,   373,   377,     0,  1072,    86,
     698,     0,     0,     0,   994,    90,     0,  1690,  1688,    92,
       0,    87,     0,    91,  1691
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   823,   824,   825,   826,  1043,  2369,  2370,   180,   322,
     181,  1392,  1393,  2206,  2526,  3532,  3028,  3029,  3438,  3533,
    3534,   827,  1182,  3066,  2770,  3456,  2147,  2768,  3310,  3070,
    3452,  2769,  3311,  3540,  3636,  3655,  3454,  3661,   645,   646,
     647,  1513,  2444,   828,  1524,  1187,  1522,  2155,  2454,  2152,
    2452,  2457,  2774,  1523,  2451,  2156,  2773,   829,     9,    28,
      29,    30,    31,    32,    88,   832,  1106,  2088,  1416,  2394,
    2398,  2399,  2395,  2396,  3035,  3039,  2736,  2728,  2727,  2729,
    2732,   494,   270,   599,   833,    55,    56,    11,    41,   115,
      70,    71,    72,    73,   196,   336,    74,    75,   242,   341,
     228,  1006,   520,  2923,   372,   934,  2269,   400,   401,   229,
     354,   343,   349,  1337,  1338,   119,   538,   120,   121,   360,
     230,   356,   342,   344,   522,   231,   256,   576,   244,   247,
     245,   246,   382,   554,   555,   557,   562,   937,   248,   249,
     391,   559,   192,    12,    51,   151,   152,   153,   943,  2867,
     154,   252,   240,   394,   395,   396,   397,  2110,   834,   835,
     836,   837,  1064,  3521,  3279,  1394,  3585,  3586,  3587,  3627,
    3626,  3630,   838,   839,   840,   841,   842,   843,   844,  1054,
     495,  1059,  1386,  1387,  1431,  1157,  1432,   297,   298,   299,
     300,   301,   302,   303,   452,   496,  1320,   497,   498,   499,
     500,   501,   502,   503,   983,   182,   514,   993,   995,  2005,
     183,   508,   989,   507,   988,   510,   991,   509,   990,   952,
     961,   304,   305,   185,   306,   419,   420,   421,   422,   405,
     424,   845,  3316,  3546,  3082,   846,  1124,  2113,  3058,  2425,
      89,   237,   548,  1934,  1250,  1251,  1252,  1931,  1932,  2256,
    2257,  2258,  2583,  2584,  1935,  1936,  2252,  2587,  2579,  2264,
    2265,  2590,  2591,  2865,  2861,  2862,   847,  1443,    57,  2073,
    2074,  2419,   406,   426,  1098,  1162,  1035,  1086,  1069,  1108,
    2484,   186,  1036,  1026,  2046,  2731,    59,   307,   848,  1192,
     849,  1205,  1206,   850,   851,   852,   853,  1213,  3091,  1234,
    3321,  1235,  2182,  1236,  2481,  1237,  2788,  1238,  2209,   854,
    2178,  2787,  3090,  3319,  3318,  3610,    90,    13,   855,  1410,
    2078,  2079,  2080,  2199,  1879,  2200,  2201,  2798,  2800,  2497,
    2496,  2501,  2495,  2494,  2487,  2486,  2489,  2488,  2491,  2493,
     856,   857,  1104,   858,  1875,  1220,  3549,   859,  1491,  3288,
    2528,  2529,  2202,  2498,  2460,  2776,  1151,  1471,  2117,  2428,
    2118,  1467,   860,   861,  1198,  2170,  3086,   862,   863,   864,
     865,    14,    45,    15,    16,    17,    91,    92,   866,    93,
      18,   925,    19,    94,    95,   131,   550,  1940,  2595,  3373,
      96,   127,   365,   867,  2709,    20,    21,    22,    23,    24,
      40,    62,    97,   674,  2011,  2650,   868,  1193,  2464,  2159,
    2462,  3457,  3077,  2160,  2461,  2779,  3079,   869,   870,   871,
    1080,  1081,  1527,    98,   238,   549,   928,   929,  1254,  1938,
     872,  1239,  1240,   873,  1887,  1241,   308,    64,    65,    66,
      67,  1534,   157,   111,    68,  1113,   108,   188,   189,  1535,
    1536,  2471,  1537,   671,   672,  1222,   673,  1223,  1155,  1156,
    1538,  1539,  1390,  3218,  3219,  3396,  2099,  1096,  1097,   874,
    1405,  3440,   875,  3047,   876,  1420,  1421,  1422,  2094,  2092,
     877,   878,  2378,  2405,   879,  2104,  2415,   880,  1152,  1153,
     881,  1019,   882,  2539,   883,  3538,  3061,   884,  2432,  3602,
    3603,  3604,  3633,  1159,   885,  1540,  2172,  2475,  2476,   886,
    2066,  1034,  1379,   887,   888,   889,  2652,  3222,  3407,  3408,
    3505,  3506,  3510,  3508,  3511,  3574,  3576,   890,   891,  1529,
    2164,   892,  1531,  1502,  1503,  1504,  2137,   893,  1172,   894,
     895,  2130,  1499,  1168,   195,  1505,  1506,   309,  2653,  2964,
    2965,  2948,  1051,  1052,  2648,  2949,  2952,    99,   126,   542,
    1347,  2319,  2966,  3411,   434,   896,  1166,   100,   123,   539,
    1344,  2317,  2953,  3409,  2649,  1186,  2761,  3306,  3539,  2132,
     897,   898,   899,   900,   901,  1067,  2376,  1045,  2372,  3275,
    3276,  3277,  3424,  3266,  3267,  3268,   902,  2915,  2703,  2704,
    2706,  2030,   903,   904,  1356,  1357,  1358,  2039,  2358,  1359,
    2355,  2036,  1360,  2331,  2031,  1361,  1362,  1363,  2323,  2328,
    1364,  2025,  2026,   905,  1076,  1056,   906,  1912,  1913,  2224,
    3118,  3337,  2828,  3115,  3554,  3555,  1914,  2246,  1893,  2575,
    2851,  3162,  2752,  3057,  2576,  1915,  1916,  2306,  2917,  2918,
    2919,  3200,  1917,  1918,  1428,   907,  1114,   908,  1247,  1919,
    1920,  2240,  3495,  2241,  2242,  2243,  2559,  2832,  2835,  2836,
    1921,  2549,  2823,  3334,  2019,  2020,  3003,  2656,  3256,  2657,
    2021,  2661,  2032,  2688,  2033,  2689,  3004,  3005,  3006,  3007,
    1922,  2218,  2219,  2546,  1923,  2912,  2639,  2908,  2301,  1987,
    2296,  2297,  2298,  2881,  1988,  2302,  2640,  2913,  2629,  2630,
    2631,  2632,  2633,  3380,  3181,  3496,  2634,  3382,  3383,  2906,
    2635,  2907,  2636,  2285,  2351,  2352,  2353,  3250,  2354,  2982,
    2989,  3418,  2658,  1023,  2837,  2970,  3155,  2660,  2624,  1298,
     310,  1299,  1968,   445,   953,  1953,  1969,  2605,    39,   909,
     910,  3110,  3330,  2816,  3329,  3616,  3641,  3642,  2820,  2540,
    1924,  2541,  2564,  3125,   602,  2536,  2537,  2307,  2642,  3328,
    3114,  1300,   968,  1301,  1302,  2909,  2637,  1304,  1305,  2287,
    3498,   911,   912,  2211,  2538,  3106,  3325,  3326,  1890,   913,
    1062,  1926,  1927,  2228,  2830,  1928,  1929,  2555,  2000,  2280,
     914,  1201,  1864,  1865,  1866,  2174,  1867,  2175,  1930,  2565,
    3161,  3369,  2847,  3158,  3159,  3160,  3157,  3145,  3146,  3147,
    3148,  3149,  3150,  3475,   915,  2102,  2410,  2411,  1115,  1306,
    1117,  2100,  1307,    25,   917,  1174,  2138,  1413,  1493,   918,
     919,  2720,   920,  2367,  1039,  2053,   921,   922,    35,   543,
     544,   545,   546,   547,   923
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2957
static const short yypact[] =
{
     903,  1428, -2957,   415,   415,  1208, -2957, -2957,  1208, -2957,
     150, -2957, -2957, -2957,   499, -2957,   903, -2957, -2957, -2957,
   -2957, -2957,  -134, -2957, -2957, -2957, -2957, -2957,   455,   556,
   -2957,   634, -2957, -2957, -2957, -2957, -2957, -2957,   -95, -2957,
    1096,   201, -2957, -2957, -2957,   291, -2957, -2957, -2957, -2957,
   -2957,   -30,   415, -2957,   415,   542,   150, -2957,   971, -2957,
   -2957, -2957, -2957, -2957, -2957,   916,    37, -2957, -2957, -2957,
     683,   359,   415, -2957, -2957,   801,   415, -2957, -2957,   415,
     415, -2957, -2957, -2957, -2957,   415,   415, -2957, -2957, -2957,
   -2957, -2957,   291, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957,  5236, -2957,    37, -2957,  1048,  3348, -2957, -2957,
     370, -2957, -2957,   889,   201,   355, -2957, -2957, -2957, -2957,
   -2957,  9685, -2957,   415,   481,   823,   415,   150, -2957, -2957,
   -2957,   415, -2957, -2957,   685,   523,   901, -2957, -2957,   643,
   -2957,   651, -2957,   583, -2957, -2957,   660, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957,   594, -2957, -2957,
   -2957,   670,   697,   708,   713,   716,   721,   724,   729,   735,
     746,  3348,   749,  4701,   773,   778,   826,   839,   847,   852,
    1904,  1321, -2957, -2957, -2957, -2957,   564, -2957,   156, -2957,
    3348, -2957,   186, -2957, -2957, -2957,   138, -2957, -2957, -2957,
     709, -2957, -2957, -2957, -2957, -2957, -2957,   685,   904,   915,
     943, -2957,   901, -2957, -2957,   961, -2957,   969, -2957,   870,
   -2957, -2957,   972, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957,   984,  1458,   415,  1012, -2957,   150,   150,  1015,
     415, -2957,   -69,  1470, -2957,   831,  1163, -2957,   834,  1211,
    1495,  1499,   415,  1509,  1512, -2957,   895, -2957,    32,    32,
      32,    32,    32,  4701,  1506,  1630,    33,  4701,   550,  4701,
   -2957,  4701,  4701,  4701, -2957, -2957, -2957,  1002,  1101,  1125,
    4701,  1419,  1143, -2957,  4701,  4701,  1147, -2957,  1153, -2957,
     778,  1159,  1187,  1194,  1201,  1690,  8624,    66, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  1251, -2957,
   -2957, -2957, -2957, -2957, -2957,   361,   361, -2957, -2957, -2957,
   -2957, -2957,  3348, -2957, -2957,   415,  3348,  1219,   167, -2957,
   -2957, -2957, -2957,  1706, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957,  1252, -2957,  1252,   -69,  1711,  1720,  1721, -2957,
   -2957, -2957,  1732,  1733,   201,  1509,  1252,  1735,  1099, -2957,
    1662, -2957,  1330,  1297, -2957,  1366, -2957, -2957, -2957,  1112,
   -2957, -2957,  1753,  1342, -2957,  1306, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957,  1211,  1306, -2957, -2957, -2957, -2957, -2957,
   -2957,  1308,   275,   400,   289, -2957,   656, -2957, -2957, -2957,
    1314,  1785,   417, -2957,  1318,   421, -2957,  -180,  1357,  1361,
     426,   435,  4106,  1364,  -172,  1546, -2957, -2957,    81,  1365,
   -2957, -2957, -2957, -2957,   441, -2957, -2957,  5072, -2957,  4001,
    8952,  4075,  4075,  4701, -2957,  1289,  4701,  8624,  1331, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,  1145,  1796,  7134,  8624,
    1289,  1799,   671,  4701,  4701,  4701,  4701, -2957,  4701,  4701,
    4701,  4701,  4701,  4701,  4701,  4701,  4701,  4701,  4701,  4701,
    4701,  4701,  4701,  4701,  4701, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,  4701,  4701, -2957, -2957,  1345,
    4701, -2957,  4701,  1348, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,   361,  4701,  4701,  4701,
    4701,  1395,  1829,  1904,  4701,  1363, -2957,  3348,  1336, -2957,
    1176,  1821, -2957,  1186, -2957,  1830,  1420,  1423,   448,  1555,
     449,   472,   296,  1397, -2957,   473, -2957, -2957, -2957,   415,
   -2957, -2957,   415,  1462, -2957,  7058,   355,  7588,  1842,  -140,
     415,  1858,   -57, -2957, -2957,  1163,  1853, -2957, -2957, -2957,
   -2957,  1855, -2957,  1860, -2957,  1866, -2957,   415, -2957,   415,
   -2957, -2957,  1509,  1869, -2957, -2957, -2957,   415,    32, -2957,
    3348,    51, -2957, -2957, -2957, -2957, -2957,  1419,  1419,  1872,
   -2957,  1876,  1273,  1243, -2957,    33, -2957, -2957, -2957,  1474,
    8624,   607,  1477,  7209,  1890,  1419,  1479, -2957,  1481,  1489,
   -2957,  8048,  8256,  8294,  8352,  8729,  8892,  8952,  9055,  1672,
    2315,  4044,  4640,  9236,  9162,  8964,  4075,  4075,  2943,  2943,
    1156,  8624,  8457,  8521,  1289,  8624,  8563,  1289, -2957,  8624,
    8624,  8624,  8624, -2957,  1902, -2957,  1924, -2957,  8624, -2957,
     221,  3348, -2957,  1493,  1912,   -57, -2957, -2957,  1907, -2957,
    1463,  1914, -2957,  1916, -2957, -2957, -2957,  1917, -2957, -2957,
    1283,  1507,  1943, -2957,   415,  1516, -2957, -2957, -2957,   361,
     361,   361,   415,  1049,   415,  1293,   148,   148,  1484,   415,
     415,   148,   148,   415, -2957,  1293, -2957, -2957,   415, -2957,
     854, -2957, -2957, -2957,   148, -2957, -2957, -2957, -2957,   415,
   -2957, -2957, -2957, -2957,    85,    85,  4701, -2957, -2957, -2957,
    1484,  1484, -2957, -2957,   148, -2957, -2957,   148, -2957, -2957,
     415, -2957, -2957,   148, -2957, -2957,   361,   148, -2957, -2957,
    4701,   148,   361,   415,   361,   148, -2957, -2957,   211,   148,
     148,   211,   148,   415,   211,   148, -2957,   148,   148,   148,
   -2957,  1293, -2957, -2957,   361,   148, -2957, -2957,   148,    54,
     415, -2957,  1484, -2957, -2957,   148,  1123, -2957, -2957,   361,
    1280, -2957,   148, -2957,   667,   361,  4701,    32,    32,   148,
   -2957, -2957,  1049,   361,  1166, -2957,  4701, -2957,   436,  4701,
     148,    74, -2957,  4701,   148,  1929,   361, -2957,   148,  4701,
   -2957,  4701,    85,   415,   148,   415,    32,   148,   415,    32,
   -2957,   415,   175, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957,   173, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957,  1027, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,   859,   415, -2957,   489, -2957,
    1518, -2957, -2957, -2957,  1610, -2957, -2957,  1521,  1523,  1524,
    1527, -2957, -2957,  1296,  1961,  1530,  1535, -2957,   254, -2957,
    1503, -2957, -2957,  1315, -2957,  1542, -2957,  1958, -2957,  1359,
   -2957, -2957, -2957,  1322, -2957, -2957, -2957, -2957,  9380, -2957,
    1002,  1553, -2957,  1002, -2957,  1002,  1002,  1002,  1002,  1002,
    1969,  1970,  1975,  4701,  1563,  1977,  4701,  1565,  1580,  1581,
    1594,  1595,  1598,  1600,  4701,  4701, -2957,   228, -2957, -2957,
   -2957,  1698,  1606, -2957,  1609,  1615,  1380,  1617,   415, -2957,
     415,  1618, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
     394,  1393,   352,  1421,  1584, -2957, -2957, -2957, -2957,  1399,
     398, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  2053,
    1400, -2957, -2957,  1607, -2957,  1484, -2957,  1548,   144, -2957,
   -2957, -2957,  1547, -2957,  8624, -2957, -2957,  1441, -2957, -2957,
    3281, -2957, -2957, -2957,   361, -2957, -2957,  1484, -2957,   -17,
   -2957, -2957,  1766, -2957,   127, -2957,  1577, -2957, -2957, -2957,
   -2957,  2078, -2957, -2957,   561, -2957,  1422, -2957,  1425,  2078,
   -2957,  1445, -2957, -2957, -2957,  1622,   111, -2957,  1588, -2957,
    1386, -2957, -2957, -2957, -2957,  1391,   244, -2957,  -227, -2957,
    1431,  1488,  1592, -2957,  1724,  1454, -2957,  1437,  4701,   113,
    1177,  4701, -2957,    91,   148, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,    59,    59,    59, -2957,    59,   582,
      59,    59,  1471,   -17,  1471,  1471,  1205,  1205,  1471,  1471,
     -17, -2957,  2109, -2957,  1649,   456, -2957,  2112, -2957,   -17,
     107,    41, -2957, -2957,  4701, -2957, -2957, -2957,   985, -2957,
   -2957,   355,  4701, -2957,  4701,  1642,  1644,  1646,  1647,  1529,
    1650,  1166, -2957,  1745,  1046,  1491, -2957,  1515, -2957, -2957,
     415, -2957, -2957,  1216, -2957,  2131, -2957,  2129,   415, -2957,
     274,  6424,  1525, -2957, -2957,  2139, -2957,  1444,  2139,  2144,
    1449,  2139,  2144,  4701,  2139, -2957, -2957,   144,   361, -2957,
   -2957,  1687,   310, -2957, -2957,  1678,   361,  4701,  1679, -2957,
   -2957,  2130,  2132,  2051, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957,  1241,  1241,   148,   148,   148,  2333, -2957, -2957,
    2028,   859, -2957, -2957,   738, -2957, -2957, -2957,  1663, -2957,
   -2957, -2957, -2957,  5236,  1509, -2957, -2957,  1505,   415,  1438,
    1419,  1539,  1596, -2957,  4920,  4920, -2957,  1431, -2957, -2957,
    1522, -2957,  5333,  1699, -2957,  1704,  1705,  1707, -2957,  1707,
    1707,  1708,  1710,  1715,  1723,   415,   549, -2957, -2957, -2957,
   -2957,   119, -2957,   415,  1994, -2957,  1712, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  8624,
     476, -2957, -2957,   486, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,  1697, -2957, -2957,   491, -2957, -2957,
   -2957, -2957, -2957, -2957,   150, -2957, -2957,   150,   707,   160,
    2156, -2957, -2957,   766,   188,   800,  2199, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,   415,  1634,   415, -2957, -2957,
    1639,   415,  1655,   415,   415,  1484,  1566,  1729, -2957,  1734,
      89, -2957, -2957, -2957,  1484, -2957, -2957,  2207, -2957, -2957,
    1545,  1740, -2957, -2957, -2957,  1177,  1264, -2957,  1264,  1166,
     211,  4701,  4701,  4701,  1741, -2957, -2957,   361,   361,  1484,
    1550,  1166,    32,  1519,    54,   361, -2957,  1549,  4701,  1836,
   -2957, -2957,  1635,  1488,  1431,  1437, -2957, -2957, -2957,   415,
    1263,  2232, -2957, -2957,  1578,   134,   144,   361, -2957, -2957,
    2224,  2226, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
    2342, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
     667,   361,   361, -2957,  1205,  4701,   -92,  2217,  2221, -2957,
   -2957, -2957, -2957, -2957,   108, -2957, -2957, -2957, -2957,  2050,
   -2957,  1822,   355,  4701, -2957,    70, -2957, -2957,   415,  2228,
      32,    32, -2957,  1620, -2957,    33,  1591,   361, -2957,   415,
     415,  4701,   -91, -2957,  1628, -2957, -2957,   379, -2957,  1737,
   -2957,  1738,  4701,  1077, -2957, -2957,  1602, -2957,  2254, -2957,
    1677, -2957,   361, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,  5715, -2957, -2957, -2957, -2957,   415,
      32,    32,   227,   310,  2072,  1446,   361,   144, -2957,  1681,
   -2957, -2957,  2232,  2249,  1831, -2957, -2957, -2957, -2957, -2957,
    1909,  1909, -2957,   717,  1688, -2957,   415,  1484, -2957,  1484,
    1484, -2957, -2957,  1484,  1484, -2957,   415,  1035,   607,  1484,
   -2957,  1035, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957,   234,   234,   815,   900, -2957,  1056, -2957,   738, -2957,
     150,  2255, -2957, -2957,  1299,  1845,  1804, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,  1696, -2957, -2957, -2957,  1611,
    1611, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  1614,
     607,  1852,   252,   633,  9380,  1777, -2957, -2957, -2957,   633,
     633,   633,   633,  1631,  9380,  9380,   110,  1727,   807, -2957,
    9380,  9380,  9380,  9380, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957,  1177,  4701, -2957, -2957,  1856,  2255, -2957, -2957, -2957,
   -2957,   150, -2957,  1823,  1825,  1826,   788,  1827,  1833, -2957,
   -2957, -2957,  2202,   415, -2957,  2302, -2957, -2957,   743,  2596,
   -2957, -2957, -2957, -2957,   415, -2957, -2957,   743,  1603, -2957,
     394, -2957,  1648, -2957,  1686, -2957,  1877,    37, -2957,  1657,
   -2957,  1691, -2957,  1747,  1850,   415, -2957, -2957, -2957, -2957,
    3281,   415, -2957,  1680, -2957, -2957, -2957, -2957,  1670, -2957,
    2339,  2340, -2957,  2352,  1736,  4701, -2957, -2957,  2358, -2957,
    1683, -2957,  1838,  1694,  2144, -2957, -2957,  1722,   910,   415,
   -2957, -2957,  1895,   148,   898,  1717, -2957, -2957,  1871, -2957,
   -2957,  4701,  1484,  1177,   190, -2957,   415,   415,  4701,    45,
     -17,  2374,   395,  2372,  2366,  2367,   582, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,   361,  2019, -2957, -2957,  2283,  4701,
     355,  2133, -2957, -2957, -2957,  4701,    85, -2957,  2022,  2393,
    2396,   492,   496,   415,  1964,  1166, -2957,  4701,  1936,  1938,
   -2957, -2957,  2009, -2957,  4701,   -35, -2957,  1778, -2957, -2957,
     483, -2957,  4701, -2957, -2957,  1748,  1048, -2957,  1333,   415,
    2409,  9217, -2957, -2957,  1177,   361, -2957, -2957,    35, -2957,
    2144,  2144,  1726, -2957,  1832,  1837, -2957, -2957, -2957, -2957,
      32,    32, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
    1485, -2957, -2957, -2957, -2957,    32,  3779,  2419,  2406, -2957,
    1166,   409,   203,   126,  2289,   -26,  1049, -2957,    23, -2957,
   -2957, -2957,  1959,    73,  1484,   181,  1772, -2957,  1767, -2957,
   -2957, -2957, -2957, -2957,  1962,  1962, -2957, -2957, -2957, -2957,
    1848,  1771,  2436, -2957, -2957, -2957,   553,  1774,  1773, -2957,
   -2957,   361,   177, -2957, -2957, -2957,  1762,   900, -2957,   415,
     415, -2957, -2957,   415,   619, -2957, -2957, -2957, -2957,  1974,
   -2957, -2957, -2957,  2421, -2957, -2957,  1544,  9380, -2957,   459,
    2010,  2444, -2957, -2957, -2957,  9380, -2957,   497,  9380,  9380,
    9380,  9380,   415,   511, -2957,   240,  2445, -2957, -2957,   415,
    9151, -2957,  2036,   415,  1797,   633,  2080, -2957, -2957, -2957,
   -2957, -2957, -2957,  8624, -2957,  1989, -2957,  1956, -2957,  1957,
     191,   191,   191,   514,  2202,   191,  9151,   415, -2957,   515,
     415,   525, -2957, -2957, -2957,  1988,  1990,  1991,  1522,  1522,
   -2957,  1992, -2957,  1993,  1997,  1998,  1999, -2957, -2957, -2957,
   -2957,   955, -2957, -2957, -2957,   526, -2957, -2957,   528,   415,
   -2957,   415,  1671, -2957,   415,  1702,  4701, -2957,   415,  2460,
   -2957, -2957,   743, -2957, -2957,  1812,   743,    90, -2957,  1166,
    4701,  4701,  4701,  3833,  2472,  1484,   153, -2957,  1166,   415,
   -2957, -2957,   415,   415, -2957,  1128, -2957, -2957,   318, -2957,
    1814,  4701, -2957, -2957, -2957,  2471,  1263,  3348, -2957,  1816,
    2476, -2957, -2957,  1166,  1862, -2957, -2957, -2957, -2957, -2957,
     415,  2144, -2957,   144, -2957,  1886, -2957, -2957,   530, -2957,
   -2957, -2957,   361, -2957,  4981, -2957,   880, -2957, -2957,  2113,
    2462, -2957,  2093,  2096,  1985,  1828,  2098,  2015, -2957, -2957,
   -2957,   518,  2086, -2957, -2957, -2957, -2957,  2009, -2957, -2957,
   -2957,   159,   495, -2957, -2957, -2957,  2232,  4701,  2023, -2957,
    1995, -2957, -2957, -2957, -2957,  2490, -2957, -2957, -2957,  2491,
   -2957,  1802, -2957,  2474,   -17,   415,  2027,  2027,  2027,  2027,
   -2957,  2496, -2957,  2498,  2027,  2027,  2027,  2027,  2342, -2957,
   -2957,  2027,   169, -2957, -2957, -2957, -2957,  2479,  2492, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  2493, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,   532, -2957, -2957, -2957,
    2482, -2957, -2957,  1484, -2957,   607, -2957, -2957, -2957, -2957,
   -2957, -2957,  1865,  1870,   125, -2957,    23, -2957,   191,  1851,
     148, -2957,  2033, -2957, -2957, -2957,   415,   415,   191, -2957,
   -2957,    95,  1484,  1144,  9380,   195, -2957,  4701, -2957,  4701,
   -2957, -2957, -2957, -2957, -2957,  1913,   148,    95,  1484,  2508,
   -2957,   361,   415,   212,   212, -2957, -2957,  2510, -2957,  2510,
     710,   710,  2510, -2957, -2957,  1842, -2957,  2081,  2044, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,   119,  1522,  1846, -2957,
    1522,  2084,  9380, -2957,  2085,  2087,  2088,  2091, -2957, -2957,
     110, -2957,   110, -2957, -2957,  9261,  1707,  9109,  1707,  2518,
    2524, -2957, -2957, -2957, -2957, -2957, -2957,   457,  9380, -2957,
    2039, -2957,  2219,   124,   203,   415, -2957,  3286,    71, -2957,
    1842,  2040, -2957,    71,  1484,   806,  2097,  2529,  1873, -2957,
   -2957,   533, -2957,   538,   788, -2957, -2957,   539,   152, -2957,
   -2957, -2957,   743, -2957,  2513,  2513,  2514,  1874,  -159,  2515,
    2516,  2517,  2515,  2515, -2957, -2957, -2957,   179, -2957,   997,
     415, -2957,   743, -2957, -2957, -2957,  1882, -2957, -2957,  1883,
   -2957, -2957,  -145,   541, -2957,   415,   546, -2957,  4701,  2111,
    2530,   551,  1166,  2531, -2957, -2957, -2957, -2957,  4701,  1940,
    2236,  4701, -2957, -2957, -2957, -2957,   318,  1501,  1501,  2547,
    -106, -2957,  2559, -2957, -2957, -2957,  1501,   415,  1976,  1362,
    2561,   415,  1905,   327,   165,  1484,  2560,  1166,  -127,  2374,
    4701, -2957, -2957,   582, -2957,  1859,  4701, -2957, -2957, -2957,
    2565,  4701,   361, -2957,   854,   415,   361, -2957,  2134,  4701,
    4701, -2957, -2957,   518,  2086, -2957,  2342, -2957, -2957,  1304,
   -2957, -2957,  1960, -2957,  3348,  4233,  9217,    24,   913, -2957,
   -2957, -2957,  1918, -2957, -2957, -2957, -2957,    32,  2027,    32,
    2027, -2957, -2957, -2957, -2957, -2957, -2957,   -17, -2957,  1069,
    1137,  3779, -2957,  2135,  2101,  9380, -2957,   126,   126, -2957,
   -2957, -2957, -2957,   552, -2957,  2064, -2957,   191,   644, -2957,
    1919, -2957,   554, -2957, -2957,  2579, -2957, -2957,  1996, -2957,
    2580,  4728,  4728,  4728,  4728,   191,   191, -2957, -2957, -2957,
   -2957, -2957, -2957,  2579,  1920,   361, -2957,  2510, -2957, -2957,
     415,   710,   710, -2957, -2957,   710,  2329,  1923, -2957,  2562,
    2154,  1926,  1544,  1927, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957,   555, -2957, -2957, -2957,   213,   230, -2957,  9151,  9151,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  4920,
    4920,  2117,  4920,  2122, -2957,  4920,   674,  9380,  2594, -2957,
   -2957,  9151, -2957, -2957, -2957, -2957, -2957,  2597, -2957,   -70,
   -2957, -2957,  2219,  1933, -2957, -2957,    85,    85,    85,  2578,
      85,    85,    85,    85,    85,    85,  2581, -2957,  2582,    85,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  3286, -2957,
     361,  1941, -2957,  2119,  2329,  2590, -2957,  2598,  2599,  2600,
    2602,  2603,  2604,  1316,  2040, -2957,  2119, -2957, -2957,  2606,
   -2957,  2263,   191,  1408,   191, -2957, -2957,  2202, -2957, -2957,
   -2957, -2957,  2195,  2196,   558,  1544,  2611,  1544, -2957,  2633,
     562,  2201,  2205,  2633, -2957, -2957, -2957, -2957,  1484, -2957,
   -2957, -2957,  2170, -2957, -2957,   997, -2957,  2202, -2957, -2957,
     415,   415, -2957, -2957,   415,   161, -2957,   743,   166,  2232,
   -2957,  2136,   166,   236,  1166, -2957,  2642,  2172, -2957, -2957,
    2214,  2055, -2957, -2957,   415,  1501,  3348,  1416,   415,  1501,
   -2957, -2957,    32, -2957, -2957,  4701, -2957, -2957, -2957, -2957,
   -2957, -2957,  1166,  2645, -2957,    32,  2232,   361,  2368, -2957,
    2630,  1832,  8624,  2635, -2957, -2957,   144,  2186, -2957, -2957,
    4701, -2957, -2957,  2223, -2957, -2957, -2957,   495, -2957,  1832,
   -2957,  4701, -2957,   350, -2957,  2112, -2957, -2957, -2957, -2957,
    2176,  2271, -2957,  2644, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,   415, -2957,   131, -2957, -2957,
   -2957,   191, -2957,   607,  2477,   572, -2957, -2957, -2957, -2957,
     415,   191, -2957,    95,    95,  2068,  5038,  5038, -2957, -2957,
    9499,  2191, -2957, -2957,  2192,  2194, -2957,  2197,  2203,  2204,
    2206,   415,   602, -2957, -2957,   574, -2957, -2957,  2056, -2957,
   -2957, -2957,   577,  2667,  2667, -2957, -2957,   584,  2670,  2663,
   -2957,   229,   361,    95, -2957, -2957, -2957, -2957, -2957,  2424,
    5236,  2246, -2957,  1544, -2957,  1544,   110, -2957, -2957,  2524,
   -2957,  2198,  1994,  2198,   182, -2957,  2198,   182, -2957,  2198,
    4920, -2957, -2957,  9380, -2957,  9380,  2518,   124, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957,   329,  2681, -2957,
     361,  1526, -2957,  2424, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,   363, -2957, -2957, -2957,  2187,
   -2957, -2957, -2957, -2957,  2664, -2957, -2957,  2256, -2957,  2671,
    2258,  2675, -2957, -2957, -2957,  2265, -2957,  2230,  9151, -2957,
   -2957, -2957, -2957, -2957,   415,  2678, -2957,   161, -2957, -2957,
    2682, -2957, -2957,  2684,   415,  2219,   166, -2957,    32,   -17,
   -2957,  2272,  1166, -2957,  4701, -2957,  2094,  2685,   -17, -2957,
   -2957,   354, -2957, -2957, -2957, -2957,   219,  2274, -2957,  1166,
    2144,  2491,  2427, -2957,   -17,  2276,  2277,  2374,  2240, -2957,
    2325,  2280, -2957, -2957, -2957, -2957,  2432,  2218,  4701,  2235,
   -2957, -2957, -2957,  1832, -2957,   588, -2957,   361,  2137, -2957,
   -2957, -2957,  9380, -2957, -2957,   191, -2957,  2247, -2957, -2957,
   -2957,  2579,  2137,  2212,  2212,  2286,   252,   633,  9543,   633,
     633,   633,   633,  2061,  9543,  4728, -2957,  9543,  9543,  9543,
    9543, -2957, -2957,   191,  2712,   191,  4728,   148,  9151, -2957,
    2491,    75, -2957, -2957, -2957, -2957, -2957, -2957, -2957,   179,
   -2957, -2957,   589, -2957, -2957, -2957, -2957,   593, -2957,  2198,
    2720, -2957, -2957, -2957, -2957, -2957, -2957,   361,  2681, -2957,
   -2957, -2957,   361, -2957,   361, -2957, -2957,  1915, -2957,  2446,
   -2957,  2447,  2703, -2957, -2957,  2292,  2065, -2957, -2957, -2957,
    2299, -2957,   191,   217, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,  1166, -2957,  2300,  9851,  2264,
   -2957, -2957, -2957,  2079,   -17, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957,  2307,   144, -2957,  2325,  2325,   495, -2957,  3348,
    2127, -2957, -2957,   415, -2957,  2491,   807,   119, -2957,  9336,
     807, -2957,  2308,  9543, -2957,   595,  9543,  9543,  9543,  9543,
     415,   603, -2957, -2957, -2957, -2957, -2957, -2957,  2273, -2957,
   -2957, -2957,  2518, -2957,   415, -2957, -2957, -2957, -2957,   170,
   -2957, -2957, -2957,  9380, -2957,  2126,  2126, -2957,  2126, -2957,
    2126,  2126, -2957, -2957, -2957,  2278, -2957,  1544, -2957,   605,
   -2957,  1226, -2957, -2957,    59,    59,    59,    59,    59,    59,
   -2957,  2726, -2957,   608, -2957,  4701,  1426, -2957,    52,  2325,
    4701,  2325,  2374, -2957, -2957, -2957,  2466,   364, -2957,   -17,
   -2957, -2957, -2957, -2957,   610, -2957, -2957,  1281, -2957,  2316,
    9543, -2957,  2317,  2318,  2319,  2320, -2957, -2957,  4728, -2957,
   -2957, -2957, -2957, -2957,  2126, -2957,  2126, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,  1300, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,  9851, -2957,  2755, -2957,
   -2957, -2957, -2957,    30, -2957, -2957, -2957, -2957, -2957, -2957,
      35, -2957,  9336, -2957,  1716, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957,   611, -2957, -2957,  1310,  1310, -2957, -2957,
    1310, -2957,  4701,   613, -2957, -2957,  2326,    24, -2957,  2103,
    2104,  2760, -2957, -2957, -2957, -2957, -2957,  2331, -2957, -2957,
   -2957,   415,   415,  1716, -2957,   199,  2106, -2957, -2957, -2957,
     144, -2957,   415,  2374, -2957
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2957, -2957, -2957, -2957, -2957,     7, -2957,    67,  -168, -2957,
   -2957, -1128,  -516, -2957, -2957, -2115, -2957, -2957, -2957, -2957,
    -823, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2068, -2957,  -978, -2957,
    1780, -2957, -2957, -2957, -2957, -2957, -2957, -2957,   320, -2957,
   -2957, -2957, -2957,  1253, -2957,   624, -2957, -2957,   -38, -2957,
   -2957,  2751, -2957,  2750,  2237, -2957, -2957, -2957, -2957, -2957,
     393,    48, -2957,   391, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,   -97,   413,   367, -2957, -2957,
    2433,   -44, -2957,  2674, -2957, -2957,  2672, -2957,  2584, -2957,
   -2957, -2957, -2957, -2957,  2448,  2140,   786,  2442,  -511, -2957,
   -2957, -2957, -2957, -2957,   791,  -642, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,   488, -2957,  2574,  2266,  2589,    49,
    2210, -2957,  2250,  1538, -2957,  2429, -2957, -2957, -2957, -2957,
    2437, -2957, -2957, -2957, -2957,  -392, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,  2248, -2957,  2252, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -1327, -2957, -2957,  -770, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  -125,
   -2957, -2957,   759, -2957, -1082, -1145,  -518, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,  1839, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,  -602, -2957, -2957, -2957, -2957, -2957,
    2025, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  -524,
   -2957,  -101, -2957, -2957, -2957, -2957,  2412, -2957, -2957,  -233,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,  1579, -2957, -2957, -2957,
   -2957,   571, -2957, -2957, -2957, -2957, -2957, -1953, -2957, -2957,
     567, -2957, -2957, -2957, -2957, -2957, -2957, -1120,  -606,   452,
     728, -2957,  -216,  -559,   353, -1112,  1358, -2957,   325, -2957,
   -2396,    -3,   796, -2957, -2957, -2300,   358,  2118, -2957, -2957,
   -2957,   784,   976, -2957, -2957, -2957, -2957, -2957, -2957,    58,
   -2957,  -244, -2957,   978, -2957,   666, -2957,   373, -2957, -2957,
   -2957, -2957,  -786, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957,   468, -2957, -2957, -1817, -2957,   655, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957,  1447, -2957, -2957, -2957, -2957, -2957, -2957,  -438,
   -2957, -2957, -2041, -2957, -2957, -2957, -2957,   570, -2192, -2957,
   -1107, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,  2843, -2957, -2957, -2957,  2768,
    2822, -1801, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  -360,
   -2957, -2957, -2957, -2957, -2957,  2824, -2957, -2957,  2844, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,   705,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
    -663,  2115, -2957, -2957, -2957, -2957, -2957,  1939, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957,  2488, -2957, -2957,   -12,
   -2957, -2957,   704, -2957, -2957, -2957, -1103,  -166,  2545, -2957,
   -2957, -2957, -2957,   872, -2957, -1040,  1863,   998, -1423,  1392,
   -2957,   711,  1658,  -343,  -515, -2957, -2957,  2100,  1473, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  1404,
   -2957,  -766, -2957,  -626, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957,  -716, -2957, -2957, -2957, -2957, -2957, -2957,   102, -2957,
    1492,   372, -2957, -2957, -2957, -2957, -2957,   -75, -2957,  -514,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957,  1389, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,  -519, -2957,   760,  2449, -2957, -2957,
     -66, -2957,  -704, -2957, -2957,   -54,   247, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957,   912, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  -119,
   -2957,  -371,  -368, -2957, -2957,  -358, -2957, -2640, -2957,  -104,
     535, -1317, -2957, -2957, -2957,   873, -2957, -1950, -2957, -2957,
   -2957, -1955, -2957, -2957, -1944, -2957, -2957, -2957, -2957, -2220,
   -2957,   891,   585, -2957, -2957, -2957, -2957, -2957,   368, -2957,
   -2957, -2957, -2957, -2957, -2957,  -695, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  -279,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957,  1008, -2957,  1009, -2957,   360,   686, -2957, -2307,  -201,
   -2957, -2957, -2957, -2957, -2957, -2957,   -47, -2957, -2957,  -497,
   -2957, -1224, -1307, -2957, -2957, -2957, -2957, -2957,   -77, -2957,
   -2957, -2957, -2957, -2957, -1926, -2957, -2957, -2957, -2957, -2957,
   -2957, -2369,   636, -2957, -2554,   706, -2957, -2957, -2271,    44,
      50,   313, -2957, -1931, -2586, -2957, -2957,  -254,  -556, -2957,
   -2957, -2957, -2957, -1884, -2957, -2957, -2957,   -49, -2957,   271,
   -1009, -2957,  -555,  -301,  1054,  -288, -2195,   298, -2957, -1624,
   -2957, -2957, -2957, -2957,    21, -2957, -1168, -2758,  2945, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957,  -699, -2957, -1927,
   -2957,  1709, -2957, -2957,   223,   314, -2957, -2076,   312,  -158,
     140,   308, -1868, -2214,   974,  -229,  -955, -1252, -2957,   988,
   -2957, -2957, -2957,  1082,  -761, -2957, -2957,  -488,  1742, -2957,
     529, -2957, -2957,   419,  -143, -2957, -2957, -2957, -2062,  -367,
   -2957, -2957, -2957,  1114, -2957, -2957, -2957, -2957, -2957, -2957,
   -2957, -2957, -2957, -2957, -2716,  -385, -2957, -2776, -2956, -1449,
   -1420, -2957, -2957,  -370, -2957, -2957, -2957,   241, -1075,  -742,
    -828,   581, -1349,   122, -2957, -2957, -2957, -2957,  1575, -2957,
   -2957, -2957, -2957, -2957, -2957, -2957, -2957, -2957,  -300,  1017,
    2451, -2957, -2957, -2957, -2957
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2222
static const short yytable[] =
{
      34,    36,    38,   268,   570,    38,   184,    87,  1380,  1426,
     998,  1053,  1438,  1303,  2112,  1445,  1446,  1332,  1447,  1494,
    1468,  1469,  1959,  1960,   328,   113,  1165,   678,   410,   411,
     236,  1486,  1466,  1171,  1116,   986,   962,    58,  2038,  1435,
    2244,  2022,   104,   408,   409,  1434,   578,  2397,   296,   103,
     425,    58,  2870,  2058,    87,  2668,  2184,  2185,   423,    33,
      33,   944,   110,  2606,   954,  2778,  3152,  3153,  3154,   117,
     184,   949,    33,   122,   197,  2135,   124,   125,    33,  2356,
    3123,    33,   128,   129,  2332,  1439,    33,  2357,  1085,   184,
     274,  2527,   504,  2733,  1877,  2288,  2289,  2290,  2291,  1436,
     591,    33,  2277,    58,  2666,   255,  2807,   592,  1203,   274,
    1048,  1049,   578,  1485,  3174,  1169,  1408,    33,  1408,  2543,
     232,  1060,    33,   235,  1985,  2659,  2662,  2662,   239,  3156,
    2662,  1872,  3088,  1031,  1895,  1029,  1985,    33,   412,  2101,
     366,   367,   427, -2220,   429,  1882,   430,   431,   432,  1029,
    2916,    33,    33,    33,   513,   437,  1123,   333,  2888,   448,
     449,   326,   274,   334,   335,  1057,  1058,   101,   274,  1215,
    1216,    33,   326,  2723,   578,    33,  1118,  1873,  1029,  1121,
      33,   255,  2581,   359,  2777,  3049,    33,    33,  1164,   331,
    1029,  2724,    33,  1426,   274,  1277,  1278,    33,  1055,   274,
    1215,  1216,    33,   274,  2994,  1278,   274,  1277,  1278,    33,
     274,   329,   330,    33,   101,    33,  1029,  1107,    33,  2888,
    3270,   184,  1071,  2888,   578,   184,   326,  3246,  1169,  3248,
      33,   363,  2101,   326,  1487,  1488,  1078,   369,    33,  2890,
    2891,  3281,  2892,  2893,  2894,  2895,  2896,  2897,  2105,   398,
    2106,  2880,  2107,  2882,  2950,   407,   407,   407,   407,   407,
    1396,  1397,   351,   407,  3493,  1029,   588,    33,  1158,  2550,
    2853,    33,   317,   318,   319,   320,   321,  1424,  1173,    33,
     563,  1188,  3201,  1425,  1224,  1194,  2841,  2842,  2843,  2844,
    2845,  1200,  2547,  1202,   567,    54,  2151,  3271,  3272,   523,
    2124,   114,   446,  1225,  1899,   529,  2805,  2589,   600,  3054,
    2592,   603,    58,    58,  3183,  1877,  3186,  2986,     6,  3189,
    2063,     1,   515,  2737,   580,     2,    54,  1971,   611,   612,
     613,   614,   326,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
    2840,   650,  2456,  2824,  2397,   326,  2885,  1233,  3634,   575,
     632,   633,   947,  2833,  1418,   635,  2128,   636,  3412,   326,
   -2220,  2193,   317,   318,   319,   320,   321,    43,  1116,   425,
      54,   932,   639,   640,   641,   642,  1027,  1027,    33,   648,
      76,  1027,  1027,  2193,  1040,    54,  2111,    77,  3036,  3482,
    1482,  2553,  2157,  2423,  1027,   565,  1111,   370,  3659,  1225,
    3490,    54,   948,    10,   933,  3376,   184,  3377,  1111,  1901,
    1516,  2644,   573,    43,  1027,  3367,   578,  1027,  1225,    10,
    2167,   578,     4,  1027,   371,  1419,    33,  1027,  3012,    54,
     578,  1027,    33,    78,    79,  1027,   595,    54,  2920,  1027,
    1027,    80,  1027,   658,   661,  1027,  3273,  1027,  1027,  1027,
    1094,  1482,   589,    33,  2607,  1027,  2890,  2891,  1027,  2892,
    2893,  2894,  2895,  2896,  2897,  1027,  1101,   663,   667,   184,
      54,  2002,  1027,  1541,   581,   997,    48,  3013,  1111,  1027,
    1377,  2002,   575,  1225,  1348,  1349,  2007,   578,  2554,    44,
    1027,   578,  2612,    58,  1027,  2198,  2157,  1878,  1027,   830,
     924,  2987,  1391,  3198,  1027,  1878,  2612,  1027, -2220,  2664,
    2330, -2220,  1024,  1024,  1350,  1351,  1352,  2198,  2898,   926,
    2672,  2690,  1521,  2692,  1907,  2753,   670,  2811,  2974,   670,
    1475,  1476,  1388,  2974,  2974,  1024,  3014,   670,  2125,  3050,
     184,  3017,   927,  1103,  1160,  1161,  3017,  3111,  3037,  3121,
    3176,    52,  3199,  3244,   398,  1226,   398,  3251,   317,   318,
     319,   320,   321,  1911,   946,   407,  3055,  3335,   951,  3355,
      33,  2738,  3355,  1209,  3076,    27,  1212,  1175,  2154,  3363,
    2979,  3660,   407,  3463,  3499,  2095,  1228,    54,  3499,  2420,
    3560,  3107,    69,  2834,  3389,  1440,  1217,  1448,  3560,  1227,
    2972,  3089,  1280,  3596,  2544,  3612,  3355,  2821,   568,  1894,
    2822,  1280, -2220,  2281,  1280,   665,   972,  1472,   327,  2857,
    2951,   102,  3116,     7,  1479,  3431,  2023,  1176,  2068,   518,
    3196,  1908,  1908,   960,  2300,    54,  1158,  3487,  2899,  2900,
    2083,  3178,  1500,  1116,  1501,  3520,  1507,  3282,  1441,  2158,
    1102,   569,    26,  1227,  2034,  3304,  1542,  2815,  2278,   916,
    2295,   670,    54,   608,  1177,  1415,    58,    58,    58,  1016,
      58,  1020,  1022,  3314,  3190,  1030,  1032,  1033,   114,  1437,
    1038,  1489,  1022,   996,  2279,  1041,  3103,    58,  1970,  2009,
    1333,   112,  1228,  2533,  2901,    81,  1033,  1218,  1190,  2324,
    1986,  2712,  1409,   564,  1433,   593,  2620,  1030,  1030,  2535,
    2038,  1228,  1125,  1126,  1127,  1128,  1267,  1033,  2980,  3327,
     295,    82,  2136,    58,  3289,  3008,  3494,  2069,  3294,    58,
    1033,    58,  3009,   404,   404,    58,  1954,  1492,    58,   295,
    1088,    58,  2479,  1943,  2483,  2898,   404,  3241,  1022,  3580,
     116,    58,   950,  2158,  2483,   404,   407,  1105,  2582,  1030,
      33,  1178,  1442,  1112,  3466, -2220,    58,  3237,  1490,  3240,
    2654,   277,    58,  2422,   407,   407,  1228,  3260,  3470,    58,
      58,    58,  3623,    33,  2866,  1184,  2108,  1398,  1191,  3048,
    3368,    83,   295,    58,  2109,  1449,   118,  3378,   295,  2654,
    1204,  2413,  1204,   407,  3287,  1204,   407,  3341,  1204,    58,
    2054,  2654,  3317,  2846,  1027,  2478,  3443,    33,  3264,  2059,
     105,  2902,   524,  3274,   295,  3413,  3609,  1483,   566,   295,
     167,  1079,    33,   295,   534,  1129,   295,  2654,  1179,  2954,
     295,  2414,   168,  1130,  2081,   574,  3371,   984,  1319,   579,
     987,  1319,  1131,  1543,   584,  1132,  1229,  1230,  1231,   648,
     648,  1942,  1961,   585,   190,  2899,  2900,  1232,  2122,   596,
    1042,    33,  3265,  2070,  2071,  2072,   659,   662,  1484,  1180,
    3108,  3109,  2463,    84,  1353, -2220,  1544,  2903, -2220, -2220,
    2090,  2213,  2214,   191, -2220, -2220,  2757,    33,  1133,  3031,
     664,   668,  3394,  3552,  2003,  1134,  3331, -2220, -2220, -2220,
   -2220, -2220,   194,  1253,  2004, -2220,  3339,  3462,  2162,  2008,
    2442,  2901,  1450,     1,  2443,  2613,   109,     2,  1451,  1452,
    1453, -2220,  2566,    33,  1027,  1027,  1027,  2904,  2905,  2619,
    1024,  2567,  2665,  2670, -2220,  1181,  2144,   233,  1962,  1336,
    1454,  3395,   132,  2673,  2691,  1296,  2693,  2123,  2754,  3191,
    2812,  2975,  1135,    85,  1963,  2568,  2976,  2978,  2569,  3015,
    1354,    86,   234,  2133,  3018,  1501,  1366,  3423,   428,  3022,
    3112,  2593,  3122,  3177,   174,  2570,  3245,  1136,  2013,   243,
    3252,   133,  2920,  2150,  1137,  1343,  1138,   670,  1367,  2429,
    3336,  2014,  3356,   965,  2165,  3362,  1139,  1964,   175,  2286,
     134,   135,  3364,  1355,     3,  1984,  3464,  3500,  2412,  2286,
    1303,  3501,  1372,  3561,  2013,  2308,  2309,  2310,  2311,  2282,
     324,  3567,  1030,  3581,  1140,    58,  3597,  2014,  3613,  3643,
     241,    54,  1141,   107,  1373,  2707,  1965,  2013,  2902,  2707,
     136,    58,   176,  2995,  1030,   257,  1455,   106,   107,  1456,
    2014,   177,   137,   155,  1017,    33,    33,  1457,  3354,  2013,
    2466,  1047, -2220,   138,  1093,  1966,  3361,   253, -2220,  1142,
      54,  2013,  2014,  1100,  1967,  3099,    33,  3492,  2663,  2571,
     139,  2667,  1065,    58,  2014,   279,   107,  3192,  1112,  3193,
     140,  2608,  1458,  2015,  1143,  1074,    54,  1112,  3467,   250,
    2390,    53,  2391,    33,  2903,   141,     1,   251,   966,   282,
     325,    58,    58,    58,  2574,    58,   254,    58,    58,  1207,
    3468, -2220,  1210,    58,    58,  2259,   258,  1459,  1110,  2015,
      33,  1144,  2572,  1189,  2283,   178,   179,  1195,   926,  2573,
    3113,  1199,  1145,  3101,    33,   142,  1460,  1461,  3117,  2448,
    2677,  2678,  2015,   259,  2904,  2905,  1514,  1462,    58,  2084,
    1255,   927,  1463,  2016,   260,     4,  2303,  1525,   143,   261,
      58,  1169,   262,    33,  2015,  1533,   474,   263,  1103,  2215,
     264,  2996,  1424,   144,    33,   265,  2015,  2684,  2685,  2686,
     145,   266,   288,   146,    58,    58,  2477,  3143,  3143,  3143,
    3143,  1464,   267,    58,  1401,   269,  2392,  2659,  2017,  2393,
      53,  1402,    33,    37,   147,    33, -2220,   967,   148,    58,
      58,  1526,  2028,    33,  2018,  3332,  2251,  2010,  2229,   311,
    2012,  2193,  3381,  1465,   312,  3386,  1063,   149,  3388,  2312,
    1146,  1147,  1148,  2284,  2017,  1945,  1888,   958,    33,   959,
    1072,  1296,  1296,  1149,  1077,   150,  2037,  2141,  2142,  1296,
    2018,  3361,  3361,  2097,    54,    54,  1091,  2017,  2260,  2064,
      33,    33,  1983,   475,   476,   477,   478,   479,   480,   425,
    1989,  2997,   313,  2018,   291,    54,     5,  2261,  2262,  2017,
    2969,   481,   482,   483,  -282,   314,   292,   293,  1021,  2270,
      33,  2017,  1303,   315,   294,  2018,    33,  2263,   316,  3078,
    2611,    33,    54,  2614,  2615,  2616,  2617,  2018,  2390,  2998,
    2391,  3231,  2221,    33,  2222,  2223,  2024,   323,  2225,  2226,
    2029,  2035,  2029,  2469,  2245,     6,  2791,  2977,  2047,  1111,
      33,  1116,  2041,  2043,  2044,  2734,  2304,    58,  2048,  2050,
    2051,  2052,  1030,    54,   355,  2038,  1150,  2305,     4, -2220,
     346,  1030,  3043,  2749,  2447,  2198,     7,  3543,  3544,    33,
    3551,   347,  1112,    58,  3557,    58,    58,    58, -2220, -2220,
    -282,  2687,    54,  2999,    58,    58,  1030, -2220,    58,   407,
    1242,   407,    58,  1111,   675,     8,  -282,  3000, -2220,   348,
    1112,  1243,   930,   338,   339,   340,  2096,  2098,  3238, -2220,
   -2220,  2299,  2438,    58,    58,    33,  3292,   352,  2826,  2871,
    1372,    54,  2873,    33,  2392,   353,  3599,  2393,   357,  2532,
    2545,   484,    54,    33,   485,  2373,    26,    27,  3502,  -282,
     361,  2230,  1373,  3473,  2852,  3476,  3477,  3478,  3479,  2193,
   -1607,  3605,  1244,  3607,   106,   107,  2231,    54,    58,    58,
    3588,    58,  1025,  1028,   362,  2186,  1245,  2187,   364,  2188,
    2189,   368,  3151,  3151,  3151,  3151,   373,  3601,  -282,     5,
      54,   374,  3143,  3143,   383,  2139,  3143,   407,   407,  1029,
    3582,    33,   407,  1424,    58,    33,  2148,  2149,  3001,  2232,
    1061,   392,  1518,  1061,  2186,   393,  2187,  -282,  2188,  2189,
    2233,   413,   414,  1070,  3002,   399,  -282,  1061,   402,    58,
      54,  1061,  1388,  1248,  1249,  3588,  1011,  2409,  1087,   106,
     107,  2234,    54,  1061,  1512,  1070,    33,  2384,  2235,   403,
    3384,  1099,  3601,  3384,  1070,   415,  2236,  2193,  1368,  1369,
     416,  1109,   418,   433,   486,  1246,   375,   435,  1122,     7,
    2166,   107,  2259,  2408,  3628,  1163,  2254,  2255,  2237,   487,
    2072,  2403,  2404,   488, -2220,  1976,  1099,  1977,  1978,  1208,
    1099,   436,  1211,  2198,  1099,  1214,  1229,  1230,     8,  1303,
    1070,  2435,  1519,  1070,  3614,  3615,  2713,  1501,  2714,   447,
    1956,  3583,  1957,   450,   384,  3584,  3019,  2725,  2232,   451,
     489,  1992,  1993,  3399,  3301,   453,  2455,  2180,  2181,  2233,
    3085,  2193,  1495,  1496,  1497,  1498,  3059,  3182,  3182,   415,
    3182, -2220,  2746,  3182,   416,   417,   418,  2875,   490,  2042,
    2234,    33,   376,   454,  2045,  2238,    33,  2235,  3056,  2552,
     455,  2239,  2886,  2992,  2993,  2236,   491,   456,   377,  3098,
    2049,  3345,    33,  2910,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,  3583,  2696,  2237,    33,  3584,
    3269,  2198,  1381,  1382,  1383, -2220,  3343,  3344,  3400, -2220,
     385, -2220,   474, -2220,  1473,  1474,   457,   506,  1477,  1478,
    2274,   378,  2275,   517,  3143,  2260,   386,  2699,   521,    33,
    3143,  3143,   519,  3143,  3143,  3143,  3143,   526, -2220,  3370,
    2299,  3639,  3143,    33,  2261,  2262,   527,   528,  1994,  1995,
    1996,  1997,  1998,  1999,  2065,  3497,  2065,   492,   530,   531,
     379,   535,  2190,   536,  2263,  2191,   537,  2192,   540,   387,
    3401,  2708,  3402,   541, -2220,  2198,   551,  3151,  3151,   552,
     553,  3151,   556,  3064,   561, -2220,   571,  2193,  3403,   380,
     572,  3072,  3073,  1027,   577,   582,  3404,  2194,   381,   583,
    3405,  2190,   587,   594,  2191,   601,  2192,   604,   388,   475,
     476,   477,   478,   479,   480,   605,   606, -2220,  2195,   609,
   -2220,   634,  2750,   493,   637,  3406,  2193,   481,   482,   483,
    2081,  2477,   438,   643,   644,  3385,  2194,   389,  3385,   649,
     651,  2196, -2220,  2267,   652,  2197,   390,   653,  2701,  3143,
     654,  1946,  3143,  3143,  3143,  3143,   655,  2499,   656,   660,
    1303,   657,  2715,  2716,  2072,  2719,  1204,   407,   407,   666,
     676,  2785,     1,    58,    58,  3384,  2421,  2313,   931,   936,
    2196,   938,  1308,  2740,  2197,  1310,   939,  1311,  1312,  1313,
    1314,  1315,   940,  2217,  1030,   945,  1030,  1030,   955,  3474,
    1030,  1030,   956,  2227,  3465,  3474,  1030,   957,  3483,  3484,
    3485,  3486,   964,  1027,  2318,   969,   971,   973,   439,   974,
    1163,  2198,   317,   318,   319,   320,   321,   975,   992,   994,
      58,   999,  1000,  1002,   440,  1961,  3143,  1947,  3182,  1003,
    1004,  2271,  1005,  1007,  3143,  1009,  1027,  1008,  1010,  2782,
    1120,  3023,  3194,  1948,  1012,  1196,  1257,  2598,  1258,  1259,
    2198,  1260,  1261,  1336,  1263,  1262,  1264,   484,  1265,  1112,
     485,  1296,  2502,  1266,  2490,  2492, -2220,   441,  2814,  1268,
    1270,  1296,  1296,  1030,  1271,  1269,  3053,  1296,  1296,  1296,
    1296,  1309,  1273,  1272,  1316,  1317,  1949,  2281,  1112,  3151,
    1318,  1321,  1322,  1324,  2434,  3151,  3151,  2838,  3151,  3151,
    3151,  3151,  1990,  1991,  1992,  1993,   442,  3151,  1325,  1326,
    2024,  1962,   648,  2854,  3559,  2029,  3307,  3562,  3563,  3564,
    3565,  2035,  1327,  1328,  2029,  1950,  1329,  1963,  1330,  1426,
    1892,  1122,  1163,  2599,  1335,   443,  1334,  1339,  1341,  2848,
    1037,  2849,  2371,  1340,   444,  1342,  1346,  1365,  2375,  2600,
    1370,  1374,  1046,  1371,  1951,  2299, -2220,  2299, -2220,  1375,
   -2220, -2220,  1378,  1952,  3357,  3358,  3359,  3360,  1395,  1376,
    1964,  1384,  1399,  1400,  1403,  1406,  2400,  1404,  1407,  1412,
     486,  1066,  3309,  1411,  1414,  1423,   107,  3400,  1427,  1030,
    1112,  1430,  2601,  2416,  2417,   487,   407,  1083,  1084,   488,
    1429,  3618,  1470,  1090,  1480,  1481,  1092,  1485,  1508,  1965,
    1509,    58,  1510,  1511,  3151,  1520,  1515,  3151,  3151,  3151,
    3151,  1994,  1995,  1996,  1997,  1998,  1999,  1517,  1521,  1530,
    2445,  2602,    58,  1532,  1869,  1868,   489,  1870,  1966,   578,
    3385,  3434,  1871,  1876,  1880,  1883,  1884,  1967,  1885,  3401,
    3442,  3402,  1886,    58,  1933,  2470,  1533,  1941,  1296,  1944,
    2603,  1112,    58,  1955,   490,  1972,  3448,  3403,  2001,  2604,
    1973,  1974,  2027,  1975,  1979,  3404,  1980,   407,   407,  3405,
    2409,  1981,   491,  1994,  1995,  1996,  1997,  1998,  1999,  1982,
    3025,  2006,   407,  3030,  2040,  2056,  2055,    58,    58,    58,
    2057,  3151,  2060,    58,  3406,  2061,  2062,  2075,  2089,  3151,
    2082,  1030,  3203,  3204,  3205,  1492,  3207,  3208,  3209,  3210,
    3211,  3212,  3359,  3360,  2091,  3215,  2093,  2101,  3390,  2103,
    2910,  2743,  2114,  2126,  1027,  2115,  2955,  2127,    58,  2129,
    1027,  2154,  2131,  2140,  2143,  3491,  2588,  2588,  2145,  2169,
    2588,  2956,  2957,  3283,  2161,  2163,  2168,  1158,  2171,  1878,
    2958,  1939,  2205,   492,  1296,  2207,  1027,  2208,  2210,  2216,
    2273,  2268,  1296,  2272,  2276,  1296,  1296,  1296,  1296,  2618,
    2278,  3298,  1030,  1970,  2314,  2292,  2623,  1296,  2300,  2320,
    2641,  2321,  2322,  2325,  2959,  2327,   184,  2330, -2220,  2326,
     332,  2359,  2361,  2960,   337,  2363,  3537,  2655,  2655,  2655,
    2362,  2364,  2655,  1296,  2669,  2365,  2368,  2024,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,  2366,   493,
    2379,  2377,  2961, -2220,  2380,  2381, -2220,  2386, -2220,  1994,
    1995,  1996,  1997,  1998,  1999,   474,  2694,  2382,  2695,  2697,
    2383,  2698,  2700,  2385,  2388,  2702,  2387,  1448, -2220,  2029,
   -2220,  2401, -2220,  2029,    58,  2407,    58,  1303, -2220,  1877,
    2424,  2406,  1030,  2655,  2431,    58,  2400,  2962, -2220,  2730,
    2730,  2389,  2426,  2427,  2433, -2220, -2220,  2436,  2440, -2220,
   -2220,  2441,  2446,  2098,  3589,  3590,  3591,  3592,  3593,  3594,
      58, -2220,  2449,  3542,  2450,   505,  2453,  2748,  2467,  2459,
      58,  3611, -2220,  2473,  2530, -2220, -2220,  2483,  2485,    58,
    1232,  2963,  2531,    58,  2542,  2548,  2556,  2557,  2558,  2561,
    2562,  2563,  2578,  3257,  2577,  2585,  2596,  2597,  2609,  2610,
    2622,  2638,   475,   476,   477,   478,   479,   480,    58,  2645,
    2643,  2646,  2647,  2651,  2674,  2705,  2675,  2676,  2679,  2680,
     481,   482,   483,  2681,  2682,  2683,  2710,  2721,  2739,  2741,
    2744,  2745,  2792,  2747,  2751,  2762,  2759,  2760,  2763,  2764,
    2766,  2767,  2765, -2220,  2783,  2786,  1482,  1231,  1896,  2784,
    2790,  2797, -2220,  2799,  2808,  2817,  2809,  2810,  2813,  2827,
    2818,  2850,  2825,  2855,  3556,  2860,  2872,  1027,  1027,  2868,
    2869,  3436,  2874,  2876,  2888,  2877,  2878,  3297,    63,  2879,
    1030,  2889,  2911,  2914,  2972,  2971,  3024,  2973,  3446,  2981,
    2984,  2988,  2990,  2991,  2985,  2655,  3010,  3011,  3571,  3020,
    3021,  3026,  3034,  2829,  2227,  2655,  3027,   924,  2217,  1030,
    3393,  1296,  3606,  3315,  3038,  1449,  3045,  3042,  3052, -2184,
    3063,  3060,  3071,  3104,  2217,  1030,  3081,  3105,    58,  2588,
    3113,  3094,  3093,  3096,  3123,  1985, -2220,  3124,  3171,  3120,
    3163,  3170,  3172,  3184,   156,   187,  3173,  3175,  3187,  3195,
    1897,  3202,  3197,  3206,  3220,  2998,  3213,  3214,  1898,  1296,
     484,  3221,   924,   485,  1899,  3224,  1900,  1030,  3083,  1030,
    3663,  2299,  1296,  3225,  1296,  3226,  3227,  1901,  3228,  3229,
    3230,  3062,  3235,  3242,  3243,  1296,   648,  3247,  3249,  3253,
    2655,    58,  2641,  3254,   648,   648,  3258,  3284,  3285,  3278,
    3287,  2655,  3286,  3299, -2220,  1902,  3303,  3556,  3308,   187,
    3305,  3312,  3320,  1226,  3323,  3333,  3327,  3346,  3347,  2029,
    3348,  1903,  3355,  3349,  3522,  3365,  1904,  3366,   187,  3350,
    3351,  3372,  3352,   184,  3375,  3379,  3397,  2035,  1905,  2029,
    3415,  2969,  1450,  3435,  3416,  1906,  3419,  3417,  1451,  1452,
    1453,  3420,  2371,  3421,  3426,  2333,  3422,  3439,  3428,    58,
    3429,  3441,  3445,  3447,  3449,  3450,  3451,  3453,  3455, -2220,
    1454, -2220,  3459,  3469,  3471,  3480,  3488,  3503,  1986,  3515,
    3516,  3513,  3514,   486,  2400,  3517,  3044,  3518,  3046,  3523,
    3535,  2655,  1030,  3536,    58,  3541,  3558,  3548,   487,  3568,
    3579,  3595,   488,  3608,  3617,  3619,  3620,  3621,  3622,    58,
    3632,    58,  3068,    58,  3649,  3653,  3437,  3651,  3652,  3654,
    3662,  3067,  3016,  3631,  1331,  2153,    58,  2775,  3374,  2458,
      49,    50,  2726,  1296,   831,  3041,  2735,   532,   193,   489,
     198,   345,  2315,   525,   407,  1001,   407,   533,  2316,   358,
    3460,   350,   669,   511,   512,   935,    58,    58,   963,  3296,
     187,  1958,  1296,   560,   187,   941,  3629,   490,  2116,  2374,
     558,   942,  3300,  1183,  2655,  1323,  1455,   590,  2586,  1456,
    1937,  2594,  1050,  1050,  2717,   491,  2418,  1457,  3142,  3142,
    3142,  3142,  2655,  2655,  1907,  2179,  3092,  3322,  2482,  1908,
    2183,  3650,    58,  2722,  2789,  2500,  1909,  3165,  3444,    46,
     130,  2086,    60,  3410,    61,  2465,    47,  1256,  3291,  1089,
    2468,   516,  1458,  1345,  2121,  2204,  1874,  3398,  1910,  1119,
    2472,  2077,  3504,  1911,  2119,  1296,  1296,  3635,  3087,  2402,
    2067,  3234,  2134,  3512,  3216,  2437,  1296,  1296,  3233,  1296,
    2967,   610,  1296,  3280,  1296,  3432,  3430,  1459,  1296,  3427,
    3263,  2711,  2819,  2360,  2329,  2671,   492,  3638,  3392,  2247,
    2248,  2560,  3340,  2839,  3236,  3519,  1460,  1461,  3259,  2551,
    1050,  2621,  3179,  3387,  2884,   184,  2887,  1462,  2883,  3180,
    1219,  2334,  1463,  3570,  3255,   648,  2983,    58,  2249,  2250,
    2220,  3414,  2968,    42,  3658,  2266,  1925,  2922,  2921,  2294,
      58,  2335,  2336,  2337,  3425,   473,  3391,  3342,  3119,  2655,
    3239,  2655,  2293,  2212,  3425,  3550,  2831,  3338,  2177,  3472,
    3489,  1464,   493,   474,  3481,  1891,  3051,  2742,  2085,     0,
       0,     0,     0,     0,   638,  1030,   677,     0,     0,     0,
    2338,     0,     0,     0,     0,   187,     0,  3261,  3262,  1122,
       0,  2702,  2339,  1465,  2029,     0,     0,  3598,     0,     0,
       0,    58,     0,  2340,     0,     0,     0,     0,     0,     0,
       0,  2730,     0,     0,  3293,  2730,     0,     0,     0,   407,
    2341,     0,  1163,     0,     0,     0,     0,     0,     0,    58,
    2342,     0,   407,     0,    58,     0,     0,     0,     0,     0,
       0,     0,  3433,    58,     0,  2343,     0,  1027,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,  1297,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   481,   482,
     483,     0,  3324,     0,     0,     0,     0,     0,  2655,     0,
       0,     0,     0,  2344,  3647,     0,     0,  2829,  2655,     0,
    2217,  2217,     0,  3142,  3142,     0,     0,  3142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3353,   187,
       0,     0,     0,  2345,     0,     0,     0,     0,     0,  3144,
    3144,  3144,  3144,  2346,     0,  2439,     0,     0,     0,    58,
    2217,     0,     0,     0,     0,     0,  1219,  1013,  1014,  1015,
       0,  1018,     0,  1030,  2347,     0,     0,     0,  2348,     0,
       0,  1112,     0,     0,  1112,     0,     0,  1296,  1044,     0,
    1296,     0,  1296,     0,  2655,  2480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2349,     0,     0,  3185,
       0,  3188,     0,     0,     0,  2350,     0,    58,     0,     0,
       0,     0,     0,     0,  1068,     0,     0,     0,     0,     0,
    1073,     0,  1075,     0,     0,     0,  1082,     0,   484,  1082,
       0,   485,  1082,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,     0,     0,  1296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,  1154,     0,   407,     0,     0,     0,    58,
    1018,  1167,  1170,     0,     0,     0,  1185,     0,     0,     0,
     271,     0,     0,  3547,  1197,     0,    58,     0,     0,   272,
     273,     0,     0,     0,     0,   274,   275,   276,    33,     0,
    1221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,  1296,
       0,     0,  2655,     0,     0,  1219,     0,     0,     0,     0,
    1122,     0,     0,  1112,     0,  3142,  1163,     0,     0,     0,
       0,  3142,  3142,     0,  3142,  3142,  3142,  3142,   184,     0,
    2655,   486,  2655,  3142,     0,  1296,   158,   159,     0,     0,
       0,     0,  1163,     0,   160,    33,   487,     0,     0,     0,
     488,     0,     0,     0,     0,     0,   161,     0,     0,     0,
       0,   277,  1297,  1297,    58,     0,     0,     0,   162,    58,
    1297,    58,     0,     0,     0,  2924,  2925,     0,  2926,  2927,
    2928,     0,     0,     0,     0,   648,     0,   489,     0,  2655,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,    58,     0,  3144,  3144,     0,     0,  3144,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
      58,     0,     0,   161,     0,     0,     0,     0,     0,     0,
    3324,     0,     0,   491,     0,   162,  1296,     0,  2771,  2772,
    3142,     0,     0,  3142,  3142,  3142,  3142,  3566,     0,  2781,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3569,   163,     0,     0,     0,  1112,     0,     0,     0,
    1296,     0,     0,  2793,  2794,  2795,  2796,     0,  2929,     0,
       0,  2801,  2802,  2803,  2804,     0,  2930,    54,  2806,   164,
       0,    58,    58,    58,    58,    58,    58,     0,     0,     0,
       0,     0,     0,  3600,     0,     0,  1221,     0,     0,     0,
       0,     0,     0,     0,   492,     0,     0,     0,     0,     0,
    2931,     0,  1389,     0,  1219,     0,     0,  3142,     0,  2932,
       0,     0,     0,     0,     0,  3142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,   164,     0,  2933,  2934,
       0,     0,     0,     0,  1417,     0,     0,     0,     0,     0,
    2858,  2859,     0,     0,     0,     0,     0,  2863,  2864,  1296,
     493,  3640,     0,  1122,  1122,     0,   165,     0,     0,     0,
       0,   278,  1444,  1444,  1444,     0,  1444,     0,  1444,  1444,
       0,     0,     0,  2935,    63,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3656,  3657,
    3640,   166,     0,     0,     0,     0,  3144,    58,     0,  3664,
       0,     0,  3144,  3144,     0,  3144,  3144,  3144,  3144,  1170,
       0,     0,     0,     0,  3144,     0,     0,  2936,     0,     0,
       0,  1528,     0,   165,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,     0,     0,
       0,     0,     0,     0,     0,  1221,  1389,     0,     0,     0,
       0,     0,     0,     0,  1881,   279,     0,     0,   166,     0,
     280,     0,     0,   281,     0,     0,     0,     0,     0,     0,
    1889,  1889,  2937,     0,   169,     0,     0,     0,     0,   282,
       0,     0,     0,     0,  3032,  3033,     0,     0,     0,   170,
       0,     0,   167,  3040,   283,     0,     0,   284,     0,     0,
     285,     0,     0,     0,   168,     0,     0,     0,     0,   286,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3144,     0,     0,  3144,  3144,  3144,  3144,     0,     0,
    3074,  3075,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,     0,     0,     0,     0,  1385,
     287,     0,     0,     0,   173,  3095,   170,  3097,     0,     0,
       0,     0,   288,     0,   171,  2503,  2504,  2505,  2506,  2507,
    2508,     0,     0,   289,     0,     0,     0,   172,     0,   174,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,   272,   273,     0,     0,     0,     0,   274,   275,   276,
      33,     0,     0,   290,     0,     0,     0,     0,  3144,     0,
       0,     0,     0,     0,     0,     0,  3144,     0,  3166,  3167,
       0,   173,  3168,  3169,    63,     0,    63,  1170,  1082,     0,
       0,     0,     0,     0,     0,  2076,  1095,     0,     0,  1170,
       0,     0,     0,  2087,     0,     0,   174,   176,     0,     0,
       0,     0,     0,     0,   291,     0,   177,     0,     0,     0,
       0,     0,  2509,     0,  1221,  1154,   292,   293,     0,     0,
     175,     0,     0,     0,   294,     0,     0,     0,   161,     0,
       0,     0,     0,   277,     0,   295,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,  2938,  2939,
    2940,  2941,  2942,  2943,  2944,  2945,  2946,  2947,     0,  2120,
    1154,  3223,    63,     0,   176,     0,     0,   163,     0,     0,
       0,     0,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1219,     0,     0,     0,     0,
     178,   179,     0,     0,     0,  2146,   598,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
    2173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3290,     0,     0,     0,  3295,     0,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   178,   179,    54,
       0,   164,     0,     0,     0,  3302,     0,     0,     0,     0,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,     0,  1297,     0,  3313,   471,   472,   473,     0,     0,
       0,     0,  1297,  1297,     0,     0,     0,     0,  1297,  1297,
    1297,  1297,   458,   459,   460,   474,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   475,   476,
     477,   478,   479,   480,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   481,   482,   483,  2510,
       0,     0,     0,  1163,     0,     0,     0,     0,   165,     0,
       0,     0,  2511,   278,     0,     0,     0,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,   482,   483,     0,     0,  2512,     0,   167,     0,     0,
       0,  2513,   271,   475,   476,   477,   478,   479,   480,   168,
       0,   272,   273,     0,  1050,     0,     0,   274,   275,   276,
      33,   481,   482,   483,     0,     0,     0,   279,     0,     0,
       0,     0,   280,     0,     0,   281,     0,     0,     0,     0,
    2514,     0,     0,     0,     0,     0,   169,     0,     0,  1297,
       0,   282,     0,     0,     0,     0,   484,     0,     0,   485,
       0,   170,     0,     0,  2515,     0,   283,     0,     0,   284,
       0,     0,   285,     0,  2516,  2517,     0,     0,     0,     0,
    2518,   286,   172,     0,     0,     0,     0,     0,     0,     0,
    2519,     0,     0,  3458,     0,     0,  3461,     0,   161,   484,
       0,     0,   485,   277,     0,     0,     0,     0,     0,     0,
     162,     0,  2520,     0,     0,  2521,  2522,     0,     0,     0,
    2523,     0,   287,     0,  2203,  1221,   173,     0,     0,     0,
     484,     0,     0,   485,   288,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,   289,     0,  2718,     0,     0,
       0,   174,     0,     0,     0,  1297,     0,     0,     0,     0,
       0,   484,     0,  1297,   485,     0,  1297,  1297,  1297,  1297,
       0,     0,     0,     0,     0,   290,     0,  2524,  1297,   486,
       0,  2253,     0,     0,     0,     0,     0,     0,  2525,     0,
       0,     0,     0,     0,   487,     0,     0,     0,   488,     0,
       0,     0,     0,     0,  1297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
       0,     0,   486,     0,     0,     0,   291,     0,   177,    54,
       0,   164,     0,     0,  3545,   489,     0,   487,   292,   293,
       0,   488,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,   486,     0,     0,     0,   295,     0,     0,
       0,     0,     0,   490,     0,     0,     0,     0,   487,     0,
       0,     0,   488,     0,     0,     0,     0,     0,   489,     0,
       0,   491,  3572,  3573,   486,  3575,     0,  3577,  3578,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,  1219,     0,   488,   586,     0,   490,     0,     0,   489,
       0,     0,   178,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,   165,     0,
       0,     0,     0,   278,     0,     0,     0,   490,     0,     0,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3624,     0,  3625,     0,   491,     0,     0,     0,     0,
       0,     0,   492,   166,     0,     0,     0,     0,   490,     0,
       0,     0,  2430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,  3637,     0,     0,
       0,     0,     0,  1170,     0,     0,     0,   167,     0,     0,
       0,     0,     0,  3644,  3645,   492,     0,  3646,     0,   168,
    3648,     0,     0,     0,   156,   466,   467,   468,   469,   470,
     471,   472,   473,  1154,     0,     0,     0,   279,   493,     0,
       0,     0,   280,     0,     0,   281,   492,     0,     0,     0,
     474,     0,  1297,     0,     0,     0,   169,     0,     0,     0,
       0,   282,     0,     0,     0,     0,     0,     0,  1170,  2534,
    1170,   170,     0,     0,  1018,     0,   283,   492,     0,   284,
     271,   493,   285,     0,     0,     0,     0,     0,     0,   272,
     273,   286,   172,     0,     0,   274,   275,   276,    33,     0,
    1297,     0,     0,     0,     0,     0,     0,     0,     0,  2580,
       0,     0,   493,  1297,     0,  1297,  3126,  3127,     0,     0,
       0,     0,   274,  1277,  1278,    33,  1297,     0,     0,     0,
       0,  3084,   287,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,   493,   288,     0,     0,   475,   476,   477,
     478,   479,   480,     0,     0,   289,     0,     0,     0,     0,
       0,   174,     0,     0,     0,   481,   482,   483,     0,     0,
       0,     0,     0,     0,     0,  1297,   161,     0,     0,     0,
       0,   277,     0,     0,     0,   290,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3128,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,     0,     0,  1170,   291,  1170,   177,     0,
       0,     0,     0,     0,     0,     0,  1170,     0,   292,   293,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   295,     0,     0,
       0,  1170,     0,     0,  1297,     0,     0,     0,     0,     0,
       0,  1221,     0,     0,     0,     0,     0,     0,     0,     0,
    2755,     0,     0,     0,  2758,     0,     0,     0,     0,     0,
       0,     0,     0,  1297,     0,   484,     0,    54,   485,   164,
    1276,     0,     0,     0,   274,  1277,  1278,    33,     0,  2780,
       0,     0,   178,   179,     0,     0,     0,     0,     0,  1297,
    1297,  1297,  1297,     0,  1111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2756,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,  1297,  1297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1297,  1297,     0,
    1297,   474,     0,  1297,     0,  1297,     0,     0,     0,  1297,
    1279,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   278,     0,     0,  1050,  1050,  1050,     0,  1050,  1050,
    1050,  1050,  1050,  1050,     0,     0,     0,  1050,   486,     0,
       0,     0,   274,  1277,  1278,    33,     0,     0,     0,  2856,
       0,   166,     0,   487,     0,     0,     0,   488,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,     0,     0,     0,     0,
       0,     0,   474,     0,   489,     0,     0,   168,   475,   476,
     477,   478,   479,   480,     0,     0,     0,     0,     0,     0,
       0,     0,  1170,     0,     0,   279,   481,   482,   483,     0,
     280,     0,   490,   281,     0,     0,     0,     0,  3128,     0,
       0,     0,     0,     0,   169,     0,  1111,     0,     0,   282,
     491,     0,     0,     0,     0,     0,     0,     0,     0,   170,
    1280,     0,     0,     0,   283,     0,     0,   284,     0,     0,
     285,     0,     0,     0,  1219,     0,     0,     0,     0,   286,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1170,  3129,     0,     0,  3130,     0,     0,     0,     0,   475,
     476,   477,   478,   479,   480,     0,     0,  3131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,   482,   483,
     287,     0,     0,     0,   173,  1170,     0,     0,     0,     0,
       0,   492,   288,     0,  1297,  1297,     0,     0,  1297,     0,
    3065,     0,  1044,   289,  3069,     0,  3132,  3133,     0,   174,
       0,     0,     0,     0,     0,     0,     0,  3080,     0,  3134,
       0,     0,   187,     0,  1111,     0,   484,     0,     0,   485,
       0,     0,     0,   290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3100,  3102,     0,
       0,     0,  1297,     0,     0,  1297,     0,   493,  1297,     0,
    3135,  1297,     0,  1297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,     0,     0,
       0,     0,     0,     0,   291,     0,   177,     0,     0,     0,
       0,     0,     0,  3164,     0,     0,   292,   293,     0,  3136,
       0,  1274,  1275,  1276,   294,     0,     0,   274,  1277,  1278,
      33,  3137,  1280,     0,     0,   295,     0,   484,     0,     0,
     485,     0,     0,  3138,  3139,     0,  1297,     0,     0,     0,
       0,  3140,     0,     0,  3141,     0,     0,     0,     0,     0,
       0,     0,   295,  1281,     0,     0,  1282,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1283,
       0,     0,     0,     0,   487,     0,     0,     0,   488,     0,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3217,     0,
       0,     0,     0,  1279,     0,     0,     0,     0,     0,  1284,
    1297,  3232,     0,     0,     0,   489,     0,     0,     0,     0,
       0,  1285,     0,     0,     0,     0,  1297,     0,     0,     0,
       0,     0,  1297,  1297,     0,  1297,  1297,  1297,  1297,     0,
    1280,     0,     0,   490,  1297,     0,  1297,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  1297,     0,     0,
       0,   491,  1286,     0,     0,   487,     0,     0,     0,   488,
     597,  3129,  1170,     0,  3130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,  3131,     0,     0,
       0,     0,     0,     0,     0,  1287,     0,     0,     0,     0,
    1170,  1288,   132,     0,     0,  1154,   489,     0,     0,     0,
    1289,  1290,     0,  1291,  1221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1292,  1293,  3133,     0,  1111,
       0,  1219,     0,  1294,   490,     0,  1295,     0,     0,  3134,
       0,   133,   492,     0,   295,     0,     0,  1297,     0,     0,
       0,  1297,   491,     0,  1297,  1297,  1297,  1297,     0,     0,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1297,     0,     0,
    3135,  1297,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,   493,     0,
    1154,     0,   137,     0,     0,     0,     0,     0,     0,  3136,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
       0,  3137,     0,   492,     0,     0,     0,     0,  1297,     0,
     139,     0,     0,  3138,  3139,     0,  1297,     0,     0,     0,
     140,  3140,     0,     0,  3141,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,   141,     0,     0,  3217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1545,  1546,  1547,  1548,  1549,  1550,     0,  1551,  1552,  1553,
    1297,     0,     0,  1554,  1555,  1556,  1557,  1558,  1559,   493,
       0,     0,     0,     0,     0,   142,     0,     0,  1560,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1561,     0,   143,     0,
    1170,     0,     0,     0,     0,  1280,     0,     0,  1219,     0,
       0,     0,     0,   144,     0,     0,     0,  1170,     0,     0,
     145,     0,     0,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1281,     0,     0,  1282,
       0,     0,     0,     0,   147,  1154,     0,     0,   148,     0,
       0,     0,  1283,  1562,     0,     0,     0,     0,     0,     0,
       0,     0,  1563,     0,     0,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1970,
    1564,  1565,     0,     0,     0,   150,     0,     0,     0,  1566,
       0,     0,  1284,     0,     0,     0,  1567,  1568,     0,     0,
    1569,  1570,  1571,  1572,  1285,     0,  1573,  1574,     0,     0,
       0,     0,     0,     0,     0,  3217,     0,     0,     0,     0,
    3507,     0,  3509,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1286,  1575,     0,     0,     0,
       0,     0,     0,  1170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1576,     0,
       0,  1221,     0,     0,  1577,     0,     0,   187,  1287,     0,
    2176,  1578,     0,  1579,  1288,     0,     0,     0,  1580,     0,
       0,     0,     0,  1289,  1290,     0,  1291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1292,  1293,
       0,     0,     0,     0,  1581,     0,  1294,     0,     0,  1295,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1444,  1444,  1444,  1444,  1444,  1444,     0,     0,
       0,     0,  1582,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1583,     0,     0,     0,     0,
       0,  1584,     0,     0,     0,     0,     0,     0,     0,     0,
    1585,  1586,     0,     0,     0,     0,     0,  1587,     0,     0,
    1588,  1589,     0,     0,     0,  1590,     0,     0,     0,     0,
       0,  1591,  1592,     0,     0,     0,     0,     0,  1593,  1594,
    1595,     0,     0,  1596,  1597,  1598,     0,     0,     0,  1599,
       0,     0,     0,  1600,     0,  1601,     0,     0,     0,     0,
       0,     0,  1602,  1603,  1604,  1605,     0,  1606,  1607,     0,
       0,     0,  1608,  1609,     0,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,     0,     0,     0,     0,     0,  1617,  1618,  1619,
       0,  1620,  1621,     0,     0,     0,  1622,  1623,  1624,  1625,
    1626,  1627,  1628,  1629,     0,  1630,     0,     0,  1221,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,  1666,  1667,     0,  1668,  1669,     0,
       0,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1679,     0,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,
    1688,  1689,  1690,  1691,  1692,  1693,  1694,     0,     0,  1695,
    1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,     0,  1704,
    1705,  1706,  1707,     0,  1708,  1709,  1710,  1711,  1712,  1713,
    1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,
    1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,
       0,  1744,  1745,  1746,  1747,  1748,  1749,     0,     0,  1750,
    1751,     0,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,
    1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,     0,     0,
    1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,
    1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,
    1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,
    1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,     0,     0,     0,     0,  1840,  1841,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1851,     0,     0,
       0,     0,     0,     0,     0,  1852,     0,     0,     0,     0,
    1853,     0,     0,     0,  1854,     0,     0,  1855,  1856,  1857,
    1858,     0,     0,  1859,  1860,     0,  1861,  1862,  1863,  1545,
    1546,  1547,  1548,  1549,  1550,     0,  1551,  1552,  1553,     0,
       0,     0,  1554,  1555,  1556,  1557,  1558,  1559,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1560,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1561,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1562,     0,     0,     0,     0,     0,     0,     0,
       0,  1563,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1564,
    1565,     0,     0,     0,     0,     0,     0,     0,  1566,     0,
       0,     0,     0,     0,     0,  1567,  1568,     0,     0,  1569,
    1570,  1571,  1572,     0,     0,  1573,  1574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1576,     0,     0,
       0,     0,     0,  1577,     0,     0,     0,     0,     0,     0,
    1578,     0,  1579,     0,     0,     0,     0,  1580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1581,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1582,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1583,     0,     0,     0,     0,     0,
    1584,     0,     0,     0,     0,     0,     0,     0,     0,  1585,
    1586,     0,     0,     0,     0,     0,  1587,     0,     0,  1588,
    1589,     0,     0,     0,  1590,     0,     0,     0,     0,     0,
    1591,  1592,     0,     0,     0,     0,     0,  1593,  1594,  1595,
       0,     0,  1596,  1597,  1598,     0,     0,     0,  1599,     0,
       0,     0,  1600,     0,  1601,     0,     0,     0,     0,     0,
       0,  1602,  1603,  1604,  1605,     0,  1606,  1607,     0,     0,
       0,  1608,  1609,     0,  1610,  1611,  1612,  1613,  1614,  1615,
    1616,     0,     0,     0,     0,     0,  1617,  1618,  1619,     0,
    1620,  1621,     0,     0,     0,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,  1629,     0,  1630,     0,     0,     0,  1631,  1632,
    1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,
    1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,     0,  1668,  1669,     0,     0,
    1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
       0,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,     0,     0,  1695,  1696,
    1697,  1698,  1699,  1700,  1701,  1702,  1703,     0,  1704,  1705,
    1706,  1707,     0,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,
    1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,     0,
    1744,  1745,  1746,  1747,  1748,  1749,     0,     0,  1750,  1751,
       0,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,     0,     0,  1778,
    1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,
    1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,
    1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,
    1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,
    1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,
    1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,
    1839, -2221,     0,     0,     0,  1840,  1841,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,  1849,  1850,     0, -2221,     0, -2221,
       0, -2221, -2221,     0,     0,     0,  1851,     0,     0,     0,
       0,     0,     0,     0,  1852,     0,     0,     0,     0,  1853,
       0,     0,     0,  1854,     0,     0,  1855,  1856,  1857,  1858,
       0,     0,  1859,  1860,     0,  1861,  1862,  1863,     0,     0,
     458,   459,   460,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2221,     0,     0,     0,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   458,   459,   460,     0,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
   -2221,     0,     0,     0,     0,     0,     0,     0,     0,   474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2221,     0,
   -2221,   475,   476,   477,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,     0,     0, -2221,     0,     0,     0,     0,
       0,     0, -2221,     0, -2221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2221,     0,     0,     0,     0,
   -2221,     0,     0,     0,     0,     0,     0,     0, -2221,     0,
       0,     0, -2221,     0,     0,     0,     0,     0, -2221,     0,
       0,     0, -2221, -2221, -2221, -2221,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,     0, -2221,     0,     0,
       0,     0,     0,     0,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0, -2221,     0,     0, -2221,     0, -2221,
       0,     0,     0,     0,     0,     0, -2221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2221,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
   -2221, -2221,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2221,     0,     0,     0,     0,
       0,     0,     0, -2221,     0,     0,     0, -2221,     0,     0,
       0,     0,     0,     0,     0, -2221, -2221, -2221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2221,     0,     0,     0,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,     0,     0,
       0,   488,   607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     2,     0,   679,   680,   681,   486,     0,     0,
     682,     0,     0,   683,     0,     0,   490,     0,     0,     0,
     684,   685,   487,     0,     0, -2221,   488,   970,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2221,     0,   489,     0,   686,   687,     0,     0,     0,
     688,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     689,   690,     0,   691,     0,     0,     0,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,   692,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2221,     0,   491,
       0,     0,     0,     0,   693,   492,     0,   694,   695,     0,
       0, -2221, -2221, -2221, -2221, -2221, -2221, -2221,     0, -2221,
   -2221,     0,   696,     0,   697,   698,   699,     0,     0,     0,
       0,     0,     0,     0,   700,   701, -2221,   702,   703,   704,
       0,     0,     0,     0,     0,   705,     0,     0,   706,     0,
     707,   708,   709,     0,     0,     0,     0,     0,   710,     0,
     711,   712,     0,   713,     0,   714,   715,     0,     0,   716,
       0,   493,   717,   718,   719,   720,   721,   722,     0,     0,
     492,   723,   724,   725,     0,   726,     0,     0,     0,   727,
       0,   728,   729,     0,     0,     0,     0,   730,     0,     0,
     731,     0,     0,   732,     0,   733,     0,   734,     0,   735,
       0,     0,     0,   736,   737,     0,   738,   739,   740,     0,
       0,   741,     0,   742,   743,     0,   744,     0,     0,     0,
       0,     0,     0,     0,   745,   746,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   493,   747,     0,     0,
     748,   749,     0,     0,   750,   751,     0,     0,   752,   753,
       0,     0,     0,     0,     0,     0,     0,   754,   755,   756,
       0,   757,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   758,   759,   760,     0,   761,     0,     0,     0,   762,
     763,     0,     0,     0,   764,     0,     0,     0,     0,     0,
       0,     0,   765,     0,     0,     0,     0,     0,     0,     0,
     766,   767,   768,     0,     0,     0,     0,     0,   769,   770,
       0,     0,     0,     0,     0,     0,   771,     0,     0,   772,
       0,     0,     0,   773,   774,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   775,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,     0,     0,     0,     0,     0,     0,     0,   777,
       0,     0,     0,     0,     0,   778,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   779,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,   780,
       0,     0,     0,     0,     0,   781,     0,   782,   783,     0,
       0,     0,     0,     0,     0,   784,     0,     0,     0,     0,
       0,     0,     0,     0,   458,   459,   460,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   785,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,   786,     0,     0,     0,     0,
       0,     0,   787,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   788,   789,     0,     0,
       0,   790,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   791,     0,     0,     0,     0,     0,   792,
     793,   794,   795,     0,     0,     0,   796,     0,     0,     0,
     797,     0,     0,     0,     0,     0,     0,   798,   799,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   800,     0,
     801,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,   802,     0,   803,     0,     0,   804,     0,     0,     0,
       0,     0,   805,   481,   482,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   806,     0,
       0,   807,     0,     0,     0,     0,   808,     0,     0,   809,
     810,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   811,     0,     0,     0,     0,     0,
       0,   812,   458,   459,   460,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,   813,   814,   815,   816,   817,   818,
     819,     0,     0,   820,     0,   821,   474,   822,     0,     0,
     458,   459,   460,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   478,   479,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   481,   482,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   459,   460,   486,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,   487,     0,     0,     0,   488,   976,     0,     0,   475,
     476,   477,   478,   479,   480,     0,     0,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,   482,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
     490,   484,     0,     0,   485,     0,     0,     0,     0,     0,
       0,   474,     0,     0,     0,     0,     0,     0,   491,   458,
     459,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,   484,
       0,     0,   485,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,   459,   460,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   484,     0,   492,
     485,     0,     0,     0,     0,     0,     0,     0,   475,   476,
     477,   478,   479,   480,   474,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,     0,   481,   482,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,     0,   488,   977,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,     0,   486,     0,     0,   493,     0,     0,   481,   482,
     483,     0,     0,     0,     0,     0,     0,   487,     0,     0,
     489,   488,   978,     0,     0,     0,   459,   460,     0,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   484,     0,     0,   485,     0,     0,   490,     0,
       0,   475,   476,   477,   478,   479,   480,     0,   489,   474,
     486,     0,     0,     0,     0,     0,   491,     0,     0,   481,
     482,   483,     0,     0,     0,   487,     0,     0,     0,   488,
     979,     0,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,   484,     0,     0,   485,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   490,     0,     0,   492,   484,     0,
       0,   485,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,   491,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,   481,   482,   483,     0,     0,     0,
     487,     0,     0,     0,   488,   492,     0,     0,     0,     0,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   484,
       0,     0,   485,   493,     0,     0,     0,     0,     0,     0,
       0,   489,   474,     0,     0,     0,     0,     0,     0,   486,
       0,     0,     0,     0,   981,     0,     0,     0,     0,     0,
       0,     0,     0,   492,   487,     0,     0,     0,   488,   490,
       0,   493,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,   491,     0,     0,
       0,   486,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,   474,     0,     0,   489,   487,     0,     0,     0,
     488,     0,     0,     0,   474,     0,     0,     0,   982,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,   490,   484,     0,     0,   485,     0,   475,
     476,   477,   478,   479,   480,     0,     0,   489,     0,     0,
       0,   491,   486,     0,     0,     0,     0,   481,   482,   483,
     985,     0,     0,     0,     0,     0,     0,   487,   492,     0,
       0,   488,     0,     0,     0,   490,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,   491,     0,     0,     0,     0,     0,   475,
     476,   477,   478,   479,   480,   474,     0,     0,   489,     0,
       0,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,     0,     0,     0,     0,  2625,   481,
     482,   483,   492,     0,   493,     0,   490,  1274,  1275,  1276,
       0,     0,     0,   274,  1277,  1278,    33,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2625,     0,   487,     0,   492,     0,   488,     0,     0,  1274,
    1275,  1276,     0,     0,     0,   274,  1277,  1278,    33,   468,
     469,   470,   471,   472,   473,     0,     0,   484,   493,     0,
     485,     0,   475,   476,   477,   478,   479,   480,     0,     0,
       0,     0,   474,   489,     0,     0,     0,     0,     0,     0,
     481,   482,   483,     0,     0,     0,     0,     0,     0,  1279,
       0,     0,     0,     0,     0,   492,     0,     0,     0,     0,
     493,   490,     0,     0,     0,  1274,  1275,  1276,     0,     0,
       0,   274,  1277,  1278,    33,     0,     0,   484,     0,   491,
     485,     0,   467,   468,   469,   470,   471,   472,   473,   484,
       0,  1279,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,  1274,
    1275,  1276,     0,     0,     0,   274,  1277,  1278,    33,     0,
       0,   493,     0,     0,     0,     0,     0,     0,     0,   475,
     476,   477,   478,   479,   480,     0,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,   481,   482,   483,
       0,     0,     0,     0,     0,   487,     0,  1279,     0,   488,
     492,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1111,     0,     0,     0,     0,
     484,     0,     0,   485,  1274,  1275,  1276,     0,     0,     0,
     274,  1277,  1278,    33,     0,     0,   489,     0,     0,     0,
     486,  1279,     0,   475,   476,   477,   478,   479,   480,     0,
       0,     0,   486,     0,     0,   487,     0,  1111,     0,   488,
       0,   481,   482,   483,   490,     0,   493,   487,  1274,  1275,
    1276,   488,     0,     0,   274,  1277,  1278,    33,     0,     0,
       0,     0,   491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,     0,     0,  1279,     0,     0,  2626,
       0,     0,     0,  1111,   490,     0,     0,   484,     0,     0,
     485,     0,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,   491,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,   487,     0,
    1279,  2626,   488,   492,     0,     0,     0,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3126,  3127,     0,
       0,     0,     0,   274,  1277,  1278,    33,     0,     0,   489,
       0,   484,     0,     0,   485,     0,     0,     0,     0,     0,
       0,     0,   980,     0,     0,     0,     0,     0,     0,     0,
       0,  1280,     0,   492,     0,     0,     0,   490,     0,   493,
       0,  3126,  3127,     0,     0,   492,     0,   274,  1277,  1278,
      33,     0,  1111,     0,     0,   491,     0,     0,     0,     0,
     486,     0,  1281,     0,     0,  2627,     0,     0,     0,     0,
       0,     0,     0,  1280,     0,   487,     0,  2628,  1283,   488,
       0,  2626,     0,     0,     0,     0,     0,     0,     0,  3128,
       0,     0,     0,     0,     0,     0,  1111,     0,     0,   493,
       0,     0,     0,     0,  1281,  1970,     0,  2627,     0,     0,
       0,   493,     0,     0,     0,     0,   489,     0,  1284,  2628,
    1283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1285,     0,     0,  3128,   486,     0,   492,     0,     0,  1280,
       0,     0,     0,     0,   490,     0,     0,     0,     0,   487,
       0,     0,     0,   488,     0,     0,     0,     0,     0,     0,
    1284,     0,   491,     0,     0,     0,     0,     0,     0,     0,
    1281,  1286,  1285,  1282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1280,     0,     0,  1283,     0,     0,     0,
     489,     0,     0,     0,     0,     0,     0,   199,     0,     0,
     200,     0,   493,     0,  1287,     0,     0,     0,     0,     0,
    1288,     0,     0,  1286,  1281,  1111,     0,  2627,   490,  1289,
    1290,     0,  1291,     0,     0,  2474,  1284,     0,     0,  2628,
    1283,     0,     0,     0,  1292,  1293,   491,     0,  1285,     0,
       0,     0,  1294,   492,     0,  1295,  1287,     0,     0,     0,
       0,     0,  1288,   295,     0,     0,     0,     0,  1280,  1111,
       0,  1289,  1290,     0,  1291,     0,     0,     0,     0,     0,
    1284,     0,     0,     0,   201,     0,  1292,  1293,     0,  1286,
       0,     0,  1285,     0,  1294,     0,     0,  1295,     0,  1281,
     202,   203,  1282,     0,     0,   295,     0,     0,     0,     0,
     204,     0,  1280,     0,     0,  1283,     0,     0,     0,   493,
       0,     0,  1287,     0,     0,     0,     0,   492,  1288,     0,
       0,     0,     0,  1286,     0,     0,     0,  1289,  1290,     0,
    1291,     0,     0,  1281,     0,     0,  1282,     0,     0,     0,
       0,     0,  1292,  1293,  3553,  1284,     0,     0,     0,  1283,
    1294,     0,     0,  1295,     0,     0,  1287,  1285,     0,     0,
       0,   295,  1288,     0,     0,     0,     0,     0,     0,     0,
       0,  1289,  1290,     0,  1291,     0,     0,  2503,  2504,  2505,
    2506,  2507,  2508,   493,     0,     0,  1292,  1293,     0,  1284,
       0,     0,     0,     0,  1294,     0,     0,  1295,  1286,     0,
       0,  1285,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1287,     0,     0,     0,     0,     0,  1288,     0,     0,
       0,     0,  1286,     0,     0,     0,  1289,  1290,     0,  1291,
       0,     0,  3129,     0,     0,  3130,     0,     0,     0,     0,
       0,  1292,  1293,     0,     0,  1280,     0,     0,  3131,  1294,
       0,   205,  1295,     0,  2509,  1287,     0,     0,     0,     0,
     295,  1288,     0,     0,     0,     0,     0,     0,     0,     0,
    1289,  1290,     0,  1291,     0,  1970,  3129,     0,     0,  3130,
       0,     0,     0,     0,     0,  1292,  1293,     0,  3133,     0,
     206,     0,  3131,  1294,     0,     0,  1295,     0,     0,     0,
    3134,     0,     0,     0,   295,     0,     0,     0,     0,   207,
     208,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,     0,     0,
       0,     0,  3133,     0,     0,     0,     0,     0,     0,     0,
       0,  3135,     0,     0,  3134,     0,     0,     0,     0,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3524,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,     0,     0,     0,     0,
    3136,     0,     0,     0,     0,  3135,     0,     0,     0,   215,
       0,     0,  3137,     0,     0,     0,     0,     0,     0,   216,
       0,     0,     0,     0,  3138,  3139,     0,     0,     0,     0,
       0,     0,  3140,     0,   217,  3141,  3525,     0,     0,     0,
       0,     0,     0,   295,  3136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3137,     0,     0,     0,
       0,  3526,     0,     0,     0,     0,     0,     0,  3138,  3139,
    3527,     0,     0,     0,   218,     0,  3140,     0,     0,  3141,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3528,     0,
       0,  2510,   220,     0,     0,     0,  3529,     0,     0,   221,
       0,     0,   222,     0,  2511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,     0,     0,  2512,     0,     0,
       0,     0,     0,  2513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,     0,  2514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2515,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2516,  2517,     0,     0,
       0,     0,  2518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2520,     0,     0,  2521,  2522,     0,
       0,     0,  2523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2524,
       0,     0,     0,     0,     0,     0,     0,     0,  3531,     0,
    2525
};

static const short yycheck[] =
{
       3,     4,     5,   171,   396,     8,   107,    45,  1048,  1112,
     652,   715,  1124,   968,  1437,  1135,  1136,   995,  1138,  1164,
    1140,  1141,  1274,  1275,   190,    69,   792,   546,   261,   262,
     127,  1159,  1139,   794,   776,   637,   595,    40,  1355,  1121,
    1908,  1348,    54,   259,   260,  1120,     5,  2088,   173,    52,
     266,    54,  2606,  1380,    92,  2326,  1873,  1874,    25,    27,
      27,   572,    65,  2277,   588,  2461,  2842,  2843,  2844,    72,
     171,    20,    27,    76,   118,     5,    79,    80,    27,  2034,
       5,    27,    85,    86,  2028,    26,    27,  2037,   751,   190,
      24,  2206,    26,  2393,     5,  1979,  1980,  1981,  1982,     8,
      19,    27,  1970,   106,  2324,   149,  2502,    26,   812,    24,
     712,    26,     5,     5,  2872,    25,     5,    27,     5,   145,
     123,   723,    27,   126,     5,  2320,  2321,  2322,   131,  2845,
    2325,  1213,   108,   688,  1246,    25,     5,    27,   263,     5,
     237,   238,   267,   108,   269,  1227,   271,   272,   273,    25,
      26,    27,    27,    27,   322,   280,   782,    19,     6,   284,
     285,     5,    24,    25,    26,   720,   721,    45,    24,    25,
      26,    27,     5,    20,     5,    27,   778,  1217,    25,   781,
      27,   225,     5,   227,    25,    20,    27,    27,   790,   192,
      25,  2386,    27,  1296,    24,    25,    26,    27,   716,    24,
      25,    26,    27,    24,    25,    26,    24,    25,    26,    27,
      24,    25,    26,    27,    92,    27,    25,   772,    27,     6,
      54,   322,   740,     6,     5,   326,     5,  2985,    25,  2987,
      27,   234,     5,     5,   127,   128,    25,   240,    27,     9,
      10,     5,    12,    13,    14,    15,    16,    17,   114,   252,
     116,  2620,   118,  2622,   183,   258,   259,   260,   261,   262,
     133,   134,   213,   266,   189,    25,   438,    27,   786,   196,
    2577,    27,    18,    19,    20,    21,    22,    25,   796,    27,
       5,   799,  2922,  1111,   111,   803,    91,    92,    93,    94,
      95,   809,  2218,   811,     5,   236,   387,   131,   132,   343,
     392,     5,   281,   320,   281,   349,  2498,  2260,   433,   436,
    2263,   436,   315,   316,  2900,     5,  2902,   476,   452,  2905,
    1395,    30,   325,     5,   504,    34,   236,  1282,   453,   454,
     455,   456,     5,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
    2564,   517,   387,  2548,  2395,     5,  2627,   873,   328,   403,
     485,   486,   578,  2558,   591,   490,  1494,   492,     5,     5,
     136,   341,    18,    19,    20,    21,    22,    10,  1120,   595,
     236,   438,   507,   508,   509,   510,   686,   687,    27,   514,
      99,   691,   692,   341,   695,   236,  1436,   106,   504,  3355,
       5,   220,    23,     8,   704,     5,   236,   476,   209,   320,
    3366,   236,   580,     0,   471,  3173,   517,  3175,   236,   294,
    1181,  2305,     5,    56,   724,   196,     5,   727,   320,    16,
    1533,     5,   282,   733,   503,   662,    27,   737,   583,   236,
       5,   741,    27,   152,   153,   745,     5,   236,  2643,   749,
     750,   160,   752,     5,     5,   755,   290,   757,   758,   759,
     761,     5,   634,    27,     5,   765,     9,    10,   768,    12,
      13,    14,    15,    16,    17,   775,   422,     5,     5,   580,
     236,     5,   782,   209,   664,   651,    31,   632,   236,   789,
    1045,     5,   536,   320,   100,   101,     5,     5,   317,     0,
     800,     5,     5,   506,   804,   475,    23,   197,   808,   547,
     548,   670,  1067,   583,   814,   197,     5,   817,    23,     5,
       5,   486,   397,   397,   130,   131,   132,   475,   298,   669,
       5,     5,   623,     5,   511,     5,   539,     5,     5,   542,
    1146,  1147,  1060,     5,     5,   397,     5,   550,   640,  2744,
     651,     5,   692,   769,   787,   788,     5,     5,   664,     5,
       5,   656,   632,     5,   567,   392,   569,     5,    18,    19,
      20,    21,    22,   550,   577,   578,   703,     5,   581,     5,
      27,  2398,     5,   816,  2776,    29,   819,   151,   623,     5,
     438,   392,   595,     5,     5,  1423,   613,   236,     5,   554,
       5,  2815,   401,   508,  3190,   546,   431,    25,     5,   436,
       5,   587,   442,     5,   640,     5,     5,  2544,   329,  1245,
    2546,   442,   587,  1972,   442,   329,   605,  1143,   472,  2582,
     559,   661,  2827,   483,  1150,  3275,   476,   201,  1399,   472,
    2911,   516,   516,   594,   571,   236,  1164,  3363,   418,   419,
    1411,   438,  1171,  1395,  1172,   438,  1174,   421,   599,   280,
     606,     5,    28,   436,   476,  3061,   392,  2535,   438,   547,
     560,   674,   236,   450,   238,   431,   679,   680,   681,   682,
     683,   684,   685,  3079,    10,   688,   689,   690,     5,   598,
     693,   584,   695,   472,   442,   698,  2811,   700,   516,  1341,
     472,   664,   613,   294,   474,   414,   709,   532,   634,  2016,
     591,   621,   601,   438,   601,   634,   476,   720,   721,   516,
    2037,   613,    55,    56,    57,    58,   472,   730,  2672,   598,
     664,   440,   662,   736,  3034,  2690,   661,  1400,  3038,   742,
     743,   744,  2692,   711,   711,   748,  1270,   706,   751,   664,
     753,   754,  2175,  1264,   595,   298,   711,  2977,   761,  3517,
     401,   764,   711,   280,   595,   711,   769,   770,   591,   772,
      27,   335,   713,   776,  3328,   280,   779,  2972,   671,  2974,
     656,   110,   785,  2110,   787,   788,   613,  3007,  3342,   792,
     793,   794,  3568,    27,  2595,   798,   662,   670,   801,   472,
     571,   510,   664,   806,   670,   223,     5,  3176,   664,   656,
     813,   621,   815,   816,   595,   818,   819,  3124,   821,   822,
    1375,   656,   472,   628,  1124,  2174,   472,    27,   667,  1384,
     288,   601,   344,   667,   664,   472,   472,   381,   438,   664,
     404,   630,    27,   664,   356,   178,   664,   656,   412,  2650,
     664,   661,   416,   186,  1409,   438,  3163,   634,   983,   438,
     637,   986,   195,   589,   438,   198,   693,   694,   695,   994,
     995,  1263,   413,   438,   504,   418,   419,   704,  1484,   438,
      26,    27,   721,  1401,  1402,  1403,   438,   438,   432,   453,
    2817,  2818,   409,   602,   500,   683,   622,   667,   686,   687,
    1418,   184,   185,    14,   409,   387,    26,    27,   241,  2726,
     438,   438,   583,  3467,   438,   248,  3111,   683,   684,   685,
     686,   687,   567,   926,   438,   407,  3121,  3323,  1530,   438,
     438,   474,   350,    30,   438,   438,    20,    34,   356,   357,
     358,   328,   389,    27,  1244,  1245,  1246,   717,   718,   438,
     397,   398,   438,   438,   341,   519,  1515,   476,   499,  1003,
     378,   632,   306,   438,   438,   968,   438,  1485,   438,   295,
     438,   438,   305,   682,   515,   422,   438,   438,   425,   438,
     586,   690,   159,  1502,   438,  1503,   634,  3258,   438,   438,
     438,   372,   438,   438,   558,   442,   438,   330,   291,   476,
     438,   345,  3197,  1521,   337,  1008,   339,  1010,   656,  2116,
     438,   304,   438,   406,  1532,   438,   349,   558,   582,  1974,
     364,   365,   438,   629,   121,   476,   438,   438,  2103,  1984,
    1985,   438,   634,   438,   291,  1990,  1991,  1992,  1993,   406,
     476,   438,  1045,   438,   377,  1048,   438,   304,   438,   438,
     365,   236,   385,   504,   656,  2372,   597,   291,   601,  2376,
     404,  1064,   626,  2687,  1067,   471,   484,   503,   504,   487,
     304,   635,   416,    25,    25,    27,    27,   495,   476,   291,
    2162,   709,   372,   427,   759,   626,  3148,   504,   475,   422,
     236,   291,   304,   768,   635,    26,    27,  3368,  2322,   546,
     444,  2325,   730,  1106,   304,   434,   504,   433,  1111,   435,
     454,  2279,   530,   406,   447,   743,   236,  1120,  3332,   476,
     210,    25,   212,    27,   667,   469,    30,   476,   521,   458,
     566,  1134,  1135,  1136,  2246,  1138,   476,  1140,  1141,   814,
    3335,   623,   817,  1146,  1147,   526,   476,   565,    25,   406,
      27,   484,   599,   800,   521,   719,   720,   804,   669,   606,
     516,   808,   495,    26,    27,   509,   584,   585,   524,  2147,
    2338,  2339,   406,   476,   717,   718,  1179,   595,  1181,  1412,
     691,   692,   600,   476,   476,   282,   379,  1190,   532,   476,
    1193,    25,   476,    27,   406,  1198,    40,   476,  1414,   482,
     476,   204,    25,   547,    27,   476,   406,   252,   253,   254,
     554,   476,   541,   557,  1217,  1218,  2171,  2841,  2842,  2843,
    2844,   639,   476,  1226,   663,   476,   316,  3422,   521,   319,
      25,   670,    27,    25,   578,    27,   526,   630,   582,  1242,
    1243,    25,   476,    27,   537,  3113,   431,  1344,   213,   476,
    1347,   341,  3183,   671,   476,  3186,   727,   601,  3189,  2001,
     593,   594,   595,   630,   521,  1268,    25,    24,    27,    26,
     741,  1274,  1275,   606,   745,   619,   476,  1510,  1511,  1282,
     537,  3343,  3344,    20,   236,   236,   757,   521,   669,    25,
      27,    27,  1295,   137,   138,   139,   140,   141,   142,  1515,
    1303,   304,   476,   537,   633,   236,   403,   688,   689,   521,
     504,   155,   156,   157,   413,   476,   645,   646,    25,    20,
      27,   521,  2277,   476,   653,   537,    27,   708,   476,    25,
    2285,    27,   236,  2288,  2289,  2290,  2291,   537,   210,   342,
     212,    25,  1897,    27,  1899,  1900,  1349,    26,  1903,  1904,
    1353,  1354,  1355,    20,  1909,   452,  2484,  2664,  1370,   236,
      27,  2103,  1365,  1366,  1367,   237,   559,  1370,  1371,  1372,
    1373,  1374,  1375,   236,   504,  2692,   709,   570,   282,   669,
     476,  1384,    20,  2423,  2145,   475,   483,  3455,  3456,    27,
    3466,   476,  1395,  1396,  3470,  1398,  1399,  1400,   688,   689,
     499,   446,   236,   406,  1407,  1408,  1409,   669,  1411,  1412,
     383,  1414,  1415,   236,   542,   512,   515,   420,   708,   476,
    1423,   394,   550,   714,   715,   716,  1429,  1430,    20,   691,
     692,  1986,  2136,  1436,  1437,    27,    20,   476,  2550,  2607,
     634,   236,  2610,    27,   316,   476,    20,   319,   476,  2210,
    2216,   295,   236,    27,   298,  2057,    28,    29,  3389,   558,
     476,   426,   656,  3347,  2576,  3349,  3350,  3351,  3352,   341,
     664,  3539,   445,  3541,   503,   504,   441,   236,  1481,  1482,
    3521,  1484,   686,   687,    26,    39,   459,    41,   476,    43,
      44,   476,  2841,  2842,  2843,  2844,    26,  3538,   597,   403,
     236,   670,  3126,  3127,   670,  1508,  3130,  1510,  1511,    25,
     284,    27,  1515,    25,  1517,    27,  1519,  1520,   521,   484,
     724,    26,   476,   727,    39,    26,    41,   626,    43,    44,
     495,    25,    26,   737,   537,    26,   635,   741,    26,  1542,
     236,   745,  2060,   684,   685,  3586,   674,  2102,   752,   503,
     504,   516,   236,   757,    25,   759,    27,  2075,   523,   664,
    3184,   765,  3603,  3187,   768,    19,   531,   341,   147,   148,
      24,   775,    26,   571,   418,   548,   413,   476,   782,   483,
     503,   504,   526,  2101,   284,   789,   686,   687,   553,   433,
    2108,   693,   694,   437,   284,  1287,   800,  1289,  1290,   815,
     804,   476,   818,   475,   808,   821,   693,   694,   512,  2564,
     814,  2130,   566,   817,   333,   334,  2377,  2135,  2379,   476,
      24,   395,    26,   476,   413,   399,  2708,  2388,   484,   476,
     474,    20,    21,   107,  3057,   476,  2154,  1870,  1871,   495,
    2785,   341,   657,   658,   659,   660,  2753,  2899,  2900,    19,
    2902,   341,  2413,  2905,    24,    25,    26,  2612,   502,    25,
     516,    27,   499,   476,    25,   630,    27,   523,  2750,  2224,
     476,   636,  2627,  2682,  2683,   531,   520,   476,   515,  2807,
      25,  3130,    27,  2638,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   395,    25,   553,    27,   399,
    3017,   475,   155,   156,   157,   395,  3126,  3127,   182,   399,
     499,   210,    40,   212,  1144,  1145,    26,   466,  1148,  1149,
      24,   558,    26,   504,  3348,   669,   515,    25,   476,    27,
    3354,  3355,    26,  3357,  3358,  3359,  3360,    26,   237,  3162,
    2295,    25,  3366,    27,   688,   689,    26,    26,   137,   138,
     139,   140,   141,   142,  1396,  3379,  1398,   601,    26,    26,
     597,    26,   316,   664,   708,   319,   104,   321,   438,   558,
     244,  2373,   246,   476,   408,   475,   664,  3126,  3127,    26,
     438,  3130,   476,  2761,   476,   475,   472,   341,   262,   626,
       5,  2769,  2770,  2093,   476,   438,   270,   351,   635,   438,
     274,   316,   438,   438,   319,   516,   321,   476,   597,   137,
     138,   139,   140,   141,   142,   670,    20,   316,   372,    20,
     319,   476,  2424,   667,   476,   299,   341,   155,   156,   157,
    2385,  2786,   413,   438,     5,  3184,   351,   626,  3187,   476,
     504,   395,   341,  1940,   668,   399,   635,    26,  2366,  3473,
     664,   413,  3476,  3477,  3478,  3479,    26,   372,   438,   304,
    2815,   438,  2380,  2381,  2382,  2383,  1869,  1870,  1871,   472,
     408,  2473,    30,  1876,  1877,  3499,  2109,  2002,    20,    26,
     395,    26,   970,  2401,   399,   973,    26,   975,   976,   977,
     978,   979,    26,  1896,  1897,    26,  1899,  1900,    26,  3348,
    1903,  1904,    26,  1906,  3327,  3354,  1909,   634,  3357,  3358,
    3359,  3360,   438,  2213,  2011,   438,    26,   438,   499,   438,
    1124,   475,    18,    19,    20,    21,    22,   438,    26,     5,
    1933,   438,    20,    26,   515,   413,  3560,   499,  3190,   476,
      26,  1944,    26,    26,  3568,   438,  2246,   664,     5,  2467,
     670,  2712,  2907,   515,   438,    26,   438,   413,   348,   438,
     475,   438,   438,  2007,   668,   438,     5,   295,   438,  1972,
     298,  1974,  2205,   438,  2190,  2191,   475,   558,  2533,   476,
     438,  1984,  1985,  1986,    26,   670,  2747,  1990,  1991,  1992,
    1993,   438,   670,   634,    25,    25,   558,  3346,  2001,  3348,
      25,   438,    25,   438,  2129,  3354,  3355,  2562,  3357,  3358,
    3359,  3360,    18,    19,    20,    21,   597,  3366,   438,   438,
    2023,   499,  2147,  2578,  3473,  2028,  3066,  3476,  3477,  3478,
    3479,  2034,   438,   438,  2037,   597,   438,   515,   438,  3142,
    1244,  1245,  1246,   499,   438,   626,   348,   438,   668,  2567,
     692,  2569,  2055,   438,   635,   438,   438,   664,  2061,   515,
     476,     8,   704,   664,   626,  2620,    39,  2622,    41,   669,
      43,    44,   524,   635,    18,    19,    20,    21,   312,   472,
     558,   640,   505,     5,   662,   640,  2089,   662,   466,   703,
     418,   733,  3070,   505,   703,   664,   504,   182,   374,  2102,
    2103,   664,   558,  2106,  2107,   433,  2109,   749,   750,   437,
     656,  3560,   641,   755,     5,   466,   758,     5,   476,   597,
     476,  2124,   476,   476,  3473,   634,   476,  3476,  3477,  3478,
    3479,   137,   138,   139,   140,   141,   142,   392,   623,     8,
    2143,   597,  2145,    14,     5,   620,   474,   703,   626,     5,
    3499,  3279,   703,   466,   476,   476,    26,   635,    26,   244,
    3288,   246,   111,  2166,   136,  2168,  2169,   504,  2171,   664,
     626,  2174,  2175,   634,   502,   476,  3304,   262,   466,   635,
     476,   476,    26,   476,   476,   270,   476,  2190,  2191,   274,
    2745,   476,   520,   137,   138,   139,   140,   141,   142,   476,
    2718,   504,  2205,  2721,     5,   476,   640,  2210,  2211,  2212,
     476,  3560,     5,  2216,   299,   670,   476,   476,   669,  3568,
     670,  2224,  2926,  2927,  2928,   706,  2930,  2931,  2932,  2933,
    2934,  2935,    20,    21,   398,  2939,   601,     5,  3193,   661,
    3195,  2407,    18,    26,  2544,    19,   206,    26,  2251,   199,
    2550,   623,   430,    25,   634,  3367,  2259,  2260,   667,     5,
    2263,   221,   222,  3024,   527,   527,   664,  2785,   591,   197,
     230,  1254,   591,   601,  2277,    26,  2576,   446,   369,   591,
     476,    26,  2285,   438,   670,  2288,  2289,  2290,  2291,  2292,
     438,  3052,  2295,   516,   438,   664,  2299,  2300,   571,   476,
    2303,   476,   476,   476,   264,   103,  2407,     5,   182,   476,
     192,   708,   664,   273,   196,   438,  3444,  2320,  2321,  2322,
     634,   664,  2325,  2326,  2327,   634,   476,  2330,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   591,   667,
     670,   661,   302,   316,     5,     5,   319,   664,   321,   137,
     138,   139,   140,   141,   142,    40,  2359,     5,  2361,  2362,
     624,  2364,  2365,     5,   670,  2368,   528,    25,   341,  2372,
     244,   476,   246,  2376,  2377,   504,  2379,  3332,   351,     5,
       8,   664,  2385,  2386,   365,  2388,  2389,   347,   262,  2392,
    2393,   669,    26,    26,   111,   373,   270,   264,     5,   372,
     274,     5,   438,  2406,  3524,  3525,  3526,  3527,  3528,  3529,
    2413,   285,   476,  3453,   476,   297,   407,  2420,   670,   641,
    2423,  3549,   395,    14,     5,   299,   399,   595,   591,  2432,
     704,   391,    26,  2436,   145,   476,   664,   670,   476,   591,
     669,     5,   669,  2998,   670,   683,   472,    26,   438,     5,
       5,   415,   137,   138,   139,   140,   141,   142,  2461,   379,
     663,   472,   506,   506,   476,     5,   476,   476,   476,   476,
     155,   156,   157,   476,   476,   476,   664,     5,   664,     8,
     664,     5,  2485,   621,   598,   392,   373,    25,   392,   504,
     392,   476,   664,   407,   471,     5,     5,   695,   165,   504,
      26,     5,   475,     5,    25,   640,    14,    14,    26,   476,
     640,   598,   661,     5,  3469,     5,   670,  2817,  2818,   438,
     476,  3282,   438,   438,     6,   438,   438,  3045,    40,   438,
    2533,     7,   493,   314,     5,   438,     5,   664,  3299,    26,
      26,    26,    26,    26,   670,  2548,   664,   664,  3503,   438,
      20,   611,     5,  2556,  2557,  2558,   320,  2595,  2561,  2562,
    3202,  2564,  3540,  3081,     5,   223,     5,   591,     8,   664,
       5,   712,   438,   438,  2577,  2578,   616,   476,  2581,  2582,
     516,  2797,   664,  2799,     5,     5,   257,   591,    26,   670,
     670,   668,   438,   476,   106,   107,   670,   670,   476,     5,
     267,   668,     5,    25,   663,   342,    25,    25,   275,  2612,
     295,   492,  2650,   298,   281,    25,   283,  2620,  2784,  2622,
    3660,  3176,  2625,    25,  2627,    26,    26,   294,    26,    26,
      26,  2756,    26,   438,   438,  2638,  2761,    26,     5,   438,
    2643,  2644,  2645,   438,  2769,  2770,   476,     5,   476,   513,
     595,  2654,   438,     8,   286,   322,    26,  3612,   472,   171,
      25,   438,   486,   392,    20,   188,   598,   476,   476,  2672,
     476,   338,     5,   476,  3435,     5,   343,    14,   190,   476,
     476,   257,   476,  2784,   438,   487,     5,  2690,   355,  2692,
      26,   504,   350,   421,   438,   362,   438,    26,   356,   357,
     358,    26,  2705,   438,    26,   109,   476,   613,    26,  2712,
      26,    26,   438,   286,   438,   438,   476,   392,   438,   287,
     378,   486,   504,   476,   438,   664,    14,     7,   591,    26,
     438,   285,   285,   418,  2737,   670,  2739,   438,  2741,   439,
     476,  2744,  2745,   664,  2747,   438,   438,   620,   433,   476,
     472,    25,   437,   287,   438,   438,   438,   438,   438,  2762,
       5,  2764,  2765,  2766,   438,     5,  3284,   664,   664,   438,
     664,  2764,  2705,  3596,   994,  1522,  2779,  2457,  3170,  2155,
      29,    31,  2389,  2786,   547,  2737,  2395,   354,   114,   474,
     118,   207,  2006,   345,  2797,   655,  2799,   355,  2007,   225,
    3318,   212,   536,   315,   316,   555,  2809,  2810,   598,  3042,
     322,  1273,  2815,   384,   326,   567,  3586,   502,   476,  2060,
     383,   569,  3055,   798,  2827,   986,   484,   415,  2257,   487,
    1251,  2264,   714,   715,  2382,   520,  2108,   495,  2841,  2842,
    2843,  2844,  2845,  2846,   511,  1869,  2788,  3091,  2182,   516,
    1872,  3637,  2855,  2385,  2481,  2200,   523,  2860,  3296,    16,
      92,  1414,    40,  3223,    40,  2160,    22,   928,  3036,   754,
    2166,   326,   530,  1010,  1482,  1877,  1218,  3220,   545,   779,
    2169,  1408,  3397,   550,  1480,  2888,  2889,  3603,  2786,  2093,
    1398,  2966,  1503,  3407,  2948,  2135,  2899,  2900,  2964,  2902,
    2653,   452,  2905,  3022,  2907,  3276,  3274,   565,  2911,  3267,
    3014,  2376,  2544,  2040,  2023,  2330,   601,  3612,  3197,  1911,
    1911,  2235,  3123,  2563,  2971,  3422,   584,   585,  3005,  2223,
     812,  2295,  2888,  3187,  2626,  3036,  2628,   595,  2625,  2889,
     822,   345,   600,  3499,  2993,  3070,  2675,  2950,  1931,  1932,
    1896,  3239,  2654,     8,  3653,  1938,  1247,  2645,  2644,  1985,
    2963,   365,   366,   367,  3264,    22,  3195,  3125,  2828,  2972,
    2973,  2974,  1984,  1891,  3274,  3463,  2557,  3120,  1864,  3346,
    3365,   639,   667,    40,  3354,  1243,  2745,  2406,  1413,    -1,
      -1,    -1,    -1,    -1,   506,  2998,   545,    -1,    -1,    -1,
     404,    -1,    -1,    -1,    -1,   517,    -1,  3010,  3011,  2213,
      -1,  3014,   416,   671,  3017,    -1,    -1,  3535,    -1,    -1,
      -1,  3024,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3034,    -1,    -1,  3037,  3038,    -1,    -1,    -1,  3042,
     444,    -1,  2246,    -1,    -1,    -1,    -1,    -1,    -1,  3052,
     454,    -1,  3055,    -1,  3057,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3278,  3066,    -1,   469,    -1,  3367,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   968,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,
     157,    -1,  3105,    -1,    -1,    -1,    -1,    -1,  3111,    -1,
      -1,    -1,    -1,   517,  3632,    -1,    -1,  3120,  3121,    -1,
    3123,  3124,    -1,  3126,  3127,    -1,    -1,  3130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3141,   651,
      -1,    -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,  2841,
    2842,  2843,  2844,   557,    -1,  2138,    -1,    -1,    -1,  3162,
    3163,    -1,    -1,    -1,    -1,    -1,  1048,   679,   680,   681,
      -1,   683,    -1,  3176,   578,    -1,    -1,    -1,   582,    -1,
      -1,  3184,    -1,    -1,  3187,    -1,    -1,  3190,   700,    -1,
    3193,    -1,  3195,    -1,  3197,  2178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,  2901,
      -1,  2903,    -1,    -1,    -1,   619,    -1,  3220,    -1,    -1,
      -1,    -1,    -1,    -1,   736,    -1,    -1,    -1,    -1,    -1,
     742,    -1,   744,    -1,    -1,    -1,   748,    -1,   295,   751,
      -1,   298,   754,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   764,    -1,    -1,  3258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,
      -1,    -1,    -1,   785,    -1,  3278,    -1,    -1,    -1,  3282,
     792,   793,   794,    -1,    -1,    -1,   798,    -1,    -1,    -1,
       9,    -1,    -1,  3459,   806,    -1,  3299,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
     822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3327,    -1,    -1,    -1,    -1,  3332,
      -1,    -1,  3335,    -1,    -1,  1217,    -1,    -1,    -1,    -1,
    2544,    -1,    -1,  3346,    -1,  3348,  2550,    -1,    -1,    -1,
      -1,  3354,  3355,    -1,  3357,  3358,  3359,  3360,  3459,    -1,
    3363,   418,  3365,  3366,    -1,  3368,    18,    19,    -1,    -1,
      -1,    -1,  2576,    -1,    26,    27,   433,    -1,    -1,    -1,
     437,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,   110,  1274,  1275,  3397,    -1,    -1,    -1,   117,  3402,
    1282,  3404,    -1,    -1,    -1,   119,   120,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,  3540,    -1,   474,    -1,  3422,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,  3435,    -1,  3126,  3127,    -1,    -1,  3130,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,    -1,    -1,    -1,
    3453,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
    3463,    -1,    -1,   520,    -1,   117,  3469,    -1,  2451,  2452,
    3473,    -1,    -1,  3476,  3477,  3478,  3479,  3480,    -1,  2462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3494,   144,    -1,    -1,    -1,  3499,    -1,    -1,    -1,
    3503,    -1,    -1,  2486,  2487,  2488,  2489,    -1,   222,    -1,
      -1,  2494,  2495,  2496,  2497,    -1,   230,   236,  2501,   238,
      -1,  3524,  3525,  3526,  3527,  3528,  3529,    -1,    -1,    -1,
      -1,    -1,    -1,  3536,    -1,    -1,  1048,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   601,    -1,    -1,    -1,    -1,    -1,
     264,    -1,  1064,    -1,  1436,    -1,    -1,  3560,    -1,   273,
      -1,    -1,    -1,    -1,    -1,  3568,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,   238,    -1,   302,   303,
      -1,    -1,    -1,    -1,  1106,    -1,    -1,    -1,    -1,    -1,
    2583,  2584,    -1,    -1,    -1,    -1,    -1,  2590,  2591,  3612,
     667,  3614,    -1,  2817,  2818,    -1,   335,    -1,    -1,    -1,
      -1,   340,  1134,  1135,  1136,    -1,  1138,    -1,  1140,  1141,
      -1,    -1,    -1,   347,  1146,  1147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3651,  3652,
    3653,   370,    -1,    -1,    -1,    -1,  3348,  3660,    -1,  3662,
      -1,    -1,  3354,  3355,    -1,  3357,  3358,  3359,  3360,  1181,
      -1,    -1,    -1,    -1,  3366,    -1,    -1,   391,    -1,    -1,
      -1,  1193,    -1,   335,    -1,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1217,  1218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1226,   434,    -1,    -1,   370,    -1,
     439,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
    1242,  1243,   446,    -1,   453,    -1,    -1,    -1,    -1,   458,
      -1,    -1,    -1,    -1,  2727,  2728,    -1,    -1,    -1,   468,
      -1,    -1,   404,  2736,   473,    -1,    -1,   476,    -1,    -1,
     479,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,   488,
     489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3473,    -1,    -1,  3476,  3477,  3478,  3479,    -1,    -1,
    2773,  2774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,
     529,    -1,    -1,    -1,   533,  2798,   468,  2800,    -1,    -1,
      -1,    -1,   541,    -1,   476,    46,    47,    48,    49,    50,
      51,    -1,    -1,   552,    -1,    -1,    -1,   489,    -1,   558,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,   582,    -1,    -1,    -1,    -1,  3560,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3568,    -1,  2861,  2862,
      -1,   533,  2865,  2866,  1396,    -1,  1398,  1399,  1400,    -1,
      -1,    -1,    -1,    -1,    -1,  1407,  1408,    -1,    -1,  1411,
      -1,    -1,    -1,  1415,    -1,    -1,   558,   626,    -1,    -1,
      -1,    -1,    -1,    -1,   633,    -1,   635,    -1,    -1,    -1,
      -1,    -1,   143,    -1,  1436,  1437,   645,   646,    -1,    -1,
     582,    -1,    -1,    -1,   653,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,   110,    -1,   664,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,    -1,  1481,
    1482,  2954,  1484,    -1,   626,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,   635,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1877,    -1,    -1,    -1,    -1,
     719,   720,    -1,    -1,    -1,  1517,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
    1542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3035,    -1,    -1,    -1,  3039,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   719,   720,   236,
      -1,   238,    -1,    -1,    -1,  3058,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1974,    -1,  3077,    20,    21,    22,    -1,    -1,
      -1,    -1,  1984,  1985,    -1,    -1,    -1,    -1,  1990,  1991,
    1992,  1993,     6,     7,     8,    40,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,   380,
      -1,    -1,    -1,  3367,    -1,    -1,    -1,    -1,   335,    -1,
      -1,    -1,   393,   340,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,   157,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,   157,    -1,    -1,   456,    -1,   404,    -1,    -1,
      -1,   462,     9,   137,   138,   139,   140,   141,   142,   416,
      -1,    18,    19,    -1,  2136,    -1,    -1,    24,    25,    26,
      27,   155,   156,   157,    -1,    -1,    -1,   434,    -1,    -1,
      -1,    -1,   439,    -1,    -1,   442,    -1,    -1,    -1,    -1,
     501,    -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,  2171,
      -1,   458,    -1,    -1,    -1,    -1,   295,    -1,    -1,   298,
      -1,   468,    -1,    -1,   525,    -1,   473,    -1,    -1,   476,
      -1,    -1,   479,    -1,   535,   536,    -1,    -1,    -1,    -1,
     541,   488,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     551,    -1,    -1,  3316,    -1,    -1,  3319,    -1,   105,   295,
      -1,    -1,   298,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,   573,    -1,    -1,   576,   577,    -1,    -1,    -1,
     581,    -1,   529,    -1,  1876,  1877,   533,    -1,    -1,    -1,
     295,    -1,    -1,   298,   541,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   552,    -1,   554,    -1,    -1,
      -1,   558,    -1,    -1,    -1,  2277,    -1,    -1,    -1,    -1,
      -1,   295,    -1,  2285,   298,    -1,  2288,  2289,  2290,  2291,
      -1,    -1,    -1,    -1,    -1,   582,    -1,   638,  2300,   418,
      -1,  1933,    -1,    -1,    -1,    -1,    -1,    -1,   649,    -1,
      -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,   437,    -1,
      -1,    -1,    -1,    -1,  2326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,
      -1,    -1,   418,    -1,    -1,    -1,   633,    -1,   635,   236,
      -1,   238,    -1,    -1,  3457,   474,    -1,   433,   645,   646,
      -1,   437,    -1,    -1,    -1,    -1,   653,    -1,    -1,    -1,
      -1,    -1,    -1,   418,    -1,    -1,    -1,   664,    -1,    -1,
      -1,    -1,    -1,   502,    -1,    -1,    -1,    -1,   433,    -1,
      -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,   520,  3505,  3506,   418,  3508,    -1,  3510,  3511,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,
      -1,  2423,    -1,   437,   438,    -1,   502,    -1,    -1,   474,
      -1,    -1,   719,   720,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,    -1,    -1,   335,    -1,
      -1,    -1,    -1,   340,    -1,    -1,    -1,   502,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3574,    -1,  3576,    -1,   520,    -1,    -1,    -1,    -1,
      -1,    -1,   601,   370,    -1,    -1,    -1,    -1,   502,    -1,
      -1,    -1,  2124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   520,  3610,    -1,    -1,
      -1,    -1,    -1,  2145,    -1,    -1,    -1,   404,    -1,    -1,
      -1,    -1,    -1,  3626,  3627,   601,    -1,  3630,    -1,   416,
    3633,    -1,    -1,    -1,  2166,    15,    16,    17,    18,    19,
      20,    21,    22,  2175,    -1,    -1,    -1,   434,   667,    -1,
      -1,    -1,   439,    -1,    -1,   442,   601,    -1,    -1,    -1,
      40,    -1,  2564,    -1,    -1,    -1,   453,    -1,    -1,    -1,
      -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,  2210,  2211,
    2212,   468,    -1,    -1,  2216,    -1,   473,   601,    -1,   476,
       9,   667,   479,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,   488,   489,    -1,    -1,    24,    25,    26,    27,    -1,
    2612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2251,
      -1,    -1,   667,  2625,    -1,  2627,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,  2638,    -1,    -1,    -1,
      -1,   528,   529,    -1,    -1,    -1,   533,    -1,    -1,    -1,
      -1,    -1,    -1,   667,   541,    -1,    -1,   137,   138,   139,
     140,   141,   142,    -1,    -1,   552,    -1,    -1,    -1,    -1,
      -1,   558,    -1,    -1,    -1,   155,   156,   157,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2687,   105,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,   582,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,
      -1,    -1,    -1,    -1,    -1,  2377,   633,  2379,   635,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2388,    -1,   645,   646,
      -1,    -1,    -1,    -1,    -1,    -1,   653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2407,    -1,   664,    -1,    -1,
      -1,  2413,    -1,    -1,  2786,    -1,    -1,    -1,    -1,    -1,
      -1,  2423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2432,    -1,    -1,    -1,  2436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2815,    -1,   295,    -1,   236,   298,   238,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,  2461,
      -1,    -1,   719,   720,    -1,    -1,    -1,    -1,    -1,  2841,
    2842,  2843,  2844,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,  2888,  2889,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2899,  2900,    -1,
    2902,    40,    -1,  2905,    -1,  2907,    -1,    -1,    -1,  2911,
     110,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,
      -1,   340,    -1,    -1,  2926,  2927,  2928,    -1,  2930,  2931,
    2932,  2933,  2934,  2935,    -1,    -1,    -1,  2939,   418,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,  2581,
      -1,   370,    -1,   433,    -1,    -1,    -1,   437,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,   474,    -1,    -1,   416,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2644,    -1,    -1,   434,   155,   156,   157,    -1,
     439,    -1,   502,   442,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   453,    -1,   236,    -1,    -1,   458,
     520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
     442,    -1,    -1,    -1,   473,    -1,    -1,   476,    -1,    -1,
     479,    -1,    -1,    -1,  3066,    -1,    -1,    -1,    -1,   488,
     489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2712,   473,    -1,    -1,   476,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,    -1,    -1,   489,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,
     529,    -1,    -1,    -1,   533,  2747,    -1,    -1,    -1,    -1,
      -1,   601,   541,    -1,  3126,  3127,    -1,    -1,  3130,    -1,
    2762,    -1,  2764,   552,  2766,    -1,   528,   529,    -1,   558,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2779,    -1,   541,
      -1,    -1,  2784,    -1,   236,    -1,   295,    -1,    -1,   298,
      -1,    -1,    -1,   582,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2809,  2810,    -1,
      -1,    -1,  3184,    -1,    -1,  3187,    -1,   667,  3190,    -1,
     582,  3193,    -1,  3195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,
      -1,    -1,    -1,    -1,   633,    -1,   635,    -1,    -1,    -1,
      -1,    -1,    -1,  2855,    -1,    -1,   645,   646,    -1,   621,
      -1,    18,    19,    20,   653,    -1,    -1,    24,    25,    26,
      27,   633,   442,    -1,    -1,   664,    -1,   295,    -1,    -1,
     298,    -1,    -1,   645,   646,    -1,  3258,    -1,    -1,    -1,
      -1,   653,    -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   664,   473,    -1,    -1,   476,    -1,    -1,   418,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   489,
      -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,   437,    -1,
     719,   720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2950,    -1,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   529,
    3332,  2963,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,   541,    -1,    -1,    -1,    -1,  3348,    -1,    -1,    -1,
      -1,    -1,  3354,  3355,    -1,  3357,  3358,  3359,  3360,    -1,
     442,    -1,    -1,   502,  3366,    -1,  3368,    -1,    -1,    -1,
     418,    -1,    -1,    -1,    -1,    -1,    -1,  3379,    -1,    -1,
      -1,   520,   582,    -1,    -1,   433,    -1,    -1,    -1,   437,
     438,   473,  3024,    -1,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3036,    -1,    -1,   489,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   615,    -1,    -1,    -1,    -1,
    3052,   621,   306,    -1,    -1,  3057,   474,    -1,    -1,    -1,
     630,   631,    -1,   633,  3066,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   645,   646,   529,    -1,   236,
      -1,  3453,    -1,   653,   502,    -1,   656,    -1,    -1,   541,
      -1,   345,   601,    -1,   664,    -1,    -1,  3469,    -1,    -1,
      -1,  3473,   520,    -1,  3476,  3477,  3478,  3479,    -1,    -1,
     364,   365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3499,    -1,    -1,
     582,  3503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   667,    -1,
    3162,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   633,    -1,   601,    -1,    -1,    -1,    -1,  3560,    -1,
     444,    -1,    -1,   645,   646,    -1,  3568,    -1,    -1,    -1,
     454,   653,    -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   664,    -1,    -1,   469,    -1,    -1,  3220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
    3612,    -1,    -1,    18,    19,    20,    21,    22,    23,   667,
      -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,   532,    -1,
    3282,    -1,    -1,    -1,    -1,   442,    -1,    -1,  3660,    -1,
      -1,    -1,    -1,   547,    -1,    -1,    -1,  3299,    -1,    -1,
     554,    -1,    -1,   557,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   473,    -1,    -1,   476,
      -1,    -1,    -1,    -1,   578,  3327,    -1,    -1,   582,    -1,
      -1,    -1,   489,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,   601,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,
     135,   136,    -1,    -1,    -1,   619,    -1,    -1,    -1,   144,
      -1,    -1,   529,    -1,    -1,    -1,   151,   152,    -1,    -1,
     155,   156,   157,   158,   541,    -1,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3397,    -1,    -1,    -1,    -1,
    3402,    -1,  3404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,   201,    -1,    -1,    -1,
      -1,    -1,    -1,  3435,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,
      -1,  3453,    -1,    -1,   229,    -1,    -1,  3459,   615,    -1,
     235,   236,    -1,   238,   621,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   630,   631,    -1,   633,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,   646,
      -1,    -1,    -1,    -1,   269,    -1,   653,    -1,    -1,   656,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   664,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3524,  3525,  3526,  3527,  3528,  3529,    -1,    -1,
      -1,    -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   320,    -1,    -1,    -1,    -1,
      -1,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     335,   336,    -1,    -1,    -1,    -1,    -1,   342,    -1,    -1,
     345,   346,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,
      -1,   356,   357,    -1,    -1,    -1,    -1,    -1,   363,   364,
     365,    -1,    -1,   368,   369,   370,    -1,    -1,    -1,   374,
      -1,    -1,    -1,   378,    -1,   380,    -1,    -1,    -1,    -1,
      -1,    -1,   387,   388,   389,   390,    -1,   392,   393,    -1,
      -1,    -1,   397,   398,    -1,   400,   401,   402,   403,   404,
     405,   406,    -1,    -1,    -1,    -1,    -1,   412,   413,   414,
      -1,   416,   417,    -1,    -1,    -1,   421,   422,   423,   424,
     425,   426,   427,   428,    -1,   430,    -1,    -1,  3660,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,    -1,   472,   473,    -1,
      -1,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,    -1,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,    -1,    -1,   504,
     505,   506,   507,   508,   509,   510,   511,   512,    -1,   514,
     515,   516,   517,    -1,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
      -1,   556,   557,   558,   559,   560,   561,    -1,    -1,   564,
     565,    -1,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,    -1,    -1,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,    -1,    -1,    -1,    -1,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   682,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   690,    -1,    -1,    -1,    -1,
     695,    -1,    -1,    -1,   699,    -1,    -1,   702,   703,   704,
     705,    -1,    -1,   708,   709,    -1,   711,   712,   713,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,   155,
     156,   157,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   320,    -1,    -1,    -1,    -1,    -1,
     326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,
     336,    -1,    -1,    -1,    -1,    -1,   342,    -1,    -1,   345,
     346,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,
     356,   357,    -1,    -1,    -1,    -1,    -1,   363,   364,   365,
      -1,    -1,   368,   369,   370,    -1,    -1,    -1,   374,    -1,
      -1,    -1,   378,    -1,   380,    -1,    -1,    -1,    -1,    -1,
      -1,   387,   388,   389,   390,    -1,   392,   393,    -1,    -1,
      -1,   397,   398,    -1,   400,   401,   402,   403,   404,   405,
     406,    -1,    -1,    -1,    -1,    -1,   412,   413,   414,    -1,
     416,   417,    -1,    -1,    -1,   421,   422,   423,   424,   425,
     426,   427,   428,    -1,   430,    -1,    -1,    -1,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,    -1,   472,   473,    -1,    -1,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
      -1,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,    -1,    -1,   504,   505,
     506,   507,   508,   509,   510,   511,   512,    -1,   514,   515,
     516,   517,    -1,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,    -1,
     556,   557,   558,   559,   560,   561,    -1,    -1,   564,   565,
      -1,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,    -1,    -1,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,    23,    -1,    -1,    -1,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,    -1,    39,    -1,    41,
      -1,    43,    44,    -1,    -1,    -1,   682,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   690,    -1,    -1,    -1,    -1,   695,
      -1,    -1,    -1,   699,    -1,    -1,   702,   703,   704,   705,
      -1,    -1,   708,   709,    -1,   711,   712,   713,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
     212,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,   157,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,   280,    -1,
      -1,    -1,   284,   285,   286,   287,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,   299,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   156,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   316,    -1,    -1,   319,    -1,   321,
      -1,    -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,
     372,   373,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   395,    -1,    -1,    -1,   399,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   407,   408,   409,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   295,    -1,    -1,   298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,
      -1,   437,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    -1,    36,    37,    38,   418,    -1,    -1,
      42,    -1,    -1,    45,    -1,    -1,   502,    -1,    -1,    -1,
      52,    53,   433,    -1,    -1,   587,   437,   438,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   623,    -1,   474,    -1,    97,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,    -1,   520,
      -1,    -1,    -1,    -1,   146,   601,    -1,   149,   150,    -1,
      -1,   683,   684,   685,   686,   687,   688,   689,    -1,   691,
     692,    -1,   164,    -1,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   177,   708,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,   190,    -1,
     192,   193,   194,    -1,    -1,    -1,    -1,    -1,   200,    -1,
     202,   203,    -1,   205,    -1,   207,   208,    -1,    -1,   211,
      -1,   667,   214,   215,   216,   217,   218,   219,    -1,    -1,
     601,   223,   224,   225,    -1,   227,    -1,    -1,    -1,   231,
      -1,   233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
     242,    -1,    -1,   245,    -1,   247,    -1,   249,    -1,   251,
      -1,    -1,    -1,   255,   256,    -1,   258,   259,   260,    -1,
      -1,   263,    -1,   265,   266,    -1,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   276,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   667,   289,    -1,    -1,
     292,   293,    -1,    -1,   296,   297,    -1,    -1,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,   310,   311,
      -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   323,   324,   325,    -1,   327,    -1,    -1,    -1,   331,
     332,    -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     352,   353,   354,    -1,    -1,    -1,    -1,    -1,   360,   361,
      -1,    -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,   371,
      -1,    -1,    -1,   375,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,
      -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,   441,
      -1,    -1,    -1,    -1,    -1,   447,    -1,   449,   450,    -1,
      -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   496,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,   514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   538,   539,    -1,    -1,
      -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,   561,
     562,   563,   564,    -1,    -1,    -1,   568,    -1,    -1,    -1,
     572,    -1,    -1,    -1,    -1,    -1,    -1,   579,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,
     592,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
     142,   603,    -1,   605,    -1,    -1,   608,    -1,    -1,    -1,
      -1,    -1,   614,   155,   156,   157,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,    -1,
      -1,   643,    -1,    -1,    -1,    -1,   648,    -1,    -1,   651,
     652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,
      -1,   673,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,   696,   697,   698,   699,   700,   701,
     702,    -1,    -1,   705,    -1,   707,    40,   709,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   295,    -1,    -1,   298,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   418,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   433,    -1,    -1,    -1,   437,   438,    -1,    -1,   137,
     138,   139,   140,   141,   142,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     502,   295,    -1,    -1,   298,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,   520,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,   295,
      -1,    -1,   298,    -1,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   295,    -1,   601,
     298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   418,    -1,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,
      -1,    -1,    -1,   437,   438,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   418,    -1,    -1,   667,    -1,    -1,   155,   156,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,
     474,   437,   438,    -1,    -1,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   295,    -1,    -1,   298,    -1,    -1,   502,    -1,
      -1,   137,   138,   139,   140,   141,   142,    -1,   474,    40,
     418,    -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,   155,
     156,   157,    -1,    -1,    -1,   433,    -1,    -1,    -1,   437,
     438,    -1,    -1,    -1,    -1,    -1,   502,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,   295,    -1,    -1,   298,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   502,    -1,    -1,   601,   295,    -1,
      -1,   298,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   520,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   156,   157,    -1,    -1,    -1,
     433,    -1,    -1,    -1,   437,   601,    -1,    -1,    -1,    -1,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,   295,
      -1,    -1,   298,   667,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    40,    -1,    -1,    -1,    -1,    -1,    -1,   418,
      -1,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   601,   433,    -1,    -1,    -1,   437,   502,
      -1,   667,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,   520,    -1,    -1,
      -1,   418,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,   474,   433,    -1,    -1,    -1,
     437,    -1,    -1,    -1,    40,    -1,    -1,    -1,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   667,
      -1,    -1,    -1,   502,   295,    -1,    -1,   298,    -1,   137,
     138,   139,   140,   141,   142,    -1,    -1,   474,    -1,    -1,
      -1,   520,   418,    -1,    -1,    -1,    -1,   155,   156,   157,
     487,    -1,    -1,    -1,    -1,    -1,    -1,   433,   601,    -1,
      -1,   437,    -1,    -1,    -1,   502,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,   520,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,    40,    -1,    -1,   474,    -1,
      -1,   137,   138,   139,   140,   141,   142,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,   155,
     156,   157,   601,    -1,   667,    -1,   502,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,    -1,   418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,   433,    -1,   601,    -1,   437,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    17,
      18,    19,    20,    21,    22,    -1,    -1,   295,   667,    -1,
     298,    -1,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    40,   474,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,    -1,    -1,
     667,   502,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,   295,    -1,   520,
     298,    -1,    16,    17,    18,    19,    20,    21,    22,   295,
      -1,   110,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,   667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
     418,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,   433,    -1,   110,    -1,   437,
     601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
     295,    -1,    -1,   298,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,   474,    -1,    -1,    -1,
     418,   110,    -1,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   418,    -1,    -1,   433,    -1,   236,    -1,   437,
      -1,   155,   156,   157,   502,    -1,   667,   433,    18,    19,
      20,   437,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,   520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   340,
      -1,    -1,    -1,   236,   502,    -1,    -1,   295,    -1,    -1,
     298,    -1,    -1,    -1,    -1,    -1,   502,    -1,    -1,    -1,
      -1,    -1,   520,   418,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,    -1,    -1,   433,    -1,
     110,   340,   437,   601,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,   474,
      -1,   295,    -1,    -1,   298,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   442,    -1,   601,    -1,    -1,    -1,   502,    -1,   667,
      -1,    18,    19,    -1,    -1,   601,    -1,    24,    25,    26,
      27,    -1,   236,    -1,    -1,   520,    -1,    -1,    -1,    -1,
     418,    -1,   473,    -1,    -1,   476,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,    -1,   433,    -1,   488,   489,   437,
      -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,   667,
      -1,    -1,    -1,    -1,   473,   516,    -1,   476,    -1,    -1,
      -1,   667,    -1,    -1,    -1,    -1,   474,    -1,   529,   488,
     489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     541,    -1,    -1,   110,   418,    -1,   601,    -1,    -1,   442,
      -1,    -1,    -1,    -1,   502,    -1,    -1,    -1,    -1,   433,
      -1,    -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,    -1,
     529,    -1,   520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     473,   582,   541,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,    -1,    -1,   489,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,    -1,   667,    -1,   615,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,   582,   473,   236,    -1,   476,   502,   630,
     631,    -1,   633,    -1,    -1,   528,   529,    -1,    -1,   488,
     489,    -1,    -1,    -1,   645,   646,   520,    -1,   541,    -1,
      -1,    -1,   653,   601,    -1,   656,   615,    -1,    -1,    -1,
      -1,    -1,   621,   664,    -1,    -1,    -1,    -1,   442,   236,
      -1,   630,   631,    -1,   633,    -1,    -1,    -1,    -1,    -1,
     529,    -1,    -1,    -1,   109,    -1,   645,   646,    -1,   582,
      -1,    -1,   541,    -1,   653,    -1,    -1,   656,    -1,   473,
     125,   126,   476,    -1,    -1,   664,    -1,    -1,    -1,    -1,
     135,    -1,   442,    -1,    -1,   489,    -1,    -1,    -1,   667,
      -1,    -1,   615,    -1,    -1,    -1,    -1,   601,   621,    -1,
      -1,    -1,    -1,   582,    -1,    -1,    -1,   630,   631,    -1,
     633,    -1,    -1,   473,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,   645,   646,   528,   529,    -1,    -1,    -1,   489,
     653,    -1,    -1,   656,    -1,    -1,   615,   541,    -1,    -1,
      -1,   664,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   630,   631,    -1,   633,    -1,    -1,    46,    47,    48,
      49,    50,    51,   667,    -1,    -1,   645,   646,    -1,   529,
      -1,    -1,    -1,    -1,   653,    -1,    -1,   656,   582,    -1,
      -1,   541,    -1,    -1,    -1,   664,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   615,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,
      -1,    -1,   582,    -1,    -1,    -1,   630,   631,    -1,   633,
      -1,    -1,   473,    -1,    -1,   476,    -1,    -1,    -1,    -1,
      -1,   645,   646,    -1,    -1,   442,    -1,    -1,   489,   653,
      -1,   306,   656,    -1,   143,   615,    -1,    -1,    -1,    -1,
     664,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     630,   631,    -1,   633,    -1,   516,   473,    -1,    -1,   476,
      -1,    -1,    -1,    -1,    -1,   645,   646,    -1,   529,    -1,
     345,    -1,   489,   653,    -1,    -1,   656,    -1,    -1,    -1,
     541,    -1,    -1,    -1,   664,    -1,    -1,    -1,    -1,   364,
     365,   366,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,    -1,    -1,
      -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   582,    -1,    -1,   541,    -1,    -1,    -1,    -1,   404,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,   444,
      -1,    -1,   633,    -1,    -1,    -1,    -1,    -1,    -1,   454,
      -1,    -1,    -1,    -1,   645,   646,    -1,    -1,    -1,    -1,
      -1,    -1,   653,    -1,   469,   656,   305,    -1,    -1,    -1,
      -1,    -1,    -1,   664,   621,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   633,    -1,    -1,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,   645,   646,
     339,    -1,    -1,    -1,   509,    -1,   653,    -1,    -1,   656,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   664,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,   380,   547,    -1,    -1,    -1,   385,    -1,    -1,   554,
      -1,    -1,   557,    -1,   393,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   578,    -1,    -1,    -1,   582,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   619,    -1,    -1,   456,    -1,    -1,
      -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   661,    -1,    -1,    -1,
      -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   535,   536,    -1,    -1,
      -1,    -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   573,    -1,    -1,   576,   577,    -1,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,    -1,
     649
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   121,   282,   403,   452,   483,   512,   780,
     808,   809,   865,  1039,  1093,  1095,  1096,  1097,  1102,  1104,
    1117,  1118,  1119,  1120,  1121,  1555,    28,    29,   781,   782,
     783,   784,   785,    27,  1003,  1570,  1003,    25,  1003,  1470,
    1122,   810,  1470,   809,     0,  1094,  1097,  1120,    31,   783,
     785,   866,   656,    25,   236,   807,   808,   990,  1003,  1008,
    1102,  1117,  1123,  1158,  1159,  1160,  1161,  1162,  1166,   401,
     812,   813,   814,   815,   818,   819,    99,   106,   152,   153,
     160,   414,   440,   510,   602,   682,   690,   780,   786,   962,
    1038,  1098,  1099,  1101,  1105,  1106,  1112,  1124,  1145,  1279,
    1289,  1555,   661,  1003,  1161,   288,   503,   504,  1168,    20,
    1003,  1165,   664,   813,     5,   811,   401,  1003,     5,   837,
     839,   840,  1003,  1290,  1003,  1003,  1280,  1113,  1003,  1003,
    1101,  1107,   306,   345,   364,   365,   404,   416,   427,   444,
     454,   469,   509,   532,   547,   554,   557,   578,   582,   601,
     619,   867,   868,   869,   872,    25,  1158,  1164,    18,    19,
      26,   105,   117,   144,   238,   335,   370,   404,   416,   453,
     468,   476,   489,   533,   558,   582,   626,   635,   719,   720,
     730,   732,   927,   932,   943,   945,  1003,  1158,  1169,  1170,
     504,    14,   864,   815,   567,  1266,   816,   813,   818,    32,
      35,   109,   125,   126,   135,   306,   345,   364,   365,   366,
     367,   382,   404,   416,   427,   444,   454,   469,   509,   532,
     547,   554,   557,   578,   582,   601,   619,   661,   822,   831,
     842,   847,  1003,   476,   159,  1003,   807,   963,  1146,  1003,
     874,   365,   820,   476,   850,   852,   853,   851,   860,   861,
     476,   476,   873,   504,   476,   813,   848,   471,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   730,   476,
     804,     9,    18,    19,    24,    25,    26,   110,   340,   434,
     439,   442,   458,   473,   476,   479,   488,   529,   541,   552,
     582,   633,   645,   646,   653,   664,   901,   909,   910,   911,
     912,   913,   914,   915,   943,   944,   946,  1009,  1158,  1269,
    1462,   476,   476,   476,   476,   476,   476,    18,    19,    20,
      21,    22,   731,    26,   476,   566,     5,   472,  1169,    25,
      26,  1003,  1009,    19,    25,    26,   817,  1009,   714,   715,
     716,   821,   844,   833,   845,   820,   476,   476,   476,   834,
     850,   851,   476,   476,   832,   504,   843,   476,   848,   813,
     841,   476,    26,  1003,   476,  1114,   807,   807,   476,  1003,
     476,   503,   826,    26,   670,   413,   499,   515,   558,   597,
     626,   635,   854,   670,   413,   499,   515,   558,   597,   626,
     635,   862,    26,    26,   875,   876,   877,   878,  1003,    26,
     829,   830,    26,   664,   711,   951,   994,  1003,   994,   994,
     951,   951,   901,    25,    26,    19,    24,    25,    26,   947,
     948,   949,   950,    25,   952,   994,   995,   901,   438,   901,
     901,   901,   901,   571,  1286,   476,   476,   901,   413,   499,
     515,   558,   597,   626,   635,  1465,  1466,   476,   901,   901,
     476,   476,   916,   476,   476,   476,   476,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    40,   137,   138,   139,   140,   141,
     142,   155,   156,   157,   295,   298,   418,   433,   437,   474,
     502,   520,   601,   667,   803,   902,   917,   919,   920,   921,
     922,   923,   924,   925,    26,  1009,   466,   935,   933,   939,
     937,  1158,  1158,   730,   928,  1003,  1170,   504,   472,    26,
     824,   476,   846,   813,   846,   826,    26,    26,    26,   813,
      26,    26,   812,   829,   846,    26,   664,   104,   838,  1291,
     438,   476,  1281,  1571,  1572,  1573,  1574,  1575,   964,  1147,
    1108,   664,    26,   438,   855,   856,   476,   857,   862,   863,
     857,   476,   858,     5,   438,     5,   438,     5,   329,     5,
     867,   472,     5,     5,   438,   813,   849,   476,     5,   438,
     504,   664,   438,   438,   438,   438,   438,   438,   438,   634,
     948,    19,    26,   634,   438,     5,   438,   438,     5,   805,
     901,   516,  1486,   901,   476,   670,    20,   438,  1486,    20,
    1269,   901,   901,   901,   901,   901,   901,   901,   901,   901,
     901,   901,   901,   901,   901,   901,   901,   901,   901,   901,
     901,   901,   901,   901,   476,   901,   901,   476,  1158,   901,
     901,   901,   901,   438,     5,   760,   761,   762,   901,   476,
    1169,   504,   668,    26,   664,    26,   438,   438,     5,   438,
     304,     5,   438,     5,   438,   329,   472,     5,   438,   849,
    1003,  1175,  1176,  1178,  1125,  1175,   408,  1572,  1266,    36,
      37,    38,    42,    45,    52,    53,    97,    98,   102,   112,
     113,   115,   129,   146,   149,   150,   164,   166,   167,   168,
     176,   177,   179,   180,   181,   187,   190,   192,   193,   194,
     200,   202,   203,   205,   207,   208,   211,   214,   215,   216,
     217,   218,   219,   223,   224,   225,   227,   231,   233,   234,
     239,   242,   245,   247,   249,   251,   255,   256,   258,   259,
     260,   263,   265,   266,   268,   276,   277,   289,   292,   293,
     296,   297,   300,   301,   309,   310,   311,   313,   323,   324,
     325,   327,   331,   332,   336,   344,   352,   353,   354,   360,
     361,   368,   371,   375,   376,   386,   403,   411,   417,   428,
     441,   447,   449,   450,   457,   496,   507,   514,   538,   539,
     543,   555,   561,   562,   563,   564,   568,   572,   579,   580,
     590,   592,   603,   605,   608,   614,   640,   643,   648,   651,
     652,   666,   673,   696,   697,   698,   699,   700,   701,   702,
     705,   707,   709,   723,   724,   725,   726,   743,   765,   779,
     780,   786,   787,   806,   880,   881,   882,   883,   894,   895,
     896,   897,   898,   899,   900,   953,   957,   988,  1010,  1012,
    1015,  1016,  1017,  1018,  1031,  1040,  1062,  1063,  1065,  1069,
    1084,  1085,  1089,  1090,  1091,  1092,  1100,  1115,  1128,  1139,
    1140,  1141,  1152,  1155,  1191,  1194,  1196,  1202,  1203,  1206,
    1209,  1212,  1214,  1216,  1219,  1226,  1231,  1235,  1236,  1237,
    1249,  1250,  1253,  1259,  1261,  1262,  1287,  1302,  1303,  1304,
    1305,  1306,  1318,  1324,  1325,  1345,  1348,  1377,  1379,  1471,
    1472,  1503,  1504,  1511,  1522,  1546,  1555,  1556,  1561,  1562,
    1564,  1568,  1569,  1576,   780,  1103,   669,   692,  1148,  1149,
    1175,    20,   438,   471,   827,   854,    26,   859,    26,    26,
      26,   876,   878,   870,   830,    26,  1003,   994,   730,    20,
     711,  1003,   941,  1466,   941,    26,    26,   634,    24,    26,
     851,   942,   995,   852,   438,   406,   521,   630,  1494,   438,
     438,    26,  1466,   438,   438,   438,   438,   438,   438,   438,
     487,   487,   487,   926,  1486,   487,   926,  1486,   936,   934,
     940,   938,    26,   929,     5,   930,   472,  1169,   837,   438,
      20,   827,    26,   476,    26,    26,   823,    26,   664,   438,
       5,  1175,   438,  1158,  1158,  1158,  1003,    25,  1158,  1213,
    1003,    25,  1003,  1455,   397,  1004,  1005,  1570,  1004,    25,
    1003,  1454,  1003,  1003,  1233,   998,  1004,   998,  1003,  1566,
    1455,  1003,    26,   727,  1158,  1309,   998,  1233,   926,    26,
    1009,  1274,  1275,  1274,   901,   908,  1347,  1454,  1454,   903,
     926,  1004,  1512,  1512,   884,  1233,   998,  1307,  1158,  1000,
    1004,   908,  1512,  1158,  1233,  1158,  1346,  1512,    25,   630,
    1142,  1143,  1158,   998,   998,  1142,   999,  1004,  1003,  1143,
     998,  1512,   998,  1000,  1455,  1158,  1189,  1190,   996,  1004,
    1000,   422,   606,   994,  1064,  1003,   788,  1454,  1001,  1004,
      25,   236,  1003,  1167,  1378,  1550,  1551,  1552,   926,  1189,
     670,   926,  1004,  1215,   958,    55,    56,    57,    58,   178,
     186,   195,   198,   241,   248,   305,   330,   337,   339,   349,
     377,   385,   422,   447,   484,   495,   593,   594,   595,   606,
     709,  1078,  1210,  1211,  1158,  1180,  1181,   907,   908,  1225,
     951,   951,   997,  1004,   926,  1213,  1288,  1158,  1265,    25,
    1158,  1506,  1260,   908,  1557,   151,   201,   238,   335,   412,
     453,   519,   744,   932,  1003,  1158,  1297,   767,   908,   996,
     634,  1003,  1011,  1129,   908,   996,    26,  1158,  1086,   996,
     908,  1523,   908,  1274,  1003,  1013,  1014,  1000,  1013,   951,
    1000,  1013,   951,  1019,  1013,    25,    26,   431,   532,  1009,
    1067,  1158,  1177,  1179,   111,   320,   392,   436,   613,   693,
     694,   695,   704,   734,  1021,  1023,  1025,  1027,  1029,  1153,
    1154,  1157,   383,   394,   445,   459,   548,  1380,   684,   685,
     966,   967,   968,  1003,  1150,   691,  1149,   438,   348,   438,
     438,   438,   438,   668,     5,   438,   438,   472,   476,   670,
     438,    26,   634,   670,    18,    19,    20,    25,    26,   110,
     442,   473,   476,   489,   529,   541,   582,   615,   621,   630,
     631,   633,   645,   646,   653,   656,  1003,  1009,  1461,  1463,
    1493,  1495,  1496,  1498,  1499,  1500,  1551,  1554,  1286,   438,
    1286,  1286,  1286,  1286,  1286,  1286,    25,    25,    25,   901,
     918,   438,    25,   918,   438,   438,   438,   438,   438,   438,
     438,   762,   760,   472,   348,   438,   813,   835,   836,   438,
     438,   668,   438,  1003,  1292,  1178,   438,  1282,   100,   101,
     130,   131,   132,   500,   586,   629,  1326,  1327,  1328,  1331,
    1334,  1337,  1338,  1339,  1342,   664,   634,   656,   147,   148,
     476,   664,   634,   656,     8,   669,   472,  1454,   524,  1234,
    1177,   155,   156,   157,   640,   528,   904,   905,   908,  1158,
    1184,  1454,   733,   734,   887,   312,   133,   134,   670,   505,
       5,   663,   670,   662,   662,  1192,   640,   466,     5,   601,
    1041,   505,   703,  1559,   703,   431,   790,  1158,   591,   662,
    1197,  1198,  1199,   664,    25,  1552,  1168,   374,  1376,   656,
     664,   906,   908,   601,  1550,   906,     8,   598,   997,    26,
     546,   599,   713,   989,  1158,   989,   989,   989,    25,   223,
     350,   356,   357,   358,   378,   484,   487,   495,   530,   565,
     584,   585,   595,   600,   639,   671,  1082,  1083,   989,   989,
     641,  1079,   734,  1079,  1079,   990,   990,  1079,  1079,   734,
       5,   466,     5,   381,   432,     5,   733,   127,   128,   584,
     671,  1070,   706,  1560,   907,   657,   658,   659,   660,  1264,
    1266,   908,  1255,  1256,  1257,  1267,  1268,   908,   476,   476,
     476,   476,    25,   763,  1003,   476,  1506,   392,   476,   566,
     634,   623,   768,   775,   766,  1003,    25,  1144,  1158,  1251,
       8,  1254,    14,  1003,  1163,  1171,  1172,  1174,  1182,  1183,
    1227,   209,   392,   589,   622,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    18,    19,    20,    21,    22,    23,
      33,    51,   108,   117,   135,   136,   144,   151,   152,   155,
     156,   157,   158,   161,   162,   201,   223,   229,   236,   238,
     243,   269,   307,   320,   326,   335,   336,   342,   345,   346,
     350,   356,   357,   363,   364,   365,   368,   369,   370,   374,
     378,   380,   387,   388,   389,   390,   392,   393,   397,   398,
     400,   401,   402,   403,   404,   405,   406,   412,   413,   414,
     416,   417,   421,   422,   423,   424,   425,   426,   427,   428,
     430,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   472,   473,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   514,   515,   516,   517,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   556,   557,   558,   559,   560,   561,
     564,   565,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   682,   690,   695,   699,   702,   703,   704,   705,   708,
     709,   711,   712,   713,  1524,  1525,  1526,  1528,   620,     5,
     703,   703,   906,  1177,  1184,  1066,   466,     5,   197,  1046,
     476,  1158,   906,   476,    26,    26,   111,  1156,    25,  1158,
    1510,  1510,  1004,  1360,  1215,   997,   165,   267,   275,   281,
     283,   294,   322,   338,   343,   355,   362,   511,   516,   523,
     545,   550,  1349,  1350,  1358,  1367,  1368,  1374,  1375,  1381,
    1382,  1392,  1412,  1416,  1482,  1483,  1513,  1514,  1517,  1518,
    1530,   969,   970,   136,   965,   976,   977,   968,  1151,  1571,
    1109,   504,   867,   830,   664,  1003,   413,   499,   515,   558,
     597,   626,   635,  1467,   941,   634,    24,    26,   855,  1499,
    1499,   413,   499,   515,   558,   597,   626,   635,  1464,  1468,
     516,  1498,   476,   476,   476,   476,  1493,  1493,  1493,   476,
     476,   476,   476,  1003,   476,     5,   591,  1421,  1426,  1003,
      18,    19,    20,    21,   137,   138,   139,   140,   141,   142,
    1520,   466,     5,   438,   438,   931,   504,     5,   438,   837,
     807,  1126,   807,   291,   304,   406,   476,   521,   537,  1396,
    1397,  1402,  1404,   476,  1003,  1343,  1344,    26,   476,  1003,
    1323,  1336,  1404,  1406,   476,  1003,  1333,   476,  1323,  1329,
       5,  1003,    25,  1003,  1003,    25,  1006,  1161,  1003,    25,
    1003,  1003,  1003,  1567,  1454,   640,   476,   476,   887,  1454,
       5,   670,   476,  1550,    25,  1008,  1232,  1232,  1506,  1142,
     908,   908,   908,   991,   992,   476,  1158,  1190,  1042,  1043,
    1044,  1454,   670,  1506,   951,  1560,  1064,  1158,   789,   669,
     908,   398,  1201,   601,  1200,  1552,  1003,    20,  1003,  1188,
    1553,     5,  1547,   661,  1207,   114,   116,   118,   662,   670,
     879,  1177,  1180,   959,    18,    19,   476,  1080,  1082,  1211,
    1158,  1181,   990,   908,   392,   640,    26,    26,   733,   199,
    1263,   430,  1301,  1266,  1257,     5,   662,  1258,  1558,  1003,
      25,   951,   951,   634,   995,   667,  1158,   748,  1003,  1003,
     908,   387,   771,   775,   623,   769,   777,    23,   280,  1131,
    1135,   527,   926,   527,  1252,   908,   503,  1168,   664,     5,
    1087,   591,  1228,  1158,  1527,  1529,   235,  1525,  1032,  1014,
     951,   951,  1024,  1025,  1046,  1046,    39,    41,    43,    44,
     316,   319,   321,   341,   351,   372,   395,   399,   475,  1045,
    1047,  1048,  1074,  1158,  1179,   591,   735,    26,   446,  1030,
     369,  1505,  1505,   184,   185,   482,   591,  1003,  1413,  1414,
    1456,  1454,  1454,  1454,  1351,  1454,  1454,  1003,  1515,   213,
     426,   441,   484,   495,   516,   523,   531,   553,   630,   636,
    1383,  1385,  1386,  1387,  1494,  1454,  1359,  1383,  1385,  1571,
    1571,   431,   978,  1158,   686,   687,   971,   972,   973,   526,
     669,   688,   689,   708,   981,   982,  1571,   807,    26,   828,
      20,  1003,   438,   476,    24,    26,   670,  1494,   438,   442,
    1521,  1554,   406,   521,   630,  1445,  1498,  1501,  1445,  1445,
    1445,  1445,   664,  1501,  1496,   560,  1422,  1423,  1424,  1454,
     571,  1420,  1427,   379,   559,   570,  1369,  1489,  1498,  1498,
    1498,  1498,  1551,   901,   438,   828,   836,  1293,   807,  1283,
     476,   476,   476,  1340,  1404,   476,   476,   103,  1341,  1343,
       5,  1335,  1336,   109,   345,   365,   366,   367,   404,   416,
     427,   444,   454,   469,   517,   547,   557,   578,   582,   610,
     619,  1446,  1447,  1448,  1450,  1332,  1333,  1329,  1330,   708,
    1327,   664,   634,   438,   664,   634,   591,  1565,   476,   728,
     729,  1003,  1310,   926,   904,  1003,  1308,   661,  1204,   670,
       5,     5,     5,   624,   908,     5,   664,   528,   670,   669,
     210,   212,   316,   319,   791,   794,   795,  1074,   792,   793,
    1003,   476,  1004,   693,   694,  1205,   664,   504,   908,  1454,
    1548,  1549,  1550,   621,   661,  1208,  1003,  1003,   992,   993,
     554,   951,   887,     8,     8,   961,    26,    26,  1081,  1082,
    1158,   365,  1220,   111,   901,  1266,   264,  1268,  1274,  1571,
       5,     5,   438,   438,   764,  1003,   438,  1506,   760,   476,
     476,   776,   772,   407,   770,   908,   387,   773,   777,   641,
    1076,  1136,  1132,   409,  1130,  1131,   906,   670,  1164,    20,
    1003,  1173,  1183,    14,   528,  1229,  1230,  1498,  1554,  1180,
    1571,  1026,  1027,   595,  1002,   591,  1057,  1056,  1059,  1058,
     994,  1060,   994,  1061,  1055,  1054,  1052,  1051,  1075,   372,
    1048,  1053,   951,    46,    47,    48,    49,    50,    51,   143,
     380,   393,   456,   462,   501,   525,   535,   536,   541,   551,
     573,   576,   577,   581,   638,   649,   736,   737,  1072,  1073,
       5,    26,  1506,   294,  1158,   516,  1487,  1488,  1506,  1215,
    1481,  1483,   145,   145,   640,  1213,  1415,  1416,   476,  1393,
     196,  1427,  1454,   220,   317,  1519,   664,   670,   476,  1388,
    1388,   591,   669,     5,  1484,  1531,   389,   398,   422,   425,
     442,   546,   599,   606,   997,  1361,  1366,   670,   669,   980,
    1158,     5,   591,   974,   975,   683,   973,   979,  1003,   979,
     983,   984,   979,   372,   982,  1110,   472,    26,   413,   499,
     515,   558,   597,   626,   635,  1469,  1495,     5,  1468,   438,
       5,  1498,     5,   438,  1498,  1498,  1498,  1498,  1003,   438,
     476,  1424,     5,  1003,  1460,     9,   340,   476,   488,  1430,
    1431,  1432,  1433,  1434,  1438,  1442,  1444,  1498,   415,  1418,
    1428,  1003,  1490,   663,  1445,   379,   472,   506,  1276,  1296,
    1127,   506,  1238,  1270,   656,  1003,  1399,  1401,  1454,  1458,
    1459,  1403,  1458,  1403,     5,   438,  1341,  1403,  1430,  1003,
     438,  1344,     5,   438,   476,   476,   476,  1468,  1468,   476,
     476,   476,   476,   476,   252,   253,   254,   446,  1405,  1407,
       5,   438,     5,   438,  1003,  1003,    25,  1003,  1003,    25,
    1003,   908,  1003,  1320,  1321,     5,  1322,  1323,   926,  1116,
     664,  1322,   621,  1506,  1506,   908,   908,   991,   554,   908,
    1563,     5,  1043,    20,  1458,  1506,   792,   800,   799,   801,
    1003,  1007,   802,  1007,   237,   795,   798,     5,  1046,   664,
     908,     8,  1553,  1169,   664,     5,  1506,   621,  1003,  1177,
     926,   598,  1364,     5,   438,  1158,     5,    26,  1158,   373,
      25,  1298,   392,   392,   504,   664,   392,   476,   749,   753,
     746,  1571,  1571,   778,   774,   770,  1077,    25,  1002,  1137,
    1158,  1571,   908,   471,   504,   926,     5,  1033,  1028,  1029,
      26,   733,  1003,  1571,  1571,  1571,  1571,     5,  1049,     5,
    1050,  1571,  1571,  1571,  1571,  1080,  1571,  1002,    25,    14,
      14,     5,   438,    26,  1454,  1494,  1475,   640,   640,  1350,
    1480,  1481,  1416,  1394,  1458,   661,   997,   476,  1354,  1003,
    1516,  1515,  1389,  1458,   508,  1390,  1391,  1456,  1454,  1387,
    1495,    91,    92,    93,    94,    95,   628,  1534,   908,   908,
     598,  1362,   997,  1390,  1454,     5,  1158,   979,  1571,  1571,
       5,   986,   987,  1571,  1571,   985,  1103,   871,   438,   476,
    1426,  1468,   670,  1468,   438,  1498,   438,   438,   438,   438,
    1423,  1425,  1423,  1433,  1493,  1430,  1498,  1493,     6,     7,
       9,    10,    12,    13,    14,    15,    16,    17,   298,   418,
     419,   474,   601,   667,   717,   718,  1441,  1443,  1419,  1497,
    1498,   493,  1417,  1429,   314,  1319,    26,  1370,  1371,  1372,
    1458,  1487,  1490,   825,   119,   120,   122,   123,   124,   222,
     230,   264,   273,   302,   303,   347,   391,   446,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,  1273,  1277,
     183,   559,  1278,  1294,  1103,   206,   221,   222,   230,   264,
     273,   302,   347,   391,  1271,  1272,  1284,  1278,  1459,   504,
    1457,   438,     5,   664,     5,   438,   438,  1404,   438,   438,
    1336,    26,  1451,  1451,    26,   670,   476,   670,    26,  1452,
      26,    26,  1452,  1452,    25,  1461,   204,   304,   342,   406,
     420,   521,   537,  1398,  1408,  1409,  1410,  1411,  1333,  1329,
     664,   664,   583,   632,     5,   438,   729,     5,   438,   906,
     438,    20,   438,  1506,     5,   908,   611,   320,   738,   739,
     908,  1046,  1571,  1571,     5,   796,   504,   664,     5,   797,
    1571,   793,   591,    20,  1003,     5,  1003,  1195,   472,    20,
    1458,  1549,     8,  1506,   436,   703,   906,  1365,   960,  1082,
     712,  1218,   901,     5,   760,  1158,   745,   727,  1003,  1158,
     751,   438,   760,   760,  1571,  1571,  1080,  1134,    25,  1138,
    1158,   616,   956,  1169,   528,   907,  1088,  1230,   108,   587,
    1034,  1020,  1021,   664,   994,  1571,   994,  1571,   733,    26,
    1158,    26,  1158,   737,   438,   476,  1507,  1495,  1481,  1481,
    1473,     5,   438,   516,  1492,  1355,  1458,   524,  1352,  1492,
     670,     5,   438,     5,   591,  1485,    18,    19,   110,   473,
     476,   489,   528,   529,   541,   582,   621,   633,   645,   646,
     653,   656,  1003,  1461,  1493,  1539,  1540,  1541,  1542,  1543,
    1544,  1554,  1539,  1539,  1539,  1458,  1536,  1538,  1535,  1536,
    1537,  1532,  1363,   670,  1158,  1003,  1571,  1571,  1571,  1571,
     668,    26,   438,   670,  1469,   670,     5,   438,   438,  1431,
    1432,  1436,  1499,  1436,   476,  1493,  1436,   476,  1493,  1436,
      10,   295,   433,   435,  1498,     5,  1430,     5,   583,   632,
    1373,  1319,   668,  1274,  1274,  1274,    25,  1274,  1274,  1274,
    1274,  1274,  1274,    25,    25,  1274,  1277,  1158,  1185,  1186,
     663,   492,  1239,  1571,    25,    25,    26,    26,    26,    26,
      26,    25,  1158,  1272,  1239,    26,  1398,  1458,    20,  1003,
    1458,  1341,   438,   438,     5,   438,  1469,    26,  1469,     5,
    1449,     5,   438,   438,   438,  1449,  1400,  1454,   476,  1410,
    1341,  1003,  1003,  1321,   667,   721,  1315,  1316,  1317,  1323,
      54,   131,   132,   290,   667,  1311,  1312,  1313,   513,   886,
    1311,     5,   421,  1506,     5,   476,   438,   595,  1071,  1007,
    1571,   730,    20,  1003,  1007,  1571,   951,   908,  1506,     8,
     951,  1180,  1571,    26,  1002,    25,  1299,  1177,   472,   760,
     750,   754,   438,  1571,  1002,   908,   954,   472,  1036,  1035,
     486,  1022,  1023,    20,  1003,  1508,  1509,   598,  1491,  1476,
    1474,  1458,  1494,   188,  1395,     5,   438,  1353,  1516,  1458,
    1391,  1390,  1491,  1542,  1542,  1541,   476,   476,   476,   476,
     476,   476,   476,  1003,   476,     5,   438,    18,    19,    20,
      21,  1520,   438,     5,   438,     5,    14,   196,   571,  1533,
    1180,  1390,   257,  1111,   867,   438,  1469,  1469,  1423,   487,
    1435,  1435,  1439,  1440,  1461,  1554,  1435,  1439,  1435,  1436,
    1498,  1497,  1371,   837,   583,   632,  1187,     5,  1185,   107,
     182,   244,   246,   262,   270,   274,   299,  1240,  1241,  1295,
    1111,  1285,     5,   472,  1457,    26,   438,    26,  1453,   438,
      26,   438,   476,  1430,  1314,  1570,    26,  1317,    26,    26,
    1314,  1319,  1313,   994,   733,   421,  1506,   908,   740,   613,
    1193,    26,   733,   472,  1071,   438,  1506,   286,   733,   438,
     438,   476,   752,   392,   758,   438,   747,  1133,  1571,   504,
     908,  1571,  1002,     5,   438,  1180,  1426,  1495,  1458,   476,
    1426,   438,  1521,  1445,  1541,  1545,  1445,  1445,  1445,  1445,
     664,  1545,  1540,  1541,  1541,  1541,  1541,  1536,    14,  1537,
    1540,   997,  1430,   189,   661,  1384,  1437,  1461,  1502,     5,
     438,   438,  1435,     7,  1186,  1242,  1243,  1158,  1245,  1158,
    1244,  1246,  1241,   285,   285,    26,   438,   670,   438,  1401,
     438,   885,  1506,   439,   248,   305,   330,   339,   377,   385,
     477,   647,   737,   741,   742,   476,   664,   733,  1217,  1300,
     755,   438,  1177,   758,   758,  1571,   955,  1169,   620,  1068,
    1509,  1489,  1426,   528,  1356,  1357,  1498,  1489,   438,  1541,
       5,   438,  1541,  1541,  1541,  1541,  1003,   438,   476,  1003,
    1440,  1498,  1571,  1571,  1247,  1571,  1248,  1571,  1571,   472,
    1469,   438,   284,   395,   399,   888,   889,   890,  1074,   989,
     989,   989,   989,   989,   989,    25,     5,   438,   908,    20,
    1003,  1074,  1221,  1222,  1223,   758,   760,   758,   287,   472,
    1037,   733,     5,   438,   333,   334,  1477,   438,  1541,   438,
     438,   438,   438,  1539,  1571,  1571,   892,   891,   284,   890,
     893,   742,     5,  1224,   328,  1223,   756,  1571,  1357,    25,
    1003,  1478,  1479,   438,  1571,  1571,  1571,   908,  1571,   438,
    1034,   664,   664,     5,   438,   757,  1003,  1003,  1479,   209,
     392,   759,   664,  1177,  1003
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
#line 990 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 993 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 997 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1003 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1008 "fgl.yacc"
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
#line 1020 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1025 "fgl.yacc"
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
#line 1048 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1049 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1050 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1051 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1052 "fgl.yacc"
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
#line 1063 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1069 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1070 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1071 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1072 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1073 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1078 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1079 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1090 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1093 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1096 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1096 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1103 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1104 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1110 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1111 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1112 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1113 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1114 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1115 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1116 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1117 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1118 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1119 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1125 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1126 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1133 "fgl.yacc"
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
#line 1144 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1148 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1149 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1153 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1159 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1161 "fgl.yacc"
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
#line 1172 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1174 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1176 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1178 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1182 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1184 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1245 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1249 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1253 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1260 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1263 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1267 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1271 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1278 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1284 "fgl.yacc"
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
#line 1293 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1297 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1302 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1306 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1314 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1318 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1322 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1324 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1330 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1335 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1338 "fgl.yacc"
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
#line 1354 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1361 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1365 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1369 "fgl.yacc"
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
#line 1391 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1391 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1395 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1396 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1397 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1402 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1405 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1411 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1414 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1426 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1432 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1435 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1450 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1460 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1466 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1475 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1488 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1491 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1493 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1499 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1501 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1506 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1511 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1517 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1521 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1536 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1539 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1542 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1545 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1548 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1551 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1573 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1582 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1592 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1606 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1611 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1614 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1623 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1629 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1644 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1648 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1653 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1663 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1663 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1664 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1664 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1665 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1665 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1666 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1666 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1667 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1667 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1675 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1679 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1685 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1689 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1704 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1707 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1710 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1713 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1716 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1719 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1728 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1736 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1741 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1754 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1758 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1773 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1774 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1782 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1782 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1791 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1791 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1800 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1801 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1802 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1805 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1810 "fgl.yacc"
    { }
    break;

  case 194:
#line 1810 "fgl.yacc"
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
#line 1827 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1831 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1846 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1847 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1848 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1849 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1854 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1860 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1869 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1873 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1889 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1891 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1892 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1899 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1899 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1900 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1901 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1904 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1906 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1916 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1931 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1931 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1937 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1938 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1939 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1940 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1941 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1942 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1943 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1944 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1945 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1946 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1949 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1950 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1951 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1952 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1956 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1961 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1966 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1970 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1973 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1977 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1978 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1979 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1980 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1981 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1982 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1983 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1984 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1985 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1988 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1989 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1990 "fgl.yacc"
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
#line 2025 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2029 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2031 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2033 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2035 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2040 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2044 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2044 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2048 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2049 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2050 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2051 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2052 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2053 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2055 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2060 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2060 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2063 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2065 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2071 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2073 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2079 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2087 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2087 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2090 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2091 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2092 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2093 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2094 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2095 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2097 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2118 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2127 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2129 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2131 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 317:
#line 2133 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 318:
#line 2134 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2135 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2136 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2137 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2142 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2149 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2154 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2156 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2158 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2159 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2160 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2161 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2162 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2163 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2164 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2167 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2169 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2175 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2183 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2191 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2195 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2203 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2204 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2205 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2206 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2225 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2237 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2241 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2244 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2247 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2248 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2249 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2250 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2251 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2257 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2264 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2269 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2274 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2279 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2283 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2292 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2294 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2299 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2311 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2315 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2318 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2322 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2325 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2329 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
#line 2336 "fgl.yacc"
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
#line 2354 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2360 "fgl.yacc"
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
#line 2384 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2387 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2402 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 384:
#line 2404 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 385:
#line 2406 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 386:
#line 2408 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 387:
#line 2410 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 388:
#line 2412 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 389:
#line 2413 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 390:
#line 2420 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 391:
#line 2422 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 392:
#line 2426 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 393:
#line 2428 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 394:
#line 2430 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 395:
#line 2432 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 396:
#line 2434 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 397:
#line 2436 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 398:
#line 2438 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 399:
#line 2444 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 400:
#line 2458 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 401:
#line 2461 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 406:
#line 2478 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 409:
#line 2484 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 410:
#line 2488 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 411:
#line 2493 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 415:
#line 2503 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 416:
#line 2504 "fgl.yacc"
    {inc_counter();}
    break;

  case 422:
#line 2510 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 423:
#line 2517 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 424:
#line 2517 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 426:
#line 2522 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 427:
#line 2526 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2532 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2540 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2546 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 431:
#line 2555 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 432:
#line 2557 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 433:
#line 2564 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 434:
#line 2572 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 435:
#line 2576 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 436:
#line 2585 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 437:
#line 2590 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 438:
#line 2595 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 439:
#line 2599 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 440:
#line 2601 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 441:
#line 2604 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 442:
#line 2611 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 443:
#line 2619 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2631 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2637 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 446:
#line 2643 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 449:
#line 2653 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 450:
#line 2659 "fgl.yacc"
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
#line 2731 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
	
}
    break;

  case 452:
#line 2742 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 453:
#line 2750 "fgl.yacc"
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
#line 2758 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 455:
#line 2758 "fgl.yacc"
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
#line 2774 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 457:
#line 2778 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 458:
#line 2784 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 459:
#line 2787 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 460:
#line 2795 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 461:
#line 2799 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 462:
#line 2802 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 463:
#line 2808 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 464:
#line 2818 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 465:
#line 2823 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 466:
#line 2830 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 467:
#line 2833 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 468:
#line 2836 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 469:
#line 2841 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 470:
#line 2848 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 471:
#line 2853 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 472:
#line 2858 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 473:
#line 2863 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 474:
#line 2874 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 475:
#line 2882 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 476:
#line 2890 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 477:
#line 2895 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 478:
#line 2899 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 479:
#line 2904 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 480:
#line 2908 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 481:
#line 2912 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 482:
#line 2918 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 483:
#line 2921 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 484:
#line 2925 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 485:
#line 2929 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 486:
#line 2933 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 487:
#line 2937 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 488:
#line 2941 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 489:
#line 2948 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 490:
#line 2958 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 491:
#line 2963 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 492:
#line 2969 "fgl.yacc"
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
#line 2979 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 494:
#line 2984 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 495:
#line 2987 "fgl.yacc"
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
#line 3001 "fgl.yacc"
    {chk4var=1;}
    break;

  case 497:
#line 3001 "fgl.yacc"
    {chk4var=0;}
    break;

  case 498:
#line 3001 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 499:
#line 3004 "fgl.yacc"
    {chk4var=1;}
    break;

  case 500:
#line 3004 "fgl.yacc"
    {chk4var=0;}
    break;

  case 501:
#line 3004 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 502:
#line 3008 "fgl.yacc"
    {chk4var=1;}
    break;

  case 503:
#line 3008 "fgl.yacc"
    {chk4var=0;}
    break;

  case 504:
#line 3008 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 505:
#line 3012 "fgl.yacc"
    {chk4var=1;}
    break;

  case 506:
#line 3012 "fgl.yacc"
    {chk4var=0;}
    break;

  case 507:
#line 3012 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 508:
#line 3016 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3022 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3028 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3034 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3040 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 513:
#line 3046 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 514:
#line 3056 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 515:
#line 3057 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 518:
#line 3065 "fgl.yacc"
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

  case 519:
#line 3076 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 520:
#line 3077 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 521:
#line 3083 "fgl.yacc"
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

  case 522:
#line 3094 "fgl.yacc"
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

  case 523:
#line 3104 "fgl.yacc"
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

  case 526:
#line 3117 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 527:
#line 3122 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 528:
#line 3129 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 529:
#line 3133 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 530:
#line 3136 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 531:
#line 3139 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 532:
#line 3145 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 533:
#line 3148 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 534:
#line 3151 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 535:
#line 3168 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 536:
#line 3171 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 537:
#line 3177 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 538:
#line 3178 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 539:
#line 3179 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 541:
#line 3184 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 542:
#line 3185 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 543:
#line 3186 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 544:
#line 3187 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 545:
#line 3189 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 546:
#line 3190 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 547:
#line 3191 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 548:
#line 3193 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 549:
#line 3194 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 551:
#line 3200 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 552:
#line 3204 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 553:
#line 3208 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 554:
#line 3213 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 555:
#line 3217 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 556:
#line 3232 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 557:
#line 3236 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 558:
#line 3237 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 559:
#line 3244 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 561:
#line 3261 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 562:
#line 3265 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 563:
#line 3271 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 564:
#line 3275 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 565:
#line 3284 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 566:
#line 3285 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 567:
#line 3297 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 568:
#line 3303 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 569:
#line 3311 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 576:
#line 3328 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 577:
#line 3330 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 578:
#line 3333 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 579:
#line 3335 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 584:
#line 3349 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 585:
#line 3351 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 586:
#line 3354 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 587:
#line 3356 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 600:
#line 3387 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 601:
#line 3389 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 602:
#line 3392 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 603:
#line 3394 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 604:
#line 3397 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 605:
#line 3399 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 606:
#line 3402 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 607:
#line 3404 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 608:
#line 3407 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 609:
#line 3409 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 610:
#line 3424 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 611:
#line 3440 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 612:
#line 3441 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 613:
#line 3442 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 614:
#line 3443 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 615:
#line 3444 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 616:
#line 3445 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 617:
#line 3446 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 621:
#line 3454 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 623:
#line 3460 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 624:
#line 3463 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 625:
#line 3468 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 626:
#line 3473 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 627:
#line 3476 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 628:
#line 3481 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 629:
#line 3486 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 630:
#line 3491 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 631:
#line 3498 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 632:
#line 3499 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 633:
#line 3506 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 634:
#line 3513 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 635:
#line 3515 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 636:
#line 3521 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 637:
#line 3526 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 638:
#line 3531 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 639:
#line 3536 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 640:
#line 3536 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 641:
#line 3539 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 642:
#line 3545 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 643:
#line 3550 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 644:
#line 3554 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 647:
#line 3562 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 648:
#line 3565 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 649:
#line 3568 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 650:
#line 3573 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 651:
#line 3578 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 652:
#line 3583 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 653:
#line 3590 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 655:
#line 3599 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 656:
#line 3661 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 658:
#line 3670 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 659:
#line 3679 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 661:
#line 3686 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 662:
#line 3689 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 663:
#line 3695 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 664:
#line 3701 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 665:
#line 3705 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 666:
#line 3709 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 667:
#line 3715 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 668:
#line 3719 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 669:
#line 3723 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 670:
#line 3728 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 671:
#line 3733 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 690:
#line 3774 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 691:
#line 3781 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 692:
#line 3783 "fgl.yacc"
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

  case 694:
#line 3802 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 696:
#line 3805 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 697:
#line 3807 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 698:
#line 3810 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 699:
#line 3814 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 700:
#line 3817 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 701:
#line 3823 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 702:
#line 3834 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 703:
#line 3835 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 704:
#line 3838 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 706:
#line 3844 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 707:
#line 3848 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 708:
#line 3849 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 709:
#line 3853 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 713:
#line 3868 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 714:
#line 3870 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 717:
#line 3879 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 718:
#line 3882 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 719:
#line 3886 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 720:
#line 3889 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 721:
#line 3892 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 722:
#line 3895 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 723:
#line 3898 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 724:
#line 3902 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 725:
#line 3905 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 726:
#line 3908 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 727:
#line 3911 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 728:
#line 3914 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 729:
#line 3917 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 730:
#line 3920 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 731:
#line 3923 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 732:
#line 3926 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 733:
#line 3927 "fgl.yacc"
    {
		A4GL_add_event(-14,"");
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 734:
#line 3930 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 735:
#line 3931 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 736:
#line 3934 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 737:
#line 3935 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 738:
#line 3938 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 739:
#line 3946 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 740:
#line 3950 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 741:
#line 3956 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 742:
#line 3960 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 743:
#line 3965 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 744:
#line 3970 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 745:
#line 3975 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 746:
#line 3976 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 747:
#line 3977 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 748:
#line 3981 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 749:
#line 3985 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 750:
#line 3994 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 751:
#line 3999 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 752:
#line 4003 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 753:
#line 4010 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 754:
#line 4019 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 755:
#line 4025 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 756:
#line 4026 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 757:
#line 4027 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 758:
#line 4028 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 759:
#line 4031 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 761:
#line 4034 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 762:
#line 4041 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 763:
#line 4042 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 764:
#line 4043 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 765:
#line 4044 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 766:
#line 4045 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 767:
#line 4046 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 768:
#line 4047 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 769:
#line 4048 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 770:
#line 4049 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 771:
#line 4054 "fgl.yacc"
    {iskey=1;}
    break;

  case 772:
#line 4054 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 773:
#line 4056 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 774:
#line 4059 "fgl.yacc"
    {iskey=1;}
    break;

  case 775:
#line 4059 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 776:
#line 4061 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 777:
#line 4065 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 778:
#line 4068 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 779:
#line 4069 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 781:
#line 4072 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 787:
#line 4084 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 788:
#line 4085 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 789:
#line 4086 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 790:
#line 4087 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 791:
#line 4088 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 792:
#line 4089 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 793:
#line 4090 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 794:
#line 4091 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 795:
#line 4092 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 796:
#line 4093 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 797:
#line 4094 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 798:
#line 4095 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 799:
#line 4096 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 800:
#line 4097 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 801:
#line 4101 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 802:
#line 4119 "fgl.yacc"
    {chk4var=1;}
    break;

  case 803:
#line 4119 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 804:
#line 4122 "fgl.yacc"
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

  case 805:
#line 4146 "fgl.yacc"
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

  case 807:
#line 4164 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 808:
#line 4170 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 809:
#line 4176 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 810:
#line 4182 "fgl.yacc"
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

  case 811:
#line 4194 "fgl.yacc"
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

  case 812:
#line 4219 "fgl.yacc"
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

  case 815:
#line 4235 "fgl.yacc"
    {
	}
    break;

  case 824:
#line 4260 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 828:
#line 4268 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 844:
#line 4294 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 845:
#line 4295 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 846:
#line 4303 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 847:
#line 4308 "fgl.yacc"
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

  case 848:
#line 4324 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 849:
#line 4330 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 851:
#line 4345 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 852:
#line 4358 "fgl.yacc"
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

  case 853:
#line 4368 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 854:
#line 4375 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 855:
#line 4382 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 856:
#line 4388 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 857:
#line 4388 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 858:
#line 4393 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 859:
#line 4399 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 860:
#line 4407 "fgl.yacc"
    {
}
    break;

  case 864:
#line 4419 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 866:
#line 4427 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 867:
#line 4433 "fgl.yacc"
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

  case 870:
#line 4449 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 871:
#line 4453 "fgl.yacc"
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

  case 872:
#line 4466 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 874:
#line 4484 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 875:
#line 4492 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 876:
#line 4498 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 877:
#line 4509 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 878:
#line 4513 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 879:
#line 4520 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 880:
#line 4527 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 881:
#line 4533 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 882:
#line 4538 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 885:
#line 4545 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 886:
#line 4546 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 887:
#line 4548 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 888:
#line 4549 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 889:
#line 4552 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 890:
#line 4553 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 891:
#line 4554 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 892:
#line 4556 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 893:
#line 4561 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 894:
#line 4566 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 895:
#line 4573 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 899:
#line 4580 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 900:
#line 4582 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 901:
#line 4584 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 902:
#line 4592 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 903:
#line 4598 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 904:
#line 4602 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 907:
#line 4614 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 908:
#line 4617 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 909:
#line 4621 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 910:
#line 4624 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 912:
#line 4633 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 913:
#line 4636 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 914:
#line 4639 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 921:
#line 4655 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 922:
#line 4660 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 923:
#line 4660 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 924:
#line 4663 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 925:
#line 4691 "fgl.yacc"
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

  case 927:
#line 4748 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 929:
#line 4755 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 930:
#line 4759 "fgl.yacc"
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

  case 931:
#line 4802 "fgl.yacc"
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

  case 935:
#line 4850 "fgl.yacc"
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

  case 936:
#line 4864 "fgl.yacc"
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

  case 941:
#line 4888 "fgl.yacc"
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

  case 942:
#line 4948 "fgl.yacc"
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

  case 943:
#line 5004 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 944:
#line 5009 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 945:
#line 5017 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 946:
#line 5022 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 947:
#line 5030 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 948:
#line 5036 "fgl.yacc"
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

  case 949:
#line 5068 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 950:
#line 5071 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 951:
#line 5073 "fgl.yacc"
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

  case 952:
#line 5114 "fgl.yacc"
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

  case 957:
#line 5167 "fgl.yacc"
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

  case 958:
#line 5219 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 960:
#line 5226 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 961:
#line 5232 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 962:
#line 5243 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 963:
#line 5250 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 965:
#line 5258 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 966:
#line 5261 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 967:
#line 5262 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 969:
#line 5264 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 970:
#line 5265 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 971:
#line 5268 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 972:
#line 5271 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 973:
#line 5277 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 974:
#line 5280 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 975:
#line 5284 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 976:
#line 5289 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 977:
#line 5297 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 978:
#line 5302 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 979:
#line 5309 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 980:
#line 5312 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 985:
#line 5325 "fgl.yacc"
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

  case 986:
#line 5344 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 987:
#line 5351 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 988:
#line 5358 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 989:
#line 5361 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 990:
#line 5375 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 995:
#line 5392 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 996:
#line 5397 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 997:
#line 5403 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 999:
#line 5410 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1000:
#line 5415 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1001:
#line 5418 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1002:
#line 5419 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1003:
#line 5422 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1004:
#line 5423 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1005:
#line 5426 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1006:
#line 5427 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1007:
#line 5432 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1008:
#line 5439 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1009:
#line 5442 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1010:
#line 5448 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1011:
#line 5450 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1012:
#line 5452 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1013:
#line 5454 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1014:
#line 5457 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1015:
#line 5457 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1016:
#line 5458 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1017:
#line 5463 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1018:
#line 5471 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1019:
#line 5472 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1020:
#line 5477 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1021:
#line 5479 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1022:
#line 5481 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1026:
#line 5498 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1027:
#line 5501 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1028:
#line 5504 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1029:
#line 5507 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1030:
#line 5511 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1031:
#line 5514 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1032:
#line 5517 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1033:
#line 5521 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1034:
#line 5522 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1035:
#line 5523 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1036:
#line 5524 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1037:
#line 5525 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1038:
#line 5526 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1039:
#line 5527 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1040:
#line 5529 "fgl.yacc"
    { print_options('A',"1"); }
    break;

  case 1041:
#line 5530 "fgl.yacc"
    { print_options('A',"2"); }
    break;

  case 1042:
#line 5532 "fgl.yacc"
    { print_options('B',"1"); }
    break;

  case 1043:
#line 5533 "fgl.yacc"
    { print_options('B',"2"); }
    break;

  case 1044:
#line 5535 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('A',"0"); }
    break;

  case 1045:
#line 5536 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('B',"0");}
    break;

  case 1046:
#line 5537 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1047:
#line 5540 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1048:
#line 5543 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1049:
#line 5546 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1050:
#line 5549 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1051:
#line 5552 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1052:
#line 5569 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1055:
#line 5579 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1056:
#line 5585 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1057:
#line 5589 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,2);
	}
    break;

  case 1058:
#line 5593 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1060:
#line 5613 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1061:
#line 5618 "fgl.yacc"
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

  case 1062:
#line 5631 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1063:
#line 5632 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1064:
#line 5636 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1065:
#line 5641 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1066:
#line 5642 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1067:
#line 5646 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1071:
#line 5652 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1072:
#line 5655 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1074:
#line 5670 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1075:
#line 5674 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1076:
#line 5680 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1077:
#line 5681 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1078:
#line 5686 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1079:
#line 5687 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1080:
#line 5690 "fgl.yacc"
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

  case 1082:
#line 5718 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1083:
#line 5723 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1084:
#line 5728 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1085:
#line 5733 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1091:
#line 5755 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1092:
#line 5762 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1093:
#line 5771 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1094:
#line 5777 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1095:
#line 5779 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1099:
#line 5790 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1100:
#line 5791 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0,1);
}
    break;

  case 1101:
#line 5797 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1102:
#line 5801 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0,1);
}
    break;

  case 1103:
#line 5807 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1104:
#line 5808 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0,1);}
    break;

  case 1105:
#line 5813 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1106:
#line 5814 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1107:
#line 5816 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1108:
#line 5817 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1109:
#line 5818 "fgl.yacc"
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

  case 1110:
#line 5832 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1111:
#line 5834 "fgl.yacc"
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

  case 1112:
#line 5851 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1119:
#line 5863 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1120:
#line 5863 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1121:
#line 5869 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1122:
#line 5869 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1123:
#line 5872 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1124:
#line 5872 "fgl.yacc"
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

  case 1125:
#line 5888 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1126:
#line 5889 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1127:
#line 5890 "fgl.yacc"
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

  case 1128:
#line 5899 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1129:
#line 5911 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1135:
#line 5922 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1136:
#line 5927 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1137:
#line 5927 "fgl.yacc"
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

  case 1138:
#line 5948 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1139:
#line 5953 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1140:
#line 5959 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1141:
#line 5960 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1142:
#line 5961 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1143:
#line 5965 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1144:
#line 5966 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1145:
#line 5967 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1146:
#line 5968 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1147:
#line 5972 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1148:
#line 5982 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1149:
#line 5984 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1150:
#line 5989 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1151:
#line 5992 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1152:
#line 5997 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1153:
#line 6004 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1154:
#line 6011 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1155:
#line 6018 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1156:
#line 6027 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1157:
#line 6034 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1158:
#line 6041 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1159:
#line 6048 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1160:
#line 6055 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1165:
#line 6068 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1166:
#line 6069 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1167:
#line 6070 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1168:
#line 6071 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1169:
#line 6072 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1170:
#line 6073 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1171:
#line 6074 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1172:
#line 6075 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1173:
#line 6076 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1174:
#line 6077 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1177:
#line 6083 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1178:
#line 6084 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1179:
#line 6085 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1180:
#line 6086 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1185:
#line 6095 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1186:
#line 6096 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1187:
#line 6097 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1188:
#line 6098 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1189:
#line 6099 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1190:
#line 6100 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1191:
#line 6101 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1192:
#line 6102 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1193:
#line 6104 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1194:
#line 6105 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1195:
#line 6106 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1196:
#line 6107 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1197:
#line 6109 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1198:
#line 6110 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1199:
#line 6111 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1200:
#line 6112 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1204:
#line 6117 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1205:
#line 6118 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1209:
#line 6125 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1210:
#line 6133 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1211:
#line 6141 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1212:
#line 6153 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1213:
#line 6162 "fgl.yacc"
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

  case 1214:
#line 6173 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1215:
#line 6177 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1216:
#line 6181 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1217:
#line 6187 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1218:
#line 6192 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1219:
#line 6200 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1220:
#line 6203 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1221:
#line 6212 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1222:
#line 6223 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1224:
#line 6230 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1225:
#line 6238 "fgl.yacc"
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

  case 1226:
#line 6248 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1227:
#line 6251 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1228:
#line 6255 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1229:
#line 6263 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1230:
#line 6266 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1231:
#line 6272 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1232:
#line 6276 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1233:
#line 6280 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1234:
#line 6284 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1235:
#line 6288 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1236:
#line 6294 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1237:
#line 6295 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1238:
#line 6296 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1239:
#line 6297 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1240:
#line 6302 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1241:
#line 6304 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1242:
#line 6307 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1243:
#line 6311 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1244:
#line 6314 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1245:
#line 6321 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1246:
#line 6326 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1247:
#line 6327 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1248:
#line 6328 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1249:
#line 6329 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1250:
#line 6334 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1251:
#line 6335 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1252:
#line 6341 "fgl.yacc"
    {insql=1;}
    break;

  case 1253:
#line 6341 "fgl.yacc"
    {insql=0;}
    break;

  case 1254:
#line 6341 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1255:
#line 6346 "fgl.yacc"
    {insql=1;}
    break;

  case 1256:
#line 6346 "fgl.yacc"
    {insql=0;}
    break;

  case 1257:
#line 6346 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1258:
#line 6354 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1259:
#line 6355 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1261:
#line 6360 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1262:
#line 6365 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1263:
#line 6366 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1264:
#line 6367 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1265:
#line 6368 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1266:
#line 6369 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1268:
#line 6374 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1269:
#line 6374 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1271:
#line 6378 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1272:
#line 6382 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1273:
#line 6383 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1274:
#line 6386 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1275:
#line 6387 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1276:
#line 6390 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1277:
#line 6393 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1278:
#line 6396 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1279:
#line 6402 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1280:
#line 6404 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1282:
#line 6417 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1283:
#line 6421 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1284:
#line 6422 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1286:
#line 6427 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1287:
#line 6430 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1288:
#line 6436 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1289:
#line 6439 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1290:
#line 6447 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1292:
#line 6454 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1293:
#line 6458 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1294:
#line 6462 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1295:
#line 6468 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1296:
#line 6471 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1297:
#line 6480 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1298:
#line 6483 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1299:
#line 6486 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1300:
#line 6489 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1301:
#line 6492 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1302:
#line 6495 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1303:
#line 6498 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1304:
#line 6505 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1305:
#line 6508 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1306:
#line 6515 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1307:
#line 6518 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1308:
#line 6524 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1309:
#line 6527 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1310:
#line 6534 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1311:
#line 6537 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1313:
#line 6545 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1315:
#line 6554 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1316:
#line 6557 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1317:
#line 6563 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1318:
#line 6566 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1319:
#line 6572 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1320:
#line 6579 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1321:
#line 6580 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1322:
#line 6584 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1323:
#line 6594 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1324:
#line 6597 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1325:
#line 6603 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1326:
#line 6605 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1327:
#line 6610 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1328:
#line 6611 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1329:
#line 6616 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1330:
#line 6617 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1331:
#line 6623 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1332:
#line 6624 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1336:
#line 6651 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6657 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1343:
#line 6660 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1344:
#line 6663 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1345:
#line 6669 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1347:
#line 6675 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1349:
#line 6686 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1350:
#line 6700 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1351:
#line 6709 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1352:
#line 6709 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1353:
#line 6714 "fgl.yacc"
    {insql=1;}
    break;

  case 1354:
#line 6714 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1355:
#line 6719 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1356:
#line 6722 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1357:
#line 6724 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1359:
#line 6731 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1360:
#line 6735 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1361:
#line 6739 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1362:
#line 6746 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1363:
#line 6749 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1364:
#line 6756 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1365:
#line 6760 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1366:
#line 6766 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1367:
#line 6771 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1368:
#line 6775 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1369:
#line 6781 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1370:
#line 6784 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1371:
#line 6790 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1372:
#line 6797 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1373:
#line 6801 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1374:
#line 6806 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1375:
#line 6816 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1376:
#line 6819 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1377:
#line 6821 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1378:
#line 6823 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1379:
#line 6825 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1380:
#line 6827 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1381:
#line 6829 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1382:
#line 6831 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1383:
#line 6837 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1384:
#line 6847 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1385:
#line 6854 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6860 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6863 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1391:
#line 6870 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1394:
#line 6875 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1395:
#line 6880 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1396:
#line 6887 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1397:
#line 6888 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1398:
#line 6895 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1399:
#line 6906 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1400:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1402:
#line 6911 "fgl.yacc"
    {insql=1;}
    break;

  case 1403:
#line 6911 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1404:
#line 6916 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1405:
#line 6921 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1407:
#line 6927 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1409:
#line 6931 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1410:
#line 6936 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1411:
#line 6941 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1412:
#line 6945 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1414:
#line 6951 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1415:
#line 6955 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1416:
#line 6962 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1417:
#line 6963 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6964 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6965 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6975 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1424:
#line 6976 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1425:
#line 6977 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1427:
#line 6982 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1430:
#line 6989 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1431:
#line 6992 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1434:
#line 6995 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 7000 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1438:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 7008 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7014 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7024 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1446:
#line 7029 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1447:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1449:
#line 7037 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 7040 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1452:
#line 7046 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1453:
#line 7054 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 7059 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1457:
#line 7069 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 7075 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 7080 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1461:
#line 7081 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 7083 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 7089 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7094 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1466:
#line 7097 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1467:
#line 7100 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1468:
#line 7107 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7108 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1470:
#line 7109 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1471:
#line 7111 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1472:
#line 7124 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1473:
#line 7129 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7133 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1476:
#line 7135 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1477:
#line 7142 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1478:
#line 7145 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1479:
#line 7151 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1480:
#line 7159 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1481:
#line 7163 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1482:
#line 7167 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1483:
#line 7171 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1484:
#line 7175 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1485:
#line 7178 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1486:
#line 7181 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1487:
#line 7189 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1488:
#line 7196 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1491:
#line 7205 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1492:
#line 7211 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1493:
#line 7214 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1494:
#line 7225 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1495:
#line 7232 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1496:
#line 7238 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7241 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1498:
#line 7248 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1499:
#line 7255 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1501:
#line 7262 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1502:
#line 7268 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1503:
#line 7269 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1504:
#line 7270 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1506:
#line 7274 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7279 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1509:
#line 7286 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1510:
#line 7291 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1511:
#line 7292 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1512:
#line 7295 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1513:
#line 7298 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1514:
#line 7303 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1515:
#line 7304 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1516:
#line 7309 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1517:
#line 7312 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7318 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1519:
#line 7321 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1520:
#line 7327 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1521:
#line 7330 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1522:
#line 7336 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1523:
#line 7339 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1524:
#line 7346 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1525:
#line 7347 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1526:
#line 7376 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1527:
#line 7378 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1528:
#line 7382 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1530:
#line 7395 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1531:
#line 7398 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1532:
#line 7401 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1533:
#line 7404 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1535:
#line 7412 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1536:
#line 7415 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1538:
#line 7421 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1540:
#line 7427 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1541:
#line 7430 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1542:
#line 7433 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1543:
#line 7436 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1544:
#line 7439 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1545:
#line 7442 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1546:
#line 7445 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1547:
#line 7448 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1548:
#line 7453 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1550:
#line 7460 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1556:
#line 7468 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1557:
#line 7469 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1558:
#line 7474 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1559:
#line 7477 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1560:
#line 7481 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1561:
#line 7487 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1562:
#line 7488 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1563:
#line 7489 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1564:
#line 7490 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1569:
#line 7510 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1571:
#line 7514 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1572:
#line 7515 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1574:
#line 7518 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1575:
#line 7520 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7529 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1584:
#line 7531 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1585:
#line 7533 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1587:
#line 7536 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1589:
#line 7539 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1593:
#line 7544 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1594:
#line 7546 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1595:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1596:
#line 7550 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1597:
#line 7557 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1601:
#line 7562 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1605:
#line 7578 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1606:
#line 7585 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1607:
#line 7589 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1608:
#line 7590 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1609:
#line 7591 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1610:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1611:
#line 7600 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1612:
#line 7601 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1613:
#line 7612 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1614:
#line 7619 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1615:
#line 7624 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1616:
#line 7625 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1617:
#line 7626 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1618:
#line 7634 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1619:
#line 7635 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1620:
#line 7636 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1622:
#line 7662 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1623:
#line 7663 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1624:
#line 7664 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1625:
#line 7668 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1626:
#line 7671 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1627:
#line 7677 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1628:
#line 7682 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1629:
#line 7687 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1631:
#line 7698 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1635:
#line 7716 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1636:
#line 7719 "fgl.yacc"
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

  case 1637:
#line 7732 "fgl.yacc"
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

  case 1638:
#line 7747 "fgl.yacc"
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

  case 1639:
#line 7759 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1640:
#line 7761 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1641:
#line 7764 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1642:
#line 7764 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1643:
#line 7764 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1644:
#line 7764 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1645:
#line 7764 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1646:
#line 7764 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1647:
#line 7765 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1648:
#line 7768 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1649:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1650:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1651:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1652:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1653:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1654:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1655:
#line 7775 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1656:
#line 7778 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1671:
#line 7785 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1672:
#line 7788 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1673:
#line 7789 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1674:
#line 7790 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1675:
#line 7794 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1676:
#line 7802 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1677:
#line 7802 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1678:
#line 7808 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1679:
#line 7808 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1680:
#line 7815 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1681:
#line 7815 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1682:
#line 7821 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1683:
#line 7821 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1684:
#line 7829 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1685:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1686:
#line 7831 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1687:
#line 7834 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1688:
#line 7834 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1690:
#line 7838 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1691:
#line 7839 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1692:
#line 7850 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1693:
#line 7853 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1694:
#line 7859 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1695:
#line 7864 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1696:
#line 7872 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1697:
#line 7884 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1698:
#line 7885 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1699:
#line 7888 "fgl.yacc"
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

  case 1700:
#line 7903 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1701:
#line 7914 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1702:
#line 7917 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1703:
#line 7925 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1704:
#line 7934 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1705:
#line 7937 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1706:
#line 7941 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1707:
#line 7944 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1708:
#line 7945 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1710:
#line 7954 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1711:
#line 7955 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1712:
#line 7964 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1713:
#line 7973 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1714:
#line 7978 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1715:
#line 7979 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1716:
#line 7980 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1717:
#line 7981 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1718:
#line 7988 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1719:
#line 7991 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1720:
#line 7997 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1721:
#line 8000 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1722:
#line 8010 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1723:
#line 8019 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1724:
#line 8022 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1725:
#line 8025 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1726:
#line 8031 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1727:
#line 8037 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1728:
#line 8040 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1729:
#line 8041 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1730:
#line 8042 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1731:
#line 8043 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1732:
#line 8044 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1733:
#line 8047 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1734:
#line 8054 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1735:
#line 8056 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1736:
#line 8058 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1737:
#line 8060 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1738:
#line 8062 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1739:
#line 8063 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1740:
#line 8064 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1741:
#line 8065 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1742:
#line 8066 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1743:
#line 8067 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1744:
#line 8068 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1745:
#line 8070 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1746:
#line 8072 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1747:
#line 8074 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1748:
#line 8076 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1749:
#line 8078 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1750:
#line 8080 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1751:
#line 8082 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1752:
#line 8083 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1753:
#line 8085 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1754:
#line 8089 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1755:
#line 8090 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1757:
#line 8100 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1758:
#line 8109 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1759:
#line 8113 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1760:
#line 8120 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1761:
#line 8120 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1763:
#line 8124 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1764:
#line 8129 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1765:
#line 8129 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1767:
#line 8133 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1768:
#line 8137 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1771:
#line 8146 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1772:
#line 8146 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1777:
#line 8165 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1778:
#line 8166 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1781:
#line 8174 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1782:
#line 8180 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1785:
#line 8199 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1786:
#line 8200 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1787:
#line 8201 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1788:
#line 8202 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1789:
#line 8203 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1790:
#line 8204 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1791:
#line 8208 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1792:
#line 8209 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1793:
#line 8210 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1794:
#line 8214 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1795:
#line 8218 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1797:
#line 8227 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1799:
#line 8232 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1800:
#line 8233 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2117:
#line 8558 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2118:
#line 8558 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2119:
#line 8565 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2120:
#line 8565 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2121:
#line 8653 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2122:
#line 8657 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2123:
#line 8659 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2124:
#line 8666 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2125:
#line 8670 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2126:
#line 8676 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2127:
#line 8684 "fgl.yacc"
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

  case 2128:
#line 8694 "fgl.yacc"
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

  case 2129:
#line 8704 "fgl.yacc"
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

  case 2130:
#line 8716 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2131:
#line 8719 "fgl.yacc"
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

  case 2132:
#line 8738 "fgl.yacc"
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

  case 2133:
#line 8764 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2134:
#line 8767 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2136:
#line 8776 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2137:
#line 8781 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2138:
#line 8784 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2139:
#line 8792 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2140:
#line 8800 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2141:
#line 8813 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2142:
#line 8816 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2143:
#line 8824 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2144:
#line 8827 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2145:
#line 8830 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2146:
#line 8838 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2147:
#line 8842 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2148:
#line 8845 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2149:
#line 8848 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2150:
#line 8851 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2151:
#line 8855 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2152:
#line 8856 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2153:
#line 8857 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2154:
#line 8858 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2155:
#line 8859 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2156:
#line 8865 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2157:
#line 8866 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2158:
#line 8867 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2159:
#line 8868 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2160:
#line 8869 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2161:
#line 8870 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2162:
#line 8871 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2163:
#line 8872 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2164:
#line 8873 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2165:
#line 8874 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2166:
#line 8875 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2167:
#line 8876 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2168:
#line 8877 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2169:
#line 8878 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2170:
#line 8882 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2171:
#line 8888 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2172:
#line 8889 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2173:
#line 8897 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2174:
#line 8899 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2176:
#line 8905 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2177:
#line 8909 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2178:
#line 8913 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2179:
#line 8929 "fgl.yacc"
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

  case 2180:
#line 8948 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2181:
#line 8950 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2182:
#line 8956 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2183:
#line 8957 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2184:
#line 8958 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2185:
#line 8959 "fgl.yacc"
    {
		if (A4GL_escape_quote_owner()) {
			sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		}
	}
    break;

  case 2189:
#line 8977 "fgl.yacc"
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

  case 2190:
#line 9003 "fgl.yacc"
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

  case 2191:
#line 9058 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2192:
#line 9072 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2193:
#line 9075 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2194:
#line 9079 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2195:
#line 9094 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2196:
#line 9094 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2197:
#line 9100 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2198:
#line 9101 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2199:
#line 9104 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2200:
#line 9105 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2201:
#line 9106 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2202:
#line 9107 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2203:
#line 9108 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2204:
#line 9109 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2205:
#line 9110 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2206:
#line 9121 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2207:
#line 9125 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2208:
#line 9129 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2209:
#line 9133 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2210:
#line 9138 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2211:
#line 9142 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2212:
#line 9147 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2214:
#line 9155 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2216:
#line 9161 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2217:
#line 9167 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2218:
#line 9171 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2223:
#line 9189 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2224:
#line 9196 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2225:
#line 9206 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2226:
#line 9206 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18809 "y.tab.c"

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


#line 9305 "fgl.yacc"

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



