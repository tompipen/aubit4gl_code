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
     NAME = 1713,
     UMINUS = 1714,
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
     NUMBER_VALUE = 1715,
     CHAR_VALUE = 1716,
     INT_VALUE = 1717,
     NAMED_GEN = 1718,
     CLINE = 1719,
     SQLLINE = 1720,
     KW_CSTART = 1721,
     KW_CEND = 1722,
     USER_DTYPE = 1723,
     SQL_TEXT = 1724,
     KW_WHENEVER_SET = 1725,
     COMMENT = 1726,
     DATETIME_VALUE = 1000,
     INTERVAL_VALUE = 1001,
     FGL_SIZEOF = 1002,
     IMPORT_PACKAGE = 1003,
     DYNAMIC_ARRAY = 1004,
     RESIZE_ARRAY = 1005,
     ALLOCATE_ARRAY = 1006,
     DEALLOCATE_ARRAY = 1007,
     AFTER_INSERT_DELETE = 1008,
     BEFORE_INSERT_DELETE = 1009,
     BEFORE_INSERT = 1010,
     AS_CONVERTABLE = 1011,
     CONCAT_PIPES = 1012,
     BEFORE_DELETE = 1013,
     DROP_TRIGGER = 1014,
     AFTER_INSERT = 1015,
     AFTER_DELETE = 1016,
     EXECUTE_IMMEDIATE = 1017,
     DELETE_ROW_EQUAL_TRUE = 1018,
     INSERT_ROW_EQUAL_TRUE = 1019,
     DELETE_ROW_EQUAL_FALSE = 1020,
     INSERT_ROW_EQUAL_FALSE = 1021,
     CURRENT_ROW_DISPLAY_EQUAL = 1022,
     MAXCOUNT = 1023,
     ALTER_TABLE = 1024,
     ALTER_INDEX = 1025,
     NEXT_SIZE = 1026,
     DISPLAY_ATTR_FORM = 1027,
     DISPLAY_ATTR_WINDOW = 1028,
     INPUT_ATTR_FORM = 1029,
     INPUT_ATTR_WINDOW = 1030,
     WHENEVER_ERROR_CONTINUE = 1031,
     WHENEVER_ANY_ERROR_CONTINUE = 1032,
     WHENEVER_WARNING_CONTINUE = 1033,
     WHENEVER_SQLSUCCESS_CONTINUE = 1034,
     WHENEVER_SQLWARNING_CONTINUE = 1035,
     WHENEVER_NOT_FOUND_CONTINUE = 1036,
     WHENEVER_SQLERROR_CONTINUE = 1037,
     WHENEVER_SUCCESS_CONTINUE = 1038,
     WHENEVER_ERROR_GOTO = 1039,
     WHENEVER_ANY_ERROR_GOTO = 1040,
     WHENEVER_WARNING_GOTO = 1041,
     WHENEVER_SQLSUCCESS_GOTO = 1042,
     WHENEVER_SQLWARNING_GOTO = 1043,
     WHENEVER_NOT_FOUND_GOTO = 1044,
     WHENEVER_SQLERROR_GOTO = 1045,
     WHENEVER_SUCCESS_GOTO = 1046,
     WHENEVER_ERROR_CALL = 1047,
     WHENEVER_ANY_ERROR_CALL = 1048,
     WHENEVER_WARNING_CALL = 1049,
     WHENEVER_SQLSUCCESS_CALL = 1050,
     WHENEVER_SQLWARNING_CALL = 1051,
     WHENEVER_NOT_FOUND_CALL = 1052,
     WHENEVER_SQLERROR_CALL = 1053,
     WHENEVER_SUCCESS_CALL = 1054,
     WHENEVER_ERROR_STOP = 1055,
     WHENEVER_ANY_ERROR_STOP = 1056,
     WHENEVER_WARNING_STOP = 1057,
     WHENEVER_SQLSUCCESS_STOP = 1058,
     WHENEVER_SQLWARNING_STOP = 1059,
     WHENEVER_NOT_FOUND_STOP = 1060,
     WHENEVER_SQLERROR_STOP = 1061,
     WHENEVER_SUCCESS_STOP = 1062,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1063,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1064,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1065,
     XSET_MULTIPLY_EQUAL = 1066,
     XSET_OPEN_BRACKET = 1067,
     NEWFORMATSHARED = 1068,
     CREATE_DATABASE = 1069,
     DROP_DATABASE = 1070,
     IMPORT_LEGACY_FUNCTION = 1071,
     ADD_CONSTRAINT = 1072,
     DROP_CONSTRAINT = 1073,
     DROP_SYNONYM = 1074,
     CONSTRAINT = 1075,
     AS_STATIC = 1076,
     NOT_FIELD_TOUCHED = 1077,
     LOCAL_FUNCTION = 1078,
     EVERY_ROW = 1079,
     ELIF = 1080,
     DOUBLE_PRECISION = 1081,
     COUNT_MULTIPLY = 1082,
     WAIT_FOR_KEY = 1083,
     AT_TERMINATION_CALL = 1084,
     TERMINATE_REPORT = 1085,
     TO_MAIN_CAPTION = 1086,
     CLEARSTAT = 1087,
     TO_MENUITEM = 1088,
     ID_TO_INT = 1089,
     TO_STATUSBOX = 1090,
     ASCII_HEIGHT_ALL = 1091,
     ASCII_WIDTH_ALL = 1092,
     IMPORT_DATATYPE = 1093,
     PAGE_TRAILER_SIZE = 1094,
     PAGE_HEADER_SIZE = 1095,
     FIRST_PAGE_HEADER_SIZE = 1096,
     BYTES_USE_AS_IMAGE = 1097,
     BYTES_USE_AS_ASCII = 1098,
     KWUP_BY = 1099,
     KWDOWN_BY = 1100,
     CLOSE_STATUSBOX = 1101,
     MODIFY_NEXT_SIZE = 1102,
     LOCK_MODE_PAGE = 1103,
     LOCK_MODE_ROW = 1104,
     TO_PIPE = 1105,
     TO_PRINTER = 1106,
     STATUSBOX = 1107,
     FORMHANDLER_INPUT = 1108,
     UNITS_YEAR = 1109,
     UNITS_MONTH = 1110,
     UNITS_DAY = 1111,
     UNITS_HOUR = 1112,
     UNITS_MINUTE = 1113,
     UNITS_SECOND = 1114,
     NO_NEW_LINES = 1115,
     FIELDTOWIDGET = 1116,
     WITH_HOLD = 1117,
     SHOW_MENU = 1118,
     TO_CLUSTER = 1119,
     TO_NOT_CLUSTER = 1120,
     CWIS = 1121,
     CREATE_IDX = 1122,
     FORM_IS_COMPILED = 1123,
     PDF_REPORT = 1124,
     IMPORT_FUNCTION = 1125,
     PROMPT_MANY = 1126,
     POINTS = 1127,
     MM = 1128,
     INCHES = 1129,
     PREPEND = 1130,
     MEMBER_OF = 1131,
     MEMBER_FUNCTION = 1132,
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
     FILLFACTOR = 1711
   };
#endif
#define NAME 1713
#define UMINUS 1714
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
#define NUMBER_VALUE 1715
#define CHAR_VALUE 1716
#define INT_VALUE 1717
#define NAMED_GEN 1718
#define CLINE 1719
#define SQLLINE 1720
#define KW_CSTART 1721
#define KW_CEND 1722
#define USER_DTYPE 1723
#define SQL_TEXT 1724
#define KW_WHENEVER_SET 1725
#define COMMENT 1726
#define DATETIME_VALUE 1000
#define INTERVAL_VALUE 1001
#define FGL_SIZEOF 1002
#define IMPORT_PACKAGE 1003
#define DYNAMIC_ARRAY 1004
#define RESIZE_ARRAY 1005
#define ALLOCATE_ARRAY 1006
#define DEALLOCATE_ARRAY 1007
#define AFTER_INSERT_DELETE 1008
#define BEFORE_INSERT_DELETE 1009
#define BEFORE_INSERT 1010
#define AS_CONVERTABLE 1011
#define CONCAT_PIPES 1012
#define BEFORE_DELETE 1013
#define DROP_TRIGGER 1014
#define AFTER_INSERT 1015
#define AFTER_DELETE 1016
#define EXECUTE_IMMEDIATE 1017
#define DELETE_ROW_EQUAL_TRUE 1018
#define INSERT_ROW_EQUAL_TRUE 1019
#define DELETE_ROW_EQUAL_FALSE 1020
#define INSERT_ROW_EQUAL_FALSE 1021
#define CURRENT_ROW_DISPLAY_EQUAL 1022
#define MAXCOUNT 1023
#define ALTER_TABLE 1024
#define ALTER_INDEX 1025
#define NEXT_SIZE 1026
#define DISPLAY_ATTR_FORM 1027
#define DISPLAY_ATTR_WINDOW 1028
#define INPUT_ATTR_FORM 1029
#define INPUT_ATTR_WINDOW 1030
#define WHENEVER_ERROR_CONTINUE 1031
#define WHENEVER_ANY_ERROR_CONTINUE 1032
#define WHENEVER_WARNING_CONTINUE 1033
#define WHENEVER_SQLSUCCESS_CONTINUE 1034
#define WHENEVER_SQLWARNING_CONTINUE 1035
#define WHENEVER_NOT_FOUND_CONTINUE 1036
#define WHENEVER_SQLERROR_CONTINUE 1037
#define WHENEVER_SUCCESS_CONTINUE 1038
#define WHENEVER_ERROR_GOTO 1039
#define WHENEVER_ANY_ERROR_GOTO 1040
#define WHENEVER_WARNING_GOTO 1041
#define WHENEVER_SQLSUCCESS_GOTO 1042
#define WHENEVER_SQLWARNING_GOTO 1043
#define WHENEVER_NOT_FOUND_GOTO 1044
#define WHENEVER_SQLERROR_GOTO 1045
#define WHENEVER_SUCCESS_GOTO 1046
#define WHENEVER_ERROR_CALL 1047
#define WHENEVER_ANY_ERROR_CALL 1048
#define WHENEVER_WARNING_CALL 1049
#define WHENEVER_SQLSUCCESS_CALL 1050
#define WHENEVER_SQLWARNING_CALL 1051
#define WHENEVER_NOT_FOUND_CALL 1052
#define WHENEVER_SQLERROR_CALL 1053
#define WHENEVER_SUCCESS_CALL 1054
#define WHENEVER_ERROR_STOP 1055
#define WHENEVER_ANY_ERROR_STOP 1056
#define WHENEVER_WARNING_STOP 1057
#define WHENEVER_SQLSUCCESS_STOP 1058
#define WHENEVER_SQLWARNING_STOP 1059
#define WHENEVER_NOT_FOUND_STOP 1060
#define WHENEVER_SQLERROR_STOP 1061
#define WHENEVER_SUCCESS_STOP 1062
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1063
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1064
#define XSET_ident_DOT_MULTIPLY_EQUAL 1065
#define XSET_MULTIPLY_EQUAL 1066
#define XSET_OPEN_BRACKET 1067
#define NEWFORMATSHARED 1068
#define CREATE_DATABASE 1069
#define DROP_DATABASE 1070
#define IMPORT_LEGACY_FUNCTION 1071
#define ADD_CONSTRAINT 1072
#define DROP_CONSTRAINT 1073
#define DROP_SYNONYM 1074
#define CONSTRAINT 1075
#define AS_STATIC 1076
#define NOT_FIELD_TOUCHED 1077
#define LOCAL_FUNCTION 1078
#define EVERY_ROW 1079
#define ELIF 1080
#define DOUBLE_PRECISION 1081
#define COUNT_MULTIPLY 1082
#define WAIT_FOR_KEY 1083
#define AT_TERMINATION_CALL 1084
#define TERMINATE_REPORT 1085
#define TO_MAIN_CAPTION 1086
#define CLEARSTAT 1087
#define TO_MENUITEM 1088
#define ID_TO_INT 1089
#define TO_STATUSBOX 1090
#define ASCII_HEIGHT_ALL 1091
#define ASCII_WIDTH_ALL 1092
#define IMPORT_DATATYPE 1093
#define PAGE_TRAILER_SIZE 1094
#define PAGE_HEADER_SIZE 1095
#define FIRST_PAGE_HEADER_SIZE 1096
#define BYTES_USE_AS_IMAGE 1097
#define BYTES_USE_AS_ASCII 1098
#define KWUP_BY 1099
#define KWDOWN_BY 1100
#define CLOSE_STATUSBOX 1101
#define MODIFY_NEXT_SIZE 1102
#define LOCK_MODE_PAGE 1103
#define LOCK_MODE_ROW 1104
#define TO_PIPE 1105
#define TO_PRINTER 1106
#define STATUSBOX 1107
#define FORMHANDLER_INPUT 1108
#define UNITS_YEAR 1109
#define UNITS_MONTH 1110
#define UNITS_DAY 1111
#define UNITS_HOUR 1112
#define UNITS_MINUTE 1113
#define UNITS_SECOND 1114
#define NO_NEW_LINES 1115
#define FIELDTOWIDGET 1116
#define WITH_HOLD 1117
#define SHOW_MENU 1118
#define TO_CLUSTER 1119
#define TO_NOT_CLUSTER 1120
#define CWIS 1121
#define CREATE_IDX 1122
#define FORM_IS_COMPILED 1123
#define PDF_REPORT 1124
#define IMPORT_FUNCTION 1125
#define PROMPT_MANY 1126
#define POINTS 1127
#define MM 1128
#define INCHES 1129
#define PREPEND 1130
#define MEMBER_OF 1131
#define MEMBER_FUNCTION 1132
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
#line 216 "fgl.yacc"
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
#line 1712 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1724 "y.tab.c"

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9634

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  729
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  864
/* YYNRULES -- Number of rules. */
#define YYNRULES  2039
/* YYNRULES -- Number of states. */
#define YYNSTATES  3466

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1726

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
     727,   728,     2,     3,     4,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35
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
    1164,  1166,  1168,  1170,  1172,  1174,  1177,  1179,  1181,  1183,
    1186,  1189,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1207,  1209,  1212,  1214,  1217,  1219,  1221,  1223,  1227,  1229,
    1233,  1235,  1239,  1241,  1244,  1246,  1248,  1252,  1257,  1262,
    1264,  1266,  1268,  1270,  1272,  1276,  1278,  1281,  1284,  1286,
    1287,  1291,  1294,  1297,  1299,  1303,  1308,  1313,  1319,  1325,
    1327,  1329,  1332,  1335,  1340,  1345,  1348,  1351,  1356,  1361,
    1363,  1366,  1369,  1372,  1375,  1378,  1381,  1384,  1387,  1390,
    1393,  1396,  1399,  1402,  1405,  1406,  1407,  1408,  1415,  1416,
    1417,  1426,  1427,  1428,  1435,  1436,  1437,  1444,  1445,  1446,
    1453,  1454,  1455,  1462,  1468,  1474,  1480,  1486,  1494,  1502,
    1512,  1522,  1529,  1538,  1549,  1560,  1568,  1578,  1587,  1598,
    1611,  1626,  1641,  1652,  1665,  1678,  1683,  1688,  1695,  1696,
    1700,  1702,  1704,  1709,  1714,  1719,  1724,  1729,  1734,  1736,
    1738,  1740,  1742,  1747,  1752,  1755,  1758,  1761,  1764,  1767,
    1769,  1771,  1774,  1776,  1778,  1780,  1783,  1788,  1795,  1802,
    1806,  1812,  1818,  1822,  1824,  1826,  1830,  1832,  1836,  1838,
    1842,  1843,  1844,  1845,  1855,  1856,  1860,  1861,  1862,  1873,
    1874,  1876,  1877,  1879,  1881,  1884,  1885,  1889,  1890,  1894,
    1895,  1897,  1899,  1902,  1903,  1907,  1908,  1912,  1916,  1918,
    1923,  1927,  1929,  1933,  1935,  1939,  1941,  1945,  1947,  1950,
    1951,  1955,  1956,  1960,  1961,  1966,  1967,  1972,  1973,  1978,
    1979,  1980,  1992,  1993,  1996,  1999,  2003,  2005,  2009,  2011,
    2013,  2015,  2017,  2019,  2021,  2023,  2027,  2029,  2031,  2036,
    2043,  2048,  2052,  2059,  2063,  2070,  2072,  2074,  2076,  2078,
    2080,  2082,  2084,  2086,  2087,  2090,  2092,  2094,  2096,  2101,
    2103,  2105,  2107,  2112,  2116,  2123,  2127,  2134,  2136,  2138,
    2141,  2144,  2146,  2149,  2152,  2154,  2158,  2160,  2163,  2166,
    2169,  2174,  2177,  2180,  2185,  2186,  2195,  2196,  2198,  2200,
    2202,  2203,  2205,  2208,  2209,  2211,  2214,  2215,  2217,  2220,
    2221,  2223,  2227,  2228,  2231,  2232,  2233,  2242,  2243,  2244,
    2248,  2249,  2250,  2258,  2264,  2267,  2270,  2273,  2274,  2280,
    2285,  2287,  2291,  2295,  2299,  2301,  2302,  2305,  2307,  2308,
    2310,  2312,  2315,  2316,  2321,  2322,  2327,  2328,  2332,  2333,
    2337,  2338,  2342,  2343,  2347,  2348,  2352,  2353,  2357,  2358,
    2362,  2363,  2367,  2368,  2372,  2373,  2377,  2378,  2382,  2384,
    2388,  2390,  2394,  2397,  2402,  2404,  2406,  2408,  2409,  2414,
    2420,  2427,  2428,  2439,  2443,  2446,  2449,  2451,  2453,  2456,
    2459,  2460,  2463,  2465,  2468,  2472,  2476,  2480,  2484,  2486,
    2488,  2490,  2492,  2493,  2497,  2499,  2500,  2504,  2507,  2510,
    2512,  2516,  2518,  2522,  2524,  2526,  2528,  2530,  2532,  2534,
    2536,  2538,  2540,  2542,  2544,  2546,  2548,  2550,  2552,  2554,
    2556,  2558,  2560,  2562,  2563,  2564,  2572,  2574,  2576,  2579,
    2582,  2585,  2589,  2594,  2595,  2599,  2600,  2602,  2604,  2607,
    2609,  2611,  2613,  2615,  2617,  2619,  2621,  2622,  2624,  2626,
    2629,  2632,  2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,
    2650,  2652,  2654,  2655,  2657,  2659,  2661,  2663,  2664,  2665,
    2666,  2667,  2681,  2683,  2684,  2685,  2692,  2695,  2697,  2700,
    2703,  2706,  2708,  2710,  2713,  2715,  2716,  2720,  2723,  2725,
    2727,  2729,  2730,  2731,  2732,  2747,  2748,  2749,  2757,  2759,
    2762,  2763,  2767,  2768,  2773,  2774,  2780,  2782,  2783,  2787,
    2788,  2796,  2797,  2803,  2805,  2808,  2809,  2811,  2813,  2815,
    2816,  2818,  2820,  2823,  2826,  2829,  2831,  2833,  2835,  2837,
    2841,  2843,  2845,  2848,  2849,  2852,  2854,  2856,  2858,  2860,
    2862,  2864,  2866,  2870,  2871,  2873,  2875,  2877,  2879,  2882,
    2885,  2888,  2894,  2903,  2905,  2907,  2909,  2914,  2919,  2921,
    2923,  2925,  2927,  2930,  2934,  2941,  2943,  2947,  2949,  2951,
    2953,  2957,  2964,  2974,  2976,  2978,  2980,  2982,  2985,  2986,
    2988,  2990,  2994,  2996,  3000,  3002,  3006,  3008,  3012,  3014,
    3016,  3018,  3020,  3024,  3026,  3030,  3032,  3036,  3038,  3040,
    3042,  3046,  3049,  3050,  3052,  3054,  3056,  3060,  3062,  3066,
    3074,  3075,  3083,  3084,  3091,  3095,  3097,  3101,  3103,  3106,
    3112,  3113,  3121,  3122,  3125,  3126,  3128,  3134,  3137,  3143,
    3144,  3150,  3157,  3162,  3163,  3165,  3167,  3173,  3174,  3177,
    3178,  3184,  3189,  3192,  3194,  3198,  3201,  3204,  3207,  3210,
    3213,  3216,  3218,  3221,  3224,  3227,  3230,  3233,  3236,  3239,
    3241,  3243,  3245,  3247,  3250,  3253,  3255,  3257,  3259,  3261,
    3263,  3265,  3271,  3273,  3275,  3278,  3283,  3288,  3295,  3298,
    3300,  3301,  3313,  3314,  3317,  3323,  3324,  3326,  3327,  3330,
    3332,  3335,  3336,  3340,  3342,  3343,  3348,  3349,  3352,  3354,
    3358,  3360,  3362,  3367,  3373,  3379,  3383,  3384,  3386,  3388,
    3390,  3392,  3393,  3395,  3403,  3406,  3409,  3412,  3415,  3418,
    3420,  3423,  3424,  3428,  3429,  3433,  3434,  3438,  3439,  3443,
    3444,  3448,  3449,  3454,  3455,  3460,  3462,  3464,  3466,  3468,
    3470,  3472,  3473,  3478,  3479,  3481,  3482,  3487,  3489,  3492,
    3495,  3498,  3499,  3501,  3503,  3506,  3509,  3510,  3513,  3514,
    3519,  3521,  3525,  3529,  3535,  3536,  3539,  3544,  3546,  3548,
    3550,  3552,  3554,  3555,  3557,  3559,  3563,  3566,  3572,  3575,
    3581,  3587,  3593,  3599,  3605,  3611,  3612,  3615,  3617,  3620,
    3623,  3626,  3629,  3632,  3635,  3637,  3640,  3643,  3646,  3649,
    3651,  3654,  3657,  3660,  3663,  3665,  3667,  3669,  3670,  3673,
    3676,  3679,  3682,  3685,  3688,  3691,  3694,  3697,  3699,  3701,
    3703,  3705,  3707,  3709,  3711,  3713,  3716,  3719,  3722,  3725,
    3728,  3730,  3732,  3734,  3735,  3739,  3742,  3743,  3744,  3745,
    3746,  3747,  3748,  3764,  3765,  3768,  3771,  3772,  3774,  3775,
    3776,  3777,  3778,  3779,  3780,  3796,  3799,  3800,  3801,  3802,
    3813,  3814,  3816,  3820,  3824,  3827,  3832,  3836,  3840,  3844,
    3846,  3849,  3852,  3855,  3858,  3860,  3862,  3863,  3864,  3873,
    3874,  3875,  3885,  3886,  3888,  3890,  3893,  3896,  3899,  3902,
    3904,  3906,  3908,  3909,  3911,  3913,  3916,  3919,  3922,  3931,
    3934,  3937,  3942,  3945,  3946,  3948,  3950,  3954,  3957,  3960,
    3962,  3964,  3968,  3970,  3972,  3975,  3977,  3981,  3985,  3989,
    3991,  3995,  3997,  3999,  4001,  4003,  4005,  4007,  4009,  4012,
    4017,  4019,  4023,  4025,  4029,  4032,  4037,  4039,  4043,  4045,
    4048,  4053,  4055,  4059,  4061,  4063,  4065,  4068,  4072,  4077,
    4080,  4085,  4086,  4089,  4092,  4097,  4099,  4103,  4105,  4107,
    4109,  4112,  4114,  4116,  4118,  4120,  4122,  4125,  4132,  4139,
    4140,  4142,  4143,  4145,  4148,  4150,  4151,  4157,  4158,  4164,
    4166,  4167,  4171,  4173,  4177,  4179,  4183,  4185,  4187,  4188,
    4193,  4195,  4198,  4200,  4201,  4202,  4206,  4207,  4208,  4212,
    4214,  4216,  4218,  4220,  4222,  4224,  4227,  4230,  4235,  4239,
    4243,  4245,  4249,  4252,  4254,  4256,  4257,  4259,  4261,  4263,
    4265,  4266,  4268,  4272,  4274,  4278,  4280,  4281,  4285,  4287,
    4289,  4291,  4293,  4295,  4297,  4299,  4301,  4303,  4305,  4307,
    4309,  4317,  4324,  4329,  4334,  4336,  4338,  4340,  4341,  4343,
    4346,  4348,  4350,  4352,  4354,  4358,  4361,  4363,  4365,  4368,
    4370,  4372,  4373,  4377,  4379,  4383,  4385,  4389,  4391,  4393,
    4400,  4401,  4405,  4407,  4411,  4412,  4414,  4419,  4425,  4428,
    4430,  4432,  4437,  4439,  4443,  4448,  4453,  4458,  4460,  4464,
    4466,  4468,  4470,  4473,  4475,  4477,  4479,  4484,  4485,  4487,
    4488,  4490,  4492,  4495,  4498,  4500,  4502,  4504,  4506,  4508,
    4513,  4515,  4519,  4521,  4523,  4525,  4528,  4530,  4532,  4535,
    4538,  4540,  4544,  4547,  4550,  4552,  4556,  4558,  4561,  4566,
    4568,  4571,  4575,  4577,  4581,  4586,  4587,  4589,  4590,  4592,
    4593,  4595,  4597,  4601,  4603,  4607,  4609,  4612,  4614,  4618,
    4621,  4624,  4625,  4628,  4630,  4632,  4638,  4642,  4648,  4652,
    4654,  4658,  4660,  4662,  4663,  4665,  4669,  4673,  4677,  4684,
    4689,  4694,  4699,  4704,  4710,  4712,  4714,  4716,  4718,  4720,
    4722,  4724,  4726,  4728,  4730,  4732,  4734,  4735,  4737,  4739,
    4741,  4743,  4745,  4747,  4749,  4754,  4755,  4757,  4762,  4764,
    4770,  4776,  4778,  4780,  4782,  4784,  4786,  4791,  4793,  4798,
    4805,  4810,  4812,  4817,  4819,  4827,  4829,  4831,  4833,  4838,
    4845,  4846,  4849,  4854,  4856,  4858,  4860,  4862,  4864,  4866,
    4868,  4872,  4874,  4876,  4880,  4886,  4890,  4896,  4904,  4908,
    4910,  4912,  4916,  4922,  4926,  4932,  4940,  4942,  4943,  4947,
    4953,  4955,  4958,  4961,  4966,  4970,  4972,  4974,  4976,  4978,
    4980,  4983,  4986,  4987,  4991,  4992,  4996,  4998,  5000,  5002,
    5004,  5006,  5008,  5010,  5015,  5017,  5019,  5021,  5023,  5025,
    5027,  5029,  5031,  5033,  5035,  5037,  5039,  5041,  5043,  5048,
    5050,  5054,  5056,  5060,  5061,  5069,  5070,  5079,  5080,  5087,
    5088,  5097,  5098,  5100,  5103,  5105,  5109,  5111,  5115,  5121,
    5123,  5125,  5127,  5129,  5131,  5132,  5133,  5143,  5149,  5151,
    5153,  5160,  5161,  5165,  5167,  5171,  5176,  5178,  5179,  5182,
    5187,  5194,  5195,  5197,  5199,  5201,  5203,  5207,  5209,  5212,
    5216,  5218,  5220,  5223,  5226,  5228,  5230,  5232,  5235,  5238,
    5241,  5244,  5249,  5253,  5256,  5260,  5264,  5268,  5270,  5272,
    5274,  5276,  5278,  5280,  5286,  5292,  5298,  5304,  5310,  5315,
    5320,  5324,  5329,  5331,  5333,  5335,  5339,  5341,  5347,  5355,
    5361,  5362,  5365,  5367,  5369,  5370,  5374,  5376,  5380,  5382,
    5384,  5386,  5387,  5391,  5393,  5395,  5397,  5399,  5404,  5411,
    5413,  5415,  5418,  5422,  5424,  5426,  5428,  5430,  5432,  5434,
    5436,  5438,  5444,  5450,  5455,  5461,  5463,  5468,  5470,  5472,
    5480,  5485,  5487,  5488,  5493,  5495,  5498,  5500,  5502,  5504,
    5505,  5509,  5510,  5514,  5515,  5516,  5523,  5524,  5527,  5530,
    5538,  5542,  5546,  5549,  5552,  5555,  5557,  5561,  5563,  5567,
    5569,  5573,  5575,  5579,  5581,  5583,  5585,  5588,  5591,  5593,
    5595,  5598,  5603,  5609,  5617,  5625,  5635,  5637,  5639,  5641,
    5643,  5645,  5647,  5651,  5654,  5658,  5662,  5666,  5672,  5678,
    5684,  5690,  5696,  5701,  5706,  5710,  5715,  5717,  5719,  5721,
    5723,  5727,  5728,  5734,  5736,  5740,  5744,  5748,  5750,  5752,
    5755,  5757,  5759,  5763,  5765,  5769,  5773,  5775,  5777,  5779,
    5783,  5786,  5790,  5797,  5799,  5803,  5805,  5807,  5808,  5809,
    5816,  5817,  5820,  5821,  5823,  5825,  5828,  5831,  5833,  5835,
    5840,  5844,  5846,  5849,  5855,  5858,  5861,  5867,  5868,  5871,
    5873,  5875,  5878,  5885,  5892,  5894,  5895,  5897,  5900,  5902,
    5905,  5906,  5909,  5911,  5913,  5915,  5917,  5919,  5921,  5923,
    5925,  5927,  5929,  5931,  5933,  5935,  5937,  5939,  5941,  5943,
    5945,  5947,  5949,  5951,  5953,  5955,  5957,  5959,  5961,  5963,
    5965,  5967,  5969,  5971,  5973,  5975,  5977,  5979,  5981,  5983,
    5985,  5987,  5989,  5991,  5993,  5995,  5997,  5999,  6001,  6003,
    6005,  6007,  6009,  6011,  6013,  6015,  6017,  6019,  6021,  6023,
    6025,  6027,  6029,  6031,  6033,  6035,  6037,  6039,  6041,  6043,
    6045,  6047,  6049,  6051,  6053,  6055,  6057,  6059,  6061,  6063,
    6065,  6067,  6069,  6071,  6073,  6075,  6077,  6079,  6081,  6083
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1100,     0,    -1,   253,    -1,   250,    -1,   184,   734,   479,
     647,   735,    -1,   195,    -1,  1165,    -1,    26,    -1,   736,
      -1,   735,     5,   736,    -1,  1007,    -1,   483,   737,   446,
      -1,   737,   738,   737,    -1,    26,    -1,   739,    26,    -1,
    1165,    -1,   947,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   741,
      -1,    -1,   328,   483,   742,   743,   446,    -1,   620,   483,
      26,     5,    26,   446,    -1,   744,    -1,   743,     5,   744,
      -1,   542,    -1,   583,    -1,   588,    -1,   558,    -1,   463,
      -1,   656,    -1,   580,    -1,   532,    -1,   469,    -1,   543,
      -1,   401,    -1,   584,    -1,   508,    -1,   388,    -1,   645,
      -1,   151,    -1,  1079,    -1,    -1,   746,    -1,    -1,   328,
     483,   747,   748,   446,    -1,   749,    -1,   748,     5,   749,
      -1,   744,    -1,   484,    -1,   654,    25,    -1,   256,   993,
      -1,   385,   993,    -1,   338,   993,    -1,   393,   993,    -1,
     347,   993,    -1,   313,   993,    -1,   586,   751,    -1,   936,
     400,  1165,    -1,    -1,   343,   483,   955,   446,   400,   752,
    1183,    -1,   159,   483,  1007,     5,    25,     5,    25,   446,
      -1,   460,   483,   999,   446,   400,  1165,    -1,  1304,    -1,
     246,   483,   955,   446,   400,  1165,    -1,    -1,    -1,  1165,
     641,  1007,   483,   753,   767,   446,   754,   765,    -1,    -1,
      -1,    -1,  1007,   483,   755,   767,   756,   446,   757,   765,
      -1,    -1,    -1,   526,  1512,   674,  1512,   483,   758,   767,
     759,   446,   765,    -1,    -1,    -1,  1007,   573,  1007,   483,
     760,   767,   761,   446,   765,    -1,    -1,    -1,    -1,   420,
     770,   641,   771,   511,   734,   479,   483,   762,   767,   763,
     446,   764,   766,    -1,    -1,   400,  1183,    -1,    -1,   400,
    1183,    -1,   217,    -1,    -1,   768,    -1,   769,    -1,   768,
       5,   769,    -1,   907,    -1,   535,    -1,    25,    -1,  1007,
      -1,  1007,    -1,  1007,   671,  1007,    -1,    -1,   587,   914,
     773,   776,   780,   777,    -1,    -1,   587,   774,   775,   778,
     777,    -1,   782,    -1,   775,   782,    -1,   784,    -1,   776,
     784,    -1,   415,    -1,    -1,    -1,   395,   779,  1587,    -1,
      -1,    -1,   395,   781,  1587,    -1,    -1,   630,   914,   783,
    1587,    -1,    -1,   630,   914,   785,  1587,    -1,   332,  1004,
      -1,   255,  1002,    -1,   137,  1002,    -1,   222,    -1,   239,
    1518,    -1,   546,  1001,    -1,    30,   788,    31,    -1,   789,
      -1,   791,    -1,   790,    -1,   789,   790,    -1,    29,    -1,
     792,    -1,   791,   792,    -1,    28,    -1,    -1,    -1,   376,
     794,   796,   795,   797,    -1,   439,  1165,   676,   798,  1051,
    1078,   740,    -1,  1165,   676,   798,  1051,   598,   955,  1078,
     740,    -1,    -1,   800,   245,    -1,   799,    -1,   798,     5,
     799,    -1,  1007,    -1,  1007,   671,  1007,    -1,  1007,   671,
      20,    -1,   801,    -1,   800,   801,    -1,    -1,   324,   807,
     802,  1587,    -1,    -1,   327,   808,   803,  1587,    -1,    -1,
    1081,   804,  1587,    -1,    -1,   220,   805,  1587,    -1,    -1,
     218,   806,  1587,    -1,  1011,    -1,   807,     5,  1011,    -1,
    1011,    -1,   808,     5,  1011,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,   149,    -1,   150,    -1,   483,   907,
     811,   446,    -1,    -1,     5,   858,   677,   861,    -1,   210,
      -1,   333,    -1,    -1,   814,    -1,   815,    -1,   814,   815,
      -1,    -1,    -1,   490,   816,   818,   817,  1273,    -1,   871,
      -1,   821,    -1,   818,     5,   821,    -1,    -1,   820,  1007,
      -1,   409,   819,   870,    25,    -1,   409,   819,   870,  1007,
      -1,   409,   819,   870,  1013,    -1,   409,   819,   870,    26,
      -1,   825,   843,    -1,    -1,   819,   409,   822,   823,    -1,
      26,    -1,    25,    -1,  1013,    -1,    19,    26,    -1,   819,
      -1,   824,    -1,   825,     5,   824,    -1,    -1,   373,    -1,
      -1,   721,    -1,   722,    -1,   723,    -1,    -1,   539,   511,
     835,   479,   829,   675,   843,    -1,    -1,    40,   827,   830,
     675,   843,    -1,    -1,   372,   826,   832,    26,   833,   356,
     511,   834,   479,   831,   675,   843,    -1,   483,    -1,   510,
      -1,   446,    -1,   478,    -1,    26,    -1,   836,     5,   836,
       5,   836,    -1,   836,     5,   836,    -1,   836,    -1,    26,
      -1,    -1,   516,   838,   818,   337,    -1,    -1,   314,   839,
     819,   671,    20,    -1,    -1,   390,   840,   819,   312,   483,
     841,   446,    -1,   842,    -1,   841,     5,   842,    -1,   819,
      -1,   845,    -1,    -1,   112,    -1,    -1,    -1,   846,   848,
     847,   844,    -1,   828,    -1,   837,    -1,   373,    -1,   374,
      -1,   373,   483,    26,   446,    -1,   374,   483,    26,   446,
      -1,   476,   483,    26,   446,    -1,   476,   483,    26,     5,
      26,   446,    -1,   375,   483,    26,   446,    -1,   375,   483,
      26,     5,    26,   446,    -1,   461,    -1,   668,   819,    -1,
     435,    -1,   561,    -1,   143,    -1,   451,    -1,   451,   483,
      26,   446,    -1,   451,   483,    26,     5,    26,   446,    -1,
     564,    -1,   564,   483,    26,   446,    -1,   564,   483,    26,
       5,    26,   446,    -1,    -1,   554,   849,   852,    -1,    -1,
     117,   850,   852,    -1,    -1,   353,   851,   852,    -1,   589,
      -1,   585,    -1,   133,    -1,   134,    -1,   626,    -1,   412,
     856,    -1,   424,   857,    -1,   853,    -1,    32,    -1,    -1,
     483,    26,   446,    -1,   608,   854,   671,   855,    -1,   819,
      -1,   819,    -1,    -1,   858,   677,   861,    -1,   866,   677,
     869,    -1,    -1,   859,   860,    -1,   633,    -1,   565,    -1,
     642,    -1,   604,    -1,   506,    -1,   522,    -1,   421,   863,
      -1,    -1,   862,   860,    -1,    -1,   483,   865,   446,    -1,
      -1,   483,    26,   446,    -1,    26,    -1,    -1,   867,   868,
     864,    -1,   633,    -1,   565,    -1,   642,    -1,   604,    -1,
     506,    -1,   522,    -1,   421,   863,    -1,   868,    -1,    -1,
      14,    -1,    -1,   290,  1007,   872,   668,   873,    -1,   875,
      -1,   878,    -1,   373,    -1,   373,   483,    26,   446,    -1,
     476,   483,    26,   446,    -1,   476,   483,    26,     5,    26,
     446,    -1,   461,    -1,   435,    -1,   561,    -1,   451,    -1,
     451,   483,    26,   446,    -1,   451,   483,    26,     5,    26,
     446,    -1,   564,    -1,   564,   483,    26,   446,    -1,   564,
     483,    26,     5,    26,   446,    -1,   554,    -1,   353,    -1,
     589,    -1,   585,    -1,   626,    -1,   412,   856,    -1,   424,
     857,    -1,   874,    -1,   608,   854,   671,   855,    -1,    -1,
     539,   511,   835,   479,   876,   675,   873,    -1,    -1,   372,
     826,   832,    26,   833,   356,   511,   834,   479,   877,   675,
     873,    -1,    -1,   516,   879,   881,   337,    -1,    -1,   314,
     880,  1007,   671,    20,    -1,   882,    -1,   881,     5,   882,
      -1,   883,   873,    -1,   884,    -1,   883,     5,   884,    -1,
    1007,    -1,    -1,   669,   997,    -1,   124,  1007,    -1,   122,
      -1,   677,   955,    -1,   677,   561,  1007,   710,   955,    -1,
     677,   561,  1007,   444,    -1,   126,  1007,    -1,   211,   930,
    1183,   893,    -1,   454,   930,   912,   885,   893,    -1,   264,
    1004,   893,    -1,    -1,    -1,   242,   890,  1190,   677,  1007,
     671,    20,   892,   740,   891,   894,    -1,    -1,   520,   998,
      -1,   740,    -1,    -1,   895,   292,    -1,   292,    -1,   896,
      -1,   895,   896,    -1,    -1,   407,   897,  1587,    -1,    -1,
     403,   898,  1587,    -1,    -1,  1081,   899,  1587,    -1,    42,
    1165,    -1,    43,  1165,    -1,    41,  1165,    -1,   550,   930,
     913,   740,    -1,   550,   930,   913,   740,   119,    -1,   268,
      -1,   268,   914,    -1,   340,    -1,   339,    -1,   267,    -1,
     419,    -1,   227,    -1,   266,    -1,   384,    -1,   383,    -1,
     297,    -1,   224,    -1,   223,    -1,   201,    -1,   257,    -1,
     185,    -1,   200,    -1,   241,    -1,   208,    -1,   915,    -1,
     919,    -1,   947,    -1,   907,   908,    -1,   948,    -1,   950,
      -1,   916,    -1,    19,   907,    -1,    18,   907,    -1,   921,
      -1,   929,    -1,   923,    -1,   527,    -1,   809,    -1,   924,
      -1,   925,    -1,   926,    -1,   927,    -1,   928,    -1,    48,
     907,    -1,   930,    -1,   930,   911,    -1,   914,    -1,   535,
      -1,   910,    -1,   911,     5,   910,    -1,   914,    -1,   912,
       5,   914,    -1,   914,    -1,   913,     5,   914,    -1,   907,
      -1,     9,   907,    -1,   536,    -1,   480,    -1,   483,   907,
     446,    -1,   495,   483,  1492,   446,    -1,   348,   483,  1492,
     446,    -1,    25,    -1,  1013,    -1,    26,    -1,   918,    -1,
    1165,    -1,  1165,   473,  1165,    -1,   917,    -1,   486,   907,
      -1,   447,   907,    -1,  1276,    -1,    -1,   559,   920,  1276,
      -1,     7,   907,    -1,     6,   907,    -1,   907,    -1,   922,
       5,   907,    -1,   674,   483,  1492,   446,    -1,   481,   483,
    1492,   446,    -1,   674,   483,   930,   922,   446,    -1,   481,
     483,   930,   922,   446,    -1,   441,    -1,   303,    -1,    10,
     907,    -1,   306,   907,    -1,    10,   907,   494,    25,    -1,
     306,   907,   494,    25,    -1,   608,   907,    -1,   426,   907,
      -1,   608,   907,   494,    25,    -1,   426,   907,   494,    25,
      -1,   445,    -1,     8,   907,    -1,    18,   907,    -1,    19,
     907,    -1,    20,   907,    -1,    21,   907,    -1,    22,   907,
      -1,    11,   907,    -1,    14,   907,    -1,   509,   907,    -1,
      12,   907,    -1,    13,   907,    -1,    17,   907,    -1,    16,
     907,    -1,    15,   907,    -1,    -1,    -1,    -1,  1007,   483,
     932,   767,   933,   446,    -1,    -1,    -1,  1007,   573,  1007,
     483,   934,   767,   935,   446,    -1,    -1,    -1,   589,   483,
     937,   907,   938,   446,    -1,    -1,    -1,   565,   483,   939,
     907,   940,   446,    -1,    -1,    -1,   642,   483,   941,   907,
     942,   446,    -1,    -1,    -1,   633,   483,   943,   907,   944,
     446,    -1,   424,   483,   951,   446,   946,    -1,   412,   483,
      25,   446,   945,    -1,   412,   483,    26,   446,   945,    -1,
     412,   483,    24,   446,   945,    -1,   412,   483,    26,   641,
      26,   446,   945,    -1,   412,   483,    26,   641,    24,   446,
     945,    -1,   412,   483,    26,   641,    26,   641,    26,   446,
     945,    -1,   412,   483,    26,   641,    26,   641,    24,   446,
     945,    -1,   412,   483,    26,    26,   446,   945,    -1,   412,
     483,    26,    26,   641,    26,   446,   945,    -1,   412,   483,
      26,    26,   641,    26,   641,    26,   446,   945,    -1,   412,
     483,    26,    26,   641,    26,   641,    24,   446,   945,    -1,
     412,   483,    26,    19,    26,   446,   945,    -1,   412,   483,
      26,    19,    26,    19,    26,   446,   945,    -1,   412,   483,
      26,    19,    26,    26,   446,   945,    -1,   412,   483,    26,
      19,    26,    19,    26,    26,   446,   945,    -1,   412,   483,
      26,    19,    26,    19,    26,    26,   641,    26,   446,   945,
      -1,   412,   483,    26,    19,    26,    19,    26,    26,   641,
      26,   641,    26,   446,   945,    -1,   412,   483,    26,    19,
      26,    19,    26,    26,   641,    26,   641,    24,   446,   945,
      -1,   412,   483,    26,    19,    26,    26,   641,    26,   446,
     945,    -1,   412,   483,    26,    19,    26,    26,   641,    26,
     641,    26,   446,   945,    -1,   412,   483,    26,    19,    26,
      26,   641,    26,   641,    24,   446,   945,    -1,    38,   483,
    1165,   446,    -1,   726,   483,  1165,   446,    -1,   727,   483,
    1165,     5,    26,   446,    -1,    -1,   860,   677,   860,    -1,
     857,    -1,   936,    -1,   343,   483,   955,   446,    -1,   152,
     483,   998,   446,    -1,   125,   483,   998,   446,    -1,   460,
     483,   956,   446,    -1,   246,   483,   955,   446,    -1,   113,
     483,   955,   446,    -1,   949,    -1,   931,    -1,  1469,    -1,
     589,    -1,   475,   483,   907,   446,    -1,   378,   483,   907,
     446,    -1,   540,   907,    -1,   496,   810,    -1,   907,   163,
      -1,   907,   164,    -1,   907,   165,    -1,    25,    -1,   952,
      -1,    19,   952,    -1,   954,    -1,   953,    -1,    26,    -1,
      26,    26,    -1,    26,    26,   641,    26,    -1,    26,    26,
     641,    26,   641,    26,    -1,    26,    26,   641,    26,   641,
      24,    -1,    26,   641,    26,    -1,    26,   641,    26,   641,
      26,    -1,    26,   641,    26,   641,    24,    -1,    26,   641,
      24,    -1,    24,    -1,    26,    -1,    26,    19,    26,    -1,
     998,    -1,   955,     5,   998,    -1,   999,    -1,   956,     5,
     999,    -1,    -1,    -1,    -1,   457,   958,  1001,   959,   961,
    1371,   960,  1587,   294,    -1,    -1,     8,   930,   912,    -1,
      -1,    -1,   689,  1007,   963,   813,   964,  1110,   966,   965,
     971,   690,    -1,    -1,   976,    -1,    -1,   967,    -1,   968,
      -1,   967,   968,    -1,    -1,   691,   969,  1587,    -1,    -1,
     692,   970,  1587,    -1,    -1,   972,    -1,   973,    -1,   972,
     973,    -1,    -1,   693,   974,  1587,    -1,    -1,   694,   975,
    1587,    -1,   977,   981,   380,    -1,   144,    -1,   144,   978,
     598,   979,    -1,   144,   439,   980,    -1,  1165,    -1,   978,
       5,  1165,    -1,  1007,    -1,   979,     5,  1007,    -1,  1165,
      -1,   980,     5,  1165,    -1,   982,    -1,   981,   982,    -1,
      -1,   695,   983,  1587,    -1,    -1,   696,   984,  1587,    -1,
      -1,   715,   979,   985,  1587,    -1,    -1,   533,   979,   986,
    1587,    -1,    -1,   676,   979,   987,  1587,    -1,    -1,    -1,
     647,  1165,    14,   914,   677,   914,   991,   989,  1587,   990,
     295,    -1,    -1,   623,   914,    -1,   597,  1000,    -1,   606,
      19,    26,    -1,   606,    -1,   553,    18,    26,    -1,   553,
      -1,    26,    -1,  1165,    -1,   720,    -1,    25,    -1,  1012,
      -1,   914,    -1,   995,     5,   995,    -1,   996,    -1,  1007,
      -1,   718,   483,  1007,   446,    -1,  1007,   671,   718,   483,
    1007,   446,    -1,  1007,   511,   737,   479,    -1,  1007,   671,
      20,    -1,  1007,   511,   737,   479,   671,    20,    -1,  1007,
     671,  1007,    -1,  1007,   511,   737,   479,   671,  1007,    -1,
     998,    -1,    25,    -1,  1008,    -1,  1008,    -1,  1008,    -1,
    1008,    -1,  1008,    -1,  1008,    -1,    -1,   602,    26,    -1,
    1586,    -1,  1009,    -1,  1586,    -1,   405,   483,  1010,   446,
      -1,  1168,    -1,    25,    -1,  1007,    -1,  1007,   511,   737,
     479,    -1,  1007,   671,    20,    -1,  1007,   511,   737,   479,
     671,    20,    -1,  1007,   671,  1007,    -1,  1007,   511,   737,
     479,   671,  1007,    -1,  1165,    -1,    24,    -1,   671,    26,
      -1,   599,  1015,    -1,  1007,    -1,   641,  1007,    -1,   703,
    1017,    -1,  1018,    -1,  1017,     5,  1018,    -1,  1007,    -1,
     714,  1017,    -1,   705,  1017,    -1,   706,   955,    -1,   704,
    1004,   710,   955,    -1,   708,  1017,    -1,   709,   955,    -1,
     707,  1004,   710,   955,    -1,    -1,   712,  1023,   912,  1028,
    1030,  1032,  1024,  1026,    -1,    -1,  1025,    -1,   700,    -1,
     701,    -1,    -1,  1027,    -1,   400,  1165,    -1,    -1,  1029,
      -1,   444,   912,    -1,    -1,  1031,    -1,   711,    26,    -1,
      -1,  1033,    -1,   702,    26,  1034,    -1,    -1,   453,    26,
      -1,    -1,    -1,   673,   914,   627,  1036,  1587,  1037,  1038,
     493,    -1,    -1,    -1,   594,  1039,  1587,    -1,    -1,    -1,
     116,  1040,   914,   627,  1041,  1587,  1038,    -1,   161,  1007,
     483,    26,   446,    -1,   107,  1007,    -1,    39,  1007,    -1,
     129,  1007,    -1,    -1,   344,  1194,  1046,   677,   535,    -1,
     344,  1194,   608,  1047,    -1,  1048,    -1,  1047,     5,  1048,
      -1,  1049,   671,  1465,    -1,  1049,   671,    20,    -1,  1461,
      -1,    -1,  1052,   380,    -1,   380,    -1,    -1,   205,    -1,
    1053,    -1,  1052,  1053,    -1,    -1,   324,  1067,  1054,  1587,
      -1,    -1,   327,  1068,  1055,  1587,    -1,    -1,   407,  1056,
    1587,    -1,    -1,   403,  1057,  1587,    -1,    -1,  1081,  1058,
    1587,    -1,    -1,   359,  1059,  1587,    -1,    -1,   329,  1060,
    1587,    -1,    -1,    49,  1061,  1587,    -1,    -1,    46,  1062,
    1587,    -1,    -1,    45,  1063,  1587,    -1,    -1,    44,  1064,
    1587,    -1,    -1,    52,  1065,  1587,    -1,    -1,    51,  1066,
    1587,    -1,   998,    -1,  1067,     5,   998,    -1,   998,    -1,
    1068,     5,   998,    -1,   368,  1071,    -1,   369,  1007,   710,
    1071,    -1,   613,    -1,   430,    -1,   998,    -1,    -1,   716,
    1074,  1073,  1050,    -1,   439,  1183,  1051,  1006,   740,    -1,
    1183,  1051,   598,   955,  1006,   740,    -1,    -1,   539,  1190,
    1051,   598,  1007,   671,    20,  1006,  1075,   740,    -1,   521,
     955,  1077,    -1,   135,    26,    -1,   136,    26,    -1,   678,
      -1,   591,    -1,   135,  1165,    -1,   136,  1165,    -1,    -1,
     602,    26,    -1,  1080,    -1,    58,    25,    -1,   548,    14,
      26,    -1,   548,    14,  1165,    -1,    59,    14,    26,    -1,
      59,    14,  1165,    -1,    55,    -1,    57,    -1,    54,    -1,
      56,    -1,    -1,   482,  1082,  1087,    -1,   349,    -1,    -1,
     648,  1084,  1087,    -1,   357,  1089,    -1,   648,  1087,    -1,
    1089,    -1,   483,  1088,   446,    -1,  1089,    -1,  1088,     5,
    1089,    -1,  1090,    -1,   646,    -1,   366,    -1,   386,    -1,
     358,    -1,   537,    -1,   494,    -1,   678,    -1,   602,    -1,
     591,    -1,   231,    -1,   491,    -1,   502,    -1,   592,    -1,
     607,    -1,   572,    -1,   364,    -1,   365,    -1,    25,    -1,
     562,    -1,    -1,    -1,   650,  1093,  1188,  1094,    14,   930,
    1095,    -1,   535,    -1,   913,    -1,   273,  1165,    -1,   263,
    1165,    -1,   276,  1165,    -1,   503,  1186,   389,    -1,   503,
    1186,   440,   994,    -1,    -1,  1102,  1101,  1105,    -1,    -1,
    1103,    -1,  1104,    -1,  1103,  1104,    -1,  1044,    -1,  1109,
      -1,  1571,    -1,  1043,    -1,  1125,    -1,  1111,    -1,  1124,
      -1,    -1,  1106,    -1,  1108,    -1,  1106,  1108,    -1,   120,
    1007,    -1,  1113,    -1,  1119,    -1,  1131,    -1,  1286,    -1,
    1296,    -1,  1135,    -1,   962,    -1,   787,    -1,  1042,    -1,
    1571,    -1,   787,    -1,    -1,   787,    -1,   814,    -1,   422,
      -1,   114,    -1,    -1,    -1,    -1,    -1,  1112,  1114,  1007,
     483,  1115,  1181,   446,  1116,   813,  1117,  1110,  1587,  1118,
      -1,   265,    -1,    -1,    -1,   609,  1120,   813,  1121,  1587,
     416,    -1,   231,   909,    -1,   930,    -1,   930,   912,    -1,
     411,  1476,    -1,   519,  1476,    -1,  1126,    -1,  1127,    -1,
    1126,  1127,    -1,  1128,    -1,    -1,   459,  1129,  1130,    -1,
     813,   296,    -1,   994,    -1,  1109,    -1,  1124,    -1,    -1,
      -1,    -1,   168,  1007,   167,  1007,   483,  1132,  1181,   446,
    1133,   813,  1134,  1110,  1587,  1118,    -1,    -1,    -1,   697,
    1007,  1136,   813,  1137,  1138,   698,    -1,  1139,    -1,  1138,
    1139,    -1,    -1,   699,  1140,  1587,    -1,    -1,   676,  1007,
    1141,  1587,    -1,    -1,   610,  1143,  1158,  1149,  1144,    -1,
     417,    -1,    -1,   288,  1146,  1587,    -1,    -1,    23,  1150,
    1151,  1152,  1006,  1147,  1587,    -1,    -1,    23,  1150,  1006,
    1148,  1587,    -1,  1145,    -1,  1149,  1145,    -1,    -1,  1083,
      -1,    25,    -1,  1165,    -1,    -1,  1165,    -1,    25,    -1,
     305,  1156,    -1,   317,  1157,    -1,   300,  1157,    -1,   637,
      -1,    25,    -1,  1165,    -1,  1156,    -1,  1157,     5,  1156,
      -1,  1165,    -1,    25,    -1,  1162,  1160,    -1,    -1,   741,
    1163,    -1,  1164,    -1,  1161,    -1,  1029,    -1,  1031,    -1,
    1033,    -1,  1025,    -1,  1027,    -1,   425,   930,   912,    -1,
      -1,   119,    -1,   119,    -1,  1166,    -1,  1168,    -1,   244,
    1168,    -1,  1168,   671,    -1,  1167,  1172,    -1,  1167,  1007,
     511,  1175,   479,    -1,  1167,  1007,   511,  1175,   479,   511,
    1175,   479,    -1,  1173,    -1,  1007,    -1,  1169,    -1,  1007,
     510,  1171,   478,    -1,  1007,   510,  1171,   478,    -1,  1165,
      -1,    25,    -1,    20,    -1,  1007,    -1,  1007,  1174,    -1,
     511,  1175,   479,    -1,   511,  1175,   479,   511,  1175,   479,
      -1,  1176,    -1,  1175,     5,  1176,    -1,   737,    -1,  1178,
      -1,  1180,    -1,  1178,   671,  1179,    -1,  1178,   671,  1007,
     511,  1175,   479,    -1,  1178,   671,  1007,   511,  1175,   479,
     511,  1175,   479,    -1,  1007,    -1,  1170,    -1,    20,    -1,
    1007,    -1,  1007,  1174,    -1,    -1,  1182,    -1,  1184,    -1,
    1182,     5,  1184,    -1,  1185,    -1,  1183,     5,  1185,    -1,
    1007,    -1,  1007,   671,  1007,    -1,  1165,    -1,  1165,   473,
    1165,    -1,    25,    -1,  1013,    -1,    26,    -1,  1187,    -1,
    1186,     5,  1187,    -1,  1165,    -1,  1165,   473,  1165,    -1,
    1189,    -1,  1188,     5,  1189,    -1,  1177,    -1,  1165,    -1,
    1192,    -1,  1191,     5,  1192,    -1,  1165,  1193,    -1,    -1,
     639,    -1,   590,    -1,  1195,    -1,  1194,     5,  1195,    -1,
    1165,    -1,  1165,   473,  1165,    -1,   308,  1003,   669,   996,
     631,  1579,   745,    -1,    -1,   669,   483,   914,     5,   914,
     446,  1198,    -1,    -1,   620,   483,   914,     5,   914,   446,
      -1,   309,  1007,  1197,    -1,  1007,    -1,   394,  1005,  1202,
      -1,  1203,    -1,   598,   914,    -1,  1204,  1205,  1210,     8,
    1200,    -1,    -1,   669,  1206,   483,   914,     5,   914,   446,
      -1,    -1,   608,  1008,    -1,    -1,   406,    -1,   271,  1518,
     320,  1560,  1209,    -1,   615,  1000,    -1,   615,  1000,     8,
     930,   912,    -1,    -1,   668,   628,  1512,   429,  1512,    -1,
     668,   628,  1512,     5,   429,  1512,    -1,   668,  1512,     5,
    1512,    -1,    -1,   700,    -1,   701,    -1,   448,   677,  1560,
    1212,  1213,    -1,    -1,   668,  1560,    -1,    -1,   668,   628,
    1512,     8,  1512,    -1,   628,  1512,     8,  1512,    -1,   464,
    1215,    -1,  1216,    -1,  1215,     5,  1216,    -1,   256,   993,
      -1,   338,   993,    -1,   385,   993,    -1,   393,   993,    -1,
     347,   993,    -1,   313,   993,    -1,  1085,    -1,   491,  1086,
      -1,   502,  1086,    -1,   613,  1086,    -1,   430,  1086,    -1,
     602,  1086,    -1,   600,   994,    -1,   601,   994,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,   454,   741,    -1,
     716,   741,    -1,   345,    -1,   249,    -1,   206,    -1,   186,
      -1,   203,    -1,   194,    -1,  1517,   466,  1220,   598,  1218,
      -1,  1165,    -1,    25,    -1,   456,  1220,    -1,   456,  1220,
       8,  1183,    -1,   456,  1220,   605,  1186,    -1,   456,  1220,
     605,  1186,     8,  1183,    -1,    53,  1218,    -1,  1008,    -1,
      -1,   514,  1230,   740,   647,  1225,  1165,  1223,  1006,   740,
    1222,  1226,    -1,    -1,   719,    26,    -1,   514,  1230,   740,
     400,  1165,    -1,    -1,   373,    -1,    -1,  1227,   336,    -1,
    1228,    -1,  1227,  1228,    -1,    -1,  1081,  1229,  1587,    -1,
     913,    -1,    -1,   655,  1000,  1232,  1233,    -1,    -1,   598,
    1234,    -1,  1235,    -1,  1234,     5,  1235,    -1,  1504,    -1,
     535,    -1,   274,  1239,   142,  1237,    -1,   274,  1239,   677,
    1238,  1237,    -1,   274,  1239,   141,  1238,  1237,    -1,   274,
    1239,  1237,    -1,    -1,    47,    -1,    25,    -1,  1012,    -1,
    1007,    -1,    -1,   531,    -1,   202,  1239,  1240,   483,   930,
    1123,   446,    -1,   247,  1239,    -1,   121,  1239,    -1,  1277,
    1285,    -1,   499,   115,    -1,   499,  1246,    -1,  1247,    -1,
    1246,  1247,    -1,    -1,   190,  1248,  1587,    -1,    -1,   252,
    1249,  1587,    -1,    -1,   282,  1250,  1587,    -1,    -1,   270,
    1251,  1587,    -1,    -1,   307,  1252,  1587,    -1,    -1,   254,
    1165,  1253,  1587,    -1,    -1,   278,  1165,  1254,  1587,    -1,
    1265,    -1,  1269,    -1,  1268,    -1,  1256,    -1,  1294,    -1,
    1259,    -1,    -1,   612,   914,  1257,   534,    -1,    -1,   534,
      -1,    -1,   621,    26,  1260,  1258,    -1,   213,    -1,   680,
    1281,    -1,   216,  1281,    -1,   215,  1281,    -1,    -1,  1262,
      -1,  1263,    -1,  1262,  1263,    -1,  1274,  1264,    -1,    -1,
     669,  1281,    -1,    -1,   571,  1266,  1261,  1273,    -1,  1512,
      -1,   483,  1512,   446,    -1,   570,  1267,  1273,    -1,   569,
    1272,  1271,  1270,  1273,    -1,    -1,   207,   907,    -1,   207,
     907,     5,   907,    -1,   664,    -1,   665,    -1,   666,    -1,
     667,    -1,  1165,    -1,    -1,   574,    -1,  1275,    -1,  1274,
       5,  1275,    -1,   914,  1308,    -1,   660,   483,   907,   446,
    1293,    -1,   118,  1293,    -1,   548,   483,    20,   446,  1293,
      -1,   465,   483,    20,   446,  1293,    -1,   442,   483,   907,
     446,  1293,    -1,   640,   483,   907,   446,  1293,    -1,   653,
     483,   907,   446,  1293,    -1,   652,   483,   907,   446,  1293,
      -1,    -1,   513,  1278,    -1,  1279,    -1,  1278,  1279,    -1,
     281,    26,    -1,   272,    26,    -1,   355,    26,    -1,   238,
      26,    -1,   310,    26,    -1,   229,    -1,   399,    25,    -1,
     399,  1165,    -1,   230,    25,    -1,   214,    25,    -1,  1284,
      -1,  1280,  1284,    -1,  1282,   163,    -1,  1282,   165,    -1,
    1282,   164,    -1,  1282,    -1,  1013,    -1,    26,    -1,    -1,
     513,  1280,    -1,   281,  1281,    -1,   272,  1281,    -1,   355,
    1281,    -1,   238,  1281,    -1,   310,  1281,    -1,   311,  1281,
      -1,   679,    25,    -1,   680,  1281,    -1,   684,    -1,   681,
      -1,   682,    -1,   683,    -1,   688,    -1,   685,    -1,   686,
      -1,   687,    -1,   130,  1281,    -1,   131,  1281,    -1,   132,
    1281,    -1,   399,    25,    -1,   230,    25,    -1,   453,    -1,
     127,    -1,   128,    -1,    -1,   566,   670,  1191,    -1,   191,
    1191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,  1287,
    1007,   483,  1288,  1181,   446,  1289,   813,  1290,  1244,  1291,
    1245,  1292,   293,    -1,    -1,   578,   907,    -1,   568,  1295,
      -1,    -1,  1218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,  1297,  1007,   483,  1298,  1181,   446,  1299,   813,  1300,
    1303,  1301,  1245,  1302,   293,    -1,  1283,  1285,    -1,    -1,
      -1,    -1,   209,   483,    25,     5,  1305,   767,  1306,   446,
    1307,   765,    -1,    -1,   438,    -1,   438,   272,    26,    -1,
     438,   272,  1165,    -1,   658,   914,    -1,   658,   914,   400,
    1165,    -1,   658,   914,   217,    -1,   658,   914,   629,    -1,
     658,   914,   596,    -1,  1311,    -1,   226,  1461,    -1,   379,
    1461,    -1,   335,  1462,    -1,    50,  1007,    -1,  1325,    -1,
    1313,    -1,    -1,    -1,   259,  1314,  1461,   483,  1315,  1329,
     446,  1318,    -1,    -1,    -1,   188,  1316,  1461,   483,  1317,
    1329,   446,  1318,  1326,    -1,    -1,  1319,    -1,  1320,    -1,
    1319,  1320,    -1,   674,  1321,    -1,   298,    26,    -1,    62,
      26,    -1,   139,    -1,   140,    -1,  1586,    -1,    -1,  1323,
      -1,  1324,    -1,  1323,  1324,    -1,   674,  1321,    -1,   728,
      26,    -1,   158,  1462,   676,  1461,   483,  1327,   446,  1322,
      -1,   105,  1008,    -1,   106,  1008,    -1,   225,  1461,   647,
    1461,    -1,   110,  1461,    -1,    -1,   322,    -1,  1328,    -1,
    1327,     5,  1328,    -1,  1007,   639,    -1,  1007,   590,    -1,
    1007,    -1,  1330,    -1,  1329,     5,  1330,    -1,  1413,    -1,
    1411,    -1,   175,  1007,    -1,   233,    -1,    60,  1007,  1333,
      -1,    61,  1462,   155,    -1,    61,  1462,   156,    -1,  1334,
      -1,  1333,     5,  1334,    -1,  1335,    -1,  1338,    -1,  1341,
      -1,  1346,    -1,  1349,    -1,  1345,    -1,  1344,    -1,   636,
    1336,    -1,   636,   483,  1337,   446,    -1,  1330,    -1,  1330,
     715,  1007,    -1,  1336,    -1,  1337,     5,  1336,    -1,   593,
    1340,    -1,   593,   483,  1339,   446,    -1,  1340,    -1,  1339,
       5,  1340,    -1,  1007,    -1,   507,  1343,    -1,   507,   483,
    1342,   446,    -1,  1343,    -1,  1342,     5,  1343,    -1,  1330,
      -1,   139,    -1,   140,    -1,   138,    26,    -1,   108,  1411,
    1348,    -1,   108,   483,  1347,   446,    -1,  1411,  1348,    -1,
    1347,     5,  1411,  1348,    -1,    -1,   111,  1007,    -1,   109,
    1350,    -1,   109,   483,  1350,   446,    -1,  1351,    -1,  1350,
       5,  1351,    -1,  1007,    -1,   319,    -1,   285,    -1,   219,
    1354,    -1,   198,    -1,   187,    -1,   174,    -1,   172,    -1,
     176,    -1,   232,  1518,    -1,   284,  1353,   512,  1512,   677,
    1512,    -1,   352,  1000,   512,  1512,   677,  1512,    -1,    -1,
    1518,    -1,    -1,   914,    -1,   575,   914,    -1,   283,    -1,
      -1,   302,  1358,  1461,  1361,  1359,    -1,    -1,   531,  1360,
     483,  1363,   446,    -1,  1498,    -1,    -1,   483,  1362,   446,
      -1,  1465,    -1,  1362,     5,  1465,    -1,  1364,    -1,  1363,
       5,  1364,    -1,  1504,    -1,   535,    -1,    -1,   552,  1366,
    1368,  1369,    -1,  1008,    -1,  1373,  1001,    -1,  1001,    -1,
      -1,    -1,   605,  1370,  1186,    -1,    -1,    -1,   605,  1372,
    1186,    -1,   553,    -1,   606,    -1,   613,    -1,   430,    -1,
     397,    -1,   449,    -1,   433,   914,    -1,   406,   914,    -1,
     291,  1461,   204,  1001,    -1,   291,  1461,  1434,    -1,   566,
     670,  1377,    -1,  1378,    -1,  1377,     5,  1378,    -1,  1379,
    1380,    -1,    26,    -1,  1465,    -1,    -1,   639,    -1,   590,
      -1,   330,    -1,   363,    -1,    -1,   382,    -1,   411,  1385,
    1383,    -1,  1560,    -1,  1560,   663,  1007,    -1,    25,    -1,
      -1,  1517,  1387,  1388,    -1,  1419,    -1,  1423,    -1,  1382,
      -1,  1519,    -1,  1381,    -1,  1374,    -1,  1375,    -1,  1365,
      -1,  1357,    -1,  1356,    -1,  1488,    -1,  1540,    -1,   557,
    1392,   676,  1461,   677,  1397,  1391,    -1,   518,  1392,   676,
    1461,   598,  1397,    -1,   557,  1390,   677,  1397,    -1,   518,
    1390,   598,  1397,    -1,   448,    -1,   434,    -1,   643,    -1,
      -1,   197,    -1,   668,  1007,    -1,   221,    -1,   637,    -1,
    1393,    -1,  1394,    -1,  1393,     5,  1394,    -1,   523,  1395,
      -1,   502,    -1,   491,    -1,   530,  1395,    -1,   538,    -1,
     560,    -1,    -1,   483,  1396,   446,    -1,  1465,    -1,  1396,
       5,  1465,    -1,  1398,    -1,  1397,     5,  1398,    -1,   515,
      -1,  1463,    -1,   289,  1461,  1400,   668,  1498,  1402,    -1,
      -1,   483,  1401,   446,    -1,  1465,    -1,  1401,     5,  1465,
      -1,    -1,   196,    -1,   544,   483,  1437,   446,    -1,   299,
     483,  1406,   446,  1405,    -1,   350,  1407,    -1,  1408,    -1,
    1461,    -1,  1461,   483,  1408,   446,    -1,  1465,    -1,  1408,
       5,  1465,    -1,   528,   483,  1410,   446,    -1,   414,   483,
    1410,   446,    -1,   312,   483,  1410,   446,    -1,  1465,    -1,
    1410,     5,  1465,    -1,  1409,    -1,  1404,    -1,  1403,    -1,
     453,  1468,    -1,   262,    -1,   261,    -1,   260,    -1,  1007,
    1453,  1414,  1415,    -1,    -1,  1412,    -1,    -1,  1416,    -1,
    1417,    -1,  1416,  1417,    -1,  1418,  1348,    -1,   428,    -1,
     212,    -1,   528,    -1,   414,    -1,  1405,    -1,   544,   483,
    1437,   446,    -1,   312,    -1,   173,  1420,  1422,    -1,  1421,
      -1,  1463,    -1,  1423,    -1,  1422,  1423,    -1,  1399,    -1,
    1389,    -1,   500,  1437,    -1,   423,  1426,    -1,  1503,    -1,
    1426,     5,  1503,    -1,   578,  1437,    -1,   598,  1429,    -1,
    1430,    -1,  1429,     5,  1430,    -1,  1431,    -1,   567,  1431,
      -1,   567,   483,  1432,   446,    -1,  1461,    -1,  1461,  1467,
      -1,  1461,   668,  1467,    -1,  1430,    -1,  1432,     5,  1430,
      -1,  1428,  1434,  1435,  1436,    -1,    -1,  1427,    -1,    -1,
    1425,    -1,    -1,  1424,    -1,  1438,    -1,  1437,     6,  1438,
      -1,  1439,    -1,  1438,     7,  1439,    -1,  1440,    -1,     9,
    1440,    -1,  1451,    -1,   483,  1437,   446,    -1,   495,  1499,
      -1,   348,  1499,    -1,    -1,   494,  1444,    -1,  1505,    -1,
    1508,    -1,  1504,   674,   483,  1446,   446,    -1,  1504,   674,
    1499,    -1,  1504,   481,   483,  1446,   446,    -1,  1504,   481,
    1499,    -1,  1447,    -1,  1446,     5,  1447,    -1,  1566,    -1,
    1468,    -1,    -1,     9,    -1,  1504,  1448,   441,    -1,  1504,
    1448,   303,    -1,  1504,  1450,  1504,    -1,  1504,  1448,   443,
    1504,     7,  1504,    -1,  1504,   608,  1443,  1442,    -1,  1504,
     426,  1443,  1442,    -1,  1504,   725,  1443,  1442,    -1,  1504,
     427,  1443,  1442,    -1,  1504,  1448,    10,  1443,  1442,    -1,
      14,    -1,    17,    -1,    12,    -1,    13,    -1,   306,    -1,
      10,    -1,   724,    -1,    16,    -1,    15,    -1,  1449,    -1,
    1445,    -1,  1441,    -1,    -1,   637,    -1,   414,    -1,   528,
      -1,  1454,    -1,  1455,    -1,  1457,    -1,   373,    -1,   373,
     483,  1458,   446,    -1,    -1,   524,    -1,   524,   483,    26,
     446,    -1,   451,    -1,   451,   483,  1459,  1456,   446,    -1,
     564,   483,  1459,  1456,   446,    -1,   564,    -1,   589,    -1,
     461,    -1,   435,    -1,   374,    -1,   374,   483,  1458,   446,
      -1,   375,    -1,   375,   483,    26,   446,    -1,   375,   483,
      26,     5,    26,   446,    -1,   412,  1474,   677,  1475,    -1,
     412,    -1,   424,  1474,   677,  1475,    -1,   424,    -1,   424,
    1474,   483,    26,   446,   677,  1475,    -1,   626,    -1,   585,
      -1,   476,    -1,   476,   483,    26,   446,    -1,   476,   483,
      26,     5,    26,   446,    -1,    -1,     5,  1460,    -1,   554,
     483,  1459,   446,    -1,   617,    -1,   353,    -1,   554,    -1,
     117,    -1,    26,    -1,    26,    -1,    26,    -1,    25,   671,
    1007,    -1,    25,    -1,  1007,    -1,  1007,   641,  1007,    -1,
    1007,   641,    25,   671,  1007,    -1,  1007,   663,  1007,    -1,
    1007,   663,  1007,   641,  1007,    -1,  1007,   663,  1007,   641,
      25,   671,  1007,    -1,    25,   671,  1007,    -1,    25,    -1,
    1007,    -1,  1007,   641,  1007,    -1,  1007,   641,    25,   671,
    1007,    -1,  1007,   663,  1007,    -1,  1007,   663,  1007,   641,
    1007,    -1,  1007,   663,  1007,   641,    25,   671,  1007,    -1,
    1007,    -1,    -1,   511,    26,   479,    -1,   511,    26,     5,
      26,   479,    -1,  1466,    -1,   663,  1466,    -1,  1007,  1464,
      -1,  1461,   671,  1007,  1464,    -1,  1461,   671,    20,    -1,
    1007,    -1,    25,    -1,  1013,    -1,    26,    -1,  1470,    -1,
     449,  1472,    -1,   449,  1471,    -1,    -1,  1474,   677,  1475,
      -1,    -1,  1473,   677,  1473,    -1,   633,    -1,   565,    -1,
     642,    -1,   604,    -1,   506,    -1,   522,    -1,   421,    -1,
     421,   483,    26,   446,    -1,   633,    -1,   565,    -1,   642,
      -1,   604,    -1,   506,    -1,   522,    -1,   421,    -1,   633,
      -1,   565,    -1,   642,    -1,   604,    -1,   506,    -1,   522,
      -1,   421,    -1,   421,   483,    26,   446,    -1,  1007,    -1,
    1007,   663,  1007,    -1,    25,    -1,  1517,   555,  1001,    -1,
      -1,  1517,   452,  1367,   489,   647,  1486,  1479,    -1,    -1,
    1517,   452,  1367,   489,   153,   647,  1487,  1480,    -1,    -1,
    1517,   452,  1367,   192,  1487,  1481,    -1,    -1,  1517,   452,
    1367,   193,   153,   647,  1487,  1482,    -1,    -1,   342,    -1,
     341,  1484,    -1,  1485,    -1,  1484,     5,  1485,    -1,  1007,
      -1,  1007,   671,  1007,    -1,    25,   671,  1007,   671,  1007,
      -1,  1487,    -1,  1357,    -1,  1220,    -1,  1489,    -1,  1489,
      -1,    -1,    -1,   523,  1500,  1490,  1501,  1491,  1497,  1433,
    1495,  1483,    -1,   523,  1500,  1501,  1433,  1495,    -1,  1494,
      -1,  1512,    -1,   523,  1500,  1501,  1497,  1433,  1495,    -1,
      -1,   577,  1452,  1493,    -1,  1376,    -1,   387,  1496,  1326,
      -1,  1376,   387,  1496,  1326,    -1,  1007,    -1,    -1,   605,
    1186,    -1,   523,  1500,  1501,  1433,    -1,   483,   523,  1500,
    1501,  1433,   446,    -1,    -1,   637,    -1,   414,    -1,   528,
      -1,  1502,    -1,  1501,     5,  1502,    -1,  1504,    -1,  1504,
    1007,    -1,  1504,   668,  1007,    -1,  1504,    -1,  1505,    -1,
      19,  1505,    -1,    18,  1505,    -1,  1506,    -1,  1566,    -1,
    1499,    -1,   637,  1499,    -1,   638,  1499,    -1,   622,  1499,
      -1,   663,  1007,    -1,   663,  1007,   671,  1007,    -1,  1505,
      21,  1504,    -1,  1505,  1526,    -1,  1505,    20,  1504,    -1,
    1505,    18,  1504,    -1,  1505,    19,  1504,    -1,  1468,    -1,
     536,    -1,   480,    -1,   628,    -1,    20,    -1,   118,    -1,
     640,   483,  1452,  1504,   446,    -1,   652,   483,  1452,  1504,
     446,    -1,   653,   483,  1452,  1504,   446,    -1,   660,   483,
    1452,  1504,   446,    -1,   548,   483,  1452,  1504,   446,    -1,
    1007,   483,  1507,   446,    -1,   589,   483,  1507,   446,    -1,
     483,  1504,   446,    -1,   496,   483,  1527,   446,    -1,  1528,
      -1,  1530,    -1,  1504,    -1,  1507,     5,  1504,    -1,  1468,
      -1,  1517,   402,  1516,  1511,  1493,    -1,  1517,   391,  1516,
    1511,   302,  1461,  1513,    -1,  1517,   391,  1516,  1511,  1165,
      -1,    -1,   377,  1512,    -1,    25,    -1,  1165,    -1,    -1,
     483,  1514,   446,    -1,  1515,    -1,  1514,     5,  1515,    -1,
    1007,    -1,    25,    -1,  1165,    -1,    -1,   321,  1518,   647,
      -1,  1008,    -1,  1524,    -1,  1523,    -1,  1520,    -1,   370,
    1521,   677,  1521,    -1,   351,  1461,   671,  1522,   677,  1522,
      -1,  1007,    -1,  1007,    -1,   275,  1461,    -1,   346,  1461,
    1525,    -1,   325,    -1,   228,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,   149,    -1,   150,    -1,   449,     5,
    1474,   677,  1475,    -1,  1566,     5,  1474,   677,  1475,    -1,
     449,  1474,   677,  1475,    -1,  1504,     5,  1474,   677,  1475,
      -1,  1529,    -1,  1529,  1474,   677,  1475,    -1,    36,    -1,
    1531,    -1,  1531,  1474,   483,    26,   446,   677,  1475,    -1,
    1531,  1474,   677,  1475,    -1,    37,    -1,    -1,   659,  1533,
    1534,   243,    -1,  1535,    -1,  1534,  1535,    -1,    33,    -1,
    1536,    -1,  1538,    -1,    -1,   244,  1537,  1566,    -1,    -1,
     605,  1539,  1186,    -1,    -1,    -1,   530,  1461,  1541,  1544,
    1542,  1543,    -1,    -1,   204,  1001,    -1,   578,  1437,    -1,
     103,  1548,   446,    14,   483,  1549,   446,    -1,    99,  1549,
     446,    -1,   100,  1549,   446,    -1,   635,  1545,    -1,   102,
    1549,    -1,   101,  1549,    -1,  1547,    -1,  1545,     5,  1547,
      -1,  1465,    -1,  1546,    14,  1550,    -1,  1546,    -1,  1548,
       5,  1546,    -1,  1550,    -1,  1549,     5,  1550,    -1,   535,
      -1,  1551,    -1,  1552,    -1,    19,  1552,    -1,    18,  1552,
      -1,  1554,    -1,  1499,    -1,   663,  1007,    -1,   663,  1007,
     671,  1007,    -1,   663,  1007,   511,    26,   479,    -1,   663,
    1007,   671,  1007,   511,    26,   479,    -1,   663,  1007,   511,
      26,     5,    26,   479,    -1,   663,  1007,   671,  1007,   511,
      26,     5,    26,   479,    -1,  1553,    -1,  1468,    -1,   536,
      -1,   480,    -1,   628,    -1,   118,    -1,  1552,    21,  1551,
      -1,  1552,  1526,    -1,  1552,    20,  1551,    -1,  1552,    18,
    1551,    -1,  1552,    19,  1551,    -1,   640,   483,  1452,  1551,
     446,    -1,   652,   483,  1452,  1551,   446,    -1,   653,   483,
    1452,  1551,   446,    -1,   660,   483,  1452,  1551,   446,    -1,
     548,   483,  1452,  1551,   446,    -1,  1007,   483,  1555,   446,
      -1,   589,   483,  1555,   446,    -1,   483,  1551,   446,    -1,
     496,   483,  1527,   446,    -1,  1528,    -1,  1530,    -1,  1566,
      -1,  1551,    -1,  1555,     5,  1551,    -1,    -1,   436,  1194,
     608,  1557,  1558,    -1,  1559,    -1,  1558,     5,  1559,    -1,
    1461,   671,  1465,    -1,  1461,   671,    20,    -1,  1562,    -1,
    1562,    -1,   244,  1563,    -1,  1563,    -1,  1564,    -1,    25,
     671,  1564,    -1,  1565,    -1,  1564,   671,  1565,    -1,  1564,
     671,    20,    -1,  1567,    -1,  1007,    -1,  1561,    -1,  1561,
     473,  1561,    -1,  1007,  1568,    -1,   511,  1569,   479,    -1,
     511,  1569,   479,   511,  1569,   479,    -1,  1570,    -1,  1569,
       5,  1570,    -1,   737,    -1,    34,    -1,    -1,    -1,   579,
    1573,   914,  1574,  1587,   381,    -1,    -1,   710,   955,    -1,
      -1,   713,    -1,   235,    -1,   331,  1002,    -1,   123,  1002,
      -1,   361,    -1,   360,    -1,   362,  1004,  1575,  1576,    -1,
     545,   955,  1576,    -1,   157,    -1,   189,  1002,    -1,   914,
     618,     5,   914,   447,    -1,   561,   914,    -1,   318,  1002,
      -1,   154,  1582,     8,  1583,  1581,    -1,    -1,   598,   914,
      -1,  1007,    -1,  1007,    -1,   301,  1002,    -1,   304,  1002,
     677,   914,     5,   914,    -1,   304,  1002,   670,   914,     5,
     914,    -1,    27,    -1,    -1,  1589,    -1,  1590,  1273,    -1,
    1588,    -1,  1589,  1588,    -1,    -1,  1591,  1592,    -1,   730,
      -1,   731,    -1,   732,    -1,   733,    -1,   750,    -1,   772,
      -1,   786,    -1,   787,    -1,   793,    -1,   812,    -1,   886,
      -1,   887,    -1,   888,    -1,   889,    -1,   900,    -1,   901,
      -1,   902,    -1,   903,    -1,   904,    -1,   905,    -1,   906,
      -1,   957,    -1,   988,    -1,   992,    -1,  1014,    -1,  1016,
      -1,  1019,    -1,  1020,    -1,  1021,    -1,  1022,    -1,  1035,
      -1,  1045,    -1,  1069,    -1,  1070,    -1,  1072,    -1,  1076,
      -1,  1091,    -1,  1092,    -1,  1096,    -1,  1097,    -1,  1098,
      -1,  1099,    -1,  1107,    -1,  1122,    -1,  1142,    -1,  1153,
      -1,  1154,    -1,  1155,    -1,  1159,    -1,  1196,    -1,  1199,
      -1,  1201,    -1,  1207,    -1,  1208,    -1,  1211,    -1,  1214,
      -1,  1217,    -1,  1219,    -1,  1221,    -1,  1224,    -1,  1231,
      -1,  1236,    -1,  1241,    -1,  1242,    -1,  1243,    -1,  1255,
      -1,  1309,    -1,  1310,    -1,  1312,    -1,  1331,    -1,  1332,
      -1,  1352,    -1,  1355,    -1,  1384,    -1,  1386,    -1,  1477,
      -1,  1478,    -1,  1509,    -1,  1510,    -1,  1532,    -1,  1556,
      -1,  1571,    -1,  1572,    -1,  1577,    -1,  1578,    -1,  1580,
      -1,  1584,    -1,  1585,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1003,  1003,  1006,  1009,  1015,  1021,  1028,  1032,  1032,
    1038,  1061,  1062,  1063,  1064,  1065,  1076,  1082,  1083,  1084,
    1085,  1086,  1091,  1092,  1103,  1106,  1109,  1109,  1113,  1116,
    1117,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1142,  1143,
    1146,  1146,  1161,  1162,  1165,  1171,  1173,  1184,  1186,  1188,
    1190,  1194,  1196,  1258,  1262,  1266,  1266,  1276,  1280,  1283,
    1284,  1291,  1297,  1291,  1310,  1315,  1319,  1310,  1331,  1335,
    1331,  1343,  1348,  1343,  1367,  1374,  1378,  1366,  1404,  1404,
    1408,  1409,  1410,  1415,  1418,  1423,  1427,  1435,  1436,  1439,
    1439,  1445,  1449,  1464,  1462,  1480,  1480,  1495,  1495,  1498,
    1498,  1502,  1505,  1505,  1505,  1512,  1513,  1512,  1520,  1520,
    1531,  1531,  1550,  1553,  1556,  1559,  1562,  1565,  1578,  1583,
    1583,  1584,  1584,  1587,  1592,  1592,  1596,  1615,  1620,  1614,
    1631,  1637,  1645,  1646,  1649,  1649,  1652,  1656,  1661,  1668,
    1668,  1672,  1672,  1673,  1673,  1674,  1674,  1675,  1675,  1676,
    1676,  1684,  1688,  1694,  1698,  1713,  1716,  1719,  1722,  1725,
    1728,  1734,  1745,  1750,  1763,  1767,  1782,  1783,  1787,  1787,
    1791,  1791,  1791,  1792,  1797,  1797,  1800,  1800,  1809,  1810,
    1811,  1814,  1818,  1819,  1819,  1836,  1836,  1836,  1836,  1840,
    1847,  1848,  1851,  1851,  1855,  1856,  1857,  1858,  1863,  1863,
    1869,  1869,  1878,  1875,  1891,  1891,  1893,  1893,  1895,  1897,
    1899,  1901,  1904,  1908,  1908,  1909,  1909,  1913,  1913,  1925,
    1925,  1930,  1934,  1936,  1937,  1940,  1940,  1940,  1944,  1945,
    1946,  1947,  1948,  1949,  1950,  1951,  1952,  1953,  1954,  1955,
    1958,  1959,  1960,  1961,  1965,  1970,  1975,  1979,  1982,  1986,
    1986,  1987,  1987,  1988,  1988,  1989,  1990,  1991,  1992,  1993,
    1994,  1997,  1998,  1999,  2029,  2029,  2034,  2038,  2040,  2042,
    2042,  2049,  2053,  2053,  2057,  2058,  2059,  2060,  2061,  2062,
    2063,  2069,  2069,  2072,  2074,  2080,  2082,  2088,  2096,  2096,
    2099,  2100,  2101,  2102,  2103,  2104,  2105,  2111,  2114,  2114,
    2127,  2127,  2134,  2135,  2136,  2138,  2139,  2142,  2146,  2147,
    2148,  2149,  2154,  2160,  2166,  2167,  2169,  2171,  2172,  2173,
    2174,  2175,  2176,  2179,  2180,  2187,  2195,  2195,  2203,  2200,
    2215,  2215,  2217,  2217,  2225,  2225,  2228,  2231,  2232,  2237,
    2249,  2253,  2256,  2259,  2260,  2261,  2262,  2263,  2268,  2275,
    2281,  2286,  2291,  2286,  2304,  2306,  2311,  2316,  2316,  2316,
    2320,  2320,  2323,  2323,  2330,  2330,  2337,  2337,  2348,  2366,
    2372,  2396,  2399,  2414,  2417,  2430,  2432,  2434,  2436,  2438,
    2440,  2442,  2448,  2450,  2454,  2456,  2458,  2460,  2462,  2464,
    2466,  2472,  2489,  2490,  2491,  2492,  2496,  2497,  2498,  2502,
    2507,  2514,  2515,  2516,  2517,  2518,  2519,  2520,  2521,  2522,
    2523,  2524,  2531,  2531,  2536,  2536,  2539,  2545,  2553,  2559,
    2569,  2570,  2578,  2599,  2603,  2608,  2613,  2615,  2618,  2636,
    2641,  2647,  2652,  2657,  2658,  2664,  2735,  2746,  2755,  2763,
    2763,  2778,  2782,  2789,  2792,  2800,  2804,  2807,  2813,  2822,
    2827,  2835,  2838,  2841,  2846,  2853,  2858,  2863,  2868,  2878,
    2886,  2894,  2899,  2903,  2908,  2912,  2916,  2923,  2926,  2929,
    2933,  2937,  2941,  2945,  2953,  2963,  2968,  2961,  2984,  2989,
    2984,  3006,  3006,  3006,  3009,  3009,  3009,  3013,  3013,  3013,
    3017,  3017,  3017,  3021,  3027,  3033,  3039,  3047,  3053,  3061,
    3067,  3076,  3082,  3089,  3096,  3105,  3111,  3117,  3124,  3130,
    3136,  3142,  3150,  3156,  3162,  3171,  3177,  3183,  3193,  3193,
    3197,  3201,  3202,  3213,  3214,  3220,  3230,  3240,  3250,  3251,
    3254,  3259,  3265,  3269,  3273,  3276,  3282,  3285,  3288,  3305,
    3308,  3314,  3315,  3316,  3320,  3321,  3322,  3323,  3324,  3326,
    3327,  3328,  3330,  3331,  3335,  3336,  3341,  3345,  3350,  3354,
    3369,  3373,  3379,  3368,  3392,  3393,  3405,  3411,  3405,  3425,
    3425,  3427,  3428,  3432,  3432,  3436,  3436,  3441,  3441,  3448,
    3449,  3453,  3453,  3457,  3457,  3462,  3462,  3469,  3473,  3474,
    3475,  3480,  3480,  3483,  3483,  3487,  3487,  3491,  3491,  3495,
    3495,  3500,  3500,  3505,  3505,  3510,  3510,  3515,  3515,  3531,
    3535,  3530,  3543,  3546,  3560,  3577,  3578,  3579,  3580,  3581,
    3582,  3583,  3586,  3586,  3589,  3591,  3594,  3597,  3600,  3605,
    3610,  3613,  3618,  3623,  3628,  3635,  3636,  3643,  3650,  3652,
    3658,  3663,  3668,  3673,  3673,  3676,  3682,  3687,  3690,  3697,
    3697,  3699,  3702,  3705,  3710,  3715,  3720,  3727,  3736,  3736,
    3798,  3806,  3807,  3815,  3822,  3822,  3826,  3831,  3837,  3841,
    3845,  3851,  3855,  3859,  3865,  3865,  3873,  3874,  3878,  3878,
    3882,  3883,  3886,  3889,  3889,  3892,  3894,  3894,  3897,  3899,
    3899,  3900,  3902,  3902,  3911,  3918,  3909,  3939,  3939,  3939,
    3942,  3944,  3942,  3951,  3954,  3961,  3966,  3977,  3977,  3981,
    3987,  3987,  3991,  3992,  3996,  4006,  4007,  4008,  4011,  4013,
    4018,  4018,  4022,  4021,  4029,  4028,  4035,  4035,  4041,  4041,
    4048,  4048,  4054,  4054,  4060,  4060,  4066,  4066,  4070,  4070,
    4071,  4071,  4072,  4072,  4073,  4073,  4077,  4077,  4088,  4092,
    4098,  4102,  4107,  4112,  4117,  4118,  4119,  4123,  4122,  4135,
    4140,  4145,  4145,  4161,  4167,  4168,  4169,  4170,  4171,  4181,
    4195,  4195,  4198,  4205,  4206,  4207,  4208,  4209,  4210,  4211,
    4212,  4213,  4218,  4218,  4220,  4223,  4223,  4225,  4229,  4232,
    4233,  4236,  4236,  4241,  4244,  4245,  4246,  4247,  4248,  4249,
    4250,  4251,  4252,  4253,  4254,  4255,  4256,  4257,  4258,  4259,
    4260,  4261,  4265,  4283,  4283,  4283,  4310,  4321,  4328,  4334,
    4340,  4346,  4358,  4383,  4382,  4399,  4399,  4403,  4404,  4412,
    4413,  4414,  4415,  4416,  4417,  4418,  4425,  4426,  4428,  4429,
    4433,  4438,  4439,  4440,  4441,  4442,  4443,  4444,  4445,  4446,
    4448,  4451,  4453,  4453,  4455,  4459,  4459,  4468,  4473,  4489,
    4495,  4467,  4509,  4523,  4533,  4522,  4546,  4553,  4553,  4558,
    4564,  4572,  4577,  4578,  4581,  4584,  4584,  4592,  4598,  4609,
    4610,  4614,  4618,  4631,  4613,  4644,  4650,  4644,  4661,  4662,
    4666,  4666,  4673,  4673,  4688,  4688,  4702,  4713,  4712,  4724,
    4720,  4737,  4734,  4747,  4747,  4749,  4750,  4752,  4753,  4756,
    4757,  4758,  4760,  4765,  4770,  4776,  4778,  4779,  4782,  4783,
    4786,  4788,  4795,  4798,  4801,  4804,  4808,  4812,  4813,  4814,
    4815,  4816,  4820,  4825,  4825,  4828,  4855,  4913,  4913,  4916,
    4920,  4924,  4967,  5009,  5010,  5011,  5014,  5028,  5040,  5040,
    5045,  5046,  5052,  5117,  5122,  5129,  5134,  5142,  5148,  5181,
    5184,  5185,  5226,  5269,  5270,  5274,  5275,  5279,  5332,  5337,
    5341,  5346,  5357,  5364,  5372,  5372,  5375,  5376,  5377,  5378,
    5379,  5382,  5385,  5391,  5394,  5398,  5403,  5411,  5416,  5423,
    5425,  5431,  5433,  5433,  5433,  5453,  5460,  5467,  5470,  5484,
    5491,  5492,  5495,  5496,  5500,  5506,  5511,  5517,  5518,  5523,
    5527,  5527,  5531,  5532,  5535,  5536,  5540,  5548,  5551,  5557,
    5558,  5560,  5562,  5566,  5566,  5567,  5572,  5580,  5581,  5586,
    5587,  5589,  5602,  5604,  5605,  5608,  5609,  5610,  5611,  5612,
    5613,  5614,  5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,
    5623,  5624,  5625,  5626,  5627,  5628,  5629,  5630,  5631,  5632,
    5633,  5647,  5655,  5655,  5657,  5661,  5665,  5669,  5673,  5678,
    5693,  5691,  5711,  5712,  5716,  5721,  5722,  5726,  5727,  5729,
    5730,  5732,  5732,  5741,  5750,  5750,  5760,  5761,  5766,  5767,
    5770,  5783,  5797,  5801,  5805,  5809,  5816,  5817,  5820,  5820,
    5824,  5827,  5827,  5829,  5835,  5843,  5849,  5851,  5855,  5858,
    5858,  5861,  5861,  5866,  5866,  5875,  5875,  5879,  5879,  5880,
    5880,  5881,  5881,  5895,  5895,  5915,  5916,  5917,  5918,  5919,
    5920,  5923,  5923,  5929,  5929,  5932,  5932,  5948,  5949,  5950,
    5959,  5971,  5972,  5975,  5976,  5979,  5982,  5982,  5987,  5987,
    6010,  6011,  6017,  6022,  6028,  6029,  6030,  6034,  6035,  6036,
    6037,  6041,  6051,  6053,  6058,  6061,  6066,  6072,  6079,  6086,
    6095,  6102,  6109,  6116,  6123,  6132,  6132,  6134,  6134,  6137,
    6138,  6139,  6140,  6141,  6142,  6143,  6144,  6145,  6146,  6149,
    6149,  6152,  6153,  6154,  6155,  6158,  6158,  6161,  6161,  6164,
    6165,  6166,  6167,  6168,  6169,  6170,  6171,  6173,  6174,  6175,
    6176,  6178,  6179,  6180,  6181,  6183,  6184,  6185,  6186,  6187,
    6188,  6189,  6190,  6194,  6202,  6212,  6225,  6234,  6245,  6249,
    6253,  6259,  6224,  6272,  6275,  6283,  6295,  6297,  6302,  6310,
    6320,  6323,  6327,  6335,  6301,  6344,  6348,  6352,  6356,  6348,
    6366,  6367,  6368,  6369,  6374,  6376,  6379,  6383,  6386,  6393,
    6398,  6405,  6406,  6407,  6412,  6413,  6419,  6419,  6419,  6424,
    6424,  6424,  6432,  6433,  6437,  6438,  6443,  6444,  6445,  6446,
    6447,  6450,  6452,  6452,  6455,  6456,  6460,  6461,  6464,  6465,
    6468,  6471,  6474,  6480,  6481,  6493,  6494,  6499,  6500,  6501,
    6505,  6508,  6514,  6517,  6525,  6526,  6532,  6536,  6540,  6546,
    6549,  6558,  6561,  6564,  6567,  6570,  6573,  6576,  6583,  6586,
    6593,  6596,  6602,  6605,  6612,  6615,  6622,  6623,  6628,  6632,
    6635,  6641,  6644,  6650,  6657,  6658,  6662,  6672,  6675,  6681,
    6683,  6688,  6689,  6693,  6695,  6701,  6702,  6715,  6727,  6728,
    6729,  6730,  6731,  6732,  6733,  6734,  6735,  6738,  6741,  6747,
    6747,  6753,  6753,  6764,  6777,  6787,  6787,  6792,  6792,  6796,
    6800,  6801,  6807,  6808,  6813,  6817,  6824,  6827,  6834,  6833,
    6844,  6848,  6852,  6859,  6862,  6862,  6875,  6879,  6879,  6894,
    6896,  6898,  6900,  6902,  6904,  6906,  6908,  6914,  6924,  6931,
    6936,  6937,  6941,  6944,  6945,  6948,  6949,  6950,  6953,  6958,
    6965,  6966,  6972,  6984,  6985,  6986,  6989,  6989,  6994,  6999,
    7004,  7005,  7008,  7009,  7014,  7019,  7023,  7028,  7029,  7033,
    7040,  7041,  7042,  7043,  7048,  7049,  7050,  7053,  7054,  7055,
    7059,  7060,  7061,  7065,  7066,  7070,  7071,  7072,  7073,  7074,
    7075,  7078,  7079,  7084,  7085,  7090,  7091,  7096,  7097,  7102,
    7107,  7108,  7113,  7114,  7118,  7119,  7124,  7131,  7136,  7141,
    7145,  7146,  7151,  7152,  7158,  7161,  7165,  7170,  7171,  7177,
    7180,  7183,  7190,  7191,  7192,  7193,  7207,  7212,  7213,  7216,
    7218,  7225,  7228,  7234,  7242,  7246,  7250,  7254,  7259,  7262,
    7265,  7272,  7279,  7284,  7288,  7289,  7295,  7298,  7309,  7316,
    7322,  7325,  7332,  7339,  7345,  7346,  7352,  7353,  7354,  7357,
    7358,  7365,  7372,  7372,  7376,  7384,  7385,  7388,  7391,  7396,
    7397,  7402,  7405,  7411,  7414,  7420,  7423,  7429,  7432,  7439,
    7440,  7469,  7470,  7475,  7483,  7488,  7491,  7494,  7497,  7503,
    7504,  7508,  7511,  7514,  7515,  7520,  7523,  7526,  7529,  7532,
    7535,  7538,  7541,  7546,  7552,  7553,  7554,  7555,  7556,  7558,
    7559,  7561,  7562,  7567,  7570,  7574,  7580,  7581,  7582,  7583,
    7595,  7596,  7597,  7601,  7602,  7606,  7607,  7608,  7609,  7610,
    7612,  7621,  7628,  7629,  7630,  7631,  7632,  7633,  7634,  7636,
    7638,  7640,  7641,  7643,  7644,  7646,  7647,  7648,  7649,  7651,
    7655,  7656,  7662,  7664,  7665,  7666,  7667,  7672,  7676,  7680,
    7684,  7691,  7695,  7696,  7697,  7705,  7706,  7707,  7718,  7725,
    7730,  7731,  7732,  7740,  7741,  7742,  7759,  7768,  7769,  7770,
    7774,  7777,  7782,  7787,  7792,  7800,  7804,  7809,  7810,  7818,
    7821,  7824,  7838,  7852,  7865,  7866,  7870,  7870,  7870,  7870,
    7870,  7870,  7871,  7874,  7891,  7891,  7891,  7891,  7891,  7891,
    7891,  7892,  7892,  7892,  7892,  7892,  7892,  7892,  7892,  7895,
    7896,  7897,  7900,  7909,  7909,  7915,  7915,  7922,  7922,  7928,
    7928,  7936,  7937,  7938,  7941,  7941,  7944,  7945,  7946,  7957,
    7960,  7966,  7971,  7978,  7991,  7992,  7989,  8010,  8021,  8024,
    8029,  8041,  8044,  8048,  8051,  8052,  8062,  8065,  8066,  8075,
    8084,  8089,  8090,  8091,  8092,  8099,  8102,  8108,  8111,  8118,
    8130,  8139,  8142,  8145,  8151,  8159,  8162,  8163,  8164,  8165,
    8166,  8169,  8175,  8177,  8179,  8181,  8183,  8185,  8186,  8187,
    8188,  8189,  8190,  8191,  8193,  8195,  8197,  8199,  8201,  8203,
    8205,  8206,  8208,  8209,  8215,  8216,  8223,  8226,  8234,  8238,
    8245,  8245,  8249,  8249,  8254,  8254,  8258,  8258,  8262,  8268,
    8268,  8271,  8271,  8277,  8284,  8285,  8286,  8290,  8291,  8294,
    8295,  8299,  8305,  8315,  8316,  8324,  8325,  8326,  8327,  8328,
    8329,  8333,  8334,  8335,  8336,  8340,  8341,  8345,  8361,  8362,
    8363,  8367,  8381,  8381,  8393,  8394,  8398,  8399,  8400,  8724,
    8724,  8731,  8731,  8819,  8823,  8819,  8832,  8836,  8842,  8850,
    8860,  8870,  8882,  8885,  8904,  8930,  8933,  8939,  8942,  8947,
    8950,  8958,  8966,  8979,  8982,  8990,  8993,  8996,  9004,  9008,
    9009,  9010,  9011,  9012,  9013,  9014,  9015,  9019,  9020,  9021,
    9022,  9023,  9029,  9030,  9031,  9032,  9033,  9034,  9035,  9036,
    9037,  9038,  9039,  9040,  9041,  9042,  9043,  9044,  9049,  9055,
    9056,  9064,  9064,  9072,  9072,  9076,  9080,  9095,  9110,  9116,
    9118,  9126,  9127,  9131,  9132,  9135,  9142,  9145,  9174,  9200,
    9254,  9290,  9299,  9310,  9313,  9318,  9332,  9346,  9349,  9345,
    9368,  9368,  9374,  9375,  9378,  9379,  9380,  9381,  9382,  9383,
    9384,  9395,  9398,  9403,  9407,  9412,  9416,  9421,  9425,  9428,
    9432,  9435,  9440,  9444,  9455,  9461,  9461,  9462,  9463,  9470,
    9480,  9480,  9482,  9483,  9484,  9485,  9486,  9487,  9488,  9489,
    9490,  9491,  9492,  9493,  9494,  9495,  9496,  9497,  9498,  9499,
    9500,  9501,  9502,  9503,  9504,  9505,  9506,  9507,  9508,  9509,
    9510,  9511,  9512,  9513,  9514,  9515,  9516,  9517,  9518,  9519,
    9520,  9521,  9522,  9523,  9524,  9525,  9526,  9527,  9528,  9529,
    9530,  9531,  9532,  9533,  9534,  9535,  9536,  9537,  9538,  9539,
    9540,  9541,  9542,  9543,  9544,  9545,  9546,  9547,  9548,  9549,
    9550,  9551,  9552,  9553,  9554,  9555,  9556,  9557,  9558,  9559,
    9560,  9561,  9562,  9563,  9564,  9565,  9566,  9567,  9568,  9569
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
  "DATETIME_VALUE", "INTERVAL_VALUE", "FGL_SIZEOF", "IMPORT_PACKAGE", 
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
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "boolean_expr", 
  "literal_expr", "variable_entry_2", "variable_entry", 
  "report_only_expr", "@57", "and_or_expr", "inexpr_list", "in_expr", 
  "null_expr", "string_match_expr", "clip_expr", "using_expr", 
  "math_expr", "comparison_expr", "reset_cnt", "function_call_expr2", 
  "@58", "@59", "@60", "@61", "function_callb", "@62", "@63", "@64", 
  "@65", "@66", "@67", "@68", "@69", "op_extend_d", "op_extend_i", 
  "function_call_expr", "builtin_expr", "builtin_funcs", "pdf_expr", 
  "interval_func_params", "numeric_time_interval", 
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
  "import_package", "module_import", "init_cmd", "@92", "init_tab_list", 
  "init_tab", "init_table_name", "end_input", "opt_defs", 
  "field_commands", "field_command", "@93", "@94", "@95", "@96", "@97", 
  "@98", "@99", "@100", "@101", "@102", "@103", "@104", "@105", 
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
  "@143", "pf_char_or_var", "print_file_command", "print_img_command", 
  "opt_scaling", "img_types", "blob_var", "opt_semi", "rep_expr_list", 
  "rep_expr", "rep_agg", "op_output_section", "output_commands", 
  "output_command", "pdf_output_commands", "nval", "nval_number", 
  "pdf_op_output_section", "pdf_output_command", "op_rep_order_by", 
  "report_def", "@144", "@145", "@146", "@147", "@148", "@149", 
  "rep_where", "pause_command", "pause_msg", "pdf_report_def", "@150", 
  "@151", "@152", "@153", "@154", "@155", "pdf_report_section", 
  "pdf_functions", "@156", "@157", "@158", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@159", "@160", 
  "@161", "@162", "opt_cr_table_extra", "cr_table_extra", 
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
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "s_curr", "e_curr", 
  "dbase_name", "flush_cmd", "declare_cmd", "@169", "@170", "@171", 
  "@172", "curs_forupdate", "cur_update_list", "colident", 
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
       0,   256,  1712,  1713,  1714,  1619,  1659,  1614,  1551,  1634,
    1431,  1537,  1533,  1448,  1609,  1350,  1407,  1479,  1645,  1632,
    1538,  1565,  1633,  1414,  1715,  1716,  1717,  1718,  1719,  1720,
    1721,  1722,  1723,  1724,  1725,  1726,  1000,  1001,  1002,  1003,
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
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   729,   730,   731,   732,   733,   734,   734,   735,   735,
     736,   737,   737,   737,   737,   737,   737,   738,   738,   738,
     738,   738,   739,   739,   740,   740,   742,   741,   741,   743,
     743,   744,   744,   744,   744,   744,   744,   744,   744,   744,
     744,   744,   744,   744,   744,   744,   744,   744,   745,   745,
     747,   746,   748,   748,   749,   749,   749,   749,   749,   749,
     749,   749,   749,   750,   751,   752,   751,   751,   751,   751,
     751,   753,   754,   751,   755,   756,   757,   751,   758,   759,
     751,   760,   761,   751,   762,   763,   764,   751,   765,   765,
     766,   766,   766,   767,   767,   768,   768,   769,   769,   770,
     770,   771,   771,   773,   772,   774,   772,   775,   775,   776,
     776,   777,   778,   779,   778,   780,   781,   780,   783,   782,
     785,   784,   786,   786,   786,   786,   786,   786,   787,   788,
     788,   789,   789,   790,   791,   791,   792,   794,   795,   793,
     796,   796,   797,   797,   798,   798,   799,   799,   799,   800,
     800,   802,   801,   803,   801,   804,   801,   805,   801,   806,
     801,   807,   807,   808,   808,   809,   809,   809,   809,   809,
     809,   810,   811,   811,   812,   812,   813,   813,   814,   814,
     816,   817,   815,   815,   818,   818,   820,   819,   821,   821,
     821,   821,   821,   822,   821,   823,   823,   823,   823,   824,
     825,   825,   826,   826,   827,   827,   827,   827,   829,   828,
     830,   828,   831,   828,   832,   832,   833,   833,   834,   835,
     835,   835,   836,   838,   837,   839,   837,   840,   837,   841,
     841,   842,   843,   844,   844,   846,   847,   845,   848,   848,
     848,   848,   848,   848,   848,   848,   848,   848,   848,   848,
     848,   848,   848,   848,   848,   848,   848,   848,   848,   849,
     848,   850,   848,   851,   848,   848,   848,   848,   848,   848,
     848,   848,   848,   848,   852,   852,   853,   854,   855,   856,
     856,   857,   859,   858,   860,   860,   860,   860,   860,   860,
     860,   862,   861,   863,   863,   864,   864,   865,   867,   866,
     868,   868,   868,   868,   868,   868,   868,   869,   870,   870,
     872,   871,   873,   873,   873,   873,   873,   873,   873,   873,
     873,   873,   873,   873,   873,   873,   873,   873,   873,   873,
     873,   873,   873,   873,   873,   874,   876,   875,   877,   875,
     879,   878,   880,   878,   881,   881,   882,   883,   883,   884,
     885,   885,   885,   885,   885,   885,   885,   885,   886,   887,
     888,   890,   891,   889,   892,   892,   893,   894,   894,   894,
     895,   895,   897,   896,   898,   896,   899,   896,   900,   901,
     902,   903,   903,   904,   904,   905,   905,   905,   905,   905,
     905,   905,   905,   905,   906,   906,   906,   906,   906,   906,
     906,   906,   907,   907,   907,   907,   907,   907,   907,   907,
     907,   908,   908,   908,   908,   908,   908,   908,   908,   908,
     908,   908,   909,   909,   910,   910,   911,   911,   912,   912,
     913,   913,   914,   915,   915,   915,   915,   915,   915,   916,
     916,   916,   916,   917,   917,   918,   919,   919,   919,   920,
     919,   921,   921,   922,   922,   923,   923,   923,   923,   924,
     924,   925,   925,   925,   925,   925,   925,   925,   925,   926,
     927,   928,   928,   928,   928,   928,   928,   929,   929,   929,
     929,   929,   929,   929,   930,   932,   933,   931,   934,   935,
     931,   937,   938,   936,   939,   940,   936,   941,   942,   936,
     943,   944,   936,   936,   936,   936,   936,   936,   936,   936,
     936,   936,   936,   936,   936,   936,   936,   936,   936,   936,
     936,   936,   936,   936,   936,   936,   936,   936,   945,   945,
     946,   947,   947,   947,   947,   947,   947,   947,   947,   947,
     948,   948,   949,   949,   949,   949,   950,   950,   950,   951,
     951,   952,   952,   952,   953,   953,   953,   953,   953,   953,
     953,   953,   953,   953,   954,   954,   955,   955,   956,   956,
     958,   959,   960,   957,   961,   961,   963,   964,   962,   965,
     965,   966,   966,   967,   967,   969,   968,   970,   968,   971,
     971,   972,   972,   974,   973,   975,   973,   976,   977,   977,
     977,   978,   978,   979,   979,   980,   980,   981,   981,   983,
     982,   984,   982,   985,   982,   986,   982,   987,   982,   989,
     990,   988,   991,   991,   992,   993,   993,   993,   993,   993,
     993,   993,   994,   994,   995,   996,   997,   998,   998,   998,
     998,   998,   998,   998,   998,   999,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1006,  1006,  1007,  1008,  1009,  1009,  1010,
    1010,  1011,  1011,  1011,  1011,  1011,  1011,  1012,  1013,  1013,
    1014,  1015,  1015,  1016,  1017,  1017,  1018,  1019,  1020,  1020,
    1020,  1021,  1021,  1021,  1023,  1022,  1024,  1024,  1025,  1025,
    1026,  1026,  1027,  1028,  1028,  1029,  1030,  1030,  1031,  1032,
    1032,  1033,  1034,  1034,  1036,  1037,  1035,  1038,  1039,  1038,
    1040,  1041,  1038,  1042,  1042,  1043,  1044,  1046,  1045,  1045,
    1047,  1047,  1048,  1048,  1049,  1050,  1050,  1050,  1051,  1051,
    1052,  1052,  1054,  1053,  1055,  1053,  1056,  1053,  1057,  1053,
    1058,  1053,  1059,  1053,  1060,  1053,  1061,  1053,  1062,  1053,
    1063,  1053,  1064,  1053,  1065,  1053,  1066,  1053,  1067,  1067,
    1068,  1068,  1069,  1070,  1071,  1071,  1071,  1073,  1072,  1074,
    1074,  1075,  1074,  1076,  1077,  1077,  1077,  1077,  1077,  1077,
    1078,  1078,  1079,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  1080,  1082,  1081,  1081,  1084,  1083,  1085,  1086,  1087,
    1087,  1088,  1088,  1089,  1090,  1090,  1090,  1090,  1090,  1090,
    1090,  1090,  1090,  1090,  1090,  1090,  1090,  1090,  1090,  1090,
    1090,  1090,  1091,  1093,  1094,  1092,  1095,  1095,  1096,  1097,
    1098,  1099,  1099,  1101,  1100,  1102,  1102,  1103,  1103,  1104,
    1104,  1104,  1104,  1104,  1104,  1104,  1105,  1105,  1106,  1106,
    1107,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,
    1108,  1109,  1110,  1110,  1111,  1112,  1112,  1114,  1115,  1116,
    1117,  1113,  1118,  1120,  1121,  1119,  1122,  1123,  1123,  1124,
    1124,  1125,  1126,  1126,  1127,  1129,  1128,  1130,  1130,  1130,
    1130,  1132,  1133,  1134,  1131,  1136,  1137,  1135,  1138,  1138,
    1140,  1139,  1141,  1139,  1143,  1142,  1144,  1146,  1145,  1147,
    1145,  1148,  1145,  1149,  1149,  1150,  1150,  1151,  1151,  1152,
    1152,  1152,  1153,  1154,  1155,  1156,  1156,  1156,  1157,  1157,
    1158,  1158,  1159,  1160,  1160,  1160,  1160,  1161,  1161,  1161,
    1161,  1161,  1162,  1163,  1163,  1164,  1165,  1166,  1166,  1167,
    1168,  1168,  1168,  1168,  1168,  1168,  1169,  1170,  1171,  1171,
    1172,  1172,  1173,  1174,  1174,  1175,  1175,  1176,  1177,  1178,
    1178,  1178,  1178,  1178,  1178,  1179,  1179,  1180,  1181,  1181,
    1182,  1182,  1183,  1183,  1184,  1184,  1185,  1185,  1185,  1185,
    1185,  1186,  1186,  1187,  1187,  1188,  1188,  1189,  1190,  1191,
    1191,  1192,  1193,  1193,  1193,  1194,  1194,  1195,  1195,  1196,
    1197,  1197,  1198,  1198,  1199,  1200,  1201,  1202,  1202,  1203,
    1204,  1204,  1205,  1205,  1206,  1206,  1207,  1208,  1208,  1209,
    1209,  1209,  1209,  1210,  1210,  1210,  1211,  1212,  1212,  1213,
    1213,  1213,  1214,  1215,  1215,  1216,  1216,  1216,  1216,  1216,
    1216,  1216,  1216,  1216,  1216,  1216,  1216,  1216,  1216,  1216,
    1216,  1216,  1216,  1216,  1216,  1216,  1216,  1216,  1216,  1216,
    1216,  1217,  1218,  1218,  1219,  1219,  1219,  1219,  1219,  1220,
    1222,  1221,  1223,  1223,  1224,  1225,  1225,  1226,  1226,  1227,
    1227,  1229,  1228,  1230,  1232,  1231,  1233,  1233,  1234,  1234,
    1235,  1235,  1236,  1236,  1236,  1236,  1237,  1237,  1238,  1238,
    1239,  1240,  1240,  1241,  1242,  1243,  1244,  1245,  1245,  1246,
    1246,  1248,  1247,  1249,  1247,  1250,  1247,  1251,  1247,  1252,
    1247,  1253,  1247,  1254,  1247,  1255,  1255,  1255,  1255,  1255,
    1255,  1257,  1256,  1258,  1258,  1260,  1259,  1259,  1259,  1259,
    1259,  1261,  1261,  1262,  1262,  1263,  1264,  1264,  1266,  1265,
    1267,  1267,  1268,  1269,  1270,  1270,  1270,  1271,  1271,  1271,
    1271,  1272,  1273,  1273,  1274,  1274,  1275,  1276,  1276,  1276,
    1276,  1276,  1276,  1276,  1276,  1277,  1277,  1278,  1278,  1279,
    1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1280,
    1280,  1281,  1281,  1281,  1281,  1282,  1282,  1283,  1283,  1284,
    1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,
    1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,
    1284,  1284,  1284,  1285,  1285,  1285,  1287,  1288,  1289,  1290,
    1291,  1292,  1286,  1293,  1293,  1294,  1295,  1295,  1297,  1298,
    1299,  1300,  1301,  1302,  1296,  1303,  1305,  1306,  1307,  1304,
    1308,  1308,  1308,  1308,  1309,  1309,  1309,  1309,  1309,  1310,
    1311,  1311,  1311,  1311,  1312,  1312,  1314,  1315,  1313,  1316,
    1317,  1313,  1318,  1318,  1319,  1319,  1320,  1320,  1320,  1320,
    1320,  1321,  1322,  1322,  1323,  1323,  1324,  1324,  1325,  1325,
    1325,  1325,  1325,  1326,  1326,  1327,  1327,  1328,  1328,  1328,
    1329,  1329,  1330,  1330,  1331,  1331,  1332,  1332,  1332,  1333,
    1333,  1334,  1334,  1334,  1334,  1334,  1334,  1334,  1335,  1335,
    1336,  1336,  1337,  1337,  1338,  1338,  1339,  1339,  1340,  1341,
    1341,  1342,  1342,  1343,  1344,  1344,  1345,  1346,  1346,  1347,
    1347,  1348,  1348,  1349,  1349,  1350,  1350,  1351,  1352,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1353,
    1353,  1354,  1354,  1355,  1356,  1358,  1357,  1360,  1359,  1359,
    1361,  1361,  1362,  1362,  1363,  1363,  1364,  1364,  1366,  1365,
    1367,  1368,  1368,  1369,  1370,  1369,  1371,  1372,  1371,  1373,
    1373,  1373,  1373,  1373,  1373,  1373,  1373,  1374,  1375,  1376,
    1377,  1377,  1378,  1379,  1379,  1380,  1380,  1380,  1381,  1382,
    1383,  1383,  1384,  1385,  1385,  1385,  1387,  1386,  1388,  1388,
    1388,  1388,  1388,  1388,  1388,  1388,  1388,  1388,  1388,  1388,
    1389,  1389,  1389,  1389,  1390,  1390,  1390,  1391,  1391,  1391,
    1392,  1392,  1392,  1393,  1393,  1394,  1394,  1394,  1394,  1394,
    1394,  1395,  1395,  1396,  1396,  1397,  1397,  1398,  1398,  1399,
    1400,  1400,  1401,  1401,  1402,  1402,  1403,  1404,  1405,  1406,
    1407,  1407,  1408,  1408,  1409,  1409,  1409,  1410,  1410,  1411,
    1411,  1411,  1412,  1412,  1412,  1412,  1413,  1414,  1414,  1415,
    1415,  1416,  1416,  1417,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1419,  1420,  1421,  1422,  1422,  1423,  1423,  1424,  1425,
    1426,  1426,  1427,  1428,  1429,  1429,  1430,  1430,  1430,  1431,
    1431,  1431,  1432,  1432,  1433,  1434,  1434,  1435,  1435,  1436,
    1436,  1437,  1437,  1438,  1438,  1439,  1439,  1440,  1440,  1441,
    1441,  1442,  1442,  1443,  1444,  1445,  1445,  1445,  1445,  1446,
    1446,  1447,  1447,  1448,  1448,  1449,  1449,  1449,  1449,  1449,
    1449,  1449,  1449,  1449,  1450,  1450,  1450,  1450,  1450,  1450,
    1450,  1450,  1450,  1451,  1451,  1451,  1452,  1452,  1452,  1452,
    1453,  1453,  1453,  1454,  1454,  1455,  1455,  1455,  1455,  1455,
    1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,
    1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,
    1456,  1456,  1457,  1457,  1457,  1457,  1457,  1458,  1459,  1460,
    1461,  1461,  1461,  1461,  1461,  1461,  1461,  1461,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1463,  1464,  1464,  1464,
    1465,  1465,  1466,  1466,  1466,  1467,  1468,  1468,  1468,  1468,
    1469,  1470,  1471,  1471,  1472,  1472,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1474,  1474,  1474,  1474,  1474,  1474,
    1474,  1475,  1475,  1475,  1475,  1475,  1475,  1475,  1475,  1476,
    1476,  1476,  1477,  1479,  1478,  1480,  1478,  1481,  1478,  1482,
    1478,  1483,  1483,  1483,  1484,  1484,  1485,  1485,  1485,  1486,
    1486,  1487,  1487,  1488,  1490,  1491,  1489,  1492,  1493,  1493,
    1494,  1495,  1495,  1495,  1495,  1495,  1496,  1497,  1497,  1498,
    1499,  1500,  1500,  1500,  1500,  1501,  1501,  1502,  1502,  1502,
    1503,  1504,  1504,  1504,  1505,  1505,  1505,  1505,  1505,  1505,
    1505,  1505,  1506,  1506,  1506,  1506,  1506,  1506,  1506,  1506,
    1506,  1506,  1506,  1506,  1506,  1506,  1506,  1506,  1506,  1506,
    1506,  1506,  1506,  1506,  1507,  1507,  1508,  1509,  1510,  1510,
    1511,  1511,  1512,  1512,  1513,  1513,  1514,  1514,  1515,  1516,
    1516,  1517,  1517,  1518,  1519,  1519,  1519,  1520,  1520,  1521,
    1522,  1523,  1524,  1525,  1525,  1526,  1526,  1526,  1526,  1526,
    1526,  1527,  1527,  1527,  1527,  1528,  1528,  1529,  1530,  1530,
    1530,  1531,  1533,  1532,  1534,  1534,  1535,  1535,  1535,  1537,
    1536,  1539,  1538,  1541,  1542,  1540,  1543,  1543,  1543,  1544,
    1544,  1544,  1544,  1544,  1544,  1545,  1545,  1546,  1547,  1548,
    1548,  1549,  1549,  1550,  1550,  1551,  1551,  1551,  1552,  1552,
    1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,
    1552,  1552,  1553,  1553,  1553,  1553,  1553,  1553,  1553,  1553,
    1553,  1553,  1553,  1553,  1553,  1553,  1553,  1553,  1554,  1555,
    1555,  1557,  1556,  1558,  1558,  1559,  1559,  1560,  1561,  1562,
    1562,  1563,  1563,  1564,  1564,  1564,  1565,  1565,  1566,  1566,
    1567,  1568,  1568,  1569,  1569,  1570,  1571,  1573,  1574,  1572,
    1575,  1575,  1576,  1576,  1577,  1577,  1577,  1577,  1577,  1577,
    1577,  1578,  1578,  1579,  1579,  1580,  1580,  1581,  1581,  1582,
    1583,  1584,  1585,  1585,  1586,  1587,  1587,  1588,  1589,  1589,
    1591,  1590,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,
    1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592,  1592
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
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     3,     4,     4,     1,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     0,
       3,     2,     2,     1,     3,     4,     4,     5,     5,     1,
       1,     2,     2,     4,     4,     2,     2,     4,     4,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     0,     0,     6,     0,     0,
       8,     0,     0,     6,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     5,     5,     5,     5,     7,     7,     9,
       9,     6,     8,    10,    10,     7,     9,     8,    10,    12,
      14,    14,    10,    12,    12,     4,     4,     6,     0,     3,
       1,     1,     4,     4,     4,     4,     4,     4,     1,     1,
       1,     1,     4,     4,     2,     2,     2,     2,     2,     1,
       1,     2,     1,     1,     1,     2,     4,     6,     6,     3,
       5,     5,     3,     1,     1,     3,     1,     3,     1,     3,
       0,     0,     0,     9,     0,     3,     0,     0,    10,     0,
       1,     0,     1,     1,     2,     0,     3,     0,     3,     0,
       1,     1,     2,     0,     3,     0,     3,     3,     1,     4,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     0,
       3,     0,     3,     0,     4,     0,     4,     0,     4,     0,
       0,    11,     0,     2,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     4,     6,
       4,     3,     6,     3,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     4,     1,
       1,     1,     4,     3,     6,     3,     6,     1,     1,     2,
       2,     1,     2,     2,     1,     3,     1,     2,     2,     2,
       4,     2,     2,     4,     0,     8,     0,     1,     1,     1,
       0,     1,     2,     0,     1,     2,     0,     1,     2,     0,
       1,     3,     0,     2,     0,     0,     8,     0,     0,     3,
       0,     0,     7,     5,     2,     2,     2,     0,     5,     4,
       1,     3,     3,     3,     1,     0,     2,     1,     0,     1,
       1,     2,     0,     4,     0,     4,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     1,     3,
       1,     3,     2,     4,     1,     1,     1,     0,     4,     5,
       6,     0,    10,     3,     2,     2,     1,     1,     2,     2,
       0,     2,     1,     2,     3,     3,     3,     3,     1,     1,
       1,     1,     0,     3,     1,     0,     3,     2,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     7,     1,     1,     2,     2,
       2,     3,     4,     0,     3,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     0,     0,     0,
       0,    13,     1,     0,     0,     6,     2,     1,     2,     2,
       2,     1,     1,     2,     1,     0,     3,     2,     1,     1,
       1,     0,     0,     0,    14,     0,     0,     7,     1,     2,
       0,     3,     0,     4,     0,     5,     1,     0,     3,     0,
       7,     0,     5,     1,     2,     0,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     1,     1,     1,     1,     2,     2,
       2,     5,     8,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     2,     3,     6,     1,     3,     1,     1,     1,
       3,     6,     9,     1,     1,     1,     1,     2,     0,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     2,     0,     1,     1,     1,     3,     1,     3,     7,
       0,     7,     0,     6,     3,     1,     3,     1,     2,     5,
       0,     7,     0,     2,     0,     1,     5,     2,     5,     0,
       5,     6,     4,     0,     1,     1,     5,     0,     2,     0,
       5,     4,     2,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     2,     4,     4,     6,     2,     1,
       0,    11,     0,     2,     5,     0,     1,     0,     2,     1,
       2,     0,     3,     1,     0,     4,     0,     2,     1,     3,
       1,     1,     4,     5,     5,     3,     0,     1,     1,     1,
       1,     0,     1,     7,     2,     2,     2,     2,     2,     1,
       2,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     1,     0,     4,     1,     2,     2,
       2,     0,     1,     1,     2,     2,     0,     2,     0,     4,
       1,     3,     3,     5,     0,     2,     4,     1,     1,     1,
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
       2,     3,     1,     3,     4,     0,     1,     0,     1,     0,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     2,
       2,     0,     2,     1,     1,     5,     3,     5,     3,     1,
       3,     1,     1,     0,     1,     3,     3,     3,     6,     4,
       4,     4,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     4,     1,     5,
       5,     1,     1,     1,     1,     1,     4,     1,     4,     6,
       4,     1,     4,     1,     7,     1,     1,     1,     4,     6,
       0,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     5,     3,     5,     7,     3,     1,
       1,     3,     5,     3,     5,     7,     1,     0,     3,     5,
       1,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       2,     2,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     3,     0,     7,     0,     8,     0,     6,     0,
       8,     0,     1,     2,     1,     3,     1,     3,     5,     1,
       1,     1,     1,     1,     0,     0,     9,     5,     1,     1,
       6,     0,     3,     1,     3,     4,     1,     0,     2,     4,
       6,     0,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     1,     2,     2,     1,     1,     1,     2,     2,     2,
       2,     4,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     5,     5,     5,     5,     5,     4,     4,
       3,     4,     1,     1,     1,     3,     1,     5,     7,     5,
       0,     2,     1,     1,     0,     3,     1,     3,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     5,     1,     4,     1,     1,     7,
       4,     1,     0,     4,     1,     2,     1,     1,     1,     0,
       3,     0,     3,     0,     0,     6,     0,     2,     2,     7,
       3,     3,     2,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     2,     1,     1,
       2,     4,     5,     7,     7,     9,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     3,     5,     5,     5,
       5,     5,     4,     4,     3,     4,     1,     1,     1,     1,
       3,     0,     5,     1,     3,     3,     3,     1,     1,     2,
       1,     1,     3,     1,     3,     3,     1,     1,     1,     3,
       2,     3,     6,     1,     3,     1,     1,     0,     0,     6,
       0,     2,     0,     1,     1,     2,     2,     1,     1,     4,
       3,     1,     2,     5,     2,     2,     5,     0,     2,     1,
       1,     2,     6,     6,     1,     0,     1,     2,     1,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
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
     835,     0,  1916,     0,     0,     0,     0,   885,   180,     0,
     861,   864,   178,   183,   842,   839,     0,   833,   836,   837,
     840,   844,   845,   843,   881,   882,   884,   841,   136,   133,
       0,   129,   131,   130,   134,  1944,   715,   655,   716,   310,
    1691,  1689,   879,   176,   186,   880,   179,     1,   846,   838,
     883,   128,   132,   135,     0,     0,   632,     0,     0,   177,
     888,   954,   633,   889,   890,   886,   667,   946,     0,   947,
     955,   953,   186,   181,   199,     0,   184,   200,   235,     0,
     866,  1248,     0,     0,   865,  1236,   873,     0,     0,   858,
     857,   859,   834,   847,   848,   867,   851,   852,   853,   856,
     854,   855,   860,     0,  1690,   948,   887,     0,     0,   962,
     960,   961,   950,   949,   308,   186,  1172,   193,   187,   186,
     192,   232,     0,   714,     0,     0,     0,     0,   176,   576,
     895,   849,     0,   342,   328,   202,   314,   279,   298,   319,
     321,   318,     0,   340,     0,   327,   320,   324,   330,   329,
     186,   331,   311,   334,   312,   313,   959,   958,     0,    22,
      23,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   967,     0,   539,   531,    16,   538,   954,    15,
       0,   965,     0,   309,     0,   185,  1173,   182,     0,   199,
     201,   273,   204,   261,   267,   268,   252,   225,   263,   202,
     240,   241,     0,   227,   279,   298,   250,   253,   248,     0,
     223,     0,   259,   251,   256,   266,   265,   186,   269,   186,
     238,   239,   236,   272,     0,     0,     0,     0,   874,   176,
     176,     0,     0,   203,     0,     0,   332,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,   277,     0,   956,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   545,     0,     0,     0,   668,   439,   441,
    1243,     0,     0,     0,  1664,     0,   435,     0,     0,     0,
     434,     0,   449,   541,     0,     0,     0,     0,     0,   544,
     402,   408,   445,   442,   403,   404,   406,   407,   440,   443,
     448,   540,   494,   491,   500,   497,     0,     0,    17,    18,
      19,    20,    21,     0,    14,   485,     0,     0,   963,     0,
     188,   191,   189,   190,     0,   196,   195,   194,   197,   205,
     206,   207,   210,   274,   186,   274,     0,     0,     0,     0,
     186,   270,   271,     0,     0,   186,     0,   274,     0,     0,
     249,   233,  1249,     0,     0,  1237,  1950,   577,   896,   868,
       0,   214,   215,     0,     0,   291,   293,   288,   289,   285,
     287,   284,   286,   283,     0,   293,   304,   305,   301,   303,
     300,   302,   295,     0,     0,     0,   344,     0,   347,   349,
     222,     0,   221,     0,   186,     0,     0,     0,   566,   637,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   563,
     549,   554,     0,   550,   553,   552,   646,     0,   645,   568,
       0,    11,   172,   433,   410,   409,     0,  1178,     0,     0,
     447,  1672,  1670,  1671,  1667,  1669,  1666,  1668,  1660,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,     0,
     669,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   546,   547,   548,   460,     0,     0,
     459,   469,     0,     0,   414,     0,     0,   415,   405,   411,
     413,   416,   417,   418,   419,   420,   412,     0,     0,     0,
       0,     0,     0,     0,    12,    93,     0,   966,     0,   951,
     198,     0,     0,   262,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,   186,   234,   237,
     978,   713,   891,   978,     0,  1948,  1950,  1172,  1791,   862,
       0,   978,     0,     0,   315,   280,     0,     0,   290,   307,
     281,   306,     0,   299,     0,   322,     0,   316,     0,   341,
       0,   346,   336,     0,     0,   325,   278,   335,   525,     0,
       0,   537,     0,     0,   534,   533,   536,   532,   543,   528,
     528,     0,     0,   528,     0,   551,     0,   555,     0,   298,
       0,   535,   542,   282,     0,  1244,  1731,     0,     0,     0,
       0,     0,   436,     0,     0,   450,     0,     0,     0,     0,
     452,   451,   470,   461,   476,   479,   480,   477,   483,   482,
     481,   471,   472,   473,   474,   475,   421,   462,   466,   484,
     478,   465,   484,   444,   495,   492,   501,   498,   526,     0,
      98,   486,    94,    95,    97,   488,     0,     0,   235,     0,
       0,     0,   242,   243,     0,   246,     0,     0,   254,     0,
     244,   224,   208,     0,   257,   276,   984,     0,   979,   980,
     978,     0,   875,  1949,  1947,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1931,     0,  1364,  1363,     0,  1365,     0,   398,  1362,  1279,
       0,     5,  1361,   399,   396,     0,   401,   174,   484,  1147,
       0,     0,  1371,   125,   395,   394,     0,     0,   389,   484,
       0,  1315,  1924,     0,   400,   361,     0,     3,     2,     0,
     397,  1276,     0,     0,   390,   387,   383,     0,     0,     0,
       0,  1369,  1359,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1358,     0,     0,     0,   175,     0,   386,   385,
       0,     0,  1928,  1927,     0,     0,     0,   137,     0,   392,
     391,     0,     0,   388,   484,     0,     0,   484,     0,   570,
       0,     0,     0,     0,     0,     0,   484,   822,  1246,     0,
       0,  1158,     0,  1917,     0,   105,     0,     0,   904,     0,
       0,     0,     0,   823,     0,     0,  1822,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   684,     0,     0,  1952,
    1953,  1954,  1955,  1956,  1957,  1958,  1959,  1960,  1961,  1962,
    1963,  1964,  1965,  1966,  1967,  1968,  1969,  1970,  1971,  1972,
    1973,  1974,  1975,  1976,  1977,  1978,  1979,  1980,  1981,  1982,
    1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,
    1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,   933,  2001,
    2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,
    2012,  2013,  2014,  2015,  2016,  2017,  1138,  1140,  1135,  1137,
    1136,  1139,  2018,  2019,  1269,  2020,  1275,  1274,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,  1426,  2031,
    2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  1951,   863,
     581,     0,   900,     0,   898,     0,   343,   216,   217,     0,
     292,   297,     0,     0,     0,     0,   345,   348,     0,   220,
       0,     0,   567,     0,   641,     0,   643,     0,   506,   504,
       0,   528,     0,   505,     0,     0,   565,     0,   562,   559,
     530,   503,   569,     0,   171,  1733,  1734,  1732,     0,   438,
    1243,     0,  1665,  1243,   437,  1243,  1243,  1243,  1243,  1243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   964,     0,   211,   275,
     226,     0,     0,   186,     0,     0,     0,     0,     0,  1250,
       0,     0,  1238,   380,   378,   379,  1273,  1073,  1072,  1078,
       0,  1639,  1640,     0,     0,  1299,   656,   657,  1300,  1631,
    1632,  1302,   850,  1110,  1115,  1926,   649,   124,  1939,     0,
       0,  1314,     7,     0,     6,     0,  1932,  1111,     0,  1206,
    1205,  1150,  1204,  1149,   432,  1372,  1360,     0,  1270,   876,
     422,  1793,  1366,   126,     0,  1114,   123,     0,   829,    24,
     651,   384,     0,   828,  1106,   830,     0,  1370,   926,   925,
     928,   924,   927,  1941,     0,   922,     0,   650,  1010,   923,
    1935,     0,  1925,   122,  1272,  1007,   717,  1005,     0,   647,
    1920,   765,   764,   766,   762,     0,     0,  1271,  1020,   652,
    1425,     0,  1907,  1420,  1423,  1897,  1900,  1901,  1903,  1906,
       0,     0,     0,     0,  1079,  1074,     0,  1059,  1060,  1061,
    1062,  1068,  1070,  1069,  1067,  1066,     0,     0,     0,  1065,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1051,  1042,  1043,   993,     0,   991,  1093,
     430,    24,     0,  1922,   127,   648,     0,  1247,  1245,  1171,
       0,  1782,     0,  1783,  1172,  1160,  1151,  1373,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,   954,     0,
      69,     0,   103,   624,     0,   671,   670,     0,  1141,  1027,
    1145,     0,     0,  1094,  1264,     0,     0,  1148,   676,   673,
     674,     0,   678,   679,     0,   681,   682,     0,   677,   988,
     990,     0,     0,   989,   767,   986,   728,   982,   945,     0,
       0,     0,     0,   688,   689,     0,     0,   943,   940,   941,
     937,   938,   939,   932,   936,   935,     0,     0,     0,     0,
       0,     0,   585,   587,   579,   582,   583,   902,  1950,   897,
     899,   869,     0,   294,   296,   323,   317,     0,     0,   326,
     638,   640,     0,     0,     0,     0,   528,   511,     0,   528,
     528,     0,   556,     0,   291,     0,     0,  1761,  1656,  1658,
    1817,  1821,  1762,  1662,  1759,     0,     0,  1758,     0,     0,
       0,  1760,     0,     0,     0,     0,     0,     0,     0,  1907,
    1657,  1757,  1659,  1746,     0,  1735,  1737,  1741,  1744,  1772,
    1815,  1773,  1818,  1908,  1898,  1745,  1181,  1673,  1180,  1179,
    1182,  1184,  1183,  1177,   463,   464,   468,   453,     0,   456,
     467,     0,   455,   496,   493,   502,   499,   527,   487,    96,
     489,   952,     0,   247,   231,     0,   229,   255,   245,   235,
     258,   985,   176,   981,   892,   176,     0,     0,     0,  1344,
    1345,     0,     0,     0,  1316,  1319,  1321,  1322,  1323,  1327,
    1326,  1324,  1325,     0,     0,     0,  1317,  1318,     0,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,    24,  1201,
    1203,  1202,     0,   425,   426,   423,   424,   998,     0,     0,
     366,    25,   360,     0,  1107,     0,  1106,     0,  1105,     0,
       0,     0,     0,     0,     0,  1014,  1792,     0,     0,     0,
       0,     0,     0,  1922,     0,     0,   138,     0,     0,  1024,
    1016,  1017,  1022,     0,     0,  1899,     0,  1910,  1421,  1422,
       0,     0,   942,   428,  1891,  1037,   350,     0,     0,   571,
     629,   628,   626,   631,  1045,   630,  1050,  1046,  1049,   821,
     813,   807,   819,   820,   805,   806,   814,   809,   815,   808,
     818,   812,   816,   811,   817,   804,   810,   797,   803,  1047,
    1048,     0,  1055,  1063,  1052,  1053,  1057,  1058,  1056,  1054,
    1064,     0,     0,     0,   831,     0,     0,     0,     0,     0,
     777,   776,   773,  1923,  1930,    24,  1167,  1168,  1169,  1170,
    1164,     0,  1162,  1260,  1172,  1152,  1153,  1156,  1174,  1918,
       0,     0,     0,     0,    99,     0,   100,     0,     0,     0,
      74,     0,     0,     0,   112,   107,     0,   672,   931,     0,
     930,     0,   484,  1143,     0,   973,   974,   997,   968,   969,
     824,   995,  1096,  1266,     0,  1268,  1267,  1826,  1829,  1831,
       0,  1824,  1827,  1828,   704,     0,     0,     0,   693,   728,
     728,   725,     0,     0,   729,     0,    26,   692,   695,     0,
     702,   698,   944,   934,  1789,  1790,  1780,  1780,  1390,     0,
       0,  1692,     0,     0,  1374,     0,     0,  1375,  1418,     0,
       0,  1419,     0,     0,  1731,     0,  1388,     0,  1437,  1436,
    1435,  1433,  1434,  1432,  1430,  1427,  1517,  1516,  1428,  1429,
    1438,  1713,  1431,  1796,  1795,  1794,  1439,  1950,  1950,   598,
     589,   580,     0,   584,  1950,   901,   176,     0,   337,   219,
       0,     0,   529,     0,   528,     0,   515,   528,     0,   508,
     507,     0,     0,     0,   561,   560,   173,  1743,  1742,  1680,
    1678,  1679,  1675,  1677,  1674,  1676,  1661,     0,  1731,     0,
       0,  1586,     0,     0,  1749,  1747,  1748,  1586,  1586,  1586,
    1586,  1750,     0,     0,     0,  1535,  1721,     0,  1738,     0,
       0,     0,     0,  1805,  1806,  1807,  1808,  1809,  1810,  1753,
       0,     0,     0,     0,   458,   457,     0,     0,   186,   228,
     209,  1251,   176,  1239,     0,     0,     0,     0,     0,     0,
    1491,  1490,  1489,  1351,     0,  1357,  1353,  1355,  1346,     0,
    1595,  1343,  1339,  1313,  1312,     0,  1338,  1334,     0,  1330,
    1328,     0,  1638,     0,  1641,  1643,   660,     0,   659,  1630,
       0,  1633,  1635,  1940,  1937,     0,     0,  1280,   484,   358,
    1301,     0,     0,  1277,  1029,  1108,  1109,  1106,  1102,  1106,
       0,   929,     0,     0,   634,     0,     0,     0,  1008,  1006,
     719,   720,     0,   724,     0,     0,  1921,  1929,   763,     0,
     142,     0,  1018,  1025,     0,     0,  1033,  1902,  1915,     0,
    1913,  1424,  1905,  1904,     0,     0,     0,  1039,   353,     0,
       0,     0,     0,    24,  1075,  1076,   574,     0,     0,     0,
     798,   799,  1044,   994,   992,   832,   431,     0,  1085,   774,
     778,   775,   779,   381,     0,  1172,  1161,  1261,  1176,  1159,
    1154,     0,     0,  1155,  1950,     0,     0,     0,     0,     0,
       0,     0,    64,    93,     0,     0,   118,   113,     0,   108,
       0,   115,   109,   915,   907,   913,     0,  1142,     0,  1144,
    1146,     0,     0,   977,     0,     0,     0,     0,  1095,  1265,
       0,     0,  1823,  1825,  1950,   675,   680,   683,   696,   694,
     653,     0,   752,   750,   748,   746,   756,   754,     0,     0,
     744,   794,   742,   727,   738,   736,   792,   768,     0,   730,
     740,   987,   983,     0,     0,     0,     0,   701,     0,     0,
       0,     0,     0,     0,     0,  1646,     0,  1512,  1513,  1801,
    1470,  1535,     0,     0,     0,  1799,     0,  1450,  1445,  1444,
    1457,  1456,  1461,  1461,  1459,  1460,  1451,  1446,     0,     0,
    1452,  1453,  1714,  1833,     0,     0,     0,   586,   588,     0,
       0,   601,   593,   595,     0,   590,   591,     0,     0,   609,
     611,     0,     0,   607,   903,   870,   218,     0,   642,   644,
     639,     0,   528,   517,     0,   512,     0,     0,   528,   528,
     558,   557,     0,     0,  1770,  1662,     0,     0,  1745,  1588,
    1589,  1587,     0,  1774,     0,     0,     0,     0,     0,     0,
       0,  1736,     0,  1523,  1524,  1526,  1529,     0,  1536,  1537,
       0,     0,  1586,  1723,  1717,  1739,  1755,  1756,  1754,  1752,
       0,     0,     0,  1909,   454,   490,     0,   230,  1207,   893,
    1185,     0,     0,     0,     0,  1351,     0,     0,     0,  1347,
       0,     0,     0,  1341,  1626,  1624,  1593,  1605,  1607,  1611,
    1613,  1604,  1598,  1603,  1617,  1596,  1625,  1601,  1616,  1602,
    1623,  1615,  1497,  1590,  1591,  1592,     0,  1336,  1332,     0,
       0,  1320,     0,     0,   658,     0,     0,     0,  1936,     0,
       4,     8,    10,     0,   484,   427,     0,     0,     0,  1026,
    1104,  1103,     0,     0,     0,     0,     0,     0,     0,     0,
     718,     0,     0,   159,   157,     0,     0,   139,     0,   149,
     155,   728,   144,   146,     0,  1023,  1034,  1035,     0,     0,
    1911,   429,     0,  1892,  1893,  1038,     0,     0,  1036,   352,
     357,   636,   351,     0,   354,   359,     0,   484,  1396,   627,
     625,     0,   801,  1084,  1086,     0,   382,  1165,  1163,     0,
    1175,  1157,     0,     0,  1256,     0,     0,     0,   101,     0,
       0,    75,    81,    71,  1950,  1950,   111,   106,   120,   116,
       0,   110,   795,   916,   653,  1950,   906,   905,   914,  1028,
       0,     0,   975,   976,   970,   996,   484,  1101,  1097,  1098,
    1100,  1830,  1832,   705,   699,   697,     0,    24,     0,  1950,
    1950,  1950,  1950,  1950,  1950,   758,   732,   760,   734,  1950,
    1950,  1950,  1950,     0,   726,   731,  1950,   653,   790,   788,
     791,   789,     0,     0,    46,    44,    41,    35,    39,    43,
      38,    31,    40,     0,    34,    37,    32,    42,    33,    45,
      36,     0,    29,    47,   782,     0,   703,  1781,     0,  1779,
    1731,  1777,  1718,  1719,  1711,  1697,  1712,     0,     0,     0,
    1071,  1511,  1514,     0,     0,     0,  1408,  1380,  1804,  1803,
    1802,     0,     0,     0,  1455,  1458,     0,     0,     0,     0,
       0,  1403,     0,  1402,     0,  1404,  1399,  1400,  1401,  1392,
    1393,     0,     0,     0,   600,   605,     0,     0,  1950,  1950,
     578,   592,   615,   603,   617,  1950,  1950,   613,   597,   608,
     862,   338,   528,     0,   516,   528,     0,   528,   528,   510,
     509,  1687,  1685,  1686,  1682,  1684,  1681,  1683,  1663,     0,
       0,     0,     0,  1771,     0,     0,     0,  1769,     0,     0,
       0,     0,  1751,  1768,     0,  1527,     0,     0,  1655,  1530,
       0,     0,     0,     0,  1522,  1541,  1543,  1545,  1585,  1584,
    1583,  1547,  1563,     0,  1538,  1539,  1726,  1303,     0,     0,
       0,  1816,     0,  1820,   212,     0,  1233,  1252,   862,     0,
    1240,  1233,     0,  1647,     0,  1479,     0,  1482,  1650,     0,
    1487,     0,     0,  1348,  1349,     0,     0,  1352,  1354,  1356,
       0,  1340,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1495,  1494,  1493,     0,  1498,  1499,     0,  1335,
       0,  1329,  1331,  1642,     0,  1644,  1634,     0,  1636,  1938,
    1309,     0,  1305,     0,     0,  1310,   877,     0,     0,     0,
       0,     0,  1367,  1943,  1942,   635,     0,     0,    48,     0,
     721,   723,   722,  1368,   728,  1950,  1950,   151,   661,   161,
     153,   163,   143,   150,  1950,     0,     0,     0,     0,     0,
    1914,     0,     0,     0,     0,     0,     0,  1077,     0,  1397,
     572,     0,   800,  1082,     0,  1262,  1263,  1919,     0,    93,
       0,    65,     0,     0,     0,    78,     0,    93,    93,   119,
     114,  1950,  1950,   104,     0,   917,   911,   919,   918,   908,
     622,   957,     0,     0,     0,   707,   686,   700,   654,   769,
       0,   753,   751,   749,   747,   757,   755,     0,  1950,     0,
    1950,   745,   743,   739,   737,   793,   741,    24,   783,     0,
       0,     0,    27,     0,  1784,     0,  1698,     0,     0,  1710,
    1693,  1709,  1515,     0,  1472,     0,  1407,     0,     0,  1800,
       0,  1797,     0,  1463,  1467,  1443,  1465,  1468,     0,  1454,
    1715,     0,     0,     0,     0,     0,     0,  1834,  1406,  1405,
    1394,  1389,  1391,  1442,     0,     0,   602,   599,   594,   596,
       0,  1950,  1950,   610,   612,  1950,  1950,     0,   518,     0,
     522,     0,     0,   514,   513,     0,     0,     0,     0,     0,
       0,  1767,  1775,  1763,  1764,  1765,  1766,  1532,     0,  1525,
    1531,  1546,  1550,     0,  1563,  1549,     0,     0,  1564,  1579,
    1576,  1577,  1574,  1582,  1581,  1575,  1578,     0,     0,     0,
       0,     0,  1580,     0,     0,     0,  1519,  1520,  1740,     0,
    1540,  1534,  1304,  1724,  1413,  1409,  1410,  1415,  1414,  1722,
    1303,     0,     0,  1231,  1232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1230,     0,     0,  1218,
    1219,  1220,  1217,  1222,  1223,  1224,  1221,  1208,  1199,     0,
       0,  1255,     0,  1950,     0,  1194,     0,     0,     0,     0,
       0,     0,     0,  1186,  1187,     0,  1116,  1651,     0,  1652,
       0,     0,     0,     0,  1486,  1485,  1351,  1484,  1476,  1342,
    1627,     0,     0,     0,     0,     0,     0,  1628,  1620,     0,
       0,     0,  1620,  1656,  1492,  1505,  1510,     0,  1507,  1504,
    1506,     0,  1508,  1496,  1500,  1501,  1351,  1337,  1333,     0,
       0,  1308,  1307,     0,  1292,     9,     0,  1282,   878,  1113,
     364,  1282,     0,     0,  1934,     0,     0,  1009,    49,     0,
     780,   160,   158,     0,  1950,     0,     0,     0,  1950,   156,
     145,     0,   148,   147,     0,  1015,  1019,     0,  1896,  1895,
    1894,     0,     0,   356,     0,   575,     0,  1950,   802,     0,
     653,  1166,     0,  1257,    70,     0,     0,   102,    68,    93,
      76,    82,     0,   121,   117,   796,  1950,   921,   653,   920,
       0,   619,     0,   826,   827,   825,  1099,   710,   708,     0,
     690,   687,     0,   759,   733,   761,   735,   770,   786,   787,
     784,   785,    30,    28,     0,  1778,  1727,  1699,  1695,  1694,
       0,  1471,  1731,  1474,     0,  1382,  1377,  1376,  1379,     0,
       0,  1462,     0,     0,  1727,     0,     0,  1871,  1869,     0,
       0,  1853,  1868,     0,     0,  1870,     0,     0,     0,     0,
       0,  1907,  1867,  1859,  1886,  1887,     0,  1851,  1854,  1855,
    1866,  1858,  1888,     0,  1844,  1843,  1847,  1849,     0,  1842,
       0,  1845,  1836,     0,     0,   606,   604,   616,   618,   614,
       0,     0,   528,     0,   528,   528,     0,  1730,     0,  1663,
       0,     0,     0,  1528,  1548,  1542,  1544,  1551,  1553,  1551,
       0,  1558,  1551,     0,  1556,  1551,     0,  1566,  1565,     0,
    1567,     0,  1518,     0,  1417,  1416,  1412,  1725,     0,   235,
    1225,  1226,  1227,  1229,  1212,  1210,  1209,  1213,  1214,  1211,
    1228,  1215,  1216,  1200,  1002,  1235,   999,     0,     0,  1253,
       0,  1198,  1197,  1192,  1190,  1189,  1193,  1191,  1195,  1196,
    1188,  1241,     0,  1477,  1483,  1654,  1647,  1488,  1350,  1594,
    1606,     0,  1608,  1610,     0,  1612,     0,     0,     0,  1618,
    1597,  1622,     0,  1478,  1480,     0,  1502,  1503,  1645,  1637,
    1306,     0,     0,  1298,  1293,  1294,  1311,     0,  1289,  1290,
       0,     0,  1303,  1283,  1284,     0,    24,  1278,     0,     0,
    1032,     0,    50,  1012,     0,    24,   162,   152,     0,   663,
     665,   164,   154,   780,     0,  1912,  1041,     0,   355,  1398,
       0,  1083,    24,     0,     0,    66,     0,    79,    88,     0,
      72,   912,   909,   623,  1950,   971,     0,  1950,   706,   685,
     691,   653,  1788,     0,  1786,     0,     0,  1700,  1696,  1473,
       0,  1475,  1469,     0,  1381,     0,  1798,  1464,  1466,  1441,
       0,  1857,  1856,     0,     0,  1586,     0,  1586,  1586,  1586,
    1586,  1860,     0,     0,  1840,     0,     0,     0,     0,  1873,
    1841,     0,     0,     0,     0,     0,     0,  1835,  1395,  1447,
     872,   871,   339,   519,     0,     0,   524,   523,  1688,  1811,
    1814,  1812,  1533,     0,  1570,  1572,     0,  1559,  1562,  1561,
    1569,     0,  1571,  1551,     0,  1521,  1411,  1819,   213,  1004,
    1003,  1001,     0,  1234,  1117,  1121,  1123,     0,  1127,     0,
    1125,  1129,  1118,  1119,     0,   894,     0,     0,  1648,  1653,
       0,     0,  1629,  1621,  1599,     0,  1600,     0,     0,  1296,
    1291,  1297,  1295,  1288,  1287,  1286,  1281,  1285,   365,   362,
       0,  1030,     0,     0,     0,  1011,   781,   140,   662,    24,
    1021,  1040,   573,  1080,    67,  1258,    84,     0,     0,    77,
      88,    88,  1950,   620,     0,     0,   709,   771,     0,  1785,
    1728,  1721,     0,  1383,     0,  1721,  1884,     0,     0,  1889,
       0,     0,     0,     0,     0,     0,     0,     0,  1852,  1875,
    1876,  1874,  1872,  1850,     0,  1846,  1848,  1837,  1838,  1448,
       0,  1440,   528,   528,  1552,  1776,  1554,     0,  1557,  1555,
    1573,     0,  1000,  1950,  1950,  1131,  1950,  1133,  1950,  1950,
    1120,  1254,  1242,     0,  1609,     0,  1619,     0,  1509,   367,
    1031,  1933,     0,     0,     0,     0,     0,     0,    55,     0,
      54,     0,    52,     0,     0,   141,  1087,    88,    93,    88,
      89,    83,    73,   910,     0,     0,   711,    24,  1787,  1720,
    1729,  1387,     0,  1384,  1386,  1701,  1885,     0,     0,  1883,
       0,     0,     0,     0,     0,  1861,  1882,     0,  1449,   521,
     520,  1560,  1568,  1122,  1124,  1950,  1128,  1950,  1126,  1130,
    1649,  1614,  1481,   369,   374,   372,   363,     0,   370,   376,
      57,    62,    59,    61,    58,    60,    56,     0,    51,     0,
     664,   666,  1091,  1081,     0,  1089,  1259,    85,    80,   621,
     972,  1950,   772,     0,  1378,     0,  1702,  1716,  1881,  1890,
    1877,  1878,  1879,  1880,     0,  1862,     0,     0,  1132,  1134,
    1950,  1950,   368,   371,  1950,    53,     0,  1950,  1088,  1090,
       0,   707,  1385,     0,  1706,  1703,  1704,     0,     0,  1839,
     375,   373,   377,     0,  1092,    86,   712,     0,     0,     0,
    1864,     0,  1863,  1013,    90,     0,  1707,  1705,     0,    92,
       0,    87,     0,  1865,    91,  1708
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   829,   830,   831,   832,  1053,  2110,  2111,   182,   323,
     183,  1420,  1421,  1934,  2271,  3320,  2797,  2798,  3223,  3321,
    3322,   833,  1196,  2835,  2528,  3241,  1873,  2526,  3088,  2839,
    3237,  2527,  3089,  3328,  3430,  3454,  3239,  3461,   651,   652,
     653,  1545,  2187,   834,  1556,  1201,  1554,  1881,  2197,  1878,
    2195,  2200,  2532,  1555,  2194,  1882,  2531,   835,    10,    30,
      31,    32,    33,    34,   837,  1116,  1810,  1446,  2137,  2141,
    2142,  2138,  2139,  2804,  2808,  2494,  2486,  2485,  2487,  2490,
     497,   273,   604,   838,    58,    59,    12,    44,   116,    73,
      74,    75,    76,   198,   337,    77,    78,   244,   342,   230,
    1016,   521,  2692,   373,   939,  1997,   401,   402,   231,   355,
     344,   350,  1365,  1366,   120,   539,   121,   122,   361,   232,
     357,   343,   345,   523,   233,   258,   577,   246,   249,   247,
     248,   957,   555,   556,   558,   563,   942,   250,   251,   392,
     560,   194,    13,    54,   152,   153,   154,   948,  2627,   155,
     254,   242,   395,   396,   397,   398,  1833,   839,   840,   841,
     842,  1074,  3309,  3056,  1422,  3376,  3377,  3378,  3421,  3420,
    3424,   843,   844,   845,   846,   847,   848,   849,  1064,   498,
    1069,  1414,  1415,  1462,  1169,  1463,   300,   301,   302,   303,
     304,   455,   499,  1348,   500,   501,   502,   503,   504,   505,
     506,   993,   184,   515,  1003,  1005,  1726,   185,   509,   999,
     508,   998,   511,  1001,   510,  1000,   958,   971,   305,   306,
     187,   307,   422,   423,   424,   425,   407,   427,   850,  1136,
    1836,  2827,  2168,    90,   239,   549,  1650,  1264,  1265,  1266,
    1647,  1648,  1984,  1985,  1986,  2328,  2329,  1651,  1652,  1980,
    2332,  2324,  1992,  1993,  2335,  2336,  2625,  2621,  2622,   851,
    3094,  3334,  2851,   852,  1474,    60,  1795,  1796,  2162,   408,
     429,  1108,  1174,  1045,  1096,  1079,  1118,  2227,   188,  1046,
    1036,  1767,  2489,    62,   308,   853,  1206,   854,  1219,  1220,
     855,   856,   857,   858,  1227,  2860,  1248,  3099,  1249,  1908,
    1250,  2224,  1251,  2546,  1252,  1937,   859,  1904,  2545,  2859,
    3097,  3096,  3401,    91,    14,    15,   860,  1440,  1800,  1801,
    1802,  1927,  1595,  1928,  1929,  2558,  2560,  2242,  2241,  2246,
    2240,  2239,  2232,  2231,  2230,  2229,  2234,  2233,  2236,  2238,
     861,   862,  1114,   863,  1591,  1234,  3337,   864,  1522,  3065,
    2273,  2274,  1930,  2243,  2203,  2534,  1163,  1502,  1840,  2171,
    1841,  1498,   865,   866,  1212,  1896,  2855,   867,   868,   869,
     870,    16,    48,    17,    18,    19,    92,    93,   871,    94,
      20,   930,    21,    95,    96,   132,   551,  1656,  2340,  3151,
      97,   128,   366,   872,  2467,    22,    23,    24,    25,    26,
      43,    65,    98,   680,  1732,  2408,    99,   240,   550,   933,
     934,  1268,  1654,   873,  1207,  2207,  1885,  2205,  3242,  2846,
    1886,  2204,  2537,  2848,   874,   875,   876,  1090,  1091,  1559,
     877,  1253,  1254,   878,  1603,  1255,   309,    67,    68,    69,
      70,  1566,   158,   112,    71,   109,   190,   191,  1567,  1568,
    2214,  1569,   677,   678,  1236,   679,  1237,  1167,  1168,  1570,
    1571,  1418,  2995,  2996,  3181,  1106,  1107,   879,  1435,  3225,
     880,  2816,   881,  1450,  1451,  1452,  1816,  1814,   882,   883,
    2119,  2148,   884,  1827,  2158,   885,  1164,  1165,   886,  1029,
     887,  2284,   888,  3326,  2830,   889,  2175,  3393,  3394,  3395,
    3427,  1171,   890,  1572,  1898,  2218,  2219,   891,  1428,  1787,
    1044,  1407,   892,   893,   894,  2410,  2999,  3192,  3193,  3293,
    3294,  3298,  3296,  3299,  3365,  3367,   895,   896,  1561,  1890,
     897,  1563,  1534,  1535,  1536,  1863,   898,  1186,  1184,   899,
     900,  1855,  1530,  1180,   197,  1537,  1538,   310,  2411,  2733,
    2734,  2717,  1061,  1062,  2406,  2718,  2721,   100,   127,   543,
    1375,  2060,  2735,  3196,   437,   901,  1178,   101,   124,   540,
    1372,  2058,  2722,  3194,  2407,  1200,  2519,  3084,  3327,  1858,
     902,   903,   904,   905,   906,  1077,  2117,  1055,  2113,  3052,
    3053,  3054,  3209,  3043,  3044,  3045,   907,  2683,  2461,  2462,
    2464,  1751,   908,   909,  1384,  1385,  1386,  1760,  2099,  1387,
    2096,  1757,  1388,  2072,  1752,  1389,  1390,  1391,  2064,  2069,
    1392,  1746,  1747,   910,  1086,  1066,   911,  1628,  1629,  1952,
    2887,  3115,  2588,  2884,  3342,  3343,  1630,  1974,  1609,  2320,
    2611,  2933,  2510,  2826,  2321,  1631,  1632,  2043,  2685,  2686,
    2687,  2976,  1633,  1634,  1459,   912,  1123,   913,  1261,  1635,
    1636,  1968,  3281,  1969,  1970,  1971,  2304,  2592,  2595,  2596,
    1637,  2294,  2583,  3112,  1740,  1741,  2772,  2414,  3033,  2415,
    1742,  2419,  1753,  2446,  1754,  2447,  2773,  2774,  2775,  2776,
    1638,  1946,  1947,  2291,  1639,  2680,  2394,  2676,  2038,  1705,
    2033,  2034,  2035,  2648,  1706,  2039,  2395,  2681,  2384,  2385,
    2386,  2387,  2388,  3164,  2957,  3284,  2389,  3166,  3167,  2674,
    2390,  2675,  2391,  2022,  2092,  2093,  2094,  3027,  2095,  2751,
    2758,  3203,  2416,  1033,  2597,  2739,  2926,  2418,  2379,  1321,
     311,  1322,  1686,   448,   449,  1687,  2358,    42,   914,   915,
    2879,  3108,  2576,  3107,  3407,  3435,  3436,  2580,  2285,  1640,
    2286,  2309,  2894,   607,  2281,  2282,  2044,  2397,  3106,  2883,
    1323,   978,  1324,  1325,  2677,  2392,  1327,  1328,  2024,  3286,
     916,   917,  1939,  2283,  2875,  3103,  3104,  1606,   918,  1072,
    1642,  1643,  1956,  2590,  1644,  1645,  2300,  1719,  2017,  1329,
    1330,  1331,  1332,   919,  1215,  1580,  1581,  1582,  1900,  1583,
    1901,  1646,  2310,  2932,  3147,  2607,  2929,  2930,  2931,  2928,
    2916,  2917,  2918,  2919,  2920,  2921,  3260,   920,  1825,  2153,
    2154,  1124,  1333,  1334,  1126,  1127,  1128,  1335,  1129,  1457,
    1819,  1820,    27,   922,  1188,  1864,  1443,  1524,   923,   924,
    2478,   925,  2108,  1049,  1774,   926,   927,    37,   544,   545,
     546,   547,   548,   928
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2624
static const short yypact[] =
{
     953,  1695, -2624,   291,   291,   291,  1336, -2624, -2624,  1336,
   -2624,    11, -2624, -2624, -2624, -2624,   409, -2624,   953, -2624,
   -2624, -2624, -2624, -2624,   -69, -2624, -2624, -2624, -2624, -2624,
     407,   424, -2624,   431, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624,  -170, -2624,   933,    74, -2624, -2624, -2624,  1135, -2624,
   -2624, -2624, -2624, -2624,  -140,   291, -2624,   291,   279,    11,
   -2624,  1130, -2624, -2624, -2624, -2624, -2624, -2624,  1366,   -55,
   -2624, -2624, -2624,   591,   257,   291, -2624, -2624,   773,   291,
   -2624, -2624,   291,   291, -2624, -2624, -2624,   291,   291, -2624,
   -2624, -2624, -2624,  1135, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,  5114, -2624,   -55, -2624,   969,  1242, -2624,
   -2624,   123, -2624, -2624,   938,    74,   397, -2624, -2624, -2624,
   -2624, -2624,  8871, -2624,   291,   538,   795,   291,    11, -2624,
   -2624, -2624,   291, -2624, -2624,   680,   589,   954, -2624, -2624,
     628, -2624,   665, -2624,   647, -2624, -2624,   701, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   721, -2624,
   -2624, -2624,   753,   758,   782,   801,   825,   837,   847,   858,
     862,   868,   898,  1242,   950,  4797,   968,   972,   978,   990,
    1009,  1024,  1892,  1062, -2624, -2624, -2624, -2624,  1087, -2624,
     220, -2624,  1242, -2624,   174, -2624, -2624, -2624,   152, -2624,
   -2624, -2624,   843, -2624, -2624, -2624, -2624, -2624, -2624,   680,
    1030,  1035,  1040, -2624,   954, -2624, -2624,  1044, -2624,  1052,
   -2624,  1020, -2624, -2624,  1069, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,  1089,  1552,   291,  1120, -2624,    11,
      11,  1123,   291, -2624,   690,  1588, -2624,   946,  1028, -2624,
     949,  1153,  1603,  1619,   291,  1651,  1671, -2624,   979, -2624,
     297,    43,    43,    43,    43,    43,  4797,  1725,  1612,    71,
    4797,  1022,  4797, -2624,  4797,  4797,  4797, -2624, -2624, -2624,
    1125,  1233,  1245,  4797,  1156,  1253, -2624,  4797,  4797,  1264,
   -2624,  1270, -2624,   972,  1273,  1295,  1298,  1314,  1733,  7246,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  1333,
   -2624, -2624, -2624, -2624, -2624, -2624,   297,   297, -2624, -2624,
   -2624, -2624, -2624,  1242, -2624, -2624,   291,  1242,  1304,   247,
   -2624, -2624, -2624, -2624,  1783, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,  1342, -2624,  1342,   690,  1804,  1814,  1830,
   -2624, -2624, -2624,  1843,  1850,    74,  1651,  1342,  1856,  1148,
   -2624,  1776, -2624,  1454,  1424, -2624,  1502, -2624, -2624, -2624,
    1252, -2624, -2624,  1902,  1497, -2624,  1476, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,  1153,  1476, -2624, -2624, -2624, -2624,
   -2624, -2624,  1483,   199,   200,   293, -2624,  1795, -2624, -2624,
   -2624,  1493,  1990,   217, -2624,  1551,  1515,   260, -2624,  -242,
    1553,  1554,   262,   275,  6266,  1555,  1558,   205,  1387, -2624,
   -2624,   130,  1559, -2624, -2624, -2624, -2624,   286, -2624, -2624,
    6309, -2624,  3284,  7575,  3635,  3635,  4797, -2624,  1486,  4797,
    7246,  1523, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  1338,
    1996,  6331,  7246,  1486,  1997,   542,  4797,  4797,  4797,  4797,
   -2624,  4797,  4797,  4797,  4797,  4797,  4797,  4797,  4797,  4797,
    4797,  4797,  4797,  4797,  4797,  4797,  4797,  4797, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  4797,  4797,
   -2624, -2624,  1535,  4797, -2624,  4797,  1538, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,   297,  4797,  4797,
    4797,  4797,  1584,  2022,  1892,  3938,  1548, -2624,  1242,  1521,
   -2624,  1360,  2012, -2624,  1369, -2624,  2017,  1599,  1600,   361,
    1732,   364,   365,   304,  1569, -2624,   415, -2624, -2624, -2624,
     291, -2624, -2624,   291,  1634, -2624,  5066,   397,  5595,  2023,
    -257,   291,  2034,   524, -2624, -2624,  1028,  2029, -2624, -2624,
   -2624, -2624,  2030, -2624,  2031, -2624,  2035, -2624,   291, -2624,
     291, -2624, -2624,  1651,  2036, -2624, -2624, -2624, -2624,   291,
      43, -2624,  1242,    51, -2624, -2624, -2624, -2624, -2624,  1028,
    1028,  2040,  -119,  1028,  1562, -2624,  2041,  1428,  1629, -2624,
      71, -2624, -2624, -2624,  1625,  7246,    21,  1630,  6376,  2044,
    1156,  1637, -2624,  1639,  1642, -2624,  6576,  6635,  6683,  6880,
    7326,  7490,  7575,  7681,  7744,  3485,  7800,  7987,  8009,  8175,
    8183,  3635,  3635,  3738,  3738,  8240,  7246,  6942,  7052,  1486,
    7246,  7139,  1486, -2624,  7246,  7246,  7246,  7246, -2624,  2068,
   -2624, -2624,  2090, -2624,  7246, -2624,   269,  1242, -2624,  1650,
    2078,   524, -2624, -2624,  2075, -2624,  1621,  2079, -2624,  2081,
   -2624, -2624, -2624,  2082, -2624, -2624,  1441,  1667,  2111, -2624,
     291,  1672, -2624, -2624, -2624,   297,   297,   297,   291,  1006,
     291,  1647,   289,   289,  1661,   291,   291,   289,   289,   291,
   -2624,  1647, -2624, -2624,   291, -2624,  1077, -2624, -2624, -2624,
     289, -2624, -2624, -2624, -2624,   291, -2624, -2624, -2624, -2624,
     142,   142,  4797, -2624, -2624, -2624,  1661,  1661, -2624, -2624,
     289, -2624, -2624,   289, -2624, -2624,   291, -2624, -2624,   289,
   -2624, -2624,   297,   289, -2624, -2624,  4797,   289,   297,   291,
     297,   289, -2624, -2624,   222,   289,   289,   222,   289,   291,
     222,   289, -2624,   289,   289,   289, -2624,  1647, -2624, -2624,
     297,   289, -2624, -2624,   289,    66,   291, -2624,  1661, -2624,
   -2624,   289,  1023, -2624, -2624,   297,  1440, -2624,   289, -2624,
    2444,   297,  4797,    43,    43,   289, -2624, -2624,  1006,   297,
     387, -2624,  4797, -2624,  1315,  4797,   289,    87, -2624,  4797,
     289,  2094,   297, -2624,   289,  4797, -2624,  4797,   142,   291,
     289,   291,    43,   289,   291,    43, -2624,   291,   263, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   486, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  1216, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
    1041,   291, -2624,   417, -2624,  1675, -2624, -2624, -2624,  1767,
   -2624, -2624,  1678,  1684,  1685,  1689, -2624, -2624,  1461,  2132,
    1698,  1699, -2624,   490, -2624,  1663, -2624,  1470, -2624, -2624,
     500,  1028,  2124, -2624,  1705,   576, -2624,  2126, -2624,  1513,
   -2624, -2624, -2624,  1478, -2624, -2624, -2624, -2624,  8475, -2624,
    1125,  1711, -2624,  1125, -2624,  1125,  1125,  1125,  1125,  1125,
    2133,  2137,  2139,  4797,  1719,  2141,  4797,  1723,  1724,  1728,
    1731,  1735,  1742,  1743,  3938,  3938, -2624,   274, -2624, -2624,
   -2624,  1822,  1744, -2624,  1746,  1748,  1496,  1749,   291, -2624,
     291,  1750, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
     461,  1508,   273,  1587,  1714, -2624, -2624, -2624, -2624,  1527,
     636, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  2192,
    1526, -2624, -2624,  1726, -2624,  1661, -2624,  1673,   211, -2624,
   -2624, -2624,  1598, -2624,  7246, -2624, -2624,  1561, -2624, -2624,
    4499, -2624, -2624, -2624,   297, -2624, -2624,  1661, -2624,   -75,
   -2624, -2624,  1886, -2624,   161, -2624,  1697, -2624, -2624, -2624,
   -2624,  2205, -2624, -2624,   767, -2624,  1542, -2624,  1543,  2205,
   -2624,  1566, -2624, -2624, -2624,  1745,   117, -2624,  1703, -2624,
    1506, -2624, -2624, -2624, -2624,  1507,   836, -2624,   810, -2624,
    1550,  1686,  1712,  1840,  1563, -2624, -2624,  1556, -2624, -2624,
    4797,   136,  1073,  4797, -2624,   137,   289, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624,    56,    56,    56, -2624,
      56,  3563,    56,    56,  1576,   -75,  1576,  1576,  1105,  1105,
    1576,  1576,   -75, -2624,  2224, -2624,  1758,   515, -2624,  2227,
   -2624,   -75,   128,    27, -2624, -2624,  4797, -2624, -2624, -2624,
    1137, -2624,  1114, -2624,   397, -2624,  4797, -2624,  4797,  1751,
    1753,  1755,  1756,  1766,  1757,  1114, -2624,  1833,  1132,  1606,
   -2624,  1611, -2624, -2624,   291, -2624, -2624,  1181, -2624,  2237,
   -2624,  2234,   291, -2624,   702,   212,  1622, -2624, -2624,  2245,
   -2624,  1541,  2245,  2247,  1547,  2245,  2247,  4797,  2245, -2624,
   -2624,   211,   297, -2624, -2624,  1780,   349, -2624, -2624,  1775,
     297,  4797,  1777, -2624, -2624,  2233,  2239,  2147, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624,  1247,  1247,   289,   289,
     289,  1604, -2624, -2624,  2125,  1041, -2624, -2624,   755, -2624,
   -2624, -2624,  1759, -2624, -2624, -2624, -2624,  5114,  1651, -2624,
   -2624,  1597,   291,  1028,  2246,   603,  1028, -2624,   616,  1028,
    1028,  1770,  1632,  1786, -2624,  8681,  8681, -2624,  1550, -2624,
   -2624, -2624, -2624,  1209, -2624,  8280,  1794, -2624,  1796,  1797,
    1798, -2624,  1798,  1798,  1799,  1800,  1803,  1805,   291,    55,
   -2624, -2624, -2624, -2624,   138, -2624,    37,  1815, -2624, -2624,
    1209, -2624,  1209,  1816, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  7246,   427, -2624,
   -2624,   428, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624,  1765, -2624, -2624,   434, -2624, -2624, -2624, -2624,
   -2624, -2624,    11, -2624, -2624,    11,   886,   146,  2252, -2624,
   -2624,   109,   188,   584,  2282, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,   291,  1793,   291, -2624, -2624,  1820,   291,
    1846,   291,   291,  1661,  1646,  1811, -2624,  1812,   132, -2624,
   -2624, -2624,  1661, -2624, -2624,  2291, -2624, -2624,  1628,  1818,
   -2624, -2624, -2624,  1073, -2624,  1251,  2255,  1251, -2624,  1114,
     222,  4797,  4797,  4797,  1824, -2624, -2624,   297,   297,  1661,
    1631,  1114,    43,  1601,    66,   297, -2624,  1636,  4797,  1904,
   -2624, -2624,  1707,   291,  1550, -2624,  1242, -2624, -2624, -2624,
     291,  1443,  2308, -2624, -2624,  1653,   160,   211,   297, -2624,
   -2624,  2298,  2299, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624,  2195, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624,  2444,   297,   297, -2624,  1105,  4797,  -122,  1145,  1236,
   -2624, -2624, -2624, -2624, -2624,   148, -2624, -2624, -2624, -2624,
    2110,  1876, -2624,  1888,   397,  4797, -2624,    96, -2624, -2624,
     291,  2302,    43,    43, -2624,  1687, -2624,    71,  1658,   297,
   -2624,   291,   291,  4797,   -80, -2624,  1706, -2624, -2624,   379,
   -2624,  1806, -2624,  1807,  4797,  1255, -2624, -2624,  1662, -2624,
    2333, -2624,  1741, -2624,   297, -2624, -2624, -2624, -2624, -2624,
     243, -2624, -2624, -2624, -2624,   291,    43,    43,   265,   349,
    2138,  2958,   297,   211, -2624,  1747, -2624, -2624,  2308,  2318,
    1893, -2624, -2624, -2624, -2624, -2624,  1971,  1971, -2624,   192,
    1754, -2624,   291,  1661, -2624,  1661,  1661, -2624, -2624,  1661,
    1661, -2624,   291,  1133,    21,  1661, -2624,  1133, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,   248,   248,   865,
    1155, -2624,  1072, -2624,   755, -2624,    11,  2325, -2624, -2624,
    1473,  1907, -2624,   443,  1028,  2329, -2624,  1028,  1848, -2624,
   -2624,  1911,  1912,  1859, -2624, -2624, -2624,  1356,  1356, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  1690,    21,  1915,
    8530,   596,  8475,  1841, -2624, -2624, -2624,   596,   596,   596,
     596,  1701,  8475,  8475,   219,  1788,   750,   291, -2624,  8475,
    8475,  8475,  8475, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
    1691,   430,  1073,  4797, -2624, -2624,  1923,  2325, -2624, -2624,
   -2624, -2624,    11, -2624,  1887,  1895,  1898,  1048,  1900,  1905,
   -2624, -2624, -2624,  2265,   291, -2624,  2377, -2624, -2624,   691,
    8866, -2624, -2624, -2624, -2624,   291, -2624, -2624,   691,  1670,
   -2624,   461, -2624,  1716, -2624,  1752, -2624,  1948,   -55, -2624,
    1721, -2624,  1761, -2624,  1808,  1922,   291, -2624, -2624, -2624,
   -2624,  4499,   291, -2624,  1730, -2624, -2624,  2255, -2624,  2255,
    1727, -2624,  2402,  2403, -2624,  2405,  1781,  4797, -2624, -2624,
    2411, -2624,  1760, -2624,  1882,  1762,  2247, -2624, -2624,  1768,
    1038,   291, -2624, -2624,  1935,   289,  1160,  1556,  1892,   321,
   -2624, -2624, -2624, -2624,  4797,  1661,  1073,  -255, -2624,   291,
     291,  4797,    59,   -75,  2414,   992,  2412,  2396,  2398,  3563,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,   297,  2050, -2624,
   -2624, -2624, -2624,  2306,  4797,   397, -2624,  2157, -2624, -2624,
   -2624,  4797,   142, -2624,  2049,  2427,  2428,   439,   444,   291,
    1988,  1114, -2624,  3938,  1953,  1954, -2624, -2624,  2026, -2624,
    4797,   -78, -2624,  1790, -2624, -2624,   629, -2624,  4797, -2624,
   -2624,  1769,   969, -2624,  1501,   291,  2429,  8338, -2624, -2624,
    1073,   297, -2624, -2624,    53, -2624,  2247,  2247,  1737, -2624,
    1849,  1852, -2624, -2624, -2624, -2624, -2624, -2624,    43,    43,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  3161, -2624,
   -2624, -2624, -2624,    43,  8668,  2447,  2433, -2624,  1114,   937,
     285,   134,  2300,   -22,  1006, -2624,   634, -2624, -2624, -2624,
    1978,    64,  1661,   853,  1791, -2624,  1787, -2624, -2624, -2624,
   -2624, -2624,  1980,  1980, -2624, -2624, -2624, -2624,  1867,  1778,
    2461, -2624, -2624, -2624,   876,  1792,  1801, -2624, -2624,   297,
     187, -2624, -2624, -2624,  1782,  1155, -2624,   291,   291, -2624,
   -2624,   291,   551, -2624, -2624, -2624, -2624,  1989, -2624, -2624,
   -2624,   618,  1028, -2624,   653, -2624,  2024,  2025,  1028,  1028,
   -2624, -2624,  1263,  8475, -2624,   426,  2468,  2028,  2470, -2624,
   -2624, -2624,  8475, -2624,   456,  8475,  8475,  8475,  8475,   291,
     459, -2624,   337,  2471, -2624, -2624,    67,  7632, -2624,  2055,
     291,  1809,   596,  2093, -2624, -2624, -2624, -2624, -2624, -2624,
    1263,  2455,  1263, -2624,  7246, -2624,  2003, -2624,  1970, -2624,
    1972,   168,   168,   168,   462,  2265,   168,  7632,   291, -2624,
     470,   291,   474, -2624, -2624, -2624,  2001,  2004,  2005,  1209,
    1209, -2624,  2007, -2624,  2008,  2010,  2014,  2015, -2624, -2624,
   -2624, -2624,  1223, -2624, -2624, -2624,   479, -2624, -2624,   487,
     291, -2624,   291,  1899, -2624,   291,  1913,  4797, -2624,   291,
    2481, -2624, -2624,   691, -2624, -2624,  1832,   691,   207, -2624,
   -2624, -2624,  1114,  4797,  4797,  4797,  4087,  2490,  1661,   103,
   -2624,  1114,   291, -2624, -2624,   291,   291, -2624,   987, -2624,
   -2624,   369, -2624,  1835,  4797, -2624, -2624, -2624,  2493,  1242,
    2000, -2624,  1842,  2507, -2624, -2624,  1114,  1890, -2624, -2624,
   -2624, -2624, -2624,   291,  2247, -2624,   211, -2624,  1909, -2624,
   -2624,   510, -2624, -2624, -2624,   297, -2624,  6072, -2624,  1358,
   -2624, -2624,  2134,  2491, -2624,  2122,  2127,  2013,  1855,  2128,
    2046, -2624, -2624, -2624,   699,  2115, -2624, -2624, -2624, -2624,
    2026, -2624, -2624, -2624,   270,   641, -2624, -2624, -2624,  2308,
    4797,  2053, -2624,  2021, -2624, -2624, -2624, -2624,  2528, -2624,
   -2624, -2624,  2531, -2624,  1836, -2624,  2511,   -75,   291,  3768,
    3768,  3768,  3768,  3768,  3768, -2624,  2534, -2624,  2535,  3768,
    3768,  3768,  3768,  2195, -2624, -2624,  3768,   213, -2624, -2624,
   -2624, -2624,  2517,  2529, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,  2530, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624,   511, -2624, -2624, -2624,  2519, -2624, -2624,  1661, -2624,
      21, -2624, -2624, -2624, -2624, -2624, -2624,  1903,  1908,   113,
   -2624,   634, -2624,   168,  1878,   289, -2624,  2064, -2624, -2624,
   -2624,   291,   291,   168, -2624, -2624,   125,  1661,  1379,  8475,
     324, -2624,  4797, -2624,  4797, -2624, -2624, -2624, -2624, -2624,
    1944,   289,   125,  1661,  2546, -2624,   297,   291,  1002,  1002,
   -2624, -2624,  2547, -2624,  2547,   884,   884,  2547, -2624, -2624,
    2023, -2624,  1028,  2532, -2624,  1028,  1918,  1028,  1028, -2624,
   -2624,  2074, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   138,
    1209,  1891,  1209, -2624,  1209,  2117,  8475, -2624,  2118,  2123,
    2129,  2130, -2624, -2624,   219, -2624,   219,   291, -2624, -2624,
    8192,  1798,  7430,  1798,  2565,  2566, -2624, -2624, -2624, -2624,
   -2624, -2624,   546,  8475, -2624,  2083, -2624,  2260,   215,   285,
     291, -2624,  2140, -2624, -2624,  2781,   108, -2624,  2023,  1648,
   -2624,   108,  1661,   891,  2142,  2580,  1916, -2624, -2624,   539,
   -2624,   559,  1048, -2624, -2624,   563,   249, -2624, -2624, -2624,
     691, -2624,  2564,  2564,  2567,  1914,   535,  2568,  2569,  2570,
    2568,  2568, -2624, -2624, -2624,   159, -2624,   796,   291, -2624,
     691, -2624, -2624, -2624,  1926, -2624, -2624,  1933, -2624, -2624,
     488,   566, -2624,   291,   567, -2624,  4797,  2146,  2585,   568,
    1114,  2601, -2624, -2624, -2624, -2624,  4797,  1991,  2280,  4797,
   -2624, -2624, -2624, -2624,   369,  1187,  1187,  2605,   -77, -2624,
    2606, -2624, -2624, -2624,  1187,   291,  2016,  1536,  2608,   291,
   -2624,  1242,   201,  1661,  2610,  1114,  -159,  2414,  4797, -2624,
   -2624,  3563, -2624,  1897,  4797, -2624, -2624, -2624,  2614,  3938,
     297, -2624,  1077,   291,   297, -2624,  2175,  3938,  3938, -2624,
   -2624,   699,  2115, -2624,  2195, -2624, -2624,  1301, -2624, -2624,
    1999, -2624,  1242,  4648,  8338,    81,  1232, -2624, -2624, -2624,
    1952, -2624, -2624, -2624, -2624, -2624, -2624,    43,  3768,    43,
    3768, -2624, -2624, -2624, -2624, -2624, -2624,   -75, -2624,  1377,
    1420,  8668, -2624,  2178,  2145,  8475, -2624,   134,   134, -2624,
   -2624, -2624, -2624,   573, -2624,  2102, -2624,   168,   917, -2624,
    1955, -2624,   574, -2624, -2624,  2624, -2624, -2624,  2033, -2624,
    2628,  4918,  4918,  4918,  4918,   168,   168, -2624, -2624, -2624,
   -2624, -2624, -2624,  2624,  1957,   297, -2624,  2547, -2624, -2624,
     291,   884,   884, -2624, -2624,   884,  2370,  1962, -2624,   664,
   -2624,  2194,  2196, -2624, -2624,  2615,  2197,  1967,  1263,  1968,
    1969, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   577, -2624,
   -2624, -2624, -2624,   435,   197, -2624,  7632,  7632, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  8681,  8681,  2165,
    8681,  2166, -2624,  8681,   644,  8475,  2646, -2624, -2624,  7632,
   -2624, -2624, -2624, -2624, -2624,  2647, -2624,   544, -2624, -2624,
    2260,  1979,  1983, -2624, -2624,   142,   142,   142,  2630,   142,
     142,   142,   142,   142,   142,  2634, -2624,  2635,   142, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  2781, -2624,   297,
    1992, -2624,  2162,  2370,  2638, -2624,  2641,  2642,  2643,  2645,
    2648,  2649,  1325,  1648, -2624,  2162, -2624, -2624,  2651, -2624,
    2323,   168,  1581,   168, -2624, -2624,  2265, -2624, -2624, -2624,
   -2624,  2235,  2236,   578,  1263,  2653,  1263, -2624,  2675,   579,
    2238,  2241,  2675, -2624, -2624, -2624, -2624,  1661, -2624, -2624,
   -2624,  2200, -2624, -2624,   796, -2624,  2265, -2624, -2624,   291,
     291, -2624, -2624,   291,   -79, -2624,   691,   154,  2308, -2624,
    2168,   154,   278,  1114, -2624,  2680,  2207, -2624, -2624,  2248,
    2089, -2624, -2624,   291,  1187,  1242,  1607,   291,  1187, -2624,
   -2624,    43, -2624, -2624,  4797, -2624, -2624,   353, -2624, -2624,
   -2624,  1114,  2684, -2624,    43,  2308,   297,  2401, -2624,  2670,
    1849,  7246,  2673, -2624, -2624,   211,  2220, -2624, -2624,  3938,
   -2624, -2624,  2256, -2624, -2624, -2624,   641, -2624,  1849, -2624,
    4797, -2624,   354, -2624,  2227, -2624, -2624, -2624, -2624,  2208,
    2303, -2624,  2686, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,   291, -2624,   112, -2624, -2624, -2624,
     168, -2624,    21,  2508,   580, -2624, -2624, -2624, -2624,   291,
     168, -2624,   125,   125,  2103,  5395,  5395, -2624, -2624,  4980,
    2226, -2624, -2624,  2229,  2232, -2624,  2240,  2242,  2243,  2244,
     291,   710, -2624, -2624, -2624, -2624,   582, -2624, -2624,  1993,
   -2624, -2624, -2624,   583,  2702,  2702, -2624, -2624,   588,  2705,
    2703, -2624,   202,   297,   125, -2624, -2624, -2624, -2624, -2624,
    2453,  5114,  1028,  1927,  1028,  1028,  2273, -2624,  1263,  2276,
    1263,  1263,   219, -2624, -2624,  2566, -2624,  2249,  1815,  2249,
     280, -2624,  2249,   280, -2624,  2249,  8681, -2624, -2624,  8475,
   -2624,  8475,  2565,   215, -2624, -2624, -2624, -2624,  1263, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,   613,  2723, -2624,   297,  1649, -2624,
    2453, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624,   381, -2624, -2624, -2624,  2219, -2624, -2624, -2624,
   -2624,  2708, -2624, -2624,  2289, -2624,  2710,  2295,  2711, -2624,
   -2624, -2624,  2296, -2624,  2261,  7632, -2624, -2624, -2624, -2624,
   -2624,   291,  2719, -2624,   -79, -2624, -2624,  2720, -2624, -2624,
    2721,   291,  2260,   154, -2624,    43,   -75, -2624,  2326,  1114,
   -2624,  4797, -2624,  2136,  2728,   -75, -2624, -2624,   514, -2624,
   -2624, -2624, -2624,   225,  2313, -2624, -2624,  1114,  2247,  2531,
    2466, -2624,   -75,  2315,  2316,  2414,  2283, -2624,  2363,  2319,
   -2624, -2624, -2624, -2624,  2473,  2258,  4797,  2277, -2624, -2624,
   -2624,  1849, -2624,   593, -2624,   297,  2173, -2624, -2624, -2624,
    8475, -2624, -2624,   168, -2624,  2290, -2624, -2624, -2624,  2624,
    2173,  1844,  1844,  2328,  8530,   596,  8544,   596,   596,   596,
     596,   554,  8544,  4918, -2624,  8544,  8544,  8544,  8544, -2624,
   -2624,   168,  2758,   168,  4918,   289,  7632, -2624,  2531,    95,
   -2624, -2624, -2624, -2624,  2332,  2335, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,   159, -2624, -2624,   601, -2624, -2624, -2624,
   -2624,   605, -2624,  2249,  2768, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624,   297,  2723, -2624, -2624, -2624,   297, -2624,   297,
   -2624, -2624,  1700, -2624,  2492, -2624,  2495,  2766, -2624, -2624,
    2338,  2116, -2624, -2624, -2624,  2348, -2624,   168,   451, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
    1114, -2624,  2349,  8978,  2312, -2624, -2624, -2624,  2135,   -75,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  2353,   211, -2624,
    2363,  2363,   641, -2624,  1242,  2180, -2624, -2624,   291, -2624,
    2531,   750,   138, -2624,  8433,   750, -2624,  2359,  8544, -2624,
     610,  8544,  8544,  8544,  8544,  2783,   291,   614, -2624, -2624,
   -2624, -2624, -2624, -2624,  2327, -2624, -2624, -2624,  2565, -2624,
     291, -2624,  1028,  1028, -2624, -2624, -2624,   163, -2624, -2624,
   -2624,  8475, -2624,  1921,  1921, -2624,  1921, -2624,  1921,  1921,
   -2624, -2624, -2624,  2334, -2624,  1263, -2624,   617, -2624,   963,
   -2624, -2624,    56,    56,    56,    56,    56,    56, -2624,  2786,
   -2624,   623, -2624,  4797,  1624, -2624,     7,  2363,  3938,  2363,
    2414, -2624, -2624, -2624,  2520,   388, -2624,   -75, -2624, -2624,
   -2624, -2624,   627, -2624, -2624,  1605, -2624,  2366,  8544, -2624,
    2368,  2371,  2373,  2374,   390,  2305, -2624,  4918, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624,  1921, -2624,  1921, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  1276, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  8978, -2624,  2817,
   -2624, -2624, -2624, -2624,   840, -2624, -2624, -2624, -2624, -2624,
   -2624,    53, -2624,  8433, -2624,  1946, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,  2798, -2624,  2799,   633, -2624, -2624,
    1381,  1381, -2624, -2624,  1381, -2624,  4797,   999, -2624, -2624,
    2380,    81, -2624,  2159,  2160,  2823, -2624,  2354,   396, -2624,
   -2624, -2624, -2624,  2388, -2624, -2624, -2624,   291,   291,  1946,
   -2624,  2809, -2624, -2624,   186,  2167, -2624, -2624,  2357, -2624,
     211, -2624,   291, -2624,  2414, -2624
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2624, -2624, -2624, -2624, -2624,   317, -2624,   377,  -166, -2624,
   -2624, -1157,    13, -2624, -2624, -1828, -2624, -2624, -2624, -2624,
    -545, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -1774, -2624,  -986, -2624,
    1839, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   645, -2624,
   -2624, -2624, -2624,  1290, -2624,   965, -2624, -2624,   -43, -2624,
   -2624,  2816, -2624,  2815, -2624, -2624, -2624, -2624, -2624,   717,
     355, -2624,   713, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,   -65,   927,   890, -2624, -2624,  2498,
      44, -2624,  2739, -2624, -2624,  2736, -2624,  2650, -2624, -2624,
   -2624, -2624, -2624,  2510,  2199,  1131,  2501,  -528, -2624, -2624,
   -2624, -2624, -2624,  1134,  -649, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,   140, -2624,  2636,  2330,  2652,    60,  2262,
   -2624,  -206,  1570, -2624,  2483, -2624, -2624, -2624, -2624,  2485,
   -2624, -2624, -2624, -2624,  -393, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,  2304, -2624,  2309, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -1165, -2624, -2624,  -507, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  -128, -2624,
   -2624,  1094, -2624, -1107, -1155,  1545, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624,  1880, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624,  -567, -2624, -2624, -2624, -2624, -2624,  2076, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624,  -531, -2624,  -100, -2624,
   -2624, -2624, -2624,  2460, -2624, -2624,  -204, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  1616,
   -2624, -2624, -2624, -2624,   897, -2624, -2624, -2624, -2624, -2624,
   -1014, -2624, -2624,   892, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -1130,  -616,   760,  1057, -2624,  -228,
    -569,   408, -1125,  1082, -2624,  -329, -2624, -2158,    -3,  -656,
   -2624, -2624, -2033,   550,  1331, -2624, -2624, -2624,   913,  1306,
   -2624, -2624, -2624, -2624, -2624, -2624,   348, -2624,    23, -2624,
    1307, -2624,   989, -2624,   675, -2624, -2624, -2624, -2624,  -530,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   772,
   -2624, -2624, -1534, -2624,   974, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624,  1459, -2624, -2624, -2624, -2624, -2624, -2624,  -168,
   -2624, -2624, -1783, -2624, -2624, -2624, -2624,   698, -1886, -2624,
   -1139, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624,  2888, -2624, -2624, -2624,  2821,
    2867, -1961, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   -84,
   -2624, -2624, -2624, -2624, -2624,  2874, -2624, -2624,  2895, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
    1987, -2624, -2624, -2624, -2624, -2624,  1036, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  -699,  2161, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624,  2397, -2624, -2624,   -41,
   -2624, -2624,  1031, -2624, -2624,  1361,  -167,  2598, -2624, -2624,
   -2624, -2624,  -180, -2624, -1045,  1917,  1334, -1458,  1415, -2624,
    1034,  1704,   -64,  -250, -2624,  2153,  1503, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  1429, -2624,  -770,
   -2624,  -532, -2624, -2624, -2624, -2624, -2624, -2624, -2624,  -455,
   -2624, -2624, -2624, -2624, -2624, -2624,   398, -2624, -1154,  1516,
     802, -2624, -2624, -2624, -2624, -2624,   209, -2624,  -245, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,  1413, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,  -523, -2624,  1090,  2497, -2624, -2624,
     221, -2624,  -622, -2624, -2624,   233,   545, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624,  1104, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,   162,
   -2624,   -98,   -93, -2624, -2624,   -85, -2624, -2413, -2624,   178,
     845, -1330, -2624, -2624, -2624,  1203, -2624, -1701, -2624, -2624,
   -2624, -1707, -2624, -2624, -1668, -2624, -2624, -2624, -2624, -2016,
   -2624,  1221,   896, -2624, -2624, -2624, -2624, -2624,   682, -2624,
   -2624, -2624, -2624, -2624, -2624,  -434, -2624, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,    -1,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624,
   -2624,  1346, -2624,  1347, -2624,   667,  1018, -2624, -2196,    90,
   -2624, -2624, -2624, -2624, -2624, -2624,   244, -2624, -2624,  -224,
   -2624,  -576, -1346, -2624, -2624, -2624, -2624, -2624,   214, -2624,
   -2624, -2624, -2624, -2624, -1665, -2624, -2624, -2624, -2624, -2624,
   -2624, -2126,   964, -2624, -2308,  1046, -2624, -2624, -2029,   329,
     338,   619, -2624, -1714, -1669, -2624, -2624,    38,  -287, -2624,
   -2624, -2624, -2624, -1631, -2624, -2624, -2624,   246, -2624,   572,
    -460, -2624,  -524,  -369,  1394,    -4, -1168,   602,   638, -2226,
   -2624, -2624, -2624, -2624,  2406, -1222, -1962,  3004, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624,  -432, -2624, -1624, -2624,
    1763, -2624, -2624,   592,   621, -2624, -2132,   622,   124,   437,
    -146, -1591, -1984,  1323,    57,   552, -1252, -2624,  1327, -2624,
   -2624, -2624,  1423,  -785, -2624, -2624,  -221,  1774, -2624,   947,
   -2624, -2624,   733,   147, -2624, -2624, -2624, -2623,   -87, -2422,
   -2624, -2282, -2624, -2624, -2624, -2624,  1458, -2624, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2486,  -104, -2624,
   -2491, -1918, -1975,  -909, -2624, -2624,   -83, -2624, -2624, -2624,
     547, -1027,  1326,  -743,  1930,  1594,  1602,   635, -2624, -2624,
     557,   906,    79, -2624, -2624, -2624, -2624,  1617, -2624, -2624,
   -2624, -2624, -2624, -2624, -2624, -2624, -2624,  -293,  1511,  2513,
   -2624, -2624, -2624, -2624
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1947
static const short yytable[] =
{
      36,    38,    39,    41,   571,    89,    41,   271,   186,  1008,
    1835,  1469,  1497,  1408,  1517,  1185,   105,  1476,  1477,  1360,
    1478,  1525,  1499,  1500,   684,   329,  1466,  2140,  1177,  2359,
    1743,   972,   580,  1972,   410,   411,  1035,  1038,  2426,  1125,
      61,   428,   383,  1677,  1678,   949,  2536,   299,  2097,  2424,
      89,  2636,   104,  1759,    61,  1910,  1911,  2098,  1095,   959,
     412,   413,   963,   238,    35,   111,  2025,  2026,  2027,  2028,
      35,   954,   118,   186,  1071,   996,   123,  1071,    35,   125,
     126,  2073,  1470,    35,   129,   130,    35,  1080,  2401,  2567,
    2403,  1071,   186,    35,    35,  1071,   426,  2013,    35,  1063,
    2892,  1861,  1097,  2491,    61,  1465,  2272,  1071,  1720,  1080,
    1721,  2923,  2924,  2925,    35,  1109,   114,  1703,  1080,  2927,
    1588,   234,  1438,  2481,   237,  1119,  2613,   102,  1039,   241,
      35,  2288,  1134,   580,  1598,  1611,    35,  1593,   414,  1175,
      35,  1438,   430,  1703,   432,  1467,   433,   434,   435,   596,
    1109,  1058,    35,  1516,  1109,   440,   597,   514,  1109,   451,
     452,    35,  1070,   199,  1080,  1824,   277,  1080,  1059, -1945,
    1041,   334,   102,    35,   367,   368,   277,   335,   336,  2914,
    2914,  2914,  2914,   277,  2763,  1299,  1589,   277,  1298,  1299,
      35,   332,  2326,  1039,   257,    35,  1217,  2857,   277,   330,
     331,    35,  1067,  1068,   564,   566,  2658,  2659,  1424,  2660,
    2661,  2662,  2663,  2664,  2665,    35,  3047,  1130,   580,  2764,
    1133,  2818,   574,   186,   591,   327,  1039,   186,    35,  1176,
     580,   592,  1181,   364,    35,   277,  1229,  1230,    35,   370,
    1039,  2684,    35,  1779,  1039,  1577,    35,  1088,  2647,    35,
    2649,   399,   327,  1239,  1117,  2656,  1135,    61,   409,   409,
     409,   409,   409,  1518,  1519,   580,   409,   580,  2295,   582,
    1824,   257,  1788,   360,   327,   352,  1577,  2977,  1847,   327,
     580,  2292,  1828,  3058,  1829,  2823,  1830,   277,  1229,  1230,
      35,   600,  3279,  3048,  3049,  2535,  3139,    35,   568,  2719,
      57,     5,  1425,  1426,   277,  1298,  1299,    35,   605,   115,
    1181,   608,    35,    61,    61,  1877,    35,  2199,    35,  2915,
    2915,  2915,  2915,   516,    35,  2600,  2149,   961,   616,   617,
     618,   619,  1050,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     940,   656,   952,  2653,  1593,  2140,  1921,  2565,  2149,   327,
     637,   638,  1039,   681,    35,   640,   664,   641,  1853,   667,
     669,   935,   428,  2156,  2495,  2912,  2912,  2912,  2912,  2626,
     644,   645,   646,   647,  1941,  1942,  3197,   654,   524,  1125,
       7,  2065, -1945,   327,   530,  3414,  1784,  1531,  1104,  1037,
    1037,  3451,  1883,  3459,  1037,  1037,  3145,  1121,  1734,    47,
    1548,  2399,  1181,  2157,    35,  1617,   953,  1037,   186,   931,
     673,  1735,  1834,  2601,  2602,  2603,  2604,  2605,  1759,   583,
    1287,  2360,  1723,  1723,  2805,   975,  1103,  1037,    51,  1728,
    1037,  2656,   932,  2222,   580,  1110,  1037,  2723,   576,   580,
    1037,    57,  3050,    29,  1037,    57,  1578,  2656,  1037,    28,
    1239,  2366,  1037,  1037,  2366,  1037,    57,  2422,  1037,  2001,
    1037,  1037,  1037,  2914,  2914,  2071,  1239,  2914,  1037,  2430,
    1175,  1037,   186,    72,  2448,   525,  1902,  1578,  1037,  1926,
    1007,  1221,  2450,    55,  1224,  1037,  1111,   535,  3139,  3139,
    1021,     8,  1037,  2666,    61,   836,   929,    57,   318,   319,
     320,   321,   322,  1037,    57,  2511,  2571,  1037,  1034,  1284,
    1513,  1037,   962,  1736,  1121,  1848,  1285,  1037,   103,    57,
    1037,  1405,   318,   319,   320,   321,   322,   676,  1702,  1034,
     676,    57,  1506,  1507,  2743,  1242, -1945,  1113,   676,   976,
    1553,  2824,  1880,  1419,  1594,  2658,  2659,   186,  2660,  2661,
    2662,  2663,  2664,  2665,  2743,   399,  1456,   399,  2743,  1376,
    1377,  2783,  2786,  2786,  1594,   106,   951,   409,  2880,  2890,
     956,   576,  2952,  3021,  3028,  3113,  3460,  3133,  3133,  1172,
    1173,  2876,  1749,  3141,  2806,  3041,   115,   409,  3248,  1378,
    1379,  1380,  1608,  1134,  1175,  1238,  3287,  2496,  1303,  1471,
    3287,    35,  1303,  2915,  2915,  3348,   113,  2915,  1223,  3348,
    2163,  1226,  2741,  2667,  2668,  2289,  2582,   921,  3387,  1744,
     569,    57,  3403,  2120,   192,  2121,  1624,  1738,  3133,  3216,
    2594,   671,  2037,  2014,  1790,   565,   567, -1945,  2845,  3042,
    2972,   593,  1883,  1739,  2966,  3273,  1805,  1624,   977,   970,
     280,  1532,  1472,   575, -1945,  2581,   117,  1884,  2165,  2912,
    2912,  1755,  3082,  2912,  2720,  2858,  2949,   676,  2669,  1112,
    1125,  1943,    61,    61,    61,  1026,    61,  1030,  1032,  2575,
    3092,  1040,  1042,  1043,  1034,  2748,  1048,  3119,  1032,   328,
    2172,  1051,  1231,    61,  2914,  1707,   581,  3059,   586,  1241,
    2914,  2914,  1043,  2914,  2914,  2914,  2914,  3105,    35,  1520,
    1730,   587,  2914,  1040,  1040,  1439,   519,  1610,  1204,  1303,
    3018,  1791,   601,  1043,  3168,  2377,  1704,  3168,  3149,    61,
    1523,  2777,  1468,  2872,  1464,    61,  1043,    61,  1006,  2778,
    1659,    61,  1242,  1361,    61,  1666,  1098,    61,  1669,  1670,
    3037,   406,  2749,  3280,  1032,  1862,  2412,    61,  1242,   955,
    3066,   598,   409,  1115,  3071,  1040,  1473,   406,   119,  1122,
    3146,  2209,    61,  2465,   406,  2327,  2032,  2465,    61,   406,
     409,   409,  3023,  2361,  3025,    61,    61,    61,  3251,  2155,
    2150,  1198,  1232,  1688,  1205,  2670,  1521,   665,  2280,    61,
     668,   670,  3255,   298,  1239,  2226,  1218,  1579,  1218,   409,
    2374,  1218,   409,   298,  1218,    61,  3162,  3064,  3051,  1831,
     298,  2412,  3075,  3095,   298,  2470,  2914,  1832,  1427,  2914,
    2914,  2914,  2914,  1037,  2915,   298,   594,  1679,  1579,  2319,
    2915,  2915,  2666,  2915,  2915,  2915,  2915,  2435,  2436,  1089,
    3198,   674,  2915,    35,  2412,  1347,  3417,  3400,  1347,  3415,
    1182,  2671,  2226,  1724,  1725,  3452,   654,   654,  2412,  1775,
    1729,  2954,   298,  1734,  1658,  2185,  1240,  2191,  1780,  2002,
    2186,  1247,    35,  2417,  2420,  2420,  1735,  3308,  2420,  1845,
    2912,    46,  2367,    35,  1514,  2373,  2912,  2912,  2423,  2912,
    2912,  2912,  2912,  2051,  1394,  1803,  2428,  1884,  2912,  1573,
    2431,  2672,  2673,  1615,  3123,  2449,  2914,    11,  1267, -1945,
    1241,  2338,  1680,  2451,   298,  2914,  1395,  3285, -1945, -1945,
   -1945, -1945, -1945,  3247,  3340,    11,  1286,  2967,  1681,    46,
    2800,   298,   193,  2877,  2878,  1515,  2512,  2572,    56,  2606,
      35,  2482,   236,     1,    35,  1037,  1037,  1037,  1381,  1281,
     937,   196,  2667,  2668,  2334,  1319,  2915,  2337,  1870,  2915,
    2915,  2915,  2915,     1,   282,  2744,  3159,     2,  3160,  3161,
    1734,  1682,     3,  3228,   156,  1888,    35,  1513,  1736,  2959,
    2166,  2962,   938,  1735,  2965,  2745,  3208,   285,  2765,  2747,
    2019,  1859,  2784,  2787,  2791,  1371,  3177,   676,  2755,  2881,
    2891,   235,  1290,  2953,  3022,  3029,  3114,  2669,  3134,  3140,
    1683,  1027,  2912,    35,  3142,  2912,  2912,  2912,  2912,  3249,
     318,   319,   320,   321,   322,   613,  2206,  3288,  1120,  1664,
      35,  3289,  1040,   243,  1382,    61,  3349,  1364, -1945,  1684,
    3356,  3168,  1667,  3372,  2342,  3265,  2915,  1758,  1685,  3388,
    2549,    61,   245,  3404,  1040,  2915,  2746,  1662,  2781,  3439,
      57,  2298,     4,  1125,  1987,  2968,  2190,  2969,   324,  1949,
     291,  1950,  1951,   931, -1945,  1953,  1954,  1383,  1454,  2345,
      35,  1973,  1574,  1052,    35,  1736,  1242,  2052,  2766,    57,
    2942,   252,  1738,    61, -1945,  1269,   932,  3278,  1122,  3339,
    1759,  2507,  2912,  3345,  2020,  2584,  3252,  2782,  1739,  1122,
      56,  2912,    35,  2003,  2974,  2593,  2005,  2040,  2637,  1181,
    2639,    35,  2640,    61,    61,    61,  2767,    61,   253,    61,
      61,  3259,  1623,  2277,  2670,    61,    61,  3259,   255,  2145,
    3269,  3270,  3271,  3272,  1694,     1,  1695,  1696,  1503,     2,
    2586,  1849,    35,   371,  2290,  1510,  3428,    57,  2299,    61,
    2036,    57,   294,  2975,   256,  1734,  1243,  1244,  1245,  1921,
    1546,  1627,    61,  3132,   295,   296,  2612,  1246,  1735,   259,
     372,  1557,   297,  3179,    61,  2133,  1558,  2134,    35,  1565,
    2768,  2114,  2756,    57,  1203,  3268,  1113,  1291,  1209,  1738,
    2671,  1456,  1213,     5,  2769,  3266,  3276,  1988,    61,    61,
    2688,   994,  2492,  2021,   997,  1739,   260,    61,  1806,  2278,
    2181,   261,    79,     5,  1665,  3165,  1989,  1990,  3170,    80,
      57,  3172,  3180,    61,    61,  3373,  2133,  1668,  2134,  2343,
     159,   160,  1851,    35, -1945,   262,  1991,  1121,   161,    35,
    2672,  2673,  1604,  2311,    35,  1445,  1785,  1400,    35,  1661,
     162,  1034,  2312,  3347,   263,  1134,  3350,  3351,  3352,  3353,
    1818,  3110,  1319,  1319,  2346,    81,    82,  3173,  1575,  1401,
    1736,  2152,  1319,    83,  1979,  2943,  2313,  1731,   264,  2314,
    1733,  2135,  1921,  2617,  2136,  1701,  2041,  1121,  1175,   428,
     265,    57,  1926,  1708,  2770,  2315,  2847,  2042,    35, -1945,
     266,  1576,  2178,  2471,  2819, -1945,  1921,  2472,  1867,  1868,
    2771,   267,    35,  3371,     6,   268,  2483,  1734, -1945,    57,
    3008,   269,    35,   162,  1957,   163,   186,  1768,    57,  2788,
    1735,    40,  2135,    35,     6,  2136,  3374,   164,  3079,  1737,
    3375,  2504,  2828,  3409,  1745,  -282,  1711,  1712,  1750,  1756,
    1750,   270,  1906,  1907,  2515,    35,   110,  1921,  2854,    57,
    1762,  1764,  1765,    35,   165,    61,  1769,  1771,  1772,  1773,
    1040,  2825,  2738,  2868,    35, -1945,   418, -1945,  1448,  1040,
    2867,   419,     7,   421,  1738,  2958,  2958, -1945,  2958,  2885,
    1122,  2958,    61,     8,    61,    57,    61,    61,  2297,  2316,
    1739, -1945, -1945,   272,    61,    61,  1040,  1431,    61,   409,
    2882,   409,    61,     8,  1432,  1926,  2870,    35,  2886,   376,
    1122,   312,     9, -1945, -1945,   313,  3046,  1821,  1122,  3290,
    -282,   314,  1736,  1822,    61,    61,  3331,  3332,   431,  1926,
      35,  2344,     9,   315,  1189,  3148,  -282,  2349,  2350,  1449,
      57, -1945,  2317,  2442,  2443,  2444,    57,  2421,   166,  2318,
    2425,    57,   316,  1998,  3258,    57,  3261,  3262,  3263,  3264,
      35,  1713,  1714,  1715,  1716,  1717,  1718,   317,  2036,    61,
      61, -1945,    61,   347, -1945,    61,    61,  1057,   348,  -282,
    1926,  2212,  1037,   349,  1190,   333,  3379,   353,    35,   338,
    1326,   356,  1400,  2833,   377,   354, -1945,  1865,  1075,   409,
     409,  2841,  2842,  3392,   409,    57,    61,  2466,  1874,  1875,
     378,  1084,   358,  3396,  1401,  3398,  2812,    84,  -282,    57,
   -1945,  1191, -1632,    35,   339,   340,   341,  1958,  3422,    57,
     325,    61,   362,  3014,   385,  3017,  1738,   441,   363, -1945,
   -1945,  1959,  1218,   409,   409,   167,   964,  -282,   965,    61,
      61,  1995,  1739,   379,  3379,  2054,  -282,   107,   108, -1945,
    2508,  3015,    57,   365,  1803,  1987,   369,  1256,    35,  1945,
    1040,  3392,  1040,  1040,   374,  1550,  1040,  1040,  1257,  1955,
     168,    57,  1040,   375,  1960,  1921,   384,  3069,  2164,   393,
    1679,   418,   380,  1134,    35,  1961,   419,   420,   421,  1175,
     107,   108,   107,   108,  3390,   394,    61,  3250,  1037,  2543,
     404,    35,    85,   968,   169,   969,  1962,  1999,  1192,   386,
     326,   381,   442,  1963,    57,  1175,   170,  2059,  1258, -1945,
     382,  1964,  1031, -1945,    35,   387,  2445,   400,   443,  3374,
    1073,  1037,  1259,  3375,  2351,  2792,  1039,  1319,    35,  1319,
    2235,  2237, -1945,  1965,  1082, -1945, -1945,   403,  1087,  1319,
    1319,  1040,   171,   436,  2045,  1551,  1319,  1319,  1319,  1319,
    1101,  1454,  3109,    35,  2958,  1680,   438,   172,   388,  1122,
    2822,   444,  3117,    28,    29,   173,  2177,   169,   439,  2247,
   -1945,  1681,  1262,  1263,  1222,  1193,   450,  1225,   174,   170,
    1228,  1745,  1396,  1397,    86,   654,  1750,   453,  1988,   415,
     416,   417,  1756,   454,  2574,  1750,   456,   389,  1926,   460,
     445,  1409,  1410,  1411,  3184,  1892,   108,  1989,  1990,  2352,
    1966,  1260,  1364,  2112,  1682,  1194,  1967,  1612,   457,  2116,
    1047,   458,   175,  2598, -1945,  2353,   390,  1991, -1945,   446,
    3085,  1544,  1056,    35,  1671,   391,  1672,   459,   447,  2614,
     570,  1526,  1527,  1528,  1529,  2688,   507,   176,  2143,   520,
    1674,  2628,  1675,  1683,  2630,   518,  2633,  2634,  1763,   537,
      35,  1076,  1040,  1122,    87,   522,  2159,  2160,  2354,   409,
     527,   177,    88,  1709,  1710,  1711,  1712,  1093,  1094,  3185,
     528,  1195,  1684,  1100,    61,  1766,  1102,    35,  1982,  1983,
    2036,  1685,  2036,  3087,  1504,  1505,   529,  1689,  1508,  1509,
    2146,  2147,  2724, -1945,  3137,  3138,  2188,  2355,    61,   531,
    1960,  1770,  2006,    35,  2007,   178,   532,  2725,  2726,  1613,
     176,  1961,   536,  2010,   179,  2011,  2727,  1614,   538,    61,
    3185,  2213,  1565,  1615,  1319,  1616,  2356,  1122,    61,  3219,
     541,  3186,  1962,  3187,   177,  2357,  1617,   542,  3227,  1963,
     318,   319,   320,   321,   322,   409,   409,  1964, -1945,  3188,
    2728,  1134,  1134,   552,  2454,  3233,    35,  3189,   553,  2729,
     409,  3190,  1243,  1244,  1618,    61,    61,    61,  2457,  1965,
      35,    61,  2631,   554,  2632,  3253,  3405,  3406,   178,  1040,
    1619,  3154,  3186,  3155,  3187,  1620,  3191,   179,  2730,   557,
    1713,  1714,  1715,  1716,  1717,  1718,   562,  1621,   180,   181,
    3188,  3433,   572,    35,  1622,  1786,    61,  1786,  3189,  2152,
    2761,  2762,  3190,  1818,  2333,  2333,  3121,  3122,  2333,  1713,
    1714,  1715,  1716,  1717,  1718,   573,  1037,   578,   579,   584,
     585,   589,  1037,  2731,   590,   599,   609,  3191,  3060,   606,
    1319,  3135,  3136,  3137,  3138,   610,   611,   614,   639,  1319,
    3277,   642,  1319,  1319,  1319,  1319,  2372,   649,  1037,  1040,
     648,   655,   657,  2378,  1319,   658,  3076,  2396,   659,  2417,
     660,   180,   181,   661,   666,   662,   663,  2732,   672,   186,
     682,  1060,  1060,     1,   936,   941,   943,   944,  2413,  2413,
    2413,   945,   950,  2413,  1319,  2427,   960,   966,  1745,   967,
     981,   974,  3325,  2980,  2981,  2982,   979,  2984,  2985,  2986,
    2987,  2988,  2989,   983,  1336,   984,  2992,  1338,   985,  1339,
    1340,  1341,  1342,  1343,  1002,  1004,  1009,  2452,  1010,  2453,
    2455,  1012,  2456,  2458,  1013,  1014,  2460,  1015,  1017,   133,
    1750, -1945,  1018,  1019,  1750,    61,  1020,  1132,  1022,    61,
    1210,  1271,  1623,  1272,  1273,  1040,  2413,  1624,    61,  2143,
    1274,  1275,  2488,  2488,  1625,  1276,  1277,  1278,  1713,  1714,
    1715,  1716,  1717,  1718,  1279,  1280,  1282,  1283,   134,  1060,
    1288,  1289,  1292,    61,  1293,  1294,  1626,  1337,  1344,  1233,
    2506,  1627,  1345,    61,  1346,  1349,  1350,   135,   136,  1352,
    1353,  1369,    61, -1945,  1354, -1945,    61,  1355,  1362,  1393,
    3402,  1356,  3380,  3381,  3382,  3383,  3384,  3385,  1357,  1358,
    1363, -1945,  1367,  3330,  1368,  1370,  1374,  1398,  1399, -1945,
    1402,    61,  1403, -1945,  1406,  1404,  1423,   137,  1412,  1429,
    1430,  1433,  1434,  1436, -1945,  1441,  1442,  1444,  1437,   138,
    1479,  1453,  1458,  1456,  1501,  2550,  1460,  1461, -1945,  1511,
     139,  1512,  1516,  1549,  1540,  2652,  1541,  2655,  1542,  1543,
    1547,  1553,  2016,  3034,  2023,  1562,   140,  1552,  1564,  1584,
    1585,  1586,   580,  1592,  2023,  1326,   141,  1587,  1596,  1600,
    1599,  2046,  2047,  2048,  2049,  1601,  1602,  1065,  1660,  1649,
    1657,   142,  1663,  1673,  3221,  1040,  1727,  1690,  1748,  1691,
    1692,  1693,  1697,  1698,  1037,  1037,  1699,  1761,  1700,  1722,
    2413,  1081,  3231,  1776,  1777,  1778,  1781,   929,  2589,  1955,
    2413,  1783,  1424,  1945,  1040,  1782,  1319,  1797,  1804,  1320,
    1813,   143,  1811,  1824,  1523,  1815,  1837,  1854,  1838,  1945,
    1040,  1826,  1856,    61,  2333,  2018,  1857,  1866,  1869,  2863,
    3178,  2865,  1871,  1894,   144,  1818,  1880,  1170,  1895,  1897,
    1887,  1889,  3397,  1594,  1935,  1933,  1936,  1187,  1938,   145,
    1202,  1996,  1944,  2000,  1208,  2004,   146,  2008,  2009,   147,
    1214,  2014,  1216,  1319,  1688,   929,  2037,  2012,  2050,  2055,
    2061,  1040,  2029,  1040,  2378,  2852,  2068,  1319,  2062,  1319,
     148,  2063,  2071,  2066,   149,  2100,  2831,  2102,  2067,  1233,
    1319,   654,  2105,  2103,  2104,  2413,    61,  2396,  2118,   654,
     654,   186,  2106,   150,  2122,  2109,  2107,  2123,  2124,  2413,
    2125,  3153,  2126,  3156,  3157,  3464,  2128,  2130,  2144,  1593,
    2167,   151,  2169,  2174,  2170,  2176,  1480,  1750,  2036,  2179,
   -1945,  2129,  2183,  2184,  2189,  3310,  2192,  2193,  2202,  2131,
      66,  2196,   186,  2216,  2132,  1756,  2210,  1750,  1246,  2220,
    2228,  2226,  2275,  2287,  2307,  2913,  2913,  2913,  2913,  2276,
    2112,  2293,  2301,  2303,  2302,  2306,  2308,    61,  2341,  2322,
    2347,  2348,  2330,  2362,  2363,  2364,  2376,  2323,  2393,  2398,
    2400,  2402,  2404,  2405,  2432,  2409,  2463,  2433,  2434,  1175,
    2437,  2438,  2143,  2439,  2813,  2479,  2815,  2440,  2441,  2413,
    1040,  2499,    61,  2468,   157,   189,  2497,  1137,  1138,  1139,
    1140,  2501,  2503,  2502,  2509,  2517,  2518,    61,  2505,    61,
    2837,    61,  2520,  2961,  2522,  2964,  2523,  2521,  2524,  2525,
   -1945,  2541,  2542,  2544,    61,  2221,  1513,  2548,  1245,  2557,
    2559,  1319,  2568,  2569,  2570,  2573,  2585,  2587,  3152,  2610,
    2577,  2615,  2620,  1481,   409,  2578,   409,  2635,  2629,  1482,
    1483,  1484,  1233,  2641,  2643,  1326,    61,    61,  2638,  2644,
     189,  2656,  1319,  2657,  2365,  2645,  2646,  2368,  2369,  2370,
    2371,  1485,  2682,  2679,  2413,  2741,  2691,  2742,  2740,   189,
    2750,  2754,  2789,  2753,  2757,  2759,  2760,  2779,  2911,  2911,
    2911,  2911,  2413,  2413,  2780,  2790,  2793,  3073,  2796,  2795,
    2803,  2807,    61,  2814,  2811,  1416,  2829,  2936,  2821,  2832,
    3078,  2840,  2850,  2862,  2873,  2882,  1320,  1320,  2874,  2892,
    1141,  2893,  2889,  1703,  2934, -1945,  1320,  2941,  1142,  3068,
    2944,  2946,  2945,  2947,  2948,  2950,  2951,  1143,  2960,  2963,
    1144,  2971,  2973,  1319,  1319,  2983,  2978,   405,  2979,  2990,
    2991,  2998,  2997,  3001,  1319,  1319,  3002,  1319,  3003,  3004,
    1319,  3005,  1319,  2767,  3006,  3007,  1319,  3012,  1839,  3024,
    3026,  3019,  3020,  3035,  3030,  3061,  1486,  3031,  3055,  1487,
    3062,  3064,  3077,  1145,  3063, -1945,  3081,  1488,  3083,  3086,
    1146,  3098,  3090,  1240,  3111,   186,  3101,  3133,  3105,  3124,
    3143,   654,  3125,   512,   513,  3126,    61,  3144,  3150,  3158,
     189,  1170, -1813,  3127,   189,  3128,  3129,  3130,  3182,    61,
    2738,  1533,  1489,  1539,  3200,  3201,  3202,  3205,  2413,  3016,
    2413,  3204,  3206,  3163,  3207,  3211,  3213,  3214,  3210,  2913,
    2913,  3359,  3360,  2913,  3226,  3220,  3224,  1147,  3210,  3230,
    3232,  3234,  3235,  3238,  1040,  3240,  3236,  1490, -1945,  3244,
   -1945,  1704,  3274,  3254,  3256,  3291,  3038,  3039,  3282,  1655,
    2460,  3283,  1148,  1750,  3304,  3301,  1491,  1492,  3302,  1149,
      61,  1150,  3303,  3305,  3306,  3323,  3311,  1493,  1233,  3329,
    2488,  1151,  1494,  3070,  2488,  3346,  3324,  3336,   409,  3354,
    3357,  3386,  3408,  3370,  3410,  3399,  3416,  3411,    61,  3412,
    3413,   409,  3426,    61,  3437,  3438,  3445,  3218,  3449,  1152,
    3447,  3448,    61,  3450,  3453,  3458,  3463,  1153,  3462,  2836,
    2785,  1495,  3425,  1359,  1879,  2533,  2201,    52,    53,  2484,
    2810,  2493,  1037,   533,   195,   200,   526,   534,  2056,   346,
    1011,  1326,  2057,   359,  1676,   973,   351,   675,   561,   559,
    3423,  3102,   946,  1496,  1154,  2115,  1351,  2413,   595,   947,
    1197,  1653,  2331,  3100,  2339,  2475,  2589,  2413,  2161,  1945,
    1945,  1905,  2911,  2911,  2861,  1909,  2911,  2225,  1155,  2547,
    2480,  3446,  2245,  1808,   643,  3229,    49,  3131,  2693,  2694,
      63,  2695,  2696,  2697,   131,   189,  3195,    64,  2642,    50,
    1270,  1099,  2208,  2211,  1233,   517,  1893,  1932,  1844,  2215,
      61,  1945,  3292,  3183,  2654,  1156,  1590,  1373,  1131,  3429,
    1842,  1799,  2856,  1789,  3011,  2678,  1157,  3300,  1860,  1040,
    2993,  2180,   615,  3057,  3010,  3217,  2736,  1122,  3215,  3212,
    1122,  3040,  2469,  1319,  2101,  2070,  1319,  2429,  1319,  3432,
    2413,  2579,  3176,  1975,  1976,  2599,  1792,  1793,  1794,   189,
    2913,  2305,  3118,  3307,  3013,  2955,  2913,  2913,  3036,  2913,
    2913,  2913,  2913,  1812,    61,  2956,  2375,  2296,  2913,  2651,
    3361,  3171,  1912,  1913,  1914,  2752,  1948,  1915,  3032,  1916,
    1917,  2698,  3199,    45,  2737,  2650,   982,  3457,  3120,  2699,
    2689,  1320,  2690,  1320,  1641,  2888,  2031,  3338,  3175,  2030,
    1940,  1607,  1319,  1320,  1320,  2591,  3116,  3257,  1903,  3275,
    1320,  1320,  1320,  1320,  1158,  1159,  1160,  1817,  2053,  3267,
    2820,  1455,   409,  2700,   189,  2500,    61,  1161,  2817,   683,
    1807,  1846,  2701,  1823,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,  3335,     0,     0,
    1533,     0,  1023,  1024,  1025,     0,  1028,     0,     0,     0,
       0,  2702,  2703,     0,     0,     0,  2220,     0,  1876,     0,
       0,     0,    61,  1054,     0,     0,     0,  1319,     0,  1891,
    2413,     0,  2913,     0,     0,  2913,  2913,  2913,  2913,     0,
       0,  1319,     0,  2911,     0,     0,     0,  1326,     0,  2911,
    2911,     0,  2911,  2911,  2911,  2911,  2704,     0,  2413,  1078,
    2413,  2911,     0,  1319,   186,  1083,     0,  1085,     0,     0,
       0,  1092,     0,     0,  1092,     0,     0,  1092,  1977,  1978,
    1162,     0,     0,     0,     0,  1994,     0,  1105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
    2705,     0,  1105,     0,    61,     0,    61,     0,  1166,     0,
       0,     0,     0,  1060,     0,  1028,  1179,  1183,     0,     0,
     654,  1199,  2913,     0,  2413,  1912,  1913,  1914,     0,  1211,
    1915,  2913,  1916,  1917,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,  1235,     0,  2970,  1320,     0,
       0,     0,     0,     0,  2706,    61,  2922,  2922,  2922,  2922,
       0,     0,     0,     0,     0,  3102,     0,     0,     0,     0,
       0,  1319,     0,     0,     0,  2911,     0,     0,  2911,  2911,
    2911,  2911,     0,  3355,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3358,     0,     0,
       0,     0,  1918,     0,  1122,  1919,     0,  1920,  1319,   603,
     461,   462,   463,     0,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,  1921,     0,    61,
      61,    61,    61,    61,    61,     0,     0,  1922,     0,     0,
       0,  3391,     0,     0,     0,     0,  1416,     0,     0,     0,
       0,     0,   477,     0,     0,     0,     0,     0,  1923,     0,
       0,     0,  2127,     0,  1320,  2911,     0,     0,     0,     0,
       0,     0,     0,  1320,  2911,     0,  1320,  1320,  1320,  1320,
       0,  1924,     0,     0,     0,  1925,     0,     0,  1320,  2151,
       0,     0,     0,     0,     0,  2182,  1794,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1320,     0,
    1319,     0,  3434,     0,     0,     0,  1533,     0,     0,     0,
       0,     0,     0,     0,     0,  2223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2198,     0,     0,     0,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,     0,
    1926,     0,     0,     0,  3455,  3456,  3434,   484,   485,   486,
       0,     0,     0,     0,     0,  1235,     0,    61,     0,  3465,
    2707,  2708,  2709,  2710,  2711,  2712,  2713,  2714,  2715,  2716,
       0,  1417,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1918,     0,     0,  1919,     0,
    1920,     0,     0,     0,     0,     0,     0,  1233,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,     0,     0,
    1921,     0,     0,  1447,     0,     0,     0,     0,     0,     0,
    1922,  3174,     0,  2678,     0,     0,     0,     0,     0,     0,
    2922,  2922,     0,   477,  2922,     0,     0,     0,     0,     0,
       0,  2244,     0,  1475,  1475,  1475,     0,  1475,     0,  1475,
    1475,     0,     0,     0,     0,    66,    66,     0,     0,     0,
       0,     0,     0,     0,  1924,     0,     0,     0,  1925,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1183,
       0,     0,     0,     0,     0,     0,     0,   487,  1479,     0,
     488,     0,  1183,     0,     0,  3169,     0,     0,  3169,     0,
       0,     0,     0,     0,  1560,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1235,  1417,
     478,   479,   480,   481,   482,   483,     0,  1597,     0,     0,
    1320,     0,     0,  1926,     0,     0,     0,     0,   484,   485,
     486,     0,  2459,  1605,  1605,   474,   475,   476,     0,     0,
       0,     0,  1326,     0,     0,     0,     0,     0,  2473,  2474,
    1794,  2477,     0,     0,     0,     0,  2016,     0,     0,     0,
       0,     0,     0,   477,     0,     0,     0,     0,     0,  2498,
       0,     0,     0,     0,     0,     0,     0,  1320,     0,     0,
       0,     0,     0,     0,     0,  2529,  2530,     0,     0,     0,
     489,  1320,     0,  1320,     0,     0,  2539,     0,     0,     0,
       0,     0,     0,     0,  1320,   490,     0,     0,     0,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2551,  2552,  2553,  2554,  2555,  2556,     0,     0,     0,     0,
    2561,  2562,  2563,  2564,     0,  2540,     0,  2566,     0,  2018,
     476,  2922,     0,     0,     0,   492,     0,  2922,  2922,     0,
    2922,  2922,  2922,  2922,     0,     0,  1320,     0,     0,  2922,
     478,   479,   480,   481,   482,   483,   477,     0,   487,     0,
       0,   488,     0,   493,  1480,     0,     0,     0,   484,   485,
     486,     0,     0,     0,     0,     0,  3344,     0,     0,     0,
       0,   494, -1945, -1945, -1945,     0,     0, -1945,     0, -1945,
   -1945,     0,    66,     0,    66,     0,  1183,  1092,     0,     0,
       0,     0,     0,     0,  1798,  1105,     0,     0,  1183,  2618,
    2619,     0,  1809,  3362,     0,     0,  2623,  2624,     0,     0,
       0,     0,     0,   189,     0,     0,     0,  2608,     0,  2609,
       0,     0,     0,     0,  1235,  1166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1320,     0,     0,     0,     0,
       0,     0,     0,   478,   479,   480,   481,   482,   483,     0,
       0,     0,   495,  2922,     0,     0,  2922,  2922,  2922,  2922,
       0,   484,   485,   486,     0,     0,  1320,     0,     0,  1843,
    1166,   489,    66,     0,     0,  1850,  1852,     0,     0,     0,
       0,  1481,  3169,     0,     0,     0,   490,  1482,  1483,  1484,
     491,     0,  1320,  1320,  1320,  1320,     0,     0,   487,     0,
       0,   488,     0,     0,     0,     0,  1872,   274,     0,  1485,
       0,     0,     0,     0,     0,  3344,   275,   276,   496,     0,
       0,     0,   277,   278,   279,    35,   492,     0,     0,     0,
       0,  1899,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,  2922,     0,     0,     0,  1320,  1320,  1931,
    1235,     0,  2922,     0,   493,     0,  2801,  2802,  1320,  1320,
       0,  1320,     0,     0,  1320,  2809,  1320,     0,     0,     0,
    1320,     0,   494,     0,     0,     0,     0,     0,     0,     0,
       0,  2794,     0,     0,  2799,     0,  1060,  1060,  1060,     0,
    1060,  1060,  1060,  1060,  1060,  1060,     0,     0,     0,  1060,
       0,   487,  2843,  2844,   488,     0,  1981,     0,     0,     0,
       0,   163,     0,     0,  1486,     0,   280,  1487,     0,     0,
       0,   489,     0,   164,     0,  1488,     0,     0,     0,  2864,
       0,  2866,     0,     0,     0,     0,   490,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,  1170,     0,
     165,     0, -1945,   495,     0, -1945,   274, -1945,     0,     0,
    1489,     0,     0,     0,     0,   275,   276,     0,     0,     0,
       0,   277,   278,   279,    35,     0,   492, -1945,     0,     0,
       0,     0,     0,     0,     0,   162,     0, -1945,     0,     0,
       0,     0,  2937,  2938,     0,  1490,  2939,  2940,     0,     0,
       0,     0,     0,     0,   493,     0,     0,     0, -1945,     0,
       0,     0,     0,     0,  1491,  1492,     0,     0,     0,   496,
       0,     0,   494,     0,   489,  1493,  1233,     0,     0,     0,
    1494, -1945,     0,     0,     0, -1945,     0,     0,     0,   490,
       0,     0,    57,   491,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,   280,     0,     0,     0,  1495,
       0,     0,   164,     0,     0,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1320,  1320,     0,     0,
    1320,     0,     0,     0,  3000,     0,     0,     0,     0,   165,
       0,  1496,     0,   495,  2173,     0,     0,   493,     0,     0,
   -1945,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   494,     0,     0,  1183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,     0,   281,     0,     0,   157,
       0,  1320,     0,     0,  1320,     0,     0,  1320,  1166,     0,
    1320,     0,  1320,     0,     0,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,  3067,   168,     0,     0,  3072,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,   166,     0,  1183,  2279,  1183,  3080,     0,
       0,  1028,     0,     0,     0,     0,   495,     0,     0,     0,
     169,     0,     0,     0,     0,     0,     0,  3091,     0,  3074,
       0,     0,   170,     0,     0,     0,  1320,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2325,     0,     0,     0,
     282,     0,     0,     0,     0,   283,     0,   284,     0,     0,
       0,     0,     0,     0,     0,  3093,     0,     0,   171,     0,
       0,     0,     0,   285,     0,     0,     0,     0,     0,     0,
       0,     0,   496,   172,     0,     0,     0,     0,   286,     0,
       0,   287,     0,     0,   288,     0,     0,     0,     0,     0,
     167,     0,     0,   289,   174,   281,     0,     0,     0,     0,
       0,  1320,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1320,     0,  1320,     0,     0,
       0,     0,     0,  1320,  1320,   168,  1320,  1320,  1320,  1320,
       0,     0,     0,   650,   290,  1320,     0,  1320,   175,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,     0,     0,  1320,     0,     0,   292,     0,   169,
       0,     0,     0,   176,     0,     0,     0,     0,   274,     0,
       0,   170,     0,     0,     0,  1183,     0,   275,   276,  1183,
       0,     0,     0,   277,   278,   279,    35,   293,  1183,   282,
       0,     0,     0,     0,   283,     0,   284,   162,     0,     0,
       0,     0,     0,     0,     0,     0,   189,   171,     0,     0,
       0,     0,   285,  1183,     0,     0,     0,     0,     0,     0,
       0,     0,   172,  1235,     0,     0,     0,   286,     0,  1233,
     287,   178,  2513,   288,     0,     0,  2516,     0,   294,     0,
     179,     0,   289,   174,     0,  1320,     0,     0,     0,  1320,
     295,   296,  1320,  1320,  1320,  1320,     0,     0,   297,     0,
       0,  2538,     0,     0,     0,  3243,  3222,     0,  3246,   298,
       0,     0,   163,     0,     0,     0,     0,   280,  1320,     0,
       0,     0,  1320,   290,   164,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,  3245,     0,     0,     0,     0,   292,     0,  2476,     0,
       0,   165,   176,     0,     0,     0,     0,   274,     0,     0,
       0,     0,     0,     0,   180,   181,   275,   276,     0,     0,
       0,     0,   277,   278,   279,    35,   293,     0,     0,  1320,
       0,     0,     0,     0,     0,     0,   162,     0,  1320,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     178,     0,     0,  2616,     0,     0,     0,   294,     0,   179,
       0,     0,     0,     0,  1320,     0,     0,     0,     0,   295,
     296,     0,     0,    57,     0,   166,     0,   297,     0,     0,
       0,     0,     0,  3333,     0,     0,     0,     0,   298,     0,
       0,   163,     0,     0,     0,     0,   280,     0,     0,     0,
       0,     0,     0,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1233,     0,     0,     0,     0,  1183,     0,     0,     0,
     165,     0,     0,     0,  3363,  3364,   274,  3366,     0,  3368,
    3369,     0,     0,   180,   181,   275,   276,     0,     0,     0,
       0,   277,   278,   279,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,     0,     0,
       0,     0,   167,     0,     0,     0,     0,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1183,  3389,     0,
       0,     0,     0,     0,     0,     0,  3418,   168,  3419,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,   166,     0,     0,     0,   189,     0,
       0,     0,  1183,     0,     0,     0,     0,     0,     0,     0,
     163,   169,  3431,     0,     0,   280,     0,  2834,     0,  1054,
       0,  2838,   164,   170,     0,     0,     0,     0,     0,     0,
       0,  3440,  3441,     0,  2849,  3442,  2895,  2896,  3444,   189,
       0,   282,   277,  1298,  1299,    35,   283,     0,   284,   165,
       0,     0,     0,     0,  1300,  1301,     0,     0,     0,   171,
       0,     0,     0,     0,   285,     0,  2869,  2871,     0,     0,
       0,  3443,     0,     0,   172,     0,     0,     0,     0,   286,
       0,     0,   287,     0,     0,   288,     0,     0,     0,     0,
       0,   167,     0,     0,   289,   174,   281,     0,  2895,  2896,
       0,     0,     0,     0,   277,  1298,  1299,    35,     0,     0,
       0,     0,  2935,     0,     0,     0,  1300,  1301,     0,     0,
       0,     0,     0,     0,     0,     0,   168,     0,     0,     0,
       0,     0,     0,     0,  1413,   290,  2897,     0,     0,   175,
       0,    57,     0,   166,     0,     0,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,     0,
     169,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293, -1946,
     282,     0,     0,     0,     0,   283,     0,   284,  2897,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,     0,
   -1946, -1946, -1946,   285,     0, -1946,  2994, -1946, -1946,     0,
       0,     0,     0,   172,     0,     0,     0,     0,   286,  3009,
       0,   287,   178,     0,   288,     0,     0,     0,     0,   294,
     167,   179,     0,   289,   174,   281,     0,     0,     0,     0,
       0,   295,   296,     0,     0,     0,     0,     0,     0,   297,
       0,     0,  1121,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,     0,     0,   168,     0,     0,     0,     0,
       0,     0, -1946,  2853,   290,     0,     0,     0,   175,     0,
    1183,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,   189,     0,     0,     0,     0,   292,     0,   169,
   -1946,     0,     0,   176,     0,     0,     0,     0,  1183,     0,
       0,   170,     0,  1166,  1121,   180,   181,     0,     0,     0,
       0,     0,  1235,     0,     0,     0,     0,   293,     0,   282,
       0,     0,     0,     0,   283,     0,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1946,   171,     0,     0,
       0,     0,   285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,     0,     0,   286,     0,     0,
     287,   178,     0,   288, -1946,     0, -1946,     0,   294,     0,
     179,     0,   289,   174,     0,     0,     0,     0,     0,     0,
     295,   296,     0,     0,     0,     0,     0,     0,   297,     0,
       0, -1946,     0,     0,     0,     0,     0,     0, -1946,   298,
   -1946,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1166, -1946,     0,   290,     0,     0, -1946,   175,     0,     0,
       0,     0,     0,     0, -1946,   291,     0,     0, -1946,     0,
       0,     0,     0,     0, -1946,     0,   292,     0, -1946, -1946,
   -1946, -1946,   176,     0,     0,     0,     0,  1303,     0,     0,
       0,     0,     0, -1946,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,     0,     0,
   -1946,     0,     0, -1946,  2994, -1946,     0,     0,  2898,     0,
       0,  2899, -1946,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2900, -1946,     0,     0,     0,   277,
    1298,  1299,    35,     0,     0, -1946,     0,     0,   133,  1303,
     178,  1300,  1301,     0,     0,     0,     0,   294,     0,   179,
       0,     0,     0,     0,     0,     0, -1946, -1946,     0,   295,
     296,     0,     0,  2901,  2902,     0,  1183,   297,     0,     0,
    2898, -1946,     0,  2899,     0,     0,  2903,   134,   298, -1946,
       0,     0,     0, -1946,  1183,     0,  2900,     0,     0,     0,
       0, -1946, -1946, -1946,     0,     0,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1166,  1688,     0,     0,     0,  2904,     0,     0,
       0,     0,     0,  2897,     0,     0,  2902,     0,     0,     0,
       0,     0,     0,   180,   181,     0,   137,     0,  2903,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,  2905,     0, -1946,   139,
       0,     0,     0,     0,     0,     0,     0,     0,  2906, -1946,
       0,     0,     0,     0,     0,   140,     0,     0,     0,  2904,
    2907,  2908,     0,     0,     0,   141,     0,     0,  2909,  2994,
       0,  2910,     0,     0,  3295,     0,  3297,     0,     0,   298,
     142,     0,     0,     0,     0,     0,     0,     0,     0, -1946,
       0,     0,     0,     0,     0,     0,     0,     0,  2905,     0,
       0,     0,     0,     0,     0,     0,     0,  1183,     0,     0,
    2906,     0,     0,     0,     0,     1,     0,     0,     0,     2,
     143,     0,  2907,  2908,     0,  1235,   685,   686,   687,  1121,
    2909,   189,     0,  2910,     0,   688,     0,     0,   689,     0,
       0,   298,     0,   144,     0,   690,   691,     0,     0,     0,
   -1946,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1946,     0,     0,   148,
     692,   693,     0,   149,     0,   694,     0,     0,     0,  1475,
    1475,  1475,  1475,  1475,  1475,   695,   696,     0,   697,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   698,     0,     0,     0,     0,     0,     0,     0,
     151,     0, -1946,     0,     0,     0,     0,     0,     0,   699,
       0,     0,   700,   701,     0,     0, -1946, -1946, -1946, -1946,
   -1946, -1946, -1946,     0, -1946, -1946,     0,   702,     0,   703,
     704,   705,     0,     0,     0,     0,     0,     0,     0,   706,
     707, -1946,   708,   709,   710,     0,     0,     0,     0,     0,
     711,     0,     0,   712,     0,   713,   714,   715,     0,     0,
       0,     0,     0,   716,     0,   717,   718,     0,   719,     0,
     720,   721,     0,     0,   722,     0,     0,   723,   724,   725,
     726,   727,   728,     0,     0,     0,   729,   730,   731,     0,
     732,     0,     0,     0,   733,     0,   734,   735,     0,     0,
       0,     0,   736,     0,  1303,   737,     0,     0,   738,     0,
     739,     0,   740,     0,   741,     0,     0,  1235,   742,   743,
       0,   744,   745,   746,     0,     0,   747,     0,   748,   749,
       0,   750,     0,     0,     0,  2898,     0,     0,  2899,   751,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2900,   753,     0,     0,   754,   755,     0,     0,   756,
     757,     0,     0,   758,   759,     0,     0,     0,     0,     0,
       0,     0,   760,   761,   762,     0,   763,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   764,   765,   766,     0,
     767,  2902,     0,     0,   768,   769,     0,     0,     0,   770,
       0,     0,     0,  2903,     0,     0,     0,   771,     0,     0,
       0,     0,     0,     0,     0,   772,   773,   774,     0,     0,
       0,     0,     0,   775,   776,     0,     0,     0,     0,     0,
       0,   777,     0,     0,   778,     0,     0,     0,   779,   780,
       0,     0,     0,     0,  2904,     0,     0,     0,     0,   781,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   782,     0,     0,     0,
       0,     0,     0,     0,   783,     0,     0,     0,     0,     0,
     784,     0,     0,  2905,     0,     0,     0,     0,     0,     0,
       0,   785,     0,     0,     0,  2906,     0,     0,     0,     0,
       0,     0,     0,   786,     0,     0,     0,  2907,  2908,   787,
       0,   788,   789,     0,     0,  2909,     0,     0,  2910,   790,
       0,     0,     0,     0,     0,     0,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2514,   461,   462,
     463,     0,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,     0,     0,     0,   791,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   792,
       0,     0,     0,     0,     0,     0,   793,     0,     0,     0,
     477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     794,   795,     0,     0,     0,   796,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   797,     0,     0,
       0,     0,     0,   798,   799,   800,   801,     0,     0,     0,
     802,     0,     0,     0,   803,     0,     0,     0,     0,     0,
       0,   804,   805,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   806,     0,   807,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   808,     0,   809,     0,     0,
     810,     0,     0,     0,     0,     0,   811,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,   485,   486,     0,     0,
       0,     0,   812,     0,     0,   813,     0,     0,     0,     0,
     814,     0,     0,   815,   816,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   817,     0,
       0,     0,   461,   462,   463,   818,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   819,   820,
     821,   822,   823,   824,   825,     0,     0,   826,     0,   827,
       0,   828,     0,     0,   477,   461,   462,   463,     0,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,     0,     0,     0,     0,     0,   461,   462,   463,
       0,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,     0,     0,     0,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,     0,     0,   488,   477,
       0,     0,   461,   462,   463,     0,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,   484,
     485,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,   485,   486,     0,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,   485,   486,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   490,     0,     0,     0,   491,     0,     0,
       0,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
     485,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,   488,     0,     0,     0,     0,     0,     0,     0,
       0,   493,   461,   462,   463,     0,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,   488,     0,     0,     0,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,     0,   488,     0,     0,
       0,   461,   462,   463,     0,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
     495,     0,   488,   477,     0,     0,     0,     0,     0,   461,
     462,   463,   489,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,     0,   490,     0,     0,
       0,   491,   588,     0,     0,     0,     0,     0,     0,     0,
       0,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   477,     0,     0,     0,   489,     0,     0,     0,   484,
     485,   486,     0,     0,     0,     0,   496,   492,     0,     0,
     490,     0,     0,     0,   491,   602,     0,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   490,     0,     0,   493,   491,   612,     0,     0,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     492,     0,     0,   494,     0,     0,     0,     0,   484,   485,
     486,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   492,     0,     0,     0,     0,   490,   493,     0,
       0,   491,   980,     0,     0,     0,     0,     0,   478,   479,
     480,   481,   482,   483,     0,     0,   494,     0,     0,     0,
     493,     0,     0,     0,     0,     0,   484,   485,   486,     0,
       0,     0,     0,     0,     0,     0,     0,   492,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   495,     0,     0,     0,     0,   487,
       0,     0,   488,     0,     0,   493,   461,   462,   463,     0,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   494,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,   495,
     496,   488,     0,     0,     0,     0,     0,     0,   461,   462,
     463,     0,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   496,   495,     0,   487,     0,     0,   488,
     477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   490,     0,     0,
       0,   491,   986,     0,     0,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,   485,   486,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,   492,   461,   462,
     463,   489,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,     0,   490,     0,     0,     0,
     491,   987,     0,     0,     0,   493,     0,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,     0,     0,     0,
     477,     0,     0,   494,     0,   484,   485,   486,     0,   489,
       0,     0,     0,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,     0,   490,     0,     0,     0,   491,   988,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   493,   461,   462,   463,     0,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   494,     0,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   495,     0,   488,   477,     0,     0,
       0,     0,   493,     0,     0,     0,     0,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,     0,     0,     0,
     494,     0,     0,     0,     0,   484,   485,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,     0,   487,     0,     0,   488,     0,
     496,     0,   461,   462,   463,     0,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   478,   479,   480,   481,   482,   483,
       0,   495,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,   484,   485,   486,     0,   489,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   490,     0,     0,     0,   491,   989,     0,     0,     0,
       0,     0,     0,   462,   463,     0,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,     0,
       0,     0,     0,     0,     0,   487,     0,   496,   488,     0,
       0,   492,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,   490,     0,     0,     0,   491,     0,   493,
       0,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   494,     0,   484,
     485,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   991,     0,     0,  2380,
       0,     0,   487,     0,     0,   488,     0,     0,  1295,  1296,
    1297,   493,     0,     0,   277,  1298,  1299,    35,     0,     0,
       0,     0,     0,     0,     0,     0,  1300,  1301,     0,   494,
       0,   478,   479,   480,   481,   482,   483,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   484,
     485,   486,     0,   490,     0,     0,     0,   491,   463,     0,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   492,     0,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,   992,     0,  1302,   487,
     495,     0,   488,     0,   496,     0,     0,     0,     0,     0,
       0,   493,     0,     0,     0,   489,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
     490,     0,     0,     0,   491,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   496,     0,     0,     0,
     492,     0,     0,   477,     0,     0,     0,     0,     0,   487,
       0,     0,   488,   995,     0,   478,   479,   480,   481,   482,
     483,  2380,     0,     0,     0,     0,     0,     0,   493,     0,
    1295,  1296,  1297,   484,   485,   486,   277,  1298,  1299,    35,
     495,     0,     0,     0,     0,     0,   494,     0,  1300,  1301,
       0,     0,   489,     0,  1121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   490,     0,     0,
       0,   491,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     478,   479,   480,   481,   482,   483,   496,   492,     0,   477,
       0,     0,     0,     0,     0,     0,     0,     0,   484,   485,
     486,     0,     0,     0,     0,     0,     0,   495,     0,     0,
    1302,     0,   489,     0,     0,   493,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   490,     0,     0,
       0,   491,     0,   494,     0,     0,     0,     0,  2381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   477,   487,     0,     0,   488,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,   496,   468,   469,   470,   471,   472,   473,
     474,   475,   476,     0,     0,     0,   478,   479,   480,   481,
     482,   483,     0,     0,     0,   493,     0,     0,     0,     0,
       0,     0,     0,     0,   484,   485,   486,     0,   477,     0,
       0,     0,     0,   494,   495,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1121,     0,   487,  1303,
       0,   488,     0,     0,     0,     0,     0,     0,     0,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,   485,   486,
    1304,     0,     0,  2382,     0,     0,   489,     0,     0,     0,
     496,     0,     0,     0,     0,  2383,  1306,     0,     0,     0,
       0,   490,     0,     0,   495,   491,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   478,   479,   480,   481,   482,
     483,     0,     0,  1688,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,   485,   486,  1307,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1308,     0,
    2381,     0,     0,     0,   487,     0,     0,   488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
     496,   489,   469,   470,   471,   472,   473,   474,   475,   476,
       0,     0,     0,     0,     0,     0,   490,   494,     0,  1309,
     491,     0,     0,     0,     0,   470,   471,   472,   473,   474,
     475,   476,     0,     0,     0,   477,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,     0,     0,
     488,     0,  1310,     0,     0,     0,   492,   477,  1311,     0,
       0,     0,     0,     0,     0,     0,     0,  1312,  1313,     0,
    1314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1303,  1315,  1316,   493,     0,     0,     0,     0,     0,
    1317,     0,     0,  1318,     0,     0,     0,     0,   495,     0,
       0,   298,   494,   487,     0,     0,   488,   489,     0,     0,
       0,     0,  1304,     0,     0,  2382,     0,     0,     0,     0,
       0,     0,   490,     0,     0,     0,   491,  2383,  1306,     0,
       0,     0,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,   485,   486,     0,   478,   479,   480,   481,   482,   483,
       0,     0,   492,     0,   496,     0,     0,     0,  1307,     0,
     489,     0,   484,   485,   486,   990,     0,     0,     0,     0,
    1308,     0,     0,   495,     0,   490,     0,     0,     0,   491,
     493,     0,   471,   472,   473,   474,   475,   476,     0,     0,
       0,   472,   473,   474,   475,   476,     0,     0,   494,     0,
    1295,  1296,  1297,     0,     0,     0,   277,  1298,  1299,    35,
       0,  1309,     0,   477,     0,   492,   489,     0,  1300,  1301,
       0,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   490,     0,     0,     0,   491,     0,     0,     0,   496,
       0,     0,     0,   493,  1310,     0,     0,     0,     0,     0,
    1311,     0,     0,     0,     0,     0,     0,     0,     0,  1312,
    1313,   494,  1314,     0,     0,     0,     0,     0,     0,     0,
       0,   492,     0,     0,  1315,  1316,     0,     0,   477,   495,
     487,     0,  1317,   488,     0,  1318,     0,     0,  1295,  1296,
    1297,     0,     0,   298,   277,  1298,  1299,    35,     0,   493,
    1302,     0,   487,     0,     0,   488,  1300,  1301,     0,     0,
     478,   479,   480,   481,   482,   483,     0,   494,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,   485,
     486,     0,     0,     0,     0,     0,   484,   485,   486,     0,
       0,     0,   495,     0,     0,   496,  1295,  1296,  1297,     0,
       0,     0,   277,  1298,  1299,    35,     0,     0,     0,     0,
       0,     0,     0,     0,  1300,  1301,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,  1302,     0,
       0,     0,     0,   484,   485,   486,     0,     0,   495,     0,
       0,     0,     0,   489,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   490,     0,
       0,     0,   491,     0,     0,   489,  1121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     490,  1295,  1296,  1297,   491,     0,  1302,   277,  1298,  1299,
      35,     0,     0,     0,     0,     0,     0,     0,   492,  1300,
    1301,     0,     0,     0,   496,     0,     0,     0,   487,     0,
       0,   488,     0,     0,     0,     0,   487,     0,     0,   488,
     492,     0,     0,  1295,  1296,  1297,   493,     0,     0,   277,
    1298,  1299,    35,     0,     0,     0,     0,     0,     0,     0,
       0,  1300,  1301,     0,   494,     0,     0,     0,   493,     0,
       0,     0,     0,     0,  1121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,     0,     0,
    2381,     0,     0,   487,     0,     0,   488,     0,  1295,  1296,
    1297,  1302,     0,     0,   277,  1298,  1299,    35,     0,     0,
       0,     0,  2895,  2896,     0,     0,  1300,  1301,   277,  1298,
    1299,    35,     0,     0,     0,     0,     0,     0,     0,     0,
    1300,  1301,  1121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1302,     0,   495,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,     0,     0,     0,   490,   495,     0,     0,
     491,     0,     0,     0,   490,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1303,     0,     0,     0,     0,     0,     0,  1302,     0,
       0,     0,     0,     0,     0,     0,   492,     0,     0,     0,
       0,   496,  2897,     0,   492,     0,   489,     0,     0,     0,
       0,     0,  1304,     0,     0,  2382,     0,  1121,     0,     0,
       0,   490,     0,   496,   493,   491,     0,  2383,  1306,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,  1297,   494,     0,     0,   277,  1298,  1299,    35,     0,
     494,     0,     0,     0,     0,     0,     0,  1300,  1301,  1121,
       0,   492,  2248,  2249,  2250,  2251,  2252,  2253,  1307,  1303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1308,     0,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1304,     0,     0,  1305,     0,     0,     0,   494,     0,     0,
       0,     0,     0,     0,  1121,     0,  1306,     0,     0,     0,
       0,  1309,     0,   495,     0,     0,     0,  1303,  1121,     0,
       0,   495,     0,     0,     0,     0,     0,     0,     0,  1302,
       0,     0,     0,  1688,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1310,     0,  1307,     0,  1304,  2254,
    1311,  1305,     0,     0,     0,     0,     0,     0,  1308,  1312,
    1313,     0,  1314,     0,  1306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1315,  1316,     0,     0,   495,   496,
       0,     0,  1317,     0,     0,  1318,     0,   496,     0,     0,
       0,     0,     0,   298,     0,     0,     0,     0,     0,  1309,
       0,     0,     0,  2217,  1307,     0,     0,     0,     0,     0,
       0,     0,  1303,     0,     0,     0,  1308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1310,   201,     0,     0,     0,     0,  1311,     0,
       0,   202,     0,  1304,   496,     0,  1305,  1312,  1313,     0,
    1314,     0,     0,     0,  1303,  1121,     0,  1309,     0,  1306,
       0,     0,  1315,  1316,     0,     0,     0,     0,     0,     0,
    1317,     0,     0,  1318,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,     0,  1304,     0,     0,  1305,     0,
    1310,     0,     0,     0,     0,     0,  1311,     0,  3341,  1307,
       0,  1306,     0,     0,     0,  1312,  1313,     0,  1314,  2015,
       0,  1308,     0,  2074,     0,     0,     0,     0,   203,     0,
    1315,  1316,     0,  1303,     0,     0,     0,     0,  1317,     0,
       0,  1318,     0,     0,   204,   205,     0,     0,     0,   298,
    1304,  1307,     0,  1305,   206,     0,     0,     0,     0,     0,
       0,     0,  1309,  1308,  2898,     0,  1306,  2899,     0,     0,
       0,     0,  2248,  2249,  2250,  2251,  2252,  2253,     0,     0,
    2900,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1310,  2255,     0,     0,     0,
       0,  1311,     0,     0,  1309,     0,  1307,     0,     0,  2256,
    1312,  1313,     0,  1314,     0,     0,     0,     0,  1308,     0,
    2902,     0,     0,     0,     0,  1315,  1316,     0,     0,     0,
       0,     0,  2903,  1317,     0,     0,  1318,  1310,     0,     0,
       0,     0,     0,  1311,   298,     0,     0,     0,     0,     0,
       0,     0,  1312,  1313,     0,  1314,     0,     0,     0,  1309,
       0,     0,     0,     0,     0,     0,     0,  1315,  1316,  2254,
    1303,  2257,     0,  2904,     0,  1317,     0,  2258,  1318,     0,
       0,     0,     0,     0,     0,     0,   298,     0,     0,     0,
       0,     0,  1310,     0,     0,     0,     0,     0,  1311,     0,
       0,  1304,     0,     0,  1305,     0,     0,  1312,  1313,     0,
    1314,     0,  2905,     0,     0,     0,  2259,  1306,     0,     0,
       0,     0,  1315,  1316,  2906,   207,     0,     0,     0,     0,
    1317,     0,     0,  1318,     0,     0,  2907,  2908,     0,     0,
    2260,   298,     0,     0,  2909,     0,     0,  2910,     0,     0,
    2261,  2262,     0,     0,     0,   298,  2263,  1307,     0,  2075,
       0,     0,     0,     0,   208,     0,  2264,     0,     0,  1308,
       0,     0,     0,     0,  3312,     0,     0,     0,     0,  2076,
    2077,  2078,     0,   209,   210,   211,   212,     0,  2265,     0,
       0,  2266,  2267,     0,     0,     0,  2268,     0,     0,     0,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
    1309,     0,     0,     0,     0,     0,     0,     0,  2079,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
    2080,  3313,     0,     0,     0,   215,     0,     0,     0,     0,
       0,  2081,     0,  1310,     0,     0,   216,     0,     0,  1311,
       0,     0,     0,  2269,     0,     0,  3314,  2082,  1312,  1313,
       0,  1314,   217,     0,  2270,  3315,     0,  2083,     0,     0,
       0,     0,   218,  1315,  1316,     0,     0,     0,     0,     0,
       0,  1317,  2084,     0,  1318,     0,     0,   219,     0,     0,
       0,     0,   298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3316,     0,     0,  2255,     0,     0,     0,
       0,  3317,     0,     0,     0,     0,     0,     0,     0,  2256,
       0,     0,     0,     0,     0,     0,     0,   220,     0,     0,
    2085,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2086,     0,     0,     0,     0,   222,     0,     0,     0,     0,
    2087,     0,   223,     0,     0,   224,     0,     0,     0,     0,
       0,  2257,     0,     0,     0,     0,     0,  2258,     0,     0,
       0,  2088,     0,     0,     0,  2089,   225,     0,     0,     0,
     226,     0,  3318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,     0,     0,  2090,     0,     0,  2259,     0,     0,     0,
       0,     0,  2091,     0,     0,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2261,  2262,     0,     0,     0,     0,  2263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2264,     0,     0,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2265,     0,
       0,  2266,  2267,     0,     0,     0,  2268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2269,     0,     0,     0,     0,     0,     0,
       0,     0,  3319,     0,  2270
};

static const short yycheck[] =
{
       3,     4,     5,     6,   397,    48,     9,   173,   108,   658,
    1468,  1136,  1151,  1058,  1171,   800,    57,  1147,  1148,  1005,
    1150,  1176,  1152,  1153,   547,   192,  1133,  1810,   798,  2013,
    1376,   600,     5,  1624,   262,   263,   692,   693,  2067,   782,
      43,   269,   248,  1295,  1296,   573,  2204,   175,  1755,  2065,
      93,  2359,    55,  1383,    57,  1589,  1590,  1758,   757,   590,
     264,   265,   593,   128,    27,    68,  1697,  1698,  1699,  1700,
      27,    20,    75,   173,   730,   642,    79,   733,    27,    82,
      83,  1749,    26,    27,    87,    88,    27,   743,  2050,  2247,
    2052,   747,   192,    27,    27,   751,    25,  1688,    27,   721,
       5,     5,   758,  2136,   107,  1132,  1934,   763,  1330,   765,
    1332,  2602,  2603,  2604,    27,   771,    72,     5,   774,  2605,
    1227,   124,     5,    20,   127,   781,  2322,    48,    25,   132,
      27,   153,   788,     5,  1241,  1260,    27,     5,   266,   795,
      27,     5,   270,     5,   272,     8,   274,   275,   276,    19,
     806,   718,    27,     5,   810,   283,    26,   323,   814,   287,
     288,    27,   729,   119,   820,     5,    24,   823,    26,   116,
     694,    19,    93,    27,   239,   240,    24,    25,    26,  2601,
    2602,  2603,  2604,    24,    25,    26,  1231,    24,    25,    26,
      27,   194,     5,    25,   150,    27,   818,   116,    24,    25,
      26,    27,   726,   727,     5,     5,     9,    10,    47,    12,
      13,    14,    15,    16,    17,    27,    62,   784,     5,  2445,
     787,    20,     5,   323,    19,     5,    25,   327,    27,   796,
       5,    26,    25,   236,    27,    24,    25,    26,    27,   242,
      25,    26,    27,  1408,    25,    33,    27,    25,  2374,    27,
    2376,   254,     5,   328,   778,     6,   788,   260,   261,   262,
     263,   264,   265,   135,   136,     5,   269,     5,   204,   511,
       5,   227,  1426,   229,     5,   215,    33,  2690,   400,     5,
       5,  1946,   122,     5,   124,   444,   126,    24,    25,    26,
      27,     5,   197,   139,   140,    25,  2919,    27,     5,   191,
     244,   290,   141,   142,    24,    25,    26,    27,   436,     5,
      25,   439,    27,   316,   317,   395,    27,   395,    27,  2601,
    2602,  2603,  2604,   326,    27,  2309,     5,   446,   456,   457,
     458,   459,   701,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     556,   518,   580,  2382,     5,  2138,   349,  2243,     5,     5,
     488,   489,    25,   543,    27,   493,     5,   495,  1525,     5,
       5,   551,   600,   628,     5,  2601,  2602,  2603,  2604,  2340,
     508,   509,   510,   511,   192,   193,     5,   515,   344,  1132,
     459,  1737,   144,     5,   350,     5,  1423,  1182,   767,   692,
     693,     5,    23,   217,   697,   698,   204,   244,   299,     0,
    1195,  2042,    25,   668,    27,   302,   582,   710,   518,   676,
       5,   312,  1467,    99,   100,   101,   102,   103,  1758,   671,
     961,     5,     5,     5,   511,   414,   765,   730,    31,     5,
     733,     6,   699,  1901,     5,   774,   739,  2408,   404,     5,
     743,   244,   298,    29,   747,   244,   244,     6,   751,    28,
     328,     5,   755,   756,     5,   758,   244,     5,   761,    26,
     763,   764,   765,  2895,  2896,     5,   328,  2899,   771,     5,
    1136,   774,   582,   409,     5,   345,   243,   244,   781,   482,
     657,   820,     5,   663,   823,   788,   430,   357,  3121,  3122,
     680,   490,   795,   306,   507,   548,   549,   244,    18,    19,
      20,    21,    22,   806,   244,     5,     5,   810,   405,    19,
       5,   814,   641,   414,   244,   647,    26,   820,   668,   244,
     823,  1055,    18,    19,    20,    21,    22,   540,   483,   405,
     543,   244,  1158,  1159,     5,   620,   493,   775,   551,   528,
     630,   710,   630,  1077,   205,     9,    10,   657,    12,    13,
      14,    15,    16,    17,     5,   568,   511,   570,     5,   108,
     109,     5,     5,     5,   205,   296,   579,   580,     5,     5,
     583,   537,     5,     5,     5,     5,   400,     5,     5,   793,
     794,  2575,   483,     5,   671,   674,     5,   600,     5,   138,
     139,   140,  1258,  1259,  1260,   119,     5,  2141,   449,   553,
       5,    27,   449,  2895,  2896,     5,   671,  2899,   822,     5,
     561,   825,     5,   426,   427,   647,  2291,   548,     5,   483,
     337,   244,     5,  1787,   511,  1789,   523,   528,     5,  3052,
     515,   337,   578,   446,  1429,   446,   446,   594,  2534,   728,
    2679,   446,    23,   544,    10,  3141,  1441,   523,   637,   599,
     118,  1184,   606,   446,    23,  2289,   409,   288,  1833,  2895,
    2896,   483,  2830,  2899,   566,   594,  2638,   680,   481,   613,
    1423,   489,   685,   686,   687,   688,   689,   690,   691,  2280,
    2848,   694,   695,   696,   405,   446,   699,  2893,   701,   479,
    1839,   704,   439,   706,  3126,   668,   446,   429,   446,   444,
    3132,  3133,   715,  3135,  3136,  3137,  3138,   605,    27,   591,
    1369,   446,  3144,   726,   727,   608,   479,  1259,   641,   449,
    2746,  1430,   446,   736,  2960,   668,   598,  2963,  2934,   742,
     713,  2448,   605,  2571,   608,   748,   749,   750,   479,  2450,
    1278,   754,   620,   479,   757,  1286,   759,   760,  1289,  1290,
    2776,   718,  2430,   668,   767,   669,   663,   770,   620,   718,
    2803,   641,   775,   776,  2807,   778,   720,   718,     5,   782,
     578,  1888,   785,  2113,   718,   598,   567,  2117,   791,   718,
     793,   794,  2754,  2015,  2756,   798,   799,   800,  3106,  1826,
     479,   804,   539,   523,   807,   608,   678,   446,   523,   812,
     446,   446,  3120,   671,   328,   602,   819,   605,   821,   822,
     483,   824,   825,   671,   827,   828,  2952,   602,   674,   669,
     671,   663,   479,   479,   671,   628,  3258,   677,   677,  3261,
    3262,  3263,  3264,  1136,  3126,   671,   641,   421,   605,  1974,
    3132,  3133,   306,  3135,  3136,  3137,  3138,  2079,  2080,   637,
     479,   446,  3144,    27,   663,   993,  3357,   479,   996,   479,
     483,   674,   602,   446,   446,   479,  1004,  1005,   663,  1403,
     446,   446,   671,   299,  1277,   446,   400,  1873,  1412,   446,
     446,   878,    27,  2061,  2062,  2063,   312,   446,  2066,  1515,
    3126,    11,   446,    27,   389,   446,  3132,  3133,   446,  3135,
    3136,  3137,  3138,   483,   641,  1439,   446,   288,  3144,   217,
     446,   724,   725,   289,  2899,   446,  3348,     0,   931,   288,
     444,   380,   506,   446,   671,  3357,   663,  3163,   690,   691,
     692,   693,   694,  3101,  3252,    18,   446,   303,   522,    59,
    2484,   671,    14,  2577,  2578,   440,   446,   446,    25,   635,
      27,  2129,   167,    30,    27,  1258,  1259,  1260,   507,   479,
     446,   574,   426,   427,  1988,   978,  3258,  1991,  1547,  3261,
    3262,  3263,  3264,    30,   442,   446,  2948,    34,  2950,  2951,
     299,   565,    39,   479,    25,  1562,    27,     5,   414,  2668,
       8,  2670,   478,   312,  2673,   446,  3035,   465,   212,   446,
     414,  1534,   446,   446,   446,  1018,  2978,  1020,   483,   446,
     446,   483,   446,   446,   446,   446,   446,   481,   446,   446,
     604,    25,  3258,    27,   446,  3261,  3262,  3263,  3264,   446,
      18,    19,    20,    21,    22,   453,   417,   446,    25,   446,
      27,   446,  1055,   373,   593,  1058,   446,  1013,   417,   633,
     446,  3287,   446,   446,   446,   511,  3348,   483,   642,   446,
    2227,  1074,   483,   446,  1077,  3357,  2422,  1283,   590,   446,
     244,   228,   129,  1826,   533,   441,  1871,   443,    26,  1613,
     548,  1615,  1616,   676,   395,  1619,  1620,   636,    25,   446,
      27,  1625,   400,    26,    27,   414,   620,   677,   312,   244,
     446,   483,   528,  1116,   415,   698,   699,  3146,  1121,  3251,
    2450,  2166,  3348,  3255,   528,  2293,  3110,   639,   544,  1132,
      25,  3357,    27,  1664,   590,  2303,  1667,   387,  2360,    25,
    2362,    27,  2364,  1146,  1147,  1148,   350,  1150,   483,  1152,
    1153,  3126,   518,  1938,   608,  1158,  1159,  3132,   511,  1815,
    3135,  3136,  3137,  3138,  1310,    30,  1312,  1313,  1155,    34,
    2295,    26,    27,   483,  1944,  1162,   336,   244,   325,  1182,
    1704,   244,   640,   639,   483,   299,   700,   701,   702,   349,
    1193,   557,  1195,   483,   652,   653,  2321,   711,   312,   478,
     510,  1204,   660,   590,  1207,   218,    25,   220,    27,  1212,
     414,  1778,   677,   244,   806,  3133,  1444,   641,   810,   528,
     674,   511,   814,   290,   428,   671,  3144,   676,  1231,  1232,
    2398,   639,   245,   637,   642,   544,   483,  1240,  1442,   302,
    1862,   483,   107,   290,   641,  2959,   695,   696,  2962,   114,
     244,  2965,   639,  1256,  1257,   292,   218,   641,   220,   641,
      18,    19,    26,    27,   380,   483,   715,   244,    26,    27,
     724,   725,    25,   397,    27,   439,    25,   641,    27,  1282,
      38,   405,   406,  3258,   483,  1941,  3261,  3262,  3263,  3264,
    1456,  2882,  1295,  1296,   641,   160,   161,  2966,   596,   663,
     414,  1825,  1305,   168,   439,   641,   430,  1372,   483,   433,
    1375,   324,   349,  2327,   327,  1318,   566,   244,  1974,  1547,
     483,   244,   482,  1326,   528,   449,    25,   577,    27,   630,
     483,   629,  1855,  2118,  2502,   336,   349,  2122,  1542,  1543,
     544,   483,    27,  3305,   411,   483,  2131,   299,   349,   244,
      25,   483,    27,    38,   221,   113,  1456,  1398,   244,  2466,
     312,    25,   324,    27,   411,   327,   403,   125,  2826,   483,
     407,  2156,  2511,  3348,  1377,   421,    20,    21,  1381,  1382,
    1383,   483,  1586,  1587,    26,    27,    20,   349,  2543,   244,
    1393,  1394,  1395,    27,   152,  1398,  1399,  1400,  1401,  1402,
    1403,  2508,   511,    26,    27,   218,    19,   220,   598,  1412,
    2567,    24,   459,    26,   528,  2667,  2668,   533,  2670,  2587,
    1423,  2673,  1425,   490,  1427,   244,  1429,  1430,  1952,   553,
     544,   676,   245,   483,  1437,  1438,  1439,   670,  1441,  1442,
     523,  1444,  1445,   490,   677,   482,    26,    27,   531,   421,
    1453,   483,   519,   698,   699,   483,  2786,  1460,  1461,  3173,
     506,   483,   414,    20,  1467,  1468,  3240,  3241,   446,   482,
      27,  2002,   519,   483,   159,  2933,   522,  2008,  2009,   669,
     244,   482,   606,   260,   261,   262,   244,  2063,   246,   613,
    2066,   244,   483,    20,  3125,   244,  3127,  3128,  3129,  3130,
      27,   145,   146,   147,   148,   149,   150,   483,  2032,  1512,
    1513,   324,  1515,   483,   327,  1518,  1519,   715,   483,   565,
     482,    20,  1815,   483,   209,   194,  3309,   483,    27,   198,
     978,   511,   641,  2519,   506,   483,   349,  1540,   736,  1542,
    1543,  2527,  2528,  3326,  1547,   244,  1549,  2114,  1551,  1552,
     522,   749,   483,  3327,   663,  3329,    20,   422,   604,   244,
     676,   246,   671,    27,   721,   722,   723,   434,   292,   244,
     483,  1574,   483,  2741,   421,  2743,   528,   421,    26,   695,
     696,   448,  1585,  1586,  1587,   343,    24,   633,    26,  1592,
    1593,  1656,   544,   565,  3377,  1723,   642,   510,   511,   715,
    2167,    20,   244,   483,  2128,   533,   483,   391,    27,  1612,
    1613,  3394,  1615,  1616,    26,   483,  1619,  1620,   402,  1622,
     378,   244,  1625,   677,   491,   349,   677,    20,  1832,    26,
     421,    19,   604,  2289,    27,   502,    24,    25,    26,  2295,
     510,   511,   510,   511,    20,    26,  1649,  3105,  1941,  2216,
     671,    27,   517,    24,   412,    26,   523,  1660,   343,   506,
     573,   633,   506,   530,   244,  2321,   424,  1732,   452,   482,
     642,   538,    25,   292,    27,   522,   453,    26,   522,   403,
     733,  1974,   466,   407,   421,  2470,    25,  1690,    27,  1692,
    1918,  1919,   690,   560,   747,   693,   694,    26,   751,  1702,
    1703,  1704,   460,   578,  1707,   573,  1709,  1710,  1711,  1712,
     763,    25,  2880,    27,  2966,   506,   483,   475,   565,  1722,
    2505,   565,  2890,    28,    29,   483,  1854,   412,   483,  1933,
     349,   522,   691,   692,   821,   420,   483,   824,   496,   424,
     827,  1744,   155,   156,   609,  1873,  1749,   483,   676,    24,
      25,    26,  1755,   483,  2278,  1758,   483,   604,   482,    26,
     604,   163,   164,   165,   115,   510,   511,   695,   696,   506,
     637,   555,  1728,  1776,   565,   460,   643,   173,   483,  1782,
     698,   483,   540,  2307,   403,   522,   633,   715,   407,   633,
    2835,    25,   710,    27,    24,   642,    26,   483,   642,  2323,
       5,   664,   665,   666,   667,  2973,   473,   565,  1811,    26,
      24,  2342,    26,   604,  2345,   511,  2347,  2348,    25,   671,
      27,   739,  1825,  1826,   689,   483,  1829,  1830,   565,  1832,
      26,   589,   697,    18,    19,    20,    21,   755,   756,   190,
      26,   526,   633,   761,  1847,    25,   764,    27,   693,   694,
    2374,   642,  2376,  2839,  1156,  1157,    26,  1305,  1160,  1161,
     700,   701,   214,   482,    20,    21,  1869,   604,  1871,    26,
     491,    25,    24,    27,    26,   633,    26,   229,   230,   275,
     565,   502,    26,    24,   642,    26,   238,   283,   112,  1892,
     190,  1894,  1895,   289,  1897,   291,   633,  1900,  1901,  3056,
     446,   252,   523,   254,   589,   642,   302,   483,  3065,   530,
      18,    19,    20,    21,    22,  1918,  1919,   538,   416,   270,
     272,  2577,  2578,   671,    25,  3082,    27,   278,    26,   281,
    1933,   282,   700,   701,   330,  1938,  1939,  1940,    25,   560,
      27,  1944,    24,   446,    26,  3113,   341,   342,   633,  1952,
     346,    24,   252,    26,   254,   351,   307,   642,   310,   483,
     145,   146,   147,   148,   149,   150,   483,   363,   726,   727,
     270,    25,   479,    27,   370,  1425,  1979,  1427,   278,  2503,
    2440,  2441,   282,  2149,  1987,  1988,  2895,  2896,  1991,   145,
     146,   147,   148,   149,   150,     5,  2289,   446,   483,   446,
     446,   446,  2295,   355,   446,   446,   483,   307,  2793,   523,
    2013,    18,    19,    20,    21,   677,    20,    20,   483,  2022,
    3145,   483,  2025,  2026,  2027,  2028,  2029,     5,  2321,  2032,
     446,   483,   511,  2036,  2037,   675,  2821,  2040,    26,  3207,
     671,   726,   727,    26,   312,   446,   446,   399,   479,  2149,
     416,   720,   721,    30,    20,    26,    26,    26,  2061,  2062,
    2063,    26,    26,  2066,  2067,  2068,    26,    26,  2071,   641,
      26,   446,  3229,  2695,  2696,  2697,   446,  2699,  2700,  2701,
    2702,  2703,  2704,   446,   980,   446,  2708,   983,   446,   985,
     986,   987,   988,   989,    26,     5,   446,  2100,    20,  2102,
    2103,    26,  2105,  2106,   483,    26,  2109,    26,    26,   314,
    2113,   190,   671,   446,  2117,  2118,     5,   677,   446,  2122,
      26,   446,   518,   356,   446,  2128,  2129,   523,  2131,  2132,
     446,   446,  2135,  2136,   530,   446,   675,     5,   145,   146,
     147,   148,   149,   150,   446,   446,   483,   677,   353,   818,
      26,   446,    26,  2156,   641,   677,   552,   446,    25,   828,
    2163,   557,    25,  2166,    25,   446,    25,   372,   373,   446,
     446,   675,  2175,   252,   446,   254,  2179,   446,   356,   671,
    3337,   446,  3312,  3313,  3314,  3315,  3316,  3317,   446,   446,
     446,   270,   446,  3238,   446,   446,   446,   483,   671,   278,
       8,  2204,   676,   282,   531,   479,   320,   412,   647,   512,
       5,   669,   669,   647,   293,   512,   710,   710,   473,   424,
      25,   671,   382,   511,   648,  2228,   663,   671,   307,     5,
     435,   473,     5,   400,   483,  2381,   483,  2383,   483,   483,
     483,   630,  1690,  2767,  1692,     8,   451,   641,    14,   627,
       5,   710,     5,   473,  1702,  1703,   461,   710,   483,    26,
     483,  1709,  1710,  1711,  1712,    26,   119,   722,   671,   144,
     511,   476,    26,   641,  3059,  2278,   511,   483,    26,   483,
     483,   483,   483,   483,  2577,  2578,   483,     5,   483,   473,
    2293,   746,  3077,   647,   483,   483,     5,  2340,  2301,  2302,
    2303,   483,    47,  2306,  2307,   677,  2309,   483,   677,   978,
     406,   516,   676,     5,   713,   608,    18,   207,    19,  2322,
    2323,   668,   446,  2326,  2327,  1690,   438,    25,   641,  2557,
    2979,  2559,   674,   671,   539,  2501,   630,   792,     5,   598,
     534,   534,  3328,   205,    26,   598,   453,   802,   377,   554,
     805,    26,   598,   446,   809,    26,   561,   446,   446,   564,
     815,   446,   817,  2366,   523,  2408,   578,   677,   677,   446,
     483,  2374,   671,  2376,  2377,  2542,   111,  2380,   483,  2382,
     585,   483,     5,   483,   589,   715,  2514,   671,   483,  1058,
    2393,  2519,   671,   641,   446,  2398,  2399,  2400,   668,  2527,
    2528,  2501,   641,   608,   677,   483,   598,     5,     5,  2412,
       5,  2942,   631,  2944,  2945,  3460,     5,   535,   483,     5,
       8,   626,    26,   373,    26,   119,   231,  2430,  2952,   272,
     381,   671,     5,     5,   446,  3220,   483,   483,   648,   677,
      43,   415,  2542,    14,   676,  2448,   677,  2450,   711,  1897,
     598,   602,     5,   153,   676,  2601,  2602,  2603,  2604,    26,
    2463,   483,   671,   483,   677,   598,     5,  2470,   479,   677,
     446,   446,   690,     5,   446,     5,     5,   676,   423,   670,
     387,    26,   479,   513,   483,   513,     5,   483,   483,  3145,
     483,   483,  2495,   483,  2497,     5,  2499,   483,   483,  2502,
    2503,     8,  2505,   671,   107,   108,   671,    63,    64,    65,
      66,   511,     5,   671,   605,   381,    25,  2520,   628,  2522,
    2523,  2524,   400,  2669,   511,  2671,   671,   400,   400,   483,
     415,   478,   511,     5,  2537,  1900,     5,    26,   702,     5,
       5,  2544,    25,    14,    14,    26,   668,   483,  2941,   605,
     647,     5,     5,   358,  2557,   647,  2559,   483,    26,   364,
     365,   366,  1231,   446,   446,  2013,  2569,  2570,   677,   446,
     173,     6,  2575,     7,  2022,   446,   446,  2025,  2026,  2027,
    2028,   386,   322,   500,  2587,     5,   446,   671,   446,   192,
      26,   677,   446,    26,    26,    26,    26,   671,  2601,  2602,
    2603,  2604,  2605,  2606,   671,    20,     5,  2811,   328,   618,
       5,     5,  2615,     5,   598,  1070,   719,  2620,     8,     5,
    2824,   446,   623,   671,   446,   523,  1295,  1296,   483,     5,
     186,   598,   677,     5,   677,   265,  1305,   675,   194,  2805,
     446,    26,   446,   446,   677,   677,   677,   203,   483,   483,
     206,     5,     5,  2656,  2657,    25,   677,   260,   675,    25,
      25,   499,   670,    25,  2667,  2668,    25,  2670,    26,    26,
    2673,    26,  2675,   350,    26,    26,  2679,    26,   483,    26,
       5,   446,   446,   483,   446,     5,   491,   446,   520,   494,
     483,   602,     8,   249,   446,   294,    26,   502,    25,   479,
     256,   493,   446,   400,   196,  2805,    20,     5,   605,   483,
       5,  2839,   483,   316,   317,   483,  2719,    14,   265,   446,
     323,  1176,   446,   483,   327,   483,   483,   483,     5,  2732,
     511,  1186,   537,  1188,    26,   446,    26,    26,  2741,  2742,
    2743,   446,   446,   494,   483,    26,    26,    26,  3041,  2895,
    2896,  3282,  3283,  2899,    26,   429,   620,   313,  3051,   446,
     294,   446,   446,   400,  2767,   446,   483,   572,   295,   511,
     493,   598,    14,   483,   446,     7,  2779,  2780,   446,  1268,
    2783,   446,   338,  2786,   446,   293,   591,   592,   293,   345,
    2793,   347,    26,   677,   446,   483,   447,   602,  1467,   446,
    2803,   357,   607,  2806,  2807,   446,   671,   627,  2811,    26,
     483,    25,   446,   479,   446,   295,   511,   446,  2821,   446,
     446,  2824,     5,  2826,    26,    26,   446,  3055,     5,   385,
     671,   671,  2835,   479,   446,    26,   479,   393,   671,  2522,
    2463,   646,  3387,  1004,  1554,  2200,  1881,    31,    33,  2132,
    2495,  2138,  3145,   355,   115,   119,   346,   356,  1727,   209,
     661,  2309,  1728,   227,  1294,   603,   214,   537,   385,   384,
    3377,  2874,   568,   678,   430,  1781,   996,  2880,   418,   570,
     804,  1265,  1985,  2860,  1992,  2125,  2889,  2890,  1831,  2892,
    2893,  1585,  2895,  2896,  2546,  1588,  2899,  1908,   454,  2224,
    2128,  3431,  1928,  1444,   507,  3073,    18,  2910,   127,   128,
      43,   130,   131,   132,    93,   518,  3000,    43,  2366,    24,
     933,   760,  1886,  1892,  1593,   327,  1565,  1593,  1513,  1895,
    2933,  2934,  3182,  2997,  2382,   491,  1232,  1020,   785,  3394,
    1511,  1438,  2544,  1427,  2735,  2393,   502,  3192,  1535,  2952,
    2717,  1861,   455,  2791,  2733,  3053,  2411,  2960,  3051,  3044,
    2963,  2783,  2117,  2966,  1761,  1744,  2969,  2071,  2971,  3403,
    2973,  2289,  2973,  1627,  1627,  2308,  1431,  1432,  1433,   582,
    3126,  1963,  2892,  3207,  2740,  2656,  3132,  3133,  2774,  3135,
    3136,  3137,  3138,  1448,  2997,  2657,  2032,  1951,  3144,  2380,
    3287,  2963,    44,    45,    46,  2433,  1612,    49,  2762,    51,
      52,   230,  3016,     9,  2412,  2377,   610,  3449,  2894,   238,
    2399,  1690,  2400,  1692,  1261,  2588,  1703,  3248,  2971,  1702,
    1607,  1257,  3035,  1702,  1703,  2302,  2889,  3124,  1580,  3143,
    1709,  1710,  1711,  1712,   600,   601,   602,  1453,  1722,  3132,
    2503,  1121,  3055,   272,   657,  2149,  3059,   613,  2501,   546,
    1443,  1516,   281,  1461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3077,    -1,    -1,  3244,    -1,    -1,
    1535,    -1,   685,   686,   687,    -1,   689,    -1,    -1,    -1,
      -1,   310,   311,    -1,    -1,    -1,  2544,    -1,  1553,    -1,
      -1,    -1,  3105,   706,    -1,    -1,    -1,  3110,    -1,  1564,
    3113,    -1,  3258,    -1,    -1,  3261,  3262,  3263,  3264,    -1,
      -1,  3124,    -1,  3126,    -1,    -1,    -1,  2575,    -1,  3132,
    3133,    -1,  3135,  3136,  3137,  3138,   355,    -1,  3141,   742,
    3143,  3144,    -1,  3146,  3244,   748,    -1,   750,    -1,    -1,
      -1,   754,    -1,    -1,   757,    -1,    -1,   760,  1647,  1648,
     716,    -1,    -1,    -1,    -1,  1654,    -1,   770,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3182,
     399,    -1,   785,    -1,  3187,    -1,  3189,    -1,   791,    -1,
      -1,    -1,    -1,  1862,    -1,   798,   799,   800,    -1,    -1,
    3328,   804,  3348,    -1,  3207,    44,    45,    46,    -1,   812,
      49,  3357,    51,    52,    -1,    -1,    -1,  3220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   828,    -1,  2675,  1897,    -1,
      -1,    -1,    -1,    -1,   453,  3238,  2601,  2602,  2603,  2604,
      -1,    -1,    -1,    -1,    -1,  3248,    -1,    -1,    -1,    -1,
      -1,  3254,    -1,    -1,    -1,  3258,    -1,    -1,  3261,  3262,
    3263,  3264,    -1,  3266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3280,    -1,    -1,
      -1,    -1,   324,    -1,  3287,   327,    -1,   329,  3291,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   349,    -1,  3312,
    3313,  3314,  3315,  3316,  3317,    -1,    -1,   359,    -1,    -1,
      -1,  3324,    -1,    -1,    -1,    -1,  1781,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,   380,    -1,
      -1,    -1,  1797,    -1,  2013,  3348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2022,  3357,    -1,  2025,  2026,  2027,  2028,
      -1,   403,    -1,    -1,    -1,   407,    -1,    -1,  2037,  1824,
      -1,    -1,    -1,    -1,    -1,  1864,  1831,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2067,    -1,
    3403,    -1,  3405,    -1,    -1,    -1,  1861,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1904,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1880,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
     482,    -1,    -1,    -1,  3447,  3448,  3449,   163,   164,   165,
      -1,    -1,    -1,    -1,    -1,  1058,    -1,  3460,    -1,  3462,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
      -1,  1074,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,   327,    -1,
     329,    -1,    -1,    -1,    -1,    -1,    -1,  2166,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     349,    -1,    -1,  1116,    -1,    -1,    -1,    -1,    -1,    -1,
     359,  2969,    -1,  2971,    -1,    -1,    -1,    -1,    -1,    -1,
    2895,  2896,    -1,    48,  2899,    -1,    -1,    -1,    -1,    -1,
      -1,   380,    -1,  1146,  1147,  1148,    -1,  1150,    -1,  1152,
    1153,    -1,    -1,    -1,    -1,  1158,  1159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   403,    -1,    -1,    -1,   407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    25,    -1,
     306,    -1,  1195,    -1,    -1,  2960,    -1,    -1,  2963,    -1,
      -1,    -1,    -1,    -1,  1207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1231,  1232,
     145,   146,   147,   148,   149,   150,    -1,  1240,    -1,    -1,
    2309,    -1,    -1,   482,    -1,    -1,    -1,    -1,   163,   164,
     165,    -1,  2107,  1256,  1257,    20,    21,    22,    -1,    -1,
      -1,    -1,  3110,    -1,    -1,    -1,    -1,    -1,  2123,  2124,
    2125,  2126,    -1,    -1,    -1,    -1,  3124,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,  2144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2194,  2195,    -1,    -1,    -1,
     426,  2380,    -1,  2382,    -1,    -1,  2205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2393,   441,    -1,    -1,    -1,   445,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2229,  2230,  2231,  2232,  2233,  2234,    -1,    -1,    -1,    -1,
    2239,  2240,  2241,  2242,    -1,  2210,    -1,  2246,    -1,  3124,
      22,  3126,    -1,    -1,    -1,   481,    -1,  3132,  3133,    -1,
    3135,  3136,  3137,  3138,    -1,    -1,  2445,    -1,    -1,  3144,
     145,   146,   147,   148,   149,   150,    48,    -1,   303,    -1,
      -1,   306,    -1,   509,   231,    -1,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,  3254,    -1,    -1,    -1,
      -1,   527,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      52,    -1,  1425,    -1,  1427,    -1,  1429,  1430,    -1,    -1,
      -1,    -1,    -1,    -1,  1437,  1438,    -1,    -1,  1441,  2328,
    2329,    -1,  1445,  3291,    -1,    -1,  2335,  2336,    -1,    -1,
      -1,    -1,    -1,  1456,    -1,    -1,    -1,  2312,    -1,  2314,
      -1,    -1,    -1,    -1,  1467,  1468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2544,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,    -1,
      -1,    -1,   608,  3258,    -1,    -1,  3261,  3262,  3263,  3264,
      -1,   163,   164,   165,    -1,    -1,  2575,    -1,    -1,  1512,
    1513,   426,  1515,    -1,    -1,  1518,  1519,    -1,    -1,    -1,
      -1,   358,  3287,    -1,    -1,    -1,   441,   364,   365,   366,
     445,    -1,  2601,  2602,  2603,  2604,    -1,    -1,   303,    -1,
      -1,   306,    -1,    -1,    -1,    -1,  1549,     9,    -1,   386,
      -1,    -1,    -1,    -1,    -1,  3403,    18,    19,   674,    -1,
      -1,    -1,    24,    25,    26,    27,   481,    -1,    -1,    -1,
      -1,  1574,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,  3348,    -1,    -1,    -1,  2656,  2657,  1592,
    1593,    -1,  3357,    -1,   509,    -1,  2485,  2486,  2667,  2668,
      -1,  2670,    -1,    -1,  2673,  2494,  2675,    -1,    -1,    -1,
    2679,    -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2476,    -1,    -1,  2479,    -1,  2695,  2696,  2697,    -1,
    2699,  2700,  2701,  2702,  2703,  2704,    -1,    -1,    -1,  2708,
      -1,   303,  2531,  2532,   306,    -1,  1649,    -1,    -1,    -1,
      -1,   113,    -1,    -1,   491,    -1,   118,   494,    -1,    -1,
      -1,   426,    -1,   125,    -1,   502,    -1,    -1,    -1,  2558,
      -1,  2560,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,
     445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2543,    -1,
     152,    -1,   324,   608,    -1,   327,     9,   329,    -1,    -1,
     537,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,   481,   349,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,   359,    -1,    -1,
      -1,    -1,  2621,  2622,    -1,   572,  2625,  2626,    -1,    -1,
      -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,   380,    -1,
      -1,    -1,    -1,    -1,   591,   592,    -1,    -1,    -1,   674,
      -1,    -1,   527,    -1,   426,   602,  2835,    -1,    -1,    -1,
     607,   403,    -1,    -1,    -1,   407,    -1,    -1,    -1,   441,
      -1,    -1,   244,   445,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   646,
      -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   481,
      -1,    -1,    -1,    -1,    -1,    -1,  2895,  2896,    -1,    -1,
    2899,    -1,    -1,    -1,  2723,    -1,    -1,    -1,    -1,   152,
      -1,   678,    -1,   608,  1847,    -1,    -1,   509,    -1,    -1,
     482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,  1871,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   343,    -1,    -1,    -1,    -1,   348,    -1,    -1,  1892,
      -1,  2960,    -1,    -1,  2963,    -1,    -1,  2966,  1901,    -1,
    2969,    -1,  2971,    -1,    -1,    -1,    -1,    -1,    -1,   674,
      -1,    -1,    -1,    -1,    -1,  2804,   378,    -1,    -1,  2808,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,   246,    -1,  1938,  1939,  1940,  2827,    -1,
      -1,  1944,    -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,  2846,    -1,  2814,
      -1,    -1,   424,    -1,    -1,    -1,  3035,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,    -1,    -1,
     442,    -1,    -1,    -1,    -1,   447,    -1,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2850,    -1,    -1,   460,    -1,
      -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   674,   475,    -1,    -1,    -1,    -1,   480,    -1,
      -1,   483,    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,
     343,    -1,    -1,   495,   496,   348,    -1,    -1,    -1,    -1,
      -1,  3110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3124,    -1,  3126,    -1,    -1,
      -1,    -1,    -1,  3132,  3133,   378,  3135,  3136,  3137,  3138,
      -1,    -1,    -1,   535,   536,  3144,    -1,  3146,   540,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3163,    -1,    -1,   559,    -1,   412,
      -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,     9,    -1,
      -1,   424,    -1,    -1,    -1,  2118,    -1,    18,    19,  2122,
      -1,    -1,    -1,    24,    25,    26,    27,   589,  2131,   442,
      -1,    -1,    -1,    -1,   447,    -1,   449,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2149,   460,    -1,    -1,
      -1,    -1,   465,  2156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   475,  2166,    -1,    -1,    -1,   480,    -1,  3238,
     483,   633,  2175,   486,    -1,    -1,  2179,    -1,   640,    -1,
     642,    -1,   495,   496,    -1,  3254,    -1,    -1,    -1,  3258,
     652,   653,  3261,  3262,  3263,  3264,    -1,    -1,   660,    -1,
      -1,  2204,    -1,    -1,    -1,  3094,  3061,    -1,  3097,   671,
      -1,    -1,   113,    -1,    -1,    -1,    -1,   118,  3287,    -1,
      -1,    -1,  3291,   536,   125,    -1,    -1,   540,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,
      -1,  3096,    -1,    -1,    -1,    -1,   559,    -1,   561,    -1,
      -1,   152,   565,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   726,   727,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,   589,    -1,    -1,  3348,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,  3357,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     633,    -1,    -1,  2326,    -1,    -1,    -1,   640,    -1,   642,
      -1,    -1,    -1,    -1,  3403,    -1,    -1,    -1,    -1,   652,
     653,    -1,    -1,   244,    -1,   246,    -1,   660,    -1,    -1,
      -1,    -1,    -1,  3242,    -1,    -1,    -1,    -1,   671,    -1,
      -1,   113,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3460,    -1,    -1,    -1,    -1,  2399,    -1,    -1,    -1,
     152,    -1,    -1,    -1,  3293,  3294,     9,  3296,    -1,  3298,
    3299,    -1,    -1,   726,   727,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2470,  3323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3365,   378,  3367,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   246,    -1,    -1,    -1,  2501,    -1,
      -1,    -1,  2505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   412,  3401,    -1,    -1,   118,    -1,  2520,    -1,  2522,
      -1,  2524,   125,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3420,  3421,    -1,  2537,  3424,    18,    19,  3427,  2542,
      -1,   442,    24,    25,    26,    27,   447,    -1,   449,   152,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,   460,
      -1,    -1,    -1,    -1,   465,    -1,  2569,  2570,    -1,    -1,
      -1,  3426,    -1,    -1,   475,    -1,    -1,    -1,    -1,   480,
      -1,    -1,   483,    -1,    -1,   486,    -1,    -1,    -1,    -1,
      -1,   343,    -1,    -1,   495,   496,   348,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,  2615,    -1,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   535,   536,   118,    -1,    -1,   540,
      -1,   244,    -1,   246,    -1,    -1,    -1,   548,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,
     412,    -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   589,    23,
     442,    -1,    -1,    -1,    -1,   447,    -1,   449,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,
      44,    45,    46,   465,    -1,    49,  2719,    51,    52,    -1,
      -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,   480,  2732,
      -1,   483,   633,    -1,   486,    -1,    -1,    -1,    -1,   640,
     343,   642,    -1,   495,   496,   348,    -1,    -1,    -1,    -1,
      -1,   652,   653,    -1,    -1,    -1,    -1,    -1,    -1,   660,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     671,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   535,   536,    -1,    -1,    -1,   540,    -1,
    2793,    -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,  2805,    -1,    -1,    -1,    -1,   559,    -1,   412,
     144,    -1,    -1,   565,    -1,    -1,    -1,    -1,  2821,    -1,
      -1,   424,    -1,  2826,   244,   726,   727,    -1,    -1,    -1,
      -1,    -1,  2835,    -1,    -1,    -1,    -1,   589,    -1,   442,
      -1,    -1,    -1,    -1,   447,    -1,   449,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   460,    -1,    -1,
      -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   475,    -1,    -1,    -1,    -1,   480,    -1,    -1,
     483,   633,    -1,   486,   218,    -1,   220,    -1,   640,    -1,
     642,    -1,   495,   496,    -1,    -1,    -1,    -1,    -1,    -1,
     652,   653,    -1,    -1,    -1,    -1,    -1,    -1,   660,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,   252,   671,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2933,   265,    -1,   536,    -1,    -1,   270,   540,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   548,    -1,    -1,   282,    -1,
      -1,    -1,    -1,    -1,   288,    -1,   559,    -1,   292,   293,
     294,   295,   565,    -1,    -1,    -1,    -1,   449,    -1,    -1,
      -1,    -1,    -1,   307,   726,   727,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,
     324,    -1,    -1,   327,  2997,   329,    -1,    -1,   480,    -1,
      -1,   483,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   496,   349,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,   359,    -1,    -1,   314,   449,
     633,    36,    37,    -1,    -1,    -1,    -1,   640,    -1,   642,
      -1,    -1,    -1,    -1,    -1,    -1,   380,   381,    -1,   652,
     653,    -1,    -1,   535,   536,    -1,  3059,   660,    -1,    -1,
     480,   395,    -1,   483,    -1,    -1,   548,   353,   671,   403,
      -1,    -1,    -1,   407,  3077,    -1,   496,    -1,    -1,    -1,
      -1,   415,   416,   417,    -1,    -1,   372,   373,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3105,   523,    -1,    -1,    -1,   589,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,   536,    -1,    -1,    -1,
      -1,    -1,    -1,   726,   727,    -1,   412,    -1,   548,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,   482,   435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,   493,
      -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,   589,
     652,   653,    -1,    -1,    -1,   461,    -1,    -1,   660,  3182,
      -1,   663,    -1,    -1,  3187,    -1,  3189,    -1,    -1,   671,
     476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3220,    -1,    -1,
     640,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
     516,    -1,   652,   653,    -1,  3238,    41,    42,    43,   244,
     660,  3244,    -1,   663,    -1,    50,    -1,    -1,    53,    -1,
      -1,   671,    -1,   539,    -1,    60,    61,    -1,    -1,    -1,
     594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,   564,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,   585,
     105,   106,    -1,   589,    -1,   110,    -1,    -1,    -1,  3312,
    3313,  3314,  3315,  3316,  3317,   120,   121,    -1,   123,    -1,
      -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     626,    -1,   676,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,    -1,   157,   158,    -1,    -1,   690,   691,   692,   693,
     694,   695,   696,    -1,   698,   699,    -1,   172,    -1,   174,
     175,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     185,   715,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,
     195,    -1,    -1,   198,    -1,   200,   201,   202,    -1,    -1,
      -1,    -1,    -1,   208,    -1,   210,   211,    -1,   213,    -1,
     215,   216,    -1,    -1,   219,    -1,    -1,   222,   223,   224,
     225,   226,   227,    -1,    -1,    -1,   231,   232,   233,    -1,
     235,    -1,    -1,    -1,   239,    -1,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,   449,   250,    -1,    -1,   253,    -1,
     255,    -1,   257,    -1,   259,    -1,    -1,  3460,   263,   264,
      -1,   266,   267,   268,    -1,    -1,   271,    -1,   273,   274,
      -1,   276,    -1,    -1,    -1,   480,    -1,    -1,   483,   284,
     285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   496,   297,    -1,    -1,   300,   301,    -1,    -1,   304,
     305,    -1,    -1,   308,   309,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   317,   318,   319,    -1,   321,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   331,   332,   333,    -1,
     335,   536,    -1,    -1,   339,   340,    -1,    -1,    -1,   344,
      -1,    -1,    -1,   548,    -1,    -1,    -1,   352,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,   361,   362,    -1,    -1,
      -1,    -1,    -1,   368,   369,    -1,    -1,    -1,    -1,    -1,
      -1,   376,    -1,    -1,   379,    -1,    -1,    -1,   383,   384,
      -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,    -1,   394,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,    -1,    -1,
     425,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,    -1,    -1,    -1,   652,   653,   454,
      -1,   456,   457,    -1,    -1,   660,    -1,    -1,   663,   464,
      -1,    -1,    -1,    -1,    -1,    -1,   671,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   514,
      -1,    -1,    -1,    -1,    -1,    -1,   521,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     545,   546,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,
      -1,    -1,    -1,   568,   569,   570,   571,    -1,    -1,    -1,
     575,    -1,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,
      -1,   586,   587,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   597,    -1,   599,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   610,    -1,   612,    -1,    -1,
     615,    -1,    -1,    -1,    -1,    -1,   621,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,   647,    -1,    -1,   650,    -1,    -1,    -1,    -1,
     655,    -1,    -1,   658,   659,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   673,    -1,
      -1,    -1,     6,     7,     8,   680,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   703,   704,
     705,   706,   707,   708,   709,    -1,    -1,   712,    -1,   714,
      -1,   716,    -1,    -1,    48,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,   306,    48,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,    -1,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,    -1,   426,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   441,    -1,    -1,    -1,   445,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   509,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   527,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,   306,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   306,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
     608,    -1,   306,    48,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,   426,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   441,    -1,    -1,
      -1,   445,   446,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,   426,    -1,    -1,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,   674,   481,    -1,    -1,
     441,    -1,    -1,    -1,   445,   446,    -1,   426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,   509,   445,   446,    -1,    -1,
     145,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
     481,    -1,    -1,   527,    -1,    -1,    -1,    -1,   163,   164,
     165,    -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   481,    -1,    -1,    -1,    -1,   441,   509,    -1,
      -1,   445,   446,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,    -1,    -1,   527,    -1,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   306,    -1,    -1,   509,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   527,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   608,
     674,   306,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   674,   608,    -1,   303,    -1,    -1,   306,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,    -1,    -1,   674,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,
      -1,   445,   446,    -1,    -1,   145,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,    -1,
     674,    -1,    -1,    -1,    -1,    -1,    -1,   481,     6,     7,
       8,   426,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,   441,    -1,    -1,    -1,
     445,   446,    -1,    -1,    -1,   509,    -1,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,   527,    -1,   163,   164,   165,    -1,   426,
      -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,   445,   446,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   509,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   527,    -1,   481,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   608,    -1,   306,    48,    -1,    -1,
      -1,    -1,   509,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     527,    -1,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   608,    -1,   303,    -1,    -1,   306,    -1,
     674,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
      -1,   608,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,    -1,   426,    -1,    -1,   674,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   441,    -1,    -1,    -1,   445,   446,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,   674,   306,    -1,
      -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   441,    -1,    -1,    -1,   445,    -1,   509,
      -1,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   494,    -1,    -1,     9,
      -1,    -1,   303,    -1,    -1,   306,    -1,    -1,    18,    19,
      20,   509,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,   527,
      -1,   145,   146,   147,   148,   149,   150,    -1,   426,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,   163,
     164,   165,    -1,   441,    -1,    -1,    -1,   445,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   494,    -1,   118,   303,
     608,    -1,   306,    -1,   674,    -1,    -1,    -1,    -1,    -1,
      -1,   509,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,
     441,    -1,    -1,    -1,   445,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   674,    -1,    -1,    -1,
     481,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   306,   494,    -1,   145,   146,   147,   148,   149,
     150,     9,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,
      18,    19,    20,   163,   164,   165,    24,    25,    26,    27,
     608,    -1,    -1,    -1,    -1,    -1,   527,    -1,    36,    37,
      -1,    -1,   426,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,
      -1,   445,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   674,   481,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,
     118,    -1,   426,    -1,    -1,   509,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   441,    -1,    -1,
      -1,   445,    -1,   527,    -1,    -1,    -1,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,   303,    -1,    -1,   306,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,
      -1,    -1,    -1,   674,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,    -1,    48,    -1,
      -1,    -1,    -1,   527,   608,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,   303,   449,
      -1,   306,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
     480,    -1,    -1,   483,    -1,    -1,   426,    -1,    -1,    -1,
     674,    -1,    -1,    -1,    -1,   495,   496,    -1,    -1,    -1,
      -1,   441,    -1,    -1,   608,   445,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   164,   165,   536,    -1,    -1,    -1,
      -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,   548,    -1,
     348,    -1,    -1,    -1,   303,    -1,    -1,   306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,
     674,   426,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,   441,   527,    -1,   589,
     445,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
     306,    -1,   622,    -1,    -1,    -1,   481,    48,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,   638,    -1,
     640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   449,   652,   653,   509,    -1,    -1,    -1,    -1,    -1,
     660,    -1,    -1,   663,    -1,    -1,    -1,    -1,   608,    -1,
      -1,   671,   527,   303,    -1,    -1,   306,   426,    -1,    -1,
      -1,    -1,   480,    -1,    -1,   483,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,   445,   495,   496,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,   145,   146,   147,   148,   149,   150,
      -1,    -1,   481,    -1,   674,    -1,    -1,    -1,   536,    -1,
     426,    -1,   163,   164,   165,   494,    -1,    -1,    -1,    -1,
     548,    -1,    -1,   608,    -1,   441,    -1,    -1,    -1,   445,
     509,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    -1,   527,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,   589,    -1,    48,    -1,   481,   426,    -1,    36,    37,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   441,    -1,    -1,    -1,   445,    -1,    -1,    -1,   674,
      -1,    -1,    -1,   509,   622,    -1,    -1,    -1,    -1,    -1,
     628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,
     638,   527,   640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   481,    -1,    -1,   652,   653,    -1,    -1,    48,   608,
     303,    -1,   660,   306,    -1,   663,    -1,    -1,    18,    19,
      20,    -1,    -1,   671,    24,    25,    26,    27,    -1,   509,
     118,    -1,   303,    -1,    -1,   306,    36,    37,    -1,    -1,
     145,   146,   147,   148,   149,   150,    -1,   527,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,    -1,
      -1,    -1,   608,    -1,    -1,   674,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,   163,   164,   165,    -1,    -1,   608,    -1,
      -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,   674,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,
      -1,    -1,   445,    -1,    -1,   426,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     441,    18,    19,    20,   445,    -1,   118,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,    36,
      37,    -1,    -1,    -1,   674,    -1,    -1,    -1,   303,    -1,
      -1,   306,    -1,    -1,    -1,    -1,   303,    -1,    -1,   306,
     481,    -1,    -1,    18,    19,    20,   509,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,   527,    -1,    -1,    -1,   509,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,
     348,    -1,    -1,   303,    -1,    -1,   306,    -1,    18,    19,
      20,   118,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    36,    37,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,   608,    -1,    -1,    -1,    -1,
      -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,
      -1,    -1,    -1,    -1,    -1,    -1,   441,   608,    -1,    -1,
     445,    -1,    -1,    -1,   441,    -1,    -1,    -1,   445,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,
      -1,   674,   118,    -1,   481,    -1,   426,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,   483,    -1,   244,    -1,    -1,
      -1,   441,    -1,   674,   509,   445,    -1,   495,   496,    -1,
      -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,   527,    -1,    -1,    24,    25,    26,    27,    -1,
     527,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,   244,
      -1,   481,    54,    55,    56,    57,    58,    59,   536,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,   483,    -1,    -1,    -1,   527,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    -1,   496,    -1,    -1,    -1,
      -1,   589,    -1,   608,    -1,    -1,    -1,   449,   244,    -1,
      -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   622,    -1,   536,    -1,   480,   151,
     628,   483,    -1,    -1,    -1,    -1,    -1,    -1,   548,   637,
     638,    -1,   640,    -1,   496,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   652,   653,    -1,    -1,   608,   674,
      -1,    -1,   660,    -1,    -1,   663,    -1,   674,    -1,    -1,
      -1,    -1,    -1,   671,    -1,    -1,    -1,    -1,    -1,   589,
      -1,    -1,    -1,   535,   536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   449,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    32,    -1,    -1,    -1,    -1,   628,    -1,
      -1,    40,    -1,   480,   674,    -1,   483,   637,   638,    -1,
     640,    -1,    -1,    -1,   449,   244,    -1,   589,    -1,   496,
      -1,    -1,   652,   653,    -1,    -1,    -1,    -1,    -1,    -1,
     660,    -1,    -1,   663,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   671,    -1,    -1,    -1,   480,    -1,    -1,   483,    -1,
     622,    -1,    -1,    -1,    -1,    -1,   628,    -1,   535,   536,
      -1,   496,    -1,    -1,    -1,   637,   638,    -1,   640,   449,
      -1,   548,    -1,   117,    -1,    -1,    -1,    -1,   117,    -1,
     652,   653,    -1,   449,    -1,    -1,    -1,    -1,   660,    -1,
      -1,   663,    -1,    -1,   133,   134,    -1,    -1,    -1,   671,
     480,   536,    -1,   483,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   589,   548,   480,    -1,   496,   483,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,    -1,    -1,
     496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   622,   388,    -1,    -1,    -1,
      -1,   628,    -1,    -1,   589,    -1,   536,    -1,    -1,   401,
     637,   638,    -1,   640,    -1,    -1,    -1,    -1,   548,    -1,
     536,    -1,    -1,    -1,    -1,   652,   653,    -1,    -1,    -1,
      -1,    -1,   548,   660,    -1,    -1,   663,   622,    -1,    -1,
      -1,    -1,    -1,   628,   671,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   637,   638,    -1,   640,    -1,    -1,    -1,   589,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,   653,   151,
     449,   463,    -1,   589,    -1,   660,    -1,   469,   663,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   671,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,   628,    -1,
      -1,   480,    -1,    -1,   483,    -1,    -1,   637,   638,    -1,
     640,    -1,   628,    -1,    -1,    -1,   508,   496,    -1,    -1,
      -1,    -1,   652,   653,   640,   314,    -1,    -1,    -1,    -1,
     660,    -1,    -1,   663,    -1,    -1,   652,   653,    -1,    -1,
     532,   671,    -1,    -1,   660,    -1,    -1,   663,    -1,    -1,
     542,   543,    -1,    -1,    -1,   671,   548,   536,    -1,   353,
      -1,    -1,    -1,    -1,   353,    -1,   558,    -1,    -1,   548,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,   373,
     374,   375,    -1,   372,   373,   374,   375,    -1,   580,    -1,
      -1,   583,   584,    -1,    -1,    -1,   588,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,
      -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,
     424,   313,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,
      -1,   435,    -1,   622,    -1,    -1,   435,    -1,    -1,   628,
      -1,    -1,    -1,   645,    -1,    -1,   338,   451,   637,   638,
      -1,   640,   451,    -1,   656,   347,    -1,   461,    -1,    -1,
      -1,    -1,   461,   652,   653,    -1,    -1,    -1,    -1,    -1,
      -1,   660,   476,    -1,   663,    -1,    -1,   476,    -1,    -1,
      -1,    -1,   671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,    -1,    -1,   388,    -1,    -1,    -1,
      -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,
     524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     554,    -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,
     564,    -1,   561,    -1,    -1,   564,    -1,    -1,    -1,    -1,
      -1,   463,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,
      -1,   585,    -1,    -1,    -1,   589,   585,    -1,    -1,    -1,
     589,    -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,
      -1,    -1,    -1,   617,    -1,    -1,   508,    -1,    -1,    -1,
      -1,    -1,   626,    -1,    -1,    -1,    -1,   626,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     542,   543,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   558,    -1,    -1,   668,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,
      -1,   583,   584,    -1,    -1,    -1,   588,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   645,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   654,    -1,   656
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    39,   129,   290,   411,   459,   490,   519,
     787,   814,   815,   871,  1043,  1044,  1100,  1102,  1103,  1104,
    1109,  1111,  1124,  1125,  1126,  1127,  1128,  1571,    28,    29,
     788,   789,   790,   791,   792,    27,  1007,  1586,  1007,  1007,
      25,  1007,  1476,  1129,   816,  1476,   815,     0,  1101,  1104,
    1127,    31,   790,   792,   872,   663,    25,   244,   813,   814,
     994,  1007,  1012,  1109,  1124,  1130,  1165,  1166,  1167,  1168,
    1169,  1173,   409,   818,   819,   820,   821,   824,   825,   107,
     114,   160,   161,   168,   422,   517,   609,   689,   697,   787,
     962,  1042,  1105,  1106,  1108,  1112,  1113,  1119,  1131,  1135,
    1286,  1296,  1571,   668,  1007,  1168,   296,   510,   511,  1174,
      20,  1007,  1172,   671,   819,     5,   817,   409,  1007,     5,
     843,   845,   846,  1007,  1297,  1007,  1007,  1287,  1120,  1007,
    1007,  1108,  1114,   314,   353,   372,   373,   412,   424,   435,
     451,   461,   476,   516,   539,   554,   561,   564,   585,   589,
     608,   626,   873,   874,   875,   878,    25,  1165,  1171,    18,
      19,    26,    38,   113,   125,   152,   246,   343,   378,   412,
     424,   460,   475,   483,   496,   540,   565,   589,   633,   642,
     726,   727,   737,   739,   931,   936,   947,   949,  1007,  1165,
    1175,  1176,   511,    14,   870,   821,   574,  1273,   822,   819,
     824,    32,    40,   117,   133,   134,   143,   314,   353,   372,
     373,   374,   375,   390,   412,   424,   435,   451,   461,   476,
     516,   539,   554,   561,   564,   585,   589,   608,   626,   668,
     828,   837,   848,   853,  1007,   483,   167,  1007,   813,   963,
    1136,  1007,   880,   373,   826,   483,   856,   858,   859,   857,
     866,   867,   483,   483,   879,   511,   483,   819,   854,   478,
     483,   483,   483,   483,   483,   483,   483,   483,   483,   483,
     483,   737,   483,   810,     9,    18,    19,    24,    25,    26,
     118,   348,   442,   447,   449,   465,   480,   483,   486,   495,
     536,   548,   559,   589,   640,   652,   653,   660,   671,   907,
     915,   916,   917,   918,   919,   947,   948,   950,  1013,  1165,
    1276,  1469,   483,   483,   483,   483,   483,   483,    18,    19,
      20,    21,    22,   738,    26,   483,   573,     5,   479,  1175,
      25,    26,  1007,  1013,    19,    25,    26,   823,  1013,   721,
     722,   723,   827,   850,   839,   851,   826,   483,   483,   483,
     840,   856,   857,   483,   483,   838,   511,   849,   483,   854,
     819,   847,   483,    26,  1007,   483,  1121,   813,   813,   483,
    1007,   483,   510,   832,    26,   677,   421,   506,   522,   565,
     604,   633,   642,   860,   677,   421,   506,   522,   565,   604,
     633,   642,   868,    26,    26,   881,   882,   883,   884,  1007,
      26,   835,   836,    26,   671,  1165,   718,   955,   998,  1007,
     998,   998,   955,   955,   907,    24,    25,    26,    19,    24,
      25,    26,   951,   952,   953,   954,    25,   956,   998,   999,
     907,   446,   907,   907,   907,   907,   578,  1293,   483,   483,
     907,   421,   506,   522,   565,   604,   633,   642,  1472,  1473,
     483,   907,   907,   483,   483,   920,   483,   483,   483,   483,
      26,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    48,   145,   146,
     147,   148,   149,   150,   163,   164,   165,   303,   306,   426,
     441,   445,   481,   509,   527,   608,   674,   809,   908,   921,
     923,   924,   925,   926,   927,   928,   929,   473,   939,   937,
     943,   941,  1165,  1165,   737,   932,  1007,  1176,   511,   479,
      26,   830,   483,   852,   819,   852,   832,    26,    26,    26,
     819,    26,    26,   818,   835,   852,    26,   671,   112,   844,
    1298,   446,   483,  1288,  1587,  1588,  1589,  1590,  1591,   964,
    1137,  1115,   671,    26,   446,   861,   862,   483,   863,   868,
     869,   863,   483,   864,     5,   446,     5,   446,     5,   337,
       5,   873,   479,     5,     5,   446,   819,   855,   446,   483,
       5,   446,   511,   671,   446,   446,   446,   446,   446,   446,
     446,    19,    26,   446,   641,   952,    19,    26,   641,   446,
       5,   446,   446,     5,   811,   907,   523,  1492,   907,   483,
     677,    20,   446,  1492,    20,  1276,   907,   907,   907,   907,
     907,   907,   907,   907,   907,   907,   907,   907,   907,   907,
     907,   907,   907,   907,   907,   907,   907,   907,   907,   483,
     907,   907,   483,  1165,   907,   907,   907,   907,   446,     5,
     535,   767,   768,   769,   907,   483,  1175,   511,   675,    26,
     671,    26,   446,   446,     5,   446,   312,     5,   446,     5,
     446,   337,   479,     5,   446,   855,  1007,  1181,  1182,  1184,
    1132,  1181,   416,  1588,  1273,    41,    42,    43,    50,    53,
      60,    61,   105,   106,   110,   120,   121,   123,   137,   154,
     157,   158,   172,   174,   175,   176,   184,   185,   187,   188,
     189,   195,   198,   200,   201,   202,   208,   210,   211,   213,
     215,   216,   219,   222,   223,   224,   225,   226,   227,   231,
     232,   233,   235,   239,   241,   242,   247,   250,   253,   255,
     257,   259,   263,   264,   266,   267,   268,   271,   273,   274,
     276,   284,   285,   297,   300,   301,   304,   305,   308,   309,
     317,   318,   319,   321,   331,   332,   333,   335,   339,   340,
     344,   352,   360,   361,   362,   368,   369,   376,   379,   383,
     384,   394,   411,   419,   425,   436,   448,   454,   456,   457,
     464,   503,   514,   521,   545,   546,   550,   562,   568,   569,
     570,   571,   575,   579,   586,   587,   597,   599,   610,   612,
     615,   621,   647,   650,   655,   658,   659,   673,   680,   703,
     704,   705,   706,   707,   708,   709,   712,   714,   716,   730,
     731,   732,   733,   750,   772,   786,   787,   793,   812,   886,
     887,   888,   889,   900,   901,   902,   903,   904,   905,   906,
     957,   988,   992,  1014,  1016,  1019,  1020,  1021,  1022,  1035,
    1045,  1069,  1070,  1072,  1076,  1091,  1092,  1096,  1097,  1098,
    1099,  1107,  1122,  1142,  1153,  1154,  1155,  1159,  1162,  1196,
    1199,  1201,  1207,  1208,  1211,  1214,  1217,  1219,  1221,  1224,
    1231,  1236,  1241,  1242,  1243,  1255,  1256,  1259,  1265,  1268,
    1269,  1294,  1309,  1310,  1311,  1312,  1313,  1325,  1331,  1332,
    1352,  1355,  1384,  1386,  1477,  1478,  1509,  1510,  1517,  1532,
    1556,  1571,  1572,  1577,  1578,  1580,  1584,  1585,  1592,   787,
    1110,   676,   699,  1138,  1139,  1181,    20,   446,   478,   833,
     860,    26,   865,    26,    26,    26,   882,   884,   876,   836,
      26,  1007,   998,   737,    20,   718,  1007,   860,   945,   945,
      26,   446,   641,   945,    24,    26,    26,   641,    24,    26,
     857,   946,   999,   858,   446,   414,   528,   637,  1500,   446,
     446,    26,  1473,   446,   446,   446,   446,   446,   446,   446,
     494,   494,   494,   930,  1492,   494,   930,  1492,   940,   938,
     944,   942,    26,   933,     5,   934,   479,  1175,   843,   446,
      20,   833,    26,   483,    26,    26,   829,    26,   671,   446,
       5,  1181,   446,  1165,  1165,  1165,  1007,    25,  1165,  1218,
    1007,    25,  1007,  1462,   405,  1008,  1009,  1586,  1008,    25,
    1007,  1461,  1007,  1007,  1239,  1002,  1008,  1002,  1007,  1582,
    1462,  1007,    26,   734,  1165,  1316,  1002,  1239,   930,    26,
    1013,  1281,  1282,  1281,   907,   914,  1354,  1461,  1461,   909,
     930,  1008,  1518,  1518,   890,  1239,  1002,  1314,  1165,  1004,
    1008,   914,  1518,  1165,  1239,  1165,  1353,  1518,    25,   637,
    1156,  1157,  1165,  1002,  1002,  1156,  1003,  1008,  1007,  1157,
    1002,  1518,  1002,  1004,  1462,  1165,  1194,  1195,  1000,  1008,
    1004,   430,   613,   998,  1071,  1007,   794,  1461,  1005,  1008,
      25,   244,  1007,  1385,  1560,  1562,  1563,  1564,  1565,  1567,
     930,  1194,   677,   930,  1008,  1220,   958,    63,    64,    65,
      66,   186,   194,   203,   206,   249,   256,   313,   338,   345,
     347,   357,   385,   393,   430,   454,   491,   502,   600,   601,
     602,   613,   716,  1085,  1215,  1216,  1165,  1186,  1187,   913,
     914,  1230,   955,   955,  1001,  1008,   930,  1218,  1295,  1165,
    1272,    25,   483,  1165,  1267,  1512,  1266,   914,  1573,   159,
     209,   246,   343,   420,   460,   526,   751,   936,  1007,  1165,
    1304,   774,   914,  1000,   641,  1007,  1015,  1143,   914,  1000,
      26,  1165,  1093,  1000,   914,  1533,   914,  1281,  1007,  1017,
    1018,  1004,  1017,   955,  1004,  1017,   955,  1023,  1017,    25,
      26,   439,   539,  1013,  1074,  1165,  1183,  1185,   119,   328,
     400,   444,   620,   700,   701,   702,   711,   741,  1025,  1027,
    1029,  1031,  1033,  1160,  1161,  1164,   391,   402,   452,   466,
     555,  1387,   691,   692,   966,   967,   968,  1007,  1140,   698,
    1139,   446,   356,   446,   446,   446,   446,   675,     5,   446,
     446,   479,   483,   677,    19,    26,   446,   945,    26,   446,
     446,   641,    26,   641,   677,    18,    19,    20,    25,    26,
      36,    37,   118,   449,   480,   483,   496,   536,   548,   589,
     622,   628,   637,   638,   640,   652,   653,   660,   663,  1007,
    1013,  1468,  1470,  1499,  1501,  1502,  1504,  1505,  1506,  1528,
    1529,  1530,  1531,  1561,  1562,  1566,  1293,   446,  1293,  1293,
    1293,  1293,  1293,  1293,    25,    25,    25,   907,   922,   446,
      25,   922,   446,   446,   446,   446,   446,   446,   446,   769,
     767,   479,   356,   446,   819,   841,   842,   446,   446,   675,
     446,  1007,  1299,  1184,   446,  1289,   108,   109,   138,   139,
     140,   507,   593,   636,  1333,  1334,  1335,  1338,  1341,  1344,
    1345,  1346,  1349,   671,   641,   663,   155,   156,   483,   671,
     641,   663,     8,   676,   479,  1461,   531,  1240,  1183,   163,
     164,   165,   647,   535,   910,   911,   914,  1165,  1190,  1461,
     740,   741,   893,   320,    47,   141,   142,   677,  1237,   512,
       5,   670,   677,   669,   669,  1197,   647,   473,     5,   608,
    1046,   512,   710,  1575,   710,   439,   796,  1165,   598,   669,
    1202,  1203,  1204,   671,    25,  1563,   511,  1568,   382,  1383,
     663,   671,   912,   914,   608,  1560,   912,     8,   605,  1001,
      26,   553,   606,   720,   993,  1165,   993,   993,   993,    25,
     231,   358,   364,   365,   366,   386,   491,   494,   502,   537,
     572,   591,   592,   602,   607,   646,   678,  1089,  1090,   993,
     993,   648,  1086,   741,  1086,  1086,   994,   994,  1086,  1086,
     741,     5,   473,     5,   389,   440,     5,   740,   135,   136,
     591,   678,  1077,   713,  1576,   913,   664,   665,   666,   667,
    1271,  1512,  1273,   914,  1261,  1262,  1263,  1274,  1275,   914,
     483,   483,   483,   483,    25,   770,  1007,   483,  1512,   400,
     483,   573,   641,   630,   775,   782,   773,  1007,    25,  1158,
    1165,  1257,     8,  1260,    14,  1007,  1170,  1177,  1178,  1180,
    1188,  1189,  1232,   217,   400,   596,   629,    33,   244,   605,
    1534,  1535,  1536,  1538,   627,     5,   710,   710,   912,  1183,
    1190,  1073,   473,     5,   205,  1051,   483,  1165,   912,   483,
      26,    26,   119,  1163,    25,  1165,  1516,  1516,  1008,  1367,
    1220,  1001,   173,   275,   283,   289,   291,   302,   330,   346,
     351,   363,   370,   518,   523,   530,   552,   557,  1356,  1357,
    1365,  1374,  1375,  1381,  1382,  1388,  1389,  1399,  1419,  1423,
    1488,  1489,  1519,  1520,  1523,  1524,  1540,   969,   970,   144,
     965,   976,   977,   968,  1141,  1587,  1116,   511,   873,   836,
     671,  1007,   860,    26,   446,   641,   945,   446,   641,   945,
     945,    24,    26,   641,    24,    26,   861,  1505,  1505,   421,
     506,   522,   565,   604,   633,   642,  1471,  1474,   523,  1504,
     483,   483,   483,   483,  1499,  1499,  1499,   483,   483,   483,
     483,  1007,   483,     5,   598,  1428,  1433,   668,  1007,    18,
      19,    20,    21,   145,   146,   147,   148,   149,   150,  1526,
    1474,  1474,   473,     5,   446,   446,   935,   511,     5,   446,
     843,   813,  1133,   813,   299,   312,   414,   483,   528,   544,
    1403,  1404,  1409,  1411,   483,  1007,  1350,  1351,    26,   483,
    1007,  1330,  1343,  1411,  1413,   483,  1007,  1340,   483,  1330,
    1336,     5,  1007,    25,  1007,  1007,    25,  1010,  1168,  1007,
      25,  1007,  1007,  1007,  1583,  1461,   647,   483,   483,   893,
    1461,     5,   677,   483,  1560,    25,  1012,  1238,  1237,  1238,
    1512,  1156,   914,   914,   914,   995,   996,   483,  1165,  1195,
    1047,  1048,  1049,  1461,   677,  1512,   955,  1576,  1071,  1165,
     795,   676,   914,   406,  1206,   608,  1205,  1564,   737,  1569,
    1570,  1007,    20,  1565,     5,  1557,   668,  1212,   122,   124,
     126,   669,   677,   885,  1183,  1186,   959,    18,    19,   483,
    1087,  1089,  1216,  1165,  1187,   994,   914,   400,   647,    26,
    1165,    26,  1165,   740,   207,  1270,   446,   438,  1308,  1273,
    1263,     5,   669,  1264,  1574,  1007,    25,   955,   955,   641,
     999,   674,  1165,   755,  1007,  1007,   914,   395,   778,   782,
     630,   776,   784,    23,   288,  1145,  1149,   534,   930,   534,
    1258,   914,   510,  1174,   671,     5,  1094,   598,  1233,  1165,
    1537,  1539,   243,  1535,  1036,  1018,   955,   955,  1028,  1029,
    1051,  1051,    44,    45,    46,    49,    51,    52,   324,   327,
     329,   349,   359,   380,   403,   407,   482,  1050,  1052,  1053,
    1081,  1165,  1185,   598,   742,    26,   453,  1034,   377,  1511,
    1511,   192,   193,   489,   598,  1007,  1420,  1421,  1463,  1461,
    1461,  1461,  1358,  1461,  1461,  1007,  1521,   221,   434,   448,
     491,   502,   523,   530,   538,   560,   637,   643,  1390,  1392,
    1393,  1394,  1500,  1461,  1366,  1390,  1392,  1587,  1587,   439,
     978,  1165,   693,   694,   971,   972,   973,   533,   676,   695,
     696,   715,   981,   982,  1587,   813,    26,   834,    20,  1007,
     446,    26,   446,   945,    26,   945,    24,    26,   446,   446,
      24,    26,   677,  1500,   446,   449,  1504,  1527,  1566,   414,
     528,   637,  1452,  1504,  1507,  1452,  1452,  1452,  1452,   671,
    1507,  1502,   567,  1429,  1430,  1431,  1461,   578,  1427,  1434,
     387,   566,   577,  1376,  1495,  1007,  1504,  1504,  1504,  1504,
     677,   483,   677,  1561,   907,   446,   834,   842,  1300,   813,
    1290,   483,   483,   483,  1347,  1411,   483,   483,   111,  1348,
    1350,     5,  1342,  1343,   117,   353,   373,   374,   375,   412,
     424,   435,   451,   461,   476,   524,   554,   564,   585,   589,
     617,   626,  1453,  1454,  1455,  1457,  1339,  1340,  1336,  1337,
     715,  1334,   671,   641,   446,   671,   641,   598,  1581,   483,
     735,   736,  1007,  1317,   930,   910,  1007,  1315,   668,  1209,
    1237,  1237,   677,     5,     5,     5,   631,   914,     5,   671,
     535,   677,   676,   218,   220,   324,   327,   797,   800,   801,
    1081,   798,   799,  1007,   483,  1008,   700,   701,  1210,     5,
     479,   914,  1461,  1558,  1559,  1560,   628,   668,  1213,  1007,
    1007,   996,   997,   561,   955,   893,     8,     8,   961,    26,
      26,  1088,  1089,  1165,   373,  1225,   119,   907,  1273,   272,
    1275,  1281,  1587,     5,     5,   446,   446,   771,  1007,   446,
    1512,   767,   483,   483,   783,   779,   415,   777,   914,   395,
     780,   784,   648,  1083,  1150,  1146,   417,  1144,  1145,   912,
     677,  1171,    20,  1007,  1179,  1189,    14,   535,  1234,  1235,
    1504,  1566,  1186,  1587,  1030,  1031,   602,  1006,   598,  1064,
    1063,  1062,  1061,  1066,  1065,   998,  1067,   998,  1068,  1060,
    1059,  1057,  1056,  1082,   380,  1053,  1058,   955,    54,    55,
      56,    57,    58,    59,   151,   388,   401,   463,   469,   508,
     532,   542,   543,   548,   558,   580,   583,   584,   588,   645,
     656,   743,   744,  1079,  1080,     5,    26,  1512,   302,  1165,
     523,  1493,  1494,  1512,  1220,  1487,  1489,   153,   153,   647,
    1218,  1422,  1423,   483,  1400,   204,  1434,  1461,   228,   325,
    1525,   671,   677,   483,  1395,  1395,   598,   676,     5,  1490,
    1541,   397,   406,   430,   433,   449,   553,   606,   613,  1001,
    1368,  1373,   677,   676,   980,  1165,     5,   598,   974,   975,
     690,   973,   979,  1007,   979,   983,   984,   979,   380,   982,
    1117,   479,   446,   641,   945,   446,   641,   446,   446,   945,
     945,   421,   506,   522,   565,   604,   633,   642,  1475,  1501,
       5,  1474,     5,   446,     5,  1504,     5,   446,  1504,  1504,
    1504,  1504,  1007,   446,   483,  1431,     5,   668,  1007,  1467,
       9,   348,   483,   495,  1437,  1438,  1439,  1440,  1441,  1445,
    1449,  1451,  1504,   423,  1425,  1435,  1007,  1496,   670,  1452,
     387,  1475,    26,  1475,   479,   513,  1283,  1303,  1134,   513,
    1244,  1277,   663,  1007,  1406,  1408,  1461,  1465,  1466,  1410,
    1465,  1410,     5,   446,  1348,  1410,  1437,  1007,   446,  1351,
       5,   446,   483,   483,   483,  1474,  1474,   483,   483,   483,
     483,   483,   260,   261,   262,   453,  1412,  1414,     5,   446,
       5,   446,  1007,  1007,    25,  1007,  1007,    25,  1007,   914,
    1007,  1327,  1328,     5,  1329,  1330,   930,  1123,   671,  1329,
     628,  1512,  1512,   914,   914,   995,   561,   914,  1579,     5,
    1048,    20,  1465,  1512,   798,   806,   805,   807,  1007,  1011,
     808,  1011,   245,   801,   804,     5,  1051,   671,   914,     8,
    1570,   511,   671,     5,  1512,   628,  1007,  1183,   930,   605,
    1371,     5,   446,  1165,     5,    26,  1165,   381,    25,  1305,
     400,   400,   511,   671,   400,   483,   756,   760,   753,  1587,
    1587,   785,   781,   777,  1084,    25,  1006,  1151,  1165,  1587,
     914,   478,   511,   930,     5,  1037,  1032,  1033,    26,   740,
    1007,  1587,  1587,  1587,  1587,  1587,  1587,     5,  1054,     5,
    1055,  1587,  1587,  1587,  1587,  1087,  1587,  1006,    25,    14,
      14,     5,   446,    26,  1461,  1500,  1481,   647,   647,  1357,
    1486,  1487,  1423,  1401,  1465,   668,  1001,   483,  1361,  1007,
    1522,  1521,  1396,  1465,   515,  1397,  1398,  1463,  1461,  1394,
    1501,    99,   100,   101,   102,   103,   635,  1544,   914,   914,
     605,  1369,  1001,  1397,  1461,     5,  1165,   979,  1587,  1587,
       5,   986,   987,  1587,  1587,   985,  1110,   877,   945,    26,
     945,    24,    26,   945,   945,   483,  1433,  1474,   677,  1474,
    1474,   446,  1504,   446,   446,   446,   446,  1430,  1432,  1430,
    1467,  1440,  1499,  1437,  1504,  1499,     6,     7,     9,    10,
      12,    13,    14,    15,    16,    17,   306,   426,   427,   481,
     608,   674,   724,   725,  1448,  1450,  1426,  1503,  1504,   500,
    1424,  1436,   322,  1326,    26,  1377,  1378,  1379,  1465,  1493,
    1496,   446,   831,   127,   128,   130,   131,   132,   230,   238,
     272,   281,   310,   311,   355,   399,   453,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,  1280,  1284,   191,
     566,  1285,  1301,  1110,   214,   229,   230,   238,   272,   281,
     310,   355,   399,  1278,  1279,  1291,  1285,  1466,   511,  1464,
     446,     5,   671,     5,   446,   446,  1411,   446,   446,  1343,
      26,  1458,  1458,    26,   677,   483,   677,    26,  1459,    26,
      26,  1459,  1459,    25,  1468,   212,   312,   350,   414,   428,
     528,   544,  1405,  1415,  1416,  1417,  1418,  1340,  1336,   671,
     671,   590,   639,     5,   446,   736,     5,   446,   912,   446,
      20,   446,  1512,     5,   914,   618,   328,   745,   746,   914,
    1051,  1587,  1587,     5,   802,   511,   671,     5,   803,  1587,
     799,   598,    20,  1007,     5,  1007,  1200,  1569,    20,  1465,
    1559,     8,  1512,   444,   710,   912,  1372,   960,  1089,   719,
    1223,   907,     5,   767,  1165,   752,   734,  1007,  1165,   758,
     446,   767,   767,  1587,  1587,  1087,  1148,    25,  1152,  1165,
     623,   991,  1175,   535,   913,  1095,  1235,   116,   594,  1038,
    1024,  1025,   671,   998,  1587,   998,  1587,   740,    26,  1165,
      26,  1165,   744,   446,   483,  1513,  1501,  1487,  1487,  1479,
       5,   446,   523,  1498,  1362,  1465,   531,  1359,  1498,   677,
       5,   446,     5,   598,  1491,    18,    19,   118,   480,   483,
     496,   535,   536,   548,   589,   628,   640,   652,   653,   660,
     663,  1007,  1468,  1499,  1528,  1530,  1549,  1550,  1551,  1552,
    1553,  1554,  1566,  1549,  1549,  1549,  1465,  1546,  1548,  1545,
    1546,  1547,  1542,  1370,   677,  1165,  1007,  1587,  1587,  1587,
    1587,   675,   446,   641,   446,   446,    26,   446,   677,  1475,
     677,   677,     5,   446,   446,  1438,  1439,  1443,  1505,  1443,
     483,  1499,  1443,   483,  1499,  1443,    10,   303,   441,   443,
    1504,     5,  1437,     5,   590,   639,  1380,  1326,   677,   675,
    1281,  1281,  1281,    25,  1281,  1281,  1281,  1281,  1281,  1281,
      25,    25,  1281,  1284,  1165,  1191,  1192,   670,   499,  1245,
    1587,    25,    25,    26,    26,    26,    26,    26,    25,  1165,
    1279,  1245,    26,  1405,  1465,    20,  1007,  1465,  1348,   446,
     446,     5,   446,  1475,    26,  1475,     5,  1456,     5,   446,
     446,   446,  1456,  1407,  1461,   483,  1417,  1348,  1007,  1007,
    1328,   674,   728,  1322,  1323,  1324,  1330,    62,   139,   140,
     298,   674,  1318,  1319,  1320,   520,   892,  1318,     5,   429,
    1512,     5,   483,   446,   602,  1078,  1011,  1587,   737,    20,
    1007,  1011,  1587,   955,   914,   479,  1512,     8,   955,  1186,
    1587,    26,  1006,    25,  1306,  1183,   479,   767,   757,   761,
     446,  1587,  1006,   914,   989,   479,  1040,  1039,   493,  1026,
    1027,    20,  1007,  1514,  1515,   605,  1497,  1482,  1480,  1465,
    1500,   196,  1402,     5,   446,  1360,  1522,  1465,  1398,  1397,
    1497,  1552,  1552,  1551,   483,   483,   483,   483,   483,   483,
     483,  1007,   483,     5,   446,    18,    19,    20,    21,  1526,
     446,     5,   446,     5,    14,   204,   578,  1543,  1186,  1397,
     265,  1118,   873,   945,    24,    26,   945,   945,   446,  1475,
    1475,  1475,  1430,   494,  1442,  1442,  1446,  1447,  1468,  1566,
    1442,  1446,  1442,  1443,  1504,  1503,  1378,  1475,   843,   590,
     639,  1193,     5,  1191,   115,   190,   252,   254,   270,   278,
     282,   307,  1246,  1247,  1302,  1118,  1292,     5,   479,  1464,
      26,   446,    26,  1460,   446,    26,   446,   483,  1437,  1321,
    1586,    26,  1324,    26,    26,  1321,  1326,  1320,   998,   740,
     429,  1512,   914,   747,   620,  1198,    26,   740,   479,  1078,
     446,  1512,   294,   740,   446,   446,   483,   759,   400,   765,
     446,   754,  1147,  1587,   511,   914,  1587,  1006,     5,   446,
    1186,  1433,  1501,  1465,   483,  1433,   446,  1527,  1452,  1551,
    1555,  1452,  1452,  1452,  1452,   511,   671,  1555,  1550,  1551,
    1551,  1551,  1551,  1546,    14,  1547,  1550,  1001,  1437,   197,
     668,  1391,   446,   446,  1444,  1468,  1508,     5,   446,   446,
    1442,     7,  1192,  1248,  1249,  1165,  1251,  1165,  1250,  1252,
    1247,   293,   293,    26,   446,   677,   446,  1408,   446,   891,
    1512,   447,   256,   313,   338,   347,   385,   393,   484,   654,
     744,   748,   749,   483,   671,   740,  1222,  1307,   762,   446,
    1183,   765,   765,  1587,   990,  1175,   627,  1075,  1515,  1495,
    1433,   535,  1363,  1364,  1504,  1495,   446,  1551,     5,   446,
    1551,  1551,  1551,  1551,    26,  1007,   446,   483,  1007,   945,
     945,  1447,  1504,  1587,  1587,  1253,  1587,  1254,  1587,  1587,
     479,  1475,   446,   292,   403,   407,   894,   895,   896,  1081,
     993,   993,   993,   993,   993,   993,    25,     5,   446,   914,
      20,  1007,  1081,  1226,  1227,  1228,   765,   767,   765,   295,
     479,  1041,   740,     5,   446,   341,   342,  1483,   446,  1551,
     446,   446,   446,   446,     5,   479,   511,  1549,  1587,  1587,
     898,   897,   292,   896,   899,   749,     5,  1229,   336,  1228,
     763,  1587,  1364,    25,  1007,  1484,  1485,    26,    26,   446,
    1587,  1587,  1587,   914,  1587,   446,  1038,   671,   671,     5,
     479,     5,   479,   446,   764,  1007,  1007,  1485,    26,   217,
     400,   766,   671,   479,  1183,  1007
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
#line 1003 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1006 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1010 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1016 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1021 "fgl.yacc"
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
#line 1033 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1038 "fgl.yacc"
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
#line 1061 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1062 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1063 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1064 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1065 "fgl.yacc"
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
#line 1076 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1083 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1084 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1085 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1086 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1091 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1092 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1103 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1106 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1109 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1109 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1116 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1117 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1136 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1137 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1138 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1139 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1146 "fgl.yacc"
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
#line 1157 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1161 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1162 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1166 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1172 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1174 "fgl.yacc"
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
#line 1185 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1187 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1189 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1191 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1195 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1197 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1258 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1262 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1266 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1273 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1276 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1280 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1284 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1291 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1297 "fgl.yacc"
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
#line 1306 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1310 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1315 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1319 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1327 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1331 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1335 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1337 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1343 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1348 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1351 "fgl.yacc"
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
#line 1367 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1374 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1378 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1382 "fgl.yacc"
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
#line 1404 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1404 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1408 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1409 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1410 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1415 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1418 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1424 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1427 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1436 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1440 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1446 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1449 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1464 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1474 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1480 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1489 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1502 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1505 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1507 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1513 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1515 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1520 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1525 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1531 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1535 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1550 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1553 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1556 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1559 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1562 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1565 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1587 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1596 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1615 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1620 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1623 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1632 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1638 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1653 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1657 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1662 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1672 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1672 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1673 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1673 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1674 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1674 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1675 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1675 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1676 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1676 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1684 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1688 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1694 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1698 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1713 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1716 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1719 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1722 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1725 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1728 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1737 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1745 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1750 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1763 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1767 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1782 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1783 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1791 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1791 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1800 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1800 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1809 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1810 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1811 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1814 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1819 "fgl.yacc"
    { }
    break;

  case 194:
#line 1819 "fgl.yacc"
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
#line 1836 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1840 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1855 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1856 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1857 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1858 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1863 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1869 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1878 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1882 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1898 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1900 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1901 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1908 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1908 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1909 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1910 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1913 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1915 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1925 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1940 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1940 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1946 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1947 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1948 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1949 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1950 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1951 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1952 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1953 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1954 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1955 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1958 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1959 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1960 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1961 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1965 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1970 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1975 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1979 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1982 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1986 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1987 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1988 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1989 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1990 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1991 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1992 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1993 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1994 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1997 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1998 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1999 "fgl.yacc"
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
#line 2034 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2038 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2040 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2042 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2044 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2049 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2053 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2053 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2057 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2058 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2059 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2060 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2061 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2062 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2064 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2069 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2069 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2072 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2074 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2080 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2082 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2088 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2096 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2096 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2099 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2100 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2101 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2102 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2103 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2104 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2106 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2127 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2136 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2138 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2139 "fgl.yacc"
    {
						dim_push_type("varchar",yyvsp[-1].str,0);
				}
    break;

  case 317:
#line 2142 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 318:
#line 2146 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2147 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2148 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2149 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2154 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2161 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2166 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2168 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2170 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2171 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2172 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2173 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2174 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2175 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2176 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2179 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2181 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2187 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2195 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2203 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2207 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2215 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2216 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2217 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2218 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2237 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2249 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2253 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2256 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2259 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2260 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2261 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2262 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2263 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2269 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2276 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2281 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2286 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2291 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2295 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2304 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2306 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2311 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2323 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2327 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2330 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2334 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2337 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2341 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
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

		print_alloc_arr(buff,s);
	}
    break;

  case 379:
#line 2366 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2372 "fgl.yacc"
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
#line 2396 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2399 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2414 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 384:
#line 2417 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2431 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 386:
#line 2433 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 387:
#line 2435 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 388:
#line 2437 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 389:
#line 2439 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 390:
#line 2441 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 391:
#line 2442 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 392:
#line 2449 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 393:
#line 2451 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 394:
#line 2455 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 395:
#line 2457 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 396:
#line 2459 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 397:
#line 2461 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 398:
#line 2463 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 399:
#line 2465 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 400:
#line 2467 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 401:
#line 2473 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 405:
#line 2492 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 408:
#line 2498 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 409:
#line 2502 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 410:
#line 2507 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 414:
#line 2517 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 415:
#line 2518 "fgl.yacc"
    {inc_counter();}
    break;

  case 421:
#line 2524 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 422:
#line 2531 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 423:
#line 2531 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 425:
#line 2536 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 426:
#line 2540 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 427:
#line 2546 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2554 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2560 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2569 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 431:
#line 2571 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 432:
#line 2578 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 433:
#line 2599 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 434:
#line 2604 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 435:
#line 2609 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 436:
#line 2613 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 437:
#line 2615 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 438:
#line 2618 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 439:
#line 2636 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 440:
#line 2642 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 441:
#line 2648 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2658 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 445:
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

  case 446:
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

  case 447:
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

  case 448:
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

  case 449:
#line 2763 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 450:
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

  case 451:
#line 2779 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 452:
#line 2783 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 453:
#line 2789 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 454:
#line 2792 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 455:
#line 2800 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 456:
#line 2804 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 457:
#line 2807 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 458:
#line 2813 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 459:
#line 2823 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 460:
#line 2828 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 461:
#line 2835 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 462:
#line 2838 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 463:
#line 2841 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 464:
#line 2846 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 465:
#line 2853 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 466:
#line 2858 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 467:
#line 2863 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 468:
#line 2868 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 469:
#line 2879 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 470:
#line 2887 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 471:
#line 2895 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 472:
#line 2900 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 473:
#line 2904 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 474:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 475:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 476:
#line 2917 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 477:
#line 2923 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 478:
#line 2926 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 479:
#line 2930 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 480:
#line 2934 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 481:
#line 2938 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 482:
#line 2942 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 483:
#line 2946 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 484:
#line 2953 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 485:
#line 2963 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 486:
#line 2968 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 487:
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

  case 488:
#line 2984 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 489:
#line 2989 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 490:
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

  case 491:
#line 3006 "fgl.yacc"
    {chk4var=1;}
    break;

  case 492:
#line 3006 "fgl.yacc"
    {chk4var=0;}
    break;

  case 493:
#line 3006 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 494:
#line 3009 "fgl.yacc"
    {chk4var=1;}
    break;

  case 495:
#line 3009 "fgl.yacc"
    {chk4var=0;}
    break;

  case 496:
#line 3009 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 497:
#line 3013 "fgl.yacc"
    {chk4var=1;}
    break;

  case 498:
#line 3013 "fgl.yacc"
    {chk4var=0;}
    break;

  case 499:
#line 3013 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 500:
#line 3017 "fgl.yacc"
    {chk4var=1;}
    break;

  case 501:
#line 3017 "fgl.yacc"
    {chk4var=0;}
    break;

  case 502:
#line 3017 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 503:
#line 3021 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 504:
#line 3027 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 505:
#line 3033 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 506:
#line 3039 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 507:
#line 3047 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 508:
#line 3053 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3061 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3067 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3076 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3082 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3089 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3096 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 515:
#line 3105 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 516:
#line 3111 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 517:
#line 3117 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 518:
#line 3124 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 519:
#line 3130 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 520:
#line 3136 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3142 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3150 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3156 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3162 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3171 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 526:
#line 3177 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 527:
#line 3183 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 528:
#line 3193 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 529:
#line 3194 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 532:
#line 3202 "fgl.yacc"
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

  case 533:
#line 3213 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 534:
#line 3214 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 535:
#line 3220 "fgl.yacc"
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

  case 536:
#line 3231 "fgl.yacc"
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

  case 537:
#line 3241 "fgl.yacc"
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

  case 540:
#line 3254 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 541:
#line 3259 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 542:
#line 3266 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 543:
#line 3270 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 544:
#line 3273 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 545:
#line 3276 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 546:
#line 3282 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 547:
#line 3285 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 548:
#line 3288 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 549:
#line 3305 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 550:
#line 3308 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 551:
#line 3314 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 552:
#line 3315 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 553:
#line 3316 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 555:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 556:
#line 3322 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 557:
#line 3323 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 558:
#line 3324 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 559:
#line 3326 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 560:
#line 3327 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 561:
#line 3328 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 562:
#line 3330 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 563:
#line 3331 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 565:
#line 3337 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 566:
#line 3341 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 567:
#line 3345 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 568:
#line 3350 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 569:
#line 3354 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 570:
#line 3369 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 571:
#line 3373 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 572:
#line 3379 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 573:
#line 3383 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 574:
#line 3392 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 575:
#line 3393 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 576:
#line 3405 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 577:
#line 3411 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 578:
#line 3419 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 585:
#line 3436 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 586:
#line 3438 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 587:
#line 3441 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 588:
#line 3443 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 593:
#line 3457 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 594:
#line 3459 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 595:
#line 3462 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 596:
#line 3464 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 609:
#line 3495 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 610:
#line 3497 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 611:
#line 3500 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 612:
#line 3502 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 613:
#line 3505 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 614:
#line 3507 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 615:
#line 3510 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 616:
#line 3512 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 617:
#line 3515 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 618:
#line 3517 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 619:
#line 3531 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 620:
#line 3535 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 621:
#line 3536 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 622:
#line 3543 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 624:
#line 3561 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 625:
#line 3577 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 626:
#line 3578 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 627:
#line 3579 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 628:
#line 3580 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 629:
#line 3581 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 630:
#line 3582 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 631:
#line 3583 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 635:
#line 3591 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 637:
#line 3597 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 638:
#line 3600 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 639:
#line 3605 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 640:
#line 3610 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 641:
#line 3613 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 642:
#line 3618 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 643:
#line 3623 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 644:
#line 3628 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 645:
#line 3635 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 646:
#line 3636 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 647:
#line 3643 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 648:
#line 3650 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 649:
#line 3652 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 650:
#line 3658 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 651:
#line 3663 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 652:
#line 3668 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 653:
#line 3673 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 654:
#line 3673 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 655:
#line 3676 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 656:
#line 3682 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 657:
#line 3687 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 658:
#line 3691 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 661:
#line 3699 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 662:
#line 3702 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 663:
#line 3705 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 664:
#line 3710 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 665:
#line 3715 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 666:
#line 3720 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 667:
#line 3727 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 669:
#line 3736 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 670:
#line 3798 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 672:
#line 3807 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 673:
#line 3816 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 675:
#line 3823 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 676:
#line 3826 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 677:
#line 3832 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 678:
#line 3838 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 679:
#line 3842 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 680:
#line 3846 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 681:
#line 3852 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 682:
#line 3856 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 683:
#line 3860 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 684:
#line 3865 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 685:
#line 3870 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 704:
#line 3911 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 705:
#line 3918 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 706:
#line 3920 "fgl.yacc"
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

  case 708:
#line 3939 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 710:
#line 3942 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 711:
#line 3944 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 712:
#line 3947 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 713:
#line 3951 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 714:
#line 3954 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 715:
#line 3961 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 716:
#line 3966 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 717:
#line 3977 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 718:
#line 3978 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 719:
#line 3981 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 721:
#line 3987 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 722:
#line 3991 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 723:
#line 3992 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 724:
#line 3996 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 728:
#line 4011 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 729:
#line 4013 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 732:
#line 4022 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 733:
#line 4025 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 734:
#line 4029 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 735:
#line 4032 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 736:
#line 4035 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 737:
#line 4038 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 738:
#line 4041 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 739:
#line 4045 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 740:
#line 4048 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 741:
#line 4051 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 742:
#line 4054 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 743:
#line 4057 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 744:
#line 4060 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 745:
#line 4063 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 746:
#line 4066 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 747:
#line 4069 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 748:
#line 4070 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 749:
#line 4070 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 750:
#line 4071 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 751:
#line 4071 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 752:
#line 4072 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 753:
#line 4072 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 754:
#line 4073 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 755:
#line 4076 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 756:
#line 4077 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 757:
#line 4080 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 758:
#line 4088 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 759:
#line 4092 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 760:
#line 4098 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 761:
#line 4102 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 762:
#line 4107 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 763:
#line 4112 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 764:
#line 4117 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 765:
#line 4118 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 766:
#line 4119 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 767:
#line 4123 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 768:
#line 4127 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 769:
#line 4136 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 770:
#line 4141 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 771:
#line 4145 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 772:
#line 4152 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 773:
#line 4161 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 774:
#line 4167 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 775:
#line 4168 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 776:
#line 4169 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 777:
#line 4170 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 778:
#line 4171 "fgl.yacc"
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

  case 779:
#line 4181 "fgl.yacc"
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

  case 780:
#line 4195 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 782:
#line 4198 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 783:
#line 4205 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 784:
#line 4206 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 785:
#line 4207 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 786:
#line 4208 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 787:
#line 4209 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 788:
#line 4210 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 789:
#line 4211 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 790:
#line 4212 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 791:
#line 4213 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 792:
#line 4218 "fgl.yacc"
    {iskey=1;}
    break;

  case 793:
#line 4218 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 794:
#line 4220 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 795:
#line 4223 "fgl.yacc"
    {iskey=1;}
    break;

  case 796:
#line 4223 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 797:
#line 4225 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 798:
#line 4229 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 799:
#line 4232 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 800:
#line 4233 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 802:
#line 4236 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 808:
#line 4248 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 809:
#line 4249 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 810:
#line 4250 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 811:
#line 4251 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 812:
#line 4252 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 813:
#line 4253 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 814:
#line 4254 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 815:
#line 4255 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 816:
#line 4256 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 817:
#line 4257 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 818:
#line 4258 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 819:
#line 4259 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 820:
#line 4260 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 821:
#line 4261 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 822:
#line 4265 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 823:
#line 4283 "fgl.yacc"
    {chk4var=1;}
    break;

  case 824:
#line 4283 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 825:
#line 4286 "fgl.yacc"
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

  case 826:
#line 4310 "fgl.yacc"
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

  case 828:
#line 4328 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 829:
#line 4334 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 830:
#line 4340 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 831:
#line 4346 "fgl.yacc"
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

  case 832:
#line 4358 "fgl.yacc"
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

  case 833:
#line 4383 "fgl.yacc"
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

  case 836:
#line 4399 "fgl.yacc"
    {
	}
    break;

  case 846:
#line 4425 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 850:
#line 4433 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 865:
#line 4459 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 866:
#line 4460 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 867:
#line 4468 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 868:
#line 4473 "fgl.yacc"
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

  case 869:
#line 4489 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 870:
#line 4495 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 872:
#line 4510 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 873:
#line 4523 "fgl.yacc"
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

  case 874:
#line 4533 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 875:
#line 4540 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 876:
#line 4547 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 877:
#line 4553 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 878:
#line 4553 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 879:
#line 4558 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 880:
#line 4564 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 881:
#line 4572 "fgl.yacc"
    {
}
    break;

  case 885:
#line 4584 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 887:
#line 4592 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 888:
#line 4598 "fgl.yacc"
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

  case 891:
#line 4614 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 892:
#line 4618 "fgl.yacc"
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

  case 893:
#line 4631 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 895:
#line 4644 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 896:
#line 4650 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 897:
#line 4654 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 900:
#line 4666 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 901:
#line 4669 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 902:
#line 4673 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 903:
#line 4676 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 904:
#line 4688 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 905:
#line 4696 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 906:
#line 4702 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 907:
#line 4713 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 908:
#line 4717 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 909:
#line 4724 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 910:
#line 4731 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 911:
#line 4737 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 912:
#line 4742 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 915:
#line 4749 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 916:
#line 4750 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 917:
#line 4752 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 918:
#line 4753 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 919:
#line 4756 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 920:
#line 4757 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 921:
#line 4758 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 922:
#line 4760 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 923:
#line 4765 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 924:
#line 4770 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 925:
#line 4777 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 929:
#line 4784 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 930:
#line 4786 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 931:
#line 4788 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 933:
#line 4798 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 934:
#line 4801 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 935:
#line 4804 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 942:
#line 4820 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 943:
#line 4825 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 944:
#line 4825 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 945:
#line 4828 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 946:
#line 4856 "fgl.yacc"
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

  case 948:
#line 4913 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 950:
#line 4920 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 951:
#line 4924 "fgl.yacc"
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

  case 952:
#line 4967 "fgl.yacc"
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

  case 956:
#line 5015 "fgl.yacc"
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

  case 957:
#line 5029 "fgl.yacc"
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

  case 962:
#line 5053 "fgl.yacc"
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

  case 963:
#line 5117 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 964:
#line 5122 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 965:
#line 5130 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 966:
#line 5135 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 967:
#line 5143 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 968:
#line 5149 "fgl.yacc"
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

  case 969:
#line 5181 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 970:
#line 5184 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 971:
#line 5186 "fgl.yacc"
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

  case 972:
#line 5227 "fgl.yacc"
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

  case 977:
#line 5280 "fgl.yacc"
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

  case 978:
#line 5332 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 980:
#line 5341 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 981:
#line 5346 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 982:
#line 5357 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 983:
#line 5364 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 985:
#line 5372 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 986:
#line 5375 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 987:
#line 5376 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 989:
#line 5378 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 990:
#line 5379 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 991:
#line 5382 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 992:
#line 5385 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 993:
#line 5391 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 994:
#line 5394 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 995:
#line 5398 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 996:
#line 5403 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 997:
#line 5411 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 998:
#line 5416 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 999:
#line 5423 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1000:
#line 5425 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1005:
#line 5453 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1006:
#line 5460 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1007:
#line 5467 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1008:
#line 5470 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1009:
#line 5484 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1014:
#line 5501 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1015:
#line 5506 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1016:
#line 5512 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1018:
#line 5519 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1019:
#line 5524 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1020:
#line 5527 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1021:
#line 5528 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1022:
#line 5531 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1023:
#line 5532 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1024:
#line 5535 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1025:
#line 5536 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1026:
#line 5541 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1027:
#line 5548 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1028:
#line 5551 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1029:
#line 5557 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1030:
#line 5559 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1031:
#line 5561 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1032:
#line 5563 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1033:
#line 5566 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1034:
#line 5566 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1035:
#line 5567 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1036:
#line 5572 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1037:
#line 5580 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1038:
#line 5581 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1039:
#line 5586 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1040:
#line 5588 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1041:
#line 5590 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1045:
#line 5608 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1046:
#line 5609 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1047:
#line 5610 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1048:
#line 5611 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1049:
#line 5612 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1050:
#line 5613 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1051:
#line 5614 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1052:
#line 5615 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1053:
#line 5616 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1054:
#line 5617 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1055:
#line 5618 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1056:
#line 5619 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1057:
#line 5620 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1058:
#line 5621 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1059:
#line 5622 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1060:
#line 5623 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1061:
#line 5624 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1062:
#line 5625 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1063:
#line 5626 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1064:
#line 5627 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1065:
#line 5628 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1066:
#line 5629 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1067:
#line 5630 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1068:
#line 5631 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1069:
#line 5632 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1070:
#line 5633 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1071:
#line 5648 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1074:
#line 5657 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1075:
#line 5661 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1076:
#line 5665 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1077:
#line 5669 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1078:
#line 5673 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1080:
#line 5693 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1081:
#line 5698 "fgl.yacc"
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

  case 1082:
#line 5711 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1083:
#line 5712 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1084:
#line 5716 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1085:
#line 5721 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1086:
#line 5722 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1087:
#line 5726 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1091:
#line 5732 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1092:
#line 5735 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1094:
#line 5750 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1095:
#line 5754 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1096:
#line 5760 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1097:
#line 5761 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1098:
#line 5766 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1099:
#line 5767 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1100:
#line 5770 "fgl.yacc"
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

  case 1102:
#line 5797 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1103:
#line 5801 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1104:
#line 5805 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1105:
#line 5809 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1106:
#line 5816 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1107:
#line 5817 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1113:
#line 5829 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1114:
#line 5835 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1115:
#line 5843 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1116:
#line 5849 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1117:
#line 5851 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1121:
#line 5861 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1122:
#line 5861 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1123:
#line 5866 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1124:
#line 5870 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1125:
#line 5875 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1126:
#line 5875 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1127:
#line 5879 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1128:
#line 5879 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1129:
#line 5880 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1130:
#line 5880 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1131:
#line 5881 "fgl.yacc"
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

  case 1132:
#line 5894 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1133:
#line 5895 "fgl.yacc"
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

  case 1134:
#line 5911 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1141:
#line 5923 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1142:
#line 5923 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1143:
#line 5929 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1144:
#line 5929 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1145:
#line 5932 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1146:
#line 5932 "fgl.yacc"
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

  case 1147:
#line 5948 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1148:
#line 5949 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1149:
#line 5950 "fgl.yacc"
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

  case 1150:
#line 5959 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1151:
#line 5971 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1157:
#line 5982 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1158:
#line 5987 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1159:
#line 5987 "fgl.yacc"
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

  case 1161:
#line 6011 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1162:
#line 6017 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1163:
#line 6022 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1164:
#line 6028 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1165:
#line 6029 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1166:
#line 6030 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1167:
#line 6034 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1168:
#line 6035 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1169:
#line 6036 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1170:
#line 6037 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1171:
#line 6041 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1172:
#line 6051 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1173:
#line 6053 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1174:
#line 6058 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1175:
#line 6061 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1176:
#line 6066 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1177:
#line 6073 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1178:
#line 6080 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1179:
#line 6087 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1180:
#line 6096 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1181:
#line 6103 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1182:
#line 6110 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1183:
#line 6117 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1184:
#line 6124 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1189:
#line 6137 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1190:
#line 6138 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1191:
#line 6139 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1192:
#line 6140 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1193:
#line 6141 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1194:
#line 6142 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1195:
#line 6143 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1196:
#line 6144 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1197:
#line 6145 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1198:
#line 6146 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1201:
#line 6152 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1202:
#line 6153 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1203:
#line 6154 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1204:
#line 6155 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1209:
#line 6164 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1210:
#line 6165 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1211:
#line 6166 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1212:
#line 6167 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1213:
#line 6168 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1214:
#line 6169 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1215:
#line 6170 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1216:
#line 6171 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1217:
#line 6173 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1218:
#line 6174 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1219:
#line 6175 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1220:
#line 6176 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1221:
#line 6178 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1222:
#line 6179 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1223:
#line 6180 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1224:
#line 6181 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1228:
#line 6186 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1229:
#line 6187 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1233:
#line 6194 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1234:
#line 6203 "fgl.yacc"
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

  case 1235:
#line 6212 "fgl.yacc"
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

  case 1236:
#line 6225 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1237:
#line 6234 "fgl.yacc"
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

  case 1238:
#line 6245 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1239:
#line 6249 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1240:
#line 6253 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1241:
#line 6259 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1242:
#line 6264 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1243:
#line 6272 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1244:
#line 6275 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1245:
#line 6284 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1246:
#line 6295 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1248:
#line 6302 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1249:
#line 6310 "fgl.yacc"
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

  case 1250:
#line 6320 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1251:
#line 6323 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1252:
#line 6327 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1253:
#line 6335 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1254:
#line 6338 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1255:
#line 6344 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1256:
#line 6348 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1257:
#line 6352 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1258:
#line 6356 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1259:
#line 6360 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1260:
#line 6366 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1261:
#line 6367 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1262:
#line 6368 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1263:
#line 6369 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1264:
#line 6374 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1265:
#line 6376 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1266:
#line 6379 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1267:
#line 6383 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1268:
#line 6386 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1269:
#line 6393 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1270:
#line 6398 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1271:
#line 6405 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1272:
#line 6406 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1273:
#line 6407 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1274:
#line 6412 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1275:
#line 6413 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1276:
#line 6419 "fgl.yacc"
    {insql=1;}
    break;

  case 1277:
#line 6419 "fgl.yacc"
    {insql=0;}
    break;

  case 1278:
#line 6419 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1279:
#line 6424 "fgl.yacc"
    {insql=1;}
    break;

  case 1280:
#line 6424 "fgl.yacc"
    {insql=0;}
    break;

  case 1281:
#line 6424 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1282:
#line 6432 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1283:
#line 6433 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1285:
#line 6438 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1286:
#line 6443 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1287:
#line 6444 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1288:
#line 6445 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1289:
#line 6446 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1290:
#line 6447 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1292:
#line 6452 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1293:
#line 6452 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1295:
#line 6456 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1296:
#line 6460 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1297:
#line 6461 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1298:
#line 6464 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 6465 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1300:
#line 6468 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1301:
#line 6471 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1302:
#line 6474 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1303:
#line 6480 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1304:
#line 6482 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1306:
#line 6495 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1307:
#line 6499 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1308:
#line 6500 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1310:
#line 6505 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1311:
#line 6508 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1312:
#line 6514 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1313:
#line 6517 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1314:
#line 6525 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1316:
#line 6532 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1317:
#line 6536 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1318:
#line 6540 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1319:
#line 6546 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1320:
#line 6549 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1321:
#line 6558 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1322:
#line 6561 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1323:
#line 6564 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1324:
#line 6567 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1325:
#line 6570 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1326:
#line 6573 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1327:
#line 6576 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1328:
#line 6583 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1329:
#line 6586 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1330:
#line 6593 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1331:
#line 6596 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1332:
#line 6602 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1333:
#line 6605 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1334:
#line 6612 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1335:
#line 6615 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1337:
#line 6623 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1339:
#line 6632 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1340:
#line 6635 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1341:
#line 6641 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1342:
#line 6644 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1343:
#line 6650 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1344:
#line 6657 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1345:
#line 6658 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1346:
#line 6662 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1347:
#line 6672 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1348:
#line 6675 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1349:
#line 6681 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1350:
#line 6683 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1351:
#line 6688 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1352:
#line 6689 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1353:
#line 6694 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1354:
#line 6695 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1355:
#line 6701 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1356:
#line 6702 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1360:
#line 6729 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6735 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1367:
#line 6738 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1368:
#line 6741 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1369:
#line 6747 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1371:
#line 6753 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1373:
#line 6764 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1374:
#line 6778 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1375:
#line 6787 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1376:
#line 6787 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1377:
#line 6792 "fgl.yacc"
    {insql=1;}
    break;

  case 1378:
#line 6792 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1379:
#line 6797 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1380:
#line 6800 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1381:
#line 6802 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6809 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6813 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1385:
#line 6817 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1386:
#line 6824 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1387:
#line 6827 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1388:
#line 6834 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1389:
#line 6838 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1390:
#line 6844 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1391:
#line 6849 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1392:
#line 6853 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1393:
#line 6859 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1394:
#line 6862 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1395:
#line 6868 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1396:
#line 6875 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1397:
#line 6879 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1398:
#line 6884 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1399:
#line 6894 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1400:
#line 6897 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1401:
#line 6899 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1402:
#line 6901 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1403:
#line 6903 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1404:
#line 6905 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1405:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1406:
#line 6909 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1407:
#line 6915 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1408:
#line 6925 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1409:
#line 6932 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6938 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1412:
#line 6941 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 6948 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1418:
#line 6953 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1419:
#line 6958 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1420:
#line 6965 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1421:
#line 6966 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1422:
#line 6973 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1423:
#line 6984 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1424:
#line 6985 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6986 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1426:
#line 6989 "fgl.yacc"
    {insql=1;}
    break;

  case 1427:
#line 6989 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1428:
#line 6994 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1429:
#line 6999 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1431:
#line 7005 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1433:
#line 7009 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1434:
#line 7014 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1435:
#line 7019 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1436:
#line 7023 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1438:
#line 7029 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1439:
#line 7033 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1440:
#line 7040 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7041 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7042 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7043 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1447:
#line 7053 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1448:
#line 7054 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1449:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 7059 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1451:
#line 7060 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1454:
#line 7067 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 7070 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1458:
#line 7073 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1461:
#line 7078 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1462:
#line 7080 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 7086 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 7092 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7102 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1470:
#line 7107 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1471:
#line 7109 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7115 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1474:
#line 7118 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1476:
#line 7124 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1477:
#line 7132 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 7137 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 7147 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7153 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7158 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1485:
#line 7161 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1486:
#line 7166 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 7172 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7177 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1490:
#line 7180 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1491:
#line 7183 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1492:
#line 7190 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7191 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1494:
#line 7192 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1495:
#line 7194 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1496:
#line 7207 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1497:
#line 7212 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1499:
#line 7216 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1500:
#line 7218 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1501:
#line 7225 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1502:
#line 7228 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1503:
#line 7234 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1504:
#line 7242 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1505:
#line 7246 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1506:
#line 7250 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1507:
#line 7254 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1508:
#line 7259 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1509:
#line 7262 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1510:
#line 7265 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1511:
#line 7273 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1512:
#line 7280 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1515:
#line 7289 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1516:
#line 7295 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1517:
#line 7298 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1518:
#line 7309 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1519:
#line 7316 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1520:
#line 7322 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1521:
#line 7325 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1522:
#line 7332 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1523:
#line 7339 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1525:
#line 7346 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1526:
#line 7352 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1527:
#line 7353 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1528:
#line 7354 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1530:
#line 7358 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1531:
#line 7365 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1533:
#line 7372 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1534:
#line 7379 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1535:
#line 7384 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1536:
#line 7385 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1537:
#line 7388 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1538:
#line 7391 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1539:
#line 7396 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1540:
#line 7397 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1541:
#line 7402 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1542:
#line 7405 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1543:
#line 7411 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1544:
#line 7414 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1545:
#line 7420 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1546:
#line 7423 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1547:
#line 7429 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1548:
#line 7432 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1549:
#line 7439 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1550:
#line 7440 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1551:
#line 7469 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1552:
#line 7471 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1553:
#line 7475 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1555:
#line 7488 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1556:
#line 7491 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1557:
#line 7494 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1558:
#line 7497 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1560:
#line 7505 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1561:
#line 7508 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1563:
#line 7514 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1565:
#line 7520 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1566:
#line 7523 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1567:
#line 7526 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1568:
#line 7529 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1569:
#line 7532 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1570:
#line 7535 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1571:
#line 7538 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1572:
#line 7541 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1573:
#line 7546 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1575:
#line 7553 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1581:
#line 7561 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1582:
#line 7562 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1583:
#line 7567 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1584:
#line 7570 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1585:
#line 7574 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1586:
#line 7580 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1587:
#line 7581 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1588:
#line 7582 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1589:
#line 7583 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1594:
#line 7603 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1596:
#line 7607 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1597:
#line 7608 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1599:
#line 7611 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1600:
#line 7612 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1601:
#line 7621 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1608:
#line 7635 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1609:
#line 7637 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1610:
#line 7639 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1612:
#line 7642 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1614:
#line 7645 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1618:
#line 7650 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1619:
#line 7652 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1620:
#line 7655 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1621:
#line 7656 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1622:
#line 7663 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1626:
#line 7668 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1630:
#line 7684 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1631:
#line 7691 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1632:
#line 7695 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1633:
#line 7696 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1634:
#line 7697 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1635:
#line 7705 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1636:
#line 7706 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1637:
#line 7707 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1638:
#line 7718 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1639:
#line 7725 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1640:
#line 7730 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1641:
#line 7731 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1642:
#line 7732 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1643:
#line 7740 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1644:
#line 7741 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1645:
#line 7742 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1647:
#line 7768 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1648:
#line 7769 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1649:
#line 7770 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1650:
#line 7774 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1651:
#line 7777 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1652:
#line 7783 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1653:
#line 7788 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1654:
#line 7793 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1656:
#line 7804 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1660:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1661:
#line 7825 "fgl.yacc"
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

  case 1662:
#line 7838 "fgl.yacc"
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

  case 1663:
#line 7853 "fgl.yacc"
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

  case 1664:
#line 7865 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1665:
#line 7867 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1666:
#line 7870 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1667:
#line 7870 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1668:
#line 7870 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1669:
#line 7870 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1670:
#line 7870 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1671:
#line 7870 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1672:
#line 7871 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1673:
#line 7874 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1688:
#line 7892 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1689:
#line 7895 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1690:
#line 7896 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1691:
#line 7897 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1692:
#line 7901 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1693:
#line 7909 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1694:
#line 7909 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1695:
#line 7915 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1696:
#line 7915 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1697:
#line 7922 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1698:
#line 7922 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1699:
#line 7928 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1700:
#line 7928 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1701:
#line 7936 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1702:
#line 7937 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1703:
#line 7938 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1704:
#line 7941 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1705:
#line 7941 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1707:
#line 7945 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1708:
#line 7946 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1709:
#line 7957 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1710:
#line 7960 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1711:
#line 7966 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1712:
#line 7971 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1713:
#line 7979 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1714:
#line 7991 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1715:
#line 7992 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1716:
#line 7995 "fgl.yacc"
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

  case 1717:
#line 8010 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1718:
#line 8021 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1719:
#line 8024 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1720:
#line 8032 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1721:
#line 8041 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1722:
#line 8044 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1723:
#line 8048 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1724:
#line 8051 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1725:
#line 8052 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1727:
#line 8065 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1728:
#line 8066 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1729:
#line 8075 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1730:
#line 8084 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1731:
#line 8089 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1732:
#line 8090 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1733:
#line 8091 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1734:
#line 8092 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1735:
#line 8099 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1736:
#line 8102 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1737:
#line 8108 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1738:
#line 8111 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1739:
#line 8118 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1740:
#line 8130 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1741:
#line 8139 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1742:
#line 8142 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1743:
#line 8145 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1744:
#line 8151 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1745:
#line 8159 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1746:
#line 8162 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1747:
#line 8163 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1748:
#line 8164 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1749:
#line 8165 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1750:
#line 8166 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1751:
#line 8169 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1752:
#line 8176 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1753:
#line 8178 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1754:
#line 8180 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1755:
#line 8182 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1756:
#line 8184 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1757:
#line 8185 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1758:
#line 8186 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1759:
#line 8187 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1760:
#line 8188 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1761:
#line 8189 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1762:
#line 8190 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1763:
#line 8192 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1764:
#line 8194 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1765:
#line 8196 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1766:
#line 8198 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1767:
#line 8200 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1768:
#line 8202 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1769:
#line 8204 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1770:
#line 8205 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1771:
#line 8207 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1772:
#line 8208 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1773:
#line 8209 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1774:
#line 8215 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1775:
#line 8216 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1777:
#line 8226 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1778:
#line 8234 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1779:
#line 8238 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1780:
#line 8245 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1781:
#line 8245 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1783:
#line 8249 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1784:
#line 8254 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1785:
#line 8254 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1787:
#line 8258 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1788:
#line 8262 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1791:
#line 8271 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1792:
#line 8271 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1797:
#line 8290 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1798:
#line 8291 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1801:
#line 8299 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1802:
#line 8305 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1805:
#line 8324 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1806:
#line 8325 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1807:
#line 8326 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1808:
#line 8327 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1809:
#line 8328 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1810:
#line 8329 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1811:
#line 8333 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1812:
#line 8334 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1813:
#line 8335 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1815:
#line 8340 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1816:
#line 8341 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1817:
#line 8345 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1818:
#line 8361 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1819:
#line 8362 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1820:
#line 8363 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1821:
#line 8367 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1822:
#line 8381 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1823:
#line 8385 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1825:
#line 8394 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1827:
#line 8399 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1828:
#line 8400 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1829:
#line 8724 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1830:
#line 8724 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1831:
#line 8731 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1832:
#line 8731 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1833:
#line 8819 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1834:
#line 8823 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1835:
#line 8825 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1836:
#line 8832 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1837:
#line 8836 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1838:
#line 8842 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1839:
#line 8850 "fgl.yacc"
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

  case 1840:
#line 8860 "fgl.yacc"
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

  case 1841:
#line 8870 "fgl.yacc"
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

  case 1842:
#line 8882 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1843:
#line 8885 "fgl.yacc"
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

  case 1844:
#line 8904 "fgl.yacc"
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

  case 1845:
#line 8930 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1846:
#line 8933 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1848:
#line 8942 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1849:
#line 8947 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1850:
#line 8950 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1851:
#line 8958 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1852:
#line 8966 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1853:
#line 8979 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1854:
#line 8982 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1855:
#line 8990 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1856:
#line 8993 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1857:
#line 8996 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1858:
#line 9004 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1859:
#line 9008 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1860:
#line 9009 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1861:
#line 9010 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1862:
#line 9011 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1863:
#line 9012 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1864:
#line 9013 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1865:
#line 9014 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1866:
#line 9015 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1867:
#line 9019 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1868:
#line 9020 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1869:
#line 9021 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1870:
#line 9022 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1871:
#line 9023 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1872:
#line 9029 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1873:
#line 9030 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1874:
#line 9031 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1875:
#line 9032 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1876:
#line 9033 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1877:
#line 9034 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1878:
#line 9035 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1879:
#line 9036 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1880:
#line 9037 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1881:
#line 9038 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1882:
#line 9039 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1883:
#line 9040 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1884:
#line 9041 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1885:
#line 9042 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1886:
#line 9043 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1887:
#line 9044 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1888:
#line 9049 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1889:
#line 9055 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1890:
#line 9056 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1891:
#line 9064 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1892:
#line 9066 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1894:
#line 9072 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1895:
#line 9076 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1896:
#line 9080 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1897:
#line 9096 "fgl.yacc"
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

  case 1898:
#line 9110 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1899:
#line 9116 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1900:
#line 9118 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1904:
#line 9132 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1905:
#line 9135 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1906:
#line 9142 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1907:
#line 9145 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1908:
#line 9175 "fgl.yacc"
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

  case 1909:
#line 9200 "fgl.yacc"
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

  case 1910:
#line 9255 "fgl.yacc"
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

  case 1911:
#line 9290 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1912:
#line 9299 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1913:
#line 9310 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1914:
#line 9313 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1915:
#line 9319 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1916:
#line 9332 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1917:
#line 9346 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1918:
#line 9349 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1919:
#line 9353 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1920:
#line 9368 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1921:
#line 9368 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1922:
#line 9374 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1923:
#line 9375 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1924:
#line 9378 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1925:
#line 9379 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1926:
#line 9380 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1927:
#line 9381 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1928:
#line 9382 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1929:
#line 9383 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1930:
#line 9384 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1931:
#line 9395 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1932:
#line 9399 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1933:
#line 9403 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1934:
#line 9407 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1935:
#line 9412 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1936:
#line 9416 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1937:
#line 9421 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1939:
#line 9429 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1941:
#line 9435 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1942:
#line 9441 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1943:
#line 9445 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1948:
#line 9463 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1949:
#line 9470 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1950:
#line 9480 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1951:
#line 9480 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18768 "y.tab.c"

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


#line 1003 "fgl.yacc"

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



