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
char *into_temp_clause=0;
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
#line 215 "fgl.yacc"
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
#line 1709 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1721 "y.tab.c"

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
#define YYLAST   10819

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  728
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  863
/* YYNRULES -- Number of rules. */
#define YYNRULES  2351
/* YYNRULES -- Number of states. */
#define YYNSTATES  3776

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
    2725,  2726,  2727,  2742,  2743,  2744,  2752,  2754,  2757,  2758,
    2762,  2763,  2768,  2769,  2775,  2777,  2778,  2782,  2783,  2791,
    2792,  2798,  2800,  2803,  2804,  2806,  2808,  2810,  2811,  2813,
    2815,  2818,  2821,  2824,  2826,  2828,  2830,  2832,  2836,  2838,
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
    3494,  3496,  3498,  3501,  3504,  3505,  3508,  3509,  3514,  3516,
    3520,  3524,  3530,  3531,  3534,  3539,  3541,  3543,  3545,  3547,
    3549,  3550,  3552,  3554,  3558,  3561,  3567,  3570,  3576,  3582,
    3588,  3594,  3600,  3606,  3607,  3610,  3612,  3615,  3618,  3621,
    3624,  3627,  3630,  3632,  3635,  3638,  3641,  3644,  3646,  3649,
    3652,  3655,  3658,  3660,  3662,  3664,  3665,  3668,  3671,  3674,
    3677,  3680,  3683,  3686,  3689,  3692,  3694,  3696,  3698,  3700,
    3702,  3704,  3706,  3708,  3711,  3714,  3717,  3720,  3723,  3725,
    3727,  3729,  3730,  3734,  3737,  3738,  3739,  3740,  3741,  3742,
    3743,  3759,  3760,  3763,  3766,  3767,  3769,  3770,  3771,  3772,
    3773,  3774,  3775,  3791,  3794,  3795,  3796,  3797,  3808,  3809,
    3811,  3815,  3819,  3822,  3827,  3831,  3835,  3839,  3841,  3844,
    3847,  3850,  3853,  3855,  3857,  3858,  3859,  3868,  3869,  3870,
    3880,  3881,  3883,  3885,  3888,  3891,  3894,  3897,  3899,  3901,
    3903,  3904,  3906,  3908,  3911,  3914,  3917,  3926,  3929,  3932,
    3937,  3940,  3941,  3943,  3945,  3949,  3952,  3955,  3957,  3959,
    3963,  3965,  3967,  3970,  3972,  3976,  3980,  3984,  3986,  3990,
    3992,  3994,  3996,  3998,  4000,  4002,  4004,  4007,  4012,  4014,
    4018,  4020,  4024,  4027,  4032,  4034,  4038,  4040,  4043,  4048,
    4050,  4054,  4056,  4058,  4060,  4063,  4067,  4072,  4075,  4080,
    4081,  4084,  4087,  4092,  4094,  4098,  4100,  4102,  4104,  4107,
    4109,  4111,  4113,  4115,  4117,  4120,  4127,  4134,  4135,  4137,
    4138,  4140,  4143,  4145,  4146,  4152,  4153,  4159,  4161,  4162,
    4166,  4168,  4172,  4174,  4178,  4180,  4182,  4183,  4188,  4190,
    4193,  4195,  4196,  4197,  4201,  4202,  4203,  4207,  4209,  4211,
    4213,  4215,  4217,  4219,  4222,  4225,  4230,  4234,  4238,  4240,
    4244,  4247,  4249,  4251,  4252,  4254,  4256,  4258,  4260,  4261,
    4263,  4267,  4269,  4273,  4275,  4276,  4280,  4282,  4284,  4286,
    4288,  4290,  4292,  4294,  4296,  4298,  4300,  4302,  4304,  4312,
    4319,  4324,  4329,  4331,  4333,  4335,  4336,  4338,  4341,  4343,
    4345,  4347,  4349,  4353,  4356,  4358,  4360,  4363,  4365,  4367,
    4368,  4372,  4374,  4378,  4380,  4384,  4386,  4388,  4395,  4396,
    4400,  4402,  4406,  4407,  4409,  4414,  4420,  4423,  4425,  4427,
    4432,  4434,  4438,  4443,  4448,  4453,  4455,  4459,  4461,  4463,
    4465,  4468,  4470,  4472,  4474,  4479,  4480,  4482,  4483,  4485,
    4487,  4490,  4493,  4495,  4497,  4499,  4501,  4503,  4508,  4510,
    4514,  4516,  4518,  4520,  4523,  4525,  4527,  4530,  4533,  4535,
    4539,  4542,  4545,  4547,  4551,  4553,  4556,  4561,  4563,  4566,
    4568,  4572,  4577,  4578,  4580,  4581,  4583,  4584,  4586,  4588,
    4592,  4594,  4598,  4600,  4603,  4605,  4609,  4612,  4615,  4616,
    4619,  4621,  4623,  4629,  4633,  4639,  4643,  4645,  4649,  4651,
    4653,  4654,  4656,  4660,  4664,  4668,  4675,  4680,  4685,  4690,
    4695,  4701,  4703,  4705,  4707,  4709,  4711,  4713,  4715,  4717,
    4719,  4721,  4723,  4725,  4726,  4728,  4730,  4732,  4734,  4736,
    4738,  4740,  4745,  4746,  4748,  4753,  4755,  4761,  4767,  4769,
    4771,  4773,  4775,  4777,  4782,  4784,  4789,  4796,  4801,  4803,
    4808,  4810,  4818,  4820,  4822,  4824,  4829,  4836,  4837,  4840,
    4845,  4847,  4849,  4851,  4853,  4855,  4857,  4859,  4863,  4865,
    4867,  4871,  4877,  4881,  4887,  4895,  4899,  4901,  4903,  4907,
    4913,  4917,  4923,  4931,  4933,  4934,  4938,  4944,  4946,  4949,
    4952,  4957,  4961,  4963,  4965,  4967,  4969,  4971,  4974,  4977,
    4978,  4982,  4983,  4987,  4989,  4991,  4993,  4995,  4997,  4999,
    5001,  5006,  5008,  5010,  5012,  5014,  5016,  5018,  5020,  5022,
    5024,  5026,  5028,  5030,  5032,  5034,  5039,  5041,  5045,  5047,
    5051,  5052,  5060,  5061,  5070,  5071,  5078,  5079,  5088,  5089,
    5091,  5094,  5096,  5100,  5102,  5106,  5112,  5114,  5116,  5118,
    5120,  5122,  5123,  5124,  5134,  5140,  5142,  5144,  5151,  5152,
    5156,  5158,  5162,  5167,  5169,  5170,  5173,  5178,  5185,  5186,
    5188,  5190,  5192,  5194,  5198,  5200,  5203,  5207,  5209,  5211,
    5214,  5217,  5219,  5221,  5223,  5226,  5229,  5232,  5235,  5240,
    5244,  5247,  5251,  5255,  5259,  5261,  5263,  5265,  5267,  5269,
    5271,  5277,  5283,  5289,  5295,  5301,  5306,  5311,  5315,  5320,
    5322,  5324,  5326,  5330,  5332,  5338,  5346,  5352,  5353,  5356,
    5358,  5360,  5361,  5365,  5367,  5371,  5373,  5375,  5377,  5378,
    5382,  5384,  5386,  5388,  5390,  5395,  5402,  5404,  5406,  5409,
    5413,  5415,  5417,  5419,  5421,  5423,  5425,  5427,  5429,  5435,
    5441,  5446,  5452,  5454,  5459,  5461,  5463,  5471,  5476,  5478,
    5479,  5484,  5486,  5489,  5491,  5493,  5495,  5497,  5499,  5501,
    5503,  5505,  5507,  5509,  5511,  5513,  5515,  5517,  5519,  5521,
    5523,  5525,  5527,  5529,  5531,  5533,  5535,  5537,  5539,  5541,
    5543,  5545,  5547,  5549,  5551,  5553,  5555,  5557,  5559,  5561,
    5563,  5565,  5567,  5569,  5571,  5573,  5575,  5577,  5579,  5581,
    5583,  5585,  5587,  5589,  5591,  5593,  5595,  5597,  5599,  5601,
    5603,  5605,  5607,  5609,  5611,  5613,  5615,  5617,  5619,  5621,
    5623,  5625,  5627,  5629,  5631,  5633,  5635,  5637,  5639,  5641,
    5643,  5645,  5647,  5649,  5651,  5653,  5655,  5657,  5659,  5661,
    5663,  5665,  5667,  5669,  5671,  5673,  5675,  5677,  5679,  5681,
    5683,  5685,  5687,  5689,  5691,  5693,  5695,  5697,  5699,  5701,
    5703,  5705,  5707,  5709,  5711,  5713,  5715,  5717,  5719,  5721,
    5723,  5725,  5727,  5729,  5731,  5733,  5735,  5737,  5739,  5741,
    5743,  5745,  5747,  5749,  5751,  5753,  5755,  5757,  5759,  5761,
    5763,  5765,  5767,  5769,  5771,  5773,  5775,  5777,  5779,  5781,
    5783,  5785,  5787,  5789,  5791,  5793,  5795,  5797,  5799,  5801,
    5803,  5805,  5807,  5809,  5811,  5813,  5815,  5817,  5819,  5821,
    5823,  5825,  5827,  5829,  5831,  5833,  5835,  5837,  5839,  5841,
    5843,  5845,  5847,  5849,  5851,  5853,  5855,  5857,  5859,  5861,
    5863,  5865,  5867,  5869,  5871,  5873,  5875,  5877,  5879,  5881,
    5883,  5885,  5887,  5889,  5891,  5893,  5895,  5897,  5899,  5901,
    5903,  5905,  5907,  5909,  5911,  5913,  5915,  5917,  5919,  5921,
    5923,  5925,  5927,  5929,  5931,  5933,  5935,  5937,  5939,  5941,
    5943,  5945,  5947,  5949,  5951,  5953,  5955,  5957,  5959,  5961,
    5963,  5965,  5967,  5969,  5971,  5973,  5975,  5977,  5979,  5981,
    5983,  5985,  5987,  5989,  5991,  5993,  5995,  5997,  5999,  6001,
    6003,  6005,  6007,  6009,  6011,  6013,  6015,  6017,  6019,  6021,
    6023,  6025,  6027,  6029,  6031,  6033,  6035,  6037,  6039,  6041,
    6043,  6045,  6047,  6049,  6051,  6053,  6055,  6057,  6059,  6061,
    6063,  6065,  6067,  6069,  6071,  6073,  6075,  6077,  6079,  6081,
    6083,  6085,  6087,  6089,  6091,  6093,  6095,  6097,  6099,  6101,
    6103,  6105,  6107,  6109,  6111,  6113,  6115,  6117,  6119,  6121,
    6123,  6125,  6126,  6130,  6131,  6135,  6136,  6137,  6144,  6145,
    6148,  6151,  6159,  6163,  6167,  6170,  6173,  6176,  6178,  6182,
    6184,  6188,  6190,  6194,  6196,  6200,  6202,  6204,  6206,  6209,
    6212,  6214,  6216,  6219,  6224,  6230,  6238,  6246,  6256,  6258,
    6260,  6262,  6264,  6266,  6268,  6272,  6275,  6279,  6283,  6287,
    6293,  6299,  6305,  6311,  6317,  6322,  6327,  6331,  6336,  6338,
    6340,  6342,  6344,  6348,  6349,  6355,  6357,  6361,  6365,  6369,
    6371,  6373,  6376,  6378,  6380,  6384,  6386,  6390,  6394,  6396,
    6398,  6400,  6404,  6407,  6411,  6418,  6420,  6424,  6426,  6428,
    6429,  6430,  6437,  6438,  6441,  6442,  6444,  6446,  6449,  6452,
    6454,  6456,  6461,  6465,  6467,  6470,  6476,  6479,  6482,  6488,
    6489,  6492,  6494,  6496,  6499,  6506,  6513,  6515,  6516,  6518,
    6521,  6523,  6526,  6527,  6530,  6532,  6534,  6536,  6538,  6540,
    6542,  6544,  6546,  6548,  6550,  6552,  6554,  6556,  6558,  6560,
    6562,  6564,  6566,  6568,  6570,  6572,  6574,  6576,  6578,  6580,
    6582,  6584,  6586,  6588,  6590,  6592,  6594,  6596,  6598,  6600,
    6602,  6604,  6606,  6608,  6610,  6612,  6614,  6616,  6618,  6620,
    6622,  6624,  6626,  6628,  6630,  6632,  6634,  6636,  6638,  6640,
    6642,  6644,  6646,  6648,  6650,  6652,  6654,  6656,  6658,  6660,
    6662,  6664,  6666,  6668,  6670,  6672,  6674,  6676,  6678,  6680,
    6682,  6684,  6686,  6688,  6690,  6692,  6694,  6696,  6698,  6700,
    6702,  6704
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
      -1,   459,   482,   998,   445,   399,  1163,    -1,  1302,    -1,
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
      -1,    -1,    -1,   489,   815,   817,   816,  1271,    -1,   870,
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
     912,   739,    -1,   549,   929,   912,   739,   118,    -1,   267,
      -1,   267,   913,    -1,   339,    -1,   338,    -1,   266,    -1,
     418,    -1,   226,    -1,   265,    -1,   383,    -1,   382,    -1,
     296,    -1,   223,    -1,   222,    -1,   200,    -1,   256,    -1,
     184,    -1,   199,    -1,   240,    -1,   207,    -1,   914,    -1,
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
      -1,   446,   906,    -1,  1274,    -1,    -1,   558,   919,  1274,
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
    1163,     5,    26,   445,    -1,    -1,   859,   676,   859,    -1,
     856,    -1,   935,    -1,   342,   482,   954,   445,    -1,   151,
     482,   997,   445,    -1,   124,   482,   997,   445,    -1,   459,
     482,   955,   445,    -1,   245,   482,   954,   445,    -1,   112,
     482,   954,   445,    -1,   948,    -1,   930,    -1,  1467,    -1,
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
     998,    -1,    -1,    -1,    -1,   456,   957,  1000,   958,   960,
    1369,   959,  1585,   293,    -1,    -1,     8,   929,   911,    -1,
      -1,    -1,   688,  1006,   962,   812,   963,  1108,   965,   964,
     970,   689,    -1,    -1,   975,    -1,    -1,   966,    -1,   967,
      -1,   966,   967,    -1,    -1,   690,   968,  1585,    -1,    -1,
     691,   969,  1585,    -1,    -1,   971,    -1,   972,    -1,   971,
     972,    -1,    -1,   692,   973,  1585,    -1,    -1,   693,   974,
    1585,    -1,   976,   980,   379,    -1,   143,    -1,   143,   977,
     597,   978,    -1,   143,   438,   979,    -1,  1163,    -1,   977,
       5,  1163,    -1,  1006,    -1,   978,     5,  1006,    -1,  1163,
      -1,   979,     5,  1163,    -1,   981,    -1,   980,   981,    -1,
      -1,   694,   982,  1585,    -1,    -1,   695,   983,  1585,    -1,
      -1,   714,   978,   984,  1585,    -1,    -1,   532,   978,   985,
    1585,    -1,    -1,   675,   978,   986,  1585,    -1,    -1,    -1,
     646,  1163,    14,   913,   676,   913,   990,   988,  1585,   989,
     294,    -1,    -1,   622,   913,    -1,   596,   999,    -1,   605,
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
    1463,    -1,  1047,   670,    20,    -1,  1459,    -1,    -1,  1050,
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
      -1,  1129,    -1,  1284,    -1,  1294,    -1,  1133,    -1,   961,
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
    1116,    -1,    -1,    -1,   696,  1006,  1134,   812,  1135,  1136,
     697,    -1,  1137,    -1,  1136,  1137,    -1,    -1,   698,  1138,
    1585,    -1,    -1,   675,  1006,  1139,  1585,    -1,    -1,   609,
    1141,  1156,  1147,  1142,    -1,   416,    -1,    -1,   287,  1144,
    1585,    -1,    -1,    23,  1148,  1149,  1150,  1005,  1145,  1585,
      -1,    -1,    23,  1148,  1005,  1146,  1585,    -1,  1143,    -1,
    1147,  1143,    -1,    -1,  1081,    -1,    25,    -1,  1163,    -1,
      -1,  1163,    -1,    25,    -1,   304,  1154,    -1,   316,  1155,
      -1,   299,  1155,    -1,   636,    -1,    25,    -1,  1163,    -1,
    1154,    -1,  1155,     5,  1154,    -1,  1163,    -1,    25,    -1,
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
      -1,   120,  1237,    -1,  1275,  1283,    -1,   498,   114,    -1,
     498,  1244,    -1,  1245,    -1,  1244,  1245,    -1,    -1,   189,
    1246,  1585,    -1,    -1,   251,  1247,  1585,    -1,    -1,   281,
    1248,  1585,    -1,    -1,   269,  1249,  1585,    -1,    -1,   306,
    1250,  1585,    -1,    -1,   253,  1163,  1251,  1585,    -1,    -1,
     277,  1163,  1252,  1585,    -1,  1263,    -1,  1267,    -1,  1266,
      -1,  1254,    -1,  1292,    -1,  1257,    -1,    -1,   611,   913,
    1255,   533,    -1,    -1,   533,    -1,    -1,   620,    26,  1258,
    1256,    -1,   212,    -1,   679,  1279,    -1,   215,  1279,    -1,
     214,  1279,    -1,    -1,  1260,    -1,  1261,    -1,  1260,  1261,
      -1,  1272,  1262,    -1,    -1,   668,  1279,    -1,    -1,   570,
    1264,  1259,  1271,    -1,  1510,    -1,   482,  1510,   445,    -1,
     569,  1265,  1271,    -1,   568,  1270,  1269,  1268,  1271,    -1,
      -1,   206,   906,    -1,   206,   906,     5,   906,    -1,   663,
      -1,   664,    -1,   665,    -1,   666,    -1,  1163,    -1,    -1,
     573,    -1,  1273,    -1,  1272,     5,  1273,    -1,   913,  1306,
      -1,   659,   482,   906,   445,  1291,    -1,   117,  1291,    -1,
     547,   482,    20,   445,  1291,    -1,   464,   482,    20,   445,
    1291,    -1,   441,   482,   906,   445,  1291,    -1,   639,   482,
     906,   445,  1291,    -1,   652,   482,   906,   445,  1291,    -1,
     651,   482,   906,   445,  1291,    -1,    -1,   512,  1276,    -1,
    1277,    -1,  1276,  1277,    -1,   280,    26,    -1,   271,    26,
      -1,   354,    26,    -1,   237,    26,    -1,   309,    26,    -1,
     228,    -1,   398,    25,    -1,   398,  1163,    -1,   229,    25,
      -1,   213,    25,    -1,  1282,    -1,  1278,  1282,    -1,  1280,
     162,    -1,  1280,   164,    -1,  1280,   163,    -1,  1280,    -1,
    1012,    -1,    26,    -1,    -1,   512,  1278,    -1,   280,  1279,
      -1,   271,  1279,    -1,   354,  1279,    -1,   237,  1279,    -1,
     309,  1279,    -1,   310,  1279,    -1,   678,    25,    -1,   679,
    1279,    -1,   683,    -1,   680,    -1,   681,    -1,   682,    -1,
     687,    -1,   684,    -1,   685,    -1,   686,    -1,   129,  1279,
      -1,   130,  1279,    -1,   131,  1279,    -1,   398,    25,    -1,
     229,    25,    -1,   452,    -1,   126,    -1,   127,    -1,    -1,
     565,   669,  1189,    -1,   190,  1189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   516,  1285,  1006,   482,  1286,  1179,   445,
    1287,   812,  1288,  1242,  1289,  1243,  1290,   292,    -1,    -1,
     577,   906,    -1,   567,  1293,    -1,    -1,  1216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,  1295,  1006,   482,  1296,
    1179,   445,  1297,   812,  1298,  1301,  1299,  1243,  1300,   292,
      -1,  1281,  1283,    -1,    -1,    -1,    -1,   208,   482,    25,
       5,  1303,   766,  1304,   445,  1305,   764,    -1,    -1,   437,
      -1,   437,   271,    26,    -1,   437,   271,  1163,    -1,   657,
     913,    -1,   657,   913,   399,  1163,    -1,   657,   913,   216,
      -1,   657,   913,   628,    -1,   657,   913,   595,    -1,  1309,
      -1,   225,  1459,    -1,   378,  1459,    -1,   334,  1460,    -1,
      49,  1006,    -1,  1323,    -1,  1311,    -1,    -1,    -1,   258,
    1312,  1459,   482,  1313,  1327,   445,  1316,    -1,    -1,    -1,
     187,  1314,  1459,   482,  1315,  1327,   445,  1316,  1324,    -1,
      -1,  1317,    -1,  1318,    -1,  1317,  1318,    -1,   673,  1319,
      -1,   297,    26,    -1,    61,    26,    -1,   138,    -1,   139,
      -1,  1584,    -1,    -1,  1321,    -1,  1322,    -1,  1321,  1322,
      -1,   673,  1319,    -1,   727,    26,    -1,   157,  1460,   675,
    1459,   482,  1325,   445,  1320,    -1,   104,  1007,    -1,   105,
    1007,    -1,   224,  1459,   646,  1459,    -1,   109,  1459,    -1,
      -1,   321,    -1,  1326,    -1,  1325,     5,  1326,    -1,  1006,
     638,    -1,  1006,   589,    -1,  1006,    -1,  1328,    -1,  1327,
       5,  1328,    -1,  1411,    -1,  1409,    -1,   174,  1006,    -1,
     232,    -1,    59,  1006,  1331,    -1,    60,  1460,   154,    -1,
      60,  1460,   155,    -1,  1332,    -1,  1331,     5,  1332,    -1,
    1333,    -1,  1336,    -1,  1339,    -1,  1344,    -1,  1347,    -1,
    1343,    -1,  1342,    -1,   635,  1334,    -1,   635,   482,  1335,
     445,    -1,  1328,    -1,  1328,   714,  1006,    -1,  1334,    -1,
    1335,     5,  1334,    -1,   592,  1338,    -1,   592,   482,  1337,
     445,    -1,  1338,    -1,  1337,     5,  1338,    -1,  1006,    -1,
     506,  1341,    -1,   506,   482,  1340,   445,    -1,  1341,    -1,
    1340,     5,  1341,    -1,  1328,    -1,   138,    -1,   139,    -1,
     137,    26,    -1,   107,  1409,  1346,    -1,   107,   482,  1345,
     445,    -1,  1409,  1346,    -1,  1345,     5,  1409,  1346,    -1,
      -1,   110,  1006,    -1,   108,  1348,    -1,   108,   482,  1348,
     445,    -1,  1349,    -1,  1348,     5,  1349,    -1,  1006,    -1,
     318,    -1,   284,    -1,   218,  1352,    -1,   197,    -1,   186,
      -1,   173,    -1,   171,    -1,   175,    -1,   231,  1516,    -1,
     283,  1351,   511,  1510,   676,  1510,    -1,   351,   999,   511,
    1510,   676,  1510,    -1,    -1,  1516,    -1,    -1,   913,    -1,
     574,   913,    -1,   282,    -1,    -1,   301,  1356,  1459,  1359,
    1357,    -1,    -1,   530,  1358,   482,  1361,   445,    -1,  1496,
      -1,    -1,   482,  1360,   445,    -1,  1463,    -1,  1360,     5,
    1463,    -1,  1362,    -1,  1361,     5,  1362,    -1,  1502,    -1,
     534,    -1,    -1,   551,  1364,  1366,  1367,    -1,  1007,    -1,
    1371,  1000,    -1,  1000,    -1,    -1,    -1,   604,  1368,  1184,
      -1,    -1,    -1,   604,  1370,  1184,    -1,   552,    -1,   605,
      -1,   612,    -1,   429,    -1,   396,    -1,   448,    -1,   432,
     913,    -1,   405,   913,    -1,   290,  1459,   203,  1000,    -1,
     290,  1459,  1432,    -1,   565,   669,  1375,    -1,  1376,    -1,
    1375,     5,  1376,    -1,  1377,  1378,    -1,    26,    -1,  1463,
      -1,    -1,   638,    -1,   589,    -1,   329,    -1,   362,    -1,
      -1,   381,    -1,   410,  1383,  1381,    -1,  1558,    -1,  1558,
     662,  1006,    -1,    25,    -1,    -1,  1515,  1385,  1386,    -1,
    1417,    -1,  1421,    -1,  1380,    -1,  1517,    -1,  1379,    -1,
    1372,    -1,  1373,    -1,  1363,    -1,  1355,    -1,  1354,    -1,
    1486,    -1,  1538,    -1,   556,  1390,   675,  1459,   676,  1395,
    1389,    -1,   517,  1390,   675,  1459,   597,  1395,    -1,   556,
    1388,   676,  1395,    -1,   517,  1388,   597,  1395,    -1,   447,
      -1,   433,    -1,   642,    -1,    -1,   196,    -1,   667,  1006,
      -1,   220,    -1,   636,    -1,  1391,    -1,  1392,    -1,  1391,
       5,  1392,    -1,   522,  1393,    -1,   501,    -1,   490,    -1,
     529,  1393,    -1,   537,    -1,   559,    -1,    -1,   482,  1394,
     445,    -1,  1463,    -1,  1394,     5,  1463,    -1,  1396,    -1,
    1395,     5,  1396,    -1,   514,    -1,  1461,    -1,   288,  1459,
    1398,   667,  1496,  1400,    -1,    -1,   482,  1399,   445,    -1,
    1463,    -1,  1399,     5,  1463,    -1,    -1,   195,    -1,   543,
     482,  1435,   445,    -1,   298,   482,  1404,   445,  1403,    -1,
     349,  1405,    -1,  1406,    -1,  1459,    -1,  1459,   482,  1406,
     445,    -1,  1463,    -1,  1406,     5,  1463,    -1,   527,   482,
    1408,   445,    -1,   413,   482,  1408,   445,    -1,   311,   482,
    1408,   445,    -1,  1463,    -1,  1408,     5,  1463,    -1,  1407,
      -1,  1402,    -1,  1401,    -1,   452,  1466,    -1,   261,    -1,
     260,    -1,   259,    -1,  1006,  1451,  1412,  1413,    -1,    -1,
    1410,    -1,    -1,  1414,    -1,  1415,    -1,  1414,  1415,    -1,
    1416,  1346,    -1,   427,    -1,   211,    -1,   527,    -1,   413,
      -1,  1403,    -1,   543,   482,  1435,   445,    -1,   311,    -1,
     172,  1418,  1420,    -1,  1419,    -1,  1461,    -1,  1421,    -1,
    1420,  1421,    -1,  1397,    -1,  1387,    -1,   499,  1435,    -1,
     422,  1424,    -1,  1501,    -1,  1424,     5,  1501,    -1,   577,
    1435,    -1,   597,  1427,    -1,  1428,    -1,  1427,     5,  1428,
      -1,  1429,    -1,   566,  1429,    -1,   566,   482,  1430,   445,
      -1,  1459,    -1,  1459,  1465,    -1,  1428,    -1,  1430,     5,
    1428,    -1,  1426,  1432,  1433,  1434,    -1,    -1,  1425,    -1,
      -1,  1423,    -1,    -1,  1422,    -1,  1436,    -1,  1435,     6,
    1436,    -1,  1437,    -1,  1436,     7,  1437,    -1,  1438,    -1,
       9,  1438,    -1,  1449,    -1,   482,  1435,   445,    -1,   494,
    1497,    -1,   347,  1497,    -1,    -1,   493,  1442,    -1,  1503,
      -1,  1506,    -1,  1502,   673,   482,  1444,   445,    -1,  1502,
     673,  1497,    -1,  1502,   480,   482,  1444,   445,    -1,  1502,
     480,  1497,    -1,  1445,    -1,  1444,     5,  1445,    -1,  1564,
      -1,  1466,    -1,    -1,     9,    -1,  1502,  1446,   440,    -1,
    1502,  1446,   302,    -1,  1502,  1448,  1502,    -1,  1502,  1446,
     442,  1502,     7,  1502,    -1,  1502,   607,  1441,  1440,    -1,
    1502,   425,  1441,  1440,    -1,  1502,   724,  1441,  1440,    -1,
    1502,   426,  1441,  1440,    -1,  1502,  1446,    10,  1441,  1440,
      -1,    14,    -1,    17,    -1,    12,    -1,    13,    -1,   305,
      -1,    10,    -1,   723,    -1,    16,    -1,    15,    -1,  1447,
      -1,  1443,    -1,  1439,    -1,    -1,   636,    -1,   413,    -1,
     527,    -1,  1452,    -1,  1453,    -1,  1455,    -1,   372,    -1,
     372,   482,  1456,   445,    -1,    -1,   523,    -1,   523,   482,
      26,   445,    -1,   450,    -1,   450,   482,  1457,  1454,   445,
      -1,   563,   482,  1457,  1454,   445,    -1,   563,    -1,   588,
      -1,   460,    -1,   434,    -1,   373,    -1,   373,   482,  1456,
     445,    -1,   374,    -1,   374,   482,    26,   445,    -1,   374,
     482,    26,     5,    26,   445,    -1,   411,  1472,   676,  1473,
      -1,   411,    -1,   423,  1472,   676,  1473,    -1,   423,    -1,
     423,  1472,   482,    26,   445,   676,  1473,    -1,   625,    -1,
     584,    -1,   475,    -1,   475,   482,    26,   445,    -1,   475,
     482,    26,     5,    26,   445,    -1,    -1,     5,  1458,    -1,
     553,   482,  1457,   445,    -1,   616,    -1,   352,    -1,   553,
      -1,   116,    -1,    26,    -1,    26,    -1,    26,    -1,    25,
     670,  1006,    -1,    25,    -1,  1006,    -1,  1006,   640,  1006,
      -1,  1006,   640,    25,   670,  1006,    -1,  1006,   662,  1006,
      -1,  1006,   662,  1006,   640,  1006,    -1,  1006,   662,  1006,
     640,    25,   670,  1006,    -1,    25,   670,  1006,    -1,    25,
      -1,  1006,    -1,  1006,   640,  1006,    -1,  1006,   640,    25,
     670,  1006,    -1,  1006,   662,  1006,    -1,  1006,   662,  1006,
     640,  1006,    -1,  1006,   662,  1006,   640,    25,   670,  1006,
      -1,  1006,    -1,    -1,   510,    26,   478,    -1,   510,    26,
       5,    26,   478,    -1,  1464,    -1,   662,  1464,    -1,  1006,
    1462,    -1,  1459,   670,  1006,  1462,    -1,  1459,   670,    20,
      -1,  1006,    -1,    25,    -1,  1012,    -1,    26,    -1,  1468,
      -1,   448,  1470,    -1,   448,  1469,    -1,    -1,  1472,   676,
    1473,    -1,    -1,  1471,   676,  1471,    -1,   632,    -1,   564,
      -1,   641,    -1,   603,    -1,   505,    -1,   521,    -1,   420,
      -1,   420,   482,    26,   445,    -1,   632,    -1,   564,    -1,
     641,    -1,   603,    -1,   505,    -1,   521,    -1,   420,    -1,
     632,    -1,   564,    -1,   641,    -1,   603,    -1,   505,    -1,
     521,    -1,   420,    -1,   420,   482,    26,   445,    -1,  1006,
      -1,  1006,   662,  1006,    -1,    25,    -1,  1515,   554,  1000,
      -1,    -1,  1515,   451,  1365,   488,   646,  1484,  1477,    -1,
      -1,  1515,   451,  1365,   488,   152,   646,  1485,  1478,    -1,
      -1,  1515,   451,  1365,   191,  1485,  1479,    -1,    -1,  1515,
     451,  1365,   192,   152,   646,  1485,  1480,    -1,    -1,   341,
      -1,   340,  1482,    -1,  1483,    -1,  1482,     5,  1483,    -1,
    1006,    -1,  1006,   670,  1006,    -1,    25,   670,  1006,   670,
    1006,    -1,  1485,    -1,  1355,    -1,  1218,    -1,  1487,    -1,
    1487,    -1,    -1,    -1,   522,  1498,  1488,  1499,  1489,  1495,
    1431,  1493,  1481,    -1,   522,  1498,  1499,  1431,  1493,    -1,
    1492,    -1,  1510,    -1,   522,  1498,  1499,  1495,  1431,  1493,
      -1,    -1,   576,  1450,  1491,    -1,  1374,    -1,   386,  1494,
    1324,    -1,  1374,   386,  1494,  1324,    -1,  1006,    -1,    -1,
     604,  1184,    -1,   522,  1498,  1499,  1431,    -1,   482,   522,
    1498,  1499,  1431,   445,    -1,    -1,   636,    -1,   413,    -1,
     527,    -1,  1500,    -1,  1499,     5,  1500,    -1,  1502,    -1,
    1502,  1006,    -1,  1502,   667,  1006,    -1,  1502,    -1,  1503,
      -1,    19,  1503,    -1,    18,  1503,    -1,  1504,    -1,  1564,
      -1,  1497,    -1,   636,  1497,    -1,   637,  1497,    -1,   621,
    1497,    -1,   662,  1006,    -1,   662,  1006,   670,  1006,    -1,
    1503,    21,  1502,    -1,  1503,  1524,    -1,  1503,    20,  1502,
      -1,  1503,    18,  1502,    -1,  1503,    19,  1502,    -1,  1466,
      -1,   535,    -1,   479,    -1,   627,    -1,    20,    -1,   117,
      -1,   639,   482,  1450,  1502,   445,    -1,   651,   482,  1450,
    1502,   445,    -1,   652,   482,  1450,  1502,   445,    -1,   659,
     482,  1450,  1502,   445,    -1,   547,   482,  1450,  1502,   445,
      -1,  1006,   482,  1505,   445,    -1,   588,   482,  1505,   445,
      -1,   482,  1502,   445,    -1,   495,   482,  1525,   445,    -1,
    1526,    -1,  1528,    -1,  1502,    -1,  1505,     5,  1502,    -1,
    1466,    -1,  1515,   401,  1514,  1509,  1491,    -1,  1515,   390,
    1514,  1509,   301,  1459,  1511,    -1,  1515,   390,  1514,  1509,
    1163,    -1,    -1,   376,  1510,    -1,    25,    -1,  1163,    -1,
      -1,   482,  1512,   445,    -1,  1513,    -1,  1512,     5,  1513,
      -1,  1006,    -1,    25,    -1,  1163,    -1,    -1,   320,  1516,
     646,    -1,  1007,    -1,  1522,    -1,  1521,    -1,  1518,    -1,
     369,  1519,   676,  1519,    -1,   350,  1459,   670,  1520,   676,
    1520,    -1,  1006,    -1,  1006,    -1,   274,  1459,    -1,   345,
    1459,  1523,    -1,   324,    -1,   227,    -1,   144,    -1,   145,
      -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,   448,
       5,  1472,   676,  1473,    -1,  1564,     5,  1472,   676,  1473,
      -1,   448,  1472,   676,  1473,    -1,  1502,     5,  1472,   676,
    1473,    -1,  1527,    -1,  1527,  1472,   676,  1473,    -1,    36,
      -1,  1529,    -1,  1529,  1472,   482,    26,   445,   676,  1473,
      -1,  1529,  1472,   676,  1473,    -1,    37,    -1,    -1,   658,
    1531,  1532,   242,    -1,  1533,    -1,  1532,  1533,    -1,    33,
      -1,  1534,    -1,  1536,    -1,   405,    -1,   357,    -1,   276,
      -1,   635,    -1,   532,    -1,   636,    -1,   537,    -1,   581,
      -1,   637,    -1,   168,    -1,   538,    -1,   667,    -1,   638,
      -1,   370,    -1,   539,    -1,   371,    -1,   668,    -1,   662,
      -1,   327,    -1,   540,    -1,   236,    -1,   441,    -1,   639,
      -1,   714,    -1,   442,    -1,   541,    -1,   542,    -1,   582,
      -1,   583,    -1,   483,    -1,   484,    -1,   407,    -1,   701,
      -1,   669,    -1,   584,    -1,   443,    -1,   586,    -1,   580,
      -1,   372,    -1,   543,    -1,   544,    -1,   444,    -1,   545,
      -1,   445,    -1,   478,    -1,   546,    -1,   640,    -1,   485,
      -1,   446,    -1,     5,    -1,    23,    -1,   486,    -1,   447,
      -1,   409,    -1,   408,    -1,   375,    -1,   547,    -1,   487,
      -1,   448,    -1,   488,    -1,   587,    -1,   410,    -1,   588,
      -1,   411,    -1,   641,    -1,   642,    -1,   449,    -1,   643,
      -1,   450,    -1,   451,    -1,   452,    -1,   412,    -1,   548,
      -1,   489,    -1,   490,    -1,   376,    -1,   589,    -1,   333,
      -1,   644,    -1,   705,    -1,   453,    -1,   413,    -1,    21,
      -1,   670,    -1,   491,    -1,   377,    -1,   592,    -1,   115,
      -1,   593,    -1,   708,    -1,   454,    -1,    14,    -1,   549,
      -1,   493,    -1,   550,    -1,   381,    -1,   594,    -1,   455,
      -1,   494,    -1,   595,    -1,   495,    -1,   496,    -1,   419,
      -1,   585,    -1,   551,    -1,   151,    -1,   245,    -1,   497,
      -1,   552,    -1,   645,    -1,   553,    -1,   554,    -1,   646,
      -1,   456,    -1,   457,    -1,   498,    -1,   688,    -1,   143,
      -1,   158,    -1,   555,    -1,   420,    -1,   596,    -1,   597,
      -1,   421,    -1,   342,    -1,   458,    -1,   671,    -1,   598,
      -1,   556,    -1,    13,    -1,   557,    -1,   558,    -1,   499,
      -1,   500,    -1,   601,    -1,   602,    -1,   603,    -1,   710,
      -1,   124,    -1,   672,    -1,   673,    -1,   164,    -1,   559,
      -1,   459,    -1,   343,    -1,   715,    -1,   501,    -1,   460,
      -1,   385,    -1,   423,    -1,   717,    -1,   387,    -1,   647,
      -1,   590,    -1,   709,    -1,   560,    -1,   533,    -1,   424,
      -1,   648,    -1,   677,    -1,   461,    -1,     7,    -1,   479,
      -1,   633,    -1,   534,    -1,     6,    -1,   535,    -1,     8,
      -1,   605,    -1,   606,    -1,    12,    -1,   649,    -1,   607,
      -1,   562,    -1,   502,    -1,   650,    -1,   462,    -1,   608,
      -1,   503,    -1,    10,    -1,    58,    -1,   504,    -1,   609,
      -1,   696,    -1,   711,    -1,    19,    -1,   505,    -1,   163,
      -1,    22,    -1,   610,    -1,   506,    -1,   563,    -1,   564,
      -1,    20,    -1,   611,    -1,   612,    -1,   363,    -1,   613,
      -1,   507,    -1,     9,    -1,   674,    -1,   719,    -1,   675,
      -1,   614,    -1,   482,    -1,   510,    -1,   511,    -1,   463,
      -1,   565,    -1,   394,    -1,   566,    -1,   512,    -1,   653,
      -1,   428,    -1,   567,    -1,   208,    -1,   159,    -1,   464,
      -1,    18,    -1,   162,    -1,   395,    -1,   465,    -1,   165,
      -1,   429,    -1,   364,    -1,   570,    -1,   396,    -1,   397,
      -1,   466,    -1,   513,    -1,   514,    -1,   654,    -1,   615,
      -1,   430,    -1,   616,    -1,   515,    -1,   467,    -1,   655,
      -1,   349,    -1,   431,    -1,   432,    -1,   516,    -1,   433,
      -1,   230,    -1,   399,    -1,   468,    -1,   517,    -1,   571,
      -1,   314,    -1,   656,    -1,   617,    -1,   657,    -1,   518,
      -1,   520,    -1,   521,    -1,   469,    -1,   522,    -1,   573,
      -1,   523,    -1,   470,    -1,   525,    -1,   618,    -1,   536,
      -1,   619,    -1,   620,    -1,   574,    -1,   352,    -1,   434,
      -1,   621,    -1,   526,    -1,   658,    -1,   353,    -1,   142,
      -1,   622,    -1,   623,    -1,   659,    -1,   471,    -1,   591,
      -1,   624,    -1,   169,    -1,   625,    -1,   626,    -1,   472,
      -1,   718,    -1,   676,    -1,   660,    -1,   473,    -1,   575,
      -1,   250,    -1,   400,    -1,   576,    -1,   527,    -1,   528,
      -1,   529,    -1,   474,    -1,   661,    -1,   627,    -1,   435,
      -1,   530,    -1,   475,    -1,   404,    -1,   628,    -1,   476,
      -1,   629,    -1,   577,    -1,   578,    -1,   579,    -1,   630,
      -1,   437,    -1,   631,    -1,   651,    -1,   652,    -1,   634,
      -1,   632,    -1,   531,    -1,    -1,   243,  1535,  1564,    -1,
      -1,   604,  1537,  1184,    -1,    -1,    -1,   529,  1459,  1539,
    1542,  1540,  1541,    -1,    -1,   203,  1000,    -1,   577,  1435,
      -1,   102,  1546,   445,    14,   482,  1547,   445,    -1,    98,
    1547,   445,    -1,    99,  1547,   445,    -1,   634,  1543,    -1,
     101,  1547,    -1,   100,  1547,    -1,  1545,    -1,  1543,     5,
    1545,    -1,  1463,    -1,  1544,    14,  1548,    -1,  1544,    -1,
    1546,     5,  1544,    -1,  1548,    -1,  1547,     5,  1548,    -1,
     534,    -1,  1549,    -1,  1550,    -1,    19,  1550,    -1,    18,
    1550,    -1,  1552,    -1,  1497,    -1,   662,  1006,    -1,   662,
    1006,   670,  1006,    -1,   662,  1006,   510,    26,   478,    -1,
     662,  1006,   670,  1006,   510,    26,   478,    -1,   662,  1006,
     510,    26,     5,    26,   478,    -1,   662,  1006,   670,  1006,
     510,    26,     5,    26,   478,    -1,  1551,    -1,  1466,    -1,
     535,    -1,   479,    -1,   627,    -1,   117,    -1,  1550,    21,
    1549,    -1,  1550,  1524,    -1,  1550,    20,  1549,    -1,  1550,
      18,  1549,    -1,  1550,    19,  1549,    -1,   639,   482,  1450,
    1549,   445,    -1,   651,   482,  1450,  1549,   445,    -1,   652,
     482,  1450,  1549,   445,    -1,   659,   482,  1450,  1549,   445,
      -1,   547,   482,  1450,  1549,   445,    -1,  1006,   482,  1553,
     445,    -1,   588,   482,  1553,   445,    -1,   482,  1549,   445,
      -1,   495,   482,  1525,   445,    -1,  1526,    -1,  1528,    -1,
    1564,    -1,  1549,    -1,  1553,     5,  1549,    -1,    -1,   435,
    1192,   607,  1555,  1556,    -1,  1557,    -1,  1556,     5,  1557,
      -1,  1459,   670,  1463,    -1,  1459,   670,    20,    -1,  1560,
      -1,  1560,    -1,   243,  1561,    -1,  1561,    -1,  1562,    -1,
      25,   670,  1562,    -1,  1563,    -1,  1562,   670,  1563,    -1,
    1562,   670,    20,    -1,  1565,    -1,  1006,    -1,  1559,    -1,
    1559,   472,  1559,    -1,  1006,  1566,    -1,   510,  1567,   478,
      -1,   510,  1567,   478,   510,  1567,   478,    -1,  1568,    -1,
    1567,     5,  1568,    -1,   736,    -1,    34,    -1,    -1,    -1,
     578,  1571,   913,  1572,  1585,   380,    -1,    -1,   709,   954,
      -1,    -1,   712,    -1,   234,    -1,   330,  1001,    -1,   122,
    1001,    -1,   360,    -1,   359,    -1,   361,  1003,  1573,  1574,
      -1,   544,   954,  1574,    -1,   156,    -1,   188,  1001,    -1,
     913,   617,     5,   913,   446,    -1,   560,   913,    -1,   317,
    1001,    -1,   153,  1580,     8,  1581,  1579,    -1,    -1,   597,
     913,    -1,  1006,    -1,  1006,    -1,   300,  1001,    -1,   303,
    1001,   676,   913,     5,   913,    -1,   303,  1001,   669,   913,
       5,   913,    -1,    27,    -1,    -1,  1587,    -1,  1588,  1271,
      -1,  1586,    -1,  1587,  1586,    -1,    -1,  1589,  1590,    -1,
     729,    -1,   730,    -1,   731,    -1,   732,    -1,   749,    -1,
     771,    -1,   785,    -1,   786,    -1,   792,    -1,   811,    -1,
     885,    -1,   886,    -1,   887,    -1,   888,    -1,   899,    -1,
     900,    -1,   901,    -1,   902,    -1,   903,    -1,   904,    -1,
     905,    -1,   956,    -1,   987,    -1,   991,    -1,  1013,    -1,
    1015,    -1,  1018,    -1,  1019,    -1,  1020,    -1,  1021,    -1,
    1034,    -1,  1043,    -1,  1067,    -1,  1068,    -1,  1070,    -1,
    1074,    -1,  1089,    -1,  1090,    -1,  1094,    -1,  1095,    -1,
    1096,    -1,  1097,    -1,  1105,    -1,  1120,    -1,  1140,    -1,
    1151,    -1,  1152,    -1,  1153,    -1,  1157,    -1,  1194,    -1,
    1197,    -1,  1199,    -1,  1205,    -1,  1206,    -1,  1209,    -1,
    1212,    -1,  1215,    -1,  1217,    -1,  1219,    -1,  1222,    -1,
    1229,    -1,  1234,    -1,  1239,    -1,  1240,    -1,  1241,    -1,
    1253,    -1,  1307,    -1,  1308,    -1,  1310,    -1,  1329,    -1,
    1330,    -1,  1350,    -1,  1353,    -1,  1382,    -1,  1384,    -1,
    1475,    -1,  1476,    -1,  1507,    -1,  1508,    -1,  1530,    -1,
    1554,    -1,  1569,    -1,  1570,    -1,  1575,    -1,  1576,    -1,
    1578,    -1,  1582,    -1,  1583,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1001,  1001,  1004,  1007,  1013,  1019,  1026,  1030,  1030,
    1036,  1059,  1060,  1061,  1062,  1063,  1074,  1080,  1081,  1082,
    1083,  1084,  1089,  1090,  1101,  1104,  1107,  1107,  1111,  1114,
    1115,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1140,  1141,
    1144,  1144,  1159,  1160,  1163,  1169,  1171,  1182,  1184,  1186,
    1188,  1192,  1194,  1256,  1260,  1264,  1264,  1274,  1278,  1281,
    1282,  1289,  1295,  1289,  1308,  1313,  1317,  1308,  1329,  1333,
    1329,  1341,  1346,  1341,  1365,  1372,  1376,  1364,  1402,  1402,
    1406,  1407,  1408,  1413,  1416,  1421,  1425,  1433,  1434,  1437,
    1437,  1443,  1447,  1462,  1460,  1478,  1478,  1493,  1493,  1496,
    1496,  1500,  1503,  1503,  1503,  1510,  1511,  1510,  1518,  1518,
    1529,  1529,  1548,  1551,  1554,  1557,  1560,  1563,  1576,  1581,
    1581,  1582,  1582,  1585,  1590,  1590,  1594,  1613,  1618,  1612,
    1629,  1635,  1643,  1644,  1647,  1647,  1650,  1654,  1659,  1666,
    1666,  1670,  1670,  1671,  1671,  1672,  1672,  1673,  1673,  1674,
    1674,  1682,  1686,  1692,  1696,  1711,  1714,  1717,  1720,  1723,
    1726,  1732,  1743,  1748,  1761,  1765,  1780,  1781,  1785,  1785,
    1789,  1789,  1789,  1790,  1795,  1795,  1798,  1798,  1807,  1808,
    1809,  1812,  1816,  1817,  1817,  1834,  1834,  1834,  1834,  1838,
    1845,  1846,  1849,  1849,  1853,  1854,  1855,  1856,  1861,  1861,
    1867,  1867,  1876,  1873,  1889,  1889,  1891,  1891,  1893,  1895,
    1897,  1899,  1902,  1906,  1906,  1907,  1907,  1911,  1911,  1923,
    1923,  1928,  1932,  1934,  1935,  1938,  1938,  1938,  1942,  1943,
    1944,  1945,  1946,  1947,  1948,  1949,  1950,  1951,  1952,  1953,
    1956,  1957,  1958,  1959,  1963,  1968,  1973,  1977,  1980,  1984,
    1984,  1985,  1985,  1986,  1986,  1987,  1988,  1989,  1990,  1991,
    1992,  1995,  1996,  1997,  2027,  2027,  2032,  2036,  2038,  2040,
    2040,  2047,  2051,  2051,  2055,  2056,  2057,  2058,  2059,  2060,
    2061,  2067,  2067,  2070,  2072,  2078,  2080,  2086,  2094,  2094,
    2097,  2098,  2099,  2100,  2101,  2102,  2103,  2109,  2112,  2112,
    2125,  2125,  2132,  2133,  2134,  2136,  2137,  2140,  2144,  2145,
    2146,  2147,  2152,  2158,  2164,  2165,  2167,  2169,  2170,  2171,
    2172,  2173,  2174,  2177,  2178,  2185,  2193,  2193,  2201,  2198,
    2213,  2213,  2215,  2215,  2223,  2223,  2226,  2229,  2230,  2235,
    2247,  2251,  2254,  2257,  2258,  2259,  2260,  2261,  2266,  2273,
    2279,  2284,  2289,  2284,  2302,  2304,  2309,  2314,  2314,  2314,
    2318,  2318,  2321,  2321,  2328,  2328,  2335,  2335,  2346,  2364,
    2370,  2394,  2397,  2412,  2415,  2428,  2430,  2432,  2434,  2436,
    2438,  2440,  2446,  2448,  2452,  2454,  2456,  2458,  2460,  2462,
    2464,  2470,  2487,  2488,  2489,  2490,  2494,  2495,  2496,  2500,
    2505,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,  2520,
    2521,  2522,  2529,  2529,  2534,  2534,  2537,  2543,  2551,  2557,
    2567,  2568,  2576,  2597,  2601,  2606,  2611,  2613,  2616,  2634,
    2639,  2645,  2650,  2655,  2656,  2662,  2733,  2744,  2753,  2761,
    2761,  2776,  2780,  2787,  2790,  2798,  2802,  2805,  2811,  2820,
    2825,  2833,  2836,  2839,  2844,  2851,  2856,  2861,  2866,  2876,
    2884,  2892,  2897,  2901,  2906,  2910,  2914,  2921,  2924,  2927,
    2931,  2935,  2939,  2943,  2951,  2961,  2966,  2959,  2982,  2987,
    2982,  3004,  3004,  3004,  3007,  3007,  3007,  3011,  3011,  3011,
    3015,  3015,  3015,  3019,  3025,  3031,  3037,  3045,  3051,  3059,
    3065,  3074,  3080,  3087,  3094,  3103,  3109,  3115,  3122,  3128,
    3134,  3140,  3148,  3154,  3160,  3169,  3175,  3181,  3191,  3191,
    3195,  3199,  3200,  3211,  3212,  3218,  3228,  3238,  3248,  3249,
    3252,  3257,  3263,  3267,  3271,  3274,  3280,  3283,  3286,  3303,
    3306,  3312,  3313,  3314,  3318,  3319,  3320,  3321,  3322,  3324,
    3325,  3326,  3328,  3329,  3333,  3334,  3339,  3343,  3348,  3352,
    3367,  3371,  3377,  3366,  3390,  3391,  3403,  3409,  3403,  3423,
    3423,  3425,  3426,  3430,  3430,  3434,  3434,  3439,  3439,  3446,
    3447,  3451,  3451,  3455,  3455,  3460,  3460,  3467,  3471,  3472,
    3473,  3478,  3478,  3481,  3481,  3485,  3485,  3489,  3489,  3493,
    3493,  3498,  3498,  3503,  3503,  3508,  3508,  3513,  3513,  3529,
    3533,  3528,  3541,  3544,  3558,  3575,  3576,  3577,  3578,  3579,
    3580,  3581,  3584,  3584,  3587,  3589,  3592,  3595,  3598,  3603,
    3608,  3611,  3616,  3621,  3626,  3633,  3634,  3641,  3648,  3650,
    3656,  3661,  3666,  3671,  3671,  3674,  3680,  3685,  3688,  3695,
    3695,  3697,  3700,  3703,  3708,  3713,  3718,  3725,  3734,  3734,
    3796,  3804,  3805,  3813,  3820,  3820,  3824,  3829,  3835,  3839,
    3843,  3849,  3853,  3857,  3863,  3863,  3871,  3872,  3876,  3876,
    3880,  3881,  3884,  3887,  3887,  3890,  3892,  3892,  3895,  3897,
    3897,  3898,  3900,  3900,  3909,  3916,  3907,  3937,  3937,  3937,
    3940,  3942,  3940,  3949,  3952,  3958,  3969,  3969,  3973,  3979,
    3979,  3983,  3984,  3988,  3998,  3999,  4000,  4003,  4005,  4010,
    4010,  4014,  4013,  4021,  4020,  4027,  4027,  4033,  4033,  4040,
    4040,  4046,  4046,  4052,  4052,  4058,  4058,  4062,  4062,  4063,
    4063,  4064,  4064,  4065,  4065,  4069,  4069,  4080,  4084,  4090,
    4094,  4099,  4104,  4109,  4110,  4111,  4115,  4114,  4127,  4132,
    4137,  4137,  4153,  4159,  4160,  4161,  4162,  4163,  4173,  4187,
    4187,  4190,  4197,  4198,  4199,  4200,  4201,  4202,  4203,  4204,
    4205,  4210,  4210,  4212,  4215,  4215,  4217,  4221,  4224,  4225,
    4228,  4228,  4233,  4236,  4237,  4238,  4239,  4240,  4241,  4242,
    4243,  4244,  4245,  4246,  4247,  4248,  4249,  4250,  4251,  4252,
    4253,  4257,  4275,  4275,  4275,  4302,  4313,  4320,  4326,  4332,
    4338,  4350,  4375,  4374,  4391,  4391,  4395,  4396,  4404,  4405,
    4406,  4407,  4408,  4409,  4416,  4417,  4419,  4420,  4424,  4429,
    4430,  4431,  4432,  4433,  4434,  4435,  4436,  4437,  4439,  4442,
    4444,  4444,  4446,  4450,  4450,  4459,  4464,  4480,  4486,  4458,
    4500,  4514,  4524,  4513,  4537,  4544,  4544,  4549,  4555,  4563,
    4568,  4569,  4572,  4575,  4575,  4583,  4589,  4600,  4601,  4605,
    4609,  4622,  4604,  4635,  4641,  4635,  4652,  4653,  4657,  4657,
    4664,  4664,  4679,  4679,  4693,  4704,  4703,  4715,  4711,  4728,
    4725,  4738,  4738,  4740,  4741,  4743,  4744,  4747,  4748,  4749,
    4751,  4756,  4761,  4767,  4769,  4770,  4773,  4774,  4777,  4779,
    4786,  4789,  4792,  4795,  4799,  4803,  4804,  4805,  4806,  4807,
    4811,  4816,  4816,  4819,  4846,  4904,  4904,  4907,  4911,  4915,
    4958,  5000,  5001,  5002,  5005,  5019,  5031,  5031,  5036,  5037,
    5043,  5108,  5113,  5120,  5125,  5133,  5139,  5172,  5175,  5176,
    5217,  5260,  5261,  5265,  5266,  5270,  5323,  5328,  5332,  5337,
    5348,  5355,  5363,  5363,  5366,  5367,  5368,  5369,  5370,  5373,
    5376,  5382,  5385,  5389,  5394,  5402,  5407,  5414,  5416,  5422,
    5424,  5424,  5424,  5444,  5451,  5458,  5461,  5475,  5482,  5483,
    5486,  5487,  5491,  5497,  5502,  5508,  5509,  5514,  5518,  5518,
    5522,  5523,  5526,  5527,  5531,  5539,  5542,  5548,  5549,  5551,
    5553,  5557,  5557,  5558,  5563,  5571,  5572,  5577,  5578,  5580,
    5593,  5595,  5596,  5599,  5600,  5601,  5602,  5603,  5604,  5605,
    5606,  5607,  5608,  5609,  5610,  5611,  5612,  5613,  5614,  5615,
    5616,  5617,  5618,  5619,  5620,  5621,  5622,  5623,  5624,  5638,
    5646,  5646,  5648,  5652,  5656,  5660,  5664,  5669,  5684,  5682,
    5702,  5703,  5707,  5712,  5713,  5717,  5718,  5720,  5721,  5723,
    5723,  5732,  5741,  5741,  5751,  5752,  5757,  5758,  5761,  5774,
    5788,  5792,  5796,  5800,  5807,  5808,  5811,  5811,  5815,  5818,
    5818,  5820,  5826,  5834,  5840,  5842,  5846,  5849,  5849,  5852,
    5852,  5857,  5857,  5866,  5866,  5870,  5870,  5871,  5871,  5872,
    5872,  5886,  5886,  5906,  5907,  5908,  5909,  5910,  5911,  5914,
    5914,  5920,  5920,  5923,  5923,  5939,  5940,  5941,  5950,  5962,
    5963,  5966,  5967,  5970,  5973,  5973,  5978,  5978,  6001,  6002,
    6008,  6013,  6019,  6020,  6021,  6025,  6026,  6027,  6028,  6032,
    6042,  6044,  6049,  6052,  6057,  6063,  6070,  6077,  6086,  6093,
    6100,  6107,  6114,  6123,  6123,  6125,  6125,  6128,  6129,  6130,
    6131,  6132,  6133,  6134,  6135,  6136,  6137,  6140,  6140,  6143,
    6144,  6145,  6146,  6149,  6149,  6152,  6152,  6155,  6156,  6157,
    6158,  6159,  6160,  6161,  6162,  6164,  6165,  6166,  6167,  6169,
    6170,  6171,  6172,  6174,  6175,  6176,  6177,  6178,  6179,  6180,
    6181,  6185,  6193,  6203,  6216,  6225,  6236,  6240,  6244,  6250,
    6215,  6263,  6266,  6274,  6286,  6288,  6293,  6301,  6311,  6314,
    6318,  6326,  6292,  6335,  6339,  6343,  6347,  6339,  6357,  6358,
    6359,  6360,  6365,  6367,  6370,  6374,  6377,  6384,  6389,  6390,
    6391,  6392,  6397,  6398,  6404,  6404,  6404,  6409,  6409,  6409,
    6417,  6418,  6422,  6423,  6428,  6429,  6430,  6431,  6432,  6435,
    6437,  6437,  6440,  6441,  6445,  6446,  6449,  6450,  6453,  6456,
    6459,  6465,  6466,  6478,  6479,  6484,  6485,  6486,  6490,  6493,
    6499,  6502,  6510,  6511,  6517,  6521,  6525,  6531,  6534,  6543,
    6546,  6549,  6552,  6555,  6558,  6561,  6568,  6571,  6578,  6581,
    6587,  6590,  6597,  6600,  6607,  6608,  6613,  6617,  6620,  6626,
    6629,  6635,  6642,  6643,  6647,  6657,  6660,  6666,  6668,  6673,
    6674,  6678,  6680,  6686,  6687,  6700,  6712,  6713,  6714,  6715,
    6716,  6717,  6718,  6719,  6720,  6723,  6726,  6732,  6732,  6738,
    6738,  6749,  6762,  6772,  6772,  6777,  6777,  6781,  6785,  6786,
    6792,  6793,  6798,  6802,  6809,  6812,  6819,  6818,  6829,  6833,
    6837,  6844,  6847,  6847,  6860,  6864,  6864,  6879,  6881,  6883,
    6885,  6887,  6889,  6891,  6893,  6899,  6909,  6916,  6921,  6922,
    6926,  6929,  6930,  6933,  6934,  6935,  6938,  6943,  6950,  6951,
    6957,  6969,  6970,  6971,  6974,  6974,  6979,  6984,  6989,  6990,
    6993,  6994,  6999,  7004,  7008,  7013,  7014,  7018,  7025,  7026,
    7027,  7028,  7033,  7034,  7035,  7038,  7039,  7040,  7044,  7045,
    7046,  7050,  7051,  7055,  7056,  7057,  7058,  7059,  7060,  7063,
    7064,  7069,  7070,  7075,  7076,  7081,  7082,  7087,  7092,  7093,
    7098,  7099,  7103,  7104,  7109,  7116,  7121,  7126,  7130,  7131,
    7136,  7137,  7143,  7146,  7150,  7155,  7156,  7162,  7165,  7168,
    7175,  7176,  7177,  7178,  7192,  7197,  7198,  7201,  7203,  7210,
    7213,  7219,  7227,  7231,  7235,  7239,  7244,  7247,  7250,  7257,
    7264,  7269,  7273,  7274,  7280,  7283,  7294,  7301,  7307,  7310,
    7317,  7324,  7330,  7331,  7337,  7338,  7339,  7342,  7343,  7348,
    7348,  7352,  7360,  7361,  7364,  7367,  7372,  7373,  7378,  7381,
    7387,  7390,  7396,  7399,  7405,  7408,  7415,  7416,  7445,  7446,
    7451,  7459,  7464,  7467,  7470,  7473,  7479,  7480,  7484,  7487,
    7490,  7491,  7496,  7499,  7502,  7505,  7508,  7511,  7514,  7517,
    7522,  7528,  7529,  7530,  7531,  7532,  7534,  7535,  7537,  7538,
    7543,  7546,  7550,  7556,  7557,  7558,  7559,  7571,  7572,  7573,
    7577,  7578,  7582,  7583,  7584,  7585,  7586,  7588,  7597,  7604,
    7605,  7606,  7607,  7608,  7609,  7610,  7612,  7614,  7616,  7617,
    7619,  7620,  7622,  7623,  7624,  7625,  7627,  7631,  7632,  7638,
    7640,  7641,  7642,  7643,  7648,  7652,  7656,  7660,  7667,  7671,
    7672,  7673,  7681,  7682,  7683,  7694,  7701,  7706,  7707,  7708,
    7716,  7717,  7718,  7735,  7744,  7745,  7746,  7750,  7753,  7758,
    7763,  7768,  7776,  7780,  7785,  7786,  7794,  7797,  7800,  7814,
    7828,  7841,  7842,  7846,  7846,  7846,  7846,  7846,  7846,  7847,
    7850,  7866,  7866,  7866,  7866,  7866,  7866,  7866,  7867,  7867,
    7867,  7867,  7867,  7867,  7867,  7867,  7870,  7871,  7872,  7875,
    7884,  7884,  7890,  7890,  7897,  7897,  7903,  7903,  7911,  7912,
    7913,  7916,  7916,  7919,  7920,  7921,  7932,  7935,  7941,  7946,
    7953,  7966,  7967,  7964,  7985,  7996,  7999,  8004,  8016,  8019,
    8023,  8026,  8027,  8037,  8040,  8041,  8050,  8059,  8064,  8065,
    8066,  8067,  8074,  8077,  8083,  8086,  8093,  8105,  8114,  8117,
    8120,  8126,  8134,  8137,  8138,  8139,  8140,  8141,  8144,  8150,
    8152,  8154,  8156,  8158,  8160,  8161,  8162,  8163,  8164,  8165,
    8166,  8168,  8170,  8172,  8174,  8176,  8178,  8180,  8181,  8183,
    8184,  8190,  8191,  8198,  8201,  8209,  8213,  8220,  8220,  8224,
    8224,  8229,  8229,  8233,  8233,  8237,  8243,  8243,  8246,  8246,
    8252,  8259,  8260,  8261,  8265,  8266,  8269,  8270,  8274,  8280,
    8290,  8291,  8299,  8300,  8301,  8302,  8303,  8304,  8308,  8309,
    8310,  8311,  8315,  8316,  8320,  8336,  8337,  8338,  8342,  8356,
    8356,  8368,  8369,  8373,  8374,  8375,  8376,  8377,  8378,  8379,
    8380,  8381,  8382,  8383,  8384,  8385,  8386,  8387,  8388,  8389,
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
    8570,  8571,  8572,  8573,  8574,  8575,  8577,  8578,  8579,  8580,
    8581,  8582,  8583,  8584,  8585,  8586,  8587,  8588,  8589,  8590,
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
    8691,  8699,  8699,  8706,  8706,  8794,  8798,  8794,  8807,  8811,
    8817,  8825,  8835,  8845,  8857,  8860,  8879,  8905,  8908,  8914,
    8917,  8922,  8925,  8933,  8941,  8954,  8957,  8965,  8968,  8971,
    8979,  8983,  8984,  8985,  8986,  8987,  8988,  8989,  8990,  8994,
    8995,  8996,  8997,  8998,  9004,  9005,  9006,  9007,  9008,  9009,
    9010,  9011,  9012,  9013,  9014,  9015,  9016,  9017,  9018,  9019,
    9024,  9030,  9031,  9039,  9039,  9047,  9047,  9051,  9055,  9070,
    9085,  9091,  9093,  9101,  9102,  9106,  9107,  9110,  9117,  9120,
    9149,  9175,  9229,  9265,  9274,  9285,  9288,  9293,  9307,  9321,
    9324,  9320,  9343,  9343,  9349,  9350,  9353,  9354,  9355,  9356,
    9357,  9358,  9359,  9370,  9373,  9378,  9382,  9387,  9391,  9396,
    9400,  9403,  9407,  9410,  9415,  9419,  9430,  9436,  9436,  9437,
    9438,  9445,  9455,  9455,  9457,  9458,  9459,  9460,  9461,  9462,
    9463,  9464,  9465,  9466,  9467,  9468,  9469,  9470,  9471,  9472,
    9473,  9474,  9475,  9476,  9477,  9478,  9479,  9480,  9481,  9482,
    9483,  9484,  9485,  9486,  9487,  9488,  9489,  9490,  9491,  9492,
    9493,  9494,  9495,  9496,  9497,  9498,  9499,  9500,  9501,  9502,
    9503,  9504,  9505,  9506,  9507,  9508,  9509,  9510,  9511,  9512,
    9513,  9514,  9515,  9516,  9517,  9518,  9519,  9520,  9521,  9522,
    9523,  9524,  9525,  9526,  9527,  9528,  9529,  9530,  9531,  9532,
    9533,  9534,  9535,  9536,  9537,  9538,  9539,  9540,  9541,  9542,
    9543,  9544
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
     901,   902,   902,   903,   903,   904,   904,   904,   904,   904,
     904,   904,   904,   904,   905,   905,   905,   905,   905,   905,
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
     957,   958,   959,   956,   960,   960,   962,   963,   961,   964,
     964,   965,   965,   966,   966,   968,   967,   969,   967,   970,
     970,   971,   971,   973,   972,   974,   972,   975,   976,   976,
     976,   977,   977,   978,   978,   979,   979,   980,   980,   982,
     981,   983,   981,   984,   981,   985,   981,   986,   981,   988,
     989,   987,   990,   990,   991,   992,   992,   992,   992,   992,
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
    1131,  1132,  1129,  1134,  1135,  1133,  1136,  1136,  1138,  1137,
    1139,  1137,  1141,  1140,  1142,  1144,  1143,  1145,  1143,  1146,
    1143,  1147,  1147,  1148,  1148,  1149,  1149,  1150,  1150,  1150,
    1151,  1152,  1153,  1154,  1154,  1154,  1155,  1155,  1156,  1156,
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
    1259,  1260,  1260,  1261,  1262,  1262,  1264,  1263,  1265,  1265,
    1266,  1267,  1268,  1268,  1268,  1269,  1269,  1269,  1269,  1270,
    1271,  1271,  1272,  1272,  1273,  1274,  1274,  1274,  1274,  1274,
    1274,  1274,  1274,  1275,  1275,  1276,  1276,  1277,  1277,  1277,
    1277,  1277,  1277,  1277,  1277,  1277,  1277,  1278,  1278,  1279,
    1279,  1279,  1279,  1280,  1280,  1281,  1281,  1282,  1282,  1282,
    1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,
    1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,  1282,
    1282,  1283,  1283,  1283,  1285,  1286,  1287,  1288,  1289,  1290,
    1284,  1291,  1291,  1292,  1293,  1293,  1295,  1296,  1297,  1298,
    1299,  1300,  1294,  1301,  1303,  1304,  1305,  1302,  1306,  1306,
    1306,  1306,  1307,  1307,  1307,  1307,  1307,  1308,  1309,  1309,
    1309,  1309,  1310,  1310,  1312,  1313,  1311,  1314,  1315,  1311,
    1316,  1316,  1317,  1317,  1318,  1318,  1318,  1318,  1318,  1319,
    1320,  1320,  1321,  1321,  1322,  1322,  1323,  1323,  1323,  1323,
    1323,  1324,  1324,  1325,  1325,  1326,  1326,  1326,  1327,  1327,
    1328,  1328,  1329,  1329,  1330,  1330,  1330,  1331,  1331,  1332,
    1332,  1332,  1332,  1332,  1332,  1332,  1333,  1333,  1334,  1334,
    1335,  1335,  1336,  1336,  1337,  1337,  1338,  1339,  1339,  1340,
    1340,  1341,  1342,  1342,  1343,  1344,  1344,  1345,  1345,  1346,
    1346,  1347,  1347,  1348,  1348,  1349,  1350,  1350,  1350,  1350,
    1350,  1350,  1350,  1350,  1350,  1350,  1350,  1351,  1351,  1352,
    1352,  1353,  1354,  1356,  1355,  1358,  1357,  1357,  1359,  1359,
    1360,  1360,  1361,  1361,  1362,  1362,  1364,  1363,  1365,  1366,
    1366,  1367,  1368,  1367,  1369,  1370,  1369,  1371,  1371,  1371,
    1371,  1371,  1371,  1371,  1371,  1372,  1373,  1374,  1375,  1375,
    1376,  1377,  1377,  1378,  1378,  1378,  1379,  1380,  1381,  1381,
    1382,  1383,  1383,  1383,  1385,  1384,  1386,  1386,  1386,  1386,
    1386,  1386,  1386,  1386,  1386,  1386,  1386,  1386,  1387,  1387,
    1387,  1387,  1388,  1388,  1388,  1389,  1389,  1389,  1390,  1390,
    1390,  1391,  1391,  1392,  1392,  1392,  1392,  1392,  1392,  1393,
    1393,  1394,  1394,  1395,  1395,  1396,  1396,  1397,  1398,  1398,
    1399,  1399,  1400,  1400,  1401,  1402,  1403,  1404,  1405,  1405,
    1406,  1406,  1407,  1407,  1407,  1408,  1408,  1409,  1409,  1409,
    1410,  1410,  1410,  1410,  1411,  1412,  1412,  1413,  1413,  1414,
    1414,  1415,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1417,
    1418,  1419,  1420,  1420,  1421,  1421,  1422,  1423,  1424,  1424,
    1425,  1426,  1427,  1427,  1428,  1428,  1428,  1429,  1429,  1430,
    1430,  1431,  1432,  1432,  1433,  1433,  1434,  1434,  1435,  1435,
    1436,  1436,  1437,  1437,  1438,  1438,  1439,  1439,  1440,  1440,
    1441,  1442,  1443,  1443,  1443,  1443,  1444,  1444,  1445,  1445,
    1446,  1446,  1447,  1447,  1447,  1447,  1447,  1447,  1447,  1447,
    1447,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,
    1449,  1449,  1449,  1450,  1450,  1450,  1450,  1451,  1451,  1451,
    1452,  1452,  1453,  1453,  1453,  1453,  1453,  1453,  1453,  1453,
    1453,  1453,  1453,  1453,  1453,  1453,  1453,  1453,  1453,  1453,
    1453,  1453,  1453,  1453,  1453,  1453,  1453,  1454,  1454,  1455,
    1455,  1455,  1455,  1455,  1456,  1457,  1458,  1459,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1460,  1460,  1460,  1460,  1460,
    1460,  1460,  1460,  1461,  1462,  1462,  1462,  1463,  1463,  1464,
    1464,  1464,  1465,  1466,  1466,  1466,  1466,  1467,  1468,  1469,
    1469,  1470,  1470,  1471,  1471,  1471,  1471,  1471,  1471,  1471,
    1471,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1474,  1474,  1474,  1475,
    1477,  1476,  1478,  1476,  1479,  1476,  1480,  1476,  1481,  1481,
    1481,  1482,  1482,  1483,  1483,  1483,  1484,  1484,  1485,  1485,
    1486,  1488,  1489,  1487,  1490,  1491,  1491,  1492,  1493,  1493,
    1493,  1493,  1493,  1494,  1495,  1495,  1496,  1497,  1498,  1498,
    1498,  1498,  1499,  1499,  1500,  1500,  1500,  1501,  1502,  1502,
    1502,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1504,
    1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,
    1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,
    1504,  1505,  1505,  1506,  1507,  1508,  1508,  1509,  1509,  1510,
    1510,  1511,  1511,  1512,  1512,  1513,  1514,  1514,  1515,  1515,
    1516,  1517,  1517,  1517,  1518,  1518,  1519,  1520,  1521,  1522,
    1523,  1523,  1524,  1524,  1524,  1524,  1524,  1524,  1525,  1525,
    1525,  1525,  1526,  1526,  1527,  1528,  1528,  1528,  1529,  1531,
    1530,  1532,  1532,  1533,  1533,  1533,  1533,  1533,  1533,  1533,
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
    1533,  1535,  1534,  1537,  1536,  1539,  1540,  1538,  1541,  1541,
    1541,  1542,  1542,  1542,  1542,  1542,  1542,  1543,  1543,  1544,
    1545,  1546,  1546,  1547,  1547,  1548,  1548,  1549,  1549,  1549,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1551,  1551,  1551,  1551,  1551,  1551,
    1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,
    1552,  1553,  1553,  1555,  1554,  1556,  1556,  1557,  1557,  1558,
    1559,  1560,  1560,  1561,  1561,  1562,  1562,  1562,  1563,  1563,
    1564,  1564,  1565,  1566,  1566,  1567,  1567,  1568,  1569,  1571,
    1572,  1570,  1573,  1573,  1574,  1574,  1575,  1575,  1575,  1575,
    1575,  1575,  1575,  1576,  1576,  1577,  1577,  1578,  1578,  1579,
    1579,  1580,  1581,  1582,  1583,  1583,  1584,  1585,  1585,  1586,
    1587,  1587,  1589,  1588,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590
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
       0,     0,    14,     0,     0,     7,     1,     2,     0,     3,
       0,     4,     0,     5,     1,     0,     3,     0,     7,     0,
       5,     1,     2,     0,     1,     1,     1,     0,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     3,     1,     1,
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
       1,     1,     2,     2,     0,     2,     0,     4,     1,     3,
       3,     5,     0,     2,     4,     1,     1,     1,     1,     1,
       0,     1,     1,     3,     2,     5,     2,     5,     5,     5,
       5,     5,     5,     0,     2,     1,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     0,     3,     2,     0,     0,     0,     0,     0,     0,
      15,     0,     2,     2,     0,     1,     0,     0,     0,     0,
       0,     0,    15,     2,     0,     0,     0,    10,     0,     1,
       3,     3,     2,     4,     3,     3,     3,     1,     2,     2,
       2,     2,     1,     1,     0,     0,     8,     0,     0,     9,
       0,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       0,     1,     1,     2,     2,     2,     8,     2,     2,     4,
       2,     0,     1,     1,     3,     2,     2,     1,     1,     3,
       1,     1,     2,     1,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     3,
       1,     3,     2,     4,     1,     3,     1,     2,     4,     1,
       3,     1,     1,     1,     2,     3,     4,     2,     4,     0,
       2,     2,     4,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     6,     6,     0,     1,     0,
       1,     2,     1,     0,     5,     0,     5,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     0,     4,     1,     2,
       1,     0,     0,     3,     0,     0,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     3,     3,     1,     3,
       2,     1,     1,     0,     1,     1,     1,     1,     0,     1,
       3,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     6,
       4,     4,     1,     1,     1,     0,     1,     2,     1,     1,
       1,     1,     3,     2,     1,     1,     2,     1,     1,     0,
       3,     1,     3,     1,     3,     1,     1,     6,     0,     3,
       1,     3,     0,     1,     4,     5,     2,     1,     1,     4,
       1,     3,     4,     4,     4,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     4,     0,     1,     0,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     1,     1,     2,     1,     1,     2,     2,     1,     3,
       2,     2,     1,     3,     1,     2,     4,     1,     2,     1,
       3,     4,     0,     1,     0,     1,     0,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     2,     2,     0,     2,
       1,     1,     5,     3,     5,     3,     1,     3,     1,     1,
       0,     1,     3,     3,     3,     6,     4,     4,     4,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     1,     4,     1,     5,     5,     1,     1,
       1,     1,     1,     4,     1,     4,     6,     4,     1,     4,
       1,     7,     1,     1,     1,     4,     6,     0,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       3,     5,     3,     5,     7,     3,     1,     1,     3,     5,
       3,     5,     7,     1,     0,     3,     5,     1,     2,     2,
       4,     3,     1,     1,     1,     1,     1,     2,     2,     0,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
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
       4,     5,     1,     4,     1,     1,     7,     4,     1,     0,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
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
       1,     0,     3,     0,     3,     0,     0,     6,     0,     2,
       2,     7,     3,     3,     2,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     2,     2,
       1,     1,     2,     4,     5,     7,     7,     9,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     3,     5,
       5,     5,     5,     5,     4,     4,     3,     4,     1,     1,
       1,     1,     3,     0,     5,     1,     3,     3,     3,     1,
       1,     2,     1,     1,     3,     1,     3,     3,     1,     1,
       1,     3,     2,     3,     6,     1,     3,     1,     1,     0,
       0,     6,     0,     2,     0,     1,     1,     2,     2,     1,
       1,     4,     3,     1,     2,     5,     2,     2,     5,     0,
       2,     1,     1,     2,     6,     6,     1,     0,     1,     2,
       1,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     834,     0,  2228,     0,     0,     0,   883,   180,     0,   859,
     862,   178,   183,   838,     0,   832,   835,   836,   839,   842,
     843,   841,   879,   880,   882,   840,   136,   133,     0,   129,
     131,   130,   134,  2256,   715,   655,   310,  1688,  1686,   877,
     176,   186,   878,   179,     1,   844,   837,   881,   128,   132,
     135,     0,     0,   632,     0,     0,   177,   886,   952,   633,
     887,   888,   884,   667,   944,     0,   945,   953,   951,   186,
     181,   199,     0,   184,   200,   235,     0,   864,  1246,     0,
       0,   863,  1234,   871,     0,     0,   856,   855,   857,   833,
     845,   846,   865,   849,   850,   851,   854,   852,   853,   858,
       0,  1687,   946,   885,     0,     0,   960,   958,   959,   948,
     947,   308,   186,  1170,   193,   187,   186,   192,   232,     0,
     714,     0,     0,     0,     0,   176,   576,   893,   847,     0,
     342,   328,   202,   314,   279,   298,   319,   321,   318,     0,
     340,     0,   327,   320,   324,   330,   329,   186,   331,   311,
     334,   312,   313,   957,   956,     0,    22,    23,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
       0,   539,   531,    16,   538,   952,    15,     0,   963,     0,
     309,     0,   185,  1171,   182,     0,   199,   201,   273,   204,
     261,   267,   268,   252,   225,   263,   202,   240,   241,     0,
     227,   279,   298,   250,   253,   248,     0,   223,     0,   259,
     251,   256,   266,   265,   186,   269,   186,   238,   239,   236,
     272,     0,     0,     0,     0,   872,   176,   176,     0,     0,
     203,     0,     0,   332,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,   277,     0,   954,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     545,     0,     0,     0,   668,   439,   441,  1241,     0,     0,
       0,  1661,     0,   435,     0,     0,     0,   434,     0,   449,
     541,     0,     0,     0,     0,     0,   544,   402,   408,   445,
     442,   403,   404,   406,   407,   440,   443,   448,   540,   494,
     491,   500,   497,     0,     0,    17,    18,    19,    20,    21,
       0,    14,   485,     0,     0,   961,     0,   188,   191,   189,
     190,     0,   196,   195,   194,   197,   205,   206,   207,   210,
     274,   186,   274,     0,     0,     0,     0,   186,   270,   271,
       0,     0,   186,     0,   274,     0,     0,   249,   233,  1247,
       0,     0,  1235,  2262,   577,   894,   866,     0,   214,   215,
       0,     0,   291,   293,   288,   289,   285,   287,   284,   286,
     283,     0,   293,   304,   305,   301,   303,   300,   302,   295,
       0,     0,     0,   344,     0,   347,   349,   222,     0,   221,
       0,   186,     0,     0,     0,   566,   637,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   563,   549,   554,     0,
     550,   553,   552,   646,     0,   645,   568,     0,    11,   172,
     433,   410,   409,     0,  1176,     0,     0,   447,  1669,  1667,
    1668,  1664,  1666,  1663,  1665,  1657,     0,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   546,   547,   548,   460,     0,     0,   459,   469,     0,
       0,   414,     0,     0,   415,   405,   411,   413,   416,   417,
     418,   419,   420,   412,     0,     0,     0,     0,     0,     0,
       0,    12,    93,     0,   964,     0,   949,   198,     0,     0,
     262,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,   186,   234,   237,   976,   713,   889,
     976,     0,  2260,  2262,  1170,  1788,   860,     0,   976,     0,
       0,   315,   280,     0,     0,   290,   307,   281,   306,     0,
     299,     0,   322,     0,   316,     0,   341,     0,   346,   336,
       0,     0,   325,   278,   335,   525,     0,     0,   537,     0,
       0,   534,   533,   536,   532,   543,   528,   528,     0,     0,
     528,     0,   551,     0,   555,     0,   298,     0,   535,   542,
     282,     0,  1242,  1728,     0,     0,     0,     0,     0,   436,
       0,     0,   450,     0,     0,     0,     0,   452,   451,   470,
     461,   476,   479,   480,   477,   483,   482,   481,   471,   472,
     473,   474,   475,   421,   462,   466,   484,   478,   465,   484,
     444,   495,   492,   501,   498,   526,     0,    98,   486,    94,
      95,    97,   488,     0,     0,   235,     0,     0,     0,   242,
     243,     0,   246,     0,     0,   254,     0,   244,   224,   208,
       0,   257,   276,   982,     0,   977,   978,   976,     0,   873,
    2261,  2259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2243,     0,  1362,
    1361,     0,  1363,     0,   398,  1360,  1277,     0,     5,  1359,
     399,   396,     0,   401,   174,   484,  1145,     0,     0,  1369,
     125,   395,   394,     0,     0,   389,   484,     0,  1313,  2236,
       0,   400,   361,     0,     3,     2,     0,   397,  1274,     0,
       0,   390,   387,   383,     0,     0,     0,     0,  1367,  1357,
     393,     0,     0,     0,     0,     0,     0,     0,     0,  1356,
       0,     0,     0,   175,     0,   386,   385,     0,     0,  2240,
    2239,     0,     0,     0,   137,     0,   392,   391,     0,     0,
     388,   484,     0,     0,   484,     0,   570,     0,     0,     0,
       0,     0,     0,   484,   821,  1244,     0,     0,  1156,     0,
    2229,     0,   105,     0,     0,   902,     0,     0,     0,     0,
     822,     0,     0,  1819,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   684,     0,     0,  2264,  2265,  2266,  2267,
    2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,  2277,
    2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,
    2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  2297,
    2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,  2307,
    2308,  2309,  2310,  2311,  2312,   931,  2313,  2314,  2315,  2316,
    2317,  2318,  2319,  2320,  2321,  2322,  2323,  2324,  2325,  2326,
    2327,  2328,  2329,  1136,  1138,  1133,  1135,  1134,  1137,  2330,
    2331,  1267,  2332,  1273,  1272,  2333,  2334,  2335,  2336,  2337,
    2338,  2339,  2340,  2341,  2342,  1424,  2343,  2344,  2345,  2346,
    2347,  2348,  2349,  2350,  2351,  2263,   861,   581,     0,   898,
       0,   896,     0,   343,   216,   217,     0,   292,   297,     0,
       0,     0,     0,   345,   348,     0,   220,     0,     0,   567,
       0,   641,     0,   643,     0,   506,   504,     0,   528,     0,
     505,     0,     0,   565,     0,   562,   559,   530,   503,   569,
       0,   171,  1730,  1731,  1729,     0,   438,  1241,     0,  1662,
    1241,   437,  1241,  1241,  1241,  1241,  1241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,   962,     0,   211,   275,   226,     0,     0,
     186,     0,     0,     0,     0,     0,  1248,     0,     0,  1236,
     380,   378,   379,  1271,  1071,  1070,  1076,     0,  1636,  1637,
       0,     0,  1297,   656,   657,  1298,  1628,  1629,  1300,   848,
    1108,  1113,  2238,   649,   124,  2251,     0,     0,  1312,     7,
       0,     6,     0,  2244,  1109,     0,  1204,  1203,  1148,  1202,
    1147,   432,  1370,  1358,     0,  1268,   874,   422,  1790,  1364,
     126,     0,  1112,   123,     0,   828,    24,   651,   384,     0,
     827,  1104,   829,     0,  1368,   924,   923,   926,   922,   925,
    2253,     0,   920,     0,   650,  1008,   921,  2247,     0,  2237,
     122,  1270,  1005,   716,  1003,     0,   647,  2232,   764,   763,
     765,   761,     0,     0,  1269,  1018,   652,  1423,     0,  2219,
    1418,  1421,  2209,  2212,  2213,  2215,  2218,     0,     0,     0,
       0,  1077,  1072,     0,  1057,  1058,  1059,  1060,  1066,  1068,
    1067,  1065,  1064,     0,     0,     0,  1063,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1049,  1040,  1041,   991,     0,   989,  1091,   430,    24,     0,
    2234,   127,   648,     0,  1245,  1243,  1169,     0,  1779,     0,
    1780,  1170,  1158,  1149,  1371,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,   952,     0,    69,     0,   103,
     624,     0,   671,   670,     0,  1139,  1025,  1143,     0,     0,
    1092,  1262,     0,     0,  1146,   676,   673,   674,     0,   678,
     679,     0,   681,   682,     0,   677,   986,   988,     0,     0,
     987,   766,   984,   727,   980,   943,     0,     0,     0,     0,
     688,   689,     0,     0,   941,   938,   939,   935,   936,   937,
     930,   934,   933,     0,     0,     0,     0,     0,     0,   585,
     587,   579,   582,   583,   900,  2262,   895,   897,   867,     0,
     294,   296,   323,   317,     0,     0,   326,   638,   640,     0,
       0,     0,     0,   528,   511,     0,   528,   528,     0,   556,
       0,   291,     0,     0,  1758,  1653,  1655,  1814,  1818,  1759,
    1659,  1756,     0,     0,  1755,     0,     0,     0,  1757,     0,
       0,     0,     0,     0,     0,     0,  2219,  1654,  1754,  1656,
    1743,     0,  1732,  1734,  1738,  1741,  1769,  1812,  1770,  1815,
    2220,  2210,  1742,  1179,  1670,  1178,  1177,  1180,  1182,  1181,
    1175,   463,   464,   468,   453,     0,   456,   467,     0,   455,
     496,   493,   502,   499,   527,   487,    96,   489,   950,     0,
     247,   231,     0,   229,   255,   245,   235,   258,   983,   176,
     979,   890,   176,     0,     0,     0,  1342,  1343,     0,     0,
       0,  1314,  1317,  1319,  1320,  1321,  1325,  1324,  1322,  1323,
       0,     0,     0,  1315,  1316,     0,     0,     0,     0,     0,
       0,     0,     0,  1110,     0,    24,  1199,  1201,  1200,     0,
     425,   426,   423,   424,   996,     0,     0,   366,    25,   360,
       0,  1105,     0,  1104,     0,  1103,     0,     0,     0,     0,
       0,     0,  1012,  1789,     0,     0,     0,     0,     0,     0,
    2234,     0,     0,   138,     0,     0,  1022,  1014,  1015,  1020,
       0,     0,  2211,     0,  2222,  1419,  1420,     0,     0,   940,
     428,  2203,  1035,   350,     0,     0,   571,   629,   628,   626,
     631,  1043,   630,  1048,  1044,  1047,   820,   812,   806,   818,
     819,   804,   805,   813,   808,   814,   807,   817,   811,   815,
     810,   816,   803,   809,   796,   802,  1045,  1046,     0,  1053,
    1061,  1050,  1051,  1055,  1056,  1054,  1052,  1062,     0,     0,
       0,   830,     0,     0,     0,     0,     0,   776,   775,   772,
    2235,  2242,    24,  1165,  1166,  1167,  1168,  1162,     0,  1160,
    1258,  1170,  1150,  1151,  1154,  1172,  2230,     0,     0,     0,
       0,    99,     0,   100,     0,     0,     0,    74,     0,     0,
       0,   112,   107,     0,   672,   929,     0,   928,     0,   484,
    1141,     0,   971,   972,   995,   966,   967,   823,   993,  1094,
    1264,     0,  1266,  1265,  1875,  1991,  1987,  1993,  2025,  2005,
    1996,  1955,  1917,  2044,  2011,  2019,  1908,  2014,  1876,  1823,
    2006,  1913,  1964,  2098,  1943,  1931,  1944,  2042,  2045,  2013,
    1967,  2048,  1835,  2105,  2041,  2069,  1846,  2141,  1932,  2114,
    1828,  2074,  1844,  1903,  1950,  1970,  2064,  2092,  2097,  1827,
    2022,  2050,  1839,  1841,  1864,  1881,  1901,  1911,  1921,  1974,
    1977,  2035,  2046,  2052,  2053,  2070,  2115,  2126,  1826,  1857,
    1880,  1879,  1887,  1889,  1897,  1907,  1928,  1946,  1949,  1975,
    1983,  2039,  2049,  2059,  2065,  2066,  2068,  2093,  2123,  2134,
    1847,  1850,  1861,  1867,  1869,  1874,  1878,  1884,  1892,  1894,
    1895,  1896,  1906,  1916,  1923,  1939,  1940,  1951,  1969,  1973,
    1986,  2002,  2033,  2043,  2047,  2054,  2062,  2071,  2081,  2085,
    2102,  2108,  2112,  2120,  2125,  2128,  1870,  1988,  2030,  1855,
    1856,  1873,  1877,  1883,  1885,  1899,  1900,  1910,  1919,  1924,
    1926,  1927,  1933,  1941,  1958,  1959,  1972,  2000,  2004,  2007,
    2012,  2016,  2024,  2031,  2032,  2037,  2055,  2056,  2061,  2067,
    2072,  2078,  2079,  2080,  2082,  2084,  2086,  2095,  2117,  2118,
    2119,  2124,  2140,  1830,  1982,  1990,  1992,  2088,  1832,  1836,
    1840,  1845,  1851,  1852,  1865,  1866,  1868,  1871,  1882,  1898,
    1918,  1920,  1930,  1934,  1936,  1937,  1945,  1954,  1956,  1957,
    1968,  1981,  1999,  2017,  2018,  2034,  2036,  2040,  2051,  2073,
    2083,  2091,  2113,  2116,  2130,  2131,  2132,  1863,  1833,  1853,
    1854,  1860,  1929,  1862,  1886,  1888,  1902,  1979,  2103,  1912,
    1914,  1922,  1925,  1947,  1948,  1953,  1960,  1961,  1962,  2143,
    1994,  1995,  1998,  2003,  2008,  2015,  2020,  2021,  2023,  2029,
    2058,  2060,  2076,  2087,  2089,  2090,  2094,  2099,  2100,  2104,
    2106,  2107,  2122,  2127,  2129,  2133,  2135,  2139,  1989,  2138,
    1829,  1831,  1834,  1838,  1848,  1872,  1890,  1891,  1893,  1904,
    1935,  1938,  1978,  1984,  1997,  2001,  2136,  2137,  2038,  2057,
    2063,  2075,  2077,  2096,  2101,  2111,  2121,  1843,  1837,  1842,
    1859,  1909,  1952,  1965,  1966,  2026,  2028,  2110,  1985,  1942,
    2009,  1858,  1905,  1915,  1980,  1963,  2010,  1849,  1971,  1976,
    2109,  2027,     0,  1821,  1824,  1825,   704,     0,     0,     0,
     693,   727,   727,   724,     0,     0,   728,     0,    26,   692,
     695,     0,   702,   698,   942,   932,  1786,  1787,  1777,  1777,
    1388,     0,     0,  1689,     0,     0,  1372,     0,     0,  1373,
    1416,     0,     0,  1417,     0,     0,  1728,     0,  1386,     0,
    1435,  1434,  1433,  1431,  1432,  1430,  1428,  1425,  1515,  1514,
    1426,  1427,  1436,  1710,  1429,  1793,  1792,  1791,  1437,  2262,
    2262,   598,   589,   580,     0,   584,  2262,   899,   176,     0,
     337,   219,     0,     0,   529,     0,   528,     0,   515,   528,
       0,   508,   507,     0,     0,     0,   561,   560,   173,  1740,
    1739,  1677,  1675,  1676,  1672,  1674,  1671,  1673,  1658,     0,
    1728,     0,     0,  1583,     0,     0,  1746,  1744,  1745,  1583,
    1583,  1583,  1583,  1747,     0,     0,     0,  1532,  1718,     0,
    1735,     0,     0,     0,     0,  1802,  1803,  1804,  1805,  1806,
    1807,  1750,     0,     0,     0,     0,   458,   457,     0,     0,
     186,   228,   209,  1249,   176,  1237,     0,     0,     0,     0,
       0,     0,  1489,  1488,  1487,  1349,     0,  1355,  1351,  1353,
    1344,     0,  1592,  1341,  1337,  1311,  1310,     0,  1336,  1332,
       0,  1328,  1326,     0,  1635,     0,  1638,  1640,   660,     0,
     659,  1627,     0,  1630,  1632,  2252,  2249,     0,     0,  1278,
     484,   358,  1299,     0,     0,  1275,  1027,  1106,  1107,  1104,
    1100,  1104,     0,   927,     0,     0,   634,     0,     0,     0,
    1006,  1004,   718,   719,     0,   723,     0,     0,  2233,  2241,
     762,     0,   142,     0,  1016,  1023,     0,     0,  1031,  2214,
    2227,     0,  2225,  1422,  2217,  2216,     0,     0,     0,  1037,
     353,     0,     0,     0,     0,    24,  1073,  1074,   574,     0,
       0,     0,   797,   798,  1042,   992,   990,   831,   431,     0,
    1083,   773,   777,   774,   778,   381,     0,  1170,  1159,  1259,
    1174,  1157,  1152,     0,     0,  1153,  2262,     0,     0,     0,
       0,     0,     0,     0,    64,    93,     0,     0,   118,   113,
       0,   108,     0,   115,   109,   913,   905,   911,     0,  1140,
       0,  1142,  1144,     0,     0,   975,     0,     0,     0,     0,
    1093,  1263,     0,     0,  1820,  1822,  2262,   675,   680,   683,
     696,   694,   653,     0,   751,   749,   747,   745,   755,   753,
       0,     0,   743,   793,   741,   726,   737,   735,   791,   767,
       0,   729,   739,   985,   981,     0,     0,     0,     0,   701,
       0,     0,     0,     0,     0,     0,     0,  1643,     0,  1510,
    1511,  1798,  1468,  1532,     0,     0,     0,  1796,     0,  1448,
    1443,  1442,  1455,  1454,  1459,  1459,  1457,  1458,  1449,  1444,
       0,     0,  1450,  1451,  1711,  2145,     0,     0,     0,   586,
     588,     0,     0,   601,   593,   595,     0,   590,   591,     0,
       0,   609,   611,     0,     0,   607,   901,   868,   218,     0,
     642,   644,   639,     0,   528,   517,     0,   512,     0,     0,
     528,   528,   558,   557,     0,     0,  1767,  1659,     0,     0,
    1742,  1585,  1586,  1584,     0,  1771,     0,     0,     0,     0,
       0,     0,     0,  1733,     0,  1521,  1522,  1524,  1527,     0,
    1533,  1534,     0,     0,  1583,  1720,  1714,  1736,  1752,  1753,
    1751,  1749,     0,     0,     0,  2221,   454,   490,     0,   230,
    1205,   891,  1183,     0,     0,     0,     0,  1349,     0,     0,
       0,  1345,     0,     0,     0,  1339,  1623,  1621,  1590,  1602,
    1604,  1608,  1610,  1601,  1595,  1600,  1614,  1593,  1622,  1598,
    1613,  1599,  1620,  1612,  1495,  1587,  1588,  1589,     0,  1334,
    1330,     0,     0,  1318,     0,     0,   658,     0,     0,     0,
    2248,     0,     4,     8,    10,     0,   484,   427,     0,     0,
       0,  1024,  1102,  1101,     0,     0,     0,     0,     0,     0,
       0,     0,   717,     0,     0,   159,   157,     0,     0,   139,
       0,   149,   155,   727,   144,   146,     0,  1021,  1032,  1033,
       0,     0,  2223,   429,     0,  2204,  2205,  1036,     0,     0,
    1034,   352,   357,   636,   351,     0,   354,   359,     0,   484,
    1394,   627,   625,     0,   800,  1082,  1084,     0,   382,  1163,
    1161,     0,  1173,  1155,     0,     0,  1254,     0,     0,     0,
     101,     0,     0,    75,    81,    71,  2262,  2262,   111,   106,
     120,   116,     0,   110,   794,   914,   653,  2262,   904,   903,
     912,  1026,     0,     0,   973,   974,   968,   994,   484,  1099,
    1095,  1096,  1098,  2142,  2144,   705,   699,   697,     0,    24,
       0,  2262,  2262,  2262,  2262,  2262,  2262,   757,   731,   759,
     733,  2262,  2262,  2262,  2262,     0,   725,   730,  2262,   653,
     789,   787,   790,   788,     0,     0,    46,    44,    41,    35,
      39,    43,    38,    31,    40,     0,    34,    37,    32,    42,
      33,    45,    36,     0,    29,    47,   781,     0,   703,  1778,
       0,  1776,  1728,  1774,  1715,  1716,  1708,  1694,  1709,     0,
       0,     0,  1069,  1509,  1512,     0,     0,     0,  1406,  1378,
    1801,  1800,  1799,     0,     0,     0,  1453,  1456,     0,     0,
       0,     0,     0,  1401,     0,  1400,     0,  1402,  1397,  1398,
    1399,  1390,  1391,     0,     0,     0,   600,   605,     0,     0,
    2262,  2262,   578,   592,   615,   603,   617,  2262,  2262,   613,
     597,   608,   860,   338,   528,     0,   516,   528,     0,   528,
     528,   510,   509,  1684,  1682,  1683,  1679,  1681,  1678,  1680,
    1660,     0,     0,     0,     0,  1768,     0,     0,     0,  1766,
       0,     0,     0,     0,  1748,  1765,     0,  1525,     0,  1652,
    1528,     0,     0,     0,     0,  1520,  1538,  1540,  1542,  1582,
    1581,  1580,  1544,  1560,     0,  1535,  1536,  1723,  1301,     0,
       0,     0,  1813,     0,  1817,   212,     0,  1231,  1250,   860,
       0,  1238,  1231,     0,  1644,     0,  1477,     0,  1480,  1647,
       0,  1485,     0,     0,  1346,  1347,     0,     0,  1350,  1352,
    1354,     0,  1338,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1493,  1492,  1491,     0,  1496,  1497,     0,
    1333,     0,  1327,  1329,  1639,     0,  1641,  1631,     0,  1633,
    2250,  1307,     0,  1303,     0,     0,  1308,   875,     0,     0,
       0,     0,     0,  1365,  2255,  2254,   635,     0,     0,    48,
       0,   720,   722,   721,  1366,   727,  2262,  2262,   151,   661,
     161,   153,   163,   143,   150,  2262,     0,     0,     0,     0,
       0,  2226,     0,     0,     0,     0,     0,     0,  1075,     0,
    1395,   572,     0,   799,  1080,     0,  1260,  1261,  2231,     0,
      93,     0,    65,     0,     0,     0,    78,     0,    93,    93,
     119,   114,  2262,  2262,   104,     0,   915,   909,   917,   916,
     906,   622,   955,     0,     0,     0,   707,   686,   700,   654,
     768,     0,   752,   750,   748,   746,   756,   754,     0,  2262,
       0,  2262,   744,   742,   738,   736,   792,   740,    24,   782,
       0,     0,     0,    27,     0,  1781,     0,  1695,     0,     0,
    1707,  1690,  1706,  1513,     0,  1470,     0,  1405,     0,     0,
    1797,     0,  1794,     0,  1461,  1465,  1441,  1463,  1466,     0,
    1452,  1712,     0,     0,     0,     0,     0,     0,  2146,  1404,
    1403,  1392,  1387,  1389,  1440,     0,     0,   602,   599,   594,
     596,     0,  2262,  2262,   610,   612,  2262,  2262,     0,   518,
       0,   522,     0,     0,   514,   513,     0,     0,     0,     0,
       0,     0,  1764,  1772,  1760,  1761,  1762,  1763,  1529,     0,
    1523,  1543,  1547,     0,  1560,  1546,     0,     0,  1561,  1576,
    1573,  1574,  1571,  1579,  1578,  1572,  1575,     0,     0,     0,
       0,     0,  1577,     0,     0,     0,  1517,  1518,  1737,     0,
    1537,  1531,  1302,  1721,  1411,  1407,  1408,  1413,  1412,  1719,
    1301,     0,     0,  1229,  1230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1228,     0,     0,  1216,
    1217,  1218,  1215,  1220,  1221,  1222,  1219,  1206,  1197,     0,
       0,  1253,     0,  2262,     0,  1192,     0,     0,     0,     0,
       0,     0,     0,  1184,  1185,     0,  1114,  1648,     0,  1649,
       0,     0,     0,     0,  1484,  1483,  1349,  1482,  1474,  1340,
    1624,     0,     0,     0,     0,     0,     0,  1625,  1617,     0,
       0,     0,  1617,  1653,  1490,  1503,  1508,     0,  1505,  1502,
    1504,     0,  1506,  1494,  1498,  1499,  1349,  1335,  1331,     0,
       0,  1306,  1305,     0,  1290,     9,     0,  1280,   876,  1111,
     364,  1280,     0,     0,  2246,     0,     0,  1007,    49,     0,
     779,   160,   158,     0,  2262,     0,     0,     0,  2262,   156,
     145,     0,   148,   147,     0,  1013,  1017,     0,  2208,  2207,
    2206,     0,     0,   356,     0,   575,     0,  2262,   801,     0,
     653,  1164,     0,  1255,    70,     0,     0,   102,    68,    93,
      76,    82,     0,   121,   117,   795,  2262,   919,   653,   918,
       0,   619,     0,   825,   826,   824,  1097,   710,   708,     0,
     690,   687,     0,   758,   732,   760,   734,   769,   785,   786,
     783,   784,    30,    28,     0,  1775,  1724,  1696,  1692,  1691,
       0,  1469,  1728,  1472,     0,  1380,  1375,  1374,  1377,     0,
       0,  1460,     0,     0,  1724,     0,     0,  2183,  2181,     0,
       0,  2165,  2180,     0,     0,  2182,     0,     0,     0,     0,
       0,  2219,  2179,  2171,  2198,  2199,     0,  2163,  2166,  2167,
    2178,  2170,  2200,     0,  2156,  2155,  2159,  2161,     0,  2154,
       0,  2157,  2148,     0,     0,   606,   604,   616,   618,   614,
       0,     0,   528,     0,   528,   528,     0,  1727,     0,  1660,
       0,     0,     0,  1526,  1545,  1539,  1541,  1548,  1550,  1548,
       0,  1555,  1548,     0,  1553,  1548,     0,  1563,  1562,     0,
    1564,     0,  1516,     0,  1415,  1414,  1410,  1722,     0,   235,
    1223,  1224,  1225,  1227,  1210,  1208,  1207,  1211,  1212,  1209,
    1226,  1213,  1214,  1198,  1000,  1233,   997,     0,     0,  1251,
       0,  1196,  1195,  1190,  1188,  1187,  1191,  1189,  1193,  1194,
    1186,  1239,     0,  1475,  1481,  1651,  1644,  1486,  1348,  1591,
    1603,     0,  1605,  1607,     0,  1609,     0,     0,     0,  1615,
    1594,  1619,     0,  1476,  1478,     0,  1500,  1501,  1642,  1634,
    1304,     0,     0,  1296,  1291,  1292,  1309,     0,  1287,  1288,
       0,     0,  1301,  1281,  1282,     0,    24,  1276,     0,     0,
    1030,     0,    50,  1010,     0,    24,   162,   152,     0,   663,
     665,   164,   154,   779,     0,  2224,  1039,     0,   355,  1396,
       0,  1081,    24,     0,     0,    66,     0,    79,    88,     0,
      72,   910,   907,   623,  2262,   969,     0,  2262,   706,   685,
     691,   653,  1785,     0,  1783,     0,     0,  1697,  1693,  1471,
       0,  1473,  1467,     0,  1379,     0,  1795,  1462,  1464,  1439,
       0,  2169,  2168,     0,     0,  1583,     0,  1583,  1583,  1583,
    1583,  2172,     0,     0,  2152,     0,     0,     0,     0,  2185,
    2153,     0,     0,     0,     0,     0,     0,  2147,  1393,  1445,
     870,   869,   339,   519,     0,     0,   524,   523,  1685,  1808,
    1811,  1809,  1530,     0,  1567,  1569,     0,  1556,  1559,  1558,
    1566,     0,  1568,  1548,     0,  1519,  1409,  1816,   213,  1002,
    1001,   999,     0,  1232,  1115,  1119,  1121,     0,  1125,     0,
    1123,  1127,  1116,  1117,     0,   892,     0,     0,  1645,  1650,
       0,     0,  1626,  1618,  1596,     0,  1597,     0,     0,  1294,
    1289,  1295,  1293,  1286,  1285,  1284,  1279,  1283,   365,   362,
       0,  1028,     0,     0,     0,  1009,   780,   140,   662,    24,
    1019,  1038,   573,  1078,    67,  1256,    84,     0,     0,    77,
      88,    88,  2262,   620,     0,     0,   709,   770,     0,  1782,
    1725,  1718,     0,  1381,     0,  1718,  2196,     0,     0,  2201,
       0,     0,     0,     0,     0,     0,     0,     0,  2164,  2187,
    2188,  2186,  2184,  2162,     0,  2158,  2160,  2149,  2150,  1446,
       0,  1438,   528,   528,  1549,  1773,  1551,     0,  1554,  1552,
    1570,     0,   998,  2262,  2262,  1129,  2262,  1131,  2262,  2262,
    1118,  1252,  1240,     0,  1606,     0,  1616,     0,  1507,   367,
    1029,  2245,     0,     0,     0,     0,     0,     0,    55,     0,
      54,     0,    52,     0,     0,   141,  1085,    88,    93,    88,
      89,    83,    73,   908,     0,     0,   711,    24,  1784,  1717,
    1726,  1385,     0,  1382,  1384,  1698,  2197,     0,     0,  2195,
       0,     0,     0,     0,     0,  2173,  2194,     0,  1447,   521,
     520,  1557,  1565,  1120,  1122,  2262,  1126,  2262,  1124,  1128,
    1646,  1611,  1479,   369,   374,   372,   363,     0,   370,   376,
      57,    62,    59,    61,    58,    60,    56,     0,    51,     0,
     664,   666,  1089,  1079,     0,  1087,  1257,    85,    80,   621,
     970,  2262,   771,     0,  1376,     0,  1699,  1713,  2193,  2202,
    2189,  2190,  2191,  2192,     0,  2174,     0,     0,  1130,  1132,
    2262,  2262,   368,   371,  2262,    53,     0,  2262,  1086,  1088,
       0,   707,  1383,     0,  1703,  1700,  1701,     0,     0,  2151,
     375,   373,   377,     0,  1090,    86,   712,     0,     0,     0,
    2176,     0,  2175,  1011,    90,     0,  1704,  1702,     0,    92,
       0,    87,     0,  2177,    91,  1705
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   826,   827,   828,   829,  1050,  2422,  2423,   179,   320,
     180,  1417,  1418,  2246,  2583,  3630,  3107,  3108,  3533,  3631,
    3632,   830,  1193,  3145,  2839,  3551,  2185,  2837,  3398,  3149,
    3547,  2838,  3399,  3638,  3740,  3764,  3549,  3771,   648,   649,
     650,  1542,  2499,   831,  1553,  1198,  1551,  2193,  2509,  2190,
    2507,  2512,  2843,  1552,  2506,  2194,  2842,   832,     9,    28,
      29,    30,    31,    32,   834,  1113,  2122,  1443,  2449,  2453,
    2454,  2450,  2451,  3114,  3118,  2805,  2797,  2796,  2798,  2801,
     494,   270,   601,   835,    55,    56,    11,    41,   113,    70,
      71,    72,    73,   195,   334,    74,    75,   241,   339,   227,
    1013,   518,  3002,   370,   936,  2309,   398,   399,   228,   352,
     341,   347,  1362,  1363,   117,   536,   118,   119,   358,   229,
     354,   340,   342,   520,   230,   255,   574,   243,   246,   244,
     245,   954,   552,   553,   555,   560,   939,   247,   248,   389,
     557,   191,    12,    51,   149,   150,   151,   945,  2938,   152,
     251,   239,   392,   393,   394,   395,  2145,   836,   837,   838,
     839,  1071,  3619,  3366,  1419,  3686,  3687,  3688,  3731,  3730,
    3734,   840,   841,   842,   843,   844,   845,   846,  1061,   495,
    1066,  1411,  1412,  1459,  1166,  1460,   297,   298,   299,   300,
     301,   452,   496,  1345,   497,   498,   499,   500,   501,   502,
     503,   990,   181,   512,  1000,  1002,  2038,   182,   506,   996,
     505,   995,   508,   998,   507,   997,   955,   968,   302,   303,
     184,   304,   419,   420,   421,   422,   404,   424,   847,  1133,
    2148,  3137,  2480,    87,   236,   546,  1962,  1261,  1262,  1263,
    1959,  1960,  2296,  2297,  2298,  2640,  2641,  1963,  1964,  2292,
    2644,  2636,  2304,  2305,  2647,  2648,  2936,  2932,  2933,   848,
    3404,  3644,  3161,   849,  1471,    57,  2107,  2108,  2474,   405,
     426,  1105,  1171,  1042,  1093,  1076,  1115,  2539,   185,  1043,
    1033,  2079,  2800,    59,   305,   850,  1203,   851,  1216,  1217,
     852,   853,   854,   855,  1224,  3170,  1245,  3409,  1246,  2220,
    1247,  2536,  1248,  2857,  1249,  2249,   856,  2216,  2856,  3169,
    3407,  3406,  3711,    88,    13,   857,  1437,  2112,  2113,  2114,
    2239,  1907,  2240,  2241,  2869,  2871,  2554,  2553,  2558,  2552,
    2551,  2544,  2543,  2542,  2541,  2546,  2545,  2548,  2550,   858,
     859,  1111,   860,  1903,  1231,  3647,   861,  1519,  3375,  2585,
    2586,  2242,  2555,  2515,  2845,  1160,  1499,  2152,  2483,  2153,
    1495,   862,   863,  1209,  2208,  3165,   864,   865,   866,   867,
      14,    45,    15,    16,    17,    89,    90,   868,    91,    18,
     927,    19,    92,    93,   129,   548,  1968,  2652,  3461,    94,
     125,   363,   869,  2778,    20,    21,    22,    23,    24,    40,
      62,    95,   677,  2044,  2719,    96,   237,   547,   930,   931,
    1265,  1966,   870,  1204,  2519,  2197,  2517,  3552,  3156,  2198,
    2516,  2848,  3158,   871,   872,   873,  1087,  1088,  1556,   874,
    1250,  1251,   875,  1915,  1252,   306,    64,    65,    66,    67,
    1563,   155,   109,    68,   106,   187,   188,  1564,  1565,  2526,
    1566,   674,   675,  1233,   676,  1234,  1164,  1165,  1567,  1568,
    1415,  3305,  3306,  3491,  1103,  1104,   876,  1432,  3535,   877,
    3126,   878,  1447,  1448,  1449,  2128,  2126,   879,   880,  2431,
    2460,   881,  2139,  2470,   882,  1161,  1162,   883,  1026,   884,
    2596,   885,  3636,  3140,   886,  2487,  3703,  3704,  3705,  3737,
    1168,   887,  1569,  2210,  2530,  2531,   888,  1425,  2099,  1041,
    1404,   889,   890,   891,  2721,  3309,  3502,  3503,  3603,  3604,
    3608,  3606,  3609,  3675,  3677,   892,   893,  1558,  2202,   894,
    1560,  1531,  1532,  1533,  2175,   895,  1183,  1181,   896,   897,
    2167,  1527,  1177,   194,  1534,  1535,   307,  2722,  3043,  3044,
    3027,  1058,  1059,  2717,  3028,  3031,    97,   124,   540,  1372,
    2372,  3045,  3506,   434,   898,  1175,    98,   121,   537,  1369,
    2370,  3032,  3504,  2718,  1197,  2830,  3394,  3637,  2170,   899,
     900,   901,   902,   903,  1074,  2429,  1052,  2425,  3362,  3363,
    3364,  3519,  3353,  3354,  3355,   904,  2993,  2772,  2773,  2775,
    2063,   905,   906,  1381,  1382,  1383,  2072,  2411,  1384,  2408,
    2069,  1385,  2384,  2064,  1386,  1387,  1388,  2376,  2381,  1389,
    2058,  2059,   907,  1083,  1063,   908,  1940,  1941,  2264,  3197,
    3425,  2899,  3194,  3652,  3653,  1942,  2286,  1921,  2632,  2922,
    3243,  2821,  3136,  2633,  1943,  1944,  2355,  2995,  2996,  2997,
    3286,  1945,  1946,  1456,   909,  1120,   910,  1258,  1947,  1948,
    2280,  3591,  2281,  2282,  2283,  2616,  2903,  2906,  2907,  1949,
    2606,  2894,  3422,  2052,  2053,  3082,  2725,  3343,  2726,  2054,
    2730,  2065,  2757,  2066,  2758,  3083,  3084,  3085,  3086,  1950,
    2258,  2259,  2603,  1951,  2990,  2705,  2986,  2350,  2017,  2345,
    2346,  2347,  2959,  2018,  2351,  2706,  2991,  2695,  2696,  2697,
    2698,  2699,  3474,  3267,  3594,  2700,  3476,  3477,  2984,  2701,
    2985,  2702,  2334,  2404,  2405,  2406,  3337,  2407,  3061,  3068,
    3513,  2727,  1030,  2908,  3049,  3236,  2729,  2690,  1318,   308,
    1319,  1998,   445,   446,  1999,  2670,    39,   911,   912,  3189,
    3418,  2887,  3417,  3717,  3745,  3746,  2891,  2597,  1952,  2598,
    2621,  3204,   604,  2593,  2594,  2356,  2708,  3416,  3193,  1320,
     975,  1321,  1322,  2987,  2703,  1324,  1325,  2336,  3596,   913,
     914,  2251,  2595,  3185,  3413,  3414,  1918,   915,  1069,  1954,
    1955,  2268,  2901,  1956,  1957,  2612,  2031,  2329,  1326,  1327,
    1328,  1329,   916,  1212,  1892,  1893,  1894,  2212,  1895,  2213,
    1958,  2622,  3242,  3457,  2918,  3239,  3240,  3241,  3238,  3226,
    3227,  3228,  3229,  3230,  3231,  3570,   917,  2137,  2465,  2466,
    1121,  1330,  1331,  1123,  1124,  1125,  1332,  1126,  1454,  2131,
    2132,    25,   919,  1185,  2176,  1440,  1521,   920,   921,  2789,
     922,  2420,  1046,  2086,   923,   924,    35,   541,   542,   543,
     544,   545,   925
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2892
static const short yypact[] =
{
    1392,   870, -2892,   333,   333,  1290, -2892, -2892,  1290, -2892,
      24, -2892, -2892, -2892,   582, -2892,  1392, -2892, -2892, -2892,
   -2892, -2892,   -54, -2892, -2892, -2892, -2892, -2892,   431,   563,
   -2892,   620, -2892, -2892, -2892, -2892, -2892, -2892,     3, -2892,
     613,   297, -2892, -2892, -2892,   442, -2892, -2892, -2892, -2892,
   -2892,   213,   333, -2892,   333,   529,    24, -2892,   758, -2892,
   -2892, -2892, -2892, -2892, -2892,  1196,   254, -2892, -2892, -2892,
     930,   558,   333, -2892, -2892,   947,   333, -2892, -2892,   333,
     333, -2892, -2892, -2892,   333,   333, -2892, -2892, -2892, -2892,
     442, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
    5802, -2892,   254, -2892,   865,  2921, -2892, -2892,   587, -2892,
   -2892,   971,   297,   555, -2892, -2892, -2892, -2892, -2892,  5204,
   -2892,   333,   561,   984,   333,    24, -2892, -2892, -2892,   333,
   -2892, -2892,   765,   673,  1168, -2892, -2892,   688, -2892,   692,
   -2892,   680, -2892, -2892,   714, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,   728, -2892, -2892, -2892,   740,
     746,   751,   766,   795,   818,   839,   872,   878,   891,   896,
    2921,   901,  5583,   926,   932,   948,   963,   983,   999,  1867,
    1312, -2892, -2892, -2892, -2892,   903, -2892,   157, -2892,  2921,
   -2892,   194, -2892, -2892, -2892,   147, -2892, -2892, -2892,   811,
   -2892, -2892, -2892, -2892, -2892, -2892,   765,  1002,  1018,  1029,
   -2892,  1168, -2892, -2892,  1034, -2892,  1053, -2892,   949, -2892,
   -2892,  1071, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892,  1090,  1442,   333,  1099, -2892,    24,    24,  1118,   333,
   -2892,   630,  1496, -2892,   934,  1311, -2892,   940,  1359,  1532,
    1579,   333,  1608,  1640, -2892,  1008, -2892,   356,    66,    66,
      66,    66,    66,  5583,  1092,  1545,    61,  5583,  1015,  5583,
   -2892,  5583,  5583,  5583, -2892, -2892, -2892,  1105,  1187,  1204,
    5583,  1363,  1219, -2892,  5583,  5583,  1223, -2892,  1224, -2892,
     932,  1231,  1247,  1248,  1257,  1670,  9122, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892,  1278, -2892, -2892, -2892,
   -2892, -2892, -2892,   356,   356, -2892, -2892, -2892, -2892, -2892,
    2921, -2892, -2892,   333,  2921,  1251,   169, -2892, -2892, -2892,
   -2892,  1731, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
    1276, -2892,  1276,   630,  1740,  1744,  1748, -2892, -2892, -2892,
    1755,  1759,   297,  1608,  1276,  1760,  1119, -2892,  1682, -2892,
    1349,  1319, -2892,  1388, -2892, -2892, -2892,  1134, -2892, -2892,
    1780,  1362, -2892,  1329, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892,  1359,  1329, -2892, -2892, -2892, -2892, -2892, -2892,  1330,
     207,   269,   473, -2892,  1188, -2892, -2892, -2892,  1339,  1810,
     274, -2892,  1380,  1344,   363, -2892,  -191,  1389,  1393,   385,
     395,  4888,  1394,  1396,    98,  1254, -2892, -2892,    89,  1397,
   -2892, -2892, -2892, -2892,   396, -2892, -2892,  8150, -2892,  7911,
    9234,  4129,  4129,  5583, -2892,  1315,  5583,  9122,  1351, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892,  1170,  1827,  8237,  9122,
    1315,  1828,   370,  5583,  5583,  5583,  5583, -2892,  5583,  5583,
    5583,  5583,  5583,  5583,  5583,  5583,  5583,  5583,  5583,  5583,
    5583,  5583,  5583,  5583,  5583, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,  5583,  5583, -2892, -2892,  1367,
    5583, -2892,  5583,  1376, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892,   356,  5583,  5583,  5583,  5583,  1414,
    1855,  1867,  3924,  1384, -2892,  2921,  1360, -2892,  1195,  1846,
   -2892,  1206, -2892,  1848,  1432,  1434,   402,  1572,   404,   413,
     524,  1413, -2892,   424, -2892, -2892, -2892,   333, -2892, -2892,
     333,  1477, -2892,  3909,   555,  7527,  1868,  -229,   333,  1877,
     628, -2892, -2892,  1311,  1873, -2892, -2892, -2892, -2892,  1874,
   -2892,  1878, -2892,  1879, -2892,   333, -2892,   333, -2892, -2892,
    1608,  1880, -2892, -2892, -2892, -2892,   333,    66, -2892,  2921,
      63, -2892, -2892, -2892, -2892, -2892,  1311,  1311,  1882,   -21,
    1311,  1484, -2892,  1883,  1263,  1493, -2892,    61, -2892, -2892,
   -2892,  1468,  9122,   248,  1471,  8258,  1893,  1363,  1475, -2892,
    1485,  1487, -2892,  8327,  8351,  8798,  8868,  9171,  4845,  9234,
    9443,  9508,  9622,  9670,  1162,  2027,  3582,  3614,  4129,  4129,
    5423,  5423,  1184,  9122,  8906,  8960,  1315,  9122,  9068,  1315,
   -2892,  9122,  9122,  9122,  9122, -2892,  1900, -2892, -2892,  1930,
   -2892,  9122, -2892,   175,  2921, -2892,  1491,  1917,   628, -2892,
   -2892,  1912, -2892,  1457,  1920, -2892,  1921, -2892, -2892, -2892,
    1922, -2892, -2892,  1287,  1515,  1956, -2892,   333,  1519, -2892,
   -2892, -2892,   356,   356,   356,   333,   986,   333,  1517,   245,
     245,  1536,   333,   333,   245,   245,   333, -2892,  1517, -2892,
   -2892,   333, -2892,   840, -2892, -2892, -2892,   245, -2892, -2892,
   -2892, -2892,   333, -2892, -2892, -2892, -2892,   104,   104,  5583,
   -2892, -2892, -2892,  1536,  1536, -2892, -2892,   245, -2892, -2892,
     245, -2892, -2892,   333, -2892, -2892,   245, -2892, -2892,   356,
     245, -2892, -2892,  5583,   245,   356,   333,   356,   245, -2892,
   -2892,   160,   245,   245,   160,   245,   333,   160,   245, -2892,
     245,   245,   245, -2892,  1517, -2892, -2892,   356,   245, -2892,
   -2892,   245,    85,   333, -2892,  1536, -2892, -2892,   245,  1049,
   -2892, -2892,   356,  1289, -2892,   245, -2892,  9645,   356,  5583,
      66,    66,   245, -2892, -2892,   986,   356,   364, -2892,  5583,
   -2892,   882,  5583,   245,    73, -2892,  5583,   245,  1942,   356,
   -2892,   245,  5583, -2892,  5583,   104,   333,   245,   333,    66,
     245,   333,    66, -2892,   333,   290, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,   584, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,   580, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892,   848,   333, -2892,
     670, -2892,  1525, -2892, -2892, -2892,  1616, -2892, -2892,  1527,
    1528,  1530,  1535, -2892, -2892,  1303,  1977,  1539,  1540, -2892,
     506, -2892,  1505, -2892,  1317, -2892, -2892,   397,  1311,  1968,
   -2892,  1551,   -12, -2892,  1980, -2892,  1370, -2892, -2892, -2892,
    1347, -2892, -2892, -2892, -2892,  9984, -2892,  1105,  1570, -2892,
    1105, -2892,  1105,  1105,  1105,  1105,  1105,  1999,  2000,  2002,
    5583,  1585,  2008,  5583,  1589,  1590,  1591,  1592,  1594,  1597,
    1605,  3924,  3924, -2892,   186, -2892, -2892, -2892,  1696,  1607,
   -2892,  1610,  1611,  1387,  1631,   333, -2892,   333,  1634, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892,   351,  1407,    -4,
    1127,  1598, -2892, -2892, -2892, -2892,  1411,   474, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892,  2074,  1408, -2892, -2892,
    1606, -2892,  1536, -2892,  1567,   178, -2892, -2892, -2892,  1481,
   -2892,  9122, -2892, -2892,  1454, -2892, -2892,  4728, -2892, -2892,
   -2892,   356, -2892, -2892,  1536, -2892,   -31, -2892, -2892,  1783,
   -2892,   124, -2892,  1595, -2892, -2892, -2892, -2892,  2100, -2892,
   -2892,   -76, -2892,  1439, -2892,  1440,  2100, -2892,  1463, -2892,
   -2892, -2892,  1639,   192, -2892,  1601, -2892,  1410, -2892, -2892,
   -2892, -2892,  1415,   222, -2892,  -243, -2892,  1446,  1622,  1612,
    1742,  1465, -2892, -2892,  1455, -2892, -2892,  5583,   226,  1076,
    5583, -2892,   111,   245, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,    58,    58,    58, -2892,    58,  2720,    58,
      58,  1486,   -31,  1486,  1486,  1096,  1096,  1486,  1486,   -31,
   -2892,  2127, -2892,  1665,   262, -2892,  2138, -2892,   -31,   127,
      43, -2892, -2892,  5583, -2892, -2892, -2892,  1133, -2892,  1097,
   -2892,   555, -2892,  5583, -2892,  5583,  1662,  1663,  1664,  1668,
    1627,  1677,  1097, -2892,  1762,  1045,  1507, -2892,  1529, -2892,
   -2892,   333, -2892, -2892,  1141, -2892,  2154, -2892,  2149,   333,
   -2892,   411,  6845,  1538, -2892, -2892,  2162, -2892,  1461,  2162,
    2164,  1473,  2162,  2164,  5583,  2162, -2892, -2892,   178,   356,
   -2892, -2892,  1705,   407, -2892, -2892,  1697,   356,  5583,  1701,
   -2892, -2892,  2159,  2161,  2070, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,  1148,  1148,   245,   245,   245,  4178, -2892,
   -2892,  2050,   848, -2892, -2892,   683, -2892, -2892, -2892,  1687,
   -2892, -2892, -2892, -2892,  5802,  1608, -2892, -2892,  1537,   333,
    1311,  2172,   416,  1311, -2892,   427,  1311,  1311,  1632,  1559,
    1636, -2892,  9695,  9695, -2892,  1446, -2892, -2892, -2892, -2892,
    1462, -2892,  6395,  1718, -2892,  1720,  1723,  1729, -2892,  1729,
    1729,  1736,  1737,  1738,  1741,   333,   -25, -2892, -2892, -2892,
   -2892,   102, -2892,    67,  2110, -2892, -2892,  1462, -2892,  1462,
    1750, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892,  9122,   425, -2892, -2892,   432, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  1714,
   -2892, -2892,   436, -2892, -2892, -2892, -2892, -2892, -2892,    24,
   -2892, -2892,    24,  1039,   140,  2200, -2892, -2892,   602,   190,
     929,  2224, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
     333,  1652,   333, -2892, -2892,  1660,   333,  1675,   333,   333,
    1536,  1584,  1749, -2892,  1753,    99, -2892, -2892, -2892,  1536,
   -2892, -2892,  2228, -2892, -2892,  1560,  1756, -2892, -2892, -2892,
    1076, -2892,  1205,  2193,  1205, -2892,  1097,   160,  5583,  5583,
    5583,  1758, -2892, -2892,   356,   356,  1536,  1565,  1097,    66,
    1531,    85,   356, -2892,  1569,  5583,  1840, -2892, -2892,  1643,
     333,  1446, -2892,  2921, -2892, -2892, -2892,   333,  1226,  2247,
   -2892, -2892,  1593,   155,   178,   356, -2892, -2892,  2246,  2248,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  1272, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  9645,   356,
     356, -2892,  1096,  5583,   -23,   969,   972, -2892, -2892, -2892,
   -2892, -2892,   170, -2892, -2892, -2892, -2892,  2059,  1821, -2892,
    1831,   555,  5583, -2892,    84, -2892, -2892,   333,  2244,    66,
      66, -2892,  1630, -2892,    61,  1599,   356, -2892,   333,   333,
    5583,  -113, -2892,  1642, -2892, -2892,   375, -2892,  1743, -2892,
    1768,  5583,  1040, -2892, -2892,  1603, -2892,  2270, -2892,  1684,
   -2892,   356, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892,  6130, -2892, -2892, -2892, -2892,   333,    66,    66,
     181,   407,  2078,  2241,   356,   178, -2892,  1690, -2892, -2892,
    2247,  2268,  1850, -2892, -2892, -2892, -2892, -2892,  1928,  1928,
   -2892,   771,  1708, -2892,   333,  1536, -2892,  1536,  1536, -2892,
   -2892,  1536,  1536, -2892,   333,  1761,   248,  1536, -2892,  1761,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,   204,
     204,   365,   883, -2892,   937, -2892,   683, -2892,    24,  2280,
   -2892, -2892,  1337,  1862, -2892,   225,  1311,  2282, -2892,  1311,
    1698, -2892, -2892,  1866,  1869,  1699, -2892, -2892, -2892,  1707,
    1707, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  1637,
     248,  1870, 10045,   497,  9984,  1790, -2892, -2892, -2892,   497,
     497,   497,   497,  1646,  9984,  9984,   241,  1746,   591,   333,
   -2892,  9984,  9984,  9984,  9984, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892,  1641,  -126,  1076,  5583, -2892, -2892,  1876,  2280,
   -2892, -2892, -2892, -2892,    24, -2892,  1836,  1842,  1844,   910,
    1845,  1851, -2892, -2892, -2892,  2218,   333, -2892,  2325, -2892,
   -2892,   577,  3955, -2892, -2892, -2892, -2892,   333, -2892, -2892,
     577,  1625, -2892,   351, -2892,  1672, -2892,  1703, -2892,  1903,
     254, -2892,  1688, -2892,  1712, -2892,  1764,  1875,   333, -2892,
   -2892, -2892, -2892,  4728,   333, -2892,  1692, -2892, -2892,  2193,
   -2892,  2193,  1689, -2892,  2362,  2363, -2892,  2364,  1752,  5583,
   -2892, -2892,  2369, -2892,  1709, -2892,  1847,  1702,  2164, -2892,
   -2892,  1711,   846,   333, -2892, -2892,  1913,   245,   886,  1455,
    1867,   191, -2892, -2892, -2892, -2892,  5583,  1536,  1076,  -196,
   -2892,   333,   333,  5583,    65,   -31,  2397,  1199,  2396,  2379,
    2381,  2720, -2892, -2892, -2892, -2892, -2892, -2892, -2892,   356,
    2034, -2892, -2892, -2892, -2892,  2290,  5583,   555, -2892,  2142,
   -2892, -2892, -2892,  5583,   104, -2892,  2036,  2412,  2415,   437,
     444,   333,  1976,  1097, -2892,  3924,  1941,  1943, -2892, -2892,
    2010, -2892,  5583,   451, -2892,  1782, -2892, -2892,   572, -2892,
    5583, -2892, -2892,  1763,   865, -2892,  1423,   333,  2418,  7998,
   -2892, -2892,  1076,   356, -2892, -2892,    38, -2892,  2164,  2164,
    1726, -2892,  1832,  1852, -2892, -2892, -2892, -2892, -2892, -2892,
      66,    66, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
    2743, -2892, -2892, -2892, -2892,    66,  5541,  2442,  2416, -2892,
    1097,   856,   328,   119,  2296,   -43,   986, -2892,    34, -2892,
   -2892, -2892,  1969,    74,  1536,   208,  1787, -2892,  1774, -2892,
   -2892, -2892, -2892, -2892,  1971,  1971, -2892, -2892, -2892, -2892,
    1863,  1784,  2461, -2892, -2892, -2892,   439,  1792,  1795, -2892,
   -2892,   356,   126, -2892, -2892, -2892,  1789,   883, -2892,   333,
     333, -2892, -2892,   333,   909, -2892, -2892, -2892, -2892,  2007,
   -2892, -2892, -2892,   467,  1311, -2892,   492, -2892,  2042,  2044,
    1311,  1311, -2892, -2892,  1554,  9984, -2892,   400,  2485,  2053,
    2494, -2892, -2892, -2892,  9984, -2892,   446,  9984,  9984,  9984,
    9984,   333,   456, -2892,   189,  2495, -2892, -2892,   333,  9533,
   -2892,  2080,   333,  1834,   497,  2119, -2892, -2892, -2892, -2892,
   -2892, -2892,  1554,  2480,  1554, -2892,  9122, -2892,  2030, -2892,
    1997, -2892,  1998,   122,   122,   122,   459,  2218,   122,  9533,
     333, -2892,   462,   333,   469, -2892, -2892, -2892,  2029,  2032,
    2035,  1462,  1462, -2892,  2038, -2892,  2040,  2041,  2048,  2049,
   -2892, -2892, -2892, -2892,   977, -2892, -2892, -2892,   470, -2892,
   -2892,   477,   333, -2892,   333,  1713, -2892,   333,  1717,  5583,
   -2892,   333,  2507, -2892, -2892,   577, -2892, -2892,  1864,   577,
     200, -2892, -2892, -2892,  1097,  5583,  5583,  5583,  5065,  2511,
    1536,    78, -2892,  1097,   333, -2892, -2892,   333,   333, -2892,
     862, -2892, -2892,   409, -2892,  1871,  5583, -2892, -2892, -2892,
    2524,  2921,  2023, -2892,  1872,  2531, -2892, -2892,  1097,  1911,
   -2892, -2892, -2892, -2892, -2892,   333,  2164, -2892,   178, -2892,
    1935, -2892, -2892,   478, -2892, -2892, -2892,   356, -2892,  7986,
   -2892,  1059, -2892, -2892,  2160,  2518, -2892,  2145,  2146,  2037,
    1881,  2150,  2073, -2892, -2892, -2892,   536,  2136, -2892, -2892,
   -2892, -2892,  2010, -2892, -2892, -2892,   277,   589, -2892, -2892,
   -2892,  2247,  5583,  2075, -2892,  2046, -2892, -2892, -2892, -2892,
    2552, -2892, -2892, -2892,  2553, -2892,  1858, -2892,  2535,   -31,
     333,  3269,  3269,  3269,  3269,  3269,  3269, -2892,  2557, -2892,
    2558,  3269,  3269,  3269,  3269,  1272, -2892, -2892,  3269,   145,
   -2892, -2892, -2892, -2892,  2540,  2554, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,  2556, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,   481, -2892, -2892, -2892,  2545, -2892, -2892,
    1536, -2892,   248, -2892, -2892, -2892, -2892, -2892, -2892,  1926,
    1927,   137, -2892,    34, -2892,   122,  1907,   245, -2892,  2094,
   -2892, -2892, -2892,   333,   333,   122, -2892, -2892,   131,  1536,
    1175,  9984,   272, -2892,  5583, -2892,  5583, -2892, -2892, -2892,
   -2892, -2892,  1973,   245,   131,  1536,  2573, -2892,   356,   333,
     836,   836, -2892, -2892,  2574, -2892,  2574,  1041,  1041,  2574,
   -2892, -2892,  1868, -2892,  1311,  2560, -2892,  1311,  1751,  1311,
    1311, -2892, -2892,  2101, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892,   102,  1462,  1906,  1462, -2892,  1462,  2139,  9984, -2892,
    2143,  2147,  2151,  2152, -2892, -2892,   241, -2892,   241, -2892,
   -2892,  9833,  1729,  5399,  1729,  2584,  2587, -2892, -2892, -2892,
   -2892, -2892, -2892,   278,  9984, -2892,  2092, -2892,  2274,   152,
     328,   333, -2892,  2153, -2892, -2892,  5713,   108, -2892,  1868,
    2206, -2892,   108,  1536,   739,  2155,  2596,  1936, -2892, -2892,
     486, -2892,   487,   910, -2892, -2892,   488,   176, -2892, -2892,
   -2892,   577, -2892,  2579,  2579,  2581,  1932,   -71,  2583,  2588,
    2593,  2583,  2583, -2892, -2892, -2892,   209, -2892,   843,   333,
   -2892,   577, -2892, -2892, -2892,  1951, -2892, -2892,  1952, -2892,
   -2892,   449,   489, -2892,   333,   491, -2892,  5583,  2168,  2604,
     493,  1097,  2620, -2892, -2892, -2892, -2892,  5583,  2009,  2300,
    5583, -2892, -2892, -2892, -2892,   409,  1307,  1307,  2623,   -95,
   -2892,  2624, -2892, -2892, -2892,  1307,   333,  2033,  1431,  2628,
     333, -2892,  2921,   100,  1536,  2629,  1097,  -137,  2397,  5583,
   -2892, -2892,  2720, -2892,  1923,  5583, -2892, -2892, -2892,  2633,
    3924,   356, -2892,   840,   333,   356, -2892,  2194,  3924,  3924,
   -2892, -2892,   536,  2136, -2892,  1272, -2892, -2892,  1214, -2892,
   -2892,  2026, -2892,  2921,  5338,  7998,    53,   897, -2892, -2892,
   -2892,  1975, -2892, -2892, -2892, -2892, -2892, -2892,    66,  3269,
      66,  3269, -2892, -2892, -2892, -2892, -2892, -2892,   -31, -2892,
    1122,  1173,  5541, -2892,  2204,  2170,  9984, -2892,   119,   119,
   -2892, -2892, -2892, -2892,   495, -2892,  2132, -2892,   122,   -15,
   -2892,  1979, -2892,   499, -2892, -2892,  2651, -2892, -2892,  2060,
   -2892,  2653,  2437,  2437,  2437,  2437,   122,   122, -2892, -2892,
   -2892, -2892, -2892, -2892,  2651,  1983,   356, -2892,  2574, -2892,
   -2892,   333,  1041,  1041, -2892, -2892,  1041,  2398,  1987, -2892,
     522, -2892,  2219,  2220, -2892, -2892,  2637,  2221,  1992,  1554,
    1994,  1995, -2892, -2892, -2892, -2892, -2892, -2892, -2892,   500,
   -2892, -2892, -2892,   223,   230, -2892,  9533,  9533, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892,  9695,  9695,  2190,
    9695,  2191, -2892,  9695,   606,  9984,  2671, -2892, -2892,  9533,
   -2892, -2892, -2892, -2892, -2892,  2672, -2892,   458, -2892, -2892,
    2274,  2003,  2004, -2892, -2892,   104,   104,   104,  2656,   104,
     104,   104,   104,   104,   104,  2657, -2892,  2661,   104, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892,  5713, -2892,   356,
    2018, -2892,  2197,  2398,  2664, -2892,  2667,  2673,  2678,  2679,
    2683,  2686,  1220,  2206, -2892,  2197, -2892, -2892,  2687, -2892,
    2349,   122,  1460,   122, -2892, -2892,  2218, -2892, -2892, -2892,
   -2892,  2271,  2272,   516,  1554,  2689,  1554, -2892,  2713,   526,
    2276,  2278,  2713, -2892, -2892, -2892, -2892,  1536, -2892, -2892,
   -2892,  2237, -2892, -2892,   843, -2892,  2218, -2892, -2892,   333,
     333, -2892, -2892,   333,  -288, -2892,   577,    62,  2247, -2892,
    2205,    62,   401,  1097, -2892,  2722,  2243, -2892, -2892,  2283,
    2128, -2892, -2892,   333,  1307,  2921,  1470,   333,  1307, -2892,
   -2892,    66, -2892, -2892,  5583, -2892, -2892,   218, -2892, -2892,
   -2892,  1097,  2724, -2892,    66,  2247,   356,  2441, -2892,  2704,
    1832,  9122,  2711, -2892, -2892,   178,  2257, -2892, -2892,  3924,
   -2892, -2892,  2292, -2892, -2892, -2892,   589, -2892,  1832, -2892,
    5583, -2892,   313, -2892,  2138, -2892, -2892, -2892, -2892,  2249,
    2340, -2892,  2723, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892,   333, -2892,   133, -2892, -2892, -2892,
     122, -2892,   248,  2547,   531, -2892, -2892, -2892, -2892,   333,
     122, -2892,   131,   131,  2140,  3682,  3682, -2892, -2892,  3969,
    2258, -2892, -2892,  2265,  2266, -2892,  2267,  2269,  2275,  2277,
     333,   676, -2892, -2892, -2892, -2892,   533, -2892, -2892,  2380,
   -2892, -2892, -2892,   534,  2748,  2748, -2892, -2892,   535,  2749,
    2746, -2892,   109,   356,   131, -2892, -2892, -2892, -2892, -2892,
    2497,  5802,  1311,  1754,  1311,  1311,  2317, -2892,  1554,  2318,
    1554,  1554,   241, -2892, -2892,  2587, -2892,  2279,  2110,  2279,
     184, -2892,  2279,   184, -2892,  2279,  9695, -2892, -2892,  9984,
   -2892,  9984,  2584,   152, -2892, -2892, -2892, -2892,  1554, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892,   475,  2759, -2892,   356,  1915, -2892,
    2497, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892,   319, -2892, -2892, -2892,  2255, -2892, -2892, -2892,
   -2892,  2744, -2892, -2892,  2328, -2892,  2750,  2329,  2751, -2892,
   -2892, -2892,  2330, -2892,  2297,  9533, -2892, -2892, -2892, -2892,
   -2892,   333,  2754, -2892,  -288, -2892, -2892,  2755, -2892, -2892,
    2756,   333,  2274,    62, -2892,    66,   -31, -2892,  2355,  1097,
   -2892,  5583, -2892,  2165,  2763,   -31, -2892, -2892,   547, -2892,
   -2892, -2892, -2892,   185,  2345, -2892, -2892,  1097,  2164,  2553,
    2492, -2892,   -31,  2347,  2350,  2397,  2314, -2892,  2399,  2352,
   -2892, -2892, -2892, -2892,  2505,  2291,  5583,  2308, -2892, -2892,
   -2892,  1832, -2892,   542, -2892,   356,  2209, -2892, -2892, -2892,
    9984, -2892, -2892,   122, -2892,  2320, -2892, -2892, -2892,  2651,
    2209,  2068,  2068,  2367, 10045,   497,  4805,   497,   497,   497,
     497,   -37,  4805,  2437, -2892,  4805,  4805,  4805,  4805, -2892,
   -2892,   122,  2795,   122,  2437,   245,  9533, -2892,  2553,   101,
   -2892, -2892, -2892, -2892,  2371,  2372, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,   209, -2892, -2892,   544, -2892, -2892, -2892,
   -2892,   548, -2892,  2279,  2811, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892,   356,  2759, -2892, -2892, -2892,   356, -2892,   356,
   -2892, -2892,  1809, -2892,  2527, -2892,  2528,  2796, -2892, -2892,
    2376,  2148, -2892, -2892, -2892,  2378, -2892,   122,   247, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
    1097, -2892,  2383, 10164,  2343, -2892, -2892, -2892,  2156,   -31,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892,  2382,   178, -2892,
    2399,  2399,   589, -2892,  2921,  2208, -2892, -2892,   333, -2892,
    2553,   591,   102, -2892,  9877,   591, -2892,  2391,  4805, -2892,
     552,  4805,  4805,  4805,  4805,  2812,   333,   565, -2892, -2892,
   -2892, -2892, -2892, -2892,  2357, -2892, -2892, -2892,  2584, -2892,
     333, -2892,  1311,  1311, -2892, -2892, -2892,   259, -2892, -2892,
   -2892,  9984, -2892,  2177,  2177, -2892,  2177, -2892,  2177,  2177,
   -2892, -2892, -2892,  2359, -2892,  1554, -2892,   571, -2892,  1265,
   -2892, -2892,    58,    58,    58,    58,    58,    58, -2892,  2815,
   -2892,   573, -2892,  5583,  1478, -2892,    27,  2399,  3924,  2399,
    2397, -2892, -2892, -2892,  2548,   358, -2892,   -31, -2892, -2892,
   -2892, -2892,   574, -2892, -2892,  1285, -2892,  2401,  4805, -2892,
    2402,  2403,  2404,  2405,   360,  2333, -2892,  2437, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,  2177, -2892,  2177, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892,  1266, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, 10164, -2892,  2839,
   -2892, -2892, -2892, -2892,   917, -2892, -2892, -2892, -2892, -2892,
   -2892,    38, -2892,  9877, -2892,  1757, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892,  2825, -2892,  2827,   575, -2892, -2892,
    1350,  1350, -2892, -2892,  1350, -2892,  5583,   923, -2892, -2892,
    2409,    53, -2892,  2185,  2186,  2852, -2892,  2384,   361, -2892,
   -2892, -2892, -2892,  2413, -2892, -2892, -2892,   333,   333,  1757,
   -2892,  2833, -2892, -2892,   107,  2196, -2892, -2892,  2386, -2892,
     178, -2892,   333, -2892,  2397, -2892
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2892, -2892, -2892, -2892, -2892,    28, -2892,    86,  -166, -2892,
   -2892, -1129,  -568, -2892, -2892, -2109, -2892, -2892, -2892, -2892,
    -829, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2276, -2892,  -994, -2892,
    1885, -2892, -2892, -2892, -2892, -2892, -2892, -2892,   357, -2892,
   -2892, -2892, -2892,  1320, -2892,   677, -2892, -2892,   -35, -2892,
   -2892,  2843, -2892,  2842, -2892, -2892, -2892, -2892, -2892,   430,
      75, -2892,   429, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892,  -103,   959,   918, -2892, -2892,  2523,
      47, -2892,  2770, -2892, -2892,  2768, -2892,  2681, -2892, -2892,
   -2892, -2892, -2892,  2546,  2230,   851,  2538,  -509, -2892, -2892,
   -2892, -2892, -2892,   852,  -639, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,   650, -2892,  2669,  2360,  2685,    70,  2298,
   -2892,  -203,  1609, -2892,  2515, -2892, -2892, -2892, -2892,  2520,
   -2892, -2892, -2892, -2892,  -388, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,  2337, -2892,  2336, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -1355, -2892, -2892,  -782, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  -128, -2892,
   -2892,   813, -2892, -1102, -1161,   560, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,  1914, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892,  -586, -2892, -2892, -2892, -2892, -2892,  2107, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892,  -561, -2892,   -98, -2892,
   -2892, -2892, -2892,  2500, -2892, -2892,  -204, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  1656,
   -2892, -2892, -2892, -2892,   623, -2892, -2892, -2892, -2892, -2892,
   -2000, -2892, -2892,   617, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -1130,  -700,   485,   781, -2892,  -228,
    -550,   511, -1115,  1256, -2892,   440, -2892, -2446,    -3,  -579,
   -2892, -2892, -2346,   368,  1676, -2892, -2892, -2892,   658,  1028,
   -2892, -2892, -2892, -2892, -2892, -2892,    72, -2892,  -244, -2892,
    1027, -2892,   711, -2892,   398, -2892, -2892, -2892, -2892,  -808,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,   496, -2892,
   -2892, -1827, -2892,   695, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892,  1497, -2892, -2892, -2892, -2892, -2892, -2892,  -446, -2892,
   -2892, -2089, -2892, -2892, -2892, -2892,   610, -2256, -2892, -1123,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892,  2925, -2892, -2892, -2892,  2853,  2902,
   -2285, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  -366, -2892,
   -2892, -2892, -2892, -2892,  2905, -2892, -2892,  2924, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  2021,
   -2892, -2892, -2892, -2892, -2892,   754, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892,  -667,  2198, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,  2710, -2892, -2892,   -13, -2892,
   -2892,   750, -2892, -2892,  1395,  -186,  2632, -2892, -2892, -2892,
   -2892,   595, -2892, -1044,  1944,  1055, -1456,  1448, -2892,   759,
    1733,  -342,  -522, -2892,  2199,  1541, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892,  1479, -2892,  -768, -2892,
    -525, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  -731, -2892,
   -2892, -2892, -2892, -2892, -2892,   128, -2892, -1360,  1561,   657,
   -2892, -2892, -2892, -2892, -2892,   -57, -2892,  -513, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,  1458, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,  -514, -2892,   819,  2539, -2892, -2892,   -50,
   -2892,  -622, -2892, -2892,   -33,   279, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892,  1086, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  -102, -2892,
    -363,  -359, -2892, -2892,  -351, -2892, -2725, -2892,   -89,   576,
   -1359, -2892, -2892, -2892,   933, -2892, -2011, -2892, -2892, -2892,
   -2003, -2892, -2892, -2009, -2892, -2892, -2892, -2892, -2323, -2892,
     951,   625, -2892, -2892, -2892, -2892, -2892,   408, -2892, -2892,
   -2892, -2892, -2892, -2892,  -703, -2892, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,  -272, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892, -2892,
    1073, -2892,  1074, -2892,   394,   743, -2892, -2479,  -187, -2892,
   -2892, -2892, -2892, -2892, -2892,   -30, -2892, -2892,  -498, -2892,
    -950, -1333, -2892, -2892, -2892, -2892, -2892,   -62, -2892, -2892,
   -2892, -2892, -2892, -1969, -2892, -2892, -2892, -2892, -2892, -2892,
   -2436,   684, -2892, -2635,   764, -2892, -2892, -2345,    71,    68,
     338, -2892, -2197, -1925, -2892, -2892,  -237,  -559, -2892, -2892,
   -2892, -2892, -1944, -2892, -2892, -2892,   -32, -2892,   298, -1112,
   -2892,  -454,  -218,  1117,  -282, -1856,   323, -2892, -2354, -2892,
   -2892, -2892, -2892,  2440, -1232, -2319,  3043, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892,  -707, -2892, -2292, -2892,  1796,
   -2892, -2892,   659,   345, -2892, -2535,   346,  -148,   159,  -146,
   -1901, -2269,  1046,  -219,  -760, -1269, -2892,  1051, -2892, -2892,
   -2892,  1149,  -784, -2892, -2892,  -491,  1816, -2892,   755, -2892,
   -2892,   461,  -121, -2892, -2892, -2892, -2424,  -361, -1853, -2892,
   -1092, -2892, -2892, -2892, -2892,  1189, -2892, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892, -2845,  -374, -2892, -2835,
   -2891, -1618, -1515, -2892, -2892,  -362, -2892, -2892, -2892,   280,
   -1069,  1058,  -733,  1984,  1645,  1648, -1294, -2892, -2892,   285,
     637,    69, -2892, -2892, -2892, -2892,  1669, -2892, -2892, -2892,
   -2892, -2892, -2892, -2892, -2892, -2892,  -308,  1328,  2561, -2892,
   -2892, -2892, -2892
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2259
static const short yytable[] =
{
      34,    36,    38,   326,   268,    38,   568,   183,  1357,  2147,
      86,  1405,  1522,  1182,  1473,  1474,  1005,  1475,  1466,  1496,
    1497,  2071,   235,  1989,  1990,  1494,   956,  1174,  1463,   960,
     681,   407,   408,  2452,  2737,  2284,  2947,    58,   425,  1514,
    2055,   102,   380,  2712,   296,  2714,  1122,   969,   577,   101,
    2091,    58,  2385,   993,  2735,    86,  2671,   409,   410,  2410,
    1462,   946,   108,  2100,  2409,  2337,  2338,  2339,  2340,   115,
    2847,  3237,   183,   120,  2222,  2223,   122,   123,  3233,  3234,
    3235,   126,   127,   951,  1467,    33,   423,  1092,    33,  2173,
      33,   183,    33,    33,    33,  2032,  1060,  2033,  2792,  2325,
      33,    58,  2802,  1036,  1905,    33,  3202,  2015,   593,  2600,
    1032,  1035,    33,  2878,    99,   594,   111,   588,   231,  1464,
    3128,   234,  1900,  3357,   589,  1036,   238,    33,   274,  1055,
    1056,  2638,   577,   364,   365,   411,  1910,  2584,  2015,   427,
    1067,   429,  1923,   430,   431,   432,    33,  1036,  1068,    33,
     577,  1068,   437, -2257,   511,  2924,   448,   449,    33,    99,
    2136,  1077,   324,   196,    33,  1068,   331,    33,  3167,  1068,
    1421,   274,   332,   333,   324,  1513,  1094,  1036,  2994,    33,
     324,  1068,  2966,  1077,  1901,  1085,  2136,    33,   329,  1106,
     577,   324,  1077,  1214,   254,  1127,  2461,  1435,  1130,  1116,
    3358,  3359,   274,  1226,  1227,    33,  1131,  1173,   274,  1295,
    1296,    33,   561,  1172,  1036,  1323,    33,    33,   274,   327,
     328,    33,   183,  2461,  1106,  1178,   183,    33,  1106,  2966,
     361,  1435,  1106,   274,  3073,  1296,   367,  1038,  1077,  2968,
    2969,  1077,  2970,  2971,  2972,  2973,  2974,  2975,   396,    33,
    2958,  2313,  2960,  2966,    58,   406,   406,   406,   406,   406,
    1132,  1515,  1516,   406,  1422,  1423,  1036,  1510,    33,  1064,
    1065,   254,    33,   357,   563,  3287,  2140,  2607,  2141,   571,
    2142,  2189,   349,   274,  1295,  1296,    33,  2968,  2969,  2604,
    2970,  2971,  2972,  2973,  2974,  2975,  1236,  3589,  3029,  2876,
    2646,    54,  2846,  2649,    33,   602,  3133,  1244,   605,  2892,
      58,    58,  3455,     4,   274,  1226,  1227,    33,   324,   579,
     513,  1114,  1927,  3769,  3507,   613,   614,   615,   616,   653,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633, -2257,  2963,   949,
     937,  2096,  2911,  1178,  1445,    33,  2363,   634,   635,  3360,
      33,  2452,   637,   324,   638,  3724,  3761,  2937,   577,   425,
    2912,  2913,  2914,  2915,  2916,  2233,  2159,   641,   642,   643,
     644,  1034,  1034,    33,   651,  3351,  1034,  1034,   521,  1178,
     577,    33,    33,  2165,   527,  1528,  1122,  1284,  2195,  1034,
     577,   597,  3074,    54,     6,  2672,  3368,   661,  1545,   664,
    2710,  3065,  1905,   950,  2806,  3115,  1281,   183,   666,  1034,
    2146,    54,  1034,  1282,   958,  1446,  1236,  1118,  1034,   670,
    2035,  2468,  1034,  1287,  3033,  2610,  1034,  2035,  1929,  3352,
    1034,  2040,   577,    54,  1034,  1034,   928,  1034,   573,   577,
    1034,  2678,  1034,  1034,  1034,  1503,  1504,  2014,  1373,  1374,
    1034,  2678,    48,  1034,  2733,    54,    33,  2383,  1004,   929,
    1034,  2469,     1,  3575,  2741,  2759,     2,  1034,   565,   580,
    1047,   183,  2761,  2822,  1034,  1453,  2882,   277,  1375,  1376,
    1377,  3053,  3053,  3053,  3093,  1034,  3096,  1236,  3096,  1034,
    3190,    58,  1118,  1034,  3200,  3262,  3770,  3192,  2238,  1034,
     833,   926,  1034,     7,  1108,  3196,  1550,  2728,  2731,  2731,
      54,  3331,  2731,  1031,   315,   316,   317,   318,   319,   112,
   -2257,  3338,  2611,    54,   673,  2976,  3423,   673,  3443,  3443,
    3451,  1031,  2001,   590,  1110,   673,  1101,  3558,    76,  3597,
    2364,  1935,  3578,  3597,  1172,    77,   183,  3658,  3222,  3222,
    3222,  3222,   396,  3586,   396,   315,   316,   317,   318,   319,
    3658,    54,  3134,   948,   406,  3116,  3051,   953,  3697,  3713,
    3443,   573,    44,  2976,  1500,  2793,  1169,  1170,  1239,  3155,
    1939,  1507,    27,  1428,   406,  2195,  3187,  3188,  1402,    54,
    1429,    78,    79,  2601,    33,  3066,  3583,    54,    54,    80,
    1468,  1906, -2257,  1906,   918,  1220,  3276,  3186,  1223,   959,
    1416,  3058,  2056,  2160,  1238,  2475,  2807,  1570,  1288,    33,
    3259, -2257,  1300,  3576,  2893,   325,  1391,  3526,    53,  2928,
      33,  1936,  2102,     1,  3282,  2905,  3168,   516,    26,  1031,
    1511,  2349,   562,  1003,  2117,  2977,  2978,  1300,  1392,  1936,
    1442,   972,  2196,  1469,  1358,    52,   967,  1529,  3264,  2462,
    2314,  2686,  2067,  3030,   673,  2326,  1920,  1131,  1172,    58,
      58,    58,  1023,    58,  1027,  1029,  3456,  1122,  1037,  1039,
    1040,  2886,  3618,  1045,  3392,  1029,  3385,  1109,  1048,  2016,
      58,  1512,  1235,  2977,  2978,    69,  2000,  1300,  2330,  1040,
    2979,  2071,  3402,  1201,   564,  1465,  2377,  1517,  1239,   572,
    1037,  1037,  1978,  2639,  3429,  1981,  1982,  2042,  1228,   595,
    1040,  1922,  3059,  3328,  2019,  3361,    58,  3415,   591,  2432,
    2723,  2433,    58,  1040,    58,  3333,  2538,  3335,    58,  2895,
    3088,    58,  2174,  1095,    58,  1520,  3087,  2534,  2979,  2904,
    2103,  1029,  2723,  3347,    58,  3459,  1971,  3376,  3590,   406,
    1112,  3381,  1037,  3182,   295,   973,  1119,  1470,   403,    58,
     952,  3561,   403,   403,  2723,    58,  3374,   406,   406,  1239,
    2477,  3405,    58,    58,    58,  3565,  1086,  3508,  1195,  1436,
    1424,  1202,   403,  2291,  1518,  3449,    58,  2344,   578,   566,
    1571,   279,  2157,  1215,  2723,  1215,   406,   295,  1215,   406,
    1991,  1215,    58,  2143,   103,  1034,  3472,  2781,  1229,  3369,
     583,  2144,  3727,  1461,   282,  2623,  3710,  2980,  3725,  3762,
     584,   598,  1283,  1031,  2624,  2511,  1179,   662,   295,   665,
    2592,  3222,  3222,  2998,   295,  3222,    54,  1378,   667,  2196,
     668,  1976,  1344,    81,   295,  1344,  1049,    33,  2625,   671,
    2036,  2626,  1979,   651,   651,  2046, -2257,  2037,  2538,   295,
     100,  2041,  2497,    33,   974,  2980,  1970,  2627,  2047,  2498,
     153,  2679,    33, -2257, -2257, -2257, -2257, -2257,    26,    27,
    2046,  2685,     4,  2981,  2734,  1992,  2917,  2739,  3277,    33,
    2331,  1236,  2654,  2047,  2742,  2760,  3478,   288,  2533,  3478,
     159,  1993,  2762,  2823,   110,  1264,  2883,  3650,    43,   295,
   -2257,  3054,  3055,  3057,  3094,   112,  3097,  2657,  3101,  3469,
    3191,  3470,  3471,  1379,  3201,  3263,  2087,  1034,  1034,  1034,
   -2257,  2981,   116,  2982,  2983,  2092,    33,  3129,    82,    10,
     295,  3332,  2253,  2254,  1994,  3557,   114,  3252,  3110,  3487,
    1253,  3339,  1316,  2200,    43,    10,  3424,  2352,  3444,  3450,
    3452,  1254,  2115,  1237,  1278,   190,  1380,  3559,  2518,  3598,
    2048,  2628,   522,  3599,  2182,  2161,    33,  3659,  2163,    33,
    3518,  2982,  2983,  1995,   532, -2257,  1572,  3449,  3449,   291,
    3666,  1024,  1368,    33,   673,  2048,  3682,  2171,  3698,  3714,
    3749,   292,   293,     5,  2332,  3538,  3649,  1238,  2484,   294,
    3655,  1255,  1996,   315,   316,   317,   318,   319,  3091,  1573,
    1186,  1997,  3195,   232,  2629,  1256,  3278,  3284,  3279,  1037,
      83,  2630,    58,  3269,  3075,  3272,  1977,  1361,  3275,  3224,
    3224,  3224,  3224,  2445,  3489,  2446,  2776,  1980,    58,  2467,
    2776,  1037,  3475,   934,  1117,  3480,    33,  1974,  3482,  2445,
    2192,  2446,  3222,    54,  2061,  2826,    33,  3092,  3222,  3222,
    1187,  3222,  3222,  3222,  3222,  2673,  3285,   189,  2521,    54,
    3222,  1451,     7,    33,  2050,   935,  2803,  2655,    54,   610,
      58,  3588,   368,  3490,  1397,  1119,   412,   413,   414,  3595,
    2051,    53,  1178,    33,    33,    54,  1119,  1188,   193,  2050,
      84,     8,  2658,  2333,  1257,   678,  1398,   240,    85,   369,
      58,    58,    58,   932,    58,  2051,    58,    58,  3178,    33,
     233,  3562,    58,    58,  3076,   242,  2353,  2590,  3442,  2746,
    2747,  2006,  3253,  2007,  2008, -2257,  1555,  2354,    33,  2447,
     249,  2631,  2448,  1916,   250,    33,    58,   466,   467,   468,
     469,   470,   471,   472,   473,  2447,  1453,  1543,  2448,    58,
     252,  2503,  3077,   567,  2233,  3324,   253,  3327,  1554,  3180,
      33,    58,  1100,  1239,  1510,   256,  1562,  2478,  2046,   474,
    2233,  1107,    54,  1110,  3222,    54,   107,  3222,  3222,  3222,
    3222,  2047,   257,    33,  1189,    58,    58,  2046,   258,    54,
    2097,   474,    33,   259,    58,  2118,  2753,  2754,  2755,  3157,
    2047,    33,  2328,  3478,  2335,  3318,  2134,    33,   260,  3048,
      58,    58,  3738,    33,  2335,  1323,  3078,  1218, -2257,  2255,
    1221,  2358,  2359,  2360,  2361,  2233,  2043,   104,   105,  2045,
    3079, -2257,  1018,   415,  3641,  3642,  1973,   261,   416,  1062,
     418,  1393,  1394,  1240,  1241,  1242,  3600,  2130,  2650,  1316,
    1316,  3420,  1118,   166,  1243,   991,  3681,  1476,   994,  1316,
     262,  1190,    54,  1078,  3222,   167,   475,   476,   477,   478,
     479,   480,  2013,  3222,  1200,    37,   425,    33,  1206,  1118,
    2020,   263,  1210,  2048,   481,   482,   483,  2238,   475,   476,
     477,   478,   479,   480,  3419,  2179,  2180,  2046,   321,    54,
      54,  1191,  2048,  2238,  3427,   928,   481,   482,   483,  1167,
    2047,  3483,  3224,  3224,   264,   183,  3224,  2310, -2257,  1184,
     265,  3706,  1199,  3708,    33,    54,  1205,  1266,   929,  1054,
    3080,  2057,  1211,   266,  1213,  2062,  2068,  2062,   267,  1397,
   -2257, -2257,  2080,   269,    54,   322,  3081,  2074,  2076,  2077,
    1072,    54,    58,  2081,  2083,  2084,  2085,  1037,  2238,  2502,
    3056,  1398,  2071,  1081, -2257,  1122,  1037,  1192,   309, -1629,
    2860,  2070,   104,   105,   310,  2315,    54,  1119,  2317,    58,
   -2257,    58,     1,    58,    58,  2732,     2,  2998,  2736,  2756,
     311,    58,    58,  1037,  2818,    58,   406,  2050,   406,    58,
    2948,  2299,  2950,  2524,  2951,   312,   173,  1119,    54,  2532,
      33,  3122,  2048,  2051,  2133,  1119,  2050,    54,    33,   353,
     428,    58,    58,    54,   484,   313,  2589,   485,   360,  2299,
     174,  2261,  2051,  2262,  2263,   323,  1219,  2265,  2266,  1222,
    3325,   314,  1225,  2285,   344,  1070,   484,    33,  2602,   485,
    3379,  3568,  2897,  3571,  3572,  3573,  3574,    33,  3700,  1079,
     345,   130,  1477,  1084,  2426,    33,    58,    58,   961,    58,
     962,   346,    58,    58,   175,  1098,   350,   965,  2923,   966,
       3,  2049,   371,   176, -2257, -2257, -2257,  1547, -2257, -2257,
    3689,   336,   337,   338,  2177,   351,   406,   406,  1259,  1260,
     131,   406,  1028,    58,    33,  2186,  2187,  3702,  2457,  2204,
     105, -2257,  2493,   355,   104,   105,  3683,  3732,   390,   132,
     133,  1036,  2348,    33,   415,  1323,  2050,  3563,    58,   416,
     417,   418,   359, -2257,  2677,  2294,  2295,  2680,  2681,  2682,
    2683,   362,  2051,  3224,  2300,  2458,  2459,   486,  -282,  3224,
    3224,  3433,  3224,  3224,  3224,  3224,  1240,  1241,  3689,   134,
     366,  3224,   487,  2301,  2302,   391,   488,   177,   178,   486,
     372,   135,  2300,  2233,  2233,  3702,   381,  1548,  3232,  3232,
    3232,  3232,   136,  2303,   487,  3715,  3716,  1413,   488,  1478,
   -2257,  2301,  2302, -2257,   397,  1479,  1480,  1481,   137,  3071,
    3072, -2257,   489,  1406,  1407,  1408,  2782,  1451,   138,    33,
    2783,  2303,  1541,  2490,    33, -2257,  1983,  1482,  1984,  2794,
    1986,  2728,  1987,   139,   489,  2272,   400,  3684,  3684,   435,
     490,  3685,  3685,  -282,  1131,  3098,  2273,  2075,   401,    33,
    3389,     4,   433,  2464,  2815,  2078,   436,    33,   491,  -282,
    3431,  3432,   490,  3164,  2218,  2219,   457,  2274, -2257,  3138,
    2082,   447,    33,   140,  2275,   450,   451,  1172,  3268,  3268,
     491,  3268,  2276,   453,  3268,  3224, -2257,  3135,  3224,  3224,
    3224,  3224,  2318,  2322,  2319,  2323,   141,  2023,  2024,   454,
     455,   373,  -282,  1167,  2277, -2257, -2257,  3356,  2765,   456,
      33,   142,  2768,  1530,    33,  1536,  2238,  2238,   143,  3177,
     504,   144, -2257,  2656,  2151, -2257, -2257,   517,   519,  2661,
    2662,   515,  1483,  1501,  1502,  1484,   524,  1505,  1506,   492,
     525,  -282,   145,  1485,   526,  2942,   146,  2943,  3464,   382,
    3465,   528,  3743,   438,    33,   529,   533,  3458, -2257,   534,
    2098,   492,  2098,   535,   538,   147,  1523,  1524,  1525,  1526,
    -282,   539,     5, -2257,   549,  3224,   550,   551,  1486,  -282,
    2609,   554,   559,   148,  3224,   570,   374,   569,  3569,  1034,
    3225,  3225,  3225,  3225,  3569,   575,   576,  3579,  3580,  3581,
    3582, -2257,   375,   606,   581,   493,  3143,   603,   582,   586,
    2777,   587,   596,  1487,  3151,  3152,   607,   608,   611,   636,
       6,  2025,  2026,  2027,  2028,  2029,  2030,   493,   639,   645,
     646,  1323,  1488,  1489,   383,  2307,   652,   330,   439,   655,
     654,   335,   656,  1490,   658,   376,   657,   659,  1491,   660,
     384,     7,  1991,   663,   440,   315,   316,   317,   318,   319,
    2348,   669,   679,  2819,  1215,   406,   406,   933,     1,   938,
     940,    58,    58,   964,   941,   942,   947,  2366,   957,   963,
       8,  3232,  3232,   971,   377,  3232,   976,  1492,  2953,   978,
     980,  2257,  1037,   385,  1037,  1037,   999,   441,  1037,  1037,
     981,  2267,   982,  2964,  1037,  1001,  1006,  1007,  1009,  1010,
    2476,  2371,  2854,   378,  2988,  1034,  1011,  1012,  1014,  1493,
    3657,  1044,   379,  3660,  3661,  3662,  3663,  1015,    58,  3560,
    1016,  1017,   386,  1053,  1019,  1129,   442,  1992,  1207,  2311,
    1268,  1269,  1270,  1271,  2663,  1272,  3479,  1274,  1034,  3479,
    1273,  2269,  1275,  1993,  1276,  1277,  2115,  1279,  2104,  2105,
    2106,   387,  1073,  1280,  1285,   443,  1286,  3102,  3495,  1316,
     388,  1316,  2547,  2549,   444,  2124,  1289,  3268,  1090,  1091,
    1290,  1316,  1316,  1037,  1097,  1334,  2357,  1099,  1316,  1316,
    1316,  1316,  1131,  1291,  1341,  1342,  1994,  1343,  1172,  3494,
    1346,  1119,  3132,  1347,  1349,  1350,  1351,  1352,  2489,  1353,
    3719,  2559,  1354,   467,   468,   469,   470,   471,   472,   473,
    1355,  1359,  1360,  2057,  1172,  1364,  1365,   651,  2062,  2664,
    3496,  1366,  3497,  1333,  2068,  1995,  1335,  2062,  1336,  1337,
    1338,  1339,  1340,  2158,   474,  2665,  1367,  1390,  3498,  1371,
    1395,  1396,  1399,  1400,  1401,  2424,  3499,  1361,  3447,  3448,
    3500,  2428,  1530,  2939,  1996,  2532,  2941,  1403,  2944,  2945,
    1409,  3395,  1420,  1997,  3495,  1427,  1426,  1430,  1431,  1433,
    2188,  1434,  1438,  3225,  3225,  3501,  1450,  3225,  2666,  1439,
    2455,  2203,  1453,  1455,  1441,  1458,  1323,  1457,  2021,  2022,
    2023,  2024,  1508,  1498,  1037,  1119,  2885,  1509,  2471,  2472,
    2330,   406,  3232,  1513,  1537,  1538,  1539,  1549,  3232,  3232,
    1540,  3232,  3232,  3232,  3232,  3397,    58,  2667,  1550,  1544,
    3232,  1546,  1559,  1561,  1896,  2909,  3496,  1897,  3497,   577,
    1898,   475,   476,   477,   478,   479,   480,  1904,  2500,  1908,
      58,  2925,  1899,  1911,  3498,  1912,  2668,  1913,  1914,   481,
     482,   483,  3499,  1961,  2270,  2669,  3500,  1969,  1975,  1985,
    2002,    58,  2003,  2525,  1562,  2004,  1316,  1972,  2271,  1119,
      58,  2005,  2025,  2026,  2027,  2028,  2029,  2030,  2009,  2010,
    2011,  3501,  2034,  2012,  2039,  3280,  2060,   406,   406,  2073,
    2088,  2089,  2348,  2093,  2348,  2090,  2094,  3529,  2095,  1421,
    2109,  2116,   406,  1520,  2123,  2125,  3537,    58,    58,    58,
    2127,  2272,  2136,    58,  2025,  2026,  2027,  2028,  2029,  2030,
    2138,  1037,  2273,  3543,  2149,  2166,  2168,  2150,  2169,  2178,
    2181,  2192,  2183,  2206,  3232,  2207,  2199,  3232,  3232,  3232,
    3232,  2209,  1906,  2274,  2224,  2225,  2226,  2245,    58,  2227,
    2275,  2228,  2229,  1034,  2247,  2130,  2645,  2645,  2276,  1034,
    2645,  2201,  2248,  3479,  2250,  2256,  2308,  2312,  2316,  1131,
    1131,  2320,  2000,  2324,  2321,  2326,  2341,  2362,  2373,  3370,
    2277,  2367,  1316,  2349,  2374,  1034,  2375,  2378,  2380,   484,
    2383,  1316,   485,  2379,  1316,  1316,  1316,  1316,  2684,  2412,
    3587,  1037,  2414,  2415,  3225,  2689,  1316,  3386,  2416,  2707,
    3225,  3225,  2418,  3225,  3225,  3225,  3225,  2421,  2417,  2430,
    2464,  2419,  3225,   183,  3232,  2434, -2257,  2435,  2436,  2437,
    2724,  2724,  2724,  3232,  2440,  2724,  1316,  2738,  2443,  2441,
    2057,  2442,  2438,  3290,  3291,  3292,  2444,  3294,  3295,  3296,
    3297,  3298,  3299,  1057,  1057,  2456,  3302,  2278,  3445,  3446,
    3447,  3448,  1905,  2279,  2479,  2481,  2486,  2482,  2488,  2763,
    3635,  2764,  2766,  2491,  2767,  2769, -2257,  2495,  2771,  3034,
    2496,  2501,  2062,  2504,  2508,  2505,  2062,    58, -2257,  2514,
   -2257,    58,  2528,  2538,  3035,  3036,  1243,  1037,  2724,  2522,
      58,  2455,  2588,  3037,  2799,  2799, -2257,  2587,  2599,  2540,
    2614,  2605,   486,  2615, -2257,  3205,  3206,  2613, -2257,  2619,
    2618,   274,  1295,  1296,    33,    58,  2620,   487,  2634, -2257,
    2635,   488,  2817,  1297,  1298,    58,  3225,  3038,  2642,  3225,
    3225,  3225,  3225, -2257,    58,  2653,  3039,  2659,    58,  2660,
    2674,  1057,  3690,  3691,  3692,  3693,  3694,  3695,  2675,  2676,
    2688,  1230,  2704,  2709,  3640,  2711,  2713,   489,  2715,  2716,
    2720,  2743,  2774,    58,  2744,  3040,  2790,  2745,  3712,  3484,
    2748,  2988,  2749,  2750,  2025,  2026,  2027,  2028,  2029,  2030,
    2751,  2752,  2810,  2812,  2779,   490,  2814,  2861,  2816,  2820,
    2828,  2808,  2813,  2829,  2831,  2832,  2962,  2833,  2965,  2835,
   -2257,  2834,  2852,   491,  3207,  2836,  2853,  2855,  1510,  1242,
    3041,  2859,  2868,  2870,  2230,  2879,  3225,  2231,  2880,  2232,
    2881,  2884,  2888,  2889,  2896,  3225,  2898,  2921,  2926,  2931,
    1034,  1034,  2949,  2946,  2952,  3531,  2940,  1037,  2954,  2233,
    2966,  2989,  2955,  1967,  2967,  2992,  2956,  2957,  3001,  2234,
    3050,  3051,  2724,  3541,  3042,  3060,  3052,  3063,  3064,  3067,
    2900,  2267,  2724,  3099,  3069,  2257,  1037,   926,  1316,  3070,
    2235,  3089,  3090,  3344,  3100,  3103,  3105,  3106,  3113,  3117,
    3121,  2257,  1037,  3124,   492,    58,  2645,  3131,  3142,  3150,
    3173,  3139,  3175,  2236,  3707,  3172,  2130,  2237,  3160,  3183,
    3488,  1317,  3184,  1413,  3192,  3199,  3202,  3203,  2015,  3244,
    1323,  3251, -2257,  3256,  3254,  3255,  3257,  3162,  3258,  2439,
    3260,  3261,  3270,  3273,  2328,  1316,  3281,  3283,  3289,  3288,
    1118,  3293,  3300,  1037,   926,  1037,  3301,  3307,  1316,  3311,
    1316,  3463,  3312,  3466,  3467,  3308,  2463,  3141,  3077,  3313,
     493,  1316,   651,  2106,  3314,  3315,  2724,    58,  2707,  3316,
     651,   651,  3317,  3322,   183,  3334,  3329,  3330,  3336,  3345,
    2724,  3340,  2238,  3341,  3365,  3372,  3774,  3371,  3373,  3374,
    3391,  1230,  3387,  1530, -2257,  3396,  3393,  3400,  2062,  1237,
    3434,  3408,  3421,  3411,  3415,  1476,  3620,  3435,  3436,  3437,
      63,  3438,  2510,  3443,  3453,   183,  2068,  3439,  2062,  3440,
    3454,  3460,  3468, -1810,  3492,  3048,  3223,  3223,  3223,  3223,
    3510,  2424,  3473,  3511,  3514,  3516,  3512,  3515,    58,  3517,
    3521,  3523,  3524,  3530,  3534,  3542,  2224,  2225,  2226,  3536,
    3540,  2227,  3544,  2228,  2229,  3545,  3546,  3550,  3548, -2257,
   -2257,  3554,  3564,  2455,  3654,  3123,  2016,  3125,  2348,  3584,
    2724,  1037,  3566,    58,   154,   186,  3592,  3593,  3601,  3611,
    3612,  3614,  3613,  3616,  3615,  3633,  3634,  3639,    58,  3621,
      58,  3147,    58,  3271,  3646,  3274,  3656,  3680,  3664,  3667,
    3696,  3672,  3709,  3726,  3736,    58,  3718,  3720,  3721,  3722,
    3723,  3747,  1316,  3748,  3755,  3757,  3758,  3759,  3763,  3768,
    3095,  3146,  3760,  3462,  3773,   406,  3772,   406,  3735,  2844,
    2513,  2191,    49,    50,  2795,   530,  1172,    58,    58,  2804,
     186,  3120,   192,  1316,   197,  1300,  1356,   343,  1008,   523,
    2368,   531,  2369,   356,   672,  2724,   348,   558,   970,   186,
    1988,   556,   943,   944,  1230,  3733,  2427,  1348,  1194,  3221,
    3221,  3221,  3221,  2724,  2724,   592,  3208,  3383,  1965,  3209,
    2643,  2651,  2786,    58,  2473,  2217,  3410,  2221,  3246,  3171,
    3388,  2537,  3210,  3756,  2858,  2557,  2791,  3539,  2120,   156,
     157,    46,    60,   128,  3505,    61,    47,   158,    33,  3378,
    1477,  1267,  2520,  3654,  2523,  1096,   514,  2205,  2156,   159,
    2244,  1370,  1902,  1316,  1316,  3493,  2527,   402,  1317,  1317,
    3602,  3211,  3212,  3739,  1316,  1316,  2111,  1316,  1317,  2770,
    1316,  1128,  1316,  3166,  3213,  2101,  1316,  2154,  3321,  3610,
    2172,   612,  2492,  3320,  3303,  2784,  2785,  2106,  2788,  3367,
    3527,  3046,  3525,  3522,  3350,  2780,  2413,  2382,  2740,  2890,
    3742,  3486,  2287,  2288,  2910,  3428,  2809,   183,  2617,  3617,
    3323,   651,  3346,   509,   510,  3214,    58,  2608,  2687,  2961,
     186,  3669,  3670,   160,   186,  3266,  3481,  3265,  3671,    58,
    3342,  2260,  3062,  3520,  3509,   161,  3047,   979,  2724,  3326,
    2724,    42,  3767,  3520,  1953,  2999,  3430,  3000,  3198,  3223,
    3223,  2343,  3485,  3223,  3215,  2342,  2230,  3648,  2252,  2231,
    1919,  2232,   162,  3567,  1037,  2902,  3216,  1478,  3426,  3585,
    3577,  2215,  2851,  1479,  1480,  1481,  3348,  3349,  3217,  3218,
    2771,  2233,  2365,  2062,  3130,  2129,  3219,  3127,  2811,  3220,
      58,  2234,  1452,     0,   680,  1482,  2135,   295,     0,  2119,
    2799,     0,     0,  3380,  2799,     0,     0,     0,   406,     0,
       0,     0,  2556,     0,     0,     0,     0,     0,    58,     0,
       0,   406,     0,    58,     0,     0,     0,  3528,     0,     0,
    1230,     0,    58,     0,     0,  2236,     0,  1034,     0,  2237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3412,     0,     0,  2919,     0,  2920,  2724,     0,     0,
       0,     0,     0,     0,     0,     0,  2900,  2724,     0,  2257,
    2257,     0,  3221,  3221,     0,     0,  3221,     0,     0,     0,
    1483,     0,     0,  1484,   640,     0,     0,  3441,     0,     0,
       0,  1485,     0,     0,  2238,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,  2257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1486,     0,     0,  1037,
       0,     0,     0,   164,     0,     0,     0,  1119,     0,     0,
    1119,     0,     0,  1316,     0,     0,  1316,     0,  1316,     0,
    2724,     0,     0,     0,     0,     0,     0,  2289,  2290,   186,
    3223,  1487,     0,     0,  2306,     0,  3223,  3223,   165,  3223,
    3223,  3223,  3223,     0,    58,     0,     0,     0,  3223,     0,
    1488,  1489, -2257, -2257, -2257,     0,     0, -2257,     0, -2257,
   -2257,  1490,     0,     0,     0,     0,  1491,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1316,     0,   167,     0,     0,  3104,     0,     0,
    3109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   406,     0,   186,  1492,    58,     0,  3645,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,  1020,  1021,  1022,   169,  1025,  1493,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,    58,  1051,  1167,     0,   171,  1316,     0,     0,
    2724,     0,  3223,     0,     0,  3223,  3223,  3223,  3223,     0,
       0,  1316,     0,  3221,     0,     0,     0,     0,     0,  3221,
    3221,     0,  3221,  3221,  3221,  3221,     0,     0,  2724,  1075,
    2724,  3221,     0,  1316,     0,  1080,   183,  1082,     0,     0,
     172,  1089,     0,     0,  1089,     0,     0,  1089,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,   173,     0,     0,     0,    58,
       0,     0,  1102,     0,    58,     0,    58,     0,  1163,     0,
       0,     0,     0,     0,  2494,  1025,  1176,  1180,     0,   174,
     651,  1196,  3223,     0,  2724,     0,     0,     0,     0,  1208,
       0,  3223,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,  1232,     0,     0,     0,     0,
       0,     0,     0,     0,  2535,    58,     0,     0,     0,     0,
       0,     0,     0,   175,     0,  3412,     0,     0,     0,     0,
       0,  1316,   176,     0,     0,  3221,     0,     0,  3221,  3221,
    3221,  3221,     0,  3665,     0,     0,     0,     0,     0,     0,
       0,  1230,     0,     0,     0,     0,     0,  3668,     0,     0,
       0,     0, -2257,     0,  1119, -2257,     0, -2257,  1316,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2257,     0,    58,
      58,    58,    58,    58,    58,     0,     0, -2257,     0,   474,
       0,  3701,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178, -2257,     0,
       0,     0,     0,     0,     0,  3221,     0,     0,     0,     0,
       0,   474,     0,     0,  3221,     0,     0,     0,     0,     0,
       0, -2257,     0,     0,     0, -2257,     0,     0,  1317,     0,
    1317,     0,     0,     0,  3384,     0,     0,     0,     0,     0,
    1317,  1317,     0,     0,     0,     0,     0,  1317,  1317,  1317,
    1317,     0,     0,     0,     0,     0,   274,  1295,  1296,    33,
    1316,     0,  3744,     0,     0,     0,     0,     0,  1297,  1298,
    3403,     0,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   481,   482,   483,     0,     0,     0,
   -2257,     0,     0,     0,  3765,  3766,  3744,     0,   475,   476,
     477,   478,   479,   480,     0,  1232,     0,    58,     0,  3775,
       0,     0,     0,     0,     0,     0,   481,   482,   483,     0,
       0,  1414,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2840,  2841,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2850,     0,     0,     0,     0,
    1057,     0,     0,  1472,  1472,  1472,     0,  1472,     0,  1472,
    1472,     0,     0,     0,     0,    63,    63,     0,     0,  2862,
    2863,  2864,  2865,  2866,  2867,     0,     0,     0,     0,  2872,
    2873,  2874,  2875,     0,   484,  1317,  2877,   485,     0,  1180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1557,     0,   484,     0,     0,   485,
       0,     0,     0,     0,     0,  1118,     0,     0,     0,     0,
       0,  3532, -2258,   271,     0,     0,     0,     0,  1232,  1414,
       0,     0,   272,   273,     0,     0,     0,  1909,   274,   275,
     276,    33, -2258, -2258, -2258,     0,     0, -2258,     0, -2258,
   -2258,     0,   159,  1917,  1917,     0,  3555,     0,  2929,  2930,
       0,     0,     0,     0,     0,  2934,  2935,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3205,  3206,     0,
       0,     0,     0,   274,  1295,  1296,    33,     0,     0,     0,
       0,  1317,     0,     0,     0,  1297,  1298,   486,     0,     0,
    1317,     0,     0,  1317,  1317,  1317,  1317,     0,     0,     0,
       0,     0,   487,     0, -2258,  1317,   488,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,     0,     0,   486,
       0,   277,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0, -2258,     0,   487,  1317,     0,     0,   488,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,  2386,     0,     0,     0,   162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3207,     0,     0,     0,
     490,     0,     0,     0,   489,     0,     0,     0, -2258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   490,     0,  3111,  3112, -2258,     0, -2258,     0,
    1300,     0,    63,  3119,    63,     0,  1180,  1089,     0,     0,
     491,     0,     0,     0,  2110,  1102,     0,     0,  1180,   471,
     472,   473,  2121, -2258,  1230,     0,     0,     0,     0,     0,
   -2258,  3208, -2258,   186,  3209,     0,     0,    54,     0,   163,
    3153,  3154,     0, -2258,  1232,  1163,   474,  3210, -2258,     0,
       0,     0,     0,     0,     0,     0, -2258,     0,     0,   492,
   -2258,     0,     0,  3699,     0,     0, -2258,  3174,     0,  3176,
   -2258, -2258, -2258, -2258,     0,     0,     0,     0,     0,     0,
       0,     0,  1118,     0,     0, -2258,     0,  3212,     0,  2155,
    1163,   492,    63,     0,     0,  2162,  2164,     0,     0,  3213,
       0,     0, -2258,     0,     0, -2258,     0, -2258,     0,     0,
       0,     0,     0,     0, -2258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,  2184, -2258,     0,     0,
    3247,  3248,     0,     0,  3249,  3250,   164, -2258,     0,     0,
    3214,   278,     0,   475,   476,   477,   478,   479,   480,     0,
       0,  2211,     0,     0,     0,     0,     0,   493, -2258, -2258,
       0,   481,   482,   483,     0,     0,  3753,  1317,     0,     0,
       0,   165,     0, -2258,     0,     0,     0,  2387,     0,  3215,
       0, -2258,     0,     0,     0, -2258,     0,     0,     0,     0,
       0,  3216,     0, -2258, -2258, -2258,     0,  2388,  2389,  2390,
       0,     0,     0,  3217,  3218,   166,     0,     0,     0,     0,
       0,  3219,     0,     0,  3220,     0,     0,   167,     0,     0,
    1924,     0,   295,     0,  1317,     0,     0,     0,     0,     0,
       0,  3310,     0,     0,     0,   279,  2391,  1317,     0,  1317,
     280,     0,   281,     0,     0,     0,     0,     0,  2392,     0,
    1317,     0,     0,   168,     0,     0,     0,     0,   282,  2393,
   -2258,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0, -2258,     0,   283,     0,  2394,   284,     0,     0,   285,
       0,     0,     0,     0,     0,  2395,     0,  1300,   286,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2396,   484,  1317,     0,   485,     0,     0,     0,     0,     0,
       0, -2258,  3377,     0,     0,     0,  3382,     0,  3208,     0,
       0,  3209,  1925,     0,     0,     0,     0,     0,   647,   287,
    1926,     0,     0,   172,  3210,  3390,  1927,     0,  1928,     0,
       0,   288,     0,     0,     0,     0,     0,     0,  2397,  1929,
       0,     0,   289,     0,  3401,     0,     0,     0,   173,     0,
       0,  2000,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2258,     0,  3212,     0,     0,  1930,  2398,     0,
       0,     0,   290,     0,     0,     0,  3213,     0,  2399,     0,
       0,     0,     0,  1931,     0,     0,     0,     0,  1932,     0,
       0,  1317,     0,     0,     0,     0,     0,     0, -2258,  2400,
    1933,     0,     0,  2401,     0,     0,     0,  1934,     0,     0,
       0,     0,     0,     0,   486,     0,   175,  3214,     0,     0,
       0,     0,  1317,   291,     0,   176,     0,     0,     0,   487,
       0,  2402,     0,   488,     0,   292,   293,     0,     0,     0,
    2403,     0,     0,   294, -2258,     0,     0,     0,  1317,  1317,
    1317,  1317,     0,     0,   295,     0,  3215,     0, -2258, -2258,
   -2258, -2258, -2258, -2258, -2258,     0, -2258, -2258,  3216,   489,
       0,     0,     0,     0,  2243,  1232,     0,     0,     0,     0,
    3217,  3218,     0, -2258,     0,     0,     0,     0,  3219,     0,
       0,  3220,     0,     0,     0,     0,     0,   490,     0,   295,
       0,     0,  1317,  1317,     0,     0,     0,     0,     0,   177,
     178,     0,     0,  1317,  1317,   491,  1317,     0,     0,  1317,
       0,  1317,     0,     0,     0,  1317,     0,     0,     0,     0,
       0,  2293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1057,  1057,  1057,     0,  1057,  1057,  1057,  1057,  1057,
    1057,     0,     0,     0,  1057,  1935,     0,     0,     0,     0,
    1936,     0,     0,     0,     0,     0,     0,  1937,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1938,
       0,     0,  3553,     0,  1939,  3556,   492,   271,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   273,     0,     0,
       0,     0,   274,   275,   276,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1230,     0,  3205,  3206,     0,     0,     0,     0,   274,
    1295,  1296,    33,     0,     0,     0,     0,     0,     0,     0,
     160,  1297,  1298,     0,     0,   277,     0,     0,     0,     0,
       0,     0,   161,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,  2485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
    3643,  1317,  1317,     0,     0,  1317,     0,     0,     0,     0,
       0,     0,   474,  1180,   458,   459,   460,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,  3207,  1163,     0,     0,     0,     0,     0,     0,
       0,  3673,  3674,     0,  3676,   474,  3678,  3679,     0,     0,
       0,     0,     0,     0,     0,     0,  1317,     0,     0,  1317,
       0,     0,  1317,     0,     0,  1317,     0,  1317,     0,     0,
    1180,  2591,  1180,     0,     0,     0,  1025,     0,     0,     0,
       0,    54,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   475,
     476,   477,   478,   479,   480,     0,     0,     0,     0,     0,
       0,  2637,     0,  3728,     0,  3729,     0,   481,   482,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1317,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,  3741,
       0,     0,     0,     0,     0,     0,     0,     0,  1118,     0,
     481,   482,   483,     0,     0,     0,     0,     0,  3750,  3751,
       0,     0,  3752,     0,     0,  3754,     0,     0,     0,     0,
     164,     0,     0,     0,   271,   278,     0,     0,     0,     0,
       0,     0,     0,   272,   273,     0,     0,     0,     0,   274,
     275,   276,    33,     0,     0,     0,  1317,     0,     0,     0,
       0,     0,     0,   159,     0,   165,     0,     0,     0,     0,
    1317,     0,  1317,     0,     0,     0,     0,     0,  1317,  1317,
       0,  1317,  1317,  1317,  1317,     0,     0,     0,     0,     0,
    1317,     0,  1317,     0,     0,     0,     0,     0,     0,   166,
    1180,     0,     0,     0,  1180,     0,     0,   484,     0,  1317,
     485,   167,     0,  1180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
       0,   186,     0,     0,   280,     0,   281,   160,  1180,     0,
       0,     0,   277,     0,     0,     0,     0,   168,  1232,   161,
     484,     0,   282,   485,     0,     0,     0,  2824,     0,     0,
       0,  2827,   169,     0,     0,     0,     0,   283,     0,     0,
     284,     0,     0,   285,     0,     0,   162,     0,     0,     0,
       0,     0,   286,   171,  1230,     0,  2849,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
    1317,     0,     0,   199,  1317,     0,     0,  1317,  1317,  1317,
    1317,     0,     0,  1300,     0,     0,     0,     0,     0,     0,
       0,     0,  1410,   287,     0,     0,     0,   172,     0,     0,
     486,     0,     0,  1317,     0,   288,     0,  1317,     0,     0,
       0,     0,     0,     0,  3208,   487,   289,  3209,     0,   488,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
    3210,     0,     0,     0,     0,     0,     0,     0,    54,     0,
     163,     0,     0,   486,     0,     0,   290,     0,     0,     0,
     200,     0,     0,     0,     0,   489,     0,     0,   487,     0,
       0,     0,   488,   585,  1317,     0,   201,   202,     0,     0,
    3212,     0,     0,  1317,     0,     0,   203,   271,  2927,     0,
       0,     0,  3213,   490,     0,     0,   272,   273,     0,     0,
     175,     0,   274,   275,   276,    33,     0,   291,   489,   176,
       0,   491,     0,     0,     0,     0,   159,     0,     0,   292,
     293,     0,     0,     0,     0,     0,     0,   294,     0,  1317,
       0,     0,     0,  3214,     0,     0,   490,     0,   295,     0,
       0,     0,     0,     0,     0,     0,     0,   164,  2691,     0,
       0,     0,   278,     0,   491,     0,     0,  1292,  1293,  1294,
    1180,     0,     0,   274,  1295,  1296,    33,     0,     0,     0,
       0,     0,  3215,     0,     0,  1297,  1298,     0,     0,     0,
       0,     0,   165,     0,  3216,   473,  1230,     0,     0,     0,
     160,     0,   492,   177,   178,   277,  3217,  3218,     0,     0,
       0,     0,   161,     0,  3219,     0,     0,  3220,     0,     0,
     474,     0,     0,     0,     0,   295,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   162,
       0,  1180,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,   280,     0,   281,     0,     0,  1299,   204,   493,     0,
       0,     0,   186,     0,   168,     0,  1180,     0,     0,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
       0,  3144,     0,  1051,   283,  3148,     0,   284,     0,     0,
     285,     0,     0,     0,     0,     0,   205,     0,  3159,   286,
     171,   493,     0,   186,     0,     0,     0,   475,   476,   477,
     478,   479,   480,     0,     0,   206,   207,   208,   209,     0,
       0,    54,     0,   163,     0,   481,   482,   483,     0,     0,
    3179,  3181,   271,   210,  2560,  2561,  2562,  2563,  2564,  2565,
     287,   272,   273,     0,   172,     0,     0,   274,   275,   276,
      33,     0,   288,     0,     0,   211,     0,     0,     0,     0,
       0,   159,     0,   289,     0,  2787,     0,   212,     0,   173,
       0,     0,     0,     0,     0,     0,  3245,     0,   213,     0,
       0,     0,  1118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   216,
     164,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,  2566,     0,     0,     0,   160,     0,   175,     0,     0,
     277,     0,     0,     0,   291,     0,   176,   161,     0,     0,
       0,     0,     0,     0,     0,   165,   292,   293,     0,   217,
       0,     0,     0,     0,   294,   484,     0,     0,   485,     0,
       0,     0,     0,     0,   162,   295,     0,     0,     0,  3304,
       0,     0,   218,     0,     0,     0,  2692,     0,     0,   166,
       0,     0,  3319,     0,     0,     0,     0,   219,     0,     0,
       0,   167,     0,     0,   220,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   280,     0,   281,     0,   222,     0,
     177,   178,   223,     0,     0,     0,     0,   168,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   169,  1180,     0,     0,     0,   283,     0,     0,
     284,     0,     0,   285,     0,   186,    54,     0,   163,   225,
       0,     0,   286,   171,     0,     0,     0,     0,     0,  3003,
    3004,  1180,  3005,  3006,  3007,     0,  1163,  1300,   486,     0,
       0,     0,     0,     0,     0,  1232,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,     0,   488,     0,     0,
       0,   226,  3163,   287,     0,     0,     0,   172,  1301,     0,
       0,  2693,     0,     0,     0,   288,     0,     0,     0,     0,
       0,     0,     0,  2694,  1303,     0,   289,     0,     0,     0,
       0,     0,   173,   489,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2000,     0,     0,     0,   164,   290,     0,  2567,     0,
     278,   490,     0,     0,  1304,     0,     0,     0,     0,     0,
       0,  2568,  3008,     0,     0,     0,  1305,     0,     0,   491,
    3009,     0,     0,  1163,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,   291,     0,   176,
       0,     0,     0,     0,  3010,     0,     0,  1306,     0,   292,
     293,     0,     0,  3011,   166,     0,     0,   294,     0,     0,
       0,     0,     0,  2569,     0,     0,   167,     0,   295,  2570,
       0,     0,     0,     0,     0,     0,     0,  3304,     0,     0,
    1307,     0,  3012,  3013,   279,     0,  1308,     0,     0,   280,
     492,   281,     0,     0,     0,  1309,  1310,     0,  1311,     0,
       0,     0,   168,     0,     0,     0,     0,   282,  2571,     0,
    1312,  1313,     0,     0,     0,     0,     0,   169,  1314,     0,
       0,  1315,   283,   177,   178,   284,     0,  3014,   285,   295,
       0,     0,  2572,     0,     0,     0,     0,   286,   171,  1180,
       0,     0,  2573,  2574,     0,     0,     0,     0,  2575,     0,
       0,     0,     0,     0,     0,     0,   493,  1180,  2576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3015,     0,     0,     0,   130,     0,     0,   287,     0,
    2577,     0,   172,  2578,  2579,  1163,     0,     0,  2580,     0,
     288,     0,     0,     0,     0,  1574,  1575,  1576,  1577,  1578,
    1579,   289,  1580,  1581,  1582,     0,     0,   173,  1583,  1584,
    1585,  1586,  1587,  1588,   131,     0,     0,     0,     0,     0,
       0,     0,     0,  1589,     0,  3016,     0,     0,     0,     0,
       0,   290,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2581,     0,     0,  1590,     0,
       0,     0,     0,     0,     0,     0,  2582,     0,     0,     0,
       0,     0,  3304,     0,     0,     0,     0,  3605,     0,  3607,
       0,     0,     0,   134,     0,   175,     0,     0,     0,     0,
       0,     0,   291,     0,   176,   135,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   136,     0,     0,     0,
    1180,     0,   294,     0,     0,  1591,     0,     0,     0,     0,
       0,     0,   137,   295,  1592,     0,     0,     0,  1232,     0,
       0,     0,   138,     0,   186,     0,     0,     0,     0,     0,
       0,     0,  1593,  1594,     0,     0,     0,   139,     0,     0,
       0,  1595,     0,     0,     0,     0,     0,     0,  1596,  1597,
       0,     0,  1598,  1599,  1600,  1601,     0,     0,  1602,  1603,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1472,  1472,  1472,  1472,  1472,  1472,  1604,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
    1605,     0,   143,     0,     0,   144,  1606,     0,     0,     0,
       0,     0,  2214,  1607,     0,  1608,     0,     0,     0,     0,
    1609,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,  3017,  3018,  3019,  3020,  3021,  3022,  3023,  3024,  3025,
    3026,     0,     0,     0,     0,     0,  1610,     0,     0,   147,
       0,     0,     0,  1292,  1293,  1294,     0,     0,     0,   274,
    1295,  1296,    33,     0,     0,     0,     0,   148,     0,     0,
       0,  1297,  1298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1611,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1612,     0,     0,
       0,     0,     0,  1613,     0,     0,     0,     0,     0,     0,
       0,     0,  1614,  1615,     0,     0,     0,     0,     0,  1616,
    1232,     0,  1617,  1618,     0,     0,     0,  1619,     0,     0,
       0,     0,     0,  1620,  1621,     0,     0,     0,     0,     0,
    1622,  1623,  1624,     0,     0,  1625,  1626,  1627,     0,     0,
       0,  1628,  1299,     0,     0,  1629,     0,  1630,     0,     0,
       0,     0,     0,     0,  1631,  1632,  1633,  1634,     0,  1635,
    1636,     0,     0,     0,  1637,  1638,     0,  1639,  1640,  1641,
    1642,  1643,  1644,  1645,     0,     0,     0,     0,     0,  1646,
    1647,  1648,     0,  1649,  1650,     0,     0,     0,  1651,  1652,
    1653,  1654,  1655,  1656,  1657,  1658,     0,  1659,     0,     0,
       0,  1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,
    1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,  1695,     0,  1696,  1697,
       0,     0,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,
    1706,  1707,     0,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1118,     0,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,     0,
    1732,  1733,  1734,  1735,     0,  1736,  1737,  1738,  1739,  1740,
    1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,
    1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,     0,  1772,  1773,  1774,  1775,  1776,  1777,     0,     0,
    1778,  1779,     0,  1780,  1781,  1782,  1783,  1784,  1785,  1786,
    1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,
    1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,     0,
       0,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,
    1825,  1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,
    1835,  1836,  1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,
    1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,
    1865,  1866,  1867,     0,     0,     0,     0,  1868,  1869,  1870,
    1871,  1872,  1873,  1874,  1875,  1876,  1877,  1878,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1879,     0,
       0,     0,     0,     0,     0,     0,  1880,     0,     0,     0,
       0,  1881,     0,     0,     0,  1882,     0,     0,  1883,  1884,
    1885,  1886,     0,  1300,  1887,  1888,     0,  1889,  1890,  1891,
    1574,  1575,  1576,  1577,  1578,  1579,     0,  1580,  1581,  1582,
       0,     0,     0,  1583,  1584,  1585,  1586,  1587,  1588,     0,
       0,     0,     0,     0,  1301,     0,     0,  1302,  1589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2000,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1591,     0,     0,     0,     0,     0,     0,     0,     0,  1592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1306,     0,     0,     0,  1593,  1594,     0,
       0,     0,     0,     0,     0,     0,  1595,     0,     0,     0,
       0,     0,     0,  1596,  1597,     0,     0,  1598,  1599,  1600,
    1601,     0,     0,  1602,  1603,     0,  1307,     0,     0,     0,
       0,     0,  1308,     0,     0,     0,     0,     0,     0,     0,
       0,  1309,  1310,     0,  1311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1312,  1313,     0,     0,
       0,     0,     0,  1604,  1314,     0,     0,  1315,     0,     0,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1605,     0,     0,     0,     0,
       0,  1606,     0,     0,     0,     0,     0,     0,  1607,     0,
    1608,     0,     0,     0,     0,  1609,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1610,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1611,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1612,     0,     0,     0,     0,     0,  1613,     0,
       0,     0,     0,     0,     0,     0,     0,  1614,  1615,     0,
       0,     0,     0,     0,  1616,     0,     0,  1617,  1618,     0,
       0,     0,  1619,     0,     0,     0,     0,     0,  1620,  1621,
       0,     0,     0,     0,     0,  1622,  1623,  1624,     0,     0,
    1625,  1626,  1627,     0,     0,     0,  1628,     0,     0,     0,
    1629,     0,  1630,     0,     0,     0,     0,     0,     0,  1631,
    1632,  1633,  1634,     0,  1635,  1636,     0,     0,     0,  1637,
    1638,     0,  1639,  1640,  1641,  1642,  1643,  1644,  1645,     0,
       0,     0,     0,     0,  1646,  1647,  1648,     0,  1649,  1650,
       0,     0,     0,  1651,  1652,  1653,  1654,  1655,  1656,  1657,
    1658,     0,  1659,     0,     0,     0,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,     0,  1696,  1697,     0,     0,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,     0,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,     0,     0,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,     0,  1732,  1733,  1734,  1735,     0,
    1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,     0,  1772,  1773,  1774,
    1775,  1776,  1777,     0,     0,  1778,  1779,     0,  1780,  1781,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,     0,     0,  1806,  1807,  1808,  1809,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,
    1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,     0,     0,
       0,     0,  1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,
    1876,  1877,  1878,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1879,     0,     0,     0,     0,     0,     0,
       0,  1880,     0,     0,     0,     0,  1881,     0,     0,     0,
    1882,     0,     0,  1883,  1884,  1885,  1886,     1,     0,  1887,
    1888,     2,  1889,  1890,  1891,     0,     0,   682,   683,   684,
       0,     0,     0,     0,     0,     0,   685,     0,     0,   686,
       0,     0,     0,     0,     0,     0,   687,   688,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,   690,     0,     0,     0,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   692,   693,     0,   694,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   695,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     696,     0,     0,   697,   698,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   699,     0,
     700,   701,   702,     0,     0,     0,     0,     0,     0,     0,
     703,   704,     0,   705,   706,   707,     0,     0,     0,     0,
       0,   708,     0,     0,   709,     0,   710,   711,   712,     0,
       0,     0,     0,     0,   713,     0,   714,   715,     0,   716,
       0,   717,   718,     0,     0,   719,     0,     0,   720,   721,
     722,   723,   724,   725,     0,     0,     0,   726,   727,   728,
       0,   729,     0,     0,     0,   730,     0,   731,   732,     0,
       0,     0,     0,   733,     0,     0,   734,     0,     0,   735,
       0,   736,     0,   737,     0,   738,     0,     0,     0,   739,
     740,     0,   741,   742,   743,     0,     0,   744,     0,   745,
     746,     0,   747,     0,     0,     0,     0,     0,     0,     0,
     748,   749,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   750,     0,     0,   751,   752,     0,     0,
     753,   754,     0,     0,   755,   756,     0,     0,     0,     0,
       0,     0,     0,   757,   758,   759,     0,   760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   761,   762,   763,
       0,   764,     0,     0,     0,   765,   766,     0,     0,     0,
     767,     0,     0,     0,     0,     0,     0,     0,   768,     0,
       0,     0,     0,     0,     0,     0,   769,   770,   771,     0,
       0,     0,     0,     0,   772,   773,     0,     0,     0,     0,
       0,     0,   774,     0,     0,   775,     0,     0,     0,   776,
     777,     0,     0,     0,     0,     0,   600,   458,   459,   460,
     778,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,   779,     0,     0,
       0,     0,     0,     0,     0,   780,     0,     0,     0,     0,
       0,   781,     0,     0,     0,     0,     0,     0,   474,     0,
       0,     0,   782,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   783,     0,     0,     0,     0,     0,
     784,     0,   785,   786,     0,     0,     0,     0,     0,     0,
     787,  2825,   458,   459,   460,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,  1292,  1293,  1294,     0,
       0,     0,   274,  1295,  1296,    33,     0,     0,     0,   788,
       0,     0,     0,   474,  1297,  1298,     0,     0,     0,     0,
     789,     0,     0,     0,     0,     0,     0,   790,     0,     0,
       0,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   791,   792,   481,   482,   483,   793,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   794,     0,
       0,     0,     0,     0,   795,   796,   797,   798,     0,     0,
       0,   799,     0,     0,     0,   800,     0,     0,     0,     0,
       0,     0,   801,   802,     0,  1299,     0,     0,     0,     0,
       0,     0,     0,   803,     0,   804,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,   805,     0,   806,     0,
       0,   807,     0,     0,     0,     0,     0,   808,   481,   482,
     483,     0,     0,     0,     0,     0,   458,   459,   460,     0,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   809,     0,     0,   810,     0,     0,     0,
       0,   811,     0,     0,   812,   813,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,     0,   814,
       0,     0,     0,     0,     0,     0,   815,     0,     0,     0,
       0,     0,     0,   484,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   816,
     817,   818,   819,   820,   821,   822,     0,     0,   823,     0,
     824,  1118,   825,   458,   459,   460,     0,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   458,   459,   460,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,   474,     0,     0,     0,   484,     0,
       0,   485,     0,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   459,   460,   486,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,   487,     0,     0,     0,   488,     0,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,     0,     0,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,     0,     0,     0,
       0,   489,     0,     0,     0,     0,     0,     0,   474,   481,
     482,   483,   475,   476,   477,   478,   479,   480,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,   490,
     481,   482,   483,     0,     0,     0,   487,     0,     0,     0,
     488,     0,     0,     0,     0,     0,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,  1300,     0,     0,     0,
       0,     0,   484,     0,     0,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,  1301,     0,     0,
    1302,     0,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,  1303,   490,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   491,   481,   482,   483,     0,     0,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2529,  1304,     0,     0,     0,     0,     0,   484,
       0,     0,   485,     0,     0,  1305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,   493,     0,  1306,     0,     0,     0,
     487,     0,     0,   492,   488,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1307,
       0,     0,     0,     0,     0,  1308,     0,     0,     0,   484,
     489,     0,   485,     0,  1309,  1310,     0,  1311,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1312,
    1313,     0,     0,   484,     0,     0,   485,  1314,   490,   493,
    1315,     0,   486,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,     0,   491,   487,     0,     0,
       0,   488,   609,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,   488,   977,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,   486,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,   491,     0,     0,   490,   487,     0,     0,
       0,   488,   983,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,   488,   984,     0,     0,     0,
       0,     0,     0,     0,   458,   459,   460,   489,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,   493,     0,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,   492,   474,     0,     0,     0,     0,
       0,     0,     0,   491,     0,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,   458,   459,   460,   491,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     493,     0,   458,   459,   460,   474,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,   493,     0,     0,   492,     0,     0,     0,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,     0,
       0,     0,     0,   474,     0,     0,     0,     0,   492,     0,
     481,   482,   483,     0,     0,     0,   458,   459,   460,     0,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     493,     0,     0,     0,     0,     0,     0,   474,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,     0,
       0,     0,     0,     0,   493,     0,     0,     0,     0,     0,
     481,   482,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   481,   482,
     483,     0,     0,     0,   458,   459,   460,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,   485,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,   481,   482,   483,     0,     0,     0,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     484,     0,     0,   485,     0,     0,     0,     0,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,   485,   475,   476,   477,   478,   479,   480,   474,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
     481,   482,   483,     0,     0,     0,     0,     0,   487,     0,
       0,     0,   488,   985,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,   484,     0,     0,   485,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,     0,     0,   489,     0,
       0,   474,     0,     0,   481,   482,   483,     0,     0,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   490,     0,   487,     0,
       0,     0,   488,   986,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,   486,     0,   481,   482,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,   489,     0,
     488,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,   485,     0,     0,   490,     0,   475,   476,
     477,   478,   479,   480,     0,   486,   489,     0,     0,     0,
       0,     0,     0,     0,   491,     0,   481,   482,   483,   988,
     487,     0,     0,     0,   488,   492,     0,     0,     0,     0,
       0,     0,     0,     0,   490,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,     0,     0,   485,     0,     0,
       0,     0,   491,     0,     0,     0,     0,     0,     0,     0,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   989,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,   490,     0,
       0,   493,     0,   484,     0,   492,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,     0,     0,     0,
     474,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,   488,   492,     0,     0,     0,     0,     0,     0,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,   484,     0,     0,   485,
       0,   493,  2691,     0,     0,     0,     0,   486,   489,     0,
       0,  1292,  1293,  1294,     0,   474,     0,   274,  1295,  1296,
      33,   992,   487,     0,     0,     0,   488,   492,     0,  1297,
    1298,     0,     0,     0,     0,     0,   490,     0,     0,   493,
       0,     0,     0,     0,     0,     0,     0,   475,   476,   477,
     478,   479,   480,     0,   491,     0,   486,     0,     0,     0,
       0,     0,   489,     0,     0,   481,   482,   483,     0,     0,
       0,   487,     0,     0,     0,   488,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     490,     0,     0,   493,     0,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,   491,     0,
    1299,   489,   475,   476,   477,   478,   479,   480,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     481,   482,   483,     0,   487,   492,     0,     0,   488,   490,
       0,     0,     0,     0,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1134,  1135,  1136,
    1137,     0,     0,     0,   489,  1294,     0,   474,     0,   274,
    1295,  1296,    33,     0,     0,     0,     0,     0,     0,   492,
       0,  1297,  1298,     0,     0,     0,     0,     0,     0,     0,
       0,   493,   490,     0,     0,   484,     0,     0,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,  1118,     0,   492,     0,
       0,     0,     0,     0,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,     0,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,  1299,   485,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1138,     0,   481,   482,   483,     0,     0,     0,  1139,     0,
       0,   492,     0,     0,   493,     0,     0,  1140,     0,     0,
    1141,  1292,  1293,  1294,     0,     0,     0,   274,  1295,  1296,
      33,     0,     0,     0,     0,     0,     0,     0,   486,  1297,
    1298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2692,     0,     0,   487,     0,     0,     0,   488,     0,     0,
       0,     0,     0,  1142,     0,  1292,  1293,  1294,     0,     0,
    1143,   274,  1295,  1296,    33,     0,     0,   493,     0,     0,
       0,     0,     0,  1297,  1298,     0,     0,     0,     0,     0,
       0,     0,     0,   489,   484,     0,     0,   485,     0,     0,
       0,     0,     0,   486,     0,     0,   987,     0,  1118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
    1299,   490,   488,     0,     0,     0,     0,  1144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   491,
       0,     0,   484,     0,     0,   485,     0,     0,     0,     0,
       0,  1300,  1145,     0,     0,     0,     0,     0,   489,  1146,
       0,  1147,     0,     0,  1299,     0,     0,     0,     0,     0,
       0,  1148,  1292,  1293,  1294,     0,     0,     0,   274,  1295,
    1296,    33,  1301,     0,     0,  2693,   490,     0,     0,     0,
    1297,  1298,     0,     0,     0,     0,     0,  2694,  1303,  1149,
       0,     0,     0,     0,   491,     0,     0,  1150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,     0,     0,
     492,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,  1292,  1293,  1294,   488,     0,  1304,   274,
    1295,  1296,    33,     0,  1151,     0,  1118,     0,     0,     0,
    1305,  1297,  1298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,  1152,     0,
       0,  1299,   489,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,   488,   492,   493,     0,     0,     0,
    1118,  1306,     0,     0,     0,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,  1153,     0,     0,     0,     0,
       0,     0,     0,  1300,     0,     0,  1154,     0,   491,     0,
     489,     0,     0,     0,  1307,     0,     0,     0,     0,     0,
    1308,     0,  1299,     0,     0,     0,     0,     0,     0,  1309,
    1310,     0,  1311,     0,  1301,     0,     0,  1302,   490,     0,
    2692,   493,     0,     0,  1312,  1313,     0,     0,     0,     0,
    1303,     0,  1314,     0,     0,  1315,   491,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2560,  2561,  2562,
    2563,  2564,  2565,     0,     0,     0,     0,  1118,     0,   492,
    1304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1305,     0,  1155,  1156,  1157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
       0,  1300,     0,  1306,     0,     0,     0,     0,  1118,     0,
       0,     0,     0,     0,     0,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1301,     0,  2566,  2693,  1307,     0,     0,     0,
       0,     0,  1308,     0,     0,  1300,     0,  2694,  1303,     0,
       0,  1309,  1310,     0,  1311,     0,     0,     0,     0,     0,
       0,     0,     0,   493,     0,     0,  1312,  1313,     0,     0,
       0,     0,     0,     0,  1314,     0,  1301,  1315,     0,  1302,
    1159,     0,     0,     0,     0,   295,     0,     0,  1304,     0,
       0,     0,  1303,     0,     0,     0,     0,     0,     0,     0,
    1305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3651,  1304,     0,     0,     0,     0,     0,     0,  3622,
       0,  1306,     0,     0,  1305,     0,     0,     0,     0,     0,
       0,     0,  1300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1307,     0,     0,     0,     0,     0,
    1308,     0,     0,  1301,     0,  1306,  1302,     0,     0,  1309,
    1310,     0,  1311,     0,     0,     0,  3623,     0,     0,  1303,
       0,     0,     0,     0,  1312,  1313,     0,     0,     0,     0,
       0,     0,  1314,  2327,     0,  1315,     0,     0,  1307,     0,
       0,  3624,     0,   295,  1308,     0,     0,     0,     0,     0,
    3625,     0,     0,  1309,  1310,     0,  1311,     0,     0,  1304,
       0,     0,     0,     0,  1301,     0,     0,  1302,  1312,  1313,
       0,  1305,     0,     0,     0,     0,  1314,     0,     0,  1315,
    1303,     0,     0,     0,     0,     0,     0,   295,  3626,     0,
       0,  2567,     0,     0,     0,     0,  3627,     0,     0,     0,
       0,     0,     0,     0,  2568,     0,     0,     0,     0,     0,
       0,     0,  1306,     0,     0,     0,     0,     0,     0,     0,
    1304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1307,     0,     0,     0,     0,
       0,  1308,     0,     0,     0,     0,     0,     0,     0,     0,
    1309,  1310,     0,  1311,     0,     0,  2569,     0,     0,     0,
       0,     0,  2570,  1306,     0,  1312,  1313,     0,     0,     0,
       0,     0,     0,  1314,     0,     0,  1315,  3628,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1307,     0,     0,     0,
       0,  2571,  1308,     0,     0,     0,     0,     0,     0,     0,
       0,  1309,  1310,     0,  1311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2572,  1312,  1313,     0,     0,
       0,     0,     0,     0,  1314,  2573,  2574,  1315,     0,     0,
       0,  2575,     0,     0,     0,   295,     0,     0,     0,     0,
       0,  2576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2577,     0,     0,  2578,  2579,     0,     0,
       0,  2580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2581,     0,
       0,     0,     0,     0,     0,     0,     0,  3629,     0,  2582
};

static const short yycheck[] =
{
       3,     4,     5,   189,   170,     8,   394,   105,  1002,  1465,
      45,  1055,  1173,   797,  1144,  1145,   655,  1147,  1133,  1149,
    1150,  1380,   125,  1292,  1293,  1148,   587,   795,  1130,   590,
     544,   259,   260,  2122,  2379,  1936,  2671,    40,   266,  1168,
    1373,    54,   245,  2362,   172,  2364,   779,   597,     5,    52,
    1405,    54,  2061,   639,  2377,    90,  2325,   261,   262,  2070,
    1129,   570,    65,  1423,  2067,  2009,  2010,  2011,  2012,    72,
    2516,  2916,   170,    76,  1901,  1902,    79,    80,  2913,  2914,
    2915,    84,    85,    20,    26,    27,    25,   754,    27,     5,
      27,   189,    27,    27,    27,  1327,   718,  1329,    20,  2000,
      27,   104,  2448,    25,     5,    27,     5,     5,    19,   152,
     689,   690,    27,  2559,    45,    26,    69,    19,   121,     8,
      20,   124,  1224,    61,    26,    25,   129,    27,    24,   715,
      26,     5,     5,   236,   237,   263,  1238,  2246,     5,   267,
     726,   269,  1257,   271,   272,   273,    27,    25,   727,    27,
       5,   730,   280,   115,   320,  2634,   284,   285,    27,    90,
       5,   740,     5,   116,    27,   744,    19,    27,   115,   748,
      46,    24,    25,    26,     5,     5,   755,    25,    26,    27,
       5,   760,     6,   762,  1228,    25,     5,    27,   191,   768,
       5,     5,   771,   815,   147,   781,     5,     5,   784,   778,
     138,   139,    24,    25,    26,    27,   785,   793,    24,    25,
      26,    27,     5,   792,    25,   975,    27,    27,    24,    25,
      26,    27,   320,     5,   803,    25,   324,    27,   807,     6,
     233,     5,   811,    24,    25,    26,   239,   691,   817,     9,
      10,   820,    12,    13,    14,    15,    16,    17,   251,    27,
    2686,    26,  2688,     6,   257,   258,   259,   260,   261,   262,
     785,   134,   135,   266,   140,   141,    25,     5,    27,   723,
     724,   224,    27,   226,     5,  3000,   121,   203,   123,     5,
     125,   394,   212,    24,    25,    26,    27,     9,    10,  2258,
      12,    13,    14,    15,    16,    17,   327,   196,   190,  2555,
    2300,   243,    25,  2303,    27,   433,   443,   875,   436,  2601,
     313,   314,   203,   289,    24,    25,    26,    27,     5,   510,
     323,   775,   288,   216,     5,   453,   454,   455,   456,   515,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   143,  2693,   577,
     553,  1420,  2621,    25,   597,    27,   482,   485,   486,   297,
      27,  2450,   490,     5,   492,     5,     5,  2652,     5,   597,
      98,    99,   100,   101,   102,   348,   399,   505,   506,   507,
     508,   689,   690,    27,   512,   673,   694,   695,   341,    25,
       5,    27,    27,  1522,   347,  1179,  1129,   958,    23,   707,
       5,     5,  2756,   243,   458,     5,     5,     5,  1192,     5,
    2354,   482,     5,   579,     5,   510,    19,   515,     5,   727,
    1464,   243,   730,    26,   445,   668,   327,   243,   736,     5,
       5,   627,   740,   445,  2719,   227,   744,     5,   301,   727,
     748,     5,     5,   243,   752,   753,   675,   755,   401,     5,
     758,     5,   760,   761,   762,  1155,  1156,   482,   107,   108,
     768,     5,    31,   771,     5,   243,    27,     5,   654,   698,
     778,   667,    30,   510,     5,     5,    34,   785,     5,   670,
     698,   579,     5,     5,   792,   510,     5,   117,   137,   138,
     139,     5,     5,     5,     5,   803,     5,   327,     5,   807,
       5,   504,   243,   811,     5,     5,   399,   522,   481,   817,
     545,   546,   820,   489,   429,   530,   629,  2373,  2374,  2375,
     243,     5,  2378,   404,    18,    19,    20,    21,    22,     5,
     492,     5,   324,   243,   537,   305,     5,   540,     5,     5,
       5,   404,  1302,   445,   772,   548,   764,     5,   106,     5,
     676,   517,  3443,     5,  1133,   113,   654,     5,  2912,  2913,
    2914,  2915,   565,  3454,   567,    18,    19,    20,    21,    22,
       5,   243,   709,   576,   577,   670,     5,   580,     5,     5,
       5,   534,     0,   305,  1152,  2441,   790,   791,   619,  2845,
     556,  1159,    29,   669,   597,    23,  2888,  2889,  1052,   243,
     676,   159,   160,   646,    27,   676,  3451,   243,   243,   167,
     552,   204,    23,   204,   545,   819,    10,  2886,   822,   640,
    1074,   445,   482,   646,   443,   560,  2453,   216,   640,    27,
    2949,   593,   448,   670,  2603,   478,   640,  3362,    25,  2639,
      27,   522,  1426,    30,  2989,   514,   593,   478,    28,   404,
     388,   577,   445,   478,  1438,   425,   426,   448,   662,   522,
     438,   413,   287,   605,   478,   662,   596,  1181,   445,   478,
     445,   482,   482,   565,   677,   445,  1255,  1256,  1257,   682,
     683,   684,   685,   686,   687,   688,   577,  1420,   691,   692,
     693,  2592,   445,   696,  3140,   698,   478,   612,   701,   597,
     703,   439,   118,   425,   426,   408,   522,   448,  2002,   712,
     480,  2070,  3158,   640,   445,   604,  2049,   590,   619,   445,
     723,   724,  1283,   597,  3203,  1286,  1287,  1366,   438,   640,
     733,  1256,  2741,  3056,   667,   673,   739,   604,   640,  2099,
     662,  2101,   745,   746,   747,  3064,   601,  3066,   751,  2605,
    2761,   754,   668,   756,   757,   712,  2759,  2213,   480,  2615,
    1427,   764,   662,  3086,   767,  3244,  1275,  3113,   667,   772,
     773,  3117,   775,  2882,   670,   527,   779,   719,   717,   782,
     717,  3416,   717,   717,   662,   788,   601,   790,   791,   619,
    2145,   478,   795,   796,   797,  3430,   636,   478,   801,   607,
     676,   804,   717,   438,   677,  3229,   809,   566,   445,   336,
     399,   441,  1512,   816,   662,   818,   819,   670,   821,   822,
     420,   824,   825,   668,   295,  1133,  3262,   627,   538,   428,
     445,   676,  3667,   607,   464,   396,   478,   607,   478,   478,
     445,   445,   445,   404,   405,   394,   482,   445,   670,   445,
     522,  3205,  3206,  2709,   670,  3209,   243,   506,   445,   287,
     336,   445,   990,   421,   670,   993,    26,    27,   429,   445,
     445,   432,   445,  1001,  1002,   298,   287,   445,   601,   670,
     667,   445,   445,    27,   636,   607,  1274,   448,   311,   445,
      25,   445,    27,   689,   690,   691,   692,   693,    28,    29,
     298,   445,   289,   673,   445,   505,   634,   445,   302,    27,
     413,   327,   445,   311,   445,   445,  3270,   547,  2212,  3273,
      38,   521,   445,   445,   670,   928,   445,  3562,    10,   670,
     394,   445,   445,   445,   445,     5,   445,   445,   445,  3258,
     445,  3260,  3261,   592,   445,   445,  1400,  1255,  1256,  1257,
     414,   673,     5,   723,   724,  1409,    27,  2813,   516,     0,
     670,   445,   191,   192,   564,  3411,   408,   445,  2795,  3288,
     390,   445,   975,  1559,    56,    16,   445,   386,   445,   445,
     445,   401,  1436,   399,   478,    14,   635,   445,   416,   445,
     413,   552,   342,   445,  1544,    26,    27,   445,    26,    27,
    3345,   723,   724,   603,   354,   416,   595,  3431,  3432,   639,
     445,    25,  1015,    27,  1017,   413,   445,  1531,   445,   445,
     445,   651,   652,   410,   527,   478,  3561,   443,  2151,   659,
    3565,   451,   632,    18,    19,    20,    21,    22,   589,   628,
     158,   641,  2898,   482,   605,   465,   440,   589,   442,  1052,
     608,   612,  1055,  2978,   211,  2980,   640,  1010,  2983,  2912,
    2913,  2914,  2915,   217,   589,   219,  2425,   640,  1071,  2138,
    2429,  1074,  3269,   445,    25,  3272,    27,  1280,  3275,   217,
     629,   219,  3436,   243,   482,    26,    27,   638,  3442,  3443,
     208,  3445,  3446,  3447,  3448,  2327,   638,   510,  2200,   243,
    3454,    25,   489,    27,   527,   477,   244,   640,   243,   450,
    1113,  3456,   482,   638,   640,  1118,    24,    25,    26,  3473,
     543,    25,    25,    27,    27,   243,  1129,   245,   573,   527,
     688,   518,   640,   636,   554,   540,   662,   372,   696,   509,
    1143,  1144,  1145,   548,  1147,   543,  1149,  1150,    26,    27,
     166,  3420,  1155,  1156,   311,   482,   565,   301,   482,  2391,
    2392,  1307,   640,  1309,  1310,   629,    25,   576,    27,   323,
     482,  2286,   326,    25,   482,    27,  1179,    15,    16,    17,
      18,    19,    20,    21,    22,   323,   510,  1190,   326,  1192,
     510,  2185,   349,     5,   348,  3051,   482,  3053,  1201,    26,
      27,  1204,   762,   619,     5,   477,  1209,     8,   298,    47,
     348,   771,   243,  1441,  3568,   243,    20,  3571,  3572,  3573,
    3574,   311,   482,    27,   342,  1228,  1229,   298,   482,   243,
      25,    47,    27,   482,  1237,  1439,   259,   260,   261,    25,
     311,    27,  2002,  3597,  2004,    25,    20,    27,   482,   510,
    1253,  1254,   335,    27,  2014,  2015,   413,   817,   335,   488,
     820,  2021,  2022,  2023,  2024,   348,  1369,   509,   510,  1372,
     427,   348,   677,    19,  3550,  3551,  1279,   482,    24,   719,
      26,   154,   155,   699,   700,   701,  3483,  1453,   379,  1292,
    1293,  3192,   243,   411,   710,   636,  3615,    25,   639,  1302,
     482,   419,   243,   743,  3658,   423,   144,   145,   146,   147,
     148,   149,  1315,  3667,   803,    25,  1544,    27,   807,   243,
    1323,   482,   811,   413,   162,   163,   164,   481,   144,   145,
     146,   147,   148,   149,  3190,  1539,  1540,   298,    26,   243,
     243,   459,   413,   481,  3200,   675,   162,   163,   164,   789,
     311,  3276,  3205,  3206,   482,  1453,  3209,    20,   675,   799,
     482,  3637,   802,  3639,    27,   243,   806,   697,   698,   712,
     527,  1374,   812,   482,   814,  1378,  1379,  1380,   482,   640,
     697,   698,  1395,   482,   243,   482,   543,  1390,  1391,  1392,
     733,   243,  1395,  1396,  1397,  1398,  1399,  1400,   481,  2183,
    2733,   662,  2761,   746,   481,  2138,  1409,   525,   482,   670,
    2539,   482,   509,   510,   482,  1976,   243,  1420,  1979,  1422,
     379,  1424,    30,  1426,  1427,  2375,    34,  3283,  2378,   452,
     482,  1434,  1435,  1436,  2478,  1438,  1439,   527,  1441,  1442,
    2672,   532,  2674,    20,  2676,   482,   564,  1450,   243,  2209,
      27,    20,   413,   543,  1457,  1458,   527,   243,    27,   510,
     445,  1464,  1465,   243,   302,   482,  2250,   305,    26,   532,
     588,  1925,   543,  1927,  1928,   572,   818,  1931,  1932,   821,
      20,   482,   824,  1937,   482,   730,   302,    27,  2256,   305,
      20,  3435,  2607,  3437,  3438,  3439,  3440,    27,    20,   744,
     482,   313,   230,   748,  2090,    27,  1509,  1510,    24,  1512,
      26,   482,  1515,  1516,   632,   760,   482,    24,  2633,    26,
     128,   482,    26,   641,   217,   689,   219,   482,   692,   693,
    3619,   720,   721,   722,  1537,   482,  1539,  1540,   690,   691,
     352,  1544,    25,  1546,    27,  1548,  1549,  3636,  2127,   509,
     510,   244,  2174,   482,   509,   510,   291,   291,    26,   371,
     372,    25,  2016,    27,    19,  2325,   527,  3423,  1571,    24,
      25,    26,   482,   532,  2334,   692,   693,  2337,  2338,  2339,
    2340,   482,   543,  3436,   675,   699,   700,   425,   420,  3442,
    3443,  3209,  3445,  3446,  3447,  3448,   699,   700,  3687,   411,
     482,  3454,   440,   694,   695,    26,   444,   725,   726,   425,
     676,   423,   675,   348,   348,  3704,   676,   572,  2912,  2913,
    2914,  2915,   434,   714,   440,   340,   341,  1067,   444,   357,
     323,   694,   695,   326,    26,   363,   364,   365,   450,  2751,
    2752,   291,   480,   162,   163,   164,  2430,    25,   460,    27,
    2434,   714,    25,  2167,    27,   348,    24,   385,    26,  2443,
      24,  3517,    26,   475,   480,   490,    26,   402,   402,   482,
     508,   406,   406,   505,  2253,  2777,   501,    25,   670,    27,
    3136,   289,   577,  2137,  2468,    25,   482,    27,   526,   521,
    3205,  3206,   508,  2854,  1898,  1899,    26,   522,   348,  2822,
      25,   482,    27,   515,   529,   482,   482,  2286,  2977,  2978,
     526,  2980,   537,   482,  2983,  3568,   675,  2819,  3571,  3572,
    3573,  3574,    24,    24,    26,    26,   538,    20,    21,   482,
     482,   420,   564,  1173,   559,   694,   695,  3096,    25,   482,
      27,   553,    25,  1183,    27,  1185,   481,   481,   560,  2878,
     472,   563,   402,  2314,   482,   714,   406,    26,   482,  2320,
    2321,   510,   490,  1153,  1154,   493,    26,  1157,  1158,   607,
      26,   603,   584,   501,    26,    24,   588,    26,    24,   420,
      26,    26,    25,   420,    27,    26,    26,  3243,   481,   670,
    1422,   607,  1424,   111,   445,   607,   663,   664,   665,   666,
     632,   482,   410,   415,   670,  3658,    26,   445,   536,   641,
    2264,   482,   482,   625,  3667,     5,   505,   478,  3436,  2127,
    2912,  2913,  2914,  2915,  3442,   445,   482,  3445,  3446,  3447,
    3448,   481,   521,   482,   445,   673,  2830,   522,   445,   445,
    2426,   445,   445,   571,  2838,  2839,   676,    20,    20,   482,
     458,   144,   145,   146,   147,   148,   149,   673,   482,   445,
       5,  2621,   590,   591,   505,  1968,   482,   191,   505,   674,
     510,   195,    26,   601,    26,   564,   670,   445,   606,   445,
     521,   489,   420,   311,   521,    18,    19,    20,    21,    22,
    2344,   478,   415,  2479,  1897,  1898,  1899,    20,    30,    26,
      26,  1904,  1905,   640,    26,    26,    26,  2035,    26,    26,
     518,  3205,  3206,   445,   603,  3209,   445,   645,  2678,    26,
     445,  1924,  1925,   564,  1927,  1928,    26,   564,  1931,  1932,
     445,  1934,   445,  2693,  1937,     5,   445,    20,    26,   482,
    2144,  2044,  2528,   632,  2704,  2253,    26,    26,    26,   677,
    3568,   695,   641,  3571,  3572,  3573,  3574,   670,  1961,  3415,
     445,     5,   603,   707,   445,   676,   603,   505,    26,  1972,
     445,   355,   445,   445,   420,   445,  3270,   674,  2286,  3273,
     445,   220,     5,   521,   445,   445,  2440,   482,  1428,  1429,
    1430,   632,   736,   676,    26,   632,   445,  2781,   189,  2002,
     641,  2004,  2230,  2231,   641,  1445,    26,  3276,   752,   753,
     640,  2014,  2015,  2016,   758,   445,  2019,   761,  2021,  2022,
    2023,  2024,  2601,   676,    25,    25,   564,    25,  2607,   114,
     445,  2034,  2816,    25,   445,   445,   445,   445,  2166,   445,
    3658,  2245,   445,    16,    17,    18,    19,    20,    21,    22,
     445,   355,   445,  2056,  2633,   445,   445,  2185,  2061,   505,
     251,   674,   253,   977,  2067,   603,   980,  2070,   982,   983,
     984,   985,   986,  1513,    47,   521,   445,   670,   269,   445,
     482,   670,     8,   675,   478,  2088,   277,  2040,    20,    21,
     281,  2094,  1532,  2654,   632,  2855,  2657,   530,  2659,  2660,
     646,  3145,   319,   641,   189,     5,   511,   668,   668,   646,
    1550,   472,   511,  3205,  3206,   306,   670,  3209,   564,   709,
    2123,  1561,   510,   381,   709,   670,  2886,   662,    18,    19,
      20,    21,     5,   647,  2137,  2138,  2590,   472,  2141,  2142,
    3434,  2144,  3436,     5,   482,   482,   482,   640,  3442,  3443,
     482,  3445,  3446,  3447,  3448,  3149,  2159,   603,   629,   482,
    3454,   399,     8,    14,   626,  2619,   251,     5,   253,     5,
     709,   144,   145,   146,   147,   148,   149,   472,  2181,   482,
    2183,  2635,   709,   482,   269,    26,   632,    26,   118,   162,
     163,   164,   277,   143,   433,   641,   281,   510,    26,   640,
     482,  2204,   482,  2206,  2207,   482,  2209,   670,   447,  2212,
    2213,   482,   144,   145,   146,   147,   148,   149,   482,   482,
     482,   306,   472,   482,   510,  2985,    26,  2230,  2231,     5,
     646,   482,  2686,     5,  2688,   482,   676,  3366,   482,    46,
     482,   676,  2245,   712,   675,   405,  3375,  2250,  2251,  2252,
     607,   490,     5,  2256,   144,   145,   146,   147,   148,   149,
     667,  2264,   501,  3392,    18,   206,   445,    19,   437,    25,
     640,   629,   673,   670,  3568,     5,   533,  3571,  3572,  3573,
    3574,   597,   204,   522,    43,    44,    45,   597,  2291,    48,
     529,    50,    51,  2601,    26,  2461,  2299,  2300,   537,  2607,
    2303,   533,   452,  3597,   376,   597,    26,   445,    26,  2888,
    2889,   445,   522,   676,   445,   445,   670,   676,   482,  3103,
     559,   445,  2325,   577,   482,  2633,   482,   482,   110,   302,
       5,  2334,   305,   482,  2337,  2338,  2339,  2340,  2341,   714,
    3455,  2344,   670,   640,  3436,  2348,  2349,  3131,   445,  2352,
    3442,  3443,   640,  3445,  3446,  3447,  3448,   482,   670,   667,
    2814,   597,  3454,  2461,  3658,   676,   189,     5,     5,     5,
    2373,  2374,  2375,  3667,     5,  2378,  2379,  2380,   676,   670,
    2383,   534,   630,  3005,  3006,  3007,   675,  3009,  3010,  3011,
    3012,  3013,  3014,   717,   718,   482,  3018,   636,    18,    19,
      20,    21,     5,   642,     8,    26,   372,    26,   118,  2412,
    3539,  2414,  2415,   271,  2417,  2418,   380,     5,  2421,   213,
       5,   445,  2425,   482,   414,   482,  2429,  2430,   251,   647,
     253,  2434,    14,   601,   228,   229,   710,  2440,  2441,   676,
    2443,  2444,    26,   237,  2447,  2448,   269,     5,   152,   597,
     676,   482,   425,   482,   277,    18,    19,   670,   281,   675,
     597,    24,    25,    26,    27,  2468,     5,   440,   676,   292,
     675,   444,  2475,    36,    37,  2478,  3568,   271,   689,  3571,
    3572,  3573,  3574,   306,  2487,   478,   280,   445,  2491,   445,
       5,   815,  3622,  3623,  3624,  3625,  3626,  3627,   445,     5,
       5,   825,   422,   669,  3548,   386,    26,   480,   478,   512,
     512,   482,     5,  2516,   482,   309,     5,   482,  3647,  3279,
     482,  3281,   482,   482,   144,   145,   146,   147,   148,   149,
     482,   482,     8,   510,   670,   508,     5,  2540,   627,   604,
     380,   670,   670,    25,   399,   399,  2692,   510,  2694,   399,
     414,   670,   477,   526,   117,   482,   510,     5,     5,   701,
     354,    26,     5,     5,   323,    25,  3658,   326,    14,   328,
      14,    26,   646,   646,   667,  3667,   482,   604,     5,     5,
    2888,  2889,   676,   482,   445,  3369,    26,  2590,   445,   348,
       6,   499,   445,  1265,     7,   321,   445,   445,   445,   358,
     445,     5,  2605,  3387,   398,    26,   670,    26,   676,    26,
    2613,  2614,  2615,   445,    26,  2618,  2619,  2652,  2621,    26,
     379,   670,   670,  3077,    20,     5,   617,   327,     5,     5,
     597,  2634,  2635,     5,   607,  2638,  2639,     8,     5,   445,
    2868,   718,  2870,   402,  3638,   670,  2812,   406,   622,   445,
    3289,   975,   482,  2093,   522,   676,     5,   597,     5,   676,
    3420,   674,   264,    26,   445,   445,   445,  2853,   676,  2109,
     676,   676,   482,   482,  3434,  2678,     5,     5,   674,   676,
     243,    25,    25,  2686,  2719,  2688,    25,   669,  2691,    25,
    2693,  3252,    25,  3254,  3255,   498,  2136,  2825,   349,    26,
     673,  2704,  2830,  2143,    26,    26,  2709,  2710,  2711,    26,
    2838,  2839,    26,    26,  2812,    26,   445,   445,     5,   482,
    2723,   445,   481,   445,   519,   482,  3770,     5,   445,   601,
      26,  1055,     8,  2173,   293,   478,    25,   445,  2741,   399,
     482,   492,   195,    20,   604,    25,  3530,   482,   482,   482,
      40,   482,  2192,     5,     5,  2853,  2759,   482,  2761,   482,
      14,   264,   445,   445,     5,   510,  2912,  2913,  2914,  2915,
      26,  2774,   493,   445,   445,   445,    26,    26,  2781,   482,
      26,    26,    26,   428,   619,   293,    43,    44,    45,    26,
     445,    48,   445,    50,    51,   445,   482,   445,   399,   294,
     492,   510,   482,  2806,  3564,  2808,   597,  2810,  3262,    14,
    2813,  2814,   445,  2816,   104,   105,   445,   445,     7,   292,
     292,   445,    26,   445,   676,   482,   670,   445,  2831,   446,
    2833,  2834,  2835,  2979,   626,  2981,   445,   478,    26,   482,
      25,  3601,   294,   510,     5,  2848,   445,   445,   445,   445,
     445,    26,  2855,    26,   445,   670,   670,     5,   445,    26,
    2774,  2833,   478,  3251,   478,  2868,   670,  2870,  3697,  2512,
    2193,  1551,    29,    31,  2444,   352,  3455,  2880,  2881,  2450,
     170,  2806,   112,  2886,   116,   448,  1001,   206,   658,   343,
    2039,   353,  2040,   224,   534,  2898,   211,   382,   600,   189,
    1291,   381,   565,   567,  1228,  3687,  2093,   993,   801,  2912,
    2913,  2914,  2915,  2916,  2917,   415,   479,  3121,  1262,   482,
    2297,  2304,  2437,  2926,  2143,  1897,  3170,  1900,  2931,  2857,
    3134,  2220,   495,  3741,  2536,  2240,  2440,  3383,  1441,    18,
      19,    16,    40,    90,  3310,    40,    22,    26,    27,  3115,
     230,   930,  2198,  3713,  2204,   757,   324,  1562,  1510,    38,
    1905,  1017,  1229,  2966,  2967,  3307,  2207,   257,  1292,  1293,
    3492,   534,   535,  3704,  2977,  2978,  1435,  2980,  1302,  2419,
    2983,   782,  2985,  2855,   547,  1424,  2989,  1508,  3045,  3502,
    1532,   452,  2173,  3043,  3027,  2435,  2436,  2437,  2438,  3101,
    3363,  2722,  3361,  3354,  3093,  2429,  2073,  2056,  2383,  2601,
    3713,  3283,  1939,  1939,  2620,  3202,  2456,  3115,  2275,  3517,
    3050,  3149,  3084,   313,   314,   588,  3029,  2263,  2344,  2691,
     320,  3592,  3593,   112,   324,  2967,  3273,  2966,  3597,  3042,
    3072,  1924,  2744,  3351,  3326,   124,  2723,   607,  3051,  3052,
    3053,     8,  3759,  3361,  1258,  2710,  3204,  2711,  2899,  3205,
    3206,  2015,  3281,  3209,   627,  2014,   323,  3558,  1919,   326,
    1254,   328,   151,  3434,  3077,  2614,   639,   357,  3199,  3453,
    3442,  1892,  2522,   363,   364,   365,  3089,  3090,   651,   652,
    3093,   348,  2034,  3096,  2814,  1450,   659,  2812,  2461,   662,
    3103,   358,  1118,    -1,   543,   385,  1458,   670,    -1,  1440,
    3113,    -1,    -1,  3116,  3117,    -1,    -1,    -1,  3121,    -1,
      -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,  3131,    -1,
      -1,  3134,    -1,  3136,    -1,    -1,    -1,  3365,    -1,    -1,
    1464,    -1,  3145,    -1,    -1,   402,    -1,  3455,    -1,   406,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3184,    -1,    -1,  2624,    -1,  2626,  3190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3199,  3200,    -1,  3202,
    3203,    -1,  3205,  3206,    -1,    -1,  3209,    -1,    -1,    -1,
     490,    -1,    -1,   493,   504,    -1,    -1,  3220,    -1,    -1,
      -1,   501,    -1,    -1,   481,   515,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3243,  3244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   536,    -1,    -1,  3262,
      -1,    -1,    -1,   342,    -1,    -1,    -1,  3270,    -1,    -1,
    3273,    -1,    -1,  3276,    -1,    -1,  3279,    -1,  3281,    -1,
    3283,    -1,    -1,    -1,    -1,    -1,    -1,  1959,  1960,   579,
    3436,   571,    -1,    -1,  1966,    -1,  3442,  3443,   377,  3445,
    3446,  3447,  3448,    -1,  3307,    -1,    -1,    -1,  3454,    -1,
     590,   591,    43,    44,    45,    -1,    -1,    48,    -1,    50,
      51,   601,    -1,    -1,    -1,    -1,   606,    -1,    -1,    -1,
      -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3345,    -1,   423,    -1,    -1,  2787,    -1,    -1,
    2790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3365,    -1,   654,   645,  3369,    -1,  3554,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     459,    -1,    -1,    -1,  3387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   682,   683,   684,   474,   686,   677,    -1,    -1,
      -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3415,   703,  2854,    -1,   495,  3420,    -1,    -1,
    3423,    -1,  3568,    -1,    -1,  3571,  3572,  3573,  3574,    -1,
      -1,  3434,    -1,  3436,    -1,    -1,    -1,    -1,    -1,  3442,
    3443,    -1,  3445,  3446,  3447,  3448,    -1,    -1,  3451,   739,
    3453,  3454,    -1,  3456,    -1,   745,  3554,   747,    -1,    -1,
     539,   751,    -1,    -1,   754,    -1,    -1,   757,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   564,    -1,    -1,    -1,  3492,
      -1,    -1,   782,    -1,  3497,    -1,  3499,    -1,   788,    -1,
      -1,    -1,    -1,    -1,  2176,   795,   796,   797,    -1,   588,
    3638,   801,  3658,    -1,  3517,    -1,    -1,    -1,    -1,   809,
      -1,  3667,    -1,    -1,    -1,    -1,    -1,  3530,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   825,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2216,  3548,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   632,    -1,  3558,    -1,    -1,    -1,    -1,
      -1,  3564,   641,    -1,    -1,  3568,    -1,    -1,  3571,  3572,
    3573,  3574,    -1,  3576,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1905,    -1,    -1,    -1,    -1,    -1,  3590,    -1,    -1,
      -1,    -1,   323,    -1,  3597,   326,    -1,   328,  3601,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,  3622,
    3623,  3624,  3625,  3626,  3627,    -1,    -1,   358,    -1,    47,
      -1,  3634,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   725,   726,   379,    -1,
      -1,    -1,    -1,    -1,    -1,  3658,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,  3667,    -1,    -1,    -1,    -1,    -1,
      -1,   402,    -1,    -1,    -1,   406,    -1,    -1,  2002,    -1,
    2004,    -1,    -1,    -1,  3124,    -1,    -1,    -1,    -1,    -1,
    2014,  2015,    -1,    -1,    -1,    -1,    -1,  2021,  2022,  2023,
    2024,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
    3713,    -1,  3715,    -1,    -1,    -1,    -1,    -1,    36,    37,
    3160,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,
     481,    -1,    -1,    -1,  3757,  3758,  3759,    -1,   144,   145,
     146,   147,   148,   149,    -1,  1055,    -1,  3770,    -1,  3772,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
      -1,  1071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2506,  2507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2517,    -1,    -1,    -1,    -1,
    2174,    -1,    -1,  1143,  1144,  1145,    -1,  1147,    -1,  1149,
    1150,    -1,    -1,    -1,    -1,  1155,  1156,    -1,    -1,  2541,
    2542,  2543,  2544,  2545,  2546,    -1,    -1,    -1,    -1,  2551,
    2552,  2553,  2554,    -1,   302,  2209,  2558,   305,    -1,  1179,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1204,    -1,   302,    -1,    -1,   305,
      -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,  3371,    23,     9,    -1,    -1,    -1,    -1,  1228,  1229,
      -1,    -1,    18,    19,    -1,    -1,    -1,  1237,    24,    25,
      26,    27,    43,    44,    45,    -1,    -1,    48,    -1,    50,
      51,    -1,    38,  1253,  1254,    -1,  3406,    -1,  2640,  2641,
      -1,    -1,    -1,    -1,    -1,  2647,  2648,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,  2325,    -1,    -1,    -1,    36,    37,   425,    -1,    -1,
    2334,    -1,    -1,  2337,  2338,  2339,  2340,    -1,    -1,    -1,
      -1,    -1,   440,    -1,   115,  2349,   444,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   425,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,   143,    -1,   440,  2379,    -1,    -1,   444,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
     508,    -1,    -1,    -1,   480,    -1,    -1,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   508,    -1,  2796,  2797,   217,    -1,   219,    -1,
     448,    -1,  1422,  2805,  1424,    -1,  1426,  1427,    -1,    -1,
     526,    -1,    -1,    -1,  1434,  1435,    -1,    -1,  1438,    20,
      21,    22,  1442,   244,  2478,    -1,    -1,    -1,    -1,    -1,
     251,   479,   253,  1453,   482,    -1,    -1,   243,    -1,   245,
    2842,  2843,    -1,   264,  1464,  1465,    47,   495,   269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,   607,
     281,    -1,    -1,  3633,    -1,    -1,   287,  2869,    -1,  2871,
     291,   292,   293,   294,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,   306,    -1,   535,    -1,  1509,
    1510,   607,  1512,    -1,    -1,  1515,  1516,    -1,    -1,   547,
      -1,    -1,   323,    -1,    -1,   326,    -1,   328,    -1,    -1,
      -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   673,  1546,   348,    -1,    -1,
    2932,  2933,    -1,    -1,  2936,  2937,   342,   358,    -1,    -1,
     588,   347,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,  1571,    -1,    -1,    -1,    -1,    -1,   673,   379,   380,
      -1,   162,   163,   164,    -1,    -1,  3736,  2621,    -1,    -1,
      -1,   377,    -1,   394,    -1,    -1,    -1,   352,    -1,   627,
      -1,   402,    -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,
      -1,   639,    -1,   414,   415,   416,    -1,   372,   373,   374,
      -1,    -1,    -1,   651,   652,   411,    -1,    -1,    -1,    -1,
      -1,   659,    -1,    -1,   662,    -1,    -1,   423,    -1,    -1,
     172,    -1,   670,    -1,  2678,    -1,    -1,    -1,    -1,    -1,
      -1,  3033,    -1,    -1,    -1,   441,   411,  2691,    -1,  2693,
     446,    -1,   448,    -1,    -1,    -1,    -1,    -1,   423,    -1,
    2704,    -1,    -1,   459,    -1,    -1,    -1,    -1,   464,   434,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,   492,    -1,   479,    -1,   450,   482,    -1,    -1,   485,
      -1,    -1,    -1,    -1,    -1,   460,    -1,   448,   494,   495,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     475,   302,  2756,    -1,   305,    -1,    -1,    -1,    -1,    -1,
      -1,   532,  3114,    -1,    -1,    -1,  3118,    -1,   479,    -1,
      -1,   482,   274,    -1,    -1,    -1,    -1,    -1,   534,   535,
     282,    -1,    -1,   539,   495,  3137,   288,    -1,   290,    -1,
      -1,   547,    -1,    -1,    -1,    -1,    -1,    -1,   523,   301,
      -1,    -1,   558,    -1,  3156,    -1,    -1,    -1,   564,    -1,
      -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   593,    -1,   535,    -1,    -1,   329,   553,    -1,
      -1,    -1,   588,    -1,    -1,    -1,   547,    -1,   563,    -1,
      -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,   350,    -1,
      -1,  2855,    -1,    -1,    -1,    -1,    -1,    -1,   629,   584,
     362,    -1,    -1,   588,    -1,    -1,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,   425,    -1,   632,   588,    -1,    -1,
      -1,    -1,  2886,   639,    -1,   641,    -1,    -1,    -1,   440,
      -1,   616,    -1,   444,    -1,   651,   652,    -1,    -1,    -1,
     625,    -1,    -1,   659,   675,    -1,    -1,    -1,  2912,  2913,
    2914,  2915,    -1,    -1,   670,    -1,   627,    -1,   689,   690,
     691,   692,   693,   694,   695,    -1,   697,   698,   639,   480,
      -1,    -1,    -1,    -1,  1904,  1905,    -1,    -1,    -1,    -1,
     651,   652,    -1,   714,    -1,    -1,    -1,    -1,   659,    -1,
      -1,   662,    -1,    -1,    -1,    -1,    -1,   508,    -1,   670,
      -1,    -1,  2966,  2967,    -1,    -1,    -1,    -1,    -1,   725,
     726,    -1,    -1,  2977,  2978,   526,  2980,    -1,    -1,  2983,
      -1,  2985,    -1,    -1,    -1,  2989,    -1,    -1,    -1,    -1,
      -1,  1961,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3005,  3006,  3007,    -1,  3009,  3010,  3011,  3012,  3013,
    3014,    -1,    -1,    -1,  3018,   517,    -1,    -1,    -1,    -1,
     522,    -1,    -1,    -1,    -1,    -1,    -1,   529,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,
      -1,    -1,  3404,    -1,   556,  3407,   607,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3145,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    36,    37,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,   124,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,  2159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
    3552,  3205,  3206,    -1,    -1,  3209,    -1,    -1,    -1,    -1,
      -1,    -1,    47,  2183,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,  2204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,  2213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3603,  3604,    -1,  3606,    47,  3608,  3609,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3270,    -1,    -1,  3273,
      -1,    -1,  3276,    -1,    -1,  3279,    -1,  3281,    -1,    -1,
    2250,  2251,  2252,    -1,    -1,    -1,  2256,    -1,    -1,    -1,
      -1,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,  2291,    -1,  3675,    -1,  3677,    -1,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,  3711,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,  3730,  3731,
      -1,    -1,  3734,    -1,    -1,  3737,    -1,    -1,    -1,    -1,
     342,    -1,    -1,    -1,     9,   347,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,  3420,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,   377,    -1,    -1,    -1,    -1,
    3434,    -1,  3436,    -1,    -1,    -1,    -1,    -1,  3442,  3443,
      -1,  3445,  3446,  3447,  3448,    -1,    -1,    -1,    -1,    -1,
    3454,    -1,  3456,    -1,    -1,    -1,    -1,    -1,    -1,   411,
    2430,    -1,    -1,    -1,  2434,    -1,    -1,   302,    -1,  3473,
     305,   423,    -1,  2443,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,
      -1,  2461,    -1,    -1,   446,    -1,   448,   112,  2468,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,   459,  2478,   124,
     302,    -1,   464,   305,    -1,    -1,    -1,  2487,    -1,    -1,
      -1,  2491,   474,    -1,    -1,    -1,    -1,   479,    -1,    -1,
     482,    -1,    -1,   485,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,   494,   495,  3548,    -1,  2516,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    3564,    -1,    -1,    39,  3568,    -1,    -1,  3571,  3572,  3573,
    3574,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   534,   535,    -1,    -1,    -1,   539,    -1,    -1,
     425,    -1,    -1,  3597,    -1,   547,    -1,  3601,    -1,    -1,
      -1,    -1,    -1,    -1,   479,   440,   558,   482,    -1,   444,
      -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,
     245,    -1,    -1,   425,    -1,    -1,   588,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,   480,    -1,    -1,   440,    -1,
      -1,    -1,   444,   445,  3658,    -1,   132,   133,    -1,    -1,
     535,    -1,    -1,  3667,    -1,    -1,   142,     9,  2638,    -1,
      -1,    -1,   547,   508,    -1,    -1,    18,    19,    -1,    -1,
     632,    -1,    24,    25,    26,    27,    -1,   639,   480,   641,
      -1,   526,    -1,    -1,    -1,    -1,    38,    -1,    -1,   651,
     652,    -1,    -1,    -1,    -1,    -1,    -1,   659,    -1,  3713,
      -1,    -1,    -1,   588,    -1,    -1,   508,    -1,   670,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,     9,    -1,
      -1,    -1,   347,    -1,   526,    -1,    -1,    18,    19,    20,
    2710,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,   627,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,   377,    -1,   639,    22,  3770,    -1,    -1,    -1,
     112,    -1,   607,   725,   726,   117,   651,   652,    -1,    -1,
      -1,    -1,   124,    -1,   659,    -1,    -1,   662,    -1,    -1,
      47,    -1,    -1,    -1,    -1,   670,   411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,   151,
      -1,  2781,    -1,    -1,    -1,   607,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,
      -1,   446,    -1,   448,    -1,    -1,   117,   313,   673,    -1,
      -1,    -1,  2812,    -1,   459,    -1,  2816,    -1,    -1,   464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,  2831,    -1,  2833,   479,  2835,    -1,   482,    -1,    -1,
     485,    -1,    -1,    -1,    -1,    -1,   352,    -1,  2848,   494,
     495,   673,    -1,  2853,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,   371,   372,   373,   374,    -1,
      -1,   243,    -1,   245,    -1,   162,   163,   164,    -1,    -1,
    2880,  2881,     9,   389,    53,    54,    55,    56,    57,    58,
     535,    18,    19,    -1,   539,    -1,    -1,    24,    25,    26,
      27,    -1,   547,    -1,    -1,   411,    -1,    -1,    -1,    -1,
      -1,    38,    -1,   558,    -1,   560,    -1,   423,    -1,   564,
      -1,    -1,    -1,    -1,    -1,    -1,  2926,    -1,   434,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   588,   450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,
     342,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,   112,    -1,   632,    -1,    -1,
     117,    -1,    -1,    -1,   639,    -1,   641,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   377,   651,   652,    -1,   515,
      -1,    -1,    -1,    -1,   659,   302,    -1,    -1,   305,    -1,
      -1,    -1,    -1,    -1,   151,   670,    -1,    -1,    -1,  3029,
      -1,    -1,   538,    -1,    -1,    -1,   347,    -1,    -1,   411,
      -1,    -1,  3042,    -1,    -1,    -1,    -1,   553,    -1,    -1,
      -1,   423,    -1,    -1,   560,    -1,    -1,   563,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,
      -1,    -1,    -1,    -1,   446,    -1,   448,    -1,   584,    -1,
     725,   726,   588,    -1,    -1,    -1,    -1,   459,    -1,    -1,
      -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   607,   474,  3103,    -1,    -1,    -1,   479,    -1,    -1,
     482,    -1,    -1,   485,    -1,  3115,   243,    -1,   245,   625,
      -1,    -1,   494,   495,    -1,    -1,    -1,    -1,    -1,   126,
     127,  3131,   129,   130,   131,    -1,  3136,   448,   425,    -1,
      -1,    -1,    -1,    -1,    -1,  3145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   440,    -1,    -1,    -1,   444,    -1,    -1,
      -1,   667,   534,   535,    -1,    -1,    -1,   539,   479,    -1,
      -1,   482,    -1,    -1,    -1,   547,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   494,   495,    -1,   558,    -1,    -1,    -1,
      -1,    -1,   564,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   522,    -1,    -1,    -1,   342,   588,    -1,   387,    -1,
     347,   508,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,
      -1,   400,   229,    -1,    -1,    -1,   547,    -1,    -1,   526,
     237,    -1,    -1,  3243,    -1,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     632,    -1,    -1,    -1,    -1,    -1,    -1,   639,    -1,   641,
      -1,    -1,    -1,    -1,   271,    -1,    -1,   588,    -1,   651,
     652,    -1,    -1,   280,   411,    -1,    -1,   659,    -1,    -1,
      -1,    -1,    -1,   462,    -1,    -1,   423,    -1,   670,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3307,    -1,    -1,
     621,    -1,   309,   310,   441,    -1,   627,    -1,    -1,   446,
     607,   448,    -1,    -1,    -1,   636,   637,    -1,   639,    -1,
      -1,    -1,   459,    -1,    -1,    -1,    -1,   464,   507,    -1,
     651,   652,    -1,    -1,    -1,    -1,    -1,   474,   659,    -1,
      -1,   662,   479,   725,   726,   482,    -1,   354,   485,   670,
      -1,    -1,   531,    -1,    -1,    -1,    -1,   494,   495,  3369,
      -1,    -1,   541,   542,    -1,    -1,    -1,    -1,   547,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   673,  3387,   557,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,    -1,    -1,    -1,   313,    -1,    -1,   535,    -1,
     579,    -1,   539,   582,   583,  3415,    -1,    -1,   587,    -1,
     547,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,   558,    12,    13,    14,    -1,    -1,   564,    18,    19,
      20,    21,    22,    23,   352,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,   452,    -1,    -1,    -1,    -1,
      -1,   588,    -1,   371,   372,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   644,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,    -1,
      -1,    -1,  3492,    -1,    -1,    -1,    -1,  3497,    -1,  3499,
      -1,    -1,    -1,   411,    -1,   632,    -1,    -1,    -1,    -1,
      -1,    -1,   639,    -1,   641,   423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   651,   652,   434,    -1,    -1,    -1,
    3530,    -1,   659,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   450,   670,   124,    -1,    -1,    -1,  3548,    -1,
      -1,    -1,   460,    -1,  3554,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    -1,   475,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   725,   726,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   515,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3622,  3623,  3624,  3625,  3626,  3627,   208,    -1,
     538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,    -1,    -1,
     230,    -1,   560,    -1,    -1,   563,   236,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,
     588,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,    -1,    -1,    -1,    -1,    -1,   276,    -1,    -1,   607,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   625,    -1,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,
      -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   342,   343,    -1,    -1,    -1,    -1,    -1,   349,
    3770,    -1,   352,   353,    -1,    -1,    -1,   357,    -1,    -1,
      -1,    -1,    -1,   363,   364,    -1,    -1,    -1,    -1,    -1,
     370,   371,   372,    -1,    -1,   375,   376,   377,    -1,    -1,
      -1,   381,   117,    -1,    -1,   385,    -1,   387,    -1,    -1,
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
     500,   501,   502,   503,   504,   505,   506,   507,   243,    -1,
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
     710,   711,    -1,   448,   714,   715,    -1,   717,   718,   719,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,   479,    -1,    -1,   482,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   588,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,   168,   169,    -1,   621,    -1,    -1,    -1,
      -1,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   636,   637,    -1,   639,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   651,   652,    -1,    -1,
      -1,    -1,    -1,   208,   659,    -1,    -1,   662,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   428,   429,   430,   431,   432,   433,   434,
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
     705,    -1,    -1,   708,   709,   710,   711,    30,    -1,   714,
     715,    34,   717,   718,   719,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,
     173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,    -1,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   197,    -1,   199,   200,   201,    -1,
      -1,    -1,    -1,    -1,   207,    -1,   209,   210,    -1,   212,
      -1,   214,   215,    -1,    -1,   218,    -1,    -1,   221,   222,
     223,   224,   225,   226,    -1,    -1,    -1,   230,   231,   232,
      -1,   234,    -1,    -1,    -1,   238,    -1,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,   249,    -1,    -1,   252,
      -1,   254,    -1,   256,    -1,   258,    -1,    -1,    -1,   262,
     263,    -1,   265,   266,   267,    -1,    -1,   270,    -1,   272,
     273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     283,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   296,    -1,    -1,   299,   300,    -1,    -1,
     303,   304,    -1,    -1,   307,   308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   316,   317,   318,    -1,   320,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,   331,   332,
      -1,   334,    -1,    -1,    -1,   338,   339,    -1,    -1,    -1,
     343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   359,   360,   361,    -1,
      -1,    -1,    -1,    -1,   367,   368,    -1,    -1,    -1,    -1,
      -1,    -1,   375,    -1,    -1,   378,    -1,    -1,    -1,   382,
     383,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
     393,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,    -1,
     453,    -1,   455,   456,    -1,    -1,    -1,    -1,    -1,    -1,
     463,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,   502,
      -1,    -1,    -1,    47,    36,    37,    -1,    -1,    -1,    -1,
     513,    -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   544,   545,   162,   163,   164,   549,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,
      -1,    -1,    -1,    -1,   567,   568,   569,   570,    -1,    -1,
      -1,   574,    -1,    -1,    -1,   578,    -1,    -1,    -1,    -1,
      -1,    -1,   585,   586,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   596,    -1,   598,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   609,    -1,   611,    -1,
      -1,   614,    -1,    -1,    -1,    -1,    -1,   620,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   646,    -1,    -1,   649,    -1,    -1,    -1,
      -1,   654,    -1,    -1,   657,   658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,   672,
      -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,
      -1,    -1,    -1,   302,    -1,    -1,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,
     703,   704,   705,   706,   707,   708,    -1,    -1,   711,    -1,
     713,   243,   715,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    47,    -1,    -1,    -1,   302,    -1,
      -1,   305,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   425,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   440,    -1,    -1,    -1,   444,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    47,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    47,   162,
     163,   164,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   508,
     162,   163,   164,    -1,    -1,    -1,   440,    -1,    -1,    -1,
     444,    -1,    -1,    -1,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,
      -1,    -1,   302,    -1,    -1,   305,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   479,    -1,    -1,
     482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,    -1,   495,   508,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   526,   162,   163,   164,    -1,    -1,   607,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   534,   535,    -1,    -1,    -1,    -1,    -1,   302,
      -1,    -1,   305,    -1,    -1,   547,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     302,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   673,    -1,   588,    -1,    -1,    -1,
     440,    -1,    -1,   607,   444,   445,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,   302,
     480,    -1,   305,    -1,   636,   637,    -1,   639,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,
     652,    -1,    -1,   302,    -1,    -1,   305,   659,   508,   673,
     662,    -1,   425,    -1,    -1,    -1,    -1,    -1,   670,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   526,   440,    -1,    -1,
      -1,   444,   445,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,
      -1,    -1,   444,   445,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,    -1,
      -1,    -1,   425,    -1,    -1,    -1,    -1,   607,    -1,    -1,
      -1,    -1,    -1,   526,    -1,    -1,   508,   440,    -1,    -1,
      -1,   444,   445,    -1,    -1,    -1,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
      -1,   440,    -1,    -1,    -1,   444,   445,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,   480,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,   508,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   607,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,   508,
      -1,    -1,    -1,    -1,    -1,   607,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,   526,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     673,    -1,     6,     7,     8,    47,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   673,    -1,    -1,   607,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,   607,    -1,
     162,   163,   164,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     673,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     302,    -1,    -1,   305,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
     302,    -1,    -1,   305,    -1,    -1,    -1,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   302,    -1,
      -1,   305,   144,   145,   146,   147,   148,   149,    47,    -1,
      -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,   440,    -1,
      -1,    -1,   444,   445,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,   302,    -1,    -1,   305,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    47,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   508,    -1,   440,    -1,
      -1,    -1,   444,   445,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
      -1,   425,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,   480,    -1,
     444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     302,    -1,    -1,   305,    -1,    -1,   508,    -1,   144,   145,
     146,   147,   148,   149,    -1,   425,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   526,    -1,   162,   163,   164,   493,
     440,    -1,    -1,    -1,   444,   607,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   302,    -1,    -1,   305,    -1,    -1,
      -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   493,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   508,    -1,
      -1,   673,    -1,   302,    -1,   607,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   526,    -1,    -1,    -1,
      47,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,
      -1,    -1,   444,   607,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,   305,
      -1,   673,     9,    -1,    -1,    -1,    -1,   425,   480,    -1,
      -1,    18,    19,    20,    -1,    47,    -1,    24,    25,    26,
      27,   493,   440,    -1,    -1,    -1,   444,   607,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,   673,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,   526,    -1,   425,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,   162,   163,   164,    -1,    -1,
      -1,   440,    -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     508,    -1,    -1,   673,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,   526,    -1,
     117,   480,   144,   145,   146,   147,   148,   149,    -1,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
     162,   163,   164,    -1,   440,   607,    -1,    -1,   444,   508,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,   480,    20,    -1,    47,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,   607,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   673,   508,    -1,    -1,   302,    -1,    -1,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   243,    -1,   607,    -1,
      -1,    -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   673,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     302,    -1,   117,   305,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     185,    -1,   162,   163,   164,    -1,    -1,    -1,   193,    -1,
      -1,   607,    -1,    -1,   673,    -1,    -1,   202,    -1,    -1,
     205,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     347,    -1,    -1,   440,    -1,    -1,    -1,   444,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    18,    19,    20,    -1,    -1,
     255,    24,    25,    26,    27,    -1,    -1,   673,    -1,    -1,
      -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,   302,    -1,    -1,   305,    -1,    -1,
      -1,    -1,    -1,   425,    -1,    -1,   493,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,
     117,   508,   444,    -1,    -1,    -1,    -1,   312,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,
      -1,    -1,   302,    -1,    -1,   305,    -1,    -1,    -1,    -1,
      -1,   448,   337,    -1,    -1,    -1,    -1,    -1,   480,   344,
      -1,   346,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,   356,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,   479,    -1,    -1,   482,   508,    -1,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,   494,   495,   384,
      -1,    -1,    -1,    -1,   526,    -1,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,
     607,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   440,    18,    19,    20,   444,    -1,   535,    24,
      25,    26,    27,    -1,   429,    -1,   243,    -1,    -1,    -1,
     547,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,   453,    -1,
      -1,   117,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     440,    -1,    -1,    -1,   444,   607,   673,    -1,    -1,    -1,
     243,   588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     508,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,    -1,    -1,   501,    -1,   526,    -1,
     480,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
     627,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   636,
     637,    -1,   639,    -1,   479,    -1,    -1,   482,   508,    -1,
     347,   673,    -1,    -1,   651,   652,    -1,    -1,    -1,    -1,
     495,    -1,   659,    -1,    -1,   662,   526,    -1,    -1,    -1,
      -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,   243,    -1,   607,
     535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   547,    -1,   599,   600,   601,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   612,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,    -1,
      -1,   448,    -1,   588,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,   673,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   479,    -1,   150,   482,   621,    -1,    -1,    -1,
      -1,    -1,   627,    -1,    -1,   448,    -1,   494,   495,    -1,
      -1,   636,   637,    -1,   639,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   673,    -1,    -1,   651,   652,    -1,    -1,
      -1,    -1,    -1,    -1,   659,    -1,   479,   662,    -1,   482,
     715,    -1,    -1,    -1,    -1,   670,    -1,    -1,   535,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   534,   535,    -1,    -1,    -1,    -1,    -1,    -1,   255,
      -1,   588,    -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
     627,    -1,    -1,   479,    -1,   588,   482,    -1,    -1,   636,
     637,    -1,   639,    -1,    -1,    -1,   312,    -1,    -1,   495,
      -1,    -1,    -1,    -1,   651,   652,    -1,    -1,    -1,    -1,
      -1,    -1,   659,   448,    -1,   662,    -1,    -1,   621,    -1,
      -1,   337,    -1,   670,   627,    -1,    -1,    -1,    -1,    -1,
     346,    -1,    -1,   636,   637,    -1,   639,    -1,    -1,   535,
      -1,    -1,    -1,    -1,   479,    -1,    -1,   482,   651,   652,
      -1,   547,    -1,    -1,    -1,    -1,   659,    -1,    -1,   662,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   670,   384,    -1,
      -1,   387,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   400,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,
      -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     636,   637,    -1,   639,    -1,    -1,   462,    -1,    -1,    -1,
      -1,    -1,   468,   588,    -1,   651,   652,    -1,    -1,    -1,
      -1,    -1,    -1,   659,    -1,    -1,   662,   483,    -1,    -1,
      -1,    -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,
      -1,   507,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   636,   637,    -1,   639,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   531,   651,   652,    -1,    -1,
      -1,    -1,    -1,    -1,   659,   541,   542,   662,    -1,    -1,
      -1,   547,    -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,
      -1,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   579,    -1,    -1,   582,   583,    -1,    -1,
      -1,   587,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   644,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   653,    -1,   655
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
     167,   421,   516,   608,   688,   696,   786,   961,  1041,  1103,
    1104,  1106,  1110,  1111,  1117,  1129,  1133,  1284,  1294,  1569,
     667,  1006,  1166,   295,   509,   510,  1172,    20,  1006,  1170,
     670,   818,     5,   816,   408,  1006,     5,   842,   844,   845,
    1006,  1295,  1006,  1006,  1285,  1118,  1006,  1006,  1106,  1112,
     313,   352,   371,   372,   411,   423,   434,   450,   460,   475,
     515,   538,   553,   560,   563,   584,   588,   607,   625,   872,
     873,   874,   877,    25,  1163,  1169,    18,    19,    26,    38,
     112,   124,   151,   245,   342,   377,   411,   423,   459,   474,
     482,   495,   539,   564,   588,   632,   641,   725,   726,   736,
     738,   930,   935,   946,   948,  1006,  1163,  1173,  1174,   510,
      14,   869,   820,   573,  1271,   821,   818,   823,    32,    39,
     116,   132,   133,   142,   313,   352,   371,   372,   373,   374,
     389,   411,   423,   434,   450,   460,   475,   515,   538,   553,
     560,   563,   584,   588,   607,   625,   667,   827,   836,   847,
     852,  1006,   482,   166,  1006,   812,   962,  1134,  1006,   879,
     372,   825,   482,   855,   857,   858,   856,   865,   866,   482,
     482,   878,   510,   482,   818,   853,   477,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   736,   482,
     809,     9,    18,    19,    24,    25,    26,   117,   347,   441,
     446,   448,   464,   479,   482,   485,   494,   535,   547,   558,
     588,   639,   651,   652,   659,   670,   906,   914,   915,   916,
     917,   918,   946,   947,   949,  1012,  1163,  1274,  1467,   482,
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
     906,   906,   906,   577,  1291,   482,   482,   906,   420,   505,
     521,   564,   603,   632,   641,  1470,  1471,   482,   906,   906,
     482,   482,   919,   482,   482,   482,   482,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    47,   144,   145,   146,   147,   148,
     149,   162,   163,   164,   302,   305,   425,   440,   444,   480,
     508,   526,   607,   673,   808,   907,   920,   922,   923,   924,
     925,   926,   927,   928,   472,   938,   936,   942,   940,  1163,
    1163,   736,   931,  1006,  1174,   510,   478,    26,   829,   482,
     851,   818,   851,   831,    26,    26,    26,   818,    26,    26,
     817,   834,   851,    26,   670,   111,   843,  1296,   445,   482,
    1286,  1585,  1586,  1587,  1588,  1589,   963,  1135,  1113,   670,
      26,   445,   860,   861,   482,   862,   867,   868,   862,   482,
     863,     5,   445,     5,   445,     5,   336,     5,   872,   478,
       5,     5,   445,   818,   854,   445,   482,     5,   445,   510,
     670,   445,   445,   445,   445,   445,   445,   445,    19,    26,
     445,   640,   951,    19,    26,   640,   445,     5,   445,   445,
       5,   810,   906,   522,  1490,   906,   482,   676,    20,   445,
    1490,    20,  1274,   906,   906,   906,   906,   906,   906,   906,
     906,   906,   906,   906,   906,   906,   906,   906,   906,   906,
     906,   906,   906,   906,   906,   906,   482,   906,   906,   482,
    1163,   906,   906,   906,   906,   445,     5,   534,   766,   767,
     768,   906,   482,  1173,   510,   674,    26,   670,    26,   445,
     445,     5,   445,   311,     5,   445,     5,   445,   336,   478,
       5,   445,   854,  1006,  1179,  1180,  1182,  1130,  1179,   415,
    1586,  1271,    40,    41,    42,    49,    52,    59,    60,   104,
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
     899,   900,   901,   902,   903,   904,   905,   956,   987,   991,
    1013,  1015,  1018,  1019,  1020,  1021,  1034,  1043,  1067,  1068,
    1070,  1074,  1089,  1090,  1094,  1095,  1096,  1097,  1105,  1120,
    1140,  1151,  1152,  1153,  1157,  1160,  1194,  1197,  1199,  1205,
    1206,  1209,  1212,  1215,  1217,  1219,  1222,  1229,  1234,  1239,
    1240,  1241,  1253,  1254,  1257,  1263,  1266,  1267,  1292,  1307,
    1308,  1309,  1310,  1311,  1323,  1329,  1330,  1350,  1353,  1382,
    1384,  1475,  1476,  1507,  1508,  1515,  1530,  1554,  1569,  1570,
    1575,  1576,  1578,  1582,  1583,  1590,   786,  1108,   675,   698,
    1136,  1137,  1179,    20,   445,   477,   832,   859,    26,   864,
      26,    26,    26,   881,   883,   875,   835,    26,  1006,   997,
     736,    20,   717,  1006,   859,   944,   944,    26,   445,   640,
     944,    24,    26,    26,   640,    24,    26,   856,   945,   998,
     857,   445,   413,   527,   636,  1498,   445,   445,    26,  1471,
     445,   445,   445,   445,   445,   445,   445,   493,   493,   493,
     929,  1490,   493,   929,  1490,   939,   937,   943,   941,    26,
     932,     5,   933,   478,  1173,   842,   445,    20,   832,    26,
     482,    26,    26,   828,    26,   670,   445,     5,  1179,   445,
    1163,  1163,  1163,  1006,    25,  1163,  1216,  1006,    25,  1006,
    1460,   404,  1007,  1008,  1584,  1007,    25,  1006,  1459,  1006,
    1006,  1237,  1001,  1007,  1001,  1006,  1580,  1460,  1006,    26,
     733,  1163,  1314,  1001,  1237,   929,    26,  1012,  1279,  1280,
    1279,   906,   913,  1352,  1459,  1459,   908,   929,  1007,  1516,
    1516,   889,  1237,  1001,  1312,  1163,  1003,  1007,   913,  1516,
    1163,  1237,  1163,  1351,  1516,    25,   636,  1154,  1155,  1163,
    1001,  1001,  1154,  1002,  1007,  1006,  1155,  1001,  1516,  1001,
    1003,  1460,  1163,  1192,  1193,   999,  1007,  1003,   429,   612,
     997,  1069,  1006,   793,  1459,  1004,  1007,    25,   243,  1006,
    1383,  1558,  1560,  1561,  1562,  1563,  1565,   929,  1192,   676,
     929,  1007,  1218,   957,    62,    63,    64,    65,   185,   193,
     202,   205,   248,   255,   312,   337,   344,   346,   356,   384,
     392,   429,   453,   490,   501,   599,   600,   601,   612,   715,
    1083,  1213,  1214,  1163,  1184,  1185,   912,   913,  1228,   954,
     954,  1000,  1007,   929,  1216,  1293,  1163,  1270,    25,   482,
    1163,  1265,  1510,  1264,   913,  1571,   158,   208,   245,   342,
     419,   459,   525,   750,   935,  1006,  1163,  1302,   773,   913,
     999,   640,  1006,  1014,  1141,   913,   999,    26,  1163,  1091,
     999,   913,  1531,   913,  1279,  1006,  1016,  1017,  1003,  1016,
     954,  1003,  1016,   954,  1022,  1016,    25,    26,   438,   538,
    1012,  1072,  1163,  1181,  1183,   118,   327,   399,   443,   619,
     699,   700,   701,   710,   740,  1024,  1026,  1028,  1030,  1032,
    1158,  1159,  1162,   390,   401,   451,   465,   554,  1385,   690,
     691,   965,   966,   967,  1006,  1138,   697,  1137,   445,   355,
     445,   445,   445,   445,   674,     5,   445,   445,   478,   482,
     676,    19,    26,   445,   944,    26,   445,   445,   640,    26,
     640,   676,    18,    19,    20,    25,    26,    36,    37,   117,
     448,   479,   482,   495,   535,   547,   588,   621,   627,   636,
     637,   639,   651,   652,   659,   662,  1006,  1012,  1466,  1468,
    1497,  1499,  1500,  1502,  1503,  1504,  1526,  1527,  1528,  1529,
    1559,  1560,  1564,  1291,   445,  1291,  1291,  1291,  1291,  1291,
    1291,    25,    25,    25,   906,   921,   445,    25,   921,   445,
     445,   445,   445,   445,   445,   445,   768,   766,   478,   355,
     445,   818,   840,   841,   445,   445,   674,   445,  1006,  1297,
    1182,   445,  1287,   107,   108,   137,   138,   139,   506,   592,
     635,  1331,  1332,  1333,  1336,  1339,  1342,  1343,  1344,  1347,
     670,   640,   662,   154,   155,   482,   670,   640,   662,     8,
     675,   478,  1459,   530,  1238,  1181,   162,   163,   164,   646,
     534,   909,   910,   913,  1163,  1188,  1459,   739,   740,   892,
     319,    46,   140,   141,   676,  1235,   511,     5,   669,   676,
     668,   668,  1195,   646,   472,     5,   607,  1044,   511,   709,
    1573,   709,   438,   795,  1163,   597,   668,  1200,  1201,  1202,
     670,    25,  1561,   510,  1566,   381,  1381,   662,   670,   911,
     913,   607,  1558,   911,     8,   604,  1000,    26,   552,   605,
     719,   992,  1163,   992,   992,   992,    25,   230,   357,   363,
     364,   365,   385,   490,   493,   501,   536,   571,   590,   591,
     601,   606,   645,   677,  1087,  1088,   992,   992,   647,  1084,
     740,  1084,  1084,   993,   993,  1084,  1084,   740,     5,   472,
       5,   388,   439,     5,   739,   134,   135,   590,   677,  1075,
     712,  1574,   912,   663,   664,   665,   666,  1269,  1510,  1271,
     913,  1259,  1260,  1261,  1272,  1273,   913,   482,   482,   482,
     482,    25,   769,  1006,   482,  1510,   399,   482,   572,   640,
     629,   774,   781,   772,  1006,    25,  1156,  1163,  1255,     8,
    1258,    14,  1006,  1168,  1175,  1176,  1178,  1186,  1187,  1230,
     216,   399,   595,   628,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    18,    19,    20,    21,    22,    23,    33,
      58,   115,   124,   142,   143,   151,   158,   159,   162,   163,
     164,   165,   168,   169,   208,   230,   236,   243,   245,   250,
     276,   314,   327,   333,   342,   343,   349,   352,   353,   357,
     363,   364,   370,   371,   372,   375,   376,   377,   381,   385,
     387,   394,   395,   396,   397,   399,   400,   404,   405,   407,
     408,   409,   410,   411,   412,   413,   419,   420,   421,   423,
     424,   428,   429,   430,   431,   432,   433,   434,   435,   437,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   478,   479,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   520,   521,   522,   523,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   562,   563,   564,   565,   566,   567,   570,   571,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   688,
     696,   701,   705,   708,   709,   710,   711,   714,   715,   717,
     718,   719,  1532,  1533,  1534,  1536,   626,     5,   709,   709,
     911,  1181,  1188,  1071,   472,     5,   204,  1049,   482,  1163,
     911,   482,    26,    26,   118,  1161,    25,  1163,  1514,  1514,
    1007,  1365,  1218,  1000,   172,   274,   282,   288,   290,   301,
     329,   345,   350,   362,   369,   517,   522,   529,   551,   556,
    1354,  1355,  1363,  1372,  1373,  1379,  1380,  1386,  1387,  1397,
    1417,  1421,  1486,  1487,  1517,  1518,  1521,  1522,  1538,   968,
     969,   143,   964,   975,   976,   967,  1139,  1585,  1114,   510,
     872,   835,   670,  1006,   859,    26,   445,   640,   944,   445,
     640,   944,   944,    24,    26,   640,    24,    26,   860,  1503,
    1503,   420,   505,   521,   564,   603,   632,   641,  1469,  1472,
     522,  1502,   482,   482,   482,   482,  1497,  1497,  1497,   482,
     482,   482,   482,  1006,   482,     5,   597,  1426,  1431,   667,
    1006,    18,    19,    20,    21,   144,   145,   146,   147,   148,
     149,  1524,  1472,  1472,   472,     5,   445,   445,   934,   510,
       5,   445,   842,   812,  1131,   812,   298,   311,   413,   482,
     527,   543,  1401,  1402,  1407,  1409,   482,  1006,  1348,  1349,
      26,   482,  1006,  1328,  1341,  1409,  1411,   482,  1006,  1338,
     482,  1328,  1334,     5,  1006,    25,  1006,  1006,    25,  1009,
    1166,  1006,    25,  1006,  1006,  1006,  1581,  1459,   646,   482,
     482,   892,  1459,     5,   676,   482,  1558,    25,  1011,  1236,
    1235,  1236,  1510,  1154,   913,   913,   913,   994,   995,   482,
    1163,  1193,  1045,  1046,  1047,  1459,   676,  1510,   954,  1574,
    1069,  1163,   794,   675,   913,   405,  1204,   607,  1203,  1562,
     736,  1567,  1568,  1006,    20,  1563,     5,  1555,   667,  1210,
     121,   123,   125,   668,   676,   884,  1181,  1184,   958,    18,
      19,   482,  1085,  1087,  1214,  1163,  1185,   993,   913,   399,
     646,    26,  1163,    26,  1163,   739,   206,  1268,   445,   437,
    1306,  1271,  1261,     5,   668,  1262,  1572,  1006,    25,   954,
     954,   640,   998,   673,  1163,   754,  1006,  1006,   913,   394,
     777,   781,   629,   775,   783,    23,   287,  1143,  1147,   533,
     929,   533,  1256,   913,   509,  1172,   670,     5,  1092,   597,
    1231,  1163,  1535,  1537,   242,  1533,  1035,  1017,   954,   954,
    1027,  1028,  1049,  1049,    43,    44,    45,    48,    50,    51,
     323,   326,   328,   348,   358,   379,   402,   406,   481,  1048,
    1050,  1051,  1079,  1163,  1183,   597,   741,    26,   452,  1033,
     376,  1509,  1509,   191,   192,   488,   597,  1006,  1418,  1419,
    1461,  1459,  1459,  1459,  1356,  1459,  1459,  1006,  1519,   220,
     433,   447,   490,   501,   522,   529,   537,   559,   636,   642,
    1388,  1390,  1391,  1392,  1498,  1459,  1364,  1388,  1390,  1585,
    1585,   438,   977,  1163,   692,   693,   970,   971,   972,   532,
     675,   694,   695,   714,   980,   981,  1585,   812,    26,   833,
      20,  1006,   445,    26,   445,   944,    26,   944,    24,    26,
     445,   445,    24,    26,   676,  1498,   445,   448,  1502,  1525,
    1564,   413,   527,   636,  1450,  1502,  1505,  1450,  1450,  1450,
    1450,   670,  1505,  1500,   566,  1427,  1428,  1429,  1459,   577,
    1425,  1432,   386,   565,   576,  1374,  1493,  1006,  1502,  1502,
    1502,  1502,   676,   482,   676,  1559,   906,   445,   833,   841,
    1298,   812,  1288,   482,   482,   482,  1345,  1409,   482,   482,
     110,  1346,  1348,     5,  1340,  1341,   116,   352,   372,   373,
     374,   411,   423,   434,   450,   460,   475,   523,   553,   563,
     584,   588,   616,   625,  1451,  1452,  1453,  1455,  1337,  1338,
    1334,  1335,   714,  1332,   670,   640,   445,   670,   640,   597,
    1579,   482,   734,   735,  1006,  1315,   929,   909,  1006,  1313,
     667,  1207,  1235,  1235,   676,     5,     5,     5,   630,   913,
       5,   670,   534,   676,   675,   217,   219,   323,   326,   796,
     799,   800,  1079,   797,   798,  1006,   482,  1007,   699,   700,
    1208,     5,   478,   913,  1459,  1556,  1557,  1558,   627,   667,
    1211,  1006,  1006,   995,   996,   560,   954,   892,     8,     8,
     960,    26,    26,  1086,  1087,  1163,   372,  1223,   118,   906,
    1271,   271,  1273,  1279,  1585,     5,     5,   445,   445,   770,
    1006,   445,  1510,   766,   482,   482,   782,   778,   414,   776,
     913,   394,   779,   783,   647,  1081,  1148,  1144,   416,  1142,
    1143,   911,   676,  1169,    20,  1006,  1177,  1187,    14,   534,
    1232,  1233,  1502,  1564,  1184,  1585,  1029,  1030,   601,  1005,
     597,  1062,  1061,  1060,  1059,  1064,  1063,   997,  1065,   997,
    1066,  1058,  1057,  1055,  1054,  1080,   379,  1051,  1056,   954,
      53,    54,    55,    56,    57,    58,   150,   387,   400,   462,
     468,   507,   531,   541,   542,   547,   557,   579,   582,   583,
     587,   644,   655,   742,   743,  1077,  1078,     5,    26,  1510,
     301,  1163,   522,  1491,  1492,  1510,  1218,  1485,  1487,   152,
     152,   646,  1216,  1420,  1421,   482,  1398,   203,  1432,  1459,
     227,   324,  1523,   670,   676,   482,  1393,  1393,   597,   675,
       5,  1488,  1539,   396,   405,   429,   432,   448,   552,   605,
     612,  1000,  1366,  1371,   676,   675,   979,  1163,     5,   597,
     973,   974,   689,   972,   978,  1006,   978,   982,   983,   978,
     379,   981,  1115,   478,   445,   640,   944,   445,   640,   445,
     445,   944,   944,   420,   505,   521,   564,   603,   632,   641,
    1473,  1499,     5,  1472,     5,   445,     5,  1502,     5,   445,
    1502,  1502,  1502,  1502,  1006,   445,   482,  1429,     5,  1006,
    1465,     9,   347,   482,   494,  1435,  1436,  1437,  1438,  1439,
    1443,  1447,  1449,  1502,   422,  1423,  1433,  1006,  1494,   669,
    1450,   386,  1473,    26,  1473,   478,   512,  1281,  1301,  1132,
     512,  1242,  1275,   662,  1006,  1404,  1406,  1459,  1463,  1464,
    1408,  1463,  1408,     5,   445,  1346,  1408,  1435,  1006,   445,
    1349,     5,   445,   482,   482,   482,  1472,  1472,   482,   482,
     482,   482,   482,   259,   260,   261,   452,  1410,  1412,     5,
     445,     5,   445,  1006,  1006,    25,  1006,  1006,    25,  1006,
     913,  1006,  1325,  1326,     5,  1327,  1328,   929,  1121,   670,
    1327,   627,  1510,  1510,   913,   913,   994,   560,   913,  1577,
       5,  1046,    20,  1463,  1510,   797,   805,   804,   806,  1006,
    1010,   807,  1010,   244,   800,   803,     5,  1049,   670,   913,
       8,  1568,   510,   670,     5,  1510,   627,  1006,  1181,   929,
     604,  1369,     5,   445,  1163,     5,    26,  1163,   380,    25,
    1303,   399,   399,   510,   670,   399,   482,   755,   759,   752,
    1585,  1585,   784,   780,   776,  1082,    25,  1005,  1149,  1163,
    1585,   913,   477,   510,   929,     5,  1036,  1031,  1032,    26,
     739,  1006,  1585,  1585,  1585,  1585,  1585,  1585,     5,  1052,
       5,  1053,  1585,  1585,  1585,  1585,  1085,  1585,  1005,    25,
      14,    14,     5,   445,    26,  1459,  1498,  1479,   646,   646,
    1355,  1484,  1485,  1421,  1399,  1463,   667,  1000,   482,  1359,
    1006,  1520,  1519,  1394,  1463,   514,  1395,  1396,  1461,  1459,
    1392,  1499,    98,    99,   100,   101,   102,   634,  1542,   913,
     913,   604,  1367,  1000,  1395,  1459,     5,  1163,   978,  1585,
    1585,     5,   985,   986,  1585,  1585,   984,  1108,   876,   944,
      26,   944,    24,    26,   944,   944,   482,  1431,  1472,   676,
    1472,  1472,   445,  1502,   445,   445,   445,   445,  1428,  1430,
    1428,  1438,  1497,  1435,  1502,  1497,     6,     7,     9,    10,
      12,    13,    14,    15,    16,    17,   305,   425,   426,   480,
     607,   673,   723,   724,  1446,  1448,  1424,  1501,  1502,   499,
    1422,  1434,   321,  1324,    26,  1375,  1376,  1377,  1463,  1491,
    1494,   445,   830,   126,   127,   129,   130,   131,   229,   237,
     271,   280,   309,   310,   354,   398,   452,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,  1278,  1282,   190,
     565,  1283,  1299,  1108,   213,   228,   229,   237,   271,   280,
     309,   354,   398,  1276,  1277,  1289,  1283,  1464,   510,  1462,
     445,     5,   670,     5,   445,   445,  1409,   445,   445,  1341,
      26,  1456,  1456,    26,   676,   482,   676,    26,  1457,    26,
      26,  1457,  1457,    25,  1466,   211,   311,   349,   413,   427,
     527,   543,  1403,  1413,  1414,  1415,  1416,  1338,  1334,   670,
     670,   589,   638,     5,   445,   735,     5,   445,   911,   445,
      20,   445,  1510,     5,   913,   617,   327,   744,   745,   913,
    1049,  1585,  1585,     5,   801,   510,   670,     5,   802,  1585,
     798,   597,    20,  1006,     5,  1006,  1198,  1567,    20,  1463,
    1557,     8,  1510,   443,   709,   911,  1370,   959,  1087,   718,
    1221,   906,     5,   766,  1163,   751,   733,  1006,  1163,   757,
     445,   766,   766,  1585,  1585,  1085,  1146,    25,  1150,  1163,
     622,   990,  1173,   534,   912,  1093,  1233,   115,   593,  1037,
    1023,  1024,   670,   997,  1585,   997,  1585,   739,    26,  1163,
      26,  1163,   743,   445,   482,  1511,  1499,  1485,  1485,  1477,
       5,   445,   522,  1496,  1360,  1463,   530,  1357,  1496,   676,
       5,   445,     5,   597,  1489,    18,    19,   117,   479,   482,
     495,   534,   535,   547,   588,   627,   639,   651,   652,   659,
     662,  1006,  1466,  1497,  1526,  1528,  1547,  1548,  1549,  1550,
    1551,  1552,  1564,  1547,  1547,  1547,  1463,  1544,  1546,  1543,
    1544,  1545,  1540,  1368,   676,  1163,  1006,  1585,  1585,  1585,
    1585,   674,   445,   640,   445,   445,    26,   445,   676,  1473,
     676,   676,     5,   445,   445,  1436,  1437,  1441,  1503,  1441,
     482,  1497,  1441,   482,  1497,  1441,    10,   302,   440,   442,
    1502,     5,  1435,     5,   589,   638,  1378,  1324,   676,   674,
    1279,  1279,  1279,    25,  1279,  1279,  1279,  1279,  1279,  1279,
      25,    25,  1279,  1282,  1163,  1189,  1190,   669,   498,  1243,
    1585,    25,    25,    26,    26,    26,    26,    26,    25,  1163,
    1277,  1243,    26,  1403,  1463,    20,  1006,  1463,  1346,   445,
     445,     5,   445,  1473,    26,  1473,     5,  1454,     5,   445,
     445,   445,  1454,  1405,  1459,   482,  1415,  1346,  1006,  1006,
    1326,   673,   727,  1320,  1321,  1322,  1328,    61,   138,   139,
     297,   673,  1316,  1317,  1318,   519,   891,  1316,     5,   428,
    1510,     5,   482,   445,   601,  1076,  1010,  1585,   736,    20,
    1006,  1010,  1585,   954,   913,   478,  1510,     8,   954,  1184,
    1585,    26,  1005,    25,  1304,  1181,   478,   766,   756,   760,
     445,  1585,  1005,   913,   988,   478,  1039,  1038,   492,  1025,
    1026,    20,  1006,  1512,  1513,   604,  1495,  1480,  1478,  1463,
    1498,   195,  1400,     5,   445,  1358,  1520,  1463,  1396,  1395,
    1495,  1550,  1550,  1549,   482,   482,   482,   482,   482,   482,
     482,  1006,   482,     5,   445,    18,    19,    20,    21,  1524,
     445,     5,   445,     5,    14,   203,   577,  1541,  1184,  1395,
     264,  1116,   872,   944,    24,    26,   944,   944,   445,  1473,
    1473,  1473,  1428,   493,  1440,  1440,  1444,  1445,  1466,  1564,
    1440,  1444,  1440,  1441,  1502,  1501,  1376,  1473,   842,   589,
     638,  1191,     5,  1189,   114,   189,   251,   253,   269,   277,
     281,   306,  1244,  1245,  1300,  1116,  1290,     5,   478,  1462,
      26,   445,    26,  1458,   445,    26,   445,   482,  1435,  1319,
    1584,    26,  1322,    26,    26,  1319,  1324,  1318,   997,   739,
     428,  1510,   913,   746,   619,  1196,    26,   739,   478,  1076,
     445,  1510,   293,   739,   445,   445,   482,   758,   399,   764,
     445,   753,  1145,  1585,   510,   913,  1585,  1005,     5,   445,
    1184,  1431,  1499,  1463,   482,  1431,   445,  1525,  1450,  1549,
    1553,  1450,  1450,  1450,  1450,   510,   670,  1553,  1548,  1549,
    1549,  1549,  1549,  1544,    14,  1545,  1548,  1000,  1435,   196,
     667,  1389,   445,   445,  1442,  1466,  1506,     5,   445,   445,
    1440,     7,  1190,  1246,  1247,  1163,  1249,  1163,  1248,  1250,
    1245,   292,   292,    26,   445,   676,   445,  1406,   445,   890,
    1510,   446,   255,   312,   337,   346,   384,   392,   483,   653,
     743,   747,   748,   482,   670,   739,  1220,  1305,   761,   445,
    1181,   764,   764,  1585,   989,  1173,   626,  1073,  1513,  1493,
    1431,   534,  1361,  1362,  1502,  1493,   445,  1549,     5,   445,
    1549,  1549,  1549,  1549,    26,  1006,   445,   482,  1006,   944,
     944,  1445,  1502,  1585,  1585,  1251,  1585,  1252,  1585,  1585,
     478,  1473,   445,   291,   402,   406,   893,   894,   895,  1079,
     992,   992,   992,   992,   992,   992,    25,     5,   445,   913,
      20,  1006,  1079,  1224,  1225,  1226,   764,   766,   764,   294,
     478,  1040,   739,     5,   445,   340,   341,  1481,   445,  1549,
     445,   445,   445,   445,     5,   478,   510,  1547,  1585,  1585,
     897,   896,   291,   895,   898,   748,     5,  1227,   335,  1226,
     762,  1585,  1362,    25,  1006,  1482,  1483,    26,    26,   445,
    1585,  1585,  1585,   913,  1585,   445,  1037,   670,   670,     5,
     478,     5,   478,   445,   763,  1006,  1006,  1483,    26,   216,
     399,   765,   670,   478,  1181,  1006
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
#line 1001 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1004 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1008 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1014 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1019 "fgl.yacc"
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
#line 1031 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1036 "fgl.yacc"
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
#line 1059 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1060 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1061 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1062 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1063 "fgl.yacc"
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
#line 1074 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1080 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1081 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1083 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1084 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1089 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1090 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1101 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1104 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1107 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1107 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1114 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1115 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1136 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1137 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1144 "fgl.yacc"
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
#line 1155 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1159 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1160 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1164 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1170 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1172 "fgl.yacc"
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
#line 1183 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1185 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1187 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1189 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1193 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1195 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1256 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1260 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1264 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1271 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1274 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1278 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1282 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1289 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1295 "fgl.yacc"
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
#line 1304 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1308 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1313 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1317 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1325 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1329 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1333 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1335 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1341 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1346 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1349 "fgl.yacc"
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
#line 1365 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1372 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1376 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1380 "fgl.yacc"
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
#line 1402 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1402 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1406 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1407 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1408 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1413 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1416 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1422 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1425 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1434 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1438 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1444 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1447 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1462 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1472 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1478 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1487 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1500 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1503 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1505 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1511 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1513 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1518 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1523 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1529 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1533 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1548 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1551 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1554 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1557 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1560 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1563 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1585 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1594 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1613 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1618 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1621 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1630 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1636 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1651 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1655 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1660 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1670 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1670 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1671 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1671 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1672 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1672 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1673 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1673 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1674 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1674 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1682 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1686 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1692 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1696 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1711 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1714 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1717 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1720 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1723 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1726 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1735 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1743 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1748 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1761 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1765 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1780 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1781 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1789 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1789 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1798 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1798 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1807 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1808 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1809 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1812 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1817 "fgl.yacc"
    { }
    break;

  case 194:
#line 1817 "fgl.yacc"
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
#line 1834 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1838 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1853 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1854 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1855 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1856 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1861 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1867 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1876 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1880 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1896 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1898 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1899 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1906 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1906 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1907 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1908 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1911 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1913 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1923 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1938 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1938 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1944 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1945 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1946 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1947 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1948 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1949 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1950 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1951 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1952 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1953 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1956 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1957 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1958 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1959 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1963 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1968 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1973 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1977 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1980 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1984 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1985 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1986 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1987 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1988 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1989 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1990 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1991 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1992 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1995 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1996 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1997 "fgl.yacc"
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
#line 2032 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2036 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2038 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2040 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2042 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2047 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2051 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2051 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2056 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2057 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2058 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2059 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2060 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2062 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2067 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2067 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2070 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2072 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2078 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2080 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2086 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2094 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2094 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2098 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2099 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2100 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2101 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2102 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2104 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2125 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2134 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2136 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2137 "fgl.yacc"
    {
						dim_push_type("varchar",yyvsp[-1].str,0);
				}
    break;

  case 317:
#line 2140 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 318:
#line 2144 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2145 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2146 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2147 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2152 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2159 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2164 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2166 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2168 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2169 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2170 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2171 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2172 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2173 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2174 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2177 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2179 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2185 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2193 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2201 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2205 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2213 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2214 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2215 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2216 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2235 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2247 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2251 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2254 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2257 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2258 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2259 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2260 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2261 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2267 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2274 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2279 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2284 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2289 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2293 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2302 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2304 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2309 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2321 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2325 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2328 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2332 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2335 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2339 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
#line 2346 "fgl.yacc"
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
#line 2364 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2370 "fgl.yacc"
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
#line 2394 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2397 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2412 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 384:
#line 2415 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2429 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 386:
#line 2431 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 387:
#line 2433 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 388:
#line 2435 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 389:
#line 2437 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 390:
#line 2439 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 391:
#line 2440 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 392:
#line 2447 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 393:
#line 2449 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 394:
#line 2453 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 395:
#line 2455 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 396:
#line 2457 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 397:
#line 2459 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 398:
#line 2461 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 399:
#line 2463 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 400:
#line 2465 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 401:
#line 2471 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 405:
#line 2490 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 408:
#line 2496 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 409:
#line 2500 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 410:
#line 2505 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 414:
#line 2515 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 415:
#line 2516 "fgl.yacc"
    {inc_counter();}
    break;

  case 421:
#line 2522 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 422:
#line 2529 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 423:
#line 2529 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 425:
#line 2534 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 426:
#line 2538 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 427:
#line 2544 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2552 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2558 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2567 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 431:
#line 2569 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 432:
#line 2576 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 433:
#line 2597 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 434:
#line 2602 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 435:
#line 2607 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 436:
#line 2611 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 437:
#line 2613 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 438:
#line 2616 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 439:
#line 2634 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 440:
#line 2640 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 441:
#line 2646 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2656 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 445:
#line 2662 "fgl.yacc"
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
#line 2734 "fgl.yacc"
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
#line 2745 "fgl.yacc"
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
#line 2753 "fgl.yacc"
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
#line 2761 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 450:
#line 2761 "fgl.yacc"
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
#line 2777 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 452:
#line 2781 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 453:
#line 2787 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 454:
#line 2790 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 455:
#line 2798 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 456:
#line 2802 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 457:
#line 2805 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 458:
#line 2811 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 459:
#line 2821 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 460:
#line 2826 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 461:
#line 2833 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 462:
#line 2836 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 463:
#line 2839 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 464:
#line 2844 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 465:
#line 2851 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 466:
#line 2856 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 467:
#line 2861 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 468:
#line 2866 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 469:
#line 2877 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 470:
#line 2885 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 471:
#line 2893 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 472:
#line 2898 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 473:
#line 2902 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 474:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 475:
#line 2911 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 476:
#line 2915 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 477:
#line 2921 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 478:
#line 2924 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 479:
#line 2928 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 480:
#line 2932 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 481:
#line 2936 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 482:
#line 2940 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 483:
#line 2944 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 484:
#line 2951 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 485:
#line 2961 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 486:
#line 2966 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 487:
#line 2972 "fgl.yacc"
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
#line 2982 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 489:
#line 2987 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 490:
#line 2990 "fgl.yacc"
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
#line 3004 "fgl.yacc"
    {chk4var=1;}
    break;

  case 492:
#line 3004 "fgl.yacc"
    {chk4var=0;}
    break;

  case 493:
#line 3004 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 494:
#line 3007 "fgl.yacc"
    {chk4var=1;}
    break;

  case 495:
#line 3007 "fgl.yacc"
    {chk4var=0;}
    break;

  case 496:
#line 3007 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 497:
#line 3011 "fgl.yacc"
    {chk4var=1;}
    break;

  case 498:
#line 3011 "fgl.yacc"
    {chk4var=0;}
    break;

  case 499:
#line 3011 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 500:
#line 3015 "fgl.yacc"
    {chk4var=1;}
    break;

  case 501:
#line 3015 "fgl.yacc"
    {chk4var=0;}
    break;

  case 502:
#line 3015 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 503:
#line 3019 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 504:
#line 3025 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 505:
#line 3031 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 506:
#line 3037 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 507:
#line 3045 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 508:
#line 3051 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3059 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3065 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3074 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3080 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3087 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3094 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 515:
#line 3103 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 516:
#line 3109 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 517:
#line 3115 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 518:
#line 3122 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 519:
#line 3128 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 520:
#line 3134 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3140 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3148 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3154 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3160 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3169 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 526:
#line 3175 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 527:
#line 3181 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 528:
#line 3191 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 529:
#line 3192 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 532:
#line 3200 "fgl.yacc"
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
#line 3211 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 534:
#line 3212 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 535:
#line 3218 "fgl.yacc"
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
#line 3229 "fgl.yacc"
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
#line 3239 "fgl.yacc"
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
#line 3252 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 541:
#line 3257 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 542:
#line 3264 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 543:
#line 3268 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 544:
#line 3271 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 545:
#line 3274 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 546:
#line 3280 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 547:
#line 3283 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 548:
#line 3286 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 549:
#line 3303 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 550:
#line 3306 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 551:
#line 3312 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 552:
#line 3313 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 553:
#line 3314 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 555:
#line 3319 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 556:
#line 3320 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 557:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 558:
#line 3322 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 559:
#line 3324 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 560:
#line 3325 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 561:
#line 3326 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 562:
#line 3328 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 563:
#line 3329 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 565:
#line 3335 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 566:
#line 3339 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 567:
#line 3343 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 568:
#line 3348 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 569:
#line 3352 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 570:
#line 3367 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 571:
#line 3371 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 572:
#line 3377 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 573:
#line 3381 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 574:
#line 3390 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 575:
#line 3391 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 576:
#line 3403 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 577:
#line 3409 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 578:
#line 3417 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 585:
#line 3434 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 586:
#line 3436 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 587:
#line 3439 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 588:
#line 3441 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 593:
#line 3455 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 594:
#line 3457 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 595:
#line 3460 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 596:
#line 3462 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 609:
#line 3493 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 610:
#line 3495 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 611:
#line 3498 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 612:
#line 3500 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 613:
#line 3503 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 614:
#line 3505 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 615:
#line 3508 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 616:
#line 3510 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 617:
#line 3513 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 618:
#line 3515 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 619:
#line 3529 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 620:
#line 3533 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 621:
#line 3534 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 622:
#line 3541 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 624:
#line 3559 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 625:
#line 3575 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 626:
#line 3576 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 627:
#line 3577 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 628:
#line 3578 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 629:
#line 3579 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 630:
#line 3580 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 631:
#line 3581 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 635:
#line 3589 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 637:
#line 3595 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 638:
#line 3598 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 639:
#line 3603 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 640:
#line 3608 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 641:
#line 3611 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 642:
#line 3616 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 643:
#line 3621 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 644:
#line 3626 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 645:
#line 3633 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 646:
#line 3634 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 647:
#line 3641 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 648:
#line 3648 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 649:
#line 3650 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 650:
#line 3656 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 651:
#line 3661 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 652:
#line 3666 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 653:
#line 3671 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 654:
#line 3671 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 655:
#line 3674 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 656:
#line 3680 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 657:
#line 3685 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 658:
#line 3689 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 661:
#line 3697 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 662:
#line 3700 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 663:
#line 3703 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 664:
#line 3708 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 665:
#line 3713 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 666:
#line 3718 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 667:
#line 3725 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 669:
#line 3734 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 670:
#line 3796 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 672:
#line 3805 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 673:
#line 3814 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 675:
#line 3821 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 676:
#line 3824 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 677:
#line 3830 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 678:
#line 3836 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 679:
#line 3840 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 680:
#line 3844 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 681:
#line 3850 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 682:
#line 3854 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 683:
#line 3858 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 684:
#line 3863 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 685:
#line 3868 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 704:
#line 3909 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 705:
#line 3916 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 706:
#line 3918 "fgl.yacc"
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
#line 3937 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 710:
#line 3940 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 711:
#line 3942 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 712:
#line 3945 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 713:
#line 3949 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 714:
#line 3952 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 715:
#line 3958 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 716:
#line 3969 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 717:
#line 3970 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 718:
#line 3973 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 720:
#line 3979 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 721:
#line 3983 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 722:
#line 3984 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 723:
#line 3988 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 727:
#line 4003 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 728:
#line 4005 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 731:
#line 4014 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 732:
#line 4017 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 733:
#line 4021 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 734:
#line 4024 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 735:
#line 4027 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 736:
#line 4030 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 737:
#line 4033 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 738:
#line 4037 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 739:
#line 4040 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 740:
#line 4043 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 741:
#line 4046 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 742:
#line 4049 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 743:
#line 4052 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 744:
#line 4055 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 745:
#line 4058 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 746:
#line 4061 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 747:
#line 4062 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 748:
#line 4062 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 749:
#line 4063 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 750:
#line 4063 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 751:
#line 4064 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 752:
#line 4064 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 753:
#line 4065 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 754:
#line 4068 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 755:
#line 4069 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 756:
#line 4072 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 757:
#line 4080 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 758:
#line 4084 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 759:
#line 4090 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 760:
#line 4094 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 761:
#line 4099 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 762:
#line 4104 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 763:
#line 4109 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 764:
#line 4110 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 765:
#line 4111 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 766:
#line 4115 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 767:
#line 4119 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 768:
#line 4128 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 769:
#line 4133 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 770:
#line 4137 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 771:
#line 4144 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 772:
#line 4153 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 773:
#line 4159 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 774:
#line 4160 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 775:
#line 4161 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 776:
#line 4162 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 777:
#line 4163 "fgl.yacc"
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
#line 4173 "fgl.yacc"
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
#line 4187 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 781:
#line 4190 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 782:
#line 4197 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 783:
#line 4198 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 784:
#line 4199 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 785:
#line 4200 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 786:
#line 4201 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 787:
#line 4202 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 788:
#line 4203 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 789:
#line 4204 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 790:
#line 4205 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 791:
#line 4210 "fgl.yacc"
    {iskey=1;}
    break;

  case 792:
#line 4210 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 793:
#line 4212 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 794:
#line 4215 "fgl.yacc"
    {iskey=1;}
    break;

  case 795:
#line 4215 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 796:
#line 4217 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 797:
#line 4221 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 798:
#line 4224 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 799:
#line 4225 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 801:
#line 4228 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 807:
#line 4240 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 808:
#line 4241 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 809:
#line 4242 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 810:
#line 4243 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 811:
#line 4244 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 812:
#line 4245 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 813:
#line 4246 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 814:
#line 4247 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 815:
#line 4248 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 816:
#line 4249 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 817:
#line 4250 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 818:
#line 4251 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 819:
#line 4252 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 820:
#line 4253 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 821:
#line 4257 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 822:
#line 4275 "fgl.yacc"
    {chk4var=1;}
    break;

  case 823:
#line 4275 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 824:
#line 4278 "fgl.yacc"
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
#line 4302 "fgl.yacc"
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
#line 4320 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 828:
#line 4326 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 829:
#line 4332 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 830:
#line 4338 "fgl.yacc"
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
#line 4350 "fgl.yacc"
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
#line 4375 "fgl.yacc"
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
#line 4391 "fgl.yacc"
    {
	}
    break;

  case 844:
#line 4416 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 848:
#line 4424 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 863:
#line 4450 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 864:
#line 4451 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 865:
#line 4459 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 866:
#line 4464 "fgl.yacc"
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
#line 4480 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 868:
#line 4486 "fgl.yacc"
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
#line 4501 "fgl.yacc"
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
#line 4514 "fgl.yacc"
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
#line 4524 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 873:
#line 4531 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 874:
#line 4538 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 875:
#line 4544 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 876:
#line 4544 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 877:
#line 4549 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 878:
#line 4555 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 879:
#line 4563 "fgl.yacc"
    {
}
    break;

  case 883:
#line 4575 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 885:
#line 4583 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 886:
#line 4589 "fgl.yacc"
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
#line 4605 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 890:
#line 4609 "fgl.yacc"
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
#line 4622 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 893:
#line 4635 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 894:
#line 4641 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 895:
#line 4645 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 898:
#line 4657 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 899:
#line 4660 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 900:
#line 4664 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 901:
#line 4667 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 902:
#line 4679 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 903:
#line 4687 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 904:
#line 4693 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 905:
#line 4704 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 906:
#line 4708 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 907:
#line 4715 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 908:
#line 4722 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 909:
#line 4728 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 910:
#line 4733 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 913:
#line 4740 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 914:
#line 4741 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 915:
#line 4743 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 916:
#line 4744 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 917:
#line 4747 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 918:
#line 4748 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 919:
#line 4749 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 920:
#line 4751 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 921:
#line 4756 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 922:
#line 4761 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 923:
#line 4768 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 927:
#line 4775 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 928:
#line 4777 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 929:
#line 4779 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 931:
#line 4789 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 932:
#line 4792 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 933:
#line 4795 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 940:
#line 4811 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 941:
#line 4816 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 942:
#line 4816 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 943:
#line 4819 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 944:
#line 4847 "fgl.yacc"
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
#line 4904 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 948:
#line 4911 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 949:
#line 4915 "fgl.yacc"
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
#line 4958 "fgl.yacc"
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
#line 5006 "fgl.yacc"
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
#line 5020 "fgl.yacc"
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
#line 5044 "fgl.yacc"
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
#line 5108 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 962:
#line 5113 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 963:
#line 5121 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 964:
#line 5126 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 965:
#line 5134 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 966:
#line 5140 "fgl.yacc"
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
#line 5172 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 968:
#line 5175 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 969:
#line 5177 "fgl.yacc"
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
#line 5218 "fgl.yacc"
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
#line 5271 "fgl.yacc"
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
#line 5323 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 978:
#line 5332 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 979:
#line 5337 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 980:
#line 5348 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 981:
#line 5355 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 983:
#line 5363 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 984:
#line 5366 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 985:
#line 5367 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 987:
#line 5369 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 988:
#line 5370 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 989:
#line 5373 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 990:
#line 5376 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 991:
#line 5382 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 992:
#line 5385 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 993:
#line 5389 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 994:
#line 5394 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 995:
#line 5402 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 996:
#line 5407 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 997:
#line 5414 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 998:
#line 5416 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1003:
#line 5444 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1004:
#line 5451 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1005:
#line 5458 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1006:
#line 5461 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1007:
#line 5475 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1012:
#line 5492 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1013:
#line 5497 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1014:
#line 5503 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1016:
#line 5510 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1017:
#line 5515 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1018:
#line 5518 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1019:
#line 5519 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1020:
#line 5522 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1021:
#line 5523 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1022:
#line 5526 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1023:
#line 5527 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1024:
#line 5532 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1025:
#line 5539 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1026:
#line 5542 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1027:
#line 5548 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1028:
#line 5550 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1029:
#line 5552 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1030:
#line 5554 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1031:
#line 5557 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1032:
#line 5557 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1033:
#line 5558 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1034:
#line 5563 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1035:
#line 5571 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1036:
#line 5572 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1037:
#line 5577 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1038:
#line 5579 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1039:
#line 5581 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1043:
#line 5599 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1044:
#line 5600 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1045:
#line 5601 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1046:
#line 5602 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1047:
#line 5603 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1048:
#line 5604 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1049:
#line 5605 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1050:
#line 5606 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1051:
#line 5607 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1052:
#line 5608 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1053:
#line 5609 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1054:
#line 5610 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1055:
#line 5611 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1056:
#line 5612 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1057:
#line 5613 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1058:
#line 5614 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1059:
#line 5615 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1060:
#line 5616 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1061:
#line 5617 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1062:
#line 5618 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1063:
#line 5619 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1064:
#line 5620 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1065:
#line 5621 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1066:
#line 5622 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1067:
#line 5623 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1068:
#line 5624 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1069:
#line 5639 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1072:
#line 5648 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1073:
#line 5652 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1074:
#line 5656 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1075:
#line 5660 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1076:
#line 5664 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1078:
#line 5684 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1079:
#line 5689 "fgl.yacc"
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
#line 5702 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1081:
#line 5703 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1082:
#line 5707 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1083:
#line 5712 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1084:
#line 5713 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1085:
#line 5717 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1089:
#line 5723 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1090:
#line 5726 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1092:
#line 5741 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1093:
#line 5745 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1094:
#line 5751 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1095:
#line 5752 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1096:
#line 5757 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1097:
#line 5758 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1098:
#line 5761 "fgl.yacc"
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
#line 5788 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1101:
#line 5792 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1102:
#line 5796 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1103:
#line 5800 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1104:
#line 5807 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1105:
#line 5808 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1111:
#line 5820 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1112:
#line 5826 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1113:
#line 5834 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1114:
#line 5840 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1115:
#line 5842 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1119:
#line 5852 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1120:
#line 5852 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1121:
#line 5857 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1122:
#line 5861 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1123:
#line 5866 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1124:
#line 5866 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1125:
#line 5870 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1126:
#line 5870 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1127:
#line 5871 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1128:
#line 5871 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1129:
#line 5872 "fgl.yacc"
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
#line 5885 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1131:
#line 5886 "fgl.yacc"
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
#line 5902 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1139:
#line 5914 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1140:
#line 5914 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1141:
#line 5920 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1142:
#line 5920 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1143:
#line 5923 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1144:
#line 5923 "fgl.yacc"
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
#line 5939 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1146:
#line 5940 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1147:
#line 5941 "fgl.yacc"
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
#line 5950 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1149:
#line 5962 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1155:
#line 5973 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1156:
#line 5978 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1157:
#line 5978 "fgl.yacc"
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

  case 1159:
#line 6002 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1160:
#line 6008 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1161:
#line 6013 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1162:
#line 6019 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1163:
#line 6020 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1164:
#line 6021 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1165:
#line 6025 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1166:
#line 6026 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1167:
#line 6027 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1168:
#line 6028 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1169:
#line 6032 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1170:
#line 6042 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1171:
#line 6044 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1172:
#line 6049 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1173:
#line 6052 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1174:
#line 6057 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1175:
#line 6064 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1176:
#line 6071 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1177:
#line 6078 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1178:
#line 6087 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1179:
#line 6094 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1180:
#line 6101 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1181:
#line 6108 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1182:
#line 6115 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1187:
#line 6128 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1188:
#line 6129 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1189:
#line 6130 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1190:
#line 6131 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1191:
#line 6132 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1192:
#line 6133 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1193:
#line 6134 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1194:
#line 6135 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1195:
#line 6136 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1196:
#line 6137 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1199:
#line 6143 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1200:
#line 6144 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1201:
#line 6145 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1202:
#line 6146 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1207:
#line 6155 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1208:
#line 6156 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1209:
#line 6157 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1210:
#line 6158 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1211:
#line 6159 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1212:
#line 6160 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1213:
#line 6161 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1214:
#line 6162 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1215:
#line 6164 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1216:
#line 6165 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1217:
#line 6166 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1218:
#line 6167 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1219:
#line 6169 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1220:
#line 6170 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1221:
#line 6171 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1222:
#line 6172 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1226:
#line 6177 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1227:
#line 6178 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1231:
#line 6185 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1232:
#line 6194 "fgl.yacc"
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

  case 1233:
#line 6203 "fgl.yacc"
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

  case 1234:
#line 6216 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1235:
#line 6225 "fgl.yacc"
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

  case 1236:
#line 6236 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1237:
#line 6240 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1238:
#line 6244 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1239:
#line 6250 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1240:
#line 6255 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1241:
#line 6263 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1242:
#line 6266 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1243:
#line 6275 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1244:
#line 6286 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1246:
#line 6293 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1247:
#line 6301 "fgl.yacc"
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

  case 1248:
#line 6311 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1249:
#line 6314 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1250:
#line 6318 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1251:
#line 6326 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1252:
#line 6329 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1253:
#line 6335 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1254:
#line 6339 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1255:
#line 6343 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1256:
#line 6347 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1257:
#line 6351 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1258:
#line 6357 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1259:
#line 6358 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1260:
#line 6359 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1261:
#line 6360 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1262:
#line 6365 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1263:
#line 6367 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1264:
#line 6370 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1265:
#line 6374 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1266:
#line 6377 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1267:
#line 6384 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1268:
#line 6389 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1269:
#line 6390 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1270:
#line 6391 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1271:
#line 6392 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1272:
#line 6397 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1273:
#line 6398 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1274:
#line 6404 "fgl.yacc"
    {insql=1;}
    break;

  case 1275:
#line 6404 "fgl.yacc"
    {insql=0;}
    break;

  case 1276:
#line 6404 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1277:
#line 6409 "fgl.yacc"
    {insql=1;}
    break;

  case 1278:
#line 6409 "fgl.yacc"
    {insql=0;}
    break;

  case 1279:
#line 6409 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1280:
#line 6417 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1281:
#line 6418 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1283:
#line 6423 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1284:
#line 6428 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1285:
#line 6429 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1286:
#line 6430 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1287:
#line 6431 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1288:
#line 6432 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1290:
#line 6437 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1291:
#line 6437 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1293:
#line 6441 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1294:
#line 6445 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1295:
#line 6446 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1296:
#line 6449 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1297:
#line 6450 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1298:
#line 6453 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1299:
#line 6456 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1300:
#line 6459 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1301:
#line 6465 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1302:
#line 6467 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1304:
#line 6480 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1305:
#line 6484 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1306:
#line 6485 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1308:
#line 6490 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1309:
#line 6493 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1310:
#line 6499 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1311:
#line 6502 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1312:
#line 6510 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1314:
#line 6517 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1315:
#line 6521 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1316:
#line 6525 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1317:
#line 6531 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1318:
#line 6534 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1319:
#line 6543 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1320:
#line 6546 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1321:
#line 6549 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1322:
#line 6552 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1323:
#line 6555 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1324:
#line 6558 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1325:
#line 6561 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1326:
#line 6568 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1327:
#line 6571 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1328:
#line 6578 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1329:
#line 6581 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1330:
#line 6587 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1331:
#line 6590 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1332:
#line 6597 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1333:
#line 6600 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1335:
#line 6608 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1337:
#line 6617 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1338:
#line 6620 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1339:
#line 6626 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1340:
#line 6629 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1341:
#line 6635 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1342:
#line 6642 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1343:
#line 6643 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1344:
#line 6647 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1345:
#line 6657 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1346:
#line 6660 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1347:
#line 6666 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1348:
#line 6668 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1349:
#line 6673 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1350:
#line 6674 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1351:
#line 6679 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1352:
#line 6680 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1353:
#line 6686 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1354:
#line 6687 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1358:
#line 6714 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6720 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1365:
#line 6723 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1366:
#line 6726 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1367:
#line 6732 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1369:
#line 6738 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1371:
#line 6749 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1372:
#line 6763 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1373:
#line 6772 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1374:
#line 6772 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1375:
#line 6777 "fgl.yacc"
    {insql=1;}
    break;

  case 1376:
#line 6777 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1377:
#line 6782 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1378:
#line 6785 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1379:
#line 6787 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6794 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6798 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1383:
#line 6802 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1384:
#line 6809 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1385:
#line 6812 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1386:
#line 6819 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1387:
#line 6823 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1388:
#line 6829 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1389:
#line 6834 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1390:
#line 6838 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1391:
#line 6844 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1392:
#line 6847 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1393:
#line 6853 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1394:
#line 6860 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1395:
#line 6864 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1396:
#line 6869 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1397:
#line 6879 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1398:
#line 6882 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1399:
#line 6884 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1400:
#line 6886 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1401:
#line 6888 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1402:
#line 6890 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1403:
#line 6892 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1404:
#line 6894 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1405:
#line 6900 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1406:
#line 6910 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1407:
#line 6917 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6923 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6926 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1413:
#line 6933 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1416:
#line 6938 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1417:
#line 6943 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1418:
#line 6950 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1419:
#line 6951 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1420:
#line 6958 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1421:
#line 6969 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1422:
#line 6970 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6971 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1424:
#line 6974 "fgl.yacc"
    {insql=1;}
    break;

  case 1425:
#line 6974 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1426:
#line 6979 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1427:
#line 6984 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1429:
#line 6990 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1431:
#line 6994 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1432:
#line 6999 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1433:
#line 7004 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1434:
#line 7008 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1436:
#line 7014 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1437:
#line 7018 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1438:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 7026 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7028 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7038 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1446:
#line 7039 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1447:
#line 7040 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1448:
#line 7044 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1449:
#line 7045 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1452:
#line 7052 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1453:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1456:
#line 7058 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 7063 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1460:
#line 7065 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 7071 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 7077 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 7087 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1468:
#line 7092 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1469:
#line 7094 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 7100 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1472:
#line 7103 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 7109 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1475:
#line 7117 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1476:
#line 7122 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 7132 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 7138 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7143 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1483:
#line 7146 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1484:
#line 7151 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1486:
#line 7157 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1487:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1488:
#line 7165 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1489:
#line 7168 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1490:
#line 7175 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7176 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1492:
#line 7177 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1493:
#line 7179 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1494:
#line 7192 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1495:
#line 7197 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1497:
#line 7201 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1498:
#line 7203 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1499:
#line 7210 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1500:
#line 7213 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1501:
#line 7219 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1502:
#line 7227 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1503:
#line 7231 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1504:
#line 7235 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1505:
#line 7239 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1506:
#line 7244 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1507:
#line 7247 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1508:
#line 7250 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1509:
#line 7258 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1510:
#line 7265 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1513:
#line 7274 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1514:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1515:
#line 7283 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1516:
#line 7294 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1517:
#line 7301 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7307 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1519:
#line 7310 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1520:
#line 7317 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1521:
#line 7324 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1523:
#line 7331 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1524:
#line 7337 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1525:
#line 7338 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1526:
#line 7339 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1528:
#line 7343 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 7348 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1531:
#line 7355 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1532:
#line 7360 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1533:
#line 7361 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1534:
#line 7364 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1535:
#line 7367 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1536:
#line 7372 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1537:
#line 7373 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1538:
#line 7378 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1539:
#line 7381 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1540:
#line 7387 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1541:
#line 7390 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1542:
#line 7396 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1543:
#line 7399 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1544:
#line 7405 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1545:
#line 7408 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1546:
#line 7415 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1547:
#line 7416 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1548:
#line 7445 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1549:
#line 7447 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1550:
#line 7451 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1552:
#line 7464 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1553:
#line 7467 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1554:
#line 7470 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1555:
#line 7473 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1557:
#line 7481 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1558:
#line 7484 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1560:
#line 7490 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1562:
#line 7496 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1563:
#line 7499 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1564:
#line 7502 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1565:
#line 7505 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1566:
#line 7508 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1567:
#line 7511 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1568:
#line 7514 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1569:
#line 7517 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1570:
#line 7522 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1572:
#line 7529 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1578:
#line 7537 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1579:
#line 7538 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1580:
#line 7543 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1581:
#line 7546 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1582:
#line 7550 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1583:
#line 7556 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1584:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1585:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1586:
#line 7559 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1591:
#line 7579 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1593:
#line 7583 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1594:
#line 7584 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1596:
#line 7587 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1597:
#line 7588 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1598:
#line 7597 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1605:
#line 7611 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1606:
#line 7613 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1607:
#line 7615 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1609:
#line 7618 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1611:
#line 7621 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1615:
#line 7626 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1616:
#line 7628 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1617:
#line 7631 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1618:
#line 7632 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1619:
#line 7639 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1623:
#line 7644 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1627:
#line 7660 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1628:
#line 7667 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1629:
#line 7671 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1630:
#line 7672 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1631:
#line 7673 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1632:
#line 7681 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1633:
#line 7682 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1634:
#line 7683 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1635:
#line 7694 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1636:
#line 7701 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1637:
#line 7706 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1638:
#line 7707 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1639:
#line 7708 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1640:
#line 7716 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1641:
#line 7717 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1642:
#line 7718 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1644:
#line 7744 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1645:
#line 7745 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1646:
#line 7746 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1647:
#line 7750 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1648:
#line 7753 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1649:
#line 7759 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1650:
#line 7764 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1651:
#line 7769 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1653:
#line 7780 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1657:
#line 7798 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1658:
#line 7801 "fgl.yacc"
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

  case 1659:
#line 7814 "fgl.yacc"
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

  case 1660:
#line 7829 "fgl.yacc"
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

  case 1661:
#line 7841 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1662:
#line 7843 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1663:
#line 7846 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1664:
#line 7846 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1665:
#line 7846 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1666:
#line 7846 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1667:
#line 7846 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1668:
#line 7846 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1669:
#line 7847 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1670:
#line 7850 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1685:
#line 7867 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1686:
#line 7870 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1687:
#line 7871 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1688:
#line 7872 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1689:
#line 7876 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1690:
#line 7884 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1691:
#line 7884 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1692:
#line 7890 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1693:
#line 7890 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1694:
#line 7897 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1695:
#line 7897 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1696:
#line 7903 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1697:
#line 7903 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1698:
#line 7911 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1699:
#line 7912 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1700:
#line 7913 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1701:
#line 7916 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1702:
#line 7916 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1704:
#line 7920 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1705:
#line 7921 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1706:
#line 7932 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1707:
#line 7935 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1708:
#line 7941 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1709:
#line 7946 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1710:
#line 7954 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1711:
#line 7966 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1712:
#line 7967 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1713:
#line 7970 "fgl.yacc"
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

  case 1714:
#line 7985 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1715:
#line 7996 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1716:
#line 7999 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1717:
#line 8007 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1718:
#line 8016 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1719:
#line 8019 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1720:
#line 8023 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1721:
#line 8026 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1722:
#line 8027 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1724:
#line 8040 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1725:
#line 8041 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1726:
#line 8050 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1727:
#line 8059 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1728:
#line 8064 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1729:
#line 8065 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1730:
#line 8066 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1731:
#line 8067 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1732:
#line 8074 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1733:
#line 8077 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1734:
#line 8083 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1735:
#line 8086 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1736:
#line 8093 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1737:
#line 8105 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1738:
#line 8114 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1739:
#line 8117 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1740:
#line 8120 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1741:
#line 8126 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1742:
#line 8134 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1743:
#line 8137 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1744:
#line 8138 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1745:
#line 8139 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1746:
#line 8140 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1747:
#line 8141 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1748:
#line 8144 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1749:
#line 8151 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1750:
#line 8153 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1751:
#line 8155 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1752:
#line 8157 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1753:
#line 8159 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1754:
#line 8160 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1755:
#line 8161 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1756:
#line 8162 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1757:
#line 8163 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1758:
#line 8164 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1759:
#line 8165 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1760:
#line 8167 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1761:
#line 8169 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1762:
#line 8171 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1763:
#line 8173 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1764:
#line 8175 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1765:
#line 8177 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1766:
#line 8179 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1767:
#line 8180 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1768:
#line 8182 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1769:
#line 8183 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1770:
#line 8184 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1771:
#line 8190 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1772:
#line 8191 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1774:
#line 8201 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1775:
#line 8209 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1776:
#line 8213 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1777:
#line 8220 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1778:
#line 8220 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1780:
#line 8224 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1781:
#line 8229 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1782:
#line 8229 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1784:
#line 8233 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1785:
#line 8237 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1788:
#line 8246 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1789:
#line 8246 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1794:
#line 8265 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1795:
#line 8266 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1798:
#line 8274 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1799:
#line 8280 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1802:
#line 8299 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1803:
#line 8300 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1804:
#line 8301 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1805:
#line 8302 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1806:
#line 8303 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1807:
#line 8304 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1808:
#line 8308 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1809:
#line 8309 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1810:
#line 8310 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1812:
#line 8315 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1813:
#line 8316 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1814:
#line 8320 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1815:
#line 8336 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1816:
#line 8337 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1817:
#line 8338 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1818:
#line 8342 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1819:
#line 8356 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1820:
#line 8360 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1822:
#line 8369 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1824:
#line 8374 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1825:
#line 8375 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2141:
#line 8699 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2142:
#line 8699 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2143:
#line 8706 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2144:
#line 8706 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2145:
#line 8794 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2146:
#line 8798 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2147:
#line 8800 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2148:
#line 8807 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2149:
#line 8811 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2150:
#line 8817 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2151:
#line 8825 "fgl.yacc"
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

  case 2152:
#line 8835 "fgl.yacc"
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

  case 2153:
#line 8845 "fgl.yacc"
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
#line 8857 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2155:
#line 8860 "fgl.yacc"
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

  case 2156:
#line 8879 "fgl.yacc"
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
#line 8905 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2158:
#line 8908 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2160:
#line 8917 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2161:
#line 8922 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2162:
#line 8925 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2163:
#line 8933 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2164:
#line 8941 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2165:
#line 8954 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2166:
#line 8957 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2167:
#line 8965 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2168:
#line 8968 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2169:
#line 8971 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2170:
#line 8979 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 2171:
#line 8983 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 2172:
#line 8984 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 2173:
#line 8985 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 2174:
#line 8986 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2175:
#line 8987 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2176:
#line 8988 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2177:
#line 8989 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2178:
#line 8990 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2179:
#line 8994 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2180:
#line 8995 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2181:
#line 8996 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2182:
#line 8997 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2183:
#line 8998 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2184:
#line 9004 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2185:
#line 9005 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2186:
#line 9006 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2187:
#line 9007 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2188:
#line 9008 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2189:
#line 9009 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2190:
#line 9010 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2191:
#line 9011 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2192:
#line 9012 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2193:
#line 9013 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2194:
#line 9014 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2195:
#line 9015 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 9016 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 9017 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 9018 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2199:
#line 9019 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2200:
#line 9024 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2201:
#line 9030 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2202:
#line 9031 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2203:
#line 9039 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2204:
#line 9041 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2206:
#line 9047 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2207:
#line 9051 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2208:
#line 9055 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2209:
#line 9071 "fgl.yacc"
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

  case 2210:
#line 9085 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 2211:
#line 9091 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2212:
#line 9093 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2216:
#line 9107 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 2217:
#line 9110 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 2218:
#line 9117 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2219:
#line 9120 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 2220:
#line 9150 "fgl.yacc"
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

  case 2221:
#line 9175 "fgl.yacc"
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

  case 2222:
#line 9230 "fgl.yacc"
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

  case 2223:
#line 9265 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 2224:
#line 9274 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 2225:
#line 9285 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 2226:
#line 9288 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 2227:
#line 9294 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 2228:
#line 9307 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2229:
#line 9321 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2230:
#line 9324 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2231:
#line 9328 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2232:
#line 9343 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2233:
#line 9343 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2234:
#line 9349 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2235:
#line 9350 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2236:
#line 9353 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2237:
#line 9354 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2238:
#line 9355 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2239:
#line 9356 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2240:
#line 9357 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2241:
#line 9358 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2242:
#line 9359 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2243:
#line 9370 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2244:
#line 9374 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2245:
#line 9378 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2246:
#line 9382 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2247:
#line 9387 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2248:
#line 9391 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2249:
#line 9396 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2251:
#line 9404 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2253:
#line 9410 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2254:
#line 9416 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2255:
#line 9420 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2260:
#line 9438 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2261:
#line 9445 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2262:
#line 9455 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2263:
#line 9455 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19258 "y.tab.c"

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


#line 9553 "fgl.yacc"

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



