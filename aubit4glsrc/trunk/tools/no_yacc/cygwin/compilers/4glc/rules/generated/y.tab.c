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
     NAME = 1712,
     UMINUS = 1713,
     COMMA = 1618,
     KW_OR = 1658,
     KW_AND = 1613,
     KW_USING = 1550,
     NOT = 1633,
     MATCHES = 1430,
     POWER = 1536,
     LESS_THAN = 1532,
     GREATER_THAN = 1447,
     EQUAL = 1608,
     GREATER_THAN_EQ = 1349,
     LESS_THAN_EQ = 1406,
     NOT_EQUAL = 1478,
     PLUS = 1644,
     MINUS = 1631,
     MULTIPLY = 1537,
     DIVIDE = 1564,
     MOD = 1632,
     COMMAND = 1413,
     NUMBER_VALUE = 1714,
     CHAR_VALUE = 1715,
     INT_VALUE = 1716,
     NAMED_GEN = 1717,
     CLINE = 1718,
     SQLLINE = 1719,
     KW_CSTART = 1720,
     KW_CEND = 1721,
     USER_DTYPE = 1722,
     SQL_TEXT = 1723,
     KW_WHENEVER_SET = 1724,
     COMMENT = 1725,
     DATETIME_VALUE = 1000,
     INTERVAL_VALUE = 1001,
     FGL_SIZEOF = 1002,
     DYNAMIC_ARRAY = 1003,
     RESIZE_ARRAY = 1004,
     ALLOCATE_ARRAY = 1005,
     DEALLOCATE_ARRAY = 1006,
     AFTER_INSERT_DELETE = 1007,
     BEFORE_INSERT_DELETE = 1008,
     BEFORE_INSERT = 1009,
     AS_CONVERTABLE = 1010,
     CONCAT_PIPES = 1011,
     BEFORE_DELETE = 1012,
     DROP_TRIGGER = 1013,
     AFTER_INSERT = 1014,
     AFTER_DELETE = 1015,
     EXECUTE_IMMEDIATE = 1016,
     DELETE_ROW_EQUAL_TRUE = 1017,
     INSERT_ROW_EQUAL_TRUE = 1018,
     DELETE_ROW_EQUAL_FALSE = 1019,
     INSERT_ROW_EQUAL_FALSE = 1020,
     CURRENT_ROW_DISPLAY_EQUAL = 1021,
     MAXCOUNT = 1022,
     ALTER_TABLE = 1023,
     ALTER_INDEX = 1024,
     NEXT_SIZE = 1025,
     DISPLAY_ATTR_FORM = 1026,
     DISPLAY_ATTR_WINDOW = 1027,
     INPUT_ATTR_FORM = 1028,
     INPUT_ATTR_WINDOW = 1029,
     WHENEVER_ERROR_CONTINUE = 1030,
     WHENEVER_ANY_ERROR_CONTINUE = 1031,
     WHENEVER_WARNING_CONTINUE = 1032,
     WHENEVER_SQLSUCCESS_CONTINUE = 1033,
     WHENEVER_SQLWARNING_CONTINUE = 1034,
     WHENEVER_NOT_FOUND_CONTINUE = 1035,
     WHENEVER_SQLERROR_CONTINUE = 1036,
     WHENEVER_SUCCESS_CONTINUE = 1037,
     WHENEVER_ERROR_GOTO = 1038,
     WHENEVER_ANY_ERROR_GOTO = 1039,
     WHENEVER_WARNING_GOTO = 1040,
     WHENEVER_SQLSUCCESS_GOTO = 1041,
     WHENEVER_SQLWARNING_GOTO = 1042,
     WHENEVER_NOT_FOUND_GOTO = 1043,
     WHENEVER_SQLERROR_GOTO = 1044,
     WHENEVER_SUCCESS_GOTO = 1045,
     WHENEVER_ERROR_CALL = 1046,
     WHENEVER_ANY_ERROR_CALL = 1047,
     WHENEVER_WARNING_CALL = 1048,
     WHENEVER_SQLSUCCESS_CALL = 1049,
     WHENEVER_SQLWARNING_CALL = 1050,
     WHENEVER_NOT_FOUND_CALL = 1051,
     WHENEVER_SQLERROR_CALL = 1052,
     WHENEVER_SUCCESS_CALL = 1053,
     WHENEVER_ERROR_STOP = 1054,
     WHENEVER_ANY_ERROR_STOP = 1055,
     WHENEVER_WARNING_STOP = 1056,
     WHENEVER_SQLSUCCESS_STOP = 1057,
     WHENEVER_SQLWARNING_STOP = 1058,
     WHENEVER_NOT_FOUND_STOP = 1059,
     WHENEVER_SQLERROR_STOP = 1060,
     WHENEVER_SUCCESS_STOP = 1061,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1062,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1063,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1064,
     XSET_MULTIPLY_EQUAL = 1065,
     XSET_OPEN_BRACKET = 1066,
     NEWFORMATSHARED = 1067,
     CREATE_DATABASE = 1068,
     DROP_DATABASE = 1069,
     IMPORT_LEGACY_FUNCTION = 1070,
     ADD_CONSTRAINT = 1071,
     DROP_CONSTRAINT = 1072,
     DROP_SYNONYM = 1073,
     CONSTRAINT = 1074,
     AS_STATIC = 1075,
     NOT_FIELD_TOUCHED = 1076,
     LOCAL_FUNCTION = 1077,
     EVERY_ROW = 1078,
     ELIF = 1079,
     DOUBLE_PRECISION = 1080,
     COUNT_MULTIPLY = 1081,
     WAIT_FOR_KEY = 1082,
     AT_TERMINATION_CALL = 1083,
     TERMINATE_REPORT = 1084,
     TO_MAIN_CAPTION = 1085,
     CLEARSTAT = 1086,
     TO_MENUITEM = 1087,
     ID_TO_INT = 1088,
     TO_STATUSBOX = 1089,
     ASCII_HEIGHT_ALL = 1090,
     ASCII_WIDTH_ALL = 1091,
     IMPORT_DATATYPE = 1092,
     PAGE_TRAILER_SIZE = 1093,
     PAGE_HEADER_SIZE = 1094,
     FIRST_PAGE_HEADER_SIZE = 1095,
     BYTES_USE_AS_IMAGE = 1096,
     BYTES_USE_AS_ASCII = 1097,
     KWUP_BY = 1098,
     KWDOWN_BY = 1099,
     CLOSE_STATUSBOX = 1100,
     MODIFY_NEXT_SIZE = 1101,
     LOCK_MODE_PAGE = 1102,
     LOCK_MODE_ROW = 1103,
     TO_PIPE = 1104,
     TO_PRINTER = 1105,
     STATUSBOX = 1106,
     FORMHANDLER_INPUT = 1107,
     UNITS_YEAR = 1108,
     UNITS_MONTH = 1109,
     UNITS_DAY = 1110,
     UNITS_HOUR = 1111,
     UNITS_MINUTE = 1112,
     UNITS_SECOND = 1113,
     NO_NEW_LINES = 1114,
     FIELDTOWIDGET = 1115,
     WITH_HOLD = 1116,
     SHOW_MENU = 1117,
     TO_CLUSTER = 1118,
     TO_NOT_CLUSTER = 1119,
     CWIS = 1120,
     CREATE_IDX = 1121,
     FORM_IS_COMPILED = 1122,
     PDF_REPORT = 1123,
     IMPORT_FUNCTION = 1124,
     PROMPT_MANY = 1125,
     POINTS = 1126,
     MM = 1127,
     INCHES = 1128,
     PREPEND = 1129,
     MEMBER_OF = 1130,
     MEMBER_FUNCTION = 1131,
     APPEND = 1132,
     TEMPLATE = 1133,
     END_TEMPLATE = 1134,
     SQLSICS = 1135,
     CREATE_SCHEMA = 1136,
     SQLSIRR = 1137,
     UPDATESTATS_T = 1138,
     SQLSICR = 1139,
     WHENEVER_SQLSUCCESS = 1140,
     WHENEVER_SQLWARNING = 1141,
     WHENEVER_ANY_ERROR = 1142,
     WHENEVER_NOT_FOUND = 1143,
     WHENEVER_SQLERROR = 1144,
     WHENEVER_SUCCESS = 1145,
     WHENEVER_ERROR = 1146,
     START_EXTERN = 1147,
     CONTINUE_CONSTRUCT = 1148,
     FOUNCONSTR = 1149,
     SQLSIDR = 1150,
     CREATE_TEMP_TABLE = 1151,
     CURRENT_WINDOW_IS = 1152,
     FIRST_PAGE_HEADER = 1153,
     ORDER_EXTERNAL_BY = 1154,
     SCROLL_CURSOR_FOR = 1155,
     SCROLL_CURSOR = 1156,
     SQL_INTERRUPT_OFF = 1157,
     STOP_ALL_EXTERNAL = 1158,
     WITH_CHECK_OPTION = 1159,
     WITH_GRANT_OPTION = 1160,
     SQLSLMNW = 1161,
     ADDCONSTUNIQ = 1162,
     CONTINUE_DISPLAY = 1163,
     CONTINUE_FOREACH = 1164,
     OUTPUT_TO_REPORT = 1165,
     SQL_INTERRUPT_ON = 1166,
     WHERE_CURRENT_OF = 1167,
     WITHOUT_DEFAULTS = 1168,
     FOCONSTR = 1169,
     SCALED_BY = 1170,
     CONTINUE_PROMPT = 1171,
     PDF_FUNCTION = 1172,
     DEFER_INTERRUPT = 1173,
     DISPLAY_BY_NAME = 1174,
     NOT_NULL_UNIQUE = 1175,
     SKIP_TO_TOP = 1176,
     TOP_OF_PAGE = 1177,
     SKIP_TO = 1178,
     SKIP_BY = 1179,
     WITHOUT_WAITING = 1180,
     BEFCONSTRUCT = 1181,
     SQLSLMW = 1182,
     AFTCONSTRUCT = 1183,
     ALL_PRIVILEGES = 1184,
     CLOSE_DATABASE = 1185,
     CONTINUE_INPUT = 1186,
     CONTINUE_WHILE = 1187,
     CREATE_SYNONYM = 1188,
     DROP_TABLE = 1189,
     EXIT_CONSTRUCT = 1190,
     INEXCLUSIVE = 1191,
     REPORT_TO_PRINTER = 1192,
     REPORT_TO_PIPE = 1193,
     RETURN = 1194,
     SET_SESSION_TO = 1195,
     UPDATESTATS = 1196,
     WITHOUT_HEAD = 1197,
     CLEARSCR = 1198,
     WITH_B_LOG = 1199,
     AUTHORIZATION = 1200,
     BOTTOM_MARGIN = 1201,
     CLOSE_SESSION = 1202,
     CONTINUE_CASE = 1203,
     CONTINUE_MENU = 1204,
     DISPLAY_ARRAY = 1205,
     END_SQL = 1206,
     DOLLAR = 1207,
     END_CONSTRUCT = 1208,
     FIELD_TOUCHED = 1209,
     FINISH_REPORT = 1210,
     INFACC = 1211,
     INPUT_NO_WRAP = 1212,
     SETPMOFF = 1213,
     UNCONSTRAINED = 1214,
     PAGE_TRAILER = 1215,
     SETPMON = 1216,
     BEFGROUP = 1217,
     CLOSE_WINDOW = 1218,
     COMMENT_LINE = 1219,
     CONTINUE_FOR = 1220,
     CREATE_DB = 1221,
     CREATE_TABLE = 1222,
     DEFAULT_NULL = 1223,
     DEFAULT_TODAY = 1224,
     DEFAULT_USER = 1225,
     DELETE_USING = 1226,
     DISPLAY_FORM = 1227,
     END_FUNCTION = 1228,
     EXIT_DISPLAY = 1229,
     EXIT_FOREACH = 1230,
     EXIT_PROGRAM = 1231,
     INFCOLS = 1232,
     ON_EVERY_ROW = 1233,
     OPEN_SESSION = 1234,
     RIGHT_MARGIN = 1235,
     SELECT_USING = 1236,
     START_REPORT = 1237,
     UNLOCK_TABLE = 1238,
     UPDATE_USING = 1239,
     ACL_BUILTIN = 1240,
     AFTGROUP = 1241,
     INFIDX = 1242,
     INFSTAT = 1243,
     LEFT_MARGIN = 1244,
     PAGE_HEADER = 1245,
     ROLLBACK_W = 1246,
     SET_SESSION = 1247,
     SQLSEOFF = 1248,
     WITH_A_LOG = 1249,
     BEFDISP = 1250,
     BEFORE_MENU = 1251,
     CREATE_VIEW = 1252,
     DEFINE_TYPE = 1253,
     DELETE_FROM = 1254,
     END_DISPLAY = 1255,
     END_REPORT = 1256,
     END_FOREACH = 1257,
     END_FOR = 1258,
     END_GLOBALS = 1259,
     EXIT_PROMPT = 1260,
     EXTENT_SIZE = 1261,
     FOREIGN_KEY = 1262,
     HIDE_OPTION = 1263,
     HIDE_WINDOW = 1264,
     INSERT_INTO = 1265,
     IS_NOT_NULL = 1266,
     MOVE_WINDOW = 1267,
     NEXT_OPTION = 1268,
     NOT_MATCHES = 1269,
     ON_LAST_ROW = 1270,
     OPEN_WINDOW = 1271,
     OPEN_STATUSBOX = 1272,
     PAGE_LENGTH = 1273,
     PAGE_WIDTH = 1274,
     PRIMARY_KEY = 1275,
     PROMPT_LINE = 1276,
     RECORD_LIKE = 1277,
     ROLLFORWARD = 1278,
     SETBL = 1279,
     SHOW_OPTION = 1280,
     SHOW_WINDOW = 1281,
     SQLSEON = 1282,
     TO_DATABASE = 1283,
     USE_SESSION = 1284,
     WITH_NO_LOG = 1285,
     AFTDISP = 1286,
     BEFFIELD = 1287,
     INSHARE = 1288,
     UNLOCKTAB = 1289,
     AFTFIELD = 1290,
     ATTRIBUTES = 1291,
     BEFINP = 1292,
     BEGIN_WORK = 1293,
     CLEARWIN = 1294,
     CLOSE_FORM = 1295,
     DEFER_QUIT = 1296,
     DESCENDING = 1297,
     DROP_INDEX = 1298,
     END_PROMPT = 1299,
     END_RECORD = 1300,
     ERROR_LINE = 1301,
     EXIT_INPUT = 1302,
     EXIT_WHILE = 1303,
     FOR_UPDATE_OF = 1304,
     FOR_UPDATE = 1305,
     GET_FLDBUF = 1306,
     INITIALIZE = 1307,
     INPUT_WRAP = 1308,
     LOCK_TABLE = 1309,
     MSG_LINE = 1310,
     NOT_EXISTS = 1311,
     ON_ANY_KEY = 1312,
     REFERENCES = 1313,
     RENCOL = 1314,
     SET_CURSOR = 1315,
     SMALLFLOAT = 1316,
     SQLSUCCESS = 1317,
     TOP_MARGIN = 1318,
     WITH_ARRAY = 1319,
     ACCEPTKEY = 1320,
     ACCEPT = 1321,
     AFTINP = 1322,
     CLEARFORMTODEFAULTS = 1323,
     CLEARFORM = 1324,
     CLEAR_X_FORM = 1325,
     COMMIT_W = 1326,
     NEXTPAGE = 1327,
     PREVPAGE = 1328,
     CTRL_KEY = 1329,
     INFTABS = 1330,
     NEXTFIELD = 1331,
     NEXTFORM = 1332,
     RENTAB = 1333,
     ASCENDING = 1334,
     ASSOCIATE = 1335,
     CHAR = 1336,
     NCHAR = 1337,
     NVARCHAR = 1338,
     CONSTRUCT = 1339,
     DELIMITER = 1340,
     DOWNSHIFT = 1341,
     DROP_VIEW = 1342,
     END_INPUT = 1343,
     END_WHILE = 1344,
     EXCLUSIVE = 1345,
     EXIT_CASE = 1346,
     EXIT_MENU = 1347,
     FORM_LINE = 1348,
     INTERRUPT = 1350,
     INTO_TEMP = 1351,
     INVISIBLE = 1352,
     IN_MEMORY = 1353,
     LINKED_TO = 1354,
     LOAD_FROM = 1355,
     LOCKTAB = 1356,
     MENU_LINE = 1357,
     OPEN_FORM = 1358,
     OTHERWISE = 1359,
     PRECISION = 1360,
     PRIOR = 1361,
     PROCEDURE = 1362,
     REPORT_TO = 1363,
     RETURNING = 1364,
     UNDERLINE = 1365,
     UNLOAD_TO = 1366,
     BEFROW = 1367,
     UNLOAD_T = 1368,
     VARIABLE = 1369,
     ABSOLUTE = 1370,
     AFTROW = 1371,
     BUFFERED = 1372,
     CONSTANT = 1373,
     CONST = 1374,
     DATABASE = 1375,
     DATETIME = 1376,
     DEFAULTS = 1377,
     DISTINCT = 1378,
     END_CASE = 1379,
     END_MAIN = 1380,
     END_MENU = 1381,
     END_TYPE = 1382,
     EXIT_FOR = 1383,
     EXTERNAL = 1384,
     FRACTION = 1385,
     FUNCTION = 1386,
     GROUP_BY = 1387,
     INTERVAL = 1388,
     KWMESSAGE = 1389,
     NOT_LIKE = 1390,
     NOT_ILIKE = 1391,
     NOT_NULL = 1392,
     PASSWORD = 1393,
     PREVIOUS = 1394,
     READONLY = 1395,
     REGISTER = 1396,
     RELATIVE = 1397,
     RESOURCE = 1398,
     SMALLINT = 1399,
     VALIDATE = 1400,
     WITH_LOG = 1401,
     WORDWRAP = 1402,
     BY_NAME = 1403,
     IN_FILE = 1404,
     IS_NULL = 1405,
     AVERAGE = 1407,
     BETWEEN = 1408,
     CAPTION = 1409,
     CLIPPED = 1410,
     CLOSE_BRACKET = 1411,
     COLUMNS = 1412,
     CONNECT = 1414,
     CURRENT = 1415,
     DBYNAME = 1416,
     DECIMAL = 1417,
     DECLARE = 1418,
     DEFAULT = 1419,
     DISPLAY = 1420,
     ENDCODE = 1421,
     EXECUTE = 1422,
     FOREACH = 1423,
     FOREIGN = 1424,
     GLOBALS = 1425,
     INFIELD = 1426,
     INTEGER = 1427,
     KWWINDOW = 1428,
     MAGENTA = 1429,
     OPTIONS = 1431,
     PERCENT = 1432,
     PREPARE = 1433,
     PROGRAM = 1434,
     RECOVER = 1435,
     REVERSE = 1436,
     SECTION = 1437,
     SESSION = 1438,
     SYNONYM = 1439,
     THRU = 1440,
     TRAILER = 1441,
     UPSHIFT = 1442,
     VARCHAR = 1443,
     WAITING = 1444,
     CLOSE_SHEV = 1445,
     CLOSE_SQUARE = 1446,
     KW_FALSE = 1448,
     NOT_IN = 1449,
     ONKEY = 1450,
     OPEN_BRACKET = 1451,
     BORDER = 1452,
     BOTTOM = 1453,
     COLUMN = 1454,
     COMMIT = 1455,
     CREATE = 1456,
     CURSOR = 1457,
     DEFINE = 1458,
     DELETE = 1459,
     DOUBLE = 1460,
     END_IF = 1461,
     ESCAPE = 1462,
     EXISTS = 1463,
     EXTEND = 1464,
     EXTENT = 1465,
     FINISH = 1466,
     FORMAT = 1467,
     HAVING = 1468,
     HEADER = 1469,
     INSERT = 1470,
     LOCATE = 1471,
     MARGIN = 1472,
     MEMORY = 1473,
     MINUTE = 1474,
     MODIFY = 1475,
     NORMAL = 1476,
     EQUAL_EQUAL = 1477,
     OPEN_SHEV = 1479,
     OPEN_SQUARE = 1480,
     OPTION = 1481,
     OUTPUT = 1482,
     PROMPT = 1483,
     PUBLIC = 1484,
     RECORD = 1485,
     REPORT = 1486,
     REVOKE = 1487,
     SCHEMA = 1488,
     SCROLL_USING = 1489,
     SCROLL = 1490,
     SECOND = 1491,
     SELECT = 1492,
     SERIAL = 1493,
     SETL = 1494,
     SHARED = 1495,
     SPACES = 1496,
     UNIQUE = 1497,
     UNLOCK = 1498,
     UPDATE = 1499,
     VALUES = 1500,
     YELLOW = 1501,
     AFTER = 1502,
     KWLINE = 1503,
     KW_NULL = 1504,
     KW_TRUE = 1505,
     SINGLE_KEY = 1506,
     ALTER = 1507,
     ARRAY = 1508,
     ASCII = 1509,
     AUDIT = 1510,
     BLACK = 1511,
     BLINK = 1512,
     CHECK = 1513,
     CLEAR = 1514,
     CLOSE = 1515,
     CODE_C = 1516,
     COUNT = 1517,
     DEFER = 1518,
     ERROR = 1519,
     EVERY = 1520,
     FETCH = 1521,
     FIRST = 1522,
     FLOAT = 1523,
     FLUSH = 1524,
     FOUND = 1525,
     GRANT = 1526,
     GREEN = 1527,
     GROUP = 1528,
     INDEX = 1529,
     KWFORM = 1530,
     LABEL = 1531,
     LOCAL = 1533,
     MONEY = 1534,
     MONTH = 1535,
     ORDER = 1538,
     OUTER = 1539,
     PAUSE = 1540,
     PRINT_IMAGE = 1541,
     PRINT_FILE = 1542,
     PRINT = 1543,
     RIGHT = 1544,
     DOUBLE_COLON = 1545,
     SEMICOLON = 1546,
     SLEEP = 1547,
     TUPLE = 1548,
     UNION = 1549,
     WHERE = 1551,
     WHILE = 1552,
     WHITE = 1553,
     CCODE = 1554,
     ANSI = 1555,
     BLUE = 1556,
     BOLD = 1557,
     BYTE = 1558,
     FCALL = 1559,
     CASE = 1560,
     CYAN = 1561,
     DATE = 1562,
     DESC = 1563,
     KWDOWN = 1565,
     TAB = 1566,
     DROP = 1567,
     ELSE = 1568,
     EXEC = 1569,
     EXIT = 1570,
     FREE = 1571,
     FROM = 1572,
     GOTO = 1573,
     HELP_FILE = 1574,
     LANG_FILE = 1575,
     HELP = 1576,
     HIDE = 1577,
     HOUR = 1578,
     INTO = 1579,
     LAST = 1580,
     LEFT = 1581,
     LIKE = 1582,
     MAIN = 1583,
     MENU = 1584,
     MODE = 1585,
     NEED = 1586,
     NEXT = 1587,
     NOCR = 1588,
     OPEN = 1589,
     QUIT = 1590,
     REAL = 1591,
     ROWS = 1592,
     SHOW = 1593,
     SIZE = 1594,
     SKIP = 1595,
     SOME = 1596,
     STEP = 1597,
     STOP = 1598,
     TEMP = 1599,
     TEXT = 1600,
     THEN = 1601,
     USER = 1602,
     WAIT = 1603,
     WHEN = 1604,
     WITH = 1605,
     WORK = 1606,
     YEAR = 1607,
     KW_IS = 1609,
     XSET = 1610,
     ADD = 1611,
     ALL = 1612,
     ANY = 1614,
     ASC = 1615,
     AVG = 1616,
     COLON = 1617,
     DAY = 1619,
     DBA = 1620,
     DEC = 1621,
     DIM = 1622,
     FKEY = 1623,
     FOR = 1624,
     KEY = 1625,
     KWNO = 1626,
     LET = 1627,
     LOG = 1628,
     XMAX = 1629,
     XMIN = 1630,
     PAD = 1634,
     PUT = 1635,
     RED = 1636,
     ROW = 1637,
     RUN = 1638,
     SQL = 1639,
     SUM = 1640,
     TOP = 1641,
     USE = 1642,
     ATSIGN = 1643,
     AS_TIFF = 1645,
     AS_GIF = 1646,
     AS_PNG = 1647,
     AS_JPEG = 1648,
     AS = 1649,
     AT = 1650,
     BY = 1651,
     DOT = 1652,
     GO = 1653,
     IF = 1654,
     IN = 1655,
     OF = 1656,
     ON = 1657,
     TO = 1659,
     KWUP = 1660,
     FONT_NAME = 1661,
     FONT_SIZE = 1662,
     PAPER_SIZE_IS_LETTER = 1663,
     PAPER_SIZE_IS_LEGAL = 1664,
     PAPER_SIZE_IS_A5 = 1665,
     PAPER_SIZE_IS_A4 = 1666,
     PAPER_SIZE_IS_LETTER_L = 1667,
     PAPER_SIZE_IS_LEGAL_L = 1668,
     PAPER_SIZE_IS_A5_L = 1669,
     PAPER_SIZE_IS_A4_L = 1670,
     FORMHANDLER = 1671,
     END_FORMHANDLER = 1672,
     BEFORE_EVENT = 1673,
     BEFORE_OPEN_FORM = 1674,
     AFTER_EVENT = 1675,
     BEFORE_CLOSE_FORM = 1676,
     BEFORE_ANY = 1677,
     AFTER_ANY = 1678,
     MENUHANDLER = 1679,
     END_MENUHANDLER = 1680,
     BEFORE_SHOW_MENU = 1681,
     DISABLE_PROGRAM = 1682,
     DISABLE_ALL = 1683,
     BUTTONS = 1684,
     CHECK_MENUITEM = 1685,
     DISABLE_FORM = 1686,
     DISABLE_MENUITEMS = 1687,
     DISABLE = 1688,
     ENABLE_FORM = 1689,
     ENABLE_MENUITEMS = 1690,
     ENABLE = 1691,
     KWFIELD = 1692,
     ICON = 1693,
     MESSAGEBOX = 1694,
     TO_DEFAULTS = 1695,
     UNCHECK_MENUITEM = 1696,
     BEFORE = 1697,
     INPUT = 1698,
     END = 1699,
     INT_TO_ID = 1700,
     TIMEOUT = 1701,
     OFF = 1702,
     WITH_1_DIMENSION = 1703,
     WITH_2_DIMENSION = 1704,
     WITH_3_DIMENSION = 1705,
     TILDE = 1706,
     ILIKE = 1707,
     FGL_ISDYNARR_ALLOCATED = 1708,
     FGL_DYNARR_EXTENTSIZE = 1709,
     FILLFACTOR = 1710
   };
#endif
#define NAME 1712
#define UMINUS 1713
#define COMMA 1618
#define KW_OR 1658
#define KW_AND 1613
#define KW_USING 1550
#define NOT 1633
#define MATCHES 1430
#define POWER 1536
#define LESS_THAN 1532
#define GREATER_THAN 1447
#define EQUAL 1608
#define GREATER_THAN_EQ 1349
#define LESS_THAN_EQ 1406
#define NOT_EQUAL 1478
#define PLUS 1644
#define MINUS 1631
#define MULTIPLY 1537
#define DIVIDE 1564
#define MOD 1632
#define COMMAND 1413
#define NUMBER_VALUE 1714
#define CHAR_VALUE 1715
#define INT_VALUE 1716
#define NAMED_GEN 1717
#define CLINE 1718
#define SQLLINE 1719
#define KW_CSTART 1720
#define KW_CEND 1721
#define USER_DTYPE 1722
#define SQL_TEXT 1723
#define KW_WHENEVER_SET 1724
#define COMMENT 1725
#define DATETIME_VALUE 1000
#define INTERVAL_VALUE 1001
#define FGL_SIZEOF 1002
#define DYNAMIC_ARRAY 1003
#define RESIZE_ARRAY 1004
#define ALLOCATE_ARRAY 1005
#define DEALLOCATE_ARRAY 1006
#define AFTER_INSERT_DELETE 1007
#define BEFORE_INSERT_DELETE 1008
#define BEFORE_INSERT 1009
#define AS_CONVERTABLE 1010
#define CONCAT_PIPES 1011
#define BEFORE_DELETE 1012
#define DROP_TRIGGER 1013
#define AFTER_INSERT 1014
#define AFTER_DELETE 1015
#define EXECUTE_IMMEDIATE 1016
#define DELETE_ROW_EQUAL_TRUE 1017
#define INSERT_ROW_EQUAL_TRUE 1018
#define DELETE_ROW_EQUAL_FALSE 1019
#define INSERT_ROW_EQUAL_FALSE 1020
#define CURRENT_ROW_DISPLAY_EQUAL 1021
#define MAXCOUNT 1022
#define ALTER_TABLE 1023
#define ALTER_INDEX 1024
#define NEXT_SIZE 1025
#define DISPLAY_ATTR_FORM 1026
#define DISPLAY_ATTR_WINDOW 1027
#define INPUT_ATTR_FORM 1028
#define INPUT_ATTR_WINDOW 1029
#define WHENEVER_ERROR_CONTINUE 1030
#define WHENEVER_ANY_ERROR_CONTINUE 1031
#define WHENEVER_WARNING_CONTINUE 1032
#define WHENEVER_SQLSUCCESS_CONTINUE 1033
#define WHENEVER_SQLWARNING_CONTINUE 1034
#define WHENEVER_NOT_FOUND_CONTINUE 1035
#define WHENEVER_SQLERROR_CONTINUE 1036
#define WHENEVER_SUCCESS_CONTINUE 1037
#define WHENEVER_ERROR_GOTO 1038
#define WHENEVER_ANY_ERROR_GOTO 1039
#define WHENEVER_WARNING_GOTO 1040
#define WHENEVER_SQLSUCCESS_GOTO 1041
#define WHENEVER_SQLWARNING_GOTO 1042
#define WHENEVER_NOT_FOUND_GOTO 1043
#define WHENEVER_SQLERROR_GOTO 1044
#define WHENEVER_SUCCESS_GOTO 1045
#define WHENEVER_ERROR_CALL 1046
#define WHENEVER_ANY_ERROR_CALL 1047
#define WHENEVER_WARNING_CALL 1048
#define WHENEVER_SQLSUCCESS_CALL 1049
#define WHENEVER_SQLWARNING_CALL 1050
#define WHENEVER_NOT_FOUND_CALL 1051
#define WHENEVER_SQLERROR_CALL 1052
#define WHENEVER_SUCCESS_CALL 1053
#define WHENEVER_ERROR_STOP 1054
#define WHENEVER_ANY_ERROR_STOP 1055
#define WHENEVER_WARNING_STOP 1056
#define WHENEVER_SQLSUCCESS_STOP 1057
#define WHENEVER_SQLWARNING_STOP 1058
#define WHENEVER_NOT_FOUND_STOP 1059
#define WHENEVER_SQLERROR_STOP 1060
#define WHENEVER_SUCCESS_STOP 1061
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1062
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1063
#define XSET_ident_DOT_MULTIPLY_EQUAL 1064
#define XSET_MULTIPLY_EQUAL 1065
#define XSET_OPEN_BRACKET 1066
#define NEWFORMATSHARED 1067
#define CREATE_DATABASE 1068
#define DROP_DATABASE 1069
#define IMPORT_LEGACY_FUNCTION 1070
#define ADD_CONSTRAINT 1071
#define DROP_CONSTRAINT 1072
#define DROP_SYNONYM 1073
#define CONSTRAINT 1074
#define AS_STATIC 1075
#define NOT_FIELD_TOUCHED 1076
#define LOCAL_FUNCTION 1077
#define EVERY_ROW 1078
#define ELIF 1079
#define DOUBLE_PRECISION 1080
#define COUNT_MULTIPLY 1081
#define WAIT_FOR_KEY 1082
#define AT_TERMINATION_CALL 1083
#define TERMINATE_REPORT 1084
#define TO_MAIN_CAPTION 1085
#define CLEARSTAT 1086
#define TO_MENUITEM 1087
#define ID_TO_INT 1088
#define TO_STATUSBOX 1089
#define ASCII_HEIGHT_ALL 1090
#define ASCII_WIDTH_ALL 1091
#define IMPORT_DATATYPE 1092
#define PAGE_TRAILER_SIZE 1093
#define PAGE_HEADER_SIZE 1094
#define FIRST_PAGE_HEADER_SIZE 1095
#define BYTES_USE_AS_IMAGE 1096
#define BYTES_USE_AS_ASCII 1097
#define KWUP_BY 1098
#define KWDOWN_BY 1099
#define CLOSE_STATUSBOX 1100
#define MODIFY_NEXT_SIZE 1101
#define LOCK_MODE_PAGE 1102
#define LOCK_MODE_ROW 1103
#define TO_PIPE 1104
#define TO_PRINTER 1105
#define STATUSBOX 1106
#define FORMHANDLER_INPUT 1107
#define UNITS_YEAR 1108
#define UNITS_MONTH 1109
#define UNITS_DAY 1110
#define UNITS_HOUR 1111
#define UNITS_MINUTE 1112
#define UNITS_SECOND 1113
#define NO_NEW_LINES 1114
#define FIELDTOWIDGET 1115
#define WITH_HOLD 1116
#define SHOW_MENU 1117
#define TO_CLUSTER 1118
#define TO_NOT_CLUSTER 1119
#define CWIS 1120
#define CREATE_IDX 1121
#define FORM_IS_COMPILED 1122
#define PDF_REPORT 1123
#define IMPORT_FUNCTION 1124
#define PROMPT_MANY 1125
#define POINTS 1126
#define MM 1127
#define INCHES 1128
#define PREPEND 1129
#define MEMBER_OF 1130
#define MEMBER_FUNCTION 1131
#define APPEND 1132
#define TEMPLATE 1133
#define END_TEMPLATE 1134
#define SQLSICS 1135
#define CREATE_SCHEMA 1136
#define SQLSIRR 1137
#define UPDATESTATS_T 1138
#define SQLSICR 1139
#define WHENEVER_SQLSUCCESS 1140
#define WHENEVER_SQLWARNING 1141
#define WHENEVER_ANY_ERROR 1142
#define WHENEVER_NOT_FOUND 1143
#define WHENEVER_SQLERROR 1144
#define WHENEVER_SUCCESS 1145
#define WHENEVER_ERROR 1146
#define START_EXTERN 1147
#define CONTINUE_CONSTRUCT 1148
#define FOUNCONSTR 1149
#define SQLSIDR 1150
#define CREATE_TEMP_TABLE 1151
#define CURRENT_WINDOW_IS 1152
#define FIRST_PAGE_HEADER 1153
#define ORDER_EXTERNAL_BY 1154
#define SCROLL_CURSOR_FOR 1155
#define SCROLL_CURSOR 1156
#define SQL_INTERRUPT_OFF 1157
#define STOP_ALL_EXTERNAL 1158
#define WITH_CHECK_OPTION 1159
#define WITH_GRANT_OPTION 1160
#define SQLSLMNW 1161
#define ADDCONSTUNIQ 1162
#define CONTINUE_DISPLAY 1163
#define CONTINUE_FOREACH 1164
#define OUTPUT_TO_REPORT 1165
#define SQL_INTERRUPT_ON 1166
#define WHERE_CURRENT_OF 1167
#define WITHOUT_DEFAULTS 1168
#define FOCONSTR 1169
#define SCALED_BY 1170
#define CONTINUE_PROMPT 1171
#define PDF_FUNCTION 1172
#define DEFER_INTERRUPT 1173
#define DISPLAY_BY_NAME 1174
#define NOT_NULL_UNIQUE 1175
#define SKIP_TO_TOP 1176
#define TOP_OF_PAGE 1177
#define SKIP_TO 1178
#define SKIP_BY 1179
#define WITHOUT_WAITING 1180
#define BEFCONSTRUCT 1181
#define SQLSLMW 1182
#define AFTCONSTRUCT 1183
#define ALL_PRIVILEGES 1184
#define CLOSE_DATABASE 1185
#define CONTINUE_INPUT 1186
#define CONTINUE_WHILE 1187
#define CREATE_SYNONYM 1188
#define DROP_TABLE 1189
#define EXIT_CONSTRUCT 1190
#define INEXCLUSIVE 1191
#define REPORT_TO_PRINTER 1192
#define REPORT_TO_PIPE 1193
#define RETURN 1194
#define SET_SESSION_TO 1195
#define UPDATESTATS 1196
#define WITHOUT_HEAD 1197
#define CLEARSCR 1198
#define WITH_B_LOG 1199
#define AUTHORIZATION 1200
#define BOTTOM_MARGIN 1201
#define CLOSE_SESSION 1202
#define CONTINUE_CASE 1203
#define CONTINUE_MENU 1204
#define DISPLAY_ARRAY 1205
#define END_SQL 1206
#define DOLLAR 1207
#define END_CONSTRUCT 1208
#define FIELD_TOUCHED 1209
#define FINISH_REPORT 1210
#define INFACC 1211
#define INPUT_NO_WRAP 1212
#define SETPMOFF 1213
#define UNCONSTRAINED 1214
#define PAGE_TRAILER 1215
#define SETPMON 1216
#define BEFGROUP 1217
#define CLOSE_WINDOW 1218
#define COMMENT_LINE 1219
#define CONTINUE_FOR 1220
#define CREATE_DB 1221
#define CREATE_TABLE 1222
#define DEFAULT_NULL 1223
#define DEFAULT_TODAY 1224
#define DEFAULT_USER 1225
#define DELETE_USING 1226
#define DISPLAY_FORM 1227
#define END_FUNCTION 1228
#define EXIT_DISPLAY 1229
#define EXIT_FOREACH 1230
#define EXIT_PROGRAM 1231
#define INFCOLS 1232
#define ON_EVERY_ROW 1233
#define OPEN_SESSION 1234
#define RIGHT_MARGIN 1235
#define SELECT_USING 1236
#define START_REPORT 1237
#define UNLOCK_TABLE 1238
#define UPDATE_USING 1239
#define ACL_BUILTIN 1240
#define AFTGROUP 1241
#define INFIDX 1242
#define INFSTAT 1243
#define LEFT_MARGIN 1244
#define PAGE_HEADER 1245
#define ROLLBACK_W 1246
#define SET_SESSION 1247
#define SQLSEOFF 1248
#define WITH_A_LOG 1249
#define BEFDISP 1250
#define BEFORE_MENU 1251
#define CREATE_VIEW 1252
#define DEFINE_TYPE 1253
#define DELETE_FROM 1254
#define END_DISPLAY 1255
#define END_REPORT 1256
#define END_FOREACH 1257
#define END_FOR 1258
#define END_GLOBALS 1259
#define EXIT_PROMPT 1260
#define EXTENT_SIZE 1261
#define FOREIGN_KEY 1262
#define HIDE_OPTION 1263
#define HIDE_WINDOW 1264
#define INSERT_INTO 1265
#define IS_NOT_NULL 1266
#define MOVE_WINDOW 1267
#define NEXT_OPTION 1268
#define NOT_MATCHES 1269
#define ON_LAST_ROW 1270
#define OPEN_WINDOW 1271
#define OPEN_STATUSBOX 1272
#define PAGE_LENGTH 1273
#define PAGE_WIDTH 1274
#define PRIMARY_KEY 1275
#define PROMPT_LINE 1276
#define RECORD_LIKE 1277
#define ROLLFORWARD 1278
#define SETBL 1279
#define SHOW_OPTION 1280
#define SHOW_WINDOW 1281
#define SQLSEON 1282
#define TO_DATABASE 1283
#define USE_SESSION 1284
#define WITH_NO_LOG 1285
#define AFTDISP 1286
#define BEFFIELD 1287
#define INSHARE 1288
#define UNLOCKTAB 1289
#define AFTFIELD 1290
#define ATTRIBUTES 1291
#define BEFINP 1292
#define BEGIN_WORK 1293
#define CLEARWIN 1294
#define CLOSE_FORM 1295
#define DEFER_QUIT 1296
#define DESCENDING 1297
#define DROP_INDEX 1298
#define END_PROMPT 1299
#define END_RECORD 1300
#define ERROR_LINE 1301
#define EXIT_INPUT 1302
#define EXIT_WHILE 1303
#define FOR_UPDATE_OF 1304
#define FOR_UPDATE 1305
#define GET_FLDBUF 1306
#define INITIALIZE 1307
#define INPUT_WRAP 1308
#define LOCK_TABLE 1309
#define MSG_LINE 1310
#define NOT_EXISTS 1311
#define ON_ANY_KEY 1312
#define REFERENCES 1313
#define RENCOL 1314
#define SET_CURSOR 1315
#define SMALLFLOAT 1316
#define SQLSUCCESS 1317
#define TOP_MARGIN 1318
#define WITH_ARRAY 1319
#define ACCEPTKEY 1320
#define ACCEPT 1321
#define AFTINP 1322
#define CLEARFORMTODEFAULTS 1323
#define CLEARFORM 1324
#define CLEAR_X_FORM 1325
#define COMMIT_W 1326
#define NEXTPAGE 1327
#define PREVPAGE 1328
#define CTRL_KEY 1329
#define INFTABS 1330
#define NEXTFIELD 1331
#define NEXTFORM 1332
#define RENTAB 1333
#define ASCENDING 1334
#define ASSOCIATE 1335
#define CHAR 1336
#define NCHAR 1337
#define NVARCHAR 1338
#define CONSTRUCT 1339
#define DELIMITER 1340
#define DOWNSHIFT 1341
#define DROP_VIEW 1342
#define END_INPUT 1343
#define END_WHILE 1344
#define EXCLUSIVE 1345
#define EXIT_CASE 1346
#define EXIT_MENU 1347
#define FORM_LINE 1348
#define INTERRUPT 1350
#define INTO_TEMP 1351
#define INVISIBLE 1352
#define IN_MEMORY 1353
#define LINKED_TO 1354
#define LOAD_FROM 1355
#define LOCKTAB 1356
#define MENU_LINE 1357
#define OPEN_FORM 1358
#define OTHERWISE 1359
#define PRECISION 1360
#define PRIOR 1361
#define PROCEDURE 1362
#define REPORT_TO 1363
#define RETURNING 1364
#define UNDERLINE 1365
#define UNLOAD_TO 1366
#define BEFROW 1367
#define UNLOAD_T 1368
#define VARIABLE 1369
#define ABSOLUTE 1370
#define AFTROW 1371
#define BUFFERED 1372
#define CONSTANT 1373
#define CONST 1374
#define DATABASE 1375
#define DATETIME 1376
#define DEFAULTS 1377
#define DISTINCT 1378
#define END_CASE 1379
#define END_MAIN 1380
#define END_MENU 1381
#define END_TYPE 1382
#define EXIT_FOR 1383
#define EXTERNAL 1384
#define FRACTION 1385
#define FUNCTION 1386
#define GROUP_BY 1387
#define INTERVAL 1388
#define KWMESSAGE 1389
#define NOT_LIKE 1390
#define NOT_ILIKE 1391
#define NOT_NULL 1392
#define PASSWORD 1393
#define PREVIOUS 1394
#define READONLY 1395
#define REGISTER 1396
#define RELATIVE 1397
#define RESOURCE 1398
#define SMALLINT 1399
#define VALIDATE 1400
#define WITH_LOG 1401
#define WORDWRAP 1402
#define BY_NAME 1403
#define IN_FILE 1404
#define IS_NULL 1405
#define AVERAGE 1407
#define BETWEEN 1408
#define CAPTION 1409
#define CLIPPED 1410
#define CLOSE_BRACKET 1411
#define COLUMNS 1412
#define CONNECT 1414
#define CURRENT 1415
#define DBYNAME 1416
#define DECIMAL 1417
#define DECLARE 1418
#define DEFAULT 1419
#define DISPLAY 1420
#define ENDCODE 1421
#define EXECUTE 1422
#define FOREACH 1423
#define FOREIGN 1424
#define GLOBALS 1425
#define INFIELD 1426
#define INTEGER 1427
#define KWWINDOW 1428
#define MAGENTA 1429
#define OPTIONS 1431
#define PERCENT 1432
#define PREPARE 1433
#define PROGRAM 1434
#define RECOVER 1435
#define REVERSE 1436
#define SECTION 1437
#define SESSION 1438
#define SYNONYM 1439
#define THRU 1440
#define TRAILER 1441
#define UPSHIFT 1442
#define VARCHAR 1443
#define WAITING 1444
#define CLOSE_SHEV 1445
#define CLOSE_SQUARE 1446
#define KW_FALSE 1448
#define NOT_IN 1449
#define ONKEY 1450
#define OPEN_BRACKET 1451
#define BORDER 1452
#define BOTTOM 1453
#define COLUMN 1454
#define COMMIT 1455
#define CREATE 1456
#define CURSOR 1457
#define DEFINE 1458
#define DELETE 1459
#define DOUBLE 1460
#define END_IF 1461
#define ESCAPE 1462
#define EXISTS 1463
#define EXTEND 1464
#define EXTENT 1465
#define FINISH 1466
#define FORMAT 1467
#define HAVING 1468
#define HEADER 1469
#define INSERT 1470
#define LOCATE 1471
#define MARGIN 1472
#define MEMORY 1473
#define MINUTE 1474
#define MODIFY 1475
#define NORMAL 1476
#define EQUAL_EQUAL 1477
#define OPEN_SHEV 1479
#define OPEN_SQUARE 1480
#define OPTION 1481
#define OUTPUT 1482
#define PROMPT 1483
#define PUBLIC 1484
#define RECORD 1485
#define REPORT 1486
#define REVOKE 1487
#define SCHEMA 1488
#define SCROLL_USING 1489
#define SCROLL 1490
#define SECOND 1491
#define SELECT 1492
#define SERIAL 1493
#define SETL 1494
#define SHARED 1495
#define SPACES 1496
#define UNIQUE 1497
#define UNLOCK 1498
#define UPDATE 1499
#define VALUES 1500
#define YELLOW 1501
#define AFTER 1502
#define KWLINE 1503
#define KW_NULL 1504
#define KW_TRUE 1505
#define SINGLE_KEY 1506
#define ALTER 1507
#define ARRAY 1508
#define ASCII 1509
#define AUDIT 1510
#define BLACK 1511
#define BLINK 1512
#define CHECK 1513
#define CLEAR 1514
#define CLOSE 1515
#define CODE_C 1516
#define COUNT 1517
#define DEFER 1518
#define ERROR 1519
#define EVERY 1520
#define FETCH 1521
#define FIRST 1522
#define FLOAT 1523
#define FLUSH 1524
#define FOUND 1525
#define GRANT 1526
#define GREEN 1527
#define GROUP 1528
#define INDEX 1529
#define KWFORM 1530
#define LABEL 1531
#define LOCAL 1533
#define MONEY 1534
#define MONTH 1535
#define ORDER 1538
#define OUTER 1539
#define PAUSE 1540
#define PRINT_IMAGE 1541
#define PRINT_FILE 1542
#define PRINT 1543
#define RIGHT 1544
#define DOUBLE_COLON 1545
#define SEMICOLON 1546
#define SLEEP 1547
#define TUPLE 1548
#define UNION 1549
#define WHERE 1551
#define WHILE 1552
#define WHITE 1553
#define CCODE 1554
#define ANSI 1555
#define BLUE 1556
#define BOLD 1557
#define BYTE 1558
#define FCALL 1559
#define CASE 1560
#define CYAN 1561
#define DATE 1562
#define DESC 1563
#define KWDOWN 1565
#define TAB 1566
#define DROP 1567
#define ELSE 1568
#define EXEC 1569
#define EXIT 1570
#define FREE 1571
#define FROM 1572
#define GOTO 1573
#define HELP_FILE 1574
#define LANG_FILE 1575
#define HELP 1576
#define HIDE 1577
#define HOUR 1578
#define INTO 1579
#define LAST 1580
#define LEFT 1581
#define LIKE 1582
#define MAIN 1583
#define MENU 1584
#define MODE 1585
#define NEED 1586
#define NEXT 1587
#define NOCR 1588
#define OPEN 1589
#define QUIT 1590
#define REAL 1591
#define ROWS 1592
#define SHOW 1593
#define SIZE 1594
#define SKIP 1595
#define SOME 1596
#define STEP 1597
#define STOP 1598
#define TEMP 1599
#define TEXT 1600
#define THEN 1601
#define USER 1602
#define WAIT 1603
#define WHEN 1604
#define WITH 1605
#define WORK 1606
#define YEAR 1607
#define KW_IS 1609
#define XSET 1610
#define ADD 1611
#define ALL 1612
#define ANY 1614
#define ASC 1615
#define AVG 1616
#define COLON 1617
#define DAY 1619
#define DBA 1620
#define DEC 1621
#define DIM 1622
#define FKEY 1623
#define FOR 1624
#define KEY 1625
#define KWNO 1626
#define LET 1627
#define LOG 1628
#define XMAX 1629
#define XMIN 1630
#define PAD 1634
#define PUT 1635
#define RED 1636
#define ROW 1637
#define RUN 1638
#define SQL 1639
#define SUM 1640
#define TOP 1641
#define USE 1642
#define ATSIGN 1643
#define AS_TIFF 1645
#define AS_GIF 1646
#define AS_PNG 1647
#define AS_JPEG 1648
#define AS 1649
#define AT 1650
#define BY 1651
#define DOT 1652
#define GO 1653
#define IF 1654
#define IN 1655
#define OF 1656
#define ON 1657
#define TO 1659
#define KWUP 1660
#define FONT_NAME 1661
#define FONT_SIZE 1662
#define PAPER_SIZE_IS_LETTER 1663
#define PAPER_SIZE_IS_LEGAL 1664
#define PAPER_SIZE_IS_A5 1665
#define PAPER_SIZE_IS_A4 1666
#define PAPER_SIZE_IS_LETTER_L 1667
#define PAPER_SIZE_IS_LEGAL_L 1668
#define PAPER_SIZE_IS_A5_L 1669
#define PAPER_SIZE_IS_A4_L 1670
#define FORMHANDLER 1671
#define END_FORMHANDLER 1672
#define BEFORE_EVENT 1673
#define BEFORE_OPEN_FORM 1674
#define AFTER_EVENT 1675
#define BEFORE_CLOSE_FORM 1676
#define BEFORE_ANY 1677
#define AFTER_ANY 1678
#define MENUHANDLER 1679
#define END_MENUHANDLER 1680
#define BEFORE_SHOW_MENU 1681
#define DISABLE_PROGRAM 1682
#define DISABLE_ALL 1683
#define BUTTONS 1684
#define CHECK_MENUITEM 1685
#define DISABLE_FORM 1686
#define DISABLE_MENUITEMS 1687
#define DISABLE 1688
#define ENABLE_FORM 1689
#define ENABLE_MENUITEMS 1690
#define ENABLE 1691
#define KWFIELD 1692
#define ICON 1693
#define MESSAGEBOX 1694
#define TO_DEFAULTS 1695
#define UNCHECK_MENUITEM 1696
#define BEFORE 1697
#define INPUT 1698
#define END 1699
#define INT_TO_ID 1700
#define TIMEOUT 1701
#define OFF 1702
#define WITH_1_DIMENSION 1703
#define WITH_2_DIMENSION 1704
#define WITH_3_DIMENSION 1705
#define TILDE 1706
#define ILIKE 1707
#define FGL_ISDYNARR_ALLOCATED 1708
#define FGL_DYNARR_EXTENTSIZE 1709
#define FILLFACTOR 1710




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
#line 1708 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1720 "y.tab.c"

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
#define YYLAST   10984

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  728
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  863
/* YYNRULES -- Number of rules. */
#define YYNRULES  2357
/* YYNRULES -- Number of states. */
#define YYNSTATES  3782

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1725

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
     376,   377,   378,   379,   380,   381,   382,   383,   384,    15,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,    16,   441,   442,   443,
     444,   445,   446,    23,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      10,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,    13,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,    17,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,    12,   562,   563,   564,    11,    20,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
       8,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,    21,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,    14,   633,
     634,   635,   636,     7,   637,   638,   639,   640,     5,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,    19,    22,     9,   653,   654,   655,   656,   657,   658,
     659,   660,   661,   662,    18,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,     6,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,     2,     3,     4,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35
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
    1163,  1165,  1168,  1170,  1172,  1174,  1177,  1179,  1181,  1183,
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
    1842,  1843,  1844,  1856,  1857,  1860,  1861,  1862,  1863,  1873,
    1874,  1878,  1879,  1880,  1891,  1892,  1894,  1895,  1897,  1899,
    1902,  1903,  1907,  1908,  1912,  1913,  1915,  1917,  1920,  1921,
    1925,  1926,  1930,  1934,  1936,  1941,  1945,  1947,  1951,  1953,
    1957,  1959,  1963,  1965,  1968,  1969,  1973,  1974,  1978,  1979,
    1984,  1985,  1990,  1991,  1996,  1999,  2003,  2005,  2009,  2011,
    2013,  2015,  2017,  2019,  2021,  2023,  2027,  2029,  2031,  2036,
    2043,  2048,  2052,  2059,  2063,  2070,  2072,  2074,  2076,  2078,
    2080,  2082,  2084,  2086,  2087,  2090,  2092,  2094,  2096,  2101,
    2103,  2105,  2107,  2112,  2116,  2123,  2127,  2134,  2136,  2138,
    2141,  2144,  2146,  2149,  2152,  2154,  2158,  2160,  2163,  2166,
    2169,  2174,  2177,  2180,  2185,  2186,  2195,  2196,  2198,  2200,
    2202,  2203,  2205,  2208,  2209,  2211,  2214,  2215,  2217,  2220,
    2221,  2223,  2227,  2228,  2231,  2232,  2233,  2242,  2243,  2244,
    2248,  2249,  2250,  2258,  2264,  2267,  2270,  2271,  2277,  2282,
    2284,  2288,  2292,  2296,  2298,  2299,  2302,  2304,  2305,  2307,
    2309,  2312,  2313,  2318,  2319,  2324,  2325,  2329,  2330,  2334,
    2335,  2339,  2340,  2344,  2345,  2349,  2350,  2354,  2355,  2359,
    2360,  2364,  2365,  2369,  2370,  2374,  2375,  2379,  2381,  2385,
    2387,  2391,  2394,  2399,  2401,  2403,  2405,  2406,  2411,  2417,
    2424,  2425,  2436,  2440,  2443,  2446,  2448,  2450,  2453,  2456,
    2457,  2460,  2462,  2465,  2469,  2473,  2477,  2481,  2483,  2485,
    2487,  2489,  2490,  2494,  2496,  2497,  2501,  2504,  2507,  2509,
    2513,  2515,  2519,  2521,  2523,  2525,  2527,  2529,  2531,  2533,
    2535,  2537,  2539,  2541,  2543,  2545,  2547,  2549,  2551,  2553,
    2555,  2557,  2559,  2560,  2561,  2569,  2571,  2573,  2576,  2579,
    2582,  2586,  2591,  2592,  2596,  2597,  2599,  2601,  2604,  2606,
    2608,  2610,  2612,  2614,  2616,  2617,  2619,  2621,  2624,  2627,
    2629,  2631,  2633,  2635,  2637,  2639,  2641,  2643,  2645,  2647,
    2649,  2650,  2652,  2654,  2656,  2658,  2659,  2660,  2661,  2662,
    2676,  2678,  2679,  2680,  2687,  2690,  2692,  2695,  2698,  2701,
    2703,  2705,  2708,  2710,  2711,  2715,  2718,  2720,  2722,  2724,
    2725,  2726,  2727,  2742,  2743,  2749,  2751,  2752,  2756,  2757,
    2765,  2766,  2772,  2774,  2777,  2778,  2780,  2782,  2784,  2785,
    2787,  2789,  2792,  2795,  2798,  2800,  2802,  2804,  2806,  2810,
    2812,  2814,  2815,  2816,  2824,  2826,  2829,  2830,  2834,  2835,
    2840,  2843,  2844,  2847,  2849,  2851,  2853,  2855,  2857,  2859,
    2861,  2865,  2866,  2868,  2870,  2872,  2874,  2877,  2880,  2883,
    2889,  2898,  2900,  2902,  2904,  2909,  2914,  2916,  2918,  2920,
    2922,  2925,  2929,  2936,  2938,  2942,  2944,  2946,  2948,  2952,
    2959,  2969,  2971,  2973,  2975,  2977,  2980,  2981,  2983,  2985,
    2989,  2991,  2995,  2997,  3001,  3003,  3007,  3009,  3011,  3013,
    3015,  3019,  3021,  3025,  3027,  3031,  3033,  3035,  3037,  3041,
    3044,  3045,  3047,  3049,  3051,  3055,  3057,  3061,  3069,  3070,
    3078,  3079,  3086,  3090,  3092,  3096,  3098,  3101,  3107,  3108,
    3116,  3117,  3120,  3121,  3123,  3129,  3132,  3138,  3139,  3145,
    3152,  3157,  3158,  3160,  3162,  3168,  3169,  3172,  3173,  3179,
    3184,  3187,  3189,  3193,  3196,  3199,  3202,  3205,  3208,  3211,
    3213,  3216,  3219,  3222,  3225,  3228,  3231,  3234,  3236,  3238,
    3240,  3242,  3245,  3248,  3250,  3252,  3254,  3256,  3258,  3260,
    3266,  3268,  3270,  3273,  3278,  3283,  3290,  3293,  3295,  3296,
    3308,  3309,  3312,  3318,  3319,  3321,  3322,  3325,  3327,  3330,
    3331,  3335,  3337,  3338,  3343,  3344,  3347,  3349,  3353,  3355,
    3357,  3362,  3368,  3374,  3378,  3379,  3381,  3383,  3385,  3387,
    3388,  3390,  3398,  3401,  3404,  3407,  3410,  3413,  3415,  3418,
    3419,  3423,  3424,  3428,  3429,  3433,  3434,  3438,  3439,  3443,
    3444,  3449,  3450,  3455,  3457,  3459,  3461,  3463,  3465,  3467,
    3468,  3473,  3474,  3476,  3477,  3482,  3484,  3487,  3490,  3493,
    3494,  3496,  3498,  3501,  3504,  3505,  3508,  3509,  3514,  3518,
    3524,  3525,  3528,  3533,  3535,  3537,  3539,  3541,  3543,  3544,
    3546,  3548,  3552,  3555,  3561,  3564,  3570,  3576,  3582,  3588,
    3594,  3600,  3601,  3604,  3606,  3609,  3612,  3615,  3618,  3621,
    3624,  3626,  3629,  3632,  3635,  3638,  3640,  3643,  3646,  3649,
    3652,  3654,  3656,  3658,  3659,  3662,  3665,  3668,  3671,  3674,
    3677,  3680,  3683,  3686,  3688,  3690,  3692,  3694,  3696,  3698,
    3700,  3702,  3705,  3708,  3711,  3714,  3717,  3719,  3721,  3723,
    3724,  3728,  3731,  3732,  3733,  3734,  3735,  3736,  3737,  3753,
    3754,  3757,  3760,  3761,  3763,  3764,  3765,  3766,  3767,  3768,
    3769,  3785,  3788,  3789,  3790,  3791,  3802,  3803,  3805,  3809,
    3813,  3816,  3821,  3825,  3829,  3833,  3835,  3838,  3841,  3844,
    3847,  3849,  3851,  3852,  3853,  3862,  3863,  3864,  3874,  3875,
    3877,  3879,  3882,  3885,  3888,  3891,  3893,  3895,  3897,  3898,
    3900,  3902,  3905,  3908,  3911,  3920,  3923,  3926,  3931,  3934,
    3935,  3937,  3939,  3943,  3946,  3949,  3951,  3953,  3957,  3959,
    3961,  3964,  3966,  3970,  3974,  3978,  3980,  3984,  3986,  3988,
    3990,  3992,  3994,  3996,  3998,  4001,  4006,  4008,  4012,  4014,
    4018,  4021,  4026,  4028,  4032,  4034,  4037,  4042,  4044,  4048,
    4050,  4052,  4054,  4057,  4061,  4066,  4069,  4074,  4075,  4078,
    4081,  4086,  4088,  4092,  4094,  4096,  4098,  4101,  4103,  4105,
    4107,  4109,  4111,  4114,  4121,  4128,  4129,  4131,  4132,  4134,
    4137,  4139,  4140,  4146,  4147,  4153,  4155,  4156,  4160,  4162,
    4166,  4168,  4172,  4174,  4176,  4177,  4182,  4184,  4187,  4189,
    4190,  4191,  4195,  4196,  4197,  4201,  4203,  4205,  4207,  4209,
    4211,  4213,  4216,  4219,  4224,  4228,  4232,  4234,  4238,  4241,
    4243,  4245,  4246,  4248,  4250,  4252,  4254,  4255,  4257,  4261,
    4263,  4267,  4269,  4270,  4274,  4276,  4278,  4280,  4282,  4284,
    4286,  4288,  4290,  4292,  4294,  4296,  4298,  4306,  4313,  4318,
    4323,  4325,  4327,  4329,  4330,  4332,  4335,  4337,  4339,  4341,
    4343,  4347,  4350,  4352,  4354,  4357,  4359,  4361,  4362,  4366,
    4368,  4372,  4374,  4378,  4380,  4382,  4389,  4390,  4394,  4396,
    4400,  4401,  4403,  4408,  4414,  4417,  4419,  4421,  4426,  4428,
    4432,  4437,  4442,  4447,  4449,  4453,  4455,  4457,  4459,  4462,
    4464,  4466,  4468,  4473,  4474,  4476,  4477,  4479,  4481,  4484,
    4487,  4489,  4491,  4493,  4495,  4497,  4502,  4504,  4508,  4510,
    4512,  4514,  4517,  4519,  4521,  4524,  4527,  4529,  4533,  4536,
    4539,  4541,  4545,  4547,  4550,  4555,  4557,  4560,  4562,  4566,
    4571,  4572,  4574,  4575,  4577,  4578,  4580,  4582,  4586,  4588,
    4592,  4594,  4597,  4599,  4603,  4606,  4609,  4610,  4613,  4615,
    4617,  4623,  4627,  4633,  4637,  4639,  4643,  4645,  4647,  4648,
    4650,  4654,  4658,  4662,  4669,  4674,  4679,  4684,  4689,  4695,
    4697,  4699,  4701,  4703,  4705,  4707,  4709,  4711,  4713,  4715,
    4717,  4719,  4720,  4722,  4724,  4726,  4728,  4730,  4732,  4734,
    4739,  4740,  4742,  4747,  4749,  4755,  4761,  4763,  4765,  4767,
    4769,  4771,  4776,  4778,  4783,  4790,  4795,  4797,  4802,  4804,
    4812,  4814,  4816,  4818,  4823,  4830,  4831,  4834,  4839,  4841,
    4843,  4845,  4847,  4849,  4851,  4853,  4857,  4859,  4861,  4865,
    4871,  4875,  4881,  4889,  4893,  4895,  4897,  4901,  4907,  4911,
    4917,  4925,  4927,  4928,  4932,  4938,  4940,  4943,  4946,  4951,
    4955,  4957,  4959,  4961,  4963,  4965,  4968,  4971,  4972,  4976,
    4977,  4981,  4983,  4985,  4987,  4989,  4991,  4993,  4995,  5000,
    5002,  5004,  5006,  5008,  5010,  5012,  5014,  5019,  5021,  5023,
    5025,  5027,  5029,  5031,  5033,  5035,  5037,  5039,  5041,  5043,
    5045,  5047,  5052,  5054,  5058,  5060,  5064,  5065,  5073,  5074,
    5083,  5084,  5091,  5092,  5101,  5102,  5104,  5107,  5109,  5113,
    5115,  5119,  5125,  5127,  5129,  5131,  5133,  5135,  5136,  5137,
    5147,  5153,  5155,  5157,  5164,  5165,  5169,  5171,  5175,  5180,
    5182,  5183,  5186,  5191,  5198,  5199,  5201,  5203,  5205,  5207,
    5211,  5213,  5216,  5220,  5222,  5224,  5227,  5230,  5232,  5234,
    5236,  5239,  5242,  5245,  5248,  5253,  5257,  5260,  5264,  5268,
    5272,  5274,  5276,  5278,  5280,  5282,  5284,  5290,  5296,  5302,
    5308,  5314,  5319,  5324,  5328,  5333,  5335,  5337,  5339,  5343,
    5345,  5351,  5359,  5365,  5366,  5369,  5371,  5373,  5374,  5378,
    5380,  5384,  5386,  5388,  5390,  5391,  5395,  5397,  5399,  5401,
    5403,  5408,  5415,  5417,  5419,  5422,  5426,  5428,  5430,  5432,
    5434,  5436,  5438,  5440,  5442,  5448,  5454,  5459,  5465,  5467,
    5472,  5474,  5476,  5484,  5489,  5491,  5492,  5497,  5499,  5502,
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
    6124,  6126,  6128,  6130,  6132,  6134,  6136,  6138,  6139,  6143,
    6144,  6148,  6149,  6150,  6157,  6158,  6161,  6164,  6172,  6176,
    6180,  6183,  6186,  6189,  6191,  6195,  6197,  6201,  6203,  6207,
    6209,  6213,  6215,  6217,  6219,  6222,  6225,  6227,  6229,  6232,
    6237,  6243,  6251,  6259,  6269,  6271,  6273,  6275,  6277,  6279,
    6281,  6285,  6288,  6292,  6296,  6300,  6306,  6312,  6318,  6324,
    6330,  6335,  6340,  6344,  6349,  6351,  6353,  6355,  6357,  6361,
    6362,  6368,  6370,  6374,  6378,  6382,  6384,  6386,  6389,  6391,
    6393,  6397,  6399,  6403,  6407,  6409,  6411,  6413,  6417,  6420,
    6424,  6431,  6433,  6437,  6439,  6441,  6442,  6443,  6450,  6451,
    6454,  6455,  6457,  6459,  6462,  6465,  6467,  6469,  6474,  6478,
    6480,  6483,  6489,  6492,  6495,  6501,  6502,  6505,  6507,  6509,
    6512,  6519,  6526,  6528,  6529,  6531,  6534,  6536,  6539,  6540,
    6543,  6545,  6547,  6549,  6551,  6553,  6555,  6557,  6559,  6561,
    6563,  6565,  6567,  6569,  6571,  6573,  6575,  6577,  6579,  6581,
    6583,  6585,  6587,  6589,  6591,  6593,  6595,  6597,  6599,  6601,
    6603,  6605,  6607,  6609,  6611,  6613,  6615,  6617,  6619,  6621,
    6623,  6625,  6627,  6629,  6631,  6633,  6635,  6637,  6639,  6641,
    6643,  6645,  6647,  6649,  6651,  6653,  6655,  6657,  6659,  6661,
    6663,  6665,  6667,  6669,  6671,  6673,  6675,  6677,  6679,  6681,
    6683,  6685,  6687,  6689,  6691,  6693,  6695,  6697,  6699,  6701,
    6703,  6705,  6707,  6709,  6711,  6713,  6715,  6717
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1098,     0,    -1,   252,    -1,   249,    -1,   183,   733,   478,
     646,   734,    -1,   194,    -1,  1163,    -1,    26,    -1,   735,
      -1,   734,     5,   735,    -1,  1006,    -1,   482,   736,   445,
      -1,   736,   737,   736,    -1,    26,    -1,   738,    26,    -1,
    1163,    -1,   946,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   740,
      -1,    -1,   327,   482,   741,   742,   445,    -1,   619,   482,
      26,     5,    26,   445,    -1,   743,    -1,   742,     5,   743,
      -1,   541,    -1,   582,    -1,   587,    -1,   557,    -1,   462,
      -1,   655,    -1,   579,    -1,   531,    -1,   468,    -1,   542,
      -1,   400,    -1,   583,    -1,   507,    -1,   387,    -1,   644,
      -1,   150,    -1,  1077,    -1,    -1,   745,    -1,    -1,   327,
     482,   746,   747,   445,    -1,   748,    -1,   747,     5,   748,
      -1,   743,    -1,   483,    -1,   653,    25,    -1,   255,   992,
      -1,   384,   992,    -1,   337,   992,    -1,   392,   992,    -1,
     346,   992,    -1,   312,   992,    -1,   585,   750,    -1,   935,
     399,  1163,    -1,    -1,   342,   482,   954,   445,   399,   751,
    1181,    -1,   158,   482,  1006,     5,    25,     5,    25,   445,
      -1,   459,   482,   998,   445,   399,  1163,    -1,  1301,    -1,
     245,   482,   954,   445,   399,  1163,    -1,    -1,    -1,  1163,
     640,  1006,   482,   752,   766,   445,   753,   764,    -1,    -1,
      -1,    -1,  1006,   482,   754,   766,   755,   445,   756,   764,
      -1,    -1,    -1,   525,  1510,   673,  1510,   482,   757,   766,
     758,   445,   764,    -1,    -1,    -1,  1006,   572,  1006,   482,
     759,   766,   760,   445,   764,    -1,    -1,    -1,    -1,   419,
     769,   640,   770,   510,   733,   478,   482,   761,   766,   762,
     445,   763,   765,    -1,    -1,   399,  1181,    -1,    -1,   399,
    1181,    -1,   216,    -1,    -1,   767,    -1,   768,    -1,   767,
       5,   768,    -1,   906,    -1,   534,    -1,    25,    -1,  1006,
      -1,  1006,    -1,  1006,   670,  1006,    -1,    -1,   586,   913,
     772,   775,   779,   776,    -1,    -1,   586,   773,   774,   777,
     776,    -1,   781,    -1,   774,   781,    -1,   783,    -1,   775,
     783,    -1,   414,    -1,    -1,    -1,   394,   778,  1585,    -1,
      -1,    -1,   394,   780,  1585,    -1,    -1,   629,   913,   782,
    1585,    -1,    -1,   629,   913,   784,  1585,    -1,   331,  1003,
      -1,   254,  1001,    -1,   136,  1001,    -1,   221,    -1,   238,
    1516,    -1,   545,  1000,    -1,    30,   787,    31,    -1,   788,
      -1,   790,    -1,   789,    -1,   788,   789,    -1,    29,    -1,
     791,    -1,   790,   791,    -1,    28,    -1,    -1,    -1,   375,
     793,   795,   794,   796,    -1,   438,  1163,   675,   797,  1049,
    1076,   739,    -1,  1163,   675,   797,  1049,   597,   954,  1076,
     739,    -1,    -1,   799,   244,    -1,   798,    -1,   797,     5,
     798,    -1,  1006,    -1,  1006,   670,  1006,    -1,  1006,   670,
      20,    -1,   800,    -1,   799,   800,    -1,    -1,   323,   806,
     801,  1585,    -1,    -1,   326,   807,   802,  1585,    -1,    -1,
    1079,   803,  1585,    -1,    -1,   219,   804,  1585,    -1,    -1,
     217,   805,  1585,    -1,  1010,    -1,   806,     5,  1010,    -1,
    1010,    -1,   807,     5,  1010,    -1,   144,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   482,   906,
     810,   445,    -1,    -1,     5,   857,   676,   860,    -1,   209,
      -1,   332,    -1,    -1,   813,    -1,   814,    -1,   813,   814,
      -1,    -1,    -1,   489,   815,   817,   816,  1270,    -1,   870,
      -1,   820,    -1,   817,     5,   820,    -1,    -1,   819,  1006,
      -1,   408,   818,   869,    25,    -1,   408,   818,   869,  1006,
      -1,   408,   818,   869,  1012,    -1,   408,   818,   869,    26,
      -1,   824,   842,    -1,    -1,   818,   408,   821,   822,    -1,
      26,    -1,    25,    -1,  1012,    -1,    19,    26,    -1,   818,
      -1,   823,    -1,   824,     5,   823,    -1,    -1,   372,    -1,
      -1,   720,    -1,   721,    -1,   722,    -1,    -1,   538,   510,
     834,   478,   828,   674,   842,    -1,    -1,    39,   826,   829,
     674,   842,    -1,    -1,   371,   825,   831,    26,   832,   355,
     510,   833,   478,   830,   674,   842,    -1,   482,    -1,   509,
      -1,   445,    -1,   477,    -1,    26,    -1,   835,     5,   835,
       5,   835,    -1,   835,     5,   835,    -1,   835,    -1,    26,
      -1,    -1,   515,   837,   817,   336,    -1,    -1,   313,   838,
     818,   670,    20,    -1,    -1,   389,   839,   818,   311,   482,
     840,   445,    -1,   841,    -1,   840,     5,   841,    -1,   818,
      -1,   844,    -1,    -1,   111,    -1,    -1,    -1,   845,   847,
     846,   843,    -1,   827,    -1,   836,    -1,   372,    -1,   373,
      -1,   372,   482,    26,   445,    -1,   373,   482,    26,   445,
      -1,   475,   482,    26,   445,    -1,   475,   482,    26,     5,
      26,   445,    -1,   374,   482,    26,   445,    -1,   374,   482,
      26,     5,    26,   445,    -1,   460,    -1,   667,   818,    -1,
     434,    -1,   560,    -1,   142,    -1,   450,    -1,   450,   482,
      26,   445,    -1,   450,   482,    26,     5,    26,   445,    -1,
     563,    -1,   563,   482,    26,   445,    -1,   563,   482,    26,
       5,    26,   445,    -1,    -1,   553,   848,   851,    -1,    -1,
     116,   849,   851,    -1,    -1,   352,   850,   851,    -1,   588,
      -1,   584,    -1,   132,    -1,   133,    -1,   625,    -1,   411,
     855,    -1,   423,   856,    -1,   852,    -1,    32,    -1,    -1,
     482,    26,   445,    -1,   607,   853,   670,   854,    -1,   818,
      -1,   818,    -1,    -1,   857,   676,   860,    -1,   865,   676,
     868,    -1,    -1,   858,   859,    -1,   632,    -1,   564,    -1,
     641,    -1,   603,    -1,   505,    -1,   521,    -1,   420,   862,
      -1,    -1,   861,   859,    -1,    -1,   482,   864,   445,    -1,
      -1,   482,    26,   445,    -1,    26,    -1,    -1,   866,   867,
     863,    -1,   632,    -1,   564,    -1,   641,    -1,   603,    -1,
     505,    -1,   521,    -1,   420,   862,    -1,   867,    -1,    -1,
      14,    -1,    -1,   289,  1006,   871,   667,   872,    -1,   874,
      -1,   877,    -1,   372,    -1,   372,   482,    26,   445,    -1,
     475,   482,    26,   445,    -1,   475,   482,    26,     5,    26,
     445,    -1,   460,    -1,   434,    -1,   560,    -1,   450,    -1,
     450,   482,    26,   445,    -1,   450,   482,    26,     5,    26,
     445,    -1,   563,    -1,   563,   482,    26,   445,    -1,   563,
     482,    26,     5,    26,   445,    -1,   553,    -1,   352,    -1,
     588,    -1,   584,    -1,   625,    -1,   411,   855,    -1,   423,
     856,    -1,   873,    -1,   607,   853,   670,   854,    -1,    -1,
     538,   510,   834,   478,   875,   674,   872,    -1,    -1,   371,
     825,   831,    26,   832,   355,   510,   833,   478,   876,   674,
     872,    -1,    -1,   515,   878,   880,   336,    -1,    -1,   313,
     879,  1006,   670,    20,    -1,   881,    -1,   880,     5,   881,
      -1,   882,   872,    -1,   883,    -1,   882,     5,   883,    -1,
    1006,    -1,    -1,   668,   996,    -1,   123,  1006,    -1,   121,
      -1,   676,   954,    -1,   676,   560,  1006,   709,   954,    -1,
     676,   560,  1006,   443,    -1,   125,  1006,    -1,   210,   929,
    1181,   892,    -1,   453,   929,   911,   884,   892,    -1,   263,
    1003,   892,    -1,    -1,    -1,   241,   889,  1188,   676,  1006,
     670,    20,   891,   739,   890,   893,    -1,    -1,   519,   997,
      -1,   739,    -1,    -1,   894,   291,    -1,   291,    -1,   895,
      -1,   894,   895,    -1,    -1,   406,   896,  1585,    -1,    -1,
     402,   897,  1585,    -1,    -1,  1079,   898,  1585,    -1,    41,
    1163,    -1,    42,  1163,    -1,    40,  1163,    -1,   549,   929,
     912,   739,    -1,   549,   929,   912,   739,   118,    -1,   339,
      -1,   338,    -1,   266,    -1,   418,    -1,   226,    -1,   265,
      -1,   383,    -1,   382,    -1,   296,    -1,   223,    -1,   222,
      -1,   200,    -1,   256,    -1,   184,    -1,   199,    -1,   240,
      -1,   207,    -1,   267,    -1,   267,   913,    -1,   914,    -1,
     918,    -1,   946,    -1,   906,   907,    -1,   947,    -1,   949,
      -1,   915,    -1,    19,   906,    -1,    18,   906,    -1,   920,
      -1,   928,    -1,   922,    -1,   526,    -1,   808,    -1,   923,
      -1,   924,    -1,   925,    -1,   926,    -1,   927,    -1,    47,
     906,    -1,   929,    -1,   929,   910,    -1,   913,    -1,   534,
      -1,   909,    -1,   910,     5,   909,    -1,   913,    -1,   911,
       5,   913,    -1,   913,    -1,   912,     5,   913,    -1,   906,
      -1,     9,   906,    -1,   535,    -1,   479,    -1,   482,   906,
     445,    -1,   494,   482,  1490,   445,    -1,   347,   482,  1490,
     445,    -1,    25,    -1,  1012,    -1,    26,    -1,   917,    -1,
    1163,    -1,  1163,   472,  1163,    -1,   916,    -1,   485,   906,
      -1,   446,   906,    -1,  1273,    -1,    -1,   558,   919,  1273,
      -1,     7,   906,    -1,     6,   906,    -1,   906,    -1,   921,
       5,   906,    -1,   673,   482,  1490,   445,    -1,   480,   482,
    1490,   445,    -1,   673,   482,   929,   921,   445,    -1,   480,
     482,   929,   921,   445,    -1,   440,    -1,   302,    -1,    10,
     906,    -1,   305,   906,    -1,    10,   906,   493,    25,    -1,
     305,   906,   493,    25,    -1,   607,   906,    -1,   425,   906,
      -1,   607,   906,   493,    25,    -1,   425,   906,   493,    25,
      -1,   444,    -1,     8,   906,    -1,    18,   906,    -1,    19,
     906,    -1,    20,   906,    -1,    21,   906,    -1,    22,   906,
      -1,    11,   906,    -1,    14,   906,    -1,   508,   906,    -1,
      12,   906,    -1,    13,   906,    -1,    17,   906,    -1,    16,
     906,    -1,    15,   906,    -1,    -1,    -1,    -1,  1006,   482,
     931,   766,   932,   445,    -1,    -1,    -1,  1006,   572,  1006,
     482,   933,   766,   934,   445,    -1,    -1,    -1,   588,   482,
     936,   906,   937,   445,    -1,    -1,    -1,   564,   482,   938,
     906,   939,   445,    -1,    -1,    -1,   641,   482,   940,   906,
     941,   445,    -1,    -1,    -1,   632,   482,   942,   906,   943,
     445,    -1,   423,   482,   950,   445,   945,    -1,   411,   482,
      25,   445,   944,    -1,   411,   482,    26,   445,   944,    -1,
     411,   482,    24,   445,   944,    -1,   411,   482,    26,   640,
      26,   445,   944,    -1,   411,   482,    26,   640,    24,   445,
     944,    -1,   411,   482,    26,   640,    26,   640,    26,   445,
     944,    -1,   411,   482,    26,   640,    26,   640,    24,   445,
     944,    -1,   411,   482,    26,    26,   445,   944,    -1,   411,
     482,    26,    26,   640,    26,   445,   944,    -1,   411,   482,
      26,    26,   640,    26,   640,    26,   445,   944,    -1,   411,
     482,    26,    26,   640,    26,   640,    24,   445,   944,    -1,
     411,   482,    26,    19,    26,   445,   944,    -1,   411,   482,
      26,    19,    26,    19,    26,   445,   944,    -1,   411,   482,
      26,    19,    26,    26,   445,   944,    -1,   411,   482,    26,
      19,    26,    19,    26,    26,   445,   944,    -1,   411,   482,
      26,    19,    26,    19,    26,    26,   640,    26,   445,   944,
      -1,   411,   482,    26,    19,    26,    19,    26,    26,   640,
      26,   640,    26,   445,   944,    -1,   411,   482,    26,    19,
      26,    19,    26,    26,   640,    26,   640,    24,   445,   944,
      -1,   411,   482,    26,    19,    26,    26,   640,    26,   445,
     944,    -1,   411,   482,    26,    19,    26,    26,   640,    26,
     640,    26,   445,   944,    -1,   411,   482,    26,    19,    26,
      26,   640,    26,   640,    24,   445,   944,    -1,    38,   482,
    1163,   445,    -1,   725,   482,  1163,   445,    -1,   726,   482,
    1163,     5,    26,   445,    -1,    -1,  1470,   676,  1471,    -1,
     856,    -1,   935,    -1,   342,   482,   954,   445,    -1,   151,
     482,   997,   445,    -1,   124,   482,   997,   445,    -1,   459,
     482,   955,   445,    -1,   245,   482,   954,   445,    -1,   112,
     482,   954,   445,    -1,   948,    -1,   930,    -1,  1466,    -1,
     588,    -1,   474,   482,   906,   445,    -1,   377,   482,   906,
     445,    -1,   539,   906,    -1,   495,   809,    -1,   906,   162,
      -1,   906,   163,    -1,   906,   164,    -1,    25,    -1,   951,
      -1,    19,   951,    -1,   953,    -1,   952,    -1,    26,    -1,
      26,    26,    -1,    26,    26,   640,    26,    -1,    26,    26,
     640,    26,   640,    26,    -1,    26,    26,   640,    26,   640,
      24,    -1,    26,   640,    26,    -1,    26,   640,    26,   640,
      26,    -1,    26,   640,    26,   640,    24,    -1,    26,   640,
      24,    -1,    24,    -1,    26,    -1,    26,    19,    26,    -1,
     997,    -1,   954,     5,   997,    -1,   998,    -1,   955,     5,
     998,    -1,    -1,    -1,   646,  1163,    14,   913,   676,   913,
     959,   957,  1585,   958,   294,    -1,    -1,   622,   913,    -1,
      -1,    -1,    -1,   456,   961,  1000,   962,   964,  1368,   963,
    1585,   293,    -1,    -1,     8,   929,   911,    -1,    -1,    -1,
     688,  1006,   966,   812,   967,  1108,   969,   968,   974,   689,
      -1,    -1,   979,    -1,    -1,   970,    -1,   971,    -1,   970,
     971,    -1,    -1,   690,   972,  1585,    -1,    -1,   691,   973,
    1585,    -1,    -1,   975,    -1,   976,    -1,   975,   976,    -1,
      -1,   692,   977,  1585,    -1,    -1,   693,   978,  1585,    -1,
     980,   984,   379,    -1,   143,    -1,   143,   981,   597,   982,
      -1,   143,   438,   983,    -1,  1163,    -1,   981,     5,  1163,
      -1,  1006,    -1,   982,     5,  1006,    -1,  1163,    -1,   983,
       5,  1163,    -1,   985,    -1,   984,   985,    -1,    -1,   694,
     986,  1585,    -1,    -1,   695,   987,  1585,    -1,    -1,   714,
     982,   988,  1585,    -1,    -1,   532,   982,   989,  1585,    -1,
      -1,   675,   982,   990,  1585,    -1,   596,   999,    -1,   605,
      19,    26,    -1,   605,    -1,   552,    18,    26,    -1,   552,
      -1,    26,    -1,  1163,    -1,   719,    -1,    25,    -1,  1011,
      -1,   913,    -1,   994,     5,   994,    -1,   995,    -1,  1006,
      -1,   717,   482,  1006,   445,    -1,  1006,   670,   717,   482,
    1006,   445,    -1,  1006,   510,   736,   478,    -1,  1006,   670,
      20,    -1,  1006,   510,   736,   478,   670,    20,    -1,  1006,
     670,  1006,    -1,  1006,   510,   736,   478,   670,  1006,    -1,
     997,    -1,    25,    -1,  1007,    -1,  1007,    -1,  1007,    -1,
    1007,    -1,  1007,    -1,  1007,    -1,    -1,   601,    26,    -1,
    1584,    -1,  1008,    -1,  1584,    -1,   404,   482,  1009,   445,
      -1,  1166,    -1,    25,    -1,  1006,    -1,  1006,   510,   736,
     478,    -1,  1006,   670,    20,    -1,  1006,   510,   736,   478,
     670,    20,    -1,  1006,   670,  1006,    -1,  1006,   510,   736,
     478,   670,  1006,    -1,  1163,    -1,    24,    -1,   670,    26,
      -1,   598,  1014,    -1,  1006,    -1,   640,  1006,    -1,   702,
    1016,    -1,  1017,    -1,  1016,     5,  1017,    -1,  1006,    -1,
     713,  1016,    -1,   704,  1016,    -1,   705,   954,    -1,   703,
    1003,   709,   954,    -1,   707,  1016,    -1,   708,   954,    -1,
     706,  1003,   709,   954,    -1,    -1,   711,  1022,   911,  1027,
    1029,  1031,  1023,  1025,    -1,    -1,  1024,    -1,   699,    -1,
     700,    -1,    -1,  1026,    -1,   399,  1163,    -1,    -1,  1028,
      -1,   443,   911,    -1,    -1,  1030,    -1,   710,    26,    -1,
      -1,  1032,    -1,   701,    26,  1033,    -1,    -1,   452,    26,
      -1,    -1,    -1,   672,   913,   626,  1035,  1585,  1036,  1037,
     492,    -1,    -1,    -1,   593,  1038,  1585,    -1,    -1,    -1,
     115,  1039,   913,   626,  1040,  1585,  1037,    -1,   160,  1006,
     482,    26,   445,    -1,   106,  1006,    -1,   128,  1006,    -1,
      -1,   343,  1192,  1044,   676,   534,    -1,   343,  1192,   607,
    1045,    -1,  1046,    -1,  1045,     5,  1046,    -1,  1047,   670,
    1462,    -1,  1047,   670,    20,    -1,  1458,    -1,    -1,  1050,
     379,    -1,   379,    -1,    -1,   204,    -1,  1051,    -1,  1050,
    1051,    -1,    -1,   323,  1065,  1052,  1585,    -1,    -1,   326,
    1066,  1053,  1585,    -1,    -1,   406,  1054,  1585,    -1,    -1,
     402,  1055,  1585,    -1,    -1,  1079,  1056,  1585,    -1,    -1,
     358,  1057,  1585,    -1,    -1,   328,  1058,  1585,    -1,    -1,
      48,  1059,  1585,    -1,    -1,    45,  1060,  1585,    -1,    -1,
      44,  1061,  1585,    -1,    -1,    43,  1062,  1585,    -1,    -1,
      51,  1063,  1585,    -1,    -1,    50,  1064,  1585,    -1,   997,
      -1,  1065,     5,   997,    -1,   997,    -1,  1066,     5,   997,
      -1,   367,  1069,    -1,   368,  1006,   709,  1069,    -1,   612,
      -1,   429,    -1,   997,    -1,    -1,   715,  1072,  1071,  1048,
      -1,   438,  1181,  1049,  1005,   739,    -1,  1181,  1049,   597,
     954,  1005,   739,    -1,    -1,   538,  1188,  1049,   597,  1006,
     670,    20,  1005,  1073,   739,    -1,   520,   954,  1075,    -1,
     134,    26,    -1,   135,    26,    -1,   677,    -1,   590,    -1,
     134,  1163,    -1,   135,  1163,    -1,    -1,   601,    26,    -1,
    1078,    -1,    57,    25,    -1,   547,    14,    26,    -1,   547,
      14,  1163,    -1,    58,    14,    26,    -1,    58,    14,  1163,
      -1,    54,    -1,    56,    -1,    53,    -1,    55,    -1,    -1,
     481,  1080,  1085,    -1,   348,    -1,    -1,   647,  1082,  1085,
      -1,   356,  1087,    -1,   647,  1085,    -1,  1087,    -1,   482,
    1086,   445,    -1,  1087,    -1,  1086,     5,  1087,    -1,  1088,
      -1,   645,    -1,   365,    -1,   385,    -1,   357,    -1,   536,
      -1,   493,    -1,   677,    -1,   601,    -1,   590,    -1,   230,
      -1,   490,    -1,   501,    -1,   591,    -1,   606,    -1,   571,
      -1,   363,    -1,   364,    -1,    25,    -1,   561,    -1,    -1,
      -1,   649,  1091,  1186,  1092,    14,   929,  1093,    -1,   534,
      -1,   912,    -1,   272,  1163,    -1,   262,  1163,    -1,   275,
    1163,    -1,   502,  1184,   388,    -1,   502,  1184,   439,   993,
      -1,    -1,  1100,  1099,  1103,    -1,    -1,  1101,    -1,  1102,
      -1,  1101,  1102,    -1,  1042,    -1,  1107,    -1,  1569,    -1,
    1123,    -1,  1109,    -1,  1122,    -1,    -1,  1104,    -1,  1106,
      -1,  1104,  1106,    -1,   119,  1006,    -1,  1111,    -1,  1117,
      -1,  1129,    -1,  1283,    -1,  1293,    -1,  1150,    -1,   965,
      -1,   786,    -1,  1041,    -1,  1569,    -1,   786,    -1,    -1,
     786,    -1,   813,    -1,   421,    -1,   113,    -1,    -1,    -1,
      -1,    -1,  1110,  1112,  1006,   482,  1113,  1179,   445,  1114,
     812,  1115,  1108,  1585,  1116,    -1,   264,    -1,    -1,    -1,
     608,  1118,   812,  1119,  1585,   415,    -1,   230,   908,    -1,
     929,    -1,   929,   911,    -1,   410,  1474,    -1,   518,  1474,
      -1,  1124,    -1,  1125,    -1,  1124,  1125,    -1,  1126,    -1,
      -1,   458,  1127,  1128,    -1,   812,   295,    -1,   993,    -1,
    1107,    -1,  1122,    -1,    -1,    -1,    -1,   167,  1006,   166,
    1006,   482,  1130,  1179,   445,  1131,   812,  1132,  1108,  1585,
    1116,    -1,    -1,   609,  1134,  1149,  1140,  1135,    -1,   416,
      -1,    -1,   287,  1137,  1585,    -1,    -1,    23,  1141,  1142,
    1143,  1005,  1138,  1585,    -1,    -1,    23,  1141,  1005,  1139,
    1585,    -1,  1136,    -1,  1140,  1136,    -1,    -1,  1081,    -1,
      25,    -1,  1163,    -1,    -1,  1163,    -1,    25,    -1,   304,
    1147,    -1,   316,  1148,    -1,   299,  1148,    -1,   636,    -1,
      25,    -1,  1163,    -1,  1147,    -1,  1148,     5,  1147,    -1,
    1163,    -1,    25,    -1,    -1,    -1,   696,  1006,  1151,   812,
    1152,  1153,   697,    -1,  1154,    -1,  1153,  1154,    -1,    -1,
     698,  1155,  1585,    -1,    -1,   675,  1006,  1156,  1585,    -1,
    1160,  1158,    -1,    -1,   740,  1161,    -1,  1162,    -1,  1159,
      -1,  1028,    -1,  1030,    -1,  1032,    -1,  1024,    -1,  1026,
      -1,   424,   929,   911,    -1,    -1,   118,    -1,   118,    -1,
    1164,    -1,  1166,    -1,   243,  1166,    -1,  1166,   670,    -1,
    1165,  1170,    -1,  1165,  1006,   510,  1173,   478,    -1,  1165,
    1006,   510,  1173,   478,   510,  1173,   478,    -1,  1171,    -1,
    1006,    -1,  1167,    -1,  1006,   509,  1169,   477,    -1,  1006,
     509,  1169,   477,    -1,  1163,    -1,    25,    -1,    20,    -1,
    1006,    -1,  1006,  1172,    -1,   510,  1173,   478,    -1,   510,
    1173,   478,   510,  1173,   478,    -1,  1174,    -1,  1173,     5,
    1174,    -1,   736,    -1,  1176,    -1,  1178,    -1,  1176,   670,
    1177,    -1,  1176,   670,  1006,   510,  1173,   478,    -1,  1176,
     670,  1006,   510,  1173,   478,   510,  1173,   478,    -1,  1006,
      -1,  1168,    -1,    20,    -1,  1006,    -1,  1006,  1172,    -1,
      -1,  1180,    -1,  1182,    -1,  1180,     5,  1182,    -1,  1183,
      -1,  1181,     5,  1183,    -1,  1006,    -1,  1006,   670,  1006,
      -1,  1163,    -1,  1163,   472,  1163,    -1,    25,    -1,  1012,
      -1,    26,    -1,  1185,    -1,  1184,     5,  1185,    -1,  1163,
      -1,  1163,   472,  1163,    -1,  1187,    -1,  1186,     5,  1187,
      -1,  1175,    -1,  1163,    -1,  1190,    -1,  1189,     5,  1190,
      -1,  1163,  1191,    -1,    -1,   638,    -1,   589,    -1,  1193,
      -1,  1192,     5,  1193,    -1,  1163,    -1,  1163,   472,  1163,
      -1,   307,  1002,   668,   995,   630,  1577,   744,    -1,    -1,
     668,   482,   913,     5,   913,   445,  1196,    -1,    -1,   619,
     482,   913,     5,   913,   445,    -1,   308,  1006,  1195,    -1,
    1006,    -1,   393,  1004,  1200,    -1,  1201,    -1,   597,   913,
      -1,  1202,  1203,  1208,     8,  1198,    -1,    -1,   668,  1204,
     482,   913,     5,   913,   445,    -1,    -1,   607,  1007,    -1,
      -1,   405,    -1,   270,  1516,   319,  1558,  1207,    -1,   614,
     999,    -1,   614,   999,     8,   929,   911,    -1,    -1,   667,
     627,  1510,   428,  1510,    -1,   667,   627,  1510,     5,   428,
    1510,    -1,   667,  1510,     5,  1510,    -1,    -1,   699,    -1,
     700,    -1,   447,   676,  1558,  1210,  1211,    -1,    -1,   667,
    1558,    -1,    -1,   667,   627,  1510,     8,  1510,    -1,   627,
    1510,     8,  1510,    -1,   463,  1213,    -1,  1214,    -1,  1213,
       5,  1214,    -1,   255,   992,    -1,   337,   992,    -1,   384,
     992,    -1,   392,   992,    -1,   346,   992,    -1,   312,   992,
      -1,  1083,    -1,   490,  1084,    -1,   501,  1084,    -1,   612,
    1084,    -1,   429,  1084,    -1,   601,  1084,    -1,   599,   993,
      -1,   600,   993,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,   453,   740,    -1,   715,   740,    -1,   344,    -1,
     248,    -1,   205,    -1,   185,    -1,   202,    -1,   193,    -1,
    1515,   465,  1218,   597,  1216,    -1,  1163,    -1,    25,    -1,
     455,  1218,    -1,   455,  1218,     8,  1181,    -1,   455,  1218,
     604,  1184,    -1,   455,  1218,   604,  1184,     8,  1181,    -1,
      52,  1216,    -1,  1007,    -1,    -1,   513,  1228,   739,   646,
    1223,  1163,  1221,  1005,   739,  1220,  1224,    -1,    -1,   718,
      26,    -1,   513,  1228,   739,   399,  1163,    -1,    -1,   372,
      -1,    -1,  1225,   335,    -1,  1226,    -1,  1225,  1226,    -1,
      -1,  1079,  1227,  1585,    -1,   912,    -1,    -1,   654,   999,
    1230,  1231,    -1,    -1,   597,  1232,    -1,  1233,    -1,  1232,
       5,  1233,    -1,  1502,    -1,   534,    -1,   273,  1237,   141,
    1235,    -1,   273,  1237,   676,  1236,  1235,    -1,   273,  1237,
     140,  1236,  1235,    -1,   273,  1237,  1235,    -1,    -1,    46,
      -1,    25,    -1,  1011,    -1,  1006,    -1,    -1,   530,    -1,
     201,  1237,  1238,   482,   929,  1121,   445,    -1,   246,  1237,
      -1,   120,  1237,    -1,  1274,  1282,    -1,   498,   114,    -1,
     498,  1244,    -1,  1245,    -1,  1244,  1245,    -1,    -1,   189,
    1246,  1585,    -1,    -1,   251,  1247,  1585,    -1,    -1,   281,
    1248,  1585,    -1,    -1,   269,  1249,  1585,    -1,    -1,   306,
    1250,  1585,    -1,    -1,   253,  1163,  1251,  1585,    -1,    -1,
     277,  1163,  1252,  1585,    -1,  1263,    -1,  1266,    -1,  1265,
      -1,  1254,    -1,  1291,    -1,  1257,    -1,    -1,   611,   913,
    1255,   533,    -1,    -1,   533,    -1,    -1,   620,    26,  1258,
    1256,    -1,   212,    -1,   679,  1278,    -1,   215,  1278,    -1,
     214,  1278,    -1,    -1,  1260,    -1,  1261,    -1,  1260,  1261,
      -1,  1271,  1262,    -1,    -1,   668,  1278,    -1,    -1,   570,
    1264,  1259,  1270,    -1,   569,  1510,  1270,    -1,   568,  1269,
    1268,  1267,  1270,    -1,    -1,   206,   906,    -1,   206,   906,
       5,   906,    -1,   663,    -1,   664,    -1,   665,    -1,   666,
      -1,  1163,    -1,    -1,   573,    -1,  1272,    -1,  1271,     5,
    1272,    -1,   913,  1305,    -1,   659,   482,   906,   445,  1290,
      -1,   117,  1290,    -1,   547,   482,    20,   445,  1290,    -1,
     464,   482,    20,   445,  1290,    -1,   441,   482,   906,   445,
    1290,    -1,   639,   482,   906,   445,  1290,    -1,   652,   482,
     906,   445,  1290,    -1,   651,   482,   906,   445,  1290,    -1,
      -1,   512,  1275,    -1,  1276,    -1,  1275,  1276,    -1,   280,
      26,    -1,   271,    26,    -1,   354,    26,    -1,   237,    26,
      -1,   309,    26,    -1,   228,    -1,   398,    25,    -1,   398,
    1163,    -1,   229,    25,    -1,   213,    25,    -1,  1281,    -1,
    1277,  1281,    -1,  1279,   162,    -1,  1279,   164,    -1,  1279,
     163,    -1,  1279,    -1,  1012,    -1,    26,    -1,    -1,   512,
    1277,    -1,   280,  1278,    -1,   271,  1278,    -1,   354,  1278,
      -1,   237,  1278,    -1,   309,  1278,    -1,   310,  1278,    -1,
     678,    25,    -1,   679,  1278,    -1,   683,    -1,   680,    -1,
     681,    -1,   682,    -1,   687,    -1,   684,    -1,   685,    -1,
     686,    -1,   129,  1278,    -1,   130,  1278,    -1,   131,  1278,
      -1,   398,    25,    -1,   229,    25,    -1,   452,    -1,   126,
      -1,   127,    -1,    -1,   565,   669,  1189,    -1,   190,  1189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,  1284,  1006,
     482,  1285,  1179,   445,  1286,   812,  1287,  1242,  1288,  1243,
    1289,   292,    -1,    -1,   577,   906,    -1,   567,  1292,    -1,
      -1,  1216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
    1294,  1006,   482,  1295,  1179,   445,  1296,   812,  1297,  1300,
    1298,  1243,  1299,   292,    -1,  1280,  1282,    -1,    -1,    -1,
      -1,   208,   482,    25,     5,  1302,   766,  1303,   445,  1304,
     764,    -1,    -1,   437,    -1,   437,   271,    26,    -1,   437,
     271,  1163,    -1,   657,   913,    -1,   657,   913,   399,  1163,
      -1,   657,   913,   216,    -1,   657,   913,   628,    -1,   657,
     913,   595,    -1,  1308,    -1,   225,  1458,    -1,   378,  1458,
      -1,   334,  1459,    -1,    49,  1006,    -1,  1322,    -1,  1310,
      -1,    -1,    -1,   258,  1311,  1458,   482,  1312,  1326,   445,
    1315,    -1,    -1,    -1,   187,  1313,  1458,   482,  1314,  1326,
     445,  1315,  1323,    -1,    -1,  1316,    -1,  1317,    -1,  1316,
    1317,    -1,   673,  1318,    -1,   297,    26,    -1,    61,    26,
      -1,   138,    -1,   139,    -1,  1584,    -1,    -1,  1320,    -1,
    1321,    -1,  1320,  1321,    -1,   673,  1318,    -1,   727,    26,
      -1,   157,  1459,   675,  1458,   482,  1324,   445,  1319,    -1,
     104,  1007,    -1,   105,  1007,    -1,   224,  1458,   646,  1458,
      -1,   109,  1458,    -1,    -1,   321,    -1,  1325,    -1,  1324,
       5,  1325,    -1,  1006,   638,    -1,  1006,   589,    -1,  1006,
      -1,  1327,    -1,  1326,     5,  1327,    -1,  1410,    -1,  1408,
      -1,   174,  1006,    -1,   232,    -1,    59,  1006,  1330,    -1,
      60,  1459,   154,    -1,    60,  1459,   155,    -1,  1331,    -1,
    1330,     5,  1331,    -1,  1332,    -1,  1335,    -1,  1338,    -1,
    1343,    -1,  1346,    -1,  1342,    -1,  1341,    -1,   635,  1333,
      -1,   635,   482,  1334,   445,    -1,  1327,    -1,  1327,   714,
    1006,    -1,  1333,    -1,  1334,     5,  1333,    -1,   592,  1337,
      -1,   592,   482,  1336,   445,    -1,  1337,    -1,  1336,     5,
    1337,    -1,  1006,    -1,   506,  1340,    -1,   506,   482,  1339,
     445,    -1,  1340,    -1,  1339,     5,  1340,    -1,  1327,    -1,
     138,    -1,   139,    -1,   137,    26,    -1,   107,  1408,  1345,
      -1,   107,   482,  1344,   445,    -1,  1408,  1345,    -1,  1344,
       5,  1408,  1345,    -1,    -1,   110,  1006,    -1,   108,  1347,
      -1,   108,   482,  1347,   445,    -1,  1348,    -1,  1347,     5,
    1348,    -1,  1006,    -1,   318,    -1,   284,    -1,   218,  1351,
      -1,   197,    -1,   186,    -1,   173,    -1,   171,    -1,   175,
      -1,   231,  1516,    -1,   283,  1350,   511,  1510,   676,  1510,
      -1,   351,   999,   511,  1510,   676,  1510,    -1,    -1,  1516,
      -1,    -1,   913,    -1,   574,   913,    -1,   282,    -1,    -1,
     301,  1355,  1458,  1358,  1356,    -1,    -1,   530,  1357,   482,
    1360,   445,    -1,  1496,    -1,    -1,   482,  1359,   445,    -1,
    1462,    -1,  1359,     5,  1462,    -1,  1361,    -1,  1360,     5,
    1361,    -1,  1502,    -1,   534,    -1,    -1,   551,  1363,  1365,
    1366,    -1,  1007,    -1,  1370,  1000,    -1,  1000,    -1,    -1,
      -1,   604,  1367,  1184,    -1,    -1,    -1,   604,  1369,  1184,
      -1,   552,    -1,   605,    -1,   612,    -1,   429,    -1,   396,
      -1,   448,    -1,   432,   913,    -1,   405,   913,    -1,   290,
    1458,   203,  1000,    -1,   290,  1458,  1431,    -1,   565,   669,
    1374,    -1,  1375,    -1,  1374,     5,  1375,    -1,  1376,  1377,
      -1,    26,    -1,  1462,    -1,    -1,   638,    -1,   589,    -1,
     329,    -1,   362,    -1,    -1,   381,    -1,   410,  1382,  1380,
      -1,  1558,    -1,  1558,   662,  1006,    -1,    25,    -1,    -1,
    1515,  1384,  1385,    -1,  1416,    -1,  1420,    -1,  1379,    -1,
    1517,    -1,  1378,    -1,  1371,    -1,  1372,    -1,  1362,    -1,
    1354,    -1,  1353,    -1,  1486,    -1,  1538,    -1,   556,  1389,
     675,  1458,   676,  1394,  1388,    -1,   517,  1389,   675,  1458,
     597,  1394,    -1,   556,  1387,   676,  1394,    -1,   517,  1387,
     597,  1394,    -1,   447,    -1,   433,    -1,   642,    -1,    -1,
     196,    -1,   667,  1006,    -1,   220,    -1,   636,    -1,  1390,
      -1,  1391,    -1,  1390,     5,  1391,    -1,   522,  1392,    -1,
     501,    -1,   490,    -1,   529,  1392,    -1,   537,    -1,   559,
      -1,    -1,   482,  1393,   445,    -1,  1462,    -1,  1393,     5,
    1462,    -1,  1395,    -1,  1394,     5,  1395,    -1,   514,    -1,
    1460,    -1,   288,  1458,  1397,   667,  1496,  1399,    -1,    -1,
     482,  1398,   445,    -1,  1462,    -1,  1398,     5,  1462,    -1,
      -1,   195,    -1,   543,   482,  1434,   445,    -1,   298,   482,
    1403,   445,  1402,    -1,   349,  1404,    -1,  1405,    -1,  1458,
      -1,  1458,   482,  1405,   445,    -1,  1462,    -1,  1405,     5,
    1462,    -1,   527,   482,  1407,   445,    -1,   413,   482,  1407,
     445,    -1,   311,   482,  1407,   445,    -1,  1462,    -1,  1407,
       5,  1462,    -1,  1406,    -1,  1401,    -1,  1400,    -1,   452,
    1465,    -1,   261,    -1,   260,    -1,   259,    -1,  1006,  1450,
    1411,  1412,    -1,    -1,  1409,    -1,    -1,  1413,    -1,  1414,
      -1,  1413,  1414,    -1,  1415,  1345,    -1,   427,    -1,   211,
      -1,   527,    -1,   413,    -1,  1402,    -1,   543,   482,  1434,
     445,    -1,   311,    -1,   172,  1417,  1419,    -1,  1418,    -1,
    1460,    -1,  1420,    -1,  1419,  1420,    -1,  1396,    -1,  1386,
      -1,   499,  1434,    -1,   422,  1423,    -1,  1501,    -1,  1423,
       5,  1501,    -1,   577,  1434,    -1,   597,  1426,    -1,  1427,
      -1,  1426,     5,  1427,    -1,  1428,    -1,   566,  1428,    -1,
     566,   482,  1429,   445,    -1,  1458,    -1,  1458,  1464,    -1,
    1427,    -1,  1429,     5,  1427,    -1,  1425,  1431,  1432,  1433,
      -1,    -1,  1424,    -1,    -1,  1422,    -1,    -1,  1421,    -1,
    1435,    -1,  1434,     6,  1435,    -1,  1436,    -1,  1435,     7,
    1436,    -1,  1437,    -1,     9,  1437,    -1,  1448,    -1,   482,
    1434,   445,    -1,   494,  1497,    -1,   347,  1497,    -1,    -1,
     493,  1441,    -1,  1503,    -1,  1506,    -1,  1502,   673,   482,
    1443,   445,    -1,  1502,   673,  1497,    -1,  1502,   480,   482,
    1443,   445,    -1,  1502,   480,  1497,    -1,  1444,    -1,  1443,
       5,  1444,    -1,  1564,    -1,  1465,    -1,    -1,     9,    -1,
    1502,  1445,   440,    -1,  1502,  1445,   302,    -1,  1502,  1447,
    1502,    -1,  1502,  1445,   442,  1502,     7,  1502,    -1,  1502,
     607,  1440,  1439,    -1,  1502,   425,  1440,  1439,    -1,  1502,
     724,  1440,  1439,    -1,  1502,   426,  1440,  1439,    -1,  1502,
    1445,    10,  1440,  1439,    -1,    14,    -1,    17,    -1,    12,
      -1,    13,    -1,   305,    -1,    10,    -1,   723,    -1,    16,
      -1,    15,    -1,  1446,    -1,  1442,    -1,  1438,    -1,    -1,
     636,    -1,   413,    -1,   527,    -1,  1451,    -1,  1452,    -1,
    1454,    -1,   372,    -1,   372,   482,  1455,   445,    -1,    -1,
     523,    -1,   523,   482,    26,   445,    -1,   450,    -1,   450,
     482,  1456,  1453,   445,    -1,   563,   482,  1456,  1453,   445,
      -1,   563,    -1,   588,    -1,   460,    -1,   434,    -1,   373,
      -1,   373,   482,  1455,   445,    -1,   374,    -1,   374,   482,
      26,   445,    -1,   374,   482,    26,     5,    26,   445,    -1,
     411,  1472,   676,  1473,    -1,   411,    -1,   423,  1472,   676,
    1473,    -1,   423,    -1,   423,  1472,   482,    26,   445,   676,
    1473,    -1,   625,    -1,   584,    -1,   475,    -1,   475,   482,
      26,   445,    -1,   475,   482,    26,     5,    26,   445,    -1,
      -1,     5,  1457,    -1,   553,   482,  1456,   445,    -1,   616,
      -1,   352,    -1,   553,    -1,   116,    -1,    26,    -1,    26,
      -1,    26,    -1,    25,   670,  1006,    -1,    25,    -1,  1006,
      -1,  1006,   640,  1006,    -1,  1006,   640,    25,   670,  1006,
      -1,  1006,   662,  1006,    -1,  1006,   662,  1006,   640,  1006,
      -1,  1006,   662,  1006,   640,    25,   670,  1006,    -1,    25,
     670,  1006,    -1,    25,    -1,  1006,    -1,  1006,   640,  1006,
      -1,  1006,   640,    25,   670,  1006,    -1,  1006,   662,  1006,
      -1,  1006,   662,  1006,   640,  1006,    -1,  1006,   662,  1006,
     640,    25,   670,  1006,    -1,  1006,    -1,    -1,   510,    26,
     478,    -1,   510,    26,     5,    26,   478,    -1,  1463,    -1,
     662,  1463,    -1,  1006,  1461,    -1,  1458,   670,  1006,  1461,
      -1,  1458,   670,    20,    -1,  1006,    -1,    25,    -1,  1012,
      -1,    26,    -1,  1467,    -1,   448,  1469,    -1,   448,  1468,
      -1,    -1,  1472,   676,  1473,    -1,    -1,  1470,   676,  1470,
      -1,   632,    -1,   564,    -1,   641,    -1,   603,    -1,   505,
      -1,   521,    -1,   420,    -1,   420,   482,    26,   445,    -1,
     632,    -1,   564,    -1,   641,    -1,   603,    -1,   505,    -1,
     521,    -1,   420,    -1,   420,   482,    26,   445,    -1,   632,
      -1,   564,    -1,   641,    -1,   603,    -1,   505,    -1,   521,
      -1,   420,    -1,   632,    -1,   564,    -1,   641,    -1,   603,
      -1,   505,    -1,   521,    -1,   420,    -1,   420,   482,    26,
     445,    -1,  1006,    -1,  1006,   662,  1006,    -1,    25,    -1,
    1515,   554,  1000,    -1,    -1,  1515,   451,  1364,   488,   646,
    1484,  1477,    -1,    -1,  1515,   451,  1364,   488,   152,   646,
    1485,  1478,    -1,    -1,  1515,   451,  1364,   191,  1485,  1479,
      -1,    -1,  1515,   451,  1364,   192,   152,   646,  1485,  1480,
      -1,    -1,   341,    -1,   340,  1482,    -1,  1483,    -1,  1482,
       5,  1483,    -1,  1006,    -1,  1006,   670,  1006,    -1,    25,
     670,  1006,   670,  1006,    -1,  1485,    -1,  1354,    -1,  1218,
      -1,  1487,    -1,  1487,    -1,    -1,    -1,   522,  1498,  1488,
    1499,  1489,  1495,  1430,  1493,  1481,    -1,   522,  1498,  1499,
    1430,  1493,    -1,  1492,    -1,  1510,    -1,   522,  1498,  1499,
    1495,  1430,  1493,    -1,    -1,   576,  1449,  1491,    -1,  1373,
      -1,   386,  1494,  1323,    -1,  1373,   386,  1494,  1323,    -1,
    1006,    -1,    -1,   604,  1184,    -1,   522,  1498,  1499,  1430,
      -1,   482,   522,  1498,  1499,  1430,   445,    -1,    -1,   636,
      -1,   413,    -1,   527,    -1,  1500,    -1,  1499,     5,  1500,
      -1,  1502,    -1,  1502,  1006,    -1,  1502,   667,  1006,    -1,
    1502,    -1,  1503,    -1,    19,  1503,    -1,    18,  1503,    -1,
    1504,    -1,  1564,    -1,  1497,    -1,   636,  1497,    -1,   637,
    1497,    -1,   621,  1497,    -1,   662,  1006,    -1,   662,  1006,
     670,  1006,    -1,  1503,    21,  1502,    -1,  1503,  1524,    -1,
    1503,    20,  1502,    -1,  1503,    18,  1502,    -1,  1503,    19,
    1502,    -1,  1465,    -1,   535,    -1,   479,    -1,   627,    -1,
      20,    -1,   117,    -1,   639,   482,  1449,  1502,   445,    -1,
     651,   482,  1449,  1502,   445,    -1,   652,   482,  1449,  1502,
     445,    -1,   659,   482,  1449,  1502,   445,    -1,   547,   482,
    1449,  1502,   445,    -1,  1006,   482,  1505,   445,    -1,   588,
     482,  1505,   445,    -1,   482,  1502,   445,    -1,   495,   482,
    1525,   445,    -1,  1526,    -1,  1528,    -1,  1502,    -1,  1505,
       5,  1502,    -1,  1465,    -1,  1515,   401,  1514,  1509,  1491,
      -1,  1515,   390,  1514,  1509,   301,  1458,  1511,    -1,  1515,
     390,  1514,  1509,  1163,    -1,    -1,   376,  1510,    -1,    25,
      -1,  1163,    -1,    -1,   482,  1512,   445,    -1,  1513,    -1,
    1512,     5,  1513,    -1,  1006,    -1,    25,    -1,  1163,    -1,
      -1,   320,  1516,   646,    -1,  1007,    -1,  1522,    -1,  1521,
      -1,  1518,    -1,   369,  1519,   676,  1519,    -1,   350,  1458,
     670,  1520,   676,  1520,    -1,  1006,    -1,  1006,    -1,   274,
    1458,    -1,   345,  1458,  1523,    -1,   324,    -1,   227,    -1,
     144,    -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,   448,     5,  1472,   676,  1473,    -1,  1564,     5,
    1472,   676,  1473,    -1,   448,  1472,   676,  1473,    -1,  1502,
       5,  1472,   676,  1473,    -1,  1527,    -1,  1527,  1472,   676,
    1473,    -1,    36,    -1,  1529,    -1,  1529,  1472,   482,    26,
     445,   676,  1473,    -1,  1529,  1472,   676,  1473,    -1,    37,
      -1,    -1,   658,  1531,  1532,   242,    -1,  1533,    -1,  1532,
    1533,    -1,    33,    -1,  1534,    -1,  1536,    -1,   405,    -1,
     357,    -1,   276,    -1,   635,    -1,   532,    -1,   636,    -1,
     537,    -1,   581,    -1,   637,    -1,   168,    -1,   538,    -1,
     667,    -1,   638,    -1,   370,    -1,   539,    -1,   371,    -1,
     668,    -1,   662,    -1,   327,    -1,   540,    -1,   236,    -1,
     441,    -1,   639,    -1,   714,    -1,   442,    -1,   541,    -1,
     542,    -1,   582,    -1,   583,    -1,   483,    -1,   484,    -1,
     407,    -1,   701,    -1,   669,    -1,   584,    -1,   443,    -1,
     586,    -1,   580,    -1,   372,    -1,   543,    -1,   544,    -1,
     444,    -1,   545,    -1,   445,    -1,   478,    -1,   546,    -1,
     640,    -1,   485,    -1,   446,    -1,     5,    -1,    23,    -1,
     486,    -1,   447,    -1,   409,    -1,   408,    -1,   375,    -1,
     547,    -1,   487,    -1,   448,    -1,   488,    -1,   587,    -1,
     410,    -1,   588,    -1,   411,    -1,   641,    -1,   642,    -1,
     449,    -1,   643,    -1,   450,    -1,   451,    -1,   452,    -1,
     412,    -1,   548,    -1,   489,    -1,   490,    -1,   376,    -1,
     589,    -1,   333,    -1,   644,    -1,   705,    -1,   453,    -1,
     413,    -1,    21,    -1,   670,    -1,   491,    -1,   377,    -1,
     592,    -1,   115,    -1,   593,    -1,   708,    -1,   454,    -1,
      14,    -1,   549,    -1,   493,    -1,   550,    -1,   381,    -1,
     594,    -1,   455,    -1,   494,    -1,   595,    -1,   495,    -1,
     496,    -1,   419,    -1,   585,    -1,   551,    -1,   151,    -1,
     245,    -1,   497,    -1,   552,    -1,   645,    -1,   553,    -1,
     554,    -1,   646,    -1,   456,    -1,   457,    -1,   498,    -1,
     688,    -1,   143,    -1,   158,    -1,   555,    -1,   420,    -1,
     596,    -1,   597,    -1,   421,    -1,   342,    -1,   458,    -1,
     671,    -1,   598,    -1,   556,    -1,    13,    -1,   557,    -1,
     558,    -1,   499,    -1,   500,    -1,   601,    -1,   602,    -1,
     603,    -1,   710,    -1,   124,    -1,   672,    -1,   673,    -1,
     164,    -1,   559,    -1,   459,    -1,   343,    -1,   715,    -1,
     501,    -1,   460,    -1,   385,    -1,   423,    -1,   717,    -1,
     387,    -1,   647,    -1,   590,    -1,   709,    -1,   560,    -1,
     533,    -1,   424,    -1,   648,    -1,   677,    -1,   461,    -1,
       7,    -1,   479,    -1,   633,    -1,   534,    -1,     6,    -1,
     535,    -1,     8,    -1,   605,    -1,   606,    -1,    12,    -1,
     649,    -1,   607,    -1,   562,    -1,   502,    -1,   650,    -1,
     462,    -1,   608,    -1,   503,    -1,    10,    -1,    58,    -1,
     504,    -1,   609,    -1,   696,    -1,   711,    -1,    19,    -1,
     505,    -1,   163,    -1,    22,    -1,   610,    -1,   506,    -1,
     563,    -1,   564,    -1,    20,    -1,   611,    -1,   612,    -1,
     363,    -1,   613,    -1,   507,    -1,     9,    -1,   674,    -1,
     719,    -1,   675,    -1,   614,    -1,   482,    -1,   510,    -1,
     511,    -1,   463,    -1,   565,    -1,   394,    -1,   566,    -1,
     512,    -1,   653,    -1,   428,    -1,   567,    -1,   208,    -1,
     159,    -1,   464,    -1,    18,    -1,   162,    -1,   395,    -1,
     465,    -1,   165,    -1,   429,    -1,   364,    -1,   570,    -1,
     396,    -1,   397,    -1,   466,    -1,   513,    -1,   514,    -1,
     654,    -1,   615,    -1,   430,    -1,   616,    -1,   515,    -1,
     467,    -1,   655,    -1,   349,    -1,   431,    -1,   432,    -1,
     516,    -1,   433,    -1,   230,    -1,   399,    -1,   468,    -1,
     517,    -1,   571,    -1,   314,    -1,   656,    -1,   617,    -1,
     657,    -1,   518,    -1,   520,    -1,   521,    -1,   469,    -1,
     522,    -1,   573,    -1,   523,    -1,   470,    -1,   525,    -1,
     618,    -1,   536,    -1,   619,    -1,   620,    -1,   574,    -1,
     352,    -1,   434,    -1,   621,    -1,   526,    -1,   658,    -1,
     353,    -1,   142,    -1,   622,    -1,   623,    -1,   659,    -1,
     471,    -1,   591,    -1,   624,    -1,   169,    -1,   625,    -1,
     626,    -1,   472,    -1,   718,    -1,   676,    -1,   660,    -1,
     473,    -1,   575,    -1,   250,    -1,   400,    -1,   576,    -1,
     527,    -1,   528,    -1,   529,    -1,   474,    -1,   661,    -1,
     627,    -1,   435,    -1,   530,    -1,   475,    -1,   404,    -1,
     628,    -1,   476,    -1,   629,    -1,   577,    -1,   578,    -1,
     579,    -1,   630,    -1,   437,    -1,   631,    -1,   651,    -1,
     652,    -1,   634,    -1,   632,    -1,   531,    -1,    -1,   243,
    1535,  1564,    -1,    -1,   604,  1537,  1184,    -1,    -1,    -1,
     529,  1458,  1539,  1542,  1540,  1541,    -1,    -1,   203,  1000,
      -1,   577,  1434,    -1,   102,  1546,   445,    14,   482,  1547,
     445,    -1,    98,  1547,   445,    -1,    99,  1547,   445,    -1,
     634,  1543,    -1,   101,  1547,    -1,   100,  1547,    -1,  1545,
      -1,  1543,     5,  1545,    -1,  1462,    -1,  1544,    14,  1548,
      -1,  1544,    -1,  1546,     5,  1544,    -1,  1548,    -1,  1547,
       5,  1548,    -1,   534,    -1,  1549,    -1,  1550,    -1,    19,
    1550,    -1,    18,  1550,    -1,  1552,    -1,  1497,    -1,   662,
    1006,    -1,   662,  1006,   670,  1006,    -1,   662,  1006,   510,
      26,   478,    -1,   662,  1006,   670,  1006,   510,    26,   478,
      -1,   662,  1006,   510,    26,     5,    26,   478,    -1,   662,
    1006,   670,  1006,   510,    26,     5,    26,   478,    -1,  1551,
      -1,  1465,    -1,   535,    -1,   479,    -1,   627,    -1,   117,
      -1,  1550,    21,  1549,    -1,  1550,  1524,    -1,  1550,    20,
    1549,    -1,  1550,    18,  1549,    -1,  1550,    19,  1549,    -1,
     639,   482,  1449,  1549,   445,    -1,   651,   482,  1449,  1549,
     445,    -1,   652,   482,  1449,  1549,   445,    -1,   659,   482,
    1449,  1549,   445,    -1,   547,   482,  1449,  1549,   445,    -1,
    1006,   482,  1553,   445,    -1,   588,   482,  1553,   445,    -1,
     482,  1549,   445,    -1,   495,   482,  1525,   445,    -1,  1526,
      -1,  1528,    -1,  1564,    -1,  1549,    -1,  1553,     5,  1549,
      -1,    -1,   435,  1192,   607,  1555,  1556,    -1,  1557,    -1,
    1556,     5,  1557,    -1,  1458,   670,  1462,    -1,  1458,   670,
      20,    -1,  1560,    -1,  1560,    -1,   243,  1561,    -1,  1561,
      -1,  1562,    -1,    25,   670,  1562,    -1,  1563,    -1,  1562,
     670,  1563,    -1,  1562,   670,    20,    -1,  1565,    -1,  1006,
      -1,  1559,    -1,  1559,   472,  1559,    -1,  1006,  1566,    -1,
     510,  1567,   478,    -1,   510,  1567,   478,   510,  1567,   478,
      -1,  1568,    -1,  1567,     5,  1568,    -1,   736,    -1,    34,
      -1,    -1,    -1,   578,  1571,   913,  1572,  1585,   380,    -1,
      -1,   709,   954,    -1,    -1,   712,    -1,   234,    -1,   330,
    1001,    -1,   122,  1001,    -1,   360,    -1,   359,    -1,   361,
    1003,  1573,  1574,    -1,   544,   954,  1574,    -1,   156,    -1,
     188,  1001,    -1,   913,   617,     5,   913,   446,    -1,   560,
     913,    -1,   317,  1001,    -1,   153,  1580,     8,  1581,  1579,
      -1,    -1,   597,   913,    -1,  1006,    -1,  1006,    -1,   300,
    1001,    -1,   303,  1001,   676,   913,     5,   913,    -1,   303,
    1001,   669,   913,     5,   913,    -1,    27,    -1,    -1,  1587,
      -1,  1588,  1270,    -1,  1586,    -1,  1587,  1586,    -1,    -1,
    1589,  1590,    -1,   729,    -1,   730,    -1,   731,    -1,   732,
      -1,   749,    -1,   771,    -1,   785,    -1,   786,    -1,   792,
      -1,   811,    -1,   885,    -1,   886,    -1,   887,    -1,   888,
      -1,   899,    -1,   900,    -1,   901,    -1,   902,    -1,   903,
      -1,   904,    -1,   905,    -1,   956,    -1,   960,    -1,   991,
      -1,  1013,    -1,  1015,    -1,  1018,    -1,  1019,    -1,  1020,
      -1,  1021,    -1,  1034,    -1,  1043,    -1,  1067,    -1,  1068,
      -1,  1070,    -1,  1074,    -1,  1089,    -1,  1090,    -1,  1094,
      -1,  1095,    -1,  1096,    -1,  1097,    -1,  1105,    -1,  1120,
      -1,  1133,    -1,  1144,    -1,  1145,    -1,  1146,    -1,  1157,
      -1,  1194,    -1,  1197,    -1,  1199,    -1,  1205,    -1,  1206,
      -1,  1209,    -1,  1212,    -1,  1215,    -1,  1217,    -1,  1219,
      -1,  1222,    -1,  1229,    -1,  1234,    -1,  1239,    -1,  1240,
      -1,  1241,    -1,  1253,    -1,  1306,    -1,  1307,    -1,  1309,
      -1,  1328,    -1,  1329,    -1,  1349,    -1,  1352,    -1,  1381,
      -1,  1383,    -1,  1475,    -1,  1476,    -1,  1507,    -1,  1508,
      -1,  1530,    -1,  1554,    -1,  1569,    -1,  1570,    -1,  1575,
      -1,  1576,    -1,  1578,    -1,  1582,    -1,  1583,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1000,  1000,  1003,  1006,  1012,  1018,  1025,  1029,  1029,
    1035,  1058,  1059,  1060,  1061,  1062,  1073,  1079,  1080,  1081,
    1082,  1083,  1088,  1089,  1100,  1103,  1106,  1106,  1110,  1113,
    1114,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1139,  1140,
    1143,  1143,  1158,  1159,  1162,  1168,  1170,  1181,  1183,  1185,
    1187,  1191,  1193,  1255,  1259,  1263,  1263,  1273,  1277,  1280,
    1281,  1288,  1294,  1288,  1307,  1312,  1316,  1307,  1328,  1332,
    1328,  1340,  1345,  1340,  1364,  1371,  1375,  1363,  1401,  1401,
    1405,  1406,  1407,  1412,  1415,  1420,  1424,  1432,  1433,  1436,
    1436,  1442,  1446,  1461,  1459,  1477,  1477,  1492,  1492,  1495,
    1495,  1499,  1502,  1502,  1502,  1509,  1510,  1509,  1517,  1517,
    1528,  1528,  1547,  1550,  1553,  1556,  1559,  1562,  1575,  1580,
    1580,  1581,  1581,  1584,  1589,  1589,  1593,  1612,  1617,  1611,
    1628,  1634,  1642,  1643,  1646,  1646,  1649,  1653,  1658,  1665,
    1665,  1669,  1669,  1670,  1670,  1671,  1671,  1672,  1672,  1673,
    1673,  1681,  1685,  1691,  1695,  1710,  1713,  1716,  1719,  1722,
    1725,  1731,  1742,  1747,  1760,  1764,  1779,  1780,  1784,  1784,
    1788,  1788,  1788,  1789,  1794,  1794,  1797,  1797,  1806,  1807,
    1808,  1811,  1815,  1816,  1816,  1833,  1833,  1833,  1833,  1837,
    1844,  1845,  1848,  1848,  1852,  1853,  1854,  1855,  1860,  1860,
    1866,  1866,  1875,  1872,  1888,  1888,  1890,  1890,  1892,  1894,
    1896,  1898,  1901,  1905,  1905,  1906,  1906,  1910,  1910,  1922,
    1922,  1927,  1931,  1933,  1934,  1937,  1937,  1937,  1941,  1942,
    1943,  1944,  1945,  1946,  1947,  1948,  1949,  1950,  1951,  1952,
    1955,  1956,  1957,  1958,  1962,  1967,  1972,  1976,  1979,  1983,
    1983,  1984,  1984,  1985,  1985,  1986,  1987,  1988,  1989,  1990,
    1991,  1994,  1995,  1996,  2026,  2026,  2031,  2035,  2037,  2039,
    2039,  2046,  2050,  2050,  2054,  2055,  2056,  2057,  2058,  2059,
    2060,  2066,  2066,  2069,  2071,  2077,  2079,  2085,  2093,  2093,
    2096,  2097,  2098,  2099,  2100,  2101,  2102,  2108,  2111,  2111,
    2124,  2124,  2131,  2132,  2133,  2135,  2136,  2139,  2143,  2144,
    2145,  2146,  2151,  2157,  2163,  2164,  2166,  2168,  2169,  2170,
    2171,  2172,  2173,  2176,  2177,  2184,  2192,  2192,  2200,  2197,
    2212,  2212,  2214,  2214,  2222,  2222,  2225,  2228,  2229,  2234,
    2246,  2250,  2253,  2256,  2257,  2258,  2259,  2260,  2265,  2272,
    2278,  2283,  2288,  2283,  2301,  2303,  2308,  2313,  2313,  2313,
    2317,  2317,  2320,  2320,  2327,  2327,  2334,  2334,  2345,  2363,
    2369,  2393,  2396,  2410,  2412,  2414,  2416,  2418,  2420,  2422,
    2428,  2430,  2434,  2436,  2438,  2440,  2442,  2444,  2446,  2452,
    2467,  2470,  2486,  2487,  2488,  2489,  2493,  2494,  2495,  2499,
    2504,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,
    2520,  2521,  2528,  2528,  2533,  2533,  2536,  2542,  2550,  2556,
    2566,  2567,  2575,  2596,  2600,  2605,  2610,  2612,  2615,  2633,
    2638,  2644,  2649,  2654,  2655,  2661,  2732,  2743,  2752,  2760,
    2760,  2775,  2779,  2786,  2789,  2797,  2801,  2804,  2810,  2819,
    2824,  2832,  2835,  2838,  2843,  2850,  2855,  2860,  2865,  2875,
    2883,  2891,  2896,  2900,  2905,  2909,  2913,  2920,  2923,  2926,
    2930,  2934,  2938,  2942,  2950,  2960,  2965,  2958,  2981,  2986,
    2981,  3003,  3003,  3003,  3006,  3006,  3006,  3010,  3010,  3010,
    3014,  3014,  3014,  3018,  3024,  3030,  3036,  3044,  3050,  3058,
    3064,  3073,  3079,  3086,  3093,  3102,  3108,  3114,  3121,  3127,
    3133,  3139,  3147,  3153,  3159,  3168,  3174,  3180,  3190,  3190,
    3194,  3198,  3199,  3210,  3211,  3217,  3227,  3237,  3247,  3248,
    3251,  3256,  3262,  3266,  3270,  3273,  3279,  3282,  3285,  3302,
    3305,  3311,  3312,  3313,  3317,  3318,  3319,  3320,  3321,  3323,
    3324,  3325,  3327,  3328,  3332,  3333,  3338,  3342,  3347,  3351,
    3366,  3370,  3365,  3378,  3381,  3395,  3399,  3405,  3394,  3418,
    3419,  3431,  3437,  3431,  3451,  3451,  3453,  3454,  3458,  3458,
    3462,  3462,  3467,  3467,  3474,  3475,  3479,  3479,  3483,  3483,
    3488,  3488,  3495,  3499,  3500,  3501,  3506,  3506,  3509,  3509,
    3513,  3513,  3517,  3517,  3521,  3521,  3526,  3526,  3531,  3531,
    3536,  3536,  3541,  3541,  3557,  3574,  3575,  3576,  3577,  3578,
    3579,  3580,  3583,  3583,  3586,  3588,  3591,  3594,  3597,  3602,
    3607,  3610,  3615,  3620,  3625,  3632,  3633,  3640,  3647,  3649,
    3655,  3660,  3665,  3670,  3670,  3673,  3679,  3684,  3687,  3694,
    3694,  3696,  3699,  3702,  3707,  3712,  3717,  3724,  3733,  3733,
    3795,  3803,  3804,  3812,  3819,  3819,  3823,  3828,  3834,  3838,
    3842,  3848,  3852,  3856,  3862,  3862,  3870,  3871,  3875,  3875,
    3879,  3880,  3883,  3886,  3886,  3889,  3891,  3891,  3894,  3896,
    3896,  3897,  3899,  3899,  3908,  3915,  3906,  3936,  3936,  3936,
    3939,  3941,  3939,  3948,  3951,  3957,  3968,  3968,  3972,  3978,
    3978,  3982,  3983,  3987,  3997,  3998,  3999,  4002,  4004,  4009,
    4009,  4013,  4012,  4020,  4019,  4026,  4026,  4032,  4032,  4039,
    4039,  4045,  4045,  4051,  4051,  4057,  4057,  4061,  4061,  4062,
    4062,  4063,  4063,  4064,  4064,  4068,  4068,  4079,  4083,  4089,
    4093,  4098,  4103,  4108,  4109,  4110,  4114,  4113,  4126,  4131,
    4136,  4136,  4152,  4158,  4159,  4160,  4161,  4162,  4172,  4186,
    4186,  4189,  4196,  4197,  4198,  4199,  4200,  4201,  4202,  4203,
    4204,  4209,  4209,  4211,  4214,  4214,  4216,  4220,  4223,  4224,
    4227,  4227,  4232,  4235,  4236,  4237,  4238,  4239,  4240,  4241,
    4242,  4243,  4244,  4245,  4246,  4247,  4248,  4249,  4250,  4251,
    4252,  4256,  4274,  4274,  4274,  4301,  4312,  4319,  4325,  4331,
    4337,  4349,  4374,  4373,  4390,  4390,  4394,  4395,  4403,  4404,
    4405,  4406,  4407,  4408,  4415,  4416,  4418,  4419,  4423,  4428,
    4429,  4430,  4431,  4432,  4433,  4434,  4435,  4436,  4438,  4441,
    4443,  4443,  4445,  4449,  4449,  4458,  4463,  4479,  4485,  4457,
    4499,  4513,  4523,  4512,  4536,  4543,  4543,  4548,  4554,  4562,
    4567,  4568,  4571,  4574,  4574,  4582,  4588,  4599,  4600,  4604,
    4608,  4621,  4603,  4639,  4639,  4653,  4664,  4663,  4675,  4671,
    4688,  4685,  4698,  4698,  4700,  4701,  4703,  4704,  4707,  4708,
    4709,  4711,  4716,  4721,  4727,  4729,  4730,  4733,  4734,  4737,
    4739,  4747,  4753,  4747,  4764,  4765,  4769,  4769,  4776,  4776,
    4785,  4788,  4791,  4794,  4798,  4802,  4803,  4804,  4805,  4806,
    4810,  4815,  4815,  4818,  4845,  4903,  4903,  4906,  4910,  4914,
    4957,  4999,  5000,  5001,  5004,  5018,  5030,  5030,  5035,  5036,
    5042,  5107,  5112,  5119,  5124,  5132,  5138,  5171,  5174,  5175,
    5216,  5259,  5260,  5264,  5265,  5269,  5322,  5327,  5331,  5336,
    5347,  5354,  5362,  5362,  5365,  5366,  5367,  5368,  5369,  5372,
    5375,  5381,  5384,  5388,  5393,  5401,  5406,  5413,  5415,  5421,
    5423,  5423,  5423,  5443,  5450,  5457,  5460,  5474,  5481,  5482,
    5485,  5486,  5490,  5496,  5501,  5507,  5508,  5513,  5517,  5517,
    5521,  5522,  5525,  5526,  5530,  5538,  5541,  5547,  5548,  5550,
    5552,  5556,  5556,  5557,  5562,  5570,  5571,  5576,  5577,  5579,
    5592,  5594,  5595,  5598,  5599,  5600,  5601,  5602,  5603,  5604,
    5605,  5606,  5607,  5608,  5609,  5610,  5611,  5612,  5613,  5614,
    5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,  5623,  5637,
    5645,  5645,  5647,  5651,  5655,  5659,  5663,  5668,  5683,  5681,
    5701,  5702,  5706,  5711,  5712,  5716,  5717,  5719,  5720,  5722,
    5722,  5731,  5740,  5740,  5750,  5751,  5756,  5757,  5760,  5773,
    5787,  5791,  5795,  5799,  5806,  5807,  5810,  5810,  5814,  5817,
    5817,  5819,  5825,  5833,  5839,  5841,  5845,  5848,  5848,  5851,
    5851,  5856,  5856,  5865,  5865,  5869,  5869,  5870,  5870,  5871,
    5871,  5885,  5885,  5905,  5906,  5907,  5908,  5909,  5910,  5913,
    5913,  5919,  5919,  5922,  5922,  5938,  5939,  5940,  5949,  5961,
    5962,  5965,  5966,  5969,  5972,  5972,  5977,  5977,  5998,  6003,
    6009,  6010,  6011,  6015,  6016,  6017,  6018,  6022,  6032,  6034,
    6039,  6042,  6047,  6053,  6060,  6067,  6076,  6083,  6090,  6097,
    6104,  6113,  6113,  6115,  6115,  6118,  6119,  6120,  6121,  6122,
    6123,  6124,  6125,  6126,  6127,  6130,  6130,  6133,  6134,  6135,
    6136,  6139,  6139,  6142,  6142,  6145,  6146,  6147,  6148,  6149,
    6150,  6151,  6152,  6154,  6155,  6156,  6157,  6159,  6160,  6161,
    6162,  6164,  6165,  6166,  6167,  6168,  6169,  6170,  6171,  6175,
    6183,  6193,  6206,  6215,  6226,  6230,  6234,  6240,  6205,  6253,
    6256,  6264,  6276,  6278,  6283,  6291,  6301,  6304,  6308,  6316,
    6282,  6325,  6329,  6333,  6337,  6329,  6347,  6348,  6349,  6350,
    6355,  6357,  6360,  6364,  6367,  6374,  6379,  6380,  6381,  6382,
    6387,  6388,  6394,  6394,  6394,  6399,  6399,  6399,  6407,  6408,
    6412,  6413,  6418,  6419,  6420,  6421,  6422,  6425,  6427,  6427,
    6430,  6431,  6435,  6436,  6439,  6440,  6443,  6446,  6449,  6455,
    6456,  6468,  6469,  6474,  6475,  6476,  6480,  6483,  6489,  6492,
    6500,  6501,  6507,  6511,  6515,  6521,  6524,  6533,  6536,  6539,
    6542,  6545,  6548,  6551,  6558,  6561,  6568,  6571,  6577,  6580,
    6587,  6590,  6597,  6598,  6603,  6607,  6610,  6616,  6619,  6625,
    6632,  6633,  6637,  6647,  6650,  6656,  6658,  6663,  6664,  6668,
    6670,  6676,  6677,  6690,  6702,  6703,  6704,  6705,  6706,  6707,
    6708,  6709,  6710,  6713,  6716,  6722,  6722,  6728,  6728,  6739,
    6752,  6762,  6762,  6767,  6767,  6771,  6775,  6776,  6782,  6783,
    6788,  6792,  6799,  6802,  6809,  6808,  6819,  6823,  6827,  6834,
    6837,  6837,  6850,  6854,  6854,  6869,  6871,  6873,  6875,  6877,
    6879,  6881,  6883,  6889,  6899,  6906,  6911,  6912,  6916,  6919,
    6920,  6923,  6924,  6925,  6928,  6933,  6940,  6941,  6947,  6959,
    6960,  6961,  6964,  6964,  6969,  6974,  6979,  6980,  6983,  6984,
    6989,  6994,  6998,  7003,  7004,  7008,  7015,  7016,  7017,  7018,
    7023,  7024,  7025,  7028,  7029,  7030,  7034,  7035,  7036,  7040,
    7041,  7045,  7046,  7047,  7048,  7049,  7050,  7053,  7054,  7059,
    7060,  7065,  7066,  7071,  7072,  7077,  7082,  7083,  7088,  7089,
    7093,  7094,  7099,  7106,  7111,  7116,  7120,  7121,  7126,  7127,
    7133,  7134,  7135,  7140,  7141,  7147,  7150,  7153,  7160,  7161,
    7162,  7163,  7177,  7182,  7183,  7186,  7188,  7195,  7198,  7204,
    7212,  7216,  7220,  7224,  7228,  7231,  7234,  7241,  7248,  7253,
    7257,  7258,  7264,  7267,  7278,  7285,  7291,  7294,  7301,  7308,
    7314,  7315,  7321,  7322,  7323,  7326,  7327,  7332,  7332,  7336,
    7344,  7345,  7348,  7351,  7356,  7357,  7362,  7365,  7371,  7374,
    7380,  7383,  7389,  7392,  7399,  7400,  7429,  7430,  7435,  7443,
    7448,  7451,  7454,  7457,  7463,  7464,  7468,  7471,  7474,  7475,
    7480,  7483,  7486,  7489,  7492,  7495,  7498,  7501,  7506,  7512,
    7513,  7514,  7515,  7516,  7518,  7519,  7521,  7522,  7527,  7530,
    7534,  7540,  7541,  7542,  7543,  7555,  7556,  7557,  7561,  7562,
    7566,  7567,  7568,  7569,  7570,  7572,  7581,  7588,  7589,  7590,
    7591,  7592,  7593,  7594,  7596,  7598,  7600,  7601,  7603,  7604,
    7606,  7607,  7608,  7609,  7611,  7615,  7616,  7622,  7624,  7625,
    7626,  7627,  7632,  7636,  7640,  7644,  7651,  7655,  7656,  7657,
    7665,  7666,  7667,  7678,  7685,  7690,  7691,  7692,  7700,  7701,
    7702,  7719,  7728,  7729,  7730,  7734,  7737,  7742,  7747,  7752,
    7760,  7764,  7769,  7770,  7778,  7781,  7784,  7798,  7812,  7825,
    7826,  7830,  7830,  7830,  7830,  7830,  7830,  7831,  7834,  7839,
    7839,  7839,  7839,  7839,  7839,  7841,  7844,  7850,  7850,  7850,
    7850,  7850,  7850,  7850,  7851,  7851,  7851,  7851,  7851,  7851,
    7851,  7851,  7854,  7855,  7856,  7859,  7868,  7868,  7874,  7874,
    7881,  7881,  7887,  7887,  7895,  7896,  7897,  7900,  7900,  7903,
    7904,  7905,  7916,  7919,  7925,  7930,  7937,  7950,  7951,  7948,
    7969,  7980,  7983,  7988,  8000,  8003,  8007,  8010,  8011,  8021,
    8024,  8025,  8034,  8043,  8048,  8049,  8050,  8051,  8058,  8061,
    8067,  8070,  8077,  8089,  8098,  8101,  8104,  8110,  8116,  8119,
    8120,  8121,  8122,  8123,  8126,  8132,  8134,  8136,  8138,  8140,
    8142,  8143,  8144,  8145,  8146,  8147,  8148,  8150,  8152,  8154,
    8156,  8158,  8160,  8162,  8163,  8165,  8166,  8172,  8173,  8180,
    8183,  8191,  8195,  8202,  8202,  8206,  8206,  8211,  8211,  8215,
    8215,  8219,  8225,  8225,  8228,  8228,  8234,  8241,  8242,  8243,
    8247,  8248,  8251,  8252,  8256,  8262,  8272,  8273,  8281,  8282,
    8283,  8284,  8285,  8286,  8290,  8291,  8292,  8293,  8297,  8298,
    8302,  8318,  8319,  8320,  8324,  8338,  8338,  8350,  8351,  8355,
    8356,  8357,  8358,  8359,  8360,  8361,  8362,  8363,  8364,  8365,
    8366,  8367,  8368,  8369,  8370,  8371,  8372,  8373,  8374,  8375,
    8376,  8377,  8378,  8379,  8380,  8381,  8382,  8383,  8384,  8385,
    8386,  8387,  8388,  8389,  8390,  8391,  8392,  8393,  8394,  8395,
    8396,  8397,  8398,  8399,  8400,  8401,  8402,  8403,  8404,  8405,
    8406,  8407,  8408,  8409,  8410,  8411,  8412,  8413,  8414,  8415,
    8416,  8417,  8418,  8419,  8420,  8421,  8422,  8423,  8424,  8425,
    8426,  8427,  8428,  8429,  8430,  8431,  8432,  8433,  8434,  8435,
    8436,  8437,  8438,  8439,  8440,  8441,  8442,  8443,  8444,  8445,
    8446,  8447,  8448,  8449,  8450,  8451,  8452,  8453,  8454,  8455,
    8456,  8457,  8458,  8459,  8460,  8461,  8462,  8463,  8464,  8465,
    8466,  8467,  8468,  8469,  8470,  8471,  8472,  8473,  8474,  8475,
    8476,  8477,  8478,  8479,  8480,  8481,  8482,  8483,  8484,  8485,
    8486,  8487,  8488,  8489,  8490,  8491,  8492,  8493,  8494,  8495,
    8496,  8497,  8498,  8499,  8500,  8501,  8502,  8503,  8504,  8505,
    8506,  8507,  8508,  8509,  8510,  8511,  8512,  8513,  8514,  8515,
    8516,  8517,  8518,  8519,  8520,  8521,  8522,  8523,  8524,  8525,
    8526,  8527,  8528,  8529,  8530,  8531,  8532,  8533,  8534,  8535,
    8536,  8537,  8538,  8539,  8540,  8541,  8542,  8543,  8544,  8545,
    8546,  8547,  8548,  8549,  8550,  8551,  8552,  8553,  8554,  8555,
    8556,  8557,  8559,  8560,  8561,  8562,  8563,  8564,  8565,  8566,
    8567,  8568,  8569,  8570,  8571,  8572,  8573,  8574,  8575,  8576,
    8577,  8578,  8579,  8580,  8581,  8582,  8583,  8584,  8585,  8586,
    8587,  8588,  8589,  8590,  8591,  8592,  8593,  8594,  8595,  8596,
    8597,  8598,  8599,  8600,  8601,  8602,  8603,  8604,  8605,  8606,
    8607,  8608,  8609,  8610,  8611,  8612,  8613,  8614,  8615,  8616,
    8617,  8618,  8619,  8620,  8621,  8622,  8623,  8624,  8625,  8626,
    8627,  8628,  8629,  8630,  8631,  8632,  8633,  8634,  8635,  8636,
    8637,  8638,  8639,  8640,  8641,  8642,  8643,  8644,  8645,  8646,
    8647,  8648,  8649,  8650,  8651,  8652,  8653,  8654,  8655,  8656,
    8657,  8658,  8659,  8660,  8661,  8662,  8663,  8664,  8665,  8666,
    8667,  8668,  8669,  8670,  8671,  8672,  8673,  8681,  8681,  8688,
    8688,  8776,  8780,  8776,  8789,  8793,  8799,  8807,  8817,  8827,
    8839,  8842,  8861,  8887,  8890,  8896,  8899,  8904,  8907,  8915,
    8923,  8936,  8939,  8947,  8950,  8953,  8961,  8965,  8966,  8967,
    8968,  8969,  8970,  8971,  8972,  8976,  8977,  8978,  8979,  8980,
    8986,  8987,  8988,  8989,  8990,  8991,  8992,  8993,  8994,  8995,
    8996,  8997,  8998,  8999,  9000,  9001,  9006,  9012,  9013,  9021,
    9021,  9029,  9029,  9033,  9037,  9052,  9067,  9073,  9075,  9083,
    9084,  9088,  9089,  9092,  9099,  9102,  9131,  9157,  9211,  9247,
    9256,  9267,  9270,  9275,  9289,  9303,  9306,  9302,  9325,  9325,
    9331,  9332,  9335,  9336,  9337,  9338,  9339,  9340,  9341,  9352,
    9355,  9360,  9364,  9369,  9373,  9378,  9382,  9385,  9389,  9392,
    9397,  9401,  9412,  9418,  9418,  9419,  9420,  9427,  9437,  9437,
    9439,  9440,  9441,  9442,  9443,  9444,  9445,  9446,  9447,  9448,
    9449,  9450,  9451,  9452,  9453,  9454,  9455,  9456,  9457,  9458,
    9459,  9460,  9461,  9462,  9463,  9464,  9465,  9466,  9467,  9468,
    9469,  9470,  9471,  9472,  9473,  9474,  9475,  9476,  9477,  9478,
    9479,  9480,  9481,  9482,  9483,  9484,  9485,  9486,  9487,  9488,
    9489,  9490,  9491,  9492,  9493,  9494,  9495,  9496,  9497,  9498,
    9499,  9500,  9501,  9502,  9503,  9504,  9505,  9506,  9507,  9508,
    9509,  9510,  9511,  9512,  9513,  9514,  9515,  9516,  9517,  9518,
    9519,  9520,  9521,  9522,  9523,  9524,  9525,  9526
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
  "DATETIME_VALUE", "INTERVAL_VALUE", "FGL_SIZEOF", "DYNAMIC_ARRAY", 
  "RESIZE_ARRAY", "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", 
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
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
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
       0,   256,  1711,  1712,  1713,  1618,  1658,  1613,  1550,  1633,
    1430,  1536,  1532,  1447,  1608,  1349,  1406,  1478,  1644,  1631,
    1537,  1564,  1632,  1413,  1714,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,  1723,  1724,  1725,  1000,  1001,  1002,  1003,
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
    1344,  1345,  1346,  1347,  1348,  1350,  1351,  1352,  1353,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1407,  1408,  1409,  1410,  1411,  1412,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1479,
    1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,
    1530,  1531,  1533,  1534,  1535,  1538,  1539,  1540,  1541,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1549,  1551,  1552,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1609,  1610,  1611,  1612,  1614,  1615,  1616,
    1617,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1634,  1635,  1636,  1637,  1638,  1639,  1640,
    1641,  1642,  1643,  1645,  1646,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1659,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   728,   729,   730,   731,   732,   733,   733,   734,   734,
     735,   736,   736,   736,   736,   736,   736,   737,   737,   737,
     737,   737,   738,   738,   739,   739,   741,   740,   740,   742,
     742,   743,   743,   743,   743,   743,   743,   743,   743,   743,
     743,   743,   743,   743,   743,   743,   743,   743,   744,   744,
     746,   745,   747,   747,   748,   748,   748,   748,   748,   748,
     748,   748,   748,   749,   750,   751,   750,   750,   750,   750,
     750,   752,   753,   750,   754,   755,   756,   750,   757,   758,
     750,   759,   760,   750,   761,   762,   763,   750,   764,   764,
     765,   765,   765,   766,   766,   767,   767,   768,   768,   769,
     769,   770,   770,   772,   771,   773,   771,   774,   774,   775,
     775,   776,   777,   778,   777,   779,   780,   779,   782,   781,
     784,   783,   785,   785,   785,   785,   785,   785,   786,   787,
     787,   788,   788,   789,   790,   790,   791,   793,   794,   792,
     795,   795,   796,   796,   797,   797,   798,   798,   798,   799,
     799,   801,   800,   802,   800,   803,   800,   804,   800,   805,
     800,   806,   806,   807,   807,   808,   808,   808,   808,   808,
     808,   809,   810,   810,   811,   811,   812,   812,   813,   813,
     815,   816,   814,   814,   817,   817,   819,   818,   820,   820,
     820,   820,   820,   821,   820,   822,   822,   822,   822,   823,
     824,   824,   825,   825,   826,   826,   826,   826,   828,   827,
     829,   827,   830,   827,   831,   831,   832,   832,   833,   834,
     834,   834,   835,   837,   836,   838,   836,   839,   836,   840,
     840,   841,   842,   843,   843,   845,   846,   844,   847,   847,
     847,   847,   847,   847,   847,   847,   847,   847,   847,   847,
     847,   847,   847,   847,   847,   847,   847,   847,   847,   848,
     847,   849,   847,   850,   847,   847,   847,   847,   847,   847,
     847,   847,   847,   847,   851,   851,   852,   853,   854,   855,
     855,   856,   858,   857,   859,   859,   859,   859,   859,   859,
     859,   861,   860,   862,   862,   863,   863,   864,   866,   865,
     867,   867,   867,   867,   867,   867,   867,   868,   869,   869,
     871,   870,   872,   872,   872,   872,   872,   872,   872,   872,
     872,   872,   872,   872,   872,   872,   872,   872,   872,   872,
     872,   872,   872,   872,   872,   873,   875,   874,   876,   874,
     878,   877,   879,   877,   880,   880,   881,   882,   882,   883,
     884,   884,   884,   884,   884,   884,   884,   884,   885,   886,
     887,   889,   890,   888,   891,   891,   892,   893,   893,   893,
     894,   894,   896,   895,   897,   895,   898,   895,   899,   900,
     901,   902,   902,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   904,   904,   904,   904,   904,   904,   904,   904,
     905,   905,   906,   906,   906,   906,   906,   906,   906,   906,
     906,   907,   907,   907,   907,   907,   907,   907,   907,   907,
     907,   907,   908,   908,   909,   909,   910,   910,   911,   911,
     912,   912,   913,   914,   914,   914,   914,   914,   914,   915,
     915,   915,   915,   916,   916,   917,   918,   918,   918,   919,
     918,   920,   920,   921,   921,   922,   922,   922,   922,   923,
     923,   924,   924,   924,   924,   924,   924,   924,   924,   925,
     926,   927,   927,   927,   927,   927,   927,   928,   928,   928,
     928,   928,   928,   928,   929,   931,   932,   930,   933,   934,
     930,   936,   937,   935,   938,   939,   935,   940,   941,   935,
     942,   943,   935,   935,   935,   935,   935,   935,   935,   935,
     935,   935,   935,   935,   935,   935,   935,   935,   935,   935,
     935,   935,   935,   935,   935,   935,   935,   935,   944,   944,
     945,   946,   946,   946,   946,   946,   946,   946,   946,   946,
     947,   947,   948,   948,   948,   948,   949,   949,   949,   950,
     950,   951,   951,   951,   952,   952,   952,   952,   952,   952,
     952,   952,   952,   952,   953,   953,   954,   954,   955,   955,
     957,   958,   956,   959,   959,   961,   962,   963,   960,   964,
     964,   966,   967,   965,   968,   968,   969,   969,   970,   970,
     972,   971,   973,   971,   974,   974,   975,   975,   977,   976,
     978,   976,   979,   980,   980,   980,   981,   981,   982,   982,
     983,   983,   984,   984,   986,   985,   987,   985,   988,   985,
     989,   985,   990,   985,   991,   992,   992,   992,   992,   992,
     992,   992,   993,   993,   994,   995,   996,   997,   997,   997,
     997,   997,   997,   997,   997,   998,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1005,  1006,  1007,  1008,  1008,  1009,
    1009,  1010,  1010,  1010,  1010,  1010,  1010,  1011,  1012,  1012,
    1013,  1014,  1014,  1015,  1016,  1016,  1017,  1018,  1019,  1019,
    1019,  1020,  1020,  1020,  1022,  1021,  1023,  1023,  1024,  1024,
    1025,  1025,  1026,  1027,  1027,  1028,  1029,  1029,  1030,  1031,
    1031,  1032,  1033,  1033,  1035,  1036,  1034,  1037,  1038,  1037,
    1039,  1040,  1037,  1041,  1041,  1042,  1044,  1043,  1043,  1045,
    1045,  1046,  1046,  1047,  1048,  1048,  1048,  1049,  1049,  1050,
    1050,  1052,  1051,  1053,  1051,  1054,  1051,  1055,  1051,  1056,
    1051,  1057,  1051,  1058,  1051,  1059,  1051,  1060,  1051,  1061,
    1051,  1062,  1051,  1063,  1051,  1064,  1051,  1065,  1065,  1066,
    1066,  1067,  1068,  1069,  1069,  1069,  1071,  1070,  1072,  1072,
    1073,  1072,  1074,  1075,  1075,  1075,  1075,  1075,  1075,  1076,
    1076,  1077,  1078,  1078,  1078,  1078,  1078,  1078,  1078,  1078,
    1078,  1080,  1079,  1079,  1082,  1081,  1083,  1084,  1085,  1085,
    1086,  1086,  1087,  1088,  1088,  1088,  1088,  1088,  1088,  1088,
    1088,  1088,  1088,  1088,  1088,  1088,  1088,  1088,  1088,  1088,
    1088,  1089,  1091,  1092,  1090,  1093,  1093,  1094,  1095,  1096,
    1097,  1097,  1099,  1098,  1100,  1100,  1101,  1101,  1102,  1102,
    1102,  1102,  1102,  1102,  1103,  1103,  1104,  1104,  1105,  1106,
    1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1107,
    1108,  1108,  1109,  1110,  1110,  1112,  1113,  1114,  1115,  1111,
    1116,  1118,  1119,  1117,  1120,  1121,  1121,  1122,  1122,  1123,
    1124,  1124,  1125,  1127,  1126,  1128,  1128,  1128,  1128,  1130,
    1131,  1132,  1129,  1134,  1133,  1135,  1137,  1136,  1138,  1136,
    1139,  1136,  1140,  1140,  1141,  1141,  1142,  1142,  1143,  1143,
    1143,  1144,  1145,  1146,  1147,  1147,  1147,  1148,  1148,  1149,
    1149,  1151,  1152,  1150,  1153,  1153,  1155,  1154,  1156,  1154,
    1157,  1158,  1158,  1158,  1158,  1159,  1159,  1159,  1159,  1159,
    1160,  1161,  1161,  1162,  1163,  1164,  1164,  1165,  1166,  1166,
    1166,  1166,  1166,  1166,  1167,  1168,  1169,  1169,  1170,  1170,
    1171,  1172,  1172,  1173,  1173,  1174,  1175,  1176,  1176,  1176,
    1176,  1176,  1176,  1177,  1177,  1178,  1179,  1179,  1180,  1180,
    1181,  1181,  1182,  1182,  1183,  1183,  1183,  1183,  1183,  1184,
    1184,  1185,  1185,  1186,  1186,  1187,  1188,  1189,  1189,  1190,
    1191,  1191,  1191,  1192,  1192,  1193,  1193,  1194,  1195,  1195,
    1196,  1196,  1197,  1198,  1199,  1200,  1200,  1201,  1202,  1202,
    1203,  1203,  1204,  1204,  1205,  1206,  1206,  1207,  1207,  1207,
    1207,  1208,  1208,  1208,  1209,  1210,  1210,  1211,  1211,  1211,
    1212,  1213,  1213,  1214,  1214,  1214,  1214,  1214,  1214,  1214,
    1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,
    1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1215,
    1216,  1216,  1217,  1217,  1217,  1217,  1217,  1218,  1220,  1219,
    1221,  1221,  1222,  1223,  1223,  1224,  1224,  1225,  1225,  1227,
    1226,  1228,  1230,  1229,  1231,  1231,  1232,  1232,  1233,  1233,
    1234,  1234,  1234,  1234,  1235,  1235,  1236,  1236,  1237,  1238,
    1238,  1239,  1240,  1241,  1242,  1243,  1243,  1244,  1244,  1246,
    1245,  1247,  1245,  1248,  1245,  1249,  1245,  1250,  1245,  1251,
    1245,  1252,  1245,  1253,  1253,  1253,  1253,  1253,  1253,  1255,
    1254,  1256,  1256,  1258,  1257,  1257,  1257,  1257,  1257,  1259,
    1259,  1260,  1260,  1261,  1262,  1262,  1264,  1263,  1265,  1266,
    1267,  1267,  1267,  1268,  1268,  1268,  1268,  1269,  1270,  1270,
    1271,  1271,  1272,  1273,  1273,  1273,  1273,  1273,  1273,  1273,
    1273,  1274,  1274,  1275,  1275,  1276,  1276,  1276,  1276,  1276,
    1276,  1276,  1276,  1276,  1276,  1277,  1277,  1278,  1278,  1278,
    1278,  1279,  1279,  1280,  1280,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1282,
    1282,  1282,  1284,  1285,  1286,  1287,  1288,  1289,  1283,  1290,
    1290,  1291,  1292,  1292,  1294,  1295,  1296,  1297,  1298,  1299,
    1293,  1300,  1302,  1303,  1304,  1301,  1305,  1305,  1305,  1305,
    1306,  1306,  1306,  1306,  1306,  1307,  1308,  1308,  1308,  1308,
    1309,  1309,  1311,  1312,  1310,  1313,  1314,  1310,  1315,  1315,
    1316,  1316,  1317,  1317,  1317,  1317,  1317,  1318,  1319,  1319,
    1320,  1320,  1321,  1321,  1322,  1322,  1322,  1322,  1322,  1323,
    1323,  1324,  1324,  1325,  1325,  1325,  1326,  1326,  1327,  1327,
    1328,  1328,  1329,  1329,  1329,  1330,  1330,  1331,  1331,  1331,
    1331,  1331,  1331,  1331,  1332,  1332,  1333,  1333,  1334,  1334,
    1335,  1335,  1336,  1336,  1337,  1338,  1338,  1339,  1339,  1340,
    1341,  1341,  1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,
    1346,  1347,  1347,  1348,  1349,  1349,  1349,  1349,  1349,  1349,
    1349,  1349,  1349,  1349,  1349,  1350,  1350,  1351,  1351,  1352,
    1353,  1355,  1354,  1357,  1356,  1356,  1358,  1358,  1359,  1359,
    1360,  1360,  1361,  1361,  1363,  1362,  1364,  1365,  1365,  1366,
    1367,  1366,  1368,  1369,  1368,  1370,  1370,  1370,  1370,  1370,
    1370,  1370,  1370,  1371,  1372,  1373,  1374,  1374,  1375,  1376,
    1376,  1377,  1377,  1377,  1378,  1379,  1380,  1380,  1381,  1382,
    1382,  1382,  1384,  1383,  1385,  1385,  1385,  1385,  1385,  1385,
    1385,  1385,  1385,  1385,  1385,  1385,  1386,  1386,  1386,  1386,
    1387,  1387,  1387,  1388,  1388,  1388,  1389,  1389,  1389,  1390,
    1390,  1391,  1391,  1391,  1391,  1391,  1391,  1392,  1392,  1393,
    1393,  1394,  1394,  1395,  1395,  1396,  1397,  1397,  1398,  1398,
    1399,  1399,  1400,  1401,  1402,  1403,  1404,  1404,  1405,  1405,
    1406,  1406,  1406,  1407,  1407,  1408,  1408,  1408,  1409,  1409,
    1409,  1409,  1410,  1411,  1411,  1412,  1412,  1413,  1413,  1414,
    1415,  1415,  1415,  1415,  1415,  1415,  1415,  1416,  1417,  1418,
    1419,  1419,  1420,  1420,  1421,  1422,  1423,  1423,  1424,  1425,
    1426,  1426,  1427,  1427,  1427,  1428,  1428,  1429,  1429,  1430,
    1431,  1431,  1432,  1432,  1433,  1433,  1434,  1434,  1435,  1435,
    1436,  1436,  1437,  1437,  1438,  1438,  1439,  1439,  1440,  1441,
    1442,  1442,  1442,  1442,  1443,  1443,  1444,  1444,  1445,  1445,
    1446,  1446,  1446,  1446,  1446,  1446,  1446,  1446,  1446,  1447,
    1447,  1447,  1447,  1447,  1447,  1447,  1447,  1447,  1448,  1448,
    1448,  1449,  1449,  1449,  1449,  1450,  1450,  1450,  1451,  1451,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1453,  1453,  1454,  1454,  1454,
    1454,  1454,  1455,  1456,  1457,  1458,  1458,  1458,  1458,  1458,
    1458,  1458,  1458,  1459,  1459,  1459,  1459,  1459,  1459,  1459,
    1459,  1460,  1461,  1461,  1461,  1462,  1462,  1463,  1463,  1463,
    1464,  1465,  1465,  1465,  1465,  1466,  1467,  1468,  1468,  1469,
    1469,  1470,  1470,  1470,  1470,  1470,  1470,  1470,  1470,  1471,
    1471,  1471,  1471,  1471,  1471,  1471,  1471,  1472,  1472,  1472,
    1472,  1472,  1472,  1472,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1474,  1474,  1474,  1475,  1477,  1476,  1478,  1476,
    1479,  1476,  1480,  1476,  1481,  1481,  1481,  1482,  1482,  1483,
    1483,  1483,  1484,  1484,  1485,  1485,  1486,  1488,  1489,  1487,
    1490,  1491,  1491,  1492,  1493,  1493,  1493,  1493,  1493,  1494,
    1495,  1495,  1496,  1497,  1498,  1498,  1498,  1498,  1499,  1499,
    1500,  1500,  1500,  1501,  1502,  1502,  1502,  1503,  1503,  1503,
    1503,  1503,  1503,  1503,  1503,  1504,  1504,  1504,  1504,  1504,
    1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,
    1504,  1504,  1504,  1504,  1504,  1504,  1504,  1505,  1505,  1506,
    1507,  1508,  1508,  1509,  1509,  1510,  1510,  1511,  1511,  1512,
    1512,  1513,  1514,  1514,  1515,  1515,  1516,  1517,  1517,  1517,
    1518,  1518,  1519,  1520,  1521,  1522,  1523,  1523,  1524,  1524,
    1524,  1524,  1524,  1524,  1525,  1525,  1525,  1525,  1526,  1526,
    1527,  1528,  1528,  1528,  1529,  1531,  1530,  1532,  1532,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1533,  1533,  1535,  1534,  1537,
    1536,  1539,  1540,  1538,  1541,  1541,  1541,  1542,  1542,  1542,
    1542,  1542,  1542,  1543,  1543,  1544,  1545,  1546,  1546,  1547,
    1547,  1548,  1548,  1549,  1549,  1549,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,
    1551,  1551,  1551,  1551,  1551,  1551,  1552,  1553,  1553,  1555,
    1554,  1556,  1556,  1557,  1557,  1558,  1559,  1560,  1560,  1561,
    1561,  1562,  1562,  1562,  1563,  1563,  1564,  1564,  1565,  1566,
    1566,  1567,  1567,  1568,  1569,  1571,  1572,  1570,  1573,  1573,
    1574,  1574,  1575,  1575,  1575,  1575,  1575,  1575,  1575,  1576,
    1576,  1577,  1577,  1578,  1578,  1579,  1579,  1580,  1581,  1582,
    1583,  1583,  1584,  1585,  1585,  1586,  1587,  1587,  1589,  1588,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590
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
       1,     2,     1,     1,     1,     2,     1,     1,     1,     2,
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
       0,     0,    11,     0,     2,     0,     0,     0,     9,     0,
       3,     0,     0,    10,     0,     1,     0,     1,     1,     2,
       0,     3,     0,     3,     0,     1,     1,     2,     0,     3,
       0,     3,     3,     1,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     0,     3,     0,     3,     0,     4,
       0,     4,     0,     4,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     4,     6,
       4,     3,     6,     3,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     4,     1,
       1,     1,     4,     3,     6,     3,     6,     1,     1,     2,
       2,     1,     2,     2,     1,     3,     1,     2,     2,     2,
       4,     2,     2,     4,     0,     8,     0,     1,     1,     1,
       0,     1,     2,     0,     1,     2,     0,     1,     2,     0,
       1,     3,     0,     2,     0,     0,     8,     0,     0,     3,
       0,     0,     7,     5,     2,     2,     0,     5,     4,     1,
       3,     3,     3,     1,     0,     2,     1,     0,     1,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     1,     3,     1,
       3,     2,     4,     1,     1,     1,     0,     4,     5,     6,
       0,    10,     3,     2,     2,     1,     1,     2,     2,     0,
       2,     1,     2,     3,     3,     3,     3,     1,     1,     1,
       1,     0,     3,     1,     0,     3,     2,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     7,     1,     1,     2,     2,     2,
       3,     4,     0,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     0,     0,     0,     0,    13,
       1,     0,     0,     6,     2,     1,     2,     2,     2,     1,
       1,     2,     1,     0,     3,     2,     1,     1,     1,     0,
       0,     0,    14,     0,     5,     1,     0,     3,     0,     7,
       0,     5,     1,     2,     0,     1,     1,     1,     0,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     0,     0,     7,     1,     2,     0,     3,     0,     4,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     2,     2,     2,     5,
       8,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       2,     3,     6,     1,     3,     1,     1,     1,     3,     6,
       9,     1,     1,     1,     1,     2,     0,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     2,
       0,     1,     1,     1,     3,     1,     3,     7,     0,     7,
       0,     6,     3,     1,     3,     1,     2,     5,     0,     7,
       0,     2,     0,     1,     5,     2,     5,     0,     5,     6,
       4,     0,     1,     1,     5,     0,     2,     0,     5,     4,
       2,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     5,
       1,     1,     2,     4,     4,     6,     2,     1,     0,    11,
       0,     2,     5,     0,     1,     0,     2,     1,     2,     0,
       3,     1,     0,     4,     0,     2,     1,     3,     1,     1,
       4,     5,     5,     3,     0,     1,     1,     1,     1,     0,
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
       1,     2,     3,     1,     1,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     4,     3,     2,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       5,     4,     4,     3,     4,     1,     1,     1,     3,     1,
       5,     7,     5,     0,     2,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       4,     6,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     5,     1,     4,
       1,     1,     7,     4,     1,     0,     4,     1,     2,     1,
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
     834,     0,  2234,     0,     0,     0,   883,   180,     0,   859,
     862,   178,   183,   838,     0,   832,   835,   836,   839,   842,
     843,   841,   879,   880,   882,   840,   136,   133,     0,   129,
     131,   130,   134,  2262,   715,   655,   310,  1694,  1692,   877,
     176,   186,   878,   179,     1,   844,   837,   881,   128,   132,
     135,     0,     0,   632,     0,     0,   177,   886,   952,   633,
     887,   888,   884,   667,   944,     0,   945,   953,   951,   186,
     181,   199,     0,   184,   200,   235,     0,   864,  1244,     0,
       0,   863,  1232,   871,     0,     0,   856,   855,   857,   833,
     845,   846,   865,   849,   850,   851,   854,   852,   853,   858,
       0,  1693,   946,   885,     0,     0,   960,   958,   959,   948,
     947,   308,   186,  1168,   193,   187,   186,   192,   232,     0,
     714,     0,     0,     0,     0,   176,   581,   921,   847,     0,
     342,   328,   202,   314,   279,   298,   319,   321,   318,     0,
     340,     0,   327,   320,   324,   330,   329,   186,   331,   311,
     334,   312,   313,   957,   956,     0,    22,    23,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
       0,   539,   531,    16,   538,   952,    15,     0,   963,     0,
     309,     0,   185,  1169,   182,     0,   199,   201,   273,   204,
     261,   267,   268,   252,   225,   263,   202,   240,   241,     0,
     227,   279,   298,   250,   253,   248,     0,   223,     0,   259,
     251,   256,   266,   265,   186,   269,   186,   238,   239,   236,
     272,     0,     0,     0,     0,   872,   176,   176,     0,     0,
     203,     0,     0,   332,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,   277,     0,   954,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     545,     0,     0,     0,   668,   439,   441,  1239,     0,     0,
       0,  1659,     0,   435,     0,     0,     0,   434,     0,   449,
     541,     0,     0,     0,     0,     0,   544,   402,   408,   445,
     442,   403,   404,   406,   407,   440,   443,   448,   540,   494,
     491,   500,   497,     0,     0,    17,    18,    19,    20,    21,
       0,    14,   485,     0,     0,   961,     0,   188,   191,   189,
     190,     0,   196,   195,   194,   197,   205,   206,   207,   210,
     274,   186,   274,     0,     0,     0,     0,   186,   270,   271,
       0,     0,   186,     0,   274,     0,     0,   249,   233,  1245,
       0,     0,  1233,  2268,   582,   922,   866,     0,   214,   215,
       0,     0,   291,   293,   288,   289,   285,   287,   284,   286,
     283,     0,   293,   304,   305,   301,   303,   300,   302,   295,
       0,     0,     0,   344,     0,   347,   349,   222,     0,   221,
       0,   186,     0,     0,     0,   566,   637,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   563,   549,   554,     0,
     550,   553,   552,   646,     0,   645,   568,     0,    11,   172,
     433,   410,   409,     0,  1174,     0,     0,   447,  1667,  1665,
    1666,  1662,  1664,  1661,  1663,  1655,     0,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   546,   547,   548,   460,     0,     0,   459,   469,     0,
       0,   414,     0,     0,   415,   405,   411,   413,   416,   417,
     418,   419,   420,   412,     0,     0,     0,     0,     0,     0,
       0,    12,    93,     0,   964,     0,   949,   198,     0,     0,
     262,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,   186,   234,   237,   976,   713,   889,
     976,     0,  2266,  2268,  1168,  1794,   860,     0,   976,     0,
       0,   315,   280,     0,     0,   290,   307,   281,   306,     0,
     299,     0,   322,     0,   316,     0,   341,     0,   346,   336,
       0,     0,   325,   278,   335,   525,     0,     0,   537,     0,
       0,   534,   533,   536,   532,   543,   528,   528,     0,     0,
     528,     0,   551,     0,   555,     0,   298,     0,   535,   542,
     282,     0,  1240,  1734,     0,     0,     0,     0,     0,   436,
       0,     0,   450,     0,     0,     0,     0,   452,   451,   470,
     461,   476,   479,   480,   477,   483,   482,   481,   471,   472,
     473,   474,   475,   421,   462,   466,   484,   478,   465,   484,
     444,   495,   492,   501,   498,   526,     0,    98,   486,    94,
      95,    97,   488,     0,     0,   235,     0,     0,     0,   242,
     243,     0,   246,     0,     0,   254,     0,   244,   224,   208,
       0,   257,   276,   982,     0,   977,   978,   976,     0,   873,
    2267,  2265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2249,     0,  1360,
    1359,     0,  1361,     0,   396,  1358,  1275,     0,     5,  1357,
     397,   394,     0,   399,   174,   484,  1145,     0,     0,  1367,
     125,   393,   392,     0,     0,   387,   484,     0,  1311,  2242,
       0,   398,   361,     0,     3,     2,     0,   395,  1272,     0,
       0,   388,   385,   400,     0,     0,     0,     0,  1365,  1355,
     391,     0,     0,     0,     0,     0,     0,     0,     0,  1354,
       0,     0,     0,   175,     0,   384,   383,     0,     0,  2246,
    2245,     0,     0,     0,   137,     0,   390,   389,     0,     0,
     386,   484,     0,     0,   484,     0,   575,     0,     0,     0,
       0,     0,     0,   484,   821,  1242,     0,     0,  1156,     0,
    2235,     0,   105,     0,     0,   893,     0,     0,     0,     0,
     822,     0,     0,  1825,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   684,     0,     0,  2270,  2271,  2272,  2273,
    2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,  2282,  2283,
    2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,  2292,  2293,
    2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,  2302,  2303,
    2304,  2305,  2306,  2307,  2308,  2309,  2310,  2311,  2312,  2313,
    2314,  2315,  2316,  2317,  2318,   931,  2319,  2320,  2321,  2322,
    2323,  2324,  2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,
    2333,  2334,  2335,  1136,  1138,  1133,  1135,  1134,  1137,  2336,
    2337,  1265,  2338,  1271,  1270,  2339,  2340,  2341,  2342,  2343,
    2344,  2345,  2346,  2347,  2348,  1422,  2349,  2350,  2351,  2352,
    2353,  2354,  2355,  2356,  2357,  2269,   861,   586,     0,   926,
       0,   924,     0,   343,   216,   217,     0,   292,   297,     0,
       0,     0,     0,   345,   348,     0,   220,     0,     0,   567,
       0,   641,     0,   643,   506,     0,   504,     0,   528,     0,
     505,     0,     0,   565,     0,   562,   559,   530,   503,   569,
       0,   171,  1736,  1737,  1735,     0,   438,  1239,     0,  1660,
    1239,   437,  1239,  1239,  1239,  1239,  1239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,   962,     0,   211,   275,   226,     0,     0,
     186,     0,     0,     0,     0,     0,  1246,     0,     0,  1234,
     380,   378,   379,  1269,  1071,  1070,  1076,     0,  1634,  1635,
       0,     0,  1295,   656,   657,  1296,  1626,  1627,  1298,   848,
    1108,  1113,  2244,   649,   124,  2257,     0,     0,  1310,     7,
       0,     6,     0,  2250,  1109,     0,  1202,  1201,  1148,  1200,
    1147,   432,  1368,  1356,     0,  1266,   874,   422,  1796,  1362,
     126,     0,  1112,   123,     0,   828,    24,   651,   401,     0,
     827,  1104,   829,     0,  1366,   915,   914,   917,   913,   916,
    2259,     0,   911,     0,   650,  1008,   912,  2253,     0,  2243,
     122,  1268,  1005,   716,  1003,     0,   647,  2238,   764,   763,
     765,   761,     0,     0,  1267,  1018,   652,  1421,     0,  2225,
    1416,  1419,  2215,  2218,  2219,  2221,  2224,     0,     0,     0,
       0,  1077,  1072,     0,  1057,  1058,  1059,  1060,  1066,  1068,
    1067,  1065,  1064,     0,     0,     0,  1063,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1049,  1040,  1041,   991,     0,   989,  1091,   430,    24,     0,
    2240,   127,   648,     0,  1243,  1241,  1167,     0,  1785,  1786,
    1168,  1149,  1369,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,   952,     0,    69,     0,   103,   624,     0,
     671,   670,     0,  1139,  1025,  1143,     0,     0,  1092,  1260,
       0,     0,  1146,   676,   673,   674,     0,   678,   679,     0,
     681,   682,     0,   677,   986,   988,     0,     0,   987,   766,
     984,   727,   980,   943,     0,     0,     0,     0,   688,   689,
       0,     0,   941,   938,   939,   935,   936,   937,   930,   934,
     933,     0,     0,     0,     0,     0,     0,   590,   592,   584,
     587,   588,   928,  2268,   923,   925,   867,     0,   294,   296,
     323,   317,     0,     0,   326,   638,   640,     0,     0,     0,
       0,   528,   511,     0,   528,   528,     0,   556,     0,   291,
       0,     0,  1764,  1651,  1653,  1820,  1824,  1765,  1657,  1762,
       0,     0,  1761,     0,     0,     0,  1763,     0,     0,     0,
       0,     0,     0,     0,  2225,  1652,  1760,  1654,  1749,     0,
    1738,  1740,  1744,  1747,  1775,  1818,  1776,  1821,  2226,  2216,
    1748,  1177,  1668,  1176,  1175,  1178,  1180,  1179,  1173,   463,
     464,   468,   453,     0,   456,   467,     0,   455,   496,   493,
     502,   499,   527,   487,    96,   489,   950,     0,   247,   231,
       0,   229,   255,   245,   235,   258,   983,   176,   979,   890,
     176,     0,     0,     0,  1340,  1341,     0,     0,     0,  1312,
    1315,  1317,  1318,  1319,  1323,  1322,  1320,  1321,     0,     0,
       0,  1313,  1314,     0,     0,     0,     0,     0,     0,     0,
       0,  1110,     0,    24,  1197,  1199,  1198,     0,   425,   426,
     423,   424,   996,     0,     0,   366,    25,   360,     0,  1105,
       0,  1104,     0,  1103,     0,     0,     0,     0,     0,     0,
    1012,  1795,     0,     0,     0,     0,     0,     0,  2240,     0,
       0,   138,     0,     0,  1022,  1014,  1015,  1020,     0,     0,
    2217,     0,  2228,  1417,  1418,     0,     0,   940,   428,  2209,
    1035,   350,     0,     0,   576,   629,   628,   626,   631,  1043,
     630,  1048,  1044,  1047,   820,   812,   806,   818,   819,   804,
     805,   813,   808,   814,   807,   817,   811,   815,   810,   816,
     803,   809,   796,   802,  1045,  1046,     0,  1053,  1061,  1050,
    1051,  1055,  1056,  1054,  1052,  1062,     0,     0,     0,   830,
       0,     0,     0,     0,     0,   776,   775,   772,  2241,  2248,
      24,  1163,  1164,  1165,  1166,  1160,  1158,  1256,  1168,  1150,
    1151,  1154,  1170,  2236,     0,     0,     0,     0,    99,     0,
     100,     0,     0,     0,    74,     0,     0,     0,   112,   107,
       0,   672,   920,     0,   919,     0,   484,  1141,     0,   971,
     972,   995,   966,   967,   823,   993,  1094,  1262,     0,  1264,
    1263,  1881,  1997,  1993,  1999,  2031,  2011,  2002,  1961,  1923,
    2050,  2017,  2025,  1914,  2020,  1882,  1829,  2012,  1919,  1970,
    2104,  1949,  1937,  1950,  2048,  2051,  2019,  1973,  2054,  1841,
    2111,  2047,  2075,  1852,  2147,  1938,  2120,  1834,  2080,  1850,
    1909,  1956,  1976,  2070,  2098,  2103,  1833,  2028,  2056,  1845,
    1847,  1870,  1887,  1907,  1917,  1927,  1980,  1983,  2041,  2052,
    2058,  2059,  2076,  2121,  2132,  1832,  1863,  1886,  1885,  1893,
    1895,  1903,  1913,  1934,  1952,  1955,  1981,  1989,  2045,  2055,
    2065,  2071,  2072,  2074,  2099,  2129,  2140,  1853,  1856,  1867,
    1873,  1875,  1880,  1884,  1890,  1898,  1900,  1901,  1902,  1912,
    1922,  1929,  1945,  1946,  1957,  1975,  1979,  1992,  2008,  2039,
    2049,  2053,  2060,  2068,  2077,  2087,  2091,  2108,  2114,  2118,
    2126,  2131,  2134,  1876,  1994,  2036,  1861,  1862,  1879,  1883,
    1889,  1891,  1905,  1906,  1916,  1925,  1930,  1932,  1933,  1939,
    1947,  1964,  1965,  1978,  2006,  2010,  2013,  2018,  2022,  2030,
    2037,  2038,  2043,  2061,  2062,  2067,  2073,  2078,  2084,  2085,
    2086,  2088,  2090,  2092,  2101,  2123,  2124,  2125,  2130,  2146,
    1836,  1988,  1996,  1998,  2094,  1838,  1842,  1846,  1851,  1857,
    1858,  1871,  1872,  1874,  1877,  1888,  1904,  1924,  1926,  1936,
    1940,  1942,  1943,  1951,  1960,  1962,  1963,  1974,  1987,  2005,
    2023,  2024,  2040,  2042,  2046,  2057,  2079,  2089,  2097,  2119,
    2122,  2136,  2137,  2138,  1869,  1839,  1859,  1860,  1866,  1935,
    1868,  1892,  1894,  1908,  1985,  2109,  1918,  1920,  1928,  1931,
    1953,  1954,  1959,  1966,  1967,  1968,  2149,  2000,  2001,  2004,
    2009,  2014,  2021,  2026,  2027,  2029,  2035,  2064,  2066,  2082,
    2093,  2095,  2096,  2100,  2105,  2106,  2110,  2112,  2113,  2128,
    2133,  2135,  2139,  2141,  2145,  1995,  2144,  1835,  1837,  1840,
    1844,  1854,  1878,  1896,  1897,  1899,  1910,  1941,  1944,  1984,
    1990,  2003,  2007,  2142,  2143,  2044,  2063,  2069,  2081,  2083,
    2102,  2107,  2117,  2127,  1849,  1843,  1848,  1865,  1915,  1958,
    1971,  1972,  2032,  2034,  2116,  1991,  1948,  2015,  1864,  1911,
    1921,  1986,  1969,  2016,  1855,  1977,  1982,  2115,  2033,     0,
    1827,  1830,  1831,   704,     0,     0,     0,   693,   727,   727,
     724,     0,     0,   728,     0,    26,   692,   695,     0,   702,
     698,   942,   932,  1792,  1793,  1783,  1783,  1386,     0,     0,
    1695,     0,     0,  1370,     0,     0,  1371,  1414,     0,     0,
    1415,     0,     0,  1734,     0,  1384,     0,  1433,  1432,  1431,
    1429,  1430,  1428,  1426,  1423,  1513,  1512,  1424,  1425,  1434,
    1716,  1427,  1799,  1798,  1797,  1435,  2268,  2268,   603,   594,
     585,     0,   589,  2268,   927,   176,     0,   337,   219,     0,
       0,  1675,  1673,  1674,  1670,  1672,  1669,  1671,   529,     0,
     528,     0,   515,   528,     0,   508,   507,     0,     0,     0,
     561,   560,   173,  1746,  1745,  1683,  1681,  1682,  1678,  1680,
    1677,  1679,  1656,     0,  1734,     0,     0,  1581,     0,     0,
    1752,  1750,  1751,  1581,  1581,  1581,  1581,  1753,     0,     0,
       0,  1530,  1724,     0,  1741,     0,     0,     0,     0,  1808,
    1809,  1810,  1811,  1812,  1813,  1756,     0,     0,     0,     0,
     458,   457,     0,     0,   186,   228,   209,  1247,   176,  1235,
       0,     0,     0,     0,     0,     0,  1487,  1486,  1485,  1347,
       0,  1353,  1349,  1351,  1342,     0,  1590,  1339,  1335,  1309,
    1308,     0,  1334,  1330,     0,  1326,  1324,     0,  1633,     0,
    1636,  1638,   660,     0,   659,  1625,     0,  1628,  1630,  2258,
    2255,     0,     0,  1276,   484,   358,  1297,     0,     0,  1273,
    1027,  1106,  1107,  1104,  1100,  1104,     0,   918,     0,     0,
     634,     0,     0,     0,  1006,  1004,   718,   719,     0,   723,
       0,     0,  2239,  2247,   762,     0,   142,     0,  1016,  1023,
       0,     0,  1031,  2220,  2233,     0,  2231,  1420,  2223,  2222,
       0,     0,     0,  1037,   353,     0,     0,     0,     0,    24,
    1073,  1074,   579,     0,     0,     0,   797,   798,  1042,   992,
     990,   831,   431,     0,  1083,   773,   777,   774,   778,   381,
       0,  1168,  1257,  1172,  1157,  1152,     0,     0,  1153,  2268,
       0,     0,     0,     0,     0,     0,     0,    64,    93,     0,
       0,   118,   113,     0,   108,     0,   115,   109,   904,   896,
     902,     0,  1140,     0,  1142,  1144,     0,     0,   975,     0,
       0,     0,     0,  1093,  1261,     0,     0,  1826,  1828,  2268,
     675,   680,   683,   696,   694,   653,     0,   751,   749,   747,
     745,   755,   753,     0,     0,   743,   793,   741,   726,   737,
     735,   791,   767,     0,   729,   739,   985,   981,     0,     0,
       0,     0,   701,     0,     0,     0,     0,     0,     0,     0,
    1641,     0,  1508,  1509,  1804,  1466,  1530,     0,     0,     0,
    1802,     0,  1446,  1441,  1440,  1453,  1452,  1457,  1457,  1455,
    1456,  1447,  1442,     0,     0,  1448,  1449,  1717,  2151,     0,
       0,     0,   591,   593,     0,     0,   606,   598,   600,     0,
     595,   596,     0,     0,   614,   616,     0,     0,   612,   929,
     868,   218,     0,   642,   644,   639,     0,     0,   528,   517,
       0,   512,     0,     0,   528,   528,   558,   557,     0,     0,
    1773,  1657,     0,     0,  1748,  1583,  1584,  1582,     0,  1777,
       0,     0,     0,     0,     0,     0,     0,  1739,     0,  1519,
    1520,  1522,  1525,     0,  1531,  1532,     0,     0,  1581,  1726,
    1720,  1742,  1758,  1759,  1757,  1755,     0,     0,     0,  2227,
     454,   490,     0,   230,  1203,   891,  1181,     0,     0,     0,
       0,  1347,     0,     0,     0,  1343,     0,     0,     0,  1337,
    1621,  1619,  1588,  1600,  1602,  1606,  1608,  1599,  1593,  1598,
    1612,  1591,  1620,  1596,  1611,  1597,  1618,  1610,  1493,  1585,
    1586,  1587,     0,  1332,  1328,     0,     0,  1316,     0,     0,
     658,     0,     0,     0,  2254,     0,     4,     8,    10,     0,
     484,   427,     0,     0,     0,  1024,  1102,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,   717,     0,     0,   159,
     157,     0,     0,   139,     0,   149,   155,   727,   144,   146,
       0,  1021,  1032,  1033,     0,     0,  2229,   429,     0,  2210,
    2211,  1036,     0,     0,  1034,   352,   357,   636,   351,     0,
     354,   359,     0,   484,  1392,   627,   625,     0,   800,  1082,
    1084,     0,   382,  1161,  1159,     0,  1171,  1155,     0,     0,
    1252,     0,     0,     0,   101,     0,     0,    75,    81,    71,
    2268,  2268,   111,   106,   120,   116,     0,   110,   794,   905,
     653,  2268,   895,   894,   903,  1026,     0,     0,   973,   974,
     968,   994,   484,  1099,  1095,  1096,  1098,  2148,  2150,   705,
     699,   697,     0,    24,     0,  2268,  2268,  2268,  2268,  2268,
    2268,   757,   731,   759,   733,  2268,  2268,  2268,  2268,     0,
     725,   730,  2268,   653,   789,   787,   790,   788,     0,     0,
      46,    44,    41,    35,    39,    43,    38,    31,    40,     0,
      34,    37,    32,    42,    33,    45,    36,     0,    29,    47,
     781,     0,   703,  1784,     0,  1782,  1734,  1780,  1721,  1722,
    1714,  1700,  1715,     0,     0,     0,  1069,  1507,  1510,     0,
       0,     0,  1404,  1376,  1807,  1806,  1805,     0,     0,     0,
    1451,  1454,     0,     0,     0,     0,     0,  1399,     0,  1398,
       0,  1400,  1395,  1396,  1397,  1388,  1389,     0,     0,     0,
     605,   610,     0,     0,  2268,  2268,   583,   597,   620,   608,
     622,  2268,  2268,   618,   602,   613,   860,   338,     0,   528,
       0,   516,   528,     0,   528,   528,   510,   509,  1690,  1688,
    1689,  1685,  1687,  1684,  1686,  1658,     0,     0,     0,     0,
    1774,     0,     0,     0,  1772,     0,     0,     0,     0,  1754,
    1771,     0,  1523,     0,  1650,  1526,     0,     0,     0,     0,
    1518,  1536,  1538,  1540,  1580,  1579,  1578,  1542,  1558,     0,
    1533,  1534,  1729,  1299,     0,     0,     0,  1819,     0,  1823,
     212,     0,  1229,  1248,   860,     0,  1236,  1229,     0,  1642,
       0,  1475,     0,  1478,  1645,     0,  1483,     0,     0,  1344,
    1345,     0,     0,  1348,  1350,  1352,     0,  1336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1491,  1490,
    1489,     0,  1494,  1495,     0,  1331,     0,  1325,  1327,  1637,
       0,  1639,  1629,     0,  1631,  2256,  1305,     0,  1301,     0,
       0,  1306,   875,     0,     0,     0,     0,     0,  1363,  2261,
    2260,   635,     0,     0,    48,     0,   720,   722,   721,  1364,
     727,  2268,  2268,   151,   661,   161,   153,   163,   143,   150,
    2268,     0,     0,     0,     0,     0,  2232,     0,     0,     0,
       0,     0,     0,  1075,     0,  1393,   577,     0,   799,  1080,
       0,  1258,  1259,  2237,     0,    93,     0,    65,     0,     0,
       0,    78,     0,    93,    93,   119,   114,  2268,  2268,   104,
       0,   906,   900,   908,   907,   897,   573,   955,     0,     0,
       0,   707,   686,   700,   654,   768,     0,   752,   750,   748,
     746,   756,   754,     0,  2268,     0,  2268,   744,   742,   738,
     736,   792,   740,    24,   782,     0,     0,     0,    27,     0,
    1787,     0,  1701,     0,     0,  1713,  1696,  1712,  1511,     0,
    1468,     0,  1403,     0,     0,  1803,     0,  1800,     0,  1459,
    1463,  1439,  1461,  1464,     0,  1450,  1718,     0,     0,     0,
       0,     0,     0,  2152,  1402,  1401,  1390,  1385,  1387,  1438,
       0,     0,   607,   604,   599,   601,     0,  2268,  2268,   615,
     617,  2268,  2268,     0,  1676,   518,     0,   522,     0,     0,
     514,   513,     0,     0,     0,     0,     0,     0,  1770,  1778,
    1766,  1767,  1768,  1769,  1527,     0,  1521,  1541,  1545,     0,
    1558,  1544,     0,     0,  1559,  1574,  1571,  1572,  1569,  1577,
    1576,  1570,  1573,     0,     0,     0,     0,     0,  1575,     0,
       0,     0,  1515,  1516,  1743,     0,  1535,  1529,  1300,  1727,
    1409,  1405,  1406,  1411,  1410,  1725,  1299,     0,     0,  1227,
    1228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1226,     0,     0,  1214,  1215,  1216,  1213,  1218,
    1219,  1220,  1217,  1204,  1195,     0,     0,  1251,     0,  2268,
       0,  1190,     0,     0,     0,     0,     0,     0,     0,  1182,
    1183,     0,  1114,  1646,     0,  1647,     0,     0,     0,     0,
    1482,  1481,  1347,  1480,  1472,  1338,  1622,     0,     0,     0,
       0,     0,     0,  1623,  1615,     0,     0,     0,  1615,  1651,
    1488,  1501,  1506,     0,  1503,  1500,  1502,     0,  1504,  1492,
    1496,  1497,  1347,  1333,  1329,     0,     0,  1304,  1303,     0,
    1288,     9,     0,  1278,   876,  1111,   364,  1278,     0,     0,
    2252,     0,     0,  1007,    49,     0,   779,   160,   158,     0,
    2268,     0,     0,     0,  2268,   156,   145,     0,   148,   147,
       0,  1013,  1017,     0,  2214,  2213,  2212,     0,     0,   356,
       0,   580,     0,  2268,   801,     0,   653,  1162,     0,  1253,
      70,     0,     0,   102,    68,    93,    76,    82,     0,   121,
     117,   795,  2268,   910,   653,   909,     0,   570,     0,   825,
     826,   824,  1097,   710,   708,     0,   690,   687,     0,   758,
     732,   760,   734,   769,   785,   786,   783,   784,    30,    28,
       0,  1781,  1730,  1702,  1698,  1697,     0,  1467,  1734,  1470,
       0,  1378,  1373,  1372,  1375,     0,     0,  1458,     0,     0,
    1730,     0,     0,  2189,  2187,     0,     0,  2171,  2186,     0,
       0,  2188,     0,     0,     0,     0,     0,  2225,  2185,  2177,
    2204,  2205,     0,  2169,  2172,  2173,  2184,  2176,  2206,     0,
    2162,  2161,  2165,  2167,     0,  2160,     0,  2163,  2154,     0,
       0,   611,   609,   621,   623,   619,     0,     0,   528,     0,
     528,   528,     0,  1733,     0,  1658,     0,     0,     0,  1524,
    1543,  1537,  1539,  1546,  1548,  1546,     0,  1553,  1546,     0,
    1551,  1546,     0,  1561,  1560,     0,  1562,     0,  1514,     0,
    1413,  1412,  1408,  1728,     0,   235,  1221,  1222,  1223,  1225,
    1208,  1206,  1205,  1209,  1210,  1207,  1224,  1211,  1212,  1196,
    1000,  1231,   997,     0,     0,  1249,     0,  1194,  1193,  1188,
    1186,  1185,  1189,  1187,  1191,  1192,  1184,  1237,     0,  1473,
    1479,  1649,  1642,  1484,  1346,  1589,  1601,     0,  1603,  1605,
       0,  1607,     0,     0,     0,  1613,  1592,  1617,     0,  1474,
    1476,     0,  1498,  1499,  1640,  1632,  1302,     0,     0,  1294,
    1289,  1290,  1307,     0,  1285,  1286,     0,     0,  1299,  1279,
    1280,     0,    24,  1274,     0,     0,  1030,     0,    50,  1010,
       0,    24,   162,   152,     0,   663,   665,   164,   154,   779,
       0,  2230,  1039,     0,   355,  1394,     0,  1081,    24,     0,
       0,    66,     0,    79,    88,     0,    72,   901,   898,   574,
    2268,   969,     0,  2268,   706,   685,   691,   653,  1791,     0,
    1789,     0,     0,  1703,  1699,  1469,     0,  1471,  1465,     0,
    1377,     0,  1801,  1460,  1462,  1437,     0,  2175,  2174,     0,
       0,  1581,     0,  1581,  1581,  1581,  1581,  2178,     0,     0,
    2158,     0,     0,     0,     0,  2191,  2159,     0,     0,     0,
       0,     0,     0,  2153,  1391,  1443,   870,   869,   339,   519,
       0,     0,   524,   523,  1691,  1814,  1817,  1815,  1528,     0,
    1565,  1567,     0,  1554,  1557,  1556,  1564,     0,  1566,  1546,
       0,  1517,  1407,  1822,   213,  1002,  1001,   999,     0,  1230,
    1115,  1119,  1121,     0,  1125,     0,  1123,  1127,  1116,  1117,
       0,   892,     0,     0,  1643,  1648,     0,     0,  1624,  1616,
    1594,     0,  1595,     0,     0,  1292,  1287,  1293,  1291,  1284,
    1283,  1282,  1277,  1281,   365,   362,     0,  1028,     0,     0,
       0,  1009,   780,   140,   662,    24,  1019,  1038,   578,  1078,
      67,  1254,    84,     0,     0,    77,    88,    88,  2268,   571,
       0,     0,   709,   770,     0,  1788,  1731,  1724,     0,  1379,
       0,  1724,  2202,     0,     0,  2207,     0,     0,     0,     0,
       0,     0,     0,     0,  2170,  2193,  2194,  2192,  2190,  2168,
       0,  2164,  2166,  2155,  2156,  1444,     0,  1436,   528,   528,
    1547,  1779,  1549,     0,  1552,  1550,  1568,     0,   998,  2268,
    2268,  1129,  2268,  1131,  2268,  2268,  1118,  1250,  1238,     0,
    1604,     0,  1614,     0,  1505,   367,  1029,  2251,     0,     0,
       0,     0,     0,     0,    55,     0,    54,     0,    52,     0,
       0,   141,  1085,    88,    93,    88,    89,    83,    73,   899,
       0,     0,   711,    24,  1790,  1723,  1732,  1383,     0,  1380,
    1382,  1704,  2203,     0,     0,  2201,     0,     0,     0,     0,
       0,  2179,  2200,     0,  1445,   521,   520,  1555,  1563,  1120,
    1122,  2268,  1126,  2268,  1124,  1128,  1644,  1609,  1477,   369,
     374,   372,   363,     0,   370,   376,    57,    62,    59,    61,
      58,    60,    56,     0,    51,     0,   664,   666,  1089,  1079,
       0,  1087,  1255,    85,    80,   572,   970,  2268,   771,     0,
    1374,     0,  1705,  1719,  2199,  2208,  2195,  2196,  2197,  2198,
       0,  2180,     0,     0,  1130,  1132,  2268,  2268,   368,   371,
    2268,    53,     0,  2268,  1086,  1088,     0,   707,  1381,     0,
    1709,  1706,  1707,     0,     0,  2157,   375,   373,   377,     0,
    1090,    86,   712,     0,     0,     0,  2182,     0,  2181,  1011,
      90,     0,  1710,  1708,     0,    92,     0,    87,     0,  2183,
      91,  1711
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   826,   827,   828,   829,  1050,  2426,  2427,   179,   320,
     180,  1415,  1416,  2249,  2587,  3636,  3113,  3114,  3539,  3637,
    3638,   830,  1191,  3151,  2844,  3557,  2188,  2842,  3404,  3155,
    3553,  2843,  3405,  3644,  3746,  3770,  3555,  3777,   648,   649,
     650,  1539,  2503,   831,  1550,  1196,  1548,  2196,  2513,  2193,
    2511,  2516,  2848,  1549,  2510,  2197,  2847,   832,     9,    28,
      29,    30,    31,    32,   834,  1113,  2126,  1441,  2453,  2457,
    2458,  2454,  2455,  3120,  3124,  2810,  2802,  2801,  2803,  2806,
     494,   270,   601,   835,    55,    56,    11,    41,   113,    70,
      71,    72,    73,   195,   334,    74,    75,   241,   339,   227,
    1013,   518,  3008,   370,   936,  2312,   398,   399,   228,   352,
     341,   347,  1360,  1361,   117,   536,   118,   119,   358,   229,
     354,   340,   342,   520,   230,   255,   574,   243,   246,   244,
     245,   380,   552,   553,   555,   560,   939,   247,   248,   389,
     557,   191,    12,    51,   149,   150,   151,   945,  2943,   152,
     251,   239,   392,   393,   394,   395,  2149,   836,   837,   838,
     839,  1071,  3625,  3372,  1417,  3692,  3693,  3694,  3737,  3736,
    3740,   840,   841,   842,   843,   844,   845,   846,  1061,   495,
    1066,  1409,  1410,  1457,  1166,  1458,   297,   298,   299,   300,
     301,   452,   496,  1343,   497,   498,   499,   500,   501,   502,
     503,   990,   181,   512,  1000,  1002,  2042,   182,   506,   996,
     505,   995,   508,   998,   507,   997,   954,   968,   302,   303,
     184,   304,   419,   420,   421,   422,   404,   424,   847,  3410,
    3650,  3167,   848,  1133,  2152,  3143,  2484,    87,   236,   546,
    1959,  1259,  1260,  1261,  1956,  1957,  2299,  2300,  2301,  2644,
    2645,  1960,  1961,  2295,  2648,  2640,  2307,  2308,  2651,  2652,
    2941,  2937,  2938,   849,  1469,    57,  2111,  2112,  2478,   405,
     426,  1105,  1171,  1042,  1093,  1076,  1115,  2543,   185,  1043,
    1033,  2083,  2805,    59,   305,   850,  1201,   851,  1214,  1215,
     852,   853,   854,   855,  1222,  3176,  1243,  3415,  1244,  2223,
    1245,  2540,  1246,  2862,  1247,  2252,   856,  2219,  2861,  3175,
    3413,  3412,  3717,    88,    13,   857,  1435,  2116,  2117,  2118,
    2242,  1904,  2243,  2244,  2874,  2876,  2558,  2557,  2562,  2556,
    2555,  2548,  2547,  2546,  2545,  2550,  2549,  2552,  2554,   858,
     859,  1111,   860,  1900,  1229,  3653,   861,  1517,  3381,  2589,
    2590,  2245,  2559,  2519,  2850,  1160,  1497,  2156,  2487,  2157,
    1493,   862,   863,  1207,  2211,  3171,   864,   865,   866,   867,
      14,    45,    15,    16,    17,    89,    90,   868,    91,    18,
     927,    19,    92,    93,   129,   548,  1965,  2656,  3467,    94,
     125,   363,   869,  2783,    20,    21,    22,    23,    24,    40,
      62,    95,   677,  2048,  2724,   870,  1202,  2523,  2200,  2521,
    3558,  3162,  2201,  2520,  2853,  3164,   871,   872,   873,  1087,
    1088,  1553,    96,   237,   547,   930,   931,  1263,  1963,   874,
    1248,  1249,   875,  1912,  1250,   306,    64,    65,    66,    67,
    1560,   155,   109,    68,   106,   187,   188,  1561,  1562,  2530,
    1563,   674,   675,  1231,   676,  1232,  1164,  1165,  1564,  1565,
    1413,  3311,  3312,  3497,  1103,  1104,   876,  1430,  3541,   877,
    3132,   878,  1445,  1446,  1447,  2132,  2130,   879,   880,  2435,
    2464,   881,  2143,  2474,   882,  1161,  1162,   883,  1026,   884,
    2600,   885,  3642,  3146,   886,  2491,  3709,  3710,  3711,  3743,
    1168,   887,  1566,  2213,  2534,  2535,   888,  1423,  2103,  1041,
    1402,   889,   890,   891,  2726,  3315,  3508,  3509,  3609,  3610,
    3614,  3612,  3615,  3681,  3683,   892,   893,  1555,  2205,   894,
    1557,  1528,  1529,  1530,  2178,   895,  1181,   896,   897,  2171,
    1525,  1177,   194,  1531,  1532,   307,  2727,  3049,  3050,  3033,
    1058,  1059,  2722,  3034,  3037,    97,   124,   540,  1370,  2376,
    3051,  3512,   434,   898,  1175,    98,   121,   537,  1367,  2374,
    3038,  3510,  2723,  1195,  2835,  3400,  3643,  2173,   899,   900,
     901,   902,   903,  1074,  2433,  1052,  2429,  3368,  3369,  3370,
    3525,  3359,  3360,  3361,   904,  2999,  2777,  2778,  2780,  2067,
     905,   906,  1379,  1380,  1381,  2076,  2415,  1382,  2412,  2073,
    1383,  2388,  2068,  1384,  1385,  1386,  2380,  2385,  1387,  2062,
    2063,   907,  1083,  1063,   908,  1937,  1938,  2267,  3203,  3431,
    2904,  3200,  3658,  3659,  1939,  2289,  1918,  2636,  2927,  3249,
    2826,  3142,  2637,  1940,  1941,  2359,  3001,  3002,  3003,  3292,
    1942,  1943,  1454,   909,  1120,   910,  1256,  1944,  1945,  2283,
    3597,  2284,  2285,  2286,  2620,  2908,  2911,  2912,  1946,  2610,
    2899,  3428,  2056,  2057,  3088,  2730,  3349,  2731,  2058,  2735,
    2069,  2762,  2070,  2763,  3089,  3090,  3091,  3092,  1947,  2261,
    2262,  2607,  1948,  2996,  2710,  2992,  2354,  2021,  2349,  2350,
    2351,  2965,  2022,  2355,  2711,  2997,  2700,  2701,  2702,  2703,
    2704,  3480,  3273,  3600,  2705,  3482,  3483,  2990,  2706,  2991,
    2707,  2338,  2408,  2409,  2410,  3343,  2411,  3067,  3074,  3519,
    2732,  1030,  2913,  3055,  3242,  2734,  2695,  1316,   308,  1317,
    2002,   445,   955,  1978,  2003,  2675,    39,   911,   912,  3195,
    3424,  2892,  3423,  3723,  3751,  3752,  2896,  2601,  1949,  2602,
    2625,  3210,   604,  2597,  2598,  2360,  2713,  3422,  3199,  1318,
     975,  1319,  1320,  2993,  2708,  1322,  1323,  2340,  3602,   913,
     914,  2254,  2599,  3191,  3419,  3420,  1915,   915,  1069,  1951,
    1952,  2271,  2906,  1953,  1954,  2616,  2035,  2333,  1324,  1325,
    1326,  1327,   916,  1210,  1889,  1890,  1891,  2215,  1892,  2216,
    1955,  2626,  3248,  3463,  2923,  3245,  3246,  3247,  3244,  3232,
    3233,  3234,  3235,  3236,  3237,  3576,   917,  2141,  2469,  2470,
    1121,  1328,  1329,  1123,  1124,  1125,  1330,  1126,  1452,  2135,
    2136,    25,   919,  1183,  2179,  1438,  1519,   920,   921,  2794,
     922,  2424,  1046,  2090,   923,   924,    35,   541,   542,   543,
     544,   545,   925
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -3133
static const short yypact[] =
{
     538,   936, -3133,   336,   336,  1189, -3133, -3133,  1189, -3133,
      -9, -3133, -3133, -3133,   497, -3133,   538, -3133, -3133, -3133,
   -3133, -3133,   -60, -3133, -3133, -3133, -3133, -3133,   472,   520,
   -3133,   494, -3133, -3133, -3133, -3133, -3133, -3133,   -77, -3133,
     979,   587, -3133, -3133, -3133,   132, -3133, -3133, -3133, -3133,
   -3133,   217,   336, -3133,   336,   631,    -9, -3133,   598, -3133,
   -3133, -3133, -3133, -3133, -3133,   413,   276, -3133, -3133, -3133,
     996,   639,   336, -3133, -3133,  1033,   336, -3133, -3133,   336,
     336, -3133, -3133, -3133,   336,   336, -3133, -3133, -3133, -3133,
     132, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
    5215, -3133,   276, -3133,   475,  4720, -3133, -3133,   563, -3133,
   -3133,  1069,   587,   519, -3133, -3133, -3133, -3133, -3133, 10023,
   -3133,   336,   620,   997,   336,    -9, -3133, -3133, -3133,   336,
   -3133, -3133,   821,   721,  1127, -3133, -3133,   772, -3133,   778,
   -3133,   708, -3133, -3133,   782, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133,   793, -3133, -3133, -3133,   826,
     832,   946,   950,   961,   983,  1012,  1031,  1044,  1064,  1074,
    4720,  1081,  5149,  1092,  1097,  1101,  1109,  1112,  1131,  1664,
    1342, -3133, -3133, -3133, -3133,   -82, -3133,   159, -3133,  4720,
   -3133,   193, -3133, -3133, -3133,   184, -3133, -3133, -3133,   883,
   -3133, -3133, -3133, -3133, -3133, -3133,   821,  1141,  1146,  1153,
   -3133,  1127, -3133, -3133,  1175, -3133,  1180, -3133,  1136, -3133,
   -3133,  1190, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133,  1212,  1640,   336,  1226, -3133,    -9,    -9,  1227,   336,
   -3133,   476,  1663, -3133,  1053,  1182, -3133,  1063,  1194,  1716,
    1717,   336,  1723,  1727, -3133,  1087, -3133,   277,    63,    63,
      63,    63,    63,  5149,  1594,  1296,    67,  5149,   578,  5149,
   -3133,  5149,  5149,  5149, -3133, -3133, -3133,  1199,  1284,  1288,
    5149,  1359,  1299, -3133,  5149,  5149,  1302, -3133,  1304, -3133,
    1097,  1306,  1307,  1311,  1313,  1765,  9107, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  1327, -3133, -3133, -3133,
   -3133, -3133, -3133,   277,   277, -3133, -3133, -3133, -3133, -3133,
    4720, -3133, -3133,   336,  4720,  1291,   216, -3133, -3133, -3133,
   -3133,  1779, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
    1324, -3133,  1324,   476,  1789,  1790,  1791, -3133, -3133, -3133,
    1793,  1796,   587,  1723,  1324,  1798,  1155, -3133,  1721, -3133,
    1382,  1346, -3133,  1419, -3133, -3133, -3133,  1166, -3133, -3133,
    1813,  1395, -3133,  1360, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133,  1194,  1360, -3133, -3133, -3133, -3133, -3133, -3133,  1363,
     165,   171,   295, -3133,  1617, -3133, -3133, -3133,  1369,  1836,
     196, -3133,  1403,  1368,   201, -3133,  -197,  1407,  1408,   219,
     241,  8085,  1409,  1414,    84,  1207, -3133, -3133,    88,  1416,
   -3133, -3133, -3133, -3133,   344, -3133, -3133,  8172, -3133,  7846,
    9169,  2431,  2431,  5149, -3133,  1334,  5149,  9107,  1381, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  1191,  1845,  8193,  9107,
    1334,  1846,   178,  5149,  5149,  5149,  5149, -3133,  5149,  5149,
    5149,  5149,  5149,  5149,  5149,  5149,  5149,  5149,  5149,  5149,
    5149,  5149,  5149,  5149,  5149, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133,  5149,  5149, -3133, -3133,  1386,
    5149, -3133,  5149,  1387, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133,   277,  5149,  5149,  5149,  5149,  1425,
    1868,  1664,  4018,  1404, -3133,  4720,  1365, -3133,  1204,  1861,
   -3133,  1218, -3133,  1864,  1449,  1462,   346,  1597,   381,   386,
     471,  1431, -3133,   454, -3133, -3133, -3133,   336, -3133, -3133,
     336,  1495, -3133,  5629,   519,  7462,  1884,   499,   336,  1895,
     -63, -3133, -3133,  1182,  1891, -3133, -3133, -3133, -3133,  1894,
   -3133,  1898, -3133,  1901, -3133,   336, -3133,   336, -3133, -3133,
    1723,  1907, -3133, -3133, -3133, -3133,   336,    63, -3133,  4720,
      60, -3133, -3133, -3133, -3133, -3133,  1359,  1359,  1910,  -179,
    1359,  1255, -3133,  1911,  1298,  1392, -3133,    67, -3133, -3133,
   -3133,  1494,  9107,  -152,  1496,  8262,  1914,  1359,  1497, -3133,
    1509,  1511, -3133,  8286,  8733,  8803,  8841,  9379,  9444,  9169,
    9606,  3730,  9556,  9718,  9774,  4269,  2440,  9831,  2431,  2431,
    3194,  3194,  2003,  9107,  8895,  9003,  1334,  9107,  9057,  1334,
   -3133,  9107,  9107,  9107,  9107, -3133,  1924, -3133, -3133,  1952,
   -3133,  9107, -3133,   223,  4720, -3133,  1513,  1941,   -63, -3133,
   -3133,  1939, -3133,  1486,  1945, -3133,  1953, -3133, -3133, -3133,
    1954, -3133, -3133,  1312,  1536,  1981, -3133,   336,  1547, -3133,
   -3133, -3133,   277,   277,   277,   336,   882,   336,  1424,   200,
     200,  1505,   336,   336,   200,   200,   336, -3133,  1424, -3133,
   -3133,   336, -3133,  1086, -3133, -3133, -3133,   200, -3133, -3133,
   -3133, -3133,   336, -3133, -3133, -3133, -3133,   173,   173,  5149,
   -3133, -3133, -3133,  1505,  1505, -3133, -3133,   200, -3133, -3133,
     200, -3133, -3133,   336, -3133, -3133,   200, -3133, -3133,   277,
     200, -3133, -3133,  5149,   200,   277,   336,   277,   200, -3133,
   -3133,   198,   200,   200,   198,   200,   336,   198,   200, -3133,
     200,   200,   200, -3133,  1424, -3133, -3133,   277,   200, -3133,
   -3133,   200,    48,   336, -3133,  1505, -3133, -3133,   200,   926,
   -3133, -3133,   277,  1317, -3133,   200, -3133,  4263,   277,  5149,
      63,    63,   200, -3133, -3133,   882,   277,  1007, -3133,  5149,
   -3133,   675,  5149,   200,   101, -3133,  5149,   200,  1968,   277,
   -3133,   200,  5149, -3133,  5149,   173,   336,   200,   336,    63,
     200,   336,    63, -3133,   336,   189, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133,   234, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133,  1124, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133,   604,   336, -3133,
     614, -3133,  1553, -3133, -3133, -3133,  1647, -3133, -3133,  1561,
    1562,  1563,  1573, -3133, -3133,  1345,  2016,  1581,  1589, -3133,
     403, -3133,  1556, -3133, -3133,  1370, -3133,   271,  1359,  2023,
   -3133,  1608,  -136, -3133,  2028, -3133,  1415, -3133, -3133, -3133,
    1383, -3133, -3133, -3133, -3133,  9992, -3133,  1199,  1613, -3133,
    1199, -3133,  1199,  1199,  1199,  1199,  1199,  2036,  2038,  2039,
    5149,  1620,  2044,  5149,  1628,  1631,  1633,  1634,  1635,  1636,
    1639,  4018,  4018, -3133,   366, -3133, -3133, -3133,  1715,  1641,
   -3133,  1648,  1649,  1422,  1652,   336, -3133,   336,  1653, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133,   483,  1430,   603,
    1075,  1621, -3133, -3133, -3133, -3133,  1432,   736, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  2097,  1433, -3133, -3133,
    1637, -3133,  1505, -3133,  1583,   166, -3133, -3133, -3133,  1554,
   -3133,  9107, -3133, -3133,  1465, -3133, -3133,  4419, -3133, -3133,
   -3133,   277, -3133, -3133,  1505, -3133,   -24, -3133, -3133,  1795,
   -3133,   134, -3133,  1605, -3133, -3133, -3133, -3133,  2112, -3133,
   -3133,   488, -3133,  1450, -3133,  1451,  2112, -3133,  1474, -3133,
   -3133, -3133,  1651,   112, -3133,  1615, -3133,  1418, -3133, -3133,
   -3133, -3133,  1420,   834, -3133,  -212, -3133,  1460,  1534,  1624,
    1750,  1473, -3133, -3133,  1466, -3133, -3133,  5149,   119,  1066,
    5149, -3133,   129,   200, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,    40,    40,    40, -3133,    40,  2408,    40,
      40,  1493,   -24,  1493,  1493,  1111,  1111,  1493,  1493,   -24,
   -3133,  2136, -3133,  1672,   229, -3133,  2141, -3133,   -24,    97,
      54, -3133, -3133,  5149, -3133, -3133, -3133,   822, -3133, -3133,
     519,  5149, -3133,  5149,  1671,  1677,  1681,  1686,  1542,  1689,
    1007, -3133,  1755,  1072,  1535, -3133,  1545, -3133, -3133,   336,
   -3133, -3133,  1123, -3133,  2168, -3133,  2164,   336, -3133,   589,
    6780,  1564, -3133, -3133,  2174, -3133,  1478,  2174,  2183,  1482,
    2174,  2183,  5149,  2174, -3133, -3133,   166,   277, -3133, -3133,
    1720,   284, -3133, -3133,  1729,   277,  5149,  1733, -3133, -3133,
    2171,  2172,  2081, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133,  1129,  1129,   200,   200,   200,  3482, -3133, -3133,  2057,
     604, -3133, -3133,   662, -3133, -3133, -3133,  1693, -3133, -3133,
   -3133, -3133,  5215,  1723, -3133, -3133,  1546,   336,  1411,  2195,
     -69,  1359, -3133,   -35,  1359,  1359,  1560,  1586,  1582, -3133,
    5297,  5297, -3133,  1460, -3133, -3133, -3133, -3133,  1469, -3133,
    1308,  1740, -3133,  1741,  1751,  1753, -3133,  1753,  1753,  1754,
    1756,  1759,  1761,   336,   549, -3133, -3133, -3133, -3133,   126,
   -3133,    79,  2175, -3133, -3133,  1469, -3133,  1469,  1772, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133,  9107,   455, -3133, -3133,   458, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133,  1719, -3133, -3133,
     459, -3133, -3133, -3133, -3133, -3133, -3133,    -9, -3133, -3133,
      -9,   929,   146,  2201, -3133, -3133,   608,   185,   632,  2227,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   336,  1604,
     336, -3133, -3133,  1665,   336,  1675,   336,   336,  1505,  1591,
    1764, -3133,  1766,    92, -3133, -3133, -3133,  1505, -3133, -3133,
    2244, -3133, -3133,  1577,  1776, -3133, -3133, -3133,  1066, -3133,
    1145,  2208,  1145, -3133,  1007,   198,  5149,  5149,  5149,  1777,
   -3133, -3133,   277,   277,  1505,  1584,  1007,    63,  1549,    48,
     277, -3133,  1587,  5149,  1858, -3133, -3133,  1662,   336,  1460,
   -3133,  4720, -3133, -3133, -3133,   336,  1193,  2265, -3133, -3133,
    1606,   156,   166,   277, -3133, -3133,  2253,  2255, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  1106, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  4263,   277,   277, -3133,
    1111,  5149,   -44,  1096,  1162, -3133, -3133, -3133, -3133, -3133,
     103, -3133, -3133, -3133, -3133,  2066, -3133,  1838,   519,  5149,
   -3133,    90, -3133, -3133,   336,  2251,    63,    63, -3133,  1638,
   -3133,    67,  1607,   277, -3133,   336,   336,  5149,  -112, -3133,
    1650, -3133, -3133,   273, -3133,  1748, -3133,  1749,  5149,   735,
   -3133, -3133,  1614, -3133,  2280, -3133,  1690, -3133,   277, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,  6065,
   -3133, -3133, -3133, -3133,   336,    63,    63,   228,   284,  2085,
    1232,   277,   166, -3133,  1696, -3133, -3133,  2265,  2264,  1842,
   -3133, -3133, -3133, -3133, -3133,  1919,  1919, -3133,    96,  1699,
   -3133,   336,  1505, -3133,  1505,  1505, -3133, -3133,  1505,  1505,
   -3133,   336,  2037,  -152,  1505, -3133,  2037, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,   179,   179,   881,   655,
   -3133,   511, -3133,   662, -3133,    -9,  2271, -3133, -3133,  1258,
    1853,  1824, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   286,
    1359,  2275, -3133,  1359,  1701, -3133, -3133,  1862,  1865,  1702,
   -3133, -3133, -3133,  1616,  1616, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  1654,  -152,  1866, 10047,   524,  9992,  1792,
   -3133, -3133, -3133,   524,   524,   524,   524,  1643,  9992,  9992,
     140,  1738,   470,   336, -3133,  9992,  9992,  9992,  9992, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  1655,   -89,  1066,  5149,
   -3133, -3133,  1871,  2271, -3133, -3133, -3133, -3133,    -9, -3133,
    1835,  1843,  1847,   880,  1851,  1852, -3133, -3133, -3133,  2217,
     336, -3133,  2323, -3133, -3133,   612,  3069, -3133, -3133, -3133,
   -3133,   336, -3133, -3133,   612,  1622, -3133,   483, -3133,  1667,
   -3133,  1703, -3133,  1902,   276, -3133,  1676, -3133,  1711, -3133,
    1758,  1872,   336, -3133, -3133, -3133, -3133,  4419,   336, -3133,
    1692, -3133, -3133,  2208, -3133,  2208,  1694, -3133,  2343,  2361,
   -3133,  2363,  1742,  5149, -3133, -3133,  2366, -3133,  1707, -3133,
    1839,  1706,  2183, -3133, -3133,  1710,   850,   336, -3133, -3133,
    1896,   200,   780,  1466,  1664,   369, -3133, -3133, -3133, -3133,
    5149,  1505,  1066,  -268, -3133,   336,   336,  5149,    51,   -24,
    2378,  1456,  2379,  2364,  2371,  2408, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,   277,  2017, -3133, -3133, -3133, -3133,  2282,
    5149,   519,  2130, -3133, -3133, -3133,  5149,   173, -3133,  2022,
    2398,  2399,   466,   467,   336,  1964,  1007, -3133,  4018,  1928,
    1929, -3133, -3133,  2006, -3133,  5149,    -5, -3133,  1770, -3133,
   -3133,   388, -3133,  5149, -3133, -3133,  1762,   475, -3133,  1264,
     336,  2407,  2524, -3133, -3133,  1066,   277, -3133, -3133,   170,
   -3133,  2183,  2183,  1714, -3133,  1822,  1828, -3133, -3133, -3133,
   -3133, -3133, -3133,    63,    63, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  1396, -3133, -3133, -3133, -3133,    63,  2749,
    2422,  2403, -3133,  1007,   878,   177,   121,  2284,   -10,   882,
   -3133,    13, -3133, -3133, -3133,  1950,    41,  1505,    71,  1767,
   -3133,  1763, -3133, -3133, -3133, -3133, -3133,  1958,  1958, -3133,
   -3133, -3133, -3133,  1837,  1771,  2445, -3133, -3133, -3133,   492,
    1778,  1780, -3133, -3133,   277,   142, -3133, -3133, -3133,  1774,
     655, -3133,   336,   336, -3133, -3133,   336,   611, -3133, -3133,
   -3133, -3133,  1986, -3133, -3133, -3133,  2439,   487,  1359, -3133,
     505, -3133,  2021,  2026,  1359,  1359, -3133, -3133,  1480,  9992,
   -3133,   447,  2462,  2027,  2463, -3133, -3133, -3133,  9992, -3133,
     469,  9992,  9992,  9992,  9992,   336,   477, -3133,   210,  2468,
   -3133, -3133,   336,  9468, -3133,  2052,   336,  1806,   524,  2091,
   -3133, -3133, -3133, -3133, -3133, -3133,  1480,  2454,  1480, -3133,
    9107, -3133,  2004, -3133,  1969, -3133,  1973,   128,   128,   128,
     484,  2217,   128,  9468,   336, -3133,   486,   336,   491, -3133,
   -3133, -3133,  2007,  2008,  2009,  1469,  1469, -3133,  2011, -3133,
    2012,  2013,  2014,  2015, -3133, -3133, -3133, -3133,   998, -3133,
   -3133, -3133,   493, -3133, -3133,   504,   336, -3133,   336,  1708,
   -3133,   336,  1713,  5149, -3133,   336,  2481, -3133, -3133,   612,
   -3133, -3133,  1830,   612,   111, -3133, -3133, -3133,  1007,  5149,
    5149,  5149,  4677,  2493,  1505,    73, -3133,  1007,   336, -3133,
   -3133,   336,   336, -3133,   886, -3133, -3133,   289, -3133,  1840,
    5149, -3133, -3133, -3133,  2501,  4720,  2002, -3133,  1844,  2508,
   -3133, -3133,  1007,  1888, -3133, -3133, -3133, -3133, -3133,   336,
    2183, -3133,   166, -3133,  1912, -3133, -3133,   510, -3133, -3133,
   -3133,   277, -3133,  7921, -3133,  1181, -3133, -3133,  2139,  2495,
   -3133,  2122,  2123,  2018,  1854,  2124,  2043, -3133, -3133, -3133,
     -22,  2116, -3133, -3133, -3133, -3133,  2006, -3133, -3133, -3133,
     251,   819, -3133, -3133, -3133,  2265,  5149,  2049, -3133,  2024,
   -3133, -3133, -3133, -3133,  2526, -3133, -3133, -3133,  2527, -3133,
    1832, -3133,  2511,   -24,   336,  1625,  1625,  1625,  1625,  1625,
    1625, -3133,  2534, -3133,  2535,  1625,  1625,  1625,  1625,  1106,
   -3133, -3133,  1625,   104, -3133, -3133, -3133, -3133,  2520,  2532,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,  2533,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133,   518, -3133, -3133,
   -3133,  2528, -3133, -3133,  1505, -3133,  -152, -3133, -3133, -3133,
   -3133, -3133, -3133,  1906,  1909,   107, -3133,    13, -3133,   128,
    1886,   200, -3133,  2074, -3133, -3133, -3133,   336,   336,   128,
   -3133, -3133,   151,  1505,  1718,  9992,   267, -3133,  5149, -3133,
    5149, -3133, -3133, -3133, -3133, -3133,  1959,   200,   151,  1505,
    2552, -3133,   277,   336,   690,   690, -3133, -3133,  2553, -3133,
    2553,   629,   629,  2553, -3133, -3133,  1884, -3133,  2117,  1359,
    2539, -3133,  1359,  1726,  1359,  1359, -3133, -3133,  2086, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,   126,  1469,  1893,  1469,
   -3133,  1469,  2125,  9992, -3133,  2126,  2127,  2128,  2137, -3133,
   -3133,   140, -3133,   140, -3133, -3133,  9873,  1753,  5479,  1753,
    2561,  2574, -3133, -3133, -3133, -3133, -3133, -3133,   877,  9992,
   -3133,  2098, -3133,  2269,   124,   177,   336, -3133,  2153, -3133,
   -3133,  4977,    75, -3133,  1884,  1819, -3133,    75,  1505,   947,
    2154,  2600,  1937, -3133, -3133,   521, -3133,   528,   880, -3133,
   -3133,   533,   181, -3133, -3133, -3133,   612, -3133,  2582,  2582,
    2583,  1935,   -75,  2586,  2587,  2591,  2586,  2586, -3133, -3133,
   -3133,   225, -3133,  1035,   336, -3133,   612, -3133, -3133, -3133,
    1948, -3133, -3133,  1951, -3133, -3133,  -188,   534, -3133,   336,
     535, -3133,  5149,  2179,  2605,   536,  1007,  2621, -3133, -3133,
   -3133, -3133,  5149,  2010,  2301,  5149, -3133, -3133, -3133, -3133,
     289,  1054,  1054,  2624,  -187, -3133,  2625, -3133, -3133, -3133,
    1054,   336,  2034,  1338,  2627,   336, -3133,  4720,   100,  1505,
    2626,  1007,  -181,  2378,  5149, -3133, -3133,  2408, -3133,  1915,
    5149, -3133, -3133, -3133,  2632,  4018,   277, -3133,  1086,   336,
     277, -3133,  2197,  4018,  4018, -3133, -3133,   -22,  2116, -3133,
    1106, -3133, -3133,  1156, -3133, -3133,  2030, -3133,  4720,  4978,
    2524,    85,   941, -3133, -3133, -3133,  1974, -3133, -3133, -3133,
   -3133, -3133, -3133,    63,  1625,    63,  1625, -3133, -3133, -3133,
   -3133, -3133, -3133,   -24, -3133,  1184,  1215,  2749, -3133,  2198,
    2163,  9992, -3133,   121,   121, -3133, -3133, -3133, -3133,   539,
   -3133,  2131, -3133,   128,   532, -3133,  1978, -3133,   541, -3133,
   -3133,  2645, -3133, -3133,  2058, -3133,  2654,  9642,  9642,  9642,
    9642,   128,   128, -3133, -3133, -3133, -3133, -3133, -3133,  2645,
    1984,   277, -3133,  2553, -3133, -3133,   336,   629,   629, -3133,
   -3133,   629,  2397,  1988, -3133, -3133,   537, -3133,  2218,  2219,
   -3133, -3133,  2639,  2221,  1991,  1480,  1992,  1993, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133,   542, -3133, -3133, -3133,   258,
     640, -3133,  9468,  9468, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  5297,  5297,  2188,  5297,  2189, -3133,  5297,
     613,  9992,  2669, -3133, -3133,  9468, -3133, -3133, -3133, -3133,
   -3133,  2670, -3133,  -151, -3133, -3133,  2269,  2001,  2020, -3133,
   -3133,   173,   173,   173,  2657,   173,   173,   173,   173,   173,
     173,  2660, -3133,  2661,   173, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  4977, -3133,   277,  2029, -3133,  2191,  2397,
    2662, -3133,  2667,  2671,  2673,  2674,  2675,  2677,  1165,  1819,
   -3133,  2191, -3133, -3133,  2678, -3133,  2347,   128,  1351,   128,
   -3133, -3133,  2217, -3133, -3133, -3133, -3133,  2260,  2263,   546,
    1480,  2684,  1480, -3133,  2709,   552,  2272,  2281,  2709, -3133,
   -3133, -3133, -3133,  1505, -3133, -3133, -3133,  2238, -3133, -3133,
    1035, -3133,  2217, -3133, -3133,   336,   336, -3133, -3133,   336,
    -261, -3133,   612,   168,  2265, -3133,  2209,   168,   206,  1007,
   -3133,  2726,  2252, -3133, -3133,  2290,  2138, -3133, -3133,   336,
    1054,  4720,  1393,   336,  1054, -3133, -3133,    63, -3133, -3133,
    5149, -3133, -3133,   382, -3133, -3133, -3133,  1007,  2729, -3133,
      63,  2265,   277,  2447, -3133,  2712,  1822,  9107,  2719, -3133,
   -3133,   166,  2270, -3133, -3133,  4018, -3133, -3133,  2296, -3133,
   -3133, -3133,   819, -3133,  1822, -3133,  5149, -3133,   397, -3133,
    2141, -3133, -3133, -3133, -3133,  2257,  2348, -3133,  2730, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
     336, -3133,   125, -3133, -3133, -3133,   128, -3133,  -152,  2556,
     553, -3133, -3133, -3133, -3133,   336,   128, -3133,   151,   151,
    2148,  1325,  1325, -3133, -3133,  5341,  2273, -3133, -3133,  2276,
    2277, -3133,  2286,  2287,  2288,  2293,   336,   607, -3133, -3133,
   -3133, -3133,   554, -3133, -3133,  2247, -3133, -3133, -3133,   560,
    2748,  2748, -3133, -3133,   562,  2752,  2740, -3133,    81,   277,
     151, -3133, -3133, -3133, -3133, -3133,  2498,  5215,  1359,  1745,
    1359,  1359,  2319, -3133,  1480,  2321,  1480,  1480,   140, -3133,
   -3133,  2574, -3133,  2285,  2175,  2285,   215, -3133,  2285,   215,
   -3133,  2285,  5297, -3133, -3133,  9992, -3133,  9992,  2561,   124,
   -3133, -3133, -3133, -3133,  1480, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
     220,  2772, -3133,   277,  1760, -3133,  2498, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   398, -3133,
   -3133, -3133,  2274, -3133, -3133, -3133, -3133,  2753, -3133, -3133,
    2335, -3133,  2756,  2340,  2760, -3133, -3133, -3133,  2342, -3133,
    2306,  9468, -3133, -3133, -3133, -3133, -3133,   336,  2763, -3133,
    -261, -3133, -3133,  2764, -3133, -3133,  2765,   336,  2269,   168,
   -3133,    63,   -24, -3133,  2367,  1007, -3133,  5149, -3133,  2177,
    2768,   -24, -3133, -3133,   424, -3133, -3133, -3133, -3133,   149,
    2352, -3133, -3133,  1007,  2183,  2527,  2505, -3133,   -24,  2354,
    2355,  2378,  2327, -3133,  2402,  2368, -3133, -3133, -3133, -3133,
    2517,  2304,  5149,  2325, -3133, -3133, -3133,  1822, -3133,   565,
   -3133,   277,  2225, -3133, -3133, -3133,  9992, -3133, -3133,   128,
   -3133,  2341, -3133, -3133, -3133,  2645,  2225,  1757,  1757,  2380,
   10047,   524, 10123,   524,   524,   524,   524,   449, 10123,  9642,
   -3133, 10123, 10123, 10123, 10123, -3133, -3133,   128,  2810,   128,
    9642,   200,  9468, -3133,  2527,   106, -3133, -3133, -3133, -3133,
    2381,  2382, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   225,
   -3133, -3133,   570, -3133, -3133, -3133, -3133,   571, -3133,  2285,
    2821, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   277,  2772,
   -3133, -3133, -3133,   277, -3133,   277, -3133, -3133,  1856, -3133,
    2537, -3133,  2538,  2805, -3133, -3133,  2387,  2158, -3133, -3133,
   -3133,  2393, -3133,   128,   287, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  1007, -3133,  2394, 10329,
    2357, -3133, -3133, -3133,  2173,   -24, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  2396,   166, -3133,  2402,  2402,   819, -3133,
    4720,  2216, -3133, -3133,   336, -3133,  2527,   470,   126, -3133,
    7933,   470, -3133,  2400, 10123, -3133,   573, 10123, 10123, 10123,
   10123,  2818,   336,   574, -3133, -3133, -3133, -3133, -3133, -3133,
    2365, -3133, -3133, -3133,  2561, -3133,   336, -3133,  1359,  1359,
   -3133, -3133, -3133,   243, -3133, -3133, -3133,  9992, -3133,  1933,
    1933, -3133,  1933, -3133,  1933,  1933, -3133, -3133, -3133,  2370,
   -3133,  1480, -3133,   575, -3133,  1090, -3133, -3133,    40,    40,
      40,    40,    40,    40, -3133,  2824, -3133,   577, -3133,  5149,
    1447, -3133,   635,  2402,  4018,  2402,  2378, -3133, -3133, -3133,
    2557,   399, -3133,   -24, -3133, -3133, -3133, -3133,   583, -3133,
   -3133,  1309, -3133,  2401, 10123, -3133,  2409,  2410,  2413,  2414,
     400,  2350, -3133,  9642, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133,  1933, -3133,  1933, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  1135, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, 10329, -3133,  2847, -3133, -3133, -3133, -3133,
     122, -3133, -3133, -3133, -3133, -3133, -3133,   170, -3133,  7933,
   -3133,  1747, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
    2827, -3133,  2835,   588, -3133, -3133,  1164,  1164, -3133, -3133,
    1164, -3133,  5149,   747, -3133, -3133,  2417,    85, -3133,  2194,
    2196,  2863, -3133,  2391,   401, -3133, -3133, -3133, -3133,  2428,
   -3133, -3133, -3133,   336,   336,  1747, -3133,  2848, -3133, -3133,
     144,  2206, -3133, -3133,  2411, -3133,   166, -3133,   336, -3133,
    2378, -3133
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -3133, -3133, -3133, -3133, -3133,    39, -3133,    99,  -161, -3133,
   -3133, -1089,  -205, -3133, -3133, -2153, -3133, -3133, -3133, -3133,
    -824, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -2424, -3133,  -986, -3133,
    1880, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   371, -3133,
   -3133, -3133, -3133,  1337, -3133,   694, -3133, -3133,   -33, -3133,
   -3133,  2864, -3133,  2861, -3133, -3133, -3133, -3133, -3133,   446,
      86, -3133,   441, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133,  -114,   516,   439, -3133, -3133,  2544,
      47, -3133,  2790, -3133, -3133,  2787, -3133,  2700, -3133, -3133,
   -3133, -3133, -3133,  2564,  2250,   867,  2559,  -502, -3133, -3133,
   -3133, -3133, -3133,   869,  -649, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,   745, -3133,  2697,  2388,  2713,   -30,  2326,
   -3133,  2372,  1642, -3133,  2541, -3133, -3133, -3133, -3133,  2546,
   -3133, -3133, -3133, -3133,  -390, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  2369, -3133,  2362, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -1347, -3133, -3133,  -763, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,  -128, -3133,
   -3133,   835, -3133, -1103, -1158,  -631, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  1943, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133,  -586, -3133, -3133, -3133, -3133, -3133,  2140, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  -577, -3133,   -98, -3133,
   -3133, -3133, -3133,  2522, -3133, -3133,  -236, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  1678, -3133, -3133, -3133, -3133,   642, -3133,
   -3133, -3133, -3133, -3133, -1982, -3133, -3133,   633, -3133, -3133,
   -3133, -3133, -3133, -3133, -1127,  -702,   502,   798, -3133,  -224,
    -547,   746, -1109,  1060, -3133,   719, -3133, -2450,    -3,  -293,
   -3133, -3133, -2363,   360,  1357, -3133, -3133, -3133,   697,  1052,
   -3133, -3133, -3133, -3133, -3133, -3133,    93, -3133,  -229, -3133,
    1057, -3133,   726, -3133,   416, -3133, -3133, -3133, -3133,  -789,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   515, -3133,
   -3133, -1844, -3133,   718, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133,  1523, -3133, -3133, -3133, -3133, -3133, -3133,  -426, -3133,
   -3133, -2098, -3133, -3133, -3133, -3133,   419, -2287, -3133, -1129,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133,  2948, -3133, -3133, -3133,  2875,  2927,
   -2295, -3133, -3133, -3133, -3133, -3133, -3133, -3133,  -348, -3133,
   -3133, -3133, -3133, -3133,  2931, -3133, -3133,  2952, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,   774, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,  -650,
    2220, -3133, -3133, -3133, -3133, -3133,  2046, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133,  2716, -3133, -3133,   -23, -3133,
   -3133,   771, -3133, -3133,  1423,  -186,  2663, -3133, -3133, -3133,
   -3133,   561, -3133, -1047,  1967,  1083, -1449,  1481, -3133,   781,
    1773,  -323,  -505, -3133,  2212,  1568, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,  1491, -3133,  -766, -3133,
    -616, -3133, -3133, -3133, -3133, -3133, -3133, -3133,  -706, -3133,
   -3133, -3133, -3133, -3133, -3133,   147, -3133, -1322,  1588,   425,
   -3133, -3133, -3133, -3133, -3133,   -40, -3133,  -496, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133,  1484, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133,  -504, -3133,   839,  2565, -3133, -3133,   -25, -3133,
    -655, -3133, -3133,   -17,   298, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133,   899, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133,   -81, -3133,  -341,
    -336, -3133, -3133,  -327, -3133, -2753, -3133,   -64,   606, -1357,
   -3133, -3133, -3133,   960, -3133, -1988, -3133, -3133, -3133, -2007,
   -3133, -3133, -1991, -3133, -3133, -3133, -3133, -2310, -3133,   981,
     656, -3133, -3133, -3133, -3133, -3133,   437, -3133, -3133, -3133,
   -3133, -3133, -3133,  -675, -3133, -3133, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133,  -243, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133, -3133,  1113,
   -3133,  1114, -3133,   427,   770, -3133, -2395,  -156, -3133, -3133,
   -3133, -3133, -3133, -3133,     1, -3133, -3133,  -463, -3133,  -876,
   -1341, -3133, -3133, -3133, -3133, -3133,   -29, -3133, -3133, -3133,
   -3133, -3133, -2001, -3133, -3133, -3133, -3133, -3133, -3133, -2519,
     714, -3133, -2611,   799, -3133, -3133, -2351,    94,    91,   372,
   -3133, -2197, -1926, -3133, -3133,  -210,  -536, -3133, -3133, -3133,
   -3133, -1968, -3133, -3133, -3133,    -8, -3133,   323, -1052, -3133,
    -405,  -285,  1152,  -258, -2193,   347, -3133,   619, -3133, -3133,
   -3133, -3133,   -76, -3133, -1267, -2325,  3068, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133,  -688, -3133, -2358, -3133,  1823,
   -3133, -3133,   630,   367, -3133, -3132,   365,  -127,   180,    33,
   -1899, -2277,  1067,  -200,   380, -1252, -3133,  1070, -3133, -3133,
   -3133,  1174,  -601, -3133, -3133,  -473,  1848, -3133,   507, -3133,
   -3133,   479,  -111, -3133, -3133, -3133, -2243,  -345, -2603, -3133,
   -2412, -3133, -3133, -3133, -3133,  1209, -3133, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133, -2806,  -358, -3133, -2835,
   -2532, -1953, -1558, -3133, -3133,  -346, -3133, -3133, -3133,   288,
   -1068,  1065,  -746,  1987,  1660,  1658,   512, -3133, -3133,   292,
     645,    87, -3133, -3133, -3133, -3133,  1679, -3133, -3133, -3133,
   -3133, -3133, -3133, -3133, -3133, -3133,   903,  1039,  2572, -3133,
   -3133, -3133, -3133
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2265
static const short yytable[] =
{
      34,    36,    38,   326,   568,    38,  1005,   183,  1403,   268,
     956,   235,    86,   960,  2151,  1520,  1355,  1471,  1472,  1492,
    1473,  2075,  1494,  1495,  1464,   409,   410,  1461,  2456,  1174,
    2059,   102,  2742,  1122,  2287,   407,   408,    58,  1993,  1994,
     681,  2717,   425,  2719,   296,  2341,  2342,  2343,  2344,   101,
     969,    58,  2676,   993,  2225,  2226,  2095,    86,  2036,   577,
    2037,  1460,   108,  1060,  2413,  2953,  1465,    33,   946,   115,
    2852,  2740,   183,   120,  2389,    33,   122,   123,    33,  1512,
     951,   126,   127,  3239,  3240,  3241,  2414,    33,  1062,  2807,
      33,   183,   423,  2797,    33,  2176,  2588,  1902,  1036,  2104,
      33,    58,   577,   588,  1092,  2329,    33,   593,  1511,   577,
     589,  3208,  1078,  2883,   594,  3243,   111,  1433,   231,  1897,
    3134,   234,   364,   365,  1433,  1036,   238,    33,    33,  1055,
    2019,  2019,    99,  1907,    33,   411,  1178,  1462,    33,   427,
    1067,   429,  2604,   430,   431,   432,  1920,  2642,    33,  1036,
    3000,    33,   437,  1036,   577,    33,   448,   449,  1167,   511,
    1212,  2140,     1,   196,   324,  1036,     2,    33,  1182,  1132,
     561,  1197,  2964,    33,  2966,  1203,   563,    99,    33,  1898,
    1419,  1209,   349,  1211,  2733,  2736,  2736,  2972,   329,  2736,
     274,  1224,  1225,    33,   254,  1127,  1180,   274,  1130,  1056,
    3173,   571,  1178,   331,    33,   446,   577,  1173,   274,   332,
     333,  3374,    33,   274,  1224,  1225,    33,   274,   327,   328,
      33,   324,   183,  1085,   577,    33,   183,    33,   324,  3363,
     361,  1513,  1514,  2140,  1508,  1036,   367,    33,    76,   274,
    1293,  1294,    33,  2929,  2611,    77,   577,  2897,   396,   274,
    3079,  1294,  2798,  3293,    58,   406,   406,   406,   406,   406,
    2608,   972,  3139,   406,  2972,  3035,   958,   274,  1293,  1294,
      33,   254,  2881,   357,  1420,  1421,  2851,  2144,    33,  2145,
       4,  2146,  2192,    54,  3461, -2263,  1038,  2256,  2257,  1902,
    1279,    78,    79,  2972,  2811,   277,  2198,  1280,  2614,    80,
     565,  1924,  3595,  1234,    33,   602,  3364,  3365,   605,  1285,
      58,    58,  2317,   579,  3230,  3230,  3230,  3230,  1064,  1065,
     513,  2650, -2263,  3121,  2653,   613,   614,   615,   616,   653,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,  2969,  2916,   597,
    2100,   661,  1233,   949,    54,  2163,  2456,   634,   635,  2472,
    3775,  2942,   637,    33,   638,  2917,  2918,  2919,  2920,  2921,
    1114,   324, -2263,   425,  2465,   973,  1980,   641,   642,   643,
     644,  1282,   934,  1122,   651,  1443,   664,  2465,   521,  2515,
    2715,   666, -2263,  2367,   527,  2615,  1032,  1035,     6,  2473,
     322,  3097,   324,  3513,   324,  3730,  3767,  3071,  1926,    54,
    1983,  2198,  3357,  1047,   935,  2150,  2900,   183,   950,  1234,
      54,   315,   316,   317,   318,   319,  2909,   104,   105,  3039,
    1234,  2169,    54,   107,  1068,  3655,  1411,  1068,  3290,  3661,
      33,    54,   315,   316,   317,   318,   319,  1077,   573,    43,
    3098,  1068,  2677,  1501,  1502,  1068,  1444,  3744,  1118,   670,
    2039,   959,  1094,  2039,  2044,  3366,  3358,  1068,  1004,  1077,
    2236,   577,   577,   580,  2683,  1106,   112,  1108,  1077,  1101,
       7,   183,  2683,  3122,   974,  1116,  1118,  3291,  1903,  2738,
     323,  2387,  1131,  1903,    54,    43,  2746,    44,  2764,  1172,
     153,    58,    33,    48,  1286,  3231,  3231,  3231,  3231,  2766,
    1106,  1031,   833,   926,  1106,  2827,    10,  1547,  1106,    33,
      54,  3004,    26,  2887,  1077,  1031,  3059,  1077,  3140,   590,
    1932,   979,    10,  3059,   673,  3193,  3194,   673,  3059,  3099,
    3102,  3102,  1167,  3776,  3196,   673,  3206,  3268,  1110,    27,
    1527,  3337,  1533,    81,  1169,  1170,   183,  3344,  3429,  3449,
    2199,  1234,   396,  3161,   396,  3449,   967,  3457,     1,  1936,
    3564,  1981,     2,   948,   406,  3603,  3603,   953,  3664,  3664,
    3057,   573,  3703,  1218,  2258,    52,  1221,  2368,  3719,  1542,
    1371,  1372,  1466,  3449,   406,  1237,   315,   316,   317,   318,
     319,  3072,  2164,  2241,  1031,  1984,  2898, -2263,  3230,  3230,
     562,  2479,  3230,  2812,  3192,  3532,   564,  1509,  2353,   279,
    1373,  1374,  1375,  3282,  2195,  3135,  3064,  1226,  2060,  1933,
    3265,   566,   918,  1235,  3375,    33,  2605,   325,  1919,    33,
    3036,   572,   282,  1933,  3288,  1467,   578,  1400,    82,  2974,
    2975,  3589,  2976,  2977,  2978,  2979,  2980,  2981,  3462,    33,
    1109,  2933, -2263,  1298,   583,  2910,     3,  2071,  1510,  1414,
    1242,  1236,  1122,  1298,   673,  2199,  1526,  1236,  3174,    58,
      58,    58,  1023,    58,  1027,  1029,   584,  1515,  1037,  1039,
    1040,  1298,  2691,  1045,   516,  1029,  3398,  2891,  1048,  2596,
      58,  1003,    33,  3270,  1982,  2542,  2348,  1985,  1986,  1040,
    3201,  1237,  2381,   159,  3408,  2046,  1281,  2075,    54,  1434,
    1037,  1037,  1237,  2020,   591,   288,  1459,  1227,   595,  3421,
    1040,  2318,  3624,  1463,  3188,  2728,    58,  2004,  2786,  2643,
      83,  1199,    58,  1040,    58,  3339,  2023,  3341,    58,  3478,
    3380,    58,  3334,  1095,    58,  3065,  3382,  3093,  2177,  1468,
    3387,  1029,  2728, -2263,    58,   403,  1518,  2538,   403,   406,
    1112,  1968,  1037,  3596,  1516,  2107,  1119,   952,  3094,    58,
     403,  2436,  3353,  2437,   403,    58,  2728,   406,   406,   598,
    2728,   662,    58,    58,    58,  2108,  2109,  2110,  1193,  3231,
    3231,  1200,  2481,  3231,  2522,  1567,    58,   668,  2161,  3495,
    1422,  3567,  2128,  1213,  3435,  1213,   406,   291,  1213,   406,
      84,  1213,    58,  2106,  2147,  3571,   665,     4,    85,   292,
     293,   667,  2148,  1184,  1086,  2121,   295,   294,  3733,  3230,
    1172,  3367, -2263,   295,  1356,  3230,  3230,  2466,  3230,  3230,
    3230,  3230,  2542,  1237,   295,  3465,  2356,  3230,  3496,   295,
    3391,    33,  1342,   295,  3330,  1342,  3333,  1995, -2263, -2263,
   -2263, -2263, -2263,   651,   651,  3411,  3514,  3716,  3731,  3768,
    2162,  1276,  1967,  1185,   100,   295,  2974,  2975,  2627,  2976,
    2977,  2978,  2979,  2980,  2981,   295,  1031,  2628,  1527,   671,
    2040,  2922,  3544,  2041,  2045,    33,  2050,  1024,    33,    33,
    2050,  2501,  2502,   295,  2684,  3283,  2191,  3584,    54,  2051,
    1186,  2629,  2690,  2051,  2630,  1262,   103,  2206,  3592,  2739,
    2050,  2744,  2659,  1238,  1239,  1240,  2747,  2335,  2765,  3475,
    2631,  3476,  3477,  2051,  1241,  2982,   110,  1498,     5,  2767,
    2662,  1117,  1996,    33,  1505,  2828,  3116,  3656,   368,  3581,
    1917,  1131,  1172,  2888,    26,    27,  3060,  3563,  1997,  3493,
    2203,  3230,  1314,  3061,  3230,  3230,  3230,  3230,  3063,  3100,
    3103,  3107,  3258,  2236,  3197,   369,  3207,  3269,  1568,  1376,
    2654,  3338,  3455,  2091,  2185,    69,     6,  3345,  3430,  3450,
    3524,   112,  2096,  3425,    53,  3456,    33,  3458, -2263,     1,
    3565,  1998,  1366,  3433,   673,  3604,  3605,  1187,  3665,  3672,
    3688,  2052,  3704,   428,  2174,  2052,  2488,     7,  3720,  2119,
    3231,  2018,  1178,  3755,    33,  2357,  3231,  3231,   116,  3231,
    3231,  3231,  3231,  2302,  2632,  2052,  2358,   114,  3231,  1037,
    1999,  2336,    58,  3284,  3198,  3285,     8,  1359,  3275,  1451,
    3278,  3230,  3202,  3281,  2678,  2983,  2984,  2449,    58,  2450,
    3230,  1037,  2781,   189,  2471,  1377,  2781,    54,  3481,  2000,
     610,  3486, -2263,   190,  3488,  2330,   166,   522,  2001,  3448,
    2065,  1449,   193,    33,  1188, -2263,  3004,  2633,   167,   532,
    2525,   678,   232,  2449,  2634,  2450, -2263,   104,   105,   932,
      58,  3594,  1049,    33,  2074,  1119,  2241,  1451,  1378,  3582,
    2985,    54,  2165,    33,    54,    54,  1119,  2660,  2751,  2752,
    2808,  1474,  3647,  3648,  1189,  2054,    53,  1054,    33,  2054,
      58,    58,    58,  2302,    58,  2663,    58,    58,  1552,  3568,
      33,  2055,    58,    58,  1913,  2055,    33,  1426,  1072,  2054,
    2337, -2263,  3231,   233,  1427,  3231,  3231,  3231,  3231,  1118,
    2101,  1081,    33,  2451,   928,  2055,  2452,  3259,  2050,  2594,
    2635,  3163,  2982,    33,  1569,  1540,  2303,    58,  2167,    33,
    3324,  2051,    33,   240,  3455,  3455,  1551,   929,  2236,    58,
    1190,  2122,  2507,   242,  1559,  2304,  2305,  2831,    33,  2451,
    3184,    33,  2452,  2138,    37,  1110,    33,  1570,   252,  3712,
      33,  3714,    54,    58,    58,  2306,   415,  2050, -2263,  1391,
    1392,   416,    58,   418,  2236, -2263,  3569,  1070,  1018,   173,
    2051,  3186,    33,  1389,  2207,   105,  3081,  2986,    58,    58,
      54,  1079,  3231,  2047,   249,  1084,  2049,  2758,  2759,  2760,
     250,  3231,  3439,   174,   253,  1390,   991,  1098,     4,   994,
     256, -2263,  1440, -2263,  1970,  2227,  2228,  2229,  2313,   961,
    2230,   962,  2231,  2232,  2528,    33,  2303,  1314,  1314,   928,
    2134,    33,  3606,  2052,  1257,  1258,  3687,  1314, -2263,  3426,
    2182,  2183,  2983,  2984, -2263,  2304,  2305,   175,   257,  1118,
    2017,  1264,   929,  2987,   258,   415,   176,   425,  2024,  2294,
     416,   417,   418, -2263, -2263,  2306,  1290,  1291,  1292,    54,
    2733,  2241,   274,  1293,  1294,    33,  1475, -2263,  2010,    54,
    2011,  2012,  2052, -2263,  1295,  1296,  3082,  2297,  2298,   274,
    1293,  1294,    33,   183,    54,  1321,  3489,  2985,  3128, -2263,
   -2263,  1295,  1296,  2988,  2989,    33,    54,  2241,   321,  2061,
    2084,  3331,    54,  2066,  2072,  2066,  1395, -2263,    33, -2263,
   -2263,  3689, -2263, -2263,  3083,  2078,  2080,  2081,    54,     5,
      58,  2085,  2087,  2088,  2089,  1037,  1122,  3062,  1396,    54,
     177,   178, -2263,  2319,  1037,    54,  2321,  2054,    54,  2075,
    2954,  2053,  2956,  3385,  2957,  1119,   965,    58,   966,    58,
      33,    58,    58,  2055,    54,  1297,  3738,    54,   259,    58,
      58,  1037,   260,    58,   406,  2823,   406,    58,  2236,  2227,
    2228,  2229,  3213,   261,  2230,  1119,  2231,  2232,  3084,  1028,
    2761,    33,  2137,  1119,  2865, -2263,  2054,  3054,    54,    58,
      58,  1508,  3085,  1476,  2482,   262,  1411,  3706,     7,  1477,
    1478,  1479,  2055,  3574,    33,  3577,  3578,  3579,  3580,  2462,
    2463,  1100,  2443,  2236,  2986,  1521,  1522,  1523,  1524,  3575,
    1107,  1480,  3690,  2606,   263,  3575,  3691,     8,  3585,  3586,
    3587,  3588,  2902,  2737,    58,    58,  2741,    58,  2430,  2467,
      58,    58, -2263,   264,  1251,  1217,  2110,  2264,  1220,  2265,
    2266,  1223,  2497,  2268,  2269,  1252,   265,  3695,  2928,  2288,
    1036,  2180,    33,   406,   406, -2263,  1216,  3690,   406,  1219,
      58,  3691,  2189,  2190,  3708,  1527,   266,  -282,   330,  1198,
    2987,  1118,   335,  1204,  1544,  2233,   267,  1208,  2234,  1449,
    2235,    33,  3086,   269,  2514,    58, -2263,  1538,  1118,    33,
   -2263,  2241,  1499,  1500,   309,  1253,  1503,  1504,  3087,   310,
    2236,   104,   105,   311,  1987,  2506,  1988,  1395,  2155,  1254,
    2237,   312,  1034,  1034,   313,  3695,  1481,  1034,  1034,  1482,
    2988,  2989,   373,   336,   337,   338,  1990,  1483,  1991,  1396,
    1034,  2238,  3708,   314,   382,  2352,  2241, -1627,   412,   413,
     414,  3663,   567,   344,  3666,  3667,  3668,  3669,   345,  2079,
    1034,    33,  -282,  1034,  2239,   346,  2027,  2028,  2240,  1034,
    1238,  1239,  1484,  1034,  1545, -2263,   353,  1034,  -282,  3721,
    3722,  1034,  2593,  3437,  3438,  1034,  1034,   350,  1034,  2221,
    2222,  1034,   351,  1034,  1034,  1034,   360,  2494, -2263, -2263,
   -2263,  1034,   355, -2263,  1034, -2263, -2263,  1485,  1255,  3104,
    2005,  1034,   315,   316,   317,   318,   319,   374,  1034,   371,
    2082,  -282,    33,  3395,   359,  1034,  1486,  1487,  3144,   383,
    2086,  3170,    33,   375,  3077,  3078,  1034,  1488,   362,   366,
    1034,  3725,  1489,  2241,  1034,   384,  1404,  1405,  1406,  2233,
    1034,  3141,  2234,  1034,  2235,  2322,  2326,  2323,  2327,   372,
    -282,  3274,  3274,  2770,  3274,    33,  2468,  3274,  2773,   381,
      33,  2661,   390,   391,  2236,  3362,   376,  2666,  2667,   397,
    2948,  1490,  2949,   400,  2237,  1044,  1298,   401,   385,  -282,
    2029,  2030,  2031,  2032,  2033,  2034,   435,  1053,  -282,  3470,
     436,  3471,  3749,  1298,    33,  2560,   433,  3453,  3454,   438,
    2102,   447,  2102,  1491,   450,   377,   451,  1299,   453,   454,
    1300,   457,  2775,   455,  3183,   456,  1073,   386,  2239,   504,
    3464,   515,  2240,  1301,  3214,   517,   519,  3215,  2789,  2790,
    2110,  2793,  1090,  1091,   378,   524,   525,   526,  1097,   528,
    3216,  1099,   529,   379,   533,   534,   387,   538,   539,  2814,
    2004,  1971,   535,  2787, -2263,   388,   549,  2788,  2461,   550,
     551,   570,   554,  1302,  2782,   559,  2799,   569,   575,  3149,
     576,  2310,   581,   582,   586,  1303,   603,  3157,  3158,   587,
    3218,   596,  2613,   606,   439,   608,   611,   607,   636,   639,
     645,  2820,  3219,   646,  3500,   654,  1331,  2241,   655,  1333,
     440,  1334,  1335,  1336,  1337,  1338,   652,   656,   657,  1995,
     658,  1213,   406,   406,   659,  2856,  1304,  2824,    58,    58,
    2668,  2029,  2030,  2031,  2032,  2033,  2034,   660,   663,   669,
     679,  2370,  2480,  3220,     1,   933,  1972,   938,  2260,  1037,
     940,  1037,  1037,   441,   941,  1037,  1037,   942,  2270,  1305,
     130,  1037,  1973,   947,  2375,  1306,   957,   963,   964,   971,
     978,   976,   980,  2352,  1307,  1308,  2859,  1309, -2263,  3501,
     999, -2263,  3221, -2263,   981,    58,   982,  1001,  1006,  1310,
    1311,  1007,   442,  1131,  3222,  1009,  2314,  1312,  1010,   131,
    1313,  1011,  3566, -2263,  1996,  1974,  3223,  3224,   295,  1012,
    1014,  1016,  1015, -2263,  3225,  2669,  1017,  3226,   132,   133,
    1997,   443,  1019,  1129,  1205,   295,  1172,  2924,  1266,  2925,
     444,  2670,  1267,  1314, -2263,  1314,  1268,  1269,  1270,  2551,
    2553,  3502,  2563,  3503,  1975,  1314,  1314,  1037,  1271,  1272,
    2361,  1273,  1314,  1314,  1314,  1314,  1274, -2263,   134,  3504,
    3274, -2263,  3040,  1998,  1275,  1119,  1034,  3505,  1277,  2119,
     135,  3506,  2493,  1976,  2671,  3501,  1278,  3041,  3042,  1283,
     474,   136,  1977,  1284,  1287,  1288,  3043,  2061,  1332,  1289,
     651,  1339,  2066,  1340,  1341,  1344,  3507,   137,  2072,  1345,
    1357,  2066,  1999,  1347,  1057,  1057,  1348,   138,  1349,  1350,
    1351,  1352,  2945,  2672,  1353,  2947,  1358,  2950,  2951,  2428,
    3044,  1359,   139,  1362,  1363,  2432,  1364,  1365,  1369,  3045,
    1388,  2000,  1394,  1393,  3401,  1397, -2263,  3502,  1398,  3503,
    2001,  1407,  2673,  1401,  1418,  1399,  1424,  1425,  1428,  1429,
    1431,  2674, -2263,  1432,  2459,  3504,  1436,  1437,  3046,  1439,
    1448,  1453,   140,  3505,  1451,  1455,  1456,  3506,  1037,  1119,
    1496,  1506,  2475,  2476,  1507,   406,  1511,   475,   476,   477,
     478,   479,   480,  1534,  1543,   141,  1034,  1034,  1034,  1535,
      58,  3110,  3507,  1536,  3115,   481,   482,   483,  1537,  3403,
     142,  1541,  1057,  3047,  1547,  1546,  1556,   143,  1558,  1894,
     144,  2504,  1228,    58, -2263,  3108, -2263,  1895,   577,  2890,
    1893,  1896,  1901,  2025,  2026,  2027,  2028,  1909,  1910,  1911,
    1958,   145, -2263,  1966,    58,   146,  2529,  1559,  2275,  1314,
   -2263,  1905,  1119,    58, -2263,  1908,  1969,  3048,  2914,  2276,
    3138,  1979,  2006,  2007,   147, -2263,  1989,  2064,  1167,  2043,
     406,   406,  2077,  2008,  2930,  2009,  2013,  2092,  2014, -2263,
    2277,  2015,   148,  2016,  2038,   406,  2093,  2278,  2094,  2097,
      58,    58,    58,  2098,  1419,  2279,    58,  2272,  2099,  2113,
    2120,  1518,  2127,  2129,  1037,  3451,  3452,  3453,  3454,  2131,
    2140,  2153,  2170,  2142,  2154,  2172,  2181,  2280,  2184,  2195,
    2186,  2202,  2204,  3535,  2209,  2210,  2352,  2212,  2352,  1903,
    2250,    58,  3543,  2248,  2251,  2253,  2259,  2311,  2315,  2649,
    2649,  2320,  1964,  2649,  2134,   484,  2316,  2324,   485,  3549,
    2325,  2330,  1131,  2345,  2004,  2353,  2371,  2377,  1172,  2029,
    2030,  2031,  2032,  2033,  2034,  2378,  1314,  2384,  2387,  2379,
    2328,  2366,  1315,  2382,  2383,  1314,  2416,  2418,  1314,  1314,
    1314,  1314,  2689,  2419,  1172,  1037,  2421,  2420,  2439,  2694,
    1314,  2422,  3593,  2712,  2425,  2423,  3296,  3297,  3298,  2434,
    3300,  3301,  3302,  3303,  3304,  3305,  2440,   183,  2441,  3308,
    2438,  2444,  2442,  2446,  2729,  2729,  2729,  2445,  2460,  2729,
    1314,  2743,  2447,  1902,  2061,  2448,  2332,  2483,  2339,  2490,
    2485,  2029,  2030,  2031,  2032,  2033,  2034,  2486,  2339,  1321,
    2492,  2495, -2263,  2499,  2500,  2362,  2363,  2364,  2365,  2505,
    2508,  2509,  1228,  2768,  2468,  2769,  2771,  2518,  2772,  2774,
    2512,  2532,  2776,  2542,  1241,  2544,  2066,  2591,   486,  2592,
    2066,    58,  2609,  1474,  2622,    58,  2603,  2617,  2526,  2618,
    2619,  1037,  2729,   487,    58,  2459,  2623,   488,  2804,  2804,
    2624,   471,   472,   473,  2638,  2639,  3641,   468,   469,   470,
     471,   472,   473,  2646,  2657,  2658,  2664,  2679,  2681,    58,
    2273,  2665,  2680,  2693,  2709,  2714,  2822,  2716,   474,    58,
    2718,  2721,  2720,   489,  2274,  2725,  2779,   474,    58,  2748,
    2749,  2750,    58,  2753,  2754,  2755,  2756,  2757,  2795,  3390,
    2784,  3696,  3697,  3698,  3699,  3700,  3701,  3646,  3376,  2815,
    2813,   490,  2817,  2819,  2818,  2821,  2825,    58,  2334,  2833,
    2834,  2836,  2837,  2840,  2839,  2841,  2857,  2275,  2838,   491,
   -2263,  2860,  1508,  1240,  2858,  3409,  3392,  2864,  2276,  2873,
    2875,  2866,  1290,  1291,  1292,  2884,  2885,  2886,   274,  1293,
    1294,    33,  2893,  2901,  2889,  2894,  2903,  2931,  2936,  2277,
    1295,  1296,  2944,  2926,  3718,  2946,  2278,  2972,  2952,  2955,
    2958,  2960,  2961,  2962,  2279,   475,   476,   477,   478,   479,
     480,  2973,  2963,  1228,   475,   476,   477,   478,   479,   480,
    2998,  1037,  2536,   481,   482,   483,  2280,  2995,  3007,  3056,
    1131,  1131,   481,   482,   483,  3057,  2729,  3058,  3066,  3069,
     492,  3070,  3073,  3075,  2905,  2270,  2729,  3076,  3095,  2260,
    1037,  3096,  1314,   926,  3105,  3106,  3109,  3111,  3112,  3119,
    3123,  3127,  3130,  3145,  3137,  2260,  1037,  3148,  1475,    58,
    2649,  1297,  3156,  3189,  3178,  3190,  3494,  1315,  1315,  3179,
    3208,  3181,  3166,  3198,  3205,  3209,  2134,  1315,  3713,  2019,
    3250, -2263,  3257,  3260,  3261,  3262,  3263,  3264,  3266,  3267,
    3276,  3279,  3168,  2281,  3287,  3289,   493,  3294,  3350,  2282,
    1314,  3469,  3299,  3472,  3473,  3306,  3307,  3317,  1037,  3314,
    1037,   926,  3318,  1314,  3295,  1314,  3083,  3319,  3313,  3320,
    3321,  3322,  3147,  3323,  3328,  3335,  1314,   651,  3336,  1321,
    3340,  2729,    58,  2712,  3342,   651,   651,  3346,  2682,   183,
    3351,  2685,  2686,  2687,  2688,  2729,  3347,  2537,  3371,  3780,
    2968,  3377,  2971,   484,  3378,  3379,   485,  3393,  3397,  3380,
   -2263,  3406,   484,  2066,  3399,   485,  3538,  1235,  3402,  3414,
    3417,  3427,  3421,  3449,  3460,  3440,    63,  3459,  3441,  3442,
     183,  2072,  3466,  2066,  3474,  1476, -1816,  1118,  3443,  3444,
    3445,  1477,  1478,  1479,  3537,  3446,  2428,  3498,  3479,  3516,
    3517,  3561,  3518,    58,  3054,  3520,  3521,  3522,  3523,  3527,
    3529,  3530,  3547,  1480,  3542,  3536,  3540,  3546,  3548,  3550,
    3551,  3554,  2564,  2565,  2566,  2567,  2568,  2569,  2459,  3552,
    3129, -2263,  3131,  3556,  3560,  2729,  1037, -2263,    58,  1228,
     154,   186,  2020,  3570,  3590,  3572,  3598,  3599,  3607,  3617,
    3618,  3619,  3620,    58,  3621,    58,  3153,    58,  3622,  3639,
    3627,  3645,  3652,  3640,  3670,  3662,  3724,  3673,  3686,  3702,
      58,  3715,  3742,  3753,  3726,  3727,   486,  1314,  3728,  3729,
    3732,  3754,  3761,  2352,  3763,   486,  3764,  3468,  3765,  3766,
     406,   487,   406,  3769,  3774,   488,  3778,  3152,  3101,  3741,
     487,  1354,    58,    58,   488,  2194,   186,  2849,  1314,  3779,
    2517,  3389,    50,    49,  2800,  2809,   530,  3126,  1481,  2570,
    2729,  1482,   192,   197,  3394,   186,   343,   523,  1008,  1483,
    2372,   489,   531,  2373,  3227,  3227,  3227,  3227,  2729,  2729,
     489,   356,   672,   558,   348,   937,   970,   556,    58,   944,
    3739,  1992,  2431,  3252,   943,  3626,  1346,   592,  1962,   490,
    2655,  1192,  2647,  2791,  1484,  2477,  2220,  3416,   490,  2541,
    3229,  3229,  3229,  3229,  2224,  3177,  2863,   491,  3762,  2796,
    3384,  2561,  2124,  3545,    46,   128,   491,    60,  3511,  1314,
    1314,    61,  1298,   402,    47,  2524,  1265,  1096,  2527,  1485,
    1314,  1314,  2208,  1314,  1368,  2247,  1314,   514,  1314,  2160,
    3499,  2531,  1314,  3608,  1128,  2292,  2293,  2158,  1486,  1487,
    1899,  2115,  2309,  1299,  3745,  1321,  1300,  3172,  3705,  1488,
    2105,  3327,  3616,  2175,  1489,  2496,  3309,   612,  3277,  1301,
    3280,  3675,  3676,   183,  3326,  3052,  3373,   651,  3533,   509,
     510,  3531,    58,  3528,  1034,  3356,   186,  2417,   492,  2785,
     186,  2386,  2895,  2745,  3748,    58,  3492,   492,  2621,  2290,
    2291,  2915,  3434,  1490,  2729,  3332,  2729,  3329,  2533,  1302,
    3623,  3352,  2692,  2959,  3272,  2612,  3271,  3677,  2967,  3487,
    3348,  1303,  3068,  2263,  3515,  3053,    42,  3773,  2970,  1950,
    1037,  3006,  3005,  3436,  3204,  1491,  2347,  3491,  2346,  2994,
    2255,  3654,  3354,  3355,  3432,  3573,  2776,  2907,  2218,  2066,
    1916,  3591,  3583,  2369,   493,  1450,    58,  3136,  2133,  3133,
    2816,  3759,  1304,   493,  2139,   680,  2804,  2123,     0,  3386,
    2804,     0,     0,     0,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,  2571,   406,     0,    58,
       0,     0,     0,     0,     0,  1305,     0,  3534,    58,  2572,
       0,  1306,     0,     0,     0,     0,     0,     0,     0,  1034,
    1307,  1308,     0,  1309,     0,     0,     0,     0,  1172,     0,
       0,     0,     0,     0,     0,  1310,  1311,     0,     0,     0,
       0,     0,     0,  1312,     0,  2390,  1313,  3418,     0,     0,
       0,     0,  1034,  2729,   295,     0,     0,     0,     0,     0,
       0,     0,  2905,  2729,     0,  2260,  2260,     0,  3227,  3227,
       0,  2573,  3227,     0,     0,     0,   473,  2574,  2498,     0,
     640,     0,     0,  3447,     0,     0,     0,     0,     0,     0,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
    2536,   474,     0,     0,  3229,  3229,    58,  2260,  3229,     0,
       0,     0,     0,     0,     0,     0,  2575,     0,  2539,  1228,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,     0,
       0,  1321,     0,  1119,     0,     0,  1119,     0,     0,  1314,
    2576,     0,  1314,     0,  1314,     0,  2729,     0,     0,     0,
    2577,  2578,     0,     0,     0,   186,  2579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2580,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2581,     0,
       0,  2582,  2583,     0,     0,     0,  2584,     0,   475,   476,
     477,   478,   479,   480,     0,     0,     0,     0,  1314,     0,
       0,     0,     0,     0,     0,     0,   481,   482,   483,     0,
       0,     0,     0,  1315,     0,  1315,     0,     0,   406,     0,
     186,  3286,    58,     0,  3651,  1315,  1315,     0,     0,     0,
    3080,     0,  1315,  1315,  1315,  1315,     0,     0,     0,     0,
      58,     0,     0,  2585,     0,     0,     0,     0,  1020,  1021,
    1022,     0,  1025,     0,  2586,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,  1051,
       0,  2391,     0,  1314,     0,     0,  2729,     0,     0,  3238,
    3238,  3238,  3238,     0,     0,     0,     0,  1314,     0,  3227,
       0,  2392,  2393,  2394,     0,  3227,  3227,     0,  3227,  3227,
    3227,  3227,     0,     0,  2729,  1075,  2729,  3227,     0,  1314,
       0,  1080,   183,  1082,     0,     0,     0,  1089,     0,     0,
    1089,     0,     0,  1089,     0,  3229,     0,     0,     0,     0,
    2395,  3229,  3229,  1102,  3229,  3229,  3229,  3229,     0,     0,
       0,     0,  2396,  3229,     0,    58,   484,     0,  1102,   485,
      58,     0,    58,  2397,  1163,     0,     0,     0,  1034,     0,
       0,  1025,  1176,  1179,  1034,     0,   651,  1194,     0,  2398,
    2729,     0,     0,     0,     0,  1206,     0,     0,     0,  2399,
       0,     0,     0,    58,  1057,     0,  3228,  3228,  3228,  3228,
    1034,  1230,     0,     0,  2400,     0,     0,     0,     0,  2845,
    2846,    58,     0,     0,     0,     0,     0,     0,     0,     0,
    2855,  3418,     0,     0,     0,     0,     0,  1314,     0,  1315,
       0,  3227,     0,     0,  3227,  3227,  3227,  3227,     0,  3671,
       0,     0,     0,     0,  2867,  2868,  2869,  2870,  2871,  2872,
       0,     0,  2401,  3674,  2877,  2878,  2879,  2880,     0,     0,
    1119,  2882,     0,     0,  1314,     0,     0,  3229,     0,     0,
    3229,  3229,  3229,  3229,     0,     0,     0,     0,     0,   486,
       0,     0,  2402,     0,     0,    58,    58,    58,    58,    58,
      58,     0,  2403,     0,   487,     0,     0,  3707,   488,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2404,  1921,     0,     0,  2405,     0,     0,
       0,  3227,     0,     0,     0,  3490,     0,  2994,     0,     0,
    3227,     0,     0,     0,   489,     0,     0,     0,     0,     0,
       0,     0,     0,  2934,  2935,  2406,  1315,     0,     0,     0,
    2939,  2940,     0,     0,  2407,  1315,     0,  3229,  1315,  1315,
    1315,  1315,   490,     0,     0,     0,  3229,     0,     0,     0,
    1315,     0,     0,     0,     0,     0,  1314,     0,  3750,     0,
     491,     0,     0,  3238,  3238,     0,     0,  3238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1315,     0,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,  1922,     0,     0,     0,
    3771,  3772,  3750,     0,  1923,     0,     0,     0,     0,     0,
    1924,  1230,  1925,    58,     0,  3781,     0,   474,     0,     0,
       0,     0,     0,  1926,     0,     0,     0,  1412,  3485,     0,
       0,  3485,     0,     0,     0,     0,  1034,  1034,     0,     0,
       0,   492,     0,     0,     0,     0,  1321,     0,     0,     0,
       0,  1927,     0,     0,     0,     0,     0,     0,     0,     0,
    2332,     0,     0,     0,     0,     0,     0,  1928,     0,  1442,
    3228,  3228,  1929,     0,  3228,     0,     0,     0,     0,  1228,
    3117,  3118,     0,     0,  1930,     0,     0,     0,     0,  3125,
       0,  1931,     0,     0,     0,     0,     0,     0,     0,  1470,
    1470,  1470,     0,  1470,     0,  1470,  1470,   493,     0,     0,
       0,    63,    63,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,     0,  3159,  3160,     0,     0,
       0,     0,   481,   482,   483,  3484,     0,     0,  3484,     0,
       0,     0,     0,     0,     0,     0,  1179,     0,     0,     0,
       0,     0,     0,  3180,     0,  3182,     0,     0,  1554,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1230,  1412,     0,     0,     0,     0,     0,     0,
    3660,  1906,  2334,     0,  3238,     0,     0,     0,     0,     0,
    3238,  3238,     0,  3238,  3238,  3238,  3238,  1914,  1914,     0,
       0,     0,  3238,     0,     0,     0,  3253,  3254,     0,     0,
    3255,  3256,  1315,     0,     0,     0,     0,  3678,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1932,
       0,     0,     0,     0,  1933,     0,     0,     0,     0,     0,
       0,  1934,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
       0,     0,   484,  1935,     0,   485,   272,   273,  1936,     0,
    1315,     0,   274,   275,   276,    33,     0,     0,     0,     0,
       0,     0,     0,  1315,     0,  1315,   159,     0,     0,     0,
       0,  3228,     0,     0,     0,     0,  1315,  3228,  3228,     0,
    3228,  3228,  3228,  3228,     0,     0,     0,     0,  3316,  3228,
       0,     0,     0,     0,     0,     0,  3238,     0,     0,  3238,
    3238,  3238,  3238,     0,     0,     0,     0,     0,  3601,  3660,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3485,     0,     0,  1315,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,     0,     0,   277,    63,     0,    63,     0,
    1179,  1089,   161,     0,     0,     0,     0,     0,  2114,  1102,
       0,     0,  1179,     0,     0,   486,  2125,     0,     0,  3383,
       0,     0,     0,  3388,     0,     0,     0,   186,     0,   162,
     487,     0,     0,     0,   488,     0,  3238,     0,  1230,  1163,
       0,     0,  3396,     0,     0,  3238,     0,     0,     0,     0,
       0,     0,     0,  3228,     0,     0,  3228,  3228,  3228,  3228,
       0,  3407,     0,     0,     0,     0,     0,     0,     0,     0,
     489,     0,     0,     0,     0,     0,     0,  1315,     0,     0,
       0,     0,  3484,  2159,  1163,     0,    63,     0,     0,  2166,
    2168,     0,     0,     0,     0,     0,     0,     0,   490,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1315,     0,
       0,     0,     0,     0,     0,     0,   491,     0,     0,  2187,
    3526,    54,     0,   163,     0,     0,     0,     0,     0,     0,
    3526,     0,     0,     0,  1315,  1315,  1315,  1315,     0,     0,
       0,     0,     0,  3228,  2214,   467,   468,   469,   470,   471,
     472,   473,  3228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,  1134,  1135,  1136,  1137,  1315,
    1315,     0,     0,     0,     0,     0,     0,   492,     0,     0,
    1315,  1315,     0,  1315,     0,     0,  1315,     0,  1315,     0,
       0,     0,  1315,     0,     0,     0,     0,     0,     0,     0,
     164,     0,     0,     0,  1034,   278,     0,     0,  1057,  1057,
    1057,     0,  1057,  1057,  1057,  1057,  1057,  1057,     0,     0,
       0,  1057,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,   476,   477,   478,   479,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   166,
       0,   481,   482,   483,     0,     0,     0,   272,   273,     0,
       0,   167,     0,   274,   275,   276,    33,     0,  1138,  3559,
       0,     0,  3562,     0,     0,     0,  1139,   159,     0,   279,
       0,     0,     0,     0,   280,  1140,   281,     0,  1141,     0,
       0,     0,     0,     0,     0,     0,     0,   168,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,     0,   283,     0,     0,
     284,     0,     0,   285,     0,     0,     0,     0,  1228,     0,
       0,  1142,   286,   171,     0,     0,     0,     0,  1143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,     0,     0,   277,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,   647,   287,     0,     0,     0,   172,     0,     0,
       0,     0,     0,     0,     0,   288,     0,     0,  1315,  1315,
     162,   484,  1315,     0,   485,  1144,   289,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3649,     0,     0,
    1145,     0,     0,     0,     0,     0,   290,  1146,     0,  1147,
       0,     0,     0,     0,     0,     0,     0,  2246,  1230,  1148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1315,     0,     0,  1315,     0,     0,  1315,
       0,     0,  1315,     0,  1315,     0,     0,  1149,  3679,  3680,
     175,  3682,     0,  3684,  3685,  1150,     0,   291,     0,   176,
       0,     0,    54,     0,   163,     0,     0,     0,     0,   292,
     293,     0,     0,     0,  2296,     0,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,   295,     0,
       0,     0,  1151,     0,   486,   272,   273,     0,     0,     0,
       0,   274,   275,   276,    33,     0,     0,     0,  1315,   487,
       0,     0,     0,   488,     0,   159,  1152,     0,     0,     0,
    3734,     0,  3735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
       0,     0,     0,   177,   178,     0,   158,    33,     0,   489,
       0,     0,     0,  1153,     0,     0,  3747,     0,   159,     0,
       0,   164,     0,     0,  1154,     0,   278,     0,     0,     0,
       0,     0,     0,     0,     0,  3756,  3757,   490,     0,  3758,
       0,     0,  3760,  1315,     0,     0,     0,     0,     0,   160,
       0,     0,     0,     0,   277,   491,   165,  1315,     0,  1315,
       0,   161,     0,     0,     0,  1315,  1315,     0,  1315,  1315,
    1315,  1315,     0,     0,     0,     0,     0,  1315,     0,  1315,
       0,     0,     0,     0,     0,     0,     0,     0,   162,     0,
     166,     0,   160,     0,     0,     0,  1315,     0,     0,     0,
       0,     0,   167,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,     0,  1155,  1156,  1157,   280,     0,   281,     0,     0,
       0,   162,     0,     0,     0,  1158,   492,     0,   168,  2489,
       0,     0,     0,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,     0,     0,     0,     0,   283,     0,
       0,   284,  1179,     0,   285,     0,     0,     0,     0,     0,
       0,  1228,     0,   286,   171,     0,     0,     0,     0,     0,
      54,     0,   163,   154,     0,     0,     0,  1315,     0,     0,
       0,  1315,  1163,     0,  1315,  1315,  1315,  1315,     0,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1408,   287,     0,     0,     0,   172,     0,
    1315,     0,     0,    54,  1315,   163,   288,     0,     0,  1179,
    2595,  1179,     0,     0,     0,  1025,     0,   289,  1159,     0,
       0,     0,     0,   173,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   273,     0,     0,
       0,     0,   274,   275,   276,    33,     0,   290,     0,     0,
    2641,     0,     0,     0,     0,     0,   159,     0,     0,   164,
       0,  1315,     0,     0,   278,     0,     0,     0,     0,     0,
    1315,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,     0,     0,   165,     0,     0,     0,   291,     0,
     176,     0,   164,     0,     0,     0,     0,     0,     0,     0,
     292,   293,     0,     0,     0,     0,  1315,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,   295,
     160,     0,     0,     0,     0,   277,     0,   165,     0,     0,
     167,     0,   161,  3009,  3010,     0,  3011,  3012,  3013,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,   280,     0,   281,     0,     0,     0,   162,
       0,   166,     0,  1228,     0,     0,   168,     0,     0,     0,
       0,   282,     0,   167,   177,   178,     0,     0,     0,     0,
    1179,   169,     0,     0,  1179,     0,   283,     0,   271,   284,
       0,     0,   285,  1179,     0,     0,     0,   272,   273,     0,
       0,   286,   171,   274,   275,   276,    33,     0,     0,   168,
       0,   186,     0,     0,     0,     0,     0,   159,  1179,     0,
       0,     0,     0,     0,   169,     0,     0,     0,  1230,     0,
       0,     0,   170,     0,     0,     0,  3014,  2829,     0,     0,
       0,  2832,   287,     0,  3015,   171,   172,     0,     0,     0,
       0,    54,     0,   163,   288,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   289,  2854,  2792,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,  3016,     0,
       0,     0,     0,     0,     0,     0,     0,  3017,     0,   172,
       0,   160,     0,     0,     0,   290,   277,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,     0,  3018,  3019,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,   174,   175,
       0,     0,     0,     0,     0,     0,   291,  1292,   176,     0,
     164,   274,  1293,  1294,    33,   278,     0,     0,   292,   293,
       0,  3020,     0,  1295,  1296,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   175,     0,     0,   165,     0,     0,  2932,  3211,
    3212,   176,     0,     0,     0,   274,  1293,  1294,    33,     0,
       0,     0,     0,     0,     0,  3021,     0,  1295,  1296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
       0,     0,    54,     0,   163,     0,     0,     0,     0,     0,
       0,   167,   177,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1297,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   280,     0,   281,     0,     0,  3022,
       0,  1179,     0,     0,     0,     0,     0,   168,     0,     0,
       0,     0,   282,     0,     0,   177,   178,     0,     0,     0,
       0,     0,   169,     0,     0,     0,     0,   283,  3213,     0,
     284,     0,     0,   285,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2696,     0,
       0,   164,     0,     0,     0,     0,   278,  1290,  1291,  1292,
       0,     0,  1179,   274,  1293,  1294,    33,     0,     0,     0,
       0,     0,  3169,   287,     0,  1295,  1296,   172,     0,     0,
       0,     0,     0,     0,     0,   288,   165,     0,   130,     0,
       0,     0,     0,   186,     0,     0,   289,  1179,     0,     0,
    1118,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3150,     0,  1051,     0,  3154,     0,     0,     0,
     166,     0,     0,     0,     0,     0,   290,   131,     0,  3165,
       0,     0,   167,     0,   186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1118,     0,   132,   133,     0,     0,
     279,     0,     0,     0,     0,   280,  1297,   281,     0,     0,
       0,  3185,  3187,     0,     0,     0,     0,     0,   168,     0,
     175,     0,     0,   282,     0,     0,     0,   291,     0,   176,
       0,     0,     0,   169,     0,     0,   134,     0,   283,   292,
     293,   284,     0,     0,   285,     0,     0,   294,   135,     0,
       0,     0,     0,   286,   171,     0,     0,  3251,   295,   136,
       0,     0, -2264,     0,     0,  3023,  3024,  3025,  3026,  3027,
    3028,  3029,  3030,  3031,  3032,   137,     0,     0,     0,     0,
       0,     0, -2264, -2264, -2264,   138,     0, -2264,     0, -2264,
   -2264,     0,     0,     0,   287,     0,     0,     0,   172,     0,
     139,     0,     0,     0,     0,     0,   288,     0,     0,     0,
       0,     0,     0,   177,   178,     0,     0,   289,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,  1118,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,     0,     0, -2264,  1298,     0,     0,     0,     0,
       0,  3310,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3325,     0,     0,     0,   142,     0,
       0,     0, -2264,     0,     0,   143,  1299,     0,   144,  1300,
       0,   175,     0,     0,     0,     0,     0,     0,   291,  1298,
     176,     0,  1301,     0,     0,     0,     0,     0,     0,   145,
     292,   293,     0,   146,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2264,   295,
    3214,     0,   147,  3215,     0,  1179,  2697,     0,     0,     0,
       0,     0,  1302,     0,     0,     0,  3216,   186,     0,     0,
     148,     0,     0,     0,  1303,     0, -2264,     0, -2264,     0,
       0,     0,     0,  1179,     0,     0,     0,     0,  1163,     0,
       0,     0,     0,  2004,     0,     0,     0,  1230,     0,     0,
       0,     0,     0, -2264,   177,   178,  3218,     0,     0,     0,
   -2264,     0, -2264,     0,     0,  1304,     0,     0,  3219,     0,
       0,     0,     0, -2264,     0,     0,     0,     0, -2264,     0,
       0,     0,     0,     0,     0,     0, -2264,     0,     0,     0,
   -2264,     0,     0,     0,     0,     0, -2264,     0,  1305,     0,
   -2264, -2264, -2264, -2264,  1306,     0,     0,  1298,     0,  3220,
       0,     0,     0,  1307,  1308, -2264,  1309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1310,  1311,
       0,     0, -2264,     0,     0, -2264,  1312, -2264,  1299,  1313,
       0,  2698,     0,     0, -2264,  1163,     0,   295,  3221,     0,
       0,     0,     0,  2699,  1301,     0,     0, -2264,     0,     0,
    3222,     0,     0,     0,     0,     0,     0, -2264,     0,     0,
       0,     0,  3223,  3224,     0,     0,     0,     0,     0,     0,
    3225,  2004,     0,  3226,     0,     0,     0,     0, -2264, -2264,
       0,   295,     0,     0,  1302,     0,     0,     0,     0,     0,
       0,     0,     0, -2264,     0,     0,  1303,     0,     0,  3310,
       0, -2264,     0,     0,     0, -2264,     0,     0,     0,     0,
       0,     0,     0, -2264, -2264, -2264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1304,     0,     0,
    1571,  1572,  1573,  1574,  1575,  1576,     0,  1577,  1578,  1579,
       0,     0,     0,  1580,  1581,  1582,  1583,  1584,  1585,     0,
       0,  1179,     0,     0,     0,     0,     0,     0,  1586,     0,
    1305,     0,     0,     0,     0,     0,  1306,     0,     0,  1179,
   -2264,     0,     0,     0,     0,  1307,  1308,     0,  1309,     0,
       0, -2264,     0,  1587,     0,     0,     0,     0,     0,     0,
    1310,  1311,     0,     0,     0,     0,     0,  1163,  1312,     0,
       0,  1313,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1588,     0,     0,     0,     0,     0,     0,     0,     0,  1589,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1590,  1591,     0,
       0,     0,     0,     0,  3310,     0,  1592,     0,     0,  3611,
       0,  3613, -2264,  1593,  1594,     0,     0,  1595,  1596,  1597,
    1598,     0,     0,  1599,  1600,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1179,     0,     0,     0,     0,     0, -2264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1230,     0,     0,  1601,     0,     0,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1602,     0,     0,     0,     0,
       0,  1603,     0,     0, -2264,     0,     0,  2217,  1604,     0,
    1605,     0,     0,     0,     0,  1606,     0,     0, -2264, -2264,
   -2264, -2264, -2264, -2264, -2264,     0, -2264, -2264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1607,     0, -2264,  1470,  1470,  1470,  1470,  1470,  1470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1608,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1609,     0,     0,     0,     0,     0,  1610,     0,
       0,     0,     0,     0,     0,     0,     0,  1611,  1612,     0,
       0,     0,     0,     0,  1613,     0,     0,  1614,  1615,     0,
       0,     0,  1616,     0,     0,     0,     0,     0,  1617,  1618,
       0,     0,     0,     0,     0,  1619,  1620,  1621,     0,     0,
    1622,  1623,  1624,     0,     0,     0,  1625,     0,     0,     0,
    1626,     0,  1627,     0,     0,     0,     0,     0,     0,  1628,
    1629,  1630,  1631,     0,  1632,  1633,     0,     0,     0,  1634,
    1635,     0,  1636,  1637,  1638,  1639,  1640,  1641,  1642,     0,
       0,     0,     0,     0,  1643,  1644,  1645,     0,  1646,  1647,
       0,     0,  1230,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,     0,  1656,     0,     0,     0,  1657,  1658,  1659,  1660,
    1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,
    1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,
    1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,
    1691,  1692,     0,  1693,  1694,     0,     0,  1695,  1696,  1697,
    1698,  1699,  1700,  1701,  1702,  1703,  1704,     0,  1705,  1706,
    1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,
    1717,  1718,  1719,     0,     0,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,     0,  1729,  1730,  1731,  1732,     0,
    1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,
    1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,
    1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,     0,  1769,  1770,  1771,
    1772,  1773,  1774,     0,     0,  1775,  1776,     0,  1777,  1778,
    1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,
    1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,
    1799,  1800,  1801,  1802,     0,     0,  1803,  1804,  1805,  1806,
    1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,
    1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,
    1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,
    1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,     0,     0,
       0,     0,  1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,
    1873,  1874,  1875,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1876,     0,     0,     0,     0,     0,     0,
       0,  1877,     0,     0,     0,     0,  1878,     0,     0,     0,
    1879,     0,     0,  1880,  1881,  1882,  1883,     0,     0,  1884,
    1885,     0,  1886,  1887,  1888,  1571,  1572,  1573,  1574,  1575,
    1576,     0,  1577,  1578,  1579,     0,     0,     0,  1580,  1581,
    1582,  1583,  1584,  1585,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1586,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1588,     0,     0,     0,     0,
       0,     0,     0,     0,  1589,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1590,  1591,     0,     0,     0,     0,     0,     0,
       0,  1592,     0,     0,     0,     0,     0,     0,  1593,  1594,
       0,     0,  1595,  1596,  1597,  1598,     0,     0,  1599,  1600,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1602,     0,     0,     0,     0,     0,  1603,     0,     0,     0,
       0,     0,     0,  1604,     0,  1605,     0,     0,     0,     0,
    1606,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1609,     0,     0,
       0,     0,     0,  1610,     0,     0,     0,     0,     0,     0,
       0,     0,  1611,  1612,     0,     0,     0,     0,     0,  1613,
       0,     0,  1614,  1615,     0,     0,     0,  1616,     0,     0,
       0,     0,     0,  1617,  1618,     0,     0,     0,     0,     0,
    1619,  1620,  1621,     0,     0,  1622,  1623,  1624,     0,     0,
       0,  1625,     0,     0,     0,  1626,     0,  1627,     0,     0,
       0,     0,     0,     0,  1628,  1629,  1630,  1631,     0,  1632,
    1633,     0,     0,     0,  1634,  1635,     0,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,     0,     0,     0,     0,     0,  1643,
    1644,  1645,     0,  1646,  1647,     0,     0,     0,  1648,  1649,
    1650,  1651,  1652,  1653,  1654,  1655,     0,  1656,     0,     0,
       0,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,
    1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1692,     0,  1693,  1694,
       0,     0,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,     0,  1705,  1706,  1707,  1708,  1709,  1710,  1711,
    1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,     0,     0,
    1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,     0,
    1729,  1730,  1731,  1732,     0,  1733,  1734,  1735,  1736,  1737,
    1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,
    1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,
    1768,     0,  1769,  1770,  1771,  1772,  1773,  1774,     0,     0,
    1775,  1776,     0,  1777,  1778,  1779,  1780,  1781,  1782,  1783,
    1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,
    1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,     0,
       0,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,
    1862,  1863,  1864,     0,     0,     0,     0,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1876,     0,
       0,     0,     0,     0,     0,     0,  1877,     0,     0,     0,
       0,  1878,     0,     0,     0,  1879,     0,     0,  1880,  1881,
    1882,  1883,     1,     0,  1884,  1885,     2,  1886,  1887,  1888,
       0,     0,   682,   683,   684,     0,     0,     0,     0,     0,
       0,   685,     0,     0,   686,     0,     0,     0,     0,     0,
       0,   687,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,   690,     0,     0,
       0,   691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   692,   693,     0,   694,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   695,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   696,     0,     0,   697,   698,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   699,     0,   700,   701,   702,     0,     0,
       0,     0,     0,     0,     0,   703,   704,     0,   705,   706,
     707,     0,     0,     0,     0,     0,   708,     0,     0,   709,
       0,   710,   711,   712,     0,     0,     0,     0,     0,   713,
       0,   714,   715,     0,   716,     0,   717,   718,     0,     0,
     719,     0,     0,   720,   721,   722,   723,   724,   725,     0,
       0,     0,   726,   727,   728,     0,   729,     0,     0,     0,
     730,     0,   731,   732,     0,     0,     0,     0,   733,     0,
       0,   734,     0,     0,   735,     0,   736,     0,   737,     0,
     738,     0,     0,     0,   739,   740,     0,   741,   742,   743,
       0,     0,   744,     0,   745,   746,     0,   747,     0,     0,
       0,     0,     0,     0,     0,   748,   749,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   750,     0,
       0,   751,   752,     0,     0,   753,   754,     0,     0,   755,
     756,     0,     0,     0,     0,     0,     0,     0,   757,   758,
     759,     0,   760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   761,   762,   763,     0,   764,     0,     0,     0,
     765,   766,     0,     0,     0,   767,     0,     0,     0,     0,
       0,     0,     0,   768,     0,     0,     0,     0,     0,     0,
       0,   769,   770,   771,     0,     0,     0,     0,     0,   772,
     773,     0,     0,     0,     0,     0,     0,   774,     0,     0,
     775,     0,     0,     0,   776,   777,     0,     0,     0,     0,
       0,   600,   458,   459,   460,   778,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,   779,     0,     0,     0,     0,     0,     0,     0,
     780,     0,     0,     0,     0,     0,   781,     0,     0,     0,
       0,     0,     0,   474,     0,     0,     0,   782,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   783,
       0,     0,     0,     0,     0,   784,     0,   785,   786,     0,
       0,     0,     0,     0,     0,   787,  2830,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,  1290,  1291,  1292,     0,     0,     0,   274,  1293,  1294,
      33,     0,     0,     0,   788,     0,     0,     0,   474,  1295,
    1296,     0,     0,     0,     0,   789,     0,     0,     0,     0,
       0,     0,   790,     0,     0,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   791,   792,   481,   482,
     483,   793,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   794,     0,     0,     0,     0,     0,   795,
     796,   797,   798,     0,     0,     0,   799,     0,     0,     0,
     800,     0,     0,     0,     0,     0,     0,   801,   802,     0,
    1297,     0,     0,     0,     0,     0,     0,     0,   803,     0,
     804,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,   805,     0,   806,     0,     0,   807,     0,     0,     0,
       0,     0,   808,   481,   482,   483,     0,     0,     0,     0,
       0,   458,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   809,     0,
       0,   810,     0,     0,     0,     0,   811,     0,     0,   812,
     813,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,     0,   814,     0,     0,     0,     0,     0,
       0,   815,     0,     0,     0,     0,     0,     0,   484,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   816,   817,   818,   819,   820,   821,
     822,     0,     0,   823,     0,   824,  1118,   825,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   458,
     459,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,   474,
       0,     0,     0,   484,     0,     0,   485,     0,     0,   475,
     476,   477,   478,   479,   480,     0,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,   481,   482,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   458,   459,
     460,   486,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   487,     0,     0,     0,
     488,     0,   458,   459,   460,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
       0,     0,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,   489,     0,     0,     0,
       0,     0,     0,   474,   481,   482,   483,   475,   476,   477,
     478,   479,   480,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,   490,   481,   482,   483,     0,     0,
       0,   487,     0,     0,     0,   488,     0,     0,     0,     0,
       0,     0,   491,     0,     0,     0,     0,     0,     0,     0,
       0,  1298,     0,     0,     0,     0,     0,   484,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,  1299,     0,     0,  1300,     0,     0,     0,     0,
       0,     0,     0,     0,   481,   482,   483,     0,  1301,   490,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,   481,   482,
     483,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3657,  1302,     0,
       0,     0,     0,     0,   484,     0,     0,   485,     0,     0,
    1303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,     0,   493,
       0,  1304,     0,     0,     0,   487,     0,     0,   492,   488,
     585,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1305,     0,     0,     0,     0,     0,
    1306,     0,     0,     0,   484,   489,     0,   485,     0,  1307,
    1308,     0,  1309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1310,  1311,     0,     0,   484,     0,
       0,   485,  1312,   490,   493,  1313,     0,   486,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,   491,   487,     0,     0,     0,   488,   599,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,     0,   488,   609,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   489,     0,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,   491,     0,
       0,   490,   487,     0,     0,     0,   488,   977,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,   491,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
     488,   983,     0,     0,     0,     0,     0,     0,     0,   458,
     459,   460,   489,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,   493,     0,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,     0,     0,   492,
     474,     0,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,   490,     0,     0,     0,     0,     0,
     492,     0,     0,     0,     0,     0,     0,     0,     0,   458,
     459,   460,   491,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,     0,   458,   459,   460,
     474,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,   493,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,   475,   476,   477,
     478,   479,   480,     0,     0,     0,     0,     0,   474,     0,
       0,     0,     0,   492,     0,   481,   482,   483,     0,     0,
       0,   458,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,     0,     0,     0,     0,
       0,     0,   474,     0,     0,     0,     0,   475,   476,   477,
     478,   479,   480,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,     0,   481,   482,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   481,   482,   483,     0,     0,     0,   458,
     459,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,   485,   475,
     476,   477,   478,   479,   480,     0,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,   481,   482,   483,
       0,     0,     0,   458,   459,   460,     0,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   484,     0,     0,   485,     0,
       0,     0,     0,   458,   459,   460,     0,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,   485,   475,   476,   477,
     478,   479,   480,     0,   474,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,   481,   482,   483,     0,     0,
       0,     0,     0,   487,     0,     0,     0,   488,   984,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,   484,     0,     0,
     485,   475,   476,   477,   478,   479,   480,     0,     0,     0,
       0,     0,     0,   489,     0,     0,   474,     0,     0,   481,
     482,   483,     0,     0,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   490,     0,   487,     0,     0,     0,   488,   985,     0,
       0,   475,   476,   477,   478,   479,   480,     0,     0,   491,
       0,     0,     0,     0,     0,     0,   486,     0,     0,   481,
     482,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,   489,     0,   488,   986,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,   485,     0,
       0,   490,     0,   475,   476,   477,   478,   479,   480,     0,
     486,   489,     0,     0,     0,     0,     0,     0,     0,   491,
       0,   481,   482,   483,     0,   487,     0,     0,     0,   488,
     492,     0,     0,     0,     0,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,   485,     0,     0,     0,     0,   491,     0,     0,
       0,     0,     0,     0,     0,   489,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   459,   460,   988,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,   490,     0,     0,   493,     0,     0,   484,
     492,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,   491,     0,     0,     0,     0,   474,     0,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,     0,   488,   492,     0,
       0,     0,   460,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   484,     0,     0,   485,     0,   493,  2696,     0,     0,
       0,     0,   486,   489,     0,     0,  1290,  1291,  1292,     0,
       0,   474,   274,  1293,  1294,    33,   989,   487,     0,     0,
       0,   488,   492,     0,  1295,  1296,     0,     0,     0,     0,
       0,   490,     0,     0,   493,     0,     0,     0,     0,     0,
       0,     0,     0,   475,   476,   477,   478,   479,   480,   491,
       0,     0,   486,     0,     0,     0,     0,   489,     0,     0,
       0,   481,   482,   483,     0,     0,     0,   487,     0,     0,
     992,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,   493,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   491,     0,  1297,     0,   489,   475,   476,
     477,   478,   479,   480,   486,     0,     0,     0,     0,     0,
       0,     0,     0,   474,     0,     0,   481,   482,   483,   487,
     492,     0,     0,   488,     0,   490,     0,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
    3211,  3212,     0,     0,   492,     0,   274,  1293,  1294,    33,
       0,     0,     0,     0,     0,     0,   493,   490,  1295,  1296,
       0,   484,     0,     0,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,  1118,     0,     0,   492,     0,     0,     0,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     493,     0,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,   484,     0,     0,   485,
     475,   476,   477,   478,   479,   480,     0,     0,     0,  3213,
       0,     0,     0,     0,     0,   474,     0,     0,   481,   482,
     483,     0,     0,     0,     0,     0,   492,     0,     0,     0,
     493,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2697,     0,     0,     0,   487,
       0,   474,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   484,   489,
       0,   485,   475,   476,   477,   478,   479,   480,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,   474,     0,
     481,   482,   483,     0,   487,  1118,     0,   490,   488,     0,
       0,  1290,  1291,  1292,     0,     0,     0,   274,  1293,  1294,
      33,     0,     0,     0,     0,   491,     0,     0,   484,  1295,
    1296,   485,     0,     0,     0,     0,  1298,     0,   475,   476,
     477,   478,   479,   480,   489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   481,   482,   483,     0,
       0,     0,     0,     0,     0,     0,     0,  1299,     0,     0,
    2698,     0,   490,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2699,  1301,     0,     0,     0,     0,     0,     0,
     491,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,   486,     0,     0,     0,     0,   492,     0,     0,     0,
    1297,     0,     0,   481,   482,   483,   487,     0,     0,     0,
     488,     0,     0,  1302,     0,     0,     0,     0,     0,     0,
    1290,  1291,  1292,     0,     0,  1303,   274,  1293,  1294,    33,
     484,     0,     0,   485,     0,     0,     0,     0,  1295,  1296,
       0,   486,     0,     0,     0,     0,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
     488,   492,   493,     0,     0,   198,  1304,     0,     0,     0,
       0,     0,   199,     0,   490,  1290,  1291,  1292,     0,     0,
       0,   274,  1293,  1294,    33,     0,   484,     0,     0,   485,
       0,     0,   491,  1295,  1296,     0,   489,     0,     0,  1305,
    1298,     0,     0,     0,     0,  1306,     0,     0,     0,   987,
       0,     0,     0,     0,  1307,  1308,     0,  1309,     0,  1297,
       0,     0,     0,     0,   490,     0,  1118,   493,     0,  1310,
    1311,  3214,     0,     0,  3215,     0,     0,  1312,     0,     0,
    1313,     0,   491,   484,     0,     0,   485,  3216,   295,   200,
       0,  3211,  3212,   486,     0,     0,     0,   274,  1293,  1294,
      33,     0,     0,     0,     0,   201,   202,     0,   487,  1295,
    1296,     0,   488,   492,  1297,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3217,  3218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3219,
       0,     0,     0,     0,     0,     0,     0,     0,   489,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   492,   487,     0,     0,     0,   488,     0,
    2697,     0,     0,     0,     0,     0,   490,     0,     0,   493,
    3220,     0,     0,     0,     0,  1118,     0,     0,     0,     0,
    3213,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3221,
       0,   487,     0,     0,     0,   488,     0,     0,     0,   493,
       0,  3222,   490,     0,     0,     0,     0,     0,     0,     0,
    1118,     0,     0,  3223,  3224,     0,     0,     0,     0,     0,
     491,  3225,     0,     0,  3226,     0,     0,     0,     0,     0,
       0,   489,   295,     0,     0,     0,     0,     0,     0,     0,
       0,  1298,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,     0,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1299,     0,     0,  2698,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,  1118,  2699,  1301,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,   492,  2564,  2565,  2566,  2567,  2568,  2569,     0,     0,
       0,   493,     0,     0,   206,   207,   208,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1302,     0,
       0,     0,   210,     0,     0,     0,     0,     0,     0,     0,
    1303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   211,     0,     0,     0,   492,     0,
    1298,     0,     0,     0,     0,     0,   212,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,  1304,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1299,     0,   214,  1300,     0,     0,     0,     0,  2570,
       0,     0,     0,   215,     0,     0,     0,  1301,     0,     0,
       0,     0,     0,     0,  1305,  2331,     0,     0,   216,     0,
    1306,     0,     0,     0,   493,     0,     0,     0,     0,  1307,
    1308,     0,  1309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1310,  1311,  1299,  1302,     0,  1300,
       0,     0,  1312,     0,     0,  1313,     0,     0,   217,  1303,
       0,     0,  1301,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1298,     0,     0,     0,     0,   219,     0,     0,     0,
    1304,     0,  1302,   220,  3628,     0,   221,     0,     0,     0,
       0,     0,     0,     0,  1303,     0,     0,     0,     0,     0,
       0,     0,  3214,     0,     0,  3215,     0,   222,     0,     0,
       0,   223,     0,  1305,     0,     0,     0,     0,  3216,  1306,
       0,     0,     0,     0,     0,     0,     0,     0,  1307,  1308,
     224,  1309,     0,     0,     0,  1304,     0,     0,     0,     0,
       0,  3629,     0,  1310,  1311,     0,     0,     0,   225,     0,
       0,  1312,     0,     0,  1313,     0,     0,     0,  3218,     0,
       0,     0,   295,     0,     0,     0,  3630,     0,  1305,     0,
    3219,     0,     0,     0,  1306,  3631,     0,     0,     0,     0,
       0,     0,     0,  1307,  1308,     0,  1309,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,  1310,  1311,
       0,     0,     0,     0,     0,     0,  1312,     0,     0,  1313,
       0,  3220,     0,  3632,     0,     0,  2571,   295,     0,     0,
       0,  3633,     0,     0,     0,     0,     0,     0,     0,  2572,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3223,  3224,     0,     0,     0,     0,
       0,     0,  3225,     0,     0,  3226,     0,     0,     0,     0,
       0,  2573,     0,   295,     0,     0,     0,  2574,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2576,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2577,  2578,     0,     0,     0,     0,  2579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2580,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2581,     0,
       0,  2582,  2583,     0,     0,     0,  2584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2585,     0,     0,     0,     0,     0,     0,
       0,     0,  3635,     0,  2586
};

static const short yycheck[] =
{
       3,     4,     5,   189,   394,     8,   655,   105,  1055,   170,
     587,   125,    45,   590,  1463,  1173,  1002,  1144,  1145,  1148,
    1147,  1378,  1149,  1150,  1133,   261,   262,  1130,  2126,   795,
    1371,    54,  2383,   779,  1933,   259,   260,    40,  1290,  1291,
     544,  2366,   266,  2368,   172,  2013,  2014,  2015,  2016,    52,
     597,    54,  2329,   639,  1898,  1899,  1403,    90,  1325,     5,
    1327,  1129,    65,   718,  2071,  2676,    26,    27,   570,    72,
    2520,  2381,   170,    76,  2065,    27,    79,    80,    27,  1168,
      20,    84,    85,  2918,  2919,  2920,  2074,    27,   719,  2452,
      27,   189,    25,    20,    27,     5,  2249,     5,    25,  1421,
      27,   104,     5,    19,   754,  2004,    27,    19,     5,     5,
      26,     5,   743,  2563,    26,  2921,    69,     5,   121,  1222,
      20,   124,   236,   237,     5,    25,   129,    27,    27,   715,
       5,     5,    45,  1236,    27,   263,    25,     8,    27,   267,
     726,   269,   152,   271,   272,   273,  1255,     5,    27,    25,
      26,    27,   280,    25,     5,    27,   284,   285,   789,   320,
     815,     5,    30,   116,     5,    25,    34,    27,   799,   785,
       5,   802,  2691,    27,  2693,   806,     5,    90,    27,  1226,
      46,   812,   212,   814,  2377,  2378,  2379,     6,   191,  2382,
      24,    25,    26,    27,   147,   781,   797,    24,   784,    26,
     115,     5,    25,    19,    27,   281,     5,   793,    24,    25,
      26,     5,    27,    24,    25,    26,    27,    24,    25,    26,
      27,     5,   320,    25,     5,    27,   324,    27,     5,    61,
     233,   134,   135,     5,     5,    25,   239,    27,   106,    24,
      25,    26,    27,  2638,   203,   113,     5,  2605,   251,    24,
      25,    26,  2445,  3006,   257,   258,   259,   260,   261,   262,
    2261,   413,   443,   266,     6,   190,   445,    24,    25,    26,
      27,   224,  2559,   226,   140,   141,    25,   121,    27,   123,
     289,   125,   394,   243,   203,   115,   691,   191,   192,     5,
      19,   159,   160,     6,     5,   117,    23,    26,   227,   167,
       5,   288,   196,   327,    27,   433,   138,   139,   436,   445,
     313,   314,    26,   510,  2917,  2918,  2919,  2920,   723,   724,
     323,  2303,   143,   510,  2306,   453,   454,   455,   456,   515,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,  2698,  2625,     5,
    1418,     5,   118,   577,   243,   399,  2454,   485,   486,   627,
     216,  2656,   490,    27,   492,    98,    99,   100,   101,   102,
     775,     5,   394,   597,     5,   527,   445,   505,   506,   507,
     508,   958,   445,  1129,   512,   597,     5,     5,   341,   394,
    2358,     5,   414,   482,   347,   324,   689,   690,   458,   667,
     482,   589,     5,     5,     5,     5,     5,   482,   301,   243,
     445,    23,   673,   698,   477,  1462,  2609,   515,   579,   327,
     243,    18,    19,    20,    21,    22,  2619,   509,   510,  2724,
     327,  1520,   243,    20,   727,  3567,  1067,   730,   589,  3571,
      27,   243,    18,    19,    20,    21,    22,   740,   401,    10,
     638,   744,     5,  1155,  1156,   748,   668,   335,   243,     5,
       5,   640,   755,     5,     5,   297,   727,   760,   654,   762,
     348,     5,     5,   670,     5,   768,     5,   429,   771,   764,
     489,   579,     5,   670,   636,   778,   243,   638,   204,     5,
     572,     5,   785,   204,   243,    56,     5,     0,     5,   792,
      25,   504,    27,    31,   640,  2917,  2918,  2919,  2920,     5,
     803,   404,   545,   546,   807,     5,     0,   629,   811,    27,
     243,  2714,    28,     5,   817,   404,     5,   820,   709,   445,
     517,   607,    16,     5,   537,  2893,  2894,   540,     5,     5,
       5,     5,  1173,   399,     5,   548,     5,     5,   772,    29,
    1181,     5,  1183,   421,   790,   791,   654,     5,     5,     5,
     287,   327,   565,  2850,   567,     5,   596,     5,    30,   556,
       5,   640,    34,   576,   577,     5,     5,   580,     5,     5,
       5,   534,     5,   819,   488,   662,   822,   676,     5,  1190,
     107,   108,   552,     5,   597,   619,    18,    19,    20,    21,
      22,   676,   646,   481,   404,   640,  2607,   629,  3211,  3212,
     445,   560,  3215,  2457,  2891,  3368,   445,   388,   577,   441,
     137,   138,   139,    10,   629,  2818,   445,   438,   482,   522,
    2955,   336,   545,   399,   428,    27,   646,   478,  1254,    27,
     565,   445,   464,   522,  2995,   605,   445,  1052,   516,     9,
      10,  3457,    12,    13,    14,    15,    16,    17,   577,    27,
     612,  2643,   492,   448,   445,   514,   128,   482,   439,  1074,
     875,   443,  1418,   448,   677,   287,  1180,   443,   593,   682,
     683,   684,   685,   686,   687,   688,   445,   590,   691,   692,
     693,   448,   482,   696,   478,   698,  3146,  2596,   701,   522,
     703,   478,    27,   445,  1281,   601,   566,  1284,  1285,   712,
    2903,   619,  2053,    38,  3164,  1364,   445,  2074,   243,   607,
     723,   724,   619,   597,   640,   547,   607,   538,   640,   604,
     733,   445,   445,   604,  2887,   662,   739,   522,   627,   597,
     608,   640,   745,   746,   747,  3070,   667,  3072,   751,  3268,
     601,   754,  3062,   756,   757,  2746,  3119,  2764,   668,   719,
    3123,   764,   662,   593,   767,   717,   712,  2216,   717,   772,
     773,  1273,   775,   667,   677,  1425,   779,   717,  2766,   782,
     717,  2103,  3092,  2105,   717,   788,   662,   790,   791,   445,
     662,   445,   795,   796,   797,  1426,  1427,  1428,   801,  3211,
    3212,   804,  2149,  3215,   416,   216,   809,   336,  1510,   589,
     676,  3422,  1443,   816,  3209,   818,   819,   639,   821,   822,
     688,   824,   825,  1424,   668,  3436,   445,   289,   696,   651,
     652,   445,   676,   158,   636,  1436,   670,   659,  3673,  3442,
    1133,   673,    23,   670,   478,  3448,  3449,   478,  3451,  3452,
    3453,  3454,   601,   619,   670,  3250,   386,  3460,   638,   670,
     478,    27,   990,   670,  3057,   993,  3059,   420,   689,   690,
     691,   692,   693,  1001,  1002,   478,   478,   478,   478,   478,
    1511,   478,  1272,   208,   667,   670,     9,    10,   396,    12,
      13,    14,    15,    16,    17,   670,   404,   405,  1529,   445,
     445,   634,   478,   445,   445,    27,   298,    25,    27,    27,
     298,   445,   445,   670,   445,   302,  1547,  3449,   243,   311,
     245,   429,   445,   311,   432,   928,   295,  1558,  3460,   445,
     298,   445,   445,   699,   700,   701,   445,   413,   445,  3264,
     448,  3266,  3267,   311,   710,   305,   670,  1152,   410,   445,
     445,    25,   505,    27,  1159,   445,  2800,  3568,   482,   510,
    1253,  1254,  1255,   445,    28,    29,   445,  3417,   521,  3294,
    1556,  3574,   975,   445,  3577,  3578,  3579,  3580,   445,   445,
     445,   445,   445,   348,   445,   509,   445,   445,   399,   506,
     379,   445,  3235,  1398,  1541,   408,   458,   445,   445,   445,
    3351,     5,  1407,  3196,    25,   445,    27,   445,   379,    30,
     445,   564,  1015,  3206,  1017,   445,   445,   342,   445,   445,
     445,   413,   445,   445,  1528,   413,  2155,   489,   445,  1434,
    3442,   482,    25,   445,    27,   565,  3448,  3449,     5,  3451,
    3452,  3453,  3454,   532,   552,   413,   576,   408,  3460,  1052,
     603,   527,  1055,   440,   522,   442,   518,  1010,  2984,   510,
    2986,  3664,   530,  2989,  2331,   425,   426,   217,  1071,   219,
    3673,  1074,  2429,   510,  2142,   592,  2433,   243,  3275,   632,
     450,  3278,   335,    14,  3281,   445,   411,   342,   641,   482,
     482,    25,   573,    27,   419,   348,  3289,   605,   423,   354,
    2203,   540,   482,   217,   612,   219,   287,   509,   510,   548,
    1113,  3462,    26,    27,   482,  1118,   481,   510,   635,   670,
     480,   243,    26,    27,   243,   243,  1129,   640,  2395,  2396,
     244,    25,  3556,  3557,   459,   527,    25,   712,    27,   527,
    1143,  1144,  1145,   532,  1147,   640,  1149,  1150,    25,  3426,
      27,   543,  1155,  1156,    25,   543,    27,   669,   733,   527,
     636,   532,  3574,   166,   676,  3577,  3578,  3579,  3580,   243,
      25,   746,    27,   323,   675,   543,   326,   640,   298,   301,
    2289,    25,   305,    27,   595,  1188,   675,  1190,    26,    27,
      25,   311,    27,   372,  3437,  3438,  1199,   698,   348,  1202,
     525,  1437,  2188,   482,  1207,   694,   695,    26,    27,   323,
      26,    27,   326,    20,    25,  1439,    27,   628,   510,  3643,
      27,  3645,   243,  1226,  1227,   714,    19,   298,   481,   154,
     155,    24,  1235,    26,   348,   416,  3429,   730,   677,   564,
     311,    26,    27,   640,   509,   510,   211,   607,  1251,  1252,
     243,   744,  3664,  1367,   482,   748,  1370,   259,   260,   261,
     482,  3673,  3215,   588,   482,   662,   636,   760,   289,   639,
     477,   217,   438,   219,  1277,    43,    44,    45,    20,    24,
      48,    26,    50,    51,    20,    27,   675,  1290,  1291,   675,
    1451,    27,  3489,   413,   690,   691,  3621,  1300,   244,  3198,
    1536,  1537,   425,   426,   675,   694,   695,   632,   482,   243,
    1313,   697,   698,   673,   482,    19,   641,  1541,  1321,   438,
      24,    25,    26,   694,   695,   714,    18,    19,    20,   243,
    3523,   481,    24,    25,    26,    27,   230,   675,  1305,   243,
    1307,  1308,   413,   714,    36,    37,   311,   692,   693,    24,
      25,    26,    27,  1451,   243,   975,  3282,   480,    20,   697,
     698,    36,    37,   723,   724,    27,   243,   481,    26,  1372,
    1393,    20,   243,  1376,  1377,  1378,   640,   323,    27,   689,
     326,   291,   692,   693,   349,  1388,  1389,  1390,   243,   410,
    1393,  1394,  1395,  1396,  1397,  1398,  2142,  2738,   662,   243,
     725,   726,   348,  1980,  1407,   243,  1983,   527,   243,  2766,
    2677,   482,  2679,    20,  2681,  1418,    24,  1420,    26,  1422,
      27,  1424,  1425,   543,   243,   117,   291,   243,   482,  1432,
    1433,  1434,   482,  1436,  1437,  2482,  1439,  1440,   348,    43,
      44,    45,   117,   482,    48,  1448,    50,    51,   413,    25,
     452,    27,  1455,  1456,  2543,   291,   527,   510,   243,  1462,
    1463,     5,   427,   357,     8,   482,  2097,    20,   489,   363,
     364,   365,   543,  3441,    27,  3443,  3444,  3445,  3446,   699,
     700,   762,  2113,   348,   607,   663,   664,   665,   666,  3442,
     771,   385,   402,  2259,   482,  3448,   406,   518,  3451,  3452,
    3453,  3454,  2611,  2379,  1507,  1508,  2382,  1510,  2094,  2140,
    1513,  1514,   348,   482,   390,   818,  2147,  1922,   821,  1924,
    1925,   824,  2177,  1928,  1929,   401,   482,  3625,  2637,  1934,
      25,  1534,    27,  1536,  1537,   481,   817,   402,  1541,   820,
    1543,   406,  1545,  1546,  3642,  2176,   482,   420,   191,   803,
     673,   243,   195,   807,   482,   323,   482,   811,   326,    25,
     328,    27,   527,   482,  2195,  1568,   402,    25,   243,    27,
     406,   481,  1153,  1154,   482,   451,  1157,  1158,   543,   482,
     348,   509,   510,   482,    24,  2186,    26,   640,   482,   465,
     358,   482,   689,   690,   482,  3693,   490,   694,   695,   493,
     723,   724,   420,   720,   721,   722,    24,   501,    26,   662,
     707,   379,  3710,   482,   420,  2020,   481,   670,    24,    25,
      26,  3574,     5,   482,  3577,  3578,  3579,  3580,   482,    25,
     727,    27,   505,   730,   402,   482,    20,    21,   406,   736,
     699,   700,   536,   740,   572,   481,   510,   744,   521,   340,
     341,   748,  2253,  3211,  3212,   752,   753,   482,   755,  1895,
    1896,   758,   482,   760,   761,   762,    26,  2171,    43,    44,
      45,   768,   482,    48,   771,    50,    51,   571,   554,  2782,
    1300,   778,    18,    19,    20,    21,    22,   505,   785,    26,
      25,   564,    27,  3142,   482,   792,   590,   591,  2827,   505,
      25,  2859,    27,   521,  2756,  2757,   803,   601,   482,   482,
     807,  3664,   606,   481,   811,   521,   162,   163,   164,   323,
     817,  2824,   326,   820,   328,    24,    24,    26,    26,   676,
     603,  2983,  2984,    25,  2986,    27,  2141,  2989,    25,   676,
      27,  2318,    26,    26,   348,  3102,   564,  2324,  2325,    26,
      24,   645,    26,    26,   358,   695,   448,   670,   564,   632,
     144,   145,   146,   147,   148,   149,   482,   707,   641,    24,
     482,    26,    25,   448,    27,   379,   577,    20,    21,   420,
    1420,   482,  1422,   677,   482,   603,   482,   479,   482,   482,
     482,    26,  2423,   482,  2883,   482,   736,   603,   402,   472,
    3249,   510,   406,   495,   479,    26,   482,   482,  2439,  2440,
    2441,  2442,   752,   753,   632,    26,    26,    26,   758,    26,
     495,   761,    26,   641,    26,   670,   632,   445,   482,  2460,
     522,   420,   111,  2434,   415,   641,   670,  2438,  2131,    26,
     445,     5,   482,   535,  2430,   482,  2447,   478,   445,  2835,
     482,  1965,   445,   445,   445,   547,   522,  2843,  2844,   445,
     535,   445,  2267,   482,   505,    20,    20,   676,   482,   482,
     445,  2472,   547,     5,   114,   510,   977,   481,   674,   980,
     521,   982,   983,   984,   985,   986,   482,    26,   670,   420,
      26,  1894,  1895,  1896,   445,  2526,   588,  2483,  1901,  1902,
     420,   144,   145,   146,   147,   148,   149,   445,   311,   478,
     415,  2039,  2148,   588,    30,    20,   505,    26,  1921,  1922,
      26,  1924,  1925,   564,    26,  1928,  1929,    26,  1931,   621,
     313,  1934,   521,    26,  2048,   627,    26,    26,   640,   445,
      26,   445,   445,  2348,   636,   637,  2532,   639,   323,   189,
      26,   326,   627,   328,   445,  1958,   445,     5,   445,   651,
     652,    20,   603,  2256,   639,    26,  1969,   659,   482,   352,
     662,    26,  3421,   348,   505,   564,   651,   652,   670,    26,
      26,   445,   670,   358,   659,   505,     5,   662,   371,   372,
     521,   632,   445,   676,    26,   670,  2289,  2628,   445,  2630,
     641,   521,   355,  2006,   379,  2008,   445,   445,   445,  2233,
    2234,   251,  2248,   253,   603,  2018,  2019,  2020,   445,   674,
    2023,     5,  2025,  2026,  2027,  2028,   445,   402,   411,   269,
    3282,   406,   213,   564,   445,  2038,  1133,   277,   482,  2444,
     423,   281,  2170,   632,   564,   189,   676,   228,   229,    26,
      47,   434,   641,   445,    26,   640,   237,  2060,   445,   676,
    2188,    25,  2065,    25,    25,   445,   306,   450,  2071,    25,
     355,  2074,   603,   445,   717,   718,   445,   460,   445,   445,
     445,   445,  2659,   603,   445,  2662,   445,  2664,  2665,  2092,
     271,  2044,   475,   445,   445,  2098,   674,   445,   445,   280,
     670,   632,   670,   482,  3151,     8,   481,   251,   675,   253,
     641,   646,   632,   530,   319,   478,   511,     5,   668,   668,
     646,   641,   189,   472,  2127,   269,   511,   709,   309,   709,
     670,   381,   515,   277,   510,   662,   670,   281,  2141,  2142,
     647,     5,  2145,  2146,   472,  2148,     5,   144,   145,   146,
     147,   148,   149,   482,   399,   538,  1253,  1254,  1255,   482,
    2163,  2792,   306,   482,  2795,   162,   163,   164,   482,  3155,
     553,   482,   815,   354,   629,   640,     8,   560,    14,     5,
     563,  2184,   825,  2186,   251,  2786,   253,   709,     5,  2594,
     626,   709,   472,    18,    19,    20,    21,    26,    26,   118,
     143,   584,   269,   510,  2207,   588,  2209,  2210,   490,  2212,
     277,   482,  2215,  2216,   281,   482,   670,   398,  2623,   501,
    2821,    26,   482,   482,   607,   292,   640,    26,  2859,   510,
    2233,  2234,     5,   482,  2639,   482,   482,   646,   482,   306,
     522,   482,   625,   482,   472,  2248,   482,   529,   482,     5,
    2253,  2254,  2255,   676,    46,   537,  2259,   220,   482,   482,
     676,   712,   675,   405,  2267,    18,    19,    20,    21,   607,
       5,    18,   206,   667,    19,   437,    25,   559,   640,   629,
     673,   533,   533,  3372,   670,     5,  2691,   597,  2693,   204,
      26,  2294,  3381,   597,   452,   376,   597,    26,   445,  2302,
    2303,    26,  1263,  2306,  2465,   302,   482,   445,   305,  3398,
     445,   445,  2605,   670,   522,   577,   445,   482,  2611,   144,
     145,   146,   147,   148,   149,   482,  2329,   110,     5,   482,
     676,   676,   975,   482,   482,  2338,   714,   670,  2341,  2342,
    2343,  2344,  2345,   640,  2637,  2348,   670,   445,     5,  2352,
    2353,   640,  3461,  2356,   482,   597,  3011,  3012,  3013,   667,
    3015,  3016,  3017,  3018,  3019,  3020,     5,  2465,     5,  3024,
     676,     5,   630,   534,  2377,  2378,  2379,   670,   482,  2382,
    2383,  2384,   676,     5,  2387,   675,  2006,     8,  2008,   372,
      26,   144,   145,   146,   147,   148,   149,    26,  2018,  2019,
     118,   271,   380,     5,     5,  2025,  2026,  2027,  2028,   445,
     482,   482,  1055,  2416,  2819,  2418,  2419,   647,  2421,  2422,
     414,    14,  2425,   601,   710,   597,  2429,     5,   425,    26,
    2433,  2434,   482,    25,   597,  2438,   152,   670,   676,   676,
     482,  2444,  2445,   440,  2447,  2448,   675,   444,  2451,  2452,
       5,    20,    21,    22,   676,   675,  3545,    17,    18,    19,
      20,    21,    22,   689,   478,    26,   445,     5,     5,  2472,
     433,   445,   445,     5,   422,   669,  2479,   386,    47,  2482,
      26,   512,   478,   480,   447,   512,     5,    47,  2491,   482,
     482,   482,  2495,   482,   482,   482,   482,   482,     5,  3130,
     670,  3628,  3629,  3630,  3631,  3632,  3633,  3554,  3109,     8,
     670,   508,   510,     5,   670,   627,   604,  2520,  2006,   380,
      25,   399,   399,   399,   670,   482,   477,   490,   510,   526,
     414,     5,     5,   701,   510,  3166,  3137,    26,   501,     5,
       5,  2544,    18,    19,    20,    25,    14,    14,    24,    25,
      26,    27,   646,   667,    26,   646,   482,     5,     5,   522,
      36,    37,   445,   604,  3653,    26,   529,     6,   482,   676,
     445,   445,   445,   445,   537,   144,   145,   146,   147,   148,
     149,     7,   445,  1226,   144,   145,   146,   147,   148,   149,
     321,  2594,  2212,   162,   163,   164,   559,   499,   445,   445,
    2893,  2894,   162,   163,   164,     5,  2609,   670,    26,    26,
     607,   676,    26,    26,  2617,  2618,  2619,    26,   670,  2622,
    2623,   670,  2625,  2656,   445,    20,     5,   617,   327,     5,
       5,   597,     5,   718,     8,  2638,  2639,     5,   230,  2642,
    2643,   117,   445,   445,   670,   482,  3295,  1290,  1291,  2873,
       5,  2875,   622,   522,   676,   597,  2817,  1300,  3644,     5,
     676,   264,   674,   445,   445,    26,   445,   676,   676,   676,
     482,   482,  2858,   636,     5,     5,   673,   676,  3083,   642,
    2683,  3258,    25,  3260,  3261,    25,    25,    25,  2691,   498,
    2693,  2724,    25,  2696,   674,  2698,   349,    26,   669,    26,
      26,    26,  2830,    26,    26,   445,  2709,  2835,   445,  2329,
      26,  2714,  2715,  2716,     5,  2843,  2844,   445,  2338,  2817,
     482,  2341,  2342,  2343,  2344,  2728,   445,  2215,   519,  3776,
    2697,     5,  2699,   302,   482,   445,   305,     8,    26,   601,
     293,   445,   302,  2746,    25,   305,  3377,   399,   478,   492,
      20,   195,   604,     5,    14,   482,    40,     5,   482,   482,
    2858,  2764,   264,  2766,   445,   357,   445,   243,   482,   482,
     482,   363,   364,   365,  3375,   482,  2779,     5,   493,    26,
     445,  3412,    26,  2786,   510,   445,    26,   445,   482,    26,
      26,    26,  3393,   385,    26,   428,   619,   445,   293,   445,
     445,   399,    53,    54,    55,    56,    57,    58,  2811,   482,
    2813,   294,  2815,   445,   510,  2818,  2819,   492,  2821,  1462,
     104,   105,   597,   482,    14,   445,   445,   445,     7,   292,
     292,    26,   445,  2836,   676,  2838,  2839,  2840,   445,   482,
     446,   445,   626,   670,    26,   445,   445,   482,   478,    25,
    2853,   294,     5,    26,   445,   445,   425,  2860,   445,   445,
     510,    26,   445,  3268,   670,   425,   670,  3257,     5,   478,
    2873,   440,  2875,   445,    26,   444,   670,  2838,  2779,  3703,
     440,  1001,  2885,  2886,   444,  1548,   170,  2516,  2891,   478,
    2196,  3127,    31,    29,  2448,  2454,   352,  2811,   490,   150,
    2903,   493,   112,   116,  3140,   189,   206,   343,   658,   501,
    2043,   480,   353,  2044,  2917,  2918,  2919,  2920,  2921,  2922,
     480,   224,   534,   382,   211,   553,   600,   381,  2931,   567,
    3693,  1289,  2097,  2936,   565,  3536,   993,   415,  1260,   508,
    2307,   801,  2300,  2441,   536,  2147,  1894,  3176,   508,  2223,
    2917,  2918,  2919,  2920,  1897,  2862,  2540,   526,  3747,  2444,
    3121,  2243,  1439,  3389,    16,    90,   526,    40,  3316,  2972,
    2973,    40,   448,   257,    22,  2201,   930,   757,  2207,   571,
    2983,  2984,  1559,  2986,  1017,  1902,  2989,   324,  2991,  1508,
    3313,  2210,  2995,  3498,   782,  1956,  1957,  1506,   590,   591,
    1227,  1433,  1963,   479,  3710,  2625,   482,  2860,  3639,   601,
    1422,  3051,  3508,  1529,   606,  2176,  3033,   452,  2985,   495,
    2987,  3598,  3599,  3121,  3049,  2727,  3107,  3155,  3369,   313,
     314,  3367,  3035,  3360,  2131,  3099,   320,  2077,   607,  2433,
     324,  2060,  2605,  2387,  3719,  3048,  3289,   607,  2278,  1936,
    1936,  2624,  3208,   645,  3057,  3058,  3059,  3056,   534,   535,
    3523,  3090,  2348,  2683,  2973,  2266,  2972,  3603,  2696,  3279,
    3078,   547,  2749,  1921,  3332,  2728,     8,  3765,  2698,  1256,
    3083,  2716,  2715,  3210,  2904,   677,  2019,  3287,  2018,  2709,
    1916,  3564,  3095,  3096,  3205,  3440,  3099,  2618,  1889,  3102,
    1252,  3459,  3448,  2038,   673,  1118,  3109,  2819,  1448,  2817,
    2465,  3742,   588,   673,  1456,   543,  3119,  1438,    -1,  3122,
    3123,    -1,    -1,    -1,  3127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3137,    -1,   387,  3140,    -1,  3142,
      -1,    -1,    -1,    -1,    -1,   621,    -1,  3371,  3151,   400,
      -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2256,
     636,   637,    -1,   639,    -1,    -1,    -1,    -1,  3461,    -1,
      -1,    -1,    -1,    -1,    -1,   651,   652,    -1,    -1,    -1,
      -1,    -1,    -1,   659,    -1,   116,   662,  3190,    -1,    -1,
      -1,    -1,  2289,  3196,   670,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3205,  3206,    -1,  3208,  3209,    -1,  3211,  3212,
      -1,   462,  3215,    -1,    -1,    -1,    22,   468,  2179,    -1,
     504,    -1,    -1,  3226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2860,    47,    -1,    -1,  3211,  3212,  3249,  3250,  3215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,  2219,  1902,
      -1,    -1,    -1,    -1,    -1,  3268,    -1,    -1,    -1,    -1,
      -1,  2891,    -1,  3276,    -1,    -1,  3279,    -1,    -1,  3282,
     531,    -1,  3285,    -1,  3287,    -1,  3289,    -1,    -1,    -1,
     541,   542,    -1,    -1,    -1,   579,   547,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,    -1,
    3313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,
      -1,   582,   583,    -1,    -1,    -1,   587,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,  3351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
      -1,    -1,    -1,  2006,    -1,  2008,    -1,    -1,  3371,    -1,
     654,  2991,  3375,    -1,  3560,  2018,  2019,    -1,    -1,    -1,
    2761,    -1,  2025,  2026,  2027,  2028,    -1,    -1,    -1,    -1,
    3393,    -1,    -1,   644,    -1,    -1,    -1,    -1,   682,   683,
     684,    -1,   686,    -1,   655,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3421,   703,
      -1,   352,    -1,  3426,    -1,    -1,  3429,    -1,    -1,  2917,
    2918,  2919,  2920,    -1,    -1,    -1,    -1,  3440,    -1,  3442,
      -1,   372,   373,   374,    -1,  3448,  3449,    -1,  3451,  3452,
    3453,  3454,    -1,    -1,  3457,   739,  3459,  3460,    -1,  3462,
      -1,   745,  3560,   747,    -1,    -1,    -1,   751,    -1,    -1,
     754,    -1,    -1,   757,    -1,  3442,    -1,    -1,    -1,    -1,
     411,  3448,  3449,   767,  3451,  3452,  3453,  3454,    -1,    -1,
      -1,    -1,   423,  3460,    -1,  3498,   302,    -1,   782,   305,
    3503,    -1,  3505,   434,   788,    -1,    -1,    -1,  2605,    -1,
      -1,   795,   796,   797,  2611,    -1,  3644,   801,    -1,   450,
    3523,    -1,    -1,    -1,    -1,   809,    -1,    -1,    -1,   460,
      -1,    -1,    -1,  3536,  2177,    -1,  2917,  2918,  2919,  2920,
    2637,   825,    -1,    -1,   475,    -1,    -1,    -1,    -1,  2510,
    2511,  3554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2521,  3564,    -1,    -1,    -1,    -1,    -1,  3570,    -1,  2212,
      -1,  3574,    -1,    -1,  3577,  3578,  3579,  3580,    -1,  3582,
      -1,    -1,    -1,    -1,  2545,  2546,  2547,  2548,  2549,  2550,
      -1,    -1,   523,  3596,  2555,  2556,  2557,  2558,    -1,    -1,
    3603,  2562,    -1,    -1,  3607,    -1,    -1,  3574,    -1,    -1,
    3577,  3578,  3579,  3580,    -1,    -1,    -1,    -1,    -1,   425,
      -1,    -1,   553,    -1,    -1,  3628,  3629,  3630,  3631,  3632,
    3633,    -1,   563,    -1,   440,    -1,    -1,  3640,   444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   584,   172,    -1,    -1,   588,    -1,    -1,
      -1,  3664,    -1,    -1,    -1,  3285,    -1,  3287,    -1,    -1,
    3673,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2644,  2645,   616,  2329,    -1,    -1,    -1,
    2651,  2652,    -1,    -1,   625,  2338,    -1,  3664,  2341,  2342,
    2343,  2344,   508,    -1,    -1,    -1,  3673,    -1,    -1,    -1,
    2353,    -1,    -1,    -1,    -1,    -1,  3719,    -1,  3721,    -1,
     526,    -1,    -1,  3211,  3212,    -1,    -1,  3215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2383,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,   274,    -1,    -1,    -1,
    3763,  3764,  3765,    -1,   282,    -1,    -1,    -1,    -1,    -1,
     288,  1055,   290,  3776,    -1,  3778,    -1,    47,    -1,    -1,
      -1,    -1,    -1,   301,    -1,    -1,    -1,  1071,  3276,    -1,
      -1,  3279,    -1,    -1,    -1,    -1,  2893,  2894,    -1,    -1,
      -1,   607,    -1,    -1,    -1,    -1,  3426,    -1,    -1,    -1,
      -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3440,    -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,  1113,
    3211,  3212,   350,    -1,  3215,    -1,    -1,    -1,    -1,  2482,
    2801,  2802,    -1,    -1,   362,    -1,    -1,    -1,    -1,  2810,
      -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1143,
    1144,  1145,    -1,  1147,    -1,  1149,  1150,   673,    -1,    -1,
      -1,  1155,  1156,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,  2847,  2848,    -1,    -1,
      -1,    -1,   162,   163,   164,  3276,    -1,    -1,  3279,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1190,    -1,    -1,    -1,
      -1,    -1,    -1,  2874,    -1,  2876,    -1,    -1,  1202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1226,  1227,    -1,    -1,    -1,    -1,    -1,    -1,
    3570,  1235,  3440,    -1,  3442,    -1,    -1,    -1,    -1,    -1,
    3448,  3449,    -1,  3451,  3452,  3453,  3454,  1251,  1252,    -1,
      -1,    -1,  3460,    -1,    -1,    -1,  2937,  2938,    -1,    -1,
    2941,  2942,  2625,    -1,    -1,    -1,    -1,  3607,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,
      -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,
      -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,   302,   551,    -1,   305,    18,    19,   556,    -1,
    2683,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2696,    -1,  2698,    38,    -1,    -1,    -1,
      -1,  3442,    -1,    -1,    -1,    -1,  2709,  3448,  3449,    -1,
    3451,  3452,  3453,  3454,    -1,    -1,    -1,    -1,  3039,  3460,
      -1,    -1,    -1,    -1,    -1,    -1,  3574,    -1,    -1,  3577,
    3578,  3579,  3580,    -1,    -1,    -1,    -1,    -1,  3479,  3719,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3603,    -1,    -1,  2761,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,   117,  1420,    -1,  1422,    -1,
    1424,  1425,   124,    -1,    -1,    -1,    -1,    -1,  1432,  1433,
      -1,    -1,  1436,    -1,    -1,   425,  1440,    -1,    -1,  3120,
      -1,    -1,    -1,  3124,    -1,    -1,    -1,  1451,    -1,   151,
     440,    -1,    -1,    -1,   444,    -1,  3664,    -1,  1462,  1463,
      -1,    -1,  3143,    -1,    -1,  3673,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3574,    -1,    -1,  3577,  3578,  3579,  3580,
      -1,  3162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,  2860,    -1,    -1,
      -1,    -1,  3603,  1507,  1508,    -1,  1510,    -1,    -1,  1513,
    1514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   508,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2891,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   526,    -1,    -1,  1543,
    3357,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
    3367,    -1,    -1,    -1,  2917,  2918,  2919,  2920,    -1,    -1,
      -1,    -1,    -1,  3664,  1568,    16,    17,    18,    19,    20,
      21,    22,  3673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,  2972,
    2973,    -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,    -1,
    2983,  2984,    -1,  2986,    -1,    -1,  2989,    -1,  2991,    -1,
      -1,    -1,  2995,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     342,    -1,    -1,    -1,  3461,   347,    -1,    -1,  3011,  3012,
    3013,    -1,  3015,  3016,  3017,  3018,  3019,  3020,    -1,    -1,
      -1,  3024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,   411,
      -1,   162,   163,   164,    -1,    -1,    -1,    18,    19,    -1,
      -1,   423,    -1,    24,    25,    26,    27,    -1,   185,  3410,
      -1,    -1,  3413,    -1,    -1,    -1,   193,    38,    -1,   441,
      -1,    -1,    -1,    -1,   446,   202,   448,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   459,    -1,    -1,
      -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,   479,    -1,    -1,
     482,    -1,    -1,   485,    -1,    -1,    -1,    -1,  3151,    -1,
      -1,   248,   494,   495,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   534,   535,    -1,    -1,    -1,   539,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   547,    -1,    -1,  3211,  3212,
     151,   302,  3215,    -1,   305,   312,   558,    -1,    -1,    -1,
      -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3558,    -1,    -1,
     337,    -1,    -1,    -1,    -1,    -1,   588,   344,    -1,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1901,  1902,   356,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3276,    -1,    -1,  3279,    -1,    -1,  3282,
      -1,    -1,  3285,    -1,  3287,    -1,    -1,   384,  3609,  3610,
     632,  3612,    -1,  3614,  3615,   392,    -1,   639,    -1,   641,
      -1,    -1,   243,    -1,   245,    -1,    -1,    -1,    -1,   651,
     652,    -1,    -1,    -1,  1958,    -1,    -1,   659,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,   670,    -1,
      -1,    -1,   429,    -1,   425,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,  3351,   440,
      -1,    -1,    -1,   444,    -1,    38,   453,    -1,    -1,    -1,
    3681,    -1,  3683,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,   725,   726,    -1,    26,    27,    -1,   480,
      -1,    -1,    -1,   490,    -1,    -1,  3717,    -1,    38,    -1,
      -1,   342,    -1,    -1,   501,    -1,   347,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3736,  3737,   508,    -1,  3740,
      -1,    -1,  3743,  3426,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,   117,   526,   377,  3440,    -1,  3442,
      -1,   124,    -1,    -1,    -1,  3448,  3449,    -1,  3451,  3452,
    3453,  3454,    -1,    -1,    -1,    -1,    -1,  3460,    -1,  3462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,
     411,    -1,   112,    -1,    -1,    -1,  3479,    -1,    -1,    -1,
      -1,    -1,   423,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     441,    -1,   599,   600,   601,   446,    -1,   448,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   612,   607,    -1,   459,  2163,
      -1,    -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,   479,    -1,
      -1,   482,  2186,    -1,   485,    -1,    -1,    -1,    -1,    -1,
      -1,  3554,    -1,   494,   495,    -1,    -1,    -1,    -1,    -1,
     243,    -1,   245,  2207,    -1,    -1,    -1,  3570,    -1,    -1,
      -1,  3574,  2216,    -1,  3577,  3578,  3579,  3580,    -1,    -1,
      -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   534,   535,    -1,    -1,    -1,   539,    -1,
    3603,    -1,    -1,   243,  3607,   245,   547,    -1,    -1,  2253,
    2254,  2255,    -1,    -1,    -1,  2259,    -1,   558,   715,    -1,
      -1,    -1,    -1,   564,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,   588,    -1,    -1,
    2294,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,   342,
      -1,  3664,    -1,    -1,   347,    -1,    -1,    -1,    -1,    -1,
    3673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   632,    -1,    -1,   377,    -1,    -1,    -1,   639,    -1,
     641,    -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     651,   652,    -1,    -1,    -1,    -1,  3719,    -1,   659,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,   670,
     112,    -1,    -1,    -1,    -1,   117,    -1,   377,    -1,    -1,
     423,    -1,   124,   126,   127,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,
      -1,    -1,    -1,   446,    -1,   448,    -1,    -1,    -1,   151,
      -1,   411,    -1,  3776,    -1,    -1,   459,    -1,    -1,    -1,
      -1,   464,    -1,   423,   725,   726,    -1,    -1,    -1,    -1,
    2434,   474,    -1,    -1,  2438,    -1,   479,    -1,     9,   482,
      -1,    -1,   485,  2447,    -1,    -1,    -1,    18,    19,    -1,
      -1,   494,   495,    24,    25,    26,    27,    -1,    -1,   459,
      -1,  2465,    -1,    -1,    -1,    -1,    -1,    38,  2472,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,  2482,    -1,
      -1,    -1,   482,    -1,    -1,    -1,   229,  2491,    -1,    -1,
      -1,  2495,   535,    -1,   237,   495,   539,    -1,    -1,    -1,
      -1,   243,    -1,   245,   547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   558,  2520,   560,    -1,    -1,
      -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,    -1,   539,
      -1,   112,    -1,    -1,    -1,   588,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   564,    -1,   309,   310,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,   632,
      -1,    -1,    -1,    -1,    -1,    -1,   639,    20,   641,    -1,
     342,    24,    25,    26,    27,   347,    -1,    -1,   651,   652,
      -1,   354,    -1,    36,    37,    -1,   659,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   670,    -1,    -1,
      -1,    -1,   632,    -1,    -1,   377,    -1,    -1,  2642,    18,
      19,   641,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,   398,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,
      -1,    -1,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,   423,   725,   726,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,   441,
      -1,    -1,    -1,    -1,   446,    -1,   448,    -1,    -1,   452,
      -1,  2715,    -1,    -1,    -1,    -1,    -1,   459,    -1,    -1,
      -1,    -1,   464,    -1,    -1,   725,   726,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,   479,   117,    -1,
     482,    -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   494,   495,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,   342,    -1,    -1,    -1,    -1,   347,    18,    19,    20,
      -1,    -1,  2786,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,   534,   535,    -1,    36,    37,   539,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   547,   377,    -1,   313,    -1,
      -1,    -1,    -1,  2817,    -1,    -1,   558,  2821,    -1,    -1,
     243,    -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2836,    -1,  2838,    -1,  2840,    -1,    -1,    -1,
     411,    -1,    -1,    -1,    -1,    -1,   588,   352,    -1,  2853,
      -1,    -1,   423,    -1,  2858,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    -1,   371,   372,    -1,    -1,
     441,    -1,    -1,    -1,    -1,   446,   117,   448,    -1,    -1,
      -1,  2885,  2886,    -1,    -1,    -1,    -1,    -1,   459,    -1,
     632,    -1,    -1,   464,    -1,    -1,    -1,   639,    -1,   641,
      -1,    -1,    -1,   474,    -1,    -1,   411,    -1,   479,   651,
     652,   482,    -1,    -1,   485,    -1,    -1,   659,   423,    -1,
      -1,    -1,    -1,   494,   495,    -1,    -1,  2931,   670,   434,
      -1,    -1,    23,    -1,    -1,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   450,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,   460,    -1,    48,    -1,    50,
      51,    -1,    -1,    -1,   535,    -1,    -1,    -1,   539,    -1,
     475,    -1,    -1,    -1,    -1,    -1,   547,    -1,    -1,    -1,
      -1,    -1,    -1,   725,   726,    -1,    -1,   558,    -1,    -1,
      -1,    -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     515,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   448,    -1,    -1,    -1,    -1,
      -1,  3035,    -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3048,    -1,    -1,    -1,   553,    -1,
      -1,    -1,   143,    -1,    -1,   560,   479,    -1,   563,   482,
      -1,   632,    -1,    -1,    -1,    -1,    -1,    -1,   639,   448,
     641,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   584,
     651,   652,    -1,   588,    -1,    -1,    -1,    -1,   659,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   670,
     479,    -1,   607,   482,    -1,  3109,   347,    -1,    -1,    -1,
      -1,    -1,   535,    -1,    -1,    -1,   495,  3121,    -1,    -1,
     625,    -1,    -1,    -1,   547,    -1,   217,    -1,   219,    -1,
      -1,    -1,    -1,  3137,    -1,    -1,    -1,    -1,  3142,    -1,
      -1,    -1,    -1,   522,    -1,    -1,    -1,  3151,    -1,    -1,
      -1,    -1,    -1,   244,   725,   726,   535,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,   588,    -1,    -1,   547,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,
     281,    -1,    -1,    -1,    -1,    -1,   287,    -1,   621,    -1,
     291,   292,   293,   294,   627,    -1,    -1,   448,    -1,   588,
      -1,    -1,    -1,   636,   637,   306,   639,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,   652,
      -1,    -1,   323,    -1,    -1,   326,   659,   328,   479,   662,
      -1,   482,    -1,    -1,   335,  3249,    -1,   670,   627,    -1,
      -1,    -1,    -1,   494,   495,    -1,    -1,   348,    -1,    -1,
     639,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,
      -1,    -1,   651,   652,    -1,    -1,    -1,    -1,    -1,    -1,
     659,   522,    -1,   662,    -1,    -1,    -1,    -1,   379,   380,
      -1,   670,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   394,    -1,    -1,   547,    -1,    -1,  3313,
      -1,   402,    -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   414,   415,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    -1,
      -1,  3375,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
     621,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,  3393,
     481,    -1,    -1,    -1,    -1,   636,   637,    -1,   639,    -1,
      -1,   492,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
     651,   652,    -1,    -1,    -1,    -1,    -1,  3421,   659,    -1,
      -1,   662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   670,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,    -1,  3498,    -1,   151,    -1,    -1,  3503,
      -1,  3505,   593,   158,   159,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3536,    -1,    -1,    -1,    -1,    -1,   629,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3554,    -1,    -1,   208,    -1,    -1,  3560,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,   675,    -1,    -1,   242,   243,    -1,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,   689,   690,
     691,   692,   693,   694,   695,    -1,   697,   698,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   276,    -1,   714,  3628,  3629,  3630,  3631,  3632,  3633,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,   333,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,   343,    -1,
      -1,    -1,    -1,    -1,   349,    -1,    -1,   352,   353,    -1,
      -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,   363,   364,
      -1,    -1,    -1,    -1,    -1,   370,   371,   372,    -1,    -1,
     375,   376,   377,    -1,    -1,    -1,   381,    -1,    -1,    -1,
     385,    -1,   387,    -1,    -1,    -1,    -1,    -1,    -1,   394,
     395,   396,   397,    -1,   399,   400,    -1,    -1,    -1,   404,
     405,    -1,   407,   408,   409,   410,   411,   412,   413,    -1,
      -1,    -1,    -1,    -1,   419,   420,   421,    -1,   423,   424,
      -1,    -1,  3776,   428,   429,   430,   431,   432,   433,   434,
     435,    -1,   437,    -1,    -1,    -1,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,    -1,   478,   479,    -1,    -1,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,    -1,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,    -1,    -1,   510,   511,   512,   513,   514,
     515,   516,   517,   518,    -1,   520,   521,   522,   523,    -1,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,    -1,   562,   563,   564,
     565,   566,   567,    -1,    -1,   570,   571,    -1,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,    -1,    -1,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,    -1,    -1,
      -1,    -1,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   688,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   696,    -1,    -1,    -1,    -1,   701,    -1,    -1,    -1,
     705,    -1,    -1,   708,   709,   710,   711,    -1,    -1,   714,
     715,    -1,   717,   718,   719,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   276,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,
      -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   342,   343,    -1,    -1,    -1,    -1,    -1,   349,
      -1,    -1,   352,   353,    -1,    -1,    -1,   357,    -1,    -1,
      -1,    -1,    -1,   363,   364,    -1,    -1,    -1,    -1,    -1,
     370,   371,   372,    -1,    -1,   375,   376,   377,    -1,    -1,
      -1,   381,    -1,    -1,    -1,   385,    -1,   387,    -1,    -1,
      -1,    -1,    -1,    -1,   394,   395,   396,   397,    -1,   399,
     400,    -1,    -1,    -1,   404,   405,    -1,   407,   408,   409,
     410,   411,   412,   413,    -1,    -1,    -1,    -1,    -1,   419,
     420,   421,    -1,   423,   424,    -1,    -1,    -1,   428,   429,
     430,   431,   432,   433,   434,   435,    -1,   437,    -1,    -1,
      -1,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,    -1,   478,   479,
      -1,    -1,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,    -1,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,    -1,    -1,
     510,   511,   512,   513,   514,   515,   516,   517,   518,    -1,
     520,   521,   522,   523,    -1,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,    -1,   562,   563,   564,   565,   566,   567,    -1,    -1,
     570,   571,    -1,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,    -1,
      -1,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,    -1,    -1,    -1,    -1,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   688,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   696,    -1,    -1,    -1,
      -1,   701,    -1,    -1,    -1,   705,    -1,    -1,   708,   709,
     710,   711,    30,    -1,   714,   715,    34,   717,   718,   719,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,    -1,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,    -1,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   197,
      -1,   199,   200,   201,    -1,    -1,    -1,    -1,    -1,   207,
      -1,   209,   210,    -1,   212,    -1,   214,   215,    -1,    -1,
     218,    -1,    -1,   221,   222,   223,   224,   225,   226,    -1,
      -1,    -1,   230,   231,   232,    -1,   234,    -1,    -1,    -1,
     238,    -1,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,   249,    -1,    -1,   252,    -1,   254,    -1,   256,    -1,
     258,    -1,    -1,    -1,   262,   263,    -1,   265,   266,   267,
      -1,    -1,   270,    -1,   272,   273,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   283,   284,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,
      -1,   299,   300,    -1,    -1,   303,   304,    -1,    -1,   307,
     308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   316,   317,
     318,    -1,   320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   330,   331,   332,    -1,   334,    -1,    -1,    -1,
     338,   339,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   359,   360,   361,    -1,    -1,    -1,    -1,    -1,   367,
     368,    -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,    -1,
     378,    -1,    -1,    -1,   382,   383,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,   393,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     418,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    -1,    -1,    -1,    -1,   453,    -1,   455,   456,    -1,
      -1,    -1,    -1,    -1,    -1,   463,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,   502,    -1,    -1,    -1,    47,    36,
      37,    -1,    -1,    -1,    -1,   513,    -1,    -1,    -1,    -1,
      -1,    -1,   520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   544,   545,   162,   163,
     164,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,   567,
     568,   569,   570,    -1,    -1,    -1,   574,    -1,    -1,    -1,
     578,    -1,    -1,    -1,    -1,    -1,    -1,   585,   586,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,    -1,
     598,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   609,    -1,   611,    -1,    -1,   614,    -1,    -1,    -1,
      -1,    -1,   620,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   646,    -1,
      -1,   649,    -1,    -1,    -1,    -1,   654,    -1,    -1,   657,
     658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,   672,    -1,    -1,    -1,    -1,    -1,
      -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,   302,    -1,
      -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   702,   703,   704,   705,   706,   707,
     708,    -1,    -1,   711,    -1,   713,   243,   715,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    47,
      -1,    -1,    -1,   302,    -1,    -1,   305,    -1,    -1,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,   425,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,   440,    -1,    -1,    -1,
     444,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    47,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    47,   162,   163,   164,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   508,   162,   163,   164,    -1,    -1,
      -1,   440,    -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,
      -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,
     305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   479,    -1,    -1,   482,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,   164,    -1,   495,   508,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,   162,   163,
     164,    -1,    -1,   607,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   534,   535,    -1,
      -1,    -1,    -1,    -1,   302,    -1,    -1,   305,    -1,    -1,
     547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   673,
      -1,   588,    -1,    -1,    -1,   440,    -1,    -1,   607,   444,
     445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
     627,    -1,    -1,    -1,   302,   480,    -1,   305,    -1,   636,
     637,    -1,   639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   651,   652,    -1,    -1,   302,    -1,
      -1,   305,   659,   508,   673,   662,    -1,   425,    -1,    -1,
      -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   526,   440,    -1,    -1,    -1,   444,   445,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   440,    -1,    -1,    -1,   444,   445,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
     508,    -1,    -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,
      -1,    -1,   607,    -1,    -1,    -1,    -1,    -1,   526,    -1,
      -1,   508,   440,    -1,    -1,    -1,   444,   445,    -1,    -1,
      -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,
      -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,    -1,    -1,
     444,   445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,   480,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   673,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
     508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,    -1,
      -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,    -1,    -1,
     607,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,   526,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   673,    -1,     6,     7,     8,
      47,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   673,    -1,    -1,   607,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,   607,    -1,   162,   163,   164,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   673,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   673,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,   305,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,   302,    -1,    -1,   305,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   302,    -1,    -1,   305,   144,   145,   146,
     147,   148,   149,    -1,    47,    -1,    -1,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,   440,    -1,    -1,    -1,   444,   445,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,
     305,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,    -1,    47,    -1,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   508,    -1,   440,    -1,    -1,    -1,   444,   445,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,   526,
      -1,    -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   440,    -1,   480,    -1,   444,   445,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,   305,    -1,
      -1,   508,    -1,   144,   145,   146,   147,   148,   149,    -1,
     425,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,
      -1,   162,   163,   164,    -1,   440,    -1,    -1,    -1,   444,
     607,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   508,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   302,
      -1,    -1,   305,    -1,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,     8,   493,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,   508,    -1,    -1,   673,    -1,    -1,   302,
     607,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   526,    -1,    -1,    -1,    -1,    47,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   440,    -1,    -1,    -1,   444,   607,    -1,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,   302,    -1,    -1,   305,    -1,   673,     9,    -1,    -1,
      -1,    -1,   425,   480,    -1,    -1,    18,    19,    20,    -1,
      -1,    47,    24,    25,    26,    27,   493,   440,    -1,    -1,
      -1,   444,   607,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,   508,    -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   526,
      -1,    -1,   425,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,   162,   163,   164,    -1,    -1,    -1,   440,    -1,    -1,
     493,   444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,   673,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,   526,    -1,   117,    -1,   480,   144,   145,
     146,   147,   148,   149,   425,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,   162,   163,   164,   440,
     607,    -1,    -1,   444,    -1,   508,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,   607,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,   673,   508,    36,    37,
      -1,   302,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,   607,    -1,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     673,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,   305,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,   607,    -1,    -1,    -1,
     673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,   440,
      -1,    47,    -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,   302,   480,
      -1,   305,   144,   145,   146,   147,   148,   149,    -1,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
     162,   163,   164,    -1,   440,   243,    -1,   508,   444,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   526,    -1,    -1,   302,    36,
      37,   305,    -1,    -1,    -1,    -1,   448,    -1,   144,   145,
     146,   147,   148,   149,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,
     482,    -1,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   494,   495,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   425,    -1,    -1,    -1,    -1,   607,    -1,    -1,    -1,
     117,    -1,    -1,   162,   163,   164,   440,    -1,    -1,    -1,
     444,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    -1,   547,    24,    25,    26,    27,
     302,    -1,    -1,   305,    -1,    -1,    -1,    -1,    36,    37,
      -1,   425,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,    -1,    -1,
     444,   607,   673,    -1,    -1,    32,   588,    -1,    -1,    -1,
      -1,    -1,    39,    -1,   508,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,   302,    -1,    -1,   305,
      -1,    -1,   526,    36,    37,    -1,   480,    -1,    -1,   621,
     448,    -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,   493,
      -1,    -1,    -1,    -1,   636,   637,    -1,   639,    -1,   117,
      -1,    -1,    -1,    -1,   508,    -1,   243,   673,    -1,   651,
     652,   479,    -1,    -1,   482,    -1,    -1,   659,    -1,    -1,
     662,    -1,   526,   302,    -1,    -1,   305,   495,   670,   116,
      -1,    18,    19,   425,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   132,   133,    -1,   440,    36,
      37,    -1,   444,   607,   117,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   534,   535,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   547,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   607,   440,    -1,    -1,    -1,   444,    -1,
     347,    -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,   673,
     588,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,
      -1,   440,    -1,    -1,    -1,   444,    -1,    -1,    -1,   673,
      -1,   639,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,   651,   652,    -1,    -1,    -1,    -1,    -1,
     526,   659,    -1,    -1,   662,    -1,    -1,    -1,    -1,    -1,
      -1,   480,   670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,   607,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,    -1,    -1,   508,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   479,    -1,    -1,   482,    -1,   526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   494,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,
      -1,   607,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,   673,    -1,    -1,   371,   372,   373,   374,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,
      -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   411,    -1,    -1,    -1,   607,    -1,
     448,    -1,    -1,    -1,    -1,    -1,   423,   673,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,
      -1,   588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   479,    -1,   450,   482,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,   460,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,    -1,   621,   448,    -1,    -1,   475,    -1,
     627,    -1,    -1,    -1,   673,    -1,    -1,    -1,    -1,   636,
     637,    -1,   639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   651,   652,   479,   535,    -1,   482,
      -1,    -1,   659,    -1,    -1,   662,    -1,    -1,   515,   547,
      -1,    -1,   495,   670,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,   553,    -1,    -1,    -1,
     588,    -1,   535,   560,   255,    -1,   563,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   479,    -1,    -1,   482,    -1,   584,    -1,    -1,
      -1,   588,    -1,   621,    -1,    -1,    -1,    -1,   495,   627,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,   637,
     607,   639,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,
      -1,   312,    -1,   651,   652,    -1,    -1,    -1,   625,    -1,
      -1,   659,    -1,    -1,   662,    -1,    -1,    -1,   535,    -1,
      -1,    -1,   670,    -1,    -1,    -1,   337,    -1,   621,    -1,
     547,    -1,    -1,    -1,   627,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   636,   637,    -1,   639,    -1,    -1,    -1,
     667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,   652,
      -1,    -1,    -1,    -1,    -1,    -1,   659,    -1,    -1,   662,
      -1,   588,    -1,   384,    -1,    -1,   387,   670,    -1,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   651,   652,    -1,    -1,    -1,    -1,
      -1,    -1,   659,    -1,    -1,   662,    -1,    -1,    -1,    -1,
      -1,   462,    -1,   670,    -1,    -1,    -1,   468,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     541,   542,    -1,    -1,    -1,    -1,   547,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,
      -1,   582,   583,    -1,    -1,    -1,   587,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   644,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   653,    -1,   655
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   128,   289,   410,   458,   489,   518,   786,
     813,   814,   870,  1042,  1098,  1100,  1101,  1102,  1107,  1109,
    1122,  1123,  1124,  1125,  1126,  1569,    28,    29,   787,   788,
     789,   790,   791,    27,  1006,  1584,  1006,    25,  1006,  1474,
    1127,   815,  1474,   814,     0,  1099,  1102,  1125,    31,   789,
     791,   871,   662,    25,   243,   812,   813,   993,  1006,  1011,
    1107,  1122,  1128,  1163,  1164,  1165,  1166,  1167,  1171,   408,
     817,   818,   819,   820,   823,   824,   106,   113,   159,   160,
     167,   421,   516,   608,   688,   696,   786,   965,  1041,  1103,
    1104,  1106,  1110,  1111,  1117,  1129,  1150,  1283,  1293,  1569,
     667,  1006,  1166,   295,   509,   510,  1172,    20,  1006,  1170,
     670,   818,     5,   816,   408,  1006,     5,   842,   844,   845,
    1006,  1294,  1006,  1006,  1284,  1118,  1006,  1006,  1106,  1112,
     313,   352,   371,   372,   411,   423,   434,   450,   460,   475,
     515,   538,   553,   560,   563,   584,   588,   607,   625,   872,
     873,   874,   877,    25,  1163,  1169,    18,    19,    26,    38,
     112,   124,   151,   245,   342,   377,   411,   423,   459,   474,
     482,   495,   539,   564,   588,   632,   641,   725,   726,   736,
     738,   930,   935,   946,   948,  1006,  1163,  1173,  1174,   510,
      14,   869,   820,   573,  1270,   821,   818,   823,    32,    39,
     116,   132,   133,   142,   313,   352,   371,   372,   373,   374,
     389,   411,   423,   434,   450,   460,   475,   515,   538,   553,
     560,   563,   584,   588,   607,   625,   667,   827,   836,   847,
     852,  1006,   482,   166,  1006,   812,   966,  1151,  1006,   879,
     372,   825,   482,   855,   857,   858,   856,   865,   866,   482,
     482,   878,   510,   482,   818,   853,   477,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   736,   482,
     809,     9,    18,    19,    24,    25,    26,   117,   347,   441,
     446,   448,   464,   479,   482,   485,   494,   535,   547,   558,
     588,   639,   651,   652,   659,   670,   906,   914,   915,   916,
     917,   918,   946,   947,   949,  1012,  1163,  1273,  1466,   482,
     482,   482,   482,   482,   482,    18,    19,    20,    21,    22,
     737,    26,   482,   572,     5,   478,  1173,    25,    26,  1006,
    1012,    19,    25,    26,   822,  1012,   720,   721,   722,   826,
     849,   838,   850,   825,   482,   482,   482,   839,   855,   856,
     482,   482,   837,   510,   848,   482,   853,   818,   846,   482,
      26,  1006,   482,  1119,   812,   812,   482,  1006,   482,   509,
     831,    26,   676,   420,   505,   521,   564,   603,   632,   641,
     859,   676,   420,   505,   521,   564,   603,   632,   641,   867,
      26,    26,   880,   881,   882,   883,  1006,    26,   834,   835,
      26,   670,  1163,   717,   954,   997,  1006,   997,   997,   954,
     954,   906,    24,    25,    26,    19,    24,    25,    26,   950,
     951,   952,   953,    25,   955,   997,   998,   906,   445,   906,
     906,   906,   906,   577,  1290,   482,   482,   906,   420,   505,
     521,   564,   603,   632,   641,  1469,  1470,   482,   906,   906,
     482,   482,   919,   482,   482,   482,   482,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    47,   144,   145,   146,   147,   148,
     149,   162,   163,   164,   302,   305,   425,   440,   444,   480,
     508,   526,   607,   673,   808,   907,   920,   922,   923,   924,
     925,   926,   927,   928,   472,   938,   936,   942,   940,  1163,
    1163,   736,   931,  1006,  1174,   510,   478,    26,   829,   482,
     851,   818,   851,   831,    26,    26,    26,   818,    26,    26,
     817,   834,   851,    26,   670,   111,   843,  1295,   445,   482,
    1285,  1585,  1586,  1587,  1588,  1589,   967,  1152,  1113,   670,
      26,   445,   860,   861,   482,   862,   867,   868,   862,   482,
     863,     5,   445,     5,   445,     5,   336,     5,   872,   478,
       5,     5,   445,   818,   854,   445,   482,     5,   445,   510,
     670,   445,   445,   445,   445,   445,   445,   445,    19,    26,
     445,   640,   951,    19,    26,   640,   445,     5,   445,   445,
       5,   810,   906,   522,  1490,   906,   482,   676,    20,   445,
    1490,    20,  1273,   906,   906,   906,   906,   906,   906,   906,
     906,   906,   906,   906,   906,   906,   906,   906,   906,   906,
     906,   906,   906,   906,   906,   906,   482,   906,   906,   482,
    1163,   906,   906,   906,   906,   445,     5,   534,   766,   767,
     768,   906,   482,  1173,   510,   674,    26,   670,    26,   445,
     445,     5,   445,   311,     5,   445,     5,   445,   336,   478,
       5,   445,   854,  1006,  1179,  1180,  1182,  1130,  1179,   415,
    1586,  1270,    40,    41,    42,    49,    52,    59,    60,   104,
     105,   109,   119,   120,   122,   136,   153,   156,   157,   171,
     173,   174,   175,   183,   184,   186,   187,   188,   194,   197,
     199,   200,   201,   207,   209,   210,   212,   214,   215,   218,
     221,   222,   223,   224,   225,   226,   230,   231,   232,   234,
     238,   240,   241,   246,   249,   252,   254,   256,   258,   262,
     263,   265,   266,   267,   270,   272,   273,   275,   283,   284,
     296,   299,   300,   303,   304,   307,   308,   316,   317,   318,
     320,   330,   331,   332,   334,   338,   339,   343,   351,   359,
     360,   361,   367,   368,   375,   378,   382,   383,   393,   410,
     418,   424,   435,   447,   453,   455,   456,   463,   502,   513,
     520,   544,   545,   549,   561,   567,   568,   569,   570,   574,
     578,   585,   586,   596,   598,   609,   611,   614,   620,   646,
     649,   654,   657,   658,   672,   679,   702,   703,   704,   705,
     706,   707,   708,   711,   713,   715,   729,   730,   731,   732,
     749,   771,   785,   786,   792,   811,   885,   886,   887,   888,
     899,   900,   901,   902,   903,   904,   905,   956,   960,   991,
    1013,  1015,  1018,  1019,  1020,  1021,  1034,  1043,  1067,  1068,
    1070,  1074,  1089,  1090,  1094,  1095,  1096,  1097,  1105,  1120,
    1133,  1144,  1145,  1146,  1157,  1160,  1194,  1197,  1199,  1205,
    1206,  1209,  1212,  1215,  1217,  1219,  1222,  1229,  1234,  1239,
    1240,  1241,  1253,  1254,  1257,  1263,  1265,  1266,  1291,  1306,
    1307,  1308,  1309,  1310,  1322,  1328,  1329,  1349,  1352,  1381,
    1383,  1475,  1476,  1507,  1508,  1515,  1530,  1554,  1569,  1570,
    1575,  1576,  1578,  1582,  1583,  1590,   786,  1108,   675,   698,
    1153,  1154,  1179,    20,   445,   477,   832,   859,    26,   864,
      26,    26,    26,   881,   883,   875,   835,    26,  1006,   997,
     736,    20,   717,  1006,   944,  1470,   944,    26,   445,   640,
     944,    24,    26,    26,   640,    24,    26,   856,   945,   998,
     857,   445,   413,   527,   636,  1498,   445,   445,    26,  1470,
     445,   445,   445,   445,   445,   445,   445,   493,   493,   493,
     929,  1490,   493,   929,  1490,   939,   937,   943,   941,    26,
     932,     5,   933,   478,  1173,   842,   445,    20,   832,    26,
     482,    26,    26,   828,    26,   670,   445,     5,  1179,   445,
    1163,  1163,  1163,  1006,    25,  1163,  1216,  1006,    25,  1006,
    1459,   404,  1007,  1008,  1584,  1007,    25,  1006,  1458,  1006,
    1006,  1237,  1001,  1007,  1001,  1006,  1580,  1459,  1006,    26,
     733,  1163,  1313,  1001,  1237,   929,    26,  1012,  1278,  1279,
    1278,   906,   913,  1351,  1458,  1458,   908,   929,  1007,  1516,
    1516,   889,  1237,  1001,  1311,  1163,  1003,  1007,   913,  1516,
    1163,  1237,  1163,  1350,  1516,    25,   636,  1147,  1148,  1163,
    1001,  1001,  1147,  1002,  1007,  1006,  1148,  1001,  1516,  1001,
    1003,  1459,  1163,  1192,  1193,   999,  1007,  1003,   429,   612,
     997,  1069,  1006,   793,  1458,  1004,  1007,    25,   243,  1006,
    1382,  1558,  1560,  1561,  1562,  1563,  1565,   929,  1192,   676,
     929,  1007,  1218,   961,    62,    63,    64,    65,   185,   193,
     202,   205,   248,   255,   312,   337,   344,   346,   356,   384,
     392,   429,   453,   490,   501,   599,   600,   601,   612,   715,
    1083,  1213,  1214,  1163,  1184,  1185,   912,   913,  1228,   954,
     954,  1000,  1007,   929,  1216,  1292,  1163,  1269,    25,  1163,
    1510,  1264,   913,  1571,   158,   208,   245,   342,   419,   459,
     525,   750,   935,  1006,  1163,  1301,   773,   913,   999,   640,
    1006,  1014,  1134,   913,   999,    26,  1163,  1091,   999,   913,
    1531,   913,  1278,  1006,  1016,  1017,  1003,  1016,   954,  1003,
    1016,   954,  1022,  1016,    25,    26,   438,   538,  1012,  1072,
    1163,  1181,  1183,   118,   327,   399,   443,   619,   699,   700,
     701,   710,   740,  1024,  1026,  1028,  1030,  1032,  1158,  1159,
    1162,   390,   401,   451,   465,   554,  1384,   690,   691,   969,
     970,   971,  1006,  1155,   697,  1154,   445,   355,   445,   445,
     445,   445,   674,     5,   445,   445,   478,   482,   676,    19,
      26,   445,   944,    26,   445,   445,   640,    26,   640,   676,
      18,    19,    20,    25,    26,    36,    37,   117,   448,   479,
     482,   495,   535,   547,   588,   621,   627,   636,   637,   639,
     651,   652,   659,   662,  1006,  1012,  1465,  1467,  1497,  1499,
    1500,  1502,  1503,  1504,  1526,  1527,  1528,  1529,  1559,  1560,
    1564,  1290,   445,  1290,  1290,  1290,  1290,  1290,  1290,    25,
      25,    25,   906,   921,   445,    25,   921,   445,   445,   445,
     445,   445,   445,   445,   768,   766,   478,   355,   445,   818,
     840,   841,   445,   445,   674,   445,  1006,  1296,  1182,   445,
    1286,   107,   108,   137,   138,   139,   506,   592,   635,  1330,
    1331,  1332,  1335,  1338,  1341,  1342,  1343,  1346,   670,   640,
     662,   154,   155,   482,   670,   640,   662,     8,   675,   478,
    1458,   530,  1238,  1181,   162,   163,   164,   646,   534,   909,
     910,   913,  1163,  1188,  1458,   739,   740,   892,   319,    46,
     140,   141,   676,  1235,   511,     5,   669,   676,   668,   668,
    1195,   646,   472,     5,   607,  1044,   511,   709,  1573,   709,
     438,   795,  1163,   597,   668,  1200,  1201,  1202,   670,    25,
    1561,   510,  1566,   381,  1380,   662,   670,   911,   913,   607,
    1558,   911,     8,   604,  1000,    26,   552,   605,   719,   992,
    1163,   992,   992,   992,    25,   230,   357,   363,   364,   365,
     385,   490,   493,   501,   536,   571,   590,   591,   601,   606,
     645,   677,  1087,  1088,   992,   992,   647,  1084,   740,  1084,
    1084,   993,   993,  1084,  1084,   740,     5,   472,     5,   388,
     439,     5,   739,   134,   135,   590,   677,  1075,   712,  1574,
     912,   663,   664,   665,   666,  1268,  1270,   913,  1259,  1260,
    1261,  1271,  1272,   913,   482,   482,   482,   482,    25,   769,
    1006,   482,  1510,   399,   482,   572,   640,   629,   774,   781,
     772,  1006,    25,  1149,  1163,  1255,     8,  1258,    14,  1006,
    1168,  1175,  1176,  1178,  1186,  1187,  1230,   216,   399,   595,
     628,     5,     6,     7,     8,     9,    10,    12,    13,    14,
      18,    19,    20,    21,    22,    23,    33,    58,   115,   124,
     142,   143,   151,   158,   159,   162,   163,   164,   165,   168,
     169,   208,   230,   236,   243,   245,   250,   276,   314,   327,
     333,   342,   343,   349,   352,   353,   357,   363,   364,   370,
     371,   372,   375,   376,   377,   381,   385,   387,   394,   395,
     396,   397,   399,   400,   404,   405,   407,   408,   409,   410,
     411,   412,   413,   419,   420,   421,   423,   424,   428,   429,
     430,   431,   432,   433,   434,   435,   437,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   478,   479,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   520,
     521,   522,   523,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   562,
     563,   564,   565,   566,   567,   570,   571,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   688,   696,   701,   705,
     708,   709,   710,   711,   714,   715,   717,   718,   719,  1532,
    1533,  1534,  1536,   626,     5,   709,   709,   911,  1181,  1188,
    1071,   472,     5,   204,  1049,   482,  1163,   911,   482,    26,
      26,   118,  1161,    25,  1163,  1514,  1514,  1007,  1364,  1218,
    1000,   172,   274,   282,   288,   290,   301,   329,   345,   350,
     362,   369,   517,   522,   529,   551,   556,  1353,  1354,  1362,
    1371,  1372,  1378,  1379,  1385,  1386,  1396,  1416,  1420,  1486,
    1487,  1517,  1518,  1521,  1522,  1538,   972,   973,   143,   968,
     979,   980,   971,  1156,  1585,  1114,   510,   872,   835,   670,
    1006,   420,   505,   521,   564,   603,   632,   641,  1471,    26,
     445,   640,   944,   445,   640,   944,   944,    24,    26,   640,
      24,    26,   860,  1503,  1503,   420,   505,   521,   564,   603,
     632,   641,  1468,  1472,   522,  1502,   482,   482,   482,   482,
    1497,  1497,  1497,   482,   482,   482,   482,  1006,   482,     5,
     597,  1425,  1430,   667,  1006,    18,    19,    20,    21,   144,
     145,   146,   147,   148,   149,  1524,  1472,  1472,   472,     5,
     445,   445,   934,   510,     5,   445,   842,   812,  1131,   812,
     298,   311,   413,   482,   527,   543,  1400,  1401,  1406,  1408,
     482,  1006,  1347,  1348,    26,   482,  1006,  1327,  1340,  1408,
    1410,   482,  1006,  1337,   482,  1327,  1333,     5,  1006,    25,
    1006,  1006,    25,  1009,  1166,  1006,    25,  1006,  1006,  1006,
    1581,  1458,   646,   482,   482,   892,  1458,     5,   676,   482,
    1558,    25,  1011,  1236,  1235,  1236,  1510,  1147,   913,   913,
     913,   994,   995,   482,  1163,  1193,  1045,  1046,  1047,  1458,
     676,  1510,   954,  1574,  1069,  1163,   794,   675,   913,   405,
    1204,   607,  1203,  1562,   736,  1567,  1568,  1006,    20,  1563,
       5,  1555,   667,  1210,   121,   123,   125,   668,   676,   884,
    1181,  1184,   962,    18,    19,   482,  1085,  1087,  1214,  1163,
    1185,   993,   913,   399,   646,    26,  1163,    26,  1163,   739,
     206,  1267,   437,  1305,  1270,  1261,     5,   668,  1262,  1572,
    1006,    25,   954,   954,   640,   998,   673,  1163,   754,  1006,
    1006,   913,   394,   777,   781,   629,   775,   783,    23,   287,
    1136,  1140,   533,   929,   533,  1256,   913,   509,  1172,   670,
       5,  1092,   597,  1231,  1163,  1535,  1537,   242,  1533,  1035,
    1017,   954,   954,  1027,  1028,  1049,  1049,    43,    44,    45,
      48,    50,    51,   323,   326,   328,   348,   358,   379,   402,
     406,   481,  1048,  1050,  1051,  1079,  1163,  1183,   597,   741,
      26,   452,  1033,   376,  1509,  1509,   191,   192,   488,   597,
    1006,  1417,  1418,  1460,  1458,  1458,  1458,  1355,  1458,  1458,
    1006,  1519,   220,   433,   447,   490,   501,   522,   529,   537,
     559,   636,   642,  1387,  1389,  1390,  1391,  1498,  1458,  1363,
    1387,  1389,  1585,  1585,   438,   981,  1163,   692,   693,   974,
     975,   976,   532,   675,   694,   695,   714,   984,   985,  1585,
     812,    26,   833,    20,  1006,   445,   482,    26,   445,   944,
      26,   944,    24,    26,   445,   445,    24,    26,   676,  1498,
     445,   448,  1502,  1525,  1564,   413,   527,   636,  1449,  1502,
    1505,  1449,  1449,  1449,  1449,   670,  1505,  1500,   566,  1426,
    1427,  1428,  1458,   577,  1424,  1431,   386,   565,   576,  1373,
    1493,  1006,  1502,  1502,  1502,  1502,   676,   482,   676,  1559,
     906,   445,   833,   841,  1297,   812,  1287,   482,   482,   482,
    1344,  1408,   482,   482,   110,  1345,  1347,     5,  1339,  1340,
     116,   352,   372,   373,   374,   411,   423,   434,   450,   460,
     475,   523,   553,   563,   584,   588,   616,   625,  1450,  1451,
    1452,  1454,  1336,  1337,  1333,  1334,   714,  1331,   670,   640,
     445,   670,   640,   597,  1579,   482,   734,   735,  1006,  1314,
     929,   909,  1006,  1312,   667,  1207,  1235,  1235,   676,     5,
       5,     5,   630,   913,     5,   670,   534,   676,   675,   217,
     219,   323,   326,   796,   799,   800,  1079,   797,   798,  1006,
     482,  1007,   699,   700,  1208,     5,   478,   913,  1458,  1556,
    1557,  1558,   627,   667,  1211,  1006,  1006,   995,   996,   560,
     954,   892,     8,     8,   964,    26,    26,  1086,  1087,  1163,
     372,  1223,   118,   906,  1270,   271,  1272,  1278,  1585,     5,
       5,   445,   445,   770,  1006,   445,  1510,   766,   482,   482,
     782,   778,   414,   776,   913,   394,   779,   783,   647,  1081,
    1141,  1137,   416,  1135,  1136,   911,   676,  1169,    20,  1006,
    1177,  1187,    14,   534,  1232,  1233,  1502,  1564,  1184,  1585,
    1029,  1030,   601,  1005,   597,  1062,  1061,  1060,  1059,  1064,
    1063,   997,  1065,   997,  1066,  1058,  1057,  1055,  1054,  1080,
     379,  1051,  1056,   954,    53,    54,    55,    56,    57,    58,
     150,   387,   400,   462,   468,   507,   531,   541,   542,   547,
     557,   579,   582,   583,   587,   644,   655,   742,   743,  1077,
    1078,     5,    26,  1510,   301,  1163,   522,  1491,  1492,  1510,
    1218,  1485,  1487,   152,   152,   646,  1216,  1419,  1420,   482,
    1397,   203,  1431,  1458,   227,   324,  1523,   670,   676,   482,
    1392,  1392,   597,   675,     5,  1488,  1539,   396,   405,   429,
     432,   448,   552,   605,   612,  1000,  1365,  1370,   676,   675,
     983,  1163,     5,   597,   977,   978,   689,   976,   982,  1006,
     982,   986,   987,   982,   379,   985,  1115,   478,    26,   445,
     640,   944,   445,   640,   445,   445,   944,   944,   420,   505,
     521,   564,   603,   632,   641,  1473,  1499,     5,  1472,     5,
     445,     5,  1502,     5,   445,  1502,  1502,  1502,  1502,  1006,
     445,   482,  1428,     5,  1006,  1464,     9,   347,   482,   494,
    1434,  1435,  1436,  1437,  1438,  1442,  1446,  1448,  1502,   422,
    1422,  1432,  1006,  1494,   669,  1449,   386,  1473,    26,  1473,
     478,   512,  1280,  1300,  1132,   512,  1242,  1274,   662,  1006,
    1403,  1405,  1458,  1462,  1463,  1407,  1462,  1407,     5,   445,
    1345,  1407,  1434,  1006,   445,  1348,     5,   445,   482,   482,
     482,  1472,  1472,   482,   482,   482,   482,   482,   259,   260,
     261,   452,  1409,  1411,     5,   445,     5,   445,  1006,  1006,
      25,  1006,  1006,    25,  1006,   913,  1006,  1324,  1325,     5,
    1326,  1327,   929,  1121,   670,  1326,   627,  1510,  1510,   913,
     913,   994,   560,   913,  1577,     5,  1046,    20,  1462,  1510,
     797,   805,   804,   806,  1006,  1010,   807,  1010,   244,   800,
     803,     5,  1049,   670,   913,     8,  1568,   510,   670,     5,
    1510,   627,  1006,  1181,   929,   604,  1368,     5,   445,  1163,
       5,    26,  1163,   380,    25,  1302,   399,   399,   510,   670,
     399,   482,   755,   759,   752,  1585,  1585,   784,   780,   776,
    1082,    25,  1005,  1142,  1163,  1585,   913,   477,   510,   929,
       5,  1036,  1031,  1032,    26,   739,  1006,  1585,  1585,  1585,
    1585,  1585,  1585,     5,  1052,     5,  1053,  1585,  1585,  1585,
    1585,  1085,  1585,  1005,    25,    14,    14,     5,   445,    26,
    1458,  1498,  1479,   646,   646,  1354,  1484,  1485,  1420,  1398,
    1462,   667,  1000,   482,  1358,  1006,  1520,  1519,  1393,  1462,
     514,  1394,  1395,  1460,  1458,  1391,  1499,    98,    99,   100,
     101,   102,   634,  1542,   913,   913,   604,  1366,  1000,  1394,
    1458,     5,  1163,   982,  1585,  1585,     5,   989,   990,  1585,
    1585,   988,  1108,   876,   445,   944,    26,   944,    24,    26,
     944,   944,   482,  1430,  1472,   676,  1472,  1472,   445,  1502,
     445,   445,   445,   445,  1427,  1429,  1427,  1437,  1497,  1434,
    1502,  1497,     6,     7,     9,    10,    12,    13,    14,    15,
      16,    17,   305,   425,   426,   480,   607,   673,   723,   724,
    1445,  1447,  1423,  1501,  1502,   499,  1421,  1433,   321,  1323,
      26,  1374,  1375,  1376,  1462,  1491,  1494,   445,   830,   126,
     127,   129,   130,   131,   229,   237,   271,   280,   309,   310,
     354,   398,   452,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,  1277,  1281,   190,   565,  1282,  1298,  1108,
     213,   228,   229,   237,   271,   280,   309,   354,   398,  1275,
    1276,  1288,  1282,  1463,   510,  1461,   445,     5,   670,     5,
     445,   445,  1408,   445,   445,  1340,    26,  1455,  1455,    26,
     676,   482,   676,    26,  1456,    26,    26,  1456,  1456,    25,
    1465,   211,   311,   349,   413,   427,   527,   543,  1402,  1412,
    1413,  1414,  1415,  1337,  1333,   670,   670,   589,   638,     5,
     445,   735,     5,   445,   911,   445,    20,   445,  1510,     5,
     913,   617,   327,   744,   745,   913,  1049,  1585,  1585,     5,
     801,   510,   670,     5,   802,  1585,   798,   597,    20,  1006,
       5,  1006,  1198,  1567,    20,  1462,  1557,     8,  1510,   443,
     709,   911,  1369,   963,  1087,   718,  1221,   906,     5,   766,
    1163,   751,   733,  1006,  1163,   757,   445,   766,   766,  1585,
    1585,  1085,  1139,    25,  1143,  1163,   622,   959,  1173,   534,
     912,  1093,  1233,   115,   593,  1037,  1023,  1024,   670,   997,
    1585,   997,  1585,   739,    26,  1163,    26,  1163,   743,   445,
     482,  1511,  1499,  1485,  1485,  1477,     5,   445,   522,  1496,
    1359,  1462,   530,  1356,  1496,   676,     5,   445,     5,   597,
    1489,    18,    19,   117,   479,   482,   495,   534,   535,   547,
     588,   627,   639,   651,   652,   659,   662,  1006,  1465,  1497,
    1526,  1528,  1547,  1548,  1549,  1550,  1551,  1552,  1564,  1547,
    1547,  1547,  1462,  1544,  1546,  1543,  1544,  1545,  1540,  1367,
     676,  1163,  1006,  1585,  1585,  1585,  1585,   674,   445,   640,
     445,   445,    26,   445,   676,  1473,   676,   676,     5,   445,
     445,  1435,  1436,  1440,  1503,  1440,   482,  1497,  1440,   482,
    1497,  1440,    10,   302,   440,   442,  1502,     5,  1434,     5,
     589,   638,  1377,  1323,   676,   674,  1278,  1278,  1278,    25,
    1278,  1278,  1278,  1278,  1278,  1278,    25,    25,  1278,  1281,
    1163,  1189,  1190,   669,   498,  1243,  1585,    25,    25,    26,
      26,    26,    26,    26,    25,  1163,  1276,  1243,    26,  1402,
    1462,    20,  1006,  1462,  1345,   445,   445,     5,   445,  1473,
      26,  1473,     5,  1453,     5,   445,   445,   445,  1453,  1404,
    1458,   482,  1414,  1345,  1006,  1006,  1325,   673,   727,  1319,
    1320,  1321,  1327,    61,   138,   139,   297,   673,  1315,  1316,
    1317,   519,   891,  1315,     5,   428,  1510,     5,   482,   445,
     601,  1076,  1010,  1585,   736,    20,  1006,  1010,  1585,   954,
     913,   478,  1510,     8,   954,  1184,  1585,    26,  1005,    25,
    1303,  1181,   478,   766,   756,   760,   445,  1585,  1005,   913,
     957,   478,  1039,  1038,   492,  1025,  1026,    20,  1006,  1512,
    1513,   604,  1495,  1480,  1478,  1462,  1498,   195,  1399,     5,
     445,  1357,  1520,  1462,  1395,  1394,  1495,  1550,  1550,  1549,
     482,   482,   482,   482,   482,   482,   482,  1006,   482,     5,
     445,    18,    19,    20,    21,  1524,   445,     5,   445,     5,
      14,   203,   577,  1541,  1184,  1394,   264,  1116,   872,   944,
      24,    26,   944,   944,   445,  1473,  1473,  1473,  1427,   493,
    1439,  1439,  1443,  1444,  1465,  1564,  1439,  1443,  1439,  1440,
    1502,  1501,  1375,  1473,   842,   589,   638,  1191,     5,  1189,
     114,   189,   251,   253,   269,   277,   281,   306,  1244,  1245,
    1299,  1116,  1289,     5,   478,  1461,    26,   445,    26,  1457,
     445,    26,   445,   482,  1434,  1318,  1584,    26,  1321,    26,
      26,  1318,  1323,  1317,   997,   739,   428,  1510,   913,   746,
     619,  1196,    26,   739,   478,  1076,   445,  1510,   293,   739,
     445,   445,   482,   758,   399,   764,   445,   753,  1138,  1585,
     510,   913,  1585,  1005,     5,   445,  1184,  1430,  1499,  1462,
     482,  1430,   445,  1525,  1449,  1549,  1553,  1449,  1449,  1449,
    1449,   510,   670,  1553,  1548,  1549,  1549,  1549,  1549,  1544,
      14,  1545,  1548,  1000,  1434,   196,   667,  1388,   445,   445,
    1441,  1465,  1506,     5,   445,   445,  1439,     7,  1190,  1246,
    1247,  1163,  1249,  1163,  1248,  1250,  1245,   292,   292,    26,
     445,   676,   445,  1405,   445,   890,  1510,   446,   255,   312,
     337,   346,   384,   392,   483,   653,   743,   747,   748,   482,
     670,   739,  1220,  1304,   761,   445,  1181,   764,   764,  1585,
     958,  1173,   626,  1073,  1513,  1493,  1430,   534,  1360,  1361,
    1502,  1493,   445,  1549,     5,   445,  1549,  1549,  1549,  1549,
      26,  1006,   445,   482,  1006,   944,   944,  1444,  1502,  1585,
    1585,  1251,  1585,  1252,  1585,  1585,   478,  1473,   445,   291,
     402,   406,   893,   894,   895,  1079,   992,   992,   992,   992,
     992,   992,    25,     5,   445,   913,    20,  1006,  1079,  1224,
    1225,  1226,   764,   766,   764,   294,   478,  1040,   739,     5,
     445,   340,   341,  1481,   445,  1549,   445,   445,   445,   445,
       5,   478,   510,  1547,  1585,  1585,   897,   896,   291,   895,
     898,   748,     5,  1227,   335,  1226,   762,  1585,  1361,    25,
    1006,  1482,  1483,    26,    26,   445,  1585,  1585,  1585,   913,
    1585,   445,  1037,   670,   670,     5,   478,     5,   478,   445,
     763,  1006,  1006,  1483,    26,   216,   399,   765,   670,   478,
    1181,  1006
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
#line 1000 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1003 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1007 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1013 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1018 "fgl.yacc"
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
#line 1030 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1035 "fgl.yacc"
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
#line 1058 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1059 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1060 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1061 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1062 "fgl.yacc"
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
#line 1073 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1079 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1080 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1081 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1083 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1088 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1089 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1100 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1103 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1106 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1106 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1113 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1114 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1135 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1136 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1143 "fgl.yacc"
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
#line 1154 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1158 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1159 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1163 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1169 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1171 "fgl.yacc"
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
#line 1182 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1184 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1186 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1188 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1192 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1194 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1255 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1259 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1263 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1270 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1273 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1277 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1281 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1288 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1294 "fgl.yacc"
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
#line 1303 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1307 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1312 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1316 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1324 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1328 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1332 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1334 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1340 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1345 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1348 "fgl.yacc"
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
#line 1364 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1371 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1375 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1379 "fgl.yacc"
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
#line 1401 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1401 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1405 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1406 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1407 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1412 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1415 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1421 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1424 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1433 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1437 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1443 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1446 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1461 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1471 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1477 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1486 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1499 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1502 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1504 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1510 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1512 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1517 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1522 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1528 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1532 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1547 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1550 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1553 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1556 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1559 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1562 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1584 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1593 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1612 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1617 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1620 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1629 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1635 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1650 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1654 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1659 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1669 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1669 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1670 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1670 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1671 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1671 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1672 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1672 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1673 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1673 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1681 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1685 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1691 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1695 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1710 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1713 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1716 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1719 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1722 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1725 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1734 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1742 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1747 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1760 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1764 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1779 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1780 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1788 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1788 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1797 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1797 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1806 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1807 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1808 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1811 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1816 "fgl.yacc"
    { }
    break;

  case 194:
#line 1816 "fgl.yacc"
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
#line 1833 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1837 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1852 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1853 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1854 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1855 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1860 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1866 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1875 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1879 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1895 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1897 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1898 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1905 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1905 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1906 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1907 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1910 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1912 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1922 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1937 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1937 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1943 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1944 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1945 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1946 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1947 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1948 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1949 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1950 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1951 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1952 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1955 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1956 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1957 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1958 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1962 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1967 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1972 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1976 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1979 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1983 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1984 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1985 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1986 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1987 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1988 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1989 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1990 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1991 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1994 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1995 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1996 "fgl.yacc"
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
#line 2031 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2035 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2037 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2039 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2041 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2046 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2050 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2050 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2054 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2056 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2057 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2058 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2059 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2061 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2066 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2066 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2069 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2071 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2077 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2079 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2085 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2093 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2093 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2096 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2098 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2099 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2100 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2101 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2103 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2124 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2133 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2135 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2136 "fgl.yacc"
    {
						dim_push_type("varchar",yyvsp[-1].str,0);
				}
    break;

  case 317:
#line 2139 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 318:
#line 2143 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2144 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2145 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2146 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2151 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2158 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2163 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2165 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2167 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2168 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2169 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2170 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2171 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2172 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2173 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2176 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2178 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2184 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2192 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2200 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2204 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2212 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2213 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2214 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2215 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2234 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2246 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2250 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2253 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2256 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2257 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2258 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2259 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2260 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2266 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2273 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2278 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2283 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2288 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2292 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2301 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2303 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2308 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2320 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2324 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2327 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2331 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2334 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2338 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
#line 2345 "fgl.yacc"
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
#line 2363 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2369 "fgl.yacc"
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
#line 2393 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2396 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2411 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 384:
#line 2413 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 385:
#line 2415 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 386:
#line 2417 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 387:
#line 2419 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 388:
#line 2421 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 389:
#line 2422 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 390:
#line 2429 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 391:
#line 2431 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 392:
#line 2435 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 393:
#line 2437 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 394:
#line 2439 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 395:
#line 2441 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 396:
#line 2443 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 397:
#line 2445 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 398:
#line 2447 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 399:
#line 2453 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 400:
#line 2467 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 401:
#line 2470 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 405:
#line 2489 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 408:
#line 2495 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 409:
#line 2499 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 410:
#line 2504 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 414:
#line 2514 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 415:
#line 2515 "fgl.yacc"
    {inc_counter();}
    break;

  case 421:
#line 2521 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 422:
#line 2528 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 423:
#line 2528 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 425:
#line 2533 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 426:
#line 2537 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 427:
#line 2543 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2551 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2557 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2566 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 431:
#line 2568 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 432:
#line 2575 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 433:
#line 2596 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 434:
#line 2601 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 435:
#line 2606 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 436:
#line 2610 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 437:
#line 2612 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 438:
#line 2615 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 439:
#line 2633 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 440:
#line 2639 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 441:
#line 2645 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2655 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 445:
#line 2661 "fgl.yacc"
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
#line 2733 "fgl.yacc"
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
#line 2744 "fgl.yacc"
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
#line 2752 "fgl.yacc"
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
#line 2760 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 450:
#line 2760 "fgl.yacc"
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
#line 2776 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 452:
#line 2780 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 453:
#line 2786 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 454:
#line 2789 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 455:
#line 2797 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 456:
#line 2801 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 457:
#line 2804 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 458:
#line 2810 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 459:
#line 2820 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 460:
#line 2825 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 461:
#line 2832 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 462:
#line 2835 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 463:
#line 2838 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 464:
#line 2843 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 465:
#line 2850 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 466:
#line 2855 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 467:
#line 2860 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 468:
#line 2865 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 469:
#line 2876 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 470:
#line 2884 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 471:
#line 2892 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 472:
#line 2897 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 473:
#line 2901 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 474:
#line 2906 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 475:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 476:
#line 2914 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 477:
#line 2920 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 478:
#line 2923 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 479:
#line 2927 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 480:
#line 2931 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 481:
#line 2935 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 482:
#line 2939 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 483:
#line 2943 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 484:
#line 2950 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 485:
#line 2960 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 486:
#line 2965 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 487:
#line 2971 "fgl.yacc"
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
#line 2981 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 489:
#line 2986 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 490:
#line 2989 "fgl.yacc"
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
#line 3003 "fgl.yacc"
    {chk4var=1;}
    break;

  case 492:
#line 3003 "fgl.yacc"
    {chk4var=0;}
    break;

  case 493:
#line 3003 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 494:
#line 3006 "fgl.yacc"
    {chk4var=1;}
    break;

  case 495:
#line 3006 "fgl.yacc"
    {chk4var=0;}
    break;

  case 496:
#line 3006 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 497:
#line 3010 "fgl.yacc"
    {chk4var=1;}
    break;

  case 498:
#line 3010 "fgl.yacc"
    {chk4var=0;}
    break;

  case 499:
#line 3010 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 500:
#line 3014 "fgl.yacc"
    {chk4var=1;}
    break;

  case 501:
#line 3014 "fgl.yacc"
    {chk4var=0;}
    break;

  case 502:
#line 3014 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 503:
#line 3018 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 504:
#line 3024 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 505:
#line 3030 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 506:
#line 3036 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 507:
#line 3044 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 508:
#line 3050 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3058 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3064 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3073 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3079 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3086 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3093 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 515:
#line 3102 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 516:
#line 3108 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 517:
#line 3114 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 518:
#line 3121 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 519:
#line 3127 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 520:
#line 3133 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3139 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3147 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3153 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3159 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3168 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 526:
#line 3174 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 527:
#line 3180 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 528:
#line 3190 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 529:
#line 3191 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 532:
#line 3199 "fgl.yacc"
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
#line 3210 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 534:
#line 3211 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 535:
#line 3217 "fgl.yacc"
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
#line 3228 "fgl.yacc"
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
#line 3238 "fgl.yacc"
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
#line 3251 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 541:
#line 3256 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 542:
#line 3263 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 543:
#line 3267 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 544:
#line 3270 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 545:
#line 3273 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 546:
#line 3279 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 547:
#line 3282 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 548:
#line 3285 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 549:
#line 3302 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 550:
#line 3305 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 551:
#line 3311 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 552:
#line 3312 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 553:
#line 3313 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 555:
#line 3318 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 556:
#line 3319 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 557:
#line 3320 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 558:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 559:
#line 3323 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 560:
#line 3324 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 561:
#line 3325 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 562:
#line 3327 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 563:
#line 3328 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 565:
#line 3334 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 566:
#line 3338 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 567:
#line 3342 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 568:
#line 3347 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 569:
#line 3351 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 570:
#line 3366 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 571:
#line 3370 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 572:
#line 3371 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 573:
#line 3378 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 575:
#line 3395 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 576:
#line 3399 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 577:
#line 3405 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 578:
#line 3409 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 579:
#line 3418 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 580:
#line 3419 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 581:
#line 3431 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 582:
#line 3437 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 583:
#line 3445 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 590:
#line 3462 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 591:
#line 3464 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 592:
#line 3467 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 593:
#line 3469 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 598:
#line 3483 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 599:
#line 3485 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 600:
#line 3488 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 601:
#line 3490 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 614:
#line 3521 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 615:
#line 3523 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 616:
#line 3526 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 617:
#line 3528 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 618:
#line 3531 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 619:
#line 3533 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 620:
#line 3536 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 621:
#line 3538 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 622:
#line 3541 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 623:
#line 3543 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 624:
#line 3558 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 625:
#line 3574 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 626:
#line 3575 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 627:
#line 3576 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 628:
#line 3577 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 629:
#line 3578 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 630:
#line 3579 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 631:
#line 3580 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 635:
#line 3588 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 637:
#line 3594 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 638:
#line 3597 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 639:
#line 3602 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 640:
#line 3607 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 641:
#line 3610 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 642:
#line 3615 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 643:
#line 3620 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 644:
#line 3625 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 645:
#line 3632 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 646:
#line 3633 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 647:
#line 3640 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 648:
#line 3647 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 649:
#line 3649 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 650:
#line 3655 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 651:
#line 3660 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 652:
#line 3665 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 653:
#line 3670 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 654:
#line 3670 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 655:
#line 3673 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 656:
#line 3679 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 657:
#line 3684 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 658:
#line 3688 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 661:
#line 3696 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 662:
#line 3699 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 663:
#line 3702 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 664:
#line 3707 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 665:
#line 3712 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 666:
#line 3717 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 667:
#line 3724 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 669:
#line 3733 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 670:
#line 3795 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 672:
#line 3804 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 673:
#line 3813 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 675:
#line 3820 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 676:
#line 3823 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 677:
#line 3829 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 678:
#line 3835 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 679:
#line 3839 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 680:
#line 3843 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 681:
#line 3849 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 682:
#line 3853 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 683:
#line 3857 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 684:
#line 3862 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 685:
#line 3867 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 704:
#line 3908 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 705:
#line 3915 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 706:
#line 3917 "fgl.yacc"
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
#line 3936 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 710:
#line 3939 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 711:
#line 3941 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 712:
#line 3944 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 713:
#line 3948 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 714:
#line 3951 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 715:
#line 3957 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 716:
#line 3968 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 717:
#line 3969 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 718:
#line 3972 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 720:
#line 3978 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 721:
#line 3982 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 722:
#line 3983 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 723:
#line 3987 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 727:
#line 4002 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 728:
#line 4004 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 731:
#line 4013 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 732:
#line 4016 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 733:
#line 4020 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 734:
#line 4023 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 735:
#line 4026 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 736:
#line 4029 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 737:
#line 4032 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 738:
#line 4036 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 739:
#line 4039 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 740:
#line 4042 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 741:
#line 4045 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 742:
#line 4048 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 743:
#line 4051 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 744:
#line 4054 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 745:
#line 4057 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 746:
#line 4060 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 747:
#line 4061 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 748:
#line 4061 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 749:
#line 4062 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 750:
#line 4062 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 751:
#line 4063 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 752:
#line 4063 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 753:
#line 4064 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 754:
#line 4067 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 755:
#line 4068 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 756:
#line 4071 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 757:
#line 4079 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 758:
#line 4083 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 759:
#line 4089 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 760:
#line 4093 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 761:
#line 4098 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 762:
#line 4103 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 763:
#line 4108 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 764:
#line 4109 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 765:
#line 4110 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 766:
#line 4114 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 767:
#line 4118 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 768:
#line 4127 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 769:
#line 4132 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 770:
#line 4136 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 771:
#line 4143 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 772:
#line 4152 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 773:
#line 4158 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 774:
#line 4159 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 775:
#line 4160 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 776:
#line 4161 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 777:
#line 4162 "fgl.yacc"
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

  case 778:
#line 4172 "fgl.yacc"
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
#line 4186 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 781:
#line 4189 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 782:
#line 4196 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 783:
#line 4197 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 784:
#line 4198 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 785:
#line 4199 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 786:
#line 4200 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 787:
#line 4201 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 788:
#line 4202 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 789:
#line 4203 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 790:
#line 4204 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 791:
#line 4209 "fgl.yacc"
    {iskey=1;}
    break;

  case 792:
#line 4209 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 793:
#line 4211 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 794:
#line 4214 "fgl.yacc"
    {iskey=1;}
    break;

  case 795:
#line 4214 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 796:
#line 4216 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 797:
#line 4220 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 798:
#line 4223 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 799:
#line 4224 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 801:
#line 4227 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 807:
#line 4239 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 808:
#line 4240 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 809:
#line 4241 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 810:
#line 4242 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 811:
#line 4243 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 812:
#line 4244 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 813:
#line 4245 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 814:
#line 4246 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 815:
#line 4247 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 816:
#line 4248 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 817:
#line 4249 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 818:
#line 4250 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 819:
#line 4251 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 820:
#line 4252 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 821:
#line 4256 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 822:
#line 4274 "fgl.yacc"
    {chk4var=1;}
    break;

  case 823:
#line 4274 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 824:
#line 4277 "fgl.yacc"
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

  case 825:
#line 4301 "fgl.yacc"
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

  case 827:
#line 4319 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 828:
#line 4325 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 829:
#line 4331 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 830:
#line 4337 "fgl.yacc"
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

  case 831:
#line 4349 "fgl.yacc"
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

  case 832:
#line 4374 "fgl.yacc"
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

  case 835:
#line 4390 "fgl.yacc"
    {
	}
    break;

  case 844:
#line 4415 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 848:
#line 4423 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 863:
#line 4449 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 864:
#line 4450 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 865:
#line 4458 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 866:
#line 4463 "fgl.yacc"
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

  case 867:
#line 4479 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 868:
#line 4485 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 870:
#line 4500 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 871:
#line 4513 "fgl.yacc"
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

  case 872:
#line 4523 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 873:
#line 4530 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 874:
#line 4537 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 875:
#line 4543 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 876:
#line 4543 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 877:
#line 4548 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 878:
#line 4554 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 879:
#line 4562 "fgl.yacc"
    {
}
    break;

  case 883:
#line 4574 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 885:
#line 4582 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 886:
#line 4588 "fgl.yacc"
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

  case 889:
#line 4604 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 890:
#line 4608 "fgl.yacc"
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

  case 891:
#line 4621 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 893:
#line 4639 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 894:
#line 4647 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 895:
#line 4653 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 896:
#line 4664 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 897:
#line 4668 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 898:
#line 4675 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 899:
#line 4682 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 900:
#line 4688 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 901:
#line 4693 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 904:
#line 4700 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 905:
#line 4701 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 906:
#line 4703 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 907:
#line 4704 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 908:
#line 4707 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 909:
#line 4708 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 910:
#line 4709 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 911:
#line 4711 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 912:
#line 4716 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 913:
#line 4721 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 914:
#line 4728 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 918:
#line 4735 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 919:
#line 4737 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 920:
#line 4739 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 921:
#line 4747 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 922:
#line 4753 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 923:
#line 4757 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 926:
#line 4769 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 927:
#line 4772 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 928:
#line 4776 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 929:
#line 4779 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 931:
#line 4788 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 932:
#line 4791 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 933:
#line 4794 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 940:
#line 4810 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 941:
#line 4815 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 942:
#line 4815 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 943:
#line 4818 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 944:
#line 4846 "fgl.yacc"
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

  case 946:
#line 4903 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 948:
#line 4910 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 949:
#line 4914 "fgl.yacc"
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

  case 950:
#line 4957 "fgl.yacc"
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

  case 954:
#line 5005 "fgl.yacc"
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

  case 955:
#line 5019 "fgl.yacc"
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

  case 960:
#line 5043 "fgl.yacc"
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

  case 961:
#line 5107 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 962:
#line 5112 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 963:
#line 5120 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 964:
#line 5125 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 965:
#line 5133 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 966:
#line 5139 "fgl.yacc"
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

  case 967:
#line 5171 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 968:
#line 5174 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 969:
#line 5176 "fgl.yacc"
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

  case 970:
#line 5217 "fgl.yacc"
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

  case 975:
#line 5270 "fgl.yacc"
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

  case 976:
#line 5322 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 978:
#line 5331 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 979:
#line 5336 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 980:
#line 5347 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 981:
#line 5354 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 983:
#line 5362 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 984:
#line 5365 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 985:
#line 5366 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 987:
#line 5368 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 988:
#line 5369 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 989:
#line 5372 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 990:
#line 5375 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 991:
#line 5381 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 992:
#line 5384 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 993:
#line 5388 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 994:
#line 5393 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 995:
#line 5401 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 996:
#line 5406 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 997:
#line 5413 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 998:
#line 5415 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1003:
#line 5443 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1004:
#line 5450 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1005:
#line 5457 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1006:
#line 5460 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1007:
#line 5474 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1012:
#line 5491 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1013:
#line 5496 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1014:
#line 5502 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1016:
#line 5509 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1017:
#line 5514 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1018:
#line 5517 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1019:
#line 5518 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1020:
#line 5521 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1021:
#line 5522 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1022:
#line 5525 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1023:
#line 5526 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1024:
#line 5531 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1025:
#line 5538 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1026:
#line 5541 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1027:
#line 5547 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1028:
#line 5549 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1029:
#line 5551 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1030:
#line 5553 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1031:
#line 5556 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1032:
#line 5556 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1033:
#line 5557 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1034:
#line 5562 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1035:
#line 5570 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1036:
#line 5571 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1037:
#line 5576 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1038:
#line 5578 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1039:
#line 5580 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1043:
#line 5598 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1044:
#line 5599 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1045:
#line 5600 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1046:
#line 5601 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1047:
#line 5602 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1048:
#line 5603 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1049:
#line 5604 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1050:
#line 5605 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1051:
#line 5606 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1052:
#line 5607 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1053:
#line 5608 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1054:
#line 5609 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1055:
#line 5610 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1056:
#line 5611 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1057:
#line 5612 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1058:
#line 5613 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1059:
#line 5614 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1060:
#line 5615 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1061:
#line 5616 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1062:
#line 5617 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1063:
#line 5618 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1064:
#line 5619 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1065:
#line 5620 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1066:
#line 5621 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1067:
#line 5622 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1068:
#line 5623 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1069:
#line 5638 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1072:
#line 5647 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1073:
#line 5651 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1074:
#line 5655 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1075:
#line 5659 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1076:
#line 5663 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1078:
#line 5683 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1079:
#line 5688 "fgl.yacc"
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

  case 1080:
#line 5701 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1081:
#line 5702 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1082:
#line 5706 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1083:
#line 5711 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1084:
#line 5712 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1085:
#line 5716 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1089:
#line 5722 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1090:
#line 5725 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1092:
#line 5740 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1093:
#line 5744 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1094:
#line 5750 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1095:
#line 5751 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1096:
#line 5756 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1097:
#line 5757 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1098:
#line 5760 "fgl.yacc"
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

  case 1100:
#line 5787 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1101:
#line 5791 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1102:
#line 5795 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1103:
#line 5799 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1104:
#line 5806 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1105:
#line 5807 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1111:
#line 5819 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1112:
#line 5825 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1113:
#line 5833 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1114:
#line 5839 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1115:
#line 5841 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1119:
#line 5851 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1120:
#line 5851 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1121:
#line 5856 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1122:
#line 5860 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1123:
#line 5865 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1124:
#line 5865 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1125:
#line 5869 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1126:
#line 5869 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1127:
#line 5870 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1128:
#line 5870 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1129:
#line 5871 "fgl.yacc"
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

  case 1130:
#line 5884 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1131:
#line 5885 "fgl.yacc"
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

  case 1132:
#line 5901 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1139:
#line 5913 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1140:
#line 5913 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1141:
#line 5919 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1142:
#line 5919 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1143:
#line 5922 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1144:
#line 5922 "fgl.yacc"
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

  case 1145:
#line 5938 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1146:
#line 5939 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1147:
#line 5940 "fgl.yacc"
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

  case 1148:
#line 5949 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1149:
#line 5961 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1155:
#line 5972 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1156:
#line 5977 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1157:
#line 5977 "fgl.yacc"
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

  case 1158:
#line 5998 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1159:
#line 6003 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1160:
#line 6009 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1161:
#line 6010 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1162:
#line 6011 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1163:
#line 6015 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1164:
#line 6016 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1165:
#line 6017 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1166:
#line 6018 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1167:
#line 6022 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1168:
#line 6032 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1169:
#line 6034 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1170:
#line 6039 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1171:
#line 6042 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1172:
#line 6047 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1173:
#line 6054 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1174:
#line 6061 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1175:
#line 6068 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1176:
#line 6077 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1177:
#line 6084 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1178:
#line 6091 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1179:
#line 6098 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1180:
#line 6105 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1185:
#line 6118 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1186:
#line 6119 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1187:
#line 6120 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1188:
#line 6121 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1189:
#line 6122 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1190:
#line 6123 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1191:
#line 6124 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1192:
#line 6125 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1193:
#line 6126 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1194:
#line 6127 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1197:
#line 6133 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1198:
#line 6134 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1199:
#line 6135 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1200:
#line 6136 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1205:
#line 6145 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1206:
#line 6146 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1207:
#line 6147 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1208:
#line 6148 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1209:
#line 6149 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1210:
#line 6150 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1211:
#line 6151 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1212:
#line 6152 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1213:
#line 6154 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1214:
#line 6155 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1215:
#line 6156 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1216:
#line 6157 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1217:
#line 6159 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1218:
#line 6160 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1219:
#line 6161 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1220:
#line 6162 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1224:
#line 6167 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1225:
#line 6168 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1229:
#line 6175 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1230:
#line 6184 "fgl.yacc"
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

  case 1231:
#line 6193 "fgl.yacc"
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

  case 1232:
#line 6206 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1233:
#line 6215 "fgl.yacc"
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

  case 1234:
#line 6226 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1235:
#line 6230 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1236:
#line 6234 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1237:
#line 6240 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1238:
#line 6245 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1239:
#line 6253 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1240:
#line 6256 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1241:
#line 6265 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1242:
#line 6276 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1244:
#line 6283 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1245:
#line 6291 "fgl.yacc"
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

  case 1246:
#line 6301 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1247:
#line 6304 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1248:
#line 6308 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1249:
#line 6316 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1250:
#line 6319 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1251:
#line 6325 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1252:
#line 6329 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1253:
#line 6333 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1254:
#line 6337 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1255:
#line 6341 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1256:
#line 6347 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1257:
#line 6348 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1258:
#line 6349 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1259:
#line 6350 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1260:
#line 6355 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1261:
#line 6357 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1262:
#line 6360 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1263:
#line 6364 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1264:
#line 6367 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1265:
#line 6374 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1266:
#line 6379 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1267:
#line 6380 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1268:
#line 6381 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1269:
#line 6382 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1270:
#line 6387 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1271:
#line 6388 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1272:
#line 6394 "fgl.yacc"
    {insql=1;}
    break;

  case 1273:
#line 6394 "fgl.yacc"
    {insql=0;}
    break;

  case 1274:
#line 6394 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1275:
#line 6399 "fgl.yacc"
    {insql=1;}
    break;

  case 1276:
#line 6399 "fgl.yacc"
    {insql=0;}
    break;

  case 1277:
#line 6399 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1278:
#line 6407 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1279:
#line 6408 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1281:
#line 6413 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1282:
#line 6418 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1283:
#line 6419 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1284:
#line 6420 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1285:
#line 6421 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1286:
#line 6422 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1288:
#line 6427 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1289:
#line 6427 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1291:
#line 6431 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1292:
#line 6435 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1293:
#line 6436 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1294:
#line 6439 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1295:
#line 6440 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1296:
#line 6443 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1297:
#line 6446 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1298:
#line 6449 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1299:
#line 6455 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1300:
#line 6457 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1302:
#line 6470 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1303:
#line 6474 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1304:
#line 6475 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1306:
#line 6480 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1307:
#line 6483 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1308:
#line 6489 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1309:
#line 6492 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1310:
#line 6500 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1312:
#line 6507 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1313:
#line 6511 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1314:
#line 6515 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1315:
#line 6521 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1316:
#line 6524 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1317:
#line 6533 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1318:
#line 6536 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1319:
#line 6539 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1320:
#line 6542 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1321:
#line 6545 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1322:
#line 6548 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1323:
#line 6551 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1324:
#line 6558 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1325:
#line 6561 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1326:
#line 6568 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1327:
#line 6571 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1328:
#line 6577 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1329:
#line 6580 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1330:
#line 6587 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1331:
#line 6590 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1333:
#line 6598 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1335:
#line 6607 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1336:
#line 6610 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1337:
#line 6616 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1338:
#line 6619 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1339:
#line 6625 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1340:
#line 6632 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1341:
#line 6633 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1342:
#line 6637 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1343:
#line 6647 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1344:
#line 6650 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1345:
#line 6656 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1346:
#line 6658 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1347:
#line 6663 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1348:
#line 6664 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1349:
#line 6669 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1350:
#line 6670 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1351:
#line 6676 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1352:
#line 6677 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1356:
#line 6704 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1362:
#line 6710 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1363:
#line 6713 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1364:
#line 6716 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1365:
#line 6722 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1367:
#line 6728 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1369:
#line 6739 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1370:
#line 6753 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1371:
#line 6762 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1372:
#line 6762 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1373:
#line 6767 "fgl.yacc"
    {insql=1;}
    break;

  case 1374:
#line 6767 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1375:
#line 6772 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1376:
#line 6775 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1377:
#line 6777 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6784 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6788 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1381:
#line 6792 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1382:
#line 6799 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1383:
#line 6802 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1384:
#line 6809 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1385:
#line 6813 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1386:
#line 6819 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1387:
#line 6824 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1388:
#line 6828 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1389:
#line 6834 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1390:
#line 6837 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1391:
#line 6843 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1392:
#line 6850 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1393:
#line 6854 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1394:
#line 6859 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1395:
#line 6869 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1396:
#line 6872 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1397:
#line 6874 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1398:
#line 6876 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1399:
#line 6878 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1400:
#line 6880 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1401:
#line 6882 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1402:
#line 6884 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1403:
#line 6890 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1404:
#line 6900 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1405:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6913 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6916 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6923 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1414:
#line 6928 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1415:
#line 6933 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1416:
#line 6940 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1417:
#line 6941 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1418:
#line 6948 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1419:
#line 6959 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1420:
#line 6960 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1421:
#line 6961 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1422:
#line 6964 "fgl.yacc"
    {insql=1;}
    break;

  case 1423:
#line 6964 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1424:
#line 6969 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1425:
#line 6974 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1427:
#line 6980 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1429:
#line 6984 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1430:
#line 6989 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1431:
#line 6994 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1432:
#line 6998 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1434:
#line 7004 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1435:
#line 7008 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1436:
#line 7015 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 7016 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7017 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 7018 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7028 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1444:
#line 7029 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1445:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1446:
#line 7034 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1447:
#line 7035 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1450:
#line 7042 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 7045 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 7048 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1457:
#line 7053 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1458:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 7061 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 7067 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7077 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1466:
#line 7082 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1467:
#line 7084 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7090 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7093 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1472:
#line 7099 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1473:
#line 7107 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1474:
#line 7112 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7122 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 7128 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1480:
#line 7133 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 7134 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7136 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7142 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1485:
#line 7147 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1486:
#line 7150 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1487:
#line 7153 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1488:
#line 7160 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7161 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1490:
#line 7162 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1491:
#line 7164 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1492:
#line 7177 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1493:
#line 7182 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1495:
#line 7186 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1496:
#line 7188 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7195 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1498:
#line 7198 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1499:
#line 7204 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1500:
#line 7212 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1501:
#line 7216 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1502:
#line 7220 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1503:
#line 7224 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1504:
#line 7228 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1505:
#line 7231 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1506:
#line 7234 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1507:
#line 7242 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1508:
#line 7249 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1511:
#line 7258 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1512:
#line 7264 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1513:
#line 7267 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1514:
#line 7278 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1515:
#line 7285 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1516:
#line 7291 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1517:
#line 7294 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7301 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1519:
#line 7308 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1521:
#line 7315 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1522:
#line 7321 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1523:
#line 7322 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1524:
#line 7323 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1526:
#line 7327 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1528:
#line 7332 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1529:
#line 7339 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1530:
#line 7344 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1531:
#line 7345 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1532:
#line 7348 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1533:
#line 7351 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1534:
#line 7356 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1535:
#line 7357 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1536:
#line 7362 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1537:
#line 7365 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1538:
#line 7371 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1539:
#line 7374 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1540:
#line 7380 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1541:
#line 7383 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1542:
#line 7389 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1543:
#line 7392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1544:
#line 7399 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1545:
#line 7400 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1546:
#line 7429 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1547:
#line 7431 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1548:
#line 7435 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1550:
#line 7448 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1551:
#line 7451 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1552:
#line 7454 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1553:
#line 7457 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1555:
#line 7465 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1556:
#line 7468 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1558:
#line 7474 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1560:
#line 7480 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1561:
#line 7483 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1562:
#line 7486 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1563:
#line 7489 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1564:
#line 7492 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1565:
#line 7495 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1566:
#line 7498 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1567:
#line 7501 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1568:
#line 7506 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1570:
#line 7513 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1576:
#line 7521 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1577:
#line 7522 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1578:
#line 7527 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1579:
#line 7530 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1580:
#line 7534 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1581:
#line 7540 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1582:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1583:
#line 7542 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1584:
#line 7543 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1589:
#line 7563 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1591:
#line 7567 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1592:
#line 7568 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1594:
#line 7571 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1595:
#line 7572 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1596:
#line 7581 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1603:
#line 7595 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1604:
#line 7597 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1605:
#line 7599 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1607:
#line 7602 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1609:
#line 7605 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1613:
#line 7610 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1614:
#line 7612 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1615:
#line 7615 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1616:
#line 7616 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1617:
#line 7623 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1621:
#line 7628 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1625:
#line 7644 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1626:
#line 7651 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1627:
#line 7655 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1628:
#line 7656 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1629:
#line 7657 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1630:
#line 7665 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1631:
#line 7666 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1632:
#line 7667 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1633:
#line 7678 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1634:
#line 7685 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1635:
#line 7690 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1636:
#line 7691 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1637:
#line 7692 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1638:
#line 7700 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1639:
#line 7701 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1640:
#line 7702 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1642:
#line 7728 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1643:
#line 7729 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1644:
#line 7730 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1645:
#line 7734 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1646:
#line 7737 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1647:
#line 7743 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1648:
#line 7748 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1649:
#line 7753 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1651:
#line 7764 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1655:
#line 7782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1656:
#line 7785 "fgl.yacc"
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

  case 1657:
#line 7798 "fgl.yacc"
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

  case 1658:
#line 7813 "fgl.yacc"
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

  case 1659:
#line 7825 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1660:
#line 7827 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1661:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1662:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1663:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1664:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1665:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1666:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1667:
#line 7831 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1668:
#line 7834 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1669:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1670:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1671:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1672:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1673:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1674:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1675:
#line 7841 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1676:
#line 7844 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1691:
#line 7851 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1692:
#line 7854 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1693:
#line 7855 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1694:
#line 7856 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1695:
#line 7860 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1696:
#line 7868 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1697:
#line 7868 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1698:
#line 7874 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1699:
#line 7874 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1700:
#line 7881 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1701:
#line 7881 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1702:
#line 7887 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1703:
#line 7887 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1704:
#line 7895 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1705:
#line 7896 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1706:
#line 7897 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1707:
#line 7900 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1708:
#line 7900 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1710:
#line 7904 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1711:
#line 7905 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1712:
#line 7916 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1713:
#line 7919 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1714:
#line 7925 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1715:
#line 7930 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1716:
#line 7938 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1717:
#line 7950 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1718:
#line 7951 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1719:
#line 7954 "fgl.yacc"
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

  case 1720:
#line 7969 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1721:
#line 7980 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1722:
#line 7983 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1723:
#line 7991 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1724:
#line 8000 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1725:
#line 8003 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1726:
#line 8007 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1727:
#line 8010 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1728:
#line 8011 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1730:
#line 8024 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1731:
#line 8025 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1732:
#line 8034 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1733:
#line 8043 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1734:
#line 8048 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1735:
#line 8049 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1736:
#line 8050 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1737:
#line 8051 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1738:
#line 8058 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1739:
#line 8061 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1740:
#line 8067 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1741:
#line 8070 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1742:
#line 8077 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1743:
#line 8089 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1744:
#line 8098 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1745:
#line 8101 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1746:
#line 8104 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1747:
#line 8110 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1748:
#line 8116 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1749:
#line 8119 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1750:
#line 8120 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1751:
#line 8121 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1752:
#line 8122 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1753:
#line 8123 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1754:
#line 8126 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1755:
#line 8133 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1756:
#line 8135 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1757:
#line 8137 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1758:
#line 8139 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1759:
#line 8141 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1760:
#line 8142 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1761:
#line 8143 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1762:
#line 8144 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1763:
#line 8145 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1764:
#line 8146 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1765:
#line 8147 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1766:
#line 8149 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1767:
#line 8151 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1768:
#line 8153 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1769:
#line 8155 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1770:
#line 8157 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1771:
#line 8159 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1772:
#line 8161 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1773:
#line 8162 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1774:
#line 8164 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1775:
#line 8165 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1776:
#line 8166 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1777:
#line 8172 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1778:
#line 8173 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1780:
#line 8183 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1781:
#line 8191 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1782:
#line 8195 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1783:
#line 8202 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1784:
#line 8202 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1786:
#line 8206 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1787:
#line 8211 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1788:
#line 8211 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1790:
#line 8215 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1791:
#line 8219 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1794:
#line 8228 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1795:
#line 8228 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1800:
#line 8247 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1801:
#line 8248 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1804:
#line 8256 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1805:
#line 8262 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1808:
#line 8281 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1809:
#line 8282 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1810:
#line 8283 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1811:
#line 8284 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1812:
#line 8285 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1813:
#line 8286 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1814:
#line 8290 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1815:
#line 8291 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1816:
#line 8292 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1818:
#line 8297 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1819:
#line 8298 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1820:
#line 8302 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1821:
#line 8318 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1822:
#line 8319 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1823:
#line 8320 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1824:
#line 8324 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1825:
#line 8338 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1826:
#line 8342 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1828:
#line 8351 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1830:
#line 8356 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1831:
#line 8357 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2147:
#line 8681 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2148:
#line 8681 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2149:
#line 8688 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2150:
#line 8688 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2151:
#line 8776 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2152:
#line 8780 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2153:
#line 8782 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2154:
#line 8789 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2155:
#line 8793 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2156:
#line 8799 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2157:
#line 8807 "fgl.yacc"
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
#line 8817 "fgl.yacc"
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
#line 8827 "fgl.yacc"
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
#line 8839 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2161:
#line 8842 "fgl.yacc"
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
#line 8861 "fgl.yacc"
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
#line 8887 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2164:
#line 8890 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2166:
#line 8899 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2167:
#line 8904 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2168:
#line 8907 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2169:
#line 8915 "fgl.yacc"
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
#line 8923 "fgl.yacc"
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
#line 8936 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2172:
#line 8939 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2173:
#line 8947 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2174:
#line 8950 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2175:
#line 8953 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2176:
#line 8961 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 2177:
#line 8965 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 2178:
#line 8966 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 2179:
#line 8967 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 2180:
#line 8968 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2181:
#line 8969 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2182:
#line 8970 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2183:
#line 8971 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2184:
#line 8972 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2185:
#line 8976 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2186:
#line 8977 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2187:
#line 8978 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2188:
#line 8979 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2189:
#line 8980 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2190:
#line 8986 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2191:
#line 8987 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2192:
#line 8988 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2193:
#line 8989 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2194:
#line 8990 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2195:
#line 8991 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 8992 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 8993 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 8994 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2199:
#line 8995 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2200:
#line 8996 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2201:
#line 8997 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2202:
#line 8998 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2203:
#line 8999 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2204:
#line 9000 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2205:
#line 9001 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2206:
#line 9006 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2207:
#line 9012 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2208:
#line 9013 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2209:
#line 9021 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2210:
#line 9023 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2212:
#line 9029 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2213:
#line 9033 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2214:
#line 9037 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2215:
#line 9053 "fgl.yacc"
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
#line 9067 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 2217:
#line 9073 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2218:
#line 9075 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2222:
#line 9089 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 2223:
#line 9092 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 2224:
#line 9099 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2225:
#line 9102 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 2226:
#line 9132 "fgl.yacc"
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
#line 9157 "fgl.yacc"
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
#line 9212 "fgl.yacc"
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
#line 9247 "fgl.yacc"
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
#line 9256 "fgl.yacc"
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
#line 9267 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 2232:
#line 9270 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 2233:
#line 9276 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 2234:
#line 9289 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2235:
#line 9303 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2236:
#line 9306 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2237:
#line 9310 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2238:
#line 9325 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2239:
#line 9325 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2240:
#line 9331 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2241:
#line 9332 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2242:
#line 9335 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2243:
#line 9336 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2244:
#line 9337 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2245:
#line 9338 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2246:
#line 9339 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2247:
#line 9340 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2248:
#line 9341 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2249:
#line 9352 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2250:
#line 9356 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2251:
#line 9360 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2252:
#line 9364 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2253:
#line 9369 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2254:
#line 9373 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2255:
#line 9378 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2257:
#line 9386 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2259:
#line 9392 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2260:
#line 9398 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2261:
#line 9402 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2266:
#line 9420 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2267:
#line 9427 "fgl.yacc"
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
#line 9437 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2269:
#line 9437 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19324 "y.tab.c"

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


#line 1000 "fgl.yacc"

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



