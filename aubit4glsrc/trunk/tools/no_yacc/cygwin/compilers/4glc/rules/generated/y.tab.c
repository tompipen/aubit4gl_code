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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11104

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  729
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  863
/* YYNRULES -- Number of rules. */
#define YYNRULES  2352
/* YYNRULES -- Number of states. */
#define YYNSTATES  3778

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
    2609,  2611,  2613,  2615,  2617,  2619,  2620,  2622,  2624,  2627,
    2630,  2632,  2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,
    2650,  2652,  2653,  2655,  2657,  2659,  2661,  2662,  2663,  2664,
    2665,  2679,  2681,  2682,  2683,  2690,  2693,  2695,  2698,  2701,
    2704,  2706,  2708,  2711,  2713,  2714,  2718,  2721,  2723,  2725,
    2727,  2728,  2729,  2730,  2745,  2746,  2747,  2755,  2757,  2760,
    2761,  2765,  2766,  2771,  2772,  2778,  2780,  2781,  2785,  2786,
    2794,  2795,  2801,  2803,  2806,  2807,  2809,  2811,  2813,  2814,
    2816,  2818,  2821,  2824,  2827,  2829,  2831,  2833,  2835,  2839,
    2841,  2843,  2846,  2847,  2850,  2852,  2854,  2856,  2858,  2860,
    2862,  2864,  2868,  2869,  2871,  2873,  2875,  2877,  2880,  2883,
    2886,  2892,  2901,  2903,  2905,  2907,  2912,  2917,  2919,  2921,
    2923,  2925,  2928,  2932,  2939,  2941,  2945,  2947,  2949,  2951,
    2955,  2962,  2972,  2974,  2976,  2978,  2980,  2983,  2984,  2986,
    2988,  2992,  2994,  2998,  3000,  3004,  3006,  3010,  3012,  3014,
    3016,  3018,  3022,  3024,  3028,  3030,  3034,  3036,  3038,  3040,
    3044,  3047,  3048,  3050,  3052,  3054,  3058,  3060,  3064,  3072,
    3073,  3081,  3082,  3089,  3093,  3095,  3099,  3101,  3104,  3110,
    3111,  3119,  3120,  3123,  3124,  3126,  3132,  3135,  3141,  3142,
    3148,  3155,  3160,  3161,  3163,  3165,  3171,  3172,  3175,  3176,
    3182,  3187,  3190,  3192,  3196,  3199,  3202,  3205,  3208,  3211,
    3214,  3216,  3219,  3222,  3225,  3228,  3231,  3234,  3237,  3239,
    3241,  3243,  3245,  3248,  3251,  3253,  3255,  3257,  3259,  3261,
    3263,  3269,  3271,  3273,  3276,  3281,  3286,  3293,  3296,  3298,
    3299,  3311,  3312,  3315,  3321,  3322,  3324,  3325,  3328,  3330,
    3333,  3334,  3338,  3340,  3341,  3346,  3347,  3350,  3352,  3356,
    3358,  3360,  3365,  3371,  3377,  3381,  3382,  3384,  3386,  3388,
    3390,  3391,  3393,  3401,  3404,  3407,  3410,  3413,  3416,  3418,
    3421,  3422,  3426,  3427,  3431,  3432,  3436,  3437,  3441,  3442,
    3446,  3447,  3452,  3453,  3458,  3460,  3462,  3464,  3466,  3468,
    3470,  3471,  3476,  3477,  3479,  3480,  3485,  3487,  3490,  3493,
    3496,  3497,  3499,  3501,  3504,  3507,  3508,  3511,  3512,  3517,
    3519,  3523,  3527,  3533,  3534,  3537,  3542,  3544,  3546,  3548,
    3550,  3552,  3553,  3555,  3557,  3561,  3564,  3570,  3573,  3579,
    3585,  3591,  3597,  3603,  3609,  3610,  3613,  3615,  3618,  3621,
    3624,  3627,  3630,  3633,  3635,  3638,  3641,  3644,  3647,  3649,
    3652,  3655,  3658,  3661,  3663,  3665,  3667,  3668,  3671,  3674,
    3677,  3680,  3683,  3686,  3689,  3692,  3695,  3697,  3699,  3701,
    3703,  3705,  3707,  3709,  3711,  3714,  3717,  3720,  3723,  3726,
    3728,  3730,  3732,  3733,  3737,  3740,  3741,  3742,  3743,  3744,
    3745,  3746,  3762,  3763,  3766,  3769,  3770,  3772,  3773,  3774,
    3775,  3776,  3777,  3778,  3794,  3797,  3798,  3799,  3800,  3811,
    3812,  3814,  3818,  3822,  3825,  3830,  3834,  3838,  3842,  3844,
    3847,  3850,  3853,  3856,  3858,  3860,  3861,  3862,  3871,  3872,
    3873,  3883,  3884,  3886,  3888,  3891,  3894,  3897,  3900,  3902,
    3904,  3906,  3907,  3909,  3911,  3914,  3917,  3920,  3929,  3932,
    3935,  3940,  3943,  3944,  3946,  3948,  3952,  3955,  3958,  3960,
    3962,  3966,  3968,  3970,  3973,  3975,  3979,  3983,  3987,  3989,
    3993,  3995,  3997,  3999,  4001,  4003,  4005,  4007,  4010,  4015,
    4017,  4021,  4023,  4027,  4030,  4035,  4037,  4041,  4043,  4046,
    4051,  4053,  4057,  4059,  4061,  4063,  4066,  4070,  4075,  4078,
    4083,  4084,  4087,  4090,  4095,  4097,  4101,  4103,  4105,  4107,
    4110,  4112,  4114,  4116,  4118,  4120,  4123,  4130,  4137,  4138,
    4140,  4141,  4143,  4146,  4148,  4149,  4155,  4156,  4162,  4164,
    4165,  4169,  4171,  4175,  4177,  4181,  4183,  4185,  4186,  4191,
    4193,  4196,  4198,  4199,  4200,  4204,  4205,  4206,  4210,  4212,
    4214,  4216,  4218,  4220,  4222,  4225,  4228,  4233,  4237,  4241,
    4243,  4247,  4250,  4252,  4254,  4255,  4257,  4259,  4261,  4263,
    4264,  4266,  4270,  4272,  4276,  4278,  4279,  4283,  4285,  4287,
    4289,  4291,  4293,  4295,  4297,  4299,  4301,  4303,  4305,  4307,
    4315,  4322,  4327,  4332,  4334,  4336,  4338,  4339,  4341,  4344,
    4346,  4348,  4350,  4352,  4356,  4359,  4361,  4363,  4366,  4368,
    4370,  4371,  4375,  4377,  4381,  4383,  4387,  4389,  4391,  4398,
    4399,  4403,  4405,  4409,  4410,  4412,  4417,  4423,  4426,  4428,
    4430,  4435,  4437,  4441,  4446,  4451,  4456,  4458,  4462,  4464,
    4466,  4468,  4471,  4473,  4475,  4477,  4482,  4483,  4485,  4486,
    4488,  4490,  4493,  4496,  4498,  4500,  4502,  4504,  4506,  4511,
    4513,  4517,  4519,  4521,  4523,  4526,  4528,  4530,  4533,  4536,
    4538,  4542,  4545,  4548,  4550,  4554,  4556,  4559,  4564,  4566,
    4569,  4571,  4575,  4580,  4581,  4583,  4584,  4586,  4587,  4589,
    4591,  4595,  4597,  4601,  4603,  4606,  4608,  4612,  4615,  4618,
    4619,  4622,  4624,  4626,  4632,  4636,  4642,  4646,  4648,  4652,
    4654,  4656,  4657,  4659,  4663,  4667,  4671,  4678,  4683,  4688,
    4693,  4698,  4704,  4706,  4708,  4710,  4712,  4714,  4716,  4718,
    4720,  4722,  4724,  4726,  4728,  4729,  4731,  4733,  4735,  4737,
    4739,  4741,  4743,  4748,  4749,  4751,  4756,  4758,  4764,  4770,
    4772,  4774,  4776,  4778,  4780,  4785,  4787,  4792,  4799,  4804,
    4806,  4811,  4813,  4821,  4823,  4825,  4827,  4832,  4839,  4840,
    4843,  4848,  4850,  4852,  4854,  4856,  4858,  4860,  4862,  4866,
    4868,  4870,  4874,  4880,  4884,  4890,  4898,  4902,  4904,  4906,
    4910,  4916,  4920,  4926,  4934,  4936,  4937,  4941,  4947,  4949,
    4952,  4955,  4960,  4964,  4966,  4968,  4970,  4972,  4974,  4977,
    4980,  4981,  4985,  4986,  4990,  4992,  4994,  4996,  4998,  5000,
    5002,  5004,  5009,  5011,  5013,  5015,  5017,  5019,  5021,  5023,
    5025,  5027,  5029,  5031,  5033,  5035,  5037,  5042,  5044,  5048,
    5050,  5054,  5055,  5063,  5064,  5073,  5074,  5081,  5082,  5091,
    5092,  5094,  5097,  5099,  5103,  5105,  5109,  5115,  5117,  5119,
    5121,  5123,  5125,  5126,  5127,  5137,  5143,  5145,  5147,  5154,
    5155,  5159,  5161,  5165,  5170,  5172,  5173,  5176,  5181,  5188,
    5189,  5191,  5193,  5195,  5197,  5201,  5203,  5206,  5210,  5212,
    5214,  5217,  5220,  5222,  5224,  5226,  5229,  5232,  5235,  5238,
    5243,  5247,  5250,  5254,  5258,  5262,  5264,  5266,  5268,  5270,
    5272,  5274,  5280,  5286,  5292,  5298,  5304,  5309,  5314,  5318,
    5323,  5325,  5327,  5329,  5333,  5335,  5341,  5349,  5355,  5356,
    5359,  5361,  5363,  5364,  5368,  5370,  5374,  5376,  5378,  5380,
    5381,  5385,  5387,  5389,  5391,  5393,  5398,  5405,  5407,  5409,
    5412,  5416,  5418,  5420,  5422,  5424,  5426,  5428,  5430,  5432,
    5438,  5444,  5449,  5455,  5457,  5462,  5464,  5466,  5474,  5479,
    5481,  5482,  5487,  5489,  5492,  5494,  5496,  5498,  5500,  5502,
    5504,  5506,  5508,  5510,  5512,  5514,  5516,  5518,  5520,  5522,
    5524,  5526,  5528,  5530,  5532,  5534,  5536,  5538,  5540,  5542,
    5544,  5546,  5548,  5550,  5552,  5554,  5556,  5558,  5560,  5562,
    5564,  5566,  5568,  5570,  5572,  5574,  5576,  5578,  5580,  5582,
    5584,  5586,  5588,  5590,  5592,  5594,  5596,  5598,  5600,  5602,
    5604,  5606,  5608,  5610,  5612,  5614,  5616,  5618,  5620,  5622,
    5624,  5626,  5628,  5630,  5632,  5634,  5636,  5638,  5640,  5642,
    5644,  5646,  5648,  5650,  5652,  5654,  5656,  5658,  5660,  5662,
    5664,  5666,  5668,  5670,  5672,  5674,  5676,  5678,  5680,  5682,
    5684,  5686,  5688,  5690,  5692,  5694,  5696,  5698,  5700,  5702,
    5704,  5706,  5708,  5710,  5712,  5714,  5716,  5718,  5720,  5722,
    5724,  5726,  5728,  5730,  5732,  5734,  5736,  5738,  5740,  5742,
    5744,  5746,  5748,  5750,  5752,  5754,  5756,  5758,  5760,  5762,
    5764,  5766,  5768,  5770,  5772,  5774,  5776,  5778,  5780,  5782,
    5784,  5786,  5788,  5790,  5792,  5794,  5796,  5798,  5800,  5802,
    5804,  5806,  5808,  5810,  5812,  5814,  5816,  5818,  5820,  5822,
    5824,  5826,  5828,  5830,  5832,  5834,  5836,  5838,  5840,  5842,
    5844,  5846,  5848,  5850,  5852,  5854,  5856,  5858,  5860,  5862,
    5864,  5866,  5868,  5870,  5872,  5874,  5876,  5878,  5880,  5882,
    5884,  5886,  5888,  5890,  5892,  5894,  5896,  5898,  5900,  5902,
    5904,  5906,  5908,  5910,  5912,  5914,  5916,  5918,  5920,  5922,
    5924,  5926,  5928,  5930,  5932,  5934,  5936,  5938,  5940,  5942,
    5944,  5946,  5948,  5950,  5952,  5954,  5956,  5958,  5960,  5962,
    5964,  5966,  5968,  5970,  5972,  5974,  5976,  5978,  5980,  5982,
    5984,  5986,  5988,  5990,  5992,  5994,  5996,  5998,  6000,  6002,
    6004,  6006,  6008,  6010,  6012,  6014,  6016,  6018,  6020,  6022,
    6024,  6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,  6042,
    6044,  6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,  6062,
    6064,  6066,  6068,  6070,  6072,  6074,  6076,  6078,  6080,  6082,
    6084,  6086,  6088,  6090,  6092,  6094,  6096,  6098,  6100,  6102,
    6104,  6106,  6108,  6110,  6112,  6114,  6116,  6118,  6120,  6122,
    6124,  6126,  6128,  6129,  6133,  6134,  6138,  6139,  6140,  6147,
    6148,  6151,  6154,  6162,  6166,  6170,  6173,  6176,  6179,  6181,
    6185,  6187,  6191,  6193,  6197,  6199,  6203,  6205,  6207,  6209,
    6212,  6215,  6217,  6219,  6222,  6227,  6233,  6241,  6249,  6259,
    6261,  6263,  6265,  6267,  6269,  6271,  6275,  6278,  6282,  6286,
    6290,  6296,  6302,  6308,  6314,  6320,  6325,  6330,  6334,  6339,
    6341,  6343,  6345,  6347,  6351,  6352,  6358,  6360,  6364,  6368,
    6372,  6374,  6376,  6379,  6381,  6383,  6387,  6389,  6393,  6397,
    6399,  6401,  6403,  6407,  6410,  6414,  6421,  6423,  6427,  6429,
    6431,  6432,  6433,  6440,  6441,  6444,  6445,  6447,  6449,  6452,
    6455,  6457,  6459,  6464,  6468,  6470,  6473,  6479,  6482,  6485,
    6491,  6492,  6495,  6497,  6499,  6502,  6509,  6516,  6518,  6519,
    6521,  6524,  6526,  6529,  6530,  6533,  6535,  6537,  6539,  6541,
    6543,  6545,  6547,  6549,  6551,  6553,  6555,  6557,  6559,  6561,
    6563,  6565,  6567,  6569,  6571,  6573,  6575,  6577,  6579,  6581,
    6583,  6585,  6587,  6589,  6591,  6593,  6595,  6597,  6599,  6601,
    6603,  6605,  6607,  6609,  6611,  6613,  6615,  6617,  6619,  6621,
    6623,  6625,  6627,  6629,  6631,  6633,  6635,  6637,  6639,  6641,
    6643,  6645,  6647,  6649,  6651,  6653,  6655,  6657,  6659,  6661,
    6663,  6665,  6667,  6669,  6671,  6673,  6675,  6677,  6679,  6681,
    6683,  6685,  6687,  6689,  6691,  6693,  6695,  6697,  6699,  6701,
    6703,  6705,  6707
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1099,     0,    -1,   253,    -1,   250,    -1,   184,   734,   479,
     647,   735,    -1,   195,    -1,  1164,    -1,    26,    -1,   736,
      -1,   735,     5,   736,    -1,  1007,    -1,   483,   737,   446,
      -1,   737,   738,   737,    -1,    26,    -1,   739,    26,    -1,
    1164,    -1,   947,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   741,
      -1,    -1,   328,   483,   742,   743,   446,    -1,   620,   483,
      26,     5,    26,   446,    -1,   744,    -1,   743,     5,   744,
      -1,   542,    -1,   583,    -1,   588,    -1,   558,    -1,   463,
      -1,   656,    -1,   580,    -1,   532,    -1,   469,    -1,   543,
      -1,   401,    -1,   584,    -1,   508,    -1,   388,    -1,   645,
      -1,   151,    -1,  1078,    -1,    -1,   746,    -1,    -1,   328,
     483,   747,   748,   446,    -1,   749,    -1,   748,     5,   749,
      -1,   744,    -1,   484,    -1,   654,    25,    -1,   256,   993,
      -1,   385,   993,    -1,   338,   993,    -1,   393,   993,    -1,
     347,   993,    -1,   313,   993,    -1,   586,   751,    -1,   936,
     400,  1164,    -1,    -1,   343,   483,   955,   446,   400,   752,
    1182,    -1,   159,   483,  1007,     5,    25,     5,    25,   446,
      -1,   460,   483,   999,   446,   400,  1164,    -1,  1303,    -1,
     246,   483,   955,   446,   400,  1164,    -1,    -1,    -1,  1164,
     641,  1007,   483,   753,   767,   446,   754,   765,    -1,    -1,
      -1,    -1,  1007,   483,   755,   767,   756,   446,   757,   765,
      -1,    -1,    -1,   526,  1511,   674,  1511,   483,   758,   767,
     759,   446,   765,    -1,    -1,    -1,  1007,   573,  1007,   483,
     760,   767,   761,   446,   765,    -1,    -1,    -1,    -1,   420,
     770,   641,   771,   511,   734,   479,   483,   762,   767,   763,
     446,   764,   766,    -1,    -1,   400,  1182,    -1,    -1,   400,
    1182,    -1,   217,    -1,    -1,   768,    -1,   769,    -1,   768,
       5,   769,    -1,   907,    -1,   535,    -1,    25,    -1,  1007,
      -1,  1007,    -1,  1007,   671,  1007,    -1,    -1,   587,   914,
     773,   776,   780,   777,    -1,    -1,   587,   774,   775,   778,
     777,    -1,   782,    -1,   775,   782,    -1,   784,    -1,   776,
     784,    -1,   415,    -1,    -1,    -1,   395,   779,  1586,    -1,
      -1,    -1,   395,   781,  1586,    -1,    -1,   630,   914,   783,
    1586,    -1,    -1,   630,   914,   785,  1586,    -1,   332,  1004,
      -1,   255,  1002,    -1,   137,  1002,    -1,   222,    -1,   239,
    1517,    -1,   546,  1001,    -1,    30,   788,    31,    -1,   789,
      -1,   791,    -1,   790,    -1,   789,   790,    -1,    29,    -1,
     792,    -1,   791,   792,    -1,    28,    -1,    -1,    -1,   376,
     794,   796,   795,   797,    -1,   439,  1164,   676,   798,  1050,
    1077,   740,    -1,  1164,   676,   798,  1050,   598,   955,  1077,
     740,    -1,    -1,   800,   245,    -1,   799,    -1,   798,     5,
     799,    -1,  1007,    -1,  1007,   671,  1007,    -1,  1007,   671,
      20,    -1,   801,    -1,   800,   801,    -1,    -1,   324,   807,
     802,  1586,    -1,    -1,   327,   808,   803,  1586,    -1,    -1,
    1080,   804,  1586,    -1,    -1,   220,   805,  1586,    -1,    -1,
     218,   806,  1586,    -1,  1011,    -1,   807,     5,  1011,    -1,
    1011,    -1,   808,     5,  1011,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,   149,    -1,   150,    -1,   483,   907,
     811,   446,    -1,    -1,     5,   858,   677,   861,    -1,   210,
      -1,   333,    -1,    -1,   814,    -1,   815,    -1,   814,   815,
      -1,    -1,    -1,   490,   816,   818,   817,  1272,    -1,   871,
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
    1182,   893,    -1,   454,   930,   912,   885,   893,    -1,   264,
    1004,   893,    -1,    -1,    -1,   242,   890,  1189,   677,  1007,
     671,    20,   892,   740,   891,   894,    -1,    -1,   520,   998,
      -1,   740,    -1,    -1,   895,   292,    -1,   292,    -1,   896,
      -1,   895,   896,    -1,    -1,   407,   897,  1586,    -1,    -1,
     403,   898,  1586,    -1,    -1,  1080,   899,  1586,    -1,    42,
    1164,    -1,    43,  1164,    -1,    41,  1164,    -1,   550,   930,
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
     446,    -1,   495,   483,  1491,   446,    -1,   348,   483,  1491,
     446,    -1,    25,    -1,  1013,    -1,    26,    -1,   918,    -1,
    1164,    -1,  1164,   473,  1164,    -1,   917,    -1,   486,   907,
      -1,   447,   907,    -1,  1275,    -1,    -1,   559,   920,  1275,
      -1,     7,   907,    -1,     6,   907,    -1,   907,    -1,   922,
       5,   907,    -1,   674,   483,  1491,   446,    -1,   481,   483,
    1491,   446,    -1,   674,   483,   930,   922,   446,    -1,   481,
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
    1164,   446,    -1,   726,   483,  1164,   446,    -1,   727,   483,
    1164,     5,    26,   446,    -1,    -1,   860,   677,   860,    -1,
     857,    -1,   936,    -1,   343,   483,   955,   446,    -1,   152,
     483,   998,   446,    -1,   125,   483,   998,   446,    -1,   460,
     483,   956,   446,    -1,   246,   483,   955,   446,    -1,   113,
     483,   955,   446,    -1,   949,    -1,   931,    -1,  1468,    -1,
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
    1370,   960,  1586,   294,    -1,    -1,     8,   930,   912,    -1,
      -1,    -1,   689,  1007,   963,   813,   964,  1109,   966,   965,
     971,   690,    -1,    -1,   976,    -1,    -1,   967,    -1,   968,
      -1,   967,   968,    -1,    -1,   691,   969,  1586,    -1,    -1,
     692,   970,  1586,    -1,    -1,   972,    -1,   973,    -1,   972,
     973,    -1,    -1,   693,   974,  1586,    -1,    -1,   694,   975,
    1586,    -1,   977,   981,   380,    -1,   144,    -1,   144,   978,
     598,   979,    -1,   144,   439,   980,    -1,  1164,    -1,   978,
       5,  1164,    -1,  1007,    -1,   979,     5,  1007,    -1,  1164,
      -1,   980,     5,  1164,    -1,   982,    -1,   981,   982,    -1,
      -1,   695,   983,  1586,    -1,    -1,   696,   984,  1586,    -1,
      -1,   715,   979,   985,  1586,    -1,    -1,   533,   979,   986,
    1586,    -1,    -1,   676,   979,   987,  1586,    -1,    -1,    -1,
     647,  1164,    14,   914,   677,   914,   991,   989,  1586,   990,
     295,    -1,    -1,   623,   914,    -1,   597,  1000,    -1,   606,
      19,    26,    -1,   606,    -1,   553,    18,    26,    -1,   553,
      -1,    26,    -1,  1164,    -1,   720,    -1,    25,    -1,  1012,
      -1,   914,    -1,   995,     5,   995,    -1,   996,    -1,  1007,
      -1,   718,   483,  1007,   446,    -1,  1007,   671,   718,   483,
    1007,   446,    -1,  1007,   511,   737,   479,    -1,  1007,   671,
      20,    -1,  1007,   511,   737,   479,   671,    20,    -1,  1007,
     671,  1007,    -1,  1007,   511,   737,   479,   671,  1007,    -1,
     998,    -1,    25,    -1,  1008,    -1,  1008,    -1,  1008,    -1,
    1008,    -1,  1008,    -1,  1008,    -1,    -1,   602,    26,    -1,
    1585,    -1,  1009,    -1,  1585,    -1,   405,   483,  1010,   446,
      -1,  1167,    -1,    25,    -1,  1007,    -1,  1007,   511,   737,
     479,    -1,  1007,   671,    20,    -1,  1007,   511,   737,   479,
     671,    20,    -1,  1007,   671,  1007,    -1,  1007,   511,   737,
     479,   671,  1007,    -1,  1164,    -1,    24,    -1,   671,    26,
      -1,   599,  1015,    -1,  1007,    -1,   641,  1007,    -1,   703,
    1017,    -1,  1018,    -1,  1017,     5,  1018,    -1,  1007,    -1,
     714,  1017,    -1,   705,  1017,    -1,   706,   955,    -1,   704,
    1004,   710,   955,    -1,   708,  1017,    -1,   709,   955,    -1,
     707,  1004,   710,   955,    -1,    -1,   712,  1023,   912,  1028,
    1030,  1032,  1024,  1026,    -1,    -1,  1025,    -1,   700,    -1,
     701,    -1,    -1,  1027,    -1,   400,  1164,    -1,    -1,  1029,
      -1,   444,   912,    -1,    -1,  1031,    -1,   711,    26,    -1,
      -1,  1033,    -1,   702,    26,  1034,    -1,    -1,   453,    26,
      -1,    -1,    -1,   673,   914,   627,  1036,  1586,  1037,  1038,
     493,    -1,    -1,    -1,   594,  1039,  1586,    -1,    -1,    -1,
     116,  1040,   914,   627,  1041,  1586,  1038,    -1,   161,  1007,
     483,    26,   446,    -1,   107,  1007,    -1,    39,  1007,    -1,
     129,  1007,    -1,    -1,   344,  1193,  1045,   677,   535,    -1,
     344,  1193,   608,  1046,    -1,  1047,    -1,  1046,     5,  1047,
      -1,  1048,   671,  1464,    -1,  1048,   671,    20,    -1,  1460,
      -1,    -1,  1051,   380,    -1,   380,    -1,    -1,   205,    -1,
    1052,    -1,  1051,  1052,    -1,    -1,   324,  1066,  1053,  1586,
      -1,    -1,   327,  1067,  1054,  1586,    -1,    -1,   407,  1055,
    1586,    -1,    -1,   403,  1056,  1586,    -1,    -1,  1080,  1057,
    1586,    -1,    -1,   359,  1058,  1586,    -1,    -1,   329,  1059,
    1586,    -1,    -1,    49,  1060,  1586,    -1,    -1,    46,  1061,
    1586,    -1,    -1,    45,  1062,  1586,    -1,    -1,    44,  1063,
    1586,    -1,    -1,    52,  1064,  1586,    -1,    -1,    51,  1065,
    1586,    -1,   998,    -1,  1066,     5,   998,    -1,   998,    -1,
    1067,     5,   998,    -1,   368,  1070,    -1,   369,  1007,   710,
    1070,    -1,   613,    -1,   430,    -1,   998,    -1,    -1,   716,
    1073,  1072,  1049,    -1,   439,  1182,  1050,  1006,   740,    -1,
    1182,  1050,   598,   955,  1006,   740,    -1,    -1,   539,  1189,
    1050,   598,  1007,   671,    20,  1006,  1074,   740,    -1,   521,
     955,  1076,    -1,   135,    26,    -1,   136,    26,    -1,   678,
      -1,   591,    -1,   135,  1164,    -1,   136,  1164,    -1,    -1,
     602,    26,    -1,  1079,    -1,    58,    25,    -1,   548,    14,
      26,    -1,   548,    14,  1164,    -1,    59,    14,    26,    -1,
      59,    14,  1164,    -1,    55,    -1,    57,    -1,    54,    -1,
      56,    -1,    -1,   482,  1081,  1086,    -1,   349,    -1,    -1,
     648,  1083,  1086,    -1,   357,  1088,    -1,   648,  1086,    -1,
    1088,    -1,   483,  1087,   446,    -1,  1088,    -1,  1087,     5,
    1088,    -1,  1089,    -1,   646,    -1,   366,    -1,   386,    -1,
     358,    -1,   537,    -1,   494,    -1,   678,    -1,   602,    -1,
     591,    -1,   231,    -1,   491,    -1,   502,    -1,   592,    -1,
     607,    -1,   572,    -1,   364,    -1,   365,    -1,    25,    -1,
     562,    -1,    -1,    -1,   650,  1092,  1187,  1093,    14,   930,
    1094,    -1,   535,    -1,   913,    -1,   273,  1164,    -1,   263,
    1164,    -1,   276,  1164,    -1,   503,  1185,   389,    -1,   503,
    1185,   440,   994,    -1,    -1,  1101,  1100,  1104,    -1,    -1,
    1102,    -1,  1103,    -1,  1102,  1103,    -1,  1043,    -1,  1108,
      -1,  1570,    -1,  1124,    -1,  1110,    -1,  1123,    -1,    -1,
    1105,    -1,  1107,    -1,  1105,  1107,    -1,   120,  1007,    -1,
    1112,    -1,  1118,    -1,  1130,    -1,  1285,    -1,  1295,    -1,
    1134,    -1,   962,    -1,   787,    -1,  1042,    -1,  1570,    -1,
     787,    -1,    -1,   787,    -1,   814,    -1,   422,    -1,   114,
      -1,    -1,    -1,    -1,    -1,  1111,  1113,  1007,   483,  1114,
    1180,   446,  1115,   813,  1116,  1109,  1586,  1117,    -1,   265,
      -1,    -1,    -1,   609,  1119,   813,  1120,  1586,   416,    -1,
     231,   909,    -1,   930,    -1,   930,   912,    -1,   411,  1475,
      -1,   519,  1475,    -1,  1125,    -1,  1126,    -1,  1125,  1126,
      -1,  1127,    -1,    -1,   459,  1128,  1129,    -1,   813,   296,
      -1,   994,    -1,  1108,    -1,  1123,    -1,    -1,    -1,    -1,
     168,  1007,   167,  1007,   483,  1131,  1180,   446,  1132,   813,
    1133,  1109,  1586,  1117,    -1,    -1,    -1,   697,  1007,  1135,
     813,  1136,  1137,   698,    -1,  1138,    -1,  1137,  1138,    -1,
      -1,   699,  1139,  1586,    -1,    -1,   676,  1007,  1140,  1586,
      -1,    -1,   610,  1142,  1157,  1148,  1143,    -1,   417,    -1,
      -1,   288,  1145,  1586,    -1,    -1,    23,  1149,  1150,  1151,
    1006,  1146,  1586,    -1,    -1,    23,  1149,  1006,  1147,  1586,
      -1,  1144,    -1,  1148,  1144,    -1,    -1,  1082,    -1,    25,
      -1,  1164,    -1,    -1,  1164,    -1,    25,    -1,   305,  1155,
      -1,   317,  1156,    -1,   300,  1156,    -1,   637,    -1,    25,
      -1,  1164,    -1,  1155,    -1,  1156,     5,  1155,    -1,  1164,
      -1,    25,    -1,  1161,  1159,    -1,    -1,   741,  1162,    -1,
    1163,    -1,  1160,    -1,  1029,    -1,  1031,    -1,  1033,    -1,
    1025,    -1,  1027,    -1,   425,   930,   912,    -1,    -1,   119,
      -1,   119,    -1,  1165,    -1,  1167,    -1,   244,  1167,    -1,
    1167,   671,    -1,  1166,  1171,    -1,  1166,  1007,   511,  1174,
     479,    -1,  1166,  1007,   511,  1174,   479,   511,  1174,   479,
      -1,  1172,    -1,  1007,    -1,  1168,    -1,  1007,   510,  1170,
     478,    -1,  1007,   510,  1170,   478,    -1,  1164,    -1,    25,
      -1,    20,    -1,  1007,    -1,  1007,  1173,    -1,   511,  1174,
     479,    -1,   511,  1174,   479,   511,  1174,   479,    -1,  1175,
      -1,  1174,     5,  1175,    -1,   737,    -1,  1177,    -1,  1179,
      -1,  1177,   671,  1178,    -1,  1177,   671,  1007,   511,  1174,
     479,    -1,  1177,   671,  1007,   511,  1174,   479,   511,  1174,
     479,    -1,  1007,    -1,  1169,    -1,    20,    -1,  1007,    -1,
    1007,  1173,    -1,    -1,  1181,    -1,  1183,    -1,  1181,     5,
    1183,    -1,  1184,    -1,  1182,     5,  1184,    -1,  1007,    -1,
    1007,   671,  1007,    -1,  1164,    -1,  1164,   473,  1164,    -1,
      25,    -1,  1013,    -1,    26,    -1,  1186,    -1,  1185,     5,
    1186,    -1,  1164,    -1,  1164,   473,  1164,    -1,  1188,    -1,
    1187,     5,  1188,    -1,  1176,    -1,  1164,    -1,  1191,    -1,
    1190,     5,  1191,    -1,  1164,  1192,    -1,    -1,   639,    -1,
     590,    -1,  1194,    -1,  1193,     5,  1194,    -1,  1164,    -1,
    1164,   473,  1164,    -1,   308,  1003,   669,   996,   631,  1578,
     745,    -1,    -1,   669,   483,   914,     5,   914,   446,  1197,
      -1,    -1,   620,   483,   914,     5,   914,   446,    -1,   309,
    1007,  1196,    -1,  1007,    -1,   394,  1005,  1201,    -1,  1202,
      -1,   598,   914,    -1,  1203,  1204,  1209,     8,  1199,    -1,
      -1,   669,  1205,   483,   914,     5,   914,   446,    -1,    -1,
     608,  1008,    -1,    -1,   406,    -1,   271,  1517,   320,  1559,
    1208,    -1,   615,  1000,    -1,   615,  1000,     8,   930,   912,
      -1,    -1,   668,   628,  1511,   429,  1511,    -1,   668,   628,
    1511,     5,   429,  1511,    -1,   668,  1511,     5,  1511,    -1,
      -1,   700,    -1,   701,    -1,   448,   677,  1559,  1211,  1212,
      -1,    -1,   668,  1559,    -1,    -1,   668,   628,  1511,     8,
    1511,    -1,   628,  1511,     8,  1511,    -1,   464,  1214,    -1,
    1215,    -1,  1214,     5,  1215,    -1,   256,   993,    -1,   338,
     993,    -1,   385,   993,    -1,   393,   993,    -1,   347,   993,
      -1,   313,   993,    -1,  1084,    -1,   491,  1085,    -1,   502,
    1085,    -1,   613,  1085,    -1,   430,  1085,    -1,   602,  1085,
      -1,   600,   994,    -1,   601,   994,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,   454,   741,    -1,   716,   741,
      -1,   345,    -1,   249,    -1,   206,    -1,   186,    -1,   203,
      -1,   194,    -1,  1516,   466,  1219,   598,  1217,    -1,  1164,
      -1,    25,    -1,   456,  1219,    -1,   456,  1219,     8,  1182,
      -1,   456,  1219,   605,  1185,    -1,   456,  1219,   605,  1185,
       8,  1182,    -1,    53,  1217,    -1,  1008,    -1,    -1,   514,
    1229,   740,   647,  1224,  1164,  1222,  1006,   740,  1221,  1225,
      -1,    -1,   719,    26,    -1,   514,  1229,   740,   400,  1164,
      -1,    -1,   373,    -1,    -1,  1226,   336,    -1,  1227,    -1,
    1226,  1227,    -1,    -1,  1080,  1228,  1586,    -1,   913,    -1,
      -1,   655,  1000,  1231,  1232,    -1,    -1,   598,  1233,    -1,
    1234,    -1,  1233,     5,  1234,    -1,  1503,    -1,   535,    -1,
     274,  1238,   142,  1236,    -1,   274,  1238,   677,  1237,  1236,
      -1,   274,  1238,   141,  1237,  1236,    -1,   274,  1238,  1236,
      -1,    -1,    47,    -1,    25,    -1,  1012,    -1,  1007,    -1,
      -1,   531,    -1,   202,  1238,  1239,   483,   930,  1122,   446,
      -1,   247,  1238,    -1,   121,  1238,    -1,  1276,  1284,    -1,
     499,   115,    -1,   499,  1245,    -1,  1246,    -1,  1245,  1246,
      -1,    -1,   190,  1247,  1586,    -1,    -1,   252,  1248,  1586,
      -1,    -1,   282,  1249,  1586,    -1,    -1,   270,  1250,  1586,
      -1,    -1,   307,  1251,  1586,    -1,    -1,   254,  1164,  1252,
    1586,    -1,    -1,   278,  1164,  1253,  1586,    -1,  1264,    -1,
    1268,    -1,  1267,    -1,  1255,    -1,  1293,    -1,  1258,    -1,
      -1,   612,   914,  1256,   534,    -1,    -1,   534,    -1,    -1,
     621,    26,  1259,  1257,    -1,   213,    -1,   680,  1280,    -1,
     216,  1280,    -1,   215,  1280,    -1,    -1,  1261,    -1,  1262,
      -1,  1261,  1262,    -1,  1273,  1263,    -1,    -1,   669,  1280,
      -1,    -1,   571,  1265,  1260,  1272,    -1,  1511,    -1,   483,
    1511,   446,    -1,   570,  1266,  1272,    -1,   569,  1271,  1270,
    1269,  1272,    -1,    -1,   207,   907,    -1,   207,   907,     5,
     907,    -1,   664,    -1,   665,    -1,   666,    -1,   667,    -1,
    1164,    -1,    -1,   574,    -1,  1274,    -1,  1273,     5,  1274,
      -1,   914,  1307,    -1,   660,   483,   907,   446,  1292,    -1,
     118,  1292,    -1,   548,   483,    20,   446,  1292,    -1,   465,
     483,    20,   446,  1292,    -1,   442,   483,   907,   446,  1292,
      -1,   640,   483,   907,   446,  1292,    -1,   653,   483,   907,
     446,  1292,    -1,   652,   483,   907,   446,  1292,    -1,    -1,
     513,  1277,    -1,  1278,    -1,  1277,  1278,    -1,   281,    26,
      -1,   272,    26,    -1,   355,    26,    -1,   238,    26,    -1,
     310,    26,    -1,   229,    -1,   399,    25,    -1,   399,  1164,
      -1,   230,    25,    -1,   214,    25,    -1,  1283,    -1,  1279,
    1283,    -1,  1281,   163,    -1,  1281,   165,    -1,  1281,   164,
      -1,  1281,    -1,  1013,    -1,    26,    -1,    -1,   513,  1279,
      -1,   281,  1280,    -1,   272,  1280,    -1,   355,  1280,    -1,
     238,  1280,    -1,   310,  1280,    -1,   311,  1280,    -1,   679,
      25,    -1,   680,  1280,    -1,   684,    -1,   681,    -1,   682,
      -1,   683,    -1,   688,    -1,   685,    -1,   686,    -1,   687,
      -1,   130,  1280,    -1,   131,  1280,    -1,   132,  1280,    -1,
     399,    25,    -1,   230,    25,    -1,   453,    -1,   127,    -1,
     128,    -1,    -1,   566,   670,  1190,    -1,   191,  1190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   517,  1286,  1007,   483,
    1287,  1180,   446,  1288,   813,  1289,  1243,  1290,  1244,  1291,
     293,    -1,    -1,   578,   907,    -1,   568,  1294,    -1,    -1,
    1217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,  1296,
    1007,   483,  1297,  1180,   446,  1298,   813,  1299,  1302,  1300,
    1244,  1301,   293,    -1,  1282,  1284,    -1,    -1,    -1,    -1,
     209,   483,    25,     5,  1304,   767,  1305,   446,  1306,   765,
      -1,    -1,   438,    -1,   438,   272,    26,    -1,   438,   272,
    1164,    -1,   658,   914,    -1,   658,   914,   400,  1164,    -1,
     658,   914,   217,    -1,   658,   914,   629,    -1,   658,   914,
     596,    -1,  1310,    -1,   226,  1460,    -1,   379,  1460,    -1,
     335,  1461,    -1,    50,  1007,    -1,  1324,    -1,  1312,    -1,
      -1,    -1,   259,  1313,  1460,   483,  1314,  1328,   446,  1317,
      -1,    -1,    -1,   188,  1315,  1460,   483,  1316,  1328,   446,
    1317,  1325,    -1,    -1,  1318,    -1,  1319,    -1,  1318,  1319,
      -1,   674,  1320,    -1,   298,    26,    -1,    62,    26,    -1,
     139,    -1,   140,    -1,  1585,    -1,    -1,  1322,    -1,  1323,
      -1,  1322,  1323,    -1,   674,  1320,    -1,   728,    26,    -1,
     158,  1461,   676,  1460,   483,  1326,   446,  1321,    -1,   105,
    1008,    -1,   106,  1008,    -1,   225,  1460,   647,  1460,    -1,
     110,  1460,    -1,    -1,   322,    -1,  1327,    -1,  1326,     5,
    1327,    -1,  1007,   639,    -1,  1007,   590,    -1,  1007,    -1,
    1329,    -1,  1328,     5,  1329,    -1,  1412,    -1,  1410,    -1,
     175,  1007,    -1,   233,    -1,    60,  1007,  1332,    -1,    61,
    1461,   155,    -1,    61,  1461,   156,    -1,  1333,    -1,  1332,
       5,  1333,    -1,  1334,    -1,  1337,    -1,  1340,    -1,  1345,
      -1,  1348,    -1,  1344,    -1,  1343,    -1,   636,  1335,    -1,
     636,   483,  1336,   446,    -1,  1329,    -1,  1329,   715,  1007,
      -1,  1335,    -1,  1336,     5,  1335,    -1,   593,  1339,    -1,
     593,   483,  1338,   446,    -1,  1339,    -1,  1338,     5,  1339,
      -1,  1007,    -1,   507,  1342,    -1,   507,   483,  1341,   446,
      -1,  1342,    -1,  1341,     5,  1342,    -1,  1329,    -1,   139,
      -1,   140,    -1,   138,    26,    -1,   108,  1410,  1347,    -1,
     108,   483,  1346,   446,    -1,  1410,  1347,    -1,  1346,     5,
    1410,  1347,    -1,    -1,   111,  1007,    -1,   109,  1349,    -1,
     109,   483,  1349,   446,    -1,  1350,    -1,  1349,     5,  1350,
      -1,  1007,    -1,   319,    -1,   285,    -1,   219,  1353,    -1,
     198,    -1,   187,    -1,   174,    -1,   172,    -1,   176,    -1,
     232,  1517,    -1,   284,  1352,   512,  1511,   677,  1511,    -1,
     352,  1000,   512,  1511,   677,  1511,    -1,    -1,  1517,    -1,
      -1,   914,    -1,   575,   914,    -1,   283,    -1,    -1,   302,
    1357,  1460,  1360,  1358,    -1,    -1,   531,  1359,   483,  1362,
     446,    -1,  1497,    -1,    -1,   483,  1361,   446,    -1,  1464,
      -1,  1361,     5,  1464,    -1,  1363,    -1,  1362,     5,  1363,
      -1,  1503,    -1,   535,    -1,    -1,   552,  1365,  1367,  1368,
      -1,  1008,    -1,  1372,  1001,    -1,  1001,    -1,    -1,    -1,
     605,  1369,  1185,    -1,    -1,    -1,   605,  1371,  1185,    -1,
     553,    -1,   606,    -1,   613,    -1,   430,    -1,   397,    -1,
     449,    -1,   433,   914,    -1,   406,   914,    -1,   291,  1460,
     204,  1001,    -1,   291,  1460,  1433,    -1,   566,   670,  1376,
      -1,  1377,    -1,  1376,     5,  1377,    -1,  1378,  1379,    -1,
      26,    -1,  1464,    -1,    -1,   639,    -1,   590,    -1,   330,
      -1,   363,    -1,    -1,   382,    -1,   411,  1384,  1382,    -1,
    1559,    -1,  1559,   663,  1007,    -1,    25,    -1,    -1,  1516,
    1386,  1387,    -1,  1418,    -1,  1422,    -1,  1381,    -1,  1518,
      -1,  1380,    -1,  1373,    -1,  1374,    -1,  1364,    -1,  1356,
      -1,  1355,    -1,  1487,    -1,  1539,    -1,   557,  1391,   676,
    1460,   677,  1396,  1390,    -1,   518,  1391,   676,  1460,   598,
    1396,    -1,   557,  1389,   677,  1396,    -1,   518,  1389,   598,
    1396,    -1,   448,    -1,   434,    -1,   643,    -1,    -1,   197,
      -1,   668,  1007,    -1,   221,    -1,   637,    -1,  1392,    -1,
    1393,    -1,  1392,     5,  1393,    -1,   523,  1394,    -1,   502,
      -1,   491,    -1,   530,  1394,    -1,   538,    -1,   560,    -1,
      -1,   483,  1395,   446,    -1,  1464,    -1,  1395,     5,  1464,
      -1,  1397,    -1,  1396,     5,  1397,    -1,   515,    -1,  1462,
      -1,   289,  1460,  1399,   668,  1497,  1401,    -1,    -1,   483,
    1400,   446,    -1,  1464,    -1,  1400,     5,  1464,    -1,    -1,
     196,    -1,   544,   483,  1436,   446,    -1,   299,   483,  1405,
     446,  1404,    -1,   350,  1406,    -1,  1407,    -1,  1460,    -1,
    1460,   483,  1407,   446,    -1,  1464,    -1,  1407,     5,  1464,
      -1,   528,   483,  1409,   446,    -1,   414,   483,  1409,   446,
      -1,   312,   483,  1409,   446,    -1,  1464,    -1,  1409,     5,
    1464,    -1,  1408,    -1,  1403,    -1,  1402,    -1,   453,  1467,
      -1,   262,    -1,   261,    -1,   260,    -1,  1007,  1452,  1413,
    1414,    -1,    -1,  1411,    -1,    -1,  1415,    -1,  1416,    -1,
    1415,  1416,    -1,  1417,  1347,    -1,   428,    -1,   212,    -1,
     528,    -1,   414,    -1,  1404,    -1,   544,   483,  1436,   446,
      -1,   312,    -1,   173,  1419,  1421,    -1,  1420,    -1,  1462,
      -1,  1422,    -1,  1421,  1422,    -1,  1398,    -1,  1388,    -1,
     500,  1436,    -1,   423,  1425,    -1,  1502,    -1,  1425,     5,
    1502,    -1,   578,  1436,    -1,   598,  1428,    -1,  1429,    -1,
    1428,     5,  1429,    -1,  1430,    -1,   567,  1430,    -1,   567,
     483,  1431,   446,    -1,  1460,    -1,  1460,  1466,    -1,  1429,
      -1,  1431,     5,  1429,    -1,  1427,  1433,  1434,  1435,    -1,
      -1,  1426,    -1,    -1,  1424,    -1,    -1,  1423,    -1,  1437,
      -1,  1436,     6,  1437,    -1,  1438,    -1,  1437,     7,  1438,
      -1,  1439,    -1,     9,  1439,    -1,  1450,    -1,   483,  1436,
     446,    -1,   495,  1498,    -1,   348,  1498,    -1,    -1,   494,
    1443,    -1,  1504,    -1,  1507,    -1,  1503,   674,   483,  1445,
     446,    -1,  1503,   674,  1498,    -1,  1503,   481,   483,  1445,
     446,    -1,  1503,   481,  1498,    -1,  1446,    -1,  1445,     5,
    1446,    -1,  1565,    -1,  1467,    -1,    -1,     9,    -1,  1503,
    1447,   441,    -1,  1503,  1447,   303,    -1,  1503,  1449,  1503,
      -1,  1503,  1447,   443,  1503,     7,  1503,    -1,  1503,   608,
    1442,  1441,    -1,  1503,   426,  1442,  1441,    -1,  1503,   725,
    1442,  1441,    -1,  1503,   427,  1442,  1441,    -1,  1503,  1447,
      10,  1442,  1441,    -1,    14,    -1,    17,    -1,    12,    -1,
      13,    -1,   306,    -1,    10,    -1,   724,    -1,    16,    -1,
      15,    -1,  1448,    -1,  1444,    -1,  1440,    -1,    -1,   637,
      -1,   414,    -1,   528,    -1,  1453,    -1,  1454,    -1,  1456,
      -1,   373,    -1,   373,   483,  1457,   446,    -1,    -1,   524,
      -1,   524,   483,    26,   446,    -1,   451,    -1,   451,   483,
    1458,  1455,   446,    -1,   564,   483,  1458,  1455,   446,    -1,
     564,    -1,   589,    -1,   461,    -1,   435,    -1,   374,    -1,
     374,   483,  1457,   446,    -1,   375,    -1,   375,   483,    26,
     446,    -1,   375,   483,    26,     5,    26,   446,    -1,   412,
    1473,   677,  1474,    -1,   412,    -1,   424,  1473,   677,  1474,
      -1,   424,    -1,   424,  1473,   483,    26,   446,   677,  1474,
      -1,   626,    -1,   585,    -1,   476,    -1,   476,   483,    26,
     446,    -1,   476,   483,    26,     5,    26,   446,    -1,    -1,
       5,  1459,    -1,   554,   483,  1458,   446,    -1,   617,    -1,
     353,    -1,   554,    -1,   117,    -1,    26,    -1,    26,    -1,
      26,    -1,    25,   671,  1007,    -1,    25,    -1,  1007,    -1,
    1007,   641,  1007,    -1,  1007,   641,    25,   671,  1007,    -1,
    1007,   663,  1007,    -1,  1007,   663,  1007,   641,  1007,    -1,
    1007,   663,  1007,   641,    25,   671,  1007,    -1,    25,   671,
    1007,    -1,    25,    -1,  1007,    -1,  1007,   641,  1007,    -1,
    1007,   641,    25,   671,  1007,    -1,  1007,   663,  1007,    -1,
    1007,   663,  1007,   641,  1007,    -1,  1007,   663,  1007,   641,
      25,   671,  1007,    -1,  1007,    -1,    -1,   511,    26,   479,
      -1,   511,    26,     5,    26,   479,    -1,  1465,    -1,   663,
    1465,    -1,  1007,  1463,    -1,  1460,   671,  1007,  1463,    -1,
    1460,   671,    20,    -1,  1007,    -1,    25,    -1,  1013,    -1,
      26,    -1,  1469,    -1,   449,  1471,    -1,   449,  1470,    -1,
      -1,  1473,   677,  1474,    -1,    -1,  1472,   677,  1472,    -1,
     633,    -1,   565,    -1,   642,    -1,   604,    -1,   506,    -1,
     522,    -1,   421,    -1,   421,   483,    26,   446,    -1,   633,
      -1,   565,    -1,   642,    -1,   604,    -1,   506,    -1,   522,
      -1,   421,    -1,   633,    -1,   565,    -1,   642,    -1,   604,
      -1,   506,    -1,   522,    -1,   421,    -1,   421,   483,    26,
     446,    -1,  1007,    -1,  1007,   663,  1007,    -1,    25,    -1,
    1516,   555,  1001,    -1,    -1,  1516,   452,  1366,   489,   647,
    1485,  1478,    -1,    -1,  1516,   452,  1366,   489,   153,   647,
    1486,  1479,    -1,    -1,  1516,   452,  1366,   192,  1486,  1480,
      -1,    -1,  1516,   452,  1366,   193,   153,   647,  1486,  1481,
      -1,    -1,   342,    -1,   341,  1483,    -1,  1484,    -1,  1483,
       5,  1484,    -1,  1007,    -1,  1007,   671,  1007,    -1,    25,
     671,  1007,   671,  1007,    -1,  1486,    -1,  1356,    -1,  1219,
      -1,  1488,    -1,  1488,    -1,    -1,    -1,   523,  1499,  1489,
    1500,  1490,  1496,  1432,  1494,  1482,    -1,   523,  1499,  1500,
    1432,  1494,    -1,  1493,    -1,  1511,    -1,   523,  1499,  1500,
    1496,  1432,  1494,    -1,    -1,   577,  1451,  1492,    -1,  1375,
      -1,   387,  1495,  1325,    -1,  1375,   387,  1495,  1325,    -1,
    1007,    -1,    -1,   605,  1185,    -1,   523,  1499,  1500,  1432,
      -1,   483,   523,  1499,  1500,  1432,   446,    -1,    -1,   637,
      -1,   414,    -1,   528,    -1,  1501,    -1,  1500,     5,  1501,
      -1,  1503,    -1,  1503,  1007,    -1,  1503,   668,  1007,    -1,
    1503,    -1,  1504,    -1,    19,  1504,    -1,    18,  1504,    -1,
    1505,    -1,  1565,    -1,  1498,    -1,   637,  1498,    -1,   638,
    1498,    -1,   622,  1498,    -1,   663,  1007,    -1,   663,  1007,
     671,  1007,    -1,  1504,    21,  1503,    -1,  1504,  1525,    -1,
    1504,    20,  1503,    -1,  1504,    18,  1503,    -1,  1504,    19,
    1503,    -1,  1467,    -1,   536,    -1,   480,    -1,   628,    -1,
      20,    -1,   118,    -1,   640,   483,  1451,  1503,   446,    -1,
     652,   483,  1451,  1503,   446,    -1,   653,   483,  1451,  1503,
     446,    -1,   660,   483,  1451,  1503,   446,    -1,   548,   483,
    1451,  1503,   446,    -1,  1007,   483,  1506,   446,    -1,   589,
     483,  1506,   446,    -1,   483,  1503,   446,    -1,   496,   483,
    1526,   446,    -1,  1527,    -1,  1529,    -1,  1503,    -1,  1506,
       5,  1503,    -1,  1467,    -1,  1516,   402,  1515,  1510,  1492,
      -1,  1516,   391,  1515,  1510,   302,  1460,  1512,    -1,  1516,
     391,  1515,  1510,  1164,    -1,    -1,   377,  1511,    -1,    25,
      -1,  1164,    -1,    -1,   483,  1513,   446,    -1,  1514,    -1,
    1513,     5,  1514,    -1,  1007,    -1,    25,    -1,  1164,    -1,
      -1,   321,  1517,   647,    -1,  1008,    -1,  1523,    -1,  1522,
      -1,  1519,    -1,   370,  1520,   677,  1520,    -1,   351,  1460,
     671,  1521,   677,  1521,    -1,  1007,    -1,  1007,    -1,   275,
    1460,    -1,   346,  1460,  1524,    -1,   325,    -1,   228,    -1,
     145,    -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,
     150,    -1,   449,     5,  1473,   677,  1474,    -1,  1565,     5,
    1473,   677,  1474,    -1,   449,  1473,   677,  1474,    -1,  1503,
       5,  1473,   677,  1474,    -1,  1528,    -1,  1528,  1473,   677,
    1474,    -1,    36,    -1,  1530,    -1,  1530,  1473,   483,    26,
     446,   677,  1474,    -1,  1530,  1473,   677,  1474,    -1,    37,
      -1,    -1,   659,  1532,  1533,   243,    -1,  1534,    -1,  1533,
    1534,    -1,    33,    -1,  1535,    -1,  1537,    -1,   406,    -1,
     358,    -1,   277,    -1,   636,    -1,   533,    -1,   637,    -1,
     538,    -1,   582,    -1,   638,    -1,   169,    -1,   539,    -1,
     668,    -1,   639,    -1,   371,    -1,   540,    -1,   372,    -1,
     669,    -1,   663,    -1,   328,    -1,   541,    -1,   237,    -1,
     442,    -1,   640,    -1,   715,    -1,   443,    -1,   542,    -1,
     543,    -1,   583,    -1,   584,    -1,   484,    -1,   485,    -1,
     408,    -1,   702,    -1,   670,    -1,   585,    -1,   444,    -1,
     587,    -1,   581,    -1,   373,    -1,   544,    -1,   545,    -1,
     445,    -1,   546,    -1,   446,    -1,   479,    -1,   547,    -1,
     641,    -1,   486,    -1,   447,    -1,     5,    -1,    23,    -1,
     487,    -1,   448,    -1,   410,    -1,   409,    -1,   376,    -1,
     548,    -1,   488,    -1,   449,    -1,   489,    -1,   588,    -1,
     411,    -1,   589,    -1,   412,    -1,   642,    -1,   643,    -1,
     450,    -1,   644,    -1,   451,    -1,   452,    -1,   453,    -1,
     413,    -1,   549,    -1,   490,    -1,   491,    -1,   377,    -1,
     590,    -1,   334,    -1,   645,    -1,   706,    -1,   454,    -1,
     414,    -1,    21,    -1,   671,    -1,   492,    -1,   378,    -1,
     593,    -1,   116,    -1,   594,    -1,   709,    -1,   455,    -1,
      14,    -1,   550,    -1,   494,    -1,   551,    -1,   382,    -1,
     595,    -1,   456,    -1,   495,    -1,   596,    -1,   496,    -1,
     497,    -1,   420,    -1,   586,    -1,   552,    -1,   152,    -1,
     246,    -1,   498,    -1,   553,    -1,   646,    -1,   554,    -1,
     555,    -1,   647,    -1,   457,    -1,   458,    -1,   499,    -1,
     689,    -1,   144,    -1,   159,    -1,   556,    -1,   421,    -1,
     597,    -1,   598,    -1,   422,    -1,   343,    -1,   459,    -1,
     672,    -1,   599,    -1,   557,    -1,    13,    -1,   558,    -1,
     559,    -1,   500,    -1,   501,    -1,   602,    -1,   603,    -1,
     604,    -1,   711,    -1,   125,    -1,   673,    -1,   674,    -1,
     165,    -1,   560,    -1,   460,    -1,   344,    -1,   716,    -1,
     502,    -1,   461,    -1,   386,    -1,   424,    -1,   718,    -1,
     388,    -1,   648,    -1,   591,    -1,   710,    -1,   561,    -1,
     534,    -1,   425,    -1,   649,    -1,   678,    -1,   462,    -1,
       7,    -1,   480,    -1,   634,    -1,   535,    -1,     6,    -1,
     536,    -1,     8,    -1,   606,    -1,   607,    -1,    12,    -1,
     650,    -1,   608,    -1,   563,    -1,   503,    -1,   651,    -1,
     463,    -1,   609,    -1,   504,    -1,    10,    -1,    59,    -1,
     505,    -1,   610,    -1,   697,    -1,   712,    -1,    19,    -1,
     506,    -1,   164,    -1,    22,    -1,   611,    -1,   507,    -1,
     564,    -1,   565,    -1,    20,    -1,   612,    -1,   613,    -1,
     364,    -1,   614,    -1,   508,    -1,     9,    -1,   675,    -1,
     720,    -1,   676,    -1,   615,    -1,   483,    -1,   511,    -1,
     512,    -1,   464,    -1,   566,    -1,   395,    -1,   567,    -1,
     513,    -1,   654,    -1,   429,    -1,   568,    -1,   209,    -1,
     160,    -1,   465,    -1,    18,    -1,   163,    -1,   396,    -1,
     466,    -1,   166,    -1,   430,    -1,   365,    -1,   571,    -1,
     397,    -1,   398,    -1,   467,    -1,   514,    -1,   515,    -1,
     655,    -1,   616,    -1,   431,    -1,   617,    -1,   516,    -1,
     468,    -1,   656,    -1,   350,    -1,   432,    -1,   433,    -1,
     517,    -1,   434,    -1,   231,    -1,   400,    -1,   469,    -1,
     518,    -1,   572,    -1,   315,    -1,   657,    -1,   618,    -1,
     658,    -1,   519,    -1,   521,    -1,   522,    -1,   470,    -1,
     523,    -1,   574,    -1,   524,    -1,   471,    -1,   526,    -1,
     619,    -1,   537,    -1,   620,    -1,   621,    -1,   575,    -1,
     353,    -1,   435,    -1,   622,    -1,   527,    -1,   659,    -1,
     354,    -1,   143,    -1,   623,    -1,   624,    -1,   660,    -1,
     472,    -1,   592,    -1,   625,    -1,   170,    -1,   626,    -1,
     627,    -1,   473,    -1,   719,    -1,   677,    -1,   661,    -1,
     474,    -1,   576,    -1,   251,    -1,   401,    -1,   577,    -1,
     528,    -1,   529,    -1,   530,    -1,   475,    -1,   662,    -1,
     628,    -1,   436,    -1,   531,    -1,   476,    -1,   405,    -1,
     629,    -1,   477,    -1,   630,    -1,   578,    -1,   579,    -1,
     580,    -1,   631,    -1,   438,    -1,   632,    -1,   652,    -1,
     653,    -1,   635,    -1,   633,    -1,   532,    -1,    -1,   244,
    1536,  1565,    -1,    -1,   605,  1538,  1185,    -1,    -1,    -1,
     530,  1460,  1540,  1543,  1541,  1542,    -1,    -1,   204,  1001,
      -1,   578,  1436,    -1,   103,  1547,   446,    14,   483,  1548,
     446,    -1,    99,  1548,   446,    -1,   100,  1548,   446,    -1,
     635,  1544,    -1,   102,  1548,    -1,   101,  1548,    -1,  1546,
      -1,  1544,     5,  1546,    -1,  1464,    -1,  1545,    14,  1549,
      -1,  1545,    -1,  1547,     5,  1545,    -1,  1549,    -1,  1548,
       5,  1549,    -1,   535,    -1,  1550,    -1,  1551,    -1,    19,
    1551,    -1,    18,  1551,    -1,  1553,    -1,  1498,    -1,   663,
    1007,    -1,   663,  1007,   671,  1007,    -1,   663,  1007,   511,
      26,   479,    -1,   663,  1007,   671,  1007,   511,    26,   479,
      -1,   663,  1007,   511,    26,     5,    26,   479,    -1,   663,
    1007,   671,  1007,   511,    26,     5,    26,   479,    -1,  1552,
      -1,  1467,    -1,   536,    -1,   480,    -1,   628,    -1,   118,
      -1,  1551,    21,  1550,    -1,  1551,  1525,    -1,  1551,    20,
    1550,    -1,  1551,    18,  1550,    -1,  1551,    19,  1550,    -1,
     640,   483,  1451,  1550,   446,    -1,   652,   483,  1451,  1550,
     446,    -1,   653,   483,  1451,  1550,   446,    -1,   660,   483,
    1451,  1550,   446,    -1,   548,   483,  1451,  1550,   446,    -1,
    1007,   483,  1554,   446,    -1,   589,   483,  1554,   446,    -1,
     483,  1550,   446,    -1,   496,   483,  1526,   446,    -1,  1527,
      -1,  1529,    -1,  1565,    -1,  1550,    -1,  1554,     5,  1550,
      -1,    -1,   436,  1193,   608,  1556,  1557,    -1,  1558,    -1,
    1557,     5,  1558,    -1,  1460,   671,  1464,    -1,  1460,   671,
      20,    -1,  1561,    -1,  1561,    -1,   244,  1562,    -1,  1562,
      -1,  1563,    -1,    25,   671,  1563,    -1,  1564,    -1,  1563,
     671,  1564,    -1,  1563,   671,    20,    -1,  1566,    -1,  1007,
      -1,  1560,    -1,  1560,   473,  1560,    -1,  1007,  1567,    -1,
     511,  1568,   479,    -1,   511,  1568,   479,   511,  1568,   479,
      -1,  1569,    -1,  1568,     5,  1569,    -1,   737,    -1,    34,
      -1,    -1,    -1,   579,  1572,   914,  1573,  1586,   381,    -1,
      -1,   710,   955,    -1,    -1,   713,    -1,   235,    -1,   331,
    1002,    -1,   123,  1002,    -1,   361,    -1,   360,    -1,   362,
    1004,  1574,  1575,    -1,   545,   955,  1575,    -1,   157,    -1,
     189,  1002,    -1,   914,   618,     5,   914,   447,    -1,   561,
     914,    -1,   318,  1002,    -1,   154,  1581,     8,  1582,  1580,
      -1,    -1,   598,   914,    -1,  1007,    -1,  1007,    -1,   301,
    1002,    -1,   304,  1002,   677,   914,     5,   914,    -1,   304,
    1002,   670,   914,     5,   914,    -1,    27,    -1,    -1,  1588,
      -1,  1589,  1272,    -1,  1587,    -1,  1588,  1587,    -1,    -1,
    1590,  1591,    -1,   730,    -1,   731,    -1,   732,    -1,   733,
      -1,   750,    -1,   772,    -1,   786,    -1,   787,    -1,   793,
      -1,   812,    -1,   886,    -1,   887,    -1,   888,    -1,   889,
      -1,   900,    -1,   901,    -1,   902,    -1,   903,    -1,   904,
      -1,   905,    -1,   906,    -1,   957,    -1,   988,    -1,   992,
      -1,  1014,    -1,  1016,    -1,  1019,    -1,  1020,    -1,  1021,
      -1,  1022,    -1,  1035,    -1,  1044,    -1,  1068,    -1,  1069,
      -1,  1071,    -1,  1075,    -1,  1090,    -1,  1091,    -1,  1095,
      -1,  1096,    -1,  1097,    -1,  1098,    -1,  1106,    -1,  1121,
      -1,  1141,    -1,  1152,    -1,  1153,    -1,  1154,    -1,  1158,
      -1,  1195,    -1,  1198,    -1,  1200,    -1,  1206,    -1,  1207,
      -1,  1210,    -1,  1213,    -1,  1216,    -1,  1218,    -1,  1220,
      -1,  1223,    -1,  1230,    -1,  1235,    -1,  1240,    -1,  1241,
      -1,  1242,    -1,  1254,    -1,  1308,    -1,  1309,    -1,  1311,
      -1,  1330,    -1,  1331,    -1,  1351,    -1,  1354,    -1,  1383,
      -1,  1385,    -1,  1476,    -1,  1477,    -1,  1508,    -1,  1509,
      -1,  1531,    -1,  1555,    -1,  1570,    -1,  1571,    -1,  1576,
      -1,  1577,    -1,  1579,    -1,  1583,    -1,  1584,    -1
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
    3942,  3944,  3942,  3951,  3954,  3957,  3963,  3974,  3974,  3978,
    3984,  3984,  3988,  3989,  3993,  4003,  4004,  4005,  4008,  4010,
    4015,  4015,  4019,  4018,  4026,  4025,  4032,  4032,  4038,  4038,
    4045,  4045,  4051,  4051,  4057,  4057,  4063,  4063,  4067,  4067,
    4068,  4068,  4069,  4069,  4070,  4070,  4074,  4074,  4085,  4089,
    4095,  4099,  4104,  4109,  4114,  4115,  4116,  4120,  4119,  4132,
    4137,  4142,  4142,  4158,  4164,  4165,  4166,  4167,  4168,  4178,
    4192,  4192,  4195,  4202,  4203,  4204,  4205,  4206,  4207,  4208,
    4209,  4210,  4215,  4215,  4217,  4220,  4220,  4222,  4226,  4229,
    4230,  4233,  4233,  4238,  4241,  4242,  4243,  4244,  4245,  4246,
    4247,  4248,  4249,  4250,  4251,  4252,  4253,  4254,  4255,  4256,
    4257,  4258,  4262,  4280,  4280,  4280,  4307,  4318,  4325,  4331,
    4337,  4343,  4355,  4380,  4379,  4396,  4396,  4400,  4401,  4409,
    4410,  4411,  4412,  4413,  4414,  4421,  4422,  4424,  4425,  4429,
    4434,  4435,  4436,  4437,  4438,  4439,  4440,  4441,  4442,  4444,
    4447,  4449,  4449,  4451,  4455,  4455,  4464,  4469,  4485,  4491,
    4463,  4505,  4519,  4529,  4518,  4542,  4549,  4549,  4554,  4560,
    4568,  4573,  4574,  4577,  4580,  4580,  4588,  4594,  4605,  4606,
    4610,  4614,  4627,  4609,  4640,  4646,  4640,  4657,  4658,  4662,
    4662,  4669,  4669,  4684,  4684,  4698,  4709,  4708,  4720,  4716,
    4733,  4730,  4743,  4743,  4745,  4746,  4748,  4749,  4752,  4753,
    4754,  4756,  4761,  4766,  4772,  4774,  4775,  4778,  4779,  4782,
    4784,  4791,  4794,  4797,  4800,  4804,  4808,  4809,  4810,  4811,
    4812,  4816,  4821,  4821,  4824,  4851,  4909,  4909,  4912,  4916,
    4920,  4963,  5005,  5006,  5007,  5010,  5024,  5036,  5036,  5041,
    5042,  5048,  5113,  5118,  5125,  5130,  5138,  5144,  5177,  5180,
    5181,  5222,  5265,  5266,  5270,  5271,  5275,  5328,  5333,  5337,
    5342,  5353,  5360,  5368,  5368,  5371,  5372,  5373,  5374,  5375,
    5378,  5381,  5387,  5390,  5394,  5399,  5407,  5412,  5419,  5421,
    5427,  5429,  5429,  5429,  5449,  5456,  5463,  5466,  5480,  5487,
    5488,  5491,  5492,  5496,  5502,  5507,  5513,  5514,  5519,  5523,
    5523,  5527,  5528,  5531,  5532,  5536,  5544,  5547,  5553,  5554,
    5556,  5558,  5562,  5562,  5563,  5568,  5576,  5577,  5582,  5583,
    5585,  5598,  5600,  5601,  5604,  5605,  5606,  5607,  5608,  5609,
    5610,  5611,  5612,  5613,  5614,  5615,  5616,  5617,  5618,  5619,
    5620,  5621,  5622,  5623,  5624,  5625,  5626,  5627,  5628,  5629,
    5643,  5651,  5651,  5653,  5657,  5661,  5665,  5669,  5674,  5689,
    5687,  5707,  5708,  5712,  5717,  5718,  5722,  5723,  5725,  5726,
    5728,  5728,  5737,  5746,  5746,  5756,  5757,  5762,  5763,  5766,
    5779,  5793,  5797,  5801,  5805,  5812,  5813,  5816,  5816,  5820,
    5823,  5823,  5825,  5831,  5839,  5845,  5847,  5851,  5854,  5854,
    5857,  5857,  5862,  5862,  5871,  5871,  5875,  5875,  5876,  5876,
    5877,  5877,  5891,  5891,  5911,  5912,  5913,  5914,  5915,  5916,
    5919,  5919,  5925,  5925,  5928,  5928,  5944,  5945,  5946,  5955,
    5967,  5968,  5971,  5972,  5975,  5978,  5978,  5983,  5983,  6006,
    6007,  6013,  6018,  6024,  6025,  6026,  6030,  6031,  6032,  6033,
    6037,  6047,  6049,  6054,  6057,  6062,  6068,  6075,  6082,  6091,
    6098,  6105,  6112,  6119,  6128,  6128,  6130,  6130,  6133,  6134,
    6135,  6136,  6137,  6138,  6139,  6140,  6141,  6142,  6145,  6145,
    6148,  6149,  6150,  6151,  6154,  6154,  6157,  6157,  6160,  6161,
    6162,  6163,  6164,  6165,  6166,  6167,  6169,  6170,  6171,  6172,
    6174,  6175,  6176,  6177,  6179,  6180,  6181,  6182,  6183,  6184,
    6185,  6186,  6190,  6198,  6208,  6221,  6230,  6241,  6245,  6249,
    6255,  6220,  6268,  6271,  6279,  6291,  6293,  6298,  6306,  6316,
    6319,  6323,  6331,  6297,  6340,  6344,  6348,  6352,  6344,  6362,
    6363,  6364,  6365,  6370,  6372,  6375,  6379,  6382,  6389,  6394,
    6401,  6402,  6403,  6408,  6409,  6415,  6415,  6415,  6420,  6420,
    6420,  6428,  6429,  6433,  6434,  6439,  6440,  6441,  6442,  6443,
    6446,  6448,  6448,  6451,  6452,  6456,  6457,  6460,  6461,  6464,
    6467,  6470,  6476,  6477,  6489,  6490,  6495,  6496,  6497,  6501,
    6504,  6510,  6513,  6521,  6522,  6528,  6532,  6536,  6542,  6545,
    6554,  6557,  6560,  6563,  6566,  6569,  6572,  6579,  6582,  6589,
    6592,  6598,  6601,  6608,  6611,  6618,  6619,  6624,  6628,  6631,
    6637,  6640,  6646,  6653,  6654,  6658,  6668,  6671,  6677,  6679,
    6684,  6685,  6689,  6691,  6697,  6698,  6711,  6723,  6724,  6725,
    6726,  6727,  6728,  6729,  6730,  6731,  6734,  6737,  6743,  6743,
    6749,  6749,  6760,  6773,  6783,  6783,  6788,  6788,  6792,  6796,
    6797,  6803,  6804,  6809,  6813,  6820,  6823,  6830,  6829,  6840,
    6844,  6848,  6855,  6858,  6858,  6871,  6875,  6875,  6890,  6892,
    6894,  6896,  6898,  6900,  6902,  6904,  6910,  6920,  6927,  6932,
    6933,  6937,  6940,  6941,  6944,  6945,  6946,  6949,  6954,  6961,
    6962,  6968,  6980,  6981,  6982,  6985,  6985,  6990,  6995,  7000,
    7001,  7004,  7005,  7010,  7015,  7019,  7024,  7025,  7029,  7036,
    7037,  7038,  7039,  7044,  7045,  7046,  7049,  7050,  7051,  7055,
    7056,  7057,  7061,  7062,  7066,  7067,  7068,  7069,  7070,  7071,
    7074,  7075,  7080,  7081,  7086,  7087,  7092,  7093,  7098,  7103,
    7104,  7109,  7110,  7114,  7115,  7120,  7127,  7132,  7137,  7141,
    7142,  7147,  7148,  7154,  7157,  7161,  7166,  7167,  7173,  7176,
    7179,  7186,  7187,  7188,  7189,  7203,  7208,  7209,  7212,  7214,
    7221,  7224,  7230,  7238,  7242,  7246,  7250,  7255,  7258,  7261,
    7268,  7275,  7280,  7284,  7285,  7291,  7294,  7305,  7312,  7318,
    7321,  7328,  7335,  7341,  7342,  7348,  7349,  7350,  7353,  7354,
    7359,  7359,  7363,  7371,  7372,  7375,  7378,  7383,  7384,  7389,
    7392,  7398,  7401,  7407,  7410,  7416,  7419,  7426,  7427,  7456,
    7457,  7462,  7470,  7475,  7478,  7481,  7484,  7490,  7491,  7495,
    7498,  7501,  7502,  7507,  7510,  7513,  7516,  7519,  7522,  7525,
    7528,  7533,  7539,  7540,  7541,  7542,  7543,  7545,  7546,  7548,
    7549,  7554,  7557,  7561,  7567,  7568,  7569,  7570,  7582,  7583,
    7584,  7588,  7589,  7593,  7594,  7595,  7596,  7597,  7599,  7608,
    7615,  7616,  7617,  7618,  7619,  7620,  7621,  7623,  7625,  7627,
    7628,  7630,  7631,  7633,  7634,  7635,  7636,  7638,  7642,  7643,
    7649,  7651,  7652,  7653,  7654,  7659,  7663,  7667,  7671,  7678,
    7682,  7683,  7684,  7692,  7693,  7694,  7705,  7712,  7717,  7718,
    7719,  7727,  7728,  7729,  7746,  7755,  7756,  7757,  7761,  7764,
    7769,  7774,  7779,  7787,  7791,  7796,  7797,  7805,  7808,  7811,
    7825,  7839,  7852,  7853,  7857,  7857,  7857,  7857,  7857,  7857,
    7858,  7861,  7877,  7877,  7877,  7877,  7877,  7877,  7877,  7878,
    7878,  7878,  7878,  7878,  7878,  7878,  7878,  7881,  7882,  7883,
    7886,  7895,  7895,  7901,  7901,  7908,  7908,  7914,  7914,  7922,
    7923,  7924,  7927,  7927,  7930,  7931,  7932,  7943,  7946,  7952,
    7957,  7964,  7977,  7978,  7975,  7996,  8007,  8010,  8015,  8027,
    8030,  8034,  8037,  8038,  8048,  8051,  8052,  8061,  8070,  8075,
    8076,  8077,  8078,  8085,  8088,  8094,  8097,  8104,  8116,  8125,
    8128,  8131,  8137,  8145,  8148,  8149,  8150,  8151,  8152,  8155,
    8161,  8163,  8165,  8167,  8169,  8171,  8172,  8173,  8174,  8175,
    8176,  8177,  8179,  8181,  8183,  8185,  8187,  8189,  8191,  8192,
    8194,  8195,  8201,  8202,  8209,  8212,  8220,  8224,  8231,  8231,
    8235,  8235,  8240,  8240,  8244,  8244,  8248,  8254,  8254,  8257,
    8257,  8263,  8270,  8271,  8272,  8276,  8277,  8280,  8281,  8285,
    8291,  8301,  8302,  8310,  8311,  8312,  8313,  8314,  8315,  8319,
    8320,  8321,  8322,  8326,  8327,  8331,  8347,  8348,  8349,  8353,
    8367,  8367,  8379,  8380,  8384,  8385,  8386,  8387,  8388,  8389,
    8390,  8391,  8392,  8393,  8394,  8395,  8396,  8397,  8398,  8399,
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
    8510,  8511,  8512,  8513,  8514,  8515,  8516,  8517,  8518,  8519,
    8520,  8521,  8522,  8523,  8524,  8525,  8526,  8527,  8528,  8529,
    8530,  8531,  8532,  8533,  8534,  8535,  8536,  8537,  8538,  8539,
    8540,  8541,  8542,  8543,  8544,  8545,  8546,  8547,  8548,  8549,
    8550,  8551,  8552,  8553,  8554,  8555,  8556,  8557,  8558,  8559,
    8560,  8561,  8562,  8563,  8564,  8565,  8566,  8567,  8568,  8569,
    8570,  8571,  8572,  8573,  8574,  8575,  8576,  8577,  8578,  8579,
    8580,  8581,  8582,  8583,  8584,  8585,  8586,  8588,  8589,  8590,
    8591,  8592,  8593,  8594,  8595,  8596,  8597,  8598,  8599,  8600,
    8601,  8602,  8603,  8604,  8605,  8606,  8607,  8608,  8609,  8610,
    8611,  8612,  8613,  8614,  8615,  8616,  8617,  8618,  8619,  8620,
    8621,  8622,  8623,  8624,  8625,  8626,  8627,  8628,  8629,  8630,
    8631,  8632,  8633,  8634,  8635,  8636,  8637,  8638,  8639,  8640,
    8641,  8642,  8643,  8644,  8645,  8646,  8647,  8648,  8649,  8650,
    8651,  8652,  8653,  8654,  8655,  8656,  8657,  8658,  8659,  8660,
    8661,  8662,  8663,  8664,  8665,  8666,  8667,  8668,  8669,  8670,
    8671,  8672,  8673,  8674,  8675,  8676,  8677,  8678,  8679,  8680,
    8681,  8682,  8683,  8684,  8685,  8686,  8687,  8688,  8689,  8690,
    8691,  8692,  8693,  8694,  8695,  8696,  8697,  8698,  8699,  8700,
    8701,  8702,  8710,  8710,  8717,  8717,  8805,  8809,  8805,  8818,
    8822,  8828,  8836,  8846,  8856,  8868,  8871,  8890,  8916,  8919,
    8925,  8928,  8933,  8936,  8944,  8952,  8965,  8968,  8976,  8979,
    8982,  8990,  8994,  8995,  8996,  8997,  8998,  8999,  9000,  9001,
    9005,  9006,  9007,  9008,  9009,  9015,  9016,  9017,  9018,  9019,
    9020,  9021,  9022,  9023,  9024,  9025,  9026,  9027,  9028,  9029,
    9030,  9035,  9041,  9042,  9050,  9050,  9058,  9058,  9062,  9066,
    9081,  9096,  9102,  9104,  9112,  9113,  9117,  9118,  9121,  9128,
    9131,  9160,  9186,  9240,  9276,  9285,  9296,  9299,  9304,  9318,
    9332,  9335,  9331,  9354,  9354,  9360,  9361,  9364,  9365,  9366,
    9367,  9368,  9369,  9370,  9381,  9384,  9389,  9393,  9398,  9402,
    9407,  9411,  9414,  9418,  9421,  9426,  9430,  9441,  9447,  9447,
    9448,  9449,  9456,  9466,  9466,  9468,  9469,  9470,  9471,  9472,
    9473,  9474,  9475,  9476,  9477,  9478,  9479,  9480,  9481,  9482,
    9483,  9484,  9485,  9486,  9487,  9488,  9489,  9490,  9491,  9492,
    9493,  9494,  9495,  9496,  9497,  9498,  9499,  9500,  9501,  9502,
    9503,  9504,  9505,  9506,  9507,  9508,  9509,  9510,  9511,  9512,
    9513,  9514,  9515,  9516,  9517,  9518,  9519,  9520,  9521,  9522,
    9523,  9524,  9525,  9526,  9527,  9528,  9529,  9530,  9531,  9532,
    9533,  9534,  9535,  9536,  9537,  9538,  9539,  9540,  9541,  9542,
    9543,  9544,  9545,  9546,  9547,  9548,  9549,  9550,  9551,  9552,
    9553,  9554,  9555
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
    1040,  1041,  1038,  1042,  1042,  1042,  1043,  1045,  1044,  1044,
    1046,  1046,  1047,  1047,  1048,  1049,  1049,  1049,  1050,  1050,
    1051,  1051,  1053,  1052,  1054,  1052,  1055,  1052,  1056,  1052,
    1057,  1052,  1058,  1052,  1059,  1052,  1060,  1052,  1061,  1052,
    1062,  1052,  1063,  1052,  1064,  1052,  1065,  1052,  1066,  1066,
    1067,  1067,  1068,  1069,  1070,  1070,  1070,  1072,  1071,  1073,
    1073,  1074,  1073,  1075,  1076,  1076,  1076,  1076,  1076,  1076,
    1077,  1077,  1078,  1079,  1079,  1079,  1079,  1079,  1079,  1079,
    1079,  1079,  1081,  1080,  1080,  1083,  1082,  1084,  1085,  1086,
    1086,  1087,  1087,  1088,  1089,  1089,  1089,  1089,  1089,  1089,
    1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,
    1089,  1089,  1090,  1092,  1093,  1091,  1094,  1094,  1095,  1096,
    1097,  1098,  1098,  1100,  1099,  1101,  1101,  1102,  1102,  1103,
    1103,  1103,  1103,  1103,  1103,  1104,  1104,  1105,  1105,  1106,
    1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,
    1108,  1109,  1109,  1110,  1111,  1111,  1113,  1114,  1115,  1116,
    1112,  1117,  1119,  1120,  1118,  1121,  1122,  1122,  1123,  1123,
    1124,  1125,  1125,  1126,  1128,  1127,  1129,  1129,  1129,  1129,
    1131,  1132,  1133,  1130,  1135,  1136,  1134,  1137,  1137,  1139,
    1138,  1140,  1138,  1142,  1141,  1143,  1145,  1144,  1146,  1144,
    1147,  1144,  1148,  1148,  1149,  1149,  1150,  1150,  1151,  1151,
    1151,  1152,  1153,  1154,  1155,  1155,  1155,  1156,  1156,  1157,
    1157,  1158,  1159,  1159,  1159,  1159,  1160,  1160,  1160,  1160,
    1160,  1161,  1162,  1162,  1163,  1164,  1165,  1165,  1166,  1167,
    1167,  1167,  1167,  1167,  1167,  1168,  1169,  1170,  1170,  1171,
    1171,  1172,  1173,  1173,  1174,  1174,  1175,  1176,  1177,  1177,
    1177,  1177,  1177,  1177,  1178,  1178,  1179,  1180,  1180,  1181,
    1181,  1182,  1182,  1183,  1183,  1184,  1184,  1184,  1184,  1184,
    1185,  1185,  1186,  1186,  1187,  1187,  1188,  1189,  1190,  1190,
    1191,  1192,  1192,  1192,  1193,  1193,  1194,  1194,  1195,  1196,
    1196,  1197,  1197,  1198,  1199,  1200,  1201,  1201,  1202,  1203,
    1203,  1204,  1204,  1205,  1205,  1206,  1207,  1207,  1208,  1208,
    1208,  1208,  1209,  1209,  1209,  1210,  1211,  1211,  1212,  1212,
    1212,  1213,  1214,  1214,  1215,  1215,  1215,  1215,  1215,  1215,
    1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1216,  1217,  1217,  1218,  1218,  1218,  1218,  1218,  1219,  1221,
    1220,  1222,  1222,  1223,  1224,  1224,  1225,  1225,  1226,  1226,
    1228,  1227,  1229,  1231,  1230,  1232,  1232,  1233,  1233,  1234,
    1234,  1235,  1235,  1235,  1235,  1236,  1236,  1237,  1237,  1238,
    1239,  1239,  1240,  1241,  1242,  1243,  1244,  1244,  1245,  1245,
    1247,  1246,  1248,  1246,  1249,  1246,  1250,  1246,  1251,  1246,
    1252,  1246,  1253,  1246,  1254,  1254,  1254,  1254,  1254,  1254,
    1256,  1255,  1257,  1257,  1259,  1258,  1258,  1258,  1258,  1258,
    1260,  1260,  1261,  1261,  1262,  1263,  1263,  1265,  1264,  1266,
    1266,  1267,  1268,  1269,  1269,  1269,  1270,  1270,  1270,  1270,
    1271,  1272,  1272,  1273,  1273,  1274,  1275,  1275,  1275,  1275,
    1275,  1275,  1275,  1275,  1276,  1276,  1277,  1277,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1279,  1279,
    1280,  1280,  1280,  1280,  1281,  1281,  1282,  1282,  1283,  1283,
    1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,
    1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,
    1283,  1283,  1284,  1284,  1284,  1286,  1287,  1288,  1289,  1290,
    1291,  1285,  1292,  1292,  1293,  1294,  1294,  1296,  1297,  1298,
    1299,  1300,  1301,  1295,  1302,  1304,  1305,  1306,  1303,  1307,
    1307,  1307,  1307,  1308,  1308,  1308,  1308,  1308,  1309,  1310,
    1310,  1310,  1310,  1311,  1311,  1313,  1314,  1312,  1315,  1316,
    1312,  1317,  1317,  1318,  1318,  1319,  1319,  1319,  1319,  1319,
    1320,  1321,  1321,  1322,  1322,  1323,  1323,  1324,  1324,  1324,
    1324,  1324,  1325,  1325,  1326,  1326,  1327,  1327,  1327,  1328,
    1328,  1329,  1329,  1330,  1330,  1331,  1331,  1331,  1332,  1332,
    1333,  1333,  1333,  1333,  1333,  1333,  1333,  1334,  1334,  1335,
    1335,  1336,  1336,  1337,  1337,  1338,  1338,  1339,  1340,  1340,
    1341,  1341,  1342,  1343,  1343,  1344,  1345,  1345,  1346,  1346,
    1347,  1347,  1348,  1348,  1349,  1349,  1350,  1351,  1351,  1351,
    1351,  1351,  1351,  1351,  1351,  1351,  1351,  1351,  1352,  1352,
    1353,  1353,  1354,  1355,  1357,  1356,  1359,  1358,  1358,  1360,
    1360,  1361,  1361,  1362,  1362,  1363,  1363,  1365,  1364,  1366,
    1367,  1367,  1368,  1369,  1368,  1370,  1371,  1370,  1372,  1372,
    1372,  1372,  1372,  1372,  1372,  1372,  1373,  1374,  1375,  1376,
    1376,  1377,  1378,  1378,  1379,  1379,  1379,  1380,  1381,  1382,
    1382,  1383,  1384,  1384,  1384,  1386,  1385,  1387,  1387,  1387,
    1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1388,
    1388,  1388,  1388,  1389,  1389,  1389,  1390,  1390,  1390,  1391,
    1391,  1391,  1392,  1392,  1393,  1393,  1393,  1393,  1393,  1393,
    1394,  1394,  1395,  1395,  1396,  1396,  1397,  1397,  1398,  1399,
    1399,  1400,  1400,  1401,  1401,  1402,  1403,  1404,  1405,  1406,
    1406,  1407,  1407,  1408,  1408,  1408,  1409,  1409,  1410,  1410,
    1410,  1411,  1411,  1411,  1411,  1412,  1413,  1413,  1414,  1414,
    1415,  1415,  1416,  1417,  1417,  1417,  1417,  1417,  1417,  1417,
    1418,  1419,  1420,  1421,  1421,  1422,  1422,  1423,  1424,  1425,
    1425,  1426,  1427,  1428,  1428,  1429,  1429,  1429,  1430,  1430,
    1431,  1431,  1432,  1433,  1433,  1434,  1434,  1435,  1435,  1436,
    1436,  1437,  1437,  1438,  1438,  1439,  1439,  1440,  1440,  1441,
    1441,  1442,  1443,  1444,  1444,  1444,  1444,  1445,  1445,  1446,
    1446,  1447,  1447,  1448,  1448,  1448,  1448,  1448,  1448,  1448,
    1448,  1448,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,
    1449,  1450,  1450,  1450,  1451,  1451,  1451,  1451,  1452,  1452,
    1452,  1453,  1453,  1454,  1454,  1454,  1454,  1454,  1454,  1454,
    1454,  1454,  1454,  1454,  1454,  1454,  1454,  1454,  1454,  1454,
    1454,  1454,  1454,  1454,  1454,  1454,  1454,  1454,  1455,  1455,
    1456,  1456,  1456,  1456,  1456,  1457,  1458,  1459,  1460,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1461,  1461,  1461,  1461,
    1461,  1461,  1461,  1461,  1462,  1463,  1463,  1463,  1464,  1464,
    1465,  1465,  1465,  1466,  1467,  1467,  1467,  1467,  1468,  1469,
    1470,  1470,  1471,  1471,  1472,  1472,  1472,  1472,  1472,  1472,
    1472,  1472,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1474,
    1474,  1474,  1474,  1474,  1474,  1474,  1474,  1475,  1475,  1475,
    1476,  1478,  1477,  1479,  1477,  1480,  1477,  1481,  1477,  1482,
    1482,  1482,  1483,  1483,  1484,  1484,  1484,  1485,  1485,  1486,
    1486,  1487,  1489,  1490,  1488,  1491,  1492,  1492,  1493,  1494,
    1494,  1494,  1494,  1494,  1495,  1496,  1496,  1497,  1498,  1499,
    1499,  1499,  1499,  1500,  1500,  1501,  1501,  1501,  1502,  1503,
    1503,  1503,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,
    1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,
    1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,
    1505,  1505,  1506,  1506,  1507,  1508,  1509,  1509,  1510,  1510,
    1511,  1511,  1512,  1512,  1513,  1513,  1514,  1515,  1515,  1516,
    1516,  1517,  1518,  1518,  1518,  1519,  1519,  1520,  1521,  1522,
    1523,  1524,  1524,  1525,  1525,  1525,  1525,  1525,  1525,  1526,
    1526,  1526,  1526,  1527,  1527,  1528,  1529,  1529,  1529,  1530,
    1532,  1531,  1533,  1533,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1534,  1534,  1536,  1535,  1538,  1537,  1540,  1541,  1539,  1542,
    1542,  1542,  1543,  1543,  1543,  1543,  1543,  1543,  1544,  1544,
    1545,  1546,  1547,  1547,  1548,  1548,  1549,  1549,  1550,  1550,
    1550,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,
    1551,  1551,  1551,  1551,  1551,  1552,  1552,  1552,  1552,  1552,
    1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,  1552,
    1552,  1553,  1554,  1554,  1556,  1555,  1557,  1557,  1558,  1558,
    1559,  1560,  1561,  1561,  1562,  1562,  1563,  1563,  1563,  1564,
    1564,  1565,  1565,  1566,  1567,  1567,  1568,  1568,  1569,  1570,
    1572,  1573,  1571,  1574,  1574,  1575,  1575,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1577,  1577,  1578,  1578,  1579,  1579,
    1580,  1580,  1581,  1582,  1583,  1584,  1584,  1585,  1586,  1586,
    1587,  1588,  1588,  1590,  1589,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,  1591,
    1591,  1591,  1591
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
       1,     1,     1,     1,     1,     0,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     0,     0,     0,     0,
      13,     1,     0,     0,     6,     2,     1,     2,     2,     2,
       1,     1,     2,     1,     0,     3,     2,     1,     1,     1,
       0,     0,     0,    14,     0,     0,     7,     1,     2,     0,
       3,     0,     4,     0,     5,     1,     0,     3,     0,     7,
       0,     5,     1,     2,     0,     1,     1,     1,     0,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     2,     2,     2,
       5,     8,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     2,     3,     6,     1,     3,     1,     1,     1,     3,
       6,     9,     1,     1,     1,     1,     2,     0,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       2,     0,     1,     1,     1,     3,     1,     3,     7,     0,
       7,     0,     6,     3,     1,     3,     1,     2,     5,     0,
       7,     0,     2,     0,     1,     5,     2,     5,     0,     5,
       6,     4,     0,     1,     1,     5,     0,     2,     0,     5,
       4,     2,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     2,     4,     4,     6,     2,     1,     0,
      11,     0,     2,     5,     0,     1,     0,     2,     1,     2,
       0,     3,     1,     0,     4,     0,     2,     1,     3,     1,
       1,     4,     5,     5,     3,     0,     1,     1,     1,     1,
       0,     1,     7,     2,     2,     2,     2,     2,     1,     2,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     1,     0,     4,     1,     2,     2,     2,
       0,     1,     1,     2,     2,     0,     2,     0,     4,     1,
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
       1,     3,     3,     2,     4,     3,     3,     3,     1,     2,
       2,     2,     2,     1,     1,     0,     0,     8,     0,     0,
       9,     0,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     0,     1,     1,     2,     2,     2,     8,     2,     2,
       4,     2,     0,     1,     1,     3,     2,     2,     1,     1,
       3,     1,     1,     2,     1,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     1,
       3,     1,     3,     2,     4,     1,     3,     1,     2,     4,
       1,     3,     1,     1,     1,     2,     3,     4,     2,     4,
       0,     2,     2,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     6,     6,     0,     1,
       0,     1,     2,     1,     0,     5,     0,     5,     1,     0,
       3,     1,     3,     1,     3,     1,     1,     0,     4,     1,
       2,     1,     0,     0,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     3,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     3,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       6,     4,     4,     1,     1,     1,     0,     1,     2,     1,
       1,     1,     1,     3,     2,     1,     1,     2,     1,     1,
       0,     3,     1,     3,     1,     3,     1,     1,     6,     0,
       3,     1,     3,     0,     1,     4,     5,     2,     1,     1,
       4,     1,     3,     4,     4,     4,     1,     3,     1,     1,
       1,     2,     1,     1,     1,     4,     0,     1,     0,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     1,     1,     2,     1,     1,     2,     2,     1,
       3,     2,     2,     1,     3,     1,     2,     4,     1,     2,
       1,     3,     4,     0,     1,     0,     1,     0,     1,     1,
       3,     1,     3,     1,     2,     1,     3,     2,     2,     0,
       2,     1,     1,     5,     3,     5,     3,     1,     3,     1,
       1,     0,     1,     3,     3,     3,     6,     4,     4,     4,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     1,     4,     1,     5,     5,     1,
       1,     1,     1,     1,     4,     1,     4,     6,     4,     1,
       4,     1,     7,     1,     1,     1,     4,     6,     0,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     5,     3,     5,     7,     3,     1,     1,     3,
       5,     3,     5,     7,     1,     0,     3,     5,     1,     2,
       2,     4,     3,     1,     1,     1,     1,     1,     2,     2,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     0,     7,     0,     8,     0,     6,     0,     8,     0,
       1,     2,     1,     3,     1,     3,     5,     1,     1,     1,
       1,     1,     0,     0,     9,     5,     1,     1,     6,     0,
       3,     1,     3,     4,     1,     0,     2,     4,     6,     0,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     1,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     4,
       3,     2,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     5,     5,     5,     5,     5,     4,     4,     3,     4,
       1,     1,     1,     3,     1,     5,     7,     5,     0,     2,
       1,     1,     0,     3,     1,     3,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     4,     6,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     5,     1,     4,     1,     1,     7,     4,     1,
       0,     4,     1,     2,     1,     1,     1,     1,     1,     1,
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
       1,     1,     0,     3,     0,     3,     0,     0,     6,     0,
       2,     2,     7,     3,     3,     2,     2,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       2,     1,     1,     2,     4,     5,     7,     7,     9,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     3,     3,
       5,     5,     5,     5,     5,     4,     4,     3,     4,     1,
       1,     1,     1,     3,     0,     5,     1,     3,     3,     3,
       1,     1,     2,     1,     1,     3,     1,     3,     3,     1,
       1,     1,     3,     2,     3,     6,     1,     3,     1,     1,
       0,     0,     6,     0,     2,     0,     1,     1,     2,     2,
       1,     1,     4,     3,     1,     2,     5,     2,     2,     5,
       0,     2,     1,     1,     2,     6,     6,     1,     0,     1,
       2,     1,     2,     0,     2,     1,     1,     1,     1,     1,
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
     835,     0,  2229,     0,     0,     0,   884,   180,     0,   860,
     863,   178,   183,   839,     0,   833,   836,   837,   840,   843,
     844,   842,   880,   881,   883,   841,   136,   133,     0,   129,
     131,   130,   134,  2257,   716,   655,   310,  1689,  1687,   878,
     176,   186,   879,   179,     1,   845,   838,   882,   128,   132,
     135,     0,     0,   632,     0,     0,   177,   887,   953,   633,
     888,   889,   885,   667,   945,     0,   946,   954,   952,   186,
     181,   199,     0,   184,   200,   235,     0,     0,   865,  1247,
       0,     0,   864,  1235,   872,     0,     0,   857,   856,   858,
     834,   846,   847,   866,   850,   851,   852,   855,   853,   854,
     859,     0,  1688,   947,   886,     0,     0,   961,   959,   960,
     949,   948,   308,   186,  1171,   193,   187,   186,   192,   232,
       0,   715,   714,     0,     0,     0,     0,   176,   576,   894,
     848,     0,   342,   328,   202,   314,   279,   298,   319,   321,
     318,     0,   340,     0,   327,   320,   324,   330,   329,   186,
     331,   311,   334,   312,   313,   958,   957,     0,    22,    23,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   966,     0,   539,   531,    16,   538,   953,    15,     0,
     964,     0,   309,     0,   185,  1172,   182,     0,   199,   201,
     273,   204,   261,   267,   268,   252,   225,   263,   202,   240,
     241,     0,   227,   279,   298,   250,   253,   248,     0,   223,
       0,   259,   251,   256,   266,   265,   186,   269,   186,   238,
     239,   236,   272,     0,     0,     0,     0,   873,   176,   176,
       0,     0,   203,     0,     0,   332,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,   277,     0,   955,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   545,     0,     0,     0,   668,   439,   441,  1242,
       0,     0,     0,  1662,     0,   435,     0,     0,     0,   434,
       0,   449,   541,     0,     0,     0,     0,     0,   544,   402,
     408,   445,   442,   403,   404,   406,   407,   440,   443,   448,
     540,   494,   491,   500,   497,     0,     0,    17,    18,    19,
      20,    21,     0,    14,   485,     0,     0,   962,     0,   188,
     191,   189,   190,     0,   196,   195,   194,   197,   205,   206,
     207,   210,   274,   186,   274,     0,     0,     0,     0,   186,
     270,   271,     0,     0,   186,     0,   274,     0,     0,   249,
     233,  1248,     0,     0,  1236,  2263,   577,   895,   867,     0,
     214,   215,     0,     0,   291,   293,   288,   289,   285,   287,
     284,   286,   283,     0,   293,   304,   305,   301,   303,   300,
     302,   295,     0,     0,     0,   344,     0,   347,   349,   222,
       0,   221,     0,   186,     0,     0,     0,   566,   637,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   563,   549,
     554,     0,   550,   553,   552,   646,     0,   645,   568,     0,
      11,   172,   433,   410,   409,     0,  1177,     0,     0,   447,
    1670,  1668,  1669,  1665,  1667,  1664,  1666,  1658,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,     0,   669,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,   170,   546,   547,   548,   460,     0,     0,   459,
     469,     0,     0,   414,     0,     0,   415,   405,   411,   413,
     416,   417,   418,   419,   420,   412,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   965,     0,   950,   198,
       0,     0,   262,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,   186,   234,   237,   977,
     713,   890,   977,     0,  2261,  2263,  1171,  1789,   861,     0,
     977,     0,     0,   315,   280,     0,     0,   290,   307,   281,
     306,     0,   299,     0,   322,     0,   316,     0,   341,     0,
     346,   336,     0,     0,   325,   278,   335,   525,     0,     0,
     537,     0,     0,   534,   533,   536,   532,   543,   528,   528,
       0,     0,   528,     0,   551,     0,   555,     0,   298,     0,
     535,   542,   282,     0,  1243,  1729,     0,     0,     0,     0,
       0,   436,     0,     0,   450,     0,     0,     0,     0,   452,
     451,   470,   461,   476,   479,   480,   477,   483,   482,   481,
     471,   472,   473,   474,   475,   421,   462,   466,   484,   478,
     465,   484,   444,   495,   492,   501,   498,   526,     0,    98,
     486,    94,    95,    97,   488,     0,     0,   235,     0,     0,
       0,   242,   243,     0,   246,     0,     0,   254,     0,   244,
     224,   208,     0,   257,   276,   983,     0,   978,   979,   977,
       0,   874,  2262,  2260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2244,
       0,  1363,  1362,     0,  1364,     0,   398,  1361,  1278,     0,
       5,  1360,   399,   396,     0,   401,   174,   484,  1146,     0,
       0,  1370,   125,   395,   394,     0,     0,   389,   484,     0,
    1314,  2237,     0,   400,   361,     0,     3,     2,     0,   397,
    1275,     0,     0,   390,   387,   383,     0,     0,     0,     0,
    1368,  1358,   393,     0,     0,     0,     0,     0,     0,     0,
       0,  1357,     0,     0,     0,   175,     0,   386,   385,     0,
       0,  2241,  2240,     0,     0,     0,   137,     0,   392,   391,
       0,     0,   388,   484,     0,     0,   484,     0,   570,     0,
       0,     0,     0,     0,     0,   484,   822,  1245,     0,     0,
    1157,     0,  2230,     0,   105,     0,     0,   903,     0,     0,
       0,     0,   823,     0,     0,  1820,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   684,     0,     0,  2265,  2266,
    2267,  2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,
    2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,
    2287,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,
    2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,
    2307,  2308,  2309,  2310,  2311,  2312,  2313,   932,  2314,  2315,
    2316,  2317,  2318,  2319,  2320,  2321,  2322,  2323,  2324,  2325,
    2326,  2327,  2328,  2329,  2330,  1137,  1139,  1134,  1136,  1135,
    1138,  2331,  2332,  1268,  2333,  1274,  1273,  2334,  2335,  2336,
    2337,  2338,  2339,  2340,  2341,  2342,  2343,  1425,  2344,  2345,
    2346,  2347,  2348,  2349,  2350,  2351,  2352,  2264,   862,   581,
       0,   899,     0,   897,     0,   343,   216,   217,     0,   292,
     297,     0,     0,     0,     0,   345,   348,     0,   220,     0,
       0,   567,     0,   641,     0,   643,     0,   506,   504,     0,
     528,     0,   505,     0,     0,   565,     0,   562,   559,   530,
     503,   569,     0,   171,  1731,  1732,  1730,     0,   438,  1242,
       0,  1663,  1242,   437,  1242,  1242,  1242,  1242,  1242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,   963,     0,   211,   275,   226,
       0,     0,   186,     0,     0,     0,     0,     0,  1249,     0,
       0,  1237,   380,   378,   379,  1272,  1072,  1071,  1077,     0,
    1637,  1638,     0,     0,  1298,   656,   657,  1299,  1629,  1630,
    1301,   849,  1109,  1114,  2239,   649,   124,  2252,     0,     0,
    1313,     7,     0,     6,     0,  2245,  1110,     0,  1205,  1204,
    1149,  1203,  1148,   432,  1371,  1359,     0,  1269,   875,   422,
    1791,  1365,   126,     0,  1113,   123,     0,   829,    24,   651,
     384,     0,   828,  1105,   830,     0,  1369,   925,   924,   927,
     923,   926,  2254,     0,   921,     0,   650,  1009,   922,  2248,
       0,  2238,   122,  1271,  1006,   717,  1004,     0,   647,  2233,
     765,   764,   766,   762,     0,     0,  1270,  1019,   652,  1424,
       0,  2220,  1419,  1422,  2210,  2213,  2214,  2216,  2219,     0,
       0,     0,     0,  1078,  1073,     0,  1058,  1059,  1060,  1061,
    1067,  1069,  1068,  1066,  1065,     0,     0,     0,  1064,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1050,  1041,  1042,   992,     0,   990,  1092,   430,
      24,     0,  2235,   127,   648,     0,  1246,  1244,  1170,     0,
    1780,     0,  1781,  1171,  1159,  1150,  1372,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,   953,     0,    69,
       0,   103,   624,     0,   671,   670,     0,  1140,  1026,  1144,
       0,     0,  1093,  1263,     0,     0,  1147,   676,   673,   674,
       0,   678,   679,     0,   681,   682,     0,   677,   987,   989,
       0,     0,   988,   767,   985,   728,   981,   944,     0,     0,
       0,     0,   688,   689,     0,     0,   942,   939,   940,   936,
     937,   938,   931,   935,   934,     0,     0,     0,     0,     0,
       0,   585,   587,   579,   582,   583,   901,  2263,   896,   898,
     868,     0,   294,   296,   323,   317,     0,     0,   326,   638,
     640,     0,     0,     0,     0,   528,   511,     0,   528,   528,
       0,   556,     0,   291,     0,     0,  1759,  1654,  1656,  1815,
    1819,  1760,  1660,  1757,     0,     0,  1756,     0,     0,     0,
    1758,     0,     0,     0,     0,     0,     0,     0,  2220,  1655,
    1755,  1657,  1744,     0,  1733,  1735,  1739,  1742,  1770,  1813,
    1771,  1816,  2221,  2211,  1743,  1180,  1671,  1179,  1178,  1181,
    1183,  1182,  1176,   463,   464,   468,   453,     0,   456,   467,
       0,   455,   496,   493,   502,   499,   527,   487,    96,   489,
     951,     0,   247,   231,     0,   229,   255,   245,   235,   258,
     984,   176,   980,   891,   176,     0,     0,     0,  1343,  1344,
       0,     0,     0,  1315,  1318,  1320,  1321,  1322,  1326,  1325,
    1323,  1324,     0,     0,     0,  1316,  1317,     0,     0,     0,
       0,     0,     0,     0,     0,  1111,     0,    24,  1200,  1202,
    1201,     0,   425,   426,   423,   424,   997,     0,     0,   366,
      25,   360,     0,  1106,     0,  1105,     0,  1104,     0,     0,
       0,     0,     0,     0,  1013,  1790,     0,     0,     0,     0,
       0,     0,  2235,     0,     0,   138,     0,     0,  1023,  1015,
    1016,  1021,     0,     0,  2212,     0,  2223,  1420,  1421,     0,
       0,   941,   428,  2204,  1036,   350,     0,     0,   571,   629,
     628,   626,   631,  1044,   630,  1049,  1045,  1048,   821,   813,
     807,   819,   820,   805,   806,   814,   809,   815,   808,   818,
     812,   816,   811,   817,   804,   810,   797,   803,  1046,  1047,
       0,  1054,  1062,  1051,  1052,  1056,  1057,  1055,  1053,  1063,
       0,     0,     0,   831,     0,     0,     0,     0,     0,   777,
     776,   773,  2236,  2243,    24,  1166,  1167,  1168,  1169,  1163,
       0,  1161,  1259,  1171,  1151,  1152,  1155,  1173,  2231,     0,
       0,     0,     0,    99,     0,   100,     0,     0,     0,    74,
       0,     0,     0,   112,   107,     0,   672,   930,     0,   929,
       0,   484,  1142,     0,   972,   973,   996,   967,   968,   824,
     994,  1095,  1265,     0,  1267,  1266,  1876,  1992,  1988,  1994,
    2026,  2006,  1997,  1956,  1918,  2045,  2012,  2020,  1909,  2015,
    1877,  1824,  2007,  1914,  1965,  2099,  1944,  1932,  1945,  2043,
    2046,  2014,  1968,  2049,  1836,  2106,  2042,  2070,  1847,  2142,
    1933,  2115,  1829,  2075,  1845,  1904,  1951,  1971,  2065,  2093,
    2098,  1828,  2023,  2051,  1840,  1842,  1865,  1882,  1902,  1912,
    1922,  1975,  1978,  2036,  2047,  2053,  2054,  2071,  2116,  2127,
    1827,  1858,  1881,  1880,  1888,  1890,  1898,  1908,  1929,  1947,
    1950,  1976,  1984,  2040,  2050,  2060,  2066,  2067,  2069,  2094,
    2124,  2135,  1848,  1851,  1862,  1868,  1870,  1875,  1879,  1885,
    1893,  1895,  1896,  1897,  1907,  1917,  1924,  1940,  1941,  1952,
    1970,  1974,  1987,  2003,  2034,  2044,  2048,  2055,  2063,  2072,
    2082,  2086,  2103,  2109,  2113,  2121,  2126,  2129,  1871,  1989,
    2031,  1856,  1857,  1874,  1878,  1884,  1886,  1900,  1901,  1911,
    1920,  1925,  1927,  1928,  1934,  1942,  1959,  1960,  1973,  2001,
    2005,  2008,  2013,  2017,  2025,  2032,  2033,  2038,  2056,  2057,
    2062,  2068,  2073,  2079,  2080,  2081,  2083,  2085,  2087,  2096,
    2118,  2119,  2120,  2125,  2141,  1831,  1983,  1991,  1993,  2089,
    1833,  1837,  1841,  1846,  1852,  1853,  1866,  1867,  1869,  1872,
    1883,  1899,  1919,  1921,  1931,  1935,  1937,  1938,  1946,  1955,
    1957,  1958,  1969,  1982,  2000,  2018,  2019,  2035,  2037,  2041,
    2052,  2074,  2084,  2092,  2114,  2117,  2131,  2132,  2133,  1864,
    1834,  1854,  1855,  1861,  1930,  1863,  1887,  1889,  1903,  1980,
    2104,  1913,  1915,  1923,  1926,  1948,  1949,  1954,  1961,  1962,
    1963,  2144,  1995,  1996,  1999,  2004,  2009,  2016,  2021,  2022,
    2024,  2030,  2059,  2061,  2077,  2088,  2090,  2091,  2095,  2100,
    2101,  2105,  2107,  2108,  2123,  2128,  2130,  2134,  2136,  2140,
    1990,  2139,  1830,  1832,  1835,  1839,  1849,  1873,  1891,  1892,
    1894,  1905,  1936,  1939,  1979,  1985,  1998,  2002,  2137,  2138,
    2039,  2058,  2064,  2076,  2078,  2097,  2102,  2112,  2122,  1844,
    1838,  1843,  1860,  1910,  1953,  1966,  1967,  2027,  2029,  2111,
    1986,  1943,  2010,  1859,  1906,  1916,  1981,  1964,  2011,  1850,
    1972,  1977,  2110,  2028,     0,  1822,  1825,  1826,   704,     0,
       0,     0,   693,   728,   728,   725,     0,     0,   729,     0,
      26,   692,   695,     0,   702,   698,   943,   933,  1787,  1788,
    1778,  1778,  1389,     0,     0,  1690,     0,     0,  1373,     0,
       0,  1374,  1417,     0,     0,  1418,     0,     0,  1729,     0,
    1387,     0,  1436,  1435,  1434,  1432,  1433,  1431,  1429,  1426,
    1516,  1515,  1427,  1428,  1437,  1711,  1430,  1794,  1793,  1792,
    1438,  2263,  2263,   598,   589,   580,     0,   584,  2263,   900,
     176,     0,   337,   219,     0,     0,   529,     0,   528,     0,
     515,   528,     0,   508,   507,     0,     0,     0,   561,   560,
     173,  1741,  1740,  1678,  1676,  1677,  1673,  1675,  1672,  1674,
    1659,     0,  1729,     0,     0,  1584,     0,     0,  1747,  1745,
    1746,  1584,  1584,  1584,  1584,  1748,     0,     0,     0,  1533,
    1719,     0,  1736,     0,     0,     0,     0,  1803,  1804,  1805,
    1806,  1807,  1808,  1751,     0,     0,     0,     0,   458,   457,
       0,     0,   186,   228,   209,  1250,   176,  1238,     0,     0,
       0,     0,     0,     0,  1490,  1489,  1488,  1350,     0,  1356,
    1352,  1354,  1345,     0,  1593,  1342,  1338,  1312,  1311,     0,
    1337,  1333,     0,  1329,  1327,     0,  1636,     0,  1639,  1641,
     660,     0,   659,  1628,     0,  1631,  1633,  2253,  2250,     0,
       0,  1279,   484,   358,  1300,     0,     0,  1276,  1028,  1107,
    1108,  1105,  1101,  1105,     0,   928,     0,     0,   634,     0,
       0,     0,  1007,  1005,   719,   720,     0,   724,     0,     0,
    2234,  2242,   763,     0,   142,     0,  1017,  1024,     0,     0,
    1032,  2215,  2228,     0,  2226,  1423,  2218,  2217,     0,     0,
       0,  1038,   353,     0,     0,     0,     0,    24,  1074,  1075,
     574,     0,     0,     0,   798,   799,  1043,   993,   991,   832,
     431,     0,  1084,   774,   778,   775,   779,   381,     0,  1171,
    1160,  1260,  1175,  1158,  1153,     0,     0,  1154,  2263,     0,
       0,     0,     0,     0,     0,     0,    64,    93,     0,     0,
     118,   113,     0,   108,     0,   115,   109,   914,   906,   912,
       0,  1141,     0,  1143,  1145,     0,     0,   976,     0,     0,
       0,     0,  1094,  1264,     0,     0,  1821,  1823,  2263,   675,
     680,   683,   696,   694,   653,     0,   752,   750,   748,   746,
     756,   754,     0,     0,   744,   794,   742,   727,   738,   736,
     792,   768,     0,   730,   740,   986,   982,     0,     0,     0,
       0,   701,     0,     0,     0,     0,     0,     0,     0,  1644,
       0,  1511,  1512,  1799,  1469,  1533,     0,     0,     0,  1797,
       0,  1449,  1444,  1443,  1456,  1455,  1460,  1460,  1458,  1459,
    1450,  1445,     0,     0,  1451,  1452,  1712,  2146,     0,     0,
       0,   586,   588,     0,     0,   601,   593,   595,     0,   590,
     591,     0,     0,   609,   611,     0,     0,   607,   902,   869,
     218,     0,   642,   644,   639,     0,   528,   517,     0,   512,
       0,     0,   528,   528,   558,   557,     0,     0,  1768,  1660,
       0,     0,  1743,  1586,  1587,  1585,     0,  1772,     0,     0,
       0,     0,     0,     0,     0,  1734,     0,  1522,  1523,  1525,
    1528,     0,  1534,  1535,     0,     0,  1584,  1721,  1715,  1737,
    1753,  1754,  1752,  1750,     0,     0,     0,  2222,   454,   490,
       0,   230,  1206,   892,  1184,     0,     0,     0,     0,  1350,
       0,     0,     0,  1346,     0,     0,     0,  1340,  1624,  1622,
    1591,  1603,  1605,  1609,  1611,  1602,  1596,  1601,  1615,  1594,
    1623,  1599,  1614,  1600,  1621,  1613,  1496,  1588,  1589,  1590,
       0,  1335,  1331,     0,     0,  1319,     0,     0,   658,     0,
       0,     0,  2249,     0,     4,     8,    10,     0,   484,   427,
       0,     0,     0,  1025,  1103,  1102,     0,     0,     0,     0,
       0,     0,     0,     0,   718,     0,     0,   159,   157,     0,
       0,   139,     0,   149,   155,   728,   144,   146,     0,  1022,
    1033,  1034,     0,     0,  2224,   429,     0,  2205,  2206,  1037,
       0,     0,  1035,   352,   357,   636,   351,     0,   354,   359,
       0,   484,  1395,   627,   625,     0,   801,  1083,  1085,     0,
     382,  1164,  1162,     0,  1174,  1156,     0,     0,  1255,     0,
       0,     0,   101,     0,     0,    75,    81,    71,  2263,  2263,
     111,   106,   120,   116,     0,   110,   795,   915,   653,  2263,
     905,   904,   913,  1027,     0,     0,   974,   975,   969,   995,
     484,  1100,  1096,  1097,  1099,  2143,  2145,   705,   699,   697,
       0,    24,     0,  2263,  2263,  2263,  2263,  2263,  2263,   758,
     732,   760,   734,  2263,  2263,  2263,  2263,     0,   726,   731,
    2263,   653,   790,   788,   791,   789,     0,     0,    46,    44,
      41,    35,    39,    43,    38,    31,    40,     0,    34,    37,
      32,    42,    33,    45,    36,     0,    29,    47,   782,     0,
     703,  1779,     0,  1777,  1729,  1775,  1716,  1717,  1709,  1695,
    1710,     0,     0,     0,  1070,  1510,  1513,     0,     0,     0,
    1407,  1379,  1802,  1801,  1800,     0,     0,     0,  1454,  1457,
       0,     0,     0,     0,     0,  1402,     0,  1401,     0,  1403,
    1398,  1399,  1400,  1391,  1392,     0,     0,     0,   600,   605,
       0,     0,  2263,  2263,   578,   592,   615,   603,   617,  2263,
    2263,   613,   597,   608,   861,   338,   528,     0,   516,   528,
       0,   528,   528,   510,   509,  1685,  1683,  1684,  1680,  1682,
    1679,  1681,  1661,     0,     0,     0,     0,  1769,     0,     0,
       0,  1767,     0,     0,     0,     0,  1749,  1766,     0,  1526,
       0,  1653,  1529,     0,     0,     0,     0,  1521,  1539,  1541,
    1543,  1583,  1582,  1581,  1545,  1561,     0,  1536,  1537,  1724,
    1302,     0,     0,     0,  1814,     0,  1818,   212,     0,  1232,
    1251,   861,     0,  1239,  1232,     0,  1645,     0,  1478,     0,
    1481,  1648,     0,  1486,     0,     0,  1347,  1348,     0,     0,
    1351,  1353,  1355,     0,  1339,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1494,  1493,  1492,     0,  1497,
    1498,     0,  1334,     0,  1328,  1330,  1640,     0,  1642,  1632,
       0,  1634,  2251,  1308,     0,  1304,     0,     0,  1309,   876,
       0,     0,     0,     0,     0,  1366,  2256,  2255,   635,     0,
       0,    48,     0,   721,   723,   722,  1367,   728,  2263,  2263,
     151,   661,   161,   153,   163,   143,   150,  2263,     0,     0,
       0,     0,     0,  2227,     0,     0,     0,     0,     0,     0,
    1076,     0,  1396,   572,     0,   800,  1081,     0,  1261,  1262,
    2232,     0,    93,     0,    65,     0,     0,     0,    78,     0,
      93,    93,   119,   114,  2263,  2263,   104,     0,   916,   910,
     918,   917,   907,   622,   956,     0,     0,     0,   707,   686,
     700,   654,   769,     0,   753,   751,   749,   747,   757,   755,
       0,  2263,     0,  2263,   745,   743,   739,   737,   793,   741,
      24,   783,     0,     0,     0,    27,     0,  1782,     0,  1696,
       0,     0,  1708,  1691,  1707,  1514,     0,  1471,     0,  1406,
       0,     0,  1798,     0,  1795,     0,  1462,  1466,  1442,  1464,
    1467,     0,  1453,  1713,     0,     0,     0,     0,     0,     0,
    2147,  1405,  1404,  1393,  1388,  1390,  1441,     0,     0,   602,
     599,   594,   596,     0,  2263,  2263,   610,   612,  2263,  2263,
       0,   518,     0,   522,     0,     0,   514,   513,     0,     0,
       0,     0,     0,     0,  1765,  1773,  1761,  1762,  1763,  1764,
    1530,     0,  1524,  1544,  1548,     0,  1561,  1547,     0,     0,
    1562,  1577,  1574,  1575,  1572,  1580,  1579,  1573,  1576,     0,
       0,     0,     0,     0,  1578,     0,     0,     0,  1518,  1519,
    1738,     0,  1538,  1532,  1303,  1722,  1412,  1408,  1409,  1414,
    1413,  1720,  1302,     0,     0,  1230,  1231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1229,     0,
       0,  1217,  1218,  1219,  1216,  1221,  1222,  1223,  1220,  1207,
    1198,     0,     0,  1254,     0,  2263,     0,  1193,     0,     0,
       0,     0,     0,     0,     0,  1185,  1186,     0,  1115,  1649,
       0,  1650,     0,     0,     0,     0,  1485,  1484,  1350,  1483,
    1475,  1341,  1625,     0,     0,     0,     0,     0,     0,  1626,
    1618,     0,     0,     0,  1618,  1654,  1491,  1504,  1509,     0,
    1506,  1503,  1505,     0,  1507,  1495,  1499,  1500,  1350,  1336,
    1332,     0,     0,  1307,  1306,     0,  1291,     9,     0,  1281,
     877,  1112,   364,  1281,     0,     0,  2247,     0,     0,  1008,
      49,     0,   780,   160,   158,     0,  2263,     0,     0,     0,
    2263,   156,   145,     0,   148,   147,     0,  1014,  1018,     0,
    2209,  2208,  2207,     0,     0,   356,     0,   575,     0,  2263,
     802,     0,   653,  1165,     0,  1256,    70,     0,     0,   102,
      68,    93,    76,    82,     0,   121,   117,   796,  2263,   920,
     653,   919,     0,   619,     0,   826,   827,   825,  1098,   710,
     708,     0,   690,   687,     0,   759,   733,   761,   735,   770,
     786,   787,   784,   785,    30,    28,     0,  1776,  1725,  1697,
    1693,  1692,     0,  1470,  1729,  1473,     0,  1381,  1376,  1375,
    1378,     0,     0,  1461,     0,     0,  1725,     0,     0,  2184,
    2182,     0,     0,  2166,  2181,     0,     0,  2183,     0,     0,
       0,     0,     0,  2220,  2180,  2172,  2199,  2200,     0,  2164,
    2167,  2168,  2179,  2171,  2201,     0,  2157,  2156,  2160,  2162,
       0,  2155,     0,  2158,  2149,     0,     0,   606,   604,   616,
     618,   614,     0,     0,   528,     0,   528,   528,     0,  1728,
       0,  1661,     0,     0,     0,  1527,  1546,  1540,  1542,  1549,
    1551,  1549,     0,  1556,  1549,     0,  1554,  1549,     0,  1564,
    1563,     0,  1565,     0,  1517,     0,  1416,  1415,  1411,  1723,
       0,   235,  1224,  1225,  1226,  1228,  1211,  1209,  1208,  1212,
    1213,  1210,  1227,  1214,  1215,  1199,  1001,  1234,   998,     0,
       0,  1252,     0,  1197,  1196,  1191,  1189,  1188,  1192,  1190,
    1194,  1195,  1187,  1240,     0,  1476,  1482,  1652,  1645,  1487,
    1349,  1592,  1604,     0,  1606,  1608,     0,  1610,     0,     0,
       0,  1616,  1595,  1620,     0,  1477,  1479,     0,  1501,  1502,
    1643,  1635,  1305,     0,     0,  1297,  1292,  1293,  1310,     0,
    1288,  1289,     0,     0,  1302,  1282,  1283,     0,    24,  1277,
       0,     0,  1031,     0,    50,  1011,     0,    24,   162,   152,
       0,   663,   665,   164,   154,   780,     0,  2225,  1040,     0,
     355,  1397,     0,  1082,    24,     0,     0,    66,     0,    79,
      88,     0,    72,   911,   908,   623,  2263,   970,     0,  2263,
     706,   685,   691,   653,  1786,     0,  1784,     0,     0,  1698,
    1694,  1472,     0,  1474,  1468,     0,  1380,     0,  1796,  1463,
    1465,  1440,     0,  2170,  2169,     0,     0,  1584,     0,  1584,
    1584,  1584,  1584,  2173,     0,     0,  2153,     0,     0,     0,
       0,  2186,  2154,     0,     0,     0,     0,     0,     0,  2148,
    1394,  1446,   871,   870,   339,   519,     0,     0,   524,   523,
    1686,  1809,  1812,  1810,  1531,     0,  1568,  1570,     0,  1557,
    1560,  1559,  1567,     0,  1569,  1549,     0,  1520,  1410,  1817,
     213,  1003,  1002,  1000,     0,  1233,  1116,  1120,  1122,     0,
    1126,     0,  1124,  1128,  1117,  1118,     0,   893,     0,     0,
    1646,  1651,     0,     0,  1627,  1619,  1597,     0,  1598,     0,
       0,  1295,  1290,  1296,  1294,  1287,  1286,  1285,  1280,  1284,
     365,   362,     0,  1029,     0,     0,     0,  1010,   781,   140,
     662,    24,  1020,  1039,   573,  1079,    67,  1257,    84,     0,
       0,    77,    88,    88,  2263,   620,     0,     0,   709,   771,
       0,  1783,  1726,  1719,     0,  1382,     0,  1719,  2197,     0,
       0,  2202,     0,     0,     0,     0,     0,     0,     0,     0,
    2165,  2188,  2189,  2187,  2185,  2163,     0,  2159,  2161,  2150,
    2151,  1447,     0,  1439,   528,   528,  1550,  1774,  1552,     0,
    1555,  1553,  1571,     0,   999,  2263,  2263,  1130,  2263,  1132,
    2263,  2263,  1119,  1253,  1241,     0,  1607,     0,  1617,     0,
    1508,   367,  1030,  2246,     0,     0,     0,     0,     0,     0,
      55,     0,    54,     0,    52,     0,     0,   141,  1086,    88,
      93,    88,    89,    83,    73,   909,     0,     0,   711,    24,
    1785,  1718,  1727,  1386,     0,  1383,  1385,  1699,  2198,     0,
       0,  2196,     0,     0,     0,     0,     0,  2174,  2195,     0,
    1448,   521,   520,  1558,  1566,  1121,  1123,  2263,  1127,  2263,
    1125,  1129,  1647,  1612,  1480,   369,   374,   372,   363,     0,
     370,   376,    57,    62,    59,    61,    58,    60,    56,     0,
      51,     0,   664,   666,  1090,  1080,     0,  1088,  1258,    85,
      80,   621,   971,  2263,   772,     0,  1377,     0,  1700,  1714,
    2194,  2203,  2190,  2191,  2192,  2193,     0,  2175,     0,     0,
    1131,  1133,  2263,  2263,   368,   371,  2263,    53,     0,  2263,
    1087,  1089,     0,   707,  1384,     0,  1704,  1701,  1702,     0,
       0,  2152,   375,   373,   377,     0,  1091,    86,   712,     0,
       0,     0,  2177,     0,  2176,  1012,    90,     0,  1705,  1703,
       0,    92,     0,    87,     0,  2178,    91,  1706
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   828,   829,   830,   831,  1052,  2424,  2425,   181,   322,
     182,  1419,  1420,  2248,  2585,  3632,  3109,  3110,  3535,  3633,
    3634,   832,  1195,  3147,  2841,  3553,  2187,  2839,  3400,  3151,
    3549,  2840,  3401,  3640,  3742,  3766,  3551,  3773,   650,   651,
     652,  1544,  2501,   833,  1555,  1200,  1553,  2195,  2511,  2192,
    2509,  2514,  2845,  1554,  2508,  2196,  2844,   834,     9,    28,
      29,    30,    31,    32,   836,  1115,  2124,  1445,  2451,  2455,
    2456,  2452,  2453,  3116,  3120,  2807,  2799,  2798,  2800,  2803,
     496,   272,   603,   837,    55,    56,    11,    41,   114,    70,
      71,    72,    73,   197,   336,    74,    75,   243,   341,   229,
    1015,   520,  3004,   372,   938,  2311,   400,   401,   230,   354,
     343,   349,  1364,  1365,   118,   538,   119,   120,   360,   231,
     356,   342,   344,   522,   232,   257,   576,   245,   248,   246,
     247,   956,   554,   555,   557,   562,   941,   249,   250,   391,
     559,   193,    12,    51,   151,   152,   153,   947,  2940,   154,
     253,   241,   394,   395,   396,   397,  2147,   838,   839,   840,
     841,  1073,  3621,  3368,  1421,  3688,  3689,  3690,  3733,  3732,
    3736,   842,   843,   844,   845,   846,   847,   848,  1063,   497,
    1068,  1413,  1414,  1461,  1168,  1462,   299,   300,   301,   302,
     303,   454,   498,  1347,   499,   500,   501,   502,   503,   504,
     505,   992,   183,   514,  1002,  1004,  2040,   184,   508,   998,
     507,   997,   510,  1000,   509,   999,   957,   970,   304,   305,
     186,   306,   421,   422,   423,   424,   406,   426,   849,  1135,
    2150,  3139,  2482,    88,   238,   548,  1964,  1263,  1264,  1265,
    1961,  1962,  2298,  2299,  2300,  2642,  2643,  1965,  1966,  2294,
    2646,  2638,  2306,  2307,  2649,  2650,  2938,  2934,  2935,   850,
    3406,  3646,  3163,   851,  1473,    57,  2109,  2110,  2476,   407,
     428,  1107,  1173,  1044,  1095,  1078,  1117,  2541,   187,  1045,
    1035,  2081,  2802,    59,   307,   852,  1205,   853,  1218,  1219,
     854,   855,   856,   857,  1226,  3172,  1247,  3411,  1248,  2222,
    1249,  2538,  1250,  2859,  1251,  2251,   858,  2218,  2858,  3171,
    3409,  3408,  3713,    89,    13,   859,  1439,  2114,  2115,  2116,
    2241,  1909,  2242,  2243,  2871,  2873,  2556,  2555,  2560,  2554,
    2553,  2546,  2545,  2544,  2543,  2548,  2547,  2550,  2552,   860,
     861,  1113,   862,  1905,  1233,  3649,   863,  1521,  3377,  2587,
    2588,  2244,  2557,  2517,  2847,  1162,  1501,  2154,  2485,  2155,
    1497,   864,   865,  1211,  2210,  3167,   866,   867,   868,   869,
      14,    45,    15,    16,    17,    90,    91,   870,    92,    18,
     929,    19,    93,    94,   131,   550,  1970,  2654,  3463,    95,
     127,   365,   871,  2780,    20,    21,    22,    23,    24,    40,
      62,    96,   679,  2046,  2721,    97,   239,   549,   932,   933,
    1267,  1968,   872,  1206,  2521,  2199,  2519,  3554,  3158,  2200,
    2518,  2850,  3160,   873,   874,   875,  1089,  1090,  1558,   876,
    1252,  1253,   877,  1917,  1254,   308,    64,    65,    66,    67,
    1565,   157,   110,    68,   107,   189,   190,  1566,  1567,  2528,
    1568,   676,   677,  1235,   678,  1236,  1166,  1167,  1569,  1570,
    1417,  3307,  3308,  3493,  1105,  1106,   878,  1434,  3537,   879,
    3128,   880,  1449,  1450,  1451,  2130,  2128,   881,   882,  2433,
    2462,   883,  2141,  2472,   884,  1163,  1164,   885,  1028,   886,
    2598,   887,  3638,  3142,   888,  2489,  3705,  3706,  3707,  3739,
    1170,   889,  1571,  2212,  2532,  2533,   890,  1427,  2101,  1043,
    1406,   891,   892,   893,  2723,  3311,  3504,  3505,  3605,  3606,
    3610,  3608,  3611,  3677,  3679,   894,   895,  1560,  2204,   896,
    1562,  1533,  1534,  1535,  2177,   897,  1185,  1183,   898,   899,
    2169,  1529,  1179,   196,  1536,  1537,   309,  2724,  3045,  3046,
    3029,  1060,  1061,  2719,  3030,  3033,    98,   126,   542,  1374,
    2374,  3047,  3508,   436,   900,  1177,    99,   123,   539,  1371,
    2372,  3034,  3506,  2720,  1199,  2832,  3396,  3639,  2172,   901,
     902,   903,   904,   905,  1076,  2431,  1054,  2427,  3364,  3365,
    3366,  3521,  3355,  3356,  3357,   906,  2995,  2774,  2775,  2777,
    2065,   907,   908,  1383,  1384,  1385,  2074,  2413,  1386,  2410,
    2071,  1387,  2386,  2066,  1388,  1389,  1390,  2378,  2383,  1391,
    2060,  2061,   909,  1085,  1065,   910,  1942,  1943,  2266,  3199,
    3427,  2901,  3196,  3654,  3655,  1944,  2288,  1923,  2634,  2924,
    3245,  2823,  3138,  2635,  1945,  1946,  2357,  2997,  2998,  2999,
    3288,  1947,  1948,  1458,   911,  1122,   912,  1260,  1949,  1950,
    2282,  3593,  2283,  2284,  2285,  2618,  2905,  2908,  2909,  1951,
    2608,  2896,  3424,  2054,  2055,  3084,  2727,  3345,  2728,  2056,
    2732,  2067,  2759,  2068,  2760,  3085,  3086,  3087,  3088,  1952,
    2260,  2261,  2605,  1953,  2992,  2707,  2988,  2352,  2019,  2347,
    2348,  2349,  2961,  2020,  2353,  2708,  2993,  2697,  2698,  2699,
    2700,  2701,  3476,  3269,  3596,  2702,  3478,  3479,  2986,  2703,
    2987,  2704,  2336,  2406,  2407,  2408,  3339,  2409,  3063,  3070,
    3515,  2729,  1032,  2910,  3051,  3238,  2731,  2692,  1320,   310,
    1321,  2000,   447,   448,  2001,  2672,    39,   913,   914,  3191,
    3420,  2889,  3419,  3719,  3747,  3748,  2893,  2599,  1954,  2600,
    2623,  3206,   606,  2595,  2596,  2358,  2710,  3418,  3195,  1322,
     977,  1323,  1324,  2989,  2705,  1326,  1327,  2338,  3598,   915,
     916,  2253,  2597,  3187,  3415,  3416,  1920,   917,  1071,  1956,
    1957,  2270,  2903,  1958,  1959,  2614,  2033,  2331,  1328,  1329,
    1330,  1331,   918,  1214,  1894,  1895,  1896,  2214,  1897,  2215,
    1960,  2624,  3244,  3459,  2920,  3241,  3242,  3243,  3240,  3228,
    3229,  3230,  3231,  3232,  3233,  3572,   919,  2139,  2467,  2468,
    1123,  1332,  1333,  1125,  1126,  1127,  1334,  1128,  1456,  2133,
    2134,    25,   921,  1187,  2178,  1442,  1523,   922,   923,  2791,
     924,  2422,  1048,  2088,   925,   926,    35,   543,   544,   545,
     546,   547,   927
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2977
static const short yypact[] =
{
     828,   813, -2977,   220,   220,  1288, -2977, -2977,  1288, -2977,
      21, -2977, -2977, -2977,   396, -2977,   828, -2977, -2977, -2977,
   -2977, -2977,    16, -2977, -2977, -2977, -2977, -2977,   453,   468,
   -2977,   598, -2977, -2977, -2977, -2977, -2977, -2977,  -122, -2977,
     602,   172, -2977, -2977, -2977,  1580, -2977, -2977, -2977, -2977,
   -2977,   -60,   220, -2977,   220,   349,    21, -2977,   793, -2977,
   -2977, -2977, -2977, -2977, -2977,   973,   223, -2977, -2977, -2977,
     894,   510,   220, -2977, -2977,   945,   220,   220, -2977, -2977,
     220,   220, -2977, -2977, -2977,   220,   220, -2977, -2977, -2977,
   -2977,  1580, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,  6434, -2977,   223, -2977,   336,  3798, -2977, -2977,   592,
   -2977, -2977,   953,   172,   589, -2977, -2977, -2977, -2977, -2977,
   10299, -2977, -2977,   220,   624,   962,   220,    21, -2977, -2977,
   -2977,   220, -2977, -2977,   766,   675,   647, -2977, -2977,   685,
   -2977,   700, -2977,   662, -2977, -2977,   707, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977,   723, -2977, -2977,
   -2977,   735,   759,   801,   805,   845,   854,   873,   891,   901,
     935,   971,  3798,   982,  5464,   985,   993,   997,  1004,  1007,
    1023,  1856,  1497, -2977, -2977, -2977, -2977,   877, -2977,   122,
   -2977,  3798, -2977,   154, -2977, -2977, -2977,   136, -2977, -2977,
   -2977,   934, -2977, -2977, -2977, -2977, -2977, -2977,   766,  1059,
    1074,  1082, -2977,   647, -2977, -2977,  1101, -2977,  1106, -2977,
    1092, -2977, -2977,  1110, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,  1117,  1585,   220,  1123, -2977,    21,    21,
    1178,   220, -2977,   -43,  1649, -2977,  1001,   820, -2977,  1008,
    1034,  1663,  1684,   220,  1697,  1710, -2977,  1068, -2977,   287,
      52,    52,    52,    52,    52,  5464,  1690,  1548,    65,  5464,
    1045,  5464, -2977,  5464,  5464,  5464, -2977, -2977, -2977,  1172,
    1268,  1269,  5464,  1180,  1271, -2977,  5464,  5464,  1274, -2977,
    1275, -2977,   993,  1284,  1285,  1286,  1290,  1748,  9371, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1302, -2977,
   -2977, -2977, -2977, -2977, -2977,   287,   287, -2977, -2977, -2977,
   -2977, -2977,  3798, -2977, -2977,   220,  3798,  1280,   134, -2977,
   -2977, -2977, -2977,  1754, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977,  1299, -2977,  1299,   -43,  1759,  1766,  1773, -2977,
   -2977, -2977,  1774,  1776,   172,  1697,  1299,  1777,  1133, -2977,
    1693, -2977,  1363,  1329, -2977,  1399, -2977, -2977, -2977,  1140,
   -2977, -2977,  1790,  1373, -2977,  1338, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,  1034,  1338, -2977, -2977, -2977, -2977, -2977,
   -2977,  1342,   146,   202,   257, -2977,  5379, -2977, -2977, -2977,
    1354,  1829,   211, -2977,  1393,  1361,   212, -2977,  -155,  1411,
    1414,   219,   231,  8391,  1419,  1422,   106,  1219, -2977, -2977,
      98,  1434, -2977, -2977, -2977, -2977,   267, -2977, -2977,  8434,
   -2977,  3971,  7716,  2850,  2850,  5464, -2977,  1359,  5464,  9371,
    1400, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1207,  1866,
    8456,  9371,  1359,  1868,   436,  5464,  5464,  5464,  5464, -2977,
    5464,  5464,  5464,  5464,  5464,  5464,  5464,  5464,  5464,  5464,
    5464,  5464,  5464,  5464,  5464,  5464,  5464, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977,  5464,  5464, -2977,
   -2977,  1406,  5464, -2977,  5464,  1417, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,   287,  5464,  5464,  5464,
    5464,  1455,  1897,  1856,  4352,  1428, -2977,  3798,  1401, -2977,
    1239,  1887, -2977,  1244, -2977,  1890,  1471,  1472,   289,  1613,
     353,   402,   258,  1449, -2977,   414, -2977, -2977, -2977,   220,
   -2977, -2977,   220,  1513, -2977,  7417,   589,  7720,  1902,   328,
     220,  1914,   -54, -2977, -2977,   820,  1909, -2977, -2977, -2977,
   -2977,  1911, -2977,  1912, -2977,  1913, -2977,   220, -2977,   220,
   -2977, -2977,  1697,  1915, -2977, -2977, -2977, -2977,   220,    52,
   -2977,  3798,    67, -2977, -2977, -2977, -2977, -2977,   820,   820,
    1917,  -151,   820,  1356, -2977,  1918,  1304,  1379, -2977,    65,
   -2977, -2977, -2977,  1500,  9371,   550,  1501,  8501,  1925,  1180,
    1506, -2977,  1507,  1508, -2977,  8701,  8760,  8808,  9005,  9451,
    9615,  7716,  5017,  4187,  9678,  9700,  3175,  3883,  4297,  5752,
    2850,  2850,  4103,  4103,  2808,  9371,  9067,  9177,  1359,  9371,
    9264,  1359, -2977,  9371,  9371,  9371,  9371, -2977,  1930, -2977,
   -2977,  1956, -2977,  9371, -2977,   183,  3798, -2977,  1516,  1947,
     -54, -2977, -2977,  1942, -2977,  1486,  1946, -2977,  1948, -2977,
   -2977, -2977,  1951, -2977, -2977,  1309,  1527,  1976, -2977,   220,
    1536, -2977, -2977, -2977,   287,   287,   287,   220,   481,   220,
    1389,   244,   244,  1404,   220,   220,   244,   244,   220, -2977,
    1389, -2977, -2977,   220, -2977,   961, -2977, -2977, -2977,   244,
   -2977, -2977, -2977, -2977,   220, -2977, -2977, -2977, -2977,   126,
     126,  5464, -2977, -2977, -2977,  1404,  1404, -2977, -2977,   244,
   -2977, -2977,   244, -2977, -2977,   220, -2977, -2977,   244, -2977,
   -2977,   287,   244, -2977, -2977,  5464,   244,   287,   220,   287,
     244, -2977, -2977,   206,   244,   244,   206,   244,   220,   206,
     244, -2977,   244,   244,   244, -2977,  1389, -2977, -2977,   287,
     244, -2977, -2977,   244,    43,   220, -2977,  1404, -2977, -2977,
     244,   626, -2977, -2977,   287,  1306, -2977,   244, -2977, 10106,
     287,  5464,    52,    52,   244, -2977, -2977,   481,   287,   210,
   -2977,  5464, -2977,   471,  5464,   244,    85, -2977,  5464,   244,
    1960,   287, -2977,   244,  5464, -2977,  5464,   126,   220,   244,
     220,    52,   244,   220,    52, -2977,   220,   194, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977,   521, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1150, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,   679,
     220, -2977,   570, -2977,  1541, -2977, -2977, -2977,  1632, -2977,
   -2977,  1544,  1547,  1549,  1551, -2977, -2977,  1331,  1993,  1558,
    1561, -2977,   382, -2977,  1525, -2977,  1334, -2977, -2977,   457,
     820,  1983, -2977,  1566,  -126, -2977,  1990, -2977,  1376, -2977,
   -2977, -2977,  1347, -2977, -2977, -2977, -2977,  9931, -2977,  1172,
    1573, -2977,  1172, -2977,  1172,  1172,  1172,  1172,  1172,  2001,
    2002,  2003,  5464,  1583,  2005,  5464,  1593,  1595,  1596,  1598,
    1606,  1607,  1608,  4352,  4352, -2977,   224, -2977, -2977, -2977,
    1705,  1610, -2977,  1612,  1617,  1390,  1618,   220, -2977,   220,
    1621, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,   478,
    1397,  -279,  1303,  1587, -2977, -2977, -2977, -2977,  1410,  -226,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  2063,  1396,
   -2977, -2977,  1603, -2977,  1404, -2977,  1553,   242, -2977, -2977,
   -2977,  1555, -2977,  9371, -2977, -2977,  1436, -2977, -2977,  4989,
   -2977, -2977, -2977,   287, -2977, -2977,  1404, -2977,   -35, -2977,
   -2977,  1782, -2977,   142, -2977,  1574, -2977, -2977, -2977, -2977,
    2098, -2977, -2977,   623, -2977,  1435, -2977,  1437,  2098, -2977,
    1461, -2977, -2977, -2977,  1636,    96, -2977,  1609, -2977,  1413,
   -2977, -2977, -2977, -2977,  1415,   633, -2977,  -244, -2977,  1456,
    1421,  1594,  1744,  1465, -2977, -2977,  1463, -2977, -2977,  5464,
     102,   907,  5464, -2977,   107,   244, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977,    82,    82,    82, -2977,    82,
    2145,    82,    82,  1481,   -35,  1481,  1481,   926,   926,  1481,
    1481,   -35, -2977,  2133, -2977,  1669,   490, -2977,  2134, -2977,
     -35,    70,    62, -2977, -2977,  5464, -2977, -2977, -2977,  1241,
   -2977,   944, -2977,   589, -2977,  5464, -2977,  5464,  1661,  1662,
    1665,  1667,  1458,  1670,   944, -2977,  1746,  1138,  1511, -2977,
    1524, -2977, -2977,   220, -2977, -2977,  1032, -2977,  2147, -2977,
    2150,   220, -2977,    72,  6776,  1532, -2977, -2977,  2162, -2977,
    1459,  2162,  2166,  1462,  2162,  2166,  5464,  2162, -2977, -2977,
     242,   287, -2977, -2977,  1701,   316, -2977, -2977,  1695,   287,
    5464,  1696, -2977, -2977,  2158,  2159,  2068, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977,  1081,  1081,   244,   244,   244,
    1805, -2977, -2977,  2046,   679, -2977, -2977,   574, -2977, -2977,
   -2977,  1680, -2977, -2977, -2977, -2977,  6434,  1697, -2977, -2977,
    1521,   220,   820,  2167,   -41,   820, -2977,     5,   820,   820,
    1473,  1556,  1496, -2977, 10127, 10127, -2977,  1456, -2977, -2977,
   -2977, -2977,  1216, -2977,  9625,  1711, -2977,  1712,  1715,  1716,
   -2977,  1716,  1716,  1717,  1721,  1726,  1727,   220,   541, -2977,
   -2977, -2977, -2977,   143, -2977,    69,  1901, -2977, -2977,  1216,
   -2977,  1216,  1741, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,  9371,   444, -2977, -2977,
     447, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,  1704, -2977, -2977,   450, -2977, -2977, -2977, -2977, -2977,
   -2977,    21, -2977, -2977,    21,   848,   140,  2190, -2977, -2977,
     617,   196,   648,  2212, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977,   220,  1503,   220, -2977, -2977,  1510,   220,  1528,
     220,   220,  1404,  1571,  1736, -2977,  1737,    94, -2977, -2977,
   -2977,  1404, -2977, -2977,  2216, -2977, -2977,  1546,  1742, -2977,
   -2977, -2977,   907, -2977,  1137,  2177,  1137, -2977,   944,   206,
    5464,  5464,  5464,  1743, -2977, -2977,   287,   287,  1404,  1550,
     944,    52,  1515,    43,   287, -2977,  1557,  5464,  1825, -2977,
   -2977,  1626,   220,  1456, -2977,  3798, -2977, -2977, -2977,   220,
    1236,  2231, -2977, -2977,  1569,    88,   242,   287, -2977, -2977,
    2220,  2221, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
     683, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   10106,   287,   287, -2977,   926,  5464,  -114,  1089,  1096, -2977,
   -2977, -2977, -2977, -2977,   111, -2977, -2977, -2977, -2977,  2034,
    1796, -2977,  1807,   589,  5464, -2977,    90, -2977, -2977,   220,
    2218,    52,    52, -2977,  1611, -2977,    65,  1572,   287, -2977,
     220,   220,  5464,   -87, -2977,  1623, -2977, -2977,   279, -2977,
    1720, -2977,  1730,  5464,  1039, -2977, -2977,  1597, -2977,  2260,
   -2977,  1668, -2977,   287, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977,  6060, -2977, -2977, -2977, -2977,   220,
      52,    52,   250,   316,  2062,  3206,   287,   242, -2977,  1672,
   -2977, -2977,  2231,  2245,  1819, -2977, -2977, -2977, -2977, -2977,
    1896,  1896, -2977,   104,  1676, -2977,   220,  1404, -2977,  1404,
    1404, -2977, -2977,  1404,  1404, -2977,   220,  1226,   550,  1404,
   -2977,  1226, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,   162,   162,   774,   930, -2977,   951, -2977,   574, -2977,
      21,  2250, -2977, -2977,  1292,  1833, -2977,   157,   820,  2255,
   -2977,   820,  1542, -2977, -2977,  1836,  1837,  1552, -2977, -2977,
   -2977,  1745,  1745, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,  1614,   550,  1838,  9997,   671,  9931,  1762, -2977, -2977,
   -2977,   671,   671,   671,   671,  1615,  9931,  9931,   221,  1714,
     630,   220, -2977,  9931,  9931,  9931,  9931, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977,  1616,  -160,   907,  5464, -2977, -2977,
    1843,  2250, -2977, -2977, -2977, -2977,    21, -2977,  1812,  1813,
    1814,   738,  1818,  1820, -2977, -2977, -2977,  2193,   220, -2977,
    2300, -2977, -2977,   322,  4052, -2977, -2977, -2977, -2977,   220,
   -2977, -2977,   322,  1591, -2977,   478, -2977,  1640, -2977,  1678,
   -2977,  1861,   223, -2977,  1651, -2977,  1679, -2977,  1728,  1842,
     220, -2977, -2977, -2977, -2977,  4989,   220, -2977,  1681, -2977,
   -2977,  2177, -2977,  2177,  1652, -2977,  2325,  2326, -2977,  2337,
    1713,  5464, -2977, -2977,  2341, -2977,  1685, -2977,  1815,  1675,
    2166, -2977, -2977,  1688,  1112,   220, -2977, -2977,  1872,   244,
     917,  1463,  1856,   312, -2977, -2977, -2977, -2977,  5464,  1404,
     907,  -233, -2977,   220,   220,  5464,    44,   -35,  2356,  1249,
    2357,  2340,  2342,  2145, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,   287,  1994, -2977, -2977, -2977, -2977,  2251,  5464,   589,
   -2977,  2097, -2977, -2977, -2977,  5464,   126, -2977,  2000,  2366,
    2370,   456,   458,   220,  1937,   944, -2977,  4352,  1904,  1907,
   -2977, -2977,  1969, -2977,  5464,    39, -2977,  1747, -2977, -2977,
     247, -2977,  5464, -2977, -2977,  1719,   336, -2977,  1297,   220,
    2377,  9768, -2977, -2977,   907,   287, -2977, -2977,    47, -2977,
    2166,  2166,  1686, -2977,  1797,  1800, -2977, -2977, -2977, -2977,
   -2977, -2977,    52,    52, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977,  3256, -2977, -2977, -2977, -2977,    52,  5506,  2395,
    2375, -2977,   944,   288,   340,   129,  2249,   -22,   481, -2977,
     583, -2977, -2977, -2977,  1920,    60,  1404,   217,  1735, -2977,
    1731, -2977, -2977, -2977, -2977, -2977,  1924,  1924, -2977, -2977,
   -2977, -2977,  1811,  1734,  2413, -2977, -2977, -2977,   492,  1749,
    1751, -2977, -2977,   287,   144, -2977, -2977, -2977,  1755,   930,
   -2977,   220,   220, -2977, -2977,   220,   564, -2977, -2977, -2977,
   -2977,  1952, -2977, -2977, -2977,   364,   820, -2977,   454, -2977,
    1975,  1979,   820,   820, -2977, -2977,  1231,  9931, -2977,   411,
    2427,  1991,  2431, -2977, -2977, -2977,  9931, -2977,   459,  9931,
    9931,  9931,  9931,   220,   460, -2977,   386,  2433, -2977, -2977,
     220,  5759, -2977,  2025,   220,  1779,   671,  2064, -2977, -2977,
   -2977, -2977, -2977, -2977,  1231,  2424,  1231, -2977,  9371, -2977,
    1973, -2977,  1940, -2977,  1941,   117,   117,   117,   465,  2193,
     117,  5759,   220, -2977,   466,   220,   469, -2977, -2977, -2977,
    1972,  1974,  1977,  1216,  1216, -2977,  1978, -2977,  1980,  1981,
    1982,  1985, -2977, -2977, -2977, -2977,   919, -2977, -2977, -2977,
     472, -2977, -2977,   482,   220, -2977,   220,  1605, -2977,   220,
    1656,  5464, -2977,   220,  2451, -2977, -2977,   322, -2977, -2977,
    1787,   322,   200, -2977, -2977, -2977,   944,  5464,  5464,  5464,
    5032,  2454,  1404,   184, -2977,   944,   220, -2977, -2977,   220,
     220, -2977,  1103, -2977, -2977,   409, -2977,  1795,  5464, -2977,
   -2977, -2977,  2461,  3798,  1959, -2977,  1801,  2468, -2977, -2977,
     944,  1848, -2977, -2977, -2977, -2977, -2977,   220,  2166, -2977,
     242, -2977,  1873, -2977, -2977,   489, -2977, -2977, -2977,   287,
   -2977,  8197, -2977,  1109, -2977, -2977,  2099,  2456, -2977,  2079,
    2082,  1984,  1821,  2083,  2006, -2977, -2977, -2977,   580,  2069,
   -2977, -2977, -2977, -2977,  1969, -2977, -2977, -2977,   214,   799,
   -2977, -2977, -2977,  2231,  5464,  2007, -2977,  1986, -2977, -2977,
   -2977, -2977,  2488, -2977, -2977, -2977,  2491, -2977,  1798, -2977,
    2472,   -35,   220,  4456,  4456,  4456,  4456,  4456,  4456, -2977,
    2494, -2977,  2500,  4456,  4456,  4456,  4456,   683, -2977, -2977,
    4456,   105, -2977, -2977, -2977, -2977,  2481,  2493, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977,  2498, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977,   496, -2977, -2977, -2977,  2487,
   -2977, -2977,  1404, -2977,   550, -2977, -2977, -2977, -2977, -2977,
   -2977,  1867,  1875,   226, -2977,   583, -2977,   117,  1855,   244,
   -2977,  2041, -2977, -2977, -2977,   220,   220,   117, -2977, -2977,
      95,  1404,  1113,  9931,   178, -2977,  5464, -2977,  5464, -2977,
   -2977, -2977, -2977, -2977,  1921,   244,    95,  1404,  2520, -2977,
     287,   220,   941,   941, -2977, -2977,  2522, -2977,  2522,   601,
     601,  2522, -2977, -2977,  1902, -2977,   820,  2503, -2977,   820,
    1666,   820,   820, -2977, -2977,  2047, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,   143,  1216,  1857,  1216, -2977,  1216,  2086,
    9931, -2977,  2087,  2089,  2090,  2091, -2977, -2977,   221, -2977,
     221, -2977, -2977,  9555,  1716,  1939,  1716,  2532,  2533, -2977,
   -2977, -2977, -2977, -2977, -2977,   185,  9931, -2977,  2042, -2977,
    2219,   166,   340,   220, -2977,  2100, -2977, -2977,  1432,    53,
   -2977,  1902,  1600, -2977,    53,  1404,   664,  2101,  2538,  1874,
   -2977, -2977,   497, -2977,   513,   738, -2977, -2977,   517,   127,
   -2977, -2977, -2977,   322, -2977,  2518,  2518,  2523,  1871,   540,
    2524,  2525,  2526,  2524,  2524, -2977, -2977, -2977,   160, -2977,
     821,   220, -2977,   322, -2977, -2977, -2977,  1882, -2977, -2977,
    1883, -2977, -2977,  -271,   522, -2977,   220,   524, -2977,  5464,
    2109,  2536,   533,   944,  2552, -2977, -2977, -2977, -2977,  5464,
    1944,  2230,  5464, -2977, -2977, -2977, -2977,   409,  1301,  1301,
    2554,   371, -2977,  2555, -2977, -2977, -2977,  1301,   220,  1965,
    1332,  2559,   220, -2977,  3798,   188,  1404,  2557,   944,  -162,
    2356,  5464, -2977, -2977,  2145, -2977,  1847,  5464, -2977, -2977,
   -2977,  2563,  4352,   287, -2977,   961,   220,   287, -2977,  2123,
    4352,  4352, -2977, -2977,   580,  2069, -2977,   683, -2977, -2977,
    1157, -2977, -2977,  1949, -2977,  3798,  5270,  9768,    48,   939,
   -2977, -2977, -2977,  1899, -2977, -2977, -2977, -2977, -2977, -2977,
      52,  4456,    52,  4456, -2977, -2977, -2977, -2977, -2977, -2977,
     -35, -2977,  1198,  1238,  5506, -2977,  2125,  2092,  9931, -2977,
     129,   129, -2977, -2977, -2977, -2977,   544, -2977,  2050, -2977,
     117,   779, -2977,  1903, -2977,   545, -2977, -2977,  2569, -2977,
   -2977,  1987, -2977,  2573,  4710,  4710,  4710,  4710,   117,   117,
   -2977, -2977, -2977, -2977, -2977, -2977,  2569,  1905,   287, -2977,
    2522, -2977, -2977,   220,   601,   601, -2977, -2977,   601,  2316,
    1908, -2977,   531, -2977,  2138,  2140, -2977, -2977,  2561,  2142,
    1916,  1231,  1919,  1923, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,   546, -2977, -2977, -2977,   190,   156, -2977,  5759,  5759,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, 10127,
   10127,  2107, 10127,  2111, -2977, 10127,   368,  9931,  2590, -2977,
   -2977,  5759, -2977, -2977, -2977, -2977, -2977,  2592, -2977,   284,
   -2977, -2977,  2219,  1926,  1931, -2977, -2977,   126,   126,   126,
    2576,   126,   126,   126,   126,   126,   126,  2580, -2977,  2582,
     126, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1432,
   -2977,   287,  1938, -2977,  2110,  2316,  2586, -2977,  2594,  2589,
    2595,  2597,  2599,  2600,  1184,  1600, -2977,  2110, -2977, -2977,
    2601, -2977,  2278,   117,  1386,   117, -2977, -2977,  2193, -2977,
   -2977, -2977, -2977,  2183,  2184,   548,  1231,  2606,  1231, -2977,
    2630,   552,  2197,  2198,  2630, -2977, -2977, -2977, -2977,  1404,
   -2977, -2977, -2977,  2163, -2977, -2977,   821, -2977,  2193, -2977,
   -2977,   220,   220, -2977, -2977,   220,  -319, -2977,   322,   112,
    2231, -2977,  2129,   112,   133,   944, -2977,  2645,  2169, -2977,
   -2977,  2207,  2052, -2977, -2977,   220,  1301,  3798,  1395,   220,
    1301, -2977, -2977,    52, -2977, -2977,  5464, -2977, -2977,   313,
   -2977, -2977, -2977,   944,  2648, -2977,    52,  2231,   287,  2363,
   -2977,  2632,  1797,  9371,  2634, -2977, -2977,   242,  2181, -2977,
   -2977,  4352, -2977, -2977,  2215, -2977, -2977, -2977,   799, -2977,
    1797, -2977,  5464, -2977,   319, -2977,  2134, -2977, -2977, -2977,
   -2977,  2170,  2262, -2977,  2644, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,   220, -2977,   124, -2977,
   -2977, -2977,   117, -2977,   550,  2469,   553, -2977, -2977, -2977,
   -2977,   220,   117, -2977,    95,    95,  2061, 10245, 10245, -2977,
   -2977,  1752,  2185, -2977, -2977,  2186,  2187, -2977,  2188,  2189,
    2191,  2192,   220,   563, -2977, -2977, -2977, -2977,   555, -2977,
   -2977,  2112, -2977, -2977, -2977,   556,  2662,  2662, -2977, -2977,
     560,  2668,  2664, -2977,    81,   287,    95, -2977, -2977, -2977,
   -2977, -2977,  2411,  6434,   820,  1700,   820,   820,  2233, -2977,
    1231,  2234,  1231,  1231,   221, -2977, -2977,  2533, -2977,  2195,
    1901,  2195,   363, -2977,  2195,   363, -2977,  2195, 10127, -2977,
   -2977,  9931, -2977,  9931,  2532,   166, -2977, -2977, -2977, -2977,
    1231, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,   520,  2676, -2977,   287,
    1554, -2977,  2411, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977,   365, -2977, -2977, -2977,  2172, -2977,
   -2977, -2977, -2977,  2658, -2977, -2977,  2240, -2977,  2665,  2248,
    2671, -2977, -2977, -2977,  2254, -2977,  2222,  5759, -2977, -2977,
   -2977, -2977, -2977,   220,  2675, -2977,  -319, -2977, -2977,  2680,
   -2977, -2977,  2681,   220,  2219,   112, -2977,    52,   -35, -2977,
    2273,   944, -2977,  5464, -2977,  2095,  2685,   -35, -2977, -2977,
     408, -2977, -2977, -2977, -2977,   116,  2270, -2977, -2977,   944,
    2166,  2491,  2425, -2977,   -35,  2272,  2274,  2356,  2238, -2977,
    2323,  2279, -2977, -2977, -2977, -2977,  2432,  2217,  5464,  2236,
   -2977, -2977, -2977,  1797, -2977,   565, -2977,   287,  2128, -2977,
   -2977, -2977,  9931, -2977, -2977,   117, -2977,  2247, -2977, -2977,
   -2977,  2569,  2128,  1929,  1929,  2286,  9997,   671, 10039,   671,
     671,   671,   671,   415, 10039,  4710, -2977, 10039, 10039, 10039,
   10039, -2977, -2977,   117,  2719,   117,  4710,   244,  5759, -2977,
    2491,   108, -2977, -2977, -2977, -2977,  2288,  2289, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977,   160, -2977, -2977,   566, -2977,
   -2977, -2977, -2977,   573, -2977,  2195,  2731, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977,   287,  2676, -2977, -2977, -2977,   287,
   -2977,   287, -2977, -2977,  1029, -2977,  2446, -2977,  2448,  2717,
   -2977, -2977,  2296,  2067, -2977, -2977, -2977,  2299, -2977,   117,
     228, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977,   944, -2977,  2301, 10448,  2263, -2977, -2977, -2977,
    2078,   -35, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  2304,
     242, -2977,  2323,  2323,   799, -2977,  3798,  2124, -2977, -2977,
     220, -2977,  2491,   630,   143, -2977,  9887,   630, -2977,  2307,
   10039, -2977,   584, 10039, 10039, 10039, 10039,  2728,   220,   586,
   -2977, -2977, -2977, -2977, -2977, -2977,  2280, -2977, -2977, -2977,
    2532, -2977,   220, -2977,   820,   820, -2977, -2977, -2977,   249,
   -2977, -2977, -2977,  9931, -2977,  1895,  1895, -2977,  1895, -2977,
    1895,  1895, -2977, -2977, -2977,  2282, -2977,  1231, -2977,   593,
   -2977,  1151, -2977, -2977,    82,    82,    82,    82,    82,    82,
   -2977,  2732, -2977,   594, -2977,  5464,  1424, -2977,   -62,  2323,
    4352,  2323,  2356, -2977, -2977, -2977,  2467,   366, -2977,   -35,
   -2977, -2977, -2977, -2977,   610, -2977, -2977,  1323, -2977,  2318,
   10039, -2977,  2319,  2320,  2321,  2322,   378,  2258, -2977,  4710,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1895, -2977,  1895,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1277,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, 10448,
   -2977,  2765, -2977, -2977, -2977, -2977,   789, -2977, -2977, -2977,
   -2977, -2977, -2977,    47, -2977,  9887, -2977,  1702, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,  2745, -2977,  2746,   615,
   -2977, -2977,  1328,  1328, -2977, -2977,  1328, -2977,  5464,   857,
   -2977, -2977,  2328,    48, -2977,  2104,  2105,  2772, -2977,  2302,
     389, -2977, -2977, -2977, -2977,  2333, -2977, -2977, -2977,   220,
     220,  1702, -2977,  2757, -2977, -2977,   168,  2114, -2977, -2977,
    2308, -2977,   242, -2977,   220, -2977,  2356, -2977
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2977, -2977, -2977, -2977, -2977,   -49, -2977,    12,  -169, -2977,
   -2977, -1155,    -4, -2977, -2977, -2168, -2977, -2977, -2977, -2977,
    -910, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2143, -2977,  -985, -2977,
    1789, -2977, -2977, -2977, -2977, -2977, -2977, -2977,   276, -2977,
   -2977, -2977, -2977,  1240, -2977,   599, -2977, -2977,   -23, -2977,
   -2977,  2766, -2977,  2767, -2977, -2977, -2977, -2977, -2977,   350,
     -11, -2977,   347, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977,  -104,   924,   367, -2977, -2977,  2447,
     -51, -2977,  2687, -2977, -2977,  2686, -2977,  2596, -2977, -2977,
   -2977, -2977, -2977,  2457,  2146,   767,  2455,  -509, -2977, -2977,
   -2977, -2977, -2977,   769,  -649, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,   870, -2977,  2591,  2284,  2603,    26,  2224,
   -2977,  -202,  1531, -2977,  2434, -2977, -2977, -2977, -2977,  2444,
   -2977, -2977, -2977, -2977,  -392, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,  2261, -2977,  2266, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -1365, -2977, -2977,  -860, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  -128, -2977,
   -2977,   736, -2977, -1100, -1168,  -348, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,  1841, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,  -541, -2977, -2977, -2977, -2977, -2977,  2035, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,  -561, -2977,  -100, -2977,
   -2977, -2977, -2977,  2420, -2977, -2977,  -247, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1575,
   -2977, -2977, -2977, -2977,   542, -2977, -2977, -2977, -2977, -2977,
   -2002, -2977, -2977,   534, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -1108,  -867,   403,   699, -2977,  -248,
    -563,   549, -1123,  1063, -2977,   849, -2977, -2464,    -3,   216,
   -2977, -2977, -2385,   306,  1674, -2977, -2977, -2977,   690,   949,
   -2977, -2977, -2977, -2977, -2977, -2977,    -7, -2977,  -315, -2977,
     957, -2977,   631, -2977,   324, -2977, -2977, -2977, -2977,  -883,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,   421, -2977,
   -2977, -1851, -2977,   622, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977,  1423, -2977, -2977, -2977, -2977, -2977, -2977,  -520, -2977,
   -2977, -2077, -2977, -2977, -2977, -2977,   431, -2241, -2977, -1125,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977,  2852, -2977, -2977, -2977,  2782,  2834,
   -2345, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  -437, -2977,
   -2977, -2977, -2977, -2977,  2837, -2977, -2977,  2856, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  1950,
   -2977, -2977, -2977, -2977, -2977,   681, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,  -645,  2127, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977,  2716, -2977, -2977,   -14, -2977,
   -2977,   677, -2977, -2977,  1320,  -167,  2564, -2977, -2977, -2977,
   -2977,   582, -2977, -1048,  1876,   980, -1438,  1380, -2977,   682,
    1671,  -416,  -600, -2977,  2115,  1464, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,  1398, -2977,  -770, -2977,
    -630, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  -810, -2977,
   -2977, -2977, -2977, -2977, -2977,    46, -2977, -1349,  1474,  -342,
   -2977, -2977, -2977, -2977, -2977,  -142, -2977,  -598, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,  1375, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,  -511, -2977,   742,  2464, -2977, -2977,  -135,
   -2977,  -699, -2977, -2977,  -110,   197, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977,   866, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  -183, -2977,
    -443,  -439, -2977, -2977,  -430, -2977, -2714, -2977,  -168,   498,
   -1352, -2977, -2977, -2977,   853, -2977, -1984, -2977, -2977, -2977,
   -2010, -2977, -2977, -1974, -2977, -2977, -2977, -2977, -2315, -2977,
     874,   551, -2977, -2977, -2977, -2977, -2977,   330, -2977, -2977,
   -2977, -2977, -2977, -2977,  -784, -2977, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,  -350, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977, -2977,
     998, -2977,   999, -2977,   320,   661, -2977, -2506,  -263, -2977,
   -2977, -2977, -2977, -2977, -2977,  -109, -2977, -2977,  -575, -2977,
   -1034, -1342, -2977, -2977, -2977, -2977, -2977,  -141, -2977, -2977,
   -2977, -2977, -2977, -2017, -2977, -2977, -2977, -2977, -2977, -2977,
   -2460,   600, -2977, -2592,   684, -2977, -2977, -2321,   -21,   -19,
     259, -2977, -2040, -2681, -2977, -2977,  -324,  -640, -2977, -2977,
   -2977, -2977, -1908, -2977, -2977, -2977,  -113, -2977,   218, -1109,
   -2977,   916,  -309,  1036,  -368, -1944,   238, -2977, -1413, -2977,
   -2977, -2977, -2977,  2358, -1274, -2308,  2962, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977,  -787, -2977, -1797, -2977,  1723,
   -2977, -2977,   606,   268, -2977, -2486,   272,  -225,    86,   296,
   -1888, -2266,   969,  -294,  -499, -1284, -2977,   975, -2977, -2977,
   -2977,  1072,  -773, -2977, -2977,  -566,  1750, -2977,   588, -2977,
   -2977,   385,  -199, -2977, -2977, -2977, -2343,  -433, -2081, -2977,
   -1978, -2977, -2977, -2977, -2977,  1111, -2977, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977, -2799,  -451, -2977, -2831,
   -2976, -1867, -1474, -2977, -2977,  -436, -2977, -2977, -2977,   191,
   -1097,   974,  -733,  1889,  1559,  1560,   644, -2977, -2977,   198,
     558,   158, -2977, -2977, -2977, -2977,  1576, -2977, -2977, -2977,
   -2977, -2977, -2977, -2977, -2977, -2977,  -250,  1163,  2471, -2977,
   -2977, -2977, -2977
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2260
static const short yytable[] =
{
      34,    36,    38,   270,   570,    38,   185,  1524,  1007,  1407,
    1991,  1992,  1468,   409,   410,  1516,   411,   412,   112,  1359,
     427,  1062,    87,   237,   328,  1496,  1184,  1176,   958,  2149,
    2073,   962,  1465,  2057,  1464,   683,   971,    58,  1475,  1476,
     103,  1477,  2093,  1498,  1499,   382,   298,  2454,  1124,   102,
    2286,    58,  2224,  2225,  2849,  2034,  2714,  2035,  2716,  2411,
    2739,  2673,   109,   948,  2737,  2804,   198,   579,    87,   116,
      33,    33,   185,   121,   122,   579,  2102,   124,   125,    33,
    2586,  2949,   128,   129,  3235,  3236,  3237,   953,  2412,  2387,
     425,   185,    33,  2138,    33,  2175,    33,  2880,   256,  1907,
     995,  1437,    58,  2339,  2340,  2341,  2342,  1437,  1469,    33,
     579,  1094,    33,  3204,  2327,  1466,  1515,   595,  1216,  3239,
     233,   579,    33,   236,   596,   590,  1902,   326,   240,  2017,
    2926,  2602,   591,  2968,   366,   367,  1925,   413,  3370,   326,
    1912,   429,  1038,   431,    33,   432,   433,   434,  2017,  2640,
     276,   563,  1058,   513,   439,   333,    33,  1134,   450,   451,
     276,   334,   335, -2258,  3169,  2970,  2971,    33,  2972,  2973,
    2974,  2975,  2976,  2977,  3359,   256,  1057,   359,   276,   329,
     330,    33,  1903,  2315,   276,  3075,  1298,  1069,   326,  1423,
     331,  1038,  2996,    33,  2970,  2971,  2968,  2972,  2973,  2974,
    2975,  2976,  2977,   100,  2794,  1517,  1518,   565,  3130,  1038,
    2142,    33,  2143,  1038,  2144,    33,   573,   579,   276,  1228,
    1229,    33,   185,    33,   579,  1180,   185,    33,  2960,   326,
    2962,  1087,   363,    33,  2968,  1180,   579,    33,   369,  2848,
     351,    33,  1129,  2606,  3031,  1132,  1038,    33,    33,   100,
     398,  3360,  3361,    33,  1175,  2138,    58,   408,   408,   408,
     408,   408,   567,   113,  2609,   408,   276,  1228,  1229,    33,
    2197,    33,   599,   276,  1297,  1298,    33,  2914,  2915,  2916,
    2917,  2918,  3135,  1424,  1425,  3457,  2161,  2235,  3289,  1572,
    1505,  1506,   523,  1238,   663,   960,  2255,  2256,   529,  3271,
    2648,  3274,  2197,  2651,  3277,  3591, -2258,   604,  2191,  2939,
     607,     4,    58,    58,    33,    33,  2878,  2463,  2463,  3093,
    1289,  1907,   515,  2365,   326,  2098,    54,   615,   616,   617,
     618,   951,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,    33,
     655,   427,   575,   939,  1447,  3353,   581,  2913,   666,   636,
     637,   155,  1393,    33,   639,  1180,   640,    33,  3094,  2167,
    3509,   326,  1056,  1064,  2965,  2454,  3035,    43,  3278,   643,
     644,   645,   646,  3726,  1394,  3771,   653,   276,  1297,  1298,
      33,  1049,   936,  1074,  3763,  2470,    44,  1080,  1124,  1286,
     317,   318,   319,   320,   321,  1978,  1083,   668,  1530,  3354,
    3362,  1038,   952,    33,  2808,  1399,  2674,   185,  2148,   672,
    2240,  1547,  1238,    43,   937,  1448,   317,   318,   319,   320,
     321,  2730,  2733,  2733,  2513,  2471,  2733,  1400,    54,  1238,
     370,  1036,  1036,  1169,    54,  2612,  1036,  1036,  2712,  2037,
      54,  1981,  2037,  1186,    54,  2042,  1201,  1103,    54,  1036,
    1207,   579,  2978,   579,  2680,  2680,  1213,   371,  1215,  3580,
    2735,  2385,  1573,  1110,  2743,     6,  1283,  2761,  1325,  1036,
    3588,   185,  1036,  1284,    48,   575,    54,  2763,  1036,  1006,
     961,  2978,  1036,  1120,  2824,  1512,  1036,    27,    33,  2795,
    1036,  2884,  3055,    58,  1036,  1036,  1026,  1036,    33,   161,
    1036,     7,  1036,  1036,  1036,  1290,   582,  2366,  3055,    33,
    1036,  1908,  3055,  1036,   835,   928,  1112,  3095,  1931,  3098,
    1036,    54,    54,  2162,  1033,  2198,   675,  1036,  3098,   675,
   -2258,    52,  2613,  1552,  1036,  1171,  1172,   675,  3136,  3192,
    3202,  3264,   592,  3333,   279,  1036,   185,  3340,  3425,  1036,
    3445,  3445,  3371,  1036,   398,  3453,   398,  2198,  3772,  1036,
    3560,  3599,  1036,  3060,  1222,   950,   408,  1225,  3599,   955,
      54,    69,  2979,  2980,    54,  1241,  1375,  1376,  2895,  3660,
    2592,  3660,   564,  2257,   568,   670,   408,  3485,  3053,  3699,
    1979,   327,  2328,  2316,  2809,  2477,  3157,  1120,   101,  1302,
    2907,  2979,  2980,   518,  1908,  3715,  1377,  1378,  1379,  3032,
    3445,  2048,  3188,  2058,   969,  2603,    26,    53,  1924,    33,
    1188,  1033,     1,  1230,  2049,  1470,  3266,  2981,  2351,  2930,
    1237, -2258,  3170,  3261,    33,   104,  1982,  2159,   566,  1033,
    3528,  1119,  1938,    33,  3585,  2104,  1111,   574,   580,  3458,
      33,  1519,  1005,  2897,  2520,   585,  2981,  2119,  1574,  2194,
    3284,  3279,  1531,  2906,  3620,    33,   675,   586,  3394,  2069,
    1189,    58,    58,    58,  1025,    58,  1029,  1031,  1471,  1124,
    1039,  1041,  1042,  1181,  1240,  1047,  3404,  1031,  1302,  3431,
    1050,  1575,    58,  1360,  1438,   920,  2888,  2540,  1478,  2379,
    1463,  1042,  1467,   600,  1241,    54,  3184,  1190,  3376,  2044,
    2073,  1415,  1039,  1039,  1980,    54,  1203,  1983,  1984,  3417,
    3378,  1241,  1042,  1231,  3383,   664,  2050,  2021,    58,   597,
    3461,  2018,  2641,  3330,    58,  1042,    58,   593,  1520,  1938,
      58,  3089,  2434,    58,  2435,  1097,    58,  2145,  3335,  2176,
    3337,   405,   405,  1031,  2982,  2146,    58,  3000,  1973,  3061,
     405,   408,  1114,  3349,  1039,  1522,  3592,  2536,  1121,  3090,
    2725,    58,  2479,   405,  2105,   954,  3363,    58,  2346,   408,
     408,  2464,  3387,  2982,    58,    58,    58,   297,  3407,   667,
    1197,    33,  1472,  1204,  3474,  2003,  2894,   297,    58,  3280,
    2656,  3281,  1302,  2919,  1191,  1217,  2540,  1217,   408,  1426,
    1217,   408, -2258,  1217,    58,   297,  3563,  1169,  2783,  2725,
    2983,   297,  1993,  3226,  3226,  3226,  3226,  1532,  3729,  1538,
    3567,    26,    27,  1088,  3510,  3712,    54,  2725,   669,  1238,
    2052,  2725, -2258, -2258, -2258, -2258, -2258,  3727,     1,  2983,
     673,  1280,     2,  2594,  1346,   297,  2053,  1346,  3764,  2688,
    1120,  3131,  1929,  1246,  3286,   653,   653,    54,   281,  1513,
    2984,  2985,  3117,   168,  1972,  1036,  2002,  3540,  3451,  2625,
    2038,  1192,     4,  2039,   111,   169,  2043,  1033,  2626,   113,
    2659,   284,  2499,  1285,  2500,  2681,  2687,  1034,  1037,  2984,
    2985,  2736,  2741,   297,  1479,  2744,  2048,  1994,  2762,   115,
     297,  1239,  2627,  3287,    10,  2628,  3577,  1266,  2764,  2049,
    1514,  1193,  1453,  1995,    33,  2825,  3227,  3227,  3227,  3227,
      10,  2629,  2885,  3056,  2652,  1070,  3112,  2048,  1070,  3559,
     117,    53,  3471,    33,  3472,  3473,  3197,     3,  1079,  3057,
    2049,  1363,  1070,  3059,   974,  1240,  1070,   192,  3096,  1180,
    3099,    33,  3652,  1096,  1318, -2258,  1996,  3254,  1070,  3103,
    1079, -2258,  3489,  2184,   290,  1380,  1108,  1051,    33,  1079,
    3193,  3203,  3265,   108,  3334, -2258,  1118,  1194,  3341,  3426,
      33,  3446,  3452,  1133,   930,  2657,  3454,  1036,  1036,  1036,
    1174,  3561,  3600,     5,  1370,  1997,   675,  2354,    54,  3601,
    2202,  1108,  2173,  3067,  2016,  1108,  3520,   931,  2486,  1108,
    3661,  2050,  3668,  3077,   297,  1079,   175,  2048,  1079,  3684,
    3700,  1480,  3118,  2469,  1998,  2630,  3444,  1481,  1482,  1483,
    2049,  1039,  1455,  1999,    58,  2675,  3716,  1557,   612,    33,
     176,  3751,  2050,   317,   318,   319,   320,   321,  -282,  1484,
      58,  1381,  1444,  1039,  1455,  2778,   293,  3651,   975,  2778,
    1976,  3657,  2106,  2107,  2108,  2333,  3578, -2258,   294,   295,
    3451,  3451,     7,  3189,  3190,  2660,   296,  2301,  2631,  2126,
    2063,  1937,  2523,   191,   177,  2632,  1918,   234,    33,  3326,
    3491,  3329,    58,   178,  1382,  2163,    33,  1121,     4,  2748,
    2749,     8,  2165,    33,   680,  3740,  3226,  3226,  1121,   235,
    3226,  2072,   934,  3078, -2258,  2828,    33,  3590,  2235,   242,
    1941,  1241,    58,    58,    58,  2052,    58,  2048,    58,    58,
    1502,  1120,  2050,  -282,    58,    58,  3564,  1509,   244,  3492,
    2049,  2053,  2099,   195,    33,  2633,  2153,  2160,   251,  -282,
      54,  3079,  3255,   254,  1485,  3050,  2052,  1486,    58,  2755,
    2756,  2757,  3159,   252,    33,  1487,  1532,   976,    54,  1545,
     255,    58,  2053, -2258,  2120,  1112,  2355,   179,   180,  2334,
    1556,   258,  2505,    58,  2190,    54, -2258,  2356,  1564,  3320,
   -2258,    33,  -282,  2293,   524,  2205, -2258,  3068,   259,  3497,
    1488,  1242,  1243,  1244,  3180,    33,   534,    58,    58,  3227,
    3227,  3477,  1245,  3227,  3482,  3080,    58,  3484,   417,     5,
    2302,   375,   260,   418,   993,   420,   930,   996,  3421,  3081,
   -2258,  -282,    58,    58,  1512,  1489,  2136,  2480,  3429,  2303,
    2304,  1020,  2050,    33,  3182,    33,  2052,  2045,  1268,   931,
    2047,  2240, -2258, -2258,  1490,  1491,    54, -2258,  1975,  2305,
    -282,  3498,  2053,  3499,   261,  1492,  2132,     6,   262,  -282,
    1493,  1318,  1318,  1430,  2181,  2182, -2258, -2258,   427,  3500,
    1431,  1318,  3194,   105,   106,  1399,  3422,  3501,  2335,  3683,
    3198,  3502,  2312,    37,  2015,    33, -2258,  2526,     7,    33,
    1072,  2447,  2022,  2448,    33,    54,   376,  1400,   263,  1494,
    2447,  2051,  2448,    54,  1081, -1630,  3503,   264,  1086, -2258,
      54,  3000,   377,  2734,  3435,  3076,  2738,     8,  2805,  3082,
    1100,  1174,  3124,    54,  1202,   185,   265,  3226,  1208,    33,
     324,  1495,  1212,  3226,  3226,  3083,  3226,  3226,  3226,  3226,
    1261,  1262,  2758,  2059,   266,  3226,  2052,  2064,  2070,  2064,
     963,    54,   964,  2082,   267,   378,  2862,   105,   106,  2076,
    2078,  2079,  2053,  3058,    58,  2083,  2085,  2086,  2087,  1039,
    2950,    54,  2952,   967,  2953,   968,  3327,  1124,  1039,  3643,
    3644,  2073,  2504,    33,  1030,  3381,    33,  2317,   268,  1121,
    2319,    58,    33,    58,   379,    58,    58,  2449,    54,  1038,
    2450,    33,  2820,    58,    58,  1039,  2449,    58,   408,  2450,
     408,    58,    54,  3685,  3702,  3602,  1453,  2271,    33,  1121,
     325,    33,  2235,   380,   269,   384,  2135,  1121,  1395,  1396,
    3227,  2235,   381,    58,    58,   271,  3227,  3227,   311,  3227,
    3227,  3227,  3227,  1922,  1133,  1174,   312,  2495,  3227,  2591,
     313,  3565,    54,  1543,  2301,    33,  2899,   314,  2604,  3226,
     315,   430,  3226,  3226,  3226,  3226,  3708,  1985,  3710,  1986,
    2235,  3224,  3224,  3224,  3224,  2330,   316,  2337,    58,    58,
    1221,    58,  2925,  1224,    58,    58,  1227,  2337,  1325, -2258,
    1988, -2258,  1989,   323,  2360,  2361,  2362,  2363,  2077,  3570,
      33,  3573,  3574,  3575,  3576,  2080,  2179,    33,   408,   408,
     385,  1255,   346,   408,  3691,    58, -2258,  2188,  2189,  2206,
     106,  2428,  1256,  2084,  3686,    33,   386,   347,  3687,  3005,
    3006,  3704,  3007,  3008,  3009,   348,  2320,   417,  2321,  3734,
      58,  3571,   418,   419,   420,  2730,  2324,  3571,  2325,  3226,
    3581,  3582,  3583,  3584,   352,  2240,  1503,  1504,  3226,   353,
    1507,  1508,  3227,   357,  2240,  3227,  3227,  3227,  3227,   387,
     361,   440,  1257,   355,  2274,  2008,   364,  2009,  2010,  1040,
       1,   362,  3691,  1102,     2,  2275,  1258,  2460,  2461,    76,
   -2258,  1549,  1109,  2296,  2297, -2258,  2235,  2302, -2258,  3704,
    2767, -2258,    33,  2240, -2258, -2258,  2276,  1993,   388,  1242,
    1243,  1066,  1067,  2277,  3073,  3074,  2303,  2304,   105,   106,
   -2258,  2278,  2665,  2220,  2221,   338,   339,   340,  2492,  2784,
    2272,   368,  3010,  2785,  3717,  3718,  2305,   389,  1220,  3496,
    3011,  1223,  2796,  2279,  2273,   373,   390, -2258,   374,  3100,
    3686,  2770,  3227,    33,  3687,   383,   441,    77,  3166,   392,
    2944,  3227,  2945,  1116,    78,  3270,  3270,  2817,  3270,  3140,
    3391,  3270,   442,  3659,  3012,  1259,  3662,  3663,  3664,  3665,
     393,  1550,  2534,  3013,   414,   415,   416,  2274,  1408,  1409,
    1410,  3137,  1994,   399,  3466,  3179,  3467,  3745,  2275,    33,
    2100, -2258,  2100,  3433,  3434, -2258,   402,  2666,  1995,   403,
      79,    80,  3014,  3015,  3497,   443,  3358,  1415,    81,  2276,
     435,   437,   438,  2667,   449,  2658,  2277,   452,   453,  2240,
    1046,  2663,  2664,  2441,  2278,  2025,  2026,   455,   456,   457,
    3207,  3208,  1055,   458,   459,   506,   276,  1297,  1298,    33,
     519,  1996,   521, -2258,   444,   526,  2279,  3016,  1299,  1300,
    2465,   517,   527,  3721,  3224,  3224,  2668,  2108,  3224,   528,
     530,  1075,   531,   535,   536,   537,  3498,  3460,  3499,   540,
   -2258,   551,   541,   445,  3036, -2258,   552,  1092,  1093,   553,
    1997,   556,   446,  1099,  3500,   561,  1101,  1532,  1325,  3037,
    3038,  3017,  3501,   571,   572,  2669,  3502,  2679,  3039,   577,
    2682,  2683,  2684,  2685,   578,  1335,  2512,  3145,  1337,  1998,
    1338,  1339,  1340,  1341,  1342,  3153,  3154,   583,  1999,  3480,
     584,  3503,  3480,  2280,  2670,   588,  2309,   332,   589,  2281,
    3209,   337,  3040,  2671,   317,   318,   319,   320,   321,  1036,
     598,  3041,   605,   608,   609,  3018,   610,  2779,   613,   638,
    2027,  2028,  2029,  2030,  2031,  2032,  1217,   408,   408,  2478,
     641,   647,   648,    58,    58,  1525,  1526,  1527,  1528,  2368,
    3042,   654,   656,   658,   657,   659,   660,   661,   662,  2023,
    2024,  2025,  2026,  2259,  1039,   665,  1039,  1039,   671,   681,
    1039,  1039,     1,  2269,   935,   940,  1039,   942,   943,   944,
    2821,   949,  2373,   959,   965,   966,   973,   978,  2693,  3449,
    3450,   980,   982,   983,   984,  3043,  1001,  1294,  1295,  1296,
      58,  1003,  1008,   276,  1297,  1298,    33,  1009,  1011,  1012,
    1404,  2313,  1013,  1018,  1014,  1299,  1300,  1016,  1926,  3562,
    1017,  1019,  1021,  1131,  2549,  2551,  1209,  1270,  1271,  2856,
    1272,  1363,  1418,  1273,  3270,  1274,  1120,  1275,  1277,  3044,
    2561,  1318,    82,  1318,  1278,  1036,  1276,  1279,  1281,  1287,
    3104,  1282,  1288,  1318,  1318,  1039,  1291,  1292,  2359,  1336,
    1318,  1318,  1318,  1318,  1293,  3224,  1343,  1344,  1345,  1348,
    1349,  3224,  3224,  1121,  3224,  3224,  3224,  3224,  1036,  1351,
    2491,  1352,  1353,  3224,  1354,  3134,  2027,  2028,  2029,  2030,
    2031,  2032,  1355,  1356,  1357,  2059,  1362,  1301,  1366,   653,
    2064,  1361,  3597,  1367,  1369,  1368,  2070,  1373,  1392,  2064,
    1397,  1401,  1402,  2772,  2027,  2028,  2029,  2030,  2031,  2032,
    1927,  1398,  1403,  1411,  1405, -2258,  1428,  2426,  1928,  2786,
    2787,  2108,  2790,  2430,  1929,  2941,  1930,    83,  2943,  3397,
    2946,  2947,  1422,  1429,  1432,  1455,  1433,  1931,  1435,  1436,
    2811,  3019,  3020,  3021,  3022,  3023,  3024,  3025,  3026,  3027,
    3028,  1440,  2457,  1441,  1325,  1443,  1457,  1452,  1459,  1500,
    3447,  3448,  3449,  3450,  1460,  1932,  1039,  1121,  1510,  1515,
    2473,  2474,  1511,   408,  1539,  1540,  1548, -2258,  1541, -2258,
    1542,  1933,  1551,  1546,  1552,  1561,  1934,  3224,    58,  1898,
    3224,  3224,  3224,  3224,  1563, -2258,  3399,  1899,  1935,  1900,
    1478,   579,  1901, -2258,  1906,  1936,  2853, -2258,  1910,  1913,
    2502,  2955,    58,  1120,  1914,  1915,  3480,  1916, -2258,    84,
    1963,  1971,  1974,  1977,  2004,  2005,  2966,  1987,  2006,  2007,
    2011,  1302, -2258,    58,  2012,  2527,  1564,  2990,  1318,  2013,
    2014,  1121,    58,  3531,  2036,  2041,  2062,  2075,  2090,  2091,
    2092,  2095,  3539,  2096,  1423,  2097,  2111,  2118,  1522,   408,
     408,  2127,  3210,  2125,  2129,  3211,  2138,  2140,  2151,  3545,
    2152,  2168,  2170,  2180,   408,  2171,  2185,  3224,  3212,    58,
      58,    58,  2183,  2194,  2201,    58,  3224,  2027,  2028,  2029,
    2030,  2031,  2032,  1039,  2203,  2209,  2211,  1908,  2208,    85,
    2247,  2249,  2250,  2252,  2258,  2002,  2310,    86,  2921,  2314,
    2922,  2318,  2322,  2323,  2328,  2002,  2343,  2694,  3214,  2369,
      58,  2326,  2351,  2364,  2132,  2375,  2376,  2377,  2647,  2647,
    3215,  2380,  2647,  2381,  2382,  2385,  2414,  2418,  3292,  3293,
    3294,  2416,  3296,  3297,  3298,  3299,  3300,  3301,  2089,  2417,
    2420,  3304,  2419,  1937,  1318,  2423,  2421,  2094,  1938,  2436,
    2437,  2438,  3372,  1318,  3589,  1939,  1318,  1318,  1318,  1318,
    2686,  3216,  2439,  1039,  2440,  2459,  2442,  2691,  1318,  2432,
    2444,  2709,  2445,  1036,  2117,  2458,  2443,  1940,  2534,  1036,
    3388,  1907,  1941,   185,  2446,  2481,  2483,  2488,  2484,  2493,
    2490,  2497,  2726,  2726,  2726,  2498,  1479,  2726,  1318,  2740,
    3217, -2258,  2059,  2503,  2510,  1036,  3637,  2506,  1302,  1325,
    2507,  2530,  3218,  1059,  1059,  2516,  2524,  1245,  2542,  2540,
    2589,  2590,  2601,  2607,  3219,  3220,  2615,  2617,  2616,  2620,
    2621,  2765,  3221,  2766,  2768,  3222,  2769,  2771,  2622,  1303,
    2773,  2661,  2695,   297,  2064,  2662,  2636,  2637,  2064,    58,
    1969,  2655,  2676,    58,  2696,  1305,  2678,  2677,  2690,  1039,
    2726,  3106,    58,  2457,  3111,  2644,  2801,  2801,  2706,  2711,
    2715,  2713,  2717,  2718,  2722,  2745,  2776,  2746,  2781,  2792,
    2747,  2750,  2002,  2751,  2752,  2753,  2810,    58,  2754,  2812,
    2814,  1133,  2815,  2816,  2819,  1306,  2818,    58,  2822,  2833,
    2830,  2831,  2834,  2837, -2258,  2854,    58,  1307,  3282,  2838,
      58,  1059,  2836,  2857,  3714,  2835,  1512,  2855,  2861,  2870,
    1244,  1232,  3642,  1480,  1174,  2872,  2881,  2882,  1169,  1481,
    1482,  1483,  2883,  2886,  2890,    58,  3692,  3693,  3694,  3695,
    3696,  3697,  2891,  2898,  2900,  2928,  2923,  2933,  1308,  2942,
    2948,  1484,  2954,  2956,  2951,  2957,  2958,  2959,  2968,  2863,
    2969,  2994,  2991,  3053,  3062,  3054,  3003,  3052,  3066,  3065,
    3069,  3071,  3072,  3091,  3092,  3101,  3102,  3105,  3108,  3115,
    3119,  1309,  3107,  3123,  3126,  3133,  3141,  1310,  3144,  3152,
    3174,  3185,  3162,  3194,  3204,  3186,  1311,  1312,  2017,  1313,
    3201, -2258,  3246,  3253,  3256,  3205,  3257,  3258,  3259,  1039,
    3272,  1314,  1315,  3260,  3275,  3283,  3262,  3285,  3533,  1316,
    3263,  3295,  1317,  3290,  2726,  3302,  3291,  3303,  3309,  3310,
     297,  3313,  2902,  2269,  2726,  3315,  3543,  2259,  1039,  3314,
    1318,  3316,  3175,  3317,  3177,  3318,  3319,  3324,  3079,  3331,
    3332,   928,  3336,  2259,  1039,  3338,  1485,    58,  2647,  1486,
    1036,  1036,  3490,  3342,  3343,  2132,  3347,  1487,  2332,  3367,
    3373,  1319,  3374,  3375,  3376,  3709,  3389, -2258,  3393,  3395,
    3398,  3402,  1239,  3410,  3413,  3423,  3417,  3445,  3436,  3437,
    3438,  3439,  3440,  3455,  3441,  3442,  3462,  1318,  3456,  3470,
   -1811,  3494,  1488,  3050,  3512,  1039,  3513,  1039,  3164,  3475,
    1318,  3514,  1318,  3465,  3516,  3468,  3469,  3517,   928,  3143,
    3518,  3523,  3532,  1318,   653,  3519,  3525,  3526,  2726,    58,
    2709,  3538,   653,   653,   185,  3536,  3542,  1489,  3546,  3544,
    3547,  3548,  2726,  3550,  3776,  3552,  2018, -2258,  3556, -2258,
    3566,  1232,  3568,  3586,  3594,  3595,  1490,  1491,  3603,  3613,
    2064,  3614,  3616,  3615,  3617,  3618,  3635,  1492,  3623,  3636,
    3641,  3648,  1493,  3658,  3666,   185,    63,  3698,  2070,  3622,
    2064,  3682,  3711,  3669,  3720,  3722,  3723,  3724,  3725,  3728,
    3738,  3749,  3750,  2426,  3757,  3759,  3760,  3761,  3386,  3765,
      58,  3762,  3486,  3770,  2990,  3774,  3148,  3775,  3097,  3737,
    2846,  1494,  1358,  2193,  2515,    49,  2797,  3122,    50,  2806,
     194,   532,   525,   199,   345,  2457,  1010,  3125,  2370,  3127,
     533,  2371,  2726,  1039,  3405,    58,   350,   358,   560,  1133,
     674,   156,   188,  1495,  1990,  1174,   972,   558,   945,  3735,
      58,  2429,    58,  3149,    58,   946,  1350,   594,  1196,  1967,
    2653,  2645,  2788,  2263,  2475,  2264,  2265,    58,  2219,  2267,
    2268,  1174,  3173,  2539,  1318,  2287,   476,  3412,  2535,  2223,
    3758,  3464,  2860,  2793,  2559,  3541,  2122,   408,    46,   408,
     473,   474,   475,   130,    60,  3507,  3385,    61,    47,    58,
      58,  2522,  1269,  2525,  2207,  1318,  1098,  2246,   188,  3390,
     516,  2529,  2158,  3495,  3604,  1372,  3741,  2726,   476,  1130,
    2103,  2113,  1904,  3168,  1232,  3323,  3612,   188,  2156,  2174,
    3322,  3223,  3223,  3223,  3223,  2726,  2726,  2494,   614,  3305,
    3369,  3048,  3529,  1325,  3527,    58,  3524,  3352,  2415,  2782,
    3248,  3744,  2384,  2892,  2350,  3488,  2742,  2330,  2619,  2289,
    2290,  3430,  2912,  3325,  3619,  3348,  2689,  3267,  3380,  2610,
    3268,  3483,  2963,   477,   478,   479,   480,   481,   482,  3673,
    3511,  3344,  2262,  3049,  3064,  1318,  1318,   981,  1319,  1319,
      42,   483,   484,   485,  3769,   404,  1318,  1318,  1319,  1318,
    3001,  3432,  1318,  1955,  1318,  3002,  2345,  3200,  1318,  3487,
    2964,  2344,  2967,  2254,  3650,   477,   478,   479,   480,   481,
     482,  2904,  3428,  3569,  3587,  2217,  1921,  3132,  3579,  1454,
    2367,  2131,  3129,   483,   484,   485,   682,   185,  2121,     0,
    2137,  2813,     0,   653,     0,  3534,     0,     0,    58,     0,
       0,   511,   512,  3671,  3672,     0,     0,     0,   188,     0,
       0,    58,   188,     0,     0,     0,     0,     0,     0,     0,
    2726,  3328,  2726,     0,     0,  2466,     0,     0,     0,     0,
    3557,     0,     0,     0,     0,     0,     0,  3656,     0,     0,
       0,     0,     0,     0,     0,     0,  1039,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3350,  3351,
       0,     0,  2773,     0,     0,  2064,     0,     0,     0,     0,
       0,     0,    58,  3522,  3674,     0,  1133,  1133,     0,     0,
       0,   486,  2801,  3522,   487,  3382,  2801,     0,     0,  3530,
     408,     0,     0,     0,  2291,  2292,     0,     0,     0,     0,
      58,  2308,     0,   408,     0,    58,     0,     0,     0,     0,
    1232,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,   486,     0,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2611,  3414,     0,     0,     0,     0,     0,  2726,
     468,   469,   470,   471,   472,   473,   474,   475,  2902,  2726,
       0,  2259,  2259,     0,  3223,  3223,     0,  1036,  3223,     0,
    3225,  3225,  3225,  3225,     0,     0,  3656,     0,     0,  3443,
       0,     0,   642,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,   488,     0,     0,     0,     0,     0,
       0,     0,    58,  2259,     0,     0,     0,     0,     0,   489,
    2226,  2227,  2228,   490,     0,  2229,     0,  2230,  2231,     0,
       0,  1039,  2350,     0,     0,     0,     0,     0,     0,  1121,
       0,     0,  1121,     0,     0,  1318,   488,  3273,  1318,  3276,
    1318,     0,  2726,     0,     0,     0,     0,  3701,     0,   491,
       0,   489,     0,     0,     0,   490,     0,   188,     0,     0,
    2226,  2227,  2228,     0,     0,  2229,    58,  2230,  2231,     0,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
     477,   478,   479,   480,   481,   482,     0,     0,     0,     0,
       0,   491,     0,     0,     0,   493,     0,     0,   483,   484,
     485,  2496,     0,     0,  1318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2117,   492,
       0,     0,     0,     0,   408,     0,     0,     0,    58,     0,
       0,     0,   188,     0,     0,     0,     0,   493,     0,     0,
       0,  2537,     0,     0,     0,     0,    58,     0,     0,  3647,
    3755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1022,  1023,  1024,     0,  1027,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,   494,     0,     0,  1318,
       0,  1053,  2726,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1318,     0,  3223,     0,     0,     0,     0,
       0,  3223,  3223,     0,  3223,  3223,  3223,  3223,     0,     0,
    2726,     0,  2726,  3223,     0,  1318,   185,  1077,   494,     0,
       0,     0,     0,  1082,     0,  1084,     0,     0,     0,  1091,
       0,     0,  1091,     0,     0,  1091,     0,     0,   486,     0,
       0,   487,   495,     0,     0,  1104,     0,     0,     0,     0,
       0,    58,     0,     0,     0,     0,    58,     0,    58,     0,
    1104,     0,     0,  3225,  3225,     0,  1165,  3225,  2887,     0,
       0,     0,   653,  1027,  1178,  1182,  2726,     0,     0,  1198,
       0,     0,     0,     0,   495,     0,     0,  1210,     0,    58,
    2232,     0,     0,  2233,     0,  2234,     0,  2911,     0,     0,
       0,     0,     0,  1234,     0,     0,     0,    58,     0,     0,
       0,     0,     0,  2927,     0,  2235,     0,  3414,  3234,  3234,
    3234,  3234,     0,  1318,     0,  2236,     0,  3223,     0,     0,
    3223,  3223,  3223,  3223,     0,  3667,     0,     0,     0,     0,
    2232,  1232,     0,  2233,     0,  2234,  2237,     0,     0,  3670,
       0,     0,     0,     0,     0,     0,  1121,     0,     0,     0,
    1318,   488,     0,     0,  2350,  2235,  2350,     0,     0,  2238,
       0,     0,     0,  2239,     0,  2236,   489,     0,     0,     0,
     490,    58,    58,    58,    58,    58,    58,     0,     0,     0,
       0,     0,     0,  3703,     0,     0,  2558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,  3223,     0,  2238,
       0,     0,     0,  2239,     0,     0,  3223,     0,     0,     0,
       0,  2842,  2843,  1174,     0,     0,     0,     0,  1319,     0,
    1319,     0,  2852,     0,   492,     0,     0,     0,  2240,     0,
    1319,  1319,     0,     0,     0,     0,     0,  1319,  1319,  1319,
    1319,     0,   493,     0,     0,     0,  2864,  2865,  2866,  2867,
    2868,  2869,  1318,     0,  3746,     0,  2874,  2875,  2876,  2877,
       0,     0,     0,  2879,     0,     0,     0,     0,     0,     0,
       0,     0,  2466,     0,  3225,     0,     0,     0,  2240,     0,
    3225,  3225,     0,  3225,  3225,  3225,  3225,     0,     0,     0,
       0,     0,  3225,     0,     0,     0,  3767,  3768,  3746,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,  3777,     0,  1234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,     0,     0,     0,     0,     0,  1416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2931,  2932,     0,     0,     0,
       0,     0,  2936,  2937,     0,     0,   158,   159,     0,     0,
       0,     0,     0,     0,   160,    33,     0,     0,     0,     0,
       0,  1446,     0,     0,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
    1059,  3234,  3234,     0,     0,  3234,     0,     0,     0,     0,
       0,  1474,  1474,  1474,     0,  1474,  3225,  1474,  1474,  3225,
    3225,  3225,  3225,    63,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1319,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1182,     0,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
    1182,   162,     0,     0,     0,     0,  3481,     0,     0,  3481,
       0,     0,  1559,   163,     0,     0,     0,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1234,  1416,     0,     0,
     164,     0,     0,     0,     0,  1911,  3225,     0,     0,     0,
       0,  3113,  3114,     0,     0,  3225,     0,     0,     0,     0,
    3121,  1919,  1919,     0,     0,     0,   602,   460,   461,   462,
       0,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,  3346,     0,     0,     0,     0,
       0,  1319,     0,     0,     0,     0,     0,  3155,  3156,     0,
    1319,     0,     0,  1319,  1319,  1319,  1319,     0,     0,   476,
       0,     0,     0,     0,     0,  1319,     0,     0,   477,   478,
     479,   480,   481,   482,  3176,     0,  3178,     0,     0,     0,
       0,     0,    54,     0,   165,     0,   483,   484,   485,     0,
       0,     0,     0,     0,     0,  1319,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2332,     0,  3234,     0,     0,     0,     0,     0,  3234,  3234,
       0,  3234,  3234,  3234,  3234,     0,     0,  3249,  3250,     0,
    3234,  3251,  3252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,   478,   479,   480,
     481,   482,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,     0,   483,   484,   485,     0,     0,     0,
      63,   166,    63,     0,  1182,  1091,     0,     0,     0,     0,
       0,   476,  2112,  1104,  1232,     0,  1182,     0,     0,     0,
    2123,     0,     0,     0,     0,     0,     0,     0,     0,  2388,
       0,   188,     0,     0,     0,     0,   167,     0,     0,     0,
    2350,     0,  1234,  1165,     0,     0,   486,     0,     0,   487,
       0,     0,     0,     0,     0,     0,     0,     0,  3312,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     168,     0,     0,     0,  3234,     0,     0,  3234,  3234,  3234,
    3234,     0,   169,     0,     0,     0,     0,  2157,  1165,     0,
      63,     0,     0,  2164,  2166,   476,     0,     0,     0,     0,
       0,     0,     0,  3481,     0,     0,     0,     0,   477,   478,
     479,   480,   481,   482,     0,     0,     0,     0,   170,     0,
       0,     0,     0,     0,  2186,     0,   483,   484,   485,     0,
       0,     0,     0,   171,   486,     0,     0,   487,     0,  3379,
       0,   172,     0,  3384,     0,     0,     0,     0,     0,  2213,
       0,     0,     0,     0,   173,     0,     0,  1319,     0,     0,
       0,     0,  3392,     0,  3234,     0,     0,     0,     0,   488,
       0,     0,     0,  3234,   470,   471,   472,   473,   474,   475,
       0,  3403,     0,     0,   489,     0,     0,     0,   490,     0,
       0,     0,   477,   478,   479,   480,   481,   482,   174,     0,
       0,     0,     0,     0,     0,   476,     0,     0,     0,     0,
     483,   484,   485,     0,  1319,     0,     0,     0,     0,     0,
       0,   273,     0,   175,   491,     0,     0,  1319,     0,  1319,
     274,   275,     0,     0,     0,     0,   276,   277,   278,    33,
    1319,     0,     0,     0,     0,     0,     0,   176,     0,     0,
     161,     0,   492,     0,     0,     0,     0,   488,     0,     0,
       0,     0,     0,     0,     0,  2389,   486,     0,     0,   487,
     493,     0,   489,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,     0,     0,  2390,  2391,  2392,     0,     0,
       0,   177,  1319,     0,     0,     0,     0,     0,     0,     0,
     178,     0,   477,   478,   479,   480,   481,   482,     0,     0,
       0,     0,   491,     0,     0,     0,     0,     0,     0,     0,
     483,   484,   485,     0,  2393,   162,     0,     0,     0,     0,
     279,     0,     0,     0,     0,     0,  2394,   163,     0,     0,
     492,     0,     0,     0,     0,     0,     0,  2395,     0,     0,
     486,   494,     0,   487,     0,     0,     0,     0,   493,     0,
   -2258, -2258, -2258,  2396,   164, -2258,     0, -2258, -2258,     0,
       0,     0,     0,  2397,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,   180,     0,     0,  2398,   488,
       0,  1319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,     0,   490,     0,
       0,     0,     0,     0,     0,     0,     0,   495,     0,     0,
       0,     0,  1319,     0,     0,     0,     0,     0,     0,  3555,
       0,     0,  3558,     0,     0,     0,  2399,     0,     0,   494,
       0,     0,     0,     0,   491,     0,     0,     0,  1319,  1319,
    1319,  1319,     0,     0,     0,     0,    54,     0,   165,     0,
     486,     0,     0,   487,     0,     0,  2400,     0,     0,     0,
       0,     0,   492,   488,     0,     0,  2401,     0,     0,     0,
       0,     0,  2245,  1234,     0,     0,     0,     0,   489,     0,
     493,     0,   490,     0,     0,     0,     0,  2402,     0,     0,
       0,  2403,  1319,  1319,     0,   495,     0,     0,     0,     0,
       0,     0,     0,  1319,  1319,     0,  1319,     0,     0,  1319,
       0,  1319,     0,     0,     0,  1319,     0,     0,   491,  2404,
       0,     0,     0,     0,     0,     0,     0,     0,  2405,  2295,
       0,  1059,  1059,  1059,     0,  1059,  1059,  1059,  1059,  1059,
    1059,     0,     0,     0,  1059,   166,   492,     0,     0,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,     0,     0,   493,     0,     0,  3645,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,  3207,  3208,
     167,     0,     0,     0,   276,  1297,  1298,    33,   489,     0,
       0,     0,   490,     0,     0,     0,  1299,  1300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,     0,     0,     0,  3675,  3676,
       0,  3678,     0,  3680,  3681,     0,   169,   495,   491,     0,
   -2258,     0,     0, -2258,     0, -2258,     0,     0,     0,     0,
       0,     0,     0,     0,   281,   494,     0,     0,     0,   282,
       0,   283,     0,     0,     0, -2258,   492,     0,     0,     0,
       0,     0,   170,     0,     0, -2258,     0,   284,     0,     0,
       0,  1232,     0,     0,   493,     0,     0,   171,  3209,     0,
       0,     0,   285,     0,     0,   286, -2258,     0,   287,     0,
    3730,     0,  3731,     0,     0,     0,     0,   288,   173,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2258,
       0,   495,     0, -2258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3743,  2487,     0,     0,
       0,  1319,  1319,     0,     0,  1319,     0,   649,   289,     0,
       0,     0,   174,     0,     0,  3752,  3753,     0,     0,  3754,
     290,  1182,  3756,     0,     0,   494,     0,     0,     0,     0,
       0,   291,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,  1165,     0,     0,     0,     0,     0,     0, -2258,     0,
       0,   292,     0,     0,     0,     0,  1319,     0,     0,  1319,
       0,     0,  1319,     0,  1120,  1319,     0,  1319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1182,  2593,
    1182,   495,     0,     0,  1027,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,   293,     0,   178,     0,     0,     0,   273,     0,
       0,     0,     0,     0,   294,   295,     0,   274,   275,  2639,
       0,     0,   296,   276,   277,   278,    33,     0,     0,     0,
       0,  1319,     0,   297,     0,     0,     0,   161,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,   273,     0,     0,     0,     0,     0,     0,     0,     0,
     274,   275,     0,     0,     0,     0,   276,   277,   278,    33,
       0,     0,     0,     0,     0,   476,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,   179,   180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1319,     0,     0,     0,
       0,     0,   162,     0,     0,     0,     0,   279,     0,     0,
    1319,     0,  1319,     0,   163,     0,     0,     0,  1319,  1319,
       0,  1319,  1319,  1319,  1319,     0,     0,     0,     0,     0,
    1319,     0,  1319,     0,     0,     0,     0,     0,     0,     0,
       0,   164,     0,     0,     0,   162,     0,     0,  1182,  1319,
     279,     0,  1182,     0,     0,     0,     0,   163,     0,  1302,
       0,  1182,   477,   478,   479,   480,   481,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     483,   484,   485,     0,   164,     0,  1182,     0,     0,     0,
    3210,     0,     0,  3211,     0,     0,  1234,     0,     0,     0,
       0,     0,     0,     0,     0,  2826,  3212,     0,     0,  2829,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1232,     0,     0,     0,     0,     0,
       0,     0,     0,    54,  2851,   165,     0,     0,     0,     0,
    1319,     0,     0,     0,  1319,  3213,  3214,  1319,  1319,  1319,
    1319,     0,     0,     0,     0,     0,     0,     0,  3215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1319,     0,     0,    54,  1319,   165,   273,
       0,     0,     0,     0,     0,     0,     0,     0,   274,   275,
       0,     0,     0,     0,   276,   277,   278,    33,     0,  3216,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,  1319,     0,     0,   280,  3217,     0,
       0,     0,     0,  1319,     0,     0,     0,     0,     0,     0,
    3218,     0,     0,     0,     0,     0,  2929,     0,     0,     0,
       0,     0,  3219,  3220,     0,     0,     0,   167,     0,     0,
    3221,     0,     0,  3222,     0,   166,     0,     0,     0,     0,
     280,   297,     0,   162,   569,     0,     0,     0,   279,  1319,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,   169,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,     0,  1182,     0,
       0,   281,     0,     0,     0,     0,   282,     0,   283,     0,
       0,     0,     0,   488,   168,     0,  1232,     0,     0,   170,
       0,     0,     0,     0,   284,     0,   169,     0,   489,     0,
       0,     0,   490,     0,   171,     0,     0,     0,     0,   285,
       0,     0,   286,   273,   281,   287,     0,     0,     0,   282,
       0,   283,   274,   275,   288,   173,     0,     0,   276,   277,
     278,    33,   170,     0,     0,     0,     0,   284,   491,  1182,
       0,     0,   161,     0,     0,     0,     0,   171,     0,     0,
       0,   989,   285,     0,    54,   286,   165,     0,   287,     0,
       0,     0,     0,     0,  1412,   289,   492,   288,   173,   174,
     188,     0,     0,     0,  1182,     0,     0,   290,     0,     0,
       0,     0,     0,     0,   493,     0,     0,     0,   291,  3146,
       0,  1053,     0,  3150,   175,     0,     0,     0,     0,     0,
    2562,  2563,  2564,  2565,  2566,  2567,  3161,     0,   289,     0,
       0,   188,   174,     0,     0,     0,     0,   162,   292,     0,
     290,     0,   279,     0,     0,     0,     0,     0,     0,   163,
       0,   291,     0,  2789,     0,     0,     0,   175,  3181,  3183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,   164,     0,   280,     0,
       0,   292,   177,     0,     0,   494,     0,     0,     0,   293,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,   295,     0,  3247,     0,     0,     0,   167,   296,
       0,     0,     0,     0,     0,     0,     0,  2568,     0,     0,
     297,     0,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,   293,     0,   178,     0,     0,     0,     0,     0,
       0,     0,   168,     0,   294,   295,     0,     0,     0,     0,
       0,   495,   296,   132,   169,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,    54,     0,
     165,     0,   281,     0,     0,   179,   180,   282,     0,   283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,     0,   133,     0,     0,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,     0,  3306,     0,     0,
     285,   134,   135,   286,     0,     0,   287,     0,   179,   180,
    3321,     0,     0,     0,     0,   288,   173,     0,  2693,     0,
     471,   472,   473,   474,   475,     0,     0,  1294,  1295,  1296,
       0,     0,     0,   276,  1297,  1298,    33,     0,     0,     0,
       0,   136,     0,     0,     0,  1299,  1300,     0,     0,     0,
     476,     0,     0,   137,     0,  3165,   289,   166,     0,     0,
     174,     0,   280,     0,   138,     0,     0,     0,   290,     0,
       0,  1182,     0,     0,     0,     0,     0,     0,     0,   291,
     139,     0,     0,   188,     0,   175,     0,     0,     0,     0,
     140,     0,   167,     0,     0,     0,     0,     0,     0,  1182,
       0,     0,     0,     0,  1165,   141,     0,     0,     0,   292,
       0,     0,     0,  1234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,  1301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,     0,     0,  2569,   142,     0,   477,   478,   479,
     480,   481,   482,   177,     0,     0,   281,  2570,     0,     0,
     293,   282,   178,   283,     0,   483,   484,   485,   143,     0,
       0,     0,   294,   295,   170,     0,     0,     0,     0,   284,
     296,     0,     0,   144,     0,     0,     0,     0,     0,   171,
     145,   297,     0,   146,   285,     0,     0,   286,     0,     0,
     287,     0,     0,     0,     0,     0,     0,     0,     0,   288,
     173,  1165,     0,     0,   147,     0,     0,     0,   148,  2571,
       0,     0,     0,     0,     0,  2572,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   180,     0,     0,
     289,     0,     0,  1120,   174,   150,     0,     0,     0,     0,
       0,     0,   290,     0,  2573,     0,     0,     0,     0,     0,
       0,     0,     0,   291,     0,  3306,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,  2574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2575,  2576,
       0,     0,     0,   292,  2577,   486,     0,     0,   487,     0,
       0,     0,     0,     0,  2578,  1576,  1577,  1578,  1579,  1580,
    1581,     0,  1582,  1583,  1584,     0,     0,     0,  1585,  1586,
    1587,  1588,  1589,  1590,     0,     0,  2579,  1182,     0,  2580,
    2581,     0,     0,  1591,  2582,     0,     0,   177,     0,     0,
       0,     0,     0,     0,   293,  1182,   178,  2694,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   295,     0,  1592,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,  1165,     0,   297,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2583,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1593,     0,   488,     0,
       0,     0,     0,     0,     0,  1594,     0,     0,     0,     0,
     179,   180,     0,   489,     0,     0,     0,   490,     0,     0,
       0,     0,     0,  1595,  1596,     0,     0,     0,  1302,     0,
    3306,     0,  1597,     0,     0,  3607,     0,  3609,     0,  1598,
    1599,     0,     0,  1600,  1601,  1602,  1603,     0,     0,  1604,
    1605,     0,     0,   491,     0,     0,     0,     0,     0,  1303,
       0,     0,  2695,     0,     0,     0,     0,     0,  1182,     0,
       0,     0,     0,     0,  2696,  1305,     0,     0,     0,     0,
       0,   492,     0,     0,     0,     0,  1234,     0,     0,  1606,
       0,     0,   188,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1607,     0,     0,     0,  1306,     0,  1608,     0,     0,
       0,     0,     0,  2216,  1609,     0,  1610,  1307,     0,     0,
       0,  1611,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1612,     0,     0,
    1474,  1474,  1474,  1474,  1474,  1474,     0,     0,  1308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1613,     0,     0,     0,     0,
       0,  1309,     0,     0,     0,     0,     0,  1310,  1614,     0,
       0,     0,     0,     0,  1615,     0,  1311,  1312,     0,  1313,
       0,     0,     0,  1616,  1617,     0,     0,     0,     0,     0,
    1618,  1314,  1315,  1619,  1620,     0,     0,     0,  1621,  1316,
       0,     0,  1317,     0,  1622,  1623,   495,     0,     0,     0,
     297,  1624,  1625,  1626,     0,     0,  1627,  1628,  1629,     0,
       0,     0,  1630,     0,     0,     0,  1631,     0,  1632,     0,
       0,     0,     0,     0,     0,  1633,  1634,  1635,  1636,     0,
    1637,  1638,     0,     0,     0,  1639,  1640,     0,  1641,  1642,
    1643,  1644,  1645,  1646,  1647,     0,     0,     0,     0,     0,
    1648,  1649,  1650,     0,  1651,  1652,     0,     0,  1234,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,     0,  1661,     0,
       0,     0,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,
    1690,  1691,  1692,  1693,  1694,  1695,  1696,  1697,     0,  1698,
    1699,     0,     0,  1700,  1701,  1702,  1703,  1704,  1705,  1706,
    1707,  1708,  1709,     0,  1710,  1711,  1712,  1713,  1714,  1715,
    1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,     0,
       0,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,
       0,  1734,  1735,  1736,  1737,     0,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,
    1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,
    1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,
    1772,  1773,     0,  1774,  1775,  1776,  1777,  1778,  1779,     0,
       0,  1780,  1781,     0,  1782,  1783,  1784,  1785,  1786,  1787,
    1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,
    1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,
       0,     0,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,
    1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,
    1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,
    1836,  1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,
    1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,
    1866,  1867,  1868,  1869,     0,     0,     0,     0,  1870,  1871,
    1872,  1873,  1874,  1875,  1876,  1877,  1878,  1879,  1880,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,  1881,
       0,     0,     0,     0,     0,     0,     0,  1882,     0,     0,
       0,     0,  1883,     0,     0,     0,  1884,     0,     0,  1885,
    1886,  1887,  1888,     0,     0,  1889,  1890,     0,  1891,  1892,
    1893,  1576,  1577,  1578,  1579,  1580,  1581,   133,  1582,  1583,
    1584,     0,     0,     0,  1585,  1586,  1587,  1588,  1589,  1590,
       0,     0,     0,     0,     0,     0,   134,   135,     0,  1591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,     0,  1593,     0,     0,   140,     0,     0,     0,     0,
       0,  1594,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,  1595,
    1596,     0,     0,     0,     0,     0,     0,     0,  1597,     0,
       0,     0,     0,     0,     0,  1598,  1599,     0,     0,  1600,
    1601,  1602,  1603,     0,     0,  1604,  1605,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1606,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   145,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,  1607,     0,     0,
       0,     0,     0,  1608,     0,     0,     0,     0,     0,   147,
    1609,     0,  1610,   148,     0,     0,     0,  1611,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1612,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1613,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1614,     0,     0,     0,     0,     0,
    1615,     0,     0,     0,     0,     0,     0,     0,     0,  1616,
    1617,     0,     0,     0,     0,     0,  1618,     0,     0,  1619,
    1620,     0,     0,     0,  1621,     0,     0,     0,     0,     0,
    1622,  1623,     0,     0,     0,     0,     0,  1624,  1625,  1626,
       0,     0,  1627,  1628,  1629,     0,     0,     0,  1630,     0,
       0,     0,  1631,     0,  1632,     0,     0,     0,     0,     0,
       0,  1633,  1634,  1635,  1636,     0,  1637,  1638,     0,     0,
       0,  1639,  1640,     0,  1641,  1642,  1643,  1644,  1645,  1646,
    1647,     0,     0,     0,     0,     0,  1648,  1649,  1650,     0,
    1651,  1652,     0,     0,     0,  1653,  1654,  1655,  1656,  1657,
    1658,  1659,  1660,     0,  1661,     0,     0,     0,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,     0,  1698,  1699,     0,     0,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,     0,
    1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,  1723,  1724,     0,     0,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,     0,  1734,  1735,  1736,
    1737,     0,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,     0,  1774,
    1775,  1776,  1777,  1778,  1779,     0,     0,  1780,  1781,     0,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,     0,     0,  1808,  1809,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,
    1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,  1868,  1869,
   -2259,     0,     0,     0,  1870,  1871,  1872,  1873,  1874,  1875,
    1876,  1877,  1878,  1879,  1880,     0,     0,     0,     0,     0,
       0, -2259, -2259, -2259,     0,  1881, -2259,     0, -2259, -2259,
       0,     0,     0,  1882,     0,     0,     0,     0,  1883,     0,
       0,     0,  1884,     0,     0,  1885,  1886,  1887,  1888,     0,
       0,  1889,  1890,     0,  1891,  1892,  1893,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2259,     0, -2259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2259,     0,     0,     0,     0,     0,     0, -2259,
       0, -2259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2259,     0,     0,     0,     0, -2259,     0,     0,
       0,     0,     0,     0,     0, -2259,     0,     0,     0, -2259,
       0,     0,     0,     0,     0, -2259,     0,     0,     0, -2259,
   -2259, -2259, -2259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2259,     0,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0, -2259,     0,     0, -2259,     0, -2259,     0,     0,     0,
       1,     0,     0, -2259,     2,     0,     0,     0,     0,     0,
       0,   684,   685,   686,   476,     0, -2259,     0,     0,     0,
     687,     0,     0,   688,     0,     0, -2259,     0,     0,     0,
     689,   690,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2259, -2259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2259,     0,     0,     0,     0,     0,     0,     0,
   -2259,     0,     0,     0, -2259,   691,   692,     0,     0,     0,
     693,     0, -2259, -2259, -2259,     0,     0,     0,     0,     0,
     694,   695,     0,   696,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   697,     0,     0,
       0,   477,   478,   479,   480,   481,   482,     0,     0,     0,
       0,     0,     0,     0,   698,     0,     0,   699,   700,   483,
     484,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   701,     0,   702,   703,   704,     0,     0, -2259,
       0,     0,     0,     0,   705,   706,     0,   707,   708,   709,
   -2259,     0,     0,     0,     0,   710,     0,     0,   711,     0,
     712,   713,   714,     0,     0,     0,     0,     0,   715,     0,
     716,   717,     0,   718,     0,   719,   720,     0,     0,   721,
       0,     0,   722,   723,   724,   725,   726,   727,     0,     0,
   -2259,   728,   729,   730,     0,   731,     0,     0,     0,   732,
       0,   733,   734,     0,     0,     0,     0,   735,     0,     0,
     736,     0,     0,   737,     0,   738,     0,   739,     0,   740,
       0,     0,     0,   741,   742,     0,   743,   744,   745,     0,
       0,   746,     0,   747,   748,     0,   749,     0,     0,     0,
       0,     0,     0,     0,   750,   751,     0,     0,     0,     0,
       0, -2259,     0,     0,     0,     0,     0,   752,     0,   486,
     753,   754,   487,     0,   755,   756,     0,     0,   757,   758,
       0,     0,     0,     0,     0,     0,     0,   759,   760,   761,
       0,   762,     0,     0,     0,     0,     0, -2259,     0,     0,
       0,   763,   764,   765,     0,   766,     0,     0,     0,   767,
     768,     0,     0,     0,   769,     0,     0,     0,     0,     0,
       0,     0,   770,     0,     0,     0,     0,     0,     0,     0,
     771,   772,   773,     0,     0,     0,     0,     0,   774,   775,
       0,     0,     0, -2259,     0,     0,   776,     0,     0,   777,
       0,     0,     0,   778,   779,     0,     0, -2259, -2259, -2259,
   -2259, -2259, -2259, -2259,   780, -2259, -2259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   781, -2259,     0,     0,     0,     0,     0,     0,   782,
       0,     0,   488,     0,     0,   783,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   784,   489,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,   785,     0,
       0,     0,     0,     0,   786,     0,   787,   788,     0,     0,
       0,     0,     0,     0,   789,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,     0,     0,
       0,     0,  2827,   460,   461,   462,     0,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,   790,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,   791,     0,     0,     0,     0,     0,
       0,   792,     0,   493,     0,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   793,   794,     0,     0,     0,
     795,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   796,     0,     0,     0,     0,     0,   797,   798,
     799,   800,     0,     0,     0,   801,     0,     0,     0,   802,
       0,     0,     0,     0,     0,     0,   803,   804,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   805,     0,   806,
       0,     0,     0,     0,   494,     0,     0,     0,     0,     0,
     807,     0,   808,     0,     0,   809,     0,     0,     0,     0,
       0,   810,   477,   478,   479,   480,   481,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     483,   484,   485,     0,     0,     0,     0,   811,     0,     0,
     812,     0,     0,     0,     0,   813,     0,     0,   814,   815,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,   816,     0,     0,     0,   460,   461,   462,
     817,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   818,   819,   820,   821,   822,   823,   824,
       0,     0,   825,     0,   826,     0,   827,     0,     0,   476,
     460,   461,   462,     0,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,     0,   460,   461,   462,     0,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,   476,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,   487,   476,     0,     0,   460,   461,   462,
       0,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,   478,   479,   480,
     481,   482,     0,     0,     0,     0,     0,     0,     0,   476,
       0,     0,     0,     0,   483,   484,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   477,
     478,   479,   480,   481,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   483,   484,   485,
       0,   477,   478,   479,   480,   481,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   483,
     484,   485,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,   490,     0,     0,     0,   477,   478,   479,   480,
     481,   482,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   483,   484,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,   487,     0,     0,
       0,     0,     0,     0,     0,     0,   492,   460,   461,   462,
       0,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,     0,     0,
     487,     0,     0,     0,     0,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   486,
       0,     0,   487,     0,     0,     0,   460,   461,   462,     0,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,   494,     0,   487,   476,     0,
       0,     0,     0,     0,   460,   461,   462,   488,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,   489,     0,     0,     0,   490,   587,     0,     0,
       0,     0,     0,     0,     0,     0,   477,   478,   479,   480,
     481,   482,     0,     0,     0,     0,   476,     0,     0,     0,
     488,     0,     0,     0,   483,   484,   485,     0,     0,     0,
       0,   495,   491,     0,     0,   489,     0,     0,     0,   490,
     601,     0,   488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   489,     0,     0,
     492,   490,   611,     0,     0,   477,   478,   479,   480,   481,
     482,     0,     0,     0,     0,   491,     0,     0,   493,     0,
       0,     0,     0,   483,   484,   485,     0,   488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,     0,     0,
       0,     0,   489,   492,     0,     0,   490,   979,     0,     0,
       0,     0,     0,   477,   478,   479,   480,   481,   482,     0,
       0,   493,     0,     0,     0,   492,     0,     0,     0,     0,
       0,   483,   484,   485,     0,     0,     0,     0,     0,     0,
       0,     0,   491,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
       0,     0,     0,     0,   486,     0,     0,   487,     0,     0,
     492,   460,   461,   462,     0,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   486,   494,   495,   487,     0,     0,     0,
       0,     0,     0,   460,   461,   462,     0,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   494,
       0,   486,     0,     0,   487,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,   490,   985,     0,     0,
     477,   478,   479,   480,   481,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   483,   484,
     485,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,   491,   460,   461,   462,   488,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,   489,     0,     0,     0,   490,   986,     0,     0,     0,
     492,     0,   477,   478,   479,   480,   481,   482,     0,     0,
       0,     0,     0,     0,     0,   476,     0,     0,   493,     0,
     483,   484,   485,     0,   488,     0,     0,     0,     0,     0,
       0,   491,     0,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,   490,   987,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   492,
     460,   461,   462,     0,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   493,     0,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   486,   494,
       0,   487,   476,     0,     0,     0,     0,   492,     0,     0,
       0,     0,   477,   478,   479,   480,   481,   482,     0,     0,
       0,     0,     0,     0,     0,   493,     0,     0,     0,     0,
     483,   484,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,     0,
     486,     0,     0,   487,     0,   495,     0,   460,   461,   462,
       0,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   477,
     478,   479,   480,   481,   482,     0,   494,     0,     0,   476,
       0,     0,     0,     0,     0,     0,     0,   483,   484,   485,
       0,   488,     0,     0,   495,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
     490,   988,     0,     0,     0,     0,     0,     0,   461,   462,
       0,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,     0,     0,
     486,     0,   495,   487,     0,     0,   491,     0,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,   490,     0,   492,     0,   477,   478,   479,   480,
     481,   482,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,     0,   483,   484,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   990,     0,     0,     0,     0,     0,   486,     0,     0,
     487,     0,     0,  1294,  1295,  1296,   492,     0,     0,   276,
    1297,  1298,    33,     0,     0,     0,     0,     0,     0,     0,
       0,  1299,  1300,     0,   493,     0,   477,   478,   479,   480,
     481,   482,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,   483,   484,   485,     0,   489,     0,
       0,     0,   490,   462,     0,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,     0,  1294,  1295,  1296,     0,     0,     0,   276,
    1297,  1298,    33,     0,     0,     0,     0,     0,   491,     0,
       0,  1299,  1300,   476,     0,     0,     0,     0,     0,     0,
       0,   991,     0,  1301,   486,   494,     0,   487,     0,   495,
       0,     0,     0,     0,     0,     0,   492,     0,     0,     0,
     488,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,   493,   489,     0,     0,     0,   490,
       0,     0,     0,     0,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,     0,  1301,     0,   491,     0,     0,   476,     0,
       0,     0,     0,     0,   486,     0,     0,   487,   994,     0,
     477,   478,   479,   480,   481,   482,     0,     0,     0,     0,
       0,     0,     0,   492,     0,     0,     0,     0,   483,   484,
     485,     0,     0,     0,     0,   494,  1294,  1295,  1296,     0,
       0,   493,   276,  1297,  1298,    33,     0,   488,     0,  1120,
       0,     0,     0,     0,  1299,  1300,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,   477,   478,   479,   480,   481,   482,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,   484,   485,     0,   477,   478,   479,   480,   481,
     482,   495,   491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   483,   484,   485,     0,     0,     0,  1120,
       0,     0,   494,     0,     0,     0,     0,   488,     0,     0,
     492,     0,     0,     0,     0,     0,  1301,     0,     0,     0,
       0,     0,   489,     0,     0,     0,   490,     0,   493,     0,
       0,     0,     0,  2694,     0,  1294,  1295,  1296,     0,     0,
       0,   276,  1297,  1298,    33,     0,     0,     0,   486,     0,
       0,   487,     0,  1299,  1300,     0,     0,     0,     0,     0,
       0,     0,   491,     0,     0,     0,     0,     0,   495,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1294,
    1295,  1296,     0,     0,     0,   276,  1297,  1298,    33,     0,
     492,     0,     0,     0,     0,     0,     0,  1299,  1300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   493,   494,
       0,   486,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   486,  1302,  1301,   487,     0,     0,     0,
       0,     0,  1120,     0,     0,  1294,  1295,  1296,     0,     0,
       0,   276,  1297,  1298,    33,     0,     0,     0,     0,     0,
       0,     0,     0,  1299,  1300,  1303,     0,     0,  2695,     0,
       0,   488,     0,     0,     0,   495,     0,     0,     0,  1301,
    2696,  1305,     0,     0,     0,     0,   489,  3207,  3208,   494,
     490,     0,     0,   276,  1297,  1298,    33,     0,     0,     0,
       0,     0,     0,     0,  1302,  1299,  1300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1306,     0,     0,     0,     0,   491,     0,     0,     0,
       0,     0,     0,  1307,   488,  1303,     0,     0,  1304,     0,
       0,     0,     0,     0,     0,  1301,     0,     0,     0,   489,
       0,  1305,     0,   490,   492,   495,   488,     0,     0,     0,
       0,  1120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,   493,     0,  1308,   490,     0,  1296,  2002,     0,
       0,   276,  1297,  1298,    33,     0,     0,  3209,     0,   491,
       0,  1306,     0,  1299,  1300,     0,     0,     0,     0,  1136,
    1137,  1138,  1139,  1307,     0,  1120,     0,  1309,     0,     0,
       0,   491,     0,  1310,     0,     0,     0,   492,     0,     0,
       0,     0,  1311,  1312,     0,  1313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,     0,  1314,  1315,   492,
       0,     0,     0,     0,  1308,  1316,     0,  1302,  1317,     0,
       0,     0,     0,   494,     0,     0,   297,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1120,     0,     0,     0,  1301,     0,  1309,  1303,     0,
       0,  1304,     0,  1310,     0,     0,     0,     0,     0,     0,
       0,     0,  1311,  1312,  1305,  1313,     0,     0,     0,   276,
    1297,  1298,    33,     0,     0,     0,     0,  1314,  1315,     0,
       0,  1299,  1300,  1120,     0,  1316,   494,     0,  1317,   495,
       0,     0,  1140,     0,     0,     0,   297,     0,     0,     0,
    1141,     0,     0,  2531,  1306,     0,     0,     0,   494,  1142,
       0,     0,  1143,     0,     0,     0,  1307,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,     0,  1302,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,     0,     0,  1144,     0,  1308,     0,     0,
       0,     0,  1145,  3209,     0,     0,     0,  1303,     0,     0,
    1304,  1120,     0,     0,   495,     0,     0,     0,     0,     0,
    1302,     0,     0,  1305,     0,     0,     0,     0,     0,     0,
    1309,     0,     0,     0,     0,     0,  1310,     0,     0,     0,
       0,     0,     0,     0,     0,  1311,  1312,     0,  1313,     0,
       0,  1303,     0,     0,  1304,     0,   202,     0,     0,  1146,
    1314,  1315,  3653,  1306,     0,     0,     0,  1305,  1316,     0,
       0,  1317,   203,   204,     0,  1307,     0,     0,     0,   297,
       0,     0,   205,     0,  1147,     0,  2329,     0,     0,     0,
       0,  1148,     0,  1149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1150,     0,     0,     0,  1306,     0,     0,
       0,     0,     0,     0,     0,     0,  1308,  1303,     0,  1307,
    1304,     0,     0,     0,     0,     0,     0,     0,  1302,  1120,
       0,  1151,     0,  1305,     0,     0,     0,     0,     0,  1152,
       0,     0,  2562,  2563,  2564,  2565,  2566,  2567,     0,  1309,
       0,     0,     0,     0,     0,  1310,     0,     0,     0,  3210,
    1308,     0,  3211,     0,  1311,  1312,     0,  1313,     0,     0,
       0,     0,     0,  1306,     0,  3212,  1153,     0,     0,  1314,
    1315,     0,     0,     0,     0,  1307,     0,  1316,     0,     0,
    1317,     0,     0,  1309,     0,     0,     0,     0,   297,  1310,
    1154,     0,     0,     0,     0,     0,     0,     0,  1311,  1312,
       0,  1313,     0,     0,     0,  3214,  1302,     0,     0,     0,
       0,     0,     0,  1314,  1315,     0,  1308,  3215,     0,     0,
       0,  1316,     0,     0,  1317,     0,     0,  1155,     0,  2568,
       0,     0,   297,     0,     0,     0,     0,  1303,  1156,     0,
    1304,     0,     0,   206,     0,     0,     0,     0,     0,  1309,
       0,     0,     0,  1305,     0,  1310,     0,     0,  3216,     0,
       0,     0,     0,     0,  1311,  1312,     0,  1313,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1314,
    1315,     0,   207,     0,     0,     0,     0,  1316,     0,     0,
    1317,     0,     0,  1306,     0,     0,     0,  3217,   297,     0,
       0,   208,   209,   210,   211,  1307,     0,     0,     0,  3218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   212,
       0,  3219,  3220,     0,  1302,     0,     0,     0,     0,  3221,
       0,     0,  3222,     0,  3624,     0,  1157,  1158,  1159,     0,
     297,   213,     0,     0,     0,     0,  1308,     0,     0,  1160,
       0,     0,     0,   214,     0,  3210,     0,     0,  3211,     0,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,  3212,     0,     0,     0,     0,     0,     0,     0,  1309,
     216,     0,     0,     0,     0,  1310,     0,     0,     0,     0,
     217,  3625,     0,     0,  1311,  1312,     0,  1313,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,  1314,
    1315,  3214,     0,     0,     0,     0,  3626,  1316,     0,     0,
    1317,     0,     0,  3215,     0,  3627,     0,     0,   297,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,     0,     0,     0,
       0,     0,  1161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3628,  3216,     0,  2569,     0,   220,     0,
       0,  3629,     0,     0,     0,     0,     0,     0,     0,  2570,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
     222,     0,     0,   223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   224,  3218,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,  3219,  3220,     0,
       0,     0,     0,     0,     0,  3221,     0,   226,  3222,     0,
       0,  2571,     0,     0,     0,     0,   297,  2572,     0,     0,
       0,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,     0,  3630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2574,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2575,  2576,     0,     0,     0,     0,  2577,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2578,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2579,     0,
       0,  2580,  2581,     0,     0,     0,  2582,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2583,     0,     0,     0,     0,     0,     0,
       0,     0,  3631,     0,  2584
};

static const short yycheck[] =
{
       3,     4,     5,   172,   396,     8,   106,  1175,   657,  1057,
    1294,  1295,  1135,   261,   262,  1170,   263,   264,    69,  1004,
     268,   720,    45,   127,   191,  1150,   799,   797,   589,  1467,
    1382,   592,  1132,  1375,  1131,   546,   599,    40,  1146,  1147,
      54,  1149,  1407,  1151,  1152,   247,   174,  2124,   781,    52,
    1938,    54,  1903,  1904,  2518,  1329,  2364,  1331,  2366,  2069,
    2381,  2327,    65,   572,  2379,  2450,   117,     5,    91,    72,
      27,    27,   172,    76,    77,     5,  1425,    80,    81,    27,
    2248,  2673,    85,    86,  2915,  2916,  2917,    20,  2072,  2063,
      25,   191,    27,     5,    27,     5,    27,  2561,   149,     5,
     641,     5,   105,  2011,  2012,  2013,  2014,     5,    26,    27,
       5,   756,    27,     5,  2002,     8,     5,    19,   817,  2918,
     123,     5,    27,   126,    26,    19,  1226,     5,   131,     5,
    2636,   153,    26,     6,   238,   239,  1259,   265,     5,     5,
    1240,   269,    25,   271,    27,   273,   274,   275,     5,     5,
      24,     5,    26,   322,   282,    19,    27,   787,   286,   287,
      24,    25,    26,   116,   116,     9,    10,    27,    12,    13,
      14,    15,    16,    17,    62,   226,   717,   228,    24,    25,
      26,    27,  1230,    26,    24,    25,    26,   728,     5,    47,
     193,    25,    26,    27,     9,    10,     6,    12,    13,    14,
      15,    16,    17,    45,    20,   135,   136,     5,    20,    25,
     122,    27,   124,    25,   126,    27,     5,     5,    24,    25,
      26,    27,   322,    27,     5,    25,   326,    27,  2688,     5,
    2690,    25,   235,    27,     6,    25,     5,    27,   241,    25,
     214,    27,   783,  2260,   191,   786,    25,    27,    27,    91,
     253,   139,   140,    27,   795,     5,   259,   260,   261,   262,
     263,   264,     5,     5,   204,   268,    24,    25,    26,    27,
      23,    27,     5,    24,    25,    26,    27,    99,   100,   101,
     102,   103,   444,   141,   142,   204,   400,   349,  3002,   217,
    1157,  1158,   343,   328,     5,   446,   192,   193,   349,  2980,
    2302,  2982,    23,  2305,  2985,   197,   144,   435,   395,  2654,
     438,   290,   315,   316,    27,    27,  2557,     5,     5,   590,
     446,     5,   325,   483,     5,  1422,   244,   455,   456,   457,
     458,   579,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,    27,
     517,   599,   403,   555,   598,   674,   511,  2623,     5,   487,
     488,    25,   641,    27,   492,    25,   494,    27,   639,  1524,
       5,     5,   714,   721,  2695,  2452,  2721,    10,    10,   507,
     508,   509,   510,     5,   663,   217,   514,    24,    25,    26,
      27,   700,   446,   735,     5,   628,     0,   745,  1131,   960,
      18,    19,    20,    21,    22,   446,   748,     5,  1181,   728,
     298,    25,   581,    27,     5,   641,     5,   517,  1466,     5,
     482,  1194,   328,    56,   478,   669,    18,    19,    20,    21,
      22,  2375,  2376,  2377,   395,   668,  2380,   663,   244,   328,
     483,   691,   692,   791,   244,   228,   696,   697,  2356,     5,
     244,   446,     5,   801,   244,     5,   804,   766,   244,   709,
     808,     5,   306,     5,     5,     5,   814,   510,   816,  3445,
       5,     5,   400,   430,     5,   459,    19,     5,   977,   729,
    3456,   581,   732,    26,    31,   536,   244,     5,   738,   656,
     641,   306,   742,   244,     5,     5,   746,    29,    27,  2443,
     750,     5,     5,   506,   754,   755,    25,   757,    27,    38,
     760,   490,   762,   763,   764,   641,   671,   677,     5,    27,
     770,   205,     5,   773,   547,   548,   774,     5,   302,     5,
     780,   244,   244,   647,   405,   288,   539,   787,     5,   542,
     493,   663,   325,   630,   794,   792,   793,   550,   710,     5,
       5,     5,   446,     5,   118,   805,   656,     5,     5,   809,
       5,     5,   429,   813,   567,     5,   569,   288,   400,   819,
       5,     5,   822,   446,   821,   578,   579,   824,     5,   582,
     244,   409,   426,   427,   244,   620,   108,   109,  2605,     5,
     302,     5,   446,   489,   337,   337,   599,  3278,     5,     5,
     641,   479,   446,   446,  2455,   561,  2847,   244,   668,   449,
     515,   426,   427,   479,   205,     5,   138,   139,   140,   566,
       5,   299,  2888,   483,   598,   647,    28,    25,  1258,    27,
     159,   405,    30,   439,   312,   553,   446,   481,   578,  2641,
     119,   594,   594,  2951,    27,   296,   641,  1514,   446,   405,
    3364,    25,   523,    27,  3453,  1428,   613,   446,   446,   578,
      27,   591,   479,  2607,   417,   446,   481,  1440,   596,   630,
    2991,   303,  1183,  2617,   446,    27,   679,   446,  3142,   483,
     209,   684,   685,   686,   687,   688,   689,   690,   606,  1422,
     693,   694,   695,   483,   444,   698,  3160,   700,   449,  3205,
     703,   629,   705,   479,   608,   547,  2594,   602,    25,  2051,
     608,   714,   605,   446,   620,   244,  2884,   246,   602,  1368,
    2072,  1069,   725,   726,  1285,   244,   641,  1288,  1289,   605,
    3115,   620,   735,   539,  3119,   446,   414,   668,   741,   641,
    3246,   598,   598,  3058,   747,   748,   749,   641,   678,   523,
     753,  2761,  2101,   756,  2103,   758,   759,   669,  3066,   669,
    3068,   718,   718,   766,   608,   677,   769,  2711,  1277,  2743,
     718,   774,   775,  3088,   777,   713,   668,  2215,   781,  2763,
     663,   784,  2147,   718,  1429,   718,   674,   790,   567,   792,
     793,   479,   479,   608,   797,   798,   799,   671,   479,   446,
     803,    27,   720,   806,  3264,  1304,  2603,   671,   811,   441,
     446,   443,   449,   635,   343,   818,   602,   820,   821,   677,
     823,   824,    23,   826,   827,   671,  3418,  1175,   628,   663,
     674,   671,   421,  2914,  2915,  2916,  2917,  1185,  3669,  1187,
    3432,    28,    29,   637,   479,   479,   244,   663,   446,   328,
     528,   663,   690,   691,   692,   693,   694,   479,    30,   674,
     446,   479,    34,   523,   992,   671,   544,   995,   479,   483,
     244,  2815,   289,   877,   590,  1003,  1004,   244,   442,   389,
     724,   725,   511,   412,  1276,  1135,   523,   479,  3231,   397,
     446,   420,   290,   446,   671,   424,   446,   405,   406,     5,
     446,   465,   446,   446,   446,   446,   446,   691,   692,   724,
     725,   446,   446,   671,   231,   446,   299,   506,   446,   409,
     671,   400,   430,   639,     0,   433,   511,   930,   446,   312,
     440,   460,    25,   522,    27,   446,  2914,  2915,  2916,  2917,
      16,   449,   446,   446,   380,   729,  2797,   299,   732,  3413,
       5,    25,  3260,    27,  3262,  3263,  2900,   129,   742,   446,
     312,  1012,   746,   446,   414,   444,   750,    14,   446,    25,
     446,    27,  3564,   757,   977,   395,   565,   446,   762,   446,
     764,   380,  3290,  1546,   548,   507,   770,    26,    27,   773,
     446,   446,   446,    20,   446,   415,   780,   526,   446,   446,
      27,   446,   446,   787,   676,   641,   446,  1257,  1258,  1259,
     794,   446,   446,   411,  1017,   604,  1019,   387,   244,   446,
    1561,   805,  1533,   483,   483,   809,  3347,   699,  2153,   813,
     446,   414,   446,   212,   671,   819,   565,   299,   822,   446,
     446,   358,   671,  2140,   633,   553,   483,   364,   365,   366,
     312,  1054,   511,   642,  1057,  2329,   446,    25,   452,    27,
     589,   446,   414,    18,    19,    20,    21,    22,   421,   386,
    1073,   593,   439,  1076,   511,  2427,   640,  3563,   528,  2431,
    1282,  3567,  1430,  1431,  1432,   414,   671,   288,   652,   653,
    3433,  3434,   490,  2890,  2891,   641,   660,   533,   606,  1447,
     483,   518,  2202,   511,   633,   613,    25,   483,    27,  3053,
     590,  3055,  1115,   642,   636,    26,    27,  1120,   290,  2393,
    2394,   519,    26,    27,   542,   336,  3207,  3208,  1131,   167,
    3211,   483,   550,   312,   533,    26,    27,  3458,   349,   373,
     557,   620,  1145,  1146,  1147,   528,  1149,   299,  1151,  1152,
    1154,   244,   414,   506,  1157,  1158,  3422,  1161,   483,   639,
     312,   544,    25,   574,    27,  2288,   483,  1515,   483,   522,
     244,   350,   641,   511,   491,   511,   528,   494,  1181,   260,
     261,   262,    25,   483,    27,   502,  1534,   637,   244,  1192,
     483,  1194,   544,   336,  1441,  1443,   566,   726,   727,   528,
    1203,   478,  2187,  1206,  1552,   244,   349,   577,  1211,    25,
     630,    27,   565,   439,   344,  1563,   417,   677,   483,   190,
     537,   700,   701,   702,    26,    27,   356,  1230,  1231,  3207,
    3208,  3271,   711,  3211,  3274,   414,  1239,  3277,    19,   411,
     676,   421,   483,    24,   638,    26,   676,   641,  3192,   428,
     676,   604,  1255,  1256,     5,   572,    20,     8,  3202,   695,
     696,   679,   414,    27,    26,    27,   528,  1371,   698,   699,
    1374,   482,   698,   699,   591,   592,   244,   676,  1281,   715,
     633,   252,   544,   254,   483,   602,  1455,   459,   483,   642,
     607,  1294,  1295,   670,  1541,  1542,   695,   696,  1546,   270,
     677,  1304,   523,   510,   511,   641,  3194,   278,   637,  3617,
     531,   282,    20,    25,  1317,    27,   715,    20,   490,    27,
     732,   218,  1325,   220,    27,   244,   506,   663,   483,   646,
     218,   483,   220,   244,   746,   671,   307,   483,   750,   482,
     244,  3285,   522,  2377,  3211,  2758,  2380,   519,   245,   528,
     762,  1135,    20,   244,   805,  1455,   483,  3438,   809,    27,
     483,   678,   813,  3444,  3445,   544,  3447,  3448,  3449,  3450,
     691,   692,   453,  1376,   483,  3456,   528,  1380,  1381,  1382,
      24,   244,    26,  1397,   483,   565,  2541,   510,   511,  1392,
    1393,  1394,   544,  2735,  1397,  1398,  1399,  1400,  1401,  1402,
    2674,   244,  2676,    24,  2678,    26,    20,  2140,  1411,  3552,
    3553,  2763,  2185,    27,    25,    20,    27,  1978,   483,  1422,
    1981,  1424,    27,  1426,   604,  1428,  1429,   324,   244,    25,
     327,    27,  2480,  1436,  1437,  1438,   324,  1440,  1441,   327,
    1443,  1444,   244,   292,    20,  3485,    25,   221,    27,  1452,
     573,    27,   349,   633,   483,   421,  1459,  1460,   155,   156,
    3438,   349,   642,  1466,  1467,   483,  3444,  3445,   483,  3447,
    3448,  3449,  3450,  1257,  1258,  1259,   483,  2176,  3456,  2252,
     483,  3425,   244,    25,   533,    27,  2609,   483,  2258,  3570,
     483,   446,  3573,  3574,  3575,  3576,  3639,    24,  3641,    26,
     349,  2914,  2915,  2916,  2917,  2004,   483,  2006,  1511,  1512,
     820,  1514,  2635,   823,  1517,  1518,   826,  2016,  2017,   218,
      24,   220,    26,    26,  2023,  2024,  2025,  2026,    25,  3437,
      27,  3439,  3440,  3441,  3442,    25,  1539,    27,  1541,  1542,
     506,   391,   483,  1546,  3621,  1548,   245,  1550,  1551,   510,
     511,  2092,   402,    25,   403,    27,   522,   483,   407,   127,
     128,  3638,   130,   131,   132,   483,    24,    19,    26,   292,
    1573,  3438,    24,    25,    26,  3519,    24,  3444,    26,  3660,
    3447,  3448,  3449,  3450,   483,   482,  1155,  1156,  3669,   483,
    1159,  1160,  3570,   483,   482,  3573,  3574,  3575,  3576,   565,
     483,   421,   452,   511,   491,  1309,   483,  1311,  1312,   693,
      30,    26,  3689,   764,    34,   502,   466,   700,   701,    39,
     292,   483,   773,   693,   694,   324,   349,   676,   327,  3706,
      25,   690,    27,   482,   693,   694,   523,   421,   604,   700,
     701,   725,   726,   530,  2753,  2754,   695,   696,   510,   511,
     349,   538,   421,  1900,  1901,   721,   722,   723,  2169,  2432,
     434,   483,   230,  2436,   341,   342,   715,   633,   819,   115,
     238,   822,  2445,   560,   448,    26,   642,   349,   677,  2779,
     403,    25,  3660,    27,   407,   677,   506,   107,  2856,    26,
      24,  3669,    26,   777,   114,  2979,  2980,  2470,  2982,  2824,
    3138,  2985,   522,  3570,   272,   555,  3573,  3574,  3575,  3576,
      26,   573,  2211,   281,    24,    25,    26,   491,   163,   164,
     165,  2821,   506,    26,    24,  2880,    26,    25,   502,    27,
    1424,   403,  1426,  3207,  3208,   407,    26,   506,   522,   671,
     160,   161,   310,   311,   190,   565,  3098,  2095,   168,   523,
     578,   483,   483,   522,   483,  2316,   530,   483,   483,   482,
     697,  2322,  2323,  2111,   538,    20,    21,   483,   483,   483,
      18,    19,   709,   483,    26,   473,    24,    25,    26,    27,
      26,   565,   483,   482,   604,    26,   560,   355,    36,    37,
    2138,   511,    26,  3660,  3207,  3208,   565,  2145,  3211,    26,
      26,   738,    26,    26,   671,   112,   252,  3245,   254,   446,
     482,   671,   483,   633,   214,   416,    26,   754,   755,   446,
     604,   483,   642,   760,   270,   483,   763,  2175,  2327,   229,
     230,   399,   278,   479,     5,   604,   282,  2336,   238,   446,
    2339,  2340,  2341,  2342,   483,   979,  2194,  2832,   982,   633,
     984,   985,   986,   987,   988,  2840,  2841,   446,   642,  3272,
     446,   307,  3275,   637,   633,   446,  1970,   193,   446,   643,
     118,   197,   272,   642,    18,    19,    20,    21,    22,  2129,
     446,   281,   523,   483,   677,   453,    20,  2428,    20,   483,
     145,   146,   147,   148,   149,   150,  1899,  1900,  1901,  2146,
     483,   446,     5,  1906,  1907,   664,   665,   666,   667,  2037,
     310,   483,   511,    26,   675,   671,    26,   446,   446,    18,
      19,    20,    21,  1926,  1927,   312,  1929,  1930,   479,   416,
    1933,  1934,    30,  1936,    20,    26,  1939,    26,    26,    26,
    2481,    26,  2046,    26,    26,   641,   446,   446,     9,    20,
      21,    26,   446,   446,   446,   355,    26,    18,    19,    20,
    1963,     5,   446,    24,    25,    26,    27,    20,    26,   483,
    1054,  1974,    26,   446,    26,    36,    37,    26,   173,  3417,
     671,     5,   446,   677,  2232,  2233,    26,   446,   356,  2530,
     446,  2042,  1076,   446,  3278,   446,   244,   446,     5,   399,
    2247,  2004,   422,  2006,   446,  2255,   675,   446,   483,    26,
    2783,   677,   446,  2016,  2017,  2018,    26,   641,  2021,   446,
    2023,  2024,  2025,  2026,   677,  3438,    25,    25,    25,   446,
      25,  3444,  3445,  2036,  3447,  3448,  3449,  3450,  2288,   446,
    2168,   446,   446,  3456,   446,  2818,   145,   146,   147,   148,
     149,   150,   446,   446,   446,  2058,   446,   118,   446,  2187,
    2063,   356,  3475,   446,   446,   675,  2069,   446,   671,  2072,
     483,     8,   676,  2421,   145,   146,   147,   148,   149,   150,
     275,   671,   479,   647,   531,   190,   512,  2090,   283,  2437,
    2438,  2439,  2440,  2096,   289,  2656,   291,   517,  2659,  3147,
    2661,  2662,   320,     5,   669,   511,   669,   302,   647,   473,
    2458,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   512,  2125,   710,  2623,   710,   382,   671,   663,   648,
      18,    19,    20,    21,   671,   330,  2139,  2140,     5,     5,
    2143,  2144,   473,  2146,   483,   483,   400,   252,   483,   254,
     483,   346,   641,   483,   630,     8,   351,  3570,  2161,   627,
    3573,  3574,  3575,  3576,    14,   270,  3151,     5,   363,   710,
      25,     5,   710,   278,   473,   370,  2524,   282,   483,   483,
    2183,  2680,  2185,   244,    26,    26,  3599,   119,   293,   609,
     144,   511,   671,    26,   483,   483,  2695,   641,   483,   483,
     483,   449,   307,  2206,   483,  2208,  2209,  2706,  2211,   483,
     483,  2214,  2215,  3368,   473,   511,    26,     5,   647,   483,
     483,     5,  3377,   677,    47,   483,   483,   677,   713,  2232,
    2233,   406,   480,   676,   608,   483,     5,   668,    18,  3394,
      19,   207,   446,    25,  2247,   438,   674,  3660,   496,  2252,
    2253,  2254,   641,   630,   534,  2258,  3669,   145,   146,   147,
     148,   149,   150,  2266,   534,     5,   598,   205,   671,   689,
     598,    26,   453,   377,   598,   523,    26,   697,  2626,   446,
    2628,    26,   446,   446,   446,   523,   671,   348,   536,   446,
    2293,   677,   578,   677,  2463,   483,   483,   483,  2301,  2302,
     548,   483,  2305,   483,   111,     5,   715,   446,  3007,  3008,
    3009,   671,  3011,  3012,  3013,  3014,  3015,  3016,  1402,   641,
     641,  3020,   671,   518,  2327,   483,   598,  1411,   523,   677,
       5,     5,  3105,  2336,  3457,   530,  2339,  2340,  2341,  2342,
    2343,   589,     5,  2346,   631,  2129,     5,  2350,  2351,   668,
     535,  2354,   677,  2603,  1438,   483,   671,   552,  2857,  2609,
    3133,     5,   557,  2463,   676,     8,    26,   373,    26,   272,
     119,     5,  2375,  2376,  2377,     5,   231,  2380,  2381,  2382,
     628,   381,  2385,   446,   415,  2635,  3541,   483,   449,  2888,
     483,    14,   640,   719,   720,   648,   677,   711,   598,   602,
       5,    26,   153,   483,   652,   653,   671,   483,   677,   598,
     676,  2414,   660,  2416,  2417,   663,  2419,  2420,     5,   480,
    2423,   446,   483,   671,  2427,   446,   677,   676,  2431,  2432,
    1267,   479,     5,  2436,   495,   496,     5,   446,     5,  2442,
    2443,  2789,  2445,  2446,  2792,   690,  2449,  2450,   423,   670,
      26,   387,   479,   513,   513,   483,     5,   483,   671,     5,
     483,   483,   523,   483,   483,   483,   671,  2470,   483,     8,
     511,  2255,   671,     5,  2477,   536,   628,  2480,   605,   400,
     381,    25,   400,   400,   415,   478,  2489,   548,  2987,   483,
    2493,   817,   671,     5,  3649,   511,     5,   511,    26,     5,
     702,   827,  3550,   358,  2288,     5,    25,    14,  2856,   364,
     365,   366,    14,    26,   647,  2518,  3624,  3625,  3626,  3627,
    3628,  3629,   647,   668,   483,     5,   605,     5,   589,    26,
     483,   386,   446,   446,   677,   446,   446,   446,     6,  2542,
       7,   322,   500,     5,    26,   671,   446,   446,   677,    26,
      26,    26,    26,   671,   671,   446,    20,     5,   328,     5,
       5,   622,   618,   598,     5,     8,   719,   628,     5,   446,
     671,   446,   623,   523,     5,   483,   637,   638,     5,   640,
     677,   265,   677,   675,   446,   598,   446,    26,   446,  2592,
     483,   652,   653,   677,   483,     5,   677,     5,  3371,   660,
     677,    25,   663,   677,  2607,    25,   675,    25,   670,   499,
     671,    25,  2615,  2616,  2617,    26,  3389,  2620,  2621,    25,
    2623,    26,  2870,    26,  2872,    26,    26,    26,   350,   446,
     446,  2654,    26,  2636,  2637,     5,   491,  2640,  2641,   494,
    2890,  2891,  3291,   446,   446,  2814,   483,   502,  2004,   520,
       5,   977,   483,   446,   602,  3640,     8,   294,    26,    25,
     479,   446,   400,   493,    20,   196,   605,     5,   483,   483,
     483,   483,   483,     5,   483,   483,   265,  2680,    14,   446,
     446,     5,   537,   511,    26,  2688,   446,  2690,  2855,   494,
    2693,    26,  2695,  3254,   446,  3256,  3257,    26,  2721,  2827,
     446,    26,   429,  2706,  2832,   483,    26,    26,  2711,  2712,
    2713,    26,  2840,  2841,  2814,   620,   446,   572,   446,   294,
     446,   483,  2725,   400,  3772,   446,   598,   295,   511,   493,
     483,  1057,   446,    14,   446,   446,   591,   592,     7,   293,
    2743,   293,   446,    26,   677,   446,   483,   602,   447,   671,
     446,   627,   607,   446,    26,  2855,    40,    25,  2761,  3532,
    2763,   479,   295,   483,   446,   446,   446,   446,   446,   511,
       5,    26,    26,  2776,   446,   671,   671,     5,  3126,   446,
    2783,   479,  3281,    26,  3283,   671,  2835,   479,  2776,  3699,
    2514,   646,  1003,  1553,  2195,    29,  2446,  2808,    31,  2452,
     113,   354,   345,   117,   208,  2808,   660,  2810,  2041,  2812,
     355,  2042,  2815,  2816,  3162,  2818,   213,   226,   384,  2603,
     536,   105,   106,   678,  1293,  2609,   602,   383,   567,  3689,
    2833,  2095,  2835,  2836,  2837,   569,   995,   417,   803,  1264,
    2306,  2299,  2439,  1927,  2145,  1929,  1930,  2850,  1899,  1933,
    1934,  2635,  2859,  2222,  2857,  1939,    48,  3172,  2214,  1902,
    3743,  3253,  2538,  2442,  2242,  3385,  1443,  2870,    16,  2872,
      20,    21,    22,    91,    40,  3312,  3123,    40,    22,  2882,
    2883,  2200,   932,  2206,  1564,  2888,   759,  1907,   172,  3136,
     326,  2209,  1512,  3309,  3494,  1019,  3706,  2900,    48,   784,
    1426,  1437,  1231,  2857,  1230,  3047,  3504,   191,  1510,  1534,
    3045,  2914,  2915,  2916,  2917,  2918,  2919,  2175,   454,  3029,
    3103,  2724,  3365,  3422,  3363,  2928,  3356,  3095,  2075,  2431,
    2933,  3715,  2058,  2603,  2018,  3285,  2385,  3436,  2277,  1941,
    1941,  3204,  2622,  3052,  3519,  3086,  2346,  2968,  3117,  2265,
    2969,  3275,  2693,   145,   146,   147,   148,   149,   150,  3599,
    3328,  3074,  1926,  2725,  2746,  2968,  2969,   609,  1294,  1295,
       8,   163,   164,   165,  3761,   259,  2979,  2980,  1304,  2982,
    2712,  3206,  2985,  1260,  2987,  2713,  2017,  2901,  2991,  3283,
    2694,  2016,  2696,  1921,  3560,   145,   146,   147,   148,   149,
     150,  2616,  3201,  3436,  3455,  1894,  1256,  2816,  3444,  1120,
    2036,  1452,  2814,   163,   164,   165,   545,  3117,  1442,    -1,
    1460,  2463,    -1,  3151,    -1,  3373,    -1,    -1,  3031,    -1,
      -1,   315,   316,  3594,  3595,    -1,    -1,    -1,   322,    -1,
      -1,  3044,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3053,  3054,  3055,    -1,    -1,  2139,    -1,    -1,    -1,    -1,
    3408,    -1,    -1,    -1,    -1,    -1,    -1,  3566,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3079,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3091,  3092,
      -1,    -1,  3095,    -1,    -1,  3098,    -1,    -1,    -1,    -1,
      -1,    -1,  3105,  3353,  3603,    -1,  2890,  2891,    -1,    -1,
      -1,   303,  3115,  3363,   306,  3118,  3119,    -1,    -1,  3367,
    3123,    -1,    -1,    -1,  1961,  1962,    -1,    -1,    -1,    -1,
    3133,  1968,    -1,  3136,    -1,  3138,    -1,    -1,    -1,    -1,
    1466,    -1,    -1,    -1,  3147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,   306,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2266,  3186,    -1,    -1,    -1,    -1,    -1,  3192,
      15,    16,    17,    18,    19,    20,    21,    22,  3201,  3202,
      -1,  3204,  3205,    -1,  3207,  3208,    -1,  3457,  3211,    -1,
    2914,  2915,  2916,  2917,    -1,    -1,  3715,    -1,    -1,  3222,
      -1,    -1,   506,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   517,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3245,  3246,    -1,    -1,    -1,    -1,    -1,   441,
      44,    45,    46,   445,    -1,    49,    -1,    51,    52,    -1,
      -1,  3264,  2346,    -1,    -1,    -1,    -1,    -1,    -1,  3272,
      -1,    -1,  3275,    -1,    -1,  3278,   426,  2981,  3281,  2983,
    3283,    -1,  3285,    -1,    -1,    -1,    -1,  3635,    -1,   481,
      -1,   441,    -1,    -1,    -1,   445,    -1,   581,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,  3309,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,
     145,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,   481,    -1,    -1,    -1,   527,    -1,    -1,   163,   164,
     165,  2178,    -1,    -1,  3347,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2442,   509,
      -1,    -1,    -1,    -1,  3367,    -1,    -1,    -1,  3371,    -1,
      -1,    -1,   656,    -1,    -1,    -1,    -1,   527,    -1,    -1,
      -1,  2218,    -1,    -1,    -1,    -1,  3389,    -1,    -1,  3556,
    3738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     684,   685,   686,    -1,   688,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3417,    -1,   608,    -1,    -1,  3422,
      -1,   705,  3425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3436,    -1,  3438,    -1,    -1,    -1,    -1,
      -1,  3444,  3445,    -1,  3447,  3448,  3449,  3450,    -1,    -1,
    3453,    -1,  3455,  3456,    -1,  3458,  3556,   741,   608,    -1,
      -1,    -1,    -1,   747,    -1,   749,    -1,    -1,    -1,   753,
      -1,    -1,   756,    -1,    -1,   759,    -1,    -1,   303,    -1,
      -1,   306,   674,    -1,    -1,   769,    -1,    -1,    -1,    -1,
      -1,  3494,    -1,    -1,    -1,    -1,  3499,    -1,  3501,    -1,
     784,    -1,    -1,  3207,  3208,    -1,   790,  3211,  2592,    -1,
      -1,    -1,  3640,   797,   798,   799,  3519,    -1,    -1,   803,
      -1,    -1,    -1,    -1,   674,    -1,    -1,   811,    -1,  3532,
     324,    -1,    -1,   327,    -1,   329,    -1,  2621,    -1,    -1,
      -1,    -1,    -1,   827,    -1,    -1,    -1,  3550,    -1,    -1,
      -1,    -1,    -1,  2637,    -1,   349,    -1,  3560,  2914,  2915,
    2916,  2917,    -1,  3566,    -1,   359,    -1,  3570,    -1,    -1,
    3573,  3574,  3575,  3576,    -1,  3578,    -1,    -1,    -1,    -1,
     324,  1907,    -1,   327,    -1,   329,   380,    -1,    -1,  3592,
      -1,    -1,    -1,    -1,    -1,    -1,  3599,    -1,    -1,    -1,
    3603,   426,    -1,    -1,  2688,   349,  2690,    -1,    -1,   403,
      -1,    -1,    -1,   407,    -1,   359,   441,    -1,    -1,    -1,
     445,  3624,  3625,  3626,  3627,  3628,  3629,    -1,    -1,    -1,
      -1,    -1,    -1,  3636,    -1,    -1,   380,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   481,  3660,    -1,   403,
      -1,    -1,    -1,   407,    -1,    -1,  3669,    -1,    -1,    -1,
      -1,  2508,  2509,  3457,    -1,    -1,    -1,    -1,  2004,    -1,
    2006,    -1,  2519,    -1,   509,    -1,    -1,    -1,   482,    -1,
    2016,  2017,    -1,    -1,    -1,    -1,    -1,  2023,  2024,  2025,
    2026,    -1,   527,    -1,    -1,    -1,  2543,  2544,  2545,  2546,
    2547,  2548,  3715,    -1,  3717,    -1,  2553,  2554,  2555,  2556,
      -1,    -1,    -1,  2560,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2816,    -1,  3438,    -1,    -1,    -1,   482,    -1,
    3444,  3445,    -1,  3447,  3448,  3449,  3450,    -1,    -1,    -1,
      -1,    -1,  3456,    -1,    -1,    -1,  3759,  3760,  3761,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3772,
      -1,  3774,    -1,  1057,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,  1073,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2642,  2643,    -1,    -1,    -1,
      -1,    -1,  2649,  2650,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,  1115,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,
    2176,  3207,  3208,    -1,    -1,  3211,    -1,    -1,    -1,    -1,
      -1,  1145,  1146,  1147,    -1,  1149,  3570,  1151,  1152,  3573,
    3574,  3575,  3576,  1157,  1158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1181,    -1,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
    1194,   113,    -1,    -1,    -1,    -1,  3272,    -1,    -1,  3275,
      -1,    -1,  1206,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1230,  1231,    -1,    -1,
     152,    -1,    -1,    -1,    -1,  1239,  3660,    -1,    -1,    -1,
      -1,  2798,  2799,    -1,    -1,  3669,    -1,    -1,    -1,    -1,
    2807,  1255,  1256,    -1,    -1,    -1,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,  3079,    -1,    -1,    -1,    -1,
      -1,  2327,    -1,    -1,    -1,    -1,    -1,  2844,  2845,    -1,
    2336,    -1,    -1,  2339,  2340,  2341,  2342,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,  2351,    -1,    -1,   145,   146,
     147,   148,   149,   150,  2871,    -1,  2873,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   246,    -1,   163,   164,   165,    -1,
      -1,    -1,    -1,    -1,    -1,  2381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3436,    -1,  3438,    -1,    -1,    -1,    -1,    -1,  3444,  3445,
      -1,  3447,  3448,  3449,  3450,    -1,    -1,  2934,  2935,    -1,
    3456,  2938,  2939,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
    1424,   343,  1426,    -1,  1428,  1429,    -1,    -1,    -1,    -1,
      -1,    48,  1436,  1437,  2480,    -1,  1440,    -1,    -1,    -1,
    1444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,  1455,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,
    3264,    -1,  1466,  1467,    -1,    -1,   303,    -1,    -1,   306,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3035,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     412,    -1,    -1,    -1,  3570,    -1,    -1,  3573,  3574,  3575,
    3576,    -1,   424,    -1,    -1,    -1,    -1,  1511,  1512,    -1,
    1514,    -1,    -1,  1517,  1518,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3599,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,   460,    -1,
      -1,    -1,    -1,    -1,  1548,    -1,   163,   164,   165,    -1,
      -1,    -1,    -1,   475,   303,    -1,    -1,   306,    -1,  3116,
      -1,   483,    -1,  3120,    -1,    -1,    -1,    -1,    -1,  1573,
      -1,    -1,    -1,    -1,   496,    -1,    -1,  2623,    -1,    -1,
      -1,    -1,  3139,    -1,  3660,    -1,    -1,    -1,    -1,   426,
      -1,    -1,    -1,  3669,    17,    18,    19,    20,    21,    22,
      -1,  3158,    -1,    -1,   441,    -1,    -1,    -1,   445,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   540,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,  2680,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,   565,   481,    -1,    -1,  2693,    -1,  2695,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
    2706,    -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,
      38,    -1,   509,    -1,    -1,    -1,    -1,   426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,   303,    -1,    -1,   306,
     527,    -1,   441,    -1,    -1,    -1,   445,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,   374,   375,    -1,    -1,
      -1,   633,  2758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     642,    -1,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,   412,   113,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,   424,   125,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,
     303,   608,    -1,   306,    -1,    -1,    -1,    -1,   527,    -1,
      44,    45,    46,   451,   152,    49,    -1,    51,    52,    -1,
      -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   726,   727,    -1,    -1,   476,   426,
      -1,  2857,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,   445,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,    -1,    -1,
      -1,    -1,  2888,    -1,    -1,    -1,    -1,    -1,    -1,  3406,
      -1,    -1,  3409,    -1,    -1,    -1,   524,    -1,    -1,   608,
      -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,  2914,  2915,
    2916,  2917,    -1,    -1,    -1,    -1,   244,    -1,   246,    -1,
     303,    -1,    -1,   306,    -1,    -1,   554,    -1,    -1,    -1,
      -1,    -1,   509,   426,    -1,    -1,   564,    -1,    -1,    -1,
      -1,    -1,  1906,  1907,    -1,    -1,    -1,    -1,   441,    -1,
     527,    -1,   445,    -1,    -1,    -1,    -1,   585,    -1,    -1,
      -1,   589,  2968,  2969,    -1,   674,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2979,  2980,    -1,  2982,    -1,    -1,  2985,
      -1,  2987,    -1,    -1,    -1,  2991,    -1,    -1,   481,   617,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,  1963,
      -1,  3007,  3008,  3009,    -1,  3011,  3012,  3013,  3014,  3015,
    3016,    -1,    -1,    -1,  3020,   343,   509,    -1,    -1,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   608,    -1,    -1,   527,    -1,    -1,  3554,    -1,    -1,
      -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,    18,    19,
     378,    -1,    -1,    -1,    24,    25,    26,    27,   441,    -1,
      -1,    -1,   445,    -1,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,  3605,  3606,
      -1,  3608,    -1,  3610,  3611,    -1,   424,   674,   481,    -1,
     324,    -1,    -1,   327,    -1,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,   608,    -1,    -1,    -1,   447,
      -1,   449,    -1,    -1,    -1,   349,   509,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,   359,    -1,   465,    -1,    -1,
      -1,  3147,    -1,    -1,   527,    -1,    -1,   475,   118,    -1,
      -1,    -1,   480,    -1,    -1,   483,   380,    -1,   486,    -1,
    3677,    -1,  3679,    -1,    -1,    -1,    -1,   495,   496,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,
      -1,   674,    -1,   407,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3713,  2161,    -1,    -1,
      -1,  3207,  3208,    -1,    -1,  3211,    -1,   535,   536,    -1,
      -1,    -1,   540,    -1,    -1,  3732,  3733,    -1,    -1,  3736,
     548,  2185,  3739,    -1,    -1,   608,    -1,    -1,    -1,    -1,
      -1,   559,    -1,    -1,    -1,    -1,    -1,   565,    -1,    -1,
      -1,    -1,  2206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2215,    -1,    -1,    -1,    -1,    -1,    -1,   482,    -1,
      -1,   589,    -1,    -1,    -1,    -1,  3272,    -1,    -1,  3275,
      -1,    -1,  3278,    -1,   244,  3281,    -1,  3283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2252,  2253,
    2254,   674,    -1,    -1,  2258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   633,    -1,    -1,    -1,    -1,
      -1,    -1,   640,    -1,   642,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,   652,   653,    -1,    18,    19,  2293,
      -1,    -1,   660,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,  3347,    -1,   671,    -1,    -1,    -1,    38,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   726,   727,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3422,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,   118,    -1,    -1,
    3436,    -1,  3438,    -1,   125,    -1,    -1,    -1,  3444,  3445,
      -1,  3447,  3448,  3449,  3450,    -1,    -1,    -1,    -1,    -1,
    3456,    -1,  3458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,   113,    -1,    -1,  2432,  3475,
     118,    -1,  2436,    -1,    -1,    -1,    -1,   125,    -1,   449,
      -1,  2445,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2463,
     163,   164,   165,    -1,   152,    -1,  2470,    -1,    -1,    -1,
     480,    -1,    -1,   483,    -1,    -1,  2480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2489,   496,    -1,    -1,  2493,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3550,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,  2518,   246,    -1,    -1,    -1,    -1,
    3566,    -1,    -1,    -1,  3570,   535,   536,  3573,  3574,  3575,
    3576,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   548,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3599,    -1,    -1,   244,  3603,   246,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,   589,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,  3660,    -1,    -1,   348,   628,    -1,
      -1,    -1,    -1,  3669,    -1,    -1,    -1,    -1,    -1,    -1,
     640,    -1,    -1,    -1,    -1,    -1,  2640,    -1,    -1,    -1,
      -1,    -1,   652,   653,    -1,    -1,    -1,   378,    -1,    -1,
     660,    -1,    -1,   663,    -1,   343,    -1,    -1,    -1,    -1,
     348,   671,    -1,   113,     5,    -1,    -1,    -1,   118,  3715,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     378,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,  2712,    -1,
      -1,   442,    -1,    -1,    -1,    -1,   447,    -1,   449,    -1,
      -1,    -1,    -1,   426,   412,    -1,  3772,    -1,    -1,   460,
      -1,    -1,    -1,    -1,   465,    -1,   424,    -1,   441,    -1,
      -1,    -1,   445,    -1,   475,    -1,    -1,    -1,    -1,   480,
      -1,    -1,   483,     9,   442,   486,    -1,    -1,    -1,   447,
      -1,   449,    18,    19,   495,   496,    -1,    -1,    24,    25,
      26,    27,   460,    -1,    -1,    -1,    -1,   465,   481,  2783,
      -1,    -1,    38,    -1,    -1,    -1,    -1,   475,    -1,    -1,
      -1,   494,   480,    -1,   244,   483,   246,    -1,   486,    -1,
      -1,    -1,    -1,    -1,   535,   536,   509,   495,   496,   540,
    2814,    -1,    -1,    -1,  2818,    -1,    -1,   548,    -1,    -1,
      -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,   559,  2833,
      -1,  2835,    -1,  2837,   565,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,  2850,    -1,   536,    -1,
      -1,  2855,   540,    -1,    -1,    -1,    -1,   113,   589,    -1,
     548,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,   559,    -1,   561,    -1,    -1,    -1,   565,  2882,  2883,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   343,    -1,    -1,   152,    -1,   348,    -1,
      -1,   589,   633,    -1,    -1,   608,    -1,    -1,    -1,   640,
      -1,   642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   652,   653,    -1,  2928,    -1,    -1,    -1,   378,   660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     671,    -1,    -1,    -1,    -1,   633,    -1,    -1,    -1,    -1,
      -1,    -1,   640,    -1,   642,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,    -1,   652,   653,    -1,    -1,    -1,    -1,
      -1,   674,   660,   314,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   671,    -1,    -1,    -1,    -1,   244,    -1,
     246,    -1,   442,    -1,    -1,   726,   727,   447,    -1,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     460,    -1,   353,    -1,    -1,   465,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   475,    -1,  3031,    -1,    -1,
     480,   372,   373,   483,    -1,    -1,   486,    -1,   726,   727,
    3044,    -1,    -1,    -1,    -1,   495,   496,    -1,     9,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,
      48,    -1,    -1,   424,    -1,   535,   536,   343,    -1,    -1,
     540,    -1,   348,    -1,   435,    -1,    -1,    -1,   548,    -1,
      -1,  3105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
     451,    -1,    -1,  3117,    -1,   565,    -1,    -1,    -1,    -1,
     461,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,  3133,
      -1,    -1,    -1,    -1,  3138,   476,    -1,    -1,    -1,   589,
      -1,    -1,    -1,  3147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   412,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,    -1,   388,   516,    -1,   145,   146,   147,
     148,   149,   150,   633,    -1,    -1,   442,   401,    -1,    -1,
     640,   447,   642,   449,    -1,   163,   164,   165,   539,    -1,
      -1,    -1,   652,   653,   460,    -1,    -1,    -1,    -1,   465,
     660,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,   475,
     561,   671,    -1,   564,   480,    -1,    -1,   483,    -1,    -1,
     486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     496,  3245,    -1,    -1,   585,    -1,    -1,    -1,   589,   463,
      -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   726,   727,    -1,    -1,
     536,    -1,    -1,   244,   540,   626,    -1,    -1,    -1,    -1,
      -1,    -1,   548,    -1,   508,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,    -1,  3309,    -1,    -1,    -1,   565,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,   543,
      -1,    -1,    -1,   589,   548,   303,    -1,    -1,   306,    -1,
      -1,    -1,    -1,    -1,   558,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,   580,  3371,    -1,   583,
     584,    -1,    -1,    33,   588,    -1,    -1,   633,    -1,    -1,
      -1,    -1,    -1,    -1,   640,  3389,   642,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   652,   653,    -1,    59,
      -1,    -1,    -1,    -1,   660,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3417,    -1,   671,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   426,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
     726,   727,    -1,   441,    -1,    -1,    -1,   445,    -1,    -1,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,   449,    -1,
    3494,    -1,   152,    -1,    -1,  3499,    -1,  3501,    -1,   159,
     160,    -1,    -1,   163,   164,   165,   166,    -1,    -1,   169,
     170,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,  3532,    -1,
      -1,    -1,    -1,    -1,   495,   496,    -1,    -1,    -1,    -1,
      -1,   509,    -1,    -1,    -1,    -1,  3550,    -1,    -1,   209,
      -1,    -1,  3556,    -1,    -1,    -1,    -1,    -1,    -1,   527,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,   536,    -1,   237,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,   246,   548,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,
    3624,  3625,  3626,  3627,  3628,  3629,    -1,    -1,   589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   315,    -1,    -1,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    -1,    -1,   628,   328,    -1,
      -1,    -1,    -1,    -1,   334,    -1,   637,   638,    -1,   640,
      -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,    -1,
     350,   652,   653,   353,   354,    -1,    -1,    -1,   358,   660,
      -1,    -1,   663,    -1,   364,   365,   674,    -1,    -1,    -1,
     671,   371,   372,   373,    -1,    -1,   376,   377,   378,    -1,
      -1,    -1,   382,    -1,    -1,    -1,   386,    -1,   388,    -1,
      -1,    -1,    -1,    -1,    -1,   395,   396,   397,   398,    -1,
     400,   401,    -1,    -1,    -1,   405,   406,    -1,   408,   409,
     410,   411,   412,   413,   414,    -1,    -1,    -1,    -1,    -1,
     420,   421,   422,    -1,   424,   425,    -1,    -1,  3772,   429,
     430,   431,   432,   433,   434,   435,   436,    -1,   438,    -1,
      -1,    -1,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,    -1,   479,
     480,    -1,    -1,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,    -1,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,    -1,
      -1,   511,   512,   513,   514,   515,   516,   517,   518,   519,
      -1,   521,   522,   523,   524,    -1,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,    -1,   563,   564,   565,   566,   567,   568,    -1,
      -1,   571,   572,    -1,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
      -1,    -1,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   663,    -1,    -1,    -1,    -1,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,   689,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   697,    -1,    -1,
      -1,    -1,   702,    -1,    -1,    -1,   706,    -1,    -1,   709,
     710,   711,   712,    -1,    -1,   715,   716,    -1,   718,   719,
     720,     5,     6,     7,     8,     9,    10,   353,    12,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,   372,   373,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,   461,    -1,    -1,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,   163,
     164,   165,   166,    -1,    -1,   169,   170,    -1,    -1,    -1,
     516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,   564,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,   585,
     244,    -1,   246,   589,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,
     626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,
     334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,
     344,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,   353,
     354,    -1,    -1,    -1,   358,    -1,    -1,    -1,    -1,    -1,
     364,   365,    -1,    -1,    -1,    -1,    -1,   371,   372,   373,
      -1,    -1,   376,   377,   378,    -1,    -1,    -1,   382,    -1,
      -1,    -1,   386,    -1,   388,    -1,    -1,    -1,    -1,    -1,
      -1,   395,   396,   397,   398,    -1,   400,   401,    -1,    -1,
      -1,   405,   406,    -1,   408,   409,   410,   411,   412,   413,
     414,    -1,    -1,    -1,    -1,    -1,   420,   421,   422,    -1,
     424,   425,    -1,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,    -1,   438,    -1,    -1,    -1,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,    -1,   479,   480,    -1,    -1,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,    -1,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,    -1,    -1,   511,   512,   513,
     514,   515,   516,   517,   518,   519,    -1,   521,   522,   523,
     524,    -1,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,    -1,   563,
     564,   565,   566,   567,   568,    -1,    -1,   571,   572,    -1,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,    -1,    -1,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
      23,    -1,    -1,    -1,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,   689,    49,    -1,    51,    52,
      -1,    -1,    -1,   697,    -1,    -1,    -1,    -1,   702,    -1,
      -1,    -1,   706,    -1,    -1,   709,   710,   711,   712,    -1,
      -1,   715,   716,    -1,   718,   719,   720,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,   252,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,    -1,    -1,    -1,   282,
      -1,    -1,    -1,    -1,    -1,   288,    -1,    -1,    -1,   292,
     293,   294,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   307,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   324,    -1,    -1,   327,    -1,   329,    -1,    -1,    -1,
      30,    -1,    -1,   336,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    48,    -1,   349,    -1,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,   359,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   380,   381,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     403,    -1,    -1,    -1,   407,   105,   106,    -1,    -1,    -1,
     110,    -1,   415,   416,   417,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,   157,   158,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,    -1,   174,   175,   176,    -1,    -1,   482,
      -1,    -1,    -1,    -1,   184,   185,    -1,   187,   188,   189,
     493,    -1,    -1,    -1,    -1,   195,    -1,    -1,   198,    -1,
     200,   201,   202,    -1,    -1,    -1,    -1,    -1,   208,    -1,
     210,   211,    -1,   213,    -1,   215,   216,    -1,    -1,   219,
      -1,    -1,   222,   223,   224,   225,   226,   227,    -1,    -1,
     533,   231,   232,   233,    -1,   235,    -1,    -1,    -1,   239,
      -1,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
     250,    -1,    -1,   253,    -1,   255,    -1,   257,    -1,   259,
      -1,    -1,    -1,   263,   264,    -1,   266,   267,   268,    -1,
      -1,   271,    -1,   273,   274,    -1,   276,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   284,   285,    -1,    -1,    -1,    -1,
      -1,   594,    -1,    -1,    -1,    -1,    -1,   297,    -1,   303,
     300,   301,   306,    -1,   304,   305,    -1,    -1,   308,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,   318,   319,
      -1,   321,    -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,
      -1,   331,   332,   333,    -1,   335,    -1,    -1,    -1,   339,
     340,    -1,    -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,   361,   362,    -1,    -1,    -1,    -1,    -1,   368,   369,
      -1,    -1,    -1,   676,    -1,    -1,   376,    -1,    -1,   379,
      -1,    -1,    -1,   383,   384,    -1,    -1,   690,   691,   692,
     693,   694,   695,   696,   394,   698,   699,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   411,   715,    -1,    -1,    -1,    -1,    -1,    -1,   419,
      -1,    -1,   426,    -1,    -1,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,   441,    -1,    -1,
      -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,
      -1,    -1,    -1,    -1,   454,    -1,   456,   457,    -1,    -1,
      -1,    -1,    -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,   503,    -1,   509,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   514,    -1,    -1,    -1,    -1,    -1,
      -1,   521,    -1,   527,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   545,   546,    -1,    -1,    -1,
     550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   568,   569,
     570,   571,    -1,    -1,    -1,   575,    -1,    -1,    -1,   579,
      -1,    -1,    -1,    -1,    -1,    -1,   586,   587,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   597,    -1,   599,
      -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,
     610,    -1,   612,    -1,    -1,   615,    -1,    -1,    -1,    -1,
      -1,   621,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,    -1,   647,    -1,    -1,
     650,    -1,    -1,    -1,    -1,   655,    -1,    -1,   658,   659,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     674,    -1,    -1,   673,    -1,    -1,    -1,     6,     7,     8,
     680,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   703,   704,   705,   706,   707,   708,   709,
      -1,    -1,   712,    -1,   714,    -1,   716,    -1,    -1,    48,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,   306,    48,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
      -1,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,    -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,
      -1,    -1,   445,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   509,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
     306,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   306,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,   608,    -1,   306,    48,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,   426,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,   441,    -1,    -1,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
     426,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
      -1,   674,   481,    -1,    -1,   441,    -1,    -1,    -1,   445,
     446,    -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,
     509,   445,   446,    -1,    -1,   145,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,   481,    -1,    -1,   527,    -1,
      -1,    -1,    -1,   163,   164,   165,    -1,   426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,
      -1,    -1,   441,   509,    -1,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,    -1,
      -1,   527,    -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,
      -1,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   481,   527,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   306,    -1,    -1,
     509,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   608,   674,   306,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,   608,
      -1,   303,    -1,    -1,   306,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,
     674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,   445,   446,    -1,    -1,
     145,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,
      -1,    -1,   481,     6,     7,     8,   426,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   441,    -1,    -1,    -1,   445,   446,    -1,    -1,    -1,
     509,    -1,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,   527,    -1,
     163,   164,   165,    -1,   426,    -1,    -1,    -1,    -1,    -1,
      -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,
      -1,    -1,    -1,   445,   446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   527,    -1,   481,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   608,
      -1,   306,    48,    -1,    -1,    -1,    -1,   509,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,
     303,    -1,    -1,   306,    -1,   674,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,    -1,   608,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
      -1,   426,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,
     445,   446,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,   674,   306,    -1,    -1,   481,    -1,    -1,    -1,
      -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,
      -1,    -1,   445,    -1,   509,    -1,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   527,    -1,   163,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   494,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
     306,    -1,    -1,    18,    19,    20,   509,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,   527,    -1,   145,   146,   147,   148,
     149,   150,    -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   608,   163,   164,   165,    -1,   441,    -1,
      -1,    -1,   445,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,   481,    -1,
      -1,    36,    37,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   494,    -1,   118,   303,   608,    -1,   306,    -1,   674,
      -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,
     426,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,   527,   441,    -1,    -1,    -1,   445,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   674,    -1,   118,    -1,   481,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,   306,   494,    -1,
     145,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,    -1,   608,    18,    19,    20,    -1,
      -1,   527,    24,    25,    26,    27,    -1,   426,    -1,   244,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,   445,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   164,   165,    -1,   145,   146,   147,   148,   149,
     150,   674,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,   244,
      -1,    -1,   608,    -1,    -1,    -1,    -1,   426,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,   445,    -1,   527,    -1,
      -1,    -1,    -1,   348,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,   303,    -1,
      -1,   306,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,   674,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
     509,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,   608,
      -1,   303,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   449,   118,   306,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,   480,    -1,    -1,   483,    -1,
      -1,   426,    -1,    -1,    -1,   674,    -1,    -1,    -1,   118,
     495,   496,    -1,    -1,    -1,    -1,   441,    18,    19,   608,
     445,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   536,    -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,
      -1,    -1,    -1,   548,   426,   480,    -1,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   441,
      -1,   496,    -1,   445,   509,   674,   426,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   441,   527,    -1,   589,   445,    -1,    20,   523,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,   118,    -1,   481,
      -1,   536,    -1,    36,    37,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,   548,    -1,   244,    -1,   622,    -1,    -1,
      -1,   481,    -1,   628,    -1,    -1,    -1,   509,    -1,    -1,
      -1,    -1,   637,   638,    -1,   640,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   527,    -1,   652,   653,   509,
      -1,    -1,    -1,    -1,   589,   660,    -1,   449,   663,    -1,
      -1,    -1,    -1,   608,    -1,    -1,   671,   527,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,   118,    -1,   622,   480,    -1,
      -1,   483,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   637,   638,   496,   640,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   652,   653,    -1,
      -1,    36,    37,   244,    -1,   660,   608,    -1,   663,   674,
      -1,    -1,   186,    -1,    -1,    -1,   671,    -1,    -1,    -1,
     194,    -1,    -1,   535,   536,    -1,    -1,    -1,   608,   203,
      -1,    -1,   206,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,   449,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   674,    -1,    -1,   249,    -1,   589,    -1,    -1,
      -1,    -1,   256,   118,    -1,    -1,    -1,   480,    -1,    -1,
     483,   244,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,
     449,    -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,
     622,    -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   637,   638,    -1,   640,    -1,
      -1,   480,    -1,    -1,   483,    -1,   117,    -1,    -1,   313,
     652,   653,   535,   536,    -1,    -1,    -1,   496,   660,    -1,
      -1,   663,   133,   134,    -1,   548,    -1,    -1,    -1,   671,
      -1,    -1,   143,    -1,   338,    -1,   449,    -1,    -1,    -1,
      -1,   345,    -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,    -1,    -1,    -1,   536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   589,   480,    -1,   548,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   449,   244,
      -1,   385,    -1,   496,    -1,    -1,    -1,    -1,    -1,   393,
      -1,    -1,    54,    55,    56,    57,    58,    59,    -1,   622,
      -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,   480,
     589,    -1,   483,    -1,   637,   638,    -1,   640,    -1,    -1,
      -1,    -1,    -1,   536,    -1,   496,   430,    -1,    -1,   652,
     653,    -1,    -1,    -1,    -1,   548,    -1,   660,    -1,    -1,
     663,    -1,    -1,   622,    -1,    -1,    -1,    -1,   671,   628,
     454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,   638,
      -1,   640,    -1,    -1,    -1,   536,   449,    -1,    -1,    -1,
      -1,    -1,    -1,   652,   653,    -1,   589,   548,    -1,    -1,
      -1,   660,    -1,    -1,   663,    -1,    -1,   491,    -1,   151,
      -1,    -1,   671,    -1,    -1,    -1,    -1,   480,   502,    -1,
     483,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,   496,    -1,   628,    -1,    -1,   589,    -1,
      -1,    -1,    -1,    -1,   637,   638,    -1,   640,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,
     653,    -1,   353,    -1,    -1,    -1,    -1,   660,    -1,    -1,
     663,    -1,    -1,   536,    -1,    -1,    -1,   628,   671,    -1,
      -1,   372,   373,   374,   375,   548,    -1,    -1,    -1,   640,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
      -1,   652,   653,    -1,   449,    -1,    -1,    -1,    -1,   660,
      -1,    -1,   663,    -1,   256,    -1,   600,   601,   602,    -1,
     671,   412,    -1,    -1,    -1,    -1,   589,    -1,    -1,   613,
      -1,    -1,    -1,   424,    -1,   480,    -1,    -1,   483,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,
      -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,
     451,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,
     461,   313,    -1,    -1,   637,   638,    -1,   640,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,   652,
     653,   536,    -1,    -1,    -1,    -1,   338,   660,    -1,    -1,
     663,    -1,    -1,   548,    -1,   347,    -1,    -1,   671,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
      -1,    -1,   716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,   589,    -1,   388,    -1,   539,    -1,
      -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,
      -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,
     561,    -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   585,   640,    -1,    -1,   589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,   653,    -1,
      -1,    -1,    -1,    -1,    -1,   660,    -1,   608,   663,    -1,
      -1,   463,    -1,    -1,    -1,    -1,   671,   469,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,    -1,    -1,
      -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     542,   543,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   558,    -1,    -1,    -1,
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
       0,    30,    34,   129,   290,   411,   459,   490,   519,   787,
     814,   815,   871,  1043,  1099,  1101,  1102,  1103,  1108,  1110,
    1123,  1124,  1125,  1126,  1127,  1570,    28,    29,   788,   789,
     790,   791,   792,    27,  1007,  1585,  1007,    25,  1007,  1475,
    1128,   816,  1475,   815,     0,  1100,  1103,  1126,    31,   790,
     792,   872,   663,    25,   244,   813,   814,   994,  1007,  1012,
    1108,  1123,  1129,  1164,  1165,  1166,  1167,  1168,  1172,   409,
     818,   819,   820,   821,   824,   825,    39,   107,   114,   160,
     161,   168,   422,   517,   609,   689,   697,   787,   962,  1042,
    1104,  1105,  1107,  1111,  1112,  1118,  1130,  1134,  1285,  1295,
    1570,   668,  1007,  1167,   296,   510,   511,  1173,    20,  1007,
    1171,   671,   819,     5,   817,   409,  1007,     5,   843,   845,
     846,  1007,  1007,  1296,  1007,  1007,  1286,  1119,  1007,  1007,
    1107,  1113,   314,   353,   372,   373,   412,   424,   435,   451,
     461,   476,   516,   539,   554,   561,   564,   585,   589,   608,
     626,   873,   874,   875,   878,    25,  1164,  1170,    18,    19,
      26,    38,   113,   125,   152,   246,   343,   378,   412,   424,
     460,   475,   483,   496,   540,   565,   589,   633,   642,   726,
     727,   737,   739,   931,   936,   947,   949,  1007,  1164,  1174,
    1175,   511,    14,   870,   821,   574,  1272,   822,   819,   824,
      32,    40,   117,   133,   134,   143,   314,   353,   372,   373,
     374,   375,   390,   412,   424,   435,   451,   461,   476,   516,
     539,   554,   561,   564,   585,   589,   608,   626,   668,   828,
     837,   848,   853,  1007,   483,   167,  1007,   813,   963,  1135,
    1007,   880,   373,   826,   483,   856,   858,   859,   857,   866,
     867,   483,   483,   879,   511,   483,   819,   854,   478,   483,
     483,   483,   483,   483,   483,   483,   483,   483,   483,   483,
     737,   483,   810,     9,    18,    19,    24,    25,    26,   118,
     348,   442,   447,   449,   465,   480,   483,   486,   495,   536,
     548,   559,   589,   640,   652,   653,   660,   671,   907,   915,
     916,   917,   918,   919,   947,   948,   950,  1013,  1164,  1275,
    1468,   483,   483,   483,   483,   483,   483,    18,    19,    20,
      21,    22,   738,    26,   483,   573,     5,   479,  1174,    25,
      26,  1007,  1013,    19,    25,    26,   823,  1013,   721,   722,
     723,   827,   850,   839,   851,   826,   483,   483,   483,   840,
     856,   857,   483,   483,   838,   511,   849,   483,   854,   819,
     847,   483,    26,  1007,   483,  1120,   813,   813,   483,  1007,
     483,   510,   832,    26,   677,   421,   506,   522,   565,   604,
     633,   642,   860,   677,   421,   506,   522,   565,   604,   633,
     642,   868,    26,    26,   881,   882,   883,   884,  1007,    26,
     835,   836,    26,   671,  1164,   718,   955,   998,  1007,   998,
     998,   955,   955,   907,    24,    25,    26,    19,    24,    25,
      26,   951,   952,   953,   954,    25,   956,   998,   999,   907,
     446,   907,   907,   907,   907,   578,  1292,   483,   483,   907,
     421,   506,   522,   565,   604,   633,   642,  1471,  1472,   483,
     907,   907,   483,   483,   920,   483,   483,   483,   483,    26,
       6,     7,     8,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    48,   145,   146,   147,
     148,   149,   150,   163,   164,   165,   303,   306,   426,   441,
     445,   481,   509,   527,   608,   674,   809,   908,   921,   923,
     924,   925,   926,   927,   928,   929,   473,   939,   937,   943,
     941,  1164,  1164,   737,   932,  1007,  1175,   511,   479,    26,
     830,   483,   852,   819,   852,   832,    26,    26,    26,   819,
      26,    26,   818,   835,   852,    26,   671,   112,   844,  1297,
     446,   483,  1287,  1586,  1587,  1588,  1589,  1590,   964,  1136,
    1114,   671,    26,   446,   861,   862,   483,   863,   868,   869,
     863,   483,   864,     5,   446,     5,   446,     5,   337,     5,
     873,   479,     5,     5,   446,   819,   855,   446,   483,     5,
     446,   511,   671,   446,   446,   446,   446,   446,   446,   446,
      19,    26,   446,   641,   952,    19,    26,   641,   446,     5,
     446,   446,     5,   811,   907,   523,  1491,   907,   483,   677,
      20,   446,  1491,    20,  1275,   907,   907,   907,   907,   907,
     907,   907,   907,   907,   907,   907,   907,   907,   907,   907,
     907,   907,   907,   907,   907,   907,   907,   907,   483,   907,
     907,   483,  1164,   907,   907,   907,   907,   446,     5,   535,
     767,   768,   769,   907,   483,  1174,   511,   675,    26,   671,
      26,   446,   446,     5,   446,   312,     5,   446,     5,   446,
     337,   479,     5,   446,   855,  1007,  1180,  1181,  1183,  1131,
    1180,   416,  1587,  1272,    41,    42,    43,    50,    53,    60,
      61,   105,   106,   110,   120,   121,   123,   137,   154,   157,
     158,   172,   174,   175,   176,   184,   185,   187,   188,   189,
     195,   198,   200,   201,   202,   208,   210,   211,   213,   215,
     216,   219,   222,   223,   224,   225,   226,   227,   231,   232,
     233,   235,   239,   241,   242,   247,   250,   253,   255,   257,
     259,   263,   264,   266,   267,   268,   271,   273,   274,   276,
     284,   285,   297,   300,   301,   304,   305,   308,   309,   317,
     318,   319,   321,   331,   332,   333,   335,   339,   340,   344,
     352,   360,   361,   362,   368,   369,   376,   379,   383,   384,
     394,   411,   419,   425,   436,   448,   454,   456,   457,   464,
     503,   514,   521,   545,   546,   550,   562,   568,   569,   570,
     571,   575,   579,   586,   587,   597,   599,   610,   612,   615,
     621,   647,   650,   655,   658,   659,   673,   680,   703,   704,
     705,   706,   707,   708,   709,   712,   714,   716,   730,   731,
     732,   733,   750,   772,   786,   787,   793,   812,   886,   887,
     888,   889,   900,   901,   902,   903,   904,   905,   906,   957,
     988,   992,  1014,  1016,  1019,  1020,  1021,  1022,  1035,  1044,
    1068,  1069,  1071,  1075,  1090,  1091,  1095,  1096,  1097,  1098,
    1106,  1121,  1141,  1152,  1153,  1154,  1158,  1161,  1195,  1198,
    1200,  1206,  1207,  1210,  1213,  1216,  1218,  1220,  1223,  1230,
    1235,  1240,  1241,  1242,  1254,  1255,  1258,  1264,  1267,  1268,
    1293,  1308,  1309,  1310,  1311,  1312,  1324,  1330,  1331,  1351,
    1354,  1383,  1385,  1476,  1477,  1508,  1509,  1516,  1531,  1555,
    1570,  1571,  1576,  1577,  1579,  1583,  1584,  1591,   787,  1109,
     676,   699,  1137,  1138,  1180,    20,   446,   478,   833,   860,
      26,   865,    26,    26,    26,   882,   884,   876,   836,    26,
    1007,   998,   737,    20,   718,  1007,   860,   945,   945,    26,
     446,   641,   945,    24,    26,    26,   641,    24,    26,   857,
     946,   999,   858,   446,   414,   528,   637,  1499,   446,   446,
      26,  1472,   446,   446,   446,   446,   446,   446,   446,   494,
     494,   494,   930,  1491,   494,   930,  1491,   940,   938,   944,
     942,    26,   933,     5,   934,   479,  1174,   843,   446,    20,
     833,    26,   483,    26,    26,   829,    26,   671,   446,     5,
    1180,   446,  1164,  1164,  1164,  1007,    25,  1164,  1217,  1007,
      25,  1007,  1461,   405,  1008,  1009,  1585,  1008,    25,  1007,
    1460,  1007,  1007,  1238,  1002,  1008,  1002,  1007,  1581,  1461,
    1007,    26,   734,  1164,  1315,  1002,  1238,   930,    26,  1013,
    1280,  1281,  1280,   907,   914,  1353,  1460,  1460,   909,   930,
    1008,  1517,  1517,   890,  1238,  1002,  1313,  1164,  1004,  1008,
     914,  1517,  1164,  1238,  1164,  1352,  1517,    25,   637,  1155,
    1156,  1164,  1002,  1002,  1155,  1003,  1008,  1007,  1156,  1002,
    1517,  1002,  1004,  1461,  1164,  1193,  1194,  1000,  1008,  1004,
     430,   613,   998,  1070,  1007,   794,  1460,  1005,  1008,    25,
     244,  1007,  1384,  1559,  1561,  1562,  1563,  1564,  1566,   930,
    1193,   677,   930,  1008,  1219,   958,    63,    64,    65,    66,
     186,   194,   203,   206,   249,   256,   313,   338,   345,   347,
     357,   385,   393,   430,   454,   491,   502,   600,   601,   602,
     613,   716,  1084,  1214,  1215,  1164,  1185,  1186,   913,   914,
    1229,   955,   955,  1001,  1008,   930,  1217,  1294,  1164,  1271,
      25,   483,  1164,  1266,  1511,  1265,   914,  1572,   159,   209,
     246,   343,   420,   460,   526,   751,   936,  1007,  1164,  1303,
     774,   914,  1000,   641,  1007,  1015,  1142,   914,  1000,    26,
    1164,  1092,  1000,   914,  1532,   914,  1280,  1007,  1017,  1018,
    1004,  1017,   955,  1004,  1017,   955,  1023,  1017,    25,    26,
     439,   539,  1013,  1073,  1164,  1182,  1184,   119,   328,   400,
     444,   620,   700,   701,   702,   711,   741,  1025,  1027,  1029,
    1031,  1033,  1159,  1160,  1163,   391,   402,   452,   466,   555,
    1386,   691,   692,   966,   967,   968,  1007,  1139,   698,  1138,
     446,   356,   446,   446,   446,   446,   675,     5,   446,   446,
     479,   483,   677,    19,    26,   446,   945,    26,   446,   446,
     641,    26,   641,   677,    18,    19,    20,    25,    26,    36,
      37,   118,   449,   480,   483,   496,   536,   548,   589,   622,
     628,   637,   638,   640,   652,   653,   660,   663,  1007,  1013,
    1467,  1469,  1498,  1500,  1501,  1503,  1504,  1505,  1527,  1528,
    1529,  1530,  1560,  1561,  1565,  1292,   446,  1292,  1292,  1292,
    1292,  1292,  1292,    25,    25,    25,   907,   922,   446,    25,
     922,   446,   446,   446,   446,   446,   446,   446,   769,   767,
     479,   356,   446,   819,   841,   842,   446,   446,   675,   446,
    1007,  1298,  1183,   446,  1288,   108,   109,   138,   139,   140,
     507,   593,   636,  1332,  1333,  1334,  1337,  1340,  1343,  1344,
    1345,  1348,   671,   641,   663,   155,   156,   483,   671,   641,
     663,     8,   676,   479,  1460,   531,  1239,  1182,   163,   164,
     165,   647,   535,   910,   911,   914,  1164,  1189,  1460,   740,
     741,   893,   320,    47,   141,   142,   677,  1236,   512,     5,
     670,   677,   669,   669,  1196,   647,   473,     5,   608,  1045,
     512,   710,  1574,   710,   439,   796,  1164,   598,   669,  1201,
    1202,  1203,   671,    25,  1562,   511,  1567,   382,  1382,   663,
     671,   912,   914,   608,  1559,   912,     8,   605,  1001,    26,
     553,   606,   720,   993,  1164,   993,   993,   993,    25,   231,
     358,   364,   365,   366,   386,   491,   494,   502,   537,   572,
     591,   592,   602,   607,   646,   678,  1088,  1089,   993,   993,
     648,  1085,   741,  1085,  1085,   994,   994,  1085,  1085,   741,
       5,   473,     5,   389,   440,     5,   740,   135,   136,   591,
     678,  1076,   713,  1575,   913,   664,   665,   666,   667,  1270,
    1511,  1272,   914,  1260,  1261,  1262,  1273,  1274,   914,   483,
     483,   483,   483,    25,   770,  1007,   483,  1511,   400,   483,
     573,   641,   630,   775,   782,   773,  1007,    25,  1157,  1164,
    1256,     8,  1259,    14,  1007,  1169,  1176,  1177,  1179,  1187,
    1188,  1231,   217,   400,   596,   629,     5,     6,     7,     8,
       9,    10,    12,    13,    14,    18,    19,    20,    21,    22,
      23,    33,    59,   116,   125,   143,   144,   152,   159,   160,
     163,   164,   165,   166,   169,   170,   209,   231,   237,   244,
     246,   251,   277,   315,   328,   334,   343,   344,   350,   353,
     354,   358,   364,   365,   371,   372,   373,   376,   377,   378,
     382,   386,   388,   395,   396,   397,   398,   400,   401,   405,
     406,   408,   409,   410,   411,   412,   413,   414,   420,   421,
     422,   424,   425,   429,   430,   431,   432,   433,   434,   435,
     436,   438,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   479,   480,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   521,   522,   523,   524,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   563,   564,   565,   566,   567,   568,
     571,   572,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   689,   697,   702,   706,   709,   710,   711,   712,   715,
     716,   718,   719,   720,  1533,  1534,  1535,  1537,   627,     5,
     710,   710,   912,  1182,  1189,  1072,   473,     5,   205,  1050,
     483,  1164,   912,   483,    26,    26,   119,  1162,    25,  1164,
    1515,  1515,  1008,  1366,  1219,  1001,   173,   275,   283,   289,
     291,   302,   330,   346,   351,   363,   370,   518,   523,   530,
     552,   557,  1355,  1356,  1364,  1373,  1374,  1380,  1381,  1387,
    1388,  1398,  1418,  1422,  1487,  1488,  1518,  1519,  1522,  1523,
    1539,   969,   970,   144,   965,   976,   977,   968,  1140,  1586,
    1115,   511,   873,   836,   671,  1007,   860,    26,   446,   641,
     945,   446,   641,   945,   945,    24,    26,   641,    24,    26,
     861,  1504,  1504,   421,   506,   522,   565,   604,   633,   642,
    1470,  1473,   523,  1503,   483,   483,   483,   483,  1498,  1498,
    1498,   483,   483,   483,   483,  1007,   483,     5,   598,  1427,
    1432,   668,  1007,    18,    19,    20,    21,   145,   146,   147,
     148,   149,   150,  1525,  1473,  1473,   473,     5,   446,   446,
     935,   511,     5,   446,   843,   813,  1132,   813,   299,   312,
     414,   483,   528,   544,  1402,  1403,  1408,  1410,   483,  1007,
    1349,  1350,    26,   483,  1007,  1329,  1342,  1410,  1412,   483,
    1007,  1339,   483,  1329,  1335,     5,  1007,    25,  1007,  1007,
      25,  1010,  1167,  1007,    25,  1007,  1007,  1007,  1582,  1460,
     647,   483,   483,   893,  1460,     5,   677,   483,  1559,    25,
    1012,  1237,  1236,  1237,  1511,  1155,   914,   914,   914,   995,
     996,   483,  1164,  1194,  1046,  1047,  1048,  1460,   677,  1511,
     955,  1575,  1070,  1164,   795,   676,   914,   406,  1205,   608,
    1204,  1563,   737,  1568,  1569,  1007,    20,  1564,     5,  1556,
     668,  1211,   122,   124,   126,   669,   677,   885,  1182,  1185,
     959,    18,    19,   483,  1086,  1088,  1215,  1164,  1186,   994,
     914,   400,   647,    26,  1164,    26,  1164,   740,   207,  1269,
     446,   438,  1307,  1272,  1262,     5,   669,  1263,  1573,  1007,
      25,   955,   955,   641,   999,   674,  1164,   755,  1007,  1007,
     914,   395,   778,   782,   630,   776,   784,    23,   288,  1144,
    1148,   534,   930,   534,  1257,   914,   510,  1173,   671,     5,
    1093,   598,  1232,  1164,  1536,  1538,   243,  1534,  1036,  1018,
     955,   955,  1028,  1029,  1050,  1050,    44,    45,    46,    49,
      51,    52,   324,   327,   329,   349,   359,   380,   403,   407,
     482,  1049,  1051,  1052,  1080,  1164,  1184,   598,   742,    26,
     453,  1034,   377,  1510,  1510,   192,   193,   489,   598,  1007,
    1419,  1420,  1462,  1460,  1460,  1460,  1357,  1460,  1460,  1007,
    1520,   221,   434,   448,   491,   502,   523,   530,   538,   560,
     637,   643,  1389,  1391,  1392,  1393,  1499,  1460,  1365,  1389,
    1391,  1586,  1586,   439,   978,  1164,   693,   694,   971,   972,
     973,   533,   676,   695,   696,   715,   981,   982,  1586,   813,
      26,   834,    20,  1007,   446,    26,   446,   945,    26,   945,
      24,    26,   446,   446,    24,    26,   677,  1499,   446,   449,
    1503,  1526,  1565,   414,   528,   637,  1451,  1503,  1506,  1451,
    1451,  1451,  1451,   671,  1506,  1501,   567,  1428,  1429,  1430,
    1460,   578,  1426,  1433,   387,   566,   577,  1375,  1494,  1007,
    1503,  1503,  1503,  1503,   677,   483,   677,  1560,   907,   446,
     834,   842,  1299,   813,  1289,   483,   483,   483,  1346,  1410,
     483,   483,   111,  1347,  1349,     5,  1341,  1342,   117,   353,
     373,   374,   375,   412,   424,   435,   451,   461,   476,   524,
     554,   564,   585,   589,   617,   626,  1452,  1453,  1454,  1456,
    1338,  1339,  1335,  1336,   715,  1333,   671,   641,   446,   671,
     641,   598,  1580,   483,   735,   736,  1007,  1316,   930,   910,
    1007,  1314,   668,  1208,  1236,  1236,   677,     5,     5,     5,
     631,   914,     5,   671,   535,   677,   676,   218,   220,   324,
     327,   797,   800,   801,  1080,   798,   799,  1007,   483,  1008,
     700,   701,  1209,     5,   479,   914,  1460,  1557,  1558,  1559,
     628,   668,  1212,  1007,  1007,   996,   997,   561,   955,   893,
       8,     8,   961,    26,    26,  1087,  1088,  1164,   373,  1224,
     119,   907,  1272,   272,  1274,  1280,  1586,     5,     5,   446,
     446,   771,  1007,   446,  1511,   767,   483,   483,   783,   779,
     415,   777,   914,   395,   780,   784,   648,  1082,  1149,  1145,
     417,  1143,  1144,   912,   677,  1170,    20,  1007,  1178,  1188,
      14,   535,  1233,  1234,  1503,  1565,  1185,  1586,  1030,  1031,
     602,  1006,   598,  1063,  1062,  1061,  1060,  1065,  1064,   998,
    1066,   998,  1067,  1059,  1058,  1056,  1055,  1081,   380,  1052,
    1057,   955,    54,    55,    56,    57,    58,    59,   151,   388,
     401,   463,   469,   508,   532,   542,   543,   548,   558,   580,
     583,   584,   588,   645,   656,   743,   744,  1078,  1079,     5,
      26,  1511,   302,  1164,   523,  1492,  1493,  1511,  1219,  1486,
    1488,   153,   153,   647,  1217,  1421,  1422,   483,  1399,   204,
    1433,  1460,   228,   325,  1524,   671,   677,   483,  1394,  1394,
     598,   676,     5,  1489,  1540,   397,   406,   430,   433,   449,
     553,   606,   613,  1001,  1367,  1372,   677,   676,   980,  1164,
       5,   598,   974,   975,   690,   973,   979,  1007,   979,   983,
     984,   979,   380,   982,  1116,   479,   446,   641,   945,   446,
     641,   446,   446,   945,   945,   421,   506,   522,   565,   604,
     633,   642,  1474,  1500,     5,  1473,     5,   446,     5,  1503,
       5,   446,  1503,  1503,  1503,  1503,  1007,   446,   483,  1430,
       5,  1007,  1466,     9,   348,   483,   495,  1436,  1437,  1438,
    1439,  1440,  1444,  1448,  1450,  1503,   423,  1424,  1434,  1007,
    1495,   670,  1451,   387,  1474,    26,  1474,   479,   513,  1282,
    1302,  1133,   513,  1243,  1276,   663,  1007,  1405,  1407,  1460,
    1464,  1465,  1409,  1464,  1409,     5,   446,  1347,  1409,  1436,
    1007,   446,  1350,     5,   446,   483,   483,   483,  1473,  1473,
     483,   483,   483,   483,   483,   260,   261,   262,   453,  1411,
    1413,     5,   446,     5,   446,  1007,  1007,    25,  1007,  1007,
      25,  1007,   914,  1007,  1326,  1327,     5,  1328,  1329,   930,
    1122,   671,  1328,   628,  1511,  1511,   914,   914,   995,   561,
     914,  1578,     5,  1047,    20,  1464,  1511,   798,   806,   805,
     807,  1007,  1011,   808,  1011,   245,   801,   804,     5,  1050,
     671,   914,     8,  1569,   511,   671,     5,  1511,   628,  1007,
    1182,   930,   605,  1370,     5,   446,  1164,     5,    26,  1164,
     381,    25,  1304,   400,   400,   511,   671,   400,   483,   756,
     760,   753,  1586,  1586,   785,   781,   777,  1083,    25,  1006,
    1150,  1164,  1586,   914,   478,   511,   930,     5,  1037,  1032,
    1033,    26,   740,  1007,  1586,  1586,  1586,  1586,  1586,  1586,
       5,  1053,     5,  1054,  1586,  1586,  1586,  1586,  1086,  1586,
    1006,    25,    14,    14,     5,   446,    26,  1460,  1499,  1480,
     647,   647,  1356,  1485,  1486,  1422,  1400,  1464,   668,  1001,
     483,  1360,  1007,  1521,  1520,  1395,  1464,   515,  1396,  1397,
    1462,  1460,  1393,  1500,    99,   100,   101,   102,   103,   635,
    1543,   914,   914,   605,  1368,  1001,  1396,  1460,     5,  1164,
     979,  1586,  1586,     5,   986,   987,  1586,  1586,   985,  1109,
     877,   945,    26,   945,    24,    26,   945,   945,   483,  1432,
    1473,   677,  1473,  1473,   446,  1503,   446,   446,   446,   446,
    1429,  1431,  1429,  1439,  1498,  1436,  1503,  1498,     6,     7,
       9,    10,    12,    13,    14,    15,    16,    17,   306,   426,
     427,   481,   608,   674,   724,   725,  1447,  1449,  1425,  1502,
    1503,   500,  1423,  1435,   322,  1325,    26,  1376,  1377,  1378,
    1464,  1492,  1495,   446,   831,   127,   128,   130,   131,   132,
     230,   238,   272,   281,   310,   311,   355,   399,   453,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,  1279,
    1283,   191,   566,  1284,  1300,  1109,   214,   229,   230,   238,
     272,   281,   310,   355,   399,  1277,  1278,  1290,  1284,  1465,
     511,  1463,   446,     5,   671,     5,   446,   446,  1410,   446,
     446,  1342,    26,  1457,  1457,    26,   677,   483,   677,    26,
    1458,    26,    26,  1458,  1458,    25,  1467,   212,   312,   350,
     414,   428,   528,   544,  1404,  1414,  1415,  1416,  1417,  1339,
    1335,   671,   671,   590,   639,     5,   446,   736,     5,   446,
     912,   446,    20,   446,  1511,     5,   914,   618,   328,   745,
     746,   914,  1050,  1586,  1586,     5,   802,   511,   671,     5,
     803,  1586,   799,   598,    20,  1007,     5,  1007,  1199,  1568,
      20,  1464,  1558,     8,  1511,   444,   710,   912,  1371,   960,
    1088,   719,  1222,   907,     5,   767,  1164,   752,   734,  1007,
    1164,   758,   446,   767,   767,  1586,  1586,  1086,  1147,    25,
    1151,  1164,   623,   991,  1174,   535,   913,  1094,  1234,   116,
     594,  1038,  1024,  1025,   671,   998,  1586,   998,  1586,   740,
      26,  1164,    26,  1164,   744,   446,   483,  1512,  1500,  1486,
    1486,  1478,     5,   446,   523,  1497,  1361,  1464,   531,  1358,
    1497,   677,     5,   446,     5,   598,  1490,    18,    19,   118,
     480,   483,   496,   535,   536,   548,   589,   628,   640,   652,
     653,   660,   663,  1007,  1467,  1498,  1527,  1529,  1548,  1549,
    1550,  1551,  1552,  1553,  1565,  1548,  1548,  1548,  1464,  1545,
    1547,  1544,  1545,  1546,  1541,  1369,   677,  1164,  1007,  1586,
    1586,  1586,  1586,   675,   446,   641,   446,   446,    26,   446,
     677,  1474,   677,   677,     5,   446,   446,  1437,  1438,  1442,
    1504,  1442,   483,  1498,  1442,   483,  1498,  1442,    10,   303,
     441,   443,  1503,     5,  1436,     5,   590,   639,  1379,  1325,
     677,   675,  1280,  1280,  1280,    25,  1280,  1280,  1280,  1280,
    1280,  1280,    25,    25,  1280,  1283,  1164,  1190,  1191,   670,
     499,  1244,  1586,    25,    25,    26,    26,    26,    26,    26,
      25,  1164,  1278,  1244,    26,  1404,  1464,    20,  1007,  1464,
    1347,   446,   446,     5,   446,  1474,    26,  1474,     5,  1455,
       5,   446,   446,   446,  1455,  1406,  1460,   483,  1416,  1347,
    1007,  1007,  1327,   674,   728,  1321,  1322,  1323,  1329,    62,
     139,   140,   298,   674,  1317,  1318,  1319,   520,   892,  1317,
       5,   429,  1511,     5,   483,   446,   602,  1077,  1011,  1586,
     737,    20,  1007,  1011,  1586,   955,   914,   479,  1511,     8,
     955,  1185,  1586,    26,  1006,    25,  1305,  1182,   479,   767,
     757,   761,   446,  1586,  1006,   914,   989,   479,  1040,  1039,
     493,  1026,  1027,    20,  1007,  1513,  1514,   605,  1496,  1481,
    1479,  1464,  1499,   196,  1401,     5,   446,  1359,  1521,  1464,
    1397,  1396,  1496,  1551,  1551,  1550,   483,   483,   483,   483,
     483,   483,   483,  1007,   483,     5,   446,    18,    19,    20,
      21,  1525,   446,     5,   446,     5,    14,   204,   578,  1542,
    1185,  1396,   265,  1117,   873,   945,    24,    26,   945,   945,
     446,  1474,  1474,  1474,  1429,   494,  1441,  1441,  1445,  1446,
    1467,  1565,  1441,  1445,  1441,  1442,  1503,  1502,  1377,  1474,
     843,   590,   639,  1192,     5,  1190,   115,   190,   252,   254,
     270,   278,   282,   307,  1245,  1246,  1301,  1117,  1291,     5,
     479,  1463,    26,   446,    26,  1459,   446,    26,   446,   483,
    1436,  1320,  1585,    26,  1323,    26,    26,  1320,  1325,  1319,
     998,   740,   429,  1511,   914,   747,   620,  1197,    26,   740,
     479,  1077,   446,  1511,   294,   740,   446,   446,   483,   759,
     400,   765,   446,   754,  1146,  1586,   511,   914,  1586,  1006,
       5,   446,  1185,  1432,  1500,  1464,   483,  1432,   446,  1526,
    1451,  1550,  1554,  1451,  1451,  1451,  1451,   511,   671,  1554,
    1549,  1550,  1550,  1550,  1550,  1545,    14,  1546,  1549,  1001,
    1436,   197,   668,  1390,   446,   446,  1443,  1467,  1507,     5,
     446,   446,  1441,     7,  1191,  1247,  1248,  1164,  1250,  1164,
    1249,  1251,  1246,   293,   293,    26,   446,   677,   446,  1407,
     446,   891,  1511,   447,   256,   313,   338,   347,   385,   393,
     484,   654,   744,   748,   749,   483,   671,   740,  1221,  1306,
     762,   446,  1182,   765,   765,  1586,   990,  1174,   627,  1074,
    1514,  1494,  1432,   535,  1362,  1363,  1503,  1494,   446,  1550,
       5,   446,  1550,  1550,  1550,  1550,    26,  1007,   446,   483,
    1007,   945,   945,  1446,  1503,  1586,  1586,  1252,  1586,  1253,
    1586,  1586,   479,  1474,   446,   292,   403,   407,   894,   895,
     896,  1080,   993,   993,   993,   993,   993,   993,    25,     5,
     446,   914,    20,  1007,  1080,  1225,  1226,  1227,   765,   767,
     765,   295,   479,  1041,   740,     5,   446,   341,   342,  1482,
     446,  1550,   446,   446,   446,   446,     5,   479,   511,  1548,
    1586,  1586,   898,   897,   292,   896,   899,   749,     5,  1228,
     336,  1227,   763,  1586,  1363,    25,  1007,  1483,  1484,    26,
      26,   446,  1586,  1586,  1586,   914,  1586,   446,  1038,   671,
     671,     5,   479,     5,   479,   446,   764,  1007,  1007,  1484,
      26,   217,   400,   766,   671,   479,  1182,  1007
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
#line 3957 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 716:
#line 3963 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 717:
#line 3974 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 718:
#line 3975 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 719:
#line 3978 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 721:
#line 3984 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 722:
#line 3988 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 723:
#line 3989 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 724:
#line 3993 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 728:
#line 4008 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 729:
#line 4010 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 732:
#line 4019 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 733:
#line 4022 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 734:
#line 4026 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 735:
#line 4029 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 736:
#line 4032 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 737:
#line 4035 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 738:
#line 4038 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 739:
#line 4042 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 740:
#line 4045 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 741:
#line 4048 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 742:
#line 4051 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 743:
#line 4054 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 744:
#line 4057 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 745:
#line 4060 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 746:
#line 4063 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 747:
#line 4066 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 748:
#line 4067 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 749:
#line 4067 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 750:
#line 4068 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 751:
#line 4068 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 752:
#line 4069 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 753:
#line 4069 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 754:
#line 4070 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 755:
#line 4073 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 756:
#line 4074 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 757:
#line 4077 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 758:
#line 4085 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 759:
#line 4089 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 760:
#line 4095 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 761:
#line 4099 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 762:
#line 4104 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 763:
#line 4109 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 764:
#line 4114 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 765:
#line 4115 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 766:
#line 4116 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 767:
#line 4120 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 768:
#line 4124 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 769:
#line 4133 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 770:
#line 4138 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 771:
#line 4142 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 772:
#line 4149 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 773:
#line 4158 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 774:
#line 4164 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 775:
#line 4165 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 776:
#line 4166 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 777:
#line 4167 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 778:
#line 4168 "fgl.yacc"
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
#line 4178 "fgl.yacc"
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
#line 4192 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 782:
#line 4195 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 783:
#line 4202 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 784:
#line 4203 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 785:
#line 4204 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 786:
#line 4205 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 787:
#line 4206 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 788:
#line 4207 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 789:
#line 4208 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 790:
#line 4209 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 791:
#line 4210 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 792:
#line 4215 "fgl.yacc"
    {iskey=1;}
    break;

  case 793:
#line 4215 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 794:
#line 4217 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 795:
#line 4220 "fgl.yacc"
    {iskey=1;}
    break;

  case 796:
#line 4220 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 797:
#line 4222 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 798:
#line 4226 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 799:
#line 4229 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 800:
#line 4230 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 802:
#line 4233 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 808:
#line 4245 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 809:
#line 4246 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 810:
#line 4247 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 811:
#line 4248 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 812:
#line 4249 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 813:
#line 4250 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 814:
#line 4251 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 815:
#line 4252 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 816:
#line 4253 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 817:
#line 4254 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 818:
#line 4255 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 819:
#line 4256 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 820:
#line 4257 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 821:
#line 4258 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 822:
#line 4262 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 823:
#line 4280 "fgl.yacc"
    {chk4var=1;}
    break;

  case 824:
#line 4280 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 825:
#line 4283 "fgl.yacc"
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
#line 4307 "fgl.yacc"
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
#line 4325 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 829:
#line 4331 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 830:
#line 4337 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 831:
#line 4343 "fgl.yacc"
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
#line 4355 "fgl.yacc"
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
#line 4380 "fgl.yacc"
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
#line 4396 "fgl.yacc"
    {
	}
    break;

  case 845:
#line 4421 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 849:
#line 4429 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 864:
#line 4455 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 865:
#line 4456 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 866:
#line 4464 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 867:
#line 4469 "fgl.yacc"
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

  case 868:
#line 4485 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 869:
#line 4491 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 871:
#line 4506 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 872:
#line 4519 "fgl.yacc"
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

  case 873:
#line 4529 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 874:
#line 4536 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 875:
#line 4543 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 876:
#line 4549 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 877:
#line 4549 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 878:
#line 4554 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 879:
#line 4560 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 880:
#line 4568 "fgl.yacc"
    {
}
    break;

  case 884:
#line 4580 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 886:
#line 4588 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 887:
#line 4594 "fgl.yacc"
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

  case 890:
#line 4610 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 891:
#line 4614 "fgl.yacc"
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

  case 892:
#line 4627 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 894:
#line 4640 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 895:
#line 4646 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 896:
#line 4650 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 899:
#line 4662 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 900:
#line 4665 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 901:
#line 4669 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 902:
#line 4672 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 903:
#line 4684 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 904:
#line 4692 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 905:
#line 4698 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 906:
#line 4709 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 907:
#line 4713 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 908:
#line 4720 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 909:
#line 4727 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 910:
#line 4733 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 911:
#line 4738 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 914:
#line 4745 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 915:
#line 4746 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 916:
#line 4748 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 917:
#line 4749 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 918:
#line 4752 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 919:
#line 4753 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 920:
#line 4754 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 921:
#line 4756 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 922:
#line 4761 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 923:
#line 4766 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 924:
#line 4773 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 928:
#line 4780 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 929:
#line 4782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 930:
#line 4784 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 932:
#line 4794 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 933:
#line 4797 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 934:
#line 4800 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 941:
#line 4816 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 942:
#line 4821 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 943:
#line 4821 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 944:
#line 4824 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 945:
#line 4852 "fgl.yacc"
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

  case 947:
#line 4909 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 949:
#line 4916 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 950:
#line 4920 "fgl.yacc"
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

  case 951:
#line 4963 "fgl.yacc"
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

  case 955:
#line 5011 "fgl.yacc"
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

  case 956:
#line 5025 "fgl.yacc"
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

  case 961:
#line 5049 "fgl.yacc"
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

  case 962:
#line 5113 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 963:
#line 5118 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 964:
#line 5126 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 965:
#line 5131 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 966:
#line 5139 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 967:
#line 5145 "fgl.yacc"
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

  case 968:
#line 5177 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 969:
#line 5180 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 970:
#line 5182 "fgl.yacc"
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

  case 971:
#line 5223 "fgl.yacc"
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

  case 976:
#line 5276 "fgl.yacc"
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

  case 977:
#line 5328 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 979:
#line 5337 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 980:
#line 5342 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 981:
#line 5353 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 982:
#line 5360 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 984:
#line 5368 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 985:
#line 5371 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 986:
#line 5372 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 988:
#line 5374 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 989:
#line 5375 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 990:
#line 5378 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 991:
#line 5381 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 992:
#line 5387 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 993:
#line 5390 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 994:
#line 5394 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 995:
#line 5399 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 996:
#line 5407 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 997:
#line 5412 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 998:
#line 5419 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 999:
#line 5421 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1004:
#line 5449 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1005:
#line 5456 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1006:
#line 5463 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1007:
#line 5466 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1008:
#line 5480 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1013:
#line 5497 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1014:
#line 5502 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1015:
#line 5508 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1017:
#line 5515 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1018:
#line 5520 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1019:
#line 5523 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1020:
#line 5524 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1021:
#line 5527 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1022:
#line 5528 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1023:
#line 5531 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1024:
#line 5532 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1025:
#line 5537 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1026:
#line 5544 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1027:
#line 5547 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1028:
#line 5553 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1029:
#line 5555 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1030:
#line 5557 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1031:
#line 5559 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1032:
#line 5562 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1033:
#line 5562 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1034:
#line 5563 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1035:
#line 5568 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1036:
#line 5576 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1037:
#line 5577 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1038:
#line 5582 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1039:
#line 5584 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1040:
#line 5586 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1044:
#line 5604 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1045:
#line 5605 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1046:
#line 5606 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1047:
#line 5607 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1048:
#line 5608 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1049:
#line 5609 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1050:
#line 5610 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1051:
#line 5611 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1052:
#line 5612 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1053:
#line 5613 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1054:
#line 5614 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1055:
#line 5615 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1056:
#line 5616 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1057:
#line 5617 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1058:
#line 5618 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1059:
#line 5619 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1060:
#line 5620 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1061:
#line 5621 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1062:
#line 5622 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1063:
#line 5623 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1064:
#line 5624 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1065:
#line 5625 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1066:
#line 5626 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1067:
#line 5627 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1068:
#line 5628 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1069:
#line 5629 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1070:
#line 5644 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1073:
#line 5653 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1074:
#line 5657 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1075:
#line 5661 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1076:
#line 5665 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1077:
#line 5669 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1079:
#line 5689 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1080:
#line 5694 "fgl.yacc"
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

  case 1081:
#line 5707 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1082:
#line 5708 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1083:
#line 5712 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1084:
#line 5717 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1085:
#line 5718 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1086:
#line 5722 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1090:
#line 5728 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1091:
#line 5731 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1093:
#line 5746 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1094:
#line 5750 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1095:
#line 5756 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1096:
#line 5757 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1097:
#line 5762 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1098:
#line 5763 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1099:
#line 5766 "fgl.yacc"
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

  case 1101:
#line 5793 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1102:
#line 5797 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1103:
#line 5801 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1104:
#line 5805 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1105:
#line 5812 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1106:
#line 5813 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1112:
#line 5825 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1113:
#line 5831 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1114:
#line 5839 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1115:
#line 5845 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1116:
#line 5847 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1120:
#line 5857 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1121:
#line 5857 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1122:
#line 5862 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1123:
#line 5866 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1124:
#line 5871 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1125:
#line 5871 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1126:
#line 5875 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1127:
#line 5875 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1128:
#line 5876 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1129:
#line 5876 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1130:
#line 5877 "fgl.yacc"
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

  case 1131:
#line 5890 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1132:
#line 5891 "fgl.yacc"
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

  case 1133:
#line 5907 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1140:
#line 5919 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1141:
#line 5919 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1142:
#line 5925 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1143:
#line 5925 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1144:
#line 5928 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1145:
#line 5928 "fgl.yacc"
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

  case 1146:
#line 5944 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1147:
#line 5945 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1148:
#line 5946 "fgl.yacc"
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

  case 1149:
#line 5955 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1150:
#line 5967 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1156:
#line 5978 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1157:
#line 5983 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1158:
#line 5983 "fgl.yacc"
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

  case 1160:
#line 6007 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1161:
#line 6013 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1162:
#line 6018 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1163:
#line 6024 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1164:
#line 6025 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1165:
#line 6026 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1166:
#line 6030 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1167:
#line 6031 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1168:
#line 6032 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1169:
#line 6033 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1170:
#line 6037 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1171:
#line 6047 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1172:
#line 6049 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1173:
#line 6054 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1174:
#line 6057 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1175:
#line 6062 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1176:
#line 6069 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1177:
#line 6076 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1178:
#line 6083 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1179:
#line 6092 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1180:
#line 6099 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1181:
#line 6106 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1182:
#line 6113 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1183:
#line 6120 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1188:
#line 6133 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1189:
#line 6134 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1190:
#line 6135 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1191:
#line 6136 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1192:
#line 6137 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1193:
#line 6138 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1194:
#line 6139 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1195:
#line 6140 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1196:
#line 6141 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1197:
#line 6142 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1200:
#line 6148 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1201:
#line 6149 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1202:
#line 6150 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1203:
#line 6151 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1208:
#line 6160 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1209:
#line 6161 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1210:
#line 6162 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1211:
#line 6163 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1212:
#line 6164 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1213:
#line 6165 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1214:
#line 6166 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1215:
#line 6167 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1216:
#line 6169 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1217:
#line 6170 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1218:
#line 6171 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1219:
#line 6172 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1220:
#line 6174 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1221:
#line 6175 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1222:
#line 6176 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1223:
#line 6177 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1227:
#line 6182 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1228:
#line 6183 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1232:
#line 6190 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1233:
#line 6199 "fgl.yacc"
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

  case 1234:
#line 6208 "fgl.yacc"
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

  case 1235:
#line 6221 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1236:
#line 6230 "fgl.yacc"
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

  case 1237:
#line 6241 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1238:
#line 6245 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1239:
#line 6249 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1240:
#line 6255 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1241:
#line 6260 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1242:
#line 6268 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1243:
#line 6271 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1244:
#line 6280 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1245:
#line 6291 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1247:
#line 6298 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1248:
#line 6306 "fgl.yacc"
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

  case 1249:
#line 6316 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1250:
#line 6319 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1251:
#line 6323 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1252:
#line 6331 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1253:
#line 6334 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1254:
#line 6340 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1255:
#line 6344 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1256:
#line 6348 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1257:
#line 6352 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1258:
#line 6356 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1259:
#line 6362 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1260:
#line 6363 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1261:
#line 6364 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1262:
#line 6365 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1263:
#line 6370 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1264:
#line 6372 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1265:
#line 6375 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1266:
#line 6379 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1267:
#line 6382 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1268:
#line 6389 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1269:
#line 6394 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1270:
#line 6401 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1271:
#line 6402 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1272:
#line 6403 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1273:
#line 6408 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1274:
#line 6409 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1275:
#line 6415 "fgl.yacc"
    {insql=1;}
    break;

  case 1276:
#line 6415 "fgl.yacc"
    {insql=0;}
    break;

  case 1277:
#line 6415 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1278:
#line 6420 "fgl.yacc"
    {insql=1;}
    break;

  case 1279:
#line 6420 "fgl.yacc"
    {insql=0;}
    break;

  case 1280:
#line 6420 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1281:
#line 6428 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1282:
#line 6429 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1284:
#line 6434 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1285:
#line 6439 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1286:
#line 6440 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1287:
#line 6441 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1288:
#line 6442 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1289:
#line 6443 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1291:
#line 6448 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1292:
#line 6448 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1294:
#line 6452 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1295:
#line 6456 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1296:
#line 6457 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1297:
#line 6460 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1298:
#line 6461 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1299:
#line 6464 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1300:
#line 6467 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1301:
#line 6470 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1302:
#line 6476 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1303:
#line 6478 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1305:
#line 6491 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1306:
#line 6495 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1307:
#line 6496 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1309:
#line 6501 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1310:
#line 6504 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1311:
#line 6510 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1312:
#line 6513 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1313:
#line 6521 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1315:
#line 6528 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1316:
#line 6532 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1317:
#line 6536 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1318:
#line 6542 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1319:
#line 6545 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1320:
#line 6554 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1321:
#line 6557 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1322:
#line 6560 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1323:
#line 6563 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1324:
#line 6566 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1325:
#line 6569 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1326:
#line 6572 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1327:
#line 6579 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1328:
#line 6582 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1329:
#line 6589 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1330:
#line 6592 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1331:
#line 6598 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1332:
#line 6601 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1333:
#line 6608 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1334:
#line 6611 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1336:
#line 6619 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1338:
#line 6628 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1339:
#line 6631 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1340:
#line 6637 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1341:
#line 6640 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1342:
#line 6646 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1343:
#line 6653 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1344:
#line 6654 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1345:
#line 6658 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1346:
#line 6668 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1347:
#line 6671 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1348:
#line 6677 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1349:
#line 6679 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1350:
#line 6684 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1351:
#line 6685 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1352:
#line 6690 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1353:
#line 6691 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1354:
#line 6697 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1355:
#line 6698 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1359:
#line 6725 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6731 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1366:
#line 6734 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1367:
#line 6737 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1368:
#line 6743 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1370:
#line 6749 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1372:
#line 6760 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1373:
#line 6774 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1374:
#line 6783 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1375:
#line 6783 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1376:
#line 6788 "fgl.yacc"
    {insql=1;}
    break;

  case 1377:
#line 6788 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1378:
#line 6793 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1379:
#line 6796 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1380:
#line 6798 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6805 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6809 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1384:
#line 6813 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1385:
#line 6820 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1386:
#line 6823 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1387:
#line 6830 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1388:
#line 6834 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1389:
#line 6840 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1390:
#line 6845 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1391:
#line 6849 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1392:
#line 6855 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1393:
#line 6858 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1394:
#line 6864 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1395:
#line 6871 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1396:
#line 6875 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1397:
#line 6880 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1398:
#line 6890 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1399:
#line 6893 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1400:
#line 6895 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1401:
#line 6897 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1402:
#line 6899 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1403:
#line 6901 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1404:
#line 6903 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1405:
#line 6905 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1406:
#line 6911 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1407:
#line 6921 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1408:
#line 6928 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6934 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6937 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1414:
#line 6944 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1417:
#line 6949 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1418:
#line 6954 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1419:
#line 6961 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1420:
#line 6962 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1421:
#line 6969 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1422:
#line 6980 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1423:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6982 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1425:
#line 6985 "fgl.yacc"
    {insql=1;}
    break;

  case 1426:
#line 6985 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1427:
#line 6990 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1428:
#line 6995 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1430:
#line 7001 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1432:
#line 7005 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1433:
#line 7010 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1434:
#line 7015 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1435:
#line 7019 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1437:
#line 7025 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1438:
#line 7029 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1439:
#line 7036 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 7037 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7038 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7039 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1446:
#line 7049 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1447:
#line 7050 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1448:
#line 7051 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1449:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1450:
#line 7056 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1453:
#line 7063 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 7066 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1457:
#line 7069 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 7074 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1461:
#line 7076 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1463:
#line 7082 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7088 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7098 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1469:
#line 7103 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1470:
#line 7105 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1472:
#line 7111 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7114 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7120 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1476:
#line 7128 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7133 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1480:
#line 7143 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7149 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7154 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1484:
#line 7157 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1485:
#line 7162 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1487:
#line 7168 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 7173 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1489:
#line 7176 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1490:
#line 7179 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1491:
#line 7186 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 7187 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1493:
#line 7188 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1494:
#line 7190 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1495:
#line 7203 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1496:
#line 7208 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1498:
#line 7212 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1499:
#line 7214 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1500:
#line 7221 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1501:
#line 7224 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1502:
#line 7230 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1503:
#line 7238 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1504:
#line 7242 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1505:
#line 7246 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1506:
#line 7250 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1507:
#line 7255 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1508:
#line 7258 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1509:
#line 7261 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1510:
#line 7269 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1511:
#line 7276 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1514:
#line 7285 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1515:
#line 7291 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1516:
#line 7294 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1517:
#line 7305 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7312 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1519:
#line 7318 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1520:
#line 7321 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1521:
#line 7328 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1522:
#line 7335 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1524:
#line 7342 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1525:
#line 7348 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1526:
#line 7349 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1527:
#line 7350 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1529:
#line 7354 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1531:
#line 7359 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1532:
#line 7366 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1533:
#line 7371 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1534:
#line 7372 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1535:
#line 7375 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1536:
#line 7378 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1537:
#line 7383 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1538:
#line 7384 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1539:
#line 7389 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1540:
#line 7392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1541:
#line 7398 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1542:
#line 7401 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1543:
#line 7407 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1544:
#line 7410 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1545:
#line 7416 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1546:
#line 7419 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1547:
#line 7426 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1548:
#line 7427 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1549:
#line 7456 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1550:
#line 7458 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1551:
#line 7462 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1553:
#line 7475 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1554:
#line 7478 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1555:
#line 7481 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1556:
#line 7484 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1558:
#line 7492 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1559:
#line 7495 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1561:
#line 7501 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1563:
#line 7507 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1564:
#line 7510 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1565:
#line 7513 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1566:
#line 7516 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1567:
#line 7519 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1568:
#line 7522 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1569:
#line 7525 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1570:
#line 7528 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1571:
#line 7533 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1573:
#line 7540 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1579:
#line 7548 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1580:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1581:
#line 7554 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1582:
#line 7557 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1583:
#line 7561 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1584:
#line 7567 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1585:
#line 7568 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1586:
#line 7569 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1587:
#line 7570 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1592:
#line 7590 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1594:
#line 7594 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1595:
#line 7595 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1597:
#line 7598 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1598:
#line 7599 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1599:
#line 7608 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1606:
#line 7622 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1607:
#line 7624 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1608:
#line 7626 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1610:
#line 7629 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1612:
#line 7632 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1616:
#line 7637 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1617:
#line 7639 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1618:
#line 7642 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1619:
#line 7643 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1620:
#line 7650 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1624:
#line 7655 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1628:
#line 7671 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1629:
#line 7678 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1630:
#line 7682 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1631:
#line 7683 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1632:
#line 7684 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1633:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1634:
#line 7693 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1635:
#line 7694 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1636:
#line 7705 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1637:
#line 7712 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1638:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1639:
#line 7718 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1640:
#line 7719 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1641:
#line 7727 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1642:
#line 7728 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1643:
#line 7729 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1645:
#line 7755 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1646:
#line 7756 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1647:
#line 7757 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1648:
#line 7761 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1649:
#line 7764 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1650:
#line 7770 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1651:
#line 7775 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1652:
#line 7780 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1654:
#line 7791 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1658:
#line 7809 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1659:
#line 7812 "fgl.yacc"
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

  case 1660:
#line 7825 "fgl.yacc"
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

  case 1661:
#line 7840 "fgl.yacc"
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

  case 1662:
#line 7852 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1663:
#line 7854 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1664:
#line 7857 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1665:
#line 7857 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1666:
#line 7857 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1667:
#line 7857 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1668:
#line 7857 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1669:
#line 7857 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1670:
#line 7858 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1671:
#line 7861 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1686:
#line 7878 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1687:
#line 7881 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1688:
#line 7882 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1689:
#line 7883 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1690:
#line 7887 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1691:
#line 7895 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1692:
#line 7895 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1693:
#line 7901 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1694:
#line 7901 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1695:
#line 7908 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1696:
#line 7908 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1697:
#line 7914 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1698:
#line 7914 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1699:
#line 7922 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1700:
#line 7923 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1701:
#line 7924 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1702:
#line 7927 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1703:
#line 7927 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1705:
#line 7931 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1706:
#line 7932 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1707:
#line 7943 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1708:
#line 7946 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1709:
#line 7952 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1710:
#line 7957 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1711:
#line 7965 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1712:
#line 7977 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1713:
#line 7978 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1714:
#line 7981 "fgl.yacc"
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

  case 1715:
#line 7996 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1716:
#line 8007 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1717:
#line 8010 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1718:
#line 8018 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1719:
#line 8027 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1720:
#line 8030 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1721:
#line 8034 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1722:
#line 8037 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1723:
#line 8038 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1725:
#line 8051 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1726:
#line 8052 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1727:
#line 8061 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1728:
#line 8070 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1729:
#line 8075 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1730:
#line 8076 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1731:
#line 8077 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1732:
#line 8078 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1733:
#line 8085 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1734:
#line 8088 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1735:
#line 8094 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1736:
#line 8097 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1737:
#line 8104 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1738:
#line 8116 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1739:
#line 8125 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1740:
#line 8128 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1741:
#line 8131 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1742:
#line 8137 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1743:
#line 8145 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1744:
#line 8148 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1745:
#line 8149 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1746:
#line 8150 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1747:
#line 8151 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1748:
#line 8152 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1749:
#line 8155 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1750:
#line 8162 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1751:
#line 8164 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1752:
#line 8166 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1753:
#line 8168 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1754:
#line 8170 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1755:
#line 8171 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1756:
#line 8172 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1757:
#line 8173 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1758:
#line 8174 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1759:
#line 8175 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1760:
#line 8176 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1761:
#line 8178 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1762:
#line 8180 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1763:
#line 8182 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1764:
#line 8184 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1765:
#line 8186 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1766:
#line 8188 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1767:
#line 8190 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1768:
#line 8191 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1769:
#line 8193 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1770:
#line 8194 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1771:
#line 8195 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1772:
#line 8201 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1773:
#line 8202 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1775:
#line 8212 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1776:
#line 8220 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1777:
#line 8224 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1778:
#line 8231 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1779:
#line 8231 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1781:
#line 8235 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1782:
#line 8240 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1783:
#line 8240 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1785:
#line 8244 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1786:
#line 8248 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1789:
#line 8257 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1790:
#line 8257 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1795:
#line 8276 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1796:
#line 8277 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1799:
#line 8285 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1800:
#line 8291 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1803:
#line 8310 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1804:
#line 8311 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1805:
#line 8312 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1806:
#line 8313 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1807:
#line 8314 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1808:
#line 8315 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1809:
#line 8319 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1810:
#line 8320 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1811:
#line 8321 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1813:
#line 8326 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1814:
#line 8327 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1815:
#line 8331 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1816:
#line 8347 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1817:
#line 8348 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1818:
#line 8349 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1819:
#line 8353 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1820:
#line 8367 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1821:
#line 8371 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1823:
#line 8380 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1825:
#line 8385 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1826:
#line 8386 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2142:
#line 8710 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2143:
#line 8710 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2144:
#line 8717 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2145:
#line 8717 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2146:
#line 8805 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2147:
#line 8809 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2148:
#line 8811 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2149:
#line 8818 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2150:
#line 8822 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2151:
#line 8828 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2152:
#line 8836 "fgl.yacc"
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

  case 2153:
#line 8846 "fgl.yacc"
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

  case 2154:
#line 8856 "fgl.yacc"
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
#line 8868 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2156:
#line 8871 "fgl.yacc"
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

  case 2157:
#line 8890 "fgl.yacc"
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
#line 8916 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2159:
#line 8919 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2161:
#line 8928 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2162:
#line 8933 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2163:
#line 8936 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2164:
#line 8944 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2165:
#line 8952 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2166:
#line 8965 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2167:
#line 8968 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2168:
#line 8976 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2169:
#line 8979 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2170:
#line 8982 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2171:
#line 8990 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 2172:
#line 8994 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 2173:
#line 8995 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 2174:
#line 8996 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 2175:
#line 8997 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2176:
#line 8998 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2177:
#line 8999 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2178:
#line 9000 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2179:
#line 9001 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2180:
#line 9005 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2181:
#line 9006 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2182:
#line 9007 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2183:
#line 9008 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2184:
#line 9009 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2185:
#line 9015 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2186:
#line 9016 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2187:
#line 9017 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2188:
#line 9018 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2189:
#line 9019 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2190:
#line 9020 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2191:
#line 9021 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2192:
#line 9022 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2193:
#line 9023 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2194:
#line 9024 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2195:
#line 9025 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 9026 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 9027 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 9028 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2199:
#line 9029 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2200:
#line 9030 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2201:
#line 9035 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2202:
#line 9041 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2203:
#line 9042 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2204:
#line 9050 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2205:
#line 9052 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2207:
#line 9058 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2208:
#line 9062 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2209:
#line 9066 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2210:
#line 9082 "fgl.yacc"
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

  case 2211:
#line 9096 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 2212:
#line 9102 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2213:
#line 9104 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2217:
#line 9118 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 2218:
#line 9121 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 2219:
#line 9128 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2220:
#line 9131 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 2221:
#line 9161 "fgl.yacc"
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

  case 2222:
#line 9186 "fgl.yacc"
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

  case 2223:
#line 9241 "fgl.yacc"
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

  case 2224:
#line 9276 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 2225:
#line 9285 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 2226:
#line 9296 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 2227:
#line 9299 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 2228:
#line 9305 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 2229:
#line 9318 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2230:
#line 9332 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2231:
#line 9335 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2232:
#line 9339 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2233:
#line 9354 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2234:
#line 9354 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2235:
#line 9360 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2236:
#line 9361 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2237:
#line 9364 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2238:
#line 9365 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2239:
#line 9366 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2240:
#line 9367 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2241:
#line 9368 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2242:
#line 9369 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2243:
#line 9370 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2244:
#line 9381 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2245:
#line 9385 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2246:
#line 9389 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2247:
#line 9393 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2248:
#line 9398 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2249:
#line 9402 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2250:
#line 9407 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2252:
#line 9415 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2254:
#line 9421 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2255:
#line 9427 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2256:
#line 9431 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2261:
#line 9449 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2262:
#line 9456 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2263:
#line 9466 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2264:
#line 9466 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19332 "y.tab.c"

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



