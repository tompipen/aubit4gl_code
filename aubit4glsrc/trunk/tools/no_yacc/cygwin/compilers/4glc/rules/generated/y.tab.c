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
     NAME = 1716,
     UMINUS = 1717,
     COMMA = 1619,
     KW_OR = 1659,
     KW_AND = 1614,
     KW_USING = 1551,
     NOT = 1634,
     MATCHES = 1431,
     POWER = 1537,
     LESS_THAN = 1533,
     GREATER_THAN = 1448,
     EQUAL = 1609,
     GREATER_THAN_EQ = 1350,
     LESS_THAN_EQ = 1407,
     NOT_EQUAL = 1479,
     PLUS = 1645,
     MINUS = 1632,
     MULTIPLY = 1538,
     DIVIDE = 1565,
     MOD = 1633,
     COMMAND = 1414,
     NUMBER_VALUE = 1718,
     CHAR_VALUE = 1719,
     INT_VALUE = 1720,
     NAMED_GEN = 1721,
     CLINE = 1722,
     SQLLINE = 1723,
     KW_CSTART = 1724,
     KW_CEND = 1725,
     USER_DTYPE = 1726,
     SQL_TEXT = 1727,
     KW_WHENEVER_SET = 1728,
     COMMENT = 1729,
     MEMBER_FUNCTION = 1000,
     DATETIME_VALUE = 1001,
     INTERVAL_VALUE = 1002,
     FGL_SIZEOF = 1003,
     IMPORT_PACKAGE = 1004,
     DYNAMIC_ARRAY = 1005,
     RESIZE_ARRAY = 1006,
     ALLOCATE_ARRAY = 1007,
     DEALLOCATE_ARRAY = 1008,
     AFTER_INSERT_DELETE = 1009,
     BEFORE_INSERT_DELETE = 1010,
     BEFORE_INSERT = 1011,
     AS_CONVERTABLE = 1012,
     CONCAT_PIPES = 1013,
     BEFORE_DELETE = 1014,
     DROP_TRIGGER = 1015,
     AFTER_INSERT = 1016,
     AFTER_DELETE = 1017,
     EXECUTE_IMMEDIATE = 1018,
     DELETE_ROW_EQUAL_TRUE = 1019,
     INSERT_ROW_EQUAL_TRUE = 1020,
     DELETE_ROW_EQUAL_FALSE = 1021,
     INSERT_ROW_EQUAL_FALSE = 1022,
     CURRENT_ROW_DISPLAY_EQUAL = 1023,
     MAXCOUNT = 1024,
     ALTER_TABLE = 1025,
     ALTER_INDEX = 1026,
     NEXT_SIZE = 1027,
     DISPLAY_ATTR_FORM = 1028,
     DISPLAY_ATTR_WINDOW = 1029,
     INPUT_ATTR_FORM = 1030,
     INPUT_ATTR_WINDOW = 1031,
     WHENEVER_ERROR_CONTINUE = 1032,
     WHENEVER_ANY_ERROR_CONTINUE = 1033,
     WHENEVER_WARNING_CONTINUE = 1034,
     WHENEVER_SQLSUCCESS_CONTINUE = 1035,
     WHENEVER_SQLWARNING_CONTINUE = 1036,
     WHENEVER_NOT_FOUND_CONTINUE = 1037,
     WHENEVER_SQLERROR_CONTINUE = 1038,
     WHENEVER_SUCCESS_CONTINUE = 1039,
     WHENEVER_ERROR_GOTO = 1040,
     WHENEVER_ANY_ERROR_GOTO = 1041,
     WHENEVER_WARNING_GOTO = 1042,
     WHENEVER_SQLSUCCESS_GOTO = 1043,
     WHENEVER_SQLWARNING_GOTO = 1044,
     WHENEVER_NOT_FOUND_GOTO = 1045,
     WHENEVER_SQLERROR_GOTO = 1046,
     WHENEVER_SUCCESS_GOTO = 1047,
     WHENEVER_ERROR_CALL = 1048,
     WHENEVER_ANY_ERROR_CALL = 1049,
     WHENEVER_WARNING_CALL = 1050,
     WHENEVER_SQLSUCCESS_CALL = 1051,
     WHENEVER_SQLWARNING_CALL = 1052,
     WHENEVER_NOT_FOUND_CALL = 1053,
     WHENEVER_SQLERROR_CALL = 1054,
     WHENEVER_SUCCESS_CALL = 1055,
     WHENEVER_ERROR_STOP = 1056,
     WHENEVER_ANY_ERROR_STOP = 1057,
     WHENEVER_WARNING_STOP = 1058,
     WHENEVER_SQLSUCCESS_STOP = 1059,
     WHENEVER_SQLWARNING_STOP = 1060,
     WHENEVER_NOT_FOUND_STOP = 1061,
     WHENEVER_SQLERROR_STOP = 1062,
     WHENEVER_SUCCESS_STOP = 1063,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1064,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1065,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1066,
     XSET_MULTIPLY_EQUAL = 1067,
     XSET_OPEN_BRACKET = 1068,
     NEWFORMATSHARED = 1069,
     CREATE_DATABASE = 1070,
     DROP_DATABASE = 1071,
     IMPORT_LEGACY_FUNCTION = 1072,
     ADD_CONSTRAINT = 1073,
     DROP_CONSTRAINT = 1074,
     DROP_SYNONYM = 1075,
     CONSTRAINT = 1076,
     AS_STATIC = 1077,
     NOT_FIELD_TOUCHED = 1078,
     LOCAL_FUNCTION = 1079,
     EVERY_ROW = 1080,
     ELIF = 1081,
     DOUBLE_PRECISION = 1082,
     COUNT_MULTIPLY = 1083,
     WAIT_FOR_KEY = 1084,
     AT_TERMINATION_CALL = 1085,
     TERMINATE_REPORT = 1086,
     TO_MAIN_CAPTION = 1087,
     CLEARSTAT = 1088,
     TO_MENUITEM = 1089,
     ID_TO_INT = 1090,
     TO_STATUSBOX = 1091,
     ASCII_HEIGHT_ALL = 1092,
     ASCII_WIDTH_ALL = 1093,
     IMPORT_DATATYPE = 1094,
     PAGE_TRAILER_SIZE = 1095,
     PAGE_HEADER_SIZE = 1096,
     FIRST_PAGE_HEADER_SIZE = 1097,
     BYTES_USE_AS_IMAGE = 1098,
     BYTES_USE_AS_ASCII = 1099,
     KWUP_BY = 1100,
     KWDOWN_BY = 1101,
     CLOSE_STATUSBOX = 1102,
     MODIFY_NEXT_SIZE = 1103,
     LOCK_MODE_PAGE = 1104,
     LOCK_MODE_ROW = 1105,
     TO_PIPE = 1106,
     TO_PRINTER = 1107,
     STATUSBOX = 1108,
     FORMHANDLER_INPUT = 1109,
     UNITS_YEAR = 1110,
     UNITS_MONTH = 1111,
     UNITS_DAY = 1112,
     UNITS_HOUR = 1113,
     UNITS_MINUTE = 1114,
     UNITS_SECOND = 1115,
     NO_NEW_LINES = 1116,
     FIELDTOWIDGET = 1117,
     WITH_HOLD = 1118,
     SHOW_MENU = 1119,
     TO_CLUSTER = 1120,
     TO_NOT_CLUSTER = 1121,
     CWIS = 1122,
     CREATE_IDX = 1123,
     FORM_IS_COMPILED = 1124,
     PDF_REPORT = 1125,
     IMPORT_FUNCTION = 1126,
     PROMPT_MANY = 1127,
     POINTS = 1128,
     MM = 1129,
     INCHES = 1130,
     PREPEND = 1131,
     MEMBER_OF = 1132,
     APPEND = 1133,
     TEMPLATE = 1134,
     END_TEMPLATE = 1135,
     SQLSICS = 1136,
     CREATE_SCHEMA = 1137,
     SQLSIRR = 1138,
     UPDATESTATS_T = 1139,
     SQLSICR = 1140,
     WHENEVER_SQLSUCCESS = 1141,
     WHENEVER_SQLWARNING = 1142,
     WHENEVER_ANY_ERROR = 1143,
     WHENEVER_NOT_FOUND = 1144,
     WHENEVER_SQLERROR = 1145,
     WHENEVER_SUCCESS = 1146,
     WHENEVER_ERROR = 1147,
     START_EXTERN = 1148,
     CONTINUE_CONSTRUCT = 1149,
     FOUNCONSTR = 1150,
     SQLSIDR = 1151,
     CREATE_TEMP_TABLE = 1152,
     CURRENT_WINDOW_IS = 1153,
     FIRST_PAGE_HEADER = 1154,
     ORDER_EXTERNAL_BY = 1155,
     SCROLL_CURSOR_FOR = 1156,
     SCROLL_CURSOR = 1157,
     SQL_INTERRUPT_OFF = 1158,
     STOP_ALL_EXTERNAL = 1159,
     WITH_CHECK_OPTION = 1160,
     WITH_GRANT_OPTION = 1161,
     SQLSLMNW = 1162,
     ADDCONSTUNIQ = 1163,
     CONTINUE_DISPLAY = 1164,
     CONTINUE_FOREACH = 1165,
     OUTPUT_TO_REPORT = 1166,
     SQL_INTERRUPT_ON = 1167,
     WHERE_CURRENT_OF = 1168,
     WITHOUT_DEFAULTS = 1169,
     FOCONSTR = 1170,
     SCALED_BY = 1171,
     CONTINUE_PROMPT = 1172,
     PDF_FUNCTION = 1173,
     DEFER_INTERRUPT = 1174,
     DISPLAY_BY_NAME = 1175,
     NOT_NULL_UNIQUE = 1176,
     SKIP_TO_TOP = 1177,
     TOP_OF_PAGE = 1178,
     SKIP_TO = 1179,
     SKIP_BY = 1180,
     WITHOUT_WAITING = 1181,
     BEFCONSTRUCT = 1182,
     SQLSLMW = 1183,
     AFTCONSTRUCT = 1184,
     ALL_PRIVILEGES = 1185,
     CLOSE_DATABASE = 1186,
     CONTINUE_INPUT = 1187,
     CONTINUE_WHILE = 1188,
     CREATE_SYNONYM = 1189,
     DROP_TABLE = 1190,
     EXIT_CONSTRUCT = 1191,
     INEXCLUSIVE = 1192,
     REPORT_TO_PRINTER = 1193,
     REPORT_TO_PIPE = 1194,
     RETURN = 1195,
     SET_SESSION_TO = 1196,
     UPDATESTATS = 1197,
     WITHOUT_HEAD = 1198,
     CLEARSCR = 1199,
     WITH_B_LOG = 1200,
     AUTHORIZATION = 1201,
     BOTTOM_MARGIN = 1202,
     CLOSE_SESSION = 1203,
     CONTINUE_CASE = 1204,
     CONTINUE_MENU = 1205,
     DISPLAY_ARRAY = 1206,
     END_SQL = 1207,
     DOLLAR = 1208,
     END_CONSTRUCT = 1209,
     FIELD_TOUCHED = 1210,
     FINISH_REPORT = 1211,
     INFACC = 1212,
     INPUT_NO_WRAP = 1213,
     SETPMOFF = 1214,
     UNCONSTRAINED = 1215,
     PAGE_TRAILER = 1216,
     SETPMON = 1217,
     BEFGROUP = 1218,
     CLOSE_WINDOW = 1219,
     COMMENT_LINE = 1220,
     CONTINUE_FOR = 1221,
     CREATE_DB = 1222,
     CREATE_TABLE = 1223,
     DEFAULT_NULL = 1224,
     DEFAULT_TODAY = 1225,
     DEFAULT_USER = 1226,
     DELETE_USING = 1227,
     DISPLAY_FORM = 1228,
     END_FUNCTION = 1229,
     EXIT_DISPLAY = 1230,
     EXIT_FOREACH = 1231,
     EXIT_PROGRAM = 1232,
     INFCOLS = 1233,
     ON_EVERY_ROW = 1234,
     OPEN_SESSION = 1235,
     RIGHT_MARGIN = 1236,
     SELECT_USING = 1237,
     START_REPORT = 1238,
     UNLOCK_TABLE = 1239,
     UPDATE_USING = 1240,
     ACL_BUILTIN = 1241,
     AFTGROUP = 1242,
     INFIDX = 1243,
     INFSTAT = 1244,
     LEFT_MARGIN = 1245,
     PAGE_HEADER = 1246,
     ROLLBACK_W = 1247,
     SET_SESSION = 1248,
     SQLSEOFF = 1249,
     WITH_A_LOG = 1250,
     BEFDISP = 1251,
     BEFORE_MENU = 1252,
     CREATE_VIEW = 1253,
     DEFINE_TYPE = 1254,
     DELETE_FROM = 1255,
     END_DISPLAY = 1256,
     END_REPORT = 1257,
     END_FOREACH = 1258,
     END_FOR = 1259,
     END_GLOBALS = 1260,
     EXIT_PROMPT = 1261,
     EXTENT_SIZE = 1262,
     FOREIGN_KEY = 1263,
     HIDE_OPTION = 1264,
     HIDE_WINDOW = 1265,
     INSERT_INTO = 1266,
     IS_NOT_NULL = 1267,
     MOVE_WINDOW = 1268,
     NEXT_OPTION = 1269,
     NOT_MATCHES = 1270,
     ON_LAST_ROW = 1271,
     OPEN_WINDOW = 1272,
     OPEN_STATUSBOX = 1273,
     PAGE_LENGTH = 1274,
     PAGE_WIDTH = 1275,
     PRIMARY_KEY = 1276,
     PROMPT_LINE = 1277,
     RECORD_LIKE = 1278,
     ROLLFORWARD = 1279,
     SETBL = 1280,
     SHOW_OPTION = 1281,
     SHOW_WINDOW = 1282,
     SQLSEON = 1283,
     TO_DATABASE = 1284,
     USE_SESSION = 1285,
     WITH_NO_LOG = 1286,
     AFTDISP = 1287,
     BEFFIELD = 1288,
     INSHARE = 1289,
     UNLOCKTAB = 1290,
     AFTFIELD = 1291,
     ATTRIBUTES = 1292,
     BEFINP = 1293,
     BEGIN_WORK = 1294,
     CLEARWIN = 1295,
     CLOSE_FORM = 1296,
     DEFER_QUIT = 1297,
     DESCENDING = 1298,
     DROP_INDEX = 1299,
     END_PROMPT = 1300,
     END_RECORD = 1301,
     ERROR_LINE = 1302,
     EXIT_INPUT = 1303,
     EXIT_WHILE = 1304,
     FOR_UPDATE_OF = 1305,
     FOR_UPDATE = 1306,
     GET_FLDBUF = 1307,
     INITIALIZE = 1308,
     INPUT_WRAP = 1309,
     LOCK_TABLE = 1310,
     MSG_LINE = 1311,
     NOT_EXISTS = 1312,
     ON_ANY_KEY = 1313,
     REFERENCES = 1314,
     RENCOL = 1315,
     SET_CURSOR = 1316,
     SMALLFLOAT = 1317,
     SQLSUCCESS = 1318,
     TOP_MARGIN = 1319,
     WITH_ARRAY = 1320,
     ACCEPTKEY = 1321,
     ACCEPT = 1322,
     AFTINP = 1323,
     CLEARFORMTODEFAULTS = 1324,
     CLEARFORM = 1325,
     CLEAR_X_FORM = 1326,
     COMMIT_W = 1327,
     NEXTPAGE = 1328,
     PREVPAGE = 1329,
     CTRL_KEY = 1330,
     INFTABS = 1331,
     NEXTFIELD = 1332,
     NEXTFORM = 1333,
     RENTAB = 1334,
     ASCENDING = 1335,
     ASSOCIATE = 1336,
     CHAR = 1337,
     NCHAR = 1338,
     NVARCHAR = 1339,
     CONSTRUCT = 1340,
     DELIMITER = 1341,
     DOWNSHIFT = 1342,
     DROP_VIEW = 1343,
     END_INPUT = 1344,
     END_WHILE = 1345,
     EXCLUSIVE = 1346,
     EXIT_CASE = 1347,
     EXIT_MENU = 1348,
     FORM_LINE = 1349,
     INTERRUPT = 1351,
     INTO_TEMP = 1352,
     INVISIBLE = 1353,
     IN_MEMORY = 1354,
     LINKED_TO = 1355,
     LOAD_FROM = 1356,
     LOCKTAB = 1357,
     MENU_LINE = 1358,
     OPEN_FORM = 1359,
     OTHERWISE = 1360,
     PRECISION = 1361,
     PRIOR = 1362,
     PROCEDURE = 1363,
     REPORT_TO = 1364,
     RETURNING = 1365,
     UNDERLINE = 1366,
     UNLOAD_TO = 1367,
     BEFROW = 1368,
     UNLOAD_T = 1369,
     VARIABLE = 1370,
     ABSOLUTE = 1371,
     AFTROW = 1372,
     BUFFERED = 1373,
     CONSTANT = 1374,
     CONST = 1375,
     DATABASE = 1376,
     DATETIME = 1377,
     DEFAULTS = 1378,
     DISTINCT = 1379,
     END_CASE = 1380,
     END_MAIN = 1381,
     END_MENU = 1382,
     END_TYPE = 1383,
     EXIT_FOR = 1384,
     EXTERNAL = 1385,
     FRACTION = 1386,
     FUNCTION = 1387,
     GROUP_BY = 1388,
     INTERVAL = 1389,
     KWMESSAGE = 1390,
     NOT_LIKE = 1391,
     NOT_ILIKE = 1392,
     NOT_NULL = 1393,
     PASSWORD = 1394,
     PREVIOUS = 1395,
     READONLY = 1396,
     REGISTER = 1397,
     RELATIVE = 1398,
     RESOURCE = 1399,
     SMALLINT = 1400,
     VALIDATE = 1401,
     WITH_LOG = 1402,
     WORDWRAP = 1403,
     BY_NAME = 1404,
     IN_FILE = 1405,
     IS_NULL = 1406,
     AVERAGE = 1408,
     BETWEEN = 1409,
     CAPTION = 1410,
     CLIPPED = 1411,
     CLOSE_BRACKET = 1412,
     COLUMNS = 1413,
     CONNECT = 1415,
     CURRENT = 1416,
     DBYNAME = 1417,
     DECIMAL = 1418,
     DECLARE = 1419,
     DEFAULT = 1420,
     DISPLAY = 1421,
     ENDCODE = 1422,
     EXECUTE = 1423,
     FOREACH = 1424,
     FOREIGN = 1425,
     GLOBALS = 1426,
     INFIELD = 1427,
     INTEGER = 1428,
     KWWINDOW = 1429,
     MAGENTA = 1430,
     OPTIONS = 1432,
     PERCENT = 1433,
     PREPARE = 1434,
     PROGRAM = 1435,
     RECOVER = 1436,
     REVERSE = 1437,
     SECTION = 1438,
     SESSION = 1439,
     SYNONYM = 1440,
     THRU = 1441,
     TRAILER = 1442,
     UPSHIFT = 1443,
     VARCHAR = 1444,
     WAITING = 1445,
     CLOSE_SHEV = 1446,
     CLOSE_SQUARE = 1447,
     KW_FALSE = 1449,
     NOT_IN = 1450,
     ONKEY = 1451,
     OPEN_BRACKET = 1452,
     BORDER = 1453,
     BOTTOM = 1454,
     COLUMN = 1455,
     COMMIT = 1456,
     CREATE = 1457,
     CURSOR = 1458,
     DEFINE = 1459,
     DELETE = 1460,
     DOUBLE = 1461,
     END_IF = 1462,
     ESCAPE = 1463,
     EXISTS = 1464,
     EXTEND = 1465,
     EXTENT = 1466,
     FINISH = 1467,
     FORMAT = 1468,
     HAVING = 1469,
     HEADER = 1470,
     INSERT = 1471,
     LOCATE = 1472,
     MARGIN = 1473,
     MEMORY = 1474,
     MINUTE = 1475,
     MODIFY = 1476,
     NORMAL = 1477,
     EQUAL_EQUAL = 1478,
     OPEN_SHEV = 1480,
     OPEN_SQUARE = 1481,
     OPTION = 1482,
     OUTPUT = 1483,
     PROMPT = 1484,
     PUBLIC = 1485,
     RECORD = 1486,
     REPORT = 1487,
     REVOKE = 1488,
     SCHEMA = 1489,
     SCROLL_USING = 1490,
     SCROLL = 1491,
     SECOND = 1492,
     SELECT = 1493,
     SERIAL = 1494,
     SETL = 1495,
     SHARED = 1496,
     SPACES = 1497,
     UNIQUE = 1498,
     UNLOCK = 1499,
     UPDATE = 1500,
     VALUES = 1501,
     YELLOW = 1502,
     AFTER = 1503,
     KWLINE = 1504,
     KW_NULL = 1505,
     KW_TRUE = 1506,
     SINGLE_KEY = 1507,
     ALTER = 1508,
     ARRAY = 1509,
     ASCII = 1510,
     AUDIT = 1511,
     BLACK = 1512,
     BLINK = 1513,
     CHECK = 1514,
     CLEAR = 1515,
     CLOSE = 1516,
     CODE_C = 1517,
     COUNT = 1518,
     DEFER = 1519,
     ERROR = 1520,
     EVERY = 1521,
     FETCH = 1522,
     FIRST = 1523,
     FLOAT = 1524,
     FLUSH = 1525,
     FOUND = 1526,
     GRANT = 1527,
     GREEN = 1528,
     GROUP = 1529,
     INDEX = 1530,
     KWFORM = 1531,
     LABEL = 1532,
     LOCAL = 1534,
     MONEY = 1535,
     MONTH = 1536,
     ORDER = 1539,
     OUTER = 1540,
     PAUSE = 1541,
     PRINT_IMAGE = 1542,
     PRINT_FILE = 1543,
     PRINT = 1544,
     RIGHT = 1545,
     DOUBLE_COLON = 1546,
     SEMICOLON = 1547,
     SLEEP = 1548,
     TUPLE = 1549,
     UNION = 1550,
     WHERE = 1552,
     WHILE = 1553,
     WHITE = 1554,
     CCODE = 1555,
     ANSI = 1556,
     BLUE = 1557,
     BOLD = 1558,
     BYTE = 1559,
     FCALL = 1560,
     CASE = 1561,
     CYAN = 1562,
     DATE = 1563,
     DESC = 1564,
     KWDOWN = 1566,
     TAB = 1567,
     DROP = 1568,
     ELSE = 1569,
     EXEC = 1570,
     EXIT = 1571,
     FREE = 1572,
     FROM = 1573,
     GOTO = 1574,
     HELP_FILE = 1575,
     LANG_FILE = 1576,
     HELP = 1577,
     HIDE = 1578,
     HOUR = 1579,
     INTO = 1580,
     LAST = 1581,
     LEFT = 1582,
     LIKE = 1583,
     MAIN = 1584,
     MENU = 1585,
     MODE = 1586,
     NEED = 1587,
     NEXT = 1588,
     NOCR = 1589,
     OPEN = 1590,
     QUIT = 1591,
     REAL = 1592,
     ROWS = 1593,
     SHOW = 1594,
     SIZE = 1595,
     SKIP = 1596,
     SOME = 1597,
     STEP = 1598,
     STOP = 1599,
     TEMP = 1600,
     TEXT = 1601,
     THEN = 1602,
     USER = 1603,
     WAIT = 1604,
     WHEN = 1605,
     WITH = 1606,
     WORK = 1607,
     YEAR = 1608,
     KW_IS = 1610,
     XSET = 1611,
     ADD = 1612,
     ALL = 1613,
     ANY = 1615,
     ASC = 1616,
     AVG = 1617,
     COLON = 1618,
     DAY = 1620,
     DBA = 1621,
     DEC = 1622,
     DIM = 1623,
     FKEY = 1624,
     FOR = 1625,
     KEY = 1626,
     KWNO = 1627,
     LET = 1628,
     LOG = 1629,
     XMAX = 1630,
     XMIN = 1631,
     PAD = 1635,
     PUT = 1636,
     RED = 1637,
     ROW = 1638,
     RUN = 1639,
     SQL = 1640,
     SUM = 1641,
     TOP = 1642,
     USE = 1643,
     ATSIGN = 1644,
     AS_TIFF = 1646,
     AS_GIF = 1647,
     AS_PNG = 1648,
     AS_JPEG = 1649,
     AS = 1650,
     AT = 1651,
     BY = 1652,
     DOT = 1653,
     GO = 1654,
     IF = 1655,
     IN = 1656,
     OF = 1657,
     ON = 1658,
     TO = 1660,
     KWUP = 1661,
     FONT_NAME = 1662,
     FONT_SIZE = 1663,
     PAPER_SIZE_IS_LETTER = 1664,
     PAPER_SIZE_IS_LEGAL = 1665,
     PAPER_SIZE_IS_A5 = 1666,
     PAPER_SIZE_IS_A4 = 1667,
     PAPER_SIZE_IS_LETTER_L = 1668,
     PAPER_SIZE_IS_LEGAL_L = 1669,
     PAPER_SIZE_IS_A5_L = 1670,
     PAPER_SIZE_IS_A4_L = 1671,
     FORMHANDLER = 1672,
     END_FORMHANDLER = 1673,
     BEFORE_EVENT = 1674,
     BEFORE_OPEN_FORM = 1675,
     AFTER_EVENT = 1676,
     BEFORE_CLOSE_FORM = 1677,
     BEFORE_ANY = 1678,
     AFTER_ANY = 1679,
     MENUHANDLER = 1680,
     END_MENUHANDLER = 1681,
     BEFORE_SHOW_MENU = 1682,
     DISABLE_PROGRAM = 1683,
     DISABLE_ALL = 1684,
     BUTTONS = 1685,
     CHECK_MENUITEM = 1686,
     DISABLE_FORM = 1687,
     DISABLE_MENUITEMS = 1688,
     DISABLE = 1689,
     ENABLE_FORM = 1690,
     ENABLE_MENUITEMS = 1691,
     ENABLE = 1692,
     KWFIELD = 1693,
     ICON = 1694,
     MESSAGEBOX = 1695,
     TO_DEFAULTS = 1696,
     UNCHECK_MENUITEM = 1697,
     BEFORE = 1698,
     INPUT = 1699,
     END = 1700,
     INT_TO_ID = 1701,
     TIMEOUT = 1702,
     OFF = 1703,
     WITH_1_DIMENSION = 1704,
     WITH_2_DIMENSION = 1705,
     WITH_3_DIMENSION = 1706,
     TILDE = 1707,
     ILIKE = 1708,
     FGL_ISDYNARR_ALLOCATED = 1709,
     FGL_DYNARR_EXTENTSIZE = 1710,
     FILLFACTOR = 1711,
     END_CLASS = 1712,
     KW_CLASS = 1713,
     EXTENDS = 1714
   };
#endif
#define NAME 1716
#define UMINUS 1717
#define COMMA 1619
#define KW_OR 1659
#define KW_AND 1614
#define KW_USING 1551
#define NOT 1634
#define MATCHES 1431
#define POWER 1537
#define LESS_THAN 1533
#define GREATER_THAN 1448
#define EQUAL 1609
#define GREATER_THAN_EQ 1350
#define LESS_THAN_EQ 1407
#define NOT_EQUAL 1479
#define PLUS 1645
#define MINUS 1632
#define MULTIPLY 1538
#define DIVIDE 1565
#define MOD 1633
#define COMMAND 1414
#define NUMBER_VALUE 1718
#define CHAR_VALUE 1719
#define INT_VALUE 1720
#define NAMED_GEN 1721
#define CLINE 1722
#define SQLLINE 1723
#define KW_CSTART 1724
#define KW_CEND 1725
#define USER_DTYPE 1726
#define SQL_TEXT 1727
#define KW_WHENEVER_SET 1728
#define COMMENT 1729
#define MEMBER_FUNCTION 1000
#define DATETIME_VALUE 1001
#define INTERVAL_VALUE 1002
#define FGL_SIZEOF 1003
#define IMPORT_PACKAGE 1004
#define DYNAMIC_ARRAY 1005
#define RESIZE_ARRAY 1006
#define ALLOCATE_ARRAY 1007
#define DEALLOCATE_ARRAY 1008
#define AFTER_INSERT_DELETE 1009
#define BEFORE_INSERT_DELETE 1010
#define BEFORE_INSERT 1011
#define AS_CONVERTABLE 1012
#define CONCAT_PIPES 1013
#define BEFORE_DELETE 1014
#define DROP_TRIGGER 1015
#define AFTER_INSERT 1016
#define AFTER_DELETE 1017
#define EXECUTE_IMMEDIATE 1018
#define DELETE_ROW_EQUAL_TRUE 1019
#define INSERT_ROW_EQUAL_TRUE 1020
#define DELETE_ROW_EQUAL_FALSE 1021
#define INSERT_ROW_EQUAL_FALSE 1022
#define CURRENT_ROW_DISPLAY_EQUAL 1023
#define MAXCOUNT 1024
#define ALTER_TABLE 1025
#define ALTER_INDEX 1026
#define NEXT_SIZE 1027
#define DISPLAY_ATTR_FORM 1028
#define DISPLAY_ATTR_WINDOW 1029
#define INPUT_ATTR_FORM 1030
#define INPUT_ATTR_WINDOW 1031
#define WHENEVER_ERROR_CONTINUE 1032
#define WHENEVER_ANY_ERROR_CONTINUE 1033
#define WHENEVER_WARNING_CONTINUE 1034
#define WHENEVER_SQLSUCCESS_CONTINUE 1035
#define WHENEVER_SQLWARNING_CONTINUE 1036
#define WHENEVER_NOT_FOUND_CONTINUE 1037
#define WHENEVER_SQLERROR_CONTINUE 1038
#define WHENEVER_SUCCESS_CONTINUE 1039
#define WHENEVER_ERROR_GOTO 1040
#define WHENEVER_ANY_ERROR_GOTO 1041
#define WHENEVER_WARNING_GOTO 1042
#define WHENEVER_SQLSUCCESS_GOTO 1043
#define WHENEVER_SQLWARNING_GOTO 1044
#define WHENEVER_NOT_FOUND_GOTO 1045
#define WHENEVER_SQLERROR_GOTO 1046
#define WHENEVER_SUCCESS_GOTO 1047
#define WHENEVER_ERROR_CALL 1048
#define WHENEVER_ANY_ERROR_CALL 1049
#define WHENEVER_WARNING_CALL 1050
#define WHENEVER_SQLSUCCESS_CALL 1051
#define WHENEVER_SQLWARNING_CALL 1052
#define WHENEVER_NOT_FOUND_CALL 1053
#define WHENEVER_SQLERROR_CALL 1054
#define WHENEVER_SUCCESS_CALL 1055
#define WHENEVER_ERROR_STOP 1056
#define WHENEVER_ANY_ERROR_STOP 1057
#define WHENEVER_WARNING_STOP 1058
#define WHENEVER_SQLSUCCESS_STOP 1059
#define WHENEVER_SQLWARNING_STOP 1060
#define WHENEVER_NOT_FOUND_STOP 1061
#define WHENEVER_SQLERROR_STOP 1062
#define WHENEVER_SUCCESS_STOP 1063
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1064
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1065
#define XSET_ident_DOT_MULTIPLY_EQUAL 1066
#define XSET_MULTIPLY_EQUAL 1067
#define XSET_OPEN_BRACKET 1068
#define NEWFORMATSHARED 1069
#define CREATE_DATABASE 1070
#define DROP_DATABASE 1071
#define IMPORT_LEGACY_FUNCTION 1072
#define ADD_CONSTRAINT 1073
#define DROP_CONSTRAINT 1074
#define DROP_SYNONYM 1075
#define CONSTRAINT 1076
#define AS_STATIC 1077
#define NOT_FIELD_TOUCHED 1078
#define LOCAL_FUNCTION 1079
#define EVERY_ROW 1080
#define ELIF 1081
#define DOUBLE_PRECISION 1082
#define COUNT_MULTIPLY 1083
#define WAIT_FOR_KEY 1084
#define AT_TERMINATION_CALL 1085
#define TERMINATE_REPORT 1086
#define TO_MAIN_CAPTION 1087
#define CLEARSTAT 1088
#define TO_MENUITEM 1089
#define ID_TO_INT 1090
#define TO_STATUSBOX 1091
#define ASCII_HEIGHT_ALL 1092
#define ASCII_WIDTH_ALL 1093
#define IMPORT_DATATYPE 1094
#define PAGE_TRAILER_SIZE 1095
#define PAGE_HEADER_SIZE 1096
#define FIRST_PAGE_HEADER_SIZE 1097
#define BYTES_USE_AS_IMAGE 1098
#define BYTES_USE_AS_ASCII 1099
#define KWUP_BY 1100
#define KWDOWN_BY 1101
#define CLOSE_STATUSBOX 1102
#define MODIFY_NEXT_SIZE 1103
#define LOCK_MODE_PAGE 1104
#define LOCK_MODE_ROW 1105
#define TO_PIPE 1106
#define TO_PRINTER 1107
#define STATUSBOX 1108
#define FORMHANDLER_INPUT 1109
#define UNITS_YEAR 1110
#define UNITS_MONTH 1111
#define UNITS_DAY 1112
#define UNITS_HOUR 1113
#define UNITS_MINUTE 1114
#define UNITS_SECOND 1115
#define NO_NEW_LINES 1116
#define FIELDTOWIDGET 1117
#define WITH_HOLD 1118
#define SHOW_MENU 1119
#define TO_CLUSTER 1120
#define TO_NOT_CLUSTER 1121
#define CWIS 1122
#define CREATE_IDX 1123
#define FORM_IS_COMPILED 1124
#define PDF_REPORT 1125
#define IMPORT_FUNCTION 1126
#define PROMPT_MANY 1127
#define POINTS 1128
#define MM 1129
#define INCHES 1130
#define PREPEND 1131
#define MEMBER_OF 1132
#define APPEND 1133
#define TEMPLATE 1134
#define END_TEMPLATE 1135
#define SQLSICS 1136
#define CREATE_SCHEMA 1137
#define SQLSIRR 1138
#define UPDATESTATS_T 1139
#define SQLSICR 1140
#define WHENEVER_SQLSUCCESS 1141
#define WHENEVER_SQLWARNING 1142
#define WHENEVER_ANY_ERROR 1143
#define WHENEVER_NOT_FOUND 1144
#define WHENEVER_SQLERROR 1145
#define WHENEVER_SUCCESS 1146
#define WHENEVER_ERROR 1147
#define START_EXTERN 1148
#define CONTINUE_CONSTRUCT 1149
#define FOUNCONSTR 1150
#define SQLSIDR 1151
#define CREATE_TEMP_TABLE 1152
#define CURRENT_WINDOW_IS 1153
#define FIRST_PAGE_HEADER 1154
#define ORDER_EXTERNAL_BY 1155
#define SCROLL_CURSOR_FOR 1156
#define SCROLL_CURSOR 1157
#define SQL_INTERRUPT_OFF 1158
#define STOP_ALL_EXTERNAL 1159
#define WITH_CHECK_OPTION 1160
#define WITH_GRANT_OPTION 1161
#define SQLSLMNW 1162
#define ADDCONSTUNIQ 1163
#define CONTINUE_DISPLAY 1164
#define CONTINUE_FOREACH 1165
#define OUTPUT_TO_REPORT 1166
#define SQL_INTERRUPT_ON 1167
#define WHERE_CURRENT_OF 1168
#define WITHOUT_DEFAULTS 1169
#define FOCONSTR 1170
#define SCALED_BY 1171
#define CONTINUE_PROMPT 1172
#define PDF_FUNCTION 1173
#define DEFER_INTERRUPT 1174
#define DISPLAY_BY_NAME 1175
#define NOT_NULL_UNIQUE 1176
#define SKIP_TO_TOP 1177
#define TOP_OF_PAGE 1178
#define SKIP_TO 1179
#define SKIP_BY 1180
#define WITHOUT_WAITING 1181
#define BEFCONSTRUCT 1182
#define SQLSLMW 1183
#define AFTCONSTRUCT 1184
#define ALL_PRIVILEGES 1185
#define CLOSE_DATABASE 1186
#define CONTINUE_INPUT 1187
#define CONTINUE_WHILE 1188
#define CREATE_SYNONYM 1189
#define DROP_TABLE 1190
#define EXIT_CONSTRUCT 1191
#define INEXCLUSIVE 1192
#define REPORT_TO_PRINTER 1193
#define REPORT_TO_PIPE 1194
#define RETURN 1195
#define SET_SESSION_TO 1196
#define UPDATESTATS 1197
#define WITHOUT_HEAD 1198
#define CLEARSCR 1199
#define WITH_B_LOG 1200
#define AUTHORIZATION 1201
#define BOTTOM_MARGIN 1202
#define CLOSE_SESSION 1203
#define CONTINUE_CASE 1204
#define CONTINUE_MENU 1205
#define DISPLAY_ARRAY 1206
#define END_SQL 1207
#define DOLLAR 1208
#define END_CONSTRUCT 1209
#define FIELD_TOUCHED 1210
#define FINISH_REPORT 1211
#define INFACC 1212
#define INPUT_NO_WRAP 1213
#define SETPMOFF 1214
#define UNCONSTRAINED 1215
#define PAGE_TRAILER 1216
#define SETPMON 1217
#define BEFGROUP 1218
#define CLOSE_WINDOW 1219
#define COMMENT_LINE 1220
#define CONTINUE_FOR 1221
#define CREATE_DB 1222
#define CREATE_TABLE 1223
#define DEFAULT_NULL 1224
#define DEFAULT_TODAY 1225
#define DEFAULT_USER 1226
#define DELETE_USING 1227
#define DISPLAY_FORM 1228
#define END_FUNCTION 1229
#define EXIT_DISPLAY 1230
#define EXIT_FOREACH 1231
#define EXIT_PROGRAM 1232
#define INFCOLS 1233
#define ON_EVERY_ROW 1234
#define OPEN_SESSION 1235
#define RIGHT_MARGIN 1236
#define SELECT_USING 1237
#define START_REPORT 1238
#define UNLOCK_TABLE 1239
#define UPDATE_USING 1240
#define ACL_BUILTIN 1241
#define AFTGROUP 1242
#define INFIDX 1243
#define INFSTAT 1244
#define LEFT_MARGIN 1245
#define PAGE_HEADER 1246
#define ROLLBACK_W 1247
#define SET_SESSION 1248
#define SQLSEOFF 1249
#define WITH_A_LOG 1250
#define BEFDISP 1251
#define BEFORE_MENU 1252
#define CREATE_VIEW 1253
#define DEFINE_TYPE 1254
#define DELETE_FROM 1255
#define END_DISPLAY 1256
#define END_REPORT 1257
#define END_FOREACH 1258
#define END_FOR 1259
#define END_GLOBALS 1260
#define EXIT_PROMPT 1261
#define EXTENT_SIZE 1262
#define FOREIGN_KEY 1263
#define HIDE_OPTION 1264
#define HIDE_WINDOW 1265
#define INSERT_INTO 1266
#define IS_NOT_NULL 1267
#define MOVE_WINDOW 1268
#define NEXT_OPTION 1269
#define NOT_MATCHES 1270
#define ON_LAST_ROW 1271
#define OPEN_WINDOW 1272
#define OPEN_STATUSBOX 1273
#define PAGE_LENGTH 1274
#define PAGE_WIDTH 1275
#define PRIMARY_KEY 1276
#define PROMPT_LINE 1277
#define RECORD_LIKE 1278
#define ROLLFORWARD 1279
#define SETBL 1280
#define SHOW_OPTION 1281
#define SHOW_WINDOW 1282
#define SQLSEON 1283
#define TO_DATABASE 1284
#define USE_SESSION 1285
#define WITH_NO_LOG 1286
#define AFTDISP 1287
#define BEFFIELD 1288
#define INSHARE 1289
#define UNLOCKTAB 1290
#define AFTFIELD 1291
#define ATTRIBUTES 1292
#define BEFINP 1293
#define BEGIN_WORK 1294
#define CLEARWIN 1295
#define CLOSE_FORM 1296
#define DEFER_QUIT 1297
#define DESCENDING 1298
#define DROP_INDEX 1299
#define END_PROMPT 1300
#define END_RECORD 1301
#define ERROR_LINE 1302
#define EXIT_INPUT 1303
#define EXIT_WHILE 1304
#define FOR_UPDATE_OF 1305
#define FOR_UPDATE 1306
#define GET_FLDBUF 1307
#define INITIALIZE 1308
#define INPUT_WRAP 1309
#define LOCK_TABLE 1310
#define MSG_LINE 1311
#define NOT_EXISTS 1312
#define ON_ANY_KEY 1313
#define REFERENCES 1314
#define RENCOL 1315
#define SET_CURSOR 1316
#define SMALLFLOAT 1317
#define SQLSUCCESS 1318
#define TOP_MARGIN 1319
#define WITH_ARRAY 1320
#define ACCEPTKEY 1321
#define ACCEPT 1322
#define AFTINP 1323
#define CLEARFORMTODEFAULTS 1324
#define CLEARFORM 1325
#define CLEAR_X_FORM 1326
#define COMMIT_W 1327
#define NEXTPAGE 1328
#define PREVPAGE 1329
#define CTRL_KEY 1330
#define INFTABS 1331
#define NEXTFIELD 1332
#define NEXTFORM 1333
#define RENTAB 1334
#define ASCENDING 1335
#define ASSOCIATE 1336
#define CHAR 1337
#define NCHAR 1338
#define NVARCHAR 1339
#define CONSTRUCT 1340
#define DELIMITER 1341
#define DOWNSHIFT 1342
#define DROP_VIEW 1343
#define END_INPUT 1344
#define END_WHILE 1345
#define EXCLUSIVE 1346
#define EXIT_CASE 1347
#define EXIT_MENU 1348
#define FORM_LINE 1349
#define INTERRUPT 1351
#define INTO_TEMP 1352
#define INVISIBLE 1353
#define IN_MEMORY 1354
#define LINKED_TO 1355
#define LOAD_FROM 1356
#define LOCKTAB 1357
#define MENU_LINE 1358
#define OPEN_FORM 1359
#define OTHERWISE 1360
#define PRECISION 1361
#define PRIOR 1362
#define PROCEDURE 1363
#define REPORT_TO 1364
#define RETURNING 1365
#define UNDERLINE 1366
#define UNLOAD_TO 1367
#define BEFROW 1368
#define UNLOAD_T 1369
#define VARIABLE 1370
#define ABSOLUTE 1371
#define AFTROW 1372
#define BUFFERED 1373
#define CONSTANT 1374
#define CONST 1375
#define DATABASE 1376
#define DATETIME 1377
#define DEFAULTS 1378
#define DISTINCT 1379
#define END_CASE 1380
#define END_MAIN 1381
#define END_MENU 1382
#define END_TYPE 1383
#define EXIT_FOR 1384
#define EXTERNAL 1385
#define FRACTION 1386
#define FUNCTION 1387
#define GROUP_BY 1388
#define INTERVAL 1389
#define KWMESSAGE 1390
#define NOT_LIKE 1391
#define NOT_ILIKE 1392
#define NOT_NULL 1393
#define PASSWORD 1394
#define PREVIOUS 1395
#define READONLY 1396
#define REGISTER 1397
#define RELATIVE 1398
#define RESOURCE 1399
#define SMALLINT 1400
#define VALIDATE 1401
#define WITH_LOG 1402
#define WORDWRAP 1403
#define BY_NAME 1404
#define IN_FILE 1405
#define IS_NULL 1406
#define AVERAGE 1408
#define BETWEEN 1409
#define CAPTION 1410
#define CLIPPED 1411
#define CLOSE_BRACKET 1412
#define COLUMNS 1413
#define CONNECT 1415
#define CURRENT 1416
#define DBYNAME 1417
#define DECIMAL 1418
#define DECLARE 1419
#define DEFAULT 1420
#define DISPLAY 1421
#define ENDCODE 1422
#define EXECUTE 1423
#define FOREACH 1424
#define FOREIGN 1425
#define GLOBALS 1426
#define INFIELD 1427
#define INTEGER 1428
#define KWWINDOW 1429
#define MAGENTA 1430
#define OPTIONS 1432
#define PERCENT 1433
#define PREPARE 1434
#define PROGRAM 1435
#define RECOVER 1436
#define REVERSE 1437
#define SECTION 1438
#define SESSION 1439
#define SYNONYM 1440
#define THRU 1441
#define TRAILER 1442
#define UPSHIFT 1443
#define VARCHAR 1444
#define WAITING 1445
#define CLOSE_SHEV 1446
#define CLOSE_SQUARE 1447
#define KW_FALSE 1449
#define NOT_IN 1450
#define ONKEY 1451
#define OPEN_BRACKET 1452
#define BORDER 1453
#define BOTTOM 1454
#define COLUMN 1455
#define COMMIT 1456
#define CREATE 1457
#define CURSOR 1458
#define DEFINE 1459
#define DELETE 1460
#define DOUBLE 1461
#define END_IF 1462
#define ESCAPE 1463
#define EXISTS 1464
#define EXTEND 1465
#define EXTENT 1466
#define FINISH 1467
#define FORMAT 1468
#define HAVING 1469
#define HEADER 1470
#define INSERT 1471
#define LOCATE 1472
#define MARGIN 1473
#define MEMORY 1474
#define MINUTE 1475
#define MODIFY 1476
#define NORMAL 1477
#define EQUAL_EQUAL 1478
#define OPEN_SHEV 1480
#define OPEN_SQUARE 1481
#define OPTION 1482
#define OUTPUT 1483
#define PROMPT 1484
#define PUBLIC 1485
#define RECORD 1486
#define REPORT 1487
#define REVOKE 1488
#define SCHEMA 1489
#define SCROLL_USING 1490
#define SCROLL 1491
#define SECOND 1492
#define SELECT 1493
#define SERIAL 1494
#define SETL 1495
#define SHARED 1496
#define SPACES 1497
#define UNIQUE 1498
#define UNLOCK 1499
#define UPDATE 1500
#define VALUES 1501
#define YELLOW 1502
#define AFTER 1503
#define KWLINE 1504
#define KW_NULL 1505
#define KW_TRUE 1506
#define SINGLE_KEY 1507
#define ALTER 1508
#define ARRAY 1509
#define ASCII 1510
#define AUDIT 1511
#define BLACK 1512
#define BLINK 1513
#define CHECK 1514
#define CLEAR 1515
#define CLOSE 1516
#define CODE_C 1517
#define COUNT 1518
#define DEFER 1519
#define ERROR 1520
#define EVERY 1521
#define FETCH 1522
#define FIRST 1523
#define FLOAT 1524
#define FLUSH 1525
#define FOUND 1526
#define GRANT 1527
#define GREEN 1528
#define GROUP 1529
#define INDEX 1530
#define KWFORM 1531
#define LABEL 1532
#define LOCAL 1534
#define MONEY 1535
#define MONTH 1536
#define ORDER 1539
#define OUTER 1540
#define PAUSE 1541
#define PRINT_IMAGE 1542
#define PRINT_FILE 1543
#define PRINT 1544
#define RIGHT 1545
#define DOUBLE_COLON 1546
#define SEMICOLON 1547
#define SLEEP 1548
#define TUPLE 1549
#define UNION 1550
#define WHERE 1552
#define WHILE 1553
#define WHITE 1554
#define CCODE 1555
#define ANSI 1556
#define BLUE 1557
#define BOLD 1558
#define BYTE 1559
#define FCALL 1560
#define CASE 1561
#define CYAN 1562
#define DATE 1563
#define DESC 1564
#define KWDOWN 1566
#define TAB 1567
#define DROP 1568
#define ELSE 1569
#define EXEC 1570
#define EXIT 1571
#define FREE 1572
#define FROM 1573
#define GOTO 1574
#define HELP_FILE 1575
#define LANG_FILE 1576
#define HELP 1577
#define HIDE 1578
#define HOUR 1579
#define INTO 1580
#define LAST 1581
#define LEFT 1582
#define LIKE 1583
#define MAIN 1584
#define MENU 1585
#define MODE 1586
#define NEED 1587
#define NEXT 1588
#define NOCR 1589
#define OPEN 1590
#define QUIT 1591
#define REAL 1592
#define ROWS 1593
#define SHOW 1594
#define SIZE 1595
#define SKIP 1596
#define SOME 1597
#define STEP 1598
#define STOP 1599
#define TEMP 1600
#define TEXT 1601
#define THEN 1602
#define USER 1603
#define WAIT 1604
#define WHEN 1605
#define WITH 1606
#define WORK 1607
#define YEAR 1608
#define KW_IS 1610
#define XSET 1611
#define ADD 1612
#define ALL 1613
#define ANY 1615
#define ASC 1616
#define AVG 1617
#define COLON 1618
#define DAY 1620
#define DBA 1621
#define DEC 1622
#define DIM 1623
#define FKEY 1624
#define FOR 1625
#define KEY 1626
#define KWNO 1627
#define LET 1628
#define LOG 1629
#define XMAX 1630
#define XMIN 1631
#define PAD 1635
#define PUT 1636
#define RED 1637
#define ROW 1638
#define RUN 1639
#define SQL 1640
#define SUM 1641
#define TOP 1642
#define USE 1643
#define ATSIGN 1644
#define AS_TIFF 1646
#define AS_GIF 1647
#define AS_PNG 1648
#define AS_JPEG 1649
#define AS 1650
#define AT 1651
#define BY 1652
#define DOT 1653
#define GO 1654
#define IF 1655
#define IN 1656
#define OF 1657
#define ON 1658
#define TO 1660
#define KWUP 1661
#define FONT_NAME 1662
#define FONT_SIZE 1663
#define PAPER_SIZE_IS_LETTER 1664
#define PAPER_SIZE_IS_LEGAL 1665
#define PAPER_SIZE_IS_A5 1666
#define PAPER_SIZE_IS_A4 1667
#define PAPER_SIZE_IS_LETTER_L 1668
#define PAPER_SIZE_IS_LEGAL_L 1669
#define PAPER_SIZE_IS_A5_L 1670
#define PAPER_SIZE_IS_A4_L 1671
#define FORMHANDLER 1672
#define END_FORMHANDLER 1673
#define BEFORE_EVENT 1674
#define BEFORE_OPEN_FORM 1675
#define AFTER_EVENT 1676
#define BEFORE_CLOSE_FORM 1677
#define BEFORE_ANY 1678
#define AFTER_ANY 1679
#define MENUHANDLER 1680
#define END_MENUHANDLER 1681
#define BEFORE_SHOW_MENU 1682
#define DISABLE_PROGRAM 1683
#define DISABLE_ALL 1684
#define BUTTONS 1685
#define CHECK_MENUITEM 1686
#define DISABLE_FORM 1687
#define DISABLE_MENUITEMS 1688
#define DISABLE 1689
#define ENABLE_FORM 1690
#define ENABLE_MENUITEMS 1691
#define ENABLE 1692
#define KWFIELD 1693
#define ICON 1694
#define MESSAGEBOX 1695
#define TO_DEFAULTS 1696
#define UNCHECK_MENUITEM 1697
#define BEFORE 1698
#define INPUT 1699
#define END 1700
#define INT_TO_ID 1701
#define TIMEOUT 1702
#define OFF 1703
#define WITH_1_DIMENSION 1704
#define WITH_2_DIMENSION 1705
#define WITH_3_DIMENSION 1706
#define TILDE 1707
#define ILIKE 1708
#define FGL_ISDYNARR_ALLOCATED 1709
#define FGL_DYNARR_EXTENTSIZE 1710
#define FILLFACTOR 1711
#define END_CLASS 1712
#define KW_CLASS 1713
#define EXTENDS 1714




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
int 		class_cnt  =0;
char mv_parent_class[255];

struct 		rep_structure rep_struct;
struct 		pdf_rep_structure pdf_rep_struct;
struct 		form_attr form_attrib;
char *		make_sql_string(char *first,...);
char *into_temp_clause=0;
void copy_gen (int a, int b);
char *get_namespace (char *s);
void set_yytext (char *s);
int isin_command (char *cmd_type);
int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);
char *do_clobbering(char *f,char *s);
void A4GL_copy_fbind_to_Obind(void);
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
#line 218 "fgl.yacc"
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
#line 1720 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1732 "y.tab.c"

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9658

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  732
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  873
/* YYNRULES -- Number of rules. */
#define YYNRULES  2050
/* YYNRULES -- Number of states. */
#define YYNSTATES  3481

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1729

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
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
      15,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,    16,   442,   443,
     444,   445,   446,   447,    23,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,    10,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,    13,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,    17,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,    12,   563,   564,   565,    11,    20,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,     8,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,    21,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,    14,
     634,   635,   636,   637,     7,   638,   639,   640,   641,     5,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,    19,    22,     9,   654,   655,   656,   657,   658,
     659,   660,   661,   662,   663,    18,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,     6,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,     2,     3,     4,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35
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
     190,   197,   198,   199,   209,   210,   211,   221,   222,   223,
     224,   233,   234,   235,   246,   247,   248,   258,   259,   260,
     261,   276,   277,   280,   281,   284,   286,   287,   289,   291,
     295,   297,   299,   301,   303,   305,   309,   310,   317,   318,
     324,   326,   329,   331,   334,   336,   337,   338,   342,   343,
     344,   348,   349,   354,   355,   360,   361,   362,   363,   373,
     374,   377,   379,   382,   384,   387,   390,   393,   395,   398,
     401,   405,   407,   409,   411,   414,   416,   418,   421,   423,
     424,   425,   431,   439,   448,   449,   452,   454,   458,   460,
     464,   468,   470,   473,   474,   479,   480,   485,   486,   490,
     491,   495,   496,   500,   502,   506,   508,   512,   514,   516,
     518,   520,   522,   524,   529,   530,   535,   537,   539,   540,
     542,   544,   547,   548,   549,   555,   557,   559,   563,   564,
     567,   572,   577,   582,   587,   590,   591,   596,   598,   600,
     602,   605,   607,   609,   613,   614,   616,   617,   619,   621,
     623,   624,   632,   633,   639,   640,   653,   655,   657,   659,
     661,   663,   669,   673,   675,   677,   678,   683,   684,   690,
     691,   699,   701,   705,   707,   709,   710,   712,   713,   714,
     719,   721,   723,   725,   727,   732,   737,   742,   749,   754,
     761,   763,   766,   768,   770,   772,   774,   779,   786,   788,
     793,   800,   801,   805,   806,   810,   811,   815,   817,   819,
     821,   823,   825,   828,   831,   833,   835,   836,   840,   845,
     847,   849,   850,   854,   858,   859,   862,   864,   866,   868,
     870,   872,   874,   877,   878,   881,   882,   886,   887,   891,
     893,   894,   898,   900,   902,   904,   906,   908,   910,   913,
     915,   916,   918,   919,   925,   927,   929,   931,   936,   941,
     948,   950,   952,   954,   956,   961,   968,   970,   975,   982,
     984,   986,   988,   990,   992,   995,   998,  1000,  1005,  1006,
    1014,  1015,  1028,  1029,  1034,  1035,  1041,  1043,  1047,  1050,
    1052,  1056,  1058,  1059,  1062,  1065,  1067,  1070,  1076,  1081,
    1084,  1089,  1095,  1099,  1100,  1101,  1113,  1114,  1117,  1119,
    1120,  1123,  1125,  1127,  1130,  1131,  1135,  1136,  1140,  1141,
    1145,  1148,  1151,  1154,  1159,  1165,  1167,  1170,  1172,  1174,
    1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,
    1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1213,  1215,
    1217,  1219,  1222,  1225,  1227,  1229,  1231,  1233,  1235,  1237,
    1239,  1241,  1243,  1245,  1248,  1250,  1253,  1255,  1257,  1259,
    1263,  1265,  1269,  1271,  1275,  1277,  1280,  1282,  1284,  1288,
    1293,  1298,  1300,  1302,  1304,  1306,  1308,  1312,  1314,  1317,
    1320,  1322,  1323,  1327,  1330,  1333,  1335,  1339,  1344,  1349,
    1355,  1361,  1363,  1365,  1368,  1371,  1376,  1381,  1384,  1387,
    1392,  1397,  1399,  1402,  1405,  1408,  1411,  1414,  1417,  1420,
    1423,  1426,  1429,  1432,  1435,  1438,  1441,  1442,  1443,  1444,
    1451,  1452,  1453,  1462,  1463,  1464,  1473,  1474,  1475,  1482,
    1483,  1484,  1491,  1492,  1493,  1500,  1501,  1502,  1509,  1515,
    1521,  1527,  1533,  1541,  1549,  1559,  1569,  1576,  1585,  1596,
    1607,  1615,  1625,  1634,  1645,  1658,  1673,  1688,  1699,  1712,
    1725,  1730,  1735,  1742,  1743,  1747,  1749,  1751,  1756,  1761,
    1766,  1771,  1776,  1781,  1783,  1785,  1787,  1789,  1794,  1799,
    1802,  1805,  1808,  1811,  1814,  1816,  1818,  1821,  1823,  1825,
    1827,  1830,  1835,  1842,  1849,  1853,  1859,  1865,  1869,  1871,
    1873,  1877,  1879,  1883,  1885,  1889,  1890,  1891,  1892,  1902,
    1903,  1907,  1908,  1909,  1920,  1921,  1923,  1924,  1926,  1928,
    1931,  1932,  1936,  1937,  1941,  1942,  1944,  1946,  1949,  1950,
    1954,  1955,  1959,  1963,  1965,  1970,  1974,  1976,  1980,  1982,
    1986,  1988,  1992,  1994,  1997,  1998,  2002,  2003,  2007,  2008,
    2013,  2014,  2019,  2020,  2025,  2026,  2027,  2039,  2040,  2043,
    2046,  2050,  2052,  2056,  2058,  2060,  2062,  2064,  2066,  2068,
    2070,  2074,  2076,  2078,  2083,  2090,  2095,  2099,  2106,  2110,
    2117,  2119,  2121,  2123,  2125,  2127,  2129,  2131,  2133,  2134,
    2137,  2139,  2141,  2143,  2148,  2150,  2152,  2154,  2159,  2163,
    2170,  2174,  2181,  2183,  2185,  2188,  2191,  2193,  2196,  2199,
    2201,  2205,  2207,  2210,  2213,  2216,  2221,  2224,  2227,  2232,
    2233,  2242,  2243,  2245,  2247,  2249,  2250,  2252,  2255,  2256,
    2258,  2261,  2262,  2264,  2267,  2268,  2270,  2274,  2275,  2278,
    2279,  2280,  2289,  2290,  2291,  2295,  2296,  2297,  2305,  2311,
    2314,  2317,  2320,  2321,  2327,  2332,  2334,  2338,  2342,  2346,
    2348,  2349,  2352,  2354,  2355,  2357,  2359,  2362,  2363,  2368,
    2369,  2374,  2375,  2379,  2380,  2384,  2385,  2389,  2390,  2394,
    2395,  2399,  2400,  2404,  2405,  2409,  2410,  2414,  2415,  2419,
    2420,  2424,  2425,  2429,  2431,  2435,  2437,  2441,  2444,  2449,
    2451,  2453,  2455,  2456,  2461,  2467,  2474,  2475,  2486,  2490,
    2493,  2496,  2498,  2500,  2503,  2506,  2507,  2510,  2512,  2515,
    2519,  2523,  2527,  2531,  2533,  2535,  2537,  2539,  2540,  2544,
    2546,  2547,  2551,  2554,  2557,  2559,  2563,  2565,  2569,  2571,
    2573,  2575,  2577,  2579,  2581,  2583,  2585,  2587,  2589,  2591,
    2593,  2595,  2597,  2599,  2601,  2603,  2605,  2607,  2609,  2610,
    2611,  2619,  2621,  2623,  2626,  2629,  2632,  2636,  2641,  2643,
    2645,  2647,  2648,  2652,  2653,  2655,  2657,  2660,  2662,  2664,
    2666,  2668,  2670,  2672,  2674,  2675,  2677,  2679,  2682,  2685,
    2687,  2689,  2691,  2693,  2695,  2697,  2699,  2701,  2703,  2705,
    2706,  2708,  2710,  2712,  2714,  2715,  2716,  2717,  2718,  2732,
    2734,  2735,  2736,  2743,  2746,  2748,  2751,  2754,  2757,  2759,
    2761,  2764,  2766,  2767,  2771,  2774,  2776,  2778,  2780,  2781,
    2782,  2790,  2792,  2795,  2796,  2800,  2801,  2806,  2807,  2813,
    2815,  2816,  2820,  2821,  2829,  2830,  2836,  2838,  2841,  2842,
    2844,  2846,  2848,  2849,  2851,  2853,  2856,  2859,  2862,  2864,
    2866,  2868,  2870,  2874,  2876,  2878,  2881,  2882,  2885,  2887,
    2889,  2891,  2893,  2895,  2897,  2899,  2903,  2904,  2906,  2908,
    2910,  2912,  2915,  2918,  2921,  2927,  2936,  2938,  2940,  2942,
    2947,  2952,  2954,  2956,  2958,  2960,  2963,  2967,  2974,  2976,
    2980,  2982,  2984,  2986,  2990,  2997,  3007,  3009,  3011,  3013,
    3015,  3018,  3019,  3021,  3023,  3027,  3029,  3033,  3035,  3039,
    3041,  3045,  3047,  3049,  3051,  3053,  3057,  3059,  3063,  3065,
    3069,  3071,  3073,  3075,  3079,  3082,  3083,  3085,  3087,  3089,
    3093,  3095,  3099,  3107,  3108,  3116,  3117,  3124,  3128,  3130,
    3134,  3136,  3139,  3145,  3146,  3154,  3155,  3158,  3159,  3161,
    3167,  3170,  3176,  3177,  3183,  3190,  3195,  3196,  3198,  3200,
    3206,  3207,  3210,  3211,  3217,  3222,  3225,  3227,  3231,  3234,
    3237,  3240,  3243,  3246,  3249,  3251,  3254,  3257,  3260,  3263,
    3266,  3269,  3272,  3274,  3276,  3278,  3280,  3283,  3286,  3288,
    3290,  3292,  3294,  3296,  3298,  3304,  3306,  3308,  3311,  3316,
    3321,  3328,  3331,  3333,  3334,  3346,  3347,  3350,  3356,  3357,
    3359,  3360,  3363,  3365,  3368,  3369,  3373,  3375,  3376,  3381,
    3382,  3385,  3387,  3391,  3393,  3395,  3400,  3406,  3412,  3416,
    3417,  3419,  3421,  3423,  3425,  3426,  3428,  3436,  3439,  3442,
    3445,  3448,  3451,  3453,  3456,  3457,  3461,  3462,  3466,  3467,
    3471,  3472,  3476,  3477,  3481,  3482,  3487,  3488,  3493,  3495,
    3497,  3499,  3501,  3503,  3505,  3506,  3511,  3512,  3514,  3515,
    3520,  3522,  3525,  3528,  3531,  3532,  3534,  3536,  3539,  3542,
    3543,  3546,  3547,  3552,  3554,  3558,  3562,  3568,  3569,  3572,
    3577,  3579,  3581,  3583,  3585,  3587,  3588,  3590,  3592,  3596,
    3599,  3605,  3608,  3614,  3620,  3626,  3632,  3638,  3644,  3645,
    3648,  3650,  3653,  3656,  3659,  3662,  3665,  3668,  3670,  3673,
    3676,  3679,  3682,  3684,  3687,  3690,  3693,  3696,  3698,  3700,
    3702,  3703,  3706,  3709,  3712,  3715,  3718,  3721,  3724,  3727,
    3730,  3732,  3734,  3736,  3738,  3740,  3742,  3744,  3746,  3749,
    3752,  3755,  3758,  3761,  3763,  3765,  3767,  3768,  3772,  3775,
    3776,  3777,  3778,  3779,  3780,  3781,  3797,  3798,  3801,  3804,
    3805,  3807,  3808,  3809,  3810,  3811,  3812,  3813,  3829,  3832,
    3833,  3834,  3835,  3846,  3847,  3849,  3853,  3857,  3860,  3865,
    3869,  3873,  3877,  3879,  3882,  3885,  3888,  3891,  3893,  3895,
    3896,  3897,  3906,  3907,  3908,  3918,  3919,  3921,  3923,  3926,
    3929,  3932,  3935,  3937,  3939,  3941,  3942,  3944,  3946,  3949,
    3952,  3955,  3964,  3967,  3970,  3975,  3978,  3979,  3981,  3983,
    3987,  3990,  3993,  3995,  3997,  4001,  4003,  4005,  4008,  4010,
    4014,  4018,  4022,  4024,  4028,  4030,  4032,  4034,  4036,  4038,
    4040,  4042,  4045,  4050,  4052,  4056,  4058,  4062,  4065,  4070,
    4072,  4076,  4078,  4081,  4086,  4088,  4092,  4094,  4096,  4098,
    4101,  4105,  4110,  4113,  4118,  4119,  4122,  4125,  4130,  4132,
    4136,  4138,  4140,  4142,  4145,  4147,  4149,  4151,  4153,  4155,
    4158,  4165,  4172,  4173,  4175,  4176,  4178,  4181,  4183,  4184,
    4190,  4191,  4197,  4199,  4200,  4204,  4206,  4210,  4212,  4216,
    4218,  4220,  4221,  4226,  4228,  4231,  4233,  4234,  4235,  4239,
    4240,  4241,  4245,  4247,  4249,  4251,  4253,  4255,  4257,  4260,
    4263,  4268,  4272,  4276,  4278,  4282,  4285,  4287,  4289,  4290,
    4292,  4294,  4296,  4298,  4299,  4301,  4305,  4307,  4311,  4313,
    4314,  4318,  4320,  4322,  4324,  4326,  4328,  4330,  4332,  4334,
    4336,  4338,  4340,  4342,  4350,  4357,  4362,  4367,  4369,  4371,
    4373,  4374,  4376,  4379,  4381,  4383,  4385,  4387,  4391,  4394,
    4396,  4398,  4401,  4403,  4405,  4406,  4410,  4412,  4416,  4418,
    4422,  4424,  4426,  4433,  4434,  4438,  4440,  4444,  4445,  4447,
    4452,  4458,  4461,  4463,  4465,  4470,  4472,  4476,  4481,  4486,
    4491,  4493,  4497,  4499,  4501,  4503,  4506,  4508,  4510,  4512,
    4517,  4518,  4520,  4521,  4523,  4525,  4528,  4531,  4533,  4535,
    4537,  4539,  4541,  4546,  4548,  4552,  4554,  4556,  4558,  4561,
    4563,  4565,  4568,  4571,  4573,  4577,  4580,  4583,  4585,  4589,
    4591,  4594,  4599,  4601,  4604,  4608,  4610,  4614,  4619,  4620,
    4622,  4623,  4625,  4626,  4628,  4630,  4634,  4636,  4640,  4642,
    4645,  4647,  4651,  4654,  4657,  4658,  4661,  4663,  4665,  4671,
    4675,  4681,  4685,  4687,  4691,  4693,  4695,  4696,  4698,  4702,
    4706,  4710,  4717,  4722,  4727,  4732,  4737,  4743,  4745,  4747,
    4749,  4751,  4753,  4755,  4757,  4759,  4761,  4763,  4764,  4766,
    4768,  4770,  4772,  4774,  4776,  4778,  4783,  4784,  4786,  4791,
    4793,  4799,  4805,  4807,  4809,  4811,  4813,  4815,  4820,  4822,
    4827,  4834,  4839,  4841,  4846,  4848,  4856,  4858,  4860,  4862,
    4867,  4874,  4875,  4878,  4883,  4885,  4887,  4889,  4891,  4893,
    4895,  4897,  4901,  4903,  4905,  4909,  4915,  4919,  4925,  4933,
    4937,  4939,  4941,  4945,  4951,  4955,  4961,  4969,  4971,  4972,
    4976,  4982,  4984,  4987,  4990,  4995,  4999,  5001,  5003,  5005,
    5007,  5009,  5012,  5015,  5016,  5020,  5021,  5025,  5027,  5029,
    5031,  5033,  5035,  5037,  5039,  5044,  5046,  5048,  5050,  5052,
    5054,  5056,  5058,  5060,  5062,  5064,  5066,  5068,  5070,  5072,
    5077,  5079,  5083,  5085,  5089,  5090,  5098,  5099,  5108,  5109,
    5116,  5117,  5126,  5127,  5129,  5132,  5134,  5138,  5140,  5144,
    5150,  5152,  5154,  5156,  5158,  5160,  5161,  5162,  5172,  5178,
    5180,  5182,  5189,  5190,  5194,  5196,  5200,  5205,  5207,  5208,
    5211,  5216,  5223,  5224,  5226,  5228,  5230,  5232,  5236,  5238,
    5241,  5245,  5247,  5249,  5252,  5255,  5257,  5259,  5261,  5264,
    5267,  5270,  5273,  5278,  5282,  5285,  5289,  5293,  5297,  5299,
    5301,  5303,  5305,  5307,  5309,  5315,  5321,  5327,  5333,  5339,
    5344,  5349,  5353,  5358,  5360,  5362,  5364,  5368,  5370,  5376,
    5384,  5390,  5391,  5394,  5396,  5398,  5399,  5403,  5405,  5409,
    5411,  5413,  5415,  5416,  5420,  5422,  5424,  5426,  5428,  5433,
    5440,  5442,  5444,  5447,  5451,  5453,  5455,  5457,  5459,  5461,
    5463,  5465,  5467,  5473,  5479,  5484,  5490,  5492,  5497,  5499,
    5501,  5509,  5514,  5516,  5517,  5522,  5524,  5527,  5529,  5531,
    5533,  5534,  5538,  5539,  5543,  5544,  5545,  5552,  5553,  5556,
    5559,  5567,  5571,  5575,  5578,  5581,  5584,  5586,  5590,  5592,
    5596,  5598,  5602,  5604,  5608,  5610,  5612,  5614,  5617,  5620,
    5622,  5624,  5627,  5632,  5638,  5646,  5654,  5664,  5666,  5668,
    5670,  5672,  5674,  5676,  5680,  5683,  5687,  5691,  5695,  5701,
    5707,  5713,  5719,  5725,  5730,  5735,  5739,  5744,  5746,  5748,
    5750,  5752,  5756,  5757,  5763,  5765,  5769,  5773,  5777,  5779,
    5781,  5784,  5786,  5788,  5792,  5794,  5798,  5802,  5804,  5806,
    5808,  5812,  5815,  5819,  5826,  5828,  5832,  5834,  5836,  5837,
    5838,  5845,  5846,  5849,  5850,  5852,  5854,  5857,  5860,  5862,
    5864,  5869,  5873,  5875,  5878,  5884,  5887,  5890,  5896,  5897,
    5900,  5902,  5904,  5907,  5914,  5921,  5923,  5924,  5926,  5929,
    5931,  5934,  5935,  5938,  5940,  5942,  5944,  5946,  5948,  5950,
    5952,  5954,  5956,  5958,  5960,  5962,  5964,  5966,  5968,  5970,
    5972,  5974,  5976,  5978,  5980,  5982,  5984,  5986,  5988,  5990,
    5992,  5994,  5996,  5998,  6000,  6002,  6004,  6006,  6008,  6010,
    6012,  6014,  6016,  6018,  6020,  6022,  6024,  6026,  6028,  6030,
    6032,  6034,  6036,  6038,  6040,  6042,  6044,  6046,  6048,  6050,
    6052,  6054,  6056,  6058,  6060,  6062,  6064,  6066,  6068,  6070,
    6072,  6074,  6076,  6078,  6080,  6082,  6084,  6086,  6088,  6090,
    6092,  6094,  6096,  6098,  6100,  6102,  6104,  6106,  6108,  6110,
    6112
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1114,     0,    -1,   253,    -1,   250,    -1,   184,   737,   479,
     647,   738,    -1,   195,    -1,  1177,    -1,    26,    -1,   739,
      -1,   738,     5,   739,    -1,  1021,    -1,   483,   740,   446,
      -1,   740,   741,   740,    -1,    26,    -1,   742,    26,    -1,
    1177,    -1,   961,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   744,
      -1,    -1,   328,   483,   745,   746,   446,    -1,   620,   483,
      26,     5,    26,   446,    -1,   747,    -1,   746,     5,   747,
      -1,   542,    -1,   583,    -1,   588,    -1,   558,    -1,   463,
      -1,   656,    -1,   580,    -1,   532,    -1,   469,    -1,   543,
      -1,   401,    -1,   584,    -1,   508,    -1,   388,    -1,   645,
      -1,   152,    -1,  1093,    -1,    -1,   749,    -1,    -1,   328,
     483,   750,   751,   446,    -1,   752,    -1,   751,     5,   752,
      -1,   747,    -1,   484,    -1,   654,    25,    -1,   256,  1007,
      -1,   385,  1007,    -1,   338,  1007,    -1,   393,  1007,    -1,
     347,  1007,    -1,   313,  1007,    -1,   586,   754,    -1,   950,
     400,  1177,    -1,    -1,   343,   483,   969,   446,   400,   755,
    1195,    -1,   160,   483,  1021,     5,    25,     5,    25,   446,
      -1,   460,   483,  1013,   446,   400,  1177,    -1,  1316,    -1,
     246,   483,   969,   446,   400,  1177,    -1,    -1,    -1,  1177,
     641,  1021,   483,   756,   772,   446,   757,   770,    -1,    -1,
      -1,  1177,    36,  1021,   483,   758,   772,   446,   759,   770,
      -1,    -1,    -1,    -1,  1021,   483,   760,   772,   761,   446,
     762,   770,    -1,    -1,    -1,   526,  1524,   674,  1524,   483,
     763,   772,   764,   446,   770,    -1,    -1,    -1,  1021,   573,
    1021,   483,   765,   772,   766,   446,   770,    -1,    -1,    -1,
      -1,   420,   775,   641,   776,   511,   737,   479,   483,   767,
     772,   768,   446,   769,   771,    -1,    -1,   400,  1195,    -1,
      -1,   400,  1195,    -1,   217,    -1,    -1,   773,    -1,   774,
      -1,   773,     5,   774,    -1,   919,    -1,   535,    -1,    25,
      -1,  1021,    -1,  1021,    -1,  1021,   671,  1021,    -1,    -1,
     587,   926,   778,   781,   785,   782,    -1,    -1,   587,   779,
     780,   783,   782,    -1,   787,    -1,   780,   787,    -1,   789,
      -1,   781,   789,    -1,   415,    -1,    -1,    -1,   395,   784,
    1599,    -1,    -1,    -1,   395,   786,  1599,    -1,    -1,   630,
     926,   788,  1599,    -1,    -1,   630,   926,   790,  1599,    -1,
      -1,    -1,    -1,   730,  1021,   792,   795,   793,   825,   794,
     796,   729,    -1,    -1,   731,  1021,    -1,   797,    -1,   796,
     797,    -1,  1129,    -1,   332,  1018,    -1,   255,  1016,    -1,
     138,  1016,    -1,   222,    -1,   239,  1530,    -1,   546,  1015,
      -1,    30,   800,    31,    -1,   801,    -1,   803,    -1,   802,
      -1,   801,   802,    -1,    29,    -1,   804,    -1,   803,   804,
      -1,    28,    -1,    -1,    -1,   376,   806,   808,   807,   809,
      -1,   439,  1177,   676,   810,  1065,  1092,   743,    -1,  1177,
     676,   810,  1065,   598,   969,  1092,   743,    -1,    -1,   812,
     245,    -1,   811,    -1,   810,     5,   811,    -1,  1021,    -1,
    1021,   671,  1021,    -1,  1021,   671,    20,    -1,   813,    -1,
     812,   813,    -1,    -1,   324,   819,   814,  1599,    -1,    -1,
     327,   820,   815,  1599,    -1,    -1,  1095,   816,  1599,    -1,
      -1,   220,   817,  1599,    -1,    -1,   218,   818,  1599,    -1,
    1025,    -1,   819,     5,  1025,    -1,  1025,    -1,   820,     5,
    1025,    -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,
     150,    -1,   151,    -1,   483,   919,   823,   446,    -1,    -1,
       5,   870,   677,   873,    -1,   210,    -1,   333,    -1,    -1,
     826,    -1,   827,    -1,   826,   827,    -1,    -1,    -1,   490,
     828,   830,   829,  1285,    -1,   883,    -1,   833,    -1,   830,
       5,   833,    -1,    -1,   832,  1021,    -1,   409,   831,   882,
      25,    -1,   409,   831,   882,  1021,    -1,   409,   831,   882,
    1027,    -1,   409,   831,   882,    26,    -1,   837,   855,    -1,
      -1,   831,   409,   834,   835,    -1,    26,    -1,    25,    -1,
    1027,    -1,    19,    26,    -1,   831,    -1,   836,    -1,   837,
       5,   836,    -1,    -1,   373,    -1,    -1,   721,    -1,   722,
      -1,   723,    -1,    -1,   539,   511,   847,   479,   841,   675,
     855,    -1,    -1,    41,   839,   842,   675,   855,    -1,    -1,
     372,   838,   844,    26,   845,   356,   511,   846,   479,   843,
     675,   855,    -1,   483,    -1,   510,    -1,   446,    -1,   478,
      -1,    26,    -1,   848,     5,   848,     5,   848,    -1,   848,
       5,   848,    -1,   848,    -1,    26,    -1,    -1,   516,   850,
     830,   337,    -1,    -1,   314,   851,   831,   671,    20,    -1,
      -1,   390,   852,   831,   312,   483,   853,   446,    -1,   854,
      -1,   853,     5,   854,    -1,   831,    -1,   857,    -1,    -1,
     113,    -1,    -1,    -1,   858,   860,   859,   856,    -1,   840,
      -1,   849,    -1,   373,    -1,   374,    -1,   373,   483,    26,
     446,    -1,   374,   483,    26,   446,    -1,   476,   483,    26,
     446,    -1,   476,   483,    26,     5,    26,   446,    -1,   375,
     483,    26,   446,    -1,   375,   483,    26,     5,    26,   446,
      -1,   461,    -1,   668,   831,    -1,   435,    -1,   561,    -1,
     144,    -1,   451,    -1,   451,   483,    26,   446,    -1,   451,
     483,    26,     5,    26,   446,    -1,   564,    -1,   564,   483,
      26,   446,    -1,   564,   483,    26,     5,    26,   446,    -1,
      -1,   554,   861,   864,    -1,    -1,   118,   862,   864,    -1,
      -1,   353,   863,   864,    -1,   589,    -1,   585,    -1,   134,
      -1,   135,    -1,   626,    -1,   412,   868,    -1,   424,   869,
      -1,   865,    -1,    32,    -1,    -1,   483,    26,   446,    -1,
     608,   866,   671,   867,    -1,   831,    -1,   831,    -1,    -1,
     870,   677,   873,    -1,   878,   677,   881,    -1,    -1,   871,
     872,    -1,   633,    -1,   565,    -1,   642,    -1,   604,    -1,
     506,    -1,   522,    -1,   421,   875,    -1,    -1,   874,   872,
      -1,    -1,   483,   877,   446,    -1,    -1,   483,    26,   446,
      -1,    26,    -1,    -1,   879,   880,   876,    -1,   633,    -1,
     565,    -1,   642,    -1,   604,    -1,   506,    -1,   522,    -1,
     421,   875,    -1,   880,    -1,    -1,    14,    -1,    -1,   290,
    1021,   884,   668,   885,    -1,   887,    -1,   890,    -1,   373,
      -1,   373,   483,    26,   446,    -1,   476,   483,    26,   446,
      -1,   476,   483,    26,     5,    26,   446,    -1,   461,    -1,
     435,    -1,   561,    -1,   451,    -1,   451,   483,    26,   446,
      -1,   451,   483,    26,     5,    26,   446,    -1,   564,    -1,
     564,   483,    26,   446,    -1,   564,   483,    26,     5,    26,
     446,    -1,   554,    -1,   353,    -1,   589,    -1,   585,    -1,
     626,    -1,   412,   868,    -1,   424,   869,    -1,   886,    -1,
     608,   866,   671,   867,    -1,    -1,   539,   511,   847,   479,
     888,   675,   885,    -1,    -1,   372,   838,   844,    26,   845,
     356,   511,   846,   479,   889,   675,   885,    -1,    -1,   516,
     891,   893,   337,    -1,    -1,   314,   892,  1021,   671,    20,
      -1,   894,    -1,   893,     5,   894,    -1,   895,   885,    -1,
     896,    -1,   895,     5,   896,    -1,  1021,    -1,    -1,   669,
    1011,    -1,   125,  1021,    -1,   123,    -1,   677,   969,    -1,
     677,   561,  1021,   710,   969,    -1,   677,   561,  1021,   444,
      -1,   127,  1021,    -1,   211,   942,  1195,   905,    -1,   454,
     942,   924,   897,   905,    -1,   264,  1018,   905,    -1,    -1,
      -1,   242,   902,  1202,   677,  1021,   671,    20,   904,   743,
     903,   906,    -1,    -1,   520,  1012,    -1,   743,    -1,    -1,
     907,   292,    -1,   292,    -1,   908,    -1,   907,   908,    -1,
      -1,   407,   909,  1599,    -1,    -1,   403,   910,  1599,    -1,
      -1,  1095,   911,  1599,    -1,    43,  1177,    -1,    44,  1177,
      -1,    42,  1177,    -1,   550,   942,   925,   743,    -1,   550,
     942,   925,   743,   120,    -1,   268,    -1,   268,   926,    -1,
     340,    -1,   339,    -1,   267,    -1,   419,    -1,   227,    -1,
     266,    -1,   384,    -1,   383,    -1,   297,    -1,   224,    -1,
     223,    -1,   201,    -1,   257,    -1,   185,    -1,   200,    -1,
     241,    -1,   208,    -1,   927,    -1,   931,    -1,   961,    -1,
     919,   920,    -1,   962,    -1,   964,    -1,   928,    -1,    19,
     919,    -1,    18,   919,    -1,   933,    -1,   941,    -1,   935,
      -1,   527,    -1,   821,    -1,   936,    -1,   937,    -1,   938,
      -1,   939,    -1,   940,    -1,    49,   919,    -1,   942,    -1,
     942,   923,    -1,   926,    -1,   535,    -1,   922,    -1,   923,
       5,   922,    -1,   926,    -1,   924,     5,   926,    -1,   926,
      -1,   925,     5,   926,    -1,   919,    -1,     9,   919,    -1,
     536,    -1,   480,    -1,   483,   919,   446,    -1,   495,   483,
    1504,   446,    -1,   348,   483,  1504,   446,    -1,    25,    -1,
    1027,    -1,    26,    -1,   930,    -1,  1177,    -1,  1177,   473,
    1177,    -1,   929,    -1,   486,   919,    -1,   447,   919,    -1,
    1288,    -1,    -1,   559,   932,  1288,    -1,     7,   919,    -1,
       6,   919,    -1,   919,    -1,   934,     5,   919,    -1,   674,
     483,  1504,   446,    -1,   481,   483,  1504,   446,    -1,   674,
     483,   942,   934,   446,    -1,   481,   483,   942,   934,   446,
      -1,   441,    -1,   303,    -1,    10,   919,    -1,   306,   919,
      -1,    10,   919,   494,    25,    -1,   306,   919,   494,    25,
      -1,   608,   919,    -1,   426,   919,    -1,   608,   919,   494,
      25,    -1,   426,   919,   494,    25,    -1,   445,    -1,     8,
     919,    -1,    18,   919,    -1,    19,   919,    -1,    20,   919,
      -1,    21,   919,    -1,    22,   919,    -1,    11,   919,    -1,
      14,   919,    -1,   509,   919,    -1,    12,   919,    -1,    13,
     919,    -1,    17,   919,    -1,    16,   919,    -1,    15,   919,
      -1,    -1,    -1,    -1,  1021,   483,   944,   772,   945,   446,
      -1,    -1,    -1,  1021,   573,  1021,   483,   946,   772,   947,
     446,    -1,    -1,    -1,  1021,    36,  1021,   483,   948,   772,
     949,   446,    -1,    -1,    -1,   589,   483,   951,   919,   952,
     446,    -1,    -1,    -1,   565,   483,   953,   919,   954,   446,
      -1,    -1,    -1,   642,   483,   955,   919,   956,   446,    -1,
      -1,    -1,   633,   483,   957,   919,   958,   446,    -1,   424,
     483,   965,   446,   960,    -1,   412,   483,    25,   446,   959,
      -1,   412,   483,    26,   446,   959,    -1,   412,   483,    24,
     446,   959,    -1,   412,   483,    26,   641,    26,   446,   959,
      -1,   412,   483,    26,   641,    24,   446,   959,    -1,   412,
     483,    26,   641,    26,   641,    26,   446,   959,    -1,   412,
     483,    26,   641,    26,   641,    24,   446,   959,    -1,   412,
     483,    26,    26,   446,   959,    -1,   412,   483,    26,    26,
     641,    26,   446,   959,    -1,   412,   483,    26,    26,   641,
      26,   641,    26,   446,   959,    -1,   412,   483,    26,    26,
     641,    26,   641,    24,   446,   959,    -1,   412,   483,    26,
      19,    26,   446,   959,    -1,   412,   483,    26,    19,    26,
      19,    26,   446,   959,    -1,   412,   483,    26,    19,    26,
      26,   446,   959,    -1,   412,   483,    26,    19,    26,    19,
      26,    26,   446,   959,    -1,   412,   483,    26,    19,    26,
      19,    26,    26,   641,    26,   446,   959,    -1,   412,   483,
      26,    19,    26,    19,    26,    26,   641,    26,   641,    26,
     446,   959,    -1,   412,   483,    26,    19,    26,    19,    26,
      26,   641,    26,   641,    24,   446,   959,    -1,   412,   483,
      26,    19,    26,    26,   641,    26,   446,   959,    -1,   412,
     483,    26,    19,    26,    26,   641,    26,   641,    26,   446,
     959,    -1,   412,   483,    26,    19,    26,    26,   641,    26,
     641,    24,   446,   959,    -1,    39,   483,  1177,   446,    -1,
     726,   483,  1177,   446,    -1,   727,   483,  1177,     5,    26,
     446,    -1,    -1,   872,   677,   872,    -1,   869,    -1,   950,
      -1,   343,   483,   969,   446,    -1,   153,   483,  1012,   446,
      -1,   126,   483,  1012,   446,    -1,   460,   483,   970,   446,
      -1,   246,   483,   969,   446,    -1,   114,   483,   969,   446,
      -1,   963,    -1,   943,    -1,  1481,    -1,   589,    -1,   475,
     483,   919,   446,    -1,   378,   483,   919,   446,    -1,   540,
     919,    -1,   496,   822,    -1,   919,   164,    -1,   919,   165,
      -1,   919,   166,    -1,    25,    -1,   966,    -1,    19,   966,
      -1,   968,    -1,   967,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   641,    26,    -1,    26,    26,   641,    26,   641,
      26,    -1,    26,    26,   641,    26,   641,    24,    -1,    26,
     641,    26,    -1,    26,   641,    26,   641,    26,    -1,    26,
     641,    26,   641,    24,    -1,    26,   641,    24,    -1,    24,
      -1,    26,    -1,    26,    19,    26,    -1,  1012,    -1,   969,
       5,  1012,    -1,  1013,    -1,   970,     5,  1013,    -1,    -1,
      -1,    -1,   457,   972,  1015,   973,   975,  1383,   974,  1599,
     294,    -1,    -1,     8,   942,   924,    -1,    -1,    -1,   689,
    1021,   977,   825,   978,  1126,   980,   979,   985,   690,    -1,
      -1,   990,    -1,    -1,   981,    -1,   982,    -1,   981,   982,
      -1,    -1,   691,   983,  1599,    -1,    -1,   692,   984,  1599,
      -1,    -1,   986,    -1,   987,    -1,   986,   987,    -1,    -1,
     693,   988,  1599,    -1,    -1,   694,   989,  1599,    -1,   991,
     995,   380,    -1,   145,    -1,   145,   992,   598,   993,    -1,
     145,   439,   994,    -1,  1177,    -1,   992,     5,  1177,    -1,
    1021,    -1,   993,     5,  1021,    -1,  1177,    -1,   994,     5,
    1177,    -1,   996,    -1,   995,   996,    -1,    -1,   695,   997,
    1599,    -1,    -1,   696,   998,  1599,    -1,    -1,   715,   993,
     999,  1599,    -1,    -1,   533,   993,  1000,  1599,    -1,    -1,
     676,   993,  1001,  1599,    -1,    -1,    -1,   647,  1177,    14,
     926,   677,   926,  1005,  1003,  1599,  1004,   295,    -1,    -1,
     623,   926,    -1,   597,  1014,    -1,   606,    19,    26,    -1,
     606,    -1,   553,    18,    26,    -1,   553,    -1,    26,    -1,
    1177,    -1,   720,    -1,    25,    -1,  1026,    -1,   926,    -1,
    1009,     5,  1009,    -1,  1010,    -1,  1021,    -1,   718,   483,
    1021,   446,    -1,  1021,   671,   718,   483,  1021,   446,    -1,
    1021,   511,   740,   479,    -1,  1021,   671,    20,    -1,  1021,
     511,   740,   479,   671,    20,    -1,  1021,   671,  1021,    -1,
    1021,   511,   740,   479,   671,  1021,    -1,  1012,    -1,    25,
      -1,  1022,    -1,  1022,    -1,  1022,    -1,  1022,    -1,  1022,
      -1,  1022,    -1,    -1,   602,    26,    -1,  1598,    -1,  1023,
      -1,  1598,    -1,   405,   483,  1024,   446,    -1,  1180,    -1,
      25,    -1,  1021,    -1,  1021,   511,   740,   479,    -1,  1021,
     671,    20,    -1,  1021,   511,   740,   479,   671,    20,    -1,
    1021,   671,  1021,    -1,  1021,   511,   740,   479,   671,  1021,
      -1,  1177,    -1,    24,    -1,   671,    26,    -1,   599,  1029,
      -1,  1021,    -1,   641,  1021,    -1,   703,  1031,    -1,  1032,
      -1,  1031,     5,  1032,    -1,  1021,    -1,   714,  1031,    -1,
     705,  1031,    -1,   706,   969,    -1,   704,  1018,   710,   969,
      -1,   708,  1031,    -1,   709,   969,    -1,   707,  1018,   710,
     969,    -1,    -1,   712,  1037,   924,  1042,  1044,  1046,  1038,
    1040,    -1,    -1,  1039,    -1,   700,    -1,   701,    -1,    -1,
    1041,    -1,   400,  1177,    -1,    -1,  1043,    -1,   444,   924,
      -1,    -1,  1045,    -1,   711,    26,    -1,    -1,  1047,    -1,
     702,    26,  1048,    -1,    -1,   453,    26,    -1,    -1,    -1,
     673,   926,   627,  1050,  1599,  1051,  1052,   493,    -1,    -1,
      -1,   594,  1053,  1599,    -1,    -1,    -1,   117,  1054,   926,
     627,  1055,  1599,  1052,    -1,   162,  1021,   483,    26,   446,
      -1,   108,  1021,    -1,    40,  1021,    -1,   130,  1021,    -1,
      -1,   344,  1206,  1060,   677,   535,    -1,   344,  1206,   608,
    1061,    -1,  1062,    -1,  1061,     5,  1062,    -1,  1063,   671,
    1477,    -1,  1063,   671,    20,    -1,  1473,    -1,    -1,  1066,
     380,    -1,   380,    -1,    -1,   205,    -1,  1067,    -1,  1066,
    1067,    -1,    -1,   324,  1081,  1068,  1599,    -1,    -1,   327,
    1082,  1069,  1599,    -1,    -1,   407,  1070,  1599,    -1,    -1,
     403,  1071,  1599,    -1,    -1,  1095,  1072,  1599,    -1,    -1,
     359,  1073,  1599,    -1,    -1,   329,  1074,  1599,    -1,    -1,
      50,  1075,  1599,    -1,    -1,    47,  1076,  1599,    -1,    -1,
      46,  1077,  1599,    -1,    -1,    45,  1078,  1599,    -1,    -1,
      53,  1079,  1599,    -1,    -1,    52,  1080,  1599,    -1,  1012,
      -1,  1081,     5,  1012,    -1,  1012,    -1,  1082,     5,  1012,
      -1,   368,  1085,    -1,   369,  1021,   710,  1085,    -1,   613,
      -1,   430,    -1,  1012,    -1,    -1,   716,  1088,  1087,  1064,
      -1,   439,  1195,  1065,  1020,   743,    -1,  1195,  1065,   598,
     969,  1020,   743,    -1,    -1,   539,  1202,  1065,   598,  1021,
     671,    20,  1020,  1089,   743,    -1,   521,   969,  1091,    -1,
     136,    26,    -1,   137,    26,    -1,   678,    -1,   591,    -1,
     136,  1177,    -1,   137,  1177,    -1,    -1,   602,    26,    -1,
    1094,    -1,    59,    25,    -1,   548,    14,    26,    -1,   548,
      14,  1177,    -1,    60,    14,    26,    -1,    60,    14,  1177,
      -1,    56,    -1,    58,    -1,    55,    -1,    57,    -1,    -1,
     482,  1096,  1101,    -1,   349,    -1,    -1,   648,  1098,  1101,
      -1,   357,  1103,    -1,   648,  1101,    -1,  1103,    -1,   483,
    1102,   446,    -1,  1103,    -1,  1102,     5,  1103,    -1,  1104,
      -1,   646,    -1,   366,    -1,   386,    -1,   358,    -1,   537,
      -1,   494,    -1,   678,    -1,   602,    -1,   591,    -1,   231,
      -1,   491,    -1,   502,    -1,   592,    -1,   607,    -1,   572,
      -1,   364,    -1,   365,    -1,    25,    -1,   562,    -1,    -1,
      -1,   650,  1107,  1200,  1108,    14,   942,  1109,    -1,   535,
      -1,   925,    -1,   273,  1177,    -1,   263,  1177,    -1,   276,
    1177,    -1,   503,  1198,   389,    -1,   503,  1198,   440,  1008,
      -1,  1115,    -1,  1116,    -1,   791,    -1,    -1,  1118,  1117,
    1121,    -1,    -1,  1119,    -1,  1120,    -1,  1119,  1120,    -1,
    1058,    -1,  1125,    -1,  1583,    -1,  1057,    -1,  1141,    -1,
    1127,    -1,  1140,    -1,    -1,  1122,    -1,  1124,    -1,  1122,
    1124,    -1,   121,  1021,    -1,  1129,    -1,  1135,    -1,  1298,
      -1,  1308,    -1,  1147,    -1,   976,    -1,   799,    -1,  1056,
      -1,  1583,    -1,   799,    -1,    -1,   799,    -1,   826,    -1,
     422,    -1,   115,    -1,    -1,    -1,    -1,    -1,  1128,  1130,
    1021,   483,  1131,  1193,   446,  1132,   825,  1133,  1126,  1599,
    1134,    -1,   265,    -1,    -1,    -1,   609,  1136,   825,  1137,
    1599,   416,    -1,   231,   921,    -1,   942,    -1,   942,   924,
      -1,   411,  1488,    -1,   519,  1488,    -1,  1142,    -1,  1143,
      -1,  1142,  1143,    -1,  1144,    -1,    -1,   459,  1145,  1146,
      -1,   825,   296,    -1,  1008,    -1,  1125,    -1,  1140,    -1,
      -1,    -1,   697,  1021,  1148,   825,  1149,  1150,   698,    -1,
    1151,    -1,  1150,  1151,    -1,    -1,   699,  1152,  1599,    -1,
      -1,   676,  1021,  1153,  1599,    -1,    -1,   610,  1155,  1170,
    1161,  1156,    -1,   417,    -1,    -1,   288,  1158,  1599,    -1,
      -1,    23,  1162,  1163,  1164,  1020,  1159,  1599,    -1,    -1,
      23,  1162,  1020,  1160,  1599,    -1,  1157,    -1,  1161,  1157,
      -1,    -1,  1097,    -1,    25,    -1,  1177,    -1,    -1,  1177,
      -1,    25,    -1,   305,  1168,    -1,   317,  1169,    -1,   300,
    1169,    -1,   637,    -1,    25,    -1,  1177,    -1,  1168,    -1,
    1169,     5,  1168,    -1,  1177,    -1,    25,    -1,  1174,  1172,
      -1,    -1,   744,  1175,    -1,  1176,    -1,  1173,    -1,  1043,
      -1,  1045,    -1,  1047,    -1,  1039,    -1,  1041,    -1,   425,
     942,   924,    -1,    -1,   120,    -1,   120,    -1,  1178,    -1,
    1180,    -1,   244,  1180,    -1,  1180,   671,    -1,  1179,  1184,
      -1,  1179,  1021,   511,  1187,   479,    -1,  1179,  1021,   511,
    1187,   479,   511,  1187,   479,    -1,  1185,    -1,  1021,    -1,
    1181,    -1,  1021,   510,  1183,   478,    -1,  1021,   510,  1183,
     478,    -1,  1177,    -1,    25,    -1,    20,    -1,  1021,    -1,
    1021,  1186,    -1,   511,  1187,   479,    -1,   511,  1187,   479,
     511,  1187,   479,    -1,  1188,    -1,  1187,     5,  1188,    -1,
     740,    -1,  1190,    -1,  1192,    -1,  1190,   671,  1191,    -1,
    1190,   671,  1021,   511,  1187,   479,    -1,  1190,   671,  1021,
     511,  1187,   479,   511,  1187,   479,    -1,  1021,    -1,  1182,
      -1,    20,    -1,  1021,    -1,  1021,  1186,    -1,    -1,  1194,
      -1,  1196,    -1,  1194,     5,  1196,    -1,  1197,    -1,  1195,
       5,  1197,    -1,  1021,    -1,  1021,   671,  1021,    -1,  1177,
      -1,  1177,   473,  1177,    -1,    25,    -1,  1027,    -1,    26,
      -1,  1199,    -1,  1198,     5,  1199,    -1,  1177,    -1,  1177,
     473,  1177,    -1,  1201,    -1,  1200,     5,  1201,    -1,  1189,
      -1,  1177,    -1,  1204,    -1,  1203,     5,  1204,    -1,  1177,
    1205,    -1,    -1,   639,    -1,   590,    -1,  1207,    -1,  1206,
       5,  1207,    -1,  1177,    -1,  1177,   473,  1177,    -1,   308,
    1017,   669,  1010,   631,  1591,   748,    -1,    -1,   669,   483,
     926,     5,   926,   446,  1210,    -1,    -1,   620,   483,   926,
       5,   926,   446,    -1,   309,  1021,  1209,    -1,  1021,    -1,
     394,  1019,  1214,    -1,  1215,    -1,   598,   926,    -1,  1216,
    1217,  1222,     8,  1212,    -1,    -1,   669,  1218,   483,   926,
       5,   926,   446,    -1,    -1,   608,  1022,    -1,    -1,   406,
      -1,   271,  1530,   320,  1572,  1221,    -1,   615,  1014,    -1,
     615,  1014,     8,   942,   924,    -1,    -1,   668,   628,  1524,
     429,  1524,    -1,   668,   628,  1524,     5,   429,  1524,    -1,
     668,  1524,     5,  1524,    -1,    -1,   700,    -1,   701,    -1,
     448,   677,  1572,  1224,  1225,    -1,    -1,   668,  1572,    -1,
      -1,   668,   628,  1524,     8,  1524,    -1,   628,  1524,     8,
    1524,    -1,   464,  1227,    -1,  1228,    -1,  1227,     5,  1228,
      -1,   256,  1007,    -1,   338,  1007,    -1,   385,  1007,    -1,
     393,  1007,    -1,   347,  1007,    -1,   313,  1007,    -1,  1099,
      -1,   491,  1100,    -1,   502,  1100,    -1,   613,  1100,    -1,
     430,  1100,    -1,   602,  1100,    -1,   600,  1008,    -1,   601,
    1008,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
     454,   744,    -1,   716,   744,    -1,   345,    -1,   249,    -1,
     206,    -1,   186,    -1,   203,    -1,   194,    -1,  1529,   466,
    1232,   598,  1230,    -1,  1177,    -1,    25,    -1,   456,  1232,
      -1,   456,  1232,     8,  1195,    -1,   456,  1232,   605,  1198,
      -1,   456,  1232,   605,  1198,     8,  1195,    -1,    54,  1230,
      -1,  1022,    -1,    -1,   514,  1242,   743,   647,  1237,  1177,
    1235,  1020,   743,  1234,  1238,    -1,    -1,   719,    26,    -1,
     514,  1242,   743,   400,  1177,    -1,    -1,   373,    -1,    -1,
    1239,   336,    -1,  1240,    -1,  1239,  1240,    -1,    -1,  1095,
    1241,  1599,    -1,   925,    -1,    -1,   655,  1014,  1244,  1245,
      -1,    -1,   598,  1246,    -1,  1247,    -1,  1246,     5,  1247,
      -1,  1516,    -1,   535,    -1,   274,  1251,   143,  1249,    -1,
     274,  1251,   677,  1250,  1249,    -1,   274,  1251,   142,  1250,
    1249,    -1,   274,  1251,  1249,    -1,    -1,    48,    -1,    25,
      -1,  1026,    -1,  1021,    -1,    -1,   531,    -1,   202,  1251,
    1252,   483,   942,  1139,   446,    -1,   247,  1251,    -1,   122,
    1251,    -1,  1289,  1297,    -1,   499,   116,    -1,   499,  1258,
      -1,  1259,    -1,  1258,  1259,    -1,    -1,   190,  1260,  1599,
      -1,    -1,   252,  1261,  1599,    -1,    -1,   282,  1262,  1599,
      -1,    -1,   270,  1263,  1599,    -1,    -1,   307,  1264,  1599,
      -1,    -1,   254,  1177,  1265,  1599,    -1,    -1,   278,  1177,
    1266,  1599,    -1,  1277,    -1,  1281,    -1,  1280,    -1,  1268,
      -1,  1306,    -1,  1271,    -1,    -1,   612,   926,  1269,   534,
      -1,    -1,   534,    -1,    -1,   621,    26,  1272,  1270,    -1,
     213,    -1,   680,  1293,    -1,   216,  1293,    -1,   215,  1293,
      -1,    -1,  1274,    -1,  1275,    -1,  1274,  1275,    -1,  1286,
    1276,    -1,    -1,   669,  1293,    -1,    -1,   571,  1278,  1273,
    1285,    -1,  1524,    -1,   483,  1524,   446,    -1,   570,  1279,
    1285,    -1,   569,  1284,  1283,  1282,  1285,    -1,    -1,   207,
     919,    -1,   207,   919,     5,   919,    -1,   664,    -1,   665,
      -1,   666,    -1,   667,    -1,  1177,    -1,    -1,   574,    -1,
    1287,    -1,  1286,     5,  1287,    -1,   926,  1320,    -1,   660,
     483,   919,   446,  1305,    -1,   119,  1305,    -1,   548,   483,
      20,   446,  1305,    -1,   465,   483,    20,   446,  1305,    -1,
     442,   483,   919,   446,  1305,    -1,   640,   483,   919,   446,
    1305,    -1,   653,   483,   919,   446,  1305,    -1,   652,   483,
     919,   446,  1305,    -1,    -1,   513,  1290,    -1,  1291,    -1,
    1290,  1291,    -1,   281,    26,    -1,   272,    26,    -1,   355,
      26,    -1,   238,    26,    -1,   310,    26,    -1,   229,    -1,
     399,    25,    -1,   399,  1177,    -1,   230,    25,    -1,   214,
      25,    -1,  1296,    -1,  1292,  1296,    -1,  1294,   164,    -1,
    1294,   166,    -1,  1294,   165,    -1,  1294,    -1,  1027,    -1,
      26,    -1,    -1,   513,  1292,    -1,   281,  1293,    -1,   272,
    1293,    -1,   355,  1293,    -1,   238,  1293,    -1,   310,  1293,
      -1,   311,  1293,    -1,   679,    25,    -1,   680,  1293,    -1,
     684,    -1,   681,    -1,   682,    -1,   683,    -1,   688,    -1,
     685,    -1,   686,    -1,   687,    -1,   131,  1293,    -1,   132,
    1293,    -1,   133,  1293,    -1,   399,    25,    -1,   230,    25,
      -1,   453,    -1,   128,    -1,   129,    -1,    -1,   566,   670,
    1203,    -1,   191,  1203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   517,  1299,  1021,   483,  1300,  1193,   446,  1301,   825,
    1302,  1256,  1303,  1257,  1304,   293,    -1,    -1,   578,   919,
      -1,   568,  1307,    -1,    -1,  1230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,  1309,  1021,   483,  1310,  1193,   446,
    1311,   825,  1312,  1315,  1313,  1257,  1314,   293,    -1,  1295,
    1297,    -1,    -1,    -1,    -1,   209,   483,    25,     5,  1317,
     772,  1318,   446,  1319,   770,    -1,    -1,   438,    -1,   438,
     272,    26,    -1,   438,   272,  1177,    -1,   658,   926,    -1,
     658,   926,   400,  1177,    -1,   658,   926,   217,    -1,   658,
     926,   629,    -1,   658,   926,   596,    -1,  1323,    -1,   226,
    1473,    -1,   379,  1473,    -1,   335,  1474,    -1,    51,  1021,
      -1,  1337,    -1,  1325,    -1,    -1,    -1,   259,  1326,  1473,
     483,  1327,  1341,   446,  1330,    -1,    -1,    -1,   188,  1328,
    1473,   483,  1329,  1341,   446,  1330,  1338,    -1,    -1,  1331,
      -1,  1332,    -1,  1331,  1332,    -1,   674,  1333,    -1,   298,
      26,    -1,    63,    26,    -1,   140,    -1,   141,    -1,  1598,
      -1,    -1,  1335,    -1,  1336,    -1,  1335,  1336,    -1,   674,
    1333,    -1,   728,    26,    -1,   159,  1474,   676,  1473,   483,
    1339,   446,  1334,    -1,   106,  1022,    -1,   107,  1022,    -1,
     225,  1473,   647,  1473,    -1,   111,  1473,    -1,    -1,   322,
      -1,  1340,    -1,  1339,     5,  1340,    -1,  1021,   639,    -1,
    1021,   590,    -1,  1021,    -1,  1342,    -1,  1341,     5,  1342,
      -1,  1425,    -1,  1423,    -1,   175,  1021,    -1,   233,    -1,
      61,  1021,  1345,    -1,    62,  1474,   156,    -1,    62,  1474,
     157,    -1,  1346,    -1,  1345,     5,  1346,    -1,  1347,    -1,
    1350,    -1,  1353,    -1,  1358,    -1,  1361,    -1,  1357,    -1,
    1356,    -1,   636,  1348,    -1,   636,   483,  1349,   446,    -1,
    1342,    -1,  1342,   715,  1021,    -1,  1348,    -1,  1349,     5,
    1348,    -1,   593,  1352,    -1,   593,   483,  1351,   446,    -1,
    1352,    -1,  1351,     5,  1352,    -1,  1021,    -1,   507,  1355,
      -1,   507,   483,  1354,   446,    -1,  1355,    -1,  1354,     5,
    1355,    -1,  1342,    -1,   140,    -1,   141,    -1,   139,    26,
      -1,   109,  1423,  1360,    -1,   109,   483,  1359,   446,    -1,
    1423,  1360,    -1,  1359,     5,  1423,  1360,    -1,    -1,   112,
    1021,    -1,   110,  1362,    -1,   110,   483,  1362,   446,    -1,
    1363,    -1,  1362,     5,  1363,    -1,  1021,    -1,   319,    -1,
     285,    -1,   219,  1366,    -1,   198,    -1,   187,    -1,   174,
      -1,   172,    -1,   176,    -1,   232,  1530,    -1,   284,  1365,
     512,  1524,   677,  1524,    -1,   352,  1014,   512,  1524,   677,
    1524,    -1,    -1,  1530,    -1,    -1,   926,    -1,   575,   926,
      -1,   283,    -1,    -1,   302,  1370,  1473,  1373,  1371,    -1,
      -1,   531,  1372,   483,  1375,   446,    -1,  1510,    -1,    -1,
     483,  1374,   446,    -1,  1477,    -1,  1374,     5,  1477,    -1,
    1376,    -1,  1375,     5,  1376,    -1,  1516,    -1,   535,    -1,
      -1,   552,  1378,  1380,  1381,    -1,  1022,    -1,  1385,  1015,
      -1,  1015,    -1,    -1,    -1,   605,  1382,  1198,    -1,    -1,
      -1,   605,  1384,  1198,    -1,   553,    -1,   606,    -1,   613,
      -1,   430,    -1,   397,    -1,   449,    -1,   433,   926,    -1,
     406,   926,    -1,   291,  1473,   204,  1015,    -1,   291,  1473,
    1446,    -1,   566,   670,  1389,    -1,  1390,    -1,  1389,     5,
    1390,    -1,  1391,  1392,    -1,    26,    -1,  1477,    -1,    -1,
     639,    -1,   590,    -1,   330,    -1,   363,    -1,    -1,   382,
      -1,   411,  1397,  1395,    -1,  1572,    -1,  1572,   663,  1021,
      -1,    25,    -1,    -1,  1529,  1399,  1400,    -1,  1431,    -1,
    1435,    -1,  1394,    -1,  1531,    -1,  1393,    -1,  1386,    -1,
    1387,    -1,  1377,    -1,  1369,    -1,  1368,    -1,  1500,    -1,
    1552,    -1,   557,  1404,   676,  1473,   677,  1409,  1403,    -1,
     518,  1404,   676,  1473,   598,  1409,    -1,   557,  1402,   677,
    1409,    -1,   518,  1402,   598,  1409,    -1,   448,    -1,   434,
      -1,   643,    -1,    -1,   197,    -1,   668,  1021,    -1,   221,
      -1,   637,    -1,  1405,    -1,  1406,    -1,  1405,     5,  1406,
      -1,   523,  1407,    -1,   502,    -1,   491,    -1,   530,  1407,
      -1,   538,    -1,   560,    -1,    -1,   483,  1408,   446,    -1,
    1477,    -1,  1408,     5,  1477,    -1,  1410,    -1,  1409,     5,
    1410,    -1,   515,    -1,  1475,    -1,   289,  1473,  1412,   668,
    1510,  1414,    -1,    -1,   483,  1413,   446,    -1,  1477,    -1,
    1413,     5,  1477,    -1,    -1,   196,    -1,   544,   483,  1449,
     446,    -1,   299,   483,  1418,   446,  1417,    -1,   350,  1419,
      -1,  1420,    -1,  1473,    -1,  1473,   483,  1420,   446,    -1,
    1477,    -1,  1420,     5,  1477,    -1,   528,   483,  1422,   446,
      -1,   414,   483,  1422,   446,    -1,   312,   483,  1422,   446,
      -1,  1477,    -1,  1422,     5,  1477,    -1,  1421,    -1,  1416,
      -1,  1415,    -1,   453,  1480,    -1,   262,    -1,   261,    -1,
     260,    -1,  1021,  1465,  1426,  1427,    -1,    -1,  1424,    -1,
      -1,  1428,    -1,  1429,    -1,  1428,  1429,    -1,  1430,  1360,
      -1,   428,    -1,   212,    -1,   528,    -1,   414,    -1,  1417,
      -1,   544,   483,  1449,   446,    -1,   312,    -1,   173,  1432,
    1434,    -1,  1433,    -1,  1475,    -1,  1435,    -1,  1434,  1435,
      -1,  1411,    -1,  1401,    -1,   500,  1449,    -1,   423,  1438,
      -1,  1515,    -1,  1438,     5,  1515,    -1,   578,  1449,    -1,
     598,  1441,    -1,  1442,    -1,  1441,     5,  1442,    -1,  1443,
      -1,   567,  1443,    -1,   567,   483,  1444,   446,    -1,  1473,
      -1,  1473,  1479,    -1,  1473,   668,  1479,    -1,  1442,    -1,
    1444,     5,  1442,    -1,  1440,  1446,  1447,  1448,    -1,    -1,
    1439,    -1,    -1,  1437,    -1,    -1,  1436,    -1,  1450,    -1,
    1449,     6,  1450,    -1,  1451,    -1,  1450,     7,  1451,    -1,
    1452,    -1,     9,  1452,    -1,  1463,    -1,   483,  1449,   446,
      -1,   495,  1511,    -1,   348,  1511,    -1,    -1,   494,  1456,
      -1,  1517,    -1,  1520,    -1,  1516,   674,   483,  1458,   446,
      -1,  1516,   674,  1511,    -1,  1516,   481,   483,  1458,   446,
      -1,  1516,   481,  1511,    -1,  1459,    -1,  1458,     5,  1459,
      -1,  1578,    -1,  1480,    -1,    -1,     9,    -1,  1516,  1460,
     441,    -1,  1516,  1460,   303,    -1,  1516,  1462,  1516,    -1,
    1516,  1460,   443,  1516,     7,  1516,    -1,  1516,   608,  1455,
    1454,    -1,  1516,   426,  1455,  1454,    -1,  1516,   725,  1455,
    1454,    -1,  1516,   427,  1455,  1454,    -1,  1516,  1460,    10,
    1455,  1454,    -1,    14,    -1,    17,    -1,    12,    -1,    13,
      -1,   724,    -1,    16,    -1,    15,    -1,  1461,    -1,  1457,
      -1,  1453,    -1,    -1,   637,    -1,   414,    -1,   528,    -1,
    1466,    -1,  1467,    -1,  1469,    -1,   373,    -1,   373,   483,
    1470,   446,    -1,    -1,   524,    -1,   524,   483,    26,   446,
      -1,   451,    -1,   451,   483,  1471,  1468,   446,    -1,   564,
     483,  1471,  1468,   446,    -1,   564,    -1,   589,    -1,   461,
      -1,   435,    -1,   374,    -1,   374,   483,  1470,   446,    -1,
     375,    -1,   375,   483,    26,   446,    -1,   375,   483,    26,
       5,    26,   446,    -1,   412,  1486,   677,  1487,    -1,   412,
      -1,   424,  1486,   677,  1487,    -1,   424,    -1,   424,  1486,
     483,    26,   446,   677,  1487,    -1,   626,    -1,   585,    -1,
     476,    -1,   476,   483,    26,   446,    -1,   476,   483,    26,
       5,    26,   446,    -1,    -1,     5,  1472,    -1,   554,   483,
    1471,   446,    -1,   617,    -1,   353,    -1,   554,    -1,   118,
      -1,    26,    -1,    26,    -1,    26,    -1,    25,   671,  1021,
      -1,    25,    -1,  1021,    -1,  1021,   641,  1021,    -1,  1021,
     641,    25,   671,  1021,    -1,  1021,   663,  1021,    -1,  1021,
     663,  1021,   641,  1021,    -1,  1021,   663,  1021,   641,    25,
     671,  1021,    -1,    25,   671,  1021,    -1,    25,    -1,  1021,
      -1,  1021,   641,  1021,    -1,  1021,   641,    25,   671,  1021,
      -1,  1021,   663,  1021,    -1,  1021,   663,  1021,   641,  1021,
      -1,  1021,   663,  1021,   641,    25,   671,  1021,    -1,  1021,
      -1,    -1,   511,    26,   479,    -1,   511,    26,     5,    26,
     479,    -1,  1478,    -1,   663,  1478,    -1,  1021,  1476,    -1,
    1473,   671,  1021,  1476,    -1,  1473,   671,    20,    -1,  1021,
      -1,    25,    -1,  1027,    -1,    26,    -1,  1482,    -1,   449,
    1484,    -1,   449,  1483,    -1,    -1,  1486,   677,  1487,    -1,
      -1,  1485,   677,  1485,    -1,   633,    -1,   565,    -1,   642,
      -1,   604,    -1,   506,    -1,   522,    -1,   421,    -1,   421,
     483,    26,   446,    -1,   633,    -1,   565,    -1,   642,    -1,
     604,    -1,   506,    -1,   522,    -1,   421,    -1,   633,    -1,
     565,    -1,   642,    -1,   604,    -1,   506,    -1,   522,    -1,
     421,    -1,   421,   483,    26,   446,    -1,  1021,    -1,  1021,
     663,  1021,    -1,    25,    -1,  1529,   555,  1015,    -1,    -1,
    1529,   452,  1379,   489,   647,  1498,  1491,    -1,    -1,  1529,
     452,  1379,   489,   154,   647,  1499,  1492,    -1,    -1,  1529,
     452,  1379,   192,  1499,  1493,    -1,    -1,  1529,   452,  1379,
     193,   154,   647,  1499,  1494,    -1,    -1,   342,    -1,   341,
    1496,    -1,  1497,    -1,  1496,     5,  1497,    -1,  1021,    -1,
    1021,   671,  1021,    -1,    25,   671,  1021,   671,  1021,    -1,
    1499,    -1,  1369,    -1,  1232,    -1,  1501,    -1,  1501,    -1,
      -1,    -1,   523,  1512,  1502,  1513,  1503,  1509,  1445,  1507,
    1495,    -1,   523,  1512,  1513,  1445,  1507,    -1,  1506,    -1,
    1524,    -1,   523,  1512,  1513,  1509,  1445,  1507,    -1,    -1,
     577,  1464,  1505,    -1,  1388,    -1,   387,  1508,  1338,    -1,
    1388,   387,  1508,  1338,    -1,  1021,    -1,    -1,   605,  1198,
      -1,   523,  1512,  1513,  1445,    -1,   483,   523,  1512,  1513,
    1445,   446,    -1,    -1,   637,    -1,   414,    -1,   528,    -1,
    1514,    -1,  1513,     5,  1514,    -1,  1516,    -1,  1516,  1021,
      -1,  1516,   668,  1021,    -1,  1516,    -1,  1517,    -1,    19,
    1517,    -1,    18,  1517,    -1,  1518,    -1,  1578,    -1,  1511,
      -1,   637,  1511,    -1,   638,  1511,    -1,   622,  1511,    -1,
     663,  1021,    -1,   663,  1021,   671,  1021,    -1,  1517,    21,
    1516,    -1,  1517,  1538,    -1,  1517,    20,  1516,    -1,  1517,
      18,  1516,    -1,  1517,    19,  1516,    -1,  1480,    -1,   536,
      -1,   480,    -1,   628,    -1,    20,    -1,   119,    -1,   640,
     483,  1464,  1516,   446,    -1,   652,   483,  1464,  1516,   446,
      -1,   653,   483,  1464,  1516,   446,    -1,   660,   483,  1464,
    1516,   446,    -1,   548,   483,  1464,  1516,   446,    -1,  1021,
     483,  1519,   446,    -1,   589,   483,  1519,   446,    -1,   483,
    1516,   446,    -1,   496,   483,  1539,   446,    -1,  1540,    -1,
    1542,    -1,  1516,    -1,  1519,     5,  1516,    -1,  1480,    -1,
    1529,   402,  1528,  1523,  1505,    -1,  1529,   391,  1528,  1523,
     302,  1473,  1525,    -1,  1529,   391,  1528,  1523,  1177,    -1,
      -1,   377,  1524,    -1,    25,    -1,  1177,    -1,    -1,   483,
    1526,   446,    -1,  1527,    -1,  1526,     5,  1527,    -1,  1021,
      -1,    25,    -1,  1177,    -1,    -1,   321,  1530,   647,    -1,
    1022,    -1,  1536,    -1,  1535,    -1,  1532,    -1,   370,  1533,
     677,  1533,    -1,   351,  1473,   671,  1534,   677,  1534,    -1,
    1021,    -1,  1021,    -1,   275,  1473,    -1,   346,  1473,  1537,
      -1,   325,    -1,   228,    -1,   146,    -1,   147,    -1,   148,
      -1,   149,    -1,   150,    -1,   151,    -1,   449,     5,  1486,
     677,  1487,    -1,  1578,     5,  1486,   677,  1487,    -1,   449,
    1486,   677,  1487,    -1,  1516,     5,  1486,   677,  1487,    -1,
    1541,    -1,  1541,  1486,   677,  1487,    -1,    37,    -1,  1543,
      -1,  1543,  1486,   483,    26,   446,   677,  1487,    -1,  1543,
    1486,   677,  1487,    -1,    38,    -1,    -1,   659,  1545,  1546,
     243,    -1,  1547,    -1,  1546,  1547,    -1,    33,    -1,  1548,
      -1,  1550,    -1,    -1,   244,  1549,  1578,    -1,    -1,   605,
    1551,  1198,    -1,    -1,    -1,   530,  1473,  1553,  1556,  1554,
    1555,    -1,    -1,   204,  1015,    -1,   578,  1449,    -1,   104,
    1560,   446,    14,   483,  1561,   446,    -1,   100,  1561,   446,
      -1,   101,  1561,   446,    -1,   635,  1557,    -1,   103,  1561,
      -1,   102,  1561,    -1,  1559,    -1,  1557,     5,  1559,    -1,
    1477,    -1,  1558,    14,  1562,    -1,  1558,    -1,  1560,     5,
    1558,    -1,  1562,    -1,  1561,     5,  1562,    -1,   535,    -1,
    1563,    -1,  1564,    -1,    19,  1564,    -1,    18,  1564,    -1,
    1566,    -1,  1511,    -1,   663,  1021,    -1,   663,  1021,   671,
    1021,    -1,   663,  1021,   511,    26,   479,    -1,   663,  1021,
     671,  1021,   511,    26,   479,    -1,   663,  1021,   511,    26,
       5,    26,   479,    -1,   663,  1021,   671,  1021,   511,    26,
       5,    26,   479,    -1,  1565,    -1,  1480,    -1,   536,    -1,
     480,    -1,   628,    -1,   119,    -1,  1564,    21,  1563,    -1,
    1564,  1538,    -1,  1564,    20,  1563,    -1,  1564,    18,  1563,
      -1,  1564,    19,  1563,    -1,   640,   483,  1464,  1563,   446,
      -1,   652,   483,  1464,  1563,   446,    -1,   653,   483,  1464,
    1563,   446,    -1,   660,   483,  1464,  1563,   446,    -1,   548,
     483,  1464,  1563,   446,    -1,  1021,   483,  1567,   446,    -1,
     589,   483,  1567,   446,    -1,   483,  1563,   446,    -1,   496,
     483,  1539,   446,    -1,  1540,    -1,  1542,    -1,  1578,    -1,
    1563,    -1,  1567,     5,  1563,    -1,    -1,   436,  1206,   608,
    1569,  1570,    -1,  1571,    -1,  1570,     5,  1571,    -1,  1473,
     671,  1477,    -1,  1473,   671,    20,    -1,  1574,    -1,  1574,
      -1,   244,  1575,    -1,  1575,    -1,  1576,    -1,    25,   671,
    1576,    -1,  1577,    -1,  1576,   671,  1577,    -1,  1576,   671,
      20,    -1,  1579,    -1,  1021,    -1,  1573,    -1,  1573,   473,
    1573,    -1,  1021,  1580,    -1,   511,  1581,   479,    -1,   511,
    1581,   479,   511,  1581,   479,    -1,  1582,    -1,  1581,     5,
    1582,    -1,   740,    -1,    34,    -1,    -1,    -1,   579,  1585,
     926,  1586,  1599,   381,    -1,    -1,   710,   969,    -1,    -1,
     713,    -1,   235,    -1,   331,  1016,    -1,   124,  1016,    -1,
     361,    -1,   360,    -1,   362,  1018,  1587,  1588,    -1,   545,
     969,  1588,    -1,   158,    -1,   189,  1016,    -1,   926,   618,
       5,   926,   447,    -1,   561,   926,    -1,   318,  1016,    -1,
     155,  1594,     8,  1595,  1593,    -1,    -1,   598,   926,    -1,
    1021,    -1,  1021,    -1,   301,  1016,    -1,   304,  1016,   677,
     926,     5,   926,    -1,   304,  1016,   670,   926,     5,   926,
      -1,    27,    -1,    -1,  1601,    -1,  1602,  1285,    -1,  1600,
      -1,  1601,  1600,    -1,    -1,  1603,  1604,    -1,   733,    -1,
     734,    -1,   735,    -1,   736,    -1,   753,    -1,   777,    -1,
     798,    -1,   799,    -1,   805,    -1,   824,    -1,   898,    -1,
     899,    -1,   900,    -1,   901,    -1,   912,    -1,   913,    -1,
     914,    -1,   915,    -1,   916,    -1,   917,    -1,   918,    -1,
     971,    -1,  1002,    -1,  1006,    -1,  1028,    -1,  1030,    -1,
    1033,    -1,  1034,    -1,  1035,    -1,  1036,    -1,  1049,    -1,
    1059,    -1,  1083,    -1,  1084,    -1,  1086,    -1,  1090,    -1,
    1105,    -1,  1106,    -1,  1110,    -1,  1111,    -1,  1112,    -1,
    1113,    -1,  1123,    -1,  1138,    -1,  1154,    -1,  1165,    -1,
    1166,    -1,  1167,    -1,  1171,    -1,  1208,    -1,  1211,    -1,
    1213,    -1,  1219,    -1,  1220,    -1,  1223,    -1,  1226,    -1,
    1229,    -1,  1231,    -1,  1233,    -1,  1236,    -1,  1243,    -1,
    1248,    -1,  1253,    -1,  1254,    -1,  1255,    -1,  1267,    -1,
    1321,    -1,  1322,    -1,  1324,    -1,  1343,    -1,  1344,    -1,
    1364,    -1,  1367,    -1,  1396,    -1,  1398,    -1,  1489,    -1,
    1490,    -1,  1521,    -1,  1522,    -1,  1544,    -1,  1568,    -1,
    1583,    -1,  1584,    -1,  1589,    -1,  1590,    -1,  1592,    -1,
    1596,    -1,  1597,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1008,  1008,  1011,  1014,  1020,  1026,  1033,  1037,  1037,
    1043,  1062,  1063,  1064,  1065,  1066,  1077,  1083,  1084,  1085,
    1086,  1087,  1092,  1093,  1104,  1107,  1110,  1110,  1114,  1117,
    1118,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1143,  1144,
    1147,  1147,  1162,  1163,  1166,  1172,  1174,  1185,  1187,  1189,
    1191,  1195,  1197,  1259,  1263,  1267,  1267,  1277,  1281,  1284,
    1285,  1294,  1300,  1294,  1314,  1320,  1314,  1336,  1341,  1345,
    1336,  1357,  1361,  1357,  1369,  1374,  1369,  1393,  1400,  1404,
    1392,  1430,  1430,  1434,  1435,  1436,  1441,  1444,  1449,  1453,
    1461,  1462,  1465,  1465,  1471,  1475,  1490,  1488,  1506,  1506,
    1521,  1521,  1524,  1524,  1528,  1531,  1531,  1531,  1538,  1539,
    1538,  1546,  1546,  1557,  1557,  1570,  1594,  1602,  1570,  1618,
    1623,  1631,  1632,  1636,  1646,  1649,  1652,  1655,  1658,  1661,
    1674,  1679,  1679,  1680,  1680,  1683,  1688,  1688,  1692,  1711,
    1716,  1710,  1727,  1733,  1741,  1742,  1745,  1745,  1748,  1752,
    1757,  1764,  1764,  1768,  1768,  1769,  1769,  1770,  1770,  1771,
    1771,  1772,  1772,  1780,  1784,  1790,  1794,  1809,  1812,  1815,
    1818,  1821,  1824,  1830,  1841,  1846,  1859,  1863,  1878,  1879,
    1883,  1883,  1887,  1887,  1887,  1888,  1893,  1893,  1896,  1896,
    1905,  1906,  1907,  1910,  1914,  1915,  1915,  1932,  1932,  1932,
    1932,  1936,  1943,  1944,  1947,  1947,  1951,  1952,  1953,  1954,
    1959,  1959,  1965,  1965,  1974,  1971,  1987,  1987,  1989,  1989,
    1991,  1993,  1995,  1997,  2000,  2004,  2004,  2005,  2005,  2009,
    2009,  2021,  2021,  2026,  2030,  2032,  2033,  2036,  2036,  2036,
    2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,  2048,  2049,
    2050,  2051,  2054,  2055,  2056,  2057,  2061,  2066,  2071,  2075,
    2078,  2082,  2082,  2083,  2083,  2084,  2084,  2085,  2086,  2087,
    2088,  2089,  2090,  2093,  2094,  2095,  2125,  2125,  2130,  2134,
    2136,  2138,  2138,  2145,  2149,  2149,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2165,  2165,  2168,  2170,  2176,  2178,  2184,
    2192,  2192,  2195,  2196,  2197,  2198,  2199,  2200,  2201,  2207,
    2210,  2210,  2223,  2223,  2230,  2231,  2232,  2234,  2235,  2236,
    2240,  2241,  2242,  2243,  2248,  2254,  2260,  2261,  2263,  2265,
    2266,  2267,  2268,  2269,  2270,  2273,  2274,  2281,  2289,  2289,
    2297,  2294,  2309,  2309,  2311,  2311,  2319,  2319,  2322,  2325,
    2326,  2331,  2343,  2347,  2350,  2353,  2354,  2355,  2356,  2357,
    2362,  2369,  2375,  2380,  2385,  2380,  2398,  2400,  2405,  2410,
    2410,  2410,  2414,  2414,  2417,  2417,  2424,  2424,  2431,  2431,
    2442,  2460,  2466,  2490,  2493,  2508,  2511,  2524,  2526,  2528,
    2530,  2532,  2534,  2536,  2542,  2544,  2548,  2550,  2552,  2554,
    2556,  2558,  2560,  2566,  2583,  2584,  2585,  2586,  2590,  2591,
    2592,  2596,  2601,  2608,  2609,  2610,  2611,  2612,  2613,  2614,
    2615,  2616,  2617,  2618,  2625,  2625,  2630,  2630,  2633,  2639,
    2647,  2653,  2663,  2664,  2672,  2693,  2697,  2702,  2707,  2709,
    2712,  2730,  2735,  2741,  2746,  2751,  2752,  2758,  2829,  2840,
    2849,  2857,  2857,  2872,  2876,  2883,  2886,  2894,  2898,  2901,
    2907,  2916,  2921,  2929,  2932,  2935,  2940,  2947,  2952,  2957,
    2962,  2972,  2980,  2988,  2993,  2997,  3002,  3006,  3010,  3017,
    3020,  3023,  3027,  3031,  3035,  3039,  3047,  3057,  3062,  3055,
    3078,  3083,  3078,  3097,  3102,  3097,  3123,  3123,  3123,  3126,
    3126,  3126,  3130,  3130,  3130,  3134,  3134,  3134,  3138,  3144,
    3150,  3156,  3164,  3170,  3178,  3184,  3193,  3199,  3206,  3213,
    3222,  3228,  3234,  3241,  3247,  3253,  3259,  3267,  3273,  3279,
    3288,  3294,  3300,  3310,  3310,  3314,  3318,  3319,  3330,  3331,
    3337,  3347,  3357,  3367,  3368,  3371,  3376,  3382,  3386,  3390,
    3393,  3399,  3402,  3405,  3422,  3425,  3431,  3432,  3433,  3437,
    3438,  3439,  3440,  3441,  3443,  3444,  3445,  3447,  3448,  3452,
    3453,  3458,  3462,  3467,  3471,  3486,  3490,  3496,  3485,  3509,
    3510,  3522,  3528,  3522,  3542,  3542,  3544,  3545,  3549,  3549,
    3553,  3553,  3558,  3558,  3565,  3566,  3570,  3570,  3574,  3574,
    3579,  3579,  3586,  3590,  3591,  3592,  3597,  3597,  3600,  3600,
    3604,  3604,  3608,  3608,  3612,  3612,  3617,  3617,  3622,  3622,
    3627,  3627,  3632,  3632,  3648,  3652,  3647,  3660,  3663,  3677,
    3694,  3695,  3696,  3697,  3698,  3699,  3700,  3703,  3703,  3706,
    3708,  3711,  3714,  3717,  3722,  3727,  3730,  3735,  3740,  3745,
    3752,  3753,  3760,  3767,  3769,  3775,  3780,  3785,  3790,  3790,
    3793,  3799,  3804,  3807,  3814,  3814,  3816,  3819,  3822,  3827,
    3832,  3837,  3844,  3855,  3855,  3917,  3925,  3926,  3934,  3941,
    3941,  3945,  3950,  3956,  3960,  3964,  3970,  3974,  3978,  3984,
    3984,  3992,  3993,  3997,  3997,  4001,  4002,  4005,  4008,  4008,
    4011,  4013,  4013,  4016,  4018,  4018,  4019,  4021,  4021,  4030,
    4037,  4028,  4058,  4058,  4058,  4061,  4063,  4061,  4070,  4073,
    4080,  4085,  4096,  4096,  4100,  4106,  4106,  4110,  4111,  4115,
    4125,  4126,  4127,  4130,  4132,  4137,  4137,  4141,  4140,  4148,
    4147,  4154,  4154,  4160,  4160,  4167,  4167,  4173,  4173,  4179,
    4179,  4185,  4185,  4189,  4189,  4190,  4190,  4191,  4191,  4192,
    4192,  4196,  4196,  4207,  4211,  4217,  4221,  4226,  4231,  4236,
    4237,  4238,  4242,  4241,  4254,  4259,  4264,  4264,  4280,  4286,
    4287,  4288,  4289,  4290,  4300,  4314,  4314,  4317,  4324,  4325,
    4326,  4327,  4328,  4329,  4330,  4331,  4332,  4337,  4337,  4339,
    4342,  4342,  4344,  4348,  4351,  4352,  4355,  4355,  4360,  4363,
    4364,  4365,  4366,  4367,  4368,  4369,  4370,  4371,  4372,  4373,
    4374,  4375,  4376,  4377,  4378,  4379,  4380,  4384,  4402,  4402,
    4402,  4429,  4440,  4447,  4453,  4459,  4465,  4477,  4500,  4501,
    4504,  4508,  4507,  4525,  4525,  4529,  4530,  4538,  4539,  4540,
    4541,  4542,  4543,  4544,  4551,  4552,  4554,  4555,  4559,  4564,
    4565,  4566,  4567,  4568,  4569,  4570,  4571,  4572,  4575,  4577,
    4577,  4579,  4583,  4583,  4592,  4598,  4614,  4620,  4591,  4634,
    4648,  4659,  4647,  4672,  4679,  4679,  4684,  4690,  4698,  4703,
    4704,  4707,  4710,  4710,  4718,  4724,  4735,  4736,  4744,  4750,
    4744,  4761,  4762,  4766,  4766,  4773,  4773,  4788,  4788,  4802,
    4813,  4812,  4824,  4820,  4837,  4834,  4847,  4847,  4849,  4850,
    4852,  4853,  4856,  4857,  4858,  4860,  4865,  4870,  4876,  4878,
    4879,  4882,  4883,  4886,  4888,  4895,  4898,  4901,  4904,  4908,
    4912,  4913,  4914,  4915,  4916,  4920,  4925,  4925,  4928,  4955,
    5013,  5013,  5016,  5020,  5024,  5067,  5109,  5110,  5111,  5114,
    5128,  5140,  5140,  5145,  5146,  5152,  5217,  5222,  5229,  5234,
    5242,  5248,  5281,  5284,  5285,  5326,  5369,  5370,  5374,  5375,
    5379,  5432,  5437,  5441,  5446,  5457,  5464,  5472,  5472,  5475,
    5476,  5477,  5478,  5479,  5482,  5485,  5491,  5494,  5498,  5503,
    5511,  5516,  5523,  5525,  5531,  5533,  5533,  5533,  5553,  5560,
    5567,  5570,  5584,  5591,  5592,  5595,  5596,  5600,  5606,  5611,
    5617,  5618,  5623,  5627,  5627,  5631,  5632,  5635,  5636,  5640,
    5648,  5651,  5657,  5658,  5660,  5662,  5666,  5666,  5667,  5672,
    5680,  5681,  5686,  5687,  5689,  5702,  5704,  5705,  5708,  5709,
    5710,  5711,  5712,  5713,  5714,  5715,  5716,  5717,  5718,  5719,
    5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,  5728,  5729,
    5730,  5731,  5732,  5733,  5747,  5755,  5755,  5757,  5761,  5765,
    5769,  5773,  5778,  5793,  5791,  5811,  5812,  5816,  5821,  5822,
    5826,  5827,  5829,  5830,  5832,  5832,  5841,  5850,  5850,  5860,
    5861,  5866,  5867,  5870,  5883,  5897,  5901,  5905,  5909,  5916,
    5917,  5920,  5920,  5924,  5927,  5927,  5929,  5935,  5943,  5949,
    5951,  5955,  5958,  5958,  5961,  5961,  5966,  5966,  5975,  5975,
    5979,  5979,  5980,  5980,  5981,  5981,  5995,  5995,  6015,  6016,
    6017,  6018,  6019,  6020,  6023,  6023,  6029,  6029,  6032,  6032,
    6048,  6049,  6050,  6059,  6071,  6072,  6075,  6076,  6079,  6082,
    6082,  6087,  6087,  6110,  6111,  6117,  6122,  6128,  6129,  6130,
    6134,  6135,  6136,  6137,  6141,  6151,  6153,  6158,  6161,  6166,
    6172,  6179,  6186,  6195,  6202,  6209,  6216,  6223,  6232,  6232,
    6234,  6234,  6237,  6238,  6239,  6240,  6241,  6242,  6243,  6244,
    6245,  6246,  6249,  6249,  6252,  6253,  6254,  6255,  6258,  6258,
    6261,  6261,  6264,  6265,  6266,  6267,  6268,  6269,  6270,  6271,
    6273,  6274,  6275,  6276,  6278,  6279,  6280,  6281,  6283,  6284,
    6285,  6286,  6287,  6288,  6289,  6290,  6294,  6302,  6312,  6325,
    6336,  6347,  6351,  6355,  6361,  6324,  6374,  6377,  6385,  6397,
    6399,  6404,  6414,  6424,  6427,  6431,  6439,  6403,  6448,  6452,
    6456,  6460,  6452,  6470,  6471,  6472,  6473,  6478,  6480,  6483,
    6487,  6490,  6497,  6502,  6509,  6510,  6511,  6516,  6517,  6523,
    6523,  6523,  6528,  6528,  6528,  6536,  6537,  6541,  6542,  6547,
    6548,  6549,  6550,  6551,  6554,  6556,  6556,  6559,  6560,  6564,
    6565,  6568,  6569,  6572,  6575,  6578,  6584,  6585,  6597,  6598,
    6603,  6604,  6605,  6609,  6612,  6618,  6621,  6629,  6630,  6636,
    6640,  6644,  6650,  6653,  6662,  6665,  6668,  6671,  6674,  6677,
    6680,  6687,  6690,  6697,  6700,  6706,  6709,  6716,  6719,  6726,
    6727,  6732,  6736,  6739,  6745,  6748,  6754,  6761,  6762,  6766,
    6776,  6779,  6785,  6787,  6792,  6793,  6797,  6799,  6805,  6806,
    6819,  6831,  6832,  6833,  6834,  6835,  6836,  6837,  6838,  6839,
    6842,  6845,  6851,  6851,  6857,  6857,  6868,  6881,  6891,  6891,
    6896,  6896,  6900,  6904,  6905,  6911,  6912,  6917,  6921,  6928,
    6931,  6938,  6937,  6948,  6952,  6956,  6963,  6966,  6966,  6979,
    6983,  6983,  6998,  7000,  7002,  7004,  7006,  7008,  7010,  7012,
    7018,  7028,  7035,  7040,  7041,  7045,  7048,  7049,  7052,  7053,
    7054,  7057,  7062,  7069,  7070,  7076,  7088,  7089,  7090,  7093,
    7093,  7098,  7103,  7108,  7109,  7112,  7113,  7118,  7123,  7127,
    7132,  7133,  7137,  7144,  7145,  7146,  7147,  7152,  7153,  7154,
    7157,  7158,  7159,  7163,  7164,  7165,  7169,  7170,  7174,  7175,
    7176,  7177,  7178,  7179,  7182,  7183,  7188,  7189,  7194,  7195,
    7200,  7201,  7206,  7211,  7212,  7217,  7218,  7222,  7223,  7228,
    7235,  7240,  7245,  7249,  7250,  7255,  7256,  7262,  7265,  7269,
    7274,  7275,  7281,  7284,  7287,  7294,  7295,  7296,  7297,  7311,
    7316,  7317,  7320,  7322,  7329,  7332,  7338,  7346,  7350,  7354,
    7358,  7363,  7366,  7369,  7376,  7383,  7388,  7392,  7393,  7399,
    7402,  7413,  7420,  7426,  7429,  7436,  7443,  7449,  7450,  7456,
    7457,  7458,  7461,  7462,  7469,  7476,  7476,  7480,  7488,  7489,
    7492,  7495,  7500,  7501,  7506,  7509,  7515,  7518,  7524,  7527,
    7533,  7536,  7543,  7544,  7573,  7574,  7578,  7586,  7591,  7594,
    7597,  7600,  7606,  7607,  7611,  7614,  7617,  7618,  7623,  7626,
    7629,  7632,  7635,  7638,  7641,  7644,  7649,  7655,  7656,  7657,
    7658,  7661,  7662,  7663,  7668,  7671,  7675,  7681,  7682,  7683,
    7684,  7696,  7697,  7698,  7702,  7703,  7707,  7708,  7709,  7710,
    7711,  7713,  7722,  7729,  7730,  7731,  7732,  7733,  7734,  7735,
    7737,  7739,  7741,  7742,  7744,  7745,  7747,  7748,  7749,  7750,
    7752,  7756,  7757,  7763,  7765,  7766,  7767,  7768,  7773,  7777,
    7781,  7785,  7792,  7796,  7797,  7798,  7806,  7807,  7808,  7819,
    7826,  7831,  7832,  7833,  7841,  7842,  7843,  7860,  7869,  7870,
    7871,  7875,  7878,  7883,  7888,  7893,  7901,  7905,  7910,  7911,
    7919,  7922,  7925,  7939,  7953,  7966,  7967,  7971,  7971,  7971,
    7971,  7971,  7971,  7972,  7975,  7992,  7992,  7992,  7992,  7992,
    7992,  7992,  7993,  7993,  7993,  7993,  7993,  7993,  7993,  7993,
    7996,  7997,  7998,  8001,  8010,  8010,  8016,  8016,  8023,  8023,
    8029,  8029,  8037,  8038,  8039,  8042,  8042,  8045,  8046,  8047,
    8058,  8061,  8067,  8072,  8079,  8092,  8093,  8090,  8111,  8122,
    8125,  8130,  8142,  8145,  8149,  8152,  8153,  8163,  8166,  8167,
    8176,  8185,  8190,  8191,  8192,  8193,  8200,  8203,  8209,  8212,
    8219,  8231,  8240,  8243,  8246,  8252,  8260,  8263,  8264,  8265,
    8266,  8267,  8270,  8276,  8278,  8280,  8282,  8284,  8286,  8287,
    8288,  8289,  8290,  8291,  8292,  8294,  8296,  8298,  8300,  8302,
    8304,  8306,  8307,  8309,  8310,  8316,  8317,  8324,  8327,  8335,
    8339,  8346,  8346,  8350,  8350,  8355,  8355,  8359,  8359,  8363,
    8369,  8369,  8372,  8372,  8378,  8385,  8386,  8387,  8391,  8392,
    8395,  8396,  8400,  8406,  8416,  8417,  8425,  8426,  8427,  8428,
    8429,  8430,  8434,  8435,  8436,  8437,  8441,  8442,  8446,  8462,
    8463,  8464,  8468,  8482,  8482,  8494,  8495,  8499,  8500,  8501,
    8825,  8825,  8832,  8832,  8920,  8924,  8920,  8933,  8937,  8943,
    8951,  8961,  8971,  8983,  8986,  9005,  9031,  9034,  9040,  9043,
    9048,  9051,  9059,  9067,  9080,  9083,  9091,  9094,  9097,  9105,
    9109,  9110,  9111,  9112,  9113,  9114,  9115,  9116,  9120,  9121,
    9122,  9123,  9124,  9130,  9131,  9132,  9133,  9134,  9135,  9136,
    9137,  9138,  9139,  9140,  9141,  9142,  9143,  9144,  9145,  9150,
    9156,  9157,  9165,  9165,  9173,  9173,  9177,  9181,  9196,  9211,
    9217,  9219,  9227,  9228,  9232,  9233,  9236,  9243,  9246,  9275,
    9301,  9355,  9391,  9400,  9411,  9414,  9419,  9433,  9447,  9450,
    9446,  9469,  9469,  9475,  9476,  9479,  9480,  9481,  9482,  9483,
    9484,  9485,  9496,  9499,  9504,  9508,  9513,  9517,  9522,  9526,
    9529,  9533,  9536,  9541,  9545,  9556,  9562,  9562,  9563,  9564,
    9571,  9581,  9581,  9583,  9584,  9585,  9586,  9587,  9588,  9589,
    9590,  9591,  9592,  9593,  9594,  9595,  9596,  9597,  9598,  9599,
    9600,  9601,  9602,  9603,  9604,  9605,  9606,  9607,  9608,  9609,
    9610,  9611,  9612,  9613,  9614,  9615,  9616,  9617,  9618,  9619,
    9620,  9621,  9622,  9623,  9624,  9625,  9626,  9627,  9628,  9629,
    9630,  9631,  9632,  9633,  9634,  9635,  9636,  9637,  9638,  9639,
    9640,  9641,  9642,  9643,  9644,  9645,  9646,  9647,  9648,  9649,
    9650,  9651,  9652,  9653,  9654,  9655,  9656,  9657,  9658,  9659,
    9660,  9661,  9662,  9663,  9664,  9665,  9666,  9667,  9668,  9669,
    9670
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
  "MEMBER_FUNCTION", "DATETIME_VALUE", "INTERVAL_VALUE", "FGL_SIZEOF", 
  "IMPORT_PACKAGE", "DYNAMIC_ARRAY", "RESIZE_ARRAY", "ALLOCATE_ARRAY", 
  "DEALLOCATE_ARRAY", "AFTER_INSERT_DELETE", "BEFORE_INSERT_DELETE", 
  "BEFORE_INSERT", "AS_CONVERTABLE", "CONCAT_PIPES", "BEFORE_DELETE", 
  "DROP_TRIGGER", "AFTER_INSERT", "AFTER_DELETE", "EXECUTE_IMMEDIATE", 
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
  "INCHES", "PREPEND", "MEMBER_OF", "APPEND", "TEMPLATE", "END_TEMPLATE", 
  "SQLSICS", "CREATE_SCHEMA", "SQLSIRR", "UPDATESTATS_T", "SQLSICR", 
  "WHENEVER_SQLSUCCESS", "WHENEVER_SQLWARNING", "WHENEVER_ANY_ERROR", 
  "WHENEVER_NOT_FOUND", "WHENEVER_SQLERROR", "WHENEVER_SUCCESS", 
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
  "INPUT_NO_WRAP", "SETPMOFF", "UNCONSTRAINED", "PAGE_TRAILER", "SETPMON", 
  "BEFGROUP", "CLOSE_WINDOW", "COMMENT_LINE", "CONTINUE_FOR", "CREATE_DB", 
  "CREATE_TABLE", "DEFAULT_NULL", "DEFAULT_TODAY", "DEFAULT_USER", 
  "DELETE_USING", "DISPLAY_FORM", "END_FUNCTION", "EXIT_DISPLAY", 
  "EXIT_FOREACH", "EXIT_PROGRAM", "INFCOLS", "ON_EVERY_ROW", 
  "OPEN_SESSION", "RIGHT_MARGIN", "SELECT_USING", "START_REPORT", 
  "UNLOCK_TABLE", "UPDATE_USING", "ACL_BUILTIN", "AFTGROUP", "INFIDX", 
  "INFSTAT", "LEFT_MARGIN", "PAGE_HEADER", "ROLLBACK_W", "SET_SESSION", 
  "SQLSEOFF", "WITH_A_LOG", "BEFDISP", "BEFORE_MENU", "CREATE_VIEW", 
  "DEFINE_TYPE", "DELETE_FROM", "END_DISPLAY", "END_REPORT", 
  "END_FOREACH", "END_FOR", "END_GLOBALS", "EXIT_PROMPT", "EXTENT_SIZE", 
  "FOREIGN_KEY", "HIDE_OPTION", "HIDE_WINDOW", "INSERT_INTO", 
  "IS_NOT_NULL", "MOVE_WINDOW", "NEXT_OPTION", "NOT_MATCHES", 
  "ON_LAST_ROW", "OPEN_WINDOW", "OPEN_STATUSBOX", "PAGE_LENGTH", 
  "PAGE_WIDTH", "PRIMARY_KEY", "PROMPT_LINE", "RECORD_LIKE", 
  "ROLLFORWARD", "SETBL", "SHOW_OPTION", "SHOW_WINDOW", "SQLSEON", 
  "TO_DATABASE", "USE_SESSION", "WITH_NO_LOG", "AFTDISP", "BEFFIELD", 
  "INSHARE", "UNLOCKTAB", "AFTFIELD", "ATTRIBUTES", "BEFINP", 
  "BEGIN_WORK", "CLEARWIN", "CLOSE_FORM", "DEFER_QUIT", "DESCENDING", 
  "DROP_INDEX", "END_PROMPT", "END_RECORD", "ERROR_LINE", "EXIT_INPUT", 
  "EXIT_WHILE", "FOR_UPDATE_OF", "FOR_UPDATE", "GET_FLDBUF", "INITIALIZE", 
  "INPUT_WRAP", "LOCK_TABLE", "MSG_LINE", "NOT_EXISTS", "ON_ANY_KEY", 
  "REFERENCES", "RENCOL", "SET_CURSOR", "SMALLFLOAT", "SQLSUCCESS", 
  "TOP_MARGIN", "WITH_ARRAY", "ACCEPTKEY", "ACCEPT", "AFTINP", 
  "CLEARFORMTODEFAULTS", "CLEARFORM", "CLEAR_X_FORM", "COMMIT_W", 
  "NEXTPAGE", "PREVPAGE", "CTRL_KEY", "INFTABS", "NEXTFIELD", "NEXTFORM", 
  "RENTAB", "ASCENDING", "ASSOCIATE", "CHAR", "NCHAR", "NVARCHAR", 
  "CONSTRUCT", "DELIMITER", "DOWNSHIFT", "DROP_VIEW", "END_INPUT", 
  "END_WHILE", "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", "FORM_LINE", 
  "INTERRUPT", "INTO_TEMP", "INVISIBLE", "IN_MEMORY", "LINKED_TO", 
  "LOAD_FROM", "LOCKTAB", "MENU_LINE", "OPEN_FORM", "OTHERWISE", 
  "PRECISION", "PRIOR", "PROCEDURE", "REPORT_TO", "RETURNING", 
  "UNDERLINE", "UNLOAD_TO", "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", 
  "AFTROW", "BUFFERED", "CONSTANT", "CONST", "DATABASE", "DATETIME", 
  "DEFAULTS", "DISTINCT", "END_CASE", "END_MAIN", "END_MENU", "END_TYPE", 
  "EXIT_FOR", "EXTERNAL", "FRACTION", "FUNCTION", "GROUP_BY", "INTERVAL", 
  "KWMESSAGE", "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "PASSWORD", 
  "PREVIOUS", "READONLY", "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", 
  "VALIDATE", "WITH_LOG", "WORDWRAP", "BY_NAME", "IN_FILE", "IS_NULL", 
  "AVERAGE", "BETWEEN", "CAPTION", "CLIPPED", "CLOSE_BRACKET", "COLUMNS", 
  "CONNECT", "CURRENT", "DBYNAME", "DECIMAL", "DECLARE", "DEFAULT", 
  "DISPLAY", "ENDCODE", "EXECUTE", "FOREACH", "FOREIGN", "GLOBALS", 
  "INFIELD", "INTEGER", "KWWINDOW", "MAGENTA", "OPTIONS", "PERCENT", 
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
  "FGL_ISDYNARR_ALLOCATED", "FGL_DYNARR_EXTENTSIZE", "FILLFACTOR", 
  "END_CLASS", "KW_CLASS", "EXTENDS", "$accept", "pause_screen_on_cmd", 
  "pause_screen_off_cmd", "start_rpc_cmd", "stop_rpc_cmd", "valid_port", 
  "remote_func_list", "remote_func", "arr_expr", "arr_next_math", 
  "arr_int_sign", "opt_attributes", "attributes_def", "@1", "attribs_sec", 
  "attribute", "win_attributes", "win_attributes_def", "@2", 
  "wattribs_sec", "wattribute", "call_cmd", "call_ext", "@3", "@4", "@5", 
  "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15", "@16", 
  "@17", "opt_return", "opt_return_remote", "opt_func_call_args", 
  "func_call_args", "func_arg", "remote_host_name", "remote_func_name", 
  "case_cmd", "@18", "@19", "when_unit", "when_unit_expr", 
  "end_case_command", "op_otherwise_command", "@20", 
  "op_otherwise_command_expr", "@21", "when_command", "@22", 
  "when_command_expr", "@23", "class_definition", "@24", "@25", "@26", 
  "op_extends", "class_entries", "class_entry", "close_cmd", "code_cmd", 
  "emb_code", "sql_code", "sql_code_part", "c_code", "c_code_part", 
  "construct_cmd", "@27", "@28", "constr_rest", "end_constr", 
  "constr_col_list", "constr_col", "constr_extra_commands", 
  "constr_extra_command", "@29", "@30", "@31", "@32", "@33", 
  "bef_c_field_list_as_struct", "aft_c_field_list_as_struct", 
  "interval_expr", "extend_parameters", "op_datetime_qual", "defer_cmd", 
  "define_section", "define_multiple", "define_set", "@34", "@35", 
  "def_part", "define_ident", "@36", "def_part2", "@37", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@38", "@39", "@40", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "record_variable", "@41", "@42", "@43", "link_to_pk_list", "link_to_pk", 
  "dtype_ident", "op_as_static", "dtype2", "@44", "@45", "dtype", "@46", 
  "@47", "@48", "op_prec", "like_var", "tab_name", "col_name", 
  "datetime_qual", "interval_qual", "dtime_start", "@49", "dtime_val", 
  "dtime_end", "@50", "opt_frac", "opt_unit_size", "dtfrac", "int_start", 
  "@51", "int_start_unit", "int_end", "op_equal", "dim_section", "@52", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@53", "@54", 
  "dim_record_variable", "@55", "@56", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@57", "@58", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@59", "@60", "@61", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "exit_prog_cmd", 
  "ext_cmd", "continue_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "boolean_expr", 
  "literal_expr", "variable_entry_2", "variable_entry", 
  "report_only_expr", "@62", "and_or_expr", "inexpr_list", "in_expr", 
  "null_expr", "string_match_expr", "clip_expr", "using_expr", 
  "math_expr", "comparison_expr", "reset_cnt", "function_call_expr2", 
  "@63", "@64", "@65", "@66", "@67", "@68", "function_callb", "@69", 
  "@70", "@71", "@72", "@73", "@74", "@75", "@76", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", 
  "field_name_list_as_struct", "field_name_list_or_char_as_struct", 
  "foreach_cmd", "@77", "@78", "@79", "opt_foreach_using_part", 
  "formhandler_def", "@80", "@81", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@82", "@83", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@84", "@85", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@86", "@87", "@88", "@89", "@90", "for_cmd", "@91", "@92", 
  "for_step", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name_as_struct", 
  "field_name_or_char_as_struct", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "field_name2_as_struct", "cvariable", "real_number", 
  "goto_cmd", "label_goto", "check_menu_cmd", "menu_item_list", 
  "menu_item", "uncheck_menu_cmd", "disable_cmd", "enable_cmd", 
  "msg_box_cmd", "@93", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@94", "@95", "op_else", "@96", "@97", "@98", "import_m", 
  "import_package", "module_import", "init_cmd", "@99", "init_tab_list", 
  "init_tab", "init_table_name", "end_input", "opt_defs", 
  "field_commands", "field_command", "@100", "@101", "@102", "@103", 
  "@104", "@105", "@106", "@107", "@108", "@109", "@110", "@111", "@112", 
  "bef_field_list_as_struct", "aft_field_list_as_struct", 
  "next_field_cmd", "next_form_cmd", "next_field", "input_cmd", "@113", 
  "inp_rest", "@114", "scroll_cmd", "up_or_down", "op_help", 
  "input_array_attributes", "input_array_attributes_int", 
  "on_key_command", "@115", "key_val", "@116", "accept_key", 
  "single_key_val", "key_do", "key_value_list", "key_value", 
  "key_value_1", "label_cmd", "let_cmd", "@117", "@118", "op_expr_null", 
  "linked_cmd", "linked_del_cmd", "linked_upd_cmd", "locate_cmd", 
  "module", "class_module", "trad_module", "@119", "op_module_header", 
  "module_header", "module_entry", "func_main_def", "func_or_main2", 
  "at_term_cmd", "func_or_main", "module_code", "op_code", 
  "module_define_section", "ldeffunction", "func_def", "@120", "@121", 
  "@122", "@123", "end_func_command", "main_def", "@124", "@125", 
  "return_cmd", "op_fgl_expr_list", "db_section", 
  "module_globals_section", "actual_globals_section", "xglobals_entry", 
  "globals_entry", "@126", "glob_section", "menu_def", "@127", "@128", 
  "menu_handler_elements", "menu_handler_element", "@129", "@130", 
  "menu_cmd", "@131", "end_menu_command", "menu_block_command", "@132", 
  "@133", "@134", "menu_commands", "opt_key", "menu_opt_name", 
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
  "prompt_cmd", "@135", "opt_timeout", "gui_prompt_cmd", "opt_char", 
  "prompt_key_sec", "prompt_key_clause", "on_key_command_prompt", "@136", 
  "prompt_title", "put_cmd", "@137", "put_from", "put_val_list", 
  "put_val", "start_cmd", "op_convert", "rout", "rep_name", "op_values", 
  "output_cmd", "finish_cmd", "term_rep_cmd", "report_section", 
  "format_section", "format_actions", "format_action", "@138", "@139", 
  "@140", "@141", "@142", "@143", "@144", "report_cmd", "need_command", 
  "@145", "op_lines", "skip_command", "@146", "opt_rep_expr_list", 
  "xrep_expr_list", "xxrep_expr_list", "opt_print_at", "print_command", 
  "@147", "pf_char_or_var", "print_file_command", "print_img_command", 
  "opt_scaling", "img_types", "blob_var", "opt_semi", "rep_expr_list", 
  "rep_expr", "rep_agg", "op_output_section", "output_commands", 
  "output_command", "pdf_output_commands", "nval", "nval_number", 
  "pdf_op_output_section", "pdf_output_command", "op_rep_order_by", 
  "report_def", "@148", "@149", "@150", "@151", "@152", "@153", 
  "rep_where", "pause_command", "pause_msg", "pdf_report_def", "@154", 
  "@155", "@156", "@157", "@158", "@159", "pdf_report_section", 
  "pdf_functions", "@160", "@161", "@162", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@163", "@164", 
  "@165", "@166", "opt_cr_table_extra", "cr_table_extra", 
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
  "@167", "ins_2_ss", "@168", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@169", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@170", "opt_foreach_into_fetch_part", "@171", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@172", 
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
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "s_curr", "e_curr", 
  "dbase_name", "flush_cmd", "declare_cmd", "@173", "@174", "@175", 
  "@176", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@177", "@178", 
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
  "sql_block_cmd", "@179", "sql_block", "sql_block_entry", "in_var", 
  "@180", "sql_block_into", "@181", "update_statement_ss", "@182", "@183", 
  "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "validate_cmd", 
  "@184", "validate_tab_list", "validate_tab", "var_ident", 
  "var2_as_string", "var2_vu", "var3_vu", "var4_vu", "var4_item_vu", 
  "var_ident_ibind_ss", "array_r_variable_or_ident_vu", 
  "arr_subscripts_al", "num_list_nl", "num_list_element_nl", 
  "whenever_cmd", "while_cmd", "@185", "@186", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "current_win_cmd", "window_type", "show_cmd", 
  "op_mnfile", "menu_name", "menu_handler", "hide_cmd", "move_cmd", 
  "NAMED", "commands", "all_commands", "command1", "commands_all", "@187", 
  "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1715,  1716,  1717,  1619,  1659,  1614,  1551,  1634,
    1431,  1537,  1533,  1448,  1609,  1350,  1407,  1479,  1645,  1632,
    1538,  1565,  1633,  1414,  1718,  1719,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1000,  1001,  1002,  1003,
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
    1344,  1345,  1346,  1347,  1348,  1349,  1351,  1352,  1353,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1408,  1409,  1410,  1411,  1412,  1413,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,
    1530,  1531,  1532,  1534,  1535,  1536,  1539,  1540,  1541,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1552,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1610,  1611,  1612,  1613,  1615,  1616,
    1617,  1618,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1635,  1636,  1637,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1646,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,
    1713,  1714
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   732,   733,   734,   735,   736,   737,   737,   738,   738,
     739,   740,   740,   740,   740,   740,   740,   741,   741,   741,
     741,   741,   742,   742,   743,   743,   745,   744,   744,   746,
     746,   747,   747,   747,   747,   747,   747,   747,   747,   747,
     747,   747,   747,   747,   747,   747,   747,   747,   748,   748,
     750,   749,   751,   751,   752,   752,   752,   752,   752,   752,
     752,   752,   752,   753,   754,   755,   754,   754,   754,   754,
     754,   756,   757,   754,   758,   759,   754,   760,   761,   762,
     754,   763,   764,   754,   765,   766,   754,   767,   768,   769,
     754,   770,   770,   771,   771,   771,   772,   772,   773,   773,
     774,   774,   775,   775,   776,   776,   778,   777,   779,   777,
     780,   780,   781,   781,   782,   783,   784,   783,   785,   786,
     785,   788,   787,   790,   789,   792,   793,   794,   791,   795,
     795,   796,   796,   797,   798,   798,   798,   798,   798,   798,
     799,   800,   800,   801,   801,   802,   803,   803,   804,   806,
     807,   805,   808,   808,   809,   809,   810,   810,   811,   811,
     811,   812,   812,   814,   813,   815,   813,   816,   813,   817,
     813,   818,   813,   819,   819,   820,   820,   821,   821,   821,
     821,   821,   821,   822,   823,   823,   824,   824,   825,   825,
     826,   826,   828,   829,   827,   827,   830,   830,   832,   831,
     833,   833,   833,   833,   833,   834,   833,   835,   835,   835,
     835,   836,   837,   837,   838,   838,   839,   839,   839,   839,
     841,   840,   842,   840,   843,   840,   844,   844,   845,   845,
     846,   847,   847,   847,   848,   850,   849,   851,   849,   852,
     849,   853,   853,   854,   855,   856,   856,   858,   859,   857,
     860,   860,   860,   860,   860,   860,   860,   860,   860,   860,
     860,   860,   860,   860,   860,   860,   860,   860,   860,   860,
     860,   861,   860,   862,   860,   863,   860,   860,   860,   860,
     860,   860,   860,   860,   860,   860,   864,   864,   865,   866,
     867,   868,   868,   869,   871,   870,   872,   872,   872,   872,
     872,   872,   872,   874,   873,   875,   875,   876,   876,   877,
     879,   878,   880,   880,   880,   880,   880,   880,   880,   881,
     882,   882,   884,   883,   885,   885,   885,   885,   885,   885,
     885,   885,   885,   885,   885,   885,   885,   885,   885,   885,
     885,   885,   885,   885,   885,   885,   885,   886,   888,   887,
     889,   887,   891,   890,   892,   890,   893,   893,   894,   895,
     895,   896,   897,   897,   897,   897,   897,   897,   897,   897,
     898,   899,   900,   902,   903,   901,   904,   904,   905,   906,
     906,   906,   907,   907,   909,   908,   910,   908,   911,   908,
     912,   913,   914,   915,   915,   916,   916,   917,   917,   917,
     917,   917,   917,   917,   917,   917,   918,   918,   918,   918,
     918,   918,   918,   918,   919,   919,   919,   919,   919,   919,
     919,   919,   919,   920,   920,   920,   920,   920,   920,   920,
     920,   920,   920,   920,   921,   921,   922,   922,   923,   923,
     924,   924,   925,   925,   926,   927,   927,   927,   927,   927,
     927,   928,   928,   928,   928,   929,   929,   930,   931,   931,
     931,   932,   931,   933,   933,   934,   934,   935,   935,   935,
     935,   936,   936,   937,   937,   937,   937,   937,   937,   937,
     937,   938,   939,   940,   940,   940,   940,   940,   940,   941,
     941,   941,   941,   941,   941,   941,   942,   944,   945,   943,
     946,   947,   943,   948,   949,   943,   951,   952,   950,   953,
     954,   950,   955,   956,   950,   957,   958,   950,   950,   950,
     950,   950,   950,   950,   950,   950,   950,   950,   950,   950,
     950,   950,   950,   950,   950,   950,   950,   950,   950,   950,
     950,   950,   950,   959,   959,   960,   961,   961,   961,   961,
     961,   961,   961,   961,   961,   962,   962,   963,   963,   963,
     963,   964,   964,   964,   965,   965,   966,   966,   966,   967,
     967,   967,   967,   967,   967,   967,   967,   967,   967,   968,
     968,   969,   969,   970,   970,   972,   973,   974,   971,   975,
     975,   977,   978,   976,   979,   979,   980,   980,   981,   981,
     983,   982,   984,   982,   985,   985,   986,   986,   988,   987,
     989,   987,   990,   991,   991,   991,   992,   992,   993,   993,
     994,   994,   995,   995,   997,   996,   998,   996,   999,   996,
    1000,   996,  1001,   996,  1003,  1004,  1002,  1005,  1005,  1006,
    1007,  1007,  1007,  1007,  1007,  1007,  1007,  1008,  1008,  1009,
    1010,  1011,  1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,
    1013,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1020,
    1021,  1022,  1023,  1023,  1024,  1024,  1025,  1025,  1025,  1025,
    1025,  1025,  1026,  1027,  1027,  1028,  1029,  1029,  1030,  1031,
    1031,  1032,  1033,  1034,  1034,  1034,  1035,  1035,  1035,  1037,
    1036,  1038,  1038,  1039,  1039,  1040,  1040,  1041,  1042,  1042,
    1043,  1044,  1044,  1045,  1046,  1046,  1047,  1048,  1048,  1050,
    1051,  1049,  1052,  1053,  1052,  1054,  1055,  1052,  1056,  1056,
    1057,  1058,  1060,  1059,  1059,  1061,  1061,  1062,  1062,  1063,
    1064,  1064,  1064,  1065,  1065,  1066,  1066,  1068,  1067,  1069,
    1067,  1070,  1067,  1071,  1067,  1072,  1067,  1073,  1067,  1074,
    1067,  1075,  1067,  1076,  1067,  1077,  1067,  1078,  1067,  1079,
    1067,  1080,  1067,  1081,  1081,  1082,  1082,  1083,  1084,  1085,
    1085,  1085,  1087,  1086,  1088,  1088,  1089,  1088,  1090,  1091,
    1091,  1091,  1091,  1091,  1091,  1092,  1092,  1093,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,  1094,  1094,  1096,  1095,  1095,
    1098,  1097,  1099,  1100,  1101,  1101,  1102,  1102,  1103,  1104,
    1104,  1104,  1104,  1104,  1104,  1104,  1104,  1104,  1104,  1104,
    1104,  1104,  1104,  1104,  1104,  1104,  1104,  1105,  1107,  1108,
    1106,  1109,  1109,  1110,  1111,  1112,  1113,  1113,  1114,  1114,
    1115,  1117,  1116,  1118,  1118,  1119,  1119,  1120,  1120,  1120,
    1120,  1120,  1120,  1120,  1121,  1121,  1122,  1122,  1123,  1124,
    1124,  1124,  1124,  1124,  1124,  1124,  1124,  1124,  1125,  1126,
    1126,  1127,  1128,  1128,  1130,  1131,  1132,  1133,  1129,  1134,
    1136,  1137,  1135,  1138,  1139,  1139,  1140,  1140,  1141,  1142,
    1142,  1143,  1145,  1144,  1146,  1146,  1146,  1146,  1148,  1149,
    1147,  1150,  1150,  1152,  1151,  1153,  1151,  1155,  1154,  1156,
    1158,  1157,  1159,  1157,  1160,  1157,  1161,  1161,  1162,  1162,
    1163,  1163,  1164,  1164,  1164,  1165,  1166,  1167,  1168,  1168,
    1168,  1169,  1169,  1170,  1170,  1171,  1172,  1172,  1172,  1172,
    1173,  1173,  1173,  1173,  1173,  1174,  1175,  1175,  1176,  1177,
    1178,  1178,  1179,  1180,  1180,  1180,  1180,  1180,  1180,  1181,
    1182,  1183,  1183,  1184,  1184,  1185,  1186,  1186,  1187,  1187,
    1188,  1189,  1190,  1190,  1190,  1190,  1190,  1190,  1191,  1191,
    1192,  1193,  1193,  1194,  1194,  1195,  1195,  1196,  1196,  1197,
    1197,  1197,  1197,  1197,  1198,  1198,  1199,  1199,  1200,  1200,
    1201,  1202,  1203,  1203,  1204,  1205,  1205,  1205,  1206,  1206,
    1207,  1207,  1208,  1209,  1209,  1210,  1210,  1211,  1212,  1213,
    1214,  1214,  1215,  1216,  1216,  1217,  1217,  1218,  1218,  1219,
    1220,  1220,  1221,  1221,  1221,  1221,  1222,  1222,  1222,  1223,
    1224,  1224,  1225,  1225,  1225,  1226,  1227,  1227,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1229,  1230,  1230,  1231,  1231,  1231,
    1231,  1231,  1232,  1234,  1233,  1235,  1235,  1236,  1237,  1237,
    1238,  1238,  1239,  1239,  1241,  1240,  1242,  1244,  1243,  1245,
    1245,  1246,  1246,  1247,  1247,  1248,  1248,  1248,  1248,  1249,
    1249,  1250,  1250,  1251,  1252,  1252,  1253,  1254,  1255,  1256,
    1257,  1257,  1258,  1258,  1260,  1259,  1261,  1259,  1262,  1259,
    1263,  1259,  1264,  1259,  1265,  1259,  1266,  1259,  1267,  1267,
    1267,  1267,  1267,  1267,  1269,  1268,  1270,  1270,  1272,  1271,
    1271,  1271,  1271,  1271,  1273,  1273,  1274,  1274,  1275,  1276,
    1276,  1278,  1277,  1279,  1279,  1280,  1281,  1282,  1282,  1282,
    1283,  1283,  1283,  1283,  1284,  1285,  1285,  1286,  1286,  1287,
    1288,  1288,  1288,  1288,  1288,  1288,  1288,  1288,  1289,  1289,
    1290,  1290,  1291,  1291,  1291,  1291,  1291,  1291,  1291,  1291,
    1291,  1291,  1292,  1292,  1293,  1293,  1293,  1293,  1294,  1294,
    1295,  1295,  1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,
    1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,
    1296,  1296,  1296,  1296,  1296,  1296,  1297,  1297,  1297,  1299,
    1300,  1301,  1302,  1303,  1304,  1298,  1305,  1305,  1306,  1307,
    1307,  1309,  1310,  1311,  1312,  1313,  1314,  1308,  1315,  1317,
    1318,  1319,  1316,  1320,  1320,  1320,  1320,  1321,  1321,  1321,
    1321,  1321,  1322,  1323,  1323,  1323,  1323,  1324,  1324,  1326,
    1327,  1325,  1328,  1329,  1325,  1330,  1330,  1331,  1331,  1332,
    1332,  1332,  1332,  1332,  1333,  1334,  1334,  1335,  1335,  1336,
    1336,  1337,  1337,  1337,  1337,  1337,  1338,  1338,  1339,  1339,
    1340,  1340,  1340,  1341,  1341,  1342,  1342,  1343,  1343,  1344,
    1344,  1344,  1345,  1345,  1346,  1346,  1346,  1346,  1346,  1346,
    1346,  1347,  1347,  1348,  1348,  1349,  1349,  1350,  1350,  1351,
    1351,  1352,  1353,  1353,  1354,  1354,  1355,  1356,  1356,  1357,
    1358,  1358,  1359,  1359,  1360,  1360,  1361,  1361,  1362,  1362,
    1363,  1364,  1364,  1364,  1364,  1364,  1364,  1364,  1364,  1364,
    1364,  1364,  1365,  1365,  1366,  1366,  1367,  1368,  1370,  1369,
    1372,  1371,  1371,  1373,  1373,  1374,  1374,  1375,  1375,  1376,
    1376,  1378,  1377,  1379,  1380,  1380,  1381,  1382,  1381,  1383,
    1384,  1383,  1385,  1385,  1385,  1385,  1385,  1385,  1385,  1385,
    1386,  1387,  1388,  1389,  1389,  1390,  1391,  1391,  1392,  1392,
    1392,  1393,  1394,  1395,  1395,  1396,  1397,  1397,  1397,  1399,
    1398,  1400,  1400,  1400,  1400,  1400,  1400,  1400,  1400,  1400,
    1400,  1400,  1400,  1401,  1401,  1401,  1401,  1402,  1402,  1402,
    1403,  1403,  1403,  1404,  1404,  1404,  1405,  1405,  1406,  1406,
    1406,  1406,  1406,  1406,  1407,  1407,  1408,  1408,  1409,  1409,
    1410,  1410,  1411,  1412,  1412,  1413,  1413,  1414,  1414,  1415,
    1416,  1417,  1418,  1419,  1419,  1420,  1420,  1421,  1421,  1421,
    1422,  1422,  1423,  1423,  1423,  1424,  1424,  1424,  1424,  1425,
    1426,  1426,  1427,  1427,  1428,  1428,  1429,  1430,  1430,  1430,
    1430,  1430,  1430,  1430,  1431,  1432,  1433,  1434,  1434,  1435,
    1435,  1436,  1437,  1438,  1438,  1439,  1440,  1441,  1441,  1442,
    1442,  1442,  1443,  1443,  1443,  1444,  1444,  1445,  1446,  1446,
    1447,  1447,  1448,  1448,  1449,  1449,  1450,  1450,  1451,  1451,
    1452,  1452,  1453,  1453,  1454,  1454,  1455,  1456,  1457,  1457,
    1457,  1457,  1458,  1458,  1459,  1459,  1460,  1460,  1461,  1461,
    1461,  1461,  1461,  1461,  1461,  1461,  1461,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1463,  1463,  1463,  1464,  1464,  1464,
    1464,  1465,  1465,  1465,  1466,  1466,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,
    1467,  1468,  1468,  1469,  1469,  1469,  1469,  1469,  1470,  1471,
    1472,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1474,
    1474,  1474,  1474,  1474,  1474,  1474,  1474,  1475,  1476,  1476,
    1476,  1477,  1477,  1478,  1478,  1478,  1479,  1480,  1480,  1480,
    1480,  1481,  1482,  1483,  1483,  1484,  1484,  1485,  1485,  1485,
    1485,  1485,  1485,  1485,  1485,  1486,  1486,  1486,  1486,  1486,
    1486,  1486,  1487,  1487,  1487,  1487,  1487,  1487,  1487,  1487,
    1488,  1488,  1488,  1489,  1491,  1490,  1492,  1490,  1493,  1490,
    1494,  1490,  1495,  1495,  1495,  1496,  1496,  1497,  1497,  1497,
    1498,  1498,  1499,  1499,  1500,  1502,  1503,  1501,  1504,  1505,
    1505,  1506,  1507,  1507,  1507,  1507,  1507,  1508,  1509,  1509,
    1510,  1511,  1512,  1512,  1512,  1512,  1513,  1513,  1514,  1514,
    1514,  1515,  1516,  1516,  1516,  1517,  1517,  1517,  1517,  1517,
    1517,  1517,  1517,  1518,  1518,  1518,  1518,  1518,  1518,  1518,
    1518,  1518,  1518,  1518,  1518,  1518,  1518,  1518,  1518,  1518,
    1518,  1518,  1518,  1518,  1518,  1519,  1519,  1520,  1521,  1522,
    1522,  1523,  1523,  1524,  1524,  1525,  1525,  1526,  1526,  1527,
    1528,  1528,  1529,  1529,  1530,  1531,  1531,  1531,  1532,  1532,
    1533,  1534,  1535,  1536,  1537,  1537,  1538,  1538,  1538,  1538,
    1538,  1538,  1539,  1539,  1539,  1539,  1540,  1540,  1541,  1542,
    1542,  1542,  1543,  1545,  1544,  1546,  1546,  1547,  1547,  1547,
    1549,  1548,  1551,  1550,  1553,  1554,  1552,  1555,  1555,  1555,
    1556,  1556,  1556,  1556,  1556,  1556,  1557,  1557,  1558,  1559,
    1560,  1560,  1561,  1561,  1562,  1562,  1563,  1563,  1563,  1564,
    1564,  1564,  1564,  1564,  1564,  1564,  1564,  1564,  1564,  1564,
    1564,  1564,  1564,  1565,  1565,  1565,  1565,  1565,  1565,  1565,
    1565,  1565,  1565,  1565,  1565,  1565,  1565,  1565,  1565,  1566,
    1567,  1567,  1569,  1568,  1570,  1570,  1571,  1571,  1572,  1573,
    1574,  1574,  1575,  1575,  1576,  1576,  1576,  1577,  1577,  1578,
    1578,  1579,  1580,  1580,  1581,  1581,  1582,  1583,  1585,  1586,
    1584,  1587,  1587,  1588,  1588,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1590,  1590,  1591,  1591,  1592,  1592,  1593,  1593,
    1594,  1595,  1596,  1597,  1597,  1598,  1599,  1599,  1600,  1601,
    1601,  1603,  1602,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,  1604,
    1604
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
       6,     0,     0,     9,     0,     0,     9,     0,     0,     0,
       8,     0,     0,    10,     0,     0,     9,     0,     0,     0,
      14,     0,     2,     0,     2,     1,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     0,     6,     0,     5,
       1,     2,     1,     2,     1,     0,     0,     3,     0,     0,
       3,     0,     4,     0,     4,     0,     0,     0,     9,     0,
       2,     1,     2,     1,     2,     2,     2,     1,     2,     2,
       3,     1,     1,     1,     2,     1,     1,     2,     1,     0,
       0,     5,     7,     8,     0,     2,     1,     3,     1,     3,
       3,     1,     2,     0,     4,     0,     4,     0,     3,     0,
       3,     0,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     0,     4,     1,     1,     0,     1,
       1,     2,     0,     0,     5,     1,     1,     3,     0,     2,
       4,     4,     4,     4,     2,     0,     4,     1,     1,     1,
       2,     1,     1,     3,     0,     1,     0,     1,     1,     1,
       0,     7,     0,     5,     0,    12,     1,     1,     1,     1,
       1,     5,     3,     1,     1,     0,     4,     0,     5,     0,
       7,     1,     3,     1,     1,     0,     1,     0,     0,     4,
       1,     1,     1,     1,     4,     4,     4,     6,     4,     6,
       1,     2,     1,     1,     1,     1,     4,     6,     1,     4,
       6,     0,     3,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     0,     3,     4,     1,
       1,     0,     3,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     0,     2,     0,     3,     0,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     1,     0,     5,     1,     1,     1,     4,     4,     6,
       1,     1,     1,     1,     4,     6,     1,     4,     6,     1,
       1,     1,     1,     1,     2,     2,     1,     4,     0,     7,
       0,    12,     0,     4,     0,     5,     1,     3,     2,     1,
       3,     1,     0,     2,     2,     1,     2,     5,     4,     2,
       4,     5,     3,     0,     0,    11,     0,     2,     1,     0,
       2,     1,     1,     2,     0,     3,     0,     3,     0,     3,
       2,     2,     2,     4,     5,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     1,     3,     4,
       4,     1,     1,     1,     1,     1,     3,     1,     2,     2,
       1,     0,     3,     2,     2,     1,     3,     4,     4,     5,
       5,     1,     1,     2,     2,     4,     4,     2,     2,     4,
       4,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     0,     0,     6,
       0,     0,     8,     0,     0,     8,     0,     0,     6,     0,
       0,     6,     0,     0,     6,     0,     0,     6,     5,     5,
       5,     5,     7,     7,     9,     9,     6,     8,    10,    10,
       7,     9,     8,    10,    12,    14,    14,    10,    12,    12,
       4,     4,     6,     0,     3,     1,     1,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     4,     4,     2,
       2,     2,     2,     2,     1,     1,     2,     1,     1,     1,
       2,     4,     6,     6,     3,     5,     5,     3,     1,     1,
       3,     1,     3,     1,     3,     0,     0,     0,     9,     0,
       3,     0,     0,    10,     0,     1,     0,     1,     1,     2,
       0,     3,     0,     3,     0,     1,     1,     2,     0,     3,
       0,     3,     3,     1,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     0,     3,     0,     3,     0,     4,
       0,     4,     0,     4,     0,     0,    11,     0,     2,     2,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     4,     6,     4,     3,     6,     3,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     4,     1,     1,     1,     4,     3,     6,
       3,     6,     1,     1,     2,     2,     1,     2,     2,     1,
       3,     1,     2,     2,     2,     4,     2,     2,     4,     0,
       8,     0,     1,     1,     1,     0,     1,     2,     0,     1,
       2,     0,     1,     2,     0,     1,     3,     0,     2,     0,
       0,     8,     0,     0,     3,     0,     0,     7,     5,     2,
       2,     2,     0,     5,     4,     1,     3,     3,     3,     1,
       0,     2,     1,     0,     1,     1,     2,     0,     4,     0,
       4,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     1,     3,     1,     3,     2,     4,     1,
       1,     1,     0,     4,     5,     6,     0,    10,     3,     2,
       2,     1,     1,     2,     2,     0,     2,     1,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     0,     3,     1,
       0,     3,     2,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     1,     1,     2,     2,     2,     3,     4,     1,     1,
       1,     0,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     0,     0,     0,     0,    13,     1,
       0,     0,     6,     2,     1,     2,     2,     2,     1,     1,
       2,     1,     0,     3,     2,     1,     1,     1,     0,     0,
       7,     1,     2,     0,     3,     0,     4,     0,     5,     1,
       0,     3,     0,     7,     0,     5,     1,     2,     0,     1,
       1,     1,     0,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     2,     2,     2,     5,     8,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     2,     3,     6,     1,     3,
       1,     1,     1,     3,     6,     9,     1,     1,     1,     1,
       2,     0,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     3,     2,     0,     1,     1,     1,     3,
       1,     3,     7,     0,     7,     0,     6,     3,     1,     3,
       1,     2,     5,     0,     7,     0,     2,     0,     1,     5,
       2,     5,     0,     5,     6,     4,     0,     1,     1,     5,
       0,     2,     0,     5,     4,     2,     1,     3,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     2,     4,     4,
       6,     2,     1,     0,    11,     0,     2,     5,     0,     1,
       0,     2,     1,     2,     0,     3,     1,     0,     4,     0,
       2,     1,     3,     1,     1,     4,     5,     5,     3,     0,
       1,     1,     1,     1,     0,     1,     7,     2,     2,     2,
       2,     2,     1,     2,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     1,     0,     4,
       1,     2,     2,     2,     0,     1,     1,     2,     2,     0,
       2,     0,     4,     1,     3,     3,     5,     0,     2,     4,
       1,     1,     1,     1,     1,     0,     1,     1,     3,     2,
       5,     2,     5,     5,     5,     5,     5,     5,     0,     2,
       1,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     0,     3,     2,     0,
       0,     0,     0,     0,     0,    15,     0,     2,     2,     0,
       1,     0,     0,     0,     0,     0,     0,    15,     2,     0,
       0,     0,    10,     0,     1,     3,     3,     2,     4,     3,
       3,     3,     1,     2,     2,     2,     2,     1,     1,     0,
       0,     8,     0,     0,     9,     0,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     0,     1,     1,     2,     2,
       2,     8,     2,     2,     4,     2,     0,     1,     1,     3,
       2,     2,     1,     1,     3,     1,     1,     2,     1,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     1,     3,     1,     3,     2,     4,     1,
       3,     1,     2,     4,     1,     3,     1,     1,     1,     2,
       3,     4,     2,     4,     0,     2,     2,     4,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       6,     6,     0,     1,     0,     1,     2,     1,     0,     5,
       0,     5,     1,     0,     3,     1,     3,     1,     3,     1,
       1,     0,     4,     1,     2,     1,     0,     0,     3,     0,
       0,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     3,     3,     1,     3,     2,     1,     1,     0,     1,
       1,     1,     1,     0,     1,     3,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     6,     4,     4,     1,     1,     1,
       0,     1,     2,     1,     1,     1,     1,     3,     2,     1,
       1,     2,     1,     1,     0,     3,     1,     3,     1,     3,
       1,     1,     6,     0,     3,     1,     3,     0,     1,     4,
       5,     2,     1,     1,     4,     1,     3,     4,     4,     4,
       1,     3,     1,     1,     1,     2,     1,     1,     1,     4,
       0,     1,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     3,     1,     3,     4,     0,     1,
       0,     1,     0,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     2,     2,     0,     2,     1,     1,     5,     3,
       5,     3,     1,     3,     1,     1,     0,     1,     3,     3,
       3,     6,     4,     4,     4,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     1,     4,     1,
       5,     5,     1,     1,     1,     1,     1,     4,     1,     4,
       6,     4,     1,     4,     1,     7,     1,     1,     1,     4,
       6,     0,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     5,     3,     5,     7,     3,
       1,     1,     3,     5,     3,     5,     7,     1,     0,     3,
       5,     1,     2,     2,     4,     3,     1,     1,     1,     1,
       1,     2,     2,     0,     3,     0,     3,     1,     1,     1,
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
       1,     1,     5,     5,     4,     5,     1,     4,     1,     1,
       7,     4,     1,     0,     4,     1,     2,     1,     1,     1,
       0,     3,     0,     3,     0,     0,     6,     0,     2,     2,
       7,     3,     3,     2,     2,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     2,     1,
       1,     2,     4,     5,     7,     7,     9,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     3,     5,     5,
       5,     5,     5,     4,     4,     3,     4,     1,     1,     1,
       1,     3,     0,     5,     1,     3,     3,     3,     1,     1,
       2,     1,     1,     3,     1,     3,     3,     1,     1,     1,
       3,     2,     3,     6,     1,     3,     1,     1,     0,     0,
       6,     0,     2,     0,     1,     1,     2,     2,     1,     1,
       4,     3,     1,     2,     5,     2,     2,     5,     0,     2,
       1,     1,     2,     6,     6,     1,     0,     1,     2,     1,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     853,     0,  1927,     0,     0,     0,     0,   902,   192,     0,
       0,   850,   878,   881,   190,   195,   860,   857,     0,   848,
     849,   851,   854,   855,   858,   862,   863,   861,   898,   899,
     901,   859,   148,   145,     0,   141,   143,   142,   146,  1955,
     730,   670,   731,   322,  1702,  1700,   896,   188,   198,   897,
     125,   191,     1,   864,   856,   900,   140,   144,   147,     0,
       0,   647,     0,     0,   189,   905,   967,   648,   906,   907,
     903,   682,   959,     0,   960,   968,   966,   198,   193,   211,
       0,   196,   212,   247,   129,     0,   883,  1261,     0,   882,
    1249,   890,     0,     0,   875,   874,   876,   852,   865,   866,
     884,   869,   870,   873,   871,   872,   877,     0,  1701,   961,
     904,     0,     0,   975,   973,   974,   963,   962,   320,   198,
    1185,   205,   199,   198,   204,   244,     0,     0,   126,   729,
       0,     0,     0,   188,   591,   908,   867,     0,   354,   340,
     214,   326,   291,   310,   331,   333,   330,     0,   352,     0,
     339,   332,   336,   342,   341,   198,   343,   323,   346,   324,
     325,   972,   971,     0,    22,    23,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   980,     0,   554,
     546,    16,   553,   967,    15,     0,   978,     0,   321,     0,
     197,  1186,   194,     0,   211,   213,   285,   216,   273,   279,
     280,   264,   237,   275,   214,   252,   253,     0,   239,   291,
     310,   262,   265,   260,     0,   235,     0,   271,   263,   268,
     278,   277,   198,   281,   198,   250,   251,   248,   284,   130,
     188,     0,     0,     0,   891,   188,   188,     0,     0,   215,
       0,     0,   344,     0,     0,   345,     0,     0,     0,     0,
       0,     0,     0,   289,     0,   969,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   560,
       0,     0,     0,   683,   451,   453,  1256,     0,     0,     0,
    1675,     0,   447,     0,     0,     0,   446,     0,   461,   556,
       0,     0,     0,     0,     0,   559,   414,   420,   457,   454,
     415,   416,   418,   419,   452,   455,   460,   555,   509,   506,
     515,   512,     0,     0,    17,    18,    19,    20,    21,     0,
      14,     0,   497,     0,     0,   976,     0,   200,   203,   201,
     202,     0,   208,   207,   206,   209,   217,   218,   219,   222,
     286,   198,   286,     0,     0,     0,     0,   198,   282,   283,
       0,     0,   198,     0,   286,     0,     0,   261,   245,   127,
    1262,     0,  1250,  1961,   592,   909,   885,     0,   226,   227,
       0,     0,   303,   305,   300,   301,   297,   299,   296,   298,
     295,     0,   305,   316,   317,   313,   315,   312,   314,   307,
       0,     0,     0,   356,     0,   359,   361,   234,     0,   233,
       0,   198,     0,     0,     0,   581,   652,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   578,   564,   569,     0,
     565,   568,   567,   661,     0,   660,   583,     0,    11,   184,
     445,   422,   421,     0,  1191,     0,     0,   459,  1683,  1681,
    1682,  1678,  1680,  1677,  1679,  1671,     0,     0,     0,   458,
       0,     0,     0,     0,     0,     0,     0,   684,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   561,   562,   563,   472,     0,     0,   471,   481,     0,
       0,   426,     0,     0,   427,   417,   423,   425,   428,   429,
     430,   431,   432,   424,     0,     0,     0,     0,     0,     0,
       0,    12,     0,    96,     0,   979,     0,   964,   210,     0,
       0,   274,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   272,     0,   198,   246,   249,     0,   991,
     728,   991,     0,  1959,  1961,  1185,  1802,   879,     0,   991,
       0,     0,   327,   292,     0,     0,   302,   319,   293,   318,
       0,   311,     0,   334,     0,   328,     0,   353,     0,   358,
     348,     0,     0,   337,   290,   347,   540,     0,     0,   552,
       0,     0,   549,   548,   551,   547,   558,   543,   543,     0,
       0,   543,     0,   566,     0,   570,     0,   310,     0,   550,
     557,   294,     0,  1257,  1742,     0,     0,     0,     0,     0,
     448,     0,     0,   462,     0,     0,     0,     0,   464,   463,
     482,   473,   488,   491,   492,   489,   495,   494,   493,   483,
     484,   485,   486,   487,   433,   474,   478,   496,   490,   477,
     496,   456,   510,   507,   516,   513,   541,     0,   503,   101,
     498,    97,    98,   100,   500,     0,     0,   247,     0,     0,
       0,   254,   255,     0,   258,     0,     0,   266,     0,   256,
     236,   220,     0,   269,   288,     0,   131,   133,   997,     0,
     992,   993,     0,   892,  1960,  1958,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1942,     0,  1377,  1376,     0,  1378,     0,   410,  1375,
    1292,     0,     5,  1374,   411,   408,     0,   413,   186,   496,
    1160,     0,     0,  1384,   137,   407,   406,     0,     0,   401,
     496,     0,  1328,  1935,     0,   412,   373,     0,     3,     2,
       0,   409,  1289,     0,     0,   402,   399,   395,     0,     0,
       0,     0,  1382,  1372,   405,     0,     0,     0,     0,     0,
       0,     0,     0,  1371,     0,     0,     0,   187,     0,   398,
     397,     0,     0,  1939,  1938,     0,     0,     0,   149,     0,
     404,   403,     0,     0,   400,   496,     0,     0,   496,     0,
     585,     0,     0,     0,     0,     0,     0,   496,   837,  1259,
       0,     0,  1171,     0,  1928,     0,   108,     0,     0,   917,
       0,     0,     0,     0,   838,     0,     0,  1833,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   699,     0,     0,
    1963,  1964,  1965,  1966,  1967,  1968,  1969,  1970,  1971,  1972,
    1973,  1974,  1975,  1976,  1977,  1978,  1979,  1980,  1981,  1982,
    1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,
    1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,  2002,
    2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,   946,
    2012,  2013,  2014,  2015,  2016,  2017,  2018,  2019,  2020,  2021,
    2022,  2023,  2024,  2025,  2026,  2027,  2028,  1151,  1153,  1148,
    1150,  1149,  1152,  2029,  2030,  1282,  2031,  1288,  1287,  2032,
    2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,  2041,  1439,
    2042,  2043,  2044,  2045,  2046,  2047,  2048,  2049,  2050,  1962,
     880,   596,     0,   913,     0,   911,     0,   355,   228,   229,
       0,   304,   309,     0,     0,     0,     0,   357,   360,     0,
     232,     0,     0,   582,     0,   656,     0,   658,     0,   521,
     519,     0,   543,     0,   520,     0,     0,   580,     0,   577,
     574,   545,   518,   584,     0,   183,  1744,  1745,  1743,     0,
     450,  1256,     0,  1676,  1256,   449,  1256,  1256,  1256,  1256,
    1256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,    96,   977,     0,
     223,   287,   238,     0,     0,   198,     0,     0,     0,     0,
     128,   132,     0,  1263,     0,  1251,   392,   390,   391,  1286,
    1086,  1085,  1091,     0,  1650,  1651,     0,     0,  1312,   671,
     672,  1313,  1642,  1643,  1315,   868,  1123,  1128,  1937,   664,
     136,  1950,     0,     0,  1327,     7,     0,     6,     0,  1943,
    1124,     0,  1219,  1218,  1163,  1217,  1162,   444,  1385,  1373,
       0,  1283,   893,   434,  1804,  1379,   138,     0,  1127,   135,
       0,   844,    24,   666,   396,     0,   843,  1119,   845,     0,
    1383,   939,   938,   941,   937,   940,  1952,     0,   935,     0,
     665,  1023,   936,  1946,     0,  1936,   134,  1285,  1020,   732,
    1018,     0,   662,  1931,   780,   779,   781,   777,     0,     0,
    1284,  1033,   667,  1438,     0,  1918,  1433,  1436,  1908,  1911,
    1912,  1914,  1917,     0,     0,     0,     0,  1092,  1087,     0,
    1072,  1073,  1074,  1075,  1081,  1083,  1082,  1080,  1079,     0,
       0,     0,  1078,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1064,  1055,  1056,  1006,
       0,  1004,  1106,   442,    24,     0,  1933,   139,   663,     0,
    1260,  1258,  1184,     0,  1793,     0,  1794,  1185,  1173,  1164,
    1386,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,   967,     0,    69,     0,   106,   639,     0,   686,   685,
       0,  1154,  1040,  1158,     0,     0,  1107,  1277,     0,     0,
    1161,   691,   688,   689,     0,   693,   694,     0,   696,   697,
       0,   692,  1001,  1003,     0,     0,  1002,   782,   999,   743,
     995,   958,     0,     0,     0,     0,   703,   704,     0,     0,
     956,   953,   954,   950,   951,   952,   945,   949,   948,     0,
       0,     0,     0,     0,     0,   600,   602,   594,   597,   598,
     915,  1961,   910,   912,   886,     0,   306,   308,   335,   329,
       0,     0,   338,   653,   655,     0,     0,     0,     0,   543,
     526,     0,   543,   543,     0,   571,     0,   303,     0,     0,
    1772,  1667,  1669,  1828,  1832,  1773,  1673,  1770,     0,     0,
    1769,     0,     0,     0,  1771,     0,     0,     0,     0,     0,
       0,     0,  1918,  1668,  1768,  1670,  1757,     0,  1746,  1748,
    1752,  1755,  1783,  1826,  1784,  1829,  1919,  1909,  1756,  1194,
    1684,  1193,  1192,  1195,  1197,  1196,  1190,   475,   476,   480,
     465,     0,   468,   479,     0,   467,   511,   508,   517,   514,
     542,   504,   499,    99,   501,   965,     0,   259,   243,     0,
     241,   267,   257,   247,   270,   998,   188,   994,   188,     0,
       0,     0,  1357,  1358,     0,     0,     0,  1329,  1332,  1334,
    1335,  1336,  1340,  1339,  1337,  1338,     0,     0,     0,  1330,
    1331,     0,     0,     0,     0,     0,     0,     0,     0,  1125,
       0,    24,  1214,  1216,  1215,     0,   437,   438,   435,   436,
    1011,     0,     0,   378,    25,   372,     0,  1120,     0,  1119,
       0,  1118,     0,     0,     0,     0,     0,     0,  1027,  1803,
       0,     0,     0,     0,     0,     0,  1933,     0,     0,   150,
       0,     0,  1037,  1029,  1030,  1035,     0,     0,  1910,     0,
    1921,  1434,  1435,     0,     0,   955,   440,  1902,  1050,   362,
       0,     0,   586,   644,   643,   641,   646,  1058,   645,  1063,
    1059,  1062,   836,   828,   822,   834,   835,   820,   821,   829,
     824,   830,   823,   833,   827,   831,   826,   832,   819,   825,
     812,   818,  1060,  1061,     0,  1068,  1076,  1065,  1066,  1070,
    1071,  1069,  1067,  1077,     0,     0,     0,   846,     0,     0,
       0,     0,     0,   792,   791,   788,  1934,  1941,    24,  1180,
    1181,  1182,  1183,  1177,     0,  1175,  1273,  1185,  1165,  1166,
    1169,  1187,  1929,     0,     0,     0,     0,   102,     0,   103,
       0,     0,     0,    77,     0,     0,     0,     0,   115,   110,
       0,   687,   944,     0,   943,     0,   496,  1156,     0,   986,
     987,  1010,   981,   982,   839,  1008,  1109,  1279,     0,  1281,
    1280,  1837,  1840,  1842,     0,  1835,  1838,  1839,   719,     0,
       0,     0,   708,   743,   743,   740,     0,     0,   744,     0,
      26,   707,   710,     0,   717,   713,   957,   947,  1800,  1801,
    1791,  1791,  1403,     0,     0,  1703,     0,     0,  1387,     0,
       0,  1388,  1431,     0,     0,  1432,     0,     0,  1742,     0,
    1401,     0,  1450,  1449,  1448,  1446,  1447,  1445,  1443,  1440,
    1530,  1529,  1441,  1442,  1451,  1724,  1444,  1807,  1806,  1805,
    1452,  1961,  1961,   613,   604,   595,     0,   599,  1961,   914,
     188,     0,   349,   231,     0,     0,   544,     0,   543,     0,
     530,   543,     0,   523,   522,     0,     0,     0,   576,   575,
     185,  1754,  1753,  1691,  1689,  1690,  1686,  1688,  1685,  1687,
    1672,     0,  1742,     0,     0,  1597,     0,     0,  1760,  1758,
    1759,  1597,  1597,  1597,  1597,  1761,     0,     0,     0,  1548,
    1732,     0,  1749,     0,     0,     0,     0,  1816,  1817,  1818,
    1819,  1820,  1821,  1764,     0,     0,     0,     0,   470,   469,
       0,     0,     0,   198,   240,   221,  1264,  1252,     0,     0,
       0,     0,     0,     0,  1504,  1503,  1502,  1364,     0,  1370,
    1366,  1368,  1359,     0,  1606,  1356,  1352,  1326,  1325,     0,
    1351,  1347,     0,  1343,  1341,     0,  1649,     0,  1652,  1654,
     675,     0,   674,  1641,     0,  1644,  1646,  1951,  1948,     0,
       0,  1293,   496,   370,  1314,     0,     0,  1290,  1042,  1121,
    1122,  1119,  1115,  1119,     0,   942,     0,     0,   649,     0,
       0,     0,  1021,  1019,   734,   735,     0,   739,     0,     0,
    1932,  1940,   778,     0,   154,     0,  1031,  1038,     0,     0,
    1046,  1913,  1926,     0,  1924,  1437,  1916,  1915,     0,     0,
       0,  1052,   365,     0,     0,     0,     0,    24,  1088,  1089,
     589,     0,     0,     0,   813,   814,  1057,  1007,  1005,   847,
     443,     0,  1098,   789,   793,   790,   794,   393,     0,  1185,
    1174,  1274,  1189,  1172,  1167,     0,     0,  1168,  1961,     0,
       0,     0,     0,     0,     0,     0,    64,    96,     0,     0,
       0,   121,   116,     0,   111,     0,   118,   112,   928,   920,
     926,     0,  1155,     0,  1157,  1159,     0,     0,   990,     0,
       0,     0,     0,  1108,  1278,     0,     0,  1834,  1836,  1961,
     690,   695,   698,   711,   709,   668,     0,   767,   765,   763,
     761,   771,   769,     0,     0,   759,   809,   757,   742,   753,
     751,   807,   783,     0,   745,   755,  1000,   996,     0,     0,
       0,     0,   716,     0,     0,     0,     0,     0,     0,     0,
    1657,     0,  1525,  1526,  1812,  1483,  1548,     0,     0,     0,
    1810,     0,  1463,  1458,  1457,  1470,  1469,  1474,  1474,  1472,
    1473,  1464,  1459,     0,     0,  1465,  1466,  1725,  1844,     0,
       0,     0,   601,   603,     0,     0,   616,   608,   610,     0,
     605,   606,     0,     0,   624,   626,     0,     0,   622,   916,
     887,   230,     0,   657,   659,   654,     0,   543,   532,     0,
     527,     0,     0,   543,   543,   573,   572,     0,     0,  1781,
    1673,     0,     0,  1756,  1599,  1600,  1598,     0,  1785,     0,
       0,     0,     0,     0,     0,     0,  1747,     0,  1536,  1537,
    1539,  1542,     0,  1549,  1550,     0,     0,  1597,  1734,  1728,
    1750,  1766,  1767,  1765,  1763,     0,     0,     0,  1920,   466,
     505,   502,     0,   242,  1220,  1198,     0,     0,     0,     0,
    1364,     0,     0,     0,  1360,     0,     0,     0,  1354,  1637,
    1635,  1604,  1616,  1618,  1622,  1624,  1615,  1609,  1614,  1628,
    1607,  1636,  1612,  1627,  1613,  1634,  1626,  1510,  1601,  1602,
    1603,     0,  1349,  1345,     0,     0,  1333,     0,     0,   673,
       0,     0,     0,  1947,     0,     4,     8,    10,     0,   496,
     439,     0,     0,     0,  1039,  1117,  1116,     0,     0,     0,
       0,     0,     0,     0,     0,   733,     0,     0,   171,   169,
       0,     0,   151,     0,   161,   167,   743,   156,   158,     0,
    1036,  1047,  1048,     0,     0,  1922,   441,     0,  1903,  1904,
    1051,     0,     0,  1049,   364,   369,   651,   363,     0,   366,
     371,     0,   496,  1409,   642,   640,     0,   816,  1097,  1099,
       0,   394,  1178,  1176,     0,  1188,  1170,     0,     0,  1269,
       0,     0,     0,   104,     0,     0,    78,    84,    74,    71,
    1961,  1961,   114,   109,   123,   119,     0,   113,   810,   929,
     668,  1961,   919,   918,   927,  1041,     0,     0,   988,   989,
     983,  1009,   496,  1114,  1110,  1111,  1113,  1841,  1843,   720,
     714,   712,     0,    24,     0,  1961,  1961,  1961,  1961,  1961,
    1961,   773,   747,   775,   749,  1961,  1961,  1961,  1961,     0,
     741,   746,  1961,   668,   805,   803,   806,   804,     0,     0,
      46,    44,    41,    35,    39,    43,    38,    31,    40,     0,
      34,    37,    32,    42,    33,    45,    36,     0,    29,    47,
     797,     0,   718,  1792,     0,  1790,  1742,  1788,  1729,  1730,
    1722,  1708,  1723,     0,     0,     0,  1084,  1524,  1527,     0,
       0,     0,  1421,  1393,  1815,  1814,  1813,     0,     0,     0,
    1468,  1471,     0,     0,     0,     0,     0,  1416,     0,  1415,
       0,  1417,  1412,  1413,  1414,  1405,  1406,     0,     0,     0,
     615,   620,     0,     0,  1961,  1961,   593,   607,   630,   618,
     632,  1961,  1961,   628,   612,   623,   879,   350,   543,     0,
     531,   543,     0,   543,   543,   525,   524,  1698,  1696,  1697,
    1693,  1695,  1692,  1694,  1674,     0,     0,     0,     0,  1782,
       0,     0,     0,  1780,     0,     0,     0,     0,  1762,  1779,
       0,  1540,     0,     0,  1666,  1543,     0,     0,     0,     0,
    1535,  1554,  1556,  1558,  1596,  1595,  1594,  1560,  1576,     0,
    1551,  1552,  1737,  1316,     0,     0,     0,  1827,     0,  1831,
     224,     0,  1246,  1265,     0,  1253,  1246,     0,  1658,     0,
    1492,     0,  1495,  1661,     0,  1500,     0,     0,  1361,  1362,
       0,     0,  1365,  1367,  1369,     0,  1353,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1508,  1507,  1506,
       0,  1511,  1512,     0,  1348,     0,  1342,  1344,  1653,     0,
    1655,  1645,     0,  1647,  1949,  1322,     0,  1318,     0,     0,
    1323,   894,     0,     0,     0,     0,     0,  1380,  1954,  1953,
     650,     0,     0,    48,     0,   736,   738,   737,  1381,   743,
    1961,  1961,   163,   676,   173,   165,   175,   155,   162,  1961,
       0,     0,     0,     0,     0,  1925,     0,     0,     0,     0,
       0,     0,  1090,     0,  1410,   587,     0,   815,  1095,     0,
    1275,  1276,  1930,     0,    96,     0,    65,     0,     0,     0,
      81,     0,    96,    96,    96,   122,   117,  1961,  1961,   107,
       0,   930,   924,   932,   931,   921,   637,   970,     0,     0,
       0,   722,   701,   715,   669,   784,     0,   768,   766,   764,
     762,   772,   770,     0,  1961,     0,  1961,   760,   758,   754,
     752,   808,   756,    24,   798,     0,     0,     0,    27,     0,
    1795,     0,  1709,     0,     0,  1721,  1704,  1720,  1528,     0,
    1485,     0,  1420,     0,     0,  1811,     0,  1808,     0,  1476,
    1480,  1456,  1478,  1481,     0,  1467,  1726,     0,     0,     0,
       0,     0,     0,  1845,  1419,  1418,  1407,  1402,  1404,  1455,
       0,     0,   617,   614,   609,   611,     0,  1961,  1961,   625,
     627,  1961,  1961,     0,   533,     0,   537,     0,     0,   529,
     528,     0,     0,     0,     0,     0,     0,  1778,  1786,  1774,
    1775,  1776,  1777,  1545,     0,  1538,  1544,  1559,  1563,     0,
    1576,  1562,     0,     0,  1577,  1589,  1590,  1587,  1593,  1592,
    1588,     0,     0,     0,     0,     0,  1591,     0,     0,     0,
    1532,  1533,  1751,     0,  1553,  1547,  1317,  1735,  1426,  1422,
    1423,  1428,  1427,  1733,  1316,     0,     0,  1244,  1245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1243,     0,     0,  1231,  1232,  1233,  1230,  1235,  1236,  1237,
    1234,  1221,  1212,     0,     0,  1268,     0,     0,  1207,     0,
       0,     0,     0,     0,     0,     0,  1199,  1200,     0,  1129,
    1662,     0,  1663,     0,     0,     0,     0,  1499,  1498,  1364,
    1497,  1489,  1355,  1638,     0,     0,     0,     0,     0,     0,
    1639,  1631,     0,     0,     0,  1631,  1667,  1505,  1518,  1523,
       0,  1520,  1517,  1519,     0,  1521,  1509,  1513,  1514,  1364,
    1350,  1346,     0,     0,  1321,  1320,     0,  1305,     9,     0,
    1295,   895,  1126,   376,  1295,     0,     0,  1945,     0,     0,
    1022,    49,     0,   795,   172,   170,     0,  1961,     0,     0,
       0,  1961,   168,   157,     0,   160,   159,     0,  1028,  1032,
       0,  1907,  1906,  1905,     0,     0,   368,     0,   590,     0,
    1961,   817,     0,   668,  1179,     0,  1270,    70,     0,     0,
     105,    68,    96,    79,    85,     0,     0,   124,   120,   811,
    1961,   934,   668,   933,     0,   634,     0,   841,   842,   840,
    1112,   725,   723,     0,   705,   702,     0,   774,   748,   776,
     750,   785,   801,   802,   799,   800,    30,    28,     0,  1789,
    1738,  1710,  1706,  1705,     0,  1484,  1742,  1487,     0,  1395,
    1390,  1389,  1392,     0,     0,  1475,     0,     0,  1738,     0,
       0,  1882,  1880,     0,     0,  1864,  1879,     0,     0,  1881,
       0,     0,     0,     0,     0,  1918,  1878,  1870,  1897,  1898,
       0,  1862,  1865,  1866,  1877,  1869,  1899,     0,  1855,  1854,
    1858,  1860,     0,  1853,     0,  1856,  1847,     0,     0,   621,
     619,   631,   633,   629,     0,     0,   543,     0,   543,   543,
       0,  1741,     0,  1674,     0,     0,     0,  1541,  1561,  1555,
    1557,  1564,  1566,  1564,     0,  1571,  1564,     0,  1569,  1564,
       0,  1579,  1578,     0,  1580,     0,  1531,     0,  1430,  1429,
    1425,  1736,     0,   247,  1238,  1239,  1240,  1242,  1225,  1223,
    1222,  1226,  1227,  1224,  1241,  1228,  1229,  1213,  1015,  1248,
    1012,     0,     0,  1266,  1211,  1210,  1205,  1203,  1202,  1206,
    1204,  1208,  1209,  1201,  1254,     0,  1490,  1496,  1665,  1658,
    1501,  1363,  1605,  1617,     0,  1619,  1621,     0,  1623,     0,
       0,     0,  1629,  1608,  1633,     0,  1491,  1493,     0,  1515,
    1516,  1656,  1648,  1319,     0,     0,  1311,  1306,  1307,  1324,
       0,  1302,  1303,     0,     0,  1316,  1296,  1297,     0,    24,
    1291,     0,     0,  1045,     0,    50,  1025,     0,    24,   174,
     164,     0,   678,   680,   176,   166,   795,     0,  1923,  1054,
       0,   367,  1411,     0,  1096,    24,     0,     0,    66,     0,
      82,    91,     0,    75,    72,   925,   922,   638,  1961,   984,
       0,  1961,   721,   700,   706,   668,  1799,     0,  1797,     0,
       0,  1711,  1707,  1486,     0,  1488,  1482,     0,  1394,     0,
    1809,  1477,  1479,  1454,     0,  1868,  1867,     0,     0,  1597,
       0,  1597,  1597,  1597,  1597,  1871,     0,     0,  1851,     0,
       0,     0,     0,  1884,  1852,     0,     0,     0,     0,     0,
       0,  1846,  1408,  1460,   889,   888,   351,   534,     0,     0,
     539,   538,  1699,  1822,  1825,  1823,  1546,     0,  1583,  1585,
       0,  1572,  1575,  1574,  1582,     0,  1584,  1564,     0,  1534,
    1424,  1830,   225,  1017,  1016,  1014,     0,  1247,  1130,  1134,
    1136,     0,  1140,     0,  1138,  1142,  1131,  1132,     0,     0,
       0,  1659,  1664,     0,     0,  1640,  1632,  1610,     0,  1611,
       0,     0,  1309,  1304,  1310,  1308,  1301,  1300,  1299,  1294,
    1298,   377,   374,     0,  1043,     0,     0,     0,  1024,   796,
     152,   677,    24,  1034,  1053,   588,  1093,    67,  1271,    87,
       0,     0,    80,    91,    91,    91,  1961,   635,     0,     0,
     724,   786,     0,  1796,  1739,  1732,     0,  1396,     0,  1732,
    1895,     0,     0,  1900,     0,     0,     0,     0,     0,     0,
       0,     0,  1863,  1886,  1887,  1885,  1883,  1861,     0,  1857,
    1859,  1848,  1849,  1461,     0,  1453,   543,   543,  1565,  1787,
    1567,     0,  1570,  1568,  1586,     0,  1013,  1961,  1961,  1144,
    1961,  1146,  1961,  1961,  1133,  1267,  1255,     0,  1620,     0,
    1630,     0,  1522,   379,  1044,  1944,     0,     0,     0,     0,
       0,     0,    55,     0,    54,     0,    52,     0,     0,   153,
    1100,    91,    96,    91,    92,    86,    76,    73,   923,     0,
       0,   726,    24,  1798,  1731,  1740,  1400,     0,  1397,  1399,
    1712,  1896,     0,     0,  1894,     0,     0,     0,     0,     0,
    1872,  1893,     0,  1462,   536,   535,  1573,  1581,  1135,  1137,
    1961,  1141,  1961,  1139,  1143,  1660,  1625,  1494,   381,   386,
     384,   375,     0,   382,   388,    57,    62,    59,    61,    58,
      60,    56,     0,    51,     0,   679,   681,  1104,  1094,     0,
    1102,  1272,    88,    83,   636,   985,  1961,   787,     0,  1391,
       0,  1713,  1727,  1892,  1901,  1888,  1889,  1890,  1891,     0,
    1873,     0,     0,  1145,  1147,  1961,  1961,   380,   383,  1961,
      53,     0,  1961,  1101,  1103,     0,   722,  1398,     0,  1717,
    1714,  1715,     0,     0,  1850,   387,   385,   389,     0,  1105,
      89,   727,     0,     0,     0,  1875,     0,  1874,  1026,    93,
       0,  1718,  1716,     0,    95,     0,    90,     0,  1876,    94,
    1719
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   840,   841,   842,   843,  1066,  2125,  2126,   187,   329,
     188,  1433,  1434,  1949,  2287,  3334,  2810,  2811,  3236,  3335,
    3336,   844,  1209,  2848,  2544,  3255,  2543,  3254,  1887,  2541,
    3101,  2852,  3250,  2542,  3102,  3342,  3445,  3469,  3252,  3476,
     660,   661,   662,  1558,  2202,   845,  1570,  1214,  1568,  1896,
    2213,  1893,  2211,  2216,  2548,  1569,  2210,  1897,  2547,    11,
      84,   240,   548,   128,   685,   686,   846,    12,    34,    35,
      36,    37,    38,   848,  1129,  1824,  1459,  2152,  2156,  2157,
    2153,  2154,  2817,  2821,  2509,  2501,  2500,  2502,  2505,   504,
     279,   612,   849,    63,    64,    14,    48,   120,    78,    79,
      80,    81,   203,   344,    82,    83,   250,   349,   235,  1028,
     529,  2706,   380,   950,  2012,   408,   409,   236,   362,   351,
     357,  1379,  1380,   124,   547,   125,   126,   368,   237,   364,
     350,   352,   531,   238,   264,   585,   252,   255,   253,   254,
     968,   563,   564,   566,   571,   953,   256,   257,   399,   568,
     199,    15,    59,   157,   158,   159,   959,  2643,   160,   260,
     248,   402,   403,   404,   405,  1847,   850,   851,   852,   853,
    1087,  3323,  3069,  1435,  3391,  3392,  3393,  3436,  3435,  3439,
     854,   855,   856,   857,   858,   859,   860,  1077,   505,  1082,
    1427,  1428,  1475,  1182,  1476,   306,   307,   308,   309,   310,
     462,   506,  1361,   507,   508,   509,   510,   511,   512,   513,
    1004,   189,   523,  1015,  1017,  1741,  1014,  1740,   190,   516,
    1010,   515,  1009,   518,  1012,   517,  1011,   969,   982,   311,
     312,   192,   313,   429,   430,   431,   432,   414,   434,   861,
    1149,  1850,  2840,  2183,    95,   245,   557,  1664,  1277,  1278,
    1279,  1661,  1662,  1999,  2000,  2001,  2344,  2345,  1665,  1666,
    1995,  2348,  2340,  2007,  2008,  2351,  2352,  2641,  2637,  2638,
     862,  3108,  3349,  2865,   863,  1487,    65,  1809,  1810,  2177,
     415,   436,  1121,  1187,  1058,  1109,  1092,  1131,  2243,   193,
    1059,  1049,  1781,  2504,    67,   314,   864,  1219,   865,  1232,
    1233,   866,   867,   868,   869,  1240,  2874,  1261,  3113,  1262,
    1923,  1263,  2240,  1264,  2562,  1265,  1952,   870,  1919,  2561,
    2873,  3111,  3110,  3416,    96,    16,    17,   871,  1453,  1814,
    1815,  1816,  1942,  1609,  1943,  1944,  2574,  2576,  2258,  2257,
    2262,  2256,  2255,  2248,  2247,  2246,  2245,  2250,  2249,  2252,
    2254,   872,   873,  1127,   874,  1605,  1247,  3352,   875,  1535,
    3078,  2289,  2290,  1945,  2259,  2219,  2550,  1176,  1515,  1854,
    2186,  1855,  1511,   876,   877,  1225,  1911,  2869,   878,   879,
     880,   881,    18,    19,    20,    53,    21,    22,    23,    97,
      98,   882,    99,    24,   941,    25,   100,   101,   137,   559,
    1670,  2356,  3165,   102,   133,   373,   883,  2482,    26,    27,
      28,    29,    30,    47,    70,   103,   246,   558,   944,   945,
    1281,  1668,   884,  1220,  2223,  1900,  2221,  3256,  2860,  1901,
    2220,  2553,  2862,   885,   886,   887,  1103,  1104,  1573,   888,
    1266,  1267,   889,  1617,  1268,   315,    72,    73,    74,    75,
    1580,   163,   116,    76,   113,   195,   196,  1581,  1582,  2230,
    1583,   689,   690,  1249,   691,  1250,  1180,  1181,  1584,  1585,
    1431,  3009,  3010,  3195,  1119,  1120,   890,  1448,  3238,   891,
    2829,   892,  1463,  1464,  1465,  1830,  1828,   893,   894,  2134,
    2163,   895,  1841,  2173,   896,  1177,  1178,   897,  1042,   898,
    2300,   899,  3340,  2843,   900,  2190,  3408,  3409,  3410,  3442,
    1184,   901,  1586,  1913,  2234,  2235,   902,  1441,  1801,  1057,
    1420,   903,   904,   905,  2425,  3013,  3206,  3207,  3307,  3308,
    3312,  3310,  3313,  3380,  3382,   906,   907,  1575,  1905,   908,
    1577,  1547,  1548,  1549,  1877,   909,  1199,  1197,   910,   911,
    1869,  1543,  1193,   202,  1550,  1551,   316,  2426,  2746,  2747,
    2731,  1074,  1075,  2422,  2732,  2735,   104,   132,   551,  1388,
    2075,  2748,  3209,   444,   912,  1191,   105,   130,   549,  1386,
    2074,  2736,  3208,  2423,  1213,  2534,  3097,  3341,  1872,   913,
     914,   915,   916,   917,  1090,  2132,  1068,  2128,  3065,  3066,
    3067,  3222,  3056,  3057,  3058,   918,  2697,  2476,  2477,  2479,
    1765,   919,   920,  1397,  1398,  1399,  1774,  2114,  1400,  2111,
    1771,  1401,  2087,  1766,  1402,  1403,  1404,  2079,  2084,  1405,
    1760,  1761,   921,  1099,  1079,   922,  1642,  1643,  1967,  2901,
    3129,  2604,  2898,  3357,  3358,  1644,  1989,  1623,  2336,  2627,
    2947,  2525,  2839,  2337,  1645,  1646,  2058,  2699,  2700,  2701,
    2990,  1647,  1648,  1472,   923,  1136,   924,  1274,  1649,  1650,
    1983,  3295,  1984,  1985,  1986,  2320,  2608,  2611,  2612,  1651,
    2310,  2599,  3126,  1754,  1755,  2785,  2429,  3046,  2430,  1756,
    2434,  1767,  2461,  1768,  2462,  2786,  2787,  2788,  2789,  1652,
    1961,  1962,  2307,  1653,  2694,  2410,  2690,  2053,  1719,  2048,
    2049,  2050,  2664,  1720,  2054,  2411,  2695,  2400,  2401,  2402,
    2403,  2404,  3178,  2971,  3298,  2405,  3180,  3181,  2688,  2406,
    2689,  2407,  2037,  2107,  2108,  2109,  3040,  2110,  2764,  2771,
    3216,  2431,  1046,  2613,  2752,  2940,  2433,  2395,  1334,   317,
    1335,  1700,   455,   456,  1701,  2374,    46,   925,   926,  2893,
    3122,  2592,  3121,  3422,  3450,  3451,  2596,  2301,  1654,  2302,
    2325,  2908,   615,  2297,  2298,  2059,  2413,  3120,  2897,  1336,
     989,  1337,  1338,  2691,  2408,  1340,  1341,  2039,  3300,   927,
     928,  1954,  2299,  2889,  3117,  3118,  1620,   929,  1085,  1656,
    1657,  1971,  2606,  1658,  1659,  2316,  1733,  2032,  1342,  1343,
    1344,  1345,   930,  1228,  1594,  1595,  1596,  1915,  1597,  1916,
    1660,  2326,  2946,  3161,  2623,  2943,  2944,  2945,  2942,  2930,
    2931,  2932,  2933,  2934,  2935,  3274,   931,  1839,  2168,  2169,
    1137,  1346,  1347,  1139,  1140,  1141,  1348,  1142,  1470,  1833,
    1834,    31,   933,  1201,  1878,  1456,  1537,   934,   935,  2493,
     936,  2123,  1062,  1788,   937,   938,    41,   552,   553,   554,
     555,   556,   939
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2837
static const short yypact[] =
{
     109,  1397, -2837,   314,   314,   314,  1473, -2837, -2837,  1473,
     314, -2837, -2837,    19, -2837, -2837, -2837, -2837,   347, -2837,
   -2837, -2837,   585, -2837, -2837, -2837, -2837, -2837,  -266, -2837,
   -2837, -2837, -2837, -2837,   374,   393, -2837,   382, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,  -221, -2837,   660,    59, -2837,
   -2837, -2837, -2837,   409, -2837, -2837, -2837, -2837, -2837,  -214,
     314, -2837,   314,   167,    19, -2837,  1006, -2837, -2837, -2837,
   -2837, -2837, -2837,   365,  -184, -2837, -2837, -2837,   493,   129,
     314, -2837, -2837,   548,  -105,   314, -2837, -2837,   314, -2837,
   -2837, -2837,   314,   314, -2837, -2837, -2837, -2837,   409, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837,  4749, -2837,  -184,
   -2837,   268,  4459, -2837, -2837,   449, -2837, -2837,   886,    59,
     396, -2837, -2837, -2837, -2837, -2837,  8903,   314, -2837, -2837,
     314,   451,   314,    19, -2837, -2837, -2837,   314, -2837, -2837,
     631,   568,   765, -2837, -2837,   634, -2837,   678, -2837,   502,
   -2837, -2837,   712, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,   728, -2837, -2837, -2837,   740,   775,   801,
     815,   833,   843,   858,   882,   907,   923,   935,  4459,   953,
    5172,   962,   991,  1004,  1029,  1038,  1048,  1828,  1014, -2837,
   -2837, -2837, -2837,   360, -2837,   192, -2837,  4459, -2837,   126,
   -2837, -2837, -2837,    80, -2837, -2837, -2837,   890, -2837, -2837,
   -2837, -2837, -2837, -2837,   631,  1066,  1086,  1089, -2837,   765,
   -2837, -2837,  1100, -2837,  1109, -2837,   737, -2837, -2837,  1118,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
      19,  1134,  1324,  1142, -2837,    19,    19,  1149,   314, -2837,
     563,  1347, -2837,   702,   967, -2837,   806,  1002,  1529,  1621,
     314,  1651,  1659, -2837,   995, -2837,   264,    42,    42,    42,
      42,    42,  5172,  1614,  1805,    61,  5172,  1060,  5172, -2837,
    5172,  5172,  5172, -2837, -2837, -2837,  1124,  1227,  1244,  5172,
    1083,  1255, -2837,  5172,  5172,  1262, -2837,  1267, -2837,   991,
    1270,  1284,  1287,  1297,  1762,  7574, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,  1319, -2837, -2837, -2837, -2837,
   -2837, -2837,   264,   264, -2837, -2837, -2837, -2837, -2837,  4459,
   -2837,   314, -2837,   314,  4459,  1285,   198, -2837, -2837, -2837,
   -2837,  1777, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
    1317, -2837,  1317,   563,  1783,  1792,  1795, -2837, -2837, -2837,
    1808,  1812,    59,  1651,  1317,  1818,  1198, -2837,  1759, -2837,
   -2837,  1456, -2837,  1492, -2837, -2837, -2837,  1243, -2837, -2837,
    1890,  1478, -2837,  1436, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837,  1002,  1436, -2837, -2837, -2837, -2837, -2837, -2837,  1442,
     128,   185,   242, -2837,  3184, -2837, -2837, -2837,  1448,  1927,
     189, -2837,  1489,  1453,   334, -2837,  -185,  1493,  1495,   435,
     440,  5997,  1497,  1498,   212,  1516, -2837, -2837,   218,  1501,
   -2837, -2837, -2837, -2837,   442, -2837, -2837,  6545, -2837,  3835,
    7685,  7628,  7628,  5172, -2837,  1430,  5172,  7574,  1466, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837,  1278,  1937,  6640,  7574,
    1430,  1938,   407,  5172,  5172,  5172,  5172, -2837,  5172,  5172,
    5172,  5172,  5172,  5172,  5172,  5172,  5172,  5172,  5172,  5172,
    5172,  5172,  5172,  5172,  5172, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,  5172,  5172, -2837, -2837,  1482,
    5172, -2837,  5172,  1484, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837,   264,  5172,  5172,  5172,  5172,  1515,
    1961,  1828,  1486,  3625,  1487, -2837,  4459,  1461, -2837,  1298,
    1948, -2837,  1304, -2837,  1952,  1540,  1541,   445,  1672,   446,
     456,   296,  1509, -2837,   460, -2837, -2837, -2837,   214,   314,
   -2837,   314,  1573, -2837,  5499,   396,  6028,  1960,   583,   314,
    1972,   -63, -2837, -2837,   967,  1967, -2837, -2837, -2837, -2837,
    1969, -2837,  1970, -2837,  1971, -2837,   314, -2837,   314, -2837,
   -2837,  1651,  1975, -2837, -2837, -2837, -2837,   314,    42, -2837,
    4459,    45, -2837, -2837, -2837, -2837, -2837,   967,   967,  1976,
    -138,   967,  1560, -2837,  1984,  1357,  1637, -2837,    61, -2837,
   -2837, -2837,  1565,  7574,   -82,  1566,  6743,  1989,  1083,  1570,
   -2837,  1571,  1574, -2837,  6801,  6848,  6909,  6962,  5459,  7598,
    7685,  3861,  7898,  8130,  7362,  3073,  4633,  3931,  5233,  7628,
    7628,  8012,  8012,  6736,  7574,  7413,  7480,  1430,  7574,  7524,
    1430, -2837,  7574,  7574,  7574,  7574, -2837,  1995, -2837, -2837,
   -2837,  2017, -2837,  7574, -2837,   221,  4459, -2837,  1577,  2004,
     -63, -2837, -2837,  2001, -2837,  1545,  2005, -2837,  2006, -2837,
   -2837, -2837,  2007, -2837, -2837,     4, -2837, -2837,  1358,  1589,
    2031, -2837,  1600, -2837, -2837, -2837,   264,   264,   264,   314,
     896,   314,  1640,   252,   252,  1648,   314,   314,   252,   252,
     314, -2837,  1640, -2837, -2837,   314, -2837,  1035, -2837, -2837,
   -2837,   252, -2837, -2837, -2837, -2837,   314, -2837, -2837, -2837,
   -2837,    83,    83,  5172, -2837, -2837, -2837,  1648,  1648, -2837,
   -2837,   252, -2837, -2837,   252, -2837, -2837,   314, -2837, -2837,
     252, -2837, -2837,   264,   252, -2837, -2837,  5172,   252,   264,
     314,   264,   252, -2837, -2837,   184,   252,   252,   184,   252,
     314,   184,   252, -2837,   252,   252,   252, -2837,  1640, -2837,
   -2837,   264,   252, -2837, -2837,   252,    41,   314, -2837,  1648,
   -2837, -2837,   252,   985, -2837, -2837,   264,  1370, -2837,   252,
   -2837,  5325,   264,  5172,    42,    42,   252, -2837, -2837,   896,
     264,   431, -2837,  5172, -2837,   582,  5172,   252,    64, -2837,
    5172,   252,  2025,   264, -2837,   252,  5172, -2837,  5172,    83,
     314,   252,   314,    42,   252,   314,    42, -2837,   314,   216,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,   519,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  1260,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837,   997,   314, -2837,   682, -2837,  1610, -2837, -2837, -2837,
    1701, -2837, -2837,  1612,  1617,  1618,  1619, -2837, -2837,  1385,
    2061,  1623,  1624, -2837,   240, -2837,  1584, -2837,  1394, -2837,
   -2837,   466,   967,  2046, -2837,  1635,   529, -2837,  2056, -2837,
    1443, -2837, -2837, -2837,  1409, -2837, -2837, -2837, -2837,  8500,
   -2837,  1124,  1641, -2837,  1124, -2837,  1124,  1124,  1124,  1124,
    1124,  2067,  2068,  2070,  5172,  1650,  2072,  5172,  1653,  1654,
    1656,  1660,  1665,  1667,  3625,  1676,  3625,  3625, -2837,   250,
   -2837, -2837, -2837,  1767,  1678, -2837,  1681,  1682,  1457,  1685,
   -2837, -2837,   314, -2837,   314, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,   528,  1471,   690,  1542,  1662, -2837, -2837,
   -2837, -2837,  1475,   778, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837,  2141,  1474, -2837, -2837,  1675, -2837,  1648, -2837,
    1630,   209, -2837, -2837, -2837,  1490, -2837,  7574, -2837, -2837,
    1519, -2837, -2837,  4381, -2837, -2837, -2837,   264, -2837, -2837,
    1648, -2837,   -24, -2837, -2837,  1842, -2837,   160, -2837,  1655,
   -2837, -2837, -2837, -2837,  2158, -2837, -2837,   667, -2837,  1502,
   -2837,  1503,  2158, -2837,  1523, -2837, -2837, -2837,  1700,   117,
   -2837,  1674, -2837,  1467, -2837, -2837, -2837, -2837,  1469,   262,
   -2837,  -256, -2837,  1517,  1669,  1679,  1807,  1543, -2837, -2837,
    1530, -2837, -2837,  5172,   137,  1000,  5172, -2837,   112,   252,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,    54,
      54,    54, -2837,    54,  2101,    54,    54,  1555,   -24,  1555,
    1555,  1018,  1018,  1555,  1555,   -24, -2837,  2199, -2837,  1732,
     420, -2837,  2202, -2837,   -24,   140,    51, -2837, -2837,  5172,
   -2837, -2837, -2837,  1195, -2837,  1049, -2837,   396, -2837,  5172,
   -2837,  5172,  1725,  1726,  1727,  1731,  1684,  1735,  1049, -2837,
    1815,  1037,    81, -2837,  1590, -2837, -2837,   314, -2837, -2837,
    1116, -2837,  2213, -2837,  2208,   314, -2837,   672,   253,  1596,
   -2837, -2837,  2219, -2837,  1518,  2219,  2220,  1521,  2219,  2220,
    5172,  2219, -2837, -2837,   209,   264, -2837, -2837,  1754,   898,
   -2837, -2837,  1746,   264,  5172,  1749, -2837, -2837,  2211,  2212,
    2119, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  1206,
    1206,   252,   252,   252,  2437, -2837, -2837,  2095,   997, -2837,
   -2837,   687, -2837, -2837, -2837,  1733, -2837, -2837, -2837, -2837,
    4749,  1651, -2837, -2837,  1572,   314,   967,  2216,   539,   967,
   -2837,   575,   967,   967,  1693,  1611,  1718, -2837,  8744,  8744,
   -2837,  1517, -2837, -2837, -2837, -2837,  1178, -2837,  8207,  1768,
   -2837,  1770,  1775,  1776, -2837,  1776,  1776,  1778,  1788,  1789,
    1791,   314,   543, -2837, -2837, -2837, -2837,   123, -2837,    56,
    1858, -2837, -2837,  1178, -2837,  1178,  1781, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
    7574,   464, -2837, -2837,   467, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837,  1751, -2837, -2837,   469,
   -2837, -2837, -2837, -2837, -2837, -2837,    19, -2837,    19,   948,
     164,  2234, -2837, -2837,   855,   361,   937,  2270, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837,   314,  1703,   314, -2837,
   -2837,  1721,   314,  1750,   314,   314,  1648,  1631,  1794, -2837,
    1799,   106, -2837, -2837, -2837,  1648, -2837, -2837,  2278, -2837,
   -2837,  1607,  1803, -2837, -2837, -2837,  1000, -2837,  1212,  2239,
    1212, -2837,  1049,   184,  5172,  5172,  5172,  1806, -2837, -2837,
     264,   264,  1648,  1613,  1049,    42,  1579,    41,   264, -2837,
    1620,  5172,  1882, -2837, -2837,  1686,   314,  1517, -2837,  4459,
   -2837, -2837, -2837,   314,  1268,  2288, -2837, -2837,  1627,   165,
     209,   264, -2837, -2837,  2279,  2280, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837,  2359, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837,  5325,   264,   264, -2837,  1018,  5172,
    -126,  1069,  1101, -2837, -2837, -2837, -2837, -2837,   116, -2837,
   -2837, -2837, -2837,  2091,  1854, -2837,  1865,   396,  5172, -2837,
      79, -2837, -2837,   314,  2282,    42,    42, -2837,  1663, -2837,
      61,  1634,   264, -2837,   314,   314,   314,  5172,   -85, -2837,
    1683, -2837, -2837,   867, -2837,  1790, -2837,  1793,  5172,  1224,
   -2837, -2837,  1646, -2837,  2300, -2837,  1714, -2837,   264, -2837,
   -2837, -2837, -2837, -2837,   236, -2837, -2837, -2837, -2837,   314,
      42,    42,   208,   898,  2118,  2506,   264,   209, -2837,  1728,
   -2837, -2837,  2288,  2299,  1875, -2837, -2837, -2837, -2837, -2837,
    1954,  1954, -2837,   791,  1736, -2837,   314,  1648, -2837,  1648,
    1648, -2837, -2837,  1648,  1648, -2837,   314,  1238,   -82,  1648,
   -2837,  1238, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837,   173,   173,   272,  1063, -2837,   823, -2837,   687, -2837,
      19,  2303, -2837, -2837,  1426,  1887, -2837,   230,   967,  2311,
   -2837,   967,  1757, -2837, -2837,  1895,  1896,  1771, -2837, -2837,
   -2837,  2034,  2034, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837,  1668,   -82,  1901,  8528,   591,  8500,  1825, -2837, -2837,
   -2837,   591,   591,   591,   591,  1680,  8500,  8500,   121,  1772,
     -64,   314, -2837,  8500,  8500,  8500,  8500, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837,  1677,   455,  1000,  5172, -2837, -2837,
    1903,  1906,  2303, -2837, -2837, -2837, -2837, -2837,  1870,  1872,
    1873,   824,  1874,  1876, -2837, -2837, -2837,  2246,   314, -2837,
    2355, -2837, -2837,   655,  4082, -2837, -2837, -2837, -2837,   314,
   -2837, -2837,   655,  1647, -2837,   528, -2837,  1690, -2837,  1722,
   -2837,  1919,  -184, -2837,  1695, -2837,  1730, -2837,  1780,  1885,
     314, -2837, -2837, -2837, -2837,  4381,   314, -2837,  1706, -2837,
   -2837,  2239, -2837,  2239,  1692, -2837,  2367,  2370, -2837,  2371,
    1752,  5172, -2837, -2837,  2376, -2837,  1711, -2837,  1850,  1709,
    2220, -2837, -2837,  1712,  1164,   314, -2837, -2837,  1908,   252,
    1062,  1530,  1828,   270, -2837, -2837, -2837, -2837,  5172,  1648,
    1000,  -201, -2837,   314,   314,  5172,    71,   -24,  2387,  1327,
    2386,  2372,  2373,  2101, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837,   264,  2023, -2837, -2837, -2837, -2837,  2277,  5172,   396,
   -2837,  2129, -2837, -2837, -2837,  5172,    83, -2837,  2024,  2399,
    2402,   470,   471,   314,  1962,  1049, -2837,  3625,  1926,  1932,
    1933, -2837, -2837,  2002, -2837,  5172,   499, -2837,  1784, -2837,
   -2837,   289, -2837,  5172, -2837, -2837,  1742,   268, -2837,  1483,
     314,  2409,  8326, -2837, -2837,  1000,   264, -2837, -2837,    47,
   -2837,  2220,  2220,  1715, -2837,  1826,  1829, -2837, -2837, -2837,
   -2837, -2837, -2837,    42,    42, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,  3028, -2837, -2837, -2837, -2837,    42,  9002,
    2426,  2410, -2837,  1049,   874,   300,   155,  2283,   -29,   896,
   -2837,   589, -2837, -2837, -2837,  1955,    96,  1648,   703,  1773,
   -2837,  1764, -2837, -2837, -2837, -2837, -2837,  1956,  1956, -2837,
   -2837, -2837, -2837,  1847,  1787,  2442, -2837, -2837, -2837,   560,
    1796,  1798, -2837, -2837,   264,   142, -2837, -2837, -2837,  1758,
    1063, -2837,   314,   314, -2837, -2837,   314,   550, -2837, -2837,
   -2837, -2837,  1985, -2837, -2837, -2837,   645,   967, -2837,   699,
   -2837,  2022,  2026,   967,   967, -2837, -2837,  1186,  8500, -2837,
     452,  2446,  2030,  2464, -2837, -2837, -2837,  8500, -2837,   476,
    8500,  8500,  8500,  8500,   314,   478, -2837,   410,  2465, -2837,
   -2837,    69,  7837, -2837,  2048,   314,  1810,   591,  2090, -2837,
   -2837, -2837, -2837, -2837, -2837,  1186,  2452,  1186, -2837,  7574,
   -2837, -2837,  2000, -2837,  1968,  1973,   156,   156,   156,   486,
    2246,   156,  7837,   314, -2837,   489,   314,   490, -2837, -2837,
   -2837,  2008,  2009,  2011,  1178,  1178, -2837,  2012, -2837,  2013,
    2014,  2016,  2018, -2837, -2837, -2837, -2837,  1115, -2837, -2837,
   -2837,   491, -2837, -2837,   494,   314, -2837,   314,  1774, -2837,
     314,  1779,  5172, -2837,   314,  2478, -2837, -2837,   655, -2837,
   -2837,  1813,   655,   197, -2837, -2837, -2837,  1049,  5172,  5172,
    5172,  4604,  2480,  1648,   135, -2837,  1049,   314, -2837, -2837,
     314,   314, -2837,   980, -2837, -2837,   915, -2837,  1817,  5172,
   -2837, -2837, -2837,  2481,  4459,  1979, -2837,  1831,  2495, -2837,
   -2837,  1049,  1877, -2837, -2837, -2837, -2837, -2837,   314,  2220,
   -2837,   209, -2837,  1899, -2837, -2837,   496, -2837, -2837, -2837,
     264, -2837,  4315, -2837,  1185, -2837, -2837,  2125,  2483, -2837,
    2110,  2112,  2015,  1845,  2113,  2035, -2837, -2837, -2837, -2837,
     557,  2108, -2837, -2837, -2837, -2837,  2002, -2837, -2837, -2837,
     260,   856, -2837, -2837, -2837,  2288,  5172,  2047, -2837,  2019,
   -2837, -2837, -2837, -2837,  2519, -2837, -2837, -2837,  2523, -2837,
    1827, -2837,  2505,   -24,   314,  4090,  4090,  4090,  4090,  4090,
    4090, -2837,  2528, -2837,  2532,  4090,  4090,  4090,  4090,  2359,
   -2837, -2837,  4090,   183, -2837, -2837, -2837, -2837,  2513,  2525,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  2527,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837,   505, -2837, -2837,
   -2837,  2516, -2837, -2837,  1648, -2837,   -82, -2837, -2837, -2837,
   -2837, -2837, -2837,  1897,  1898,   187, -2837,   589, -2837,   156,
    1878,   252, -2837,  2060, -2837, -2837, -2837,   314,   314,   156,
   -2837, -2837,   127,  1648,  1256,  8500,   213, -2837,  5172, -2837,
    5172, -2837, -2837, -2837, -2837, -2837,  1942,   252,   127,  1648,
    2543, -2837,   264,   314,   458,   458, -2837, -2837,  2544, -2837,
    2544,   579,   579,  2544, -2837, -2837,  1960, -2837,   967,  2534,
   -2837,   967,  1786,   967,   967, -2837, -2837,  2079, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,   123,  1178,  1886,  1178, -2837,
    1178,  2122,  8500, -2837,  2123,  2127,  2128,  2130, -2837, -2837,
     121, -2837,   121,   314, -2837, -2837,  8096,  1776,  7734,  1776,
    2559,  2570, -2837, -2837, -2837, -2837, -2837, -2837,   203,  8500,
   -2837,  2085, -2837,  2264,   150,   300,   314, -2837,  2143, -2837,
   -2837,  3118,   114, -2837,  1704, -2837,   114,  1648,   761,  2145,
    2582,  1922, -2837, -2837,   510, -2837,   522,   824, -2837, -2837,
     523,   415, -2837, -2837, -2837,   655, -2837,  2568,  2568,  2571,
    1921,   495,  2573,  2576,  2578,  2573,  2573, -2837, -2837, -2837,
     132, -2837,   799,   314, -2837,   655, -2837, -2837, -2837,  1925,
   -2837, -2837,  1934, -2837, -2837,   595,   525, -2837,   314,   530,
   -2837,  5172,  2160,  2591,   536,  1049,  2607, -2837, -2837, -2837,
   -2837,  5172,  2027,  2285,  5172, -2837, -2837, -2837, -2837,   915,
     990,   990,  2615,  -166, -2837,  2616, -2837, -2837, -2837,   990,
     314,  2028,  1531,  2617,   314, -2837,  4459,   141,  1648,  2619,
    1049,   -49,  2387,  5172, -2837, -2837,  2101, -2837,  1904,  5172,
   -2837, -2837, -2837,  2620,  3625,   264, -2837,  1035,   314,   264,
   -2837,  2178,  3625,  3625,  3625, -2837, -2837,   557,  2108, -2837,
    2359, -2837, -2837,  1236, -2837, -2837,  2020, -2837,  4459,  4872,
    8326,    72,  1113, -2837, -2837, -2837,  1958, -2837, -2837, -2837,
   -2837, -2837, -2837,    42,  4090,    42,  4090, -2837, -2837, -2837,
   -2837, -2837, -2837,   -24, -2837,  1225,  1263,  9002, -2837,  2184,
    2148,  8500, -2837,   155,   155, -2837, -2837, -2837, -2837,   542,
   -2837,  2109, -2837,   156,   574, -2837,  1957, -2837,   549, -2837,
   -2837,  2630, -2837, -2837,  2038, -2837,  2632,  5335,  5335,  5335,
    5335,   156,   156, -2837, -2837, -2837, -2837, -2837, -2837,  2630,
    1963,   264, -2837,  2544, -2837, -2837,   314,   579,   579, -2837,
   -2837,   579,  2377,  1966, -2837,   713, -2837,  2198,  2200, -2837,
   -2837,  2621,  2203,  1977,  1186,  1978,  1980, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837,   552, -2837, -2837, -2837, -2837,   423,
     237, -2837,  7837,  7837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837,  8744,  8744,  2173,  8744,  2175, -2837,  8744,   581,  8500,
    2654, -2837, -2837,  7837, -2837, -2837, -2837, -2837, -2837,  2655,
   -2837,   601, -2837, -2837,  2264,  1986,  1987, -2837, -2837,    83,
      83,    83,  2636,    83,    83,    83,    83,    83,    83,  2639,
   -2837,  2640,    83, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837,  3118, -2837,   264,  1997, -2837,  2169,  2646, -2837,  2647,
    2648,  2650,  2651,  2656,  2657,  1258,  1704, -2837,  2169, -2837,
   -2837,  2659, -2837,  2330,   156,  1554,   156, -2837, -2837,  2246,
   -2837, -2837, -2837, -2837,  2241,  2242,   553,  1186,  2663,  1186,
   -2837,  2686,   554,  2248,  2249,  2686, -2837, -2837, -2837, -2837,
    1648, -2837, -2837, -2837,  2214, -2837, -2837,   799, -2837,  2246,
   -2837, -2837,   314,   314, -2837, -2837,   314,  -377, -2837,   655,
     166,  2288, -2837,  2176,   166,   243,  1049, -2837,  2693,  2217,
   -2837, -2837,  2253,  2100, -2837, -2837,   314,   990,  4459,  1567,
     314,   990, -2837, -2837,    42, -2837, -2837,  5172, -2837, -2837,
     291, -2837, -2837, -2837,  1049,  2696, -2837,    42,  2288,   264,
    2407, -2837,  2679,  1826,  7574,  2681, -2837, -2837,   209,  2228,
   -2837, -2837,  3625, -2837, -2837,  2267,  2268, -2837, -2837, -2837,
     856, -2837,  1826, -2837,  5172, -2837,   326, -2837,  2202, -2837,
   -2837, -2837, -2837,  2222,  2310, -2837,  2698, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,   314, -2837,
     133, -2837, -2837, -2837,   156, -2837,   -82,  2526,   561, -2837,
   -2837, -2837, -2837,   314,   156, -2837,   127,   127,  2114,  1390,
    1390, -2837, -2837,  8570,  2238, -2837, -2837,  2244,  2250, -2837,
    2251,  2252,  2255,  2261,   314,   707, -2837, -2837, -2837, -2837,
     562, -2837, -2837,  2117, -2837, -2837, -2837,   584,  2724,  2724,
   -2837, -2837,   588,  2726,  2718, -2837,   319,   264,   127, -2837,
   -2837, -2837, -2837, -2837,  2471,  4749,   967,  1809,   967,   967,
    2302, -2837,  1186,  2304,  1186,  1186,   121, -2837, -2837,  2570,
   -2837,  2260,  1858,  2260,   406, -2837,  2260,   406, -2837,  2260,
    8744, -2837, -2837,  8500, -2837,  8500,  2559,   150, -2837, -2837,
   -2837, -2837,  1186, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,   680,  2744,
   -2837,   264,  1633, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,   338, -2837, -2837, -2837,  2245,
   -2837, -2837, -2837, -2837,  2729, -2837, -2837,  2313, -2837,  2731,
    2314,  2735, -2837, -2837, -2837,  2316, -2837,  2281,  7837, -2837,
   -2837, -2837, -2837, -2837,   314,  2737, -2837,  -377, -2837, -2837,
    2739, -2837, -2837,  2740,   314,  2264,   166, -2837,    42,   -24,
   -2837,  2339,  1049, -2837,  5172, -2837,  2149,  2745,   -24, -2837,
   -2837,   359, -2837, -2837, -2837, -2837,   193,  2324, -2837, -2837,
    1049,  2220,  2523,  2479, -2837,   -24,  2326,  2328,  2387,  2292,
   -2837,  2378,  2334, -2837, -2837, -2837, -2837, -2837,  2486,  2265,
    5172,  2291, -2837, -2837, -2837,  1826, -2837,   593, -2837,   264,
    2187, -2837, -2837, -2837,  8500, -2837, -2837,   156, -2837,  2308,
   -2837, -2837, -2837,  2630,  2187,  2099,  2099,  2340,  8528,   591,
    8646,   591,   591,   591,   591,  -121,  8646,  5335, -2837,  8646,
    8646,  8646,  8646, -2837, -2837,   156,  2773,   156,  5335,   252,
    7837, -2837,  2523,    73, -2837, -2837, -2837, -2837,  2346,  2348,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837,   132, -2837, -2837,
     603, -2837, -2837, -2837, -2837,   606, -2837,  2260,  2788, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837,   264,  2744, -2837, -2837,
   -2837,   264, -2837,   264, -2837, -2837,  2003, -2837,  2504,  2508,
    2772, -2837, -2837,  2353,  2131, -2837, -2837, -2837,  2356, -2837,
     156,   430, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,  1049, -2837,  2358,  8947,  2323, -2837, -2837,
   -2837,  2138,   -24, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
    2364,   209, -2837,  2378,  2378,  2378,   856, -2837,  4459,  2185,
   -2837, -2837,   314, -2837,  2523,   -64,   123, -2837,  8392,   -64,
   -2837,  2365,  8646, -2837,   607,  8646,  8646,  8646,  8646,  2789,
     314,   609, -2837, -2837, -2837, -2837, -2837, -2837,  2331, -2837,
   -2837, -2837,  2559, -2837,   314, -2837,   967,   967, -2837, -2837,
   -2837,   175, -2837, -2837, -2837,  8500, -2837,  1398,  1398, -2837,
    1398, -2837,  1398,  1398, -2837, -2837, -2837,  2341, -2837,  1186,
   -2837,   611, -2837,  1072, -2837, -2837,    54,    54,    54,    54,
      54,    54, -2837,  2793, -2837,   612, -2837,  5172,  1575, -2837,
     648,  2378,  3625,  2378,  2387, -2837, -2837, -2837, -2837,  2524,
     345, -2837,   -24, -2837, -2837, -2837, -2837,   617, -2837, -2837,
    1524, -2837,  2379,  8646, -2837,  2380,  2381,  2382,  2383,   371,
    2312, -2837,  5335, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
    1398, -2837,  1398, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837,  1242, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837,  8947, -2837,  2819, -2837, -2837, -2837, -2837,   961,
   -2837, -2837, -2837, -2837, -2837, -2837,    47, -2837,  8392, -2837,
    1864, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  2806,
   -2837,  2811,   618, -2837, -2837,  1382,  1382, -2837, -2837,  1382,
   -2837,  5172,   984, -2837, -2837,  2392,    72, -2837,  2168,  2170,
    2835, -2837,  2369,   389, -2837, -2837, -2837, -2837,  2397, -2837,
   -2837, -2837,   314,   314,  1864, -2837,  2818, -2837, -2837,   -52,
    2180, -2837, -2837,  2375, -2837,   209, -2837,   314, -2837,  2387,
   -2837
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2837, -2837, -2837, -2837, -2837,   312, -2837,   379,  -170, -2837,
   -2837, -1141,     7, -2837, -2837, -1874, -2837, -2837, -2837, -2837,
    -550, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -1883, -2837,
    -978, -2837,  1843, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
     642, -2837, -2837, -2837, -2837,  1292, -2837,   966, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,  2179, -2837,   -38, -2837, -2837,
    2828, -2837,  2829, -2837, -2837, -2837, -2837, -2837,   721,   363,
   -2837,   716, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,  -110,  1232,   320, -2837, -2837,  2509,   -11,
   -2837,  2751, -2837, -2837,  2753, -2837,  2660, -2837, -2837, -2837,
   -2837, -2837,  2530,  2207,  1136,  2517,  -520, -2837, -2837, -2837,
   -2837, -2837,  1138,  -655, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837,    37, -2837,  2652,  2342,  2669,   101,  2284, -2837,
    -206,  1582, -2837,  2487, -2837, -2837, -2837, -2837,  2499, -2837,
   -2837, -2837, -2837,  -391, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837,  2317, -2837,  2319, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -1191, -2837, -2837,  -498, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837,  -109, -2837, -2837,
    1104, -2837, -1122, -1163,   381, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837,  1905, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
    -603, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  2087, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837,  -556, -2837,  -102,
   -2837, -2837, -2837, -2837,  2489, -2837, -2837,  -253, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
    1638, -2837, -2837, -2837, -2837,   908, -2837, -2837, -2837, -2837,
   -2837, -1778, -2837, -2837,   904, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -1131,  -610,   777,  1070, -2837,
    -264,  -559,   613, -1133,  1196, -2837,   905, -2837, -2170,    -3,
    -292, -2837, -2837, -2028,   454,  1538, -2837, -2837, -2837,   698,
    1306, -2837, -2837, -2837, -2837, -2837, -2837,   356, -2837,    46,
   -2837,  1320, -2837,   996, -2837,   683, -2837, -2837, -2837, -2837,
    -522, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
     782, -2837, -2837, -1550, -2837,   983, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,  1470, -2837, -2837, -2837, -2837, -2837, -2837,
    -153, -2837, -2837, -1750, -2837, -2837, -2837, -2837,   509, -1385,
   -2837, -1137, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  2912, -2837,
   -2837, -2837,  2837,  2889,   596, -2837, -2837,  -212, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  2890, -2837,
   -2837,  2910, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  2021,
   -2837, -2837, -2837, -2837, -2837,  1040, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837,  -667,  2182, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,  2232, -2837, -2837,   -37, -2837,
   -2837,  1032, -2837, -2837,  1377,  -188,  2623, -2837, -2837, -2837,
   -2837,   637, -2837, -1057,  1924,  1352, -1461,  1438, -2837,  1052,
    1723,   -42,  -226, -2837,  2177,  1525, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837,  1451, -2837,  -778, -2837,
    -621, -2837, -2837, -2837, -2837, -2837, -2837, -2837,  -437, -2837,
   -2837, -2837, -2837, -2837, -2837,   418, -2837,  -753,  1539,   517,
   -2837, -2837, -2837, -2837, -2837,   233, -2837,  -223, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,  1444, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,  -527, -2837,  1111,  2533, -2837, -2837,   244,
   -2837,  -558, -2837, -2837,   265,   572, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837,   899, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,   195, -2837,
     -65,   -62, -2837, -2837,   -53, -2837, -2422, -2837,   210,   877,
   -1355, -2837, -2837, -2837,  1237, -2837, -1693, -2837, -2837, -2837,
   -1702, -2837, -2837, -1676, -2837, -2837, -2837, -2837, -2007, -2837,
    1253,   928, -2837, -2837, -2837, -2837, -2837,   710, -2837, -2837,
   -2837, -2837, -2837, -2837,  -402, -2837, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,    30, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837, -2837,
    1378, -2837,  1379, -2837,   697,  1044, -2837, -2228,   118, -2837,
   -2837, -2837, -2837, -2837, -2837,   273, -2837, -2837,  -197, -2837,
    -596, -1349, -2837, -2837, -2837, -2837, -2837,   238, -2837, -2837,
   -2837, -2837, -2837, -1667, -2837, -2837, -2837, -2837, -2837, -2837,
   -2112,   982, -2837, -2320,  1061, -2837, -2837, -2045,   358,   362,
     636, -2837, -1887, -1646, -2837, -2837,    62,  -265, -2837, -2837,
   -2837, -2837, -1598, -2837, -2837, -2837,   263, -2837,   592,  -572,
   -2837,  -686,  -360,  1418,    17, -1871,   621,   656,    33, -2837,
   -2837, -2837, -2837,  2432, -1243, -1973,  3042, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837,  -412, -2837, -1578, -2837,  1782,
   -2837, -2837,   527,   638, -2837, -2199,   641,   146,   457, -1042,
   -1605, -1990,  1341,    74,    48, -1287, -2837,  1344, -2837, -2837,
   -2837,  1441,  -632, -2837, -2837,  -199,  1797, -2837,   753, -2837,
   -2837,   746,   163, -2837, -2837, -2837, -1824,   -70, -1295, -2837,
    -697, -2837, -2837, -2837, -2837,  1485, -2837, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837, -2490,   -81, -2837, -2556,
   -2836, -1656, -1009, -2837, -2837,   -74, -2837, -2837, -2837,   559,
   -1087,  1350,  -747,  1964,  1636,  1622,   465, -2837, -2837,   587,
     933,    88, -2837, -2837, -2837, -2837,  1643, -2837, -2837, -2837,
   -2837, -2837, -2837, -2837, -2837, -2837,  -172,  1286,  2546, -2837,
   -2837, -2837, -2837
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1958
static const short yytable[] =
{
      40,    42,    43,    45,   417,   418,    45,    50,   277,   336,
     191,   435,  1020,   579,  1421,    94,  1482,   419,   420,  1054,
    1849,  1691,  1692,   244,  1479,   109,  1538,  1510,   695,  1489,
    1490,  1190,  1491,  1987,  1512,  1513,  1371,  2441,  2375,  1374,
    1757,  1773,   970,  1530,    66,   974,  1138,  1007,   390,   983,
    2552,  1080,  1081,  1925,  1926,  2652,   588,   108,  1478,    66,
      94,   960,  2937,  2938,  2939,   965,   118,  2112,    39,    39,
     115,   305,    39,  2439,  2155,  2288,   191,   122,  2906,  2113,
    1483,    39,   129,    39,  1875,   131,   433,  2088,    39,   134,
     135,    39,  2417,  2583,  2419,   191,    39,  2028,    39,   341,
    1734,  1108,  1735,  1130,   283,   342,   343,   283,    66,  1072,
    2629,  1607,   204,  2040,  2041,  2042,  2043,  1565,  1602,    86,
    1480,  1529,  1451,  2506,   239,  2304,  1071,   241,  1717,   243,
     369,  2941,  1612,   572,   247,   374,   375,  1083,  1717,     1,
    1625,   106,  1451,     2,   263,   588,  1052,  2342,    39,     3,
     283,   337,   338,    39,    39,  2496,   283,  2776,  1312,   521,
    1052,  2831,    39,   421, -1956,  3474,  1052,   437,    39,   439,
    1838,   440,   441,   442,  1076,  1052,  2698,    39,  1148,  1198,
     447,  1052,    39,    39,   458,   459,   106,  1603,   588,  2871,
     574,    39,  1143,     7,   582,  1146,   339,   334,   588,   283,
    1311,  1312,    39,   334,  1189,  2432,  2435,  2435,  1437,  1101,
    2435,    39,  2674,  1838,    39,  2675,  2676,  2677,  2678,  2679,
    2680,   263,  1194,   367,    39,  2350,   334,   191,  2353,  3060,
    1793,   599,   191,   283,  1242,  1243,    39,   604,   600,     4,
     283,  1242,  1243,    39,   605,   377,  2674,   576,  3071,  2675,
    2676,  2677,  2678,  2679,  2680,   334,  2016,   406,   324,   325,
     326,   327,   328,    66,   416,   416,   416,   416,   416,  1591,
    3293,  1230,   416,  2497,  1861,  2164,  1531,  1532,  2663,    39,
    2665,  1708,  2991,  1709,  1710,  2551,  1591,    39,  1842,    39,
    1843,    39,  1844,   161,  2308,    39,  2164,  3054,    62,    39,
    2311,   119,  1438,  1439,  1252,  2733,  3061,  3062,   972,     5,
    1892,  3282,  1898,  2617,  2618,  2619,  2620,  2621, -1956,    66,
      66,   359,  3290,  2055,   963,  1194,   590,    39,   522,    86,
     524,   334,   986,    51,   613,  2616,   687,   616,   665,   588,
     532,    39,  1461,  3210,   435,  2818,   538,    52,  3475,  1798,
     334,  3055,  1063,  2669,   624,   625,   626,   627,   951,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,  3429,   324,   325,   326,
     327,   328,  1418,   948,    51,   114,   645,   646,    39,   533,
    3279,   648,    39,   649,  3466,  2836,   331,  1867,  1138,     5,
     584,   543,  2080,  2155,  1432,    56,   652,   653,   654,   655,
      32,  1048,  1051,  1462,   663,   949,  1300,  1773,  1117,  1134,
     964,  2672,    33,  1848,   191,  1526,    89,  2171,    62,  2672,
     283,  1311,  1312,    39,  1252,  1052,  2672,    39,  2600,     1,
     588,    62,    60,     2,  1252,   588,   987,   608,  2609,  1084,
     673,   676,  1084,    62,   107,  2238,  1194,  2376,    39,  2415,
      62,   678,  1093,   110,  3063,   682,  1084,  2172,    77,  1737,
    1084,  1124,  1737,   687,  1743,   588,   588,  1110,  1019,  1917,
    1592,  2382,  1084,  2382,  1093,  1297,   591,   117,   191,  1631,
    1122,  2437,  1298,  1093,  2086,  2445,  2463,  1592,   119,  2465,
    1132,  2526,  2056,   973,    62,  2819,    62,  1147,    62,     8,
    2587,    66,    62,  2057,  1188,  2756,    62,    85,   847,   940,
       6,  1862,  1126,  3159,    86,  1122,   286,  2756,  2756,  1122,
    2796,  1050,  1050,  1122,   584,  2799,  1050,  1050,   121,  1093,
   -1956,  2799,  1093,  2702,    62,  1567,   688,  2894,   688,  1050,
    3280,  1185,  1186,   123,  2904,   988,   688,  2966,  3034,  3041,
    1047,  1519,  1520,  1544,   191,  2633,  3127,  3147,     7,  1050,
      87,    88,  1050,   406,   573,   406,  1561,  1899,  1050,   577,
    1236,  1316,  1050,  1239,   962,   416,  1050,    39,   967,  3147,
    1050,  2980,  1047,  3155,  1050,  1050,  1255,  1050,  3262,     8,
    1050,  2890,  1050,  1050,  1050,   416,  2511,  1484,  3301,    39,
    1050,  3301,  3363,  1050,  3363,     1,  2754,  3402,  2305,     2,
    1050,   167,  3418,  3147,  1316,     3,   127,  1050,     9,  2681,
    2682,   575,  2178,   680,  1050,   583,    89,  1389,  1390,  1251,
    2598, -1956,  2610,  3229,   932,  1050,  2832,  1758,  2986,  1050,
    1134,  1624,  1254,  1050,  1125,  1244,  2180,  1047,   601,  1050,
    1485,  2837,  1050,  2681,  2682,  3287,  2872,  1391,  1392,  1393,
    1545,   335,  3072,  3095,  2052,    62,  2017,   527,  1638,  3133,
    2734,  2963,    39,  2029,  2683,    61,  1802,    39,  2047,  1138,
       1,  2591,  3106,    66,    66,    66,  1039,    66,  1043,  1045,
    1018,  1458,  1053,  1055,  1056,  1217,  2222,  1061,   981,  1045,
    1638,  1994,  1064,  2886,    66,     4,  2187,  1481,  2683,  1294,
    3163,  1718,  1566,  1056,  1721,  1452,  1255,  2597,  1745,  1375,
    1789,  1533,  2899,  1030,  1053,  1053,  1255,  2393,  3119,  1794,
    2343,  3294,  1202,  1680,  1056,  1477,  1683,  1684,  1876,  2165,
      66,   304,  3031,  2170,   304,  1245,    66,  1056,    66,   413,
     413,  2790,    66,   966,  1536,    66,  1817,  1111,    66,  2762,
    3088,  1673,  2791,  2480,  1486,  1045,  1805,  2480,    66,   413,
     589,  2225,  3050,   416,  1128,  2242,  1053,  2377,  3079,   413,
    1135,  1203,  3084,    66,  3036,  3077,  3038,   304,  2427,    66,
    3265,   416,   416,   304,  2427,  3109,    66,    66,    66,  1527,
    1804,  2684,  1211,  2427,  3269,  1218,  3432,  3211,  1534,  2427,
      66,  1102,  1819,  2296,  3415,  2485,    62,  1231,  1204,  1231,
     416,    89,  1231,   416,  1845,  1231,    66,  1440,  3241,    10,
    3064,  1593,  1846,   332,  1769,  2684,   304,  1252,  2622,   288,
    3430,  2450,  2451,   602,  3176,  1316,  2335,  1188,  1593,   606,
    1528,  2761,  2242, -1956, -1956, -1956, -1956, -1956,  3467,  2968,
     111,   112,   291,  1693,  2581,     5,  3322,  2685,  1629, -1956,
     304,   594,    39,  3027,  2981,  3030,   595,   304,   609,  1587,
    1898,   674,   677,  2390,  2215,  1360,  1260,  3160,  1360,  1672,
     198,    39,   679,  1607,    62,   663,   683,   663,   663,  2206,
    1738,  2685,  1299,  1739,  1195,  1744,  2200,  2201,  1859,  1253,
    2510,  1040,  2383,    39,  2389,  1205,    90,  2686,  2687,  1702,
    2354,  2314,  2438,   333,   242,  2443,  2446,  2464,  2066,  1280,
    2466,  1964,  2527,  1965,  1966,  3261,  3355,  1968,  1969,  2813,
       5,  2588, -1956,  1988,  1748,   297,  2757,  2327,  1694, -1956,
     197,  2686,  2687,  1254,    39,  1047,  2328,  1749,  2758,  2760,
     201,  2797, -1956,  1903,  1695,  1303,  2800,  1050,  2768,  1622,
    1147,  1188,  2804,  1956,  1957,  1678,  1332,   621,  2895,  3173,
    2329,  3174,  3175,  2330,   174,  2905,     6,  1936,  2967,  3035,
    3042,  1884,  1206,  3221,   249,  2034,   175,  3128,  3148,  2331,
    1133,  2778,    39,   261,  1378,  2891,  2892,  1696,    91,  3191,
    1873,  1681,  2982,  3123,  2983,  1467,  1716,    39,  2315,  1385,
    3154,   688,  2051,  3131,  3156,  1394,  2973,  1339,  2976,  3263,
     330,  2979,  1207,    61,     7,    39,   378,   300,  2135,  3302,
    2136,   251,  3303,  3364,  1469,  3371,  1697,  3387,  3403,   301,
     302,  1065,    39,  3419,  3454,  1053,  3354,   303,    66,  1750,
    3360,     6,  1588,   379,  1194,     8,    39,   304,   324,   325,
     326,   327,   328,  2002,    66,  1698,  3179,  1053,  2759,  3184,
    1676,  2358,  3186,  1138,  1699,  1863,    39,  2896,    92,  1050,
    1050,  1050,  2565,  1608,     9,  2900,    93,  1637,  1208,  3153,
    1773,  2779, -1956,  2332,  1078,  3292,  2702,   258,    62,  2035,
    1608,  1395,  2018,  1748,  2522,  2020,    66,  1865,    39,  1895,
    1941,  1135,  2067,  2653,  3266,  2655,  1749,  2656,  1094,  1255,
      62,  1572,  1135,    39, -1956,  2361,  1641,   181, -1956,  2780,
       8, -1956, -1956,  2167,  1748,  1899,    66,    66,    66,  2956,
      66,   259,    66,    66,  1396,  2859,  2333,  1749,    66,    66,
    1304,   182,  2769,  2334,  1005,  1516,  2294,  1008,  2602,     9,
    1679,  2306,  1523,  1752,  1183,  2794,  -294, -1956,   692,  2129,
    3146,  2988,    66,  1126,  1200,   262,   946,  1215,  2148,  1753,
    2149,  1221,  1820,  1559,  2628,    66,   265,  1227, -1956,  1229,
   -1956,  2530,    39,  2781,  1571,   183,  1682,    66,  1469,  1256,
    1257,  1258,  1579,   266,   184,  2507,  2003,  2782,  2036,  1134,
    1259,  1618,    13,    39,  2795, -1956,  1748,  1799,  1750,    39,
    2989,    66,    66,  1070,  1134,  2004,  2005,  1748,   363,  1749,
      66,  2882,    39,  2205,    13, -1956,  3267,  3137,   267,   942,
    1749,  2861,    62,    39,  1088,  2006,    66,    66,  1589,  1750,
    3193,  -294,  2751, -1956, -1956, -1956,  1746,  1097,  1747,    62,
    1958,  2313,   943,  3021,   268,    39,  2359,  -294,  1836,  2884,
      39,  3124,  1675,    62, -1956,    39,   435,  3443,   269,  1832,
    3304,  1590,  1881,  1882,  2150,  1332,  1332,  2151,   185,   186,
    1936,  3153,  3153,    62, -1956,  1332,   270, -1956,  2196,  3194,
   -1956,  2293,  2928,  2928,  2928,  2928,   271,  2783,  1715,  1936,
    -294,  1407,  1526, -1956,  3187,  2181,  1722,  1444,  1763, -1956,
    2362,   272,  2193,  2784,  1445,    62,  3386,  1921,  1922,  2432,
     371,  1750,  1752,  1408,  2957,  2668,  2002,  2671,   942,  2801,
      62,  2051,  1750, -1956,  3388,   273,  1703,   191,  1753,  -294,
    3345,  3346,  3347,   381,  1782,  2457,  2458,  2459,  3092,   382,
    1282,   943,  2148,  1752,  2149, -1956, -1956,  1759,   383,  2841,
     274,  1764,  1770,  1764,  2972,  2972,  2868,  2972,  -294,  1753,
    2972,  2838,  1413,  1776,  1778,  1779,   275,  -294,    66,  1783,
    1785,  1786,  1787,  1053,   283,  1311,  1312,    39,   276,  1413,
    1772,  1936,  1053,   392,  1414,    32,    33,  1313,  1314,    62,
    1216,  1751, -1643,  1135,  1222,    66,   278,    66,  1226,    66,
      66,  1414,  2881,  1941,  3059,   318,  2013,    66,    66,  1053,
      62,    66,   416,    39,   416,    66,    62,  1817,  3411,  1972,
    3413,  2360,  1941,  1135,  1429,  1752, -1956,  2365,  2366,    62,
    1835,  1135, -1956,   384,   319,  3389,  1752,    66,    66,  3390,
      62,  1753,  2436,   391,  3273,  2440,  3162,   320,  2150,   385,
    3273,  2151,  1753,  3283,  3284,  3285,  3286,  1086,    44,  2003,
      39,  2486,    62,  2228,   448,  2487,   438,    62,   393,  2911,
      39,  1095,   321,  1936,  2498,  1100,   111,   112,  2004,  2005,
    1563,   322,    66,    66,   394,    66,  2481,  1114,    66,    66,
    1235,   323,   386,  1238,  3437,   425,  1241,  2160,  2006,  2519,
     426,  3272,   428,  3275,  3276,  3277,  3278,   111,   112,   354,
    1879,  2825,   416,   416,  1941,   400,  2846,   416,    39,    66,
    2010,  1888,  1889,  1890,  2854,  2855,  2856,   395,  2460,   355,
    1183,   387,   356,  3394,  3028,  2927,  2927,  2927,  2927,  2523,
    1546,    39,  1552,   360,   975,    66,   976,  3082, -1956,   449,
    3407,  1936,   361,  2179,    39,  3405,  1231,   416,   416,  1693,
     388,   365,    39,    66,    66,   450,   396,  2367,  2590,   389,
    1564,   346,   347,   348,  2928,  2928,  3362,   370,  2928,  3365,
    3366,  3367,  3368,  1960,  1053,   372,  1053,  1053,  2069,  2559,
    1053,  1053,   376,  1970,  1134,   397,  1053,  2614,   422,   423,
     424,  2975,  3394,  2978,   398,  3389,  1941,   401,   451,  3390,
   -1956,  1269, -1956,  2630,  1422,  1423,  1424,  1050,  3264,  3407,
      66,   979,  1270,   980,  1147,  1044,   411,    39, -1956,  2251,
    2253,  2014,  1973,  1052, -1956,    39, -1956,   407,  1517,  1518,
   -1956,  1116,  1521,  1522,  1694,   410,  1974,   452,  1275,  1276,
    1123, -1956,  2368,  2972,  1467,  2263,    39,  1188,  1409,  1410,
    1695,  1332,   443,  1332,  2051, -1956,  2051,  3424,  2369,  1557,
     445,    39,  1271,  1332,  1332,  1053,   453,  1685,  2060,  1686,
    1332,  1332,  1332,  1332,  1941,   454,  1272,   446,  1777,  1975,
      39, -1956,  1378,  1135,  1907,   112,  1234,   340,   457,  1237,
    1976,   345,  1688,  1696,  1689,   460,  1780,  1975,    39,  3198,
     461,  2370,  2031,   463,  2038,  1759,  1997,  1998,  1976,  2192,
    1764,  1977,  2161,  2162,  2038,  1339,  1770,   464,  1978,  1764,
     465,  2061,  2062,  2063,  2064,  1784,  1979,    39,   663,  1977,
     466,  2021,  1697,  2022,  1050, -1956,  1978,  2127,   467, -1956,
    2371,  3098,   514,  2131,  1979,  2025,   526,  2026,  1980,  2469,
     530,    39,  2644,   528,  2472,  2646,    39,  2649,  2650,   535,
    2647,  1698,  2648,  1256,  1257,  1273,  1980,  1050,   536,  2372,
    1699,   537,  2158,  3199,   425,  1806,  1807,  1808,  2373,   426,
     427,   428,  2167,  3168,   539,  3169,  1053,  1135,   540,  1316,
    2174,  2175,  1826,   416,   544,  2928,   324,   325,   326,   327,
     328,  2928,  2928,  2805,  2928,  2928,  2928,  2928,    66,  1539,
    1540,  1541,  1542,  2928, -1956,  3420,  3421,  2927,  2927,   545,
    2912,  2927,   546,  2913,  3100,  1981,  1723,  1724,  1725,  1726,
    2203,  1982,    66,  2774,  2775,  3200,  2914,  3201,  2835,  3448,
    1349,    39,  1800,  1351,  1800,  1352,  1353,  1354,  1355,  1356,
    3135,  3136,   550,  3202,    66,  1060,  2229,  1579, -1956,  1332,
    1860,  3203,  1135,    66,   560,  3204,   561,  1069,  2737,   565,
    2929,  2929,  2929,  2929,   562,   570,  2916,   580,  3232,  1546,
     416,   416,   581,  2738,  2739,   586,   587,  3240,  2917,   592,
    3205,   593,  2740,   597,   598,   416,  1089,   607,  1891,   617,
      66,    66,    66,   614,  3246,   618,    66,   619,   622,  1906,
    2236,   656,  1106,  1107,  1053,   647,   657,   650,  1113,   658,
     664,  1115,   666,   667,   668,   669,  2741,  2928,   670,  2918,
    2928,  2928,  2928,  2928,   675,  2742,   671,   672,   681,   693,
       1,    66,   947,   952,  1832,   954,   955,   956,   978,  2349,
    2349,   961,   971,  2349,  1727,  1728,  1729,  1730,  1731,  1732,
     977,   985,   990,  1147,  2743,   992,   994,   995,  2919,  1188,
     996,  1013,  1016,  1021,  1022,  1332,  3291,  1024,  1025,  1032,
    2920,  1026,  1027,  1029,  1332,  1033,  1034,  1332,  1332,  1332,
    1332,  2388,  2921,  2922,  1053,  1188,  1035,  1145,  2394,  1332,
    2923,  1223,  2412,  2924,  1725,  1726,  1284,  1285,  1286,  2744,
    1290,   304,   191,  1287,  1288,  1289,  1291,  1295,  2928,  1292,
    1293,  1296,  1301,  2428,  2428,  2428,  1339,  2928,  2428,  1332,
    2442,  1302,  1305,  1759,  1306,  2381,  1307,  1350,  2384,  2385,
    2386,  2387,  1357,  1358,  3047,  1359,  1362,  1363,  2927,  1365,
    1366,  3339,  1367,  2745,  2927,  2927,  1368,  2927,  2927,  2927,
    2927,  1369,  2467,  1370,  2468,  2470,  2927,  2471,  2473,  3151,
    3152,  2475,  1372,  1376,  1377,  1764,  1492,  1381,  1382,  1764,
      66,  1384,  1383,  1050,    66,  3149,  3150,  3151,  3152,  1050,
    1053,  2428,  1406,    66,  2158,  1411,  1412,  2503,  2503,  1415,
    1416,  2994,  2995,  2996,  1417,  2998,  2999,  3000,  3001,  3002,
    3003,  1419,  1436,  1443,  3006,  1050,  1425,  1442,    66,  2033,
    1449,  1446,  1447,  1450,  3073,  2521,  1429,  1455,    66,  1457,
    1727,  1728,  1729,  1730,  1731,  1732,  1454,    66,  1466,  1471,
    1469,    66,  2142,  3199,  3344,  3395,  3396,  3397,  3398,  3399,
    3400,  1474,  3089,  1514,  1524,  1525,  1473,  1529,  1553,  1554,
    1555,  3417,  2929,  2929,  1556,  1562,  2929,    66,  1560,  2166,
    1567,  1576,  1578,  1598,  1599,   588,  1808,  1606,  1600,  1610,
    2927,  1601,  1613,  2927,  2927,  2927,  2927,  1614,  1615,  1616,
    1663,  2566,  1677,  1674,  1671,  1727,  1728,  1729,  1730,  1731,
    1732,  1704,  1687,  1705,  1736,  3200,  1546,  3201,  1706,  1707,
    1762,  1711,  1742,  1727,  1728,  1729,  1730,  1731,  1732,  1073,
    1073,  1712,  1713,  3202,  1714,  1775,  2214,  1791,  1790,    71,
    2051,  3203,  1792,  1795,  1796,  3204,  1797,  1437,  1827,  1811,
    1818,  1053,  1536,  1838,  1829,  1840,  1825,  1851,  1868,  1852,
    1870,  1147,  1147,  1871,  1883,  1910,  2428,  1880,  1885,  2877,
    3205,  2879,  1912,  1895,  2605,  1970,  2428,  1909,   940,  1960,
    1053,  2927,  1332,  1608,  1902,  1950,  1948,  1904,  1951,  2011,
    2927,  1953,  1493,  2015,  1959,  1960,  1053,  2019,  3192,    66,
    2349,  2023,  2024,   162,   194,  2027,  1832,  2029,  1702,  2070,
    2052,  2044,  2071,  2076,  2065,  2077,  2078,  2081,  2083,  2082,
    2086,  2117,  2115,  2118,  3412,  2119,  2120,  1073,  2124,  2137,
    2866,  2121,  2138,  1339,  2133,  2139,  2140,  1246,  2122,  1332,
    2237,  2143,  2144,  2141,  1492,  2145,  2146,  1053,  2147,  1053,
    2394,  2159,  1607,  1332,  2182,  1332,  2189,  2191,  2184,  2185,
    3167,  2194,  3170,  3171,  2198, -1956,  1332,  2199,  2204,  2207,
     194,  2428,    66,  2412,   191,  2208,  2209,  2212,  3479,  2226,
    2844,  1050,  1050,  2232,  2428,   663,  1259,  2244,  2242,   194,
    2658,  2291,  2218,   663,   663,   663,  2292,  2303,  2309,  2319,
    3234,  2318,  1764,  2929,  2317,  2322,  2670,  2324,  2346,  2929,
    2929,  2378,  2929,  2929,  2929,  2929,   191,  2692,  3244,  1494,
    1770,  2929,  1764,  2323,  2357,  1495,  1496,  1497,  2363,  2380,
    2392,  2409,  2364,  2338,  2339,  2127,  2379,  2416,  2418,  2420,
    2414,  2421,    66,  2478,  2483,  2494,  2424,  1498,  2512,  2514,
    2516,  2447,  2448,  2777,  2449,  2452,  2453,  2454,   412,  2455,
    2518,  2456,  2517,  2474,  2524,  2520,  2532,  2158,  2533,  2826,
    2535,  2828,  2536,  2539,  2428,  1053,  2538,    66,  2540,  2488,
    2489,  1808,  2492, -1956,  2560,  2557,  2537,  1333,  1526,  1258,
    2558,  2564,    66,  2573,    66,  2850,    66,  2575,  2584,  2585,
    2513,  2586,  2589,  2603,  2593,  2594,  2601,  2626,  2631,  2636,
      66,  1927,  1928,  1929,   519,   520,  1930,  1332,  1931,  1932,
    2645,   194,  2651,  2654,  3166,  2672,   194,  1669,  2657,  2659,
     416,  3086,   416,  2660,  2661,  2929,  2662,  2673,  2929,  2929,
    2929,  2929,    66,    66,  3091,  2693,  2696,  2754,  1332,  2705,
    1493,  2753,  1499,  2755,  2763,  1500,  2792,  2766,  2767,  2770,
    2428,  3324,  2772,  1501,  2773,  2793,  2802,  2556,  2236,  1246,
    1626,  2803,  2806,  2809,  2925,  2925,  2925,  2925,  2428,  2428,
    2816,  2820,  2827,  2842,  2853,  2845,  2824,  2834,    66,  2876,
    2887,  2888,  2896,  2950,  2903,  2906,  2907,  1717,  1502,  1339,
    2948,  2955, -1956,  2864,  2958,  2808,  2959,  2960,  3081,  2961,
    2926,  2926,  2926,  2926,  2962,  2964,  2974,  2965,  2977,  2985,
    2987,  2997,  2993,  2992,  3004,  3005,  2929,  3011,  3012,  1332,
    1332,  3014,  3015,  1503,  3016,  2929,  3017,  3018,  1332,  1332,
    2780,  1332,  3019,  3020,  1332,  3025,  1332,  3032,  3033,  3037,
    1332,  3039,  1504,  1505,  3043,  3044,  3068,  3048,  3074,  3076,
    3075, -1956,  3077,  1506,  3090,  3094,  3096,  3099,  1507,  2624,
    1253,  2625,  1627,  3103,  3104,  3112,   191,  1494,  3115,  3119,
    1628,  3138,  3125,  1495,  1496,  1497,  1629,  3139,  1630,  3147,
      66,  3157,  3158,  3140,  3141,  3142,  3164,  2984,  3143,  1631,
    3374,  3375,    66,   663,  3144,  1498,   651,  1508,  3172,  3196,
   -1824,  2428,  3029,  2428,  3177,  3213,  2751,  3215,   194,  3214,
    3217,  3218,  3219,  3224,  3220,  3226,  3227,  1632,  3233,  3237,
    3243,  3239,  3247,  3245,  3248,  3249,  3258,  1053,  3251,  1509,
    3253, -1956,  1246,  1633, -1956,  1718,  3270,  3288,  1634,  3051,
    3052,  3268,  3296,  2475,  3297,  3305,  1764,  3315,  3317,  3318,
    1635,  3316,  3320,    66,  3231,  3325,  3337,  1636,  3319,  3338,
    3343,  3361,  3351,  2503,  3372,  3369,  3083,  2503,  3401,  3414,
    3385,   416,   194,  3431,  3441,  3423,  3425,  3426,  3427,  3428,
    1933,    66,  3452,  1934,   416,  1935,    66,  3453,  3460,  3462,
    3464,  3463,  1853,  3468,  3473,    66,  1333,  1333,  3465,  2849,
    1499,  3477,  3440,  1500,  3478,  1936,  1333,  2798,  2549,  1373,
    1894,  1501,  2217,    57,  1031,  1937,    58,  1188,  2499,  2508,
     200,   541,  2807,  2823,   353,  2812,   205,  1023,  2072,   569,
     542,  2073,  3223,   534,   366,  3116,  1938,   684,   358,  1690,
     567,  2428,  3223,   957,  3438,   984,  1502,   958,   194,  2130,
    2605,  2428,  1210,  1960,  1960,  1920,  2925,  2925,  2347,  1939,
    2925,  2355,  1364,  1940,   603,  2176,  1667,  2490,  2875,  2241,
    3114,  3145,  1924,  2563,  3461,  2495,  2261,  1822,  1036,  1037,
    1038,  1503,  1041,  3242,    54,   136,    68,    69,    55,  2227,
    1183,  2224,  2926,  2926,    66,  1960,  2926,  1992,  1993,  1067,
    1504,  1505,  2642,  1112,  2009,  1637,  1908,   525,  1387,  1947,
    1638,  1506,  2231,  1053,  1858,  1283,  1507,  1639,  1604,  3197,
    3306,  1135,  3444,  1144,  1135,  1856,  1813,  1332,  2870,  1803,
    1332,  3024,  1332,  3314,  2428,  1091,  2195,  1050,  1941,  1640,
    3023,  1096,  1874,  1098,  1641,   623,  3007,  1105,  2749,  3070,
    1105,  3230,  3228,  1105,  3225,  1508,  3053,  3182,    66,  2484,
    3182,  2085,  2116,  1118,  2444,  2595,  3447,  3190,  1246,  1990,
    1991,  2615,  2321,  3321,  3132,  3049,  3026,  2312,  1118,  2391,
    2969,  3188,  2667,  2692,  1179,  2970,  3376,  1509,  3045,  3185,
    2765,  1041,  1192,  1196,  1963,  1332,  3212,  1212,  2750,  2666,
     993,    49,  3472,  2703,  3134,  1224,  1655,  2704,  2046,  3189,
    2045,  2902,  1955,  3353,  2607,   416,  3130,  1621,  3271,    66,
    3350,  1248,  3281,  1927,  1928,  1929,  3289,  2833,  1930,  1918,
    1931,  1932,  2936,  2936,  2936,  2936,  2068,    66,   476,   477,
     478,   479,   480,   481,   482,   483,  1837,  2515,  1468,  1821,
     694,     0,  1831,  2830,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,     0,     0,
       0,  1332,   484,     0,  2428,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1332,     0,  2925,     0,     0,
       0,     0,     0,  2925,  2925,  1246,  2925,  2925,  2925,  2925,
       0,     0,  2428,     0,  2428,  2925,   191,  1332,     0,     0,
       0,     0,     0,     0,  2197,     0,     0,     0,     0,     0,
       0,     0,  1339,  2926,     0,     0,     0,     0,     0,  2926,
    2926,     0,  2926,  2926,  2926,  2926,  2031,     0,     0,   578,
       0,  2926,     0,    66,     0,     0,     0,     0,    66,     0,
      66,     0,     0,     0,     0,  2239,     0,     0,  3087,     0,
    3299,     0,     0,     0,     0,     0,     0,  2428,     0,   485,
     486,   487,   488,   489,   490,     0,     0,     0,     0,     0,
      66,     0,     0,   663,     0,     0,     0,   491,   492,   493,
       0,     0,  1333,     0,  1333,  3107,  2707,  2708,    66,  2709,
    2710,  2711,     0,     0,  1333,  1333,     0,     0,     0,  3116,
       0,  1333,  1333,  1333,  1333,  1332,     0,     0,     0,  2925,
       0,     0,  2925,  2925,  2925,  2925,     0,  3370,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3373,     0,     0,     0,     0,     0,     0,  1135,     0,
       0,     0,  1332,  1248,     0,  2926,     0,     0,  2926,  2926,
    2926,  2926,     0,     0,     0,     0,  3359,     0,     0,  1430,
       0,     0,     0,    66,    66,    66,    66,    66,    66,     0,
       0,     0,     0,     0,  3182,  3406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2712,     0,
       0,     0,  1933,  3377,     0,  1934,  2713,  1935,     0,     0,
    2925,  1460,     0,     0,     0,     0,     0,     0,     0,  2925,
       0,     0,     0,     0,  2936,  2936,   494,  1936,  2936,   495,
       0,     0,     0,     0,     0,     0,     0,  1937,     0,     0,
    2714,  1488,  1488,  1488,     0,  1488,  2926,  1488,  1488,  2715,
       0,     0,     0,    71,    71,  2926,     0,     0,  2260,     0,
       0,     0,     0,     0,  1073,  1332,     0,  3449,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1196,  2716,  2717,
       0,  1939,     0,     0,     0,  1940,     0,     0,     0,  3183,
    1196,     0,  3183,     0,     0,     0,     0,     0,     0,     0,
    1333,     0,  1574,     0,     0,  3235,     0,     0,     0,  3470,
    3471,  3449,     0,     0,     0,     0,  3359,     0,     0,     0,
       0,     0,    66,  2718,  3480,     0,  1248,  1430,     0,     0,
       0,     0,     0,     0,     0,  1611,     0,     0,     0,     0,
       0,  3259,     0,     0,     0,     0,  2545,  2546,   138,   496,
       0,  1619,  1619,     0,     0,     0,     0,  2555,     0,     0,
    1941,     0,     0,     0,   497,     0,     0,  2719,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2567,  2568,  2569,  2570,  2571,  2572,   139,     0,     0,
       0,  2577,  2578,  2579,  2580,     0,     0,     0,  2582,     0,
       0,     0,     0,     0,   499,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,  1333,     0,     0,     0,
       0,  2720,     0,     0,     0,  1333,     0,     0,  1333,  1333,
    1333,  1333,   500,     0,     0,     0,     0,     0,     0,     0,
    1333,     0,     0,     0,     0,     0,   142,     0,     0,     0,
     501,     0,     0,  2033,     0,  2936,     0,     0,   143,     0,
       0,  2936,  2936,     0,  2936,  2936,  2936,  2936,     0,   144,
    1333,     0,     0,  2936,     0,     0,     0,     0,     0,     0,
    2634,  2635,     0,     0,   280,   145,     0,  2639,  2640,     0,
       0,     0,     0,   281,   282,   146,     0,     0,     0,   283,
     284,   285,    39,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,   167,     0,     0,     0,     0,     0,
      71,     0,    71,     0,  1196,  1105,     0,     0,     0,     0,
       0,   502,  1812,  1118,     0,     0,  1196,     0,     0,     0,
    1823,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1248,  1179,     0,     0,     0,     0,  3404,  1246,
       0,     0,     0,   149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2936,   150,   168,
    2936,  2936,  2936,  2936,   286,   151,     0,   503,   152,     0,
       0,   169,     0,     0,     0,     0,     0,  1857,  1179,     0,
      71,     0,     0,  1864,  1866,     0,  3183,     0,     0,   153,
       0,     0,     0,   154,     0,     0,     0,     0,   170,     0,
       0,     0,     0,     0,     0,     0,  2814,  2815,     0,     0,
       0,     0,   155,     0,  1886,  2822,     0,  2721,  2722,  2723,
    2724,  2725,  2726,  2727,  2728,  2729,  2730,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1914,     0,  3458,     0,     0,     0,     0,     0,  2936,     0,
       0,     0,     0,  2857,  2858,     0,     0,  2936,  1946,  1248,
     611,   468,   469,   470,     0,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
    2878,     0,  2880,  1333,     0,     0,     0,     0,     0,    62,
       0,   171,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1996,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1333,     0,     0,  2951,  2952,     0,     0,  2953,  2954,     0,
       0,     0,     0,     0,  1333,     0,  1333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1333,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,     0,     0,   287,     0,     0,     0,     0,     0,     0,
     484,   485,   486,   487,   488,   489,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1333,   491,
     492,   493,     0,   173,     0,     0,     0,   485,   486,   487,
     488,   489,   490,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,   289,     0,   290,     0,     0,   485,   486,   487,
     488,   489,   490,     0,     0,   176,     0,     0,     0,     0,
     291,     0,     0,  2188,     0,   491,   492,   493,  1333,     0,
     177,     0,     0,  3080,     0,   292,     0,  3085,   293,     0,
       0,   294,     0,     0,     0,     0,     0,  1196,     0,     0,
     295,   179,     0,     0,     0,     0,  3093,     0,     0,  1333,
       0,     0,     0,     0,     0, -1956, -1956, -1956,   494,   162,
   -1956,   495, -1956, -1956,     0,     0,  3105,     0,  1179,     0,
       0,     0,     0,     0,     0,  1333,  1333,  1333,  1333,     0,
     659,   296,     0,     0,   494,   180,     0,   495,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,  1196,  2295,  1196,     0,     0,
     181,  1041,     0,     0,     0,     0,     0,     0,     0,     0,
    2089,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1333,  1333,     0,     0,   299,     0,     0,     0,     0,  1333,
    1333,     0,  1333,     0,     0,  1333,  2341,  1333,     0,     0,
       0,  1333,     0,     0,   494,     0,     0,   495,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1073,  1073,  1073,
       0,  1073,  1073,  1073,  1073,  1073,  1073,     0,   183,     0,
    1073,   496,     0,     0,     0,   300,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     0,   497,   301,   302,     0,
     498,     0,     0,     0,     0,   303,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,   304,     0,     0,     0,
       0,     0,   497,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
    2529,   468,   469,   470,     0,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   499,     0,   500,     0,     0,     0,     0,     0,
       0,   185,   186,     0,     0,  1001,     0,   496,     0,     0,
       0,     0,   501,     0,   484,  1196,     0,     0,     0,  1196,
     500,     0,   497,     0,     0,     0,   498,     0,  1196,     0,
       0,     0,     0,     0,     0,     0,  1246,     0,   501,     0,
     280,     0,     0,     0,  3257,     0,   194,  3260,     0,   281,
     282,     0,     0,  1196,     0,   283,   284,   285,    39,     0,
       0,     0,   499,  1248, -1956,     0,     0, -1956,     0, -1956,
     167,     0,  2528,     0,     0,     0,  2531,     0,     0,     0,
       0,     0,     0,     0,     0,  2090,     0,     0,     0, -1956,
     500,     0,     0,   502,     0,     0,     0,  1333,  1333, -1956,
       0,  1333,  2554,     0,     0,  2091,  2092,  2093,   501,     0,
       0,   485,   486,   487,   488,   489,   490,     0,     0,   502,
   -1956,     0,     0,     0,     0,     0,     0,   164,   165,   491,
     492,   493,     0,     0,     0,   166,    39,     0,     0,     0,
       0,     0,     0, -1956,  2094,   168,     0, -1956,   167,     0,
     286,     0,     0,     0,     0,     0,  2095,   169,     0,   503,
       0,     0,  1333,     0,     0,  1333,     0,  2096,  1333,     0,
       0,  1333,     0,  1333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2097,   170,   503,     0,     0,     0,   502,
       0,     0,  3348,  2098,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2099,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1956,   168,  2632,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,  1333,     0,     0,     0,
       0,     0,     0,  3378,  3379,     0,  3381,     0,  3383,  3384,
       0,     0,     0,     0,     0,   503,  2100,     0,     0,     0,
       0,     0,   170,   280,     0,     0,     0,     0,   494,     0,
       0,   495,   281,   282,     0,    62,     0,   171,   283,   284,
     285,    39,     0,     0,     0,     0,  2101,     0,     0,     0,
       0,     0,     0,   167,     0,     0,  2102,  1196,     0,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
       0,     0,  1333,     0,     0,     0,  3433,  2103,  3434,     0,
       0,  2104,     0,     0,     0,     0,  1333,     0,  1333,     0,
       0,     0,   484,     0,  1333,  1333,     0,  1333,  1333,  1333,
    1333,     0,     0,     0,     0,     0,  1333,     0,  1333,  2105,
       0,     0,  3446,    62,     0,   171,     0,     0,  2106,     0,
       0,     0,     0,     0,     0,  1333,     0,  1196,   168,     0,
       0,  3455,  3456,   286,   172,  3457,     0,     0,  3459,   287,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,     0,   194,     0,
       0,     0,  1196,     0,     0,     0,   497,   170,     0,   173,
     498,     0,     0,     0,     0,     0,     0,  2847,     0,  1067,
       0,  2851,     0,     0,     0,     0,     0,     0,     0,   485,
     486,   487,   488,   489,   490,  2863,     0,     0,     0,  1246,
     194,     0,     0,   174,     0,     0,   499,   491,   492,   493,
       0,     0,   172,     0,     0,   175,  1333,     0,     0,     0,
    1333,     0,     0,  1333,  1333,  1333,  1333,  2883,  2885,     0,
       0,     0,     0,   288,   500,     0,     0,     0,   289,     0,
     290,     0,     0,     0,     0,     0,     0,   173,     0,  1333,
       0,   176,   501,  1333,     0,     0,   291,     0,    62,     0,
     171,     0,     0,     0,     0,     0,   177,     0,     0,     0,
       0,   292,     0,  2949,   293,     0,     0,   294,     0,     0,
       0,   174,     0,     0,     0,     0,   295,   179,     0,     0,
       0,   280,     0,   175,     0,     0,     0,     0,     0,     0,
     281,   282,     0,     0,     0,     0,   283,   284,   285,    39,
       0,  1333,     0,     0,     0,     0,     0,     0,     0,     0,
    1333,   167,     0,     0,     0,     0,  1426,   296,     0,   176,
       0,   180,     0,   502,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   177,     0,   494,     0,     0,   495,
     298,     0,   178,     0,     0,     0,   181,   172,     0,     0,
       0,     0,   287,     0,     0,   179,  1333,     0,     0,     0,
       0,     0,     0,     0,     0,  3008,     0,     0,     0,     0,
     299,     0,     0,     0,     0,     0,     0,  3022,     0,     0,
       0,     0,   173,     0,     0,     0,   168,     0,     0,   503,
       0,   286,     0,     0,     0,     0,     0,     0,   169,   180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1246,   183,     0,   174,     0,     0,     0,
       0,   300,     0,   184,   181,   170,     0,     0,   175,     0,
       0,     0,     0,   301,   302,     0,     0,     0,  1196,     0,
       0,   303,     0,     0,     0,     0,   288,     0,   182,     0,
     194,   289,   304,   290,     0,     0,     0,     0,     0,   496,
       0,     0,     0,   138,   176,     0,  1196,     0,     0,   291,
       0,  1179,     0,     0,   497,     0,     0,     0,   498,   177,
    1248,     0,     0,     0,   292,     0,     0,   293,     0,     0,
     294,     0,   183,     0,     0,     0,     0,     0,     0,   295,
     179,   184,   139,     0,     0,     0,     0,   185,   186,     0,
       0,     0,     0,     0,   499,     0,    62,     0,   171,     0,
       0,   140,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     0,   500,     0,   180,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,     0,
     501,   142,     0,   298,     0,  2491,     0,     0,     0,   181,
       0,     0,     0,   143,     0,     0,     0,     0,     0,  1179,
       0,   280,     0,     0,   144,   185,   186,     0,     0,     0,
     281,   282,     0,   299,     0,     0,   283,   284,   285,    39,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   167,     0,     0,     0,   172,     0,     0,     0,     0,
     287,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,     0,     0,
       0,   502,     0,  3008,   300,     0,   184,     0,     0,     0,
     173,   479,   480,   481,   482,   483,   301,   302,     0,     0,
       0,     0,     0,     0,   303,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,     0,     0,     0,     0,
       0,     0,   484,     0,   174,     0,   168,     0,   149,     0,
       0,   286,     0,     0,     0,     0,   175,     0,   169,     0,
       0,     0,     0,   150,  1196,     0,     0,   503,     0,     0,
     151,     0,     0,   152,   288,     0,     0,     0,     0,   289,
       0,   290,  1196,     0,     0,   170,     0,     0,     0,     0,
     185,   186,   176,     0,   153,     0,     0,   291,   154,     0,
       0,     0,     0,     0,     0,     0,     0,   177,     0,     0,
       0,  1179,   292,  2909,  2910,   293,     0,   155,   294,   283,
    1311,  1312,    39,     0,     0,     0,     0,   295,   179,     0,
       0,     0,  1313,  1314,     0,   156,     0,     0,     0,   485,
     486,   487,   488,   489,   490,     0,     0,     0,     0,  1150,
    1151,  1152,  1153,     0,     0,     0,     0,   491,   492,   493,
       0,     0,     0,     0,     0,     0,     0,  2867,   296,     0,
       0,     0,   180,     0,     0,     0,    62,     0,   171,     0,
     297,     0,     0,     0,     0,     0,     0,     0,  3008,     0,
       0,   298,     0,  3309,     0,  3311,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2911,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,  1196,   469,   470,     0,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,  1248,     0,     0,     0,     0,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,     0,     0,   484,     0,
       0,  1154,   300,     0,   184,   172,     0,     0,     0,  1155,
     287,     0, -1957,     0,   301,   302,     0,     0,  1156,     0,
       0,  1157,   303,     0,     0,     0,   494,     0,     0,   495,
       0,     0,     0,   304, -1957, -1957, -1957,     0,     0, -1957,
     173, -1957, -1957,     0,     0,     0,     0,     0,  1488,  1488,
    1488,  1488,  1488,  1488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1158,     0,     0,     0,     0,  1134,
       0,  1159,     0,     0,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,   185,   186,
       0,     0,     0,     0,     0,   485,   486,   487,   488,   489,
     490,     0,     0,     0,   288,     0, -1957,     0,     0,   289,
       0,   290,     0,   491,   492,   493,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,   291,  1160,     0,
       0,     0,     0,     0, -1957,     0,     0,   177,     0,     0,
       0,     0,   292,     0,     0,   293,     0,     0,   294,   496,
       0,     0,     0,  1161,     0,     0,     0,   295,   179,     0,
    1162,     0,  1163,     0,   497,     0,     0,     0,   498,     0,
       0,     0,  1164,     0,     0,     0,     0,     0,     0, -1957,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1248,   296,     0,
    1165,     0,   180,     0,   499,     0,     0, -1957,  1166, -1957,
     297,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,     0,     0,     0,   181,     0,     0,
       0,     0,   500,     0, -1957,     0,     0,     0,     0,     0,
       0, -1957,     0, -1957,     0,  1167,     0,     0,     0,     0,
     501,   299,   494,     0, -1957,   495,     0,     0,     0, -1957,
       0,     0,     0,     0,     0,     0,     0, -1957,     0,  1168,
       0, -1957,     0,     0,  1316,     0,     0, -1957,     0,     0,
       0, -1957, -1957, -1957, -1957,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183, -1957,     0,     0,     0,
       0,     0,   300,     0,   184,  2912,  1169,     0,  2913,     0,
       0,     0,     0, -1957,   301,   302, -1957,  1170, -1957,     0,
       0,  2914,   303,     0,     0, -1957,     0,     0,     0,     0,
       0,   502,     0,   304,     0,     0,     0,     0, -1957,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1957,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2915,  2916,     0,     0,     0,     0,     0,     0,     0, -1957,
   -1957,     0,     0,  2917,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0, -1957,     0,     0,     0,   185,   186,
     497,     0, -1957,     0,   498,     0, -1957,   503,     0,     0,
       0,     0,     0,     0, -1957, -1957, -1957,     0,     0,     0,
       0,     0,     0,     0,  2918,  1171,  1172,  1173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1174,     0,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2919,     0,     0,     0,     0,   500,     0,
       0,     0,     0,     0,     0,  2920,     0,     0,     0,     0,
       0, -1957,     0,     0,     0,     0,   501,  2921,  2922,     0,
       0,     0, -1957,     0,     0,  2923,     0,     0,  2924,     0,
       0,     0,     0,   468,   469,   470,   304,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1957,     0,     0,     0,     0,     0,     0,     0,
       0,  1175,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     2,     0,     0,     0,     0,   502,     0,     0,
     696,   697,   698,     0,     0,     0,     0,     0,     0,   699,
       0,     0,   700,     0,     0,     0,     0,     0,     0,   701,
     702,     0,     0, -1957,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1957,
       0,     0,     0,   503,   703,   704,     0,     0,     0,   705,
       0,     0,     0,   485,   486,   487,   488,   489,   490,   706,
     707,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,   491,   492,   493,     0,     0,   709,     0,     0,     0,
       0,     0,     0,     0,     0, -1957,     0,     0,     0,     0,
       0,     0,     0,   710,     0,     0,   711,   712,     0, -1957,
   -1957, -1957, -1957, -1957, -1957, -1957,     0, -1957, -1957,     0,
     713,     0,   714,   715,   716,     0,     0,     0,     0,     0,
       0,     0,   717,   718, -1957,   719,   720,   721,     0,     0,
       0,     0,     0,   722,     0,     0,   723,     0,   724,   725,
     726,     0,     0,     0,     0,     0,   727,     0,   728,   729,
       0,   730,     0,   731,   732,     0,     0,   733,     0,     0,
     734,   735,   736,   737,   738,   739,     0,     0,     0,   740,
     741,   742,     0,   743,     0,     0,     0,   744,     0,   745,
     746,     0,     0,     0,     0,   747,     0,     0,   748,     0,
       0,   749,     0,   750,     0,   751,     0,   752,     0,     0,
       0,   753,   754,     0,   755,   756,   757,     0,     0,   758,
     494,   759,   760,   495,   761,     0,     0,     0,     0,     0,
       0,     0,   762,   763,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   764,     0,     0,   765,   766,
       0,     0,   767,   768,     0,     0,   769,   770,     0,     0,
       0,     0,     0,     0,     0,   771,   772,   773,     0,   774,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   775,
     776,   777,     0,   778,     0,     0,     0,   779,   780,     0,
       0,     0,   781,     0,     0,     0,     0,     0,     0,     0,
     782,     0,     0,     0,     0,     0,     0,     0,   783,   784,
     785,     0,     0,     0,     0,     0,   786,   787,     0,     0,
       0,     0,     0,     0,   788,     0,     0,   789,     0,     0,
       0,   790,   791,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   792,   496,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,   793,
       0,     0,   498,   596,     0,     0,     0,   794,     0,     0,
       0,     0,     0,   795,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   796,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   797,     0,   499,     0,
       0,     0,   798,     0,   799,   800,     0,     0,     0,     0,
       0,     0,   801,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,     0,     0,     0,
       0,   802,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   803,     0,     0,     0,     0,     0,     0,   804,
       0,   468,   469,   470,     0,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,     0,   805,   806,     0,     0,     0,   807,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     808,     0,     0,     0,   484,     0,   809,   810,   811,   812,
       0,     0,     0,   813,     0,   502,     0,   814,     0,     0,
       0,     0,     0,     0,   815,   816,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   817,     0,   818,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   819,     0,
     820,     0,     0,   821,     0,     0,   468,   469,   470,   822,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,     0,     0,   823,     0,     0,   824,     0,
       0,     0,     0,   825,     0,     0,   826,   827,     0,   484,
       0,   485,   486,   487,   488,   489,   490,     0,     0,     0,
       0,   828,     0,     0,     0,     0,     0,     0,   829,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   830,   831,   832,   833,   834,   835,   836,     0,     0,
     837,     0,   838,     0,   839,     0,     0,     0,     0,   468,
     469,   470,     0,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,   485,   486,   487,   488,
     489,   490,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   493,   468,   469,   470,
       0,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,     0,
     484,   495,     0,     0,   468,   469,   470,     0,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   485,   486,   487,   488,   489,   490,     0,   485,
     486,   487,   488,   489,   490,     0,     0,   484,     0,     0,
     491,   492,   493,     0,     0,     0,     0,   491,   492,   493,
       0,     0,     0,     0,     0,   468,   469,   470,     0,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,     0,     0,   495,   485,   486,   487,
     488,   489,   490,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,   491,   492,   493,   468,   469,
     470,   496,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,   497,     0,     0,     0,
     498,   610,     0,     0,   485,   486,   487,   488,   489,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
       0,     0,   495,     0,     0,     0,   494,     0,     0,   495,
       0,     0,     0,     0,   500,   485,   486,   487,   488,   489,
     490,     0,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,   501,   491,   492,   493,     0,     0,     0,     0,
       0,   497,     0,     0,     0,   498,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,     0,     0,   495,   485,   486,
     487,   488,   489,   490,     0,     0,     0,     0,     0,     0,
       0,   499,     0,     0,     0,     0,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,   494,     0,   502,   495,     0,     0,     0,     0,     0,
       0,     0,   496,     0,     0,     0,     0,   501,     0,   496,
       0,     0,     0,     0,     0,     0,     0,   497,     0,     0,
       0,   498,     0,     0,   497,     0,     0,     0,   498,   991,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   494,     0,     0,   495,     0,   499,     0,   503,
       0,     0,     0,     0,   499,     0,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   497,     0,     0,   500,   498,   997,   502,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,     0,   494,     0,     0,   495,     0,
     501,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,     0,     0,     0,   497,
       0,     0,     0,   498,   998,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     500,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,   499,
       0,     0,     0,     0,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,   502,     0,     0,     0,     0,     0,
     497,   502,     0,     0,   498,   999,     0,   500,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,   496,     0,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,     0,     0,   498,  1000,   502,
     503,   484,     0,     0,     0,     0,     0,   503,   500,   468,
     469,   470,     0,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   501,     0,     0,     0,
       0,     0,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,   500,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   468,   469,   470,   501,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,     0,   485,   486,
     487,   488,   489,   490,     0,     0,     0,   502,     0,     0,
       0,     0,   503,     0,     0,     0,   491,   492,   493,   484,
     468,   469,   470,     0,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
     486,   487,   488,   489,   490,     0,     0,     0,     0,     0,
     502,     0,     0,   484,     0,     0,     0,   491,   492,   493,
     468,   469,   470,   503,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   470,     0,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,   484,     0,     0,   485,   486,   487,   488,
     489,   490,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   493,   484,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   494,     0,     0,   495,     0,
     485,   486,   487,   488,   489,   490,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   492,
     493,     0,     0,     0,     0,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,     0,   495,
     485,   486,   487,   488,   489,   490,     0,     0,     0,     0,
       0,     0,     0,     0,   484,     0,     0,     0,   491,   492,
     493,     0,     0,  2396,   485,   486,   487,   488,   489,   490,
       0,     0,  1308,  1309,  1310,     0,     0,     0,   283,  1311,
    1312,    39,   491,   492,   493,     0,     0,     0,     0,     0,
       0,  1313,  1314,     0,   485,   486,   487,   488,   489,   490,
       0,     0,     0,   494,     0,     0,   495,     0,   496,     0,
       0,     0,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,     0,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   494,     0,     0,
     495,   485,   486,   487,   488,   489,   490,     0,     0,   496,
       0,     0,     0,   499,     0,     0,  2396,     0,     0,   491,
     492,   493,     0,  1315,   497,  1308,  1309,  1310,   498,     0,
       0,   283,  1311,  1312,    39,     0,     0,     0,     0,     0,
       0,   500,     0,     0,  1313,  1314,     0,   494,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,     0,   499,     0,     0,     0,     0,     0,
       0,   494,     0,     0,   495,     0,   496,  1002,     0,     0,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   497,   500,     0,     0,   498,     0,     0,     0,     0,
       0,   494,     0,     0,   495,     0,     0,     0,     0,     0,
     501,     0,     0,     0,     0,     0,     0,   484,     0,     0,
     496,     0,     0,     0,     0,     0,  1315,     0,     0,     0,
       0,   499,     0,     0,     0,   497,     0,     0,     0,   498,
     502,     0,     0,     0,  1003,     0,     0,     0,  1134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   500,
       0,   495,     0,     0,     0,     0,     0,     0,     0,     0,
     496,     0,     0,     0,     0,   499,     0,   501,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,  1006,   498,
       0,   502,     0,     0,   496,     0,     0,     0,     0,     0,
       0,     0,     0,   500,   483,     0,   503,     0,     0,   497,
       0,     0,     0,   498,   485,   486,   487,   488,   489,   490,
       0,   501,     0,     0,   496,   499,     0,     0,     0,     0,
       0,   484,   491,   492,   493,     0,     0,     0,     0,   497,
       0,     0,     0,   498,     0,     0,     0,     0,     0,   499,
       0,  1134,  2397,   500,     0,     0,     0,   503,   502,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,     0,     0,     0,   500,     0,   499,
       0,   496,     0,     0,  1308,  1309,  1310,     0,     0,     0,
     283,  1311,  1312,    39,     0,   501,   497,     0,     0,     0,
     498,     0,   502,  1313,  1314,     0,     0,   500,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,   503,   501,     0,     0,   485,   486,
     487,   488,   489,   490,     0,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,   492,   493,   484,
       0,     0,   502,  1316,     0,  2397,     0,     0,     0,     0,
       0,     0,     0,     0,   500,     0,     0,     0,   503,     0,
       0,   494,     0,     0,   495,     0,   502,     0,     0,     0,
       0,     0,   501,     0,  1317,  1315,     0,  2398,     0,     0,
       0,     0,     0,     0,     0,  1308,  1309,  1310,     0,  2399,
    1319,   283,  1311,  1312,    39,     0,   502,     0,     0,     0,
       0,     0,     0,     0,  1313,  1314,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,  1702,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1320,     0,   503,     0,     0,     0,   485,   486,   487,   488,
     489,   490,  1321,     0,     0,     0,  1316,     0,     0,     0,
       0,     0,     0,   502,   491,   492,   493,     0,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   494,     0,  1317,   495,     0,
    2398,     0,     0,  1322,   496,     0,  1315,     0,     0,     0,
       0,     0,  2399,  1319,     0,     0,     0,     0,     0,   497,
    1134,     0,     0,   498,  1308,  1309,  1310,     0,     0,     0,
     283,  1311,  1312,    39,     0,     0,  1323,     0,     0,   503,
       0,     0,  1324,  1313,  1314,     0,     0,     0,     0,     0,
       0,  1325,  1326,  1320,  1327,     0,     0,     0,     0,   499,
       0,     0,     0,     0,     0,  1321,  1328,  1329,     0,     0,
       0,     0,     0,     0,  1330,     0,     0,  1331,     0,     0,
       0,     0,     0,     0,     0,   304,     0,   500,     0,     0,
    1308,  1309,  1310,     0,     0,     0,   283,  1311,  1312,    39,
       0,     0,     0,     0,     0,   501,  1322,     0,     0,  1313,
    1314,     0,     0,   494,     0,     0,   495,     0,   496,     0,
       0,     0,     0,     0,  2397,  1315,     0,     0,     0,     0,
       0,  1134,     0,   497,     0,     0,     0,   498,     0,  1323,
       0,     0,     0,     0,     0,  1324,     0,     0,     0,     0,
       0,     0,     0,     0,  1325,  1326,     0,  1327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1328,
    1329,     0,     0,   499,     0,     0,     0,  1330,     0,     0,
    1331,     0,     0,     0,     0,     0,   502,     0,   304,     0,
       0,  1315,     0,     0,     0,     0,     0,     0,  1308,  1309,
    1310,   500,     0,     0,   283,  1311,  1312,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1313,  1314,   501,
       0,     0,     0,     0,     0,  1316,  1308,  1309,  1310,     0,
       0,     0,   283,  1311,  1312,    39,   496,     0,     0,     0,
       0,     0,     0,     0,     0,  1313,  1314,     0,     0,     0,
    1134,   497,   503,     0,     0,   498,  1317,     0,     0,  2398,
       0,     0,     0,     0,     0,     0,     0,     0,  2909,  2910,
       0,  2399,  1319,     0,   283,  1311,  1312,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1313,  1314,     0,
       0,   499,     0,     0,     0,     0,     0,     0,     0,  1315,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1320,     0,     0,     0,  1134,     0,     0,   500,
       0,     0,     0,     0,  1321,     0,     0,  1315,     0,     0,
       0,     0,     0,     0,     0,     0,  1316,   501,     0,     0,
       0,     0,     0,     0,  2909,  2910,     0,     0,     0,     0,
     283,  1311,  1312,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1313,  1314,  1322,   503,  1317,     0,  2911,
    1318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1323,     0,
       0,     0,     0,     0,  1324,     0,     0,     0,     0,     0,
    1702,     0,     0,  1325,  1326,     0,  1327,     0,   502,     0,
       0,     0,     0,  1320,  1134,     0,     0,     0,  1328,  1329,
       0,     0,     0,     0,     0,  1321,  1330,     0,     0,  1331,
       0,     0,     0,     0,  1310,  2911,     0,   304,   283,  1311,
    1312,    39,  1134,     0,     0,  1316,     0,     0,     0,     0,
       0,  1313,  1314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1322,     0,     0,     0,
       0,     0,     0,     0,   503,     0,  1317,     0,     0,  1318,
       0,     0,     0,     0,  1134,     0,     0,     0,     0,     0,
       0,     0,  1319,     0,     0,     0,     0,     0,     0,  1323,
       0,     0,     0,     0,     0,  1324,     0,     0,     0,     0,
       0,  1316,     0,     0,  1325,  1326,     0,  1327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1328,
    1329,  2233,  1320,  1315,     0,     0,     0,  1330,     0,     0,
    1331,     0,  1317,     0,  1321,  1318,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1319,     0,
    1134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1322,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3356,  1320,     0,
       0,     0,     0,     0,     0,   206,     0,     0,     0,     0,
    1321,     0,     0,     0,   207,     0,     0,     0,  1323,  1316,
       0,     0,     0,     0,  1324,     0,     0,     0,     0,     0,
       0,     0,     0,  1325,  1326,     0,  1327,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2030,  1328,  1329,
    1317,  1322,     0,  1318,     0,     0,  1330,     0,  1134,  1331,
       0,     0,     0,     0,     0,     0,  1319,   304,     0,     0,
       0,     0,  2264,  2265,  2266,  2267,  2268,  2269,  1317,     0,
       0,  1318,     0,     0,  1323,     0,     0,     0,     0,  1316,
    1324,   208,     0,     0,  1319,     0,     0,     0,     0,  1325,
    1326,     0,  1327,     0,     0,     0,  1320,   209,   210,     0,
       0,     0,     0,     0,  1328,  1329,     0,   211,  1321,     0,
    2912,     0,  1330,  2913,     0,  1331,     0,  2264,  2265,  2266,
    2267,  2268,  2269,   304,  1320,     0,  2914,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1322,
       0,     0,     0,  1702,     0,  1316,     0,     0,     0,  2270,
       0,     0,     0,     0,     0,     0,  2916,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1322,  2917,     0,
       0,     0,  1323,     0,     0,     0,  2912,     0,  1324,  2913,
       0,     0,     0,     0,     0,     0,     0,  1325,  1326,     0,
    1327,     0,  2914,     0,     0,     0,     0,     0,     0,     0,
    1323,     0,  1328,  1329,  2270,     0,  1324,     0,     0,  2918,
    1330,     0,     0,  1331,     0,  1325,  1326,     0,  1327,     0,
       0,   304,     0,     0,     0,     0,     0,     0,     0,     0,
    1328,  1329,  2916,     0,     0,     0,     0,     0,  1330,     0,
       0,  1331,     0,  1316,  2917,     0,     0,     0,  2919,   304,
       0,     0,     0,  3326,     0,     0,     0,     0,     0,     0,
    2920,     0,     0,     0,     0,     0,     0,   212,     0,     0,
       0,     0,  2921,  2922,  1317,     0,     0,  1318,     0,     0,
    2923,     0,     0,  2924,     0,  2918,     0,     0,     0,     0,
    1319,   304,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,     0,     0,     0,
    3327,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2919,   214,   215,   216,   217,     0,
    1320,     0,     0,     0,     0,  3328,  2920,     0,     0,     0,
       0,     0,  1321,   218,  3329,     0,     0,     0,  2921,  2922,
       0,     0,     0,     0,     0,     0,  2923,     0,     0,  2924,
       0,     0,     0,     0,     0,   219,     0,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,     0,     0,
       0,     0,  3330,  1322,     0,  2271,     0,     0,   221,     0,
    3331,     0,     0,     0,     0,     0,     0,     0,  2272,     0,
       0,     0,     0,     0,   222,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,  1323,     0,     0,     0,
       0,     0,  1324,     0,     0,     0,     0,     0,     0,   224,
       0,  1325,  1326,     0,  1327,     0,     0,     0,     0,     0,
    2271,     0,     0,     0,     0,     0,  1328,  1329,     0,     0,
       0,     0,     0,  2272,  1330,     0,     0,  1331,     0,     0,
    2273,     0,     0,     0,     0,   304,  2274,     0,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3332,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2275,     0,   227,     0,     0,
       0,     0,     0,     0,   228,  2273,     0,   229,     0,     0,
       0,  2274,     0,     0,     0,     0,     0,     0,     0,  2276,
       0,     0,     0,     0,     0,     0,     0,     0,   230,  2277,
    2278,     0,   231,     0,     0,  2279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2280,     0,     0,     0,     0,
    2275,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2281,     0,   233,
    2282,  2283,     0,     0,  2276,  2284,     0,     0,     0,     0,
       0,     0,     0,     0,  2277,  2278,     0,     0,     0,     0,
    2279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2281,     0,     0,  2282,  2283,     0,     0,     0,
    2284,     0,  2285,     0,     0,     0,     0,     0,     0,     0,
       0,  3333,     0,  2286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2286
};

static const short yycheck[] =
{
       3,     4,     5,     6,   268,   269,     9,    10,   178,   197,
     112,   275,   667,   404,  1071,    53,  1149,   270,   271,   705,
    1481,  1308,  1309,   133,  1146,    62,  1189,  1164,   555,  1160,
    1161,   809,  1163,  1638,  1165,  1166,  1014,  2082,  2028,  1017,
    1389,  1396,   598,  1184,    47,   601,   793,   650,   254,   608,
    2220,   737,   738,  1603,  1604,  2375,     5,    60,  1145,    62,
      98,   581,  2618,  2619,  2620,    20,    77,  1769,    27,    27,
      73,   180,    27,  2080,  1824,  1949,   178,    80,     5,  1772,
      26,    27,    85,    27,     5,    88,    25,  1763,    27,    92,
      93,    27,  2065,  2263,  2067,   197,    27,  1702,    27,    19,
    1343,   768,  1345,   789,    24,    25,    26,    24,   111,    26,
    2338,     5,   123,  1711,  1712,  1713,  1714,    36,  1240,   115,
       8,     5,     5,  2151,   127,   154,   729,   130,     5,   132,
     240,  2621,  1254,     5,   137,   245,   246,   740,     5,    30,
    1273,    53,     5,    34,   155,     5,    25,     5,    27,    40,
      24,    25,    26,    27,    27,    20,    24,    25,    26,   329,
      25,    20,    27,   272,   117,   217,    25,   276,    27,   278,
       5,   280,   281,   282,   732,    25,    26,    27,   799,   811,
     289,    25,    27,    27,   293,   294,    98,  1244,     5,   117,
       5,    27,   795,   459,     5,   798,   199,     5,     5,    24,
      25,    26,    27,     5,   807,  2076,  2077,  2078,    48,    25,
    2081,    27,     9,     5,    27,    12,    13,    14,    15,    16,
      17,   232,    25,   234,    27,  2003,     5,   329,  2006,    63,
    1421,    19,   334,    24,    25,    26,    27,    19,    26,   130,
      24,    25,    26,    27,    26,   248,     9,     5,     5,    12,
      13,    14,    15,    16,    17,     5,    26,   260,    18,    19,
      20,    21,    22,   266,   267,   268,   269,   270,   271,    33,
     197,   829,   275,  2144,   400,     5,   136,   137,  2390,    27,
    2392,  1323,  2704,  1325,  1326,    25,    33,    27,   123,    27,
     125,    27,   127,    25,  1961,    27,     5,   674,   244,    27,
     204,     5,   142,   143,   328,   191,   140,   141,   446,   290,
     395,  3147,    23,   100,   101,   102,   103,   104,   145,   322,
     323,   220,  3158,   387,   588,    25,   511,    27,   331,   115,
     333,     5,   414,    13,   443,  2325,   548,   446,   526,     5,
     351,    27,   598,     5,   608,   511,   357,     0,   400,  1436,
       5,   728,   712,  2398,   463,   464,   465,   466,   564,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,     5,    18,    19,    20,
      21,    22,  1068,   446,    64,    20,   495,   496,    27,   352,
     511,   500,    27,   502,     5,   444,    36,  1538,  1145,   290,
     411,   364,  1751,  2153,  1090,    31,   515,   516,   517,   518,
      28,   703,   704,   669,   523,   478,   972,  1772,   778,   244,
     590,     6,    29,  1480,   526,     5,   422,   628,   244,     6,
      24,    25,    26,    27,   328,    25,     6,    27,  2309,    30,
       5,   244,   663,    34,   328,     5,   528,     5,  2319,   741,
       5,     5,   744,   244,   668,  1916,    25,     5,    27,  2057,
     244,     5,   754,   296,   298,     5,   758,   668,   409,     5,
     762,   430,     5,   685,     5,     5,     5,   769,   666,   243,
     244,     5,   774,     5,   776,    19,   671,   671,   590,   302,
     782,     5,    26,   785,     5,     5,     5,   244,     5,     5,
     792,     5,   566,   641,   244,   671,   244,   799,   244,   490,
       5,   514,   244,   577,   806,     5,   244,   108,   556,   557,
     411,   647,   786,   204,   115,   817,   119,     5,     5,   821,
       5,   703,   704,   825,   545,     5,   708,   709,   409,   831,
     493,     5,   834,  2414,   244,   630,   549,     5,   551,   721,
     671,   804,   805,     5,     5,   637,   559,     5,     5,     5,
     405,  1171,  1172,  1195,   666,  2343,     5,     5,   459,   741,
     161,   162,   744,   576,   446,   578,  1208,   288,   750,   337,
     833,   449,   754,   836,   587,   588,   758,    27,   591,     5,
     762,    10,   405,     5,   766,   767,   620,   769,     5,   490,
     772,  2591,   774,   775,   776,   608,  2156,   553,     5,    27,
     782,     5,     5,   785,     5,    30,     5,     5,   647,    34,
     792,    39,     5,     5,   449,    40,   731,   799,   519,   426,
     427,   446,   561,   337,   806,   446,   422,   109,   110,   120,
    2307,   594,   515,  3065,   556,   817,  2517,   483,  2693,   821,
     244,  1272,   444,   825,   613,   439,  1847,   405,   446,   831,
     606,   710,   834,   426,   427,  3155,   594,   139,   140,   141,
    1197,   479,   429,  2843,   578,   244,   446,   479,   523,  2907,
     566,  2654,    27,   446,   481,    25,  1439,    27,   567,  1436,
      30,  2296,  2862,   696,   697,   698,   699,   700,   701,   702,
     479,   439,   705,   706,   707,   641,   417,   710,   607,   712,
     523,   439,   715,  2587,   717,   130,  1853,   605,   481,   479,
    2948,   598,   641,   726,   668,   608,   620,  2305,  1383,   479,
    1416,   591,  2603,   729,   737,   738,   620,   668,   605,  1425,
     598,   668,   160,  1299,   747,   608,  1302,  1303,   669,   479,
     753,   671,  2759,  1840,   671,   539,   759,   760,   761,   718,
     718,  2463,   765,   718,   713,   768,  1452,   770,   771,  2445,
     479,  1291,  2465,  2128,   720,   778,  1443,  2132,   781,   718,
     446,  1903,  2789,   786,   787,   602,   789,  2030,  2816,   718,
     793,   209,  2820,   796,  2767,   602,  2769,   671,   663,   802,
    3120,   804,   805,   671,   663,   479,   809,   810,   811,   389,
    1442,   608,   815,   663,  3134,   818,  3372,   479,   678,   663,
     823,   637,  1454,   523,   479,   628,   244,   830,   246,   832,
     833,   422,   835,   836,   669,   838,   839,   677,   479,   730,
     674,   605,   677,   483,   483,   608,   671,   328,   635,   442,
     479,  2094,  2095,   641,  2966,   449,  1989,  1149,   605,   641,
     440,   446,   602,   690,   691,   692,   693,   694,   479,   446,
     510,   511,   465,   421,  2259,   290,   446,   674,   289,    23,
     671,   446,    27,  2754,   303,  2756,   446,   671,   446,   217,
      23,   446,   446,   483,   395,  1004,   889,   578,  1007,  1290,
      14,    27,   446,     5,   244,  1014,   446,  1016,  1017,  1887,
     446,   674,   446,   446,   483,   446,   446,   446,  1528,   400,
       5,    25,   446,    27,   446,   343,   517,   724,   725,   523,
     380,   228,   446,   573,   483,   446,   446,   446,   483,   942,
     446,  1627,   446,  1629,  1630,  3115,  3266,  1633,  1634,  2499,
     290,   446,   395,  1639,   299,   548,   446,   397,   506,   380,
     511,   724,   725,   444,    27,   405,   406,   312,   446,   446,
     574,   446,   415,  1576,   522,   446,   446,  1149,   483,  1271,
    1272,  1273,   446,   192,   193,   446,   989,   460,   446,  2962,
     430,  2964,  2965,   433,   412,   446,   411,   349,   446,   446,
     446,  1560,   420,  3048,   373,   414,   424,   446,   446,   449,
      25,   212,    27,   511,  1025,  2593,  2594,   565,   609,  2992,
    1547,   446,   441,  2894,   443,    25,   483,    27,   325,  1032,
     446,  1034,  1718,  2904,   446,   507,  2682,   989,  2684,   446,
      26,  2687,   460,    25,   459,    27,   483,   640,  1801,   446,
    1803,   483,   446,   446,   511,   446,   604,   446,   446,   652,
     653,    26,    27,   446,   446,  1068,  3265,   660,  1071,   414,
    3269,   411,   400,   510,    25,   490,    27,   671,    18,    19,
      20,    21,    22,   533,  1087,   633,  2973,  1090,  2437,  2976,
    1296,   446,  2979,  1840,   642,    26,    27,   523,   689,  1271,
    1272,  1273,  2243,   205,   519,   531,   697,   518,   526,  2933,
    2465,   312,   533,   553,   733,  3160,  2987,   483,   244,   528,
     205,   593,  1678,   299,  2181,  1681,  1129,    26,    27,   630,
     482,  1134,   677,  2376,  3124,  2378,   312,  2380,   757,   620,
     244,    25,  1145,    27,   288,   446,   557,   565,   690,   350,
     490,   693,   694,  1839,   299,   288,  1159,  1160,  1161,   446,
    1163,   483,  1165,  1166,   636,  2550,   606,   312,  1171,  1172,
     641,   589,   677,   613,   647,  1168,   302,   650,  2311,   519,
     641,  1959,  1175,   528,   803,   590,   421,   630,   551,  1792,
     483,   590,  1195,  1457,   813,   483,   559,   816,   218,   544,
     220,   820,  1455,  1206,  2337,  1208,   478,   826,   218,   828,
     220,    26,    27,   414,  1217,   633,   641,  1220,   511,   700,
     701,   702,  1225,   483,   642,   245,   676,   428,   637,   244,
     711,    25,     0,    27,   639,   245,   299,    25,   414,    27,
     639,  1244,  1245,   726,   244,   695,   696,   299,   511,   312,
    1253,    26,    27,  1885,    22,   676,  3127,  2913,   483,   676,
     312,    25,   244,    27,   747,   715,  1269,  1270,   596,   414,
     590,   506,   511,   417,   695,   696,  1386,   760,  1388,   244,
     489,  1967,   699,    25,   483,    27,   641,   522,    20,    26,
      27,  2896,  1295,   244,   715,    27,  1560,   336,   483,  1469,
    3187,   629,  1555,  1556,   324,  1308,  1309,   327,   726,   727,
     349,  3135,  3136,   244,   324,  1318,   483,   327,  1876,   639,
     336,  1953,  2617,  2618,  2619,  2620,   483,   528,  1331,   349,
     565,   641,     5,   349,  2980,     8,  1339,   670,   483,   349,
     641,   483,  1869,   544,   677,   244,  3319,  1600,  1601,  3220,
      26,   414,   528,   663,   641,  2397,   533,  2399,   676,  2481,
     244,  2047,   414,   676,   292,   483,  1318,  1469,   544,   604,
    3253,  3254,  3255,    26,  1411,   260,   261,   262,  2839,   677,
     698,   699,   218,   528,   220,   698,   699,  1390,   421,  2526,
     483,  1394,  1395,  1396,  2681,  2682,  2559,  2684,   633,   544,
    2687,  2523,   641,  1406,  1407,  1408,   483,   642,  1411,  1412,
    1413,  1414,  1415,  1416,    24,    25,    26,    27,   483,   641,
     483,   349,  1425,   421,   663,    28,    29,    37,    38,   244,
     817,   483,   671,  1436,   821,  1438,   483,  1440,   825,  1442,
    1443,   663,  2583,   482,  2799,   483,    20,  1450,  1451,  1452,
     244,  1454,  1455,    27,  1457,  1458,   244,  2143,  3341,   221,
    3343,  2017,   482,  1466,  1083,   528,   482,  2023,  2024,   244,
    1473,  1474,   482,   506,   483,   403,   528,  1480,  1481,   407,
     244,   544,  2078,   677,  3140,  2081,  2947,   483,   324,   522,
    3146,   327,   544,  3149,  3150,  3151,  3152,   744,    25,   676,
      27,  2133,   244,    20,   421,  2137,   446,   244,   506,   119,
      27,   758,   483,   349,  2146,   762,   510,   511,   695,   696,
     483,   483,  1525,  1526,   522,  1528,  2129,   774,  1531,  1532,
     832,   483,   565,   835,   292,    19,   838,  1829,   715,  2171,
      24,  3139,    26,  3141,  3142,  3143,  3144,   510,   511,   483,
    1553,    20,  1555,  1556,   482,    26,  2534,  1560,    27,  1562,
    1670,  1564,  1565,  1566,  2542,  2543,  2544,   565,   453,   483,
    1189,   604,   483,  3323,    20,  2617,  2618,  2619,  2620,  2182,
    1199,    27,  1201,   483,    24,  1588,    26,    20,   190,   506,
    3340,   349,   483,  1846,    27,    20,  1599,  1600,  1601,   421,
     633,   483,    27,  1606,  1607,   522,   604,   421,  2294,   642,
     573,   721,   722,   723,  2909,  2910,  3272,   483,  2913,  3275,
    3276,  3277,  3278,  1626,  1627,   483,  1629,  1630,  1737,  2232,
    1633,  1634,   483,  1636,   244,   633,  1639,  2323,    24,    25,
      26,  2683,  3392,  2685,   642,   403,   482,    26,   565,   407,
     252,   391,   254,  2339,   164,   165,   166,  1829,  3119,  3409,
    1663,    24,   402,    26,  1956,    25,   671,    27,   270,  1933,
    1934,  1674,   434,    25,   292,    27,   278,    26,  1169,  1170,
     282,   776,  1173,  1174,   506,    26,   448,   604,   691,   692,
     785,   293,   506,  2980,    25,  1948,    27,  1989,   156,   157,
     522,  1704,   578,  1706,  2390,   307,  2392,  3363,   522,    25,
     483,    27,   452,  1716,  1717,  1718,   633,    24,  1721,    26,
    1723,  1724,  1725,  1726,   482,   642,   466,   483,    25,   491,
      27,   349,  1743,  1736,   510,   511,   831,   199,   483,   834,
     502,   203,    24,   565,    26,   483,    25,   491,    27,   116,
     483,   565,  1704,   483,  1706,  1758,   693,   694,   502,  1868,
    1763,   523,   700,   701,  1716,  1717,  1769,   483,   530,  1772,
     483,  1723,  1724,  1725,  1726,    25,   538,    27,  1887,   523,
     483,    24,   604,    26,  1956,   403,   530,  1790,    26,   407,
     604,  2848,   473,  1796,   538,    24,   511,    26,   560,    25,
     483,    27,  2358,    26,    25,  2361,    27,  2363,  2364,    26,
      24,   633,    26,   700,   701,   555,   560,  1989,    26,   633,
     642,    26,  1825,   190,    19,  1444,  1445,  1446,   642,    24,
      25,    26,  2518,    24,    26,    26,  1839,  1840,    26,   449,
    1843,  1844,  1461,  1846,    26,  3140,    18,    19,    20,    21,
      22,  3146,  3147,  2485,  3149,  3150,  3151,  3152,  1861,   664,
     665,   666,   667,  3158,   482,   341,   342,  2909,  2910,   671,
     480,  2913,   113,   483,  2852,   637,    18,    19,    20,    21,
    1883,   643,  1885,  2455,  2456,   252,   496,   254,  2520,    25,
     991,    27,  1438,   994,  1440,   996,   997,   998,   999,  1000,
    2909,  2910,   446,   270,  1907,   709,  1909,  1910,   416,  1912,
    1529,   278,  1915,  1916,   671,   282,    26,   721,   214,   483,
    2617,  2618,  2619,  2620,   446,   483,   536,   479,  3069,  1548,
    1933,  1934,     5,   229,   230,   446,   483,  3078,   548,   446,
     307,   446,   238,   446,   446,  1948,   750,   446,  1567,   483,
    1953,  1954,  1955,   523,  3095,   677,  1959,    20,    20,  1578,
    1912,   446,   766,   767,  1967,   483,     5,   483,   772,   483,
     483,   775,   511,   675,    26,   671,   272,  3272,    26,   589,
    3275,  3276,  3277,  3278,   312,   281,   446,   446,   479,   416,
      30,  1994,    20,    26,  2164,    26,    26,    26,   641,  2002,
    2003,    26,    26,  2006,   146,   147,   148,   149,   150,   151,
      26,   446,   446,  2305,   310,    26,   446,   446,   628,  2311,
     446,    26,     5,   446,    20,  2028,  3159,    26,   483,   671,
     640,    26,    26,    26,  2037,   446,     5,  2040,  2041,  2042,
    2043,  2044,   652,   653,  2047,  2337,   446,   677,  2051,  2052,
     660,    26,  2055,   663,    20,    21,   446,   356,   446,   355,
     675,   671,  2164,   446,   446,   446,     5,   483,  3363,   446,
     446,   677,    26,  2076,  2077,  2078,  2028,  3372,  2081,  2082,
    2083,   446,    26,  2086,   641,  2037,   677,   446,  2040,  2041,
    2042,  2043,    25,    25,  2780,    25,   446,    25,  3140,   446,
     446,  3242,   446,   399,  3146,  3147,   446,  3149,  3150,  3151,
    3152,   446,  2115,   446,  2117,  2118,  3158,  2120,  2121,    20,
      21,  2124,   446,   356,   446,  2128,    25,   446,   446,  2132,
    2133,   446,   675,  2305,  2137,    18,    19,    20,    21,  2311,
    2143,  2144,   671,  2146,  2147,   483,   671,  2150,  2151,     8,
     676,  2709,  2710,  2711,   479,  2713,  2714,  2715,  2716,  2717,
    2718,   531,   320,     5,  2722,  2337,   647,   512,  2171,  1704,
     647,   669,   669,   473,  2806,  2178,  1795,   710,  2181,   710,
     146,   147,   148,   149,   150,   151,   512,  2190,   671,   382,
     511,  2194,  1811,   190,  3251,  3326,  3327,  3328,  3329,  3330,
    3331,   671,  2834,   648,     5,   473,   663,     5,   483,   483,
     483,  3352,  2909,  2910,   483,   400,  2913,  2220,   483,  1838,
     630,     8,    14,   627,     5,     5,  1845,   473,   710,   483,
    3272,   710,   483,  3275,  3276,  3277,  3278,    26,    26,   120,
     145,  2244,    26,   671,   511,   146,   147,   148,   149,   150,
     151,   483,   641,   483,   473,   252,  1875,   254,   483,   483,
      26,   483,   511,   146,   147,   148,   149,   150,   151,   731,
     732,   483,   483,   270,   483,     5,  1895,   483,   647,    47,
    2966,   278,   483,     5,   677,   282,   483,    48,   406,   483,
     677,  2294,   713,     5,   608,   668,   676,    18,   207,    19,
     446,  2593,  2594,   438,   641,     5,  2309,    25,   674,  2573,
     307,  2575,   598,   630,  2317,  2318,  2319,   671,  2356,  2322,
    2323,  3363,  2325,   205,   534,    26,   598,   534,   453,    26,
    3372,   377,   231,   446,   598,  2338,  2339,    26,  2993,  2342,
    2343,   446,   446,   111,   112,   677,  2516,   446,   523,   446,
     578,   671,   446,   483,   677,   483,   483,   483,   112,   483,
       5,   671,   715,   641,  3342,   446,   671,   829,   483,   677,
    2558,   641,     5,  2325,   668,     5,     5,   839,   598,  2382,
    1915,     5,   671,   631,    25,   535,   677,  2390,   676,  2392,
    2393,   483,     5,  2396,     8,  2398,   373,   120,    26,    26,
    2956,   272,  2958,  2959,     5,   381,  2409,     5,   446,   483,
     178,  2414,  2415,  2416,  2516,   483,   483,   415,  3475,   677,
    2529,  2593,  2594,    14,  2427,  2534,   711,   598,   602,   197,
    2382,     5,   648,  2542,  2543,  2544,    26,   154,   483,   483,
    3072,   677,  2445,  3140,   671,   598,  2398,     5,   690,  3146,
    3147,     5,  3149,  3150,  3151,  3152,  2558,  2409,  3090,   358,
    2463,  3158,  2465,   676,   479,   364,   365,   366,   446,     5,
       5,   423,   446,   677,   676,  2478,   446,   387,    26,   479,
     670,   513,  2485,     5,   671,     5,   513,   386,   671,     8,
     511,   483,   483,  2460,   483,   483,   483,   483,   266,   483,
       5,   483,   671,  2122,   605,   628,   381,  2510,    25,  2512,
     400,  2514,   400,   400,  2517,  2518,   671,  2520,   483,  2138,
    2139,  2140,  2141,   415,     5,   478,   511,   989,     5,   702,
     511,    26,  2535,     5,  2537,  2538,  2539,     5,    25,    14,
    2159,    14,    26,   483,   647,   647,   668,   605,     5,     5,
    2553,    45,    46,    47,   322,   323,    50,  2560,    52,    53,
      26,   329,   483,   677,  2955,     6,   334,  1281,   446,   446,
    2573,  2824,  2575,   446,   446,  3272,   446,     7,  3275,  3276,
    3277,  3278,  2585,  2586,  2837,   500,   322,     5,  2591,   446,
     231,   446,   491,   671,    26,   494,   671,    26,   677,    26,
    2603,  3233,    26,   502,    26,   671,   446,  2226,  2560,  1071,
     173,    20,     5,   328,  2617,  2618,  2619,  2620,  2621,  2622,
       5,     5,     5,   719,   446,     5,   598,     8,  2631,   671,
     446,   483,   523,  2636,   677,     5,   598,     5,   537,  2591,
     677,   675,   265,   623,   446,   618,   446,    26,  2818,   446,
    2617,  2618,  2619,  2620,   677,   677,   483,   677,   483,     5,
       5,    25,   675,   677,    25,    25,  3363,   670,   499,  2672,
    2673,    25,    25,   572,    26,  3372,    26,    26,  2681,  2682,
     350,  2684,    26,    26,  2687,    26,  2689,   446,   446,    26,
    2693,     5,   591,   592,   446,   446,   520,   483,     5,   446,
     483,   294,   602,   602,     8,    26,    25,   479,   607,  2328,
     400,  2330,   275,   446,   446,   493,  2818,   358,    20,   605,
     283,   483,   196,   364,   365,   366,   289,   483,   291,     5,
    2733,     5,    14,   483,   483,   483,   265,  2689,   483,   302,
    3296,  3297,  2745,  2852,   483,   386,   514,   646,   446,     5,
     446,  2754,  2755,  2756,   494,    26,   511,    26,   526,   446,
     446,    26,   446,    26,   483,    26,    26,   330,   429,   620,
     446,    26,   446,   294,   446,   483,   511,  2780,   400,   678,
     446,   295,  1244,   346,   493,   598,   446,    14,   351,  2792,
    2793,   483,   446,  2796,   446,     7,  2799,   293,    26,   446,
     363,   293,   446,  2806,  3068,   447,   483,   370,   677,   671,
     446,   446,   627,  2816,   483,    26,  2819,  2820,    25,   295,
     479,  2824,   590,   511,     5,   446,   446,   446,   446,   446,
     324,  2834,    26,   327,  2837,   329,  2839,    26,   446,   671,
       5,   671,   483,   446,    26,  2848,  1308,  1309,   479,  2537,
     491,   671,  3402,   494,   479,   349,  1318,  2478,  2216,  1016,
    1568,   502,  1896,    35,   685,   359,    37,  3159,  2147,  2153,
     119,   362,  2491,  2510,   214,  2494,   123,   670,  1742,   392,
     363,  1743,  3054,   353,   232,  2888,   380,   545,   219,  1307,
     391,  2894,  3064,   576,  3392,   611,   537,   578,   666,  1795,
    2903,  2904,   815,  2906,  2907,  1599,  2909,  2910,  2000,   403,
    2913,  2007,  1007,   407,   425,  1845,  1278,  2140,  2562,  1923,
    2874,  2924,  1602,  2240,  3446,  2143,  1943,  1457,   696,   697,
     698,   572,   700,  3086,    22,    98,    47,    47,    28,  1907,
    2559,  1901,  2909,  2910,  2947,  2948,  2913,  1661,  1662,   717,
     591,   592,  2356,   771,  1668,   518,  1579,   334,  1034,  1607,
     523,   602,  1910,  2966,  1526,   944,   607,   530,  1245,  3011,
    3196,  2974,  3409,   796,  2977,  1524,  1451,  2980,  2560,  1440,
    2983,  2748,  2985,  3206,  2987,   753,  1875,  3159,   482,   552,
    2746,   759,  1548,   761,   557,   462,  2731,   765,  2426,  2804,
     768,  3066,  3064,   771,  3057,   646,  2796,  2974,  3011,  2132,
    2977,  1758,  1775,   781,  2086,  2305,  3418,  2987,  1480,  1641,
    1641,  2324,  1978,  3220,  2906,  2787,  2753,  1966,   796,  2047,
    2672,  2983,  2396,  2985,   802,  2673,  3301,   678,  2775,  2977,
    2448,   809,   810,   811,  1626,  3048,  3029,   815,  2427,  2393,
     618,     9,  3464,  2415,  2908,   823,  1274,  2416,  1717,  2985,
    1716,  2604,  1621,  3262,  2318,  3068,  2903,  1270,  3138,  3072,
    3258,   839,  3146,    45,    46,    47,  3157,  2518,    50,  1594,
      52,    53,  2617,  2618,  2619,  2620,  1736,  3090,    15,    16,
      17,    18,    19,    20,    21,    22,  1474,  2164,  1134,  1456,
     554,    -1,  1466,  2516,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3119,    -1,    -1,    -1,
      -1,  3124,    49,    -1,  3127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3138,    -1,  3140,    -1,    -1,
      -1,    -1,    -1,  3146,  3147,  1607,  3149,  3150,  3151,  3152,
      -1,    -1,  3155,    -1,  3157,  3158,  3258,  3160,    -1,    -1,
      -1,    -1,    -1,    -1,  1878,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3124,  3140,    -1,    -1,    -1,    -1,    -1,  3146,
    3147,    -1,  3149,  3150,  3151,  3152,  3138,    -1,    -1,     5,
      -1,  3158,    -1,  3196,    -1,    -1,    -1,    -1,  3201,    -1,
    3203,    -1,    -1,    -1,    -1,  1919,    -1,    -1,  2827,    -1,
    3177,    -1,    -1,    -1,    -1,    -1,    -1,  3220,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
    3233,    -1,    -1,  3342,    -1,    -1,    -1,   164,   165,   166,
      -1,    -1,  1704,    -1,  1706,  2864,   128,   129,  3251,   131,
     132,   133,    -1,    -1,  1716,  1717,    -1,    -1,    -1,  3262,
      -1,  1723,  1724,  1725,  1726,  3268,    -1,    -1,    -1,  3272,
      -1,    -1,  3275,  3276,  3277,  3278,    -1,  3280,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3294,    -1,    -1,    -1,    -1,    -1,    -1,  3301,    -1,
      -1,    -1,  3305,  1071,    -1,  3272,    -1,    -1,  3275,  3276,
    3277,  3278,    -1,    -1,    -1,    -1,  3268,    -1,    -1,  1087,
      -1,    -1,    -1,  3326,  3327,  3328,  3329,  3330,  3331,    -1,
      -1,    -1,    -1,    -1,  3301,  3338,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,   324,  3305,    -1,   327,   238,   329,    -1,    -1,
    3363,  1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3372,
      -1,    -1,    -1,    -1,  2909,  2910,   303,   349,  2913,   306,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,
     272,  1159,  1160,  1161,    -1,  1163,  3363,  1165,  1166,   281,
      -1,    -1,    -1,  1171,  1172,  3372,    -1,    -1,   380,    -1,
      -1,    -1,    -1,    -1,  1876,  3418,    -1,  3420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1195,   310,   311,
      -1,   403,    -1,    -1,    -1,   407,    -1,    -1,    -1,  2974,
    1208,    -1,  2977,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1912,    -1,  1220,    -1,    -1,  3074,    -1,    -1,    -1,  3462,
    3463,  3464,    -1,    -1,    -1,    -1,  3418,    -1,    -1,    -1,
      -1,    -1,  3475,   355,  3477,    -1,  1244,  1245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1253,    -1,    -1,    -1,    -1,
      -1,  3110,    -1,    -1,    -1,    -1,  2210,  2211,   314,   426,
      -1,  1269,  1270,    -1,    -1,    -1,    -1,  2221,    -1,    -1,
     482,    -1,    -1,    -1,   441,    -1,    -1,   399,   445,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2245,  2246,  2247,  2248,  2249,  2250,   353,    -1,    -1,
      -1,  2255,  2256,  2257,  2258,    -1,    -1,    -1,  2262,    -1,
      -1,    -1,    -1,    -1,   481,    -1,   372,   373,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2028,    -1,    -1,    -1,
      -1,   453,    -1,    -1,    -1,  2037,    -1,    -1,  2040,  2041,
    2042,  2043,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2052,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,
     527,    -1,    -1,  3138,    -1,  3140,    -1,    -1,   424,    -1,
      -1,  3146,  3147,    -1,  3149,  3150,  3151,  3152,    -1,   435,
    2082,    -1,    -1,  3158,    -1,    -1,    -1,    -1,    -1,    -1,
    2344,  2345,    -1,    -1,     9,   451,    -1,  2351,  2352,    -1,
      -1,    -1,    -1,    18,    19,   461,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     476,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
    1438,    -1,  1440,    -1,  1442,  1443,    -1,    -1,    -1,    -1,
      -1,   608,  1450,  1451,    -1,    -1,  1454,    -1,    -1,    -1,
    1458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     516,  1469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1480,  1481,    -1,    -1,    -1,    -1,  3337,  2181,
      -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3272,   554,   114,
    3275,  3276,  3277,  3278,   119,   561,    -1,   674,   564,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,  1525,  1526,    -1,
    1528,    -1,    -1,  1531,  1532,    -1,  3301,    -1,    -1,   585,
      -1,    -1,    -1,   589,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2500,  2501,    -1,    -1,
      -1,    -1,   608,    -1,  1562,  2509,    -1,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,    -1,    -1,    -1,
     626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1588,    -1,  3441,    -1,    -1,    -1,    -1,    -1,  3363,    -1,
      -1,    -1,    -1,  2547,  2548,    -1,    -1,  3372,  1606,  1607,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
    2574,    -1,  2576,  2325,    -1,    -1,    -1,    -1,    -1,   244,
      -1,   246,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1663,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2382,    -1,    -1,  2637,  2638,    -1,    -1,  2641,  2642,    -1,
      -1,    -1,    -1,    -1,  2396,    -1,  2398,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2409,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,
      -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      49,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2460,   164,
     165,   166,    -1,   378,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,   447,    -1,   449,    -1,    -1,   146,   147,   148,
     149,   150,   151,    -1,    -1,   460,    -1,    -1,    -1,    -1,
     465,    -1,    -1,  1861,    -1,   164,   165,   166,  2560,    -1,
     475,    -1,    -1,  2817,    -1,   480,    -1,  2821,   483,    -1,
      -1,   486,    -1,    -1,    -1,    -1,    -1,  1885,    -1,    -1,
     495,   496,    -1,    -1,    -1,    -1,  2840,    -1,    -1,  2591,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,   303,  1907,
      50,   306,    52,    53,    -1,    -1,  2860,    -1,  1916,    -1,
      -1,    -1,    -1,    -1,    -1,  2617,  2618,  2619,  2620,    -1,
     535,   536,    -1,    -1,   303,   540,    -1,   306,    -1,    -1,
      -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,  1953,  1954,  1955,    -1,    -1,
     565,  1959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2672,  2673,    -1,    -1,   589,    -1,    -1,    -1,    -1,  2681,
    2682,    -1,  2684,    -1,    -1,  2687,  1994,  2689,    -1,    -1,
      -1,  2693,    -1,    -1,   303,    -1,    -1,   306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2709,  2710,  2711,
      -1,  2713,  2714,  2715,  2716,  2717,  2718,    -1,   633,    -1,
    2722,   426,    -1,    -1,    -1,   640,    -1,   642,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,   652,   653,    -1,
     445,    -1,    -1,    -1,    -1,   660,    -1,   426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   671,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,   445,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,   481,    -1,   509,    -1,    -1,    -1,    -1,    -1,
      -1,   726,   727,    -1,    -1,   494,    -1,   426,    -1,    -1,
      -1,    -1,   527,    -1,    49,  2133,    -1,    -1,    -1,  2137,
     509,    -1,   441,    -1,    -1,    -1,   445,    -1,  2146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2848,    -1,   527,    -1,
       9,    -1,    -1,    -1,  3108,    -1,  2164,  3111,    -1,    18,
      19,    -1,    -1,  2171,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,   481,  2181,   324,    -1,    -1,   327,    -1,   329,
      39,    -1,  2190,    -1,    -1,    -1,  2194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,   349,
     509,    -1,    -1,   608,    -1,    -1,    -1,  2909,  2910,   359,
      -1,  2913,  2220,    -1,    -1,   373,   374,   375,   527,    -1,
      -1,   146,   147,   148,   149,   150,   151,    -1,    -1,   608,
     380,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,   164,
     165,   166,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,   403,   412,   114,    -1,   407,    39,    -1,
     119,    -1,    -1,    -1,    -1,    -1,   424,   126,    -1,   674,
      -1,    -1,  2974,    -1,    -1,  2977,    -1,   435,  2980,    -1,
      -1,  2983,    -1,  2985,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,   153,   674,    -1,    -1,    -1,   608,
      -1,    -1,  3256,   461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   482,   114,  2342,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,  3048,    -1,    -1,    -1,
      -1,    -1,    -1,  3307,  3308,    -1,  3310,    -1,  3312,  3313,
      -1,    -1,    -1,    -1,    -1,   674,   524,    -1,    -1,    -1,
      -1,    -1,   153,     9,    -1,    -1,    -1,    -1,   303,    -1,
      -1,   306,    18,    19,    -1,   244,    -1,   246,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,   564,  2415,    -1,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,  3124,    -1,    -1,    -1,  3380,   585,  3382,    -1,
      -1,   589,    -1,    -1,    -1,    -1,  3138,    -1,  3140,    -1,
      -1,    -1,    49,    -1,  3146,  3147,    -1,  3149,  3150,  3151,
    3152,    -1,    -1,    -1,    -1,    -1,  3158,    -1,  3160,   617,
      -1,    -1,  3416,   244,    -1,   246,    -1,    -1,   626,    -1,
      -1,    -1,    -1,    -1,    -1,  3177,    -1,  2485,   114,    -1,
      -1,  3435,  3436,   119,   343,  3439,    -1,    -1,  3442,   348,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,  2516,    -1,
      -1,    -1,  2520,    -1,    -1,    -1,   441,   153,    -1,   378,
     445,    -1,    -1,    -1,    -1,    -1,    -1,  2535,    -1,  2537,
      -1,  2539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,  2553,    -1,    -1,    -1,  3251,
    2558,    -1,    -1,   412,    -1,    -1,   481,   164,   165,   166,
      -1,    -1,   343,    -1,    -1,   424,  3268,    -1,    -1,    -1,
    3272,    -1,    -1,  3275,  3276,  3277,  3278,  2585,  2586,    -1,
      -1,    -1,    -1,   442,   509,    -1,    -1,    -1,   447,    -1,
     449,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,  3301,
      -1,   460,   527,  3305,    -1,    -1,   465,    -1,   244,    -1,
     246,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,
      -1,   480,    -1,  2631,   483,    -1,    -1,   486,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,   495,   496,    -1,    -1,
      -1,     9,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,  3363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3372,    39,    -1,    -1,    -1,    -1,   535,   536,    -1,   460,
      -1,   540,    -1,   608,    -1,    -1,    -1,    -1,    -1,   548,
      -1,    -1,    -1,    -1,   475,    -1,   303,    -1,    -1,   306,
     559,    -1,   483,    -1,    -1,    -1,   565,   343,    -1,    -1,
      -1,    -1,   348,    -1,    -1,   496,  3418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2733,    -1,    -1,    -1,    -1,
     589,    -1,    -1,    -1,    -1,    -1,    -1,  2745,    -1,    -1,
      -1,    -1,   378,    -1,    -1,    -1,   114,    -1,    -1,   674,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   540,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3475,   633,    -1,   412,    -1,    -1,    -1,
      -1,   640,    -1,   642,   565,   153,    -1,    -1,   424,    -1,
      -1,    -1,    -1,   652,   653,    -1,    -1,    -1,  2806,    -1,
      -1,   660,    -1,    -1,    -1,    -1,   442,    -1,   589,    -1,
    2818,   447,   671,   449,    -1,    -1,    -1,    -1,    -1,   426,
      -1,    -1,    -1,   314,   460,    -1,  2834,    -1,    -1,   465,
      -1,  2839,    -1,    -1,   441,    -1,    -1,    -1,   445,   475,
    2848,    -1,    -1,    -1,   480,    -1,    -1,   483,    -1,    -1,
     486,    -1,   633,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     496,   642,   353,    -1,    -1,    -1,    -1,   726,   727,    -1,
      -1,    -1,    -1,    -1,   481,    -1,   244,    -1,   246,    -1,
      -1,   372,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     536,    -1,   509,    -1,   540,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     527,   412,    -1,   559,    -1,   561,    -1,    -1,    -1,   565,
      -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,  2947,
      -1,     9,    -1,    -1,   435,   726,   727,    -1,    -1,    -1,
      18,    19,    -1,   589,    -1,    -1,    24,    25,    26,    27,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     461,    39,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,
     348,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   633,    -1,    -1,
      -1,   608,    -1,  3011,   640,    -1,   642,    -1,    -1,    -1,
     378,    18,    19,    20,    21,    22,   652,   653,    -1,    -1,
      -1,    -1,    -1,    -1,   660,   516,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   671,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,   412,    -1,   114,    -1,   539,    -1,
      -1,   119,    -1,    -1,    -1,    -1,   424,    -1,   126,    -1,
      -1,    -1,    -1,   554,  3072,    -1,    -1,   674,    -1,    -1,
     561,    -1,    -1,   564,   442,    -1,    -1,    -1,    -1,   447,
      -1,   449,  3090,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     726,   727,   460,    -1,   585,    -1,    -1,   465,   589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,
      -1,  3119,   480,    18,    19,   483,    -1,   608,   486,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   495,   496,    -1,
      -1,    -1,    37,    38,    -1,   626,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   536,    -1,
      -1,    -1,   540,    -1,    -1,    -1,   244,    -1,   246,    -1,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3196,    -1,
      -1,   559,    -1,  3201,    -1,  3203,    -1,   565,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   589,    -1,    -1,    -1,  3233,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,  3251,    -1,    -1,    -1,    -1,    -1,    -1,
    3258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   633,    -1,    -1,    49,    -1,
      -1,   186,   640,    -1,   642,   343,    -1,    -1,    -1,   194,
     348,    -1,    23,    -1,   652,   653,    -1,    -1,   203,    -1,
      -1,   206,   660,    -1,    -1,    -1,   303,    -1,    -1,   306,
      -1,    -1,    -1,   671,    45,    46,    47,    -1,    -1,    50,
     378,    52,    53,    -1,    -1,    -1,    -1,    -1,  3326,  3327,
    3328,  3329,  3330,  3331,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   244,
      -1,   256,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,   726,   727,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   442,    -1,   117,    -1,    -1,   447,
      -1,   449,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,    -1,   465,   313,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,   475,    -1,    -1,
      -1,    -1,   480,    -1,    -1,   483,    -1,    -1,   486,   426,
      -1,    -1,    -1,   338,    -1,    -1,    -1,   495,   496,    -1,
     345,    -1,   347,    -1,   441,    -1,    -1,    -1,   445,    -1,
      -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3475,   536,    -1,
     385,    -1,   540,    -1,   481,    -1,    -1,   218,   393,   220,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,    -1,    -1,    -1,    -1,    -1,   565,    -1,    -1,
      -1,    -1,   509,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,   254,    -1,   430,    -1,    -1,    -1,    -1,
     527,   589,   303,    -1,   265,   306,    -1,    -1,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,   454,
      -1,   282,    -1,    -1,   449,    -1,    -1,   288,    -1,    -1,
      -1,   292,   293,   294,   295,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   633,   307,    -1,    -1,    -1,
      -1,    -1,   640,    -1,   642,   480,   491,    -1,   483,    -1,
      -1,    -1,    -1,   324,   652,   653,   327,   502,   329,    -1,
      -1,   496,   660,    -1,    -1,   336,    -1,    -1,    -1,    -1,
      -1,   608,    -1,   671,    -1,    -1,    -1,    -1,   349,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     535,   536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   380,
     381,    -1,    -1,   548,    -1,   426,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,   726,   727,
     441,    -1,   403,    -1,   445,    -1,   407,   674,    -1,    -1,
      -1,    -1,    -1,    -1,   415,   416,   417,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   589,   600,   601,   602,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,   509,    -1,
      -1,    -1,    -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,
      -1,   482,    -1,    -1,    -1,    -1,   527,   652,   653,    -1,
      -1,    -1,   493,    -1,    -1,   660,    -1,    -1,   663,    -1,
      -1,    -1,    -1,     6,     7,     8,   671,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   533,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   716,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,   608,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,   594,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,
      -1,    -1,    -1,   674,   106,   107,    -1,    -1,    -1,   111,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   121,
     122,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,    -1,   158,   159,    -1,   690,
     691,   692,   693,   694,   695,   696,    -1,   698,   699,    -1,
     172,    -1,   174,   175,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   715,   187,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,   198,    -1,   200,   201,
     202,    -1,    -1,    -1,    -1,    -1,   208,    -1,   210,   211,
      -1,   213,    -1,   215,   216,    -1,    -1,   219,    -1,    -1,
     222,   223,   224,   225,   226,   227,    -1,    -1,    -1,   231,
     232,   233,    -1,   235,    -1,    -1,    -1,   239,    -1,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,   250,    -1,
      -1,   253,    -1,   255,    -1,   257,    -1,   259,    -1,    -1,
      -1,   263,   264,    -1,   266,   267,   268,    -1,    -1,   271,
     303,   273,   274,   306,   276,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   284,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,   300,   301,
      -1,    -1,   304,   305,    -1,    -1,   308,   309,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   317,   318,   319,    -1,   321,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   331,
     332,   333,    -1,   335,    -1,    -1,    -1,   339,   340,    -1,
      -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   361,
     362,    -1,    -1,    -1,    -1,    -1,   368,   369,    -1,    -1,
      -1,    -1,    -1,    -1,   376,    -1,    -1,   379,    -1,    -1,
      -1,   383,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   394,   426,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,   411,
      -1,    -1,   445,   446,    -1,    -1,    -1,   419,    -1,    -1,
      -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,   481,    -1,
      -1,    -1,   454,    -1,   456,   457,    -1,    -1,    -1,    -1,
      -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,
      -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   514,    -1,    -1,    -1,    -1,    -1,    -1,   521,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,   545,   546,    -1,    -1,    -1,   550,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     562,    -1,    -1,    -1,    49,    -1,   568,   569,   570,   571,
      -1,    -1,    -1,   575,    -1,   608,    -1,   579,    -1,    -1,
      -1,    -1,    -1,    -1,   586,   587,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   597,    -1,   599,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,
     612,    -1,    -1,   615,    -1,    -1,     6,     7,     8,   621,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   674,    -1,    -1,    -1,   647,    -1,    -1,   650,    -1,
      -1,    -1,    -1,   655,    -1,    -1,   658,   659,    -1,    49,
      -1,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,   680,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   703,   704,   705,   706,   707,   708,   709,    -1,    -1,
     712,    -1,   714,    -1,   716,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,   146,   147,   148,   149,
     150,   151,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      49,   306,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    49,    -1,    -1,
     164,   165,   166,    -1,    -1,    -1,    -1,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,   306,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,     6,     7,
       8,   426,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,   441,    -1,    -1,    -1,
     445,   446,    -1,    -1,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   306,    -1,    -1,    -1,   303,    -1,    -1,   306,
      -1,    -1,    -1,    -1,   509,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,   527,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,   441,    -1,    -1,    -1,   445,   446,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   306,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   481,    -1,    -1,    -1,    -1,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,
      -1,   303,    -1,   608,   306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,    -1,    -1,    -1,    -1,   527,    -1,   426,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,
      -1,   445,    -1,    -1,   441,    -1,    -1,    -1,   445,   446,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,   306,    -1,   481,    -1,   674,
      -1,    -1,    -1,    -1,   481,    -1,    -1,   426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,   509,   445,   446,   608,    -1,
      -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   527,    -1,   303,    -1,    -1,   306,    -1,
     527,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,   441,
      -1,    -1,    -1,   445,   446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     509,    -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,   481,
      -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,
     441,   608,    -1,    -1,   445,   446,    -1,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   527,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,   426,    -1,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   441,    -1,    -1,    -1,   445,   446,   608,
     674,    49,    -1,    -1,    -1,    -1,    -1,   674,   509,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   527,    -1,    -1,    -1,
      -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   509,    -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,   527,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,   608,    -1,    -1,
      -1,    -1,   674,    -1,    -1,    -1,   164,   165,   166,    49,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
     608,    -1,    -1,    49,    -1,    -1,    -1,   164,   165,   166,
       6,     7,     8,   674,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    49,    -1,    -1,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   674,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,    49,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   306,    -1,
     146,   147,   148,   149,   150,   151,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   306,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,   164,   165,
     166,    -1,    -1,     9,   146,   147,   148,   149,   150,   151,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   303,    -1,    -1,   306,    -1,   426,    -1,
      -1,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   441,    -1,    -1,    -1,   445,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
     306,   146,   147,   148,   149,   150,   151,    -1,    -1,   426,
      -1,    -1,    -1,   481,    -1,    -1,     9,    -1,    -1,   164,
     165,   166,    -1,   119,   441,    18,    19,    20,   445,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,   509,    -1,    -1,    37,    38,    -1,   303,    -1,    -1,
     306,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,
      -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,   306,    -1,   426,   494,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   441,   509,    -1,    -1,   445,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,
     527,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
     426,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,   481,    -1,    -1,    -1,   441,    -1,    -1,    -1,   445,
     608,    -1,    -1,    -1,   494,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   509,
      -1,   306,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,    -1,    -1,    -1,    -1,   481,    -1,   527,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,   494,   445,
      -1,   608,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   509,    22,    -1,   674,    -1,    -1,   441,
      -1,    -1,    -1,   445,   146,   147,   148,   149,   150,   151,
      -1,   527,    -1,    -1,   426,   481,    -1,    -1,    -1,    -1,
      -1,    49,   164,   165,   166,    -1,    -1,    -1,    -1,   441,
      -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,   481,
      -1,   244,   348,   509,    -1,    -1,    -1,   674,   608,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   527,    -1,    -1,    -1,    -1,    -1,   509,    -1,   481,
      -1,   426,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,   527,   441,    -1,    -1,    -1,
     445,    -1,   608,    37,    38,    -1,    -1,   509,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,   674,   527,    -1,    -1,   146,   147,
     148,   149,   150,   151,    -1,    -1,   481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,    49,
      -1,    -1,   608,   449,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,   674,    -1,
      -1,   303,    -1,    -1,   306,    -1,   608,    -1,    -1,    -1,
      -1,    -1,   527,    -1,   480,   119,    -1,   483,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,   495,
     496,    24,    25,    26,    27,    -1,   608,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,   674,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     536,    -1,   674,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   548,    -1,    -1,    -1,   449,    -1,    -1,    -1,
      -1,    -1,    -1,   608,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,   480,   306,    -1,
     483,    -1,    -1,   589,   426,    -1,   119,    -1,    -1,    -1,
      -1,    -1,   495,   496,    -1,    -1,    -1,    -1,    -1,   441,
     244,    -1,    -1,   445,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,   622,    -1,    -1,   674,
      -1,    -1,   628,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,   637,   638,   536,   640,    -1,    -1,    -1,    -1,   481,
      -1,    -1,    -1,    -1,    -1,   548,   652,   653,    -1,    -1,
      -1,    -1,    -1,    -1,   660,    -1,    -1,   663,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   671,    -1,   509,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,   527,   589,    -1,    -1,    37,
      38,    -1,    -1,   303,    -1,    -1,   306,    -1,   426,    -1,
      -1,    -1,    -1,    -1,   348,   119,    -1,    -1,    -1,    -1,
      -1,   244,    -1,   441,    -1,    -1,    -1,   445,    -1,   622,
      -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   637,   638,    -1,   640,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,
     653,    -1,    -1,   481,    -1,    -1,    -1,   660,    -1,    -1,
     663,    -1,    -1,    -1,    -1,    -1,   608,    -1,   671,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,   509,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,   527,
      -1,    -1,    -1,    -1,    -1,   449,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
     244,   441,   674,    -1,    -1,   445,   480,    -1,    -1,   483,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,   495,   496,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   536,    -1,    -1,    -1,   244,    -1,    -1,   509,
      -1,    -1,    -1,    -1,   548,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   449,   527,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,   589,   674,   480,    -1,   119,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,
      -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,
     523,    -1,    -1,   637,   638,    -1,   640,    -1,   608,    -1,
      -1,    -1,    -1,   536,   244,    -1,    -1,    -1,   652,   653,
      -1,    -1,    -1,    -1,    -1,   548,   660,    -1,    -1,   663,
      -1,    -1,    -1,    -1,    20,   119,    -1,   671,    24,    25,
      26,    27,   244,    -1,    -1,   449,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   674,    -1,   480,    -1,    -1,   483,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,   637,   638,    -1,   640,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,
     653,   535,   536,   119,    -1,    -1,    -1,   660,    -1,    -1,
     663,    -1,   480,    -1,   548,   483,    -1,    -1,   671,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   496,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   536,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    41,    -1,    -1,    -1,   622,   449,
      -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   637,   638,    -1,   640,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   449,   652,   653,
     480,   589,    -1,   483,    -1,    -1,   660,    -1,   244,   663,
      -1,    -1,    -1,    -1,    -1,    -1,   496,   671,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,   480,    -1,
      -1,   483,    -1,    -1,   622,    -1,    -1,    -1,    -1,   449,
     628,   118,    -1,    -1,   496,    -1,    -1,    -1,    -1,   637,
     638,    -1,   640,    -1,    -1,    -1,   536,   134,   135,    -1,
      -1,    -1,    -1,    -1,   652,   653,    -1,   144,   548,    -1,
     480,    -1,   660,   483,    -1,   663,    -1,    55,    56,    57,
      58,    59,    60,   671,   536,    -1,   496,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,
      -1,    -1,    -1,   523,    -1,   449,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   536,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,   548,    -1,
      -1,    -1,   622,    -1,    -1,    -1,   480,    -1,   628,   483,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,   638,    -1,
     640,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,    -1,   652,   653,   152,    -1,   628,    -1,    -1,   589,
     660,    -1,    -1,   663,    -1,   637,   638,    -1,   640,    -1,
      -1,   671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     652,   653,   536,    -1,    -1,    -1,    -1,    -1,   660,    -1,
      -1,   663,    -1,   449,   548,    -1,    -1,    -1,   628,   671,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
     640,    -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,
      -1,    -1,   652,   653,   480,    -1,    -1,   483,    -1,    -1,
     660,    -1,    -1,   663,    -1,   589,    -1,    -1,    -1,    -1,
     496,   671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   628,   372,   373,   374,   375,    -1,
     536,    -1,    -1,    -1,    -1,   338,   640,    -1,    -1,    -1,
      -1,    -1,   548,   390,   347,    -1,    -1,    -1,   652,   653,
      -1,    -1,    -1,    -1,    -1,    -1,   660,    -1,    -1,   663,
      -1,    -1,    -1,    -1,    -1,   412,    -1,   671,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,
      -1,    -1,   385,   589,    -1,   388,    -1,    -1,   435,    -1,
     393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,
      -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   461,    -1,   622,    -1,    -1,    -1,
      -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,   637,   638,    -1,   640,    -1,    -1,    -1,    -1,    -1,
     388,    -1,    -1,    -1,    -1,    -1,   652,   653,    -1,    -1,
      -1,    -1,    -1,   401,   660,    -1,    -1,   663,    -1,    -1,
     463,    -1,    -1,    -1,    -1,   671,   469,    -1,    -1,   516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   508,    -1,   554,    -1,    -1,
      -1,    -1,    -1,    -1,   561,   463,    -1,   564,    -1,    -1,
      -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,   542,
     543,    -1,   589,    -1,    -1,   548,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   558,    -1,    -1,    -1,    -1,
     508,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,   626,
     583,   584,    -1,    -1,   532,   588,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   542,   543,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,    -1,    -1,   583,   584,    -1,    -1,    -1,
     588,    -1,   645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   654,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   656
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    40,   130,   290,   411,   459,   490,   519,
     730,   791,   799,   826,   827,   883,  1057,  1058,  1114,  1115,
    1116,  1118,  1119,  1120,  1125,  1127,  1140,  1141,  1142,  1143,
    1144,  1583,    28,    29,   800,   801,   802,   803,   804,    27,
    1021,  1598,  1021,  1021,    25,  1021,  1488,  1145,   828,  1488,
    1021,   827,     0,  1117,  1120,  1143,    31,   802,   804,   884,
     663,    25,   244,   825,   826,  1008,  1021,  1026,  1125,  1140,
    1146,  1177,  1178,  1179,  1180,  1181,  1185,   409,   830,   831,
     832,   833,   836,   837,   792,   108,   115,   161,   162,   422,
     517,   609,   689,   697,   799,   976,  1056,  1121,  1122,  1124,
    1128,  1129,  1135,  1147,  1298,  1308,  1583,   668,  1021,  1180,
     296,   510,   511,  1186,    20,  1021,  1184,   671,   831,     5,
     829,   409,  1021,     5,   855,   857,   858,   731,   795,  1021,
    1309,  1021,  1299,  1136,  1021,  1021,  1124,  1130,   314,   353,
     372,   373,   412,   424,   435,   451,   461,   476,   516,   539,
     554,   561,   564,   585,   589,   608,   626,   885,   886,   887,
     890,    25,  1177,  1183,    18,    19,    26,    39,   114,   126,
     153,   246,   343,   378,   412,   424,   460,   475,   483,   496,
     540,   565,   589,   633,   642,   726,   727,   740,   742,   943,
     950,   961,   963,  1021,  1177,  1187,  1188,   511,    14,   882,
     833,   574,  1285,   834,   831,   836,    32,    41,   118,   134,
     135,   144,   314,   353,   372,   373,   374,   375,   390,   412,
     424,   435,   451,   461,   476,   516,   539,   554,   561,   564,
     585,   589,   608,   626,   668,   840,   849,   860,   865,  1021,
     793,  1021,   483,  1021,   825,   977,  1148,  1021,   892,   373,
     838,   483,   868,   870,   871,   869,   878,   879,   483,   483,
     891,   511,   483,   831,   866,   478,   483,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   740,   483,   822,
       9,    18,    19,    24,    25,    26,   119,   348,   442,   447,
     449,   465,   480,   483,   486,   495,   536,   548,   559,   589,
     640,   652,   653,   660,   671,   919,   927,   928,   929,   930,
     931,   961,   962,   964,  1027,  1177,  1288,  1481,   483,   483,
     483,   483,   483,   483,    18,    19,    20,    21,    22,   741,
      26,    36,   483,   573,     5,   479,  1187,    25,    26,  1021,
    1027,    19,    25,    26,   835,  1027,   721,   722,   723,   839,
     862,   851,   863,   838,   483,   483,   483,   852,   868,   869,
     483,   483,   850,   511,   861,   483,   866,   831,   859,   825,
     483,    26,   483,  1137,   825,   825,   483,  1021,   483,   510,
     844,    26,   677,   421,   506,   522,   565,   604,   633,   642,
     872,   677,   421,   506,   522,   565,   604,   633,   642,   880,
      26,    26,   893,   894,   895,   896,  1021,    26,   847,   848,
      26,   671,  1177,   718,   969,  1012,  1021,  1012,  1012,   969,
     969,   919,    24,    25,    26,    19,    24,    25,    26,   965,
     966,   967,   968,    25,   970,  1012,  1013,   919,   446,   919,
     919,   919,   919,   578,  1305,   483,   483,   919,   421,   506,
     522,   565,   604,   633,   642,  1484,  1485,   483,   919,   919,
     483,   483,   932,   483,   483,   483,   483,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    49,   146,   147,   148,   149,   150,
     151,   164,   165,   166,   303,   306,   426,   441,   445,   481,
     509,   527,   608,   674,   821,   920,   933,   935,   936,   937,
     938,   939,   940,   941,   473,   953,   951,   957,   955,  1177,
    1177,   740,  1021,   944,  1021,  1188,   511,   479,    26,   842,
     483,   864,   831,   864,   844,    26,    26,    26,   831,    26,
      26,   830,   847,   864,    26,   671,   113,   856,   794,  1310,
     446,  1300,  1599,  1600,  1601,  1602,  1603,   978,  1149,  1131,
     671,    26,   446,   873,   874,   483,   875,   880,   881,   875,
     483,   876,     5,   446,     5,   446,     5,   337,     5,   885,
     479,     5,     5,   446,   831,   867,   446,   483,     5,   446,
     511,   671,   446,   446,   446,   446,   446,   446,   446,    19,
      26,   446,   641,   966,    19,    26,   641,   446,     5,   446,
     446,     5,   823,   919,   523,  1504,   919,   483,   677,    20,
     446,  1504,    20,  1288,   919,   919,   919,   919,   919,   919,
     919,   919,   919,   919,   919,   919,   919,   919,   919,   919,
     919,   919,   919,   919,   919,   919,   919,   483,   919,   919,
     483,  1177,   919,   919,   919,   919,   446,     5,   483,   535,
     772,   773,   774,   919,   483,  1187,   511,   675,    26,   671,
      26,   446,   446,     5,   446,   312,     5,   446,     5,   446,
     337,   479,     5,   446,   867,   796,   797,  1129,  1021,  1193,
    1194,  1196,  1193,   416,  1600,  1285,    42,    43,    44,    51,
      54,    61,    62,   106,   107,   111,   121,   122,   124,   138,
     155,   158,   159,   172,   174,   175,   176,   184,   185,   187,
     188,   189,   195,   198,   200,   201,   202,   208,   210,   211,
     213,   215,   216,   219,   222,   223,   224,   225,   226,   227,
     231,   232,   233,   235,   239,   241,   242,   247,   250,   253,
     255,   257,   259,   263,   264,   266,   267,   268,   271,   273,
     274,   276,   284,   285,   297,   300,   301,   304,   305,   308,
     309,   317,   318,   319,   321,   331,   332,   333,   335,   339,
     340,   344,   352,   360,   361,   362,   368,   369,   376,   379,
     383,   384,   394,   411,   419,   425,   436,   448,   454,   456,
     457,   464,   503,   514,   521,   545,   546,   550,   562,   568,
     569,   570,   571,   575,   579,   586,   587,   597,   599,   610,
     612,   615,   621,   647,   650,   655,   658,   659,   673,   680,
     703,   704,   705,   706,   707,   708,   709,   712,   714,   716,
     733,   734,   735,   736,   753,   777,   798,   799,   805,   824,
     898,   899,   900,   901,   912,   913,   914,   915,   916,   917,
     918,   971,  1002,  1006,  1028,  1030,  1033,  1034,  1035,  1036,
    1049,  1059,  1083,  1084,  1086,  1090,  1105,  1106,  1110,  1111,
    1112,  1113,  1123,  1138,  1154,  1165,  1166,  1167,  1171,  1174,
    1208,  1211,  1213,  1219,  1220,  1223,  1226,  1229,  1231,  1233,
    1236,  1243,  1248,  1253,  1254,  1255,  1267,  1268,  1271,  1277,
    1280,  1281,  1306,  1321,  1322,  1323,  1324,  1325,  1337,  1343,
    1344,  1364,  1367,  1396,  1398,  1489,  1490,  1521,  1522,  1529,
    1544,  1568,  1583,  1584,  1589,  1590,  1592,  1596,  1597,  1604,
     799,  1126,   676,   699,  1150,  1151,  1193,    20,   446,   478,
     845,   872,    26,   877,    26,    26,    26,   894,   896,   888,
     848,    26,  1021,  1012,   740,    20,   718,  1021,   872,   959,
     959,    26,   446,   641,   959,    24,    26,    26,   641,    24,
      26,   869,   960,  1013,   870,   446,   414,   528,   637,  1512,
     446,   446,    26,  1485,   446,   446,   446,   446,   446,   446,
     446,   494,   494,   494,   942,  1504,   494,   942,  1504,   954,
     952,   958,   956,    26,   948,   945,     5,   946,   479,  1187,
     855,   446,    20,   845,    26,   483,    26,    26,   841,    26,
     729,   797,   671,   446,     5,   446,  1177,  1177,  1177,  1021,
      25,  1177,  1230,  1021,    25,  1021,  1474,   405,  1022,  1023,
    1598,  1022,    25,  1021,  1473,  1021,  1021,  1251,  1016,  1022,
    1016,  1021,  1594,  1474,  1021,    26,   737,  1177,  1328,  1016,
    1251,   942,    26,  1027,  1293,  1294,  1293,   919,   926,  1366,
    1473,  1473,   921,   942,  1022,  1530,  1530,   902,  1251,  1016,
    1326,  1177,  1018,  1022,   926,  1530,  1177,  1251,  1177,  1365,
    1530,    25,   637,  1168,  1169,  1177,  1016,  1016,  1168,  1017,
    1022,  1021,  1169,  1016,  1530,  1016,  1018,  1474,  1177,  1206,
    1207,  1014,  1022,  1018,   430,   613,  1012,  1085,  1021,   806,
    1473,  1019,  1022,    25,   244,  1021,  1397,  1572,  1574,  1575,
    1576,  1577,  1579,   942,  1206,   677,   942,  1022,  1232,   972,
      64,    65,    66,    67,   186,   194,   203,   206,   249,   256,
     313,   338,   345,   347,   357,   385,   393,   430,   454,   491,
     502,   600,   601,   602,   613,   716,  1099,  1227,  1228,  1177,
    1198,  1199,   925,   926,  1242,   969,   969,  1015,  1022,   942,
    1230,  1307,  1177,  1284,    25,   483,  1177,  1279,  1524,  1278,
     926,  1585,   160,   209,   246,   343,   420,   460,   526,   754,
     950,  1021,  1177,  1316,   779,   926,  1014,   641,  1021,  1029,
    1155,   926,  1014,    26,  1177,  1107,  1014,   926,  1545,   926,
    1293,  1021,  1031,  1032,  1018,  1031,   969,  1018,  1031,   969,
    1037,  1031,    25,    26,   439,   539,  1027,  1088,  1177,  1195,
    1197,   120,   328,   400,   444,   620,   700,   701,   702,   711,
     744,  1039,  1041,  1043,  1045,  1047,  1172,  1173,  1176,   391,
     402,   452,   466,   555,  1399,   691,   692,   980,   981,   982,
    1021,  1152,   698,  1151,   446,   356,   446,   446,   446,   446,
     675,     5,   446,   446,   479,   483,   677,    19,    26,   446,
     959,    26,   446,   446,   641,    26,   641,   677,    18,    19,
      20,    25,    26,    37,    38,   119,   449,   480,   483,   496,
     536,   548,   589,   622,   628,   637,   638,   640,   652,   653,
     660,   663,  1021,  1027,  1480,  1482,  1511,  1513,  1514,  1516,
    1517,  1518,  1540,  1541,  1542,  1543,  1573,  1574,  1578,  1305,
     446,  1305,  1305,  1305,  1305,  1305,  1305,    25,    25,    25,
     919,   934,   446,    25,   934,   446,   446,   446,   446,   446,
     446,   772,   446,   774,   772,   479,   356,   446,   831,   853,
     854,   446,   446,   675,   446,  1021,  1311,  1196,  1301,   109,
     110,   139,   140,   141,   507,   593,   636,  1345,  1346,  1347,
    1350,  1353,  1356,  1357,  1358,  1361,   671,   641,   663,   156,
     157,   483,   671,   641,   663,     8,   676,   479,  1473,   531,
    1252,  1195,   164,   165,   166,   647,   535,   922,   923,   926,
    1177,  1202,  1473,   743,   744,   905,   320,    48,   142,   143,
     677,  1249,   512,     5,   670,   677,   669,   669,  1209,   647,
     473,     5,   608,  1060,   512,   710,  1587,   710,   439,   808,
    1177,   598,   669,  1214,  1215,  1216,   671,    25,  1575,   511,
    1580,   382,  1395,   663,   671,   924,   926,   608,  1572,   924,
       8,   605,  1015,    26,   553,   606,   720,  1007,  1177,  1007,
    1007,  1007,    25,   231,   358,   364,   365,   366,   386,   491,
     494,   502,   537,   572,   591,   592,   602,   607,   646,   678,
    1103,  1104,  1007,  1007,   648,  1100,   744,  1100,  1100,  1008,
    1008,  1100,  1100,   744,     5,   473,     5,   389,   440,     5,
     743,   136,   137,   591,   678,  1091,   713,  1588,   925,   664,
     665,   666,   667,  1283,  1524,  1285,   926,  1273,  1274,  1275,
    1286,  1287,   926,   483,   483,   483,   483,    25,   775,  1021,
     483,  1524,   400,   483,   573,    36,   641,   630,   780,   787,
     778,  1021,    25,  1170,  1177,  1269,     8,  1272,    14,  1021,
    1182,  1189,  1190,  1192,  1200,  1201,  1244,   217,   400,   596,
     629,    33,   244,   605,  1546,  1547,  1548,  1550,   627,     5,
     710,   710,   924,  1195,  1202,  1087,   473,     5,   205,  1065,
     483,  1177,   924,   483,    26,    26,   120,  1175,    25,  1177,
    1528,  1528,  1022,  1379,  1232,  1015,   173,   275,   283,   289,
     291,   302,   330,   346,   351,   363,   370,   518,   523,   530,
     552,   557,  1368,  1369,  1377,  1386,  1387,  1393,  1394,  1400,
    1401,  1411,  1431,  1435,  1500,  1501,  1531,  1532,  1535,  1536,
    1552,   983,   984,   145,   979,   990,   991,   982,  1153,  1599,
    1132,   511,   885,   848,   671,  1021,   872,    26,   446,   641,
     959,   446,   641,   959,   959,    24,    26,   641,    24,    26,
     873,  1517,  1517,   421,   506,   522,   565,   604,   633,   642,
    1483,  1486,   523,  1516,   483,   483,   483,   483,  1511,  1511,
    1511,   483,   483,   483,   483,  1021,   483,     5,   598,  1440,
    1445,   668,  1021,    18,    19,    20,    21,   146,   147,   148,
     149,   150,   151,  1538,  1486,  1486,   473,     5,   446,   446,
     949,   947,   511,     5,   446,   855,   825,   825,   299,   312,
     414,   483,   528,   544,  1415,  1416,  1421,  1423,   483,  1021,
    1362,  1363,    26,   483,  1021,  1342,  1355,  1423,  1425,   483,
    1021,  1352,   483,  1342,  1348,     5,  1021,    25,  1021,  1021,
      25,  1024,  1180,  1021,    25,  1021,  1021,  1021,  1595,  1473,
     647,   483,   483,   905,  1473,     5,   677,   483,  1572,    25,
    1026,  1250,  1249,  1250,  1524,  1168,   926,   926,   926,  1009,
    1010,   483,  1177,  1207,  1061,  1062,  1063,  1473,   677,  1524,
     969,  1588,  1085,  1177,   807,   676,   926,   406,  1218,   608,
    1217,  1576,   740,  1581,  1582,  1021,    20,  1577,     5,  1569,
     668,  1224,   123,   125,   127,   669,   677,   897,  1195,  1198,
     973,    18,    19,   483,  1101,  1103,  1228,  1177,  1199,  1008,
     926,   400,   647,    26,  1177,    26,  1177,   743,   207,  1282,
     446,   438,  1320,  1285,  1275,     5,   669,  1276,  1586,  1021,
      25,   969,   969,   641,  1013,   674,  1177,   760,  1021,  1021,
    1021,   926,   395,   783,   787,   630,   781,   789,    23,   288,
    1157,  1161,   534,   942,   534,  1270,   926,   510,  1186,   671,
       5,  1108,   598,  1245,  1177,  1549,  1551,   243,  1547,  1050,
    1032,   969,   969,  1042,  1043,  1065,  1065,    45,    46,    47,
      50,    52,    53,   324,   327,   329,   349,   359,   380,   403,
     407,   482,  1064,  1066,  1067,  1095,  1177,  1197,   598,   745,
      26,   453,  1048,   377,  1523,  1523,   192,   193,   489,   598,
    1021,  1432,  1433,  1475,  1473,  1473,  1473,  1370,  1473,  1473,
    1021,  1533,   221,   434,   448,   491,   502,   523,   530,   538,
     560,   637,   643,  1402,  1404,  1405,  1406,  1512,  1473,  1378,
    1402,  1404,  1599,  1599,   439,   992,  1177,   693,   694,   985,
     986,   987,   533,   676,   695,   696,   715,   995,   996,  1599,
     825,    26,   846,    20,  1021,   446,    26,   446,   959,    26,
     959,    24,    26,   446,   446,    24,    26,   677,  1512,   446,
     449,  1516,  1539,  1578,   414,   528,   637,  1464,  1516,  1519,
    1464,  1464,  1464,  1464,   671,  1519,  1514,   567,  1441,  1442,
    1443,  1473,   578,  1439,  1446,   387,   566,   577,  1388,  1507,
    1021,  1516,  1516,  1516,  1516,   677,   483,   677,  1573,   919,
     446,   446,   846,   854,  1312,  1302,   483,   483,   483,  1359,
    1423,   483,   483,   112,  1360,  1362,     5,  1354,  1355,   118,
     353,   373,   374,   375,   412,   424,   435,   451,   461,   476,
     524,   554,   564,   585,   589,   617,   626,  1465,  1466,  1467,
    1469,  1351,  1352,  1348,  1349,   715,  1346,   671,   641,   446,
     671,   641,   598,  1593,   483,   738,   739,  1021,  1329,   942,
     922,  1021,  1327,   668,  1221,  1249,  1249,   677,     5,     5,
       5,   631,   926,     5,   671,   535,   677,   676,   218,   220,
     324,   327,   809,   812,   813,  1095,   810,   811,  1021,   483,
    1022,   700,   701,  1222,     5,   479,   926,  1473,  1570,  1571,
    1572,   628,   668,  1225,  1021,  1021,  1010,  1011,   561,   969,
     905,     8,     8,   975,    26,    26,  1102,  1103,  1177,   373,
    1237,   120,   919,  1285,   272,  1287,  1293,  1599,     5,     5,
     446,   446,   776,  1021,   446,  1524,   772,   483,   483,   483,
     788,   784,   415,   782,   926,   395,   785,   789,   648,  1097,
    1162,  1158,   417,  1156,  1157,   924,   677,  1183,    20,  1021,
    1191,  1201,    14,   535,  1246,  1247,  1516,  1578,  1198,  1599,
    1044,  1045,   602,  1020,   598,  1078,  1077,  1076,  1075,  1080,
    1079,  1012,  1081,  1012,  1082,  1074,  1073,  1071,  1070,  1096,
     380,  1067,  1072,   969,    55,    56,    57,    58,    59,    60,
     152,   388,   401,   463,   469,   508,   532,   542,   543,   548,
     558,   580,   583,   584,   588,   645,   656,   746,   747,  1093,
    1094,     5,    26,  1524,   302,  1177,   523,  1505,  1506,  1524,
    1232,  1499,  1501,   154,   154,   647,  1230,  1434,  1435,   483,
    1412,   204,  1446,  1473,   228,   325,  1537,   671,   677,   483,
    1407,  1407,   598,   676,     5,  1502,  1553,   397,   406,   430,
     433,   449,   553,   606,   613,  1015,  1380,  1385,   677,   676,
     994,  1177,     5,   598,   988,   989,   690,   987,   993,  1021,
     993,   997,   998,   993,   380,   996,  1133,   479,   446,   641,
     959,   446,   641,   446,   446,   959,   959,   421,   506,   522,
     565,   604,   633,   642,  1487,  1513,     5,  1486,     5,   446,
       5,  1516,     5,   446,  1516,  1516,  1516,  1516,  1021,   446,
     483,  1443,     5,   668,  1021,  1479,     9,   348,   483,   495,
    1449,  1450,  1451,  1452,  1453,  1457,  1461,  1463,  1516,   423,
    1437,  1447,  1021,  1508,   670,  1464,   387,  1487,    26,  1487,
     479,   513,  1295,  1315,   513,  1256,  1289,   663,  1021,  1418,
    1420,  1473,  1477,  1478,  1422,  1477,  1422,     5,   446,  1360,
    1422,  1449,  1021,   446,  1363,     5,   446,   483,   483,   483,
    1486,  1486,   483,   483,   483,   483,   483,   260,   261,   262,
     453,  1424,  1426,     5,   446,     5,   446,  1021,  1021,    25,
    1021,  1021,    25,  1021,   926,  1021,  1339,  1340,     5,  1341,
    1342,   942,  1139,   671,  1341,   628,  1524,  1524,   926,   926,
    1009,   561,   926,  1591,     5,  1062,    20,  1477,  1524,   810,
     818,   817,   819,  1021,  1025,   820,  1025,   245,   813,   816,
       5,  1065,   671,   926,     8,  1582,   511,   671,     5,  1524,
     628,  1021,  1195,   942,   605,  1383,     5,   446,  1177,     5,
      26,  1177,   381,    25,  1317,   400,   400,   511,   671,   400,
     483,   761,   765,   758,   756,  1599,  1599,   790,   786,   782,
    1098,    25,  1020,  1163,  1177,  1599,   926,   478,   511,   942,
       5,  1051,  1046,  1047,    26,   743,  1021,  1599,  1599,  1599,
    1599,  1599,  1599,     5,  1068,     5,  1069,  1599,  1599,  1599,
    1599,  1101,  1599,  1020,    25,    14,    14,     5,   446,    26,
    1473,  1512,  1493,   647,   647,  1369,  1498,  1499,  1435,  1413,
    1477,   668,  1015,   483,  1373,  1021,  1534,  1533,  1408,  1477,
     515,  1409,  1410,  1475,  1473,  1406,  1513,   100,   101,   102,
     103,   104,   635,  1556,   926,   926,   605,  1381,  1015,  1409,
    1473,     5,  1177,   993,  1599,  1599,     5,  1000,  1001,  1599,
    1599,   999,  1126,   889,   959,    26,   959,    24,    26,   959,
     959,   483,  1445,  1486,   677,  1486,  1486,   446,  1516,   446,
     446,   446,   446,  1442,  1444,  1442,  1479,  1452,  1511,  1449,
    1516,  1511,     6,     7,     9,    12,    13,    14,    15,    16,
      17,   426,   427,   481,   608,   674,   724,   725,  1460,  1462,
    1438,  1515,  1516,   500,  1436,  1448,   322,  1338,    26,  1389,
    1390,  1391,  1477,  1505,  1508,   446,   843,   128,   129,   131,
     132,   133,   230,   238,   272,   281,   310,   311,   355,   399,
     453,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,  1292,  1296,   191,   566,  1297,  1313,   214,   229,   230,
     238,   272,   281,   310,   355,   399,  1290,  1291,  1303,  1297,
    1478,   511,  1476,   446,     5,   671,     5,   446,   446,  1423,
     446,   446,  1355,    26,  1470,  1470,    26,   677,   483,   677,
      26,  1471,    26,    26,  1471,  1471,    25,  1480,   212,   312,
     350,   414,   428,   528,   544,  1417,  1427,  1428,  1429,  1430,
    1352,  1348,   671,   671,   590,   639,     5,   446,   739,     5,
     446,   924,   446,    20,   446,  1524,     5,   926,   618,   328,
     748,   749,   926,  1065,  1599,  1599,     5,   814,   511,   671,
       5,   815,  1599,   811,   598,    20,  1021,     5,  1021,  1212,
    1581,    20,  1477,  1571,     8,  1524,   444,   710,   924,  1384,
     974,  1103,   719,  1235,   919,     5,   772,  1177,   755,   737,
    1021,  1177,   763,   446,   772,   772,   772,  1599,  1599,  1101,
    1160,    25,  1164,  1177,   623,  1005,  1187,   535,   925,  1109,
    1247,   117,   594,  1052,  1038,  1039,   671,  1012,  1599,  1012,
    1599,   743,    26,  1177,    26,  1177,   747,   446,   483,  1525,
    1513,  1499,  1499,  1491,     5,   446,   523,  1510,  1374,  1477,
     531,  1371,  1510,   677,     5,   446,     5,   598,  1503,    18,
      19,   119,   480,   483,   496,   535,   536,   548,   589,   628,
     640,   652,   653,   660,   663,  1021,  1480,  1511,  1540,  1542,
    1561,  1562,  1563,  1564,  1565,  1566,  1578,  1561,  1561,  1561,
    1477,  1558,  1560,  1557,  1558,  1559,  1554,  1382,   677,  1177,
    1021,  1599,  1599,  1599,  1599,   675,   446,   641,   446,   446,
      26,   446,   677,  1487,   677,   677,     5,   446,   446,  1450,
    1451,  1455,  1517,  1455,   483,  1511,  1455,   483,  1511,  1455,
      10,   303,   441,   443,  1516,     5,  1449,     5,   590,   639,
    1392,  1338,   677,   675,  1293,  1293,  1293,    25,  1293,  1293,
    1293,  1293,  1293,  1293,    25,    25,  1293,  1296,  1177,  1203,
    1204,   670,   499,  1257,    25,    25,    26,    26,    26,    26,
      26,    25,  1177,  1291,  1257,    26,  1417,  1477,    20,  1021,
    1477,  1360,   446,   446,     5,   446,  1487,    26,  1487,     5,
    1468,     5,   446,   446,   446,  1468,  1419,  1473,   483,  1429,
    1360,  1021,  1021,  1340,   674,   728,  1334,  1335,  1336,  1342,
      63,   140,   141,   298,   674,  1330,  1331,  1332,   520,   904,
    1330,     5,   429,  1524,     5,   483,   446,   602,  1092,  1025,
    1599,   740,    20,  1021,  1025,  1599,   969,   926,   479,  1524,
       8,   969,  1198,  1599,    26,  1020,    25,  1318,  1195,   479,
     772,   762,   766,   446,   446,  1599,  1020,   926,  1003,   479,
    1054,  1053,   493,  1040,  1041,    20,  1021,  1526,  1527,   605,
    1509,  1494,  1492,  1477,  1512,   196,  1414,     5,   446,  1372,
    1534,  1477,  1410,  1409,  1509,  1564,  1564,  1563,   483,   483,
     483,   483,   483,   483,   483,  1021,   483,     5,   446,    18,
      19,    20,    21,  1538,   446,     5,   446,     5,    14,   204,
     578,  1555,  1198,  1409,   265,  1134,   885,   959,    24,    26,
     959,   959,   446,  1487,  1487,  1487,  1442,   494,  1454,  1454,
    1458,  1459,  1480,  1578,  1454,  1458,  1454,  1455,  1516,  1515,
    1390,  1487,   855,   590,   639,  1205,     5,  1203,   116,   190,
     252,   254,   270,   278,   282,   307,  1258,  1259,  1314,  1304,
       5,   479,  1476,    26,   446,    26,  1472,   446,    26,   446,
     483,  1449,  1333,  1598,    26,  1336,    26,    26,  1333,  1338,
    1332,  1012,   743,   429,  1524,   926,   750,   620,  1210,    26,
     743,   479,  1092,   446,  1524,   294,   743,   446,   446,   483,
     764,   400,   770,   446,   759,   757,  1159,  1599,   511,   926,
    1599,  1020,     5,   446,  1198,  1445,  1513,  1477,   483,  1445,
     446,  1539,  1464,  1563,  1567,  1464,  1464,  1464,  1464,   511,
     671,  1567,  1562,  1563,  1563,  1563,  1563,  1558,    14,  1559,
    1562,  1015,  1449,   197,   668,  1403,   446,   446,  1456,  1480,
    1520,     5,   446,   446,  1454,     7,  1204,  1260,  1261,  1177,
    1263,  1177,  1262,  1264,  1259,   293,   293,    26,   446,   677,
     446,  1420,   446,   903,  1524,   447,   256,   313,   338,   347,
     385,   393,   484,   654,   747,   751,   752,   483,   671,   743,
    1234,  1319,   767,   446,  1195,   770,   770,   770,  1599,  1004,
    1187,   627,  1089,  1527,  1507,  1445,   535,  1375,  1376,  1516,
    1507,   446,  1563,     5,   446,  1563,  1563,  1563,  1563,    26,
    1021,   446,   483,  1021,   959,   959,  1459,  1516,  1599,  1599,
    1265,  1599,  1266,  1599,  1599,   479,  1487,   446,   292,   403,
     407,   906,   907,   908,  1095,  1007,  1007,  1007,  1007,  1007,
    1007,    25,     5,   446,   926,    20,  1021,  1095,  1238,  1239,
    1240,   770,   772,   770,   295,   479,  1055,   743,     5,   446,
     341,   342,  1495,   446,  1563,   446,   446,   446,   446,     5,
     479,   511,  1561,  1599,  1599,   910,   909,   292,   908,   911,
     752,     5,  1241,   336,  1240,   768,  1599,  1376,    25,  1021,
    1496,  1497,    26,    26,   446,  1599,  1599,  1599,   926,  1599,
     446,  1052,   671,   671,     5,   479,     5,   479,   446,   769,
    1021,  1021,  1497,    26,   217,   400,   771,   671,   479,  1195,
    1021
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
#line 1008 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1011 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1015 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1021 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1026 "fgl.yacc"
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
#line 1038 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1043 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	//sprintf($<str>$, "A4GL_unregister_func(\"%s\",%s%s);\n", $<str>1, (char *)get_namespace($<str>1), $<str>1);
	sprintf(yyval.str, "A4GL_unregister_func(\"%s\");\n", yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1062 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1063 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1064 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1065 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1066 "fgl.yacc"
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
#line 1077 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1083 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1084 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1085 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1086 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1087 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1092 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1093 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1104 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1107 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1110 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1110 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1117 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1118 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1136 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1137 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1138 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1139 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1140 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1147 "fgl.yacc"
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
#line 1158 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1162 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1163 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1167 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1173 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1175 "fgl.yacc"
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
#line 1186 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1188 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1190 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1192 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1196 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1198 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1259 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1263 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1267 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1274 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1277 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1281 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1285 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1294 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1300 "fgl.yacc"
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
#line 1309 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1314 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1320 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
 A4GL_debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 76:
#line 1329 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 77:
#line 1336 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 78:
#line 1341 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 79:
#line 1345 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 80:
#line 1353 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 81:
#line 1357 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1361 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1363 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 84:
#line 1369 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 85:
#line 1374 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 86:
#line 1377 "fgl.yacc"
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

  case 87:
#line 1393 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 88:
#line 1400 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 89:
#line 1404 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 90:
#line 1408 "fgl.yacc"
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

  case 91:
#line 1430 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 92:
#line 1430 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 93:
#line 1434 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 94:
#line 1435 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 95:
#line 1436 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 96:
#line 1441 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 97:
#line 1444 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 98:
#line 1450 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 99:
#line 1453 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 101:
#line 1462 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 103:
#line 1466 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 104:
#line 1472 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 105:
#line 1475 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 106:
#line 1490 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 107:
#line 1500 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1506 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 109:
#line 1515 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 114:
#line 1528 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 116:
#line 1531 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 117:
#line 1533 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 119:
#line 1539 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 120:
#line 1541 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 121:
#line 1546 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 122:
#line 1551 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 123:
#line 1557 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 124:
#line 1561 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 125:
#line 1570 "fgl.yacc"
    { 
		char buff[256];
		if (class_cnt!=0) {
			a4gl_yyerror("Only a single class can be defined in any single module");
			}

		set_4gl_vars();
                set_current_variable_scope('g'); print_variables (); set_current_variable_scope('G'); print_variables (); set_current_variable_scope('m'); print_variables ();
print_module_variable_init();
                set_current_variable_scope('m');


		printf("CLASS NAME : %s FILENAME %s\n",yyvsp[0].str,infilename);
		CLASS_set_class_name(yyvsp[0].str);

		set_current_variable_scope('C'); 

		printf("Pushing THIS as a new record\n");
		class_cnt++;
		variable_action (-1, "THIS", "", "", "a4gl_add_variable");
		push_record();in_record++;
		sprintf(buff,"\"%s\"",yyvsp[0].str);
		variable_action (-1, "_class_name", buff, "c", "add_constant");
		}
    break;

  case 126:
#line 1594 "fgl.yacc"
    { 
		char buff[256];
		printf("Calling read_class (%s)\n",yyvsp[0].str);  
		sprintf(buff,"\"%s\"",yyvsp[0].str);
		if (strcmp(yyval.str,"default_object")!=0) {
			variable_action (-1, "_parent_name", buff, "c", "add_constant");
		}
	}
    break;

  case 127:
#line 1602 "fgl.yacc"
    { 
		pop_record();in_record--;
		read_class(yyvsp[-2].str); 
		print_variables(); 
		class_set_parent();
		}
    break;

  case 128:
#line 1608 "fgl.yacc"
    {
		class_cnt++; 
		CLASS_print_reflector();
		dump_class();
		}
    break;

  case 129:
#line 1618 "fgl.yacc"
    {
	static char buff[256];
		strcpy(buff,"default_object");
		CLASS_set_parent_name(buff);
		strcpy(yyval.str,buff);
	}
    break;

  case 130:
#line 1623 "fgl.yacc"
    {
		CLASS_set_parent_name(yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 134:
#line 1646 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 135:
#line 1649 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 136:
#line 1652 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 137:
#line 1655 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 138:
#line 1658 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 139:
#line 1661 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 145:
#line 1683 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 148:
#line 1692 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 149:
#line 1711 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 150:
#line 1716 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 151:
#line 1719 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 152:
#line 1728 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 153:
#line 1734 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 158:
#line 1749 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 159:
#line 1753 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 160:
#line 1758 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 163:
#line 1768 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 164:
#line 1768 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 165:
#line 1769 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 166:
#line 1769 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 167:
#line 1770 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 168:
#line 1770 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 169:
#line 1771 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 170:
#line 1771 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 171:
#line 1772 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 172:
#line 1772 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 173:
#line 1780 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 174:
#line 1784 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 175:
#line 1790 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 176:
#line 1794 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 177:
#line 1809 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 178:
#line 1812 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 179:
#line 1815 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 180:
#line 1818 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 181:
#line 1821 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 182:
#line 1824 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 183:
#line 1833 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 184:
#line 1841 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 185:
#line 1846 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 186:
#line 1859 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 187:
#line 1863 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 188:
#line 1878 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 189:
#line 1879 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 192:
#line 1887 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 193:
#line 1887 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 198:
#line 1896 "fgl.yacc"
    {in_define=1;}
    break;

  case 199:
#line 1896 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 200:
#line 1905 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 201:
#line 1906 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 202:
#line 1907 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 203:
#line 1910 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 205:
#line 1915 "fgl.yacc"
    { }
    break;

  case 206:
#line 1915 "fgl.yacc"
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

  case 210:
#line 1932 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 211:
#line 1936 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 216:
#line 1951 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 217:
#line 1952 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 218:
#line 1953 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 219:
#line 1954 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 220:
#line 1959 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 222:
#line 1965 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 224:
#line 1974 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 225:
#line 1978 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 231:
#line 1994 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 232:
#line 1996 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 233:
#line 1997 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 235:
#line 2004 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 236:
#line 2004 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 237:
#line 2005 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 238:
#line 2006 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 239:
#line 2009 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 240:
#line 2011 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 242:
#line 2021 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 247:
#line 2036 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 248:
#line 2036 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 252:
#line 2042 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 253:
#line 2043 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 254:
#line 2044 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 255:
#line 2045 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 256:
#line 2046 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 257:
#line 2047 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 258:
#line 2048 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 259:
#line 2049 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 260:
#line 2050 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 261:
#line 2051 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 262:
#line 2054 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 263:
#line 2055 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 264:
#line 2056 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 265:
#line 2057 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 266:
#line 2061 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 267:
#line 2066 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 268:
#line 2071 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 269:
#line 2075 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 270:
#line 2078 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 271:
#line 2082 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 273:
#line 2083 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 275:
#line 2084 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 277:
#line 2085 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 278:
#line 2086 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 279:
#line 2087 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 280:
#line 2088 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 281:
#line 2089 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 282:
#line 2090 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 283:
#line 2093 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 284:
#line 2094 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 285:
#line 2095 "fgl.yacc"
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

  case 288:
#line 2130 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 289:
#line 2134 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 290:
#line 2136 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 291:
#line 2138 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 292:
#line 2140 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 293:
#line 2145 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 294:
#line 2149 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 295:
#line 2149 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 296:
#line 2153 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 297:
#line 2154 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 298:
#line 2155 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 299:
#line 2156 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 300:
#line 2157 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 301:
#line 2158 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 302:
#line 2160 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 303:
#line 2165 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 304:
#line 2165 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 305:
#line 2168 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 306:
#line 2170 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 307:
#line 2176 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 308:
#line 2178 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 309:
#line 2184 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 310:
#line 2192 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 311:
#line 2192 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 312:
#line 2195 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 313:
#line 2196 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 314:
#line 2197 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 315:
#line 2198 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 316:
#line 2199 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 317:
#line 2200 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 318:
#line 2202 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 322:
#line 2223 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 326:
#line 2232 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 327:
#line 2234 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 328:
#line 2235 "fgl.yacc"
    { dim_push_type("varchar",yyvsp[-1].str,0); }
    break;

  case 329:
#line 2236 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 330:
#line 2240 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 331:
#line 2241 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 332:
#line 2242 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 333:
#line 2243 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 334:
#line 2248 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 335:
#line 2255 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 336:
#line 2260 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 337:
#line 2262 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 338:
#line 2264 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 339:
#line 2265 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 340:
#line 2266 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 341:
#line 2267 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 342:
#line 2268 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 343:
#line 2269 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 344:
#line 2270 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 345:
#line 2273 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 346:
#line 2275 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 347:
#line 2281 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 348:
#line 2289 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 350:
#line 2297 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 351:
#line 2301 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 352:
#line 2309 "fgl.yacc"
    {dim_push_record();}
    break;

  case 353:
#line 2310 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 354:
#line 2311 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 355:
#line 2312 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 361:
#line 2331 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 362:
#line 2343 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 363:
#line 2347 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 364:
#line 2350 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 365:
#line 2353 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 366:
#line 2354 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 367:
#line 2355 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 368:
#line 2356 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 369:
#line 2357 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 370:
#line 2363 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 371:
#line 2370 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 372:
#line 2375 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 373:
#line 2380 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 374:
#line 2385 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 375:
#line 2389 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 376:
#line 2398 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 377:
#line 2400 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 378:
#line 2405 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 384:
#line 2417 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 385:
#line 2421 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 386:
#line 2424 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 387:
#line 2428 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 388:
#line 2431 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 389:
#line 2435 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 390:
#line 2442 "fgl.yacc"
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

  case 391:
#line 2460 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 392:
#line 2466 "fgl.yacc"
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

  case 393:
#line 2490 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 394:
#line 2493 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 395:
#line 2508 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 396:
#line 2511 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 397:
#line 2525 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 398:
#line 2527 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 399:
#line 2529 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 400:
#line 2531 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 401:
#line 2533 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 402:
#line 2535 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 403:
#line 2536 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 404:
#line 2543 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 405:
#line 2545 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 406:
#line 2549 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 407:
#line 2551 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 408:
#line 2553 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 409:
#line 2555 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 410:
#line 2557 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 411:
#line 2559 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 412:
#line 2561 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 413:
#line 2567 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 417:
#line 2586 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 420:
#line 2592 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 421:
#line 2596 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 422:
#line 2601 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 426:
#line 2611 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 427:
#line 2612 "fgl.yacc"
    {inc_counter();}
    break;

  case 433:
#line 2618 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 434:
#line 2625 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 435:
#line 2625 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 437:
#line 2630 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 438:
#line 2634 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 439:
#line 2640 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 440:
#line 2648 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 441:
#line 2654 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 442:
#line 2663 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 443:
#line 2665 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 444:
#line 2672 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 445:
#line 2693 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 446:
#line 2698 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 447:
#line 2703 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 448:
#line 2707 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 449:
#line 2709 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 450:
#line 2712 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 451:
#line 2730 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 452:
#line 2736 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 453:
#line 2742 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 456:
#line 2752 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 457:
#line 2758 "fgl.yacc"
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

  case 458:
#line 2830 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
	
}
    break;

  case 459:
#line 2841 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 460:
#line 2849 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 461:
#line 2857 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 462:
#line 2857 "fgl.yacc"
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

  case 463:
#line 2873 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 464:
#line 2877 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 465:
#line 2883 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 466:
#line 2886 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 467:
#line 2894 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 468:
#line 2898 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 469:
#line 2901 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 470:
#line 2907 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 471:
#line 2917 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 472:
#line 2922 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 473:
#line 2929 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 474:
#line 2932 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 475:
#line 2935 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 476:
#line 2940 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 477:
#line 2947 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 478:
#line 2952 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 479:
#line 2957 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 480:
#line 2962 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 481:
#line 2973 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 482:
#line 2981 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 483:
#line 2989 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 484:
#line 2994 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 485:
#line 2998 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 486:
#line 3003 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 487:
#line 3007 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 488:
#line 3011 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 489:
#line 3017 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 490:
#line 3020 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 491:
#line 3024 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 492:
#line 3028 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 493:
#line 3032 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 494:
#line 3036 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 495:
#line 3040 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 496:
#line 3047 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 497:
#line 3057 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 498:
#line 3062 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 499:
#line 3068 "fgl.yacc"
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

  case 500:
#line 3078 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 501:
#line 3083 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 502:
#line 3086 "fgl.yacc"
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

  case 503:
#line 3097 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 504:
#line 3102 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 505:
#line 3105 "fgl.yacc"
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

  case 506:
#line 3123 "fgl.yacc"
    {chk4var=1;}
    break;

  case 507:
#line 3123 "fgl.yacc"
    {chk4var=0;}
    break;

  case 508:
#line 3123 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 509:
#line 3126 "fgl.yacc"
    {chk4var=1;}
    break;

  case 510:
#line 3126 "fgl.yacc"
    {chk4var=0;}
    break;

  case 511:
#line 3126 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 512:
#line 3130 "fgl.yacc"
    {chk4var=1;}
    break;

  case 513:
#line 3130 "fgl.yacc"
    {chk4var=0;}
    break;

  case 514:
#line 3130 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 515:
#line 3134 "fgl.yacc"
    {chk4var=1;}
    break;

  case 516:
#line 3134 "fgl.yacc"
    {chk4var=0;}
    break;

  case 517:
#line 3134 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 518:
#line 3138 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 519:
#line 3144 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 520:
#line 3150 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3156 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3164 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3170 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3178 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3184 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 526:
#line 3193 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 527:
#line 3199 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 528:
#line 3206 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 529:
#line 3213 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 530:
#line 3222 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 531:
#line 3228 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 532:
#line 3234 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 533:
#line 3241 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 534:
#line 3247 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 535:
#line 3253 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 536:
#line 3259 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 537:
#line 3267 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 538:
#line 3273 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 539:
#line 3279 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 540:
#line 3288 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 541:
#line 3294 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 542:
#line 3300 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 543:
#line 3310 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 544:
#line 3311 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 547:
#line 3319 "fgl.yacc"
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

  case 548:
#line 3330 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 549:
#line 3331 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 550:
#line 3337 "fgl.yacc"
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

  case 551:
#line 3348 "fgl.yacc"
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

  case 552:
#line 3358 "fgl.yacc"
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

  case 555:
#line 3371 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 556:
#line 3376 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 557:
#line 3383 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 558:
#line 3387 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 559:
#line 3390 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 560:
#line 3393 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 561:
#line 3399 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 562:
#line 3402 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 563:
#line 3405 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 564:
#line 3422 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 565:
#line 3425 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 566:
#line 3431 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 567:
#line 3432 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 568:
#line 3433 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 570:
#line 3438 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 571:
#line 3439 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 572:
#line 3440 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 573:
#line 3441 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 574:
#line 3443 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 575:
#line 3444 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 576:
#line 3445 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 577:
#line 3447 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 578:
#line 3448 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 580:
#line 3454 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 581:
#line 3458 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 582:
#line 3462 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 583:
#line 3467 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 584:
#line 3471 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 585:
#line 3486 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 586:
#line 3490 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 587:
#line 3496 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 588:
#line 3500 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 589:
#line 3509 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 590:
#line 3510 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 591:
#line 3522 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 592:
#line 3528 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 593:
#line 3536 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 600:
#line 3553 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 601:
#line 3555 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 602:
#line 3558 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 603:
#line 3560 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 608:
#line 3574 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 609:
#line 3576 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 610:
#line 3579 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 611:
#line 3581 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 624:
#line 3612 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 625:
#line 3614 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 626:
#line 3617 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 627:
#line 3619 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 628:
#line 3622 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 629:
#line 3624 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 630:
#line 3627 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 631:
#line 3629 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 632:
#line 3632 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 633:
#line 3634 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 634:
#line 3648 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 635:
#line 3652 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 636:
#line 3653 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 637:
#line 3660 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 639:
#line 3678 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 640:
#line 3694 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 641:
#line 3695 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 642:
#line 3696 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 643:
#line 3697 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 644:
#line 3698 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 645:
#line 3699 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 646:
#line 3700 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 650:
#line 3708 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 652:
#line 3714 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 653:
#line 3717 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 654:
#line 3722 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 655:
#line 3727 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 656:
#line 3730 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 657:
#line 3735 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 658:
#line 3740 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 659:
#line 3745 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 660:
#line 3752 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 661:
#line 3753 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 662:
#line 3760 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 663:
#line 3767 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 664:
#line 3769 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 665:
#line 3775 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 666:
#line 3780 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 667:
#line 3785 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 668:
#line 3790 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 669:
#line 3790 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 670:
#line 3793 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 671:
#line 3799 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 672:
#line 3804 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 673:
#line 3808 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 676:
#line 3816 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 677:
#line 3819 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 678:
#line 3822 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 679:
#line 3827 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 680:
#line 3832 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 681:
#line 3837 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 682:
#line 3844 "fgl.yacc"
    {
int dtype;
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
dtype=scan_variable(yyvsp[0].str)&15;
if (dtype!=DTYPE_CHAR && dtype!=DTYPE_VCHAR) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 684:
#line 3855 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 685:
#line 3917 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 687:
#line 3926 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 688:
#line 3935 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 690:
#line 3942 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 691:
#line 3945 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 692:
#line 3951 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 693:
#line 3957 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 694:
#line 3961 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 695:
#line 3965 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 696:
#line 3971 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 697:
#line 3975 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 698:
#line 3979 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 699:
#line 3984 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 700:
#line 3989 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 719:
#line 4030 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 720:
#line 4037 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 721:
#line 4039 "fgl.yacc"
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

  case 723:
#line 4058 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 725:
#line 4061 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 726:
#line 4063 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 727:
#line 4066 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 728:
#line 4070 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 729:
#line 4073 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 730:
#line 4080 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 731:
#line 4085 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 732:
#line 4096 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 733:
#line 4097 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 734:
#line 4100 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 736:
#line 4106 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 737:
#line 4110 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 738:
#line 4111 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 739:
#line 4115 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 743:
#line 4130 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 744:
#line 4132 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 747:
#line 4141 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 748:
#line 4144 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 749:
#line 4148 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 750:
#line 4151 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 751:
#line 4154 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 752:
#line 4157 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 753:
#line 4160 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 754:
#line 4164 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 755:
#line 4167 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 756:
#line 4170 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 757:
#line 4173 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 758:
#line 4176 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 759:
#line 4179 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 760:
#line 4182 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 761:
#line 4185 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 762:
#line 4188 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 763:
#line 4189 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 764:
#line 4189 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 765:
#line 4190 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 766:
#line 4190 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 767:
#line 4191 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 768:
#line 4191 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 769:
#line 4192 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 770:
#line 4195 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 771:
#line 4196 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 772:
#line 4199 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 773:
#line 4207 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 774:
#line 4211 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 775:
#line 4217 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 776:
#line 4221 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 777:
#line 4226 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 778:
#line 4231 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 779:
#line 4236 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 780:
#line 4237 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 781:
#line 4238 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 782:
#line 4242 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 783:
#line 4246 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 784:
#line 4255 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 785:
#line 4260 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 786:
#line 4264 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 787:
#line 4271 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 788:
#line 4280 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 789:
#line 4286 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 790:
#line 4287 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 791:
#line 4288 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 792:
#line 4289 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 793:
#line 4290 "fgl.yacc"
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

  case 794:
#line 4300 "fgl.yacc"
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

  case 795:
#line 4314 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 797:
#line 4317 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 798:
#line 4324 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 799:
#line 4325 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 800:
#line 4326 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 801:
#line 4327 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 802:
#line 4328 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 803:
#line 4329 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 804:
#line 4330 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 805:
#line 4331 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 806:
#line 4332 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 807:
#line 4337 "fgl.yacc"
    {iskey=1;}
    break;

  case 808:
#line 4337 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 809:
#line 4339 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 810:
#line 4342 "fgl.yacc"
    {iskey=1;}
    break;

  case 811:
#line 4342 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 812:
#line 4344 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 813:
#line 4348 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 814:
#line 4351 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 815:
#line 4352 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 817:
#line 4355 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 823:
#line 4367 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 824:
#line 4368 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 825:
#line 4369 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 826:
#line 4370 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 827:
#line 4371 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 828:
#line 4372 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 829:
#line 4373 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 830:
#line 4374 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 831:
#line 4375 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 832:
#line 4376 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 833:
#line 4377 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 834:
#line 4378 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 835:
#line 4379 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 836:
#line 4380 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 837:
#line 4384 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 838:
#line 4402 "fgl.yacc"
    {chk4var=1;}
    break;

  case 839:
#line 4402 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 840:
#line 4405 "fgl.yacc"
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

  case 841:
#line 4429 "fgl.yacc"
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

  case 843:
#line 4447 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 844:
#line 4453 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 845:
#line 4459 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 846:
#line 4465 "fgl.yacc"
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

  case 847:
#line 4477 "fgl.yacc"
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

  case 851:
#line 4508 "fgl.yacc"
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

  case 854:
#line 4525 "fgl.yacc"
    {
	}
    break;

  case 864:
#line 4551 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 868:
#line 4559 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 882:
#line 4583 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 883:
#line 4584 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 884:
#line 4592 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 885:
#line 4598 "fgl.yacc"
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

  case 886:
#line 4614 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 887:
#line 4620 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 889:
#line 4635 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 890:
#line 4648 "fgl.yacc"
    { 
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
    lastlineno=yylineno;
    variable_action(-1,yyvsp[0].str,"","","add_function");
    sprintf(curr_func,"MAIN");
    clr_variable(); 
    push_blockcommand("MAIN"); 
    addmap("MAIN",curr_func,"MODULE",yylineno,infilename);
    print_main_1();
  }
    break;

  case 891:
#line 4659 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 892:
#line 4666 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 893:
#line 4673 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 894:
#line 4679 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 895:
#line 4679 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 896:
#line 4684 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 897:
#line 4690 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 898:
#line 4698 "fgl.yacc"
    {
}
    break;

  case 902:
#line 4710 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 904:
#line 4718 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 905:
#line 4724 "fgl.yacc"
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

  case 908:
#line 4744 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 909:
#line 4750 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 910:
#line 4754 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 913:
#line 4766 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 914:
#line 4769 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 915:
#line 4773 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 916:
#line 4776 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 917:
#line 4788 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 918:
#line 4796 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 919:
#line 4802 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 920:
#line 4813 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 921:
#line 4817 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 922:
#line 4824 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 923:
#line 4831 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 924:
#line 4837 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 925:
#line 4842 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 928:
#line 4849 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 929:
#line 4850 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 930:
#line 4852 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 931:
#line 4853 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 932:
#line 4856 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 933:
#line 4857 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 934:
#line 4858 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 935:
#line 4860 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 936:
#line 4865 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 937:
#line 4870 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 938:
#line 4877 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 942:
#line 4884 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 943:
#line 4886 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 944:
#line 4888 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 946:
#line 4898 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 947:
#line 4901 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 948:
#line 4904 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 955:
#line 4920 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 956:
#line 4925 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 957:
#line 4925 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 958:
#line 4928 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 959:
#line 4956 "fgl.yacc"
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

  case 961:
#line 5013 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 963:
#line 5020 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 964:
#line 5024 "fgl.yacc"
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

  case 965:
#line 5067 "fgl.yacc"
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

  case 969:
#line 5115 "fgl.yacc"
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

  case 970:
#line 5129 "fgl.yacc"
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

  case 975:
#line 5153 "fgl.yacc"
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

  case 976:
#line 5217 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 977:
#line 5222 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 978:
#line 5230 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 979:
#line 5235 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 980:
#line 5243 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 981:
#line 5249 "fgl.yacc"
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

  case 982:
#line 5281 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 983:
#line 5284 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 984:
#line 5286 "fgl.yacc"
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

  case 985:
#line 5327 "fgl.yacc"
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

  case 990:
#line 5380 "fgl.yacc"
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

  case 991:
#line 5432 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 993:
#line 5441 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 994:
#line 5446 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 995:
#line 5457 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 996:
#line 5464 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 998:
#line 5472 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 999:
#line 5475 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 1000:
#line 5476 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1002:
#line 5478 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1003:
#line 5479 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1004:
#line 5482 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 1005:
#line 5485 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1006:
#line 5491 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 1007:
#line 5494 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1008:
#line 5498 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 1009:
#line 5503 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1010:
#line 5511 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 1011:
#line 5516 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 1012:
#line 5523 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1013:
#line 5525 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1018:
#line 5553 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1019:
#line 5560 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1020:
#line 5567 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1021:
#line 5570 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1022:
#line 5584 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1027:
#line 5601 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1028:
#line 5606 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1029:
#line 5612 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1031:
#line 5619 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1032:
#line 5624 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1033:
#line 5627 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1034:
#line 5628 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1035:
#line 5631 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1036:
#line 5632 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1037:
#line 5635 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1038:
#line 5636 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1039:
#line 5641 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1040:
#line 5648 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1041:
#line 5651 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1042:
#line 5657 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1043:
#line 5659 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1044:
#line 5661 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1045:
#line 5663 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1046:
#line 5666 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1047:
#line 5666 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1048:
#line 5667 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1049:
#line 5672 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1050:
#line 5680 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1051:
#line 5681 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1052:
#line 5686 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1053:
#line 5688 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1054:
#line 5690 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1058:
#line 5708 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1059:
#line 5709 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1060:
#line 5710 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1061:
#line 5711 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1062:
#line 5712 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1063:
#line 5713 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1064:
#line 5714 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1065:
#line 5715 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1066:
#line 5716 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1067:
#line 5717 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1068:
#line 5718 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1069:
#line 5719 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1070:
#line 5720 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1071:
#line 5721 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1072:
#line 5722 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1073:
#line 5723 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1074:
#line 5724 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1075:
#line 5725 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1076:
#line 5726 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1077:
#line 5727 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1078:
#line 5728 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1079:
#line 5729 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1080:
#line 5730 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1081:
#line 5731 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1082:
#line 5732 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1083:
#line 5733 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1084:
#line 5748 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1087:
#line 5757 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1088:
#line 5761 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1089:
#line 5765 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1090:
#line 5769 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1091:
#line 5773 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1093:
#line 5793 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1094:
#line 5798 "fgl.yacc"
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

  case 1095:
#line 5811 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1096:
#line 5812 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1097:
#line 5816 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1098:
#line 5821 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1099:
#line 5822 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1100:
#line 5826 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1104:
#line 5832 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1105:
#line 5835 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1107:
#line 5850 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1108:
#line 5854 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1109:
#line 5860 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1110:
#line 5861 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1111:
#line 5866 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1112:
#line 5867 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1113:
#line 5870 "fgl.yacc"
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

  case 1115:
#line 5897 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1116:
#line 5901 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1117:
#line 5905 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1118:
#line 5909 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1119:
#line 5916 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1120:
#line 5917 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1126:
#line 5929 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1127:
#line 5935 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1128:
#line 5943 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1129:
#line 5949 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1130:
#line 5951 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1134:
#line 5961 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1135:
#line 5961 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1136:
#line 5966 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1137:
#line 5970 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1138:
#line 5975 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1139:
#line 5975 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1140:
#line 5979 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1141:
#line 5979 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1142:
#line 5980 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1143:
#line 5980 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1144:
#line 5981 "fgl.yacc"
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

  case 1145:
#line 5994 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1146:
#line 5995 "fgl.yacc"
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

  case 1147:
#line 6011 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1154:
#line 6023 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1155:
#line 6023 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1156:
#line 6029 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1157:
#line 6029 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1158:
#line 6032 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1159:
#line 6032 "fgl.yacc"
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

  case 1160:
#line 6048 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1161:
#line 6049 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1162:
#line 6050 "fgl.yacc"
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

  case 1163:
#line 6059 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1164:
#line 6071 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1170:
#line 6082 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1171:
#line 6087 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1172:
#line 6087 "fgl.yacc"
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

  case 1174:
#line 6111 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1175:
#line 6117 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1176:
#line 6122 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1177:
#line 6128 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1178:
#line 6129 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1179:
#line 6130 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1180:
#line 6134 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1181:
#line 6135 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1182:
#line 6136 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1183:
#line 6137 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1184:
#line 6141 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1185:
#line 6151 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1186:
#line 6153 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1187:
#line 6158 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1188:
#line 6161 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1189:
#line 6166 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1190:
#line 6173 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1191:
#line 6180 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1192:
#line 6187 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1193:
#line 6196 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1194:
#line 6203 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1195:
#line 6210 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1196:
#line 6217 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1197:
#line 6224 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1202:
#line 6237 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1203:
#line 6238 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1204:
#line 6239 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1205:
#line 6240 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1206:
#line 6241 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1207:
#line 6242 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1208:
#line 6243 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1209:
#line 6244 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1210:
#line 6245 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1211:
#line 6246 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1214:
#line 6252 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1215:
#line 6253 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1216:
#line 6254 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1217:
#line 6255 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1222:
#line 6264 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1223:
#line 6265 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1224:
#line 6266 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1225:
#line 6267 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1226:
#line 6268 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1227:
#line 6269 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1228:
#line 6270 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1229:
#line 6271 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1230:
#line 6273 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1231:
#line 6274 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1232:
#line 6275 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1233:
#line 6276 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1234:
#line 6278 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1235:
#line 6279 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1236:
#line 6280 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1237:
#line 6281 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1241:
#line 6286 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1242:
#line 6287 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1246:
#line 6294 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1247:
#line 6303 "fgl.yacc"
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

  case 1248:
#line 6312 "fgl.yacc"
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

  case 1249:
#line 6325 "fgl.yacc"
    { 
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1250:
#line 6336 "fgl.yacc"
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

  case 1251:
#line 6347 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1252:
#line 6351 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1253:
#line 6355 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1254:
#line 6361 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1255:
#line 6366 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1256:
#line 6374 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1257:
#line 6377 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1258:
#line 6386 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1259:
#line 6397 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1261:
#line 6404 "fgl.yacc"
    {
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1262:
#line 6414 "fgl.yacc"
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

  case 1263:
#line 6424 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1264:
#line 6427 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1265:
#line 6431 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1266:
#line 6439 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1267:
#line 6442 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1268:
#line 6448 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1269:
#line 6452 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1270:
#line 6456 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1271:
#line 6460 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1272:
#line 6464 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1273:
#line 6470 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1274:
#line 6471 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1275:
#line 6472 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1276:
#line 6473 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1277:
#line 6478 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1278:
#line 6480 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1279:
#line 6483 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1280:
#line 6487 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1281:
#line 6490 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1282:
#line 6497 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1283:
#line 6502 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1284:
#line 6509 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1285:
#line 6510 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1286:
#line 6511 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1287:
#line 6516 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1288:
#line 6517 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1289:
#line 6523 "fgl.yacc"
    {insql=1;}
    break;

  case 1290:
#line 6523 "fgl.yacc"
    {insql=0;}
    break;

  case 1291:
#line 6523 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1292:
#line 6528 "fgl.yacc"
    {insql=1;}
    break;

  case 1293:
#line 6528 "fgl.yacc"
    {insql=0;}
    break;

  case 1294:
#line 6528 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1295:
#line 6536 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1296:
#line 6537 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1298:
#line 6542 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1299:
#line 6547 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1300:
#line 6548 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1301:
#line 6549 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1302:
#line 6550 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1303:
#line 6551 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1305:
#line 6556 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1306:
#line 6556 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1308:
#line 6560 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1309:
#line 6564 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1310:
#line 6565 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1311:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1312:
#line 6569 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1313:
#line 6572 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1314:
#line 6575 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1315:
#line 6578 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1316:
#line 6584 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1317:
#line 6586 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1319:
#line 6599 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1320:
#line 6603 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1321:
#line 6604 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1323:
#line 6609 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1324:
#line 6612 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1325:
#line 6618 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1326:
#line 6621 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1327:
#line 6629 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1329:
#line 6636 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1330:
#line 6640 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1331:
#line 6644 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1332:
#line 6650 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1333:
#line 6653 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1334:
#line 6662 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1335:
#line 6665 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1336:
#line 6668 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1337:
#line 6671 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1338:
#line 6674 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1339:
#line 6677 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1340:
#line 6680 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1341:
#line 6687 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1342:
#line 6690 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1343:
#line 6697 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1344:
#line 6700 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1345:
#line 6706 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1346:
#line 6709 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1347:
#line 6716 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1348:
#line 6719 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1350:
#line 6727 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1352:
#line 6736 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1353:
#line 6739 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1354:
#line 6745 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1355:
#line 6748 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1356:
#line 6754 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1357:
#line 6761 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1358:
#line 6762 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1359:
#line 6766 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1360:
#line 6776 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1361:
#line 6779 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1362:
#line 6785 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1363:
#line 6787 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1364:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1365:
#line 6793 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6798 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1367:
#line 6799 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1368:
#line 6805 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1369:
#line 6806 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1373:
#line 6833 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6839 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1380:
#line 6842 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1381:
#line 6845 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1382:
#line 6851 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1384:
#line 6857 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1386:
#line 6868 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1387:
#line 6882 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1388:
#line 6891 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1389:
#line 6891 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1390:
#line 6896 "fgl.yacc"
    {insql=1;}
    break;

  case 1391:
#line 6896 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1392:
#line 6901 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1393:
#line 6904 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1394:
#line 6906 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6913 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6917 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1398:
#line 6921 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1399:
#line 6928 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1400:
#line 6931 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1401:
#line 6938 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1402:
#line 6942 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1403:
#line 6948 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1404:
#line 6953 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1405:
#line 6957 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1406:
#line 6963 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1407:
#line 6966 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1408:
#line 6972 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1409:
#line 6979 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1410:
#line 6983 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1411:
#line 6988 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1412:
#line 6998 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1413:
#line 7001 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1414:
#line 7003 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1415:
#line 7005 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1416:
#line 7007 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1417:
#line 7009 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1418:
#line 7011 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1419:
#line 7013 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1420:
#line 7019 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1421:
#line 7029 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1422:
#line 7036 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 7042 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 7045 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 7052 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1431:
#line 7057 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1432:
#line 7062 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1433:
#line 7069 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1434:
#line 7070 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1435:
#line 7077 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1436:
#line 7088 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1437:
#line 7089 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7090 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1439:
#line 7093 "fgl.yacc"
    {insql=1;}
    break;

  case 1440:
#line 7093 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1441:
#line 7098 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1442:
#line 7103 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1444:
#line 7109 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1446:
#line 7113 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1447:
#line 7118 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1448:
#line 7123 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1449:
#line 7127 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1451:
#line 7133 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1452:
#line 7137 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1453:
#line 7144 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 7145 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 7146 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1456:
#line 7147 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 7157 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1461:
#line 7158 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1462:
#line 7159 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1463:
#line 7163 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1464:
#line 7164 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1467:
#line 7171 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7174 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 7177 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1474:
#line 7182 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7184 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7190 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 7196 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7206 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1483:
#line 7211 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1484:
#line 7213 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1486:
#line 7219 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1487:
#line 7222 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1489:
#line 7228 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1490:
#line 7236 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7241 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 7251 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1496:
#line 7257 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7262 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1498:
#line 7265 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1499:
#line 7270 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 7276 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7281 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1503:
#line 7284 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1504:
#line 7287 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1505:
#line 7294 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1506:
#line 7295 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1507:
#line 7296 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1508:
#line 7298 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1509:
#line 7311 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1510:
#line 7316 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1512:
#line 7320 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1513:
#line 7322 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1514:
#line 7329 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1515:
#line 7332 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1516:
#line 7338 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1517:
#line 7346 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1518:
#line 7350 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1519:
#line 7354 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1520:
#line 7358 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1521:
#line 7363 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1522:
#line 7366 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1523:
#line 7369 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1524:
#line 7377 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1525:
#line 7384 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1528:
#line 7393 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1529:
#line 7399 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1530:
#line 7402 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1531:
#line 7413 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1532:
#line 7420 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1533:
#line 7426 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1534:
#line 7429 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1535:
#line 7436 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1536:
#line 7443 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1538:
#line 7450 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1539:
#line 7456 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1540:
#line 7457 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1541:
#line 7458 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1543:
#line 7462 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1544:
#line 7469 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1546:
#line 7476 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1547:
#line 7483 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1548:
#line 7488 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1549:
#line 7489 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1550:
#line 7492 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1551:
#line 7495 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1552:
#line 7500 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1553:
#line 7501 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1554:
#line 7506 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1555:
#line 7509 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1556:
#line 7515 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1557:
#line 7518 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1558:
#line 7524 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1559:
#line 7527 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1560:
#line 7533 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1561:
#line 7536 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1562:
#line 7543 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1563:
#line 7544 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1564:
#line 7573 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1565:
#line 7574 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1566:
#line 7578 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1568:
#line 7591 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1569:
#line 7594 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1570:
#line 7597 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1571:
#line 7600 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1573:
#line 7608 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1574:
#line 7611 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1576:
#line 7617 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1578:
#line 7623 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1579:
#line 7626 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1580:
#line 7629 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1581:
#line 7632 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1582:
#line 7635 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1583:
#line 7638 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1584:
#line 7641 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1585:
#line 7644 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1586:
#line 7649 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1588:
#line 7656 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1592:
#line 7662 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1593:
#line 7663 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1594:
#line 7668 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1595:
#line 7671 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1596:
#line 7675 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1597:
#line 7681 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1598:
#line 7682 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1599:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1600:
#line 7684 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1605:
#line 7704 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1607:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1608:
#line 7709 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1610:
#line 7712 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1611:
#line 7713 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1612:
#line 7722 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1619:
#line 7736 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1620:
#line 7738 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1621:
#line 7740 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1623:
#line 7743 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1625:
#line 7746 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1629:
#line 7751 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1630:
#line 7753 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1631:
#line 7756 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1632:
#line 7757 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1633:
#line 7764 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1637:
#line 7769 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1641:
#line 7785 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1642:
#line 7792 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1643:
#line 7796 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1644:
#line 7797 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1645:
#line 7798 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1646:
#line 7806 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1647:
#line 7807 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1648:
#line 7808 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1649:
#line 7819 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1650:
#line 7826 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1651:
#line 7831 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1652:
#line 7832 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1653:
#line 7833 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1654:
#line 7841 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1655:
#line 7842 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1656:
#line 7843 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1658:
#line 7869 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1659:
#line 7870 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1660:
#line 7871 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1661:
#line 7875 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1662:
#line 7878 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1663:
#line 7884 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1664:
#line 7889 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1665:
#line 7894 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1667:
#line 7905 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1671:
#line 7923 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1672:
#line 7926 "fgl.yacc"
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

  case 1673:
#line 7939 "fgl.yacc"
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

  case 1674:
#line 7954 "fgl.yacc"
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

  case 1675:
#line 7966 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1676:
#line 7968 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1677:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1678:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1679:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1680:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1681:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1682:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1683:
#line 7972 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1684:
#line 7975 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1699:
#line 7993 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1700:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1701:
#line 7997 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1702:
#line 7998 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1703:
#line 8002 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1704:
#line 8010 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1705:
#line 8010 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1706:
#line 8016 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1707:
#line 8016 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1708:
#line 8023 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1709:
#line 8023 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1710:
#line 8029 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1711:
#line 8029 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1712:
#line 8037 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1713:
#line 8038 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1714:
#line 8039 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1715:
#line 8042 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1716:
#line 8042 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1718:
#line 8046 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1719:
#line 8047 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1720:
#line 8058 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1721:
#line 8061 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1722:
#line 8067 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1723:
#line 8072 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1724:
#line 8080 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1725:
#line 8092 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1726:
#line 8093 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1727:
#line 8096 "fgl.yacc"
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

  case 1728:
#line 8111 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1729:
#line 8122 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1730:
#line 8125 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1731:
#line 8133 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1732:
#line 8142 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1733:
#line 8145 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1734:
#line 8149 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1735:
#line 8152 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1736:
#line 8153 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1738:
#line 8166 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1739:
#line 8167 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1740:
#line 8176 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1741:
#line 8185 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1742:
#line 8190 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1743:
#line 8191 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1744:
#line 8192 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1745:
#line 8193 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1746:
#line 8200 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1747:
#line 8203 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1748:
#line 8209 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1749:
#line 8212 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1750:
#line 8219 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1751:
#line 8231 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1752:
#line 8240 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1753:
#line 8243 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1754:
#line 8246 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1755:
#line 8252 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1756:
#line 8260 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1757:
#line 8263 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1758:
#line 8264 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1759:
#line 8265 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1760:
#line 8266 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1761:
#line 8267 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1762:
#line 8270 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1763:
#line 8277 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1764:
#line 8279 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1765:
#line 8281 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1766:
#line 8283 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1767:
#line 8285 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1768:
#line 8286 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1769:
#line 8287 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1770:
#line 8288 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1771:
#line 8289 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1772:
#line 8290 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1773:
#line 8291 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1774:
#line 8293 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1775:
#line 8295 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1776:
#line 8297 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1777:
#line 8299 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1778:
#line 8301 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1779:
#line 8303 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1780:
#line 8305 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1781:
#line 8306 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1782:
#line 8308 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1783:
#line 8309 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1784:
#line 8310 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1785:
#line 8316 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1786:
#line 8317 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1788:
#line 8327 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1789:
#line 8335 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1790:
#line 8339 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1791:
#line 8346 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1792:
#line 8346 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1794:
#line 8350 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1795:
#line 8355 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1796:
#line 8355 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1798:
#line 8359 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1799:
#line 8363 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1802:
#line 8372 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1803:
#line 8372 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1808:
#line 8391 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1809:
#line 8392 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1812:
#line 8400 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1813:
#line 8406 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1816:
#line 8425 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1817:
#line 8426 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1818:
#line 8427 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1819:
#line 8428 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1820:
#line 8429 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1821:
#line 8430 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1822:
#line 8434 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1823:
#line 8435 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1824:
#line 8436 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1826:
#line 8441 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1827:
#line 8442 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1828:
#line 8446 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1829:
#line 8462 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1830:
#line 8463 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1831:
#line 8464 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1832:
#line 8468 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1833:
#line 8482 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1834:
#line 8486 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1836:
#line 8495 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1838:
#line 8500 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1839:
#line 8501 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1840:
#line 8825 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1841:
#line 8825 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1842:
#line 8832 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1843:
#line 8832 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1844:
#line 8920 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1845:
#line 8924 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1846:
#line 8926 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1847:
#line 8933 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1848:
#line 8937 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1849:
#line 8943 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1850:
#line 8951 "fgl.yacc"
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

  case 1851:
#line 8961 "fgl.yacc"
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

  case 1852:
#line 8971 "fgl.yacc"
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

  case 1853:
#line 8983 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1854:
#line 8986 "fgl.yacc"
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

  case 1855:
#line 9005 "fgl.yacc"
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

  case 1856:
#line 9031 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1857:
#line 9034 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1859:
#line 9043 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1860:
#line 9048 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1861:
#line 9051 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1862:
#line 9059 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1863:
#line 9067 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1864:
#line 9080 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1865:
#line 9083 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1866:
#line 9091 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1867:
#line 9094 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1868:
#line 9097 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1869:
#line 9105 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1870:
#line 9109 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1871:
#line 9110 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1872:
#line 9111 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1873:
#line 9112 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1874:
#line 9113 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1875:
#line 9114 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1876:
#line 9115 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1877:
#line 9116 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1878:
#line 9120 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1879:
#line 9121 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1880:
#line 9122 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1881:
#line 9123 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1882:
#line 9124 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1883:
#line 9130 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1884:
#line 9131 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1885:
#line 9132 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1886:
#line 9133 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1887:
#line 9134 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1888:
#line 9135 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1889:
#line 9136 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1890:
#line 9137 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1891:
#line 9138 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1892:
#line 9139 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1893:
#line 9140 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1894:
#line 9141 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1895:
#line 9142 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1896:
#line 9143 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1897:
#line 9144 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1898:
#line 9145 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1899:
#line 9150 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1900:
#line 9156 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1901:
#line 9157 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1902:
#line 9165 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1903:
#line 9167 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1905:
#line 9173 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1906:
#line 9177 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1907:
#line 9181 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1908:
#line 9197 "fgl.yacc"
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

  case 1909:
#line 9211 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1910:
#line 9217 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1911:
#line 9219 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1915:
#line 9233 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1916:
#line 9236 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1917:
#line 9243 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1918:
#line 9246 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1919:
#line 9276 "fgl.yacc"
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

  case 1920:
#line 9301 "fgl.yacc"
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

  case 1921:
#line 9356 "fgl.yacc"
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

  case 1922:
#line 9391 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1923:
#line 9400 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1924:
#line 9411 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1925:
#line 9414 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1926:
#line 9420 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1927:
#line 9433 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1928:
#line 9447 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1929:
#line 9450 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1930:
#line 9454 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1931:
#line 9469 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1932:
#line 9469 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1933:
#line 9475 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1934:
#line 9476 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1935:
#line 9479 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1936:
#line 9480 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1937:
#line 9481 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1938:
#line 9482 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1939:
#line 9483 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1940:
#line 9484 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1941:
#line 9485 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1942:
#line 9496 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1943:
#line 9500 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1944:
#line 9504 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1945:
#line 9508 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1946:
#line 9513 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1947:
#line 9517 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1948:
#line 9522 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1950:
#line 9530 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1952:
#line 9536 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1953:
#line 9542 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1954:
#line 9546 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1959:
#line 9564 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1960:
#line 9571 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1961:
#line 9581 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1962:
#line 9581 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18907 "y.tab.c"

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


#line 1008 "fgl.yacc"

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



