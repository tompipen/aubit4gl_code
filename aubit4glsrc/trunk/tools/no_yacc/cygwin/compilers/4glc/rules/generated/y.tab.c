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
     NAME = 1719,
     UMINUS = 1720,
     COMMA = 1621,
     KW_OR = 1661,
     KW_AND = 1616,
     KW_USING = 1553,
     NOT = 1636,
     MATCHES = 1433,
     POWER = 1539,
     LESS_THAN = 1535,
     GREATER_THAN = 1450,
     EQUAL = 1611,
     GREATER_THAN_EQ = 1352,
     LESS_THAN_EQ = 1409,
     NOT_EQUAL = 1481,
     PLUS = 1647,
     MINUS = 1634,
     MULTIPLY = 1540,
     DIVIDE = 1567,
     MOD = 1635,
     COMMAND = 1416,
     NUMBER_VALUE = 1721,
     CHAR_VALUE = 1722,
     INT_VALUE = 1723,
     NAMED_GEN = 1724,
     CLINE = 1725,
     SQLLINE = 1726,
     KW_CSTART = 1727,
     KW_CEND = 1728,
     USER_DTYPE = 1729,
     SQL_TEXT = 1730,
     KW_WHENEVER_SET = 1731,
     COMMENT = 1732,
     MEMBER_FUNCTION = 1000,
     DATETIME_VALUE = 1001,
     INTERVAL_VALUE = 1002,
     IN_LINE_MODE = 1003,
     IN_FORM_MODE = 1004,
     FGL_SIZEOF = 1005,
     IMPORT_PACKAGE = 1006,
     DYNAMIC_ARRAY = 1007,
     RESIZE_ARRAY = 1008,
     ALLOCATE_ARRAY = 1009,
     DEALLOCATE_ARRAY = 1010,
     AFTER_INSERT_DELETE = 1011,
     BEFORE_INSERT_DELETE = 1012,
     BEFORE_INSERT = 1013,
     AS_CONVERTABLE = 1014,
     CONCAT_PIPES = 1015,
     BEFORE_DELETE = 1016,
     DROP_TRIGGER = 1017,
     AFTER_INSERT = 1018,
     AFTER_DELETE = 1019,
     EXECUTE_IMMEDIATE = 1020,
     DELETE_ROW_EQUAL_TRUE = 1021,
     INSERT_ROW_EQUAL_TRUE = 1022,
     DELETE_ROW_EQUAL_FALSE = 1023,
     INSERT_ROW_EQUAL_FALSE = 1024,
     CURRENT_ROW_DISPLAY_EQUAL = 1025,
     MAXCOUNT = 1026,
     ALTER_TABLE = 1027,
     ALTER_INDEX = 1028,
     NEXT_SIZE = 1029,
     DISPLAY_ATTR_FORM = 1030,
     DISPLAY_ATTR_WINDOW = 1031,
     INPUT_ATTR_FORM = 1032,
     INPUT_ATTR_WINDOW = 1033,
     WHENEVER_ERROR_CONTINUE = 1034,
     WHENEVER_ANY_ERROR_CONTINUE = 1035,
     WHENEVER_WARNING_CONTINUE = 1036,
     WHENEVER_SQLSUCCESS_CONTINUE = 1037,
     WHENEVER_SQLWARNING_CONTINUE = 1038,
     WHENEVER_NOT_FOUND_CONTINUE = 1039,
     WHENEVER_SQLERROR_CONTINUE = 1040,
     WHENEVER_SUCCESS_CONTINUE = 1041,
     WHENEVER_ERROR_GOTO = 1042,
     WHENEVER_ANY_ERROR_GOTO = 1043,
     WHENEVER_WARNING_GOTO = 1044,
     WHENEVER_SQLSUCCESS_GOTO = 1045,
     WHENEVER_SQLWARNING_GOTO = 1046,
     WHENEVER_NOT_FOUND_GOTO = 1047,
     WHENEVER_SQLERROR_GOTO = 1048,
     WHENEVER_SUCCESS_GOTO = 1049,
     WHENEVER_ERROR_CALL = 1050,
     WHENEVER_ANY_ERROR_CALL = 1051,
     WHENEVER_WARNING_CALL = 1052,
     WHENEVER_SQLSUCCESS_CALL = 1053,
     WHENEVER_SQLWARNING_CALL = 1054,
     WHENEVER_NOT_FOUND_CALL = 1055,
     WHENEVER_SQLERROR_CALL = 1056,
     WHENEVER_SUCCESS_CALL = 1057,
     WHENEVER_ERROR_STOP = 1058,
     WHENEVER_ANY_ERROR_STOP = 1059,
     WHENEVER_WARNING_STOP = 1060,
     WHENEVER_SQLSUCCESS_STOP = 1061,
     WHENEVER_SQLWARNING_STOP = 1062,
     WHENEVER_NOT_FOUND_STOP = 1063,
     WHENEVER_SQLERROR_STOP = 1064,
     WHENEVER_SUCCESS_STOP = 1065,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1066,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1067,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1068,
     XSET_MULTIPLY_EQUAL = 1069,
     XSET_OPEN_BRACKET = 1070,
     NEWFORMATSHARED = 1071,
     CREATE_DATABASE = 1072,
     DROP_DATABASE = 1073,
     IMPORT_LEGACY_FUNCTION = 1074,
     ADD_CONSTRAINT = 1075,
     DROP_CONSTRAINT = 1076,
     DROP_SYNONYM = 1077,
     CONSTRAINT = 1078,
     AS_STATIC = 1079,
     NOT_FIELD_TOUCHED = 1080,
     LOCAL_FUNCTION = 1081,
     EVERY_ROW = 1082,
     ELIF = 1083,
     DOUBLE_PRECISION = 1084,
     COUNT_MULTIPLY = 1085,
     WAIT_FOR_KEY = 1086,
     AT_TERMINATION_CALL = 1087,
     TERMINATE_REPORT = 1088,
     TO_MAIN_CAPTION = 1089,
     CLEARSTAT = 1090,
     TO_MENUITEM = 1091,
     ID_TO_INT = 1092,
     TO_STATUSBOX = 1093,
     ASCII_HEIGHT_ALL = 1094,
     ASCII_WIDTH_ALL = 1095,
     IMPORT_DATATYPE = 1096,
     PAGE_TRAILER_SIZE = 1097,
     PAGE_HEADER_SIZE = 1098,
     FIRST_PAGE_HEADER_SIZE = 1099,
     BYTES_USE_AS_IMAGE = 1100,
     BYTES_USE_AS_ASCII = 1101,
     KWUP_BY = 1102,
     KWDOWN_BY = 1103,
     CLOSE_STATUSBOX = 1104,
     MODIFY_NEXT_SIZE = 1105,
     LOCK_MODE_PAGE = 1106,
     LOCK_MODE_ROW = 1107,
     TO_PIPE = 1108,
     TO_PRINTER = 1109,
     STATUSBOX = 1110,
     FORMHANDLER_INPUT = 1111,
     UNITS_YEAR = 1112,
     UNITS_MONTH = 1113,
     UNITS_DAY = 1114,
     UNITS_HOUR = 1115,
     UNITS_MINUTE = 1116,
     UNITS_SECOND = 1117,
     NO_NEW_LINES = 1118,
     FIELDTOWIDGET = 1119,
     WITH_HOLD = 1120,
     SHOW_MENU = 1121,
     TO_CLUSTER = 1122,
     TO_NOT_CLUSTER = 1123,
     CWIS = 1124,
     CREATE_IDX = 1125,
     FORM_IS_COMPILED = 1126,
     PDF_REPORT = 1127,
     IMPORT_FUNCTION = 1128,
     PROMPT_MANY = 1129,
     POINTS = 1130,
     MM = 1131,
     INCHES = 1132,
     PREPEND = 1133,
     MEMBER_OF = 1134,
     APPEND = 1135,
     TEMPLATE = 1136,
     END_TEMPLATE = 1137,
     SQLSICS = 1138,
     CREATE_SCHEMA = 1139,
     SQLSIRR = 1140,
     UPDATESTATS_T = 1141,
     SQLSICR = 1142,
     WHENEVER_SQLSUCCESS = 1143,
     WHENEVER_SQLWARNING = 1144,
     WHENEVER_ANY_ERROR = 1145,
     WHENEVER_NOT_FOUND = 1146,
     WHENEVER_SQLERROR = 1147,
     WHENEVER_SUCCESS = 1148,
     WHENEVER_ERROR = 1149,
     START_EXTERN = 1150,
     CONTINUE_CONSTRUCT = 1151,
     FOUNCONSTR = 1152,
     SQLSIDR = 1153,
     CREATE_TEMP_TABLE = 1154,
     CURRENT_WINDOW_IS = 1155,
     FIRST_PAGE_HEADER = 1156,
     ORDER_EXTERNAL_BY = 1157,
     SCROLL_CURSOR_FOR = 1158,
     SCROLL_CURSOR = 1159,
     SQL_INTERRUPT_OFF = 1160,
     STOP_ALL_EXTERNAL = 1161,
     WITH_CHECK_OPTION = 1162,
     WITH_GRANT_OPTION = 1163,
     SQLSLMNW = 1164,
     ADDCONSTUNIQ = 1165,
     CONTINUE_DISPLAY = 1166,
     CONTINUE_FOREACH = 1167,
     OUTPUT_TO_REPORT = 1168,
     SQL_INTERRUPT_ON = 1169,
     WHERE_CURRENT_OF = 1170,
     WITHOUT_DEFAULTS = 1171,
     FOCONSTR = 1172,
     SCALED_BY = 1173,
     CONTINUE_PROMPT = 1174,
     PDF_FUNCTION = 1175,
     DEFER_INTERRUPT = 1176,
     DISPLAY_BY_NAME = 1177,
     NOT_NULL_UNIQUE = 1178,
     SKIP_TO_TOP = 1179,
     TOP_OF_PAGE = 1180,
     SKIP_TO = 1181,
     SKIP_BY = 1182,
     WITHOUT_WAITING = 1183,
     BEFCONSTRUCT = 1184,
     SQLSLMW = 1185,
     AFTCONSTRUCT = 1186,
     ALL_PRIVILEGES = 1187,
     CLOSE_DATABASE = 1188,
     CONTINUE_INPUT = 1189,
     CONTINUE_WHILE = 1190,
     CREATE_SYNONYM = 1191,
     DROP_TABLE = 1192,
     EXIT_CONSTRUCT = 1193,
     INEXCLUSIVE = 1194,
     REPORT_TO_PRINTER = 1195,
     REPORT_TO_PIPE = 1196,
     RETURN = 1197,
     SET_SESSION_TO = 1198,
     UPDATESTATS = 1199,
     WITHOUT_HEAD = 1200,
     CLEARSCR = 1201,
     WITH_B_LOG = 1202,
     AUTHORIZATION = 1203,
     BOTTOM_MARGIN = 1204,
     CLOSE_SESSION = 1205,
     CONTINUE_CASE = 1206,
     CONTINUE_MENU = 1207,
     DISPLAY_ARRAY = 1208,
     END_SQL = 1209,
     DOLLAR = 1210,
     END_CONSTRUCT = 1211,
     FIELD_TOUCHED = 1212,
     FINISH_REPORT = 1213,
     INFACC = 1214,
     INPUT_NO_WRAP = 1215,
     SETPMOFF = 1216,
     UNCONSTRAINED = 1217,
     PAGE_TRAILER = 1218,
     SETPMON = 1219,
     BEFGROUP = 1220,
     CLOSE_WINDOW = 1221,
     COMMENT_LINE = 1222,
     CONTINUE_FOR = 1223,
     CREATE_DB = 1224,
     CREATE_TABLE = 1225,
     DEFAULT_NULL = 1226,
     DEFAULT_TODAY = 1227,
     DEFAULT_USER = 1228,
     DELETE_USING = 1229,
     DISPLAY_FORM = 1230,
     END_FUNCTION = 1231,
     EXIT_DISPLAY = 1232,
     EXIT_FOREACH = 1233,
     EXIT_PROGRAM = 1234,
     INFCOLS = 1235,
     ON_EVERY_ROW = 1236,
     OPEN_SESSION = 1237,
     RIGHT_MARGIN = 1238,
     SELECT_USING = 1239,
     START_REPORT = 1240,
     UNLOCK_TABLE = 1241,
     UPDATE_USING = 1242,
     ACL_BUILTIN = 1243,
     AFTGROUP = 1244,
     INFIDX = 1245,
     INFSTAT = 1246,
     LEFT_MARGIN = 1247,
     PAGE_HEADER = 1248,
     ROLLBACK_W = 1249,
     SET_SESSION = 1250,
     SQLSEOFF = 1251,
     WITH_A_LOG = 1252,
     BEFDISP = 1253,
     BEFORE_MENU = 1254,
     CREATE_VIEW = 1255,
     DEFINE_TYPE = 1256,
     DELETE_FROM = 1257,
     END_DISPLAY = 1258,
     END_REPORT = 1259,
     END_FOREACH = 1260,
     END_FOR = 1261,
     END_GLOBALS = 1262,
     EXIT_PROMPT = 1263,
     EXTENT_SIZE = 1264,
     FOREIGN_KEY = 1265,
     HIDE_OPTION = 1266,
     HIDE_WINDOW = 1267,
     INSERT_INTO = 1268,
     IS_NOT_NULL = 1269,
     MOVE_WINDOW = 1270,
     NEXT_OPTION = 1271,
     NOT_MATCHES = 1272,
     ON_LAST_ROW = 1273,
     OPEN_WINDOW = 1274,
     OPEN_STATUSBOX = 1275,
     PAGE_LENGTH = 1276,
     PAGE_WIDTH = 1277,
     PRIMARY_KEY = 1278,
     PROMPT_LINE = 1279,
     RECORD_LIKE = 1280,
     ROLLFORWARD = 1281,
     SETBL = 1282,
     SHOW_OPTION = 1283,
     SHOW_WINDOW = 1284,
     SQLSEON = 1285,
     TO_DATABASE = 1286,
     USE_SESSION = 1287,
     WITH_NO_LOG = 1288,
     AFTDISP = 1289,
     BEFFIELD = 1290,
     INSHARE = 1291,
     UNLOCKTAB = 1292,
     AFTFIELD = 1293,
     ATTRIBUTES = 1294,
     BEFINP = 1295,
     BEGIN_WORK = 1296,
     CLEARWIN = 1297,
     CLOSE_FORM = 1298,
     DEFER_QUIT = 1299,
     DESCENDING = 1300,
     DROP_INDEX = 1301,
     END_PROMPT = 1302,
     END_RECORD = 1303,
     ERROR_LINE = 1304,
     EXIT_INPUT = 1305,
     EXIT_WHILE = 1306,
     FOR_UPDATE_OF = 1307,
     FOR_UPDATE = 1308,
     GET_FLDBUF = 1309,
     INITIALIZE = 1310,
     INPUT_WRAP = 1311,
     LOCK_TABLE = 1312,
     MSG_LINE = 1313,
     NOT_EXISTS = 1314,
     ON_ANY_KEY = 1315,
     REFERENCES = 1316,
     RENCOL = 1317,
     SET_CURSOR = 1318,
     SMALLFLOAT = 1319,
     SQLSUCCESS = 1320,
     TOP_MARGIN = 1321,
     WITH_ARRAY = 1322,
     ACCEPTKEY = 1323,
     ACCEPT = 1324,
     AFTINP = 1325,
     CLEARFORMTODEFAULTS = 1326,
     CLEARFORM = 1327,
     CLEAR_X_FORM = 1328,
     COMMIT_W = 1329,
     NEXTPAGE = 1330,
     PREVPAGE = 1331,
     CTRL_KEY = 1332,
     INFTABS = 1333,
     NEXTFIELD = 1334,
     NEXTFORM = 1335,
     RENTAB = 1336,
     ASCENDING = 1337,
     ASSOCIATE = 1338,
     CHAR = 1339,
     NCHAR = 1340,
     NVARCHAR = 1341,
     CONSTRUCT = 1342,
     DELIMITER = 1343,
     DOWNSHIFT = 1344,
     DROP_VIEW = 1345,
     END_INPUT = 1346,
     END_WHILE = 1347,
     EXCLUSIVE = 1348,
     EXIT_CASE = 1349,
     EXIT_MENU = 1350,
     FORM_LINE = 1351,
     INTERRUPT = 1353,
     INTO_TEMP = 1354,
     INVISIBLE = 1355,
     IN_MEMORY = 1356,
     LINKED_TO = 1357,
     LOAD_FROM = 1358,
     LOCKTAB = 1359,
     MENU_LINE = 1360,
     OPEN_FORM = 1361,
     OTHERWISE = 1362,
     PRECISION = 1363,
     PRIOR = 1364,
     PROCEDURE = 1365,
     REPORT_TO = 1366,
     RETURNING = 1367,
     UNDERLINE = 1368,
     UNLOAD_TO = 1369,
     BEFROW = 1370,
     UNLOAD_T = 1371,
     VARIABLE = 1372,
     ABSOLUTE = 1373,
     AFTROW = 1374,
     BUFFERED = 1375,
     CONSTANT = 1376,
     CONST = 1377,
     DATABASE = 1378,
     DATETIME = 1379,
     DEFAULTS = 1380,
     DISTINCT = 1381,
     END_CASE = 1382,
     END_MAIN = 1383,
     END_MENU = 1384,
     END_TYPE = 1385,
     EXIT_FOR = 1386,
     EXTERNAL = 1387,
     FRACTION = 1388,
     FUNCTION = 1389,
     GROUP_BY = 1390,
     INTERVAL = 1391,
     KWMESSAGE = 1392,
     NOT_LIKE = 1393,
     NOT_ILIKE = 1394,
     NOT_NULL = 1395,
     PASSWORD = 1396,
     PREVIOUS = 1397,
     READONLY = 1398,
     REGISTER = 1399,
     RELATIVE = 1400,
     RESOURCE = 1401,
     SMALLINT = 1402,
     VALIDATE = 1403,
     WITH_LOG = 1404,
     WORDWRAP = 1405,
     BY_NAME = 1406,
     IN_FILE = 1407,
     IS_NULL = 1408,
     AVERAGE = 1410,
     BETWEEN = 1411,
     CAPTION = 1412,
     CLIPPED = 1413,
     CLOSE_BRACKET = 1414,
     COLUMNS = 1415,
     CONNECT = 1417,
     CURRENT = 1418,
     DBYNAME = 1419,
     DECIMAL = 1420,
     DECLARE = 1421,
     DEFAULT = 1422,
     DISPLAY = 1423,
     ENDCODE = 1424,
     EXECUTE = 1425,
     FOREACH = 1426,
     FOREIGN = 1427,
     GLOBALS = 1428,
     INFIELD = 1429,
     INTEGER = 1430,
     KWWINDOW = 1431,
     MAGENTA = 1432,
     OPTIONS = 1434,
     PERCENT = 1435,
     PREPARE = 1436,
     PROGRAM = 1437,
     RECOVER = 1438,
     REVERSE = 1439,
     SECTION = 1440,
     SESSION = 1441,
     SYNONYM = 1442,
     THRU = 1443,
     TRAILER = 1444,
     UPSHIFT = 1445,
     VARCHAR = 1446,
     WAITING = 1447,
     CLOSE_SHEV = 1448,
     CLOSE_SQUARE = 1449,
     KW_FALSE = 1451,
     NOT_IN = 1452,
     ONKEY = 1453,
     OPEN_BRACKET = 1454,
     BORDER = 1455,
     BOTTOM = 1456,
     COLUMN = 1457,
     COMMIT = 1458,
     CREATE = 1459,
     CURSOR = 1460,
     DEFINE = 1461,
     DELETE = 1462,
     DOUBLE = 1463,
     END_IF = 1464,
     ESCAPE = 1465,
     EXISTS = 1466,
     EXTEND = 1467,
     EXTENT = 1468,
     FINISH = 1469,
     FORMAT = 1470,
     HAVING = 1471,
     HEADER = 1472,
     INSERT = 1473,
     LOCATE = 1474,
     MARGIN = 1475,
     MEMORY = 1476,
     MINUTE = 1477,
     MODIFY = 1478,
     NORMAL = 1479,
     EQUAL_EQUAL = 1480,
     OPEN_SHEV = 1482,
     OPEN_SQUARE = 1483,
     OPTION = 1484,
     OUTPUT = 1485,
     PROMPT = 1486,
     PUBLIC = 1487,
     RECORD = 1488,
     REPORT = 1489,
     REVOKE = 1490,
     SCHEMA = 1491,
     SCROLL_USING = 1492,
     SCROLL = 1493,
     SECOND = 1494,
     SELECT = 1495,
     SERIAL = 1496,
     SETL = 1497,
     SHARED = 1498,
     SPACES = 1499,
     UNIQUE = 1500,
     UNLOCK = 1501,
     UPDATE = 1502,
     VALUES = 1503,
     YELLOW = 1504,
     AFTER = 1505,
     KWLINE = 1506,
     KW_NULL = 1507,
     KW_TRUE = 1508,
     SINGLE_KEY = 1509,
     ALTER = 1510,
     ARRAY = 1511,
     ASCII = 1512,
     AUDIT = 1513,
     BLACK = 1514,
     BLINK = 1515,
     CHECK = 1516,
     CLEAR = 1517,
     CLOSE = 1518,
     CODE_C = 1519,
     COUNT = 1520,
     DEFER = 1521,
     ERROR = 1522,
     EVERY = 1523,
     FETCH = 1524,
     FIRST = 1525,
     FLOAT = 1526,
     FLUSH = 1527,
     FOUND = 1528,
     GRANT = 1529,
     GREEN = 1530,
     GROUP = 1531,
     INDEX = 1532,
     KWFORM = 1533,
     LABEL = 1534,
     LOCAL = 1536,
     MONEY = 1537,
     MONTH = 1538,
     ORDER = 1541,
     OUTER = 1542,
     PAUSE = 1543,
     PRINT_IMAGE = 1544,
     PRINT_FILE = 1545,
     PRINT = 1546,
     RIGHT = 1547,
     DOUBLE_COLON = 1548,
     SEMICOLON = 1549,
     SLEEP = 1550,
     TUPLE = 1551,
     UNION = 1552,
     WHERE = 1554,
     WHILE = 1555,
     WHITE = 1556,
     CCODE = 1557,
     ANSI = 1558,
     BLUE = 1559,
     BOLD = 1560,
     BYTE = 1561,
     FCALL = 1562,
     CASE = 1563,
     CYAN = 1564,
     DATE = 1565,
     DESC = 1566,
     KWDOWN = 1568,
     TAB = 1569,
     DROP = 1570,
     ELSE = 1571,
     EXEC = 1572,
     EXIT = 1573,
     FREE = 1574,
     FROM = 1575,
     GOTO = 1576,
     HELP_FILE = 1577,
     LANG_FILE = 1578,
     HELP = 1579,
     HIDE = 1580,
     HOUR = 1581,
     INTO = 1582,
     LAST = 1583,
     LEFT = 1584,
     LIKE = 1585,
     MAIN = 1586,
     MENU = 1587,
     MODE = 1588,
     NEED = 1589,
     NEXT = 1590,
     NOCR = 1591,
     OPEN = 1592,
     QUIT = 1593,
     REAL = 1594,
     ROWS = 1595,
     SHOW = 1596,
     SIZE = 1597,
     SKIP = 1598,
     SOME = 1599,
     STEP = 1600,
     STOP = 1601,
     TEMP = 1602,
     TEXT = 1603,
     THEN = 1604,
     USER = 1605,
     WAIT = 1606,
     WHEN = 1607,
     WITH = 1608,
     WORK = 1609,
     YEAR = 1610,
     KW_IS = 1612,
     XSET = 1613,
     ADD = 1614,
     ALL = 1615,
     ANY = 1617,
     ASC = 1618,
     AVG = 1619,
     COLON = 1620,
     DAY = 1622,
     DBA = 1623,
     DEC = 1624,
     DIM = 1625,
     FKEY = 1626,
     FOR = 1627,
     KEY = 1628,
     KWNO = 1629,
     LET = 1630,
     LOG = 1631,
     XMAX = 1632,
     XMIN = 1633,
     PAD = 1637,
     PUT = 1638,
     RED = 1639,
     ROW = 1640,
     RUN = 1641,
     SQL = 1642,
     SUM = 1643,
     TOP = 1644,
     USE = 1645,
     ATSIGN = 1646,
     AS_TIFF = 1648,
     AS_GIF = 1649,
     AS_PNG = 1650,
     AS_JPEG = 1651,
     AS = 1652,
     AT = 1653,
     BY = 1654,
     DOT = 1655,
     GO = 1656,
     IF = 1657,
     IN = 1658,
     OF = 1659,
     ON = 1660,
     TO = 1662,
     KWUP = 1663,
     FONT_NAME = 1664,
     FONT_SIZE = 1665,
     PAPER_SIZE_IS_LETTER = 1666,
     PAPER_SIZE_IS_LEGAL = 1667,
     PAPER_SIZE_IS_A5 = 1668,
     PAPER_SIZE_IS_A4 = 1669,
     PAPER_SIZE_IS_LETTER_L = 1670,
     PAPER_SIZE_IS_LEGAL_L = 1671,
     PAPER_SIZE_IS_A5_L = 1672,
     PAPER_SIZE_IS_A4_L = 1673,
     FORMHANDLER = 1674,
     END_FORMHANDLER = 1675,
     BEFORE_EVENT = 1676,
     BEFORE_OPEN_FORM = 1677,
     AFTER_EVENT = 1678,
     BEFORE_CLOSE_FORM = 1679,
     BEFORE_ANY = 1680,
     AFTER_ANY = 1681,
     MENUHANDLER = 1682,
     END_MENUHANDLER = 1683,
     BEFORE_SHOW_MENU = 1684,
     DISABLE_PROGRAM = 1685,
     DISABLE_ALL = 1686,
     BUTTONS = 1687,
     CHECK_MENUITEM = 1688,
     DISABLE_FORM = 1689,
     DISABLE_MENUITEMS = 1690,
     DISABLE = 1691,
     ENABLE_FORM = 1692,
     ENABLE_MENUITEMS = 1693,
     ENABLE = 1694,
     KWFIELD = 1695,
     ICON = 1696,
     MESSAGEBOX = 1697,
     TO_DEFAULTS = 1698,
     UNCHECK_MENUITEM = 1699,
     BEFORE = 1700,
     INPUT = 1701,
     END = 1702,
     INT_TO_ID = 1703,
     TIMEOUT = 1704,
     OFF = 1705,
     WITH_1_DIMENSION = 1706,
     WITH_2_DIMENSION = 1707,
     WITH_3_DIMENSION = 1708,
     TILDE = 1709,
     ILIKE = 1710,
     FGL_ISDYNARR_ALLOCATED = 1711,
     FGL_DYNARR_EXTENTSIZE = 1712,
     FILLFACTOR = 1713,
     END_CLASS = 1714,
     KW_CLASS = 1715,
     EXTENDS = 1716,
     PIPE = 1717
   };
#endif
#define NAME 1719
#define UMINUS 1720
#define COMMA 1621
#define KW_OR 1661
#define KW_AND 1616
#define KW_USING 1553
#define NOT 1636
#define MATCHES 1433
#define POWER 1539
#define LESS_THAN 1535
#define GREATER_THAN 1450
#define EQUAL 1611
#define GREATER_THAN_EQ 1352
#define LESS_THAN_EQ 1409
#define NOT_EQUAL 1481
#define PLUS 1647
#define MINUS 1634
#define MULTIPLY 1540
#define DIVIDE 1567
#define MOD 1635
#define COMMAND 1416
#define NUMBER_VALUE 1721
#define CHAR_VALUE 1722
#define INT_VALUE 1723
#define NAMED_GEN 1724
#define CLINE 1725
#define SQLLINE 1726
#define KW_CSTART 1727
#define KW_CEND 1728
#define USER_DTYPE 1729
#define SQL_TEXT 1730
#define KW_WHENEVER_SET 1731
#define COMMENT 1732
#define MEMBER_FUNCTION 1000
#define DATETIME_VALUE 1001
#define INTERVAL_VALUE 1002
#define IN_LINE_MODE 1003
#define IN_FORM_MODE 1004
#define FGL_SIZEOF 1005
#define IMPORT_PACKAGE 1006
#define DYNAMIC_ARRAY 1007
#define RESIZE_ARRAY 1008
#define ALLOCATE_ARRAY 1009
#define DEALLOCATE_ARRAY 1010
#define AFTER_INSERT_DELETE 1011
#define BEFORE_INSERT_DELETE 1012
#define BEFORE_INSERT 1013
#define AS_CONVERTABLE 1014
#define CONCAT_PIPES 1015
#define BEFORE_DELETE 1016
#define DROP_TRIGGER 1017
#define AFTER_INSERT 1018
#define AFTER_DELETE 1019
#define EXECUTE_IMMEDIATE 1020
#define DELETE_ROW_EQUAL_TRUE 1021
#define INSERT_ROW_EQUAL_TRUE 1022
#define DELETE_ROW_EQUAL_FALSE 1023
#define INSERT_ROW_EQUAL_FALSE 1024
#define CURRENT_ROW_DISPLAY_EQUAL 1025
#define MAXCOUNT 1026
#define ALTER_TABLE 1027
#define ALTER_INDEX 1028
#define NEXT_SIZE 1029
#define DISPLAY_ATTR_FORM 1030
#define DISPLAY_ATTR_WINDOW 1031
#define INPUT_ATTR_FORM 1032
#define INPUT_ATTR_WINDOW 1033
#define WHENEVER_ERROR_CONTINUE 1034
#define WHENEVER_ANY_ERROR_CONTINUE 1035
#define WHENEVER_WARNING_CONTINUE 1036
#define WHENEVER_SQLSUCCESS_CONTINUE 1037
#define WHENEVER_SQLWARNING_CONTINUE 1038
#define WHENEVER_NOT_FOUND_CONTINUE 1039
#define WHENEVER_SQLERROR_CONTINUE 1040
#define WHENEVER_SUCCESS_CONTINUE 1041
#define WHENEVER_ERROR_GOTO 1042
#define WHENEVER_ANY_ERROR_GOTO 1043
#define WHENEVER_WARNING_GOTO 1044
#define WHENEVER_SQLSUCCESS_GOTO 1045
#define WHENEVER_SQLWARNING_GOTO 1046
#define WHENEVER_NOT_FOUND_GOTO 1047
#define WHENEVER_SQLERROR_GOTO 1048
#define WHENEVER_SUCCESS_GOTO 1049
#define WHENEVER_ERROR_CALL 1050
#define WHENEVER_ANY_ERROR_CALL 1051
#define WHENEVER_WARNING_CALL 1052
#define WHENEVER_SQLSUCCESS_CALL 1053
#define WHENEVER_SQLWARNING_CALL 1054
#define WHENEVER_NOT_FOUND_CALL 1055
#define WHENEVER_SQLERROR_CALL 1056
#define WHENEVER_SUCCESS_CALL 1057
#define WHENEVER_ERROR_STOP 1058
#define WHENEVER_ANY_ERROR_STOP 1059
#define WHENEVER_WARNING_STOP 1060
#define WHENEVER_SQLSUCCESS_STOP 1061
#define WHENEVER_SQLWARNING_STOP 1062
#define WHENEVER_NOT_FOUND_STOP 1063
#define WHENEVER_SQLERROR_STOP 1064
#define WHENEVER_SUCCESS_STOP 1065
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1066
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1067
#define XSET_ident_DOT_MULTIPLY_EQUAL 1068
#define XSET_MULTIPLY_EQUAL 1069
#define XSET_OPEN_BRACKET 1070
#define NEWFORMATSHARED 1071
#define CREATE_DATABASE 1072
#define DROP_DATABASE 1073
#define IMPORT_LEGACY_FUNCTION 1074
#define ADD_CONSTRAINT 1075
#define DROP_CONSTRAINT 1076
#define DROP_SYNONYM 1077
#define CONSTRAINT 1078
#define AS_STATIC 1079
#define NOT_FIELD_TOUCHED 1080
#define LOCAL_FUNCTION 1081
#define EVERY_ROW 1082
#define ELIF 1083
#define DOUBLE_PRECISION 1084
#define COUNT_MULTIPLY 1085
#define WAIT_FOR_KEY 1086
#define AT_TERMINATION_CALL 1087
#define TERMINATE_REPORT 1088
#define TO_MAIN_CAPTION 1089
#define CLEARSTAT 1090
#define TO_MENUITEM 1091
#define ID_TO_INT 1092
#define TO_STATUSBOX 1093
#define ASCII_HEIGHT_ALL 1094
#define ASCII_WIDTH_ALL 1095
#define IMPORT_DATATYPE 1096
#define PAGE_TRAILER_SIZE 1097
#define PAGE_HEADER_SIZE 1098
#define FIRST_PAGE_HEADER_SIZE 1099
#define BYTES_USE_AS_IMAGE 1100
#define BYTES_USE_AS_ASCII 1101
#define KWUP_BY 1102
#define KWDOWN_BY 1103
#define CLOSE_STATUSBOX 1104
#define MODIFY_NEXT_SIZE 1105
#define LOCK_MODE_PAGE 1106
#define LOCK_MODE_ROW 1107
#define TO_PIPE 1108
#define TO_PRINTER 1109
#define STATUSBOX 1110
#define FORMHANDLER_INPUT 1111
#define UNITS_YEAR 1112
#define UNITS_MONTH 1113
#define UNITS_DAY 1114
#define UNITS_HOUR 1115
#define UNITS_MINUTE 1116
#define UNITS_SECOND 1117
#define NO_NEW_LINES 1118
#define FIELDTOWIDGET 1119
#define WITH_HOLD 1120
#define SHOW_MENU 1121
#define TO_CLUSTER 1122
#define TO_NOT_CLUSTER 1123
#define CWIS 1124
#define CREATE_IDX 1125
#define FORM_IS_COMPILED 1126
#define PDF_REPORT 1127
#define IMPORT_FUNCTION 1128
#define PROMPT_MANY 1129
#define POINTS 1130
#define MM 1131
#define INCHES 1132
#define PREPEND 1133
#define MEMBER_OF 1134
#define APPEND 1135
#define TEMPLATE 1136
#define END_TEMPLATE 1137
#define SQLSICS 1138
#define CREATE_SCHEMA 1139
#define SQLSIRR 1140
#define UPDATESTATS_T 1141
#define SQLSICR 1142
#define WHENEVER_SQLSUCCESS 1143
#define WHENEVER_SQLWARNING 1144
#define WHENEVER_ANY_ERROR 1145
#define WHENEVER_NOT_FOUND 1146
#define WHENEVER_SQLERROR 1147
#define WHENEVER_SUCCESS 1148
#define WHENEVER_ERROR 1149
#define START_EXTERN 1150
#define CONTINUE_CONSTRUCT 1151
#define FOUNCONSTR 1152
#define SQLSIDR 1153
#define CREATE_TEMP_TABLE 1154
#define CURRENT_WINDOW_IS 1155
#define FIRST_PAGE_HEADER 1156
#define ORDER_EXTERNAL_BY 1157
#define SCROLL_CURSOR_FOR 1158
#define SCROLL_CURSOR 1159
#define SQL_INTERRUPT_OFF 1160
#define STOP_ALL_EXTERNAL 1161
#define WITH_CHECK_OPTION 1162
#define WITH_GRANT_OPTION 1163
#define SQLSLMNW 1164
#define ADDCONSTUNIQ 1165
#define CONTINUE_DISPLAY 1166
#define CONTINUE_FOREACH 1167
#define OUTPUT_TO_REPORT 1168
#define SQL_INTERRUPT_ON 1169
#define WHERE_CURRENT_OF 1170
#define WITHOUT_DEFAULTS 1171
#define FOCONSTR 1172
#define SCALED_BY 1173
#define CONTINUE_PROMPT 1174
#define PDF_FUNCTION 1175
#define DEFER_INTERRUPT 1176
#define DISPLAY_BY_NAME 1177
#define NOT_NULL_UNIQUE 1178
#define SKIP_TO_TOP 1179
#define TOP_OF_PAGE 1180
#define SKIP_TO 1181
#define SKIP_BY 1182
#define WITHOUT_WAITING 1183
#define BEFCONSTRUCT 1184
#define SQLSLMW 1185
#define AFTCONSTRUCT 1186
#define ALL_PRIVILEGES 1187
#define CLOSE_DATABASE 1188
#define CONTINUE_INPUT 1189
#define CONTINUE_WHILE 1190
#define CREATE_SYNONYM 1191
#define DROP_TABLE 1192
#define EXIT_CONSTRUCT 1193
#define INEXCLUSIVE 1194
#define REPORT_TO_PRINTER 1195
#define REPORT_TO_PIPE 1196
#define RETURN 1197
#define SET_SESSION_TO 1198
#define UPDATESTATS 1199
#define WITHOUT_HEAD 1200
#define CLEARSCR 1201
#define WITH_B_LOG 1202
#define AUTHORIZATION 1203
#define BOTTOM_MARGIN 1204
#define CLOSE_SESSION 1205
#define CONTINUE_CASE 1206
#define CONTINUE_MENU 1207
#define DISPLAY_ARRAY 1208
#define END_SQL 1209
#define DOLLAR 1210
#define END_CONSTRUCT 1211
#define FIELD_TOUCHED 1212
#define FINISH_REPORT 1213
#define INFACC 1214
#define INPUT_NO_WRAP 1215
#define SETPMOFF 1216
#define UNCONSTRAINED 1217
#define PAGE_TRAILER 1218
#define SETPMON 1219
#define BEFGROUP 1220
#define CLOSE_WINDOW 1221
#define COMMENT_LINE 1222
#define CONTINUE_FOR 1223
#define CREATE_DB 1224
#define CREATE_TABLE 1225
#define DEFAULT_NULL 1226
#define DEFAULT_TODAY 1227
#define DEFAULT_USER 1228
#define DELETE_USING 1229
#define DISPLAY_FORM 1230
#define END_FUNCTION 1231
#define EXIT_DISPLAY 1232
#define EXIT_FOREACH 1233
#define EXIT_PROGRAM 1234
#define INFCOLS 1235
#define ON_EVERY_ROW 1236
#define OPEN_SESSION 1237
#define RIGHT_MARGIN 1238
#define SELECT_USING 1239
#define START_REPORT 1240
#define UNLOCK_TABLE 1241
#define UPDATE_USING 1242
#define ACL_BUILTIN 1243
#define AFTGROUP 1244
#define INFIDX 1245
#define INFSTAT 1246
#define LEFT_MARGIN 1247
#define PAGE_HEADER 1248
#define ROLLBACK_W 1249
#define SET_SESSION 1250
#define SQLSEOFF 1251
#define WITH_A_LOG 1252
#define BEFDISP 1253
#define BEFORE_MENU 1254
#define CREATE_VIEW 1255
#define DEFINE_TYPE 1256
#define DELETE_FROM 1257
#define END_DISPLAY 1258
#define END_REPORT 1259
#define END_FOREACH 1260
#define END_FOR 1261
#define END_GLOBALS 1262
#define EXIT_PROMPT 1263
#define EXTENT_SIZE 1264
#define FOREIGN_KEY 1265
#define HIDE_OPTION 1266
#define HIDE_WINDOW 1267
#define INSERT_INTO 1268
#define IS_NOT_NULL 1269
#define MOVE_WINDOW 1270
#define NEXT_OPTION 1271
#define NOT_MATCHES 1272
#define ON_LAST_ROW 1273
#define OPEN_WINDOW 1274
#define OPEN_STATUSBOX 1275
#define PAGE_LENGTH 1276
#define PAGE_WIDTH 1277
#define PRIMARY_KEY 1278
#define PROMPT_LINE 1279
#define RECORD_LIKE 1280
#define ROLLFORWARD 1281
#define SETBL 1282
#define SHOW_OPTION 1283
#define SHOW_WINDOW 1284
#define SQLSEON 1285
#define TO_DATABASE 1286
#define USE_SESSION 1287
#define WITH_NO_LOG 1288
#define AFTDISP 1289
#define BEFFIELD 1290
#define INSHARE 1291
#define UNLOCKTAB 1292
#define AFTFIELD 1293
#define ATTRIBUTES 1294
#define BEFINP 1295
#define BEGIN_WORK 1296
#define CLEARWIN 1297
#define CLOSE_FORM 1298
#define DEFER_QUIT 1299
#define DESCENDING 1300
#define DROP_INDEX 1301
#define END_PROMPT 1302
#define END_RECORD 1303
#define ERROR_LINE 1304
#define EXIT_INPUT 1305
#define EXIT_WHILE 1306
#define FOR_UPDATE_OF 1307
#define FOR_UPDATE 1308
#define GET_FLDBUF 1309
#define INITIALIZE 1310
#define INPUT_WRAP 1311
#define LOCK_TABLE 1312
#define MSG_LINE 1313
#define NOT_EXISTS 1314
#define ON_ANY_KEY 1315
#define REFERENCES 1316
#define RENCOL 1317
#define SET_CURSOR 1318
#define SMALLFLOAT 1319
#define SQLSUCCESS 1320
#define TOP_MARGIN 1321
#define WITH_ARRAY 1322
#define ACCEPTKEY 1323
#define ACCEPT 1324
#define AFTINP 1325
#define CLEARFORMTODEFAULTS 1326
#define CLEARFORM 1327
#define CLEAR_X_FORM 1328
#define COMMIT_W 1329
#define NEXTPAGE 1330
#define PREVPAGE 1331
#define CTRL_KEY 1332
#define INFTABS 1333
#define NEXTFIELD 1334
#define NEXTFORM 1335
#define RENTAB 1336
#define ASCENDING 1337
#define ASSOCIATE 1338
#define CHAR 1339
#define NCHAR 1340
#define NVARCHAR 1341
#define CONSTRUCT 1342
#define DELIMITER 1343
#define DOWNSHIFT 1344
#define DROP_VIEW 1345
#define END_INPUT 1346
#define END_WHILE 1347
#define EXCLUSIVE 1348
#define EXIT_CASE 1349
#define EXIT_MENU 1350
#define FORM_LINE 1351
#define INTERRUPT 1353
#define INTO_TEMP 1354
#define INVISIBLE 1355
#define IN_MEMORY 1356
#define LINKED_TO 1357
#define LOAD_FROM 1358
#define LOCKTAB 1359
#define MENU_LINE 1360
#define OPEN_FORM 1361
#define OTHERWISE 1362
#define PRECISION 1363
#define PRIOR 1364
#define PROCEDURE 1365
#define REPORT_TO 1366
#define RETURNING 1367
#define UNDERLINE 1368
#define UNLOAD_TO 1369
#define BEFROW 1370
#define UNLOAD_T 1371
#define VARIABLE 1372
#define ABSOLUTE 1373
#define AFTROW 1374
#define BUFFERED 1375
#define CONSTANT 1376
#define CONST 1377
#define DATABASE 1378
#define DATETIME 1379
#define DEFAULTS 1380
#define DISTINCT 1381
#define END_CASE 1382
#define END_MAIN 1383
#define END_MENU 1384
#define END_TYPE 1385
#define EXIT_FOR 1386
#define EXTERNAL 1387
#define FRACTION 1388
#define FUNCTION 1389
#define GROUP_BY 1390
#define INTERVAL 1391
#define KWMESSAGE 1392
#define NOT_LIKE 1393
#define NOT_ILIKE 1394
#define NOT_NULL 1395
#define PASSWORD 1396
#define PREVIOUS 1397
#define READONLY 1398
#define REGISTER 1399
#define RELATIVE 1400
#define RESOURCE 1401
#define SMALLINT 1402
#define VALIDATE 1403
#define WITH_LOG 1404
#define WORDWRAP 1405
#define BY_NAME 1406
#define IN_FILE 1407
#define IS_NULL 1408
#define AVERAGE 1410
#define BETWEEN 1411
#define CAPTION 1412
#define CLIPPED 1413
#define CLOSE_BRACKET 1414
#define COLUMNS 1415
#define CONNECT 1417
#define CURRENT 1418
#define DBYNAME 1419
#define DECIMAL 1420
#define DECLARE 1421
#define DEFAULT 1422
#define DISPLAY 1423
#define ENDCODE 1424
#define EXECUTE 1425
#define FOREACH 1426
#define FOREIGN 1427
#define GLOBALS 1428
#define INFIELD 1429
#define INTEGER 1430
#define KWWINDOW 1431
#define MAGENTA 1432
#define OPTIONS 1434
#define PERCENT 1435
#define PREPARE 1436
#define PROGRAM 1437
#define RECOVER 1438
#define REVERSE 1439
#define SECTION 1440
#define SESSION 1441
#define SYNONYM 1442
#define THRU 1443
#define TRAILER 1444
#define UPSHIFT 1445
#define VARCHAR 1446
#define WAITING 1447
#define CLOSE_SHEV 1448
#define CLOSE_SQUARE 1449
#define KW_FALSE 1451
#define NOT_IN 1452
#define ONKEY 1453
#define OPEN_BRACKET 1454
#define BORDER 1455
#define BOTTOM 1456
#define COLUMN 1457
#define COMMIT 1458
#define CREATE 1459
#define CURSOR 1460
#define DEFINE 1461
#define DELETE 1462
#define DOUBLE 1463
#define END_IF 1464
#define ESCAPE 1465
#define EXISTS 1466
#define EXTEND 1467
#define EXTENT 1468
#define FINISH 1469
#define FORMAT 1470
#define HAVING 1471
#define HEADER 1472
#define INSERT 1473
#define LOCATE 1474
#define MARGIN 1475
#define MEMORY 1476
#define MINUTE 1477
#define MODIFY 1478
#define NORMAL 1479
#define EQUAL_EQUAL 1480
#define OPEN_SHEV 1482
#define OPEN_SQUARE 1483
#define OPTION 1484
#define OUTPUT 1485
#define PROMPT 1486
#define PUBLIC 1487
#define RECORD 1488
#define REPORT 1489
#define REVOKE 1490
#define SCHEMA 1491
#define SCROLL_USING 1492
#define SCROLL 1493
#define SECOND 1494
#define SELECT 1495
#define SERIAL 1496
#define SETL 1497
#define SHARED 1498
#define SPACES 1499
#define UNIQUE 1500
#define UNLOCK 1501
#define UPDATE 1502
#define VALUES 1503
#define YELLOW 1504
#define AFTER 1505
#define KWLINE 1506
#define KW_NULL 1507
#define KW_TRUE 1508
#define SINGLE_KEY 1509
#define ALTER 1510
#define ARRAY 1511
#define ASCII 1512
#define AUDIT 1513
#define BLACK 1514
#define BLINK 1515
#define CHECK 1516
#define CLEAR 1517
#define CLOSE 1518
#define CODE_C 1519
#define COUNT 1520
#define DEFER 1521
#define ERROR 1522
#define EVERY 1523
#define FETCH 1524
#define FIRST 1525
#define FLOAT 1526
#define FLUSH 1527
#define FOUND 1528
#define GRANT 1529
#define GREEN 1530
#define GROUP 1531
#define INDEX 1532
#define KWFORM 1533
#define LABEL 1534
#define LOCAL 1536
#define MONEY 1537
#define MONTH 1538
#define ORDER 1541
#define OUTER 1542
#define PAUSE 1543
#define PRINT_IMAGE 1544
#define PRINT_FILE 1545
#define PRINT 1546
#define RIGHT 1547
#define DOUBLE_COLON 1548
#define SEMICOLON 1549
#define SLEEP 1550
#define TUPLE 1551
#define UNION 1552
#define WHERE 1554
#define WHILE 1555
#define WHITE 1556
#define CCODE 1557
#define ANSI 1558
#define BLUE 1559
#define BOLD 1560
#define BYTE 1561
#define FCALL 1562
#define CASE 1563
#define CYAN 1564
#define DATE 1565
#define DESC 1566
#define KWDOWN 1568
#define TAB 1569
#define DROP 1570
#define ELSE 1571
#define EXEC 1572
#define EXIT 1573
#define FREE 1574
#define FROM 1575
#define GOTO 1576
#define HELP_FILE 1577
#define LANG_FILE 1578
#define HELP 1579
#define HIDE 1580
#define HOUR 1581
#define INTO 1582
#define LAST 1583
#define LEFT 1584
#define LIKE 1585
#define MAIN 1586
#define MENU 1587
#define MODE 1588
#define NEED 1589
#define NEXT 1590
#define NOCR 1591
#define OPEN 1592
#define QUIT 1593
#define REAL 1594
#define ROWS 1595
#define SHOW 1596
#define SIZE 1597
#define SKIP 1598
#define SOME 1599
#define STEP 1600
#define STOP 1601
#define TEMP 1602
#define TEXT 1603
#define THEN 1604
#define USER 1605
#define WAIT 1606
#define WHEN 1607
#define WITH 1608
#define WORK 1609
#define YEAR 1610
#define KW_IS 1612
#define XSET 1613
#define ADD 1614
#define ALL 1615
#define ANY 1617
#define ASC 1618
#define AVG 1619
#define COLON 1620
#define DAY 1622
#define DBA 1623
#define DEC 1624
#define DIM 1625
#define FKEY 1626
#define FOR 1627
#define KEY 1628
#define KWNO 1629
#define LET 1630
#define LOG 1631
#define XMAX 1632
#define XMIN 1633
#define PAD 1637
#define PUT 1638
#define RED 1639
#define ROW 1640
#define RUN 1641
#define SQL 1642
#define SUM 1643
#define TOP 1644
#define USE 1645
#define ATSIGN 1646
#define AS_TIFF 1648
#define AS_GIF 1649
#define AS_PNG 1650
#define AS_JPEG 1651
#define AS 1652
#define AT 1653
#define BY 1654
#define DOT 1655
#define GO 1656
#define IF 1657
#define IN 1658
#define OF 1659
#define ON 1660
#define TO 1662
#define KWUP 1663
#define FONT_NAME 1664
#define FONT_SIZE 1665
#define PAPER_SIZE_IS_LETTER 1666
#define PAPER_SIZE_IS_LEGAL 1667
#define PAPER_SIZE_IS_A5 1668
#define PAPER_SIZE_IS_A4 1669
#define PAPER_SIZE_IS_LETTER_L 1670
#define PAPER_SIZE_IS_LEGAL_L 1671
#define PAPER_SIZE_IS_A5_L 1672
#define PAPER_SIZE_IS_A4_L 1673
#define FORMHANDLER 1674
#define END_FORMHANDLER 1675
#define BEFORE_EVENT 1676
#define BEFORE_OPEN_FORM 1677
#define AFTER_EVENT 1678
#define BEFORE_CLOSE_FORM 1679
#define BEFORE_ANY 1680
#define AFTER_ANY 1681
#define MENUHANDLER 1682
#define END_MENUHANDLER 1683
#define BEFORE_SHOW_MENU 1684
#define DISABLE_PROGRAM 1685
#define DISABLE_ALL 1686
#define BUTTONS 1687
#define CHECK_MENUITEM 1688
#define DISABLE_FORM 1689
#define DISABLE_MENUITEMS 1690
#define DISABLE 1691
#define ENABLE_FORM 1692
#define ENABLE_MENUITEMS 1693
#define ENABLE 1694
#define KWFIELD 1695
#define ICON 1696
#define MESSAGEBOX 1697
#define TO_DEFAULTS 1698
#define UNCHECK_MENUITEM 1699
#define BEFORE 1700
#define INPUT 1701
#define END 1702
#define INT_TO_ID 1703
#define TIMEOUT 1704
#define OFF 1705
#define WITH_1_DIMENSION 1706
#define WITH_2_DIMENSION 1707
#define WITH_3_DIMENSION 1708
#define TILDE 1709
#define ILIKE 1710
#define FGL_ISDYNARR_ALLOCATED 1711
#define FGL_DYNARR_EXTENTSIZE 1712
#define FILLFACTOR 1713
#define END_CLASS 1714
#define KW_CLASS 1715
#define EXTENDS 1716
#define PIPE 1717




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
#line 1726 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1738 "y.tab.c"

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
#define YYLAST   9650

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  735
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  876
/* YYNRULES -- Number of rules. */
#define YYNRULES  2063
/* YYNRULES -- Number of states. */
#define YYNSTATES  3501

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1732

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
     386,   387,    15,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,    16,
     444,   445,   446,   447,   448,   449,    23,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,    10,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
      13,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,    17,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,    12,   565,   566,   567,    11,
      20,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,     8,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,    21,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,    14,   636,   637,   638,   639,     7,   640,   641,   642,
     643,     5,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,    19,    22,     9,   656,   657,   658,
     659,   660,   661,   662,   663,   664,   665,    18,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,     6,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,     2,     3,
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
     661,   663,   669,   673,   675,   677,   679,   683,   689,   690,
     695,   696,   702,   703,   711,   713,   717,   719,   721,   722,
     724,   725,   726,   731,   733,   735,   737,   739,   744,   749,
     754,   761,   766,   773,   775,   778,   780,   782,   784,   786,
     791,   798,   800,   805,   812,   813,   817,   818,   822,   823,
     827,   829,   831,   833,   835,   837,   840,   843,   845,   847,
     848,   852,   857,   859,   860,   864,   868,   869,   872,   874,
     876,   878,   880,   882,   884,   887,   888,   891,   892,   896,
     897,   901,   903,   904,   908,   910,   912,   914,   916,   918,
     920,   923,   925,   926,   928,   929,   935,   937,   939,   941,
     946,   951,   958,   960,   962,   964,   966,   971,   978,   980,
     985,   992,   994,   996,   998,  1000,  1002,  1005,  1008,  1010,
    1015,  1016,  1024,  1025,  1038,  1039,  1044,  1045,  1051,  1053,
    1057,  1060,  1062,  1066,  1068,  1069,  1072,  1075,  1077,  1080,
    1086,  1091,  1094,  1099,  1105,  1109,  1110,  1111,  1123,  1124,
    1127,  1129,  1130,  1133,  1135,  1137,  1140,  1141,  1145,  1146,
    1150,  1151,  1155,  1158,  1161,  1164,  1169,  1175,  1177,  1180,
    1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,  1198,  1200,
    1202,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,  1220,
    1223,  1225,  1227,  1229,  1232,  1235,  1237,  1239,  1241,  1243,
    1245,  1247,  1249,  1251,  1253,  1255,  1258,  1260,  1263,  1265,
    1267,  1269,  1273,  1275,  1279,  1281,  1285,  1287,  1290,  1292,
    1294,  1298,  1303,  1308,  1310,  1312,  1314,  1316,  1318,  1322,
    1324,  1327,  1330,  1332,  1333,  1337,  1340,  1343,  1345,  1349,
    1354,  1359,  1365,  1371,  1373,  1375,  1378,  1381,  1386,  1391,
    1394,  1397,  1402,  1407,  1409,  1412,  1415,  1418,  1421,  1424,
    1427,  1430,  1433,  1436,  1439,  1442,  1445,  1448,  1451,  1452,
    1453,  1454,  1461,  1462,  1463,  1472,  1473,  1474,  1483,  1484,
    1485,  1492,  1493,  1494,  1501,  1502,  1503,  1510,  1511,  1512,
    1519,  1525,  1531,  1537,  1543,  1551,  1559,  1569,  1579,  1586,
    1595,  1606,  1617,  1625,  1635,  1644,  1655,  1668,  1683,  1698,
    1709,  1722,  1735,  1740,  1745,  1752,  1753,  1757,  1759,  1761,
    1766,  1771,  1776,  1781,  1786,  1791,  1793,  1795,  1797,  1799,
    1804,  1809,  1812,  1815,  1818,  1821,  1824,  1826,  1828,  1831,
    1833,  1835,  1837,  1840,  1845,  1852,  1859,  1863,  1869,  1875,
    1879,  1881,  1883,  1887,  1889,  1893,  1895,  1899,  1900,  1901,
    1902,  1912,  1913,  1917,  1918,  1919,  1930,  1931,  1933,  1934,
    1936,  1938,  1941,  1942,  1946,  1947,  1951,  1952,  1954,  1956,
    1959,  1960,  1964,  1965,  1969,  1973,  1975,  1980,  1984,  1986,
    1990,  1992,  1996,  1998,  2002,  2004,  2007,  2008,  2012,  2013,
    2017,  2018,  2023,  2024,  2029,  2030,  2035,  2036,  2037,  2049,
    2050,  2053,  2056,  2060,  2062,  2066,  2068,  2070,  2072,  2074,
    2076,  2078,  2080,  2084,  2086,  2088,  2093,  2100,  2105,  2109,
    2116,  2120,  2127,  2129,  2131,  2133,  2135,  2137,  2139,  2141,
    2143,  2144,  2147,  2149,  2151,  2153,  2158,  2160,  2162,  2164,
    2169,  2173,  2180,  2184,  2191,  2193,  2195,  2198,  2201,  2203,
    2206,  2209,  2211,  2215,  2217,  2220,  2223,  2226,  2231,  2234,
    2237,  2242,  2243,  2252,  2253,  2255,  2257,  2259,  2260,  2262,
    2265,  2266,  2268,  2271,  2272,  2274,  2277,  2278,  2280,  2284,
    2285,  2288,  2289,  2290,  2299,  2300,  2301,  2305,  2306,  2307,
    2315,  2321,  2324,  2327,  2330,  2331,  2337,  2342,  2344,  2348,
    2352,  2356,  2358,  2359,  2362,  2364,  2365,  2367,  2369,  2372,
    2373,  2378,  2379,  2384,  2385,  2389,  2390,  2394,  2395,  2399,
    2400,  2404,  2405,  2409,  2410,  2414,  2415,  2419,  2420,  2424,
    2425,  2429,  2430,  2434,  2435,  2439,  2441,  2445,  2447,  2451,
    2454,  2459,  2461,  2463,  2465,  2466,  2471,  2477,  2484,  2485,
    2496,  2500,  2503,  2506,  2508,  2510,  2513,  2516,  2517,  2520,
    2522,  2525,  2529,  2533,  2537,  2541,  2543,  2545,  2547,  2549,
    2550,  2554,  2556,  2557,  2561,  2564,  2567,  2569,  2573,  2575,
    2579,  2581,  2583,  2585,  2587,  2589,  2591,  2593,  2595,  2597,
    2599,  2601,  2603,  2605,  2607,  2609,  2611,  2613,  2615,  2617,
    2619,  2620,  2621,  2629,  2631,  2633,  2636,  2639,  2642,  2646,
    2651,  2653,  2655,  2657,  2658,  2662,  2663,  2665,  2667,  2670,
    2672,  2674,  2676,  2678,  2680,  2682,  2684,  2685,  2687,  2689,
    2692,  2695,  2697,  2699,  2701,  2703,  2705,  2707,  2709,  2711,
    2713,  2715,  2716,  2718,  2720,  2722,  2724,  2725,  2726,  2727,
    2728,  2742,  2744,  2745,  2746,  2753,  2756,  2758,  2761,  2764,
    2767,  2769,  2771,  2774,  2776,  2777,  2781,  2784,  2786,  2788,
    2790,  2791,  2792,  2800,  2802,  2805,  2806,  2810,  2811,  2816,
    2817,  2823,  2825,  2826,  2830,  2831,  2839,  2840,  2846,  2848,
    2851,  2852,  2854,  2856,  2858,  2859,  2861,  2863,  2866,  2869,
    2872,  2874,  2876,  2878,  2880,  2884,  2886,  2888,  2891,  2892,
    2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2913,  2914,
    2916,  2918,  2920,  2922,  2925,  2928,  2931,  2937,  2946,  2948,
    2950,  2952,  2957,  2962,  2964,  2966,  2968,  2970,  2973,  2977,
    2984,  2986,  2990,  2992,  2994,  2996,  3000,  3007,  3017,  3019,
    3021,  3023,  3025,  3028,  3029,  3031,  3033,  3037,  3039,  3043,
    3045,  3049,  3051,  3055,  3057,  3059,  3061,  3063,  3067,  3069,
    3073,  3075,  3079,  3081,  3083,  3085,  3089,  3092,  3093,  3095,
    3097,  3099,  3103,  3105,  3109,  3117,  3118,  3126,  3127,  3134,
    3138,  3140,  3144,  3146,  3149,  3155,  3156,  3164,  3165,  3168,
    3169,  3171,  3177,  3180,  3186,  3187,  3193,  3200,  3205,  3206,
    3208,  3210,  3216,  3217,  3220,  3221,  3227,  3232,  3235,  3237,
    3241,  3244,  3247,  3250,  3253,  3256,  3259,  3261,  3264,  3267,
    3270,  3273,  3276,  3279,  3282,  3284,  3286,  3288,  3290,  3293,
    3296,  3298,  3300,  3302,  3304,  3306,  3308,  3311,  3314,  3316,
    3318,  3320,  3322,  3328,  3330,  3332,  3335,  3340,  3345,  3352,
    3355,  3357,  3358,  3370,  3371,  3374,  3380,  3381,  3383,  3384,
    3387,  3389,  3392,  3393,  3397,  3399,  3400,  3405,  3406,  3409,
    3411,  3415,  3417,  3419,  3424,  3430,  3436,  3440,  3441,  3443,
    3445,  3447,  3449,  3450,  3452,  3460,  3463,  3466,  3469,  3472,
    3475,  3477,  3480,  3481,  3485,  3486,  3490,  3491,  3495,  3496,
    3500,  3501,  3505,  3506,  3511,  3512,  3517,  3519,  3521,  3523,
    3525,  3527,  3529,  3530,  3535,  3536,  3538,  3539,  3544,  3546,
    3549,  3552,  3555,  3556,  3558,  3560,  3563,  3566,  3567,  3570,
    3571,  3576,  3578,  3582,  3586,  3592,  3593,  3596,  3601,  3603,
    3605,  3607,  3609,  3611,  3612,  3614,  3616,  3620,  3623,  3629,
    3632,  3638,  3644,  3650,  3656,  3662,  3668,  3669,  3672,  3674,
    3677,  3680,  3683,  3686,  3689,  3692,  3694,  3697,  3700,  3703,
    3706,  3708,  3711,  3714,  3717,  3720,  3722,  3724,  3726,  3727,
    3730,  3733,  3736,  3739,  3742,  3745,  3748,  3751,  3754,  3756,
    3758,  3760,  3762,  3764,  3766,  3768,  3770,  3773,  3776,  3779,
    3782,  3785,  3787,  3789,  3791,  3792,  3796,  3799,  3800,  3801,
    3802,  3803,  3804,  3805,  3821,  3822,  3825,  3828,  3829,  3831,
    3832,  3833,  3834,  3835,  3836,  3837,  3853,  3856,  3857,  3858,
    3859,  3870,  3871,  3873,  3877,  3881,  3884,  3888,  3893,  3897,
    3903,  3908,  3912,  3916,  3918,  3920,  3922,  3925,  3928,  3931,
    3934,  3936,  3938,  3939,  3940,  3949,  3950,  3951,  3961,  3962,
    3964,  3966,  3969,  3972,  3975,  3978,  3980,  3982,  3984,  3985,
    3987,  3989,  3992,  3995,  3998,  4007,  4010,  4013,  4018,  4021,
    4022,  4024,  4026,  4030,  4033,  4036,  4038,  4040,  4044,  4046,
    4048,  4051,  4053,  4057,  4061,  4065,  4067,  4071,  4073,  4075,
    4077,  4079,  4081,  4083,  4085,  4088,  4093,  4095,  4099,  4101,
    4105,  4108,  4113,  4115,  4119,  4121,  4124,  4129,  4131,  4135,
    4137,  4139,  4141,  4144,  4148,  4153,  4156,  4161,  4162,  4165,
    4168,  4173,  4175,  4179,  4181,  4183,  4185,  4188,  4190,  4192,
    4194,  4196,  4198,  4201,  4208,  4215,  4216,  4218,  4219,  4221,
    4224,  4226,  4227,  4233,  4234,  4240,  4242,  4243,  4247,  4249,
    4253,  4255,  4259,  4261,  4263,  4264,  4269,  4271,  4274,  4276,
    4277,  4278,  4282,  4283,  4284,  4288,  4290,  4292,  4294,  4296,
    4298,  4300,  4303,  4306,  4311,  4315,  4319,  4321,  4325,  4328,
    4330,  4332,  4333,  4335,  4337,  4339,  4341,  4342,  4344,  4348,
    4350,  4354,  4356,  4357,  4361,  4363,  4365,  4367,  4369,  4371,
    4373,  4375,  4377,  4379,  4381,  4383,  4385,  4393,  4400,  4405,
    4410,  4412,  4414,  4416,  4417,  4419,  4422,  4424,  4426,  4428,
    4430,  4434,  4437,  4439,  4441,  4444,  4446,  4448,  4449,  4453,
    4455,  4459,  4461,  4465,  4467,  4469,  4476,  4477,  4481,  4483,
    4487,  4488,  4490,  4495,  4501,  4504,  4506,  4508,  4513,  4515,
    4519,  4524,  4529,  4534,  4536,  4540,  4542,  4544,  4546,  4549,
    4551,  4553,  4555,  4560,  4561,  4563,  4564,  4566,  4568,  4571,
    4574,  4576,  4578,  4580,  4582,  4584,  4589,  4591,  4595,  4597,
    4599,  4601,  4604,  4606,  4608,  4611,  4614,  4616,  4620,  4623,
    4626,  4628,  4632,  4634,  4637,  4642,  4644,  4647,  4651,  4653,
    4657,  4662,  4663,  4665,  4666,  4668,  4669,  4671,  4673,  4677,
    4679,  4683,  4685,  4688,  4690,  4694,  4697,  4700,  4701,  4704,
    4706,  4708,  4714,  4718,  4724,  4728,  4730,  4734,  4736,  4738,
    4739,  4741,  4745,  4749,  4753,  4760,  4765,  4770,  4775,  4780,
    4786,  4788,  4790,  4792,  4794,  4796,  4798,  4800,  4802,  4804,
    4806,  4807,  4809,  4811,  4813,  4815,  4817,  4819,  4821,  4826,
    4827,  4829,  4834,  4836,  4842,  4848,  4850,  4852,  4854,  4856,
    4858,  4863,  4865,  4870,  4877,  4882,  4884,  4889,  4891,  4899,
    4901,  4903,  4905,  4910,  4917,  4918,  4921,  4926,  4928,  4930,
    4932,  4934,  4936,  4938,  4940,  4944,  4946,  4948,  4952,  4958,
    4962,  4968,  4976,  4980,  4982,  4984,  4988,  4994,  4998,  5004,
    5012,  5014,  5015,  5019,  5025,  5027,  5030,  5033,  5038,  5042,
    5044,  5046,  5048,  5050,  5052,  5055,  5058,  5059,  5063,  5064,
    5068,  5070,  5072,  5074,  5076,  5078,  5080,  5082,  5087,  5089,
    5091,  5093,  5095,  5097,  5099,  5101,  5103,  5105,  5107,  5109,
    5111,  5113,  5115,  5120,  5122,  5126,  5128,  5132,  5133,  5141,
    5142,  5151,  5152,  5159,  5160,  5169,  5170,  5172,  5175,  5177,
    5181,  5183,  5187,  5193,  5195,  5197,  5199,  5201,  5203,  5204,
    5205,  5215,  5221,  5223,  5225,  5232,  5233,  5237,  5239,  5243,
    5248,  5250,  5251,  5254,  5259,  5266,  5267,  5269,  5271,  5273,
    5275,  5279,  5281,  5284,  5288,  5290,  5292,  5295,  5298,  5300,
    5302,  5304,  5307,  5310,  5313,  5316,  5321,  5325,  5328,  5332,
    5336,  5340,  5342,  5344,  5346,  5348,  5350,  5352,  5358,  5364,
    5370,  5376,  5382,  5387,  5392,  5396,  5401,  5403,  5405,  5407,
    5411,  5413,  5419,  5427,  5433,  5434,  5437,  5439,  5441,  5442,
    5446,  5448,  5452,  5454,  5456,  5458,  5459,  5463,  5465,  5467,
    5469,  5471,  5476,  5483,  5485,  5487,  5490,  5494,  5496,  5498,
    5500,  5502,  5504,  5506,  5508,  5510,  5516,  5522,  5527,  5533,
    5535,  5540,  5542,  5544,  5552,  5557,  5559,  5560,  5565,  5567,
    5570,  5572,  5574,  5576,  5577,  5581,  5582,  5586,  5587,  5588,
    5595,  5596,  5599,  5602,  5610,  5614,  5618,  5621,  5624,  5627,
    5629,  5633,  5635,  5639,  5641,  5645,  5647,  5651,  5653,  5655,
    5657,  5660,  5663,  5665,  5667,  5670,  5675,  5681,  5689,  5697,
    5707,  5709,  5711,  5713,  5715,  5717,  5719,  5723,  5726,  5730,
    5734,  5738,  5744,  5750,  5756,  5762,  5768,  5773,  5778,  5782,
    5787,  5789,  5791,  5793,  5795,  5799,  5800,  5806,  5808,  5812,
    5816,  5820,  5822,  5824,  5827,  5829,  5831,  5835,  5837,  5841,
    5845,  5847,  5849,  5851,  5855,  5858,  5862,  5869,  5871,  5875,
    5877,  5879,  5880,  5881,  5888,  5889,  5892,  5893,  5895,  5897,
    5900,  5903,  5905,  5907,  5912,  5916,  5918,  5921,  5927,  5930,
    5933,  5939,  5940,  5943,  5945,  5947,  5950,  5957,  5964,  5966,
    5967,  5969,  5972,  5974,  5977,  5978,  5981,  5983,  5985,  5987,
    5989,  5991,  5993,  5995,  5997,  5999,  6001,  6003,  6005,  6007,
    6009,  6011,  6013,  6015,  6017,  6019,  6021,  6023,  6025,  6027,
    6029,  6031,  6033,  6035,  6037,  6039,  6041,  6043,  6045,  6047,
    6049,  6051,  6053,  6055,  6057,  6059,  6061,  6063,  6065,  6067,
    6069,  6071,  6073,  6075,  6077,  6079,  6081,  6083,  6085,  6087,
    6089,  6091,  6093,  6095,  6097,  6099,  6101,  6103,  6105,  6107,
    6109,  6111,  6113,  6115,  6117,  6119,  6121,  6123,  6125,  6127,
    6129,  6131,  6133,  6135,  6137,  6139,  6141,  6143,  6145,  6147,
    6149,  6151,  6153,  6155
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1117,     0,    -1,   255,    -1,   252,    -1,   186,   740,   481,
     649,   741,    -1,   197,    -1,  1180,    -1,    26,    -1,   742,
      -1,   741,     5,   742,    -1,  1024,    -1,   485,   743,   448,
      -1,   743,   744,   743,    -1,    26,    -1,   745,    26,    -1,
    1180,    -1,   964,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   747,
      -1,    -1,   330,   485,   748,   749,   448,    -1,   622,   485,
      26,     5,    26,   448,    -1,   750,    -1,   749,     5,   750,
      -1,   544,    -1,   585,    -1,   590,    -1,   560,    -1,   465,
      -1,   658,    -1,   582,    -1,   534,    -1,   471,    -1,   545,
      -1,   403,    -1,   586,    -1,   510,    -1,   390,    -1,   647,
      -1,   154,    -1,  1096,    -1,    -1,   752,    -1,    -1,   330,
     485,   753,   754,   448,    -1,   755,    -1,   754,     5,   755,
      -1,   750,    -1,   486,    -1,   656,    25,    -1,   258,  1010,
      -1,   387,  1010,    -1,   340,  1010,    -1,   395,  1010,    -1,
     349,  1010,    -1,   315,  1010,    -1,   588,   757,    -1,   953,
     402,  1180,    -1,    -1,   345,   485,   972,   448,   402,   758,
    1198,    -1,   162,   485,  1024,     5,    25,     5,    25,   448,
      -1,   462,   485,  1016,   448,   402,  1180,    -1,  1321,    -1,
     248,   485,   972,   448,   402,  1180,    -1,    -1,    -1,  1180,
     643,  1024,   485,   759,   775,   448,   760,   773,    -1,    -1,
      -1,  1180,    36,  1024,   485,   761,   775,   448,   762,   773,
      -1,    -1,    -1,    -1,  1024,   485,   763,   775,   764,   448,
     765,   773,    -1,    -1,    -1,   528,  1530,   676,  1530,   485,
     766,   775,   767,   448,   773,    -1,    -1,    -1,  1024,   575,
    1024,   485,   768,   775,   769,   448,   773,    -1,    -1,    -1,
      -1,   422,   778,   643,   779,   513,   740,   481,   485,   770,
     775,   771,   448,   772,   774,    -1,    -1,   402,  1198,    -1,
      -1,   402,  1198,    -1,   219,    -1,    -1,   776,    -1,   777,
      -1,   776,     5,   777,    -1,   922,    -1,   537,    -1,    25,
      -1,  1024,    -1,  1024,    -1,  1024,   673,  1024,    -1,    -1,
     589,   929,   781,   784,   788,   785,    -1,    -1,   589,   782,
     783,   786,   785,    -1,   790,    -1,   783,   790,    -1,   792,
      -1,   784,   792,    -1,   417,    -1,    -1,    -1,   397,   787,
    1605,    -1,    -1,    -1,   397,   789,  1605,    -1,    -1,   632,
     929,   791,  1605,    -1,    -1,   632,   929,   793,  1605,    -1,
      -1,    -1,    -1,   732,  1024,   795,   798,   796,   828,   797,
     799,   731,    -1,    -1,   733,  1024,    -1,   800,    -1,   799,
     800,    -1,  1132,    -1,   334,  1021,    -1,   257,  1019,    -1,
     140,  1019,    -1,   224,    -1,   241,  1536,    -1,   548,  1018,
      -1,    30,   803,    31,    -1,   804,    -1,   806,    -1,   805,
      -1,   804,   805,    -1,    29,    -1,   807,    -1,   806,   807,
      -1,    28,    -1,    -1,    -1,   378,   809,   811,   810,   812,
      -1,   441,  1180,   678,   813,  1068,  1095,   746,    -1,  1180,
     678,   813,  1068,   600,   972,  1095,   746,    -1,    -1,   815,
     247,    -1,   814,    -1,   813,     5,   814,    -1,  1024,    -1,
    1024,   673,  1024,    -1,  1024,   673,    20,    -1,   816,    -1,
     815,   816,    -1,    -1,   326,   822,   817,  1605,    -1,    -1,
     329,   823,   818,  1605,    -1,    -1,  1098,   819,  1605,    -1,
      -1,   222,   820,  1605,    -1,    -1,   220,   821,  1605,    -1,
    1028,    -1,   822,     5,  1028,    -1,  1028,    -1,   823,     5,
    1028,    -1,   148,    -1,   149,    -1,   150,    -1,   151,    -1,
     152,    -1,   153,    -1,   485,   922,   826,   448,    -1,    -1,
       5,   873,   679,   876,    -1,   212,    -1,   335,    -1,    -1,
     829,    -1,   830,    -1,   829,   830,    -1,    -1,    -1,   492,
     831,   833,   832,  1290,    -1,   886,    -1,   836,    -1,   833,
       5,   836,    -1,    -1,   835,  1024,    -1,   411,   834,   885,
      25,    -1,   411,   834,   885,  1024,    -1,   411,   834,   885,
    1030,    -1,   411,   834,   885,    26,    -1,   840,   859,    -1,
      -1,   834,   411,   837,   838,    -1,    26,    -1,    25,    -1,
    1030,    -1,    19,    26,    -1,   834,    -1,   839,    -1,   840,
       5,   839,    -1,    -1,   375,    -1,    -1,   723,    -1,   724,
      -1,   725,    -1,    -1,   541,   513,   850,   481,   844,   677,
     859,    -1,    -1,    43,   842,   845,   677,   859,    -1,    -1,
     374,   841,   847,    26,   848,   358,   513,   849,   481,   846,
     677,   859,    -1,   485,    -1,   512,    -1,   448,    -1,   480,
      -1,    26,    -1,   851,     5,   851,     5,   851,    -1,   851,
       5,   851,    -1,   851,    -1,    26,    -1,   834,    -1,   834,
     643,   834,    -1,   834,   665,   834,   643,   834,    -1,    -1,
     518,   854,   833,   339,    -1,    -1,   316,   855,   852,   673,
      20,    -1,    -1,   392,   856,   852,   314,   485,   857,   448,
      -1,   858,    -1,   857,     5,   858,    -1,   834,    -1,   861,
      -1,    -1,   115,    -1,    -1,    -1,   862,   864,   863,   860,
      -1,   843,    -1,   853,    -1,   375,    -1,   376,    -1,   375,
     485,    26,   448,    -1,   376,   485,    26,   448,    -1,   478,
     485,    26,   448,    -1,   478,   485,    26,     5,    26,   448,
      -1,   377,   485,    26,   448,    -1,   377,   485,    26,     5,
      26,   448,    -1,   463,    -1,   670,   834,    -1,   437,    -1,
     563,    -1,   146,    -1,   453,    -1,   453,   485,    26,   448,
      -1,   453,   485,    26,     5,    26,   448,    -1,   566,    -1,
     566,   485,    26,   448,    -1,   566,   485,    26,     5,    26,
     448,    -1,    -1,   556,   865,   868,    -1,    -1,   120,   866,
     868,    -1,    -1,   355,   867,   868,    -1,   591,    -1,   587,
      -1,   136,    -1,   137,    -1,   628,    -1,   414,   871,    -1,
     426,   872,    -1,   869,    -1,    32,    -1,    -1,   485,    26,
     448,    -1,   610,   852,   673,   870,    -1,   834,    -1,    -1,
     873,   679,   876,    -1,   881,   679,   884,    -1,    -1,   874,
     875,    -1,   635,    -1,   567,    -1,   644,    -1,   606,    -1,
     508,    -1,   524,    -1,   423,   878,    -1,    -1,   877,   875,
      -1,    -1,   485,   880,   448,    -1,    -1,   485,    26,   448,
      -1,    26,    -1,    -1,   882,   883,   879,    -1,   635,    -1,
     567,    -1,   644,    -1,   606,    -1,   508,    -1,   524,    -1,
     423,   878,    -1,   883,    -1,    -1,    14,    -1,    -1,   292,
    1024,   887,   670,   888,    -1,   890,    -1,   893,    -1,   375,
      -1,   375,   485,    26,   448,    -1,   478,   485,    26,   448,
      -1,   478,   485,    26,     5,    26,   448,    -1,   463,    -1,
     437,    -1,   563,    -1,   453,    -1,   453,   485,    26,   448,
      -1,   453,   485,    26,     5,    26,   448,    -1,   566,    -1,
     566,   485,    26,   448,    -1,   566,   485,    26,     5,    26,
     448,    -1,   556,    -1,   355,    -1,   591,    -1,   587,    -1,
     628,    -1,   414,   871,    -1,   426,   872,    -1,   889,    -1,
     610,   852,   673,   870,    -1,    -1,   541,   513,   850,   481,
     891,   677,   888,    -1,    -1,   374,   841,   847,    26,   848,
     358,   513,   849,   481,   892,   677,   888,    -1,    -1,   518,
     894,   896,   339,    -1,    -1,   316,   895,  1024,   673,    20,
      -1,   897,    -1,   896,     5,   897,    -1,   898,   888,    -1,
     899,    -1,   898,     5,   899,    -1,  1024,    -1,    -1,   671,
    1014,    -1,   127,  1024,    -1,   125,    -1,   679,   972,    -1,
     679,   563,  1024,   712,   972,    -1,   679,   563,  1024,   446,
      -1,   129,  1024,    -1,   213,   945,  1198,   908,    -1,   456,
     945,   927,   900,   908,    -1,   266,  1021,   908,    -1,    -1,
      -1,   244,   905,  1205,   679,  1024,   673,    20,   907,   746,
     906,   909,    -1,    -1,   522,  1015,    -1,   746,    -1,    -1,
     910,   294,    -1,   294,    -1,   911,    -1,   910,   911,    -1,
      -1,   409,   912,  1605,    -1,    -1,   405,   913,  1605,    -1,
      -1,  1098,   914,  1605,    -1,    45,  1180,    -1,    46,  1180,
      -1,    44,  1180,    -1,   552,   945,   928,   746,    -1,   552,
     945,   928,   746,   122,    -1,   270,    -1,   270,   929,    -1,
     342,    -1,   341,    -1,   269,    -1,   421,    -1,   229,    -1,
     268,    -1,   386,    -1,   385,    -1,   299,    -1,   226,    -1,
     225,    -1,   203,    -1,   259,    -1,   187,    -1,   202,    -1,
     243,    -1,   210,    -1,   930,    -1,   934,    -1,   964,    -1,
     922,   923,    -1,   965,    -1,   967,    -1,   931,    -1,    19,
     922,    -1,    18,   922,    -1,   936,    -1,   944,    -1,   938,
      -1,   529,    -1,   824,    -1,   939,    -1,   940,    -1,   941,
      -1,   942,    -1,   943,    -1,    51,   922,    -1,   945,    -1,
     945,   926,    -1,   929,    -1,   537,    -1,   925,    -1,   926,
       5,   925,    -1,   929,    -1,   927,     5,   929,    -1,   929,
      -1,   928,     5,   929,    -1,   922,    -1,     9,   922,    -1,
     538,    -1,   482,    -1,   485,   922,   448,    -1,   497,   485,
    1510,   448,    -1,   350,   485,  1510,   448,    -1,    25,    -1,
    1030,    -1,    26,    -1,   933,    -1,  1180,    -1,  1180,   475,
    1180,    -1,   932,    -1,   488,   922,    -1,   449,   922,    -1,
    1293,    -1,    -1,   561,   935,  1293,    -1,     7,   922,    -1,
       6,   922,    -1,   922,    -1,   937,     5,   922,    -1,   676,
     485,  1510,   448,    -1,   483,   485,  1510,   448,    -1,   676,
     485,   945,   937,   448,    -1,   483,   485,   945,   937,   448,
      -1,   443,    -1,   305,    -1,    10,   922,    -1,   308,   922,
      -1,    10,   922,   496,    25,    -1,   308,   922,   496,    25,
      -1,   610,   922,    -1,   428,   922,    -1,   610,   922,   496,
      25,    -1,   428,   922,   496,    25,    -1,   447,    -1,     8,
     922,    -1,    18,   922,    -1,    19,   922,    -1,    20,   922,
      -1,    21,   922,    -1,    22,   922,    -1,    11,   922,    -1,
      14,   922,    -1,   511,   922,    -1,    12,   922,    -1,    13,
     922,    -1,    17,   922,    -1,    16,   922,    -1,    15,   922,
      -1,    -1,    -1,    -1,  1024,   485,   947,   775,   948,   448,
      -1,    -1,    -1,  1024,   575,  1024,   485,   949,   775,   950,
     448,    -1,    -1,    -1,  1024,    36,  1024,   485,   951,   775,
     952,   448,    -1,    -1,    -1,   591,   485,   954,   922,   955,
     448,    -1,    -1,    -1,   567,   485,   956,   922,   957,   448,
      -1,    -1,    -1,   644,   485,   958,   922,   959,   448,    -1,
      -1,    -1,   635,   485,   960,   922,   961,   448,    -1,   426,
     485,   968,   448,   963,    -1,   414,   485,    25,   448,   962,
      -1,   414,   485,    26,   448,   962,    -1,   414,   485,    24,
     448,   962,    -1,   414,   485,    26,   643,    26,   448,   962,
      -1,   414,   485,    26,   643,    24,   448,   962,    -1,   414,
     485,    26,   643,    26,   643,    26,   448,   962,    -1,   414,
     485,    26,   643,    26,   643,    24,   448,   962,    -1,   414,
     485,    26,    26,   448,   962,    -1,   414,   485,    26,    26,
     643,    26,   448,   962,    -1,   414,   485,    26,    26,   643,
      26,   643,    26,   448,   962,    -1,   414,   485,    26,    26,
     643,    26,   643,    24,   448,   962,    -1,   414,   485,    26,
      19,    26,   448,   962,    -1,   414,   485,    26,    19,    26,
      19,    26,   448,   962,    -1,   414,   485,    26,    19,    26,
      26,   448,   962,    -1,   414,   485,    26,    19,    26,    19,
      26,    26,   448,   962,    -1,   414,   485,    26,    19,    26,
      19,    26,    26,   643,    26,   448,   962,    -1,   414,   485,
      26,    19,    26,    19,    26,    26,   643,    26,   643,    26,
     448,   962,    -1,   414,   485,    26,    19,    26,    19,    26,
      26,   643,    26,   643,    24,   448,   962,    -1,   414,   485,
      26,    19,    26,    26,   643,    26,   448,   962,    -1,   414,
     485,    26,    19,    26,    26,   643,    26,   643,    26,   448,
     962,    -1,   414,   485,    26,    19,    26,    26,   643,    26,
     643,    24,   448,   962,    -1,    41,   485,  1180,   448,    -1,
     728,   485,  1180,   448,    -1,   729,   485,  1180,     5,    26,
     448,    -1,    -1,   875,   679,   875,    -1,   872,    -1,   953,
      -1,   345,   485,   972,   448,    -1,   155,   485,  1015,   448,
      -1,   128,   485,  1015,   448,    -1,   462,   485,   973,   448,
      -1,   248,   485,   972,   448,    -1,   116,   485,   972,   448,
      -1,   966,    -1,   946,    -1,  1487,    -1,   591,    -1,   477,
     485,   922,   448,    -1,   380,   485,   922,   448,    -1,   542,
     922,    -1,   498,   825,    -1,   922,   166,    -1,   922,   167,
      -1,   922,   168,    -1,    25,    -1,   969,    -1,    19,   969,
      -1,   971,    -1,   970,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   643,    26,    -1,    26,    26,   643,    26,   643,
      26,    -1,    26,    26,   643,    26,   643,    24,    -1,    26,
     643,    26,    -1,    26,   643,    26,   643,    26,    -1,    26,
     643,    26,   643,    24,    -1,    26,   643,    24,    -1,    24,
      -1,    26,    -1,    26,    19,    26,    -1,  1015,    -1,   972,
       5,  1015,    -1,  1016,    -1,   973,     5,  1016,    -1,    -1,
      -1,    -1,   459,   975,  1018,   976,   978,  1389,   977,  1605,
     296,    -1,    -1,     8,   945,   927,    -1,    -1,    -1,   691,
    1024,   980,   828,   981,  1129,   983,   982,   988,   692,    -1,
      -1,   993,    -1,    -1,   984,    -1,   985,    -1,   984,   985,
      -1,    -1,   693,   986,  1605,    -1,    -1,   694,   987,  1605,
      -1,    -1,   989,    -1,   990,    -1,   989,   990,    -1,    -1,
     695,   991,  1605,    -1,    -1,   696,   992,  1605,    -1,   994,
     998,   382,    -1,   147,    -1,   147,   995,   600,   996,    -1,
     147,   441,   997,    -1,  1180,    -1,   995,     5,  1180,    -1,
    1024,    -1,   996,     5,  1024,    -1,  1180,    -1,   997,     5,
    1180,    -1,   999,    -1,   998,   999,    -1,    -1,   697,  1000,
    1605,    -1,    -1,   698,  1001,  1605,    -1,    -1,   717,   996,
    1002,  1605,    -1,    -1,   535,   996,  1003,  1605,    -1,    -1,
     678,   996,  1004,  1605,    -1,    -1,    -1,   649,  1180,    14,
     929,   679,   929,  1008,  1006,  1605,  1007,   297,    -1,    -1,
     625,   929,    -1,   599,  1017,    -1,   608,    19,    26,    -1,
     608,    -1,   555,    18,    26,    -1,   555,    -1,    26,    -1,
    1180,    -1,   722,    -1,    25,    -1,  1029,    -1,   929,    -1,
    1012,     5,  1012,    -1,  1013,    -1,  1024,    -1,   720,   485,
    1024,   448,    -1,  1024,   673,   720,   485,  1024,   448,    -1,
    1024,   513,   743,   481,    -1,  1024,   673,    20,    -1,  1024,
     513,   743,   481,   673,    20,    -1,  1024,   673,  1024,    -1,
    1024,   513,   743,   481,   673,  1024,    -1,  1015,    -1,    25,
      -1,  1025,    -1,  1025,    -1,  1025,    -1,  1025,    -1,  1025,
      -1,  1025,    -1,    -1,   604,    26,    -1,  1604,    -1,  1026,
      -1,  1604,    -1,   407,   485,  1027,   448,    -1,  1183,    -1,
      25,    -1,  1024,    -1,  1024,   513,   743,   481,    -1,  1024,
     673,    20,    -1,  1024,   513,   743,   481,   673,    20,    -1,
    1024,   673,  1024,    -1,  1024,   513,   743,   481,   673,  1024,
      -1,  1180,    -1,    24,    -1,   673,    26,    -1,   601,  1032,
      -1,  1024,    -1,   643,  1024,    -1,   705,  1034,    -1,  1035,
      -1,  1034,     5,  1035,    -1,  1024,    -1,   716,  1034,    -1,
     707,  1034,    -1,   708,   972,    -1,   706,  1021,   712,   972,
      -1,   710,  1034,    -1,   711,   972,    -1,   709,  1021,   712,
     972,    -1,    -1,   714,  1040,   927,  1045,  1047,  1049,  1041,
    1043,    -1,    -1,  1042,    -1,   702,    -1,   703,    -1,    -1,
    1044,    -1,   402,  1180,    -1,    -1,  1046,    -1,   446,   927,
      -1,    -1,  1048,    -1,   713,    26,    -1,    -1,  1050,    -1,
     704,    26,  1051,    -1,    -1,   455,    26,    -1,    -1,    -1,
     675,   929,   629,  1053,  1605,  1054,  1055,   495,    -1,    -1,
      -1,   596,  1056,  1605,    -1,    -1,    -1,   119,  1057,   929,
     629,  1058,  1605,  1055,    -1,   164,  1024,   485,    26,   448,
      -1,   110,  1024,    -1,    42,  1024,    -1,   132,  1024,    -1,
      -1,   346,  1209,  1063,   679,   537,    -1,   346,  1209,   610,
    1064,    -1,  1065,    -1,  1064,     5,  1065,    -1,  1066,   673,
    1483,    -1,  1066,   673,    20,    -1,  1479,    -1,    -1,  1069,
     382,    -1,   382,    -1,    -1,   207,    -1,  1070,    -1,  1069,
    1070,    -1,    -1,   326,  1084,  1071,  1605,    -1,    -1,   329,
    1085,  1072,  1605,    -1,    -1,   409,  1073,  1605,    -1,    -1,
     405,  1074,  1605,    -1,    -1,  1098,  1075,  1605,    -1,    -1,
     361,  1076,  1605,    -1,    -1,   331,  1077,  1605,    -1,    -1,
      52,  1078,  1605,    -1,    -1,    49,  1079,  1605,    -1,    -1,
      48,  1080,  1605,    -1,    -1,    47,  1081,  1605,    -1,    -1,
      55,  1082,  1605,    -1,    -1,    54,  1083,  1605,    -1,  1015,
      -1,  1084,     5,  1015,    -1,  1015,    -1,  1085,     5,  1015,
      -1,   370,  1088,    -1,   371,  1024,   712,  1088,    -1,   615,
      -1,   432,    -1,  1015,    -1,    -1,   718,  1091,  1090,  1067,
      -1,   441,  1198,  1068,  1023,   746,    -1,  1198,  1068,   600,
     972,  1023,   746,    -1,    -1,   541,  1205,  1068,   600,  1024,
     673,    20,  1023,  1092,   746,    -1,   523,   972,  1094,    -1,
     138,    26,    -1,   139,    26,    -1,   680,    -1,   593,    -1,
     138,  1180,    -1,   139,  1180,    -1,    -1,   604,    26,    -1,
    1097,    -1,    61,    25,    -1,   550,    14,    26,    -1,   550,
      14,  1180,    -1,    62,    14,    26,    -1,    62,    14,  1180,
      -1,    58,    -1,    60,    -1,    57,    -1,    59,    -1,    -1,
     484,  1099,  1104,    -1,   351,    -1,    -1,   650,  1101,  1104,
      -1,   359,  1106,    -1,   650,  1104,    -1,  1106,    -1,   485,
    1105,   448,    -1,  1106,    -1,  1105,     5,  1106,    -1,  1107,
      -1,   648,    -1,   368,    -1,   388,    -1,   360,    -1,   539,
      -1,   496,    -1,   680,    -1,   604,    -1,   593,    -1,   233,
      -1,   493,    -1,   504,    -1,   594,    -1,   609,    -1,   574,
      -1,   366,    -1,   367,    -1,    25,    -1,   564,    -1,    -1,
      -1,   652,  1110,  1203,  1111,    14,   945,  1112,    -1,   537,
      -1,   928,    -1,   275,  1180,    -1,   265,  1180,    -1,   278,
    1180,    -1,   505,  1201,   391,    -1,   505,  1201,   442,  1011,
      -1,  1118,    -1,  1119,    -1,   794,    -1,    -1,  1121,  1120,
    1124,    -1,    -1,  1122,    -1,  1123,    -1,  1122,  1123,    -1,
    1061,    -1,  1128,    -1,  1589,    -1,  1060,    -1,  1144,    -1,
    1130,    -1,  1143,    -1,    -1,  1125,    -1,  1127,    -1,  1125,
    1127,    -1,   123,  1024,    -1,  1132,    -1,  1138,    -1,  1303,
      -1,  1313,    -1,  1150,    -1,   979,    -1,   802,    -1,  1059,
      -1,  1589,    -1,   802,    -1,    -1,   802,    -1,   829,    -1,
     424,    -1,   117,    -1,    -1,    -1,    -1,    -1,  1131,  1133,
    1024,   485,  1134,  1196,   448,  1135,   828,  1136,  1129,  1605,
    1137,    -1,   267,    -1,    -1,    -1,   611,  1139,   828,  1140,
    1605,   418,    -1,   233,   924,    -1,   945,    -1,   945,   927,
      -1,   413,  1494,    -1,   521,  1494,    -1,  1145,    -1,  1146,
      -1,  1145,  1146,    -1,  1147,    -1,    -1,   461,  1148,  1149,
      -1,   828,   298,    -1,  1011,    -1,  1128,    -1,  1143,    -1,
      -1,    -1,   699,  1024,  1151,   828,  1152,  1153,   700,    -1,
    1154,    -1,  1153,  1154,    -1,    -1,   701,  1155,  1605,    -1,
      -1,   678,  1024,  1156,  1605,    -1,    -1,   612,  1158,  1173,
    1164,  1159,    -1,   419,    -1,    -1,   290,  1161,  1605,    -1,
      -1,    23,  1165,  1166,  1167,  1023,  1162,  1605,    -1,    -1,
      23,  1165,  1023,  1163,  1605,    -1,  1160,    -1,  1164,  1160,
      -1,    -1,  1100,    -1,    25,    -1,  1180,    -1,    -1,  1180,
      -1,    25,    -1,   307,  1171,    -1,   319,  1172,    -1,   302,
    1172,    -1,   639,    -1,    25,    -1,  1180,    -1,  1171,    -1,
    1172,     5,  1171,    -1,  1180,    -1,    25,    -1,  1177,  1175,
      -1,    -1,   747,  1178,    -1,  1179,    -1,  1176,    -1,  1046,
      -1,  1048,    -1,  1050,    -1,  1042,    -1,  1044,    -1,   427,
     945,   927,    -1,    -1,   122,    -1,   122,    -1,  1181,    -1,
    1183,    -1,   246,  1183,    -1,  1183,   673,    -1,  1182,  1187,
      -1,  1182,  1024,   513,  1190,   481,    -1,  1182,  1024,   513,
    1190,   481,   513,  1190,   481,    -1,  1188,    -1,  1024,    -1,
    1184,    -1,  1024,   512,  1186,   480,    -1,  1024,   512,  1186,
     480,    -1,  1180,    -1,    25,    -1,    20,    -1,  1024,    -1,
    1024,  1189,    -1,   513,  1190,   481,    -1,   513,  1190,   481,
     513,  1190,   481,    -1,  1191,    -1,  1190,     5,  1191,    -1,
     743,    -1,  1193,    -1,  1195,    -1,  1193,   673,  1194,    -1,
    1193,   673,  1024,   513,  1190,   481,    -1,  1193,   673,  1024,
     513,  1190,   481,   513,  1190,   481,    -1,  1024,    -1,  1185,
      -1,    20,    -1,  1024,    -1,  1024,  1189,    -1,    -1,  1197,
      -1,  1199,    -1,  1197,     5,  1199,    -1,  1200,    -1,  1198,
       5,  1200,    -1,  1024,    -1,  1024,   673,  1024,    -1,  1180,
      -1,  1180,   475,  1180,    -1,    25,    -1,  1030,    -1,    26,
      -1,  1202,    -1,  1201,     5,  1202,    -1,  1180,    -1,  1180,
     475,  1180,    -1,  1204,    -1,  1203,     5,  1204,    -1,  1192,
      -1,  1180,    -1,  1207,    -1,  1206,     5,  1207,    -1,  1180,
    1208,    -1,    -1,   641,    -1,   592,    -1,  1210,    -1,  1209,
       5,  1210,    -1,  1180,    -1,  1180,   475,  1180,    -1,   310,
    1020,   671,  1013,   633,  1597,   751,    -1,    -1,   671,   485,
     929,     5,   929,   448,  1213,    -1,    -1,   622,   485,   929,
       5,   929,   448,    -1,   311,  1024,  1212,    -1,  1024,    -1,
     396,  1022,  1217,    -1,  1218,    -1,   600,   929,    -1,  1219,
    1220,  1225,     8,  1215,    -1,    -1,   671,  1221,   485,   929,
       5,   929,   448,    -1,    -1,   610,  1025,    -1,    -1,   408,
      -1,   273,  1536,   322,  1578,  1224,    -1,   617,  1017,    -1,
     617,  1017,     8,   945,   927,    -1,    -1,   670,   630,  1530,
     431,  1530,    -1,   670,   630,  1530,     5,   431,  1530,    -1,
     670,  1530,     5,  1530,    -1,    -1,   702,    -1,   703,    -1,
     450,   679,  1578,  1227,  1228,    -1,    -1,   670,  1578,    -1,
      -1,   670,   630,  1530,     8,  1530,    -1,   630,  1530,     8,
    1530,    -1,   466,  1230,    -1,  1231,    -1,  1230,     5,  1231,
      -1,   258,  1010,    -1,   340,  1010,    -1,   387,  1010,    -1,
     395,  1010,    -1,   349,  1010,    -1,   315,  1010,    -1,  1102,
      -1,   493,  1103,    -1,   504,  1103,    -1,   615,  1103,    -1,
     432,  1103,    -1,   604,  1103,    -1,   602,  1011,    -1,   603,
    1011,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
     456,   747,    -1,   718,   747,    -1,   347,    -1,   251,    -1,
     208,    -1,   188,    -1,   196,    -1,   205,    -1,   660,  1232,
      -1,   734,  1233,    -1,    39,    -1,    40,    -1,    39,    -1,
      40,    -1,  1535,   468,  1237,   600,  1235,    -1,  1180,    -1,
      25,    -1,   458,  1237,    -1,   458,  1237,     8,  1198,    -1,
     458,  1237,   607,  1201,    -1,   458,  1237,   607,  1201,     8,
    1198,    -1,    56,  1235,    -1,  1025,    -1,    -1,   516,  1247,
     746,   649,  1242,  1180,  1240,  1023,   746,  1239,  1243,    -1,
      -1,   721,    26,    -1,   516,  1247,   746,   402,  1180,    -1,
      -1,   375,    -1,    -1,  1244,   338,    -1,  1245,    -1,  1244,
    1245,    -1,    -1,  1098,  1246,  1605,    -1,   928,    -1,    -1,
     657,  1017,  1249,  1250,    -1,    -1,   600,  1251,    -1,  1252,
      -1,  1251,     5,  1252,    -1,  1522,    -1,   537,    -1,   276,
    1256,   145,  1254,    -1,   276,  1256,   679,  1255,  1254,    -1,
     276,  1256,   144,  1255,  1254,    -1,   276,  1256,  1254,    -1,
      -1,    50,    -1,    25,    -1,  1029,    -1,  1024,    -1,    -1,
     533,    -1,   204,  1256,  1257,   485,   945,  1142,   448,    -1,
     249,  1256,    -1,   124,  1256,    -1,  1294,  1302,    -1,   501,
     118,    -1,   501,  1263,    -1,  1264,    -1,  1263,  1264,    -1,
      -1,   192,  1265,  1605,    -1,    -1,   254,  1266,  1605,    -1,
      -1,   284,  1267,  1605,    -1,    -1,   272,  1268,  1605,    -1,
      -1,   309,  1269,  1605,    -1,    -1,   256,  1180,  1270,  1605,
      -1,    -1,   280,  1180,  1271,  1605,    -1,  1282,    -1,  1286,
      -1,  1285,    -1,  1273,    -1,  1311,    -1,  1276,    -1,    -1,
     614,   929,  1274,   536,    -1,    -1,   536,    -1,    -1,   623,
      26,  1277,  1275,    -1,   215,    -1,   682,  1298,    -1,   218,
    1298,    -1,   217,  1298,    -1,    -1,  1279,    -1,  1280,    -1,
    1279,  1280,    -1,  1291,  1281,    -1,    -1,   671,  1298,    -1,
      -1,   573,  1283,  1278,  1290,    -1,  1530,    -1,   485,  1530,
     448,    -1,   572,  1284,  1290,    -1,   571,  1289,  1288,  1287,
    1290,    -1,    -1,   209,   922,    -1,   209,   922,     5,   922,
      -1,   666,    -1,   667,    -1,   668,    -1,   669,    -1,  1180,
      -1,    -1,   576,    -1,  1292,    -1,  1291,     5,  1292,    -1,
     929,  1325,    -1,   662,   485,   922,   448,  1310,    -1,   121,
    1310,    -1,   550,   485,    20,   448,  1310,    -1,   467,   485,
      20,   448,  1310,    -1,   444,   485,   922,   448,  1310,    -1,
     642,   485,   922,   448,  1310,    -1,   655,   485,   922,   448,
    1310,    -1,   654,   485,   922,   448,  1310,    -1,    -1,   515,
    1295,    -1,  1296,    -1,  1295,  1296,    -1,   283,    26,    -1,
     274,    26,    -1,   357,    26,    -1,   240,    26,    -1,   312,
      26,    -1,   231,    -1,   401,    25,    -1,   401,  1180,    -1,
     232,    25,    -1,   216,    25,    -1,  1301,    -1,  1297,  1301,
      -1,  1299,   166,    -1,  1299,   168,    -1,  1299,   167,    -1,
    1299,    -1,  1030,    -1,    26,    -1,    -1,   515,  1297,    -1,
     283,  1298,    -1,   274,  1298,    -1,   357,  1298,    -1,   240,
    1298,    -1,   312,  1298,    -1,   313,  1298,    -1,   681,    25,
      -1,   682,  1298,    -1,   686,    -1,   683,    -1,   684,    -1,
     685,    -1,   690,    -1,   687,    -1,   688,    -1,   689,    -1,
     133,  1298,    -1,   134,  1298,    -1,   135,  1298,    -1,   401,
      25,    -1,   232,    25,    -1,   455,    -1,   130,    -1,   131,
      -1,    -1,   568,   672,  1206,    -1,   193,  1206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   519,  1304,  1024,   485,  1305,
    1196,   448,  1306,   828,  1307,  1261,  1308,  1262,  1309,   295,
      -1,    -1,   580,   922,    -1,   570,  1312,    -1,    -1,  1235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,  1314,  1024,
     485,  1315,  1196,   448,  1316,   828,  1317,  1320,  1318,  1262,
    1319,   295,    -1,  1300,  1302,    -1,    -1,    -1,    -1,   211,
     485,    25,     5,  1322,   775,  1323,   448,  1324,   773,    -1,
      -1,   440,    -1,   440,   274,    26,    -1,   440,   274,  1180,
      -1,   660,   929,    -1,   660,   929,  1327,    -1,   660,   929,
     402,  1180,    -1,   660,   929,   219,    -1,   660,   929,  1327,
     402,  1180,    -1,   660,   929,  1327,   219,    -1,   660,   929,
     631,    -1,   660,   929,   598,    -1,    40,    -1,    39,    -1,
    1329,    -1,   228,  1479,    -1,   381,  1479,    -1,   337,  1480,
      -1,    53,  1024,    -1,  1343,    -1,  1331,    -1,    -1,    -1,
     261,  1332,  1479,   485,  1333,  1347,   448,  1336,    -1,    -1,
      -1,   190,  1334,  1479,   485,  1335,  1347,   448,  1336,  1344,
      -1,    -1,  1337,    -1,  1338,    -1,  1337,  1338,    -1,   676,
    1339,    -1,   300,    26,    -1,    65,    26,    -1,   142,    -1,
     143,    -1,  1604,    -1,    -1,  1341,    -1,  1342,    -1,  1341,
    1342,    -1,   676,  1339,    -1,   730,    26,    -1,   161,  1480,
     678,  1479,   485,  1345,   448,  1340,    -1,   108,  1025,    -1,
     109,  1025,    -1,   227,  1479,   649,  1479,    -1,   113,  1479,
      -1,    -1,   324,    -1,  1346,    -1,  1345,     5,  1346,    -1,
    1024,   641,    -1,  1024,   592,    -1,  1024,    -1,  1348,    -1,
    1347,     5,  1348,    -1,  1431,    -1,  1429,    -1,   177,  1024,
      -1,   235,    -1,    63,  1024,  1351,    -1,    64,  1480,   158,
      -1,    64,  1480,   159,    -1,  1352,    -1,  1351,     5,  1352,
      -1,  1353,    -1,  1356,    -1,  1359,    -1,  1364,    -1,  1367,
      -1,  1363,    -1,  1362,    -1,   638,  1354,    -1,   638,   485,
    1355,   448,    -1,  1348,    -1,  1348,   717,  1024,    -1,  1354,
      -1,  1355,     5,  1354,    -1,   595,  1358,    -1,   595,   485,
    1357,   448,    -1,  1358,    -1,  1357,     5,  1358,    -1,  1024,
      -1,   509,  1361,    -1,   509,   485,  1360,   448,    -1,  1361,
      -1,  1360,     5,  1361,    -1,  1348,    -1,   142,    -1,   143,
      -1,   141,    26,    -1,   111,  1429,  1366,    -1,   111,   485,
    1365,   448,    -1,  1429,  1366,    -1,  1365,     5,  1429,  1366,
      -1,    -1,   114,  1024,    -1,   112,  1368,    -1,   112,   485,
    1368,   448,    -1,  1369,    -1,  1368,     5,  1369,    -1,  1024,
      -1,   321,    -1,   287,    -1,   221,  1372,    -1,   200,    -1,
     189,    -1,   176,    -1,   174,    -1,   178,    -1,   234,  1536,
      -1,   286,  1371,   514,  1530,   679,  1530,    -1,   354,  1017,
     514,  1530,   679,  1530,    -1,    -1,  1536,    -1,    -1,   929,
      -1,   577,   929,    -1,   285,    -1,    -1,   304,  1376,  1479,
    1379,  1377,    -1,    -1,   533,  1378,   485,  1381,   448,    -1,
    1516,    -1,    -1,   485,  1380,   448,    -1,  1483,    -1,  1380,
       5,  1483,    -1,  1382,    -1,  1381,     5,  1382,    -1,  1522,
      -1,   537,    -1,    -1,   554,  1384,  1386,  1387,    -1,  1025,
      -1,  1391,  1018,    -1,  1018,    -1,    -1,    -1,   607,  1388,
    1201,    -1,    -1,    -1,   607,  1390,  1201,    -1,   555,    -1,
     608,    -1,   615,    -1,   432,    -1,   399,    -1,   451,    -1,
     435,   929,    -1,   408,   929,    -1,   293,  1479,   206,  1018,
      -1,   293,  1479,  1452,    -1,   568,   672,  1395,    -1,  1396,
      -1,  1395,     5,  1396,    -1,  1397,  1398,    -1,    26,    -1,
    1483,    -1,    -1,   641,    -1,   592,    -1,   332,    -1,   365,
      -1,    -1,   384,    -1,   413,  1403,  1401,    -1,  1578,    -1,
    1578,   665,  1024,    -1,    25,    -1,    -1,  1535,  1405,  1406,
      -1,  1437,    -1,  1441,    -1,  1400,    -1,  1537,    -1,  1399,
      -1,  1392,    -1,  1393,    -1,  1383,    -1,  1375,    -1,  1374,
      -1,  1506,    -1,  1558,    -1,   559,  1410,   678,  1479,   679,
    1415,  1409,    -1,   520,  1410,   678,  1479,   600,  1415,    -1,
     559,  1408,   679,  1415,    -1,   520,  1408,   600,  1415,    -1,
     450,    -1,   436,    -1,   645,    -1,    -1,   199,    -1,   670,
    1024,    -1,   223,    -1,   639,    -1,  1411,    -1,  1412,    -1,
    1411,     5,  1412,    -1,   525,  1413,    -1,   504,    -1,   493,
      -1,   532,  1413,    -1,   540,    -1,   562,    -1,    -1,   485,
    1414,   448,    -1,  1483,    -1,  1414,     5,  1483,    -1,  1416,
      -1,  1415,     5,  1416,    -1,   517,    -1,  1481,    -1,   291,
    1479,  1418,   670,  1516,  1420,    -1,    -1,   485,  1419,   448,
      -1,  1483,    -1,  1419,     5,  1483,    -1,    -1,   198,    -1,
     546,   485,  1455,   448,    -1,   301,   485,  1424,   448,  1423,
      -1,   352,  1425,    -1,  1426,    -1,  1479,    -1,  1479,   485,
    1426,   448,    -1,  1483,    -1,  1426,     5,  1483,    -1,   530,
     485,  1428,   448,    -1,   416,   485,  1428,   448,    -1,   314,
     485,  1428,   448,    -1,  1483,    -1,  1428,     5,  1483,    -1,
    1427,    -1,  1422,    -1,  1421,    -1,   455,  1486,    -1,   264,
      -1,   263,    -1,   262,    -1,  1024,  1471,  1432,  1433,    -1,
      -1,  1430,    -1,    -1,  1434,    -1,  1435,    -1,  1434,  1435,
      -1,  1436,  1366,    -1,   430,    -1,   214,    -1,   530,    -1,
     416,    -1,  1423,    -1,   546,   485,  1455,   448,    -1,   314,
      -1,   175,  1438,  1440,    -1,  1439,    -1,  1481,    -1,  1441,
      -1,  1440,  1441,    -1,  1417,    -1,  1407,    -1,   502,  1455,
      -1,   425,  1444,    -1,  1521,    -1,  1444,     5,  1521,    -1,
     580,  1455,    -1,   600,  1447,    -1,  1448,    -1,  1447,     5,
    1448,    -1,  1449,    -1,   569,  1449,    -1,   569,   485,  1450,
     448,    -1,  1479,    -1,  1479,  1485,    -1,  1479,   670,  1485,
      -1,  1448,    -1,  1450,     5,  1448,    -1,  1446,  1452,  1453,
    1454,    -1,    -1,  1445,    -1,    -1,  1443,    -1,    -1,  1442,
      -1,  1456,    -1,  1455,     6,  1456,    -1,  1457,    -1,  1456,
       7,  1457,    -1,  1458,    -1,     9,  1458,    -1,  1469,    -1,
     485,  1455,   448,    -1,   497,  1517,    -1,   350,  1517,    -1,
      -1,   496,  1462,    -1,  1523,    -1,  1526,    -1,  1522,   676,
     485,  1464,   448,    -1,  1522,   676,  1517,    -1,  1522,   483,
     485,  1464,   448,    -1,  1522,   483,  1517,    -1,  1465,    -1,
    1464,     5,  1465,    -1,  1584,    -1,  1486,    -1,    -1,     9,
      -1,  1522,  1466,   443,    -1,  1522,  1466,   305,    -1,  1522,
    1468,  1522,    -1,  1522,  1466,   445,  1522,     7,  1522,    -1,
    1522,   610,  1461,  1460,    -1,  1522,   428,  1461,  1460,    -1,
    1522,   727,  1461,  1460,    -1,  1522,   429,  1461,  1460,    -1,
    1522,  1466,    10,  1461,  1460,    -1,    14,    -1,    17,    -1,
      12,    -1,    13,    -1,   726,    -1,    16,    -1,    15,    -1,
    1467,    -1,  1463,    -1,  1459,    -1,    -1,   639,    -1,   416,
      -1,   530,    -1,  1472,    -1,  1473,    -1,  1475,    -1,   375,
      -1,   375,   485,  1476,   448,    -1,    -1,   526,    -1,   526,
     485,    26,   448,    -1,   453,    -1,   453,   485,  1477,  1474,
     448,    -1,   566,   485,  1477,  1474,   448,    -1,   566,    -1,
     591,    -1,   463,    -1,   437,    -1,   376,    -1,   376,   485,
    1476,   448,    -1,   377,    -1,   377,   485,    26,   448,    -1,
     377,   485,    26,     5,    26,   448,    -1,   414,  1492,   679,
    1493,    -1,   414,    -1,   426,  1492,   679,  1493,    -1,   426,
      -1,   426,  1492,   485,    26,   448,   679,  1493,    -1,   628,
      -1,   587,    -1,   478,    -1,   478,   485,    26,   448,    -1,
     478,   485,    26,     5,    26,   448,    -1,    -1,     5,  1478,
      -1,   556,   485,  1477,   448,    -1,   619,    -1,   355,    -1,
     556,    -1,   120,    -1,    26,    -1,    26,    -1,    26,    -1,
      25,   673,  1024,    -1,    25,    -1,  1024,    -1,  1024,   643,
    1024,    -1,  1024,   643,    25,   673,  1024,    -1,  1024,   665,
    1024,    -1,  1024,   665,  1024,   643,  1024,    -1,  1024,   665,
    1024,   643,    25,   673,  1024,    -1,    25,   673,  1024,    -1,
      25,    -1,  1024,    -1,  1024,   643,  1024,    -1,  1024,   643,
      25,   673,  1024,    -1,  1024,   665,  1024,    -1,  1024,   665,
    1024,   643,  1024,    -1,  1024,   665,  1024,   643,    25,   673,
    1024,    -1,  1024,    -1,    -1,   513,    26,   481,    -1,   513,
      26,     5,    26,   481,    -1,  1484,    -1,   665,  1484,    -1,
    1024,  1482,    -1,  1479,   673,  1024,  1482,    -1,  1479,   673,
      20,    -1,  1024,    -1,    25,    -1,  1030,    -1,    26,    -1,
    1488,    -1,   451,  1490,    -1,   451,  1489,    -1,    -1,  1492,
     679,  1493,    -1,    -1,  1491,   679,  1491,    -1,   635,    -1,
     567,    -1,   644,    -1,   606,    -1,   508,    -1,   524,    -1,
     423,    -1,   423,   485,    26,   448,    -1,   635,    -1,   567,
      -1,   644,    -1,   606,    -1,   508,    -1,   524,    -1,   423,
      -1,   635,    -1,   567,    -1,   644,    -1,   606,    -1,   508,
      -1,   524,    -1,   423,    -1,   423,   485,    26,   448,    -1,
    1024,    -1,  1024,   665,  1024,    -1,    25,    -1,  1535,   557,
    1018,    -1,    -1,  1535,   454,  1385,   491,   649,  1504,  1497,
      -1,    -1,  1535,   454,  1385,   491,   156,   649,  1505,  1498,
      -1,    -1,  1535,   454,  1385,   194,  1505,  1499,    -1,    -1,
    1535,   454,  1385,   195,   156,   649,  1505,  1500,    -1,    -1,
     344,    -1,   343,  1502,    -1,  1503,    -1,  1502,     5,  1503,
      -1,  1024,    -1,  1024,   673,  1024,    -1,    25,   673,  1024,
     673,  1024,    -1,  1505,    -1,  1375,    -1,  1237,    -1,  1507,
      -1,  1507,    -1,    -1,    -1,   525,  1518,  1508,  1519,  1509,
    1515,  1451,  1513,  1501,    -1,   525,  1518,  1519,  1451,  1513,
      -1,  1512,    -1,  1530,    -1,   525,  1518,  1519,  1515,  1451,
    1513,    -1,    -1,   579,  1470,  1511,    -1,  1394,    -1,   389,
    1514,  1344,    -1,  1394,   389,  1514,  1344,    -1,  1024,    -1,
      -1,   607,  1201,    -1,   525,  1518,  1519,  1451,    -1,   485,
     525,  1518,  1519,  1451,   448,    -1,    -1,   639,    -1,   416,
      -1,   530,    -1,  1520,    -1,  1519,     5,  1520,    -1,  1522,
      -1,  1522,  1024,    -1,  1522,   670,  1024,    -1,  1522,    -1,
    1523,    -1,    19,  1523,    -1,    18,  1523,    -1,  1524,    -1,
    1584,    -1,  1517,    -1,   639,  1517,    -1,   640,  1517,    -1,
     624,  1517,    -1,   665,  1024,    -1,   665,  1024,   673,  1024,
      -1,  1523,    21,  1522,    -1,  1523,  1544,    -1,  1523,    20,
    1522,    -1,  1523,    18,  1522,    -1,  1523,    19,  1522,    -1,
    1486,    -1,   538,    -1,   482,    -1,   630,    -1,    20,    -1,
     121,    -1,   642,   485,  1470,  1522,   448,    -1,   654,   485,
    1470,  1522,   448,    -1,   655,   485,  1470,  1522,   448,    -1,
     662,   485,  1470,  1522,   448,    -1,   550,   485,  1470,  1522,
     448,    -1,  1024,   485,  1525,   448,    -1,   591,   485,  1525,
     448,    -1,   485,  1522,   448,    -1,   498,   485,  1545,   448,
      -1,  1546,    -1,  1548,    -1,  1522,    -1,  1525,     5,  1522,
      -1,  1486,    -1,  1535,   404,  1534,  1529,  1511,    -1,  1535,
     393,  1534,  1529,   304,  1479,  1531,    -1,  1535,   393,  1534,
    1529,  1180,    -1,    -1,   379,  1530,    -1,    25,    -1,  1180,
      -1,    -1,   485,  1532,   448,    -1,  1533,    -1,  1532,     5,
    1533,    -1,  1024,    -1,    25,    -1,  1180,    -1,    -1,   323,
    1536,   649,    -1,  1025,    -1,  1542,    -1,  1541,    -1,  1538,
      -1,   372,  1539,   679,  1539,    -1,   353,  1479,   673,  1540,
     679,  1540,    -1,  1024,    -1,  1024,    -1,   277,  1479,    -1,
     348,  1479,  1543,    -1,   327,    -1,   230,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     451,     5,  1492,   679,  1493,    -1,  1584,     5,  1492,   679,
    1493,    -1,   451,  1492,   679,  1493,    -1,  1522,     5,  1492,
     679,  1493,    -1,  1547,    -1,  1547,  1492,   679,  1493,    -1,
      37,    -1,  1549,    -1,  1549,  1492,   485,    26,   448,   679,
    1493,    -1,  1549,  1492,   679,  1493,    -1,    38,    -1,    -1,
     661,  1551,  1552,   245,    -1,  1553,    -1,  1552,  1553,    -1,
      33,    -1,  1554,    -1,  1556,    -1,    -1,   246,  1555,  1584,
      -1,    -1,   607,  1557,  1201,    -1,    -1,    -1,   532,  1479,
    1559,  1562,  1560,  1561,    -1,    -1,   206,  1018,    -1,   580,
    1455,    -1,   106,  1566,   448,    14,   485,  1567,   448,    -1,
     102,  1567,   448,    -1,   103,  1567,   448,    -1,   637,  1563,
      -1,   105,  1567,    -1,   104,  1567,    -1,  1565,    -1,  1563,
       5,  1565,    -1,  1483,    -1,  1564,    14,  1568,    -1,  1564,
      -1,  1566,     5,  1564,    -1,  1568,    -1,  1567,     5,  1568,
      -1,   537,    -1,  1569,    -1,  1570,    -1,    19,  1570,    -1,
      18,  1570,    -1,  1572,    -1,  1517,    -1,   665,  1024,    -1,
     665,  1024,   673,  1024,    -1,   665,  1024,   513,    26,   481,
      -1,   665,  1024,   673,  1024,   513,    26,   481,    -1,   665,
    1024,   513,    26,     5,    26,   481,    -1,   665,  1024,   673,
    1024,   513,    26,     5,    26,   481,    -1,  1571,    -1,  1486,
      -1,   538,    -1,   482,    -1,   630,    -1,   121,    -1,  1570,
      21,  1569,    -1,  1570,  1544,    -1,  1570,    20,  1569,    -1,
    1570,    18,  1569,    -1,  1570,    19,  1569,    -1,   642,   485,
    1470,  1569,   448,    -1,   654,   485,  1470,  1569,   448,    -1,
     655,   485,  1470,  1569,   448,    -1,   662,   485,  1470,  1569,
     448,    -1,   550,   485,  1470,  1569,   448,    -1,  1024,   485,
    1573,   448,    -1,   591,   485,  1573,   448,    -1,   485,  1569,
     448,    -1,   498,   485,  1545,   448,    -1,  1546,    -1,  1548,
      -1,  1584,    -1,  1569,    -1,  1573,     5,  1569,    -1,    -1,
     438,  1209,   610,  1575,  1576,    -1,  1577,    -1,  1576,     5,
    1577,    -1,  1479,   673,  1483,    -1,  1479,   673,    20,    -1,
    1580,    -1,  1580,    -1,   246,  1581,    -1,  1581,    -1,  1582,
      -1,    25,   673,  1582,    -1,  1583,    -1,  1582,   673,  1583,
      -1,  1582,   673,    20,    -1,  1585,    -1,  1024,    -1,  1579,
      -1,  1579,   475,  1579,    -1,  1024,  1586,    -1,   513,  1587,
     481,    -1,   513,  1587,   481,   513,  1587,   481,    -1,  1588,
      -1,  1587,     5,  1588,    -1,   743,    -1,    34,    -1,    -1,
      -1,   581,  1591,   929,  1592,  1605,   383,    -1,    -1,   712,
     972,    -1,    -1,   715,    -1,   237,    -1,   333,  1019,    -1,
     126,  1019,    -1,   363,    -1,   362,    -1,   364,  1021,  1593,
    1594,    -1,   547,   972,  1594,    -1,   160,    -1,   191,  1019,
      -1,   929,   620,     5,   929,   449,    -1,   563,   929,    -1,
     320,  1019,    -1,   157,  1600,     8,  1601,  1599,    -1,    -1,
     600,   929,    -1,  1024,    -1,  1024,    -1,   303,  1019,    -1,
     306,  1019,   679,   929,     5,   929,    -1,   306,  1019,   672,
     929,     5,   929,    -1,    27,    -1,    -1,  1607,    -1,  1608,
    1290,    -1,  1606,    -1,  1607,  1606,    -1,    -1,  1609,  1610,
      -1,   736,    -1,   737,    -1,   738,    -1,   739,    -1,   756,
      -1,   780,    -1,   801,    -1,   802,    -1,   808,    -1,   827,
      -1,   901,    -1,   902,    -1,   903,    -1,   904,    -1,   915,
      -1,   916,    -1,   917,    -1,   918,    -1,   919,    -1,   920,
      -1,   921,    -1,   974,    -1,  1005,    -1,  1009,    -1,  1031,
      -1,  1033,    -1,  1036,    -1,  1037,    -1,  1038,    -1,  1039,
      -1,  1052,    -1,  1062,    -1,  1086,    -1,  1087,    -1,  1089,
      -1,  1093,    -1,  1108,    -1,  1109,    -1,  1113,    -1,  1114,
      -1,  1115,    -1,  1116,    -1,  1126,    -1,  1141,    -1,  1157,
      -1,  1168,    -1,  1169,    -1,  1170,    -1,  1174,    -1,  1211,
      -1,  1214,    -1,  1216,    -1,  1222,    -1,  1223,    -1,  1226,
      -1,  1229,    -1,  1234,    -1,  1236,    -1,  1238,    -1,  1241,
      -1,  1248,    -1,  1253,    -1,  1258,    -1,  1259,    -1,  1260,
      -1,  1272,    -1,  1326,    -1,  1328,    -1,  1330,    -1,  1349,
      -1,  1350,    -1,  1370,    -1,  1373,    -1,  1402,    -1,  1404,
      -1,  1495,    -1,  1496,    -1,  1527,    -1,  1528,    -1,  1550,
      -1,  1574,    -1,  1589,    -1,  1590,    -1,  1595,    -1,  1596,
      -1,  1598,    -1,  1602,    -1,  1603,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1011,  1011,  1014,  1017,  1023,  1029,  1036,  1040,  1040,
    1046,  1065,  1066,  1067,  1068,  1069,  1080,  1086,  1087,  1088,
    1089,  1090,  1095,  1096,  1107,  1110,  1113,  1113,  1117,  1120,
    1121,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1146,  1147,
    1150,  1150,  1165,  1166,  1169,  1175,  1177,  1188,  1190,  1192,
    1194,  1198,  1200,  1262,  1266,  1270,  1270,  1280,  1284,  1287,
    1288,  1297,  1303,  1297,  1317,  1323,  1317,  1339,  1344,  1348,
    1339,  1360,  1364,  1360,  1372,  1377,  1372,  1396,  1403,  1407,
    1395,  1433,  1433,  1437,  1438,  1439,  1444,  1447,  1452,  1456,
    1464,  1465,  1468,  1468,  1474,  1478,  1493,  1491,  1509,  1509,
    1524,  1524,  1527,  1527,  1531,  1534,  1534,  1534,  1541,  1542,
    1541,  1549,  1549,  1560,  1560,  1573,  1597,  1605,  1573,  1621,
    1626,  1634,  1635,  1639,  1649,  1652,  1655,  1658,  1661,  1664,
    1677,  1682,  1682,  1683,  1683,  1686,  1691,  1691,  1695,  1714,
    1719,  1713,  1730,  1736,  1744,  1745,  1748,  1748,  1751,  1755,
    1760,  1767,  1767,  1771,  1771,  1772,  1772,  1773,  1773,  1774,
    1774,  1775,  1775,  1783,  1787,  1793,  1797,  1812,  1815,  1818,
    1821,  1824,  1827,  1833,  1844,  1849,  1862,  1866,  1881,  1882,
    1886,  1886,  1890,  1890,  1890,  1891,  1896,  1896,  1899,  1899,
    1908,  1909,  1910,  1913,  1917,  1918,  1918,  1935,  1935,  1935,
    1935,  1939,  1946,  1947,  1950,  1950,  1954,  1955,  1956,  1957,
    1962,  1962,  1968,  1968,  1977,  1974,  1990,  1990,  1992,  1992,
    1994,  1996,  1998,  2000,  2003,  2008,  2009,  2011,  2016,  2016,
    2017,  2017,  2021,  2021,  2033,  2033,  2038,  2042,  2044,  2045,
    2048,  2048,  2048,  2052,  2053,  2054,  2055,  2056,  2057,  2058,
    2059,  2060,  2061,  2062,  2063,  2066,  2067,  2068,  2069,  2073,
    2078,  2083,  2087,  2090,  2094,  2094,  2095,  2095,  2096,  2096,
    2097,  2098,  2099,  2100,  2101,  2102,  2105,  2106,  2107,  2137,
    2137,  2142,  2147,  2149,  2149,  2156,  2160,  2160,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,  2176,  2176,  2179,  2181,  2187,
    2189,  2195,  2203,  2203,  2206,  2207,  2208,  2209,  2210,  2211,
    2212,  2218,  2221,  2221,  2234,  2234,  2241,  2242,  2243,  2245,
    2246,  2247,  2251,  2252,  2253,  2254,  2259,  2265,  2271,  2272,
    2274,  2276,  2277,  2278,  2279,  2280,  2281,  2284,  2285,  2292,
    2300,  2300,  2308,  2305,  2320,  2320,  2322,  2322,  2330,  2330,
    2333,  2336,  2337,  2342,  2354,  2358,  2361,  2364,  2365,  2366,
    2367,  2368,  2373,  2380,  2386,  2391,  2396,  2391,  2409,  2411,
    2416,  2421,  2421,  2421,  2425,  2425,  2428,  2428,  2435,  2435,
    2442,  2442,  2453,  2471,  2477,  2501,  2504,  2519,  2522,  2535,
    2537,  2539,  2541,  2543,  2545,  2547,  2553,  2555,  2559,  2561,
    2563,  2565,  2567,  2569,  2571,  2577,  2594,  2595,  2596,  2597,
    2601,  2602,  2603,  2607,  2612,  2619,  2620,  2621,  2622,  2623,
    2624,  2625,  2626,  2627,  2628,  2629,  2636,  2636,  2641,  2641,
    2644,  2650,  2658,  2664,  2674,  2675,  2683,  2704,  2708,  2713,
    2718,  2720,  2723,  2741,  2746,  2752,  2757,  2762,  2763,  2769,
    2840,  2851,  2860,  2868,  2868,  2883,  2887,  2894,  2897,  2905,
    2909,  2912,  2918,  2927,  2932,  2940,  2943,  2946,  2951,  2958,
    2963,  2968,  2973,  2983,  2991,  2999,  3004,  3008,  3013,  3017,
    3021,  3028,  3031,  3034,  3038,  3042,  3046,  3050,  3058,  3068,
    3073,  3066,  3089,  3094,  3089,  3108,  3113,  3108,  3134,  3134,
    3134,  3137,  3137,  3137,  3141,  3141,  3141,  3145,  3145,  3145,
    3149,  3155,  3161,  3167,  3175,  3181,  3189,  3195,  3204,  3210,
    3217,  3224,  3233,  3239,  3245,  3252,  3258,  3264,  3270,  3278,
    3284,  3290,  3299,  3305,  3311,  3321,  3321,  3325,  3329,  3330,
    3341,  3342,  3348,  3358,  3368,  3378,  3379,  3382,  3387,  3393,
    3397,  3401,  3404,  3410,  3413,  3416,  3433,  3436,  3442,  3443,
    3444,  3448,  3449,  3450,  3451,  3452,  3454,  3455,  3456,  3458,
    3459,  3463,  3464,  3469,  3473,  3478,  3482,  3497,  3501,  3507,
    3496,  3520,  3521,  3533,  3539,  3533,  3553,  3553,  3555,  3556,
    3560,  3560,  3564,  3564,  3569,  3569,  3576,  3577,  3581,  3581,
    3585,  3585,  3590,  3590,  3597,  3601,  3602,  3603,  3608,  3608,
    3611,  3611,  3615,  3615,  3619,  3619,  3623,  3623,  3628,  3628,
    3633,  3633,  3638,  3638,  3643,  3643,  3659,  3663,  3658,  3671,
    3674,  3688,  3705,  3706,  3707,  3708,  3709,  3710,  3711,  3714,
    3714,  3717,  3719,  3722,  3725,  3728,  3733,  3738,  3741,  3746,
    3751,  3756,  3763,  3764,  3771,  3778,  3780,  3786,  3791,  3796,
    3801,  3801,  3804,  3810,  3815,  3818,  3825,  3825,  3827,  3830,
    3833,  3838,  3843,  3848,  3855,  3866,  3866,  3928,  3936,  3937,
    3945,  3952,  3952,  3956,  3961,  3967,  3971,  3975,  3981,  3985,
    3989,  3995,  3995,  4003,  4004,  4008,  4008,  4012,  4013,  4016,
    4019,  4019,  4022,  4024,  4024,  4027,  4029,  4029,  4030,  4032,
    4032,  4041,  4048,  4039,  4069,  4069,  4069,  4072,  4074,  4072,
    4081,  4084,  4091,  4096,  4107,  4107,  4111,  4117,  4117,  4121,
    4122,  4126,  4136,  4137,  4138,  4141,  4143,  4148,  4148,  4152,
    4151,  4159,  4158,  4165,  4165,  4171,  4171,  4178,  4178,  4184,
    4184,  4190,  4190,  4196,  4196,  4200,  4200,  4201,  4201,  4202,
    4202,  4203,  4203,  4207,  4207,  4218,  4222,  4228,  4232,  4237,
    4242,  4247,  4248,  4249,  4253,  4252,  4265,  4270,  4275,  4275,
    4291,  4297,  4298,  4299,  4300,  4301,  4311,  4325,  4325,  4328,
    4335,  4336,  4337,  4338,  4339,  4340,  4341,  4342,  4343,  4348,
    4348,  4350,  4353,  4353,  4355,  4359,  4362,  4363,  4366,  4366,
    4371,  4374,  4375,  4376,  4377,  4378,  4379,  4380,  4381,  4382,
    4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,  4391,  4395,
    4413,  4413,  4413,  4440,  4451,  4458,  4464,  4470,  4476,  4488,
    4511,  4512,  4515,  4519,  4518,  4536,  4536,  4540,  4541,  4549,
    4550,  4551,  4552,  4553,  4554,  4555,  4562,  4563,  4565,  4566,
    4570,  4575,  4576,  4577,  4578,  4579,  4580,  4581,  4582,  4583,
    4586,  4588,  4588,  4590,  4594,  4594,  4603,  4609,  4625,  4631,
    4602,  4645,  4659,  4670,  4658,  4683,  4690,  4690,  4695,  4701,
    4709,  4714,  4715,  4718,  4721,  4721,  4729,  4735,  4746,  4747,
    4755,  4761,  4755,  4772,  4773,  4777,  4777,  4784,  4784,  4799,
    4799,  4813,  4824,  4823,  4835,  4831,  4848,  4845,  4858,  4858,
    4860,  4861,  4863,  4864,  4867,  4868,  4869,  4871,  4876,  4881,
    4887,  4889,  4890,  4893,  4894,  4897,  4899,  4906,  4909,  4912,
    4915,  4919,  4923,  4924,  4925,  4926,  4927,  4931,  4936,  4936,
    4939,  4966,  5024,  5024,  5027,  5031,  5035,  5078,  5120,  5121,
    5122,  5125,  5139,  5151,  5151,  5156,  5157,  5163,  5228,  5233,
    5240,  5245,  5253,  5259,  5292,  5295,  5296,  5337,  5380,  5381,
    5385,  5386,  5390,  5443,  5448,  5452,  5457,  5468,  5475,  5483,
    5483,  5486,  5487,  5488,  5489,  5490,  5493,  5496,  5502,  5505,
    5509,  5514,  5522,  5527,  5534,  5536,  5542,  5544,  5544,  5544,
    5564,  5571,  5578,  5581,  5595,  5602,  5603,  5606,  5607,  5611,
    5617,  5622,  5628,  5629,  5634,  5638,  5638,  5642,  5643,  5646,
    5647,  5651,  5659,  5662,  5668,  5669,  5671,  5673,  5677,  5677,
    5678,  5683,  5691,  5692,  5697,  5698,  5700,  5713,  5715,  5716,
    5719,  5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,  5728,
    5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,  5738,
    5739,  5740,  5741,  5742,  5743,  5744,  5745,  5746,  5750,  5751,
    5755,  5756,  5770,  5778,  5778,  5780,  5784,  5788,  5792,  5796,
    5801,  5816,  5814,  5834,  5835,  5839,  5844,  5845,  5849,  5850,
    5852,  5853,  5855,  5855,  5864,  5873,  5873,  5883,  5884,  5889,
    5890,  5893,  5906,  5920,  5924,  5928,  5932,  5939,  5940,  5943,
    5943,  5947,  5950,  5950,  5952,  5958,  5966,  5972,  5974,  5978,
    5981,  5981,  5984,  5984,  5989,  5989,  5998,  5998,  6002,  6002,
    6003,  6003,  6004,  6004,  6018,  6018,  6038,  6039,  6040,  6041,
    6042,  6043,  6046,  6046,  6052,  6052,  6055,  6055,  6071,  6072,
    6073,  6082,  6094,  6095,  6098,  6099,  6102,  6105,  6105,  6110,
    6110,  6133,  6134,  6140,  6145,  6151,  6152,  6153,  6157,  6158,
    6159,  6160,  6164,  6174,  6176,  6181,  6184,  6189,  6195,  6202,
    6209,  6218,  6225,  6232,  6239,  6246,  6255,  6255,  6257,  6257,
    6260,  6261,  6262,  6263,  6264,  6265,  6266,  6267,  6268,  6269,
    6272,  6272,  6275,  6276,  6277,  6278,  6281,  6281,  6284,  6284,
    6287,  6288,  6289,  6290,  6291,  6292,  6293,  6294,  6296,  6297,
    6298,  6299,  6301,  6302,  6303,  6304,  6306,  6307,  6308,  6309,
    6310,  6311,  6312,  6313,  6317,  6325,  6335,  6348,  6359,  6370,
    6374,  6378,  6384,  6347,  6397,  6400,  6408,  6420,  6422,  6427,
    6437,  6447,  6450,  6454,  6462,  6426,  6471,  6475,  6479,  6483,
    6475,  6493,  6494,  6495,  6496,  6501,  6502,  6503,  6504,  6505,
    6506,  6507,  6508,  6512,  6513,  6516,  6521,  6528,  6529,  6530,
    6535,  6536,  6542,  6542,  6542,  6547,  6547,  6547,  6555,  6556,
    6560,  6561,  6566,  6567,  6568,  6569,  6570,  6573,  6575,  6575,
    6578,  6579,  6583,  6584,  6587,  6588,  6591,  6594,  6597,  6603,
    6604,  6616,  6617,  6622,  6623,  6624,  6628,  6631,  6637,  6640,
    6648,  6649,  6655,  6659,  6663,  6669,  6672,  6681,  6684,  6687,
    6690,  6693,  6696,  6699,  6706,  6709,  6716,  6719,  6725,  6728,
    6735,  6738,  6745,  6746,  6751,  6755,  6758,  6764,  6767,  6773,
    6780,  6781,  6785,  6795,  6798,  6804,  6806,  6811,  6812,  6816,
    6818,  6824,  6825,  6838,  6850,  6851,  6852,  6853,  6854,  6855,
    6856,  6857,  6858,  6861,  6864,  6870,  6870,  6876,  6876,  6887,
    6900,  6910,  6910,  6915,  6915,  6919,  6923,  6924,  6930,  6931,
    6936,  6940,  6947,  6950,  6957,  6956,  6967,  6971,  6975,  6982,
    6985,  6985,  6998,  7002,  7002,  7017,  7019,  7021,  7023,  7025,
    7027,  7029,  7031,  7037,  7047,  7054,  7059,  7060,  7064,  7067,
    7068,  7071,  7072,  7073,  7076,  7081,  7088,  7089,  7095,  7107,
    7108,  7109,  7112,  7112,  7117,  7122,  7127,  7128,  7131,  7132,
    7137,  7142,  7146,  7151,  7152,  7156,  7163,  7164,  7165,  7166,
    7171,  7172,  7173,  7176,  7177,  7178,  7182,  7183,  7184,  7188,
    7189,  7193,  7194,  7195,  7196,  7197,  7198,  7201,  7202,  7207,
    7208,  7213,  7214,  7219,  7220,  7225,  7230,  7231,  7236,  7237,
    7241,  7242,  7247,  7254,  7259,  7264,  7268,  7269,  7274,  7275,
    7281,  7284,  7288,  7293,  7294,  7300,  7303,  7306,  7313,  7314,
    7315,  7316,  7330,  7335,  7336,  7339,  7341,  7348,  7351,  7357,
    7365,  7369,  7373,  7377,  7382,  7385,  7388,  7395,  7402,  7407,
    7411,  7412,  7418,  7421,  7432,  7439,  7445,  7448,  7455,  7462,
    7468,  7469,  7475,  7476,  7477,  7480,  7481,  7488,  7495,  7495,
    7499,  7507,  7508,  7511,  7514,  7519,  7520,  7525,  7528,  7534,
    7537,  7543,  7546,  7552,  7555,  7562,  7563,  7592,  7593,  7597,
    7605,  7610,  7613,  7616,  7619,  7625,  7626,  7630,  7633,  7636,
    7637,  7642,  7645,  7648,  7651,  7654,  7657,  7660,  7663,  7668,
    7674,  7675,  7676,  7677,  7680,  7681,  7682,  7687,  7690,  7694,
    7700,  7701,  7702,  7703,  7715,  7716,  7717,  7721,  7722,  7726,
    7727,  7728,  7729,  7730,  7732,  7741,  7748,  7749,  7750,  7751,
    7752,  7753,  7754,  7756,  7758,  7760,  7761,  7763,  7764,  7766,
    7767,  7768,  7769,  7771,  7775,  7776,  7782,  7784,  7785,  7786,
    7787,  7792,  7796,  7800,  7804,  7811,  7815,  7816,  7817,  7825,
    7826,  7827,  7838,  7845,  7850,  7851,  7852,  7860,  7861,  7862,
    7879,  7888,  7889,  7890,  7894,  7897,  7902,  7907,  7912,  7920,
    7924,  7929,  7930,  7938,  7941,  7944,  7958,  7972,  7985,  7986,
    7990,  7990,  7990,  7990,  7990,  7990,  7991,  7994,  8011,  8011,
    8011,  8011,  8011,  8011,  8011,  8012,  8012,  8012,  8012,  8012,
    8012,  8012,  8012,  8015,  8016,  8017,  8020,  8029,  8029,  8035,
    8035,  8042,  8042,  8048,  8048,  8056,  8057,  8058,  8061,  8061,
    8064,  8065,  8066,  8077,  8080,  8086,  8091,  8098,  8111,  8112,
    8109,  8130,  8141,  8144,  8149,  8161,  8164,  8168,  8171,  8172,
    8182,  8185,  8186,  8195,  8204,  8209,  8210,  8211,  8212,  8219,
    8222,  8228,  8231,  8238,  8250,  8259,  8262,  8265,  8271,  8279,
    8282,  8283,  8284,  8285,  8286,  8289,  8295,  8297,  8299,  8301,
    8303,  8305,  8306,  8307,  8308,  8309,  8310,  8311,  8313,  8315,
    8317,  8319,  8321,  8323,  8325,  8326,  8328,  8329,  8335,  8336,
    8343,  8346,  8354,  8358,  8365,  8365,  8369,  8369,  8374,  8374,
    8378,  8378,  8382,  8388,  8388,  8391,  8391,  8397,  8404,  8405,
    8406,  8410,  8411,  8414,  8415,  8419,  8425,  8435,  8436,  8444,
    8445,  8446,  8447,  8448,  8449,  8453,  8454,  8455,  8456,  8460,
    8461,  8465,  8481,  8482,  8483,  8487,  8501,  8501,  8513,  8514,
    8518,  8519,  8520,  8844,  8844,  8851,  8851,  8939,  8943,  8939,
    8952,  8956,  8962,  8970,  8980,  8990,  9002,  9005,  9024,  9050,
    9053,  9059,  9062,  9067,  9070,  9078,  9086,  9099,  9102,  9110,
    9113,  9116,  9124,  9128,  9129,  9130,  9131,  9132,  9133,  9134,
    9135,  9139,  9140,  9141,  9142,  9143,  9149,  9150,  9151,  9152,
    9153,  9154,  9155,  9156,  9157,  9158,  9159,  9160,  9161,  9162,
    9163,  9164,  9169,  9175,  9176,  9184,  9184,  9192,  9192,  9196,
    9200,  9215,  9230,  9236,  9238,  9246,  9247,  9251,  9252,  9255,
    9262,  9265,  9294,  9320,  9374,  9410,  9419,  9430,  9433,  9438,
    9452,  9466,  9469,  9465,  9488,  9488,  9494,  9495,  9498,  9499,
    9500,  9501,  9502,  9503,  9504,  9515,  9518,  9523,  9527,  9532,
    9536,  9541,  9545,  9548,  9552,  9555,  9560,  9564,  9575,  9581,
    9581,  9582,  9583,  9590,  9600,  9600,  9602,  9603,  9604,  9605,
    9606,  9607,  9608,  9609,  9610,  9611,  9612,  9613,  9614,  9615,
    9616,  9617,  9618,  9619,  9620,  9621,  9622,  9623,  9624,  9625,
    9626,  9627,  9628,  9629,  9630,  9631,  9632,  9633,  9634,  9635,
    9636,  9637,  9638,  9639,  9640,  9641,  9642,  9643,  9644,  9645,
    9646,  9647,  9648,  9649,  9650,  9651,  9652,  9653,  9654,  9655,
    9656,  9657,  9658,  9659,  9660,  9661,  9662,  9663,  9664,  9665,
    9666,  9667,  9668,  9669,  9670,  9671,  9672,  9673,  9674,  9675,
    9676,  9677,  9678,  9679,  9680,  9681,  9682,  9683,  9684,  9685,
    9686,  9687,  9688,  9689
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
  "MEMBER_FUNCTION", "DATETIME_VALUE", "INTERVAL_VALUE", "IN_LINE_MODE", 
  "IN_FORM_MODE", "FGL_SIZEOF", "IMPORT_PACKAGE", "DYNAMIC_ARRAY", 
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
  "END_CLASS", "KW_CLASS", "EXTENDS", "PIPE", "$accept", 
  "pause_screen_on_cmd", "pause_screen_off_cmd", "start_rpc_cmd", 
  "stop_rpc_cmd", "valid_port", "remote_func_list", "remote_func", 
  "arr_expr", "arr_next_math", "arr_int_sign", "opt_attributes", 
  "attributes_def", "@1", "attribs_sec", "attribute", "win_attributes", 
  "win_attributes_def", "@2", "wattribs_sec", "wattribute", "call_cmd", 
  "call_ext", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11", 
  "@12", "@13", "@14", "@15", "@16", "@17", "opt_return", 
  "opt_return_remote", "opt_func_call_args", "func_call_args", "func_arg", 
  "remote_host_name", "remote_func_name", "case_cmd", "@18", "@19", 
  "when_unit", "when_unit_expr", "end_case_command", 
  "op_otherwise_command", "@20", "op_otherwise_command_expr", "@21", 
  "when_command", "@22", "when_command_expr", "@23", "class_definition", 
  "@24", "@25", "@26", "op_extends", "class_entries", "class_entry", 
  "close_cmd", "code_cmd", "emb_code", "sql_code", "sql_code_part", 
  "c_code", "c_code_part", "construct_cmd", "@27", "@28", "constr_rest", 
  "end_constr", "constr_col_list", "constr_col", "constr_extra_commands", 
  "constr_extra_command", "@29", "@30", "@31", "@32", "@33", 
  "bef_c_field_list_as_struct", "aft_c_field_list_as_struct", 
  "interval_expr", "extend_parameters", "op_datetime_qual", "defer_cmd", 
  "define_section", "define_multiple", "define_set", "@34", "@35", 
  "def_part", "define_ident", "@36", "def_part2", "@37", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@38", "@39", "@40", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "define_table_name", "record_variable", "@41", "@42", "@43", 
  "link_to_pk_list", "link_to_pk", "dtype_ident", "op_as_static", 
  "dtype2", "@44", "@45", "dtype", "@46", "@47", "@48", "op_prec", 
  "like_var", "col_name", "datetime_qual", "interval_qual", "dtime_start", 
  "@49", "dtime_val", "dtime_end", "@50", "opt_frac", "opt_unit_size", 
  "dtfrac", "int_start", "@51", "int_start_unit", "int_end", "op_equal", 
  "dim_section", "@52", "dim_dtype", "dim_like_var", "dim_array_variable", 
  "@53", "@54", "dim_record_variable", "@55", "@56", "dim_def_part", 
  "dim_def_part2", "dim_var_def_list", "dim_var_def_name", "opt_at", 
  "display_b_n_cmd", "display_cmd", "display_form_cmd", 
  "display_array_cmd", "@57", "@58", "opt_scroll", "display_attr", 
  "disp_rest", "disp_field_commands", "disp_field_command", "@59", "@60", 
  "@61", "alloc_arr_cmd", "dealloc_arr_cmd", "resize_arr_cmd", 
  "error_cmd", "exit_prog_cmd", "ext_cmd", "continue_cmd", "fgl_expr_c", 
  "fgl_next", "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
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
  "opt_allopts", "option_run_mode", "option_pipe_mode", "prepare_cmd", 
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@135", 
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@136", "prompt_title", 
  "put_cmd", "@137", "put_from", "put_val_list", "put_val", "start_cmd", 
  "op_convert", "rout", "rep_name", "op_values", "output_cmd", 
  "finish_cmd", "term_rep_cmd", "report_section", "format_section", 
  "format_actions", "format_action", "@138", "@139", "@140", "@141", 
  "@142", "@143", "@144", "report_cmd", "need_command", "@145", 
  "op_lines", "skip_command", "@146", "opt_rep_expr_list", 
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
  "run_mode", "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", 
  "@163", "@164", "@165", "@166", "opt_cr_table_extra", "cr_table_extra", 
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
       0,   256,  1718,  1719,  1720,  1621,  1661,  1616,  1553,  1636,
    1433,  1539,  1535,  1450,  1611,  1352,  1409,  1481,  1647,  1634,
    1540,  1567,  1635,  1416,  1721,  1722,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1000,  1001,  1002,  1003,
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
    1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1353,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1408,  1410,  1411,  1412,  1413,  1414,  1415,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,
    1530,  1531,  1532,  1533,  1534,  1536,  1537,  1538,  1541,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1612,  1613,  1614,  1615,
    1617,  1618,  1619,  1620,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1633,  1637,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1645,  1646,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,
    1713,  1714,  1715,  1716,  1717
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   735,   736,   737,   738,   739,   740,   740,   741,   741,
     742,   743,   743,   743,   743,   743,   743,   744,   744,   744,
     744,   744,   745,   745,   746,   746,   748,   747,   747,   749,
     749,   750,   750,   750,   750,   750,   750,   750,   750,   750,
     750,   750,   750,   750,   750,   750,   750,   750,   751,   751,
     753,   752,   754,   754,   755,   755,   755,   755,   755,   755,
     755,   755,   755,   756,   757,   758,   757,   757,   757,   757,
     757,   759,   760,   757,   761,   762,   757,   763,   764,   765,
     757,   766,   767,   757,   768,   769,   757,   770,   771,   772,
     757,   773,   773,   774,   774,   774,   775,   775,   776,   776,
     777,   777,   778,   778,   779,   779,   781,   780,   782,   780,
     783,   783,   784,   784,   785,   786,   787,   786,   788,   789,
     788,   791,   790,   793,   792,   795,   796,   797,   794,   798,
     798,   799,   799,   800,   801,   801,   801,   801,   801,   801,
     802,   803,   803,   804,   804,   805,   806,   806,   807,   809,
     810,   808,   811,   811,   812,   812,   813,   813,   814,   814,
     814,   815,   815,   817,   816,   818,   816,   819,   816,   820,
     816,   821,   816,   822,   822,   823,   823,   824,   824,   824,
     824,   824,   824,   825,   826,   826,   827,   827,   828,   828,
     829,   829,   831,   832,   830,   830,   833,   833,   835,   834,
     836,   836,   836,   836,   836,   837,   836,   838,   838,   838,
     838,   839,   840,   840,   841,   841,   842,   842,   842,   842,
     844,   843,   845,   843,   846,   843,   847,   847,   848,   848,
     849,   850,   850,   850,   851,   852,   852,   852,   854,   853,
     855,   853,   856,   853,   857,   857,   858,   859,   860,   860,
     862,   863,   861,   864,   864,   864,   864,   864,   864,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   864,
     864,   864,   864,   864,   865,   864,   866,   864,   867,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   868,
     868,   869,   870,   871,   871,   872,   874,   873,   875,   875,
     875,   875,   875,   875,   875,   877,   876,   878,   878,   879,
     879,   880,   882,   881,   883,   883,   883,   883,   883,   883,
     883,   884,   885,   885,   887,   886,   888,   888,   888,   888,
     888,   888,   888,   888,   888,   888,   888,   888,   888,   888,
     888,   888,   888,   888,   888,   888,   888,   888,   888,   889,
     891,   890,   892,   890,   894,   893,   895,   893,   896,   896,
     897,   898,   898,   899,   900,   900,   900,   900,   900,   900,
     900,   900,   901,   902,   903,   905,   906,   904,   907,   907,
     908,   909,   909,   909,   910,   910,   912,   911,   913,   911,
     914,   911,   915,   916,   917,   918,   918,   919,   919,   920,
     920,   920,   920,   920,   920,   920,   920,   920,   921,   921,
     921,   921,   921,   921,   921,   921,   922,   922,   922,   922,
     922,   922,   922,   922,   922,   923,   923,   923,   923,   923,
     923,   923,   923,   923,   923,   923,   924,   924,   925,   925,
     926,   926,   927,   927,   928,   928,   929,   930,   930,   930,
     930,   930,   930,   931,   931,   931,   931,   932,   932,   933,
     934,   934,   934,   935,   934,   936,   936,   937,   937,   938,
     938,   938,   938,   939,   939,   940,   940,   940,   940,   940,
     940,   940,   940,   941,   942,   943,   943,   943,   943,   943,
     943,   944,   944,   944,   944,   944,   944,   944,   945,   947,
     948,   946,   949,   950,   946,   951,   952,   946,   954,   955,
     953,   956,   957,   953,   958,   959,   953,   960,   961,   953,
     953,   953,   953,   953,   953,   953,   953,   953,   953,   953,
     953,   953,   953,   953,   953,   953,   953,   953,   953,   953,
     953,   953,   953,   953,   953,   962,   962,   963,   964,   964,
     964,   964,   964,   964,   964,   964,   964,   965,   965,   966,
     966,   966,   966,   967,   967,   967,   968,   968,   969,   969,
     969,   970,   970,   970,   970,   970,   970,   970,   970,   970,
     970,   971,   971,   972,   972,   973,   973,   975,   976,   977,
     974,   978,   978,   980,   981,   979,   982,   982,   983,   983,
     984,   984,   986,   985,   987,   985,   988,   988,   989,   989,
     991,   990,   992,   990,   993,   994,   994,   994,   995,   995,
     996,   996,   997,   997,   998,   998,  1000,   999,  1001,   999,
    1002,   999,  1003,   999,  1004,   999,  1006,  1007,  1005,  1008,
    1008,  1009,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1011,
    1011,  1012,  1013,  1014,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1016,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1023,  1024,  1025,  1026,  1026,  1027,  1027,  1028,  1028,
    1028,  1028,  1028,  1028,  1029,  1030,  1030,  1031,  1032,  1032,
    1033,  1034,  1034,  1035,  1036,  1037,  1037,  1037,  1038,  1038,
    1038,  1040,  1039,  1041,  1041,  1042,  1042,  1043,  1043,  1044,
    1045,  1045,  1046,  1047,  1047,  1048,  1049,  1049,  1050,  1051,
    1051,  1053,  1054,  1052,  1055,  1056,  1055,  1057,  1058,  1055,
    1059,  1059,  1060,  1061,  1063,  1062,  1062,  1064,  1064,  1065,
    1065,  1066,  1067,  1067,  1067,  1068,  1068,  1069,  1069,  1071,
    1070,  1072,  1070,  1073,  1070,  1074,  1070,  1075,  1070,  1076,
    1070,  1077,  1070,  1078,  1070,  1079,  1070,  1080,  1070,  1081,
    1070,  1082,  1070,  1083,  1070,  1084,  1084,  1085,  1085,  1086,
    1087,  1088,  1088,  1088,  1090,  1089,  1091,  1091,  1092,  1091,
    1093,  1094,  1094,  1094,  1094,  1094,  1094,  1095,  1095,  1096,
    1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1099,
    1098,  1098,  1101,  1100,  1102,  1103,  1104,  1104,  1105,  1105,
    1106,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,
    1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1108,
    1110,  1111,  1109,  1112,  1112,  1113,  1114,  1115,  1116,  1116,
    1117,  1117,  1118,  1120,  1119,  1121,  1121,  1122,  1122,  1123,
    1123,  1123,  1123,  1123,  1123,  1123,  1124,  1124,  1125,  1125,
    1126,  1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,
    1128,  1129,  1129,  1130,  1131,  1131,  1133,  1134,  1135,  1136,
    1132,  1137,  1139,  1140,  1138,  1141,  1142,  1142,  1143,  1143,
    1144,  1145,  1145,  1146,  1148,  1147,  1149,  1149,  1149,  1149,
    1151,  1152,  1150,  1153,  1153,  1155,  1154,  1156,  1154,  1158,
    1157,  1159,  1161,  1160,  1162,  1160,  1163,  1160,  1164,  1164,
    1165,  1165,  1166,  1166,  1167,  1167,  1167,  1168,  1169,  1170,
    1171,  1171,  1171,  1172,  1172,  1173,  1173,  1174,  1175,  1175,
    1175,  1175,  1176,  1176,  1176,  1176,  1176,  1177,  1178,  1178,
    1179,  1180,  1181,  1181,  1182,  1183,  1183,  1183,  1183,  1183,
    1183,  1184,  1185,  1186,  1186,  1187,  1187,  1188,  1189,  1189,
    1190,  1190,  1191,  1192,  1193,  1193,  1193,  1193,  1193,  1193,
    1194,  1194,  1195,  1196,  1196,  1197,  1197,  1198,  1198,  1199,
    1199,  1200,  1200,  1200,  1200,  1200,  1201,  1201,  1202,  1202,
    1203,  1203,  1204,  1205,  1206,  1206,  1207,  1208,  1208,  1208,
    1209,  1209,  1210,  1210,  1211,  1212,  1212,  1213,  1213,  1214,
    1215,  1216,  1217,  1217,  1218,  1219,  1219,  1220,  1220,  1221,
    1221,  1222,  1223,  1223,  1224,  1224,  1224,  1224,  1225,  1225,
    1225,  1226,  1227,  1227,  1228,  1228,  1228,  1229,  1230,  1230,
    1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,
    1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,
    1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1232,  1232,
    1233,  1233,  1234,  1235,  1235,  1236,  1236,  1236,  1236,  1236,
    1237,  1239,  1238,  1240,  1240,  1241,  1242,  1242,  1243,  1243,
    1244,  1244,  1246,  1245,  1247,  1249,  1248,  1250,  1250,  1251,
    1251,  1252,  1252,  1253,  1253,  1253,  1253,  1254,  1254,  1255,
    1255,  1256,  1257,  1257,  1258,  1259,  1260,  1261,  1262,  1262,
    1263,  1263,  1265,  1264,  1266,  1264,  1267,  1264,  1268,  1264,
    1269,  1264,  1270,  1264,  1271,  1264,  1272,  1272,  1272,  1272,
    1272,  1272,  1274,  1273,  1275,  1275,  1277,  1276,  1276,  1276,
    1276,  1276,  1278,  1278,  1279,  1279,  1280,  1281,  1281,  1283,
    1282,  1284,  1284,  1285,  1286,  1287,  1287,  1287,  1288,  1288,
    1288,  1288,  1289,  1290,  1290,  1291,  1291,  1292,  1293,  1293,
    1293,  1293,  1293,  1293,  1293,  1293,  1294,  1294,  1295,  1295,
    1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,
    1297,  1297,  1298,  1298,  1298,  1298,  1299,  1299,  1300,  1300,
    1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,
    1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,
    1301,  1301,  1301,  1301,  1302,  1302,  1302,  1304,  1305,  1306,
    1307,  1308,  1309,  1303,  1310,  1310,  1311,  1312,  1312,  1314,
    1315,  1316,  1317,  1318,  1319,  1313,  1320,  1322,  1323,  1324,
    1321,  1325,  1325,  1325,  1325,  1326,  1326,  1326,  1326,  1326,
    1326,  1326,  1326,  1327,  1327,  1328,  1329,  1329,  1329,  1329,
    1330,  1330,  1332,  1333,  1331,  1334,  1335,  1331,  1336,  1336,
    1337,  1337,  1338,  1338,  1338,  1338,  1338,  1339,  1340,  1340,
    1341,  1341,  1342,  1342,  1343,  1343,  1343,  1343,  1343,  1344,
    1344,  1345,  1345,  1346,  1346,  1346,  1347,  1347,  1348,  1348,
    1349,  1349,  1350,  1350,  1350,  1351,  1351,  1352,  1352,  1352,
    1352,  1352,  1352,  1352,  1353,  1353,  1354,  1354,  1355,  1355,
    1356,  1356,  1357,  1357,  1358,  1359,  1359,  1360,  1360,  1361,
    1362,  1362,  1363,  1364,  1364,  1365,  1365,  1366,  1366,  1367,
    1367,  1368,  1368,  1369,  1370,  1370,  1370,  1370,  1370,  1370,
    1370,  1370,  1370,  1370,  1370,  1371,  1371,  1372,  1372,  1373,
    1374,  1376,  1375,  1378,  1377,  1377,  1379,  1379,  1380,  1380,
    1381,  1381,  1382,  1382,  1384,  1383,  1385,  1386,  1386,  1387,
    1388,  1387,  1389,  1390,  1389,  1391,  1391,  1391,  1391,  1391,
    1391,  1391,  1391,  1392,  1393,  1394,  1395,  1395,  1396,  1397,
    1397,  1398,  1398,  1398,  1399,  1400,  1401,  1401,  1402,  1403,
    1403,  1403,  1405,  1404,  1406,  1406,  1406,  1406,  1406,  1406,
    1406,  1406,  1406,  1406,  1406,  1406,  1407,  1407,  1407,  1407,
    1408,  1408,  1408,  1409,  1409,  1409,  1410,  1410,  1410,  1411,
    1411,  1412,  1412,  1412,  1412,  1412,  1412,  1413,  1413,  1414,
    1414,  1415,  1415,  1416,  1416,  1417,  1418,  1418,  1419,  1419,
    1420,  1420,  1421,  1422,  1423,  1424,  1425,  1425,  1426,  1426,
    1427,  1427,  1427,  1428,  1428,  1429,  1429,  1429,  1430,  1430,
    1430,  1430,  1431,  1432,  1432,  1433,  1433,  1434,  1434,  1435,
    1436,  1436,  1436,  1436,  1436,  1436,  1436,  1437,  1438,  1439,
    1440,  1440,  1441,  1441,  1442,  1443,  1444,  1444,  1445,  1446,
    1447,  1447,  1448,  1448,  1448,  1449,  1449,  1449,  1450,  1450,
    1451,  1452,  1452,  1453,  1453,  1454,  1454,  1455,  1455,  1456,
    1456,  1457,  1457,  1458,  1458,  1459,  1459,  1460,  1460,  1461,
    1462,  1463,  1463,  1463,  1463,  1464,  1464,  1465,  1465,  1466,
    1466,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1469,  1469,  1469,
    1470,  1470,  1470,  1470,  1471,  1471,  1471,  1472,  1472,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1474,  1474,  1475,  1475,  1475,  1475,
    1475,  1476,  1477,  1478,  1479,  1479,  1479,  1479,  1479,  1479,
    1479,  1479,  1480,  1480,  1480,  1480,  1480,  1480,  1480,  1480,
    1481,  1482,  1482,  1482,  1483,  1483,  1484,  1484,  1484,  1485,
    1486,  1486,  1486,  1486,  1487,  1488,  1489,  1489,  1490,  1490,
    1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1494,  1494,  1494,  1495,  1497,  1496,  1498,
    1496,  1499,  1496,  1500,  1496,  1501,  1501,  1501,  1502,  1502,
    1503,  1503,  1503,  1504,  1504,  1505,  1505,  1506,  1508,  1509,
    1507,  1510,  1511,  1511,  1512,  1513,  1513,  1513,  1513,  1513,
    1514,  1515,  1515,  1516,  1517,  1518,  1518,  1518,  1518,  1519,
    1519,  1520,  1520,  1520,  1521,  1522,  1522,  1522,  1523,  1523,
    1523,  1523,  1523,  1523,  1523,  1523,  1524,  1524,  1524,  1524,
    1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,
    1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,  1525,  1525,
    1526,  1527,  1528,  1528,  1529,  1529,  1530,  1530,  1531,  1531,
    1532,  1532,  1533,  1534,  1534,  1535,  1535,  1536,  1537,  1537,
    1537,  1538,  1538,  1539,  1540,  1541,  1542,  1543,  1543,  1544,
    1544,  1544,  1544,  1544,  1544,  1545,  1545,  1545,  1545,  1546,
    1546,  1547,  1548,  1548,  1548,  1549,  1551,  1550,  1552,  1552,
    1553,  1553,  1553,  1555,  1554,  1557,  1556,  1559,  1560,  1558,
    1561,  1561,  1561,  1562,  1562,  1562,  1562,  1562,  1562,  1563,
    1563,  1564,  1565,  1566,  1566,  1567,  1567,  1568,  1568,  1569,
    1569,  1569,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,
    1570,  1570,  1570,  1570,  1570,  1570,  1571,  1571,  1571,  1571,
    1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,
    1571,  1571,  1572,  1573,  1573,  1575,  1574,  1576,  1576,  1577,
    1577,  1578,  1579,  1580,  1580,  1581,  1581,  1582,  1582,  1582,
    1583,  1583,  1584,  1584,  1585,  1586,  1586,  1587,  1587,  1588,
    1589,  1591,  1592,  1590,  1593,  1593,  1594,  1594,  1595,  1595,
    1595,  1595,  1595,  1595,  1595,  1596,  1596,  1597,  1597,  1598,
    1598,  1599,  1599,  1600,  1601,  1602,  1603,  1603,  1604,  1605,
    1605,  1606,  1607,  1607,  1609,  1608,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610
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
       1,     5,     3,     1,     1,     1,     3,     5,     0,     4,
       0,     5,     0,     7,     1,     3,     1,     1,     0,     1,
       0,     0,     4,     1,     1,     1,     1,     4,     4,     4,
       6,     4,     6,     1,     2,     1,     1,     1,     1,     4,
       6,     1,     4,     6,     0,     3,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     0,
       3,     4,     1,     0,     3,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     0,     3,     0,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     1,     0,     5,     1,     1,     1,     4,
       4,     6,     1,     1,     1,     1,     4,     6,     1,     4,
       6,     1,     1,     1,     1,     1,     2,     2,     1,     4,
       0,     7,     0,    12,     0,     4,     0,     5,     1,     3,
       2,     1,     3,     1,     0,     2,     2,     1,     2,     5,
       4,     2,     4,     5,     3,     0,     0,    11,     0,     2,
       1,     0,     2,     1,     1,     2,     0,     3,     0,     3,
       0,     3,     2,     2,     2,     4,     5,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     1,
       3,     4,     4,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     1,     0,     3,     2,     2,     1,     3,     4,
       4,     5,     5,     1,     1,     2,     2,     4,     4,     2,
       2,     4,     4,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     0,
       0,     6,     0,     0,     8,     0,     0,     8,     0,     0,
       6,     0,     0,     6,     0,     0,     6,     0,     0,     6,
       5,     5,     5,     5,     7,     7,     9,     9,     6,     8,
      10,    10,     7,     9,     8,    10,    12,    14,    14,    10,
      12,    12,     4,     4,     6,     0,     3,     1,     1,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     4,
       4,     2,     2,     2,     2,     2,     1,     1,     2,     1,
       1,     1,     2,     4,     6,     6,     3,     5,     5,     3,
       1,     1,     3,     1,     3,     1,     3,     0,     0,     0,
       9,     0,     3,     0,     0,    10,     0,     1,     0,     1,
       1,     2,     0,     3,     0,     3,     0,     1,     1,     2,
       0,     3,     0,     3,     3,     1,     4,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     0,     3,     0,     3,
       0,     4,     0,     4,     0,     4,     0,     0,    11,     0,
       2,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     4,     6,     4,     3,     6,
       3,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     4,     1,     1,     1,     4,
       3,     6,     3,     6,     1,     1,     2,     2,     1,     2,
       2,     1,     3,     1,     2,     2,     2,     4,     2,     2,
       4,     0,     8,     0,     1,     1,     1,     0,     1,     2,
       0,     1,     2,     0,     1,     2,     0,     1,     3,     0,
       2,     0,     0,     8,     0,     0,     3,     0,     0,     7,
       5,     2,     2,     2,     0,     5,     4,     1,     3,     3,
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
       1,     1,     1,     0,     3,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     0,     0,     0,     0,
      13,     1,     0,     0,     6,     2,     1,     2,     2,     2,
       1,     1,     2,     1,     0,     3,     2,     1,     1,     1,
       0,     0,     7,     1,     2,     0,     3,     0,     4,     0,
       5,     1,     0,     3,     0,     7,     0,     5,     1,     2,
       0,     1,     1,     1,     0,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     2,     2,     2,     5,     8,     1,     1,
       1,     4,     4,     1,     1,     1,     1,     2,     3,     6,
       1,     3,     1,     1,     1,     3,     6,     9,     1,     1,
       1,     1,     2,     0,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     3,     2,     0,     1,     1,
       1,     3,     1,     3,     7,     0,     7,     0,     6,     3,
       1,     3,     1,     2,     5,     0,     7,     0,     2,     0,
       1,     5,     2,     5,     0,     5,     6,     4,     0,     1,
       1,     5,     0,     2,     0,     5,     4,     2,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     5,     1,     1,     2,     4,     4,     6,     2,
       1,     0,    11,     0,     2,     5,     0,     1,     0,     2,
       1,     2,     0,     3,     1,     0,     4,     0,     2,     1,
       3,     1,     1,     4,     5,     5,     3,     0,     1,     1,
       1,     1,     0,     1,     7,     2,     2,     2,     2,     2,
       1,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     4,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     1,     0,     4,     1,     2,
       2,     2,     0,     1,     1,     2,     2,     0,     2,     0,
       4,     1,     3,     3,     5,     0,     2,     4,     1,     1,
       1,     1,     1,     0,     1,     1,     3,     2,     5,     2,
       5,     5,     5,     5,     5,     5,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     1,     1,     1,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     0,     3,     2,     0,     0,     0,
       0,     0,     0,    15,     0,     2,     2,     0,     1,     0,
       0,     0,     0,     0,     0,    15,     2,     0,     0,     0,
      10,     0,     1,     3,     3,     2,     3,     4,     3,     5,
       4,     3,     3,     1,     1,     1,     2,     2,     2,     2,
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
       1,     3,     1,     2,     4,     1,     2,     3,     1,     3,
       4,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     2,     0,     2,     1,
       1,     5,     3,     5,     3,     1,     3,     1,     1,     0,
       1,     3,     3,     3,     6,     4,     4,     4,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       1,     4,     1,     5,     5,     1,     1,     1,     1,     1,
       4,     1,     4,     6,     4,     1,     4,     1,     7,     1,
       1,     1,     4,     6,     0,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     5,     3,
       5,     7,     3,     1,     1,     3,     5,     3,     5,     7,
       1,     0,     3,     5,     1,     2,     2,     4,     3,     1,
       1,     1,     1,     1,     2,     2,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     0,     7,     0,
       8,     0,     6,     0,     8,     0,     1,     2,     1,     3,
       1,     3,     5,     1,     1,     1,     1,     1,     0,     0,
       9,     5,     1,     1,     6,     0,     3,     1,     3,     4,
       1,     0,     2,     4,     6,     0,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     1,     2,     2,     1,     1,
       1,     2,     2,     2,     2,     4,     3,     2,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     4,     4,     3,     4,     1,     1,     1,     3,
       1,     5,     7,     5,     0,     2,     1,     1,     0,     3,
       1,     3,     1,     1,     1,     0,     3,     1,     1,     1,
       1,     4,     6,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     4,     5,     1,
       4,     1,     1,     7,     4,     1,     0,     4,     1,     2,
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
     855,     0,  1940,     0,     0,     0,     0,   904,   192,     0,
       0,   852,   880,   883,   190,   195,   862,   859,     0,   850,
     851,   853,   856,   857,   860,   864,   865,   863,   900,   901,
     903,   861,   148,   145,     0,   141,   143,   142,   146,  1968,
     732,   672,   733,   324,  1715,  1713,   898,   188,   198,   899,
     125,   191,     1,   866,   858,   902,   140,   144,   147,     0,
       0,   649,     0,     0,   189,   907,   969,   650,   908,   909,
     905,   684,   961,     0,   962,   970,   968,   198,   193,   211,
       0,   196,   212,   250,   129,     0,   885,  1269,     0,   884,
    1257,   892,     0,     0,   877,   876,   878,   854,   867,   868,
     886,   871,   872,   875,   873,   874,   879,     0,  1714,   963,
     906,     0,     0,   977,   975,   976,   965,   964,   322,   198,
    1193,   205,   199,   198,   204,   247,     0,     0,   126,   731,
       0,     0,     0,   188,   593,   910,   869,     0,   356,   342,
     214,   328,   293,   312,   333,   335,   332,     0,   354,     0,
     341,   334,   338,   344,   343,   198,   345,   325,   348,   326,
     327,   974,   973,     0,    22,    23,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   982,     0,   556,
     548,    16,   555,   969,    15,     0,   980,     0,   323,     0,
     197,  1194,   194,     0,   211,   213,   288,   216,   276,   282,
     283,   267,   240,   278,   214,   255,   256,     0,   242,   293,
     312,   265,   268,   263,     0,   238,     0,   274,   266,   271,
     281,   280,   198,   284,   198,   253,   254,   251,   287,   130,
     188,     0,     0,     0,   893,   188,   188,     0,     0,   215,
       0,     0,   346,     0,     0,   347,     0,     0,     0,     0,
       0,     0,     0,   235,     0,   971,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   562,
       0,     0,     0,   685,   453,   455,  1264,     0,     0,     0,
    1688,     0,   449,     0,     0,     0,   448,     0,   463,   558,
       0,     0,     0,     0,     0,   561,   416,   422,   459,   456,
     417,   418,   420,   421,   454,   457,   462,   557,   511,   508,
     517,   514,     0,     0,    17,    18,    19,    20,    21,     0,
      14,     0,   499,     0,     0,   978,     0,   200,   203,   201,
     202,     0,   208,   207,   206,   209,   217,   218,   219,   222,
     289,   198,   289,     0,     0,     0,     0,   198,   285,   286,
       0,     0,   198,     0,   289,     0,     0,   264,   248,   127,
    1270,     0,  1258,  1974,   594,   911,   887,     0,   226,   227,
       0,     0,   305,   307,   302,   303,   299,   301,   298,   300,
     297,     0,   307,   318,   319,   315,   317,   314,   316,   309,
       0,     0,     0,   358,     0,   361,   363,   234,     0,   233,
       0,   198,   198,   198,     0,     0,     0,   583,   654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   580,   566,
     571,     0,   567,   570,   569,   663,     0,   662,   585,     0,
      11,   184,   447,   424,   423,     0,  1199,     0,     0,   461,
    1696,  1694,  1695,  1691,  1693,  1690,  1692,  1684,     0,     0,
       0,   460,     0,     0,     0,     0,     0,     0,     0,   686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   563,   564,   565,   474,     0,     0,   473,
     483,     0,     0,   428,     0,     0,   429,   419,   425,   427,
     430,   431,   432,   433,   434,   426,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    96,     0,   981,     0,   966,
     210,     0,     0,   277,     0,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,   198,   249,   252,
       0,   993,   730,   993,     0,  1972,  1974,  1193,  1815,   881,
       0,   993,     0,     0,   329,   294,     0,     0,   304,   321,
     295,   320,     0,   313,     0,   336,     0,   330,     0,   355,
       0,   360,   350,     0,     0,   339,   236,     0,   292,   349,
     542,     0,     0,   554,     0,     0,   551,   550,   553,   549,
     560,   545,   545,     0,     0,   545,     0,   568,     0,   572,
       0,   312,     0,   552,   559,   296,     0,  1265,  1755,     0,
       0,     0,     0,     0,   450,     0,     0,   464,     0,     0,
       0,     0,   466,   465,   484,   475,   490,   493,   494,   491,
     497,   496,   495,   485,   486,   487,   488,   489,   435,   476,
     480,   498,   492,   479,   498,   458,   512,   509,   518,   515,
     543,     0,   505,   101,   500,    97,    98,   100,   502,     0,
       0,   250,     0,     0,     0,   257,   258,     0,   261,     0,
       0,   269,     0,   259,   239,   220,     0,   272,   291,     0,
     131,   133,   999,     0,   994,   995,     0,   894,  1973,  1971,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1955,     0,  1390,  1389,     0,
    1391,     0,   412,  1388,  1305,     0,     5,  1387,   413,   410,
       0,   415,   186,   498,  1168,     0,     0,  1397,   137,   409,
     408,     0,     0,   403,   498,     0,  1341,  1948,     0,   414,
     375,     0,     3,     2,     0,   411,  1302,     0,     0,   404,
     401,   397,     0,     0,     0,     0,  1395,  1385,   407,     0,
       0,     0,     0,     0,     0,     0,     0,  1384,     0,     0,
       0,   187,     0,   400,   399,     0,     0,  1952,  1951,     0,
       0,     0,   149,     0,   406,   405,     0,     0,   402,   498,
       0,     0,   498,     0,   587,     0,     0,     0,     0,     0,
       0,   498,   839,  1267,     0,     0,  1179,     0,  1941,     0,
     108,     0,     0,   919,     0,     0,     0,     0,   840,     0,
       0,  1846,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   701,     0,     0,  1976,  1977,  1978,  1979,  1980,  1981,
    1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,
    1992,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,
    2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,
    2012,  2013,  2014,  2015,  2016,  2017,  2018,  2019,  2020,  2021,
    2022,  2023,  2024,   948,  2025,  2026,  2027,  2028,  2029,  2030,
    2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,
    2041,  1159,  1161,  1156,  1158,  1157,  1160,  2042,  2043,  1295,
    2044,  1301,  1300,  2045,  2046,  2047,  2048,  2049,  2050,  2051,
    2052,  2053,  2054,  1452,  2055,  2056,  2057,  2058,  2059,  2060,
    2061,  2062,  2063,  1975,   882,   598,     0,   915,     0,   913,
       0,   357,   228,   229,     0,   306,   311,     0,     0,     0,
       0,   359,   362,     0,   232,     0,   198,     0,   584,     0,
     658,     0,   660,     0,   523,   521,     0,   545,     0,   522,
       0,     0,   582,     0,   579,   576,   547,   520,   586,     0,
     183,  1757,  1758,  1756,     0,   452,  1264,     0,  1689,  1264,
     451,  1264,  1264,  1264,  1264,  1264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,    96,   979,     0,   223,   290,   241,     0,     0,
     198,     0,     0,     0,     0,   128,   132,     0,  1271,     0,
    1259,   394,   392,   393,  1299,  1094,  1093,  1099,     0,  1663,
    1664,     0,     0,  1325,   673,   674,  1326,  1655,  1656,  1328,
     870,  1131,  1136,  1950,   666,   136,  1963,     0,     0,  1340,
       7,     0,     6,     0,  1956,  1132,     0,  1227,  1226,  1171,
    1225,  1170,   446,  1398,  1386,     0,  1296,   895,   436,  1817,
    1392,   138,     0,  1135,   135,     0,   846,    24,   668,   398,
       0,   845,  1127,   847,     0,  1396,   941,   940,   943,   939,
     942,  1965,     0,   937,     0,   667,  1025,   938,  1959,     0,
    1949,   134,  1298,  1022,   734,  1020,     0,   664,  1944,   782,
     781,   783,   779,     0,     0,  1297,  1035,   669,  1451,     0,
    1931,  1446,  1449,  1921,  1924,  1925,  1927,  1930,     0,     0,
       0,     0,  1100,  1095,     0,  1074,  1075,  1076,  1077,  1083,
    1084,  1085,  1082,  1081,     0,     0,     0,  1080,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1066,  1057,  1058,  1008,     0,  1006,  1114,
     444,    24,     0,  1946,   139,   665,     0,  1268,  1266,  1192,
       0,  1806,     0,  1807,  1193,  1181,  1172,  1399,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,   969,     0,
      69,     0,   106,   641,     0,   688,   687,     0,  1162,  1042,
    1166,     0,     0,  1115,  1285,     0,     0,  1169,   693,   690,
     691,     0,   695,   696,     0,   698,   699,     0,   694,  1003,
    1005,     0,     0,  1004,   784,  1001,   745,   997,   960,     0,
       0,     0,     0,   705,   706,     0,     0,   958,   955,   956,
     952,   953,   954,   947,   951,   950,     0,     0,     0,     0,
       0,     0,   602,   604,   596,   599,   600,   917,  1974,   912,
     914,   888,     0,   308,   310,   337,   331,     0,     0,   340,
     237,   655,   657,     0,     0,     0,     0,   545,   528,     0,
     545,   545,     0,   573,     0,   305,     0,     0,  1785,  1680,
    1682,  1841,  1845,  1786,  1686,  1783,     0,     0,  1782,     0,
       0,     0,  1784,     0,     0,     0,     0,     0,     0,     0,
    1931,  1681,  1781,  1683,  1770,     0,  1759,  1761,  1765,  1768,
    1796,  1839,  1797,  1842,  1932,  1922,  1769,  1202,  1697,  1201,
    1200,  1203,  1205,  1204,  1198,   477,   478,   482,   467,     0,
     470,   481,     0,   469,   513,   510,   519,   516,   544,   506,
     501,    99,   503,   967,     0,   262,   246,     0,   244,   270,
     260,   250,   273,  1000,   188,   996,   188,     0,     0,     0,
    1370,  1371,     0,     0,     0,  1342,  1345,  1347,  1348,  1349,
    1353,  1352,  1350,  1351,     0,     0,     0,  1343,  1344,     0,
       0,     0,     0,     0,     0,     0,     0,  1133,     0,    24,
    1222,  1224,  1223,     0,   439,   440,   437,   438,  1013,     0,
       0,   380,    25,   374,     0,  1128,     0,  1127,     0,  1126,
       0,     0,     0,     0,     0,     0,  1029,  1816,     0,     0,
       0,     0,     0,     0,  1946,     0,     0,   150,     0,     0,
    1039,  1031,  1032,  1037,     0,     0,  1923,     0,  1934,  1447,
    1448,     0,     0,   957,   442,  1915,  1052,   364,     0,     0,
     588,   646,   645,   643,   648,  1060,   647,  1065,  1061,  1064,
     838,   830,   824,   836,   837,   822,   823,   831,   826,   832,
     825,   835,   829,   833,   828,   834,   821,   827,   814,   820,
    1062,  1063,     0,  1070,  1078,  1067,  1068,  1072,  1073,  1071,
    1069,  1088,  1089,  1086,  1079,  1090,  1091,  1087,     0,     0,
       0,   848,     0,     0,     0,     0,     0,   794,   793,   790,
    1947,  1954,    24,  1188,  1189,  1190,  1191,  1185,     0,  1183,
    1281,  1193,  1173,  1174,  1177,  1195,  1942,     0,     0,     0,
       0,   102,     0,   103,     0,     0,     0,    77,     0,     0,
       0,     0,   115,   110,     0,   689,   946,     0,   945,     0,
     498,  1164,     0,   988,   989,  1012,   983,   984,   841,  1010,
    1117,  1294,  1293,  1288,     0,  1292,  1291,  1286,  1850,  1853,
    1855,     0,  1848,  1851,  1852,   721,     0,     0,     0,   710,
     745,   745,   742,     0,     0,   746,     0,    26,   709,   712,
       0,   719,   715,   959,   949,  1813,  1814,  1804,  1804,  1416,
       0,     0,  1716,     0,     0,  1400,     0,     0,  1401,  1444,
       0,     0,  1445,     0,     0,  1755,     0,  1414,     0,  1463,
    1462,  1461,  1459,  1460,  1458,  1456,  1453,  1543,  1542,  1454,
    1455,  1464,  1737,  1457,  1820,  1819,  1818,  1465,  1974,  1974,
     615,   606,   597,     0,   601,  1974,   916,   188,     0,   351,
     231,     0,     0,   546,     0,   545,     0,   532,   545,     0,
     525,   524,     0,     0,     0,   578,   577,   185,  1767,  1766,
    1704,  1702,  1703,  1699,  1701,  1698,  1700,  1685,     0,  1755,
       0,     0,  1610,     0,     0,  1773,  1771,  1772,  1610,  1610,
    1610,  1610,  1774,     0,     0,     0,  1561,  1745,     0,  1762,
       0,     0,     0,     0,  1829,  1830,  1831,  1832,  1833,  1834,
    1777,     0,     0,     0,     0,   472,   471,     0,     0,     0,
     198,   243,   221,  1272,  1260,     0,     0,     0,     0,     0,
       0,  1517,  1516,  1515,  1377,     0,  1383,  1379,  1381,  1372,
       0,  1619,  1369,  1365,  1339,  1338,     0,  1364,  1360,     0,
    1356,  1354,     0,  1662,     0,  1665,  1667,   677,     0,   676,
    1654,     0,  1657,  1659,  1964,  1961,     0,     0,  1306,   498,
     372,  1327,     0,     0,  1303,  1044,  1129,  1130,  1127,  1123,
    1127,     0,   944,     0,     0,   651,     0,     0,     0,  1023,
    1021,   736,   737,     0,   741,     0,     0,  1945,  1953,   780,
       0,   154,     0,  1033,  1040,     0,     0,  1048,  1926,  1939,
       0,  1937,  1450,  1929,  1928,     0,     0,     0,  1054,   367,
       0,     0,     0,     0,    24,  1096,  1097,   591,     0,     0,
       0,   815,   816,  1059,  1009,  1007,   849,   445,     0,  1106,
     791,   795,   792,   796,   395,     0,  1193,  1182,  1282,  1197,
    1180,  1175,     0,     0,  1176,  1974,     0,     0,     0,     0,
       0,     0,     0,    64,    96,     0,     0,     0,   121,   116,
       0,   111,     0,   118,   112,   930,   922,   928,     0,  1163,
       0,  1165,  1167,     0,     0,   992,     0,     0,     0,     0,
    1116,  1287,  1290,     0,     0,     0,  1847,  1849,  1974,   692,
     697,   700,   713,   711,   670,     0,   769,   767,   765,   763,
     773,   771,     0,     0,   761,   811,   759,   744,   755,   753,
     809,   785,     0,   747,   757,  1002,   998,     0,     0,     0,
       0,   718,     0,     0,     0,     0,     0,     0,     0,  1670,
       0,  1538,  1539,  1825,  1496,  1561,     0,     0,     0,  1823,
       0,  1476,  1471,  1470,  1483,  1482,  1487,  1487,  1485,  1486,
    1477,  1472,     0,     0,  1478,  1479,  1738,  1857,     0,     0,
       0,   603,   605,     0,     0,   618,   610,   612,     0,   607,
     608,     0,     0,   626,   628,     0,     0,   624,   918,   889,
     230,     0,   659,   661,   656,     0,   545,   534,     0,   529,
       0,     0,   545,   545,   575,   574,     0,     0,  1794,  1686,
       0,     0,  1769,  1612,  1613,  1611,     0,  1798,     0,     0,
       0,     0,     0,     0,     0,  1760,     0,  1549,  1550,  1552,
    1555,     0,  1562,  1563,     0,     0,  1610,  1747,  1741,  1763,
    1779,  1780,  1778,  1776,     0,     0,     0,  1933,   468,   507,
     504,     0,   245,  1228,  1206,     0,     0,     0,     0,  1377,
       0,     0,     0,  1373,     0,     0,     0,  1367,  1650,  1648,
    1617,  1629,  1631,  1635,  1637,  1628,  1622,  1627,  1641,  1620,
    1649,  1625,  1640,  1626,  1647,  1639,  1523,  1614,  1615,  1616,
       0,  1362,  1358,     0,     0,  1346,     0,     0,   675,     0,
       0,     0,  1960,     0,     4,     8,    10,     0,   498,   441,
       0,     0,     0,  1041,  1125,  1124,     0,     0,     0,     0,
       0,     0,     0,     0,   735,     0,     0,   171,   169,     0,
       0,   151,     0,   161,   167,   745,   156,   158,     0,  1038,
    1049,  1050,     0,     0,  1935,   443,     0,  1916,  1917,  1053,
       0,     0,  1051,   366,   371,   653,   365,     0,   368,   373,
       0,   498,  1422,   644,   642,     0,   818,  1105,  1107,     0,
     396,  1186,  1184,     0,  1196,  1178,     0,     0,  1277,     0,
       0,     0,   104,     0,     0,    78,    84,    74,    71,  1974,
    1974,   114,   109,   123,   119,     0,   113,   812,   931,   670,
    1974,   921,   920,   929,  1043,     0,     0,   990,   991,   985,
    1011,   498,  1122,  1118,  1119,  1121,  1289,  1854,  1856,   722,
     716,   714,     0,    24,     0,  1974,  1974,  1974,  1974,  1974,
    1974,   775,   749,   777,   751,  1974,  1974,  1974,  1974,     0,
     743,   748,  1974,   670,   807,   805,   808,   806,     0,     0,
      46,    44,    41,    35,    39,    43,    38,    31,    40,     0,
      34,    37,    32,    42,    33,    45,    36,     0,    29,    47,
     799,     0,   720,  1805,     0,  1803,  1755,  1801,  1742,  1743,
    1735,  1721,  1736,     0,     0,     0,  1092,  1537,  1540,     0,
       0,     0,  1434,  1406,  1828,  1827,  1826,     0,     0,     0,
    1481,  1484,     0,     0,     0,     0,     0,  1429,     0,  1428,
       0,  1430,  1425,  1426,  1427,  1418,  1419,     0,     0,     0,
     617,   622,     0,     0,  1974,  1974,   595,   609,   632,   620,
     634,  1974,  1974,   630,   614,   625,   881,   352,   545,     0,
     533,   545,     0,   545,   545,   527,   526,  1711,  1709,  1710,
    1706,  1708,  1705,  1707,  1687,     0,     0,     0,     0,  1795,
       0,     0,     0,  1793,     0,     0,     0,     0,  1775,  1792,
       0,  1553,     0,     0,  1679,  1556,     0,     0,     0,     0,
    1548,  1567,  1569,  1571,  1609,  1608,  1607,  1573,  1589,     0,
    1564,  1565,  1750,  1329,     0,     0,     0,  1840,     0,  1844,
     224,     0,  1254,  1273,     0,  1261,  1254,     0,  1671,     0,
    1505,     0,  1508,  1674,     0,  1513,     0,     0,  1374,  1375,
       0,     0,  1378,  1380,  1382,     0,  1366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1521,  1520,  1519,
       0,  1524,  1525,     0,  1361,     0,  1355,  1357,  1666,     0,
    1668,  1658,     0,  1660,  1962,  1335,     0,  1331,     0,     0,
    1336,   896,     0,     0,     0,     0,     0,  1393,  1967,  1966,
     652,     0,     0,    48,     0,   738,   740,   739,  1394,   745,
    1974,  1974,   163,   678,   173,   165,   175,   155,   162,  1974,
       0,     0,     0,     0,     0,  1938,     0,     0,     0,     0,
       0,     0,  1098,     0,  1423,   589,     0,   817,  1103,     0,
    1283,  1284,  1943,     0,    96,     0,    65,     0,     0,     0,
      81,     0,    96,    96,    96,   122,   117,  1974,  1974,   107,
       0,   932,   926,   934,   933,   923,   639,   972,     0,     0,
       0,   724,   703,   717,   671,   786,     0,   770,   768,   766,
     764,   774,   772,     0,  1974,     0,  1974,   762,   760,   756,
     754,   810,   758,    24,   800,     0,     0,     0,    27,     0,
    1808,     0,  1722,     0,     0,  1734,  1717,  1733,  1541,     0,
    1498,     0,  1433,     0,     0,  1824,     0,  1821,     0,  1489,
    1493,  1469,  1491,  1494,     0,  1480,  1739,     0,     0,     0,
       0,     0,     0,  1858,  1432,  1431,  1420,  1415,  1417,  1468,
       0,     0,   619,   616,   611,   613,     0,  1974,  1974,   627,
     629,  1974,  1974,     0,   535,     0,   539,     0,     0,   531,
     530,     0,     0,     0,     0,     0,     0,  1791,  1799,  1787,
    1788,  1789,  1790,  1558,     0,  1551,  1557,  1572,  1576,     0,
    1589,  1575,     0,     0,  1590,  1602,  1603,  1600,  1606,  1605,
    1601,     0,     0,     0,     0,     0,  1604,     0,     0,     0,
    1545,  1546,  1764,     0,  1566,  1560,  1330,  1748,  1439,  1435,
    1436,  1441,  1440,  1746,  1329,     0,     0,  1252,  1253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1251,     0,     0,  1239,  1240,  1241,  1238,  1243,  1244,  1245,
    1242,  1229,  1220,     0,     0,  1276,     0,     0,  1215,     0,
       0,     0,     0,     0,     0,     0,  1207,  1208,     0,  1137,
    1675,     0,  1676,     0,     0,     0,     0,  1512,  1511,  1377,
    1510,  1502,  1368,  1651,     0,     0,     0,     0,     0,     0,
    1652,  1644,     0,     0,     0,  1644,  1680,  1518,  1531,  1536,
       0,  1533,  1530,  1532,     0,  1534,  1522,  1526,  1527,  1377,
    1363,  1359,     0,     0,  1334,  1333,     0,  1318,     9,     0,
    1308,   897,  1134,   378,  1308,     0,     0,  1958,     0,     0,
    1024,    49,     0,   797,   172,   170,     0,  1974,     0,     0,
       0,  1974,   168,   157,     0,   160,   159,     0,  1030,  1034,
       0,  1920,  1919,  1918,     0,     0,   370,     0,   592,     0,
    1974,   819,     0,   670,  1187,     0,  1278,    70,     0,     0,
     105,    68,    96,    79,    85,     0,     0,   124,   120,   813,
    1974,   936,   670,   935,     0,   636,     0,   843,   844,   842,
    1120,   727,   725,     0,   707,   704,     0,   776,   750,   778,
     752,   787,   803,   804,   801,   802,    30,    28,     0,  1802,
    1751,  1723,  1719,  1718,     0,  1497,  1755,  1500,     0,  1408,
    1403,  1402,  1405,     0,     0,  1488,     0,     0,  1751,     0,
       0,  1895,  1893,     0,     0,  1877,  1892,     0,     0,  1894,
       0,     0,     0,     0,     0,  1931,  1891,  1883,  1910,  1911,
       0,  1875,  1878,  1879,  1890,  1882,  1912,     0,  1868,  1867,
    1871,  1873,     0,  1866,     0,  1869,  1860,     0,     0,   623,
     621,   633,   635,   631,     0,     0,   545,     0,   545,   545,
       0,  1754,     0,  1687,     0,     0,     0,  1554,  1574,  1568,
    1570,  1577,  1579,  1577,     0,  1584,  1577,     0,  1582,  1577,
       0,  1592,  1591,     0,  1593,     0,  1544,     0,  1443,  1442,
    1438,  1749,     0,   250,  1246,  1247,  1248,  1250,  1233,  1231,
    1230,  1234,  1235,  1232,  1249,  1236,  1237,  1221,  1017,  1256,
    1014,     0,     0,  1274,  1219,  1218,  1213,  1211,  1210,  1214,
    1212,  1216,  1217,  1209,  1262,     0,  1503,  1509,  1678,  1671,
    1514,  1376,  1618,  1630,     0,  1632,  1634,     0,  1636,     0,
       0,     0,  1642,  1621,  1646,     0,  1504,  1506,     0,  1528,
    1529,  1669,  1661,  1332,     0,     0,  1324,  1319,  1320,  1337,
       0,  1315,  1316,     0,     0,  1329,  1309,  1310,     0,    24,
    1304,     0,     0,  1047,     0,    50,  1027,     0,    24,   174,
     164,     0,   680,   682,   176,   166,   797,     0,  1936,  1056,
       0,   369,  1424,     0,  1104,    24,     0,     0,    66,     0,
      82,    91,     0,    75,    72,   927,   924,   640,  1974,   986,
       0,  1974,   723,   702,   708,   670,  1812,     0,  1810,     0,
       0,  1724,  1720,  1499,     0,  1501,  1495,     0,  1407,     0,
    1822,  1490,  1492,  1467,     0,  1881,  1880,     0,     0,  1610,
       0,  1610,  1610,  1610,  1610,  1884,     0,     0,  1864,     0,
       0,     0,     0,  1897,  1865,     0,     0,     0,     0,     0,
       0,  1859,  1421,  1473,   891,   890,   353,   536,     0,     0,
     541,   540,  1712,  1835,  1838,  1836,  1559,     0,  1596,  1598,
       0,  1585,  1588,  1587,  1595,     0,  1597,  1577,     0,  1547,
    1437,  1843,   225,  1019,  1018,  1016,     0,  1255,  1138,  1142,
    1144,     0,  1148,     0,  1146,  1150,  1139,  1140,     0,     0,
       0,  1672,  1677,     0,     0,  1653,  1645,  1623,     0,  1624,
       0,     0,  1322,  1317,  1323,  1321,  1314,  1313,  1312,  1307,
    1311,   379,   376,     0,  1045,     0,     0,     0,  1026,   798,
     152,   679,    24,  1036,  1055,   590,  1101,    67,  1279,    87,
       0,     0,    80,    91,    91,    91,  1974,   637,     0,     0,
     726,   788,     0,  1809,  1752,  1745,     0,  1409,     0,  1745,
    1908,     0,     0,  1913,     0,     0,     0,     0,     0,     0,
       0,     0,  1876,  1899,  1900,  1898,  1896,  1874,     0,  1870,
    1872,  1861,  1862,  1474,     0,  1466,   545,   545,  1578,  1800,
    1580,     0,  1583,  1581,  1599,     0,  1015,  1974,  1974,  1152,
    1974,  1154,  1974,  1974,  1141,  1275,  1263,     0,  1633,     0,
    1643,     0,  1535,   381,  1046,  1957,     0,     0,     0,     0,
       0,     0,    55,     0,    54,     0,    52,     0,     0,   153,
    1108,    91,    96,    91,    92,    86,    76,    73,   925,     0,
       0,   728,    24,  1811,  1744,  1753,  1413,     0,  1410,  1412,
    1725,  1909,     0,     0,  1907,     0,     0,     0,     0,     0,
    1885,  1906,     0,  1475,   538,   537,  1586,  1594,  1143,  1145,
    1974,  1149,  1974,  1147,  1151,  1673,  1638,  1507,   383,   388,
     386,   377,     0,   384,   390,    57,    62,    59,    61,    58,
      60,    56,     0,    51,     0,   681,   683,  1112,  1102,     0,
    1110,  1280,    88,    83,   638,   987,  1974,   789,     0,  1404,
       0,  1726,  1740,  1905,  1914,  1901,  1902,  1903,  1904,     0,
    1886,     0,     0,  1153,  1155,  1974,  1974,   382,   385,  1974,
      53,     0,  1974,  1109,  1111,     0,   724,  1411,     0,  1730,
    1727,  1728,     0,     0,  1863,   389,   387,   391,     0,  1113,
      89,   729,     0,     0,     0,  1888,     0,  1887,  1028,    93,
       0,  1731,  1729,     0,    95,     0,    90,     0,  1889,    94,
    1732
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   844,   845,   846,   847,  1071,  2144,  2145,   187,   329,
     188,  1441,  1442,  1968,  2307,  3354,  2830,  2831,  3256,  3355,
    3356,   848,  1216,  2868,  2564,  3275,  2563,  3274,  1904,  2561,
    3121,  2872,  3270,  2562,  3122,  3362,  3465,  3489,  3272,  3496,
     664,   665,   666,  1572,  2221,   849,  1584,  1221,  1582,  1913,
    2232,  1910,  2230,  2235,  2568,  1583,  2229,  1914,  2567,    11,
      84,   240,   550,   128,   689,   690,   850,    12,    34,    35,
      36,    37,    38,   852,  1134,  1841,  1467,  2171,  2175,  2176,
    2172,  2173,  2837,  2841,  2529,  2521,  2520,  2522,  2525,   506,
     279,   616,   853,    63,    64,    14,    48,   120,    78,   263,
      80,    81,   203,   344,    82,    83,   250,   349,   235,  1033,
     531,  2726,   380,   954,  2031,   408,   409,   264,   236,   362,
     351,   357,  1387,  1388,   124,   549,   125,   126,   368,   237,
     364,   350,   352,   533,   238,   589,   252,   255,   253,   254,
     973,   565,   566,   568,   573,   957,   256,   257,   399,   570,
     199,    15,    59,   157,   158,   159,   963,  2663,   160,   260,
     248,   402,   403,   404,   405,  1864,   854,   855,   856,   857,
    1092,  3343,  3089,  1443,  3411,  3412,  3413,  3456,  3455,  3459,
     858,   859,   860,   861,   862,   863,   864,  1082,   507,  1087,
    1435,  1436,  1483,  1189,  1484,   306,   307,   308,   309,   310,
     464,   508,  1369,   509,   510,   511,   512,   513,   514,   515,
    1009,   189,   525,  1020,  1022,  1758,  1019,  1757,   190,   518,
    1015,   517,  1014,   520,  1017,   519,  1016,   974,   987,   311,
     312,   192,   313,   431,   432,   433,   434,   416,   436,   865,
    1154,  1867,  2860,  2202,    95,   245,   559,  1681,  1284,  1285,
    1286,  1678,  1679,  2018,  2019,  2020,  2364,  2365,  1682,  1683,
    2014,  2368,  2360,  2026,  2027,  2371,  2372,  2661,  2657,  2658,
     866,  3128,  3369,  2885,   867,  1495,    65,  1826,  1827,  2196,
     417,   438,  1126,  1194,  1063,  1114,  1097,  1136,  2263,   193,
    1064,  1054,  1798,  2524,    67,   314,   868,  1226,   869,  1239,
    1240,   870,   871,   872,   873,  1247,  2894,  1268,  3133,  1269,
    1942,  1270,  2260,  1271,  2582,  1272,  1971,   874,  1938,  2581,
    2893,  3131,  3130,  3436,    96,    16,    17,   875,  1461,  1831,
    1832,  1833,  1961,  1626,  1962,  1963,  2594,  2596,  2278,  2277,
    2282,  2276,  2275,  2268,  2267,  2266,  2265,  2270,  2269,  2272,
    2274,   876,   877,  1132,   878,  1622,  1254,  3372,   879,  1549,
    3098,  2309,  2310,  1964,  2279,  2238,  2570,  1183,  1523,  1871,
    2205,  1872,  1519,   880,   881,  1232,  1928,  2889,   882,   883,
     884,   885,    18,    19,    20,    53,    21,    22,    23,    97,
      98,   886,    99,    24,   945,    25,   100,   101,   137,   561,
    1687,  2376,  3185,   102,   133,   373,   887,  2502,    26,    27,
      28,    29,    30,    47,    70,   103,   246,   560,   948,   949,
    1288,  1685,   888,  1227,  2242,  1917,  2240,  3276,  2880,  1918,
    2239,  2573,  2882,   889,   890,   891,  1108,  1109,  1587,   892,
    1273,  1274,   893,  1634,  1275,   315,    72,    73,    74,    75,
    1594,   163,   116,    76,   113,   195,   196,  1595,  1596,  2249,
    1597,   693,   694,  1256,   695,  1257,  1187,  1188,  1598,  1599,
    1439,  3029,  3030,  3215,  1124,  1125,   894,  1456,  3258,   895,
    2849,   896,  1471,  1472,  1473,  1847,  1845,   897,   898,  2153,
    2182,   899,  1858,  2192,   900,  1184,  1185,  1533,  1537,   901,
    1047,   902,  2320,   903,  3360,  2863,   904,  2209,  3428,  3429,
    3430,  3462,  1191,   905,  1600,  1930,  2253,  2254,   906,  1449,
    1818,  1062,  1428,   907,   908,   909,  2445,  3033,  3226,  3227,
    3327,  3328,  3332,  3330,  3333,  3400,  3402,   910,   911,  1589,
    1922,   912,  1591,  1561,  1562,  1563,  1894,   913,  1206,  1204,
     914,   915,  1886,  1557,  1200,   202,  1564,  1565,   316,  2446,
    2766,  2767,  2751,  1079,  1080,  2442,  2752,  2755,   104,   132,
     553,  1396,  2094,  2768,  3229,   446,   916,  1198,   105,   130,
     551,  1394,  2093,  2756,  3228,  2443,  1220,  2554,  3117,  3361,
    1889,   917,  1607,   918,   919,   920,   921,  1095,  2151,  1073,
    2147,  3085,  3086,  3087,  3242,  3076,  3077,  3078,   922,  2717,
    2496,  2497,  2499,  1782,   923,   924,  1405,  1406,  1407,  1791,
    2133,  1408,  2130,  1788,  1409,  2106,  1783,  1410,  1411,  1412,
    2098,  2103,  1413,  1777,  1778,   925,  1104,  1084,   926,  1659,
    1660,  1986,  2921,  3149,  2624,  2918,  3377,  3378,  1661,  2008,
    1640,  2356,  2647,  2967,  2545,  2859,  2357,  1662,  1663,  2077,
    2719,  2720,  2721,  3010,  1664,  1665,  1480,   927,  1141,   928,
    1281,  1666,  1667,  2002,  3315,  2003,  2004,  2005,  2340,  2628,
    2631,  2632,  1668,  2330,  2619,  3146,  1771,  1772,  2805,  2449,
    3066,  2450,  1773,  2454,  1784,  2481,  1785,  2482,  2806,  2807,
    2808,  2809,  1669,  1980,  1981,  2327,  1670,  2714,  2430,  2710,
    2072,  1736,  2067,  2068,  2069,  2684,  1737,  2073,  2431,  2715,
    2420,  2421,  2422,  2423,  2424,  3198,  2991,  3318,  2425,  3200,
    3201,  2708,  2426,  2709,  2427,  2056,  2126,  2127,  2128,  3060,
    2129,  2784,  2791,  3236,  2451,  1051,  2633,  2772,  2960,  2453,
    2415,  1342,   317,  1343,  1717,   457,   458,  1718,  2394,    46,
     929,   930,  2913,  3142,  2612,  3141,  3442,  3470,  3471,  2616,
    2321,  1671,  2322,  2345,  2928,   619,  2317,  2318,  2078,  2433,
    3140,  2917,  1344,   994,  1345,  1346,  2711,  2428,  1348,  1349,
    2058,  3320,   931,   932,  1973,  2319,  2909,  3137,  3138,  1637,
     933,  1090,  1673,  1674,  1990,  2626,  1675,  1676,  2336,  1750,
    2051,  1350,  1351,  1352,  1353,   934,  1235,  1611,  1612,  1613,
    1934,  1614,  1935,  1677,  2346,  2966,  3181,  2643,  2963,  2964,
    2965,  2962,  2950,  2951,  2952,  2953,  2954,  2955,  3294,   935,
    1856,  2187,  2188,  1142,  1354,  1355,  1144,  1145,  1146,  1356,
    1147,  1478,  1850,  1851,    31,   937,  1208,  1895,  1464,  1551,
     938,   939,  2513,   940,  2142,  1067,  1805,   941,   942,    41,
     554,   555,   556,   557,   558,   943
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2623
static const short yypact[] =
{
     151,  1147, -2623,   246,   246,   246,  1244, -2623, -2623,  1244,
     246, -2623, -2623,   631, -2623, -2623, -2623, -2623,   290, -2623,
   -2623, -2623,  1019, -2623, -2623, -2623, -2623, -2623,  -143, -2623,
   -2623, -2623, -2623, -2623,   392,   447, -2623,   455, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  -122, -2623,   933,   187, -2623,
   -2623, -2623, -2623,   406, -2623, -2623, -2623, -2623, -2623,  -118,
     246, -2623,   246,   393,   631, -2623,  1289, -2623, -2623, -2623,
   -2623, -2623, -2623,  1338,   -11, -2623, -2623, -2623,   822,   511,
     246, -2623, -2623,   954,   237,   246, -2623, -2623,   246, -2623,
   -2623, -2623,   246,   246, -2623, -2623, -2623, -2623,   406, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623,  5220, -2623,   -11,
   -2623,  1030,  3373, -2623, -2623,   514, -2623, -2623,  1057,   187,
     548, -2623, -2623, -2623, -2623, -2623,  8860,   246, -2623, -2623,
     246,   630,   246,   631, -2623, -2623, -2623,   246, -2623, -2623,
     725,   711,  1111, -2623, -2623,   761, -2623,   767, -2623,   698,
   -2623, -2623,   796, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,   821, -2623, -2623, -2623,   824,   848,   857,
     877,   896,   908,   925,   938,   949,   965,   985,  3373,   991,
    5199,  1018,  1028,  1032,  1038,  1043,  1048,  1707,  1413, -2623,
   -2623, -2623, -2623,   110, -2623,   123, -2623,  3373, -2623,   216,
   -2623, -2623, -2623,   173, -2623, -2623, -2623,   893, -2623, -2623,
   -2623, -2623, -2623, -2623,   725,  1056,  1063,  1071, -2623,  1111,
   -2623, -2623,  1080, -2623,  1115, -2623,  1133, -2623, -2623,  1121,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
     631,  1174,  1472,  1197, -2623,   631,   631,  1205,   246, -2623,
     835,  1648, -2623,  1034,  1249, -2623,  1042,  1299,  1671,  1678,
     246,  1715,  1718,   720,  1060, -2623,   974,    56,    56,    56,
      56,    56,  5199,  1612,  1536,    76,  5199,  1185,  5199, -2623,
    5199,  5199,  5199, -2623, -2623, -2623,  1178,  1278,  1285,  5199,
    1319,  1296, -2623,  5199,  5199,  1302, -2623,  1306, -2623,  1028,
    1328,  1344,  1348,  1367,  1758,  7454, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  1381, -2623, -2623, -2623, -2623,
   -2623, -2623,   974,   974, -2623, -2623, -2623, -2623, -2623,  3373,
   -2623,   246, -2623,   246,  3373,  1355,   166, -2623, -2623, -2623,
   -2623,  1848, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
    1394, -2623,  1394,   835,  1861,  1868,  1874, -2623, -2623, -2623,
    1878,  1885,   187,  1715,  1394,  1887,  1242, -2623,  1804, -2623,
   -2623,  1479, -2623,  1502, -2623, -2623, -2623,  1255, -2623, -2623,
    1903,  1485, -2623,  1450, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623,  1299,  1450, -2623, -2623, -2623, -2623, -2623, -2623,  1451,
     190,   229,   874, -2623,  5379, -2623, -2623, -2623,  1456,  1935,
     257, -2623, -2623, -2623,  1493,  1457,   332, -2623,  -178,  1499,
    1504,   404,   414,  5966,  1505,  1512,    80,  1313, -2623, -2623,
     230,  1513, -2623, -2623, -2623, -2623,   429, -2623, -2623,  6515,
   -2623,  3911,  8041,  2372,  2372,  5199, -2623,  1441,  5199,  7454,
    1483, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  1288,  1952,
    6611,  7454,  1441,  1953,   529,  5199,  5199,  5199,  5199, -2623,
    5199,  5199,  5199,  5199,  5199,  5199,  5199,  5199,  5199,  5199,
    5199,  5199,  5199,  5199,  5199,  5199,  5199, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623,  5199,  5199, -2623,
   -2623,  1489,  5199, -2623,  5199,  1491, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623,   974,  5199,  5199,  5199,
    5199,  1529,  1974,  1707,  1495,  3660,  1500, -2623,  3373,  1469,
   -2623,  1309,  1962, -2623,  1316, -2623,  1965,  1544,  1545,   439,
    1682,   448,   452,   904,  1514, -2623,   454, -2623, -2623, -2623,
     141,   246, -2623,   246,  1580, -2623,  5468,   548,  5997,  1977,
    -270,   246,  1997,    39, -2623, -2623,  1249,  1994, -2623, -2623,
   -2623, -2623,  1999, -2623,  2001, -2623,  2002, -2623,   246, -2623,
     246, -2623, -2623,  1715,  2004, -2623, -2623,  1395, -2623, -2623,
   -2623,   246,    56, -2623,  3373,    53, -2623, -2623, -2623, -2623,
   -2623,  1249,  1249,  2005,  -119,  1249,  1346, -2623,  2011,  1397,
    1526, -2623,    76, -2623, -2623, -2623,  1595,  7454,   616,  1603,
    6714,  2026,  1319,  1607, -2623,  1613,  1614, -2623,  6735,  6783,
    6825,  7056,  7622,  7669,  8041,  8144,  8269,  7794,  8391,  4003,
    4946,  5862,  8053,  2372,  2372,  3299,  3299,  3899,  7454,  7359,
    7406,  1441,  7454,  7430,  1441, -2623,  7454,  7454,  7454,  7454,
   -2623,  2038, -2623, -2623, -2623,  2060, -2623,  7454, -2623,   167,
    3373, -2623,  1618,  2050,    39, -2623, -2623,  2046, -2623,  1597,
    2054, -2623,  2058, -2623, -2623, -2623,  2061, -2623, -2623,   -12,
   -2623, -2623,  1410,  1638,  2084, -2623,  1643, -2623, -2623, -2623,
     974,   974,   974,   246,  1037,   246,  1571,   189,   189,  1578,
     246,   246,   189,   189,   246, -2623,  1571, -2623, -2623,   246,
   -2623,   986, -2623, -2623, -2623,   189, -2623, -2623, -2623, -2623,
     246, -2623, -2623, -2623, -2623,   112,   112,  5199, -2623, -2623,
   -2623,  1578,  1578, -2623, -2623,   189, -2623, -2623,   189, -2623,
   -2623,   246, -2623, -2623,   189, -2623, -2623,   974,   189, -2623,
   -2623,  5199,   189,   974,   246,   974,   189, -2623, -2623,   252,
     189,   189,   252,   189,   246,   252,   189, -2623,   189,   189,
     189, -2623,  1571, -2623, -2623,   974,   189, -2623, -2623,   189,
      95,   246, -2623,  1578, -2623, -2623,   189,  1085, -2623, -2623,
     974,  1416, -2623,   189, -2623,  7525,   974,  5199,    56,    56,
     189, -2623, -2623,  1037,   974,   422, -2623,  5199, -2623,   840,
    5199,   189,   157, -2623,  5199,   189,  2070,   974, -2623,   189,
    5199, -2623,  5199,   112,   246,   189,   246,    56,   189,   246,
      56, -2623,   246,   195, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,   531, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,  1294, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  1131,   246, -2623,   727, -2623,
    1652, -2623, -2623, -2623,  1743, -2623, -2623,  1655,  1657,  1658,
    1659, -2623, -2623,  1432,  2103,  1662, -2623,  1663, -2623,   560,
   -2623,  1631, -2623,  1445, -2623, -2623,   492,  1249,  2099, -2623,
    1680,  -109, -2623,  2104, -2623,  1486, -2623, -2623, -2623,  1453,
   -2623, -2623, -2623, -2623,  8586, -2623,  1178,  1687, -2623,  1178,
   -2623,  1178,  1178,  1178,  1178,  1178,  2117,  2118,  2120,  5199,
    1698,  2125,  5199,  1703,  1709,  1713,  1716,  1724,  1725,  3660,
    1727,  3660,  3660, -2623,   213, -2623, -2623, -2623,  1797,  1728,
   -2623,  1731,  1735,  1481,  1736, -2623, -2623,   246, -2623,   246,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,   367,  1515,
     726,  1683,  1704, -2623, -2623, -2623, -2623,  1518,   759, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623,  2187,  1520, -2623,
   -2623,  1719, -2623,  1578, -2623,  1668,   181, -2623, -2623, -2623,
    1497, -2623,  7454, -2623, -2623,  1547, -2623, -2623,  4258, -2623,
   -2623, -2623,   974, -2623, -2623,  1578, -2623,  -136, -2623, -2623,
    1880, -2623,   159, -2623,  1694, -2623, -2623, -2623, -2623,  2199,
   -2623, -2623,   718, -2623,  1538, -2623,  1553,  2199, -2623,  1576,
   -2623, -2623, -2623,  1752,   127, -2623,  1714, -2623,  1519, -2623,
   -2623, -2623, -2623,  1522,   820, -2623,  -149, -2623,  1557,  1604,
    1733,  1853,  1567, -2623, -2623,  1565, -2623, -2623,  5199,   140,
    1089,  5199, -2623,    85,   189, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623,    71,    71,    71, -2623,    71,  1681,
      71,    71,  1590,  -136,  1590,  1590,  1103,  1103,  1590,  1590,
    1825,  -136,  1831, -2623,  2236, -2623,  1772,   254, -2623,  2245,
   -2623,  -136,   184,    66, -2623, -2623,  5199, -2623, -2623, -2623,
    1153, -2623,  1125, -2623,   548, -2623,  5199, -2623,  5199,  1766,
    1768,  1774,  1775,  1664,  1777,  1125, -2623,  1854,   865,    77,
   -2623,  1625, -2623, -2623,   246, -2623, -2623,  1162, -2623,  2255,
   -2623,  2251,   246, -2623,   286,   228,  1637, -2623, -2623,  2262,
   -2623,  1556,  2262,  2264,  1558,  2262,  2264,  5199,  2262, -2623,
   -2623,   181,   974, -2623, -2623,  1796,   359, -2623, -2623,  1791,
     974,  5199,  1792, -2623, -2623,  2254,  2256,  2159, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623,  1192,  1192,   189,   189,
     189,  2677, -2623, -2623,  2136,  1131, -2623, -2623,   768, -2623,
   -2623, -2623,  1779, -2623, -2623, -2623, -2623,  5220,  1715, -2623,
   -2623, -2623,  1611,   246,  1249,  2267,   -33,  1249, -2623,   558,
    1249,  1249,  1690,  1651,  1710, -2623,  8707,  8707, -2623,  1557,
   -2623, -2623, -2623, -2623,  1388, -2623,  4380,  1810, -2623,  1811,
    1814,  1815, -2623,  1815,  1815,  1816,  1817,  1818,  1819,   246,
     565, -2623, -2623, -2623, -2623,   225, -2623,    47,  2224, -2623,
   -2623,  1388, -2623,  1388,  1823, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  7454,   456,
   -2623, -2623,   463, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623,  1793, -2623, -2623,   465, -2623, -2623,
   -2623, -2623, -2623, -2623,   631, -2623,   631,   782,   279,  2279,
   -2623, -2623,   591,   358,   592,  2302, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623,   246,  1722,   246, -2623, -2623,  1726,
     246,  1729,   246,   246,  1578,  1660,  1827, -2623,  1830,    73,
   -2623, -2623, -2623,  1578, -2623, -2623,  2305, -2623, -2623,  1639,
    1832, -2623, -2623, -2623,  1089, -2623,  1203,  2269,  1203, -2623,
    1125,   252,  5199,  5199,  5199,  1835, -2623, -2623,   974,   974,
    1578,  1642,  1125,    56,  1609,    95,   974, -2623,  1644,  5199,
    1917, -2623, -2623,  1717,   246,  1557, -2623,  3373, -2623, -2623,
   -2623,   246,  1406,  2323, -2623, -2623,  1661,   104,   181,   974,
   -2623, -2623,  2312,  2314, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623,  2607, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  7525,   974,
     974, -2623,  1103,  5199,  -113,  1013,  1092, -2623, -2623, -2623,
   -2623, -2623,   169, -2623, -2623, -2623, -2623,  2128,  1893, -2623,
    1904,   548,  5199, -2623,    64, -2623, -2623,   246,  2318,    56,
      56, -2623,  1702, -2623,    76,  1670,   974, -2623,   246,   246,
     246,  5199,   577, -2623,  1720, -2623, -2623,   247, -2623,  1812,
   -2623,  1822,  5199,  1365, -2623, -2623,  1676, -2623,  2345, -2623,
    1753, -2623, -2623, -2623,   974, -2623, -2623,   149, -2623, -2623,
   -2623,    67, -2623, -2623, -2623, -2623,   246,    56,    56,   466,
     359,  2156,  1467,   974,   181, -2623,  1767, -2623, -2623,  2323,
    2342,  1914, -2623, -2623, -2623, -2623, -2623,  2003,  2003, -2623,
     106,  1778, -2623,   246,  1578, -2623,  1578,  1578, -2623, -2623,
    1578,  1578, -2623,   246,  1376,   616,  1578, -2623,  1376, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,   234,   234,
     914,  1187, -2623,   795, -2623,   768, -2623,   631,  2358, -2623,
   -2623,  1409,  1940, -2623,   430,  1249,  2363, -2623,  1249,  1745,
   -2623, -2623,  1954,  1956,  1750, -2623, -2623, -2623,  1431,  1431,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  1732,   616,
    1957,  8641,   636,  8586,  1872, -2623, -2623, -2623,   636,   636,
     636,   636,  1739,  8586,  8586,   114,  1828,   808,   246, -2623,
    8586,  8586,  8586,  8586, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623,  1748,  -246,  1089,  5199, -2623, -2623,  1976,  1980,  2358,
   -2623, -2623, -2623, -2623, -2623,  1937,  1944,  1951,   936,  1958,
    1960, -2623, -2623, -2623,  2327,   246, -2623,  2437, -2623, -2623,
     602,  4912, -2623, -2623, -2623, -2623,   246, -2623, -2623,   602,
    1730, -2623,   367, -2623,  1773, -2623,  1805, -2623,  2006,   -11,
   -2623,  1776, -2623,  1807, -2623,  1851,  1967,   246, -2623, -2623,
   -2623, -2623,  4258,   246, -2623,  1783, -2623, -2623,  2269, -2623,
    2269,  1780, -2623,  2451,  2452, -2623,  2453,  1833,  5199, -2623,
   -2623,  2455, -2623,  1788, -2623,  1926,  1785,  2264, -2623, -2623,
    1787,   889,   246, -2623, -2623,  1982,   189,  1189,  1565,  1707,
     364, -2623, -2623, -2623, -2623,  5199,  1578,  1089,  -206, -2623,
     246,   246,  5199,    48,  -136,  2465,  1151,  2463,  2446,  2447,
    1681, -2623, -2623, -2623, -2623, -2623, -2623, -2623,   974,  2100,
   -2623, -2623, -2623, -2623,  2352,  5199,   548, -2623,  2203, -2623,
   -2623, -2623,  5199,   112, -2623,  2095,  2476,  2478,   467,   470,
     246,  2036,  1125, -2623,  3660,  2007,  2008,  2009, -2623, -2623,
    2079, -2623,  5199,   607, -2623,  1837, -2623, -2623,   259, -2623,
    5199, -2623, -2623,  1820,  1030, -2623,  1417,   246,  2484,  8226,
   -2623, -2623, -2623,   974,  1089,   974, -2623, -2623,    11, -2623,
    2264,  2264,  1798, -2623,  1896,  1901, -2623, -2623, -2623, -2623,
   -2623, -2623,    56,    56, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623,  3025, -2623, -2623, -2623, -2623,    56,  3241,  2500,
    2483, -2623,  1125,   853,   289,   134,  2354,     7,  1037, -2623,
      -5, -2623, -2623, -2623,  2027,    69,  1578,   115,  1840, -2623,
    1838, -2623, -2623, -2623, -2623, -2623,  2029,  2029, -2623, -2623,
   -2623, -2623,  1915,  1841,  2513, -2623, -2623, -2623,   587,  1847,
    1850, -2623, -2623,   974,   241, -2623, -2623, -2623,  1844,  1187,
   -2623,   246,   246, -2623, -2623,   246,   567, -2623, -2623, -2623,
   -2623,  2049, -2623, -2623, -2623,   583,  1249, -2623,   608, -2623,
    2085,  2093,  1249,  1249, -2623, -2623,  1521,  8586, -2623,   386,
    2537,  2096,  2538, -2623, -2623, -2623,  8586, -2623,   484,  8586,
    8586,  8586,  8586,   246,   486, -2623,   365,  2540, -2623, -2623,
      60,  7977, -2623,  2121,   246,  1875,   636,  2160, -2623, -2623,
   -2623, -2623, -2623, -2623,  1521,  2522,  1521, -2623,  7454, -2623,
   -2623,  2069, -2623,  2042,  2043,    59,    59,    59,   496,  2327,
      59,  7977,   246, -2623,   497,   246,   507, -2623, -2623, -2623,
    2066,  2068,  2074,  1388,  1388, -2623,  2075, -2623,  2077,  2080,
    2081,  2082, -2623, -2623, -2623, -2623,  1044, -2623, -2623, -2623,
     520, -2623, -2623,   521,   246, -2623,   246,  1765, -2623,   246,
    1813,  5199, -2623,   246,  2559, -2623, -2623,   602, -2623, -2623,
    1895,   602,   244, -2623, -2623, -2623,  1125,  5199,  5199,  5199,
    4819,  2564,  1578,   139, -2623,  1125,   246, -2623, -2623,   246,
     246, -2623,  1261, -2623, -2623,   395, -2623,  1902,  5199, -2623,
   -2623, -2623,  2566,  3373,  2063, -2623,  1905,  2575, -2623, -2623,
    1125,  1961, -2623, -2623, -2623, -2623, -2623,   246,  2264, -2623,
     181, -2623,  1975, -2623, -2623,   524, -2623, -2623, -2623,   974,
   -2623,  4636, -2623,  1118, -2623, -2623,  2198,  2558, -2623,  2182,
    2191,  2083,  1921,  2193,  2114, -2623, -2623, -2623, -2623,   606,
    2183, -2623, -2623, -2623, -2623,  2079, -2623, -2623, -2623,   271,
     641, -2623, -2623, -2623,  2323,  5199,  2124, -2623,  2088, -2623,
   -2623, -2623, -2623,  2601, -2623, -2623, -2623, -2623,  2602, -2623,
    1906, -2623,  2583,  -136,   246,  3077,  3077,  3077,  3077,  3077,
    3077, -2623,  2613, -2623,  2614,  3077,  3077,  3077,  3077,  2607,
   -2623, -2623,  3077,    83, -2623, -2623, -2623, -2623,  2587,  2608,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  2609,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623,   527, -2623, -2623,
   -2623,  2595, -2623, -2623,  1578, -2623,   616, -2623, -2623, -2623,
   -2623, -2623, -2623,  1978,  1979,   540, -2623,    -5, -2623,    59,
    1955,   189, -2623,  2139, -2623, -2623, -2623,   246,   246,    59,
   -2623, -2623,    98,  1578,  1070,  8586,   205, -2623,  5199, -2623,
    5199, -2623, -2623, -2623, -2623, -2623,  2019,   189,    98,  1578,
    2624, -2623,   974,   246,  1093,  1093, -2623, -2623,  2625, -2623,
    2625,   643,   643,  2625, -2623, -2623,  1977, -2623,  1249,  2605,
   -2623,  1249,  1771,  1249,  1249, -2623, -2623,  2148, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,   225,  1388,  1963,  1388, -2623,
    1388,  2195,  8586, -2623,  2196,  2197,  2201,  2202, -2623, -2623,
     114, -2623,   114,   246, -2623, -2623,  3695,  1815,  7730,  1815,
    2640,  2645, -2623, -2623, -2623, -2623, -2623, -2623,   102,  8586,
   -2623,  2153, -2623,  2333,   198,   289,   246, -2623,  2210, -2623,
   -2623,  2373,   292, -2623,  1907, -2623,   292,  1578,   881,  2211,
    2655,  1989, -2623, -2623,   528, -2623,   533,   936, -2623, -2623,
     534,   487, -2623, -2623, -2623,   602, -2623,  2637,  2637,  2639,
    1987,  -183,  2641,  2642,  2644,  2641,  2641, -2623, -2623, -2623,
     125, -2623,   958,   246, -2623,   602, -2623, -2623, -2623,  1998,
   -2623, -2623,  2000, -2623, -2623,  -195,   535, -2623,   246,   539,
   -2623,  5199,  2227,  2656,   541,  1125,  2673, -2623, -2623, -2623,
   -2623,  5199,  2062,  2351,  5199, -2623, -2623, -2623, -2623,   395,
    1325,  1325,  2678,   590, -2623,  2679, -2623, -2623, -2623,  1325,
     246,  2087,  1447,  2683,   246, -2623,  3373,   155,  1578,  2684,
    1125,  -170,  2465,  5199, -2623, -2623,  1681, -2623,  1970,  5199,
   -2623, -2623, -2623,  2688,  3660,   974, -2623,   986,   246,   974,
   -2623,  2246,  3660,  3660,  3660, -2623, -2623,   606,  2183, -2623,
    2607, -2623, -2623,  1231, -2623, -2623,  2071, -2623,  3373,  4934,
    8226,    34,  1200, -2623, -2623, -2623,  2022, -2623, -2623, -2623,
   -2623, -2623, -2623,    56,  3077,    56,  3077, -2623, -2623, -2623,
   -2623, -2623, -2623,  -136, -2623,  1196,  1215,  3241, -2623,  2249,
    2215,  8586, -2623,   134,   134, -2623, -2623, -2623, -2623,   566,
   -2623,  2178, -2623,    59,   562, -2623,  2028, -2623,   568, -2623,
   -2623,  2700, -2623, -2623,  2108, -2623,  2704,  1741,  1741,  1741,
    1741,    59,    59, -2623, -2623, -2623, -2623, -2623, -2623,  2700,
    2033,   974, -2623,  2625, -2623, -2623,   246,   643,   643, -2623,
   -2623,   643,  2448,  2037, -2623,   610, -2623,  2265,  2270, -2623,
   -2623,  2691,  2271,  2041,  1521,  2044,  2045, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623,   585, -2623, -2623, -2623, -2623,   494,
     238, -2623,  7977,  7977, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623,  8707,  8707,  2237,  8707,  2241, -2623,  8707,   849,  8586,
    2716, -2623, -2623,  7977, -2623, -2623, -2623, -2623, -2623,  2723,
   -2623,   488, -2623, -2623,  2333,  2052,  2055, -2623, -2623,   112,
     112,   112,  2709,   112,   112,   112,   112,   112,   112,  2710,
   -2623,  2712,   112, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623,  2373, -2623,   974,  2072, -2623,  2228,  2715, -2623,  2717,
    2719,  2720,  2721,  2725,  2727,  1243,  1907, -2623,  2228, -2623,
   -2623,  2728, -2623,  2389,    59,  1480,    59, -2623, -2623,  2327,
   -2623, -2623, -2623, -2623,  2301,  2307,   589,  1521,  2730,  1521,
   -2623,  2755,   594,  2315,  2316,  2755, -2623, -2623, -2623, -2623,
    1578, -2623, -2623, -2623,  2280, -2623, -2623,   958, -2623,  2327,
   -2623, -2623,   246,   246, -2623, -2623,   246,  -278, -2623,   602,
     150,  2323, -2623,  2244,   150,   185,  1125, -2623,  2762,  2283,
   -2623, -2623,  2321,  2166, -2623, -2623,   246,  1325,  3373,  1482,
     246,  1325, -2623, -2623,    56, -2623, -2623,  5199, -2623, -2623,
     370, -2623, -2623, -2623,  1125,  2769, -2623,    56,  2323,   974,
    2485, -2623,  2753,  1896,  7454,  2758, -2623, -2623,   181,  2299,
   -2623, -2623,  3660, -2623, -2623,  2336,  2337, -2623, -2623, -2623,
     641, -2623,  1896, -2623,  5199, -2623,   372, -2623,  2245, -2623,
   -2623, -2623, -2623,  2291,  2385, -2623,  2768, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,   246, -2623,
     107, -2623, -2623, -2623,    59, -2623,   616,  2591,   615, -2623,
   -2623, -2623, -2623,   246,    59, -2623,    98,    98,  2184,  4691,
    4691, -2623, -2623,  5234,  2308, -2623, -2623,  2309,  2310, -2623,
    2311,  2313,  2317,  2319,   246,   664, -2623, -2623, -2623, -2623,
     619, -2623, -2623,  2268, -2623, -2623, -2623,   620,  2785,  2785,
   -2623, -2623,   626,  2787,  2789, -2623,   109,   974,    98, -2623,
   -2623, -2623, -2623, -2623,  2532,  5220,  1249,  1821,  1249,  1249,
    2353, -2623,  1521,  2357,  1521,  1521,   114, -2623, -2623,  2645,
   -2623,  2322,  2224,  2322,   307, -2623,  2322,   307, -2623,  2322,
    8707, -2623, -2623,  8586, -2623,  8586,  2640,   198, -2623, -2623,
   -2623, -2623,  1521, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,   639,  2801,
   -2623,   974,  1770, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,   374, -2623, -2623, -2623,  2294,
   -2623, -2623, -2623, -2623,  2782, -2623, -2623,  2364, -2623,  2791,
    2377,  2795, -2623, -2623, -2623,  2379, -2623,  2326,  7977, -2623,
   -2623, -2623, -2623, -2623,   246,  2805, -2623,  -278, -2623, -2623,
    2808, -2623, -2623,  2809,   246,  2333,   150, -2623,    56,  -136,
   -2623,  2408,  1125, -2623,  5199, -2623,  2221,  2818,  -136, -2623,
   -2623,  1025, -2623, -2623, -2623, -2623,   182,  2397, -2623, -2623,
    1125,  2264,  2602,  2550, -2623,  -136,  2399,  2400,  2465,  2365,
   -2623,  2456,  2401, -2623, -2623, -2623, -2623, -2623,  2556,  2347,
    5199,  2366, -2623, -2623, -2623,  1896, -2623,   627, -2623,   974,
    2266, -2623, -2623, -2623,  8586, -2623, -2623,    59, -2623,  2382,
   -2623, -2623, -2623,  2700,  2266,  1925,  1925,  2414,  8641,   636,
    8439,   636,   636,   636,   636,   642,  8439,  1741, -2623,  8439,
    8439,  8439,  8439, -2623, -2623,    59,  2850,    59,  1741,   189,
    7977, -2623,  2602,    86, -2623, -2623, -2623, -2623,  2420,  2421,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623,   125, -2623, -2623,
     634, -2623, -2623, -2623, -2623,   637, -2623,  2322,  2866, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623,   974,  2801, -2623, -2623,
   -2623,   974, -2623,   974, -2623, -2623,  1949, -2623,  2579,  2580,
    2851, -2623, -2623,  2432,  2206, -2623, -2623, -2623,  2433, -2623,
      59,   508, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,  1125, -2623,  2438,  8992,  2403, -2623, -2623,
   -2623,  2213,  -136, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
    2441,   181, -2623,  2456,  2456,  2456,   641, -2623,  3373,  2261,
   -2623, -2623,   246, -2623,  2602,   808,   225, -2623,  8467,   808,
   -2623,  2443,  8439, -2623,   650,  8439,  8439,  8439,  8439,  2870,
     246,   656, -2623, -2623, -2623, -2623, -2623, -2623,  2412, -2623,
   -2623, -2623,  2640, -2623,   246, -2623,  1249,  1249, -2623, -2623,
   -2623,   176, -2623, -2623, -2623,  8586, -2623,  1898,  1898, -2623,
    1898, -2623,  1898,  1898, -2623, -2623, -2623,  2417, -2623,  1521,
   -2623,   677, -2623,  1291, -2623, -2623,    71,    71,    71,    71,
      71,    71, -2623,  2874, -2623,   710, -2623,  5199,  1524, -2623,
     -73,  2456,  3660,  2456,  2465, -2623, -2623, -2623, -2623,  2606,
     401, -2623,  -136, -2623, -2623, -2623, -2623,   721, -2623, -2623,
    1563, -2623,  2454,  8439, -2623,  2458,  2459,  2460,  2461,   405,
    2391, -2623,  1741, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
    1898, -2623,  1898, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623,  1298, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623,  8992, -2623,  2905, -2623, -2623, -2623, -2623,   842,
   -2623, -2623, -2623, -2623, -2623, -2623,    11, -2623,  8467, -2623,
    1834, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  2887,
   -2623,  2888,   779, -2623, -2623,  1310,  1310, -2623, -2623,  1310,
   -2623,  5199,  1010, -2623, -2623,  2467,    34, -2623,  2243,  2252,
    2912, -2623,  2450,   409, -2623, -2623, -2623, -2623,  2470, -2623,
   -2623, -2623,   246,   246,  1834, -2623,  2893, -2623, -2623,   170,
    2259, -2623, -2623,  2464, -2623,   181, -2623,   246, -2623,  2465,
   -2623
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2623, -2623, -2623, -2623, -2623,   376, -2623,   424,  -174, -2623,
   -2623, -1150,   118, -2623, -2623, -1876, -2623, -2623, -2623, -2623,
    -493, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -1977, -2623,
   -1005, -2623,  1913, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
     700, -2623, -2623, -2623, -2623,  1358, -2623,  1024, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  2257, -2623,   -38, -2623, -2623,
    2909, -2623,  2910, -2623, -2623, -2623, -2623, -2623,   783,   420,
   -2623,   780, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,   -78,  1170,   971, -2623, -2623,  2589,    54,
   -2623,  2834, -2623, -2623,  2833, -2623,  2745, -2623, -2623, -2623,
   -2623, -2623,  2610,  2287,  1207,  2615,  -547,   968, -2623, -2623,
   -2623, -2623, -2623,  1209,  -666, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,   717, -2623,  2424,  2757,   -37,  2362, -2623,
    -196,  1665, -2623,  2592, -2623, -2623, -2623, -2623,  2581, -2623,
   -2623, -2623, -2623,  -396, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623,  2407, -2623,  2406, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,  -956, -2623, -2623,  -433, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623,  -124, -2623, -2623,
    1175, -2623, -1121, -1183,  -533, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623,  1981, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
    -623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  2169, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623,  -578, -2623,  -102,
   -2623, -2623, -2623, -2623,  2562, -2623, -2623,  -203, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
    1705, -2623, -2623, -2623, -2623,   977, -2623, -2623, -2623, -2623,
   -2623, -1562, -2623, -2623,   972, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -1133,  -896,   844,  1137, -2623,
    -229,  -589,   666, -1143,  1119, -2623,   554, -2623, -2211,    -3,
    -145, -2623, -2623, -2066,   400,  1836, -2623, -2623, -2623,   755,
    1385, -2623, -2623, -2623, -2623, -2623, -2623,   423, -2623,   113,
   -2623,  1387, -2623,  1066, -2623,   750, -2623, -2623, -2623, -2623,
    -455, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
     850, -2623, -2623, -1567, -2623,  1051, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,  1549, -2623, -2623, -2623, -2623, -2623, -2623,
     -91, -2623, -2623, -1790, -2623, -2623, -2623, -2623,   505, -1984,
   -2623, -1148, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  2994, -2623,
   -2623, -2623,  2919,  2971,   644, -2623, -2623,  -212, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  2972, -2623,
   -2623,  2993, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  2076,
   -2623, -2623, -2623, -2623, -2623,  1104, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623,  -723,  2248, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  2057, -2623, -2623,   -36, -2623,
   -2623,  1102, -2623, -2623,  1436,  -188,  2697, -2623, -2623, -2623,
   -2623,   655, -2623, -1060,  1993,  1412, -1477,  1498, -2623,  1106,
    1789,     6,  -177, -2623,  2240,  1584, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623,  1506, -2623, -2623, -2623,
    -788, -2623,  -625, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
    -384, -2623, -2623, -2623, -2623, -2623, -2623,   471, -2623, -1261,
    1598,   342, -2623, -2623, -2623, -2623, -2623,   282, -2623,  -179,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  1490, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  -535, -2623,  1161,  2600, -2623,
   -2623,   300, -2623,  -616, -2623, -2623,   316,   622, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623,  1001, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623,   245, -2623,   -16,   -13, -2623, -2623,    -2, -2623, -2498,
   -2623,   260,   927, -1384, -2623, -2623, -2623,  1290, -2623, -1728,
   -2623, -2623, -2623, -1741, -2623, -2623, -1718, -2623, -2623, -2623,
   -2623, -2020, -2623,  1308,   976, -2623, -2623, -2623, -2623, -2623,
     763, -2623, -2623, -2623, -2623, -2623, -2623,  -354, -2623, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623,    79, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,
   -2623, -2623, -2623,  1433, -2623,  1435, -2623,   751,  1100, -2623,
   -2110,   168, -2623, -2623, -2623, -2623, -2623, -2623,   325, -2623,
   -2623,  -141, -2623,  -773, -1350, -2623, -2623, -2623, -2623, -2623,
     294, -2623, -2623, -2623, -2623, -2623, -1736, -2623, -2623, -2623,
   -2623, -2623, -2623, -2277,  1036, -2623, -2332,  1120, -2623, -2623,
   -2053,   412,   413,   692, -2623, -1711, -1714, -2623, -2623,   116,
    -209, -2623, -2623, -2623, -2623, -1493, -2623, -2623, -2623,   319,
   -2623,   649,  -566, -2623,  1292,  -328,  1487,    74, -1953,   675,
     715,  -681, -2623, -2623, -2623, -2623,  2512, -1257, -2034,  3126,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  -347, -2623,
   -1523, -2623,  1857, -2623, -2623,   702,   704, -2623, -2261,   706,
     212,   519,   255, -1612, -2018,  1411,   142,   -48, -1298, -2623,
    1418, -2623, -2623, -2623,  1516,  -655, -2623, -2623,  -132,  1879,
   -2623,   845, -2623, -2623,   823,   235, -2623, -2623, -2623, -1974,
       1, -2426, -2623,   -51, -2623, -2623, -2623, -2623,  1554, -2623,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2518,
     -17, -2623, -2574, -2622, -1461, -1012, -2623, -2623,     4, -2623,
   -2623, -2623,   633, -1108,  1420,  -763,  2039,  1706,  1697, -1640,
   -2623, -2623,   646,  1000,   207, -2623, -2623, -2623, -2623,  1723,
   -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623, -2623,  -341,
    1097,  2630, -2623, -2623, -2623, -2623
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1971
static const short yytable[] =
{
      40,    42,    43,    45,   277,  1025,    45,    50,   581,   336,
     191,  1490,  1866,  1552,  1379,    94,  1429,  1382,  1708,  1709,
    1790,  1518,   699,   988,   975,  1197,   109,   979,  2572,  2395,
    1487,  1012,  1497,  1498,  1143,  1499,   964,  1520,  1521,   419,
     420,  1544,  1486,  2006,    66,  2131,   437,  1774,  2461,  1113,
    2437,  2174,  2439,  1944,  1945,   244,   305,   108,   390,    66,
      94,  2132,  2107,  2672,  2957,  2958,  2959,   421,   422,  1892,
     115,   592,  2603,   970,    39,    39,   191,   122,  1624,  2459,
      39,  2052,   129,    39,  1057,   131,    39,    39,   592,   134,
     135,  2926,  2308,  1488,  1751,   191,  1752,  1491,    39,   603,
    1608,   435,    79,    39,  2526,    86,   604,  2047,    66,  1855,
    1076,  2694,  1734,  1579,  2695,  2696,  2697,  2698,  2699,  2700,
    1081,  1088,    39,  2961,   239,    39,  1619,   241,   334,   243,
   -1969,   118,  1459,  2683,   247,  2685,   283,  1642,  1077,  1057,
    1629,    39,  2452,  2455,  2455,  1459,   331,  2455,   423,   283,
    2796,  1320,   439,  2891,   441,   523,   442,   443,   444,  2516,
    1205,    39,   369,  2324,  1057,   449,    39,   374,   375,   460,
     461,   334,   334,    79,  1543,  2851,  1148,   204,  1153,  1151,
    1057,     1,    39,   359,    39,     2,  1819,   592,  1196,   592,
    3091,  1620,   341,     3,  1259,   574,   339,   283,   342,   343,
     283,  1319,  1320,    39,  1083,   283,  1249,  1250,    39,  1445,
    2517,  2948,  2948,  2948,  2948,  3080,    39,  1237,   334,   283,
    1249,  1250,    39,  1057,  2718,    39,  3011,   191,  1099,  1859,
    1734,  1860,   191,  1861,   576,  2059,  2060,  2061,  2062,  2085,
     283,   337,   338,    39,  2328,   377,  2362,  2694,  2649,   608,
    2695,  2696,  2697,  2698,  2699,  2700,   609,   406,    86,  1540,
     106,  1608,   584,    66,   418,   418,   418,   418,   418,  1201,
    1915,    39,   418,    39,  1190,  2331,  2856,  1106,  1955,    39,
    1527,  1528,  1915,     4,  1207,  3313,  1646,  1222,   367,  1878,
      52,  1228,  3081,  3082,  2257,  2601,  2571,  1234,    39,  1236,
    1975,  1976,  2788,  1446,  1447,   106,    39,  2637,  2638,  2639,
    2640,  2641,  1936,  1609,  1201,  3179,    39,    62,     7,    66,
      66,   617,  1545,  1546,   620,  1601,  1602,  2636,   524,   977,
     526,   283,  1319,  1320,    39,   594,  1815,   592,   691,  1311,
     669,   628,   629,   630,   631,  2334,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   968,  1624,  2689,  1055,  1055,  1932,  2183,
     955,  1055,  1055,   649,   650,  2183,  2620,   334,   652,  3230,
     653, -1969,  2174,   437,  1055,    39,  2629,  1143,  1068,  3494,
    1057,  2396,    39,   656,   657,   658,   659,  2814,  3074,  1308,
    2530,   667,  1884,  1259,  1055,  1790,   334,  1055,   946,   592,
    3449,  1960,    89,  1055,  3486,  1695,    79,  1055,  2099,   592,
     969,  1055,  1139,    56,  2190,  1055,   191,    62,  1865,  1055,
    1055,   947,  1055,  2086,   612,  1055,     1,  1055,  1055,  1055,
       2,    62,  2335,     5,   677,  1055,  2815,  1201,  1055,    39,
    3083,  1469,  3075,   680,  1122,  1055,  2035,   682,  2258,   686,
    2370,  1754,  1055,  2373,  2191,   586,   587,   588,  1754,  1055,
    1760,  1855,   592,  1810,  1609,   592,    33,   691,  1397,  1398,
    1055,  2722,  1024,    32,  1055,  2753,  1262,   952,  1055,  2402,
      62,  2402,   191,  2692,  1055,   595,  2789,  1055,    62,  1259,
    2692,  2457,  2105,  2948,  2948,  1603, -1969,  2948,  1399,  1400,
    1401,  1305,  2465,    66,  2692,  1654,    85,    62,  1306,   953,
     851,   944,  1470,    86,   978,  2483,  2485,  1129,   605,  2546,
    2701,  2702,  2607,  2776,  1312,    62,  1879,  1916,  2776,  2776,
    2816,  1052,  2857,    60,  2819,  3302,  2819,  1558,   692,  1916,
     692,  1933,   107,  1139,  1658,  1437,  3310,  2154,   692,  2155,
    1575,  1131,  1053,  1056,     6,    89,  1625,    39,   191,    87,
      88,  2914,  3495,  2924,   986,   406,  1324,   406,   324,   325,
     326,   327,   328,  2435,  2852,  2703,  2879,  3249,   967,   418,
    2986,  2618,   972,  2910,  3054,   332,  1052,  1977,    77,  3061,
    1089,   588,  1625,  1089,   335,  1192,  1193, -1969,  2531,   418,
    1696,  2197,     7,  1098,    39,  2630,  3092,  1089,    39,    39,
    3147,  1089,   111,   112,  3167,  3167,  1492,  1324,  1115,    39,
    2892,  3175,  3282,  1089,  1243,  1098,  1251,  1246,   575,  3321,
    2983,  1127,  3321,     8,  1098,  1541,  1876,   529,  1023,  2071,
     286,  1137,  3115,  1258,  1641,  3383,  2325,  3307,  1152,  1655,
    3006,  3383,   117,  1190, -1969,  1195,  2701,  2702,    62,  1559,
    2919,  3126,     9,  1560,  1610,  1566,  1127,   577,  2241,  1493,
    1127,  1143,  2774,  2066,  1127,   333,  2048,  2262,  1604,  3180,
    1098,   110,  1489,  1098,  1383,  1262,  1542,    66,    66,    66,
    1044,    66,  1048,  1050,  2611,   585,  1058,  1060,  1061,  3196,
    1130,  1066,  2704,  1050,  3139,  3422,  1069,  1738,    66,  1035,
    1580,  2703,  2206,   606,  2447,  1762,  3438,  1061,  1822,  1697,
    2413,  2906,  1700,  1701,  2948,  1893,  1252,  1460,  1058,  1058,
    2948,  2948,  2810,  2948,  2948,  2948,  2948,  2782,  1061,  2189,
    1485,  1690,  2948,  3056,    66,  3058,  3314,  2811,  1324,  3051,
      66,  1061,    66,  2500,  1775,   936,    66,  2500,   415,    66,
    3099,  1116,    66,   971,  3104,  1862,   415,  1547,  2705,  1050,
     593,  1550,    66,  1863,  3167,   304,  3097,   418,  1133,  3070,
    1058,  1262,  2397,  1494,  1140,  1821,   415,    66,   304,  2244,
    1224,  2653,  2617,    66,  2447,   418,   418,  1836,  3285,  1710,
      66,    66,    66,  1055,  2316,   415,  1218,  3153,  3452,  1225,
    2447,  3047,  3289,  3050,    66,  1735,  3084,   119,  2706,  2707,
      89,  1238,  1719,  1238,   418,  1610,  1238,   418,  1448,  1238,
      66,  2363,  2642,  1786,  1648,  2184,   304,    39,  2704,   304,
    2410,  3108,   598,  3129,   304,  3231,  2470,  2471,  3183,  3000,
    2754,  1259,   599,  2447,  1548,  2355,  2948,    39,   304,  2948,
    2948,  2948,  2948,   610,  2505,  2262,  1402,   613,  2036,   578,
      39,   167,  3435,    10,  1605,  1368,  3450,   678,  1368,   304,
    3487,  1107,  1765,  1765,  1711,   667,   681,   667,   667,  2225,
     683,  1689,   687,  1765,  1755,  1766,  1766,  1202,  2199,   119,
    1712,  1756,  1261,  1761,  2705,  2219,  1766,  1606,  2220,  1823,
    1824,  1825,   121,     5,  3281,    90, -1969, -1969, -1969, -1969,
   -1969, -1969,  2403,  1260,  2409,  2781,  1843,  1055,  1055,  1055,
    1307,    39,  2988,  1287,  2458,  2463,  1347,  1052,  3193,  2374,
    3194,  3195,  2833,  1713,  3375,  2466,  3342,  2948,    61,   123,
      39,  3143,  1403,     1,  2706,  2707,  2948,  1920,  2484,  2486,
     127,  3151,  2547,   288,  1909,  2608,  2777,  1261,  3211,  3173,
     304,  2778,  2780,  2817,    51,  1901,  2347,  2820,  2993,  2824,
    2996,  1340,  1714,  2999,  1052,  2348,   291,  2956,  2956,  2956,
    2956,    39,  1209, -1969,  2234,  1404,  1698,  1767,  1767,  1195,
    1877,  1267,  1070,    39,  2915,  3241,  2925,    91,  1767,  2349,
    1300,  1715,  2350, -1969,  3374, -1969,  1890,   197,  3380,  1560,
    1716,  2378,   991,  2987,  1393,    51,   692,  3055,  2351,  1880,
      39,  1302,  3062,   324,   325,   326,   327,   328,  1908,     1,
    1733,  1210,  2053,     2,  2722,   161,  2381,    39,  2976,  1923,
   -1969,     3,  1045,  3148,    39,  1655,    62,  3168,  3174,   535,
    1058,   198,  1075,    66,  3176,  3283,  1780,  1789,  1477,   297,
    3008,   545,  3322,  1765,  1386,  3323,    62,  2916,  1211,    66,
    2911,  2912,  1058,  1093,  1143,  2920,  1766,    92,  3384,    62,
     249,  1790,  2021,  2838,  3391,    93,  1102,  2779,  1693,  2167,
    1138,  2168,    39,  2585,  1475,   242,    39,  2037,  1882,    39,
    2039,  1769,  1769,     8,   201,  3407,  3286,  3312,    61,  3009,
      39,    66,  1769,  1639,  1152,  1195,  1140,  1770,  1770,  2673,
    2542,  2675,  2352,  2676,  2550,    39,   992,  1140,  1770,  3166,
    1201,     4,    39,  1262,  3001,  3299,  1540,  2314,  3423,  2200,
      62,    66,    66,    66,   625,    66,  2054,    66,    66,  3439,
      13,   300,  2798,    66,    66,    32,    33,  1477, -1969,    62,
    3463,  3173,  3173,   301,   302,  1212,  2148,  1586,  2622,    39,
    2326,   303,    13,  1955,  3287,  2353,   251,  2074,  1767,    66,
     366,  1699,  2354,   324,   325,   326,   327,   328,   696,  1581,
    1573,   261,    66,   579,  2648,  2169,   950,  1635,  2170,    39,
      62,  1585,  2902,    39,    66,     5,  2379,  3474,  1816,  1593,
      39,  3213,    62,  1263,  1264,  1265,  1131,  1765, -1969,  1912,
    1955,  2904,    39,   684,  1266,  2022,   258,  2224,    66,    66,
    1766,  2382,   259,  2977,   174,   993,  2881,    66,    39,    62,
    1837,  1466,  1213,  2839,  2023,  2024,   175,  1768,  3041,    44,
      39,    39,  2799,    66,    66,  2055,    62,  2215,  1720,  1437,
    3214,   262,  3199,    62,  2025,  3204,  3207,  2452,  3206,  2956,
    2956,  1524,  3002,  2956,  3003,  2161,  3365,  3366,  3367,  1534,
    1692,   265,  1214,  1849,  3144,  3406,  2477,  2478,  2479,   266,
    2800,     5,  1769,  1340,  1340,  3300,  1763,  2313,  1764,   534,
     378, -1969,  2185,  1340,  2456,   540,  1960,  2460,  1770,  1825,
    2021,  1139,   427,   267,  1121,  1139,  1732,   428,    62,   430,
   -1969, -1969,   268,  1128,  1739,   437,     6,   379, -1969,    62,
    1577,  2212,  1767,  1010,  3203,  2013,  1013,  3203,   114,  1560,
   -1969, -1969,   269,   411,    62,    39,  1898,  1899,  1215,  1415,
     980,    62,   981,  1960,  2801,   191,  2075,   111,   112,  2233,
    2821,   270,  3112,  1799,  3431,   412,  3433,  2076,  2802,  1241,
    1452,  1416,  1244,   271,  2771,  1776,  2888,  1453,  2861,  1781,
    1787,  1781,  1421,  2992,  2992,   946,  2992,   181,    62,  2992,
     272,  1793,  1795,  1796,  1940,  1941,    66,  1800,  1802,  1803,
    1804,  1058,  2858,   273,  1422,     8,  1853,  1289,   947,  2032,
    1058,   182,     6,    39,   274,  3079,    39,  2247,    62,   330,
    1578,  1140,    62,    66,    39,    66, -1969,    66,    66,    62,
     275,  1742,  1743,  2901,     9,    66,    66,  1058,  2380,    66,
     418,    62,   418,    66,  2385,  2386,  1769,  2845, -1969, -1969,
     276,  1140,  3157,  2022,    39,   183,   278,    62,  1852,  1140,
       7,  2167,  1770,  2168,   184,    66,    66,  1223,  2803,    62,
    3182,  1229,  2023,  2024, -1969,  1233,  3324,  2506,   371,  2480,
    3048,  2507,  3102,   318,  2804,  1055,  3261,    39,  2527,    39,
    2518,     8,  2025,   319,  1946,  1947,  1948,   320,  2052,  1949,
    2956,  1950,  1951,   321,  1421,  2501,  2956,  2956,   322,  2956,
    2956,  2956,  2956,   323,  -296,  2539,    66,    66,  2956,    66,
       9,   354,    66,    66,  3425, -1969,  1422, -1969,   355,  2866,
     984,    39,   985,  3414, -1656,   427,   356,  2874,  2875,  2876,
     428,   429,   430,  1994,  1896,   360,   418,   418,   185,   186,
    3427,   418, -1969,    66,  1995,  1905,  1906,  1907,  2543,  1744,
    1745,  1746,  1747,  1748,  1749,  3408,  1725,  2169,  1726,  1727,
    2170,  1242,  3457,  1091,  1245,  1996,  1049,  1248,    39,  1991,
     361,    66,  1997,  1057, -1969,    39,   365,  1100,  2494,  2029,
    1998,  1105,  1955,  1238,   418,   418,   346,   347,   348,  -296,
      66,    66,  3414,  1119,  2508,  2509,  1825,  2512,  2579,  1475,
    2088,    39,  1999,   440,  1055,  -296,   424,   425,   426,  3427,
    1979,  1058,  1955,  1058,  1058,  2533,   363,  1058,  1058,  1955,
    1989, -1969,  2956,  1058, -1969,  2956,  2956,  2956,  2956,   370,
    2198, -1969,  3284,  1430,  1431,  1432,  3292,  1055,  3295,  3296,
    3297,  3298,   383,  2050,   381,  2057, -1969,    66,  -296,  1525,
    1526,  3203,   372,  1529,  1530,  2057,  1347,  1276,  2033,  1571,
     376,    39,  2080,  2081,  2082,  2083,  3409,   400,  1277,  3293,
    3410,  2179,  2992,  3409,   401,  3293,  1500,  3410,  3303,  3304,
    3305,  3306,  2576,   382,  1702, -1969,  1703,  -296,  1340, -1969,
    1340,   391,   392,  2271,  2273,   324,   325,   326,   327,   328,
    1340,  1340,  1058,   413,  1705,  2079,  1706,  1340,  1340,  1340,
    1340,   407,   450,  2956,   410,  1960,  -296,  1794,  1278,    39,
    1140,  1797,  2956,    39,  1801,  -296,    39,   384,   445,  2929,
    2930,  2211,  1279,   447,  2283,   283,  1319,  1320,    39,  2040,
     448,  2041,  1776,   385,  2044,  1960,  2045,  1781,  1321,  1322,
     667,   459,  1960,  1787,   469, -1969,  1781,   462, -1969, -1969,
    2489,   463,    39,  1952, -1969,  2667,  1953,  2668,  1954,  2797,
    2664,   111,   112,  2666,  2146,  2669,  2670,   393,  3118, -1969,
    2150,  1710,  1992,   465,  1386,  2644,   386,  2645,  1955,  1553,
    1554,  1555,  1556,   394,  1282,  1283,  1993,   451,  1956,   466,
    1152,  3382,  1065,   467,  3385,  3386,  3387,  3388,  2492,  2177,
      39,  1417,  1418,   452,  1074,  3188,  1817,  3189,  1817,  1957,
    2825,  1280,   468,  1058,  1140,   387,   516,  2193,  2194,  3468,
     418,    39,  2931,  1195,  1531,  1532,   395,  3120,   528,  1994,
    1535,  1536,  1958,  1094,   530,    66,  1959,  1924,   112,   532,
    1995,  2255,  2016,  2017,   388,  2855,   453,   537,  3218,  1111,
    1112,  2180,  2181,   389,   538,  1118,  1711,  2222,  1120,    66,
     539,  1996,  1263,  1264,   541,   396,  3440,  3441,  1997,  2794,
    2795,   542,  1712,   546,  1501,   547,  1998,  3155,  3156,   548,
   -1969,    66,  3444,  2248,  1593,   454,  1340,   552,   562,   563,
      66,  1140,    66,   564,   397,   567,   572,   582,  1999,  3252,
     583,   590,   591,   398,  2387,  3171,  3172,   596,  3260,   418,
     418,  1960,   597,   601,   455,  1713,  2946,  2946,  2946,  2946,
     602,   611,  3219,   456,   418,  3266,   618,   622,   621,    66,
      66,    66,   623,   626,   651,    66,   654,   660,  2827,   661,
     662,  2832,   670,  1058,  1055,   668,   671,  1139,   672,   673,
    1055,   674,   675,   676,  1714,   685,   679,  1357,   697,  1347,
    1359,  1059,  1360,  1361,  1362,  1363,  1364,     1,  2401,  1849,
      66,  2404,  2405,  2406,  2407,  2000,  1055,   951,  2369,  2369,
     956,  2001,  2369,  1715,  3220,   958,  3221,   959,   960,  2388,
     965,   976,  1716,  1085,  1086,   340,  3311,   982,   966,   345,
     983,  1502,  3222,   990,  1340,  2389,  1190,  1503,  1504,  1505,
    3223,   995,   997,  1340,  3224,   999,  1340,  1340,  1340,  1340,
    2408,  1000,  1001,  1058,  1018,  1021,  1026,  2414,  1340,  1506,
    1027,  2432,  1029,  1744,  1745,  1746,  1747,  1748,  1749,  3225,
    1031,   191,  1030,  1037,  1032,  1135,  1038,  1034,  2390,  1039,
   -1969,  1040,  2448,  2448,  2448,  1150,  1230,  2448,  1340,  2462,
    1291,  1292,  1776,  1293,    71,  1294,  1295,  1296,  1298,  1297,
    1299,  1301,  3359,  3014,  3015,  3016,  1303,  3018,  3019,  3020,
    3021,  3022,  3023,  2757,  1304,  1309,  3026,  2391,  1310,  1314,
    1313,  2487,  1315,  2488,  2490,  1358,  2491,  2493,  2758,  2759,
    2495,  3219,  1365,  1366,  1781,  1367,  1370,  2760,  1781,    66,
    1371,  1373, -1969,    66, -1969,  1384,  2392,  1374,  1391,  1058,
    2448,  1375,    66,  2177,  1376,  2393,  2523,  2523,   162,   194,
   -1969,  3093,  1377,  1378,  1507,  1380,  1385,  1508, -1969,  1389,
    1152,  2761, -1969,  1390,  1392,  1509,  1195,    66,  1414,  1419,
    2762,  1420,  1324, -1969,  2541,  1423,  1433,    66,  1424,  3109,
    1425,  1427,  1444,  3220,  1451,  3221,    66, -1969,  1450,  1454,
      66,  3364,  1195,  3415,  3416,  3417,  3418,  3419,  3420,  2763,
    1510,  3222,  3437,  2932,  1455,  1457,  2933,  1458,  1462,  3223,
    1474,  1463,  1481,  3224,  1465,   194,    66,  1479,  1482,  2934,
    1522,  1538,  1740,  1741,  1742,  1743,  1477,  1539,  2946,  2946,
    1543,  1567,  2946,  1568,   194,  1511,  1576,  1581,  3225,  1569,
    1570,  2586,  1574,  1590,  2764,  1592,  1615,  1616,  1617,   592,
    1618,  1623,  1055,  1055,  1512,  1513,  1627,  1630,  2935,  2936,
    1631,  1633,  1632,  1680,  1691,  1514,  3169,  3170,  3171,  3172,
    1515,  2937,  1688,  1694,  1704,  1721,  1722,  1347,  1753,  1723,
    1724,  1728,  1729,  1730,  1731,  1779,  1759,  1792,  2765,  1807,
    1812,  1058,  1808,  3202,  3107,  1809,  3202,  1814,  1813,  1445,
    1828,  1835,  1842,   414,  1550,  1844,  2448,  1846,  1855,  1516,
    1868,  1857,  2938,  1869,  2625,  1989,  2448,  1885,   944,  1979,
    1058,  1887,  1340,  1897,  1888,  1900,  1902,  3212,  1919,  1926,
    1927,  3127,  1912,  1929,  2678,  1979,  1058,  3432,  1921,    66,
    2369,  1517,  1849,  1625,  2897,  1426,  2899,  1967,  1969,  1970,
    2690,  2939,  1744,  1745,  1746,  1747,  1748,  1749,  1978,   521,
     522,  2712,  1972,  2940,  2030,  1686,   194,  1440,  2034,  2038,
    2886,   194,   483,   484,   485,  2941,  2942,  1719,  3187,  1340,
    3190,  3191,  2042,  2943,  2043,  2048,  2944,  1058,  2071,  1058,
    2414,  2046,  2063,  1340,   304,  1340,  1744,  1745,  1746,  1747,
    1748,  1749,  2095,   486,  2089,  2864,  1340,  2084,  2090,  2096,
     667,  2448,    66,  2432,   191,  3499,  2097,  3254,   667,   667,
     667,  2102,  2105,  2100,  2448,  2101,  2136,  2134,  2137,  2139,
    2140,  2141,  2143,  2152,  2138,  3264,  2157,  2158,  2159,  2156,
    2162,  2163,  1781,  2164,  2165,  2166,  2160,  2178,  1152,  1152,
    1624,  2201,  2203,  2204,  2210,  2208,   191,  2213, -1969,  2946,
    1787,  2217,  1781,  2218,  2223,  2946,  2946,  2237,  2946,  2946,
    2946,  2946,  2226,  2227,  2228,  2146,  2231,  2946,  2251,  2245,
    2262,  2264,    66,  2727,  2728,  2311,  2729,  2730,  2731,  2312,
    2323,  1266,  2329,  2337,  2339,  2342,  3319,  2338,  2344,  2343,
     487,   488,   489,   490,   491,   492,  2358,  2177,  2359,  2846,
    2377,  2848,  2255,  2383,  2448,  1058,  2366,    66,   493,   494,
     495,  2384,  2398,  2400,  2399,  2412,  2429,  2434,  2438,  2436,
    2440,  2467,    66,  2468,    66,  2870,    66,  2441,  2444,  2469,
    2472,  3255,  2473,  1347,  2498,  2474,  2475,  2476,  2503,  2514,
      66,  1078,  1078,   655,  2534,  2532,  2536,  1340,  2537,  3186,
    2538,  2552,  2544,  2553,  2555,   194,  2949,  2949,  2949,  2949,
     418,  2540,   418,  2556,  2558,  2559,  2557,  3279,  3344,  2560,
   -1969,  2578,    66,    66,  2577,  2732,  2580,  1540,  1340,  2584,
    1265,  2946,  2604,  2733,  2946,  2946,  2946,  2946,  2593,  2595,
    2448,  2609,  2605,  2606,  2623,  2621,  2646,  2613,  2614,  2651,
    2656,  2665,  1500,  2671,  2945,  2945,  2945,  2945,  2448,  2448,
    3202,  3106,  2674,  2677,  2679,  2680,  2692,  2734,    66,  2681,
    2682,   194,  2693,  2970,  3111,  2713,  2735,  2716,  2725,  2773,
    2774,  3004,  2775,  2783,  3101,  2786,  2787,  2790,  2792,  1078,
    2793,  2812,  2688,  2813,  2691,  2822,  2823,   496,  2826,  1253,
     497,  2829,  2828,  2836,  2840,  2736,  2737,  2844,  2847,  1340,
    1340,  2862,  2854,  2865,  2873,  2896,  2884,  2907,  1340,  1340,
    2908,  1340,  2946,  2916,  1340,  2926,  1340,  2923,  2927,  1734,
    1340,  2946,  2968,  2978,  2975, -1969,  1806,  2980,  2979,  2981,
    2982,  3005,  2994,  2984,  2985,  1811,  2997,   194,  3007,  3032,
    2738,  3012,  3013,  3243,  3017,  3024,   191,  3025,  3394,  3395,
    3034,  2800,  3035,  3243,  3031,  3036,  3037,  3038,   667,  3052,
      66,  3039,  1834,  3040,  3045,  3053,  3057,  1041,  1042,  1043,
    3059,  1046,    66,  3063,  3064,  3068,  3088,  3094,  3095,  3096,
    3097,  2448,  3049,  2448,  2739,  2011,  2012,  3110,  1072,  3114,
    3119, -1969,  2028,  3116,  3123,  3124,  3132,  1260,  3135,  3145,
    3167,  3139,  3177,  3158,  3159,  3160,  3161,  1058,  3162,  3184,
     498,  3192,  3163,  3178,  3164, -1837,  3216,  2771,  3233,  3071,
    3072,  3240,  3234,  2495,  1096,   499,  1781,  3235,  3197,   500,
    1101,  3238,  1103,    66,  3424,  3237,  1110,  3239,  2740,  1110,
    1341,  3244,  1110,  2523,  3246,  3247,  3103,  2523,  1055,  3253,
    1501,   418,  1123,  3257,  3259,  3263,  3265,  3267,  3268,  3273,
    3269,    66,  1643, -1969,   418,   501,    66,  1123,  3271,  3251,
    3278, -1969,  3290,  1186,  3308,    66,  1735,  3288,  3316,  3317,
    1046,  1199,  1203,  3325,  3335,  3336,  1219,  3337,  2949,  2949,
    3338,  3340,  2949,   502,  1231,  3339,  3358,  3345,  3357,  3363,
    3371,  3381,  2947,  2947,  2947,  2947,  3389,  3392,  3405,  3421,
    1255,   503,  3443,  3434,  3451,  3136,  3445,  3446,  3447,  3448,
    3461,  2448,  1253,  3472,  3473,  3480,  3482,  3484,  3488,  3493,
    2625,  2448,  2818,  1979,  1979,  3483,  2945,  2945,  3478,  3460,
    2945,  3485,  3497,  2869,  1381,  2569,  1983,  2236,  1984,  1985,
    1911,  3165,  1987,  1988,    57,  3498,  1036,    58,  2007,  2519,
    2843,   543,  2528,   200,  1644,  3208,   205,  2712,  2995,   353,
    2998,  1028,  1645,   536,    66,  1979,  2091,  1502,  1646,  2092,
    1647,   688,   569,  1503,  1504,  1505,   358,   989,   544,  3458,
    1707,  1648,   504,  1058,   571,   961,   962,  2149,  1217,   607,
    1684,  1140,  2216,  1372,  1140,  1506,  2367,  1340,  2375,  2195,
    1340,  1939,  1340,  2510,  2448,  2895,  1943,  3134,  2261,  1649,
    2583,  3481,  2515,  2281,  1839,  3262,    54,   136,    68,    69,
    2662,    55,  2243,  1117,  1290,  1650,  2246,  2070,    66,  1925,
    1651,   527,  1395,  2250,  1195,  2259,  1966,  3217,  1875,  3326,
    1149,  1621,  1652,  1830,  1873,  3464,  1820,  3334,   505,  1653,
    3044,  2890,  1891,  2214,  2741,  2742,  2743,  2744,  2745,  2746,
    2747,  2748,  2749,  2750,   627,  1340,  3043,  3027,  2769,  3090,
    3250,  3248,  1946,  1947,  1948,  3245,  3073,  1949,  2504,  1950,
    1951,  2464,  2135,  2104,  3467,   418,  3210,  1253,  2615,    66,
    3370,  2009,  1870,  2010,  3152,  2635,  1347,  2341,  3046,  3341,
    1507,  3069,  2411,  1508,  2989,  2332,  2990,    66,  2687,  2949,
    2050,  1509,  3396,  3205,  3065,  2949,  2949,  2785,  2949,  2949,
    2949,  2949,  2770,  3232, -1969, -1969, -1969,  2949,  2686, -1969,
    1982, -1969, -1969,  1255,   998,    49,    66,  3492,  1672,  2723,
    3154,  1340,  2724,  2922,  2448,  2065,  1510,  3209,  2186,  1438,
    3373,  2064,  1341,  1341,  1974,  1340,  1638,  2945,  3150,  3291,
    3309,  2627,  1341,  2945,  2945,  1937,  2945,  2945,  2945,  2945,
    3301,  2853,  2448,  2087,  2448,  2945,   191,  1340,  1476,  1854,
    1848,  1511,  2850,  2535,  2947,  2947,   698,  1838,  2947,     0,
       0,  1468,     0,     0,     0,     0,     0,  1654,     0,     0,
    1512,  1513,  1655,     0,     0,     0,     0,     0,     0,  1656,
       0,  1514,     0,    66,     0,     0,  1515,     0,    66,     0,
      66,  1496,  1496,  1496,     0,  1496,     0,  1496,  1496,     0,
       0,  1657,     0,    71,    71,     0,  1658,  2448,   667,     0,
    3379,  2949,     0,     0,  2949,  2949,  2949,  2949,     0,     0,
      66,     0,     0,     0,     0,  1516,     0,     0,     0,  1203,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,  1203,     0,     0,     0,     0,  3397,  2333,  3136,
       0,     0,     0,     0,  1588,  1340,     0,  1517,     0,  2945,
       0,     0,  2945,  2945,  2945,  2945,     0,  3390,  2284,  2285,
    2286,  2287,  2288,  2289,     0,     0,     0,     0,  1255,  1438,
       0,  3393,     0,     0,     0,     0,     0,  1628,  1140,     0,
       0,   485,  1340,     0,  1253,     0,  2565,  2566,     0,     0,
       0,     0,  2949,  1636,  1636,     0,     0,  2575,     0,     0,
       0,  2949,     0,    66,    66,    66,    66,    66,    66,     0,
     486,  1952,     0,     0,  1953,  3426,  1954,     0,  2070,     0,
       0,     0,  2587,  2588,  2589,  2590,  2591,  2592,     0,     0,
       0,     0,  2597,  2598,  2599,  2600,  1955,     0,     0,  2602,
    2945,     0,     0,     0,     0,     0,  1956,     0,     0,  2945,
    3379,   164,   165,     0,     0,  2290,     0,     0,     0,   166,
      39,     0,     0, -1969,     0,     0, -1969,  2280, -1969,     0,
       0,     0,     0,     0,   167,  2947,     0,     0,     0,     0,
       0,  2947,  2947,     0,  2947,  2947,  2947,  2947, -1969,     0,
    1958,     0,     0,  2947,  1959,  1340,     0,  3469, -1969,     0,
       0,     0,     0,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,     0,  1834,     0,     0,     0,     0, -1969,
    1253,  2654,  2655,     0,     0,   493,   494,   495,  2659,  2660,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3490,
    3491,  3469, -1969,     0,     0,     0, -1969,     0,     0,   168,
       0,     0,    66,     0,  3500,     0,     0,     0,     0,     0,
       0,   169,     0,    71,     0,    71,     0,  1203,  1110,  1960,
       0,     0,     0,     0,     0,  1829,  1123,     0,     0,  1203,
       0,     0,     0,  1840,     0,     0,     0,     0,   170,     0,
       0,     0,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1255,  1186,  2947,     0,     0,
    2947,  2947,  2947,  2947,     0,     0,     0,  1341,     0,  1341,
       0, -1969,     0,     0,     0,     0,     0,     0,     0,  1341,
    1341,     0,     0,     0,     0,     0,  1341,  1341,  1341,  1341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1874,  1186,     0,    71,
       0,     0,  1881,  1883,   496,     0,  2610,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2834,  2835,    62,
       0,   171,     0,     0,     0,     0,  2842,     0,     0,     0,
       0,  2291,     0,  1903,     0,  2634,     0,     0,  2947,     0,
       0,     0,     0,     0,  2292,     0,     0,  2947,     0,     0,
       0,  2650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1931,     0,     0,  2877,  2878,     0,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   281,   282,
    1965,  1255,     0,     0,   283,   284,   285,    39,     0,     0,
       0,  2898,     0,  2900,     0,     0,     0,     0,     0,     0,
       0,   167,  2070,     0,  2070,     0,  2293,     0,     0,     0,
       0,     0,  2294,  1316,  1317,  1318,     0,     0,   172,   283,
    1319,  1320,    39,     0,     0,     0,     0,   498,     0,  1078,
       0,     0,  1321,  1322,     0,     0,     0,  2015,     0,     0,
       0,     0,   499,     0,     0,     0,   500,     0,     0,     0,
       0,  2295,     0,   173,  2971,  2972,     0,     0,  2973,  2974,
       0,     0,     0,     0,     0,  1341,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2296,   168,     0,     0,     0,
       0,   286,   501,     0,     0,  2297,  2298,   174,   169,     0,
       0,  2299,     0,     0,     0,     0,     0,     0,     0,   175,
       0,  2300,     0,     0,     0,     0,     0,     0,     0,     0,
     502,     0,     0,     0,     0,   170,  1323,     0,     0,     0,
       0,     0,     0,  2301,     0,     0,  2302,  2303,   503,     0,
    2186,  2304,     0,     0,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,     0,     0,     0,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1341,     0,     0,     0,     0,  2305,     0,
       0,     0,  1341,     0,     0,  1341,  1341,  1341,  1341,  2306,
       0,     0,     0,     0,     0,     0,    62,  1341,   171,   504,
       0,     0,     0,     0,     0,   180,   615,   470,   471,   472,
       0,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,  3100,  2207,     0,  1341,  3105,     0,
     181,  1139,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  3113,     0,  1203,
       0,     0,   486,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,  3125,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
    2256,     0,  1186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,     0,     0,   183,     0,
     287,     0,     0,     0,     0,     0,     0,   184,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,  1203,
    2315,  1203,     0,     0,     0,  1046,  1253,     0,     0,     0,
     173,     0,     0,     0,     0,  2417,     0,   487,   488,   489,
     490,   491,   492,     0,   486,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
    2361,     0,     0,     0,   174,     0,     0,   493,   494,   495,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,  3067,     0,     0,     0,     0,     0,     0,     0,
       0,   185,   186,     0,   288,     0,     0,     0,     0,   289,
       0,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,     0,     0,
       0,     0,   292,     0,     0,   293,  1324,     0,   294,     0,
       0,   487,   488,   489,   490,   491,   492,   295,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
     494,   495,     0,     0,     0,     0,     0,  1325,     0,     0,
    2418,  1341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2419,  1327,     0,     0,     0,   663,   296,     0,
       0,     0,   180,     0,   496,     0,     0,   497,     0,  1203,
     297,     0,     0,  1203,     0,     0,   496,     0,     0,   497,
       0,   298,  1203,     0,     0,  3277,     0,   181,  3280,     0,
       0,     0,     0,  1328,     0,     0,     0,     0,  1341,     0,
     194,     0,     0,     0,     0,  1329,     0,  1203,     0,     0,
       0,   299,  1341,     0,  1341,     0,     0,  1255,     0,     0,
       0,     0,     0,     0,     0,  1341,  2548,   280,     0,     0,
    2551,     0,     0,     0,     0,     0,   281,   282,  2070,     0,
       0,     0,   283,   284,   285,    39,  1330,     0,     0,     0,
       0,     0,     0,     0,     0,   183,  2574,     0,     0,   167,
       0,     0,   300,     0,   184,     0,     0,     0,   496,     0,
       0,   497,     0,     0,   301,   302,  1341,     0,     0,  1331,
       0,     0,   303,     0,     0,  1332,     0,   498,     0,     0,
       0,     0,     0,   304,  1333,  1334,     0,  1335,     0,   498,
       0,     0,   499,     0,     0,     0,   500,     0,     0,  1336,
    1337,     0,     0,     0,   499,     0,     0,  1338,   500,     0,
    1339,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,  3368,   168,     0,     0,     0,     0,   286,
       0,     0,   501,     0,     0,     0,   169,     0,   185,   186,
       0,     0,     0,     0,   501,     0,     0,     0,  1316,  1317,
    1318,     0,     0,     0,   283,  1319,  1320,    39,     0,     0,
     502,     0,     0,   170,     0,     0,  1341,  1321,  1322,  2652,
       0,     0,   502,     0,  3398,  3399,     0,  3401,   503,  3403,
    3404,   498,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,   499,  1341,     0,     0,
     500,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1341,  1341,  1341,  1341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,     0,     0,     0,
       0,     0,  1203,     0,     0,     0,     0,  3453,     0,  3454,
       0,  1323,     0,     0,    62,     0,   171,     0,     0,   504,
       0,     0,     0,     0,   502,     0,     0,     0,     0,     0,
       0,   504,     0,     0,     0,     0,     0,     0,  1341,  1341,
       0,     0,   503,  3466,     0,     0,     0,  1341,  1341,     0,
    1341,     0,     0,  1341,     0,  1341,     0,     0,     0,  1341,
       0,     0,  3475,  3476,     0,     0,  3477,     0,     0,  3479,
       0,     0,  1203,     0,     0,  1078,  1078,  1078,     0,  1078,
    1078,  1078,  1078,  1078,  1078,   505,     0,     0,  1078,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,   194,     0,     0,     0,  1203,     0,     0,
       0,     0,     0,   172,     0,     0,     0,     0,   287,     0,
       0,     0,  2867,   504,  1072,     0,  2871,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1139,     0,     0,     0,
    2883,     0,     0,     0,     0,   194,     0,     0,   173,     0,
       0,  2549,   470,   471,   472,     0,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,  2903,  2905,     0,     0,     0,     0,     0,     0,
       0,     0,   174,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,   175,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   288,     0,  1253,     0,     0,   289,  2969,   290,
       0,     0,     0,     0,     0,   283,  1319,  1320,    39,     0,
     176,     0,     0,     0,     0,   291,     0,     0,  1321,  1322,
       0,     0,     0,     0,     0,   177,     0,     0,     0,     0,
     292,     0,     0,   293,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,   295,   179,     0,     0,     0,
       0,     0,     0,     0,     0,  1341,  1341,     0,     0,  1341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
       0,     0,     0,     0,     0,  1434,   296,     0,     0,     0,
     180,     0,   493,   494,   495,     0,     0,     0,   297,     0,
    3028,     0,  2931,     0,     0,     0,     0,     0,     0,   298,
       0,     0,  3042,     0,     0,   181,     0,     0,   280,     0,
    1341,  1324,     0,  1341,     0,     0,  1341,   281,   282,  1341,
       0,  1341,     0,   283,   284,   285,    39,     0,     0,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,  1325,     0,     0,  1326,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1327,     0,
       0,     0,     0,  1203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,     0,   194,     0,     0,     0,     0,
     300,     0,   184,     0,  1341,  1719,     0,     0,     0,     0,
       0,  1203,   301,   302,     0,     0,  1186,     0,  1328,     0,
     303,     0,     0,     0,     0,  1255,     0,     0,     0,     0,
    1329,   304,     0,     0,     0,   168,     0,  1139,     0,     0,
     286,   496,     0,   280,   497,     0,     0,   169,     0,     0,
       0,     0,   281,   282,     0,     0,     0,     0,   283,   284,
     285,    39,   479,   480,   481,   482,   483,   484,   485,     0,
       0,  1330,     0,     0,   170,   167,     0,     0,     0,     0,
    1341,     0,     0,     0,     0,     0,   185,   186,     0,     0,
       0,     0,     0,     0,  1341,     0,  1341,   486,     0,     0,
       0,     0,  1341,  1341,  1331,  1341,  1341,  1341,  1341,     0,
    1332,     0,     0,     0,  1341,     0,  1341,     0,     0,  1333,
    1334,     0,  1335,     0,  1186,     0,     0,     0,     0,     0,
       0,     0,  2108,  1341,  1336,  1337,     0,     0,     0,     0,
       0,     0,  1338,     0,     0,  1339,     0,     0,     0,     0,
     168,     0,     0,   304,     0,   286,     0,     0,     0,     0,
       0,     0,   169,     0,   498,    62,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,     0,     0,   500,     0,     0,     0,     0,  3028,   170,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
       0,     0,     0,     0,     0,     0,     0,  1253,     0,     0,
       0,     0,   493,   494,   495,     0,     0,     0,     0,   501,
       0,     0,     0,     0,  1341,     0,     0,     0,  1341,     0,
       0,  1341,  1341,  1341,  1341,     0,     0,     0,     0,     0,
       0,     0,  1324,     0,     0,     0,     0,   502,     0,  1203,
       0,     0,     0,     0,     0,     0,     0,  1341,     0,     0,
       0,  1341,     0,     0,   172,   503,     0,  1203,     0,   287,
       0,     0,     0,  2932,     0,     0,  2933,     0,     0,     0,
      62,     0,   171,     0,     0,     0,     0,     0,     0,  2934,
       0,     0,     0,     0,     0,     0,  1186,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   282,  1341,
       0,     0,     0,   283,   284,   285,    39,     0,  1341,  2936,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
     167,  2937,     0,     0,     0,   175,   504,     0,     0,     0,
       0,   496,  2929,  2930,   497,     0,     0,     0,   283,  1319,
    1320,    39,     0,   288,     0,     0,     0,  2109,   289,     0,
     290,  1321,  1322,  3028,  1341,     0,     0,     0,  3329,   172,
    3331,   176,  2938,     0,   287,     0,   291,  2110,  2111,  2112,
       0,     0,     0,     0,     0,     0,   177,     0,     0,     0,
       0,   292,     0,     0,   293,     0,     0,   294,     0,     0,
    1203,     0,   505,     0,   173,   168,   295,   179,     0,     0,
     286,  2939,     0,     0,     0,     0,  2113,   169,  1255,     0,
       0,  1253,     0,  2940,     0,   194,     0,     0,  2114,     0,
       0,     0,     0,     0,     0,  2941,  2942,     0,   174,  2115,
       0,     0,     0,  2943,   170,  2931,  2944,   296,     0,     0,
     175,   180,     0,     0,   304,  2116,     0,     0,     0,   297,
       0,     0,     0,     0,   498,  2117,     0,     0,   288,     0,
     298,     0,  2511,   289,   580,   290,   181,     0,     0,   499,
    2118,     0,     0,   500,     0,     0,   176,     0,     0,     0,
       0,   291,     0,  1496,  1496,  1496,  1496,  1496,  1496,     0,
     299,   177,     0,     0,     0,     0,   292,     0,     0,   293,
       0,     0,   294,     0,     0,     0,     0,     0,     0,   501,
       0,   295,   179,     0,     0,     0,     0,     0,  2119,     0,
       0,     0,     0,     0,     0,    62,     0,   171,     0,     0,
       0,     0,     0,     0,   183,     0,     0,   502,     0,     0,
       0,   300,     0,   184,     0,     0,     0,     0,  2120,     0,
       0,  2887,   296,   301,   302,   503,   180,     0,  2121,     0,
    1139,   303,     0,     0,   297,     0,     0,     0,     0,     0,
       0, -1970,   304,     0,     0,   298,     0,     0,     0,  2122,
       0,   181,     0,  2123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1970, -1970, -1970,     0,     0,
   -1970,     0, -1970, -1970,     0,   299,     0,     0,     0,     0,
       0,  2124,     0,     0,     0,     0,   138,     0,     0,     0,
    2125,     0,     0,     0,   172,     0,     0,   185,   186,   287,
       0,     0,  1255,     0,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,   139,   300,     0,   184,   173,
       0,     0,     0,     0,     0,     0,     0, -1970,   301,   302,
       0,     0,     0,     0,   140,   141,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,   174,     0, -1970,     0,     0,     0,     0,
       0,     0,   505,     0,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,     0,     0,   288,     0,     0,   143,     0,   289,     0,
     290,     0,     0,     0,     0,     0,     0,   144,     0,     0,
   -1970,   176,   185,   186,     0,     0,   291,     0,     0,     0,
       0,     0,     0,   145,     0,     0,   177,     0,     0,     0,
       0,   292,     0,   146,   293,  1324,     0,   294, -1970,     0,
   -1970,     0,     0,     0,     0,   138,   295,   179,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1970,  2932,     0,     0,  2933,
       0,     0, -1970,     0, -1970,     0,     0,     0,     0,     0,
       0,     0,  2934,     0,   139, -1970,     0,   296,   148,     0,
   -1970,   180,     0,     0,     0,     0,     0,     0, -1970,   297,
       0,     0, -1970,   140,   141,     0,     0,     0, -1970,  1719,
     298,   149, -1970, -1970, -1970, -1970,   181,     0,     0,     0,
       0,     0,  2936,     0,     0,     0,   150, -1970,     0,     0,
       0,     0,     0,   151,  2937,     0,   152,     0,     0,     0,
     299,     0,     0,   142, -1970,     0,     0, -1970,     0, -1970,
       0,     0,     0,     0,     0,   143, -1970,   153,     0,     0,
       0,   154,     0,     0,     0,     0,   144,     0,     0, -1970,
       0,     0,     0,     0,     0,  2938,     0,     0,     0, -1970,
     155,     0,   145,     0,   183,     0,     0,     0,     0,     0,
       0,   300,   146,   184,     0,     0,     0,     0,   156,     0,
   -1970, -1970,     0,   301,   302,     0,     0,   147,     0,     0,
       0,   303,     0,     0,  2939, -1970,     0,     0,     0,     0,
       0,     0,   304, -1970,     0,     0,  2940, -1970,     0,   480,
     481,   482,   483,   484,   485, -1970, -1970, -1970,  2941,  2942,
       0,     0,     0,     0,     0,     0,  2943,   148,     0,  2944,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,     0,     0,     0,   185,   186,     0,
       0,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,   151,     0,     0,   152,     0,     0,     0,     0,
       0,     0, -1970,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1970,     0,     0,   153,     0,     0,     0,
     154,     0,   470,   471,   472,     0,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1970,     0,     0,     0,   156,     0,     0,
     487,   488,   489,   490,   491,   492,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,   493,   494,
     495,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   700,   701,   702,     0,     0,     0,     0,     0,     0,
     703,     0,     0,   704,     0,     0,     0,     0,     0,     0,
     705,   706,     0,     0, -1970,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1970,     0,     0,     0,     0,   707,   708,     0,     0,     0,
     709,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     710,   711,     0,   712,     0,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   495,     0,     0,   713,     0,     0,
       0,     0,     0,     0,     0,     0, -1970,     0,     0,     0,
       0,     0,     0,     0,   714,     0,     0,   715,   716,     0,
   -1970, -1970, -1970, -1970, -1970, -1970, -1970,   496, -1970, -1970,
     497,   717,     0,   718,   719,   720,     0,     0,     0,     0,
       0,     0,     0,   721,   722, -1970,   723,   724,   725,     0,
       0,     0,     0,     0,   726,     0,     0,   727,     0,   728,
     729,   730,     0,     0,     0,     0,     0,   731,     0,   732,
     733,     0,   734,     0,   735,   736,     0,     0,   737,     0,
       0,   738,   739,   740,   741,   742,   743,     0,     0,     0,
     744,   745,   746,     0,   747,     0,     0,     0,   748,     0,
     749,   750,     0,     0,     0,     0,   751,     0,     0,   752,
       0,     0,   753,     0,   754,     0,   755,     0,   756,     0,
       0,     0,   757,   758,     0,   759,   760,   761,     0,     0,
     762,   496,   763,   764,   497,   765,     0,     0,     0,     0,
       0,     0,     0,   766,   767,     0,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,   768,     0,     0,   769,
     770,     0,     0,   771,   772,   499,     0,   773,   774,   500,
       0,     0,     0,     0,     0,     0,   775,   776,   777,     0,
     778,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     779,   780,   781,     0,   782,     0,     0,     0,   783,   784,
       0,     0,     0,   785,     0,   501,     0,     0,     0,     0,
       0,   786,     0,     0,     0,     0,     0,     0,     0,   787,
     788,   789,     0,     0,     0,     0,     0,   790,   791,     0,
       0,     0,     0,   502,     0,   792,     0,     0,   793,     0,
       0,     0,   794,   795,     0,     0,     0,     0,     0,     0,
       0,   503,     0,   796,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
     797,     0,     0,   500,   600,     0,     0,     0,   798,     0,
       0,     0,     0,     0,   799,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   800,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   801,     0,   501,
       0,     0,     0,   802,     0,   803,   804,     0,     0,     0,
       0,     0,     0,   805,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,     0,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,   806,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   807,     0,     0,     0,     0,     0,     0,
     808,   470,   471,   472,     0,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   505,     0,
       0,     0,     0,     0,   809,   810,     0,     0,     0,   811,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   812,     0,     0,     0,     0,   486,   813,   814,   815,
     816,     0,     0,     0,   817,     0,   504,     0,   818,     0,
       0,     0,     0,     0,     0,   819,   820,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   821,     0,   822,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   823,
       0,   824,     0,     0,   825,     0,     0,   470,   471,   472,
     826,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,     0,     0,   827,     0,     0,   828,
       0,     0,     0,     0,   829,     0,     0,   830,   831,     0,
       0,     0,   486,   487,   488,   489,   490,   491,   492,     0,
       0,     0,   832,     0,     0,     0,     0,     0,     0,   833,
       0,   493,   494,   495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   834,   835,   836,   837,   838,   839,   840,     0,
       0,   841,     0,   842,     0,   843,     0,     0,     0,     0,
     470,   471,   472,     0,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   470,   471,   472,     0,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,   487,
     488,   489,   490,   491,   492,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   493,   494,   495,
       0,     0,     0,     0,     0,     0,   486,     0,     0,   470,
     471,   472,     0,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   486,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
     493,   494,   495,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   496,     0,     0,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,     0,     0,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,   493,
     494,   495,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,   500,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   495,     0,     0,     0,     0,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   496,
       0,     0,   497,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
     496,     0,     0,   497,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   499,     0,     0,     0,   500,   624,
       0,     0,   470,   471,   472,     0,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   496,     0,
       0,   497,     0,     0,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   502,     0,     0,   504,     0,     0,     0,     0,
     496,     0,     0,   497,     0,     0,     0,     0,     0,     0,
     503,     0,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,   500,   996,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,   500,  1002,     0,     0,     0,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,   501,     0,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
       0,   498,     0,     0,     0,     0,     0,     0,   501,     0,
       0,   504,   493,   494,   495,   502,   499,     0,     0,     0,
     500,  1003,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,     0,     0,   502,     0,     0,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,     0,   501,     0,   499,     0,
       0,     0,   500,  1004,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,   496,     0,     0,   497,   470,   471,   472,     0,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,   504,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,   505,   470,   471,   472,     0,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,     0,     0,   504,   470,   471,   472,     0,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,   505,
     470,   471,   472,     0,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,   505,     0,   500,  1005,   486,     0,   487,   488,   489,
     490,   491,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
       0,     0,     0,     0,     0,     0,     0,   502,     0,     0,
       0,     0,   493,   494,   495,     0,     0,     0,   487,   488,
     489,   490,   491,   492,     0,   503,     0,     0,     0,     0,
       0,  1155,  1156,  1157,  1158,     0,   493,   494,   495,     0,
       0,     0,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     493,   494,   495,     0,     0,     0,     0,     0,     0,   471,
     472,     0,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,   504,   497,     0,     0,
       0,     0,     0,   486,     0,     0,     0,   472,     0,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,     0,  1159,   497,     0,     0,     0,     0,     0,
     486,  1160,     0,     0,     0,     0,     0,     0,     0,     0,
    1161,     0,   505,  1162,     0,   496,     0,     0,   497,  2416,
       0,     0,     0,     0,     0,     0,     0,     0,  1316,  1317,
    1318,     0,     0,     0,   283,  1319,  1320,    39,     0,   496,
       0,     0,   497,     0,     0,     0,     0,  1321,  1322,     0,
     487,   488,   489,   490,   491,   492,  1163,     0,     0,     0,
       0,     0,     0,  1164,     0,     0,     0,   498,   493,   494,
     495,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,   500,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   487,   488,   489,
     490,   491,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   498,   493,   494,   495,     0,     0,
    1165,     0,   501,     0,     0,   486,     0,     0,     0,   499,
       0,  1323,     0,   500,     0,  1007,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1166,     0,     0,     0,     0,
     502,     0,  1167,   499,  1168,     0,     0,   500,     0,     0,
       0,     0,   498,     0,  1169,     0,     0,     0,   503,   501,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,   500,  1008,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1170,   501,     0,     0,     0,   502,     0,     0,
    1171,     0,     0,     0,     0,     0,  1011,   496,     0,     0,
     497,     0,     0,     0,     0,   503,     0,   501,     0,     0,
       0,   502,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1172,     0,   503,
     493,   494,   495,     0,     0,   502,     0,     0,     0,   504,
       0,     0,     0,     0,   496,     0,  1139,   497,     0,     0,
       0,  1173,     0,   503,     0,     0,  2416,     0,     0,     0,
       0,     0,     0,     0,     0,  1316,  1317,  1318,     0,     0,
       0,   283,  1319,  1320,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1321,  1322,   504,     0,  1174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1175,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     498,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   504,   499,     0,     0,     0,   500,
       0,   481,   482,   483,   484,   485,     0,     0,     0,     0,
    2417,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   486,     0,     0,     0,     0,   498,  1323,   496,
       0,     0,   497,     0,   486,   501,   505,     0,     0,     0,
       0,     0,   499,     0,     0,     0,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1176,  1177,  1178,
     505,     0,     0,   502,     0,     0,     0,     0,     0,     0,
    1179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,   501,     0,     0,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     502,  1324,     0,     0,     0,  1180,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   486,     0,     0,   503,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,  1325,     0,     0,  2418,     0,     0,     0,   493,
     494,   495,   498,  1139,     0,     0,     0,  2419,  1327,     0,
       0,     0,   504,     0,     0,     0,     0,   499,     0,     0,
       0,   500,     0,  1181,  1316,  1317,  1318,     0,     0,     0,
     283,  1319,  1320,    39,     0,  1719,     0,     0,     0,  1182,
       0,     0,     0,  1321,  1322,     0,     0,     0,  1328,     0,
       0,     0,     0,     0,     0,     0,     0,   501,     0,   504,
    1329,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   487,   488,   489,   490,   491,   492,   505,     0,
       0,     0,     0,     0,     0,   502,     0,     0,     0,     0,
     493,   494,   495,     0,     0,     0,     0,     0,     0,     0,
     486,  1330,     0,   503,     0,     0,     0,  2417,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,   496,  1323,     0,   497,
       0,     0,     0,     0,  1331,     0,     0,     0,   496,     0,
    1332,   497,     0,     0,     0,     0,     0,     0,     0,  1333,
    1334,     0,  1335,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1336,  1337,     0,     0,     0,     0,
       0,     0,  1338,     0,     0,  1339,     0,     0,     0,     0,
       0,     0,     0,   304,   504,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,   487,   488,   489,
     490,   491,   492,     0,     0,     0,     0,     0,  1324,     0,
       0,     0,     0,     0,     0,   493,   494,   495,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,   496,
       0,     0,   497,     0,     0,     0,     0,  2929,  2930,  1325,
       0,     0,  2418,   283,  1319,  1320,    39,     0,     0,   498,
     505,     0,  1139,     0,  2419,  1327,  1321,  1322,     0,     0,
       0,   498,     0,     0,   499,  1316,  1317,  1318,   500,     0,
       0,   283,  1319,  1320,    39,     0,   499,     0,     0,     0,
     500,     0,     0,     0,  1321,  1322,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1328,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,  1329,     0,     0,
       0,     0,     0,     0,     0,     0,   501,     0,     0,   487,
     488,   489,   490,   491,   492,     0,     0,     0,     0,     0,
       0,     0,   502,     0,     0,     0,     0,   493,   494,   495,
    2931,     0,     0,     0,   502,     0,     0,     0,  1330,     0,
     503,     0,   498,     0,   496,     0,     0,   497,     0,     0,
       0,     0,   503,     0,     0,     0,     0,   499,  1323,     0,
       0,   500,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1331,     0,     0,  1316,  1317,  1318,  1332,     0,     0,
     283,  1319,  1320,    39,     0,     0,  1333,  1334,     0,  1335,
       0,     0,     0,  1321,  1322,     0,     0,   501,     0,     0,
       0,  1336,  1337,     0,     0,     0,     0,     0,     0,  1338,
    1006,     0,  1339,     0,     0,     0,     0,     0,     0,     0,
     304,   504,     0,     0,     0,   502,     0,     0,     0,  1316,
    1317,  1318,     0,   504,     0,   283,  1319,  1320,    39,     0,
       0,     0,     0,   503,     0,     0,     0,  1324,  1321,  1322,
       0,     0,     0,     0,     0,  1139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   496,   498,     0,   497,
       0,     0,     0,     0,     0,     0,     0,  1323,  1325,     0,
       0,  1326,   499,  1139,     0,     0,   500,   505,     0,     0,
       0,     0,     0,     0,  1327,     0,     0,  1318,     0,   505,
       0,   283,  1319,  1320,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1321,  1322,     0,     0,     0,     0,
       0,     0,   501,     0,   504,     0,     0,     0,     0,     0,
       0,     0,  1323,  2252,  1328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1329,     0,     0,     0,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1330,     0,   498,
     505,     0,     0,     0,     0,     0,     0,     0,  1323,     0,
       0,     0,  1139,     0,   499,     0,     0,     0,   500,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1331,     0,     0,     0,     0,     0,  1332,     0,     0,     0,
       0,     0,     0,     0,     0,  1333,  1334,     0,  1335,     0,
       0,     0,     0,     0,   501,     0,     0,     0,     0,   504,
    1336,  1337,     0,     0,     0,     0,     0,  1139,  1338,     0,
    1324,  1339,   206,     0,     0,     0,     0,     0,     0,   304,
       0,     0,   502,   207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1324,     0,
     503,  2932,     0,     0,  2933,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2934,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,  1325,
       0,     0,  1326,  1139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2936,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,  2937,
       0,     0,     0,     0,     0,     0,   209,   210,     0,     0,
       0,   504,     0,     0,  3376,  1328,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2938,     0,     0,     0,     0,     0,     0,  1324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2284,
    2285,  2286,  2287,  2288,  2289,     0,     0,     0,  1330,     0,
       0,     0,     0,     0,     0,     0,     0,   505,  1325,  2939,
       0,  1326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2940,     0,     0,  1327,     0,     0,     0,     0,     0,
       0,  1331,  2049,  2941,  2942,     0,     0,  1332,     0,     0,
       0,  2943,     0,     0,  2944,     0,  1333,  1334,     0,  1335,
       0,     0,   304,     0,     0,     0,     0,     0,     0,     0,
       0,  1336,  1337,  1325,  1328,     0,  1326,     0,     0,  1338,
       0,     0,  1339,     0,     0,     0,  1329,     0,     0,  1327,
     304,     0,     0,     0,     0,     0,  2290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   212,  1330,     0,  1328,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1325,
       0,  1329,  1326,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1327,     0,     0,     0,     0,
    1331,     0,     0,     0,     0,   213,  1332,     0,     0,     0,
       0,     0,     0,     0,     0,  1333,  1334,     0,  1335,     0,
       0,     0,  1330,     0,   214,   215,   216,   217,     0,     0,
    1336,  1337,     0,     0,     0,  1328,     0,     0,  1338,     0,
    3346,  1339,   218,     0,     0,     0,     0,  1329,     0,   304,
       0,     0,     0,     0,     0,  1331,     0,     0,     0,     0,
       0,  1332,     0,     0,   219,     0,     0,     0,     0,     0,
    1333,  1334,     0,  1335,     0,     0,   220,     0,     0,     0,
       0,     0,     0,     0,     0,  1336,  1337,   221,  1330,     0,
       0,     0,     0,  1338,     0,     0,  1339,  3347,     0,     0,
       0,     0,     0,   222,   304,     0,     0,     0,     0,     0,
       0,     0,     0,   223,     0,     0,     0,     0,     0,     0,
       0,  1331,  3348,     0,     0,     0,     0,  1332,   224,     0,
       0,  3349,     0,     0,     0,     0,  1333,  1334,     0,  1335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1336,  1337,     0,     0,     0,     0,     0,     0,  1338,
       0,     0,  1339,     0,     0,     0,     0,     0,   225,  3350,
     304,     0,  2291,     0,     0,     0,     0,  3351,     0,     0,
       0,     0,     0,     0,     0,  2292,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,     0,     0,   228,     0,     0,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,     0,
       0,   231,     0,     0,     0,     0,     0,  2293,     0,     0,
       0,     0,     0,  2294,     0,     0,     0,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,  3352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2296,     0,     0,     0,
     234,     0,     0,     0,     0,     0,  2297,  2298,     0,     0,
       0,     0,  2299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2301,     0,     0,  2302,  2303,     0,
       0,     0,  2304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2305,
       0,     0,     0,     0,     0,     0,     0,     0,  3353,     0,
    2306
};

static const short yycheck[] =
{
       3,     4,     5,     6,   178,   671,     9,    10,   404,   197,
     112,  1154,  1489,  1196,  1019,    53,  1076,  1022,  1316,  1317,
    1404,  1169,   557,   612,   602,   813,    62,   605,  2239,  2047,
    1151,   654,  1165,  1166,   797,  1168,   583,  1170,  1171,   268,
     269,  1191,  1150,  1655,    47,  1786,   275,  1397,  2101,   772,
    2084,  1841,  2086,  1620,  1621,   133,   180,    60,   254,    62,
      98,  1789,  1780,  2395,  2638,  2639,  2640,   270,   271,     5,
      73,     5,  2283,    20,    27,    27,   178,    80,     5,  2099,
      27,  1721,    85,    27,    25,    88,    27,    27,     5,    92,
      93,     5,  1968,     8,  1351,   197,  1353,    26,    27,    19,
      33,    25,    48,    27,  2170,   117,    26,  1719,   111,     5,
     733,     9,     5,    36,    12,    13,    14,    15,    16,    17,
     736,   744,    27,  2641,   127,    27,  1247,   130,     5,   132,
     119,    77,     5,  2410,   137,  2412,    24,  1280,    26,    25,
    1261,    27,  2095,  2096,  2097,     5,    36,  2100,   272,    24,
      25,    26,   276,   119,   278,   329,   280,   281,   282,    20,
     815,    27,   240,   156,    25,   289,    27,   245,   246,   293,
     294,     5,     5,   119,     5,    20,   799,   123,   803,   802,
      25,    30,    27,   220,    27,    34,  1447,     5,   811,     5,
       5,  1251,    19,    42,   330,     5,   199,    24,    25,    26,
      24,    25,    26,    27,   737,    24,    25,    26,    27,    50,
    2163,  2637,  2638,  2639,  2640,    65,    27,   833,     5,    24,
      25,    26,    27,    25,    26,    27,  2724,   329,   761,   125,
       5,   127,   334,   129,     5,  1728,  1729,  1730,  1731,   485,
      24,    25,    26,    27,  1980,   248,     5,     9,  2358,    19,
      12,    13,    14,    15,    16,    17,    26,   260,   117,     5,
      53,    33,     5,   266,   267,   268,   269,   270,   271,    25,
      23,    27,   275,    27,   807,   206,   446,    25,   351,    27,
    1176,  1177,    23,   132,   817,   199,   291,   820,   234,   402,
       0,   824,   142,   143,  1934,  2279,    25,   830,    27,   832,
     194,   195,   485,   144,   145,    98,    27,   102,   103,   104,
     105,   106,   245,   246,    25,   206,    27,   246,   461,   322,
     323,   445,   138,   139,   448,    39,    40,  2345,   331,   448,
     333,    24,    25,    26,    27,   513,  1444,     5,   550,   448,
     528,   465,   466,   467,   468,   230,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   592,     5,  2418,   707,   708,   219,     5,
     566,   712,   713,   497,   498,     5,  2329,     5,   502,     5,
     504,   147,  2172,   612,   725,    27,  2339,  1150,   716,   219,
      25,     5,    27,   517,   518,   519,   520,   592,   676,   977,
       5,   525,  1552,   330,   745,  1789,     5,   748,   678,     5,
       5,   484,   424,   754,     5,   448,   362,   758,  1768,     5,
     594,   762,   246,    31,   630,   766,   528,   246,  1488,   770,
     771,   701,   773,   679,     5,   776,    30,   778,   779,   780,
      34,   246,   327,   292,     5,   786,   641,    25,   789,    27,
     300,   600,   730,     5,   782,   796,    26,     5,  1935,     5,
    2022,     5,   803,  2025,   670,   411,   412,   413,     5,   810,
       5,     5,     5,  1429,   246,     5,    29,   689,   111,   112,
     821,  2434,   670,    28,   825,   193,   622,   448,   829,     5,
     246,     5,   594,     6,   835,   673,   679,   838,   246,   330,
       6,     5,     5,  2929,  2930,   219,   495,  2933,   141,   142,
     143,    19,     5,   516,     6,   520,   110,   246,    26,   480,
     558,   559,   671,   117,   643,     5,     5,   432,   448,     5,
     428,   429,     5,     5,   643,   246,   649,   290,     5,     5,
       5,   407,   712,   665,     5,  3167,     5,  1202,   551,   290,
     553,   402,   670,   246,   559,  1088,  3178,  1818,   561,  1820,
    1215,   790,   707,   708,   413,   424,   207,    27,   670,   163,
     164,     5,   402,     5,   611,   578,   451,   580,    18,    19,
      20,    21,    22,  2076,  2537,   483,  2570,  3085,   591,   592,
       5,  2327,   595,  2611,     5,   485,   407,   491,   411,     5,
     745,   547,   207,   748,   481,   808,   809,   596,  2175,   612,
     643,   563,   461,   758,    27,   517,   431,   762,    27,    27,
       5,   766,   512,   513,     5,     5,   555,   451,   773,    27,
     596,     5,     5,   778,   837,   780,   441,   840,   448,     5,
    2674,   786,     5,   492,   789,   391,  1542,   481,   481,   580,
     121,   796,  2863,   122,  1279,     5,   649,  3175,   803,   525,
    2713,     5,   673,  1196,    23,   810,   428,   429,   246,  1204,
    2623,  2882,   521,  1206,   607,  1208,   821,   448,   419,   608,
     825,  1444,     5,   569,   829,   575,   448,   604,   402,   580,
     835,   298,   607,   838,   481,   622,   442,   700,   701,   702,
     703,   704,   705,   706,  2316,   448,   709,   710,   711,  2986,
     615,   714,   610,   716,   607,     5,   719,   670,   721,   731,
     643,   483,  1870,   643,   665,  1391,     5,   730,  1451,  1307,
     670,  2607,  1310,  1311,  3160,   671,   541,   610,   741,   742,
    3166,  3167,  2483,  3169,  3170,  3171,  3172,  2465,   751,  1857,
     610,  1298,  3178,  2787,   757,  2789,   670,  2485,   451,  2779,
     763,   764,   765,  2147,   485,   558,   769,  2151,   720,   772,
    2836,   774,   775,   720,  2840,   671,   720,   593,   676,   782,
     448,   715,   785,   679,     5,   673,   604,   790,   791,  2809,
     793,   622,  2049,   722,   797,  1450,   720,   800,   673,  1920,
     643,  2363,  2325,   806,   665,   808,   809,  1462,  3140,   423,
     813,   814,   815,  1154,   525,   720,   819,  2927,  3392,   822,
     665,  2774,  3154,  2776,   827,   600,   676,     5,   726,   727,
     424,   834,   525,   836,   837,   607,   839,   840,   679,   842,
     843,   600,   637,   485,   304,   481,   673,    27,   610,   673,
     485,   481,   448,   481,   673,   481,  2113,  2114,  2968,    10,
     568,   330,   448,   665,   680,  2008,  3292,    27,   673,  3295,
    3296,  3297,  3298,   643,   630,   604,   509,   448,   448,     5,
      27,    41,   481,   732,   598,  1009,   481,   448,  1012,   673,
     481,   639,   301,   301,   508,  1019,   448,  1021,  1022,  1904,
     448,  1297,   448,   301,   448,   314,   314,   485,  1864,     5,
     524,   448,   446,   448,   676,   448,   314,   631,   448,  1452,
    1453,  1454,   411,   292,  3135,   519,   692,   693,   694,   695,
     696,   290,   448,   402,   448,   448,  1469,  1278,  1279,  1280,
     448,    27,   448,   946,   448,   448,   994,   407,  2982,   382,
    2984,  2985,  2519,   567,  3286,   448,   448,  3383,    25,     5,
      27,  2914,   595,    30,   726,   727,  3392,  1590,   448,   448,
     733,  2924,   448,   444,   397,   448,   448,   446,  3012,  2953,
     673,   448,   448,   448,    13,  1574,   399,   448,  2702,   448,
    2704,   994,   606,  2707,   407,   408,   467,  2637,  2638,  2639,
    2640,    27,   162,   397,   397,   638,   448,   416,   416,  1154,
    1543,   893,    26,    27,   448,  3068,   448,   611,   416,   432,
     966,   635,   435,   417,  3285,   382,  1561,   513,  3289,  1562,
     644,   448,   416,   448,  1037,    64,  1039,   448,   451,    26,
      27,   481,   448,    18,    19,    20,    21,    22,  1581,    30,
     485,   211,   416,    34,  3007,    25,   448,    27,   448,  1592,
     419,    42,    25,   448,    27,   525,   246,   448,   448,   352,
    1073,    14,   730,  1076,   448,   448,   485,   485,   513,   550,
     592,   364,   448,   301,  1030,   448,   246,   525,   248,  1092,
    2613,  2614,  1095,   751,  1857,   533,   314,   691,   448,   246,
     375,  2485,   535,   513,   448,   699,   764,  2457,  1304,   220,
      25,   222,    27,  2263,    25,   485,    27,  1695,    26,    27,
    1698,   530,   530,   492,   576,   448,  3144,  3180,    25,   641,
      27,  1134,   530,  1278,  1279,  1280,  1139,   546,   546,  2396,
    2200,  2398,   555,  2400,    26,    27,   530,  1150,   546,   485,
      25,   132,    27,   622,   305,   513,     5,   304,   448,     8,
     246,  1164,  1165,  1166,   462,  1168,   530,  1170,  1171,   448,
       0,   642,   214,  1176,  1177,    28,    29,   513,   535,   246,
     338,  3155,  3156,   654,   655,   345,  1809,    25,  2331,    27,
    1978,   662,    22,   351,  3147,   608,   485,   389,   416,  1202,
     232,   643,   615,    18,    19,    20,    21,    22,   553,   632,
    1213,   513,  1215,   339,  2357,   326,   561,    25,   329,    27,
     246,  1224,    26,    27,  1227,   292,   643,   448,    25,  1232,
      27,   592,   246,   702,   703,   704,  1465,   301,   632,   632,
     351,    26,    27,   339,   713,   678,   485,  1902,  1251,  1252,
     314,   643,   485,   643,   414,   639,    25,  1260,    27,   246,
    1463,   441,   422,   673,   697,   698,   426,   485,    25,    25,
      27,    27,   314,  1276,  1277,   639,   246,  1893,  1326,  1812,
     641,   485,  2993,   246,   717,  2996,  3000,  3240,  2999,  2929,
    2930,  1173,   443,  2933,   445,  1828,  3273,  3274,  3275,  1181,
    1303,   480,   462,  1477,  2916,  3339,   262,   263,   264,   485,
     352,   292,   530,  1316,  1317,   673,  1394,  1972,  1396,   351,
     485,   678,  1855,  1326,  2097,   357,   484,  2100,   546,  1862,
     535,   246,    19,   485,   780,   246,  1339,    24,   246,    26,
     697,   698,   485,   789,  1347,  1574,   413,   512,   338,   246,
     485,  1886,   416,   651,  2994,   441,   654,  2997,    20,  1892,
     717,   351,   485,   643,   246,    27,  1569,  1570,   528,   643,
      24,   246,    26,   484,   416,  1477,   568,   512,   513,  1912,
    2501,   485,  2859,  1419,  3361,   665,  3363,   579,   430,   835,
     672,   665,   838,   485,   513,  1398,  2579,   679,  2546,  1402,
    1403,  1404,   643,  2701,  2702,   678,  2704,   567,   246,  2707,
     485,  1414,  1415,  1416,  1617,  1618,  1419,  1420,  1421,  1422,
    1423,  1424,  2543,   485,   665,   492,    20,   700,   701,    20,
    1433,   591,   413,    27,   485,  2819,    27,    20,   246,    26,
     575,  1444,   246,  1446,    27,  1448,   678,  1450,  1451,   246,
     485,    20,    21,  2603,   521,  1458,  1459,  1460,  2036,  1462,
    1463,   246,  1465,  1466,  2042,  2043,   530,    20,   700,   701,
     485,  1474,  2933,   678,    27,   635,   485,   246,  1481,  1482,
     461,   220,   546,   222,   644,  1488,  1489,   821,   530,   246,
    2967,   825,   697,   698,   484,   829,  3207,  2152,    26,   455,
      20,  2156,    20,   485,   546,  1846,   481,    27,   247,    27,
    2165,   492,   717,   485,    47,    48,    49,   485,  3158,    52,
    3160,    54,    55,   485,   643,  2148,  3166,  3167,   485,  3169,
    3170,  3171,  3172,   485,   423,  2190,  1539,  1540,  3178,  1542,
     521,   485,  1545,  1546,    20,   220,   665,   222,   485,  2554,
      24,    27,    26,  3343,   673,    19,   485,  2562,  2563,  2564,
      24,    25,    26,   493,  1567,   485,  1569,  1570,   728,   729,
    3360,  1574,   247,  1576,   504,  1578,  1579,  1580,  2201,   148,
     149,   150,   151,   152,   153,   294,  1331,   326,  1333,  1334,
     329,   836,   294,   748,   839,   525,    25,   842,    27,   223,
     485,  1604,   532,    25,   294,    27,   485,   762,  2141,  1687,
     540,   766,   351,  1616,  1617,  1618,   723,   724,   725,   508,
    1623,  1624,  3412,   778,  2157,  2158,  2159,  2160,  2251,    25,
    1754,    27,   562,   448,  1975,   524,    24,    25,    26,  3429,
    1643,  1644,   351,  1646,  1647,  2178,   513,  1650,  1651,   351,
    1653,   326,  3292,  1656,   329,  3295,  3296,  3297,  3298,   485,
    1863,   351,  3139,   166,   167,   168,  3159,  2008,  3161,  3162,
    3163,  3164,   423,  1721,    26,  1723,   351,  1680,   567,  1174,
    1175,  3321,   485,  1178,  1179,  1733,  1734,   393,  1691,    25,
     485,    27,  1740,  1741,  1742,  1743,   405,    26,   404,  3160,
     409,  1846,  3000,   405,    26,  3166,    25,   409,  3169,  3170,
    3171,  3172,  2245,   679,    24,   405,    26,   606,  1721,   409,
    1723,   679,   423,  1952,  1953,    18,    19,    20,    21,    22,
    1733,  1734,  1735,   673,    24,  1738,    26,  1740,  1741,  1742,
    1743,    26,   423,  3383,    26,   484,   635,    25,   454,    27,
    1753,    25,  3392,    27,    25,   644,    27,   508,   580,    18,
      19,  1885,   468,   485,  1967,    24,    25,    26,    27,    24,
     485,    26,  1775,   524,    24,   484,    26,  1780,    37,    38,
    1904,   485,   484,  1786,    26,   692,  1789,   485,   695,   696,
      25,   485,    27,   326,   484,    24,   329,    26,   331,  2480,
    2378,   512,   513,  2381,  1807,  2383,  2384,   508,  2868,   484,
    1813,   423,   436,   485,  1760,  2348,   567,  2350,   351,   666,
     667,   668,   669,   524,   693,   694,   450,   508,   361,   485,
    1975,  3292,   713,   485,  3295,  3296,  3297,  3298,    25,  1842,
      27,   158,   159,   524,   725,    24,  1446,    26,  1448,   382,
    2505,   557,   485,  1856,  1857,   606,   475,  1860,  1861,    25,
    1863,    27,   121,  2008,    39,    40,   567,  2872,   513,   493,
      39,    40,   405,   754,    26,  1878,   409,   512,   513,   485,
     504,  1929,   695,   696,   635,  2540,   567,    26,   118,   770,
     771,   702,   703,   644,    26,   776,   508,  1900,   779,  1902,
      26,   525,   702,   703,    26,   606,   343,   344,   532,  2475,
    2476,    26,   524,    26,   233,   673,   540,  2929,  2930,   115,
     418,  1924,  3383,  1926,  1927,   606,  1929,   448,   673,    26,
    1933,  1934,  1935,   448,   635,   485,   485,   481,   562,  3089,
       5,   448,   485,   644,   423,    20,    21,   448,  3098,  1952,
    1953,   484,   448,   448,   635,   567,  2637,  2638,  2639,  2640,
     448,   448,   192,   644,  1967,  3115,   525,   679,   485,  1972,
    1973,  1974,    20,    20,   485,  1978,   485,   448,  2511,     5,
     485,  2514,   513,  1986,  2325,   485,   677,   246,    26,   673,
    2331,    26,   448,   448,   606,   481,   314,   996,   418,  2047,
     999,   709,  1001,  1002,  1003,  1004,  1005,    30,  2056,  2183,
    2013,  2059,  2060,  2061,  2062,   639,  2357,    20,  2021,  2022,
      26,   645,  2025,   635,   254,    26,   256,    26,    26,   508,
      26,    26,   644,   741,   742,   199,  3179,    26,   643,   203,
     643,   360,   272,   448,  2047,   524,  2579,   366,   367,   368,
     280,   448,    26,  2056,   284,   448,  2059,  2060,  2061,  2062,
    2063,   448,   448,  2066,    26,     5,   448,  2070,  2071,   388,
      20,  2074,    26,   148,   149,   150,   151,   152,   153,   309,
      26,  2183,   485,   673,    26,   793,   448,    26,   567,     5,
     192,   448,  2095,  2096,  2097,   679,    26,  2100,  2101,  2102,
     448,   358,  2105,   448,    47,   448,   448,   448,     5,   677,
     448,   448,  3262,  2729,  2730,  2731,   485,  2733,  2734,  2735,
    2736,  2737,  2738,   216,   679,    26,  2742,   606,   448,   643,
      26,  2134,   679,  2136,  2137,   448,  2139,  2140,   231,   232,
    2143,   192,    25,    25,  2147,    25,   448,   240,  2151,  2152,
      25,   448,   254,  2156,   256,   358,   635,   448,   677,  2162,
    2163,   448,  2165,  2166,   448,   644,  2169,  2170,   111,   112,
     272,  2826,   448,   448,   493,   448,   448,   496,   280,   448,
    2325,   274,   284,   448,   448,   504,  2331,  2190,   673,   485,
     283,   673,   451,   295,  2197,     8,   649,  2200,   678,  2854,
     481,   533,   322,   254,     5,   256,  2209,   309,   514,   671,
    2213,  3271,  2357,  3346,  3347,  3348,  3349,  3350,  3351,   312,
     539,   272,  3372,   482,   671,   649,   485,   475,   514,   280,
     673,   712,   665,   284,   712,   178,  2239,   384,   673,   498,
     650,     5,    18,    19,    20,    21,   513,   475,  2929,  2930,
       5,   485,  2933,   485,   197,   574,   402,   632,   309,   485,
     485,  2264,   485,     8,   357,    14,   629,     5,   712,     5,
     712,   475,  2613,  2614,   593,   594,   485,   485,   537,   538,
      26,   122,    26,   147,   673,   604,    18,    19,    20,    21,
     609,   550,   513,    26,   643,   485,   485,  2345,   475,   485,
     485,   485,   485,   485,   485,    26,   513,     5,   401,   649,
       5,  2314,   485,  2994,  2847,   485,  2997,   485,   679,    50,
     485,   679,   678,   266,   715,   408,  2329,   610,     5,   648,
      18,   670,   591,    19,  2337,  2338,  2339,   209,  2376,  2342,
    2343,   448,  2345,    25,   440,   643,   676,  3013,   536,   673,
       5,  2884,   632,   600,  2402,  2358,  2359,  3362,   536,  2362,
    2363,   680,  2536,   207,  2593,  1073,  2595,   600,    26,   455,
    2418,   630,   148,   149,   150,   151,   152,   153,   600,   322,
     323,  2429,   379,   642,    26,  1288,   329,  1095,   448,    26,
    2578,   334,    20,    21,    22,   654,   655,   525,  2976,  2402,
    2978,  2979,   448,   662,   448,   448,   665,  2410,   580,  2412,
    2413,   679,   673,  2416,   673,  2418,   148,   149,   150,   151,
     152,   153,   485,    51,   448,  2549,  2429,   679,   448,   485,
    2554,  2434,  2435,  2436,  2536,  3495,   485,  3092,  2562,  2563,
    2564,   114,     5,   485,  2447,   485,   673,   717,   643,   673,
     643,   600,   485,   670,   448,  3110,     5,     5,     5,   679,
       5,   673,  2465,   537,   679,   678,   633,   485,  2613,  2614,
       5,     8,    26,    26,   122,   375,  2578,   274,   383,  3160,
    2483,     5,  2485,     5,   448,  3166,  3167,   650,  3169,  3170,
    3171,  3172,   485,   485,   485,  2498,   417,  3178,    14,   679,
     604,   600,  2505,   130,   131,     5,   133,   134,   135,    26,
     156,   713,   485,   673,   485,   600,  3197,   679,     5,   678,
     148,   149,   150,   151,   152,   153,   679,  2530,   678,  2532,
     481,  2534,  2580,   448,  2537,  2538,   692,  2540,   166,   167,
     168,   448,     5,     5,   448,     5,   425,   672,    26,   389,
     481,   485,  2555,   485,  2557,  2558,  2559,   515,   515,   485,
     485,  3094,   485,  2611,     5,   485,   485,   485,   673,     5,
    2573,   735,   736,   516,     8,   673,   513,  2580,   673,  2975,
       5,   383,   607,    25,   402,   528,  2637,  2638,  2639,  2640,
    2593,   630,  2595,   402,   673,   402,   513,  3130,  3253,   485,
     417,   513,  2605,  2606,   480,   232,     5,     5,  2611,    26,
     704,  3292,    25,   240,  3295,  3296,  3297,  3298,     5,     5,
    2623,    26,    14,    14,   485,   670,   607,   649,   649,     5,
       5,    26,    25,   485,  2637,  2638,  2639,  2640,  2641,  2642,
    3321,  2844,   679,   448,   448,   448,     6,   274,  2651,   448,
     448,   594,     7,  2656,  2857,   502,   283,   324,   448,   448,
       5,  2709,   673,    26,  2838,    26,   679,    26,    26,   833,
      26,   673,  2417,   673,  2419,   448,    20,   305,     5,   843,
     308,   330,   620,     5,     5,   312,   313,   600,     5,  2692,
    2693,   721,     8,     5,   448,   673,   625,   448,  2701,  2702,
     485,  2704,  3383,   525,  2707,     5,  2709,   679,   600,     5,
    2713,  3392,   679,   448,   677,   267,  1424,    26,   448,   448,
     679,     5,   485,   679,   679,  1433,   485,   670,     5,   501,
     357,   679,   677,  3074,    25,    25,  2838,    25,  3316,  3317,
      25,   352,    25,  3084,   672,    26,    26,    26,  2872,   448,
    2753,    26,  1460,    26,    26,   448,    26,   700,   701,   702,
       5,   704,  2765,   448,   448,   485,   522,     5,   485,   448,
     604,  2774,  2775,  2776,   401,  1678,  1679,     8,   721,    26,
     481,   296,  1685,    25,   448,   448,   495,   402,    20,   198,
       5,   607,     5,   485,   485,   485,   485,  2800,   485,   267,
     428,   448,   485,    14,   485,   448,     5,   513,    26,  2812,
    2813,   485,   448,  2816,   757,   443,  2819,    26,   496,   447,
     763,    26,   765,  2826,  3357,   448,   769,   448,   455,   772,
     994,    26,   775,  2836,    26,    26,  2839,  2840,  3179,   431,
     233,  2844,   785,   622,    26,   448,   296,   448,   448,   448,
     485,  2854,   175,   297,  2857,   483,  2859,   800,   402,  3088,
     513,   495,   448,   806,    14,  2868,   600,   485,   448,   448,
     813,   814,   815,     7,   295,   295,   819,    26,  2929,  2930,
     448,   448,  2933,   511,   827,   679,   673,   449,   485,   448,
     629,   448,  2637,  2638,  2639,  2640,    26,   485,   481,    25,
     843,   529,   448,   297,   513,  2908,   448,   448,   448,   448,
       5,  2914,  1076,    26,    26,   448,   673,     5,   448,    26,
    2923,  2924,  2498,  2926,  2927,   673,  2929,  2930,  3461,  3422,
    2933,   481,   673,  2557,  1021,  2235,  1644,  1913,  1646,  1647,
    1582,  2944,  1650,  1651,    35,   481,   689,    37,  1656,  2166,
    2530,   362,  2172,   119,   277,  3003,   123,  3005,  2703,   214,
    2705,   674,   285,   353,  2967,  2968,  1759,   360,   291,  1760,
     293,   547,   391,   366,   367,   368,   219,   615,   363,  3412,
    1315,   304,   610,  2986,   392,   578,   580,  1812,   819,   427,
    1285,  2994,  1895,  1012,  2997,   388,  2019,  3000,  2026,  1862,
    3003,  1616,  3005,  2159,  3007,  2582,  1619,  2894,  1942,   332,
    2260,  3466,  2162,  1962,  1465,  3106,    22,    98,    47,    47,
    2376,    28,  1918,   775,   948,   348,  1924,  1735,  3031,  1593,
     353,   334,  1039,  1927,  3179,  1938,  1624,  3031,  1540,  3216,
     800,  1252,   365,  1459,  1538,  3429,  1448,  3226,   676,   372,
    2768,  2580,  1562,  1892,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   464,  3068,  2766,  2751,  2446,  2824,
    3086,  3084,    47,    48,    49,  3077,  2816,    52,  2151,    54,
      55,  2105,  1792,  1775,  3438,  3088,  3007,  1251,  2325,  3092,
    3278,  1658,   485,  1658,  2926,  2344,  3144,  1997,  2773,  3240,
     493,  2807,  2066,   496,  2692,  1985,  2693,  3110,  2416,  3160,
    3158,   504,  3321,  2997,  2795,  3166,  3167,  2468,  3169,  3170,
    3171,  3172,  2447,  3049,    47,    48,    49,  3178,  2413,    52,
    1643,    54,    55,  1076,   622,     9,  3139,  3484,  1281,  2435,
    2928,  3144,  2436,  2624,  3147,  1734,   539,  3005,  1856,  1092,
    3282,  1733,  1316,  1317,  1638,  3158,  1277,  3160,  2923,  3158,
    3177,  2338,  1326,  3166,  3167,  1611,  3169,  3170,  3171,  3172,
    3166,  2538,  3175,  1753,  3177,  3178,  3278,  3180,  1139,  1482,
    1474,   574,  2536,  2183,  2929,  2930,   556,  1464,  2933,    -1,
      -1,  1134,    -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,
     593,   594,   525,    -1,    -1,    -1,    -1,    -1,    -1,   532,
      -1,   604,    -1,  3216,    -1,    -1,   609,    -1,  3221,    -1,
    3223,  1164,  1165,  1166,    -1,  1168,    -1,  1170,  1171,    -1,
      -1,   554,    -1,  1176,  1177,    -1,   559,  3240,  3362,    -1,
    3288,  3292,    -1,    -1,  3295,  3296,  3297,  3298,    -1,    -1,
    3253,    -1,    -1,    -1,    -1,   648,    -1,    -1,    -1,  1202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3271,    -1,
      -1,    -1,  1215,    -1,    -1,    -1,    -1,  3325,  1986,  3282,
      -1,    -1,    -1,    -1,  1227,  3288,    -1,   680,    -1,  3292,
      -1,    -1,  3295,  3296,  3297,  3298,    -1,  3300,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,  1251,  1252,
      -1,  3314,    -1,    -1,    -1,    -1,    -1,  1260,  3321,    -1,
      -1,    22,  3325,    -1,  1488,    -1,  2229,  2230,    -1,    -1,
      -1,    -1,  3383,  1276,  1277,    -1,    -1,  2240,    -1,    -1,
      -1,  3392,    -1,  3346,  3347,  3348,  3349,  3350,  3351,    -1,
      51,   326,    -1,    -1,   329,  3358,   331,    -1,  2066,    -1,
      -1,    -1,  2265,  2266,  2267,  2268,  2269,  2270,    -1,    -1,
      -1,    -1,  2275,  2276,  2277,  2278,   351,    -1,    -1,  2282,
    3383,    -1,    -1,    -1,    -1,    -1,   361,    -1,    -1,  3392,
    3438,    18,    19,    -1,    -1,   154,    -1,    -1,    -1,    26,
      27,    -1,    -1,   326,    -1,    -1,   329,   382,   331,    -1,
      -1,    -1,    -1,    -1,    41,  3160,    -1,    -1,    -1,    -1,
      -1,  3166,  3167,    -1,  3169,  3170,  3171,  3172,   351,    -1,
     405,    -1,    -1,  3178,   409,  3438,    -1,  3440,   361,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,  2162,    -1,    -1,    -1,    -1,   382,
    1624,  2364,  2365,    -1,    -1,   166,   167,   168,  2371,  2372,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3482,
    3483,  3484,   405,    -1,    -1,    -1,   409,    -1,    -1,   116,
      -1,    -1,  3495,    -1,  3497,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,  1446,    -1,  1448,    -1,  1450,  1451,   484,
      -1,    -1,    -1,    -1,    -1,  1458,  1459,    -1,    -1,  1462,
      -1,    -1,    -1,  1466,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,  1477,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1488,  1489,  3292,    -1,    -1,
    3295,  3296,  3297,  3298,    -1,    -1,    -1,  1721,    -1,  1723,
      -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1733,
    1734,    -1,    -1,    -1,    -1,    -1,  1740,  1741,  1742,  1743,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1539,  1540,    -1,  1542,
      -1,    -1,  1545,  1546,   305,    -1,  2314,   308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2520,  2521,   246,
      -1,   248,    -1,    -1,    -1,    -1,  2529,    -1,    -1,    -1,
      -1,   390,    -1,  1576,    -1,  2343,    -1,    -1,  3383,    -1,
      -1,    -1,    -1,    -1,   403,    -1,    -1,  3392,    -1,    -1,
      -1,  2359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1604,    -1,    -1,  2567,  2568,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
    1623,  1624,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,  2594,    -1,  2596,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,  2410,    -1,  2412,    -1,   465,    -1,    -1,    -1,
      -1,    -1,   471,    18,    19,    20,    -1,    -1,   345,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   428,    -1,  1893,
      -1,    -1,    37,    38,    -1,    -1,    -1,  1680,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,   447,    -1,    -1,    -1,
      -1,   510,    -1,   380,  2657,  2658,    -1,    -1,  2661,  2662,
      -1,    -1,    -1,    -1,    -1,  1929,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   534,   116,    -1,    -1,    -1,
      -1,   121,   483,    -1,    -1,   544,   545,   414,   128,    -1,
      -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,
      -1,   560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    -1,    -1,    -1,    -1,   155,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   582,    -1,    -1,   585,   586,   529,    -1,
    2538,   590,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2047,    -1,    -1,    -1,    -1,   647,    -1,
      -1,    -1,  2056,    -1,    -1,  2059,  2060,  2061,  2062,   658,
      -1,    -1,    -1,    -1,    -1,    -1,   246,  2071,   248,   610,
      -1,    -1,    -1,    -1,    -1,   542,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,  2837,  1878,    -1,  2101,  2841,    -1,
     567,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,  2860,    -1,  1902,
      -1,    -1,    51,    -1,   591,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   676,    -1,  2880,    -1,    -1,
      -1,  1924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1933,    -1,  1935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,   635,    -1,
     350,    -1,    -1,    -1,    -1,    -1,    -1,   644,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,  1972,
    1973,  1974,    -1,    -1,    -1,  1978,  2200,    -1,    -1,    -1,
     380,    -1,    -1,    -1,    -1,   350,    -1,   148,   149,   150,
     151,   152,   153,    -1,    51,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   166,   167,   168,    -1,    -1,
    2013,    -1,    -1,    -1,   414,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,  2800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   728,   729,    -1,   444,    -1,    -1,    -1,    -1,   449,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,
      -1,    -1,   482,    -1,    -1,   485,   451,    -1,   488,    -1,
      -1,   148,   149,   150,   151,   152,   153,   497,   498,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,   482,    -1,    -1,
     485,  2345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   497,   498,    -1,    -1,    -1,   537,   538,    -1,
      -1,    -1,   542,    -1,   305,    -1,    -1,   308,    -1,  2152,
     550,    -1,    -1,  2156,    -1,    -1,   305,    -1,    -1,   308,
      -1,   561,  2165,    -1,    -1,  3128,    -1,   567,  3131,    -1,
      -1,    -1,    -1,   538,    -1,    -1,    -1,    -1,  2402,    -1,
    2183,    -1,    -1,    -1,    -1,   550,    -1,  2190,    -1,    -1,
      -1,   591,  2416,    -1,  2418,    -1,    -1,  2200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2429,  2209,     9,    -1,    -1,
    2213,    -1,    -1,    -1,    -1,    -1,    18,    19,  2986,    -1,
      -1,    -1,    24,    25,    26,    27,   591,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   635,  2239,    -1,    -1,    41,
      -1,    -1,   642,    -1,   644,    -1,    -1,    -1,   305,    -1,
      -1,   308,    -1,    -1,   654,   655,  2480,    -1,    -1,   624,
      -1,    -1,   662,    -1,    -1,   630,    -1,   428,    -1,    -1,
      -1,    -1,    -1,   673,   639,   640,    -1,   642,    -1,   428,
      -1,    -1,   443,    -1,    -1,    -1,   447,    -1,    -1,   654,
     655,    -1,    -1,    -1,   443,    -1,    -1,   662,   447,    -1,
     665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   673,    -1,
      -1,    -1,    -1,  3276,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,   483,    -1,    -1,    -1,   128,    -1,   728,   729,
      -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
     511,    -1,    -1,   155,    -1,    -1,  2580,    37,    38,  2362,
      -1,    -1,   511,    -1,  3327,  3328,    -1,  3330,   529,  3332,
    3333,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     529,    -1,    -1,    -1,    -1,    -1,   443,  2611,    -1,    -1,
     447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2637,  2638,  2639,  2640,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,  2435,    -1,    -1,    -1,    -1,  3400,    -1,  3402,
      -1,   121,    -1,    -1,   246,    -1,   248,    -1,    -1,   610,
      -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
      -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,  2692,  2693,
      -1,    -1,   529,  3436,    -1,    -1,    -1,  2701,  2702,    -1,
    2704,    -1,    -1,  2707,    -1,  2709,    -1,    -1,    -1,  2713,
      -1,    -1,  3455,  3456,    -1,    -1,  3459,    -1,    -1,  3462,
      -1,    -1,  2505,    -1,    -1,  2729,  2730,  2731,    -1,  2733,
    2734,  2735,  2736,  2737,  2738,   676,    -1,    -1,  2742,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,
      -1,    -1,    -1,  2536,    -1,    -1,    -1,  2540,    -1,    -1,
      -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,   350,    -1,
      -1,    -1,  2555,   610,  2557,    -1,  2559,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
    2573,    -1,    -1,    -1,    -1,  2578,    -1,    -1,   380,    -1,
      -1,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,  2605,  2606,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,   676,
      -1,    -1,    -1,    -1,   426,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   444,    -1,  2868,    -1,    -1,   449,  2651,   451,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
     462,    -1,    -1,    -1,    -1,   467,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,    -1,    -1,
     482,    -1,    -1,   485,    -1,    -1,   488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2929,  2930,    -1,    -1,  2933,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,   537,   538,    -1,    -1,    -1,
     542,    -1,   166,   167,   168,    -1,    -1,    -1,   550,    -1,
    2753,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   561,
      -1,    -1,  2765,    -1,    -1,   567,    -1,    -1,     9,    -1,
    2994,   451,    -1,  2997,    -1,    -1,  3000,    18,    19,  3003,
      -1,  3005,    -1,    24,    25,    26,    27,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,   482,    -1,    -1,   485,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,    -1,
      -1,    -1,    -1,  2826,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   635,    -1,  2838,    -1,    -1,    -1,    -1,
     642,    -1,   644,    -1,  3068,   525,    -1,    -1,    -1,    -1,
      -1,  2854,   654,   655,    -1,    -1,  2859,    -1,   538,    -1,
     662,    -1,    -1,    -1,    -1,  2868,    -1,    -1,    -1,    -1,
     550,   673,    -1,    -1,    -1,   116,    -1,   246,    -1,    -1,
     121,   305,    -1,     9,   308,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   591,    -1,    -1,   155,    41,    -1,    -1,    -1,    -1,
    3144,    -1,    -1,    -1,    -1,    -1,   728,   729,    -1,    -1,
      -1,    -1,    -1,    -1,  3158,    -1,  3160,    51,    -1,    -1,
      -1,    -1,  3166,  3167,   624,  3169,  3170,  3171,  3172,    -1,
     630,    -1,    -1,    -1,  3178,    -1,  3180,    -1,    -1,   639,
     640,    -1,   642,    -1,  2967,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,  3197,   654,   655,    -1,    -1,    -1,    -1,
      -1,    -1,   662,    -1,    -1,   665,    -1,    -1,    -1,    -1,
     116,    -1,    -1,   673,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,   428,   246,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,  3031,   155,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3271,    -1,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,   483,
      -1,    -1,    -1,    -1,  3288,    -1,    -1,    -1,  3292,    -1,
      -1,  3295,  3296,  3297,  3298,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,   511,    -1,  3092,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3321,    -1,    -1,
      -1,  3325,    -1,    -1,   345,   529,    -1,  3110,    -1,   350,
      -1,    -1,    -1,   482,    -1,    -1,   485,    -1,    -1,    -1,
     246,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    -1,    -1,    -1,  3139,    -1,    -1,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,  3383,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,  3392,   538,
      -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,
      41,   550,    -1,    -1,    -1,   426,   610,    -1,    -1,    -1,
      -1,   305,    18,    19,   308,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,   444,    -1,    -1,    -1,   355,   449,    -1,
     451,    37,    38,  3216,  3438,    -1,    -1,    -1,  3221,   345,
    3223,   462,   591,    -1,   350,    -1,   467,   375,   376,   377,
      -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,    -1,
      -1,   482,    -1,    -1,   485,    -1,    -1,   488,    -1,    -1,
    3253,    -1,   676,    -1,   380,   116,   497,   498,    -1,    -1,
     121,   630,    -1,    -1,    -1,    -1,   414,   128,  3271,    -1,
      -1,  3495,    -1,   642,    -1,  3278,    -1,    -1,   426,    -1,
      -1,    -1,    -1,    -1,    -1,   654,   655,    -1,   414,   437,
      -1,    -1,    -1,   662,   155,   121,   665,   538,    -1,    -1,
     426,   542,    -1,    -1,   673,   453,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,   428,   463,    -1,    -1,   444,    -1,
     561,    -1,   563,   449,     5,   451,   567,    -1,    -1,   443,
     478,    -1,    -1,   447,    -1,    -1,   462,    -1,    -1,    -1,
      -1,   467,    -1,  3346,  3347,  3348,  3349,  3350,  3351,    -1,
     591,   477,    -1,    -1,    -1,    -1,   482,    -1,    -1,   485,
      -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   483,
      -1,   497,   498,    -1,    -1,    -1,    -1,    -1,   526,    -1,
      -1,    -1,    -1,    -1,    -1,   246,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,   635,    -1,    -1,   511,    -1,    -1,
      -1,   642,    -1,   644,    -1,    -1,    -1,    -1,   556,    -1,
      -1,   537,   538,   654,   655,   529,   542,    -1,   566,    -1,
     246,   662,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,
      -1,    23,   673,    -1,    -1,   561,    -1,    -1,    -1,   587,
      -1,   567,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      52,    -1,    54,    55,    -1,   591,    -1,    -1,    -1,    -1,
      -1,   619,    -1,    -1,    -1,    -1,   316,    -1,    -1,    -1,
     628,    -1,    -1,    -1,   345,    -1,    -1,   728,   729,   350,
      -1,    -1,  3495,    -1,    -1,    -1,   610,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,
      -1,    -1,    -1,    -1,    -1,   355,   642,    -1,   644,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   654,   655,
      -1,    -1,    -1,    -1,   374,   375,   662,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   673,    -1,    -1,
      -1,    -1,    -1,   414,    -1,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   676,    -1,    -1,   426,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,    -1,    -1,   426,    -1,   449,    -1,
     451,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,
     192,   462,   728,   729,    -1,    -1,   467,    -1,    -1,    -1,
      -1,    -1,    -1,   453,    -1,    -1,   477,    -1,    -1,    -1,
      -1,   482,    -1,   463,   485,   451,    -1,   488,   220,    -1,
     222,    -1,    -1,    -1,    -1,   316,   497,   498,   478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   482,    -1,    -1,   485,
      -1,    -1,   254,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   498,    -1,   355,   267,    -1,   538,   518,    -1,
     272,   542,    -1,    -1,    -1,    -1,    -1,    -1,   280,   550,
      -1,    -1,   284,   374,   375,    -1,    -1,    -1,   290,   525,
     561,   541,   294,   295,   296,   297,   567,    -1,    -1,    -1,
      -1,    -1,   538,    -1,    -1,    -1,   556,   309,    -1,    -1,
      -1,    -1,    -1,   563,   550,    -1,   566,    -1,    -1,    -1,
     591,    -1,    -1,   414,   326,    -1,    -1,   329,    -1,   331,
      -1,    -1,    -1,    -1,    -1,   426,   338,   587,    -1,    -1,
      -1,   591,    -1,    -1,    -1,    -1,   437,    -1,    -1,   351,
      -1,    -1,    -1,    -1,    -1,   591,    -1,    -1,    -1,   361,
     610,    -1,   453,    -1,   635,    -1,    -1,    -1,    -1,    -1,
      -1,   642,   463,   644,    -1,    -1,    -1,    -1,   628,    -1,
     382,   383,    -1,   654,   655,    -1,    -1,   478,    -1,    -1,
      -1,   662,    -1,    -1,   630,   397,    -1,    -1,    -1,    -1,
      -1,    -1,   673,   405,    -1,    -1,   642,   409,    -1,    17,
      18,    19,    20,    21,    22,   417,   418,   419,   654,   655,
      -1,    -1,    -1,    -1,    -1,    -1,   662,   518,    -1,   665,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   673,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
     541,    -1,    -1,    -1,    -1,    -1,    -1,   728,   729,    -1,
      -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      -1,    -1,   563,    -1,    -1,   566,    -1,    -1,    -1,    -1,
      -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   495,    -1,    -1,   587,    -1,    -1,    -1,
     591,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   610,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   535,    -1,    -1,    -1,   628,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,   166,   167,
     168,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,   596,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     632,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
     113,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     123,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   678,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,   161,    -1,
     692,   693,   694,   695,   696,   697,   698,   305,   700,   701,
     308,   174,    -1,   176,   177,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   717,   189,   190,   191,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,   200,    -1,   202,
     203,   204,    -1,    -1,    -1,    -1,    -1,   210,    -1,   212,
     213,    -1,   215,    -1,   217,   218,    -1,    -1,   221,    -1,
      -1,   224,   225,   226,   227,   228,   229,    -1,    -1,    -1,
     233,   234,   235,    -1,   237,    -1,    -1,    -1,   241,    -1,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,
      -1,    -1,   255,    -1,   257,    -1,   259,    -1,   261,    -1,
      -1,    -1,   265,   266,    -1,   268,   269,   270,    -1,    -1,
     273,   305,   275,   276,   308,   278,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
     428,    -1,    -1,    -1,    -1,    -1,   299,    -1,    -1,   302,
     303,    -1,    -1,   306,   307,   443,    -1,   310,   311,   447,
      -1,    -1,    -1,    -1,    -1,    -1,   319,   320,   321,    -1,
     323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     333,   334,   335,    -1,   337,    -1,    -1,    -1,   341,   342,
      -1,    -1,    -1,   346,    -1,   483,    -1,    -1,    -1,    -1,
      -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,
     363,   364,    -1,    -1,    -1,    -1,    -1,   370,   371,    -1,
      -1,    -1,    -1,   511,    -1,   378,    -1,    -1,   381,    -1,
      -1,    -1,   385,   386,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   529,    -1,   396,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
     413,    -1,    -1,   447,   448,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,   483,
      -1,    -1,    -1,   456,    -1,   458,   459,    -1,    -1,    -1,
      -1,    -1,    -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   610,    -1,    -1,    -1,    -1,   511,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   529,    -1,    -1,    -1,    -1,
      -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,
     523,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   676,    -1,
      -1,    -1,    -1,    -1,   547,   548,    -1,    -1,    -1,   552,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   564,    -1,    -1,    -1,    -1,    51,   570,   571,   572,
     573,    -1,    -1,    -1,   577,    -1,   610,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,   588,   589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,   601,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   612,
      -1,   614,    -1,    -1,   617,    -1,    -1,     6,     7,     8,
     623,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   676,    -1,    -1,    -1,   649,    -1,    -1,   652,
      -1,    -1,    -1,    -1,   657,    -1,    -1,   660,   661,    -1,
      -1,    -1,    51,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   675,    -1,    -1,    -1,    -1,    -1,    -1,   682,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   705,   706,   707,   708,   709,   710,   711,    -1,
      -1,   714,    -1,   716,    -1,   718,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   148,
     149,   150,   151,   152,   153,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     305,    -1,    -1,   308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    51,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
     166,   167,   168,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,   308,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,   447,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,
      -1,    -1,   308,    -1,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     305,    -1,    -1,   308,   529,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,   447,   448,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,
      -1,   308,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,    -1,   610,    -1,    -1,    -1,    -1,
     305,    -1,    -1,   308,    -1,    -1,    -1,    -1,    -1,    -1,
     529,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,   447,   448,   428,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,   447,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   676,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,   610,   166,   167,   168,   511,   443,    -1,    -1,    -1,
     447,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   529,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   529,    -1,   483,    -1,   443,    -1,
      -1,    -1,   447,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,
      -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,
      -1,   305,    -1,    -1,   308,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     676,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,   676,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,   610,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    51,    -1,   676,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    51,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      -1,   676,    -1,   447,   448,    51,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   529,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,   166,   167,   168,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   305,    -1,   610,   308,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   305,    -1,   188,   308,    -1,    -1,    -1,    -1,    -1,
      51,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,    -1,   676,   208,    -1,   305,    -1,    -1,   308,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,   305,
      -1,    -1,   308,    -1,    -1,    -1,    -1,    37,    38,    -1,
     148,   149,   150,   151,   152,   153,   251,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,   428,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,   447,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   166,   167,   168,    -1,    -1,
     315,    -1,   483,    -1,    -1,    51,    -1,    -1,    -1,   443,
      -1,   121,    -1,   447,    -1,   496,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,   340,    -1,    -1,    -1,    -1,
     511,    -1,   347,   443,   349,    -1,    -1,   447,    -1,    -1,
      -1,    -1,   428,    -1,   359,    -1,    -1,    -1,   529,   483,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,   447,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   387,   483,    -1,    -1,    -1,   511,    -1,    -1,
     395,    -1,    -1,    -1,    -1,    -1,   496,   305,    -1,    -1,
     308,    -1,    -1,    -1,    -1,   529,    -1,   483,    -1,    -1,
      -1,   511,   148,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,   529,
     166,   167,   168,    -1,    -1,   511,    -1,    -1,    -1,   610,
      -1,    -1,    -1,    -1,   305,    -1,   246,   308,    -1,    -1,
      -1,   456,    -1,   529,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,   610,    -1,   493,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,
      -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,    -1,
     610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   610,   443,    -1,    -1,    -1,   447,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
     350,    -1,   676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,   428,   121,   305,
      -1,    -1,   308,    -1,    51,   483,   676,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,   447,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,   603,   604,
     676,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,
     615,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   529,   483,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,   451,    -1,    -1,    -1,   660,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,    51,    -1,    -1,   529,    -1,
      -1,   148,   149,   150,   151,   152,   153,   166,   167,   168,
      -1,    -1,   482,    -1,    -1,   485,    -1,    -1,    -1,   166,
     167,   168,   428,   246,    -1,    -1,    -1,   497,   498,    -1,
      -1,    -1,   610,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,   447,    -1,   718,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,   525,    -1,    -1,    -1,   734,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,   538,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,   610,
     550,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   148,   149,   150,   151,   152,   153,   676,    -1,
      -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,   591,    -1,   529,    -1,    -1,    -1,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   676,   305,   121,    -1,   308,
      -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,   305,    -1,
     630,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   639,
     640,    -1,   642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   654,   655,    -1,    -1,    -1,    -1,
      -1,    -1,   662,    -1,    -1,   665,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   673,   610,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,   451,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,   305,
      -1,    -1,   308,    -1,    -1,    -1,    -1,    18,    19,   482,
      -1,    -1,   485,    24,    25,    26,    27,    -1,    -1,   428,
     676,    -1,   246,    -1,   497,   498,    37,    38,    -1,    -1,
      -1,   428,    -1,    -1,   443,    18,    19,    20,   447,    -1,
      -1,    24,    25,    26,    27,    -1,   443,    -1,    -1,    -1,
     447,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   538,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   483,    -1,    -1,   550,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,    -1,    -1,    -1,   166,   167,   168,
     121,    -1,    -1,    -1,   511,    -1,    -1,    -1,   591,    -1,
     529,    -1,   428,    -1,   305,    -1,    -1,   308,    -1,    -1,
      -1,    -1,   529,    -1,    -1,    -1,    -1,   443,   121,    -1,
      -1,   447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,    -1,    -1,    18,    19,    20,   630,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,   639,   640,    -1,   642,
      -1,    -1,    -1,    37,    38,    -1,    -1,   483,    -1,    -1,
      -1,   654,   655,    -1,    -1,    -1,    -1,    -1,    -1,   662,
     496,    -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     673,   610,    -1,    -1,    -1,   511,    -1,    -1,    -1,    18,
      19,    20,    -1,   610,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,   529,    -1,    -1,    -1,   451,    37,    38,
      -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   305,   428,    -1,   308,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   482,    -1,
      -1,   485,   443,   246,    -1,    -1,   447,   676,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    20,    -1,   676,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,   483,    -1,   610,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   537,   538,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,
     511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   591,    -1,   428,
     676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,   246,    -1,   443,    -1,    -1,    -1,   447,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     624,    -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   639,   640,    -1,   642,    -1,
      -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,   610,
     654,   655,    -1,    -1,    -1,    -1,    -1,   246,   662,    -1,
     451,   665,    32,    -1,    -1,    -1,    -1,    -1,    -1,   673,
      -1,    -1,   511,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
     529,   482,    -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,   482,
      -1,    -1,   485,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    -1,    -1,
      -1,   610,    -1,    -1,   537,   538,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     591,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,   591,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,   482,   630,
      -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   642,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,
      -1,   624,   451,   654,   655,    -1,    -1,   630,    -1,    -1,
      -1,   662,    -1,    -1,   665,    -1,   639,   640,    -1,   642,
      -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   654,   655,   482,   538,    -1,   485,    -1,    -1,   662,
      -1,    -1,   665,    -1,    -1,    -1,   550,    -1,    -1,   498,
     673,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   316,   591,    -1,   538,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   482,
      -1,   550,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,
     624,    -1,    -1,    -1,    -1,   355,   630,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   639,   640,    -1,   642,    -1,
      -1,    -1,   591,    -1,   374,   375,   376,   377,    -1,    -1,
     654,   655,    -1,    -1,    -1,   538,    -1,    -1,   662,    -1,
     258,   665,   392,    -1,    -1,    -1,    -1,   550,    -1,   673,
      -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,
      -1,   630,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
     639,   640,    -1,   642,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   654,   655,   437,   591,    -1,
      -1,    -1,    -1,   662,    -1,    -1,   665,   315,    -1,    -1,
      -1,    -1,    -1,   453,   673,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,   340,    -1,    -1,    -1,    -1,   630,   478,    -1,
      -1,   349,    -1,    -1,    -1,    -1,   639,   640,    -1,   642,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   654,   655,    -1,    -1,    -1,    -1,    -1,    -1,   662,
      -1,    -1,   665,    -1,    -1,    -1,    -1,    -1,   518,   387,
     673,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,    -1,    -1,
      -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,   563,    -1,    -1,   566,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   587,    -1,    -1,
      -1,   591,    -1,    -1,    -1,    -1,    -1,   465,    -1,    -1,
      -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,
     670,    -1,    -1,    -1,    -1,    -1,   544,   545,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   582,    -1,    -1,   585,   586,    -1,
      -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,    -1,
     658
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    42,   132,   292,   413,   461,   492,   521,
     732,   794,   802,   829,   830,   886,  1060,  1061,  1117,  1118,
    1119,  1121,  1122,  1123,  1128,  1130,  1143,  1144,  1145,  1146,
    1147,  1589,    28,    29,   803,   804,   805,   806,   807,    27,
    1024,  1604,  1024,  1024,    25,  1024,  1494,  1148,   831,  1494,
    1024,   830,     0,  1120,  1123,  1146,    31,   805,   807,   887,
     665,    25,   246,   828,   829,  1011,  1024,  1029,  1128,  1143,
    1149,  1180,  1181,  1182,  1183,  1184,  1188,   411,   833,   834,
     835,   836,   839,   840,   795,   110,   117,   163,   164,   424,
     519,   611,   691,   699,   802,   979,  1059,  1124,  1125,  1127,
    1131,  1132,  1138,  1150,  1303,  1313,  1589,   670,  1024,  1183,
     298,   512,   513,  1189,    20,  1024,  1187,   673,   834,     5,
     832,   411,  1024,     5,   859,   861,   862,   733,   798,  1024,
    1314,  1024,  1304,  1139,  1024,  1024,  1127,  1133,   316,   355,
     374,   375,   414,   426,   437,   453,   463,   478,   518,   541,
     556,   563,   566,   587,   591,   610,   628,   888,   889,   890,
     893,    25,  1180,  1186,    18,    19,    26,    41,   116,   128,
     155,   248,   345,   380,   414,   426,   462,   477,   485,   498,
     542,   567,   591,   635,   644,   728,   729,   743,   745,   946,
     953,   964,   966,  1024,  1180,  1190,  1191,   513,    14,   885,
     836,   576,  1290,   837,   834,   839,    32,    43,   120,   136,
     137,   146,   316,   355,   374,   375,   376,   377,   392,   414,
     426,   437,   453,   463,   478,   518,   541,   556,   563,   566,
     587,   591,   610,   628,   670,   843,   853,   864,   869,  1024,
     796,  1024,   485,  1024,   828,   980,  1151,  1024,   895,   375,
     841,   485,   871,   873,   874,   872,   881,   882,   485,   485,
     894,   513,   485,   834,   852,   480,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   743,   485,   825,
       9,    18,    19,    24,    25,    26,   121,   350,   444,   449,
     451,   467,   482,   485,   488,   497,   538,   550,   561,   591,
     642,   654,   655,   662,   673,   922,   930,   931,   932,   933,
     934,   964,   965,   967,  1030,  1180,  1293,  1487,   485,   485,
     485,   485,   485,   485,    18,    19,    20,    21,    22,   744,
      26,    36,   485,   575,     5,   481,  1190,    25,    26,  1024,
    1030,    19,    25,    26,   838,  1030,   723,   724,   725,   842,
     866,   855,   867,   841,   485,   485,   485,   856,   871,   872,
     485,   485,   854,   513,   865,   485,   852,   834,   863,   828,
     485,    26,   485,  1140,   828,   828,   485,  1024,   485,   512,
     847,    26,   679,   423,   508,   524,   567,   606,   635,   644,
     875,   679,   423,   508,   524,   567,   606,   635,   644,   883,
      26,    26,   896,   897,   898,   899,  1024,    26,   850,   851,
      26,   643,   665,   673,  1180,   720,   972,  1015,  1024,  1015,
    1015,   972,   972,   922,    24,    25,    26,    19,    24,    25,
      26,   968,   969,   970,   971,    25,   973,  1015,  1016,   922,
     448,   922,   922,   922,   922,   580,  1310,   485,   485,   922,
     423,   508,   524,   567,   606,   635,   644,  1490,  1491,   485,
     922,   922,   485,   485,   935,   485,   485,   485,   485,    26,
       6,     7,     8,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    51,   148,   149,   150,
     151,   152,   153,   166,   167,   168,   305,   308,   428,   443,
     447,   483,   511,   529,   610,   676,   824,   923,   936,   938,
     939,   940,   941,   942,   943,   944,   475,   956,   954,   960,
     958,  1180,  1180,   743,  1024,   947,  1024,  1191,   513,   481,
      26,   845,   485,   868,   852,   868,   847,    26,    26,    26,
     852,    26,    26,   833,   850,   868,    26,   673,   115,   860,
     797,  1315,   448,  1305,  1605,  1606,  1607,  1608,  1609,   981,
    1152,  1134,   673,    26,   448,   876,   877,   485,   878,   883,
     884,   878,   485,   879,     5,   448,     5,   448,     5,   339,
       5,   888,   481,     5,     5,   448,   834,   834,   834,   870,
     448,   485,     5,   448,   513,   673,   448,   448,   448,   448,
     448,   448,   448,    19,    26,   448,   643,   969,    19,    26,
     643,   448,     5,   448,   448,     5,   826,   922,   525,  1510,
     922,   485,   679,    20,   448,  1510,    20,  1293,   922,   922,
     922,   922,   922,   922,   922,   922,   922,   922,   922,   922,
     922,   922,   922,   922,   922,   922,   922,   922,   922,   922,
     922,   485,   922,   922,   485,  1180,   922,   922,   922,   922,
     448,     5,   485,   537,   775,   776,   777,   922,   485,  1190,
     513,   677,    26,   673,    26,   448,   448,     5,   448,   314,
       5,   448,     5,   448,   339,   481,     5,   448,   870,   799,
     800,  1132,  1024,  1196,  1197,  1199,  1196,   418,  1606,  1290,
      44,    45,    46,    53,    56,    63,    64,   108,   109,   113,
     123,   124,   126,   140,   157,   160,   161,   174,   176,   177,
     178,   186,   187,   189,   190,   191,   197,   200,   202,   203,
     204,   210,   212,   213,   215,   217,   218,   221,   224,   225,
     226,   227,   228,   229,   233,   234,   235,   237,   241,   243,
     244,   249,   252,   255,   257,   259,   261,   265,   266,   268,
     269,   270,   273,   275,   276,   278,   286,   287,   299,   302,
     303,   306,   307,   310,   311,   319,   320,   321,   323,   333,
     334,   335,   337,   341,   342,   346,   354,   362,   363,   364,
     370,   371,   378,   381,   385,   386,   396,   413,   421,   427,
     438,   450,   456,   458,   459,   466,   505,   516,   523,   547,
     548,   552,   564,   570,   571,   572,   573,   577,   581,   588,
     589,   599,   601,   612,   614,   617,   623,   649,   652,   657,
     660,   661,   675,   682,   705,   706,   707,   708,   709,   710,
     711,   714,   716,   718,   736,   737,   738,   739,   756,   780,
     801,   802,   808,   827,   901,   902,   903,   904,   915,   916,
     917,   918,   919,   920,   921,   974,  1005,  1009,  1031,  1033,
    1036,  1037,  1038,  1039,  1052,  1062,  1086,  1087,  1089,  1093,
    1108,  1109,  1113,  1114,  1115,  1116,  1126,  1141,  1157,  1168,
    1169,  1170,  1174,  1177,  1211,  1214,  1216,  1222,  1223,  1226,
    1229,  1234,  1236,  1238,  1241,  1248,  1253,  1258,  1259,  1260,
    1272,  1273,  1276,  1282,  1285,  1286,  1311,  1326,  1328,  1329,
    1330,  1331,  1343,  1349,  1350,  1370,  1373,  1402,  1404,  1495,
    1496,  1527,  1528,  1535,  1550,  1574,  1589,  1590,  1595,  1596,
    1598,  1602,  1603,  1610,   802,  1129,   678,   701,  1153,  1154,
    1196,    20,   448,   480,   848,   875,    26,   880,    26,    26,
      26,   897,   899,   891,   851,    26,   643,  1024,  1015,   743,
      20,   720,  1024,   875,   962,   962,    26,   448,   643,   962,
      24,    26,    26,   643,    24,    26,   872,   963,  1016,   873,
     448,   416,   530,   639,  1518,   448,   448,    26,  1491,   448,
     448,   448,   448,   448,   448,   448,   496,   496,   496,   945,
    1510,   496,   945,  1510,   957,   955,   961,   959,    26,   951,
     948,     5,   949,   481,  1190,   859,   448,    20,   848,    26,
     485,    26,    26,   844,    26,   731,   800,   673,   448,     5,
     448,  1180,  1180,  1180,  1024,    25,  1180,  1235,  1024,    25,
    1024,  1480,   407,  1025,  1026,  1604,  1025,    25,  1024,  1479,
    1024,  1024,  1256,  1019,  1025,  1019,  1024,  1600,  1480,  1024,
      26,   740,  1180,  1334,  1019,  1256,   945,    26,  1030,  1298,
    1299,  1298,   922,   929,  1372,  1479,  1479,   924,   945,  1025,
    1536,  1536,   905,  1256,  1019,  1332,  1180,  1021,  1025,   929,
    1536,  1180,  1256,  1180,  1371,  1536,    25,   639,  1171,  1172,
    1180,  1019,  1019,  1171,  1020,  1025,  1024,  1172,  1019,  1536,
    1019,  1021,  1480,  1180,  1209,  1210,  1017,  1025,  1021,   432,
     615,  1015,  1088,  1024,   809,  1479,  1022,  1025,    25,   246,
    1024,  1403,  1578,  1580,  1581,  1582,  1583,  1585,   945,  1209,
     679,   945,  1025,  1237,   975,    66,    67,    68,    69,   188,
     196,   205,   208,   251,   258,   315,   340,   347,   349,   359,
     387,   395,   432,   456,   493,   504,   602,   603,   604,   615,
     660,   718,   734,  1102,  1230,  1231,  1180,  1201,  1202,   928,
     929,  1247,   972,   972,  1018,  1025,   945,  1235,  1312,  1180,
    1289,    25,   485,  1180,  1284,  1530,  1283,   929,  1591,   162,
     211,   248,   345,   422,   462,   528,   757,   953,  1024,  1180,
    1321,   782,   929,  1017,   643,  1024,  1032,  1158,   929,  1017,
      26,  1180,  1110,  1017,   929,  1551,   929,  1298,  1024,  1034,
    1035,  1021,  1034,   972,  1021,  1034,   972,  1040,  1034,    25,
      26,   441,   541,  1030,  1091,  1180,  1198,  1200,   122,   330,
     402,   446,   622,   702,   703,   704,   713,   747,  1042,  1044,
    1046,  1048,  1050,  1175,  1176,  1179,   393,   404,   454,   468,
     557,  1405,   693,   694,   983,   984,   985,  1024,  1155,   700,
    1154,   448,   358,   448,   448,   448,   448,   677,     5,   448,
     834,   448,   481,   485,   679,    19,    26,   448,   962,    26,
     448,   448,   643,    26,   643,   679,    18,    19,    20,    25,
      26,    37,    38,   121,   451,   482,   485,   498,   538,   550,
     591,   624,   630,   639,   640,   642,   654,   655,   662,   665,
    1024,  1030,  1486,  1488,  1517,  1519,  1520,  1522,  1523,  1524,
    1546,  1547,  1548,  1549,  1579,  1580,  1584,  1310,   448,  1310,
    1310,  1310,  1310,  1310,  1310,    25,    25,    25,   922,   937,
     448,    25,   937,   448,   448,   448,   448,   448,   448,   775,
     448,   777,   775,   481,   358,   448,   834,   857,   858,   448,
     448,   677,   448,  1024,  1316,  1199,  1306,   111,   112,   141,
     142,   143,   509,   595,   638,  1351,  1352,  1353,  1356,  1359,
    1362,  1363,  1364,  1367,   673,   643,   665,   158,   159,   485,
     673,   643,   665,     8,   678,   481,  1479,   533,  1257,  1198,
     166,   167,   168,   649,   537,   925,   926,   929,  1180,  1205,
    1479,   746,   747,   908,   322,    50,   144,   145,   679,  1254,
     514,     5,   672,   679,   671,   671,  1212,   649,   475,     5,
     610,  1063,   514,   712,  1593,   712,   441,   811,  1180,   600,
     671,  1217,  1218,  1219,   673,    25,  1581,   513,  1586,   384,
    1401,   665,   673,   927,   929,   610,  1578,   927,     8,   607,
    1018,    26,   555,   608,   722,  1010,  1180,  1010,  1010,  1010,
      25,   233,   360,   366,   367,   368,   388,   493,   496,   504,
     539,   574,   593,   594,   604,   609,   648,   680,  1106,  1107,
    1010,  1010,   650,  1103,   747,  1103,  1103,  1011,  1011,  1103,
    1103,    39,    40,  1232,   747,    39,    40,  1233,     5,   475,
       5,   391,   442,     5,   746,   138,   139,   593,   680,  1094,
     715,  1594,   928,   666,   667,   668,   669,  1288,  1530,  1290,
     929,  1278,  1279,  1280,  1291,  1292,   929,   485,   485,   485,
     485,    25,   778,  1024,   485,  1530,   402,   485,   575,    36,
     643,   632,   783,   790,   781,  1024,    25,  1173,  1180,  1274,
       8,  1277,    14,  1024,  1185,  1192,  1193,  1195,  1203,  1204,
    1249,    39,    40,   219,   402,   598,   631,  1327,    33,   246,
     607,  1552,  1553,  1554,  1556,   629,     5,   712,   712,   927,
    1198,  1205,  1090,   475,     5,   207,  1068,   485,  1180,   927,
     485,    26,    26,   122,  1178,    25,  1180,  1534,  1534,  1025,
    1385,  1237,  1018,   175,   277,   285,   291,   293,   304,   332,
     348,   353,   365,   372,   520,   525,   532,   554,   559,  1374,
    1375,  1383,  1392,  1393,  1399,  1400,  1406,  1407,  1417,  1437,
    1441,  1506,  1507,  1537,  1538,  1541,  1542,  1558,   986,   987,
     147,   982,   993,   994,   985,  1156,  1605,  1135,   513,   888,
     851,   673,  1024,   875,    26,   448,   643,   962,   448,   643,
     962,   962,    24,    26,   643,    24,    26,   876,  1523,  1523,
     423,   508,   524,   567,   606,   635,   644,  1489,  1492,   525,
    1522,   485,   485,   485,   485,  1517,  1517,  1517,   485,   485,
     485,   485,  1024,   485,     5,   600,  1446,  1451,   670,  1024,
      18,    19,    20,    21,   148,   149,   150,   151,   152,   153,
    1544,  1492,  1492,   475,     5,   448,   448,   952,   950,   513,
       5,   448,   859,   828,   828,   301,   314,   416,   485,   530,
     546,  1421,  1422,  1427,  1429,   485,  1024,  1368,  1369,    26,
     485,  1024,  1348,  1361,  1429,  1431,   485,  1024,  1358,   485,
    1348,  1354,     5,  1024,    25,  1024,  1024,    25,  1027,  1183,
    1024,    25,  1024,  1024,  1024,  1601,  1479,   649,   485,   485,
     908,  1479,     5,   679,   485,  1578,    25,  1029,  1255,  1254,
    1255,  1530,  1171,   929,   929,   929,  1012,  1013,   485,  1180,
    1210,  1064,  1065,  1066,  1479,   679,  1530,   972,  1594,  1088,
    1180,   810,   678,   929,   408,  1221,   610,  1220,  1582,   743,
    1587,  1588,  1024,    20,  1583,     5,  1575,   670,  1227,   125,
     127,   129,   671,   679,   900,  1198,  1201,   976,    18,    19,
     485,  1104,  1106,  1231,  1180,  1202,  1011,   929,   402,   649,
      26,  1180,    26,  1180,   746,   209,  1287,   448,   440,  1325,
    1290,  1280,     5,   671,  1281,  1592,  1024,    25,   972,   972,
     643,  1016,   676,  1180,   763,  1024,  1024,  1024,   929,   397,
     786,   790,   632,   784,   792,    23,   290,  1160,  1164,   536,
     945,   536,  1275,   929,   512,  1189,   673,     5,  1111,   600,
    1250,  1180,   219,   402,  1555,  1557,   245,  1553,  1053,  1035,
     972,   972,  1045,  1046,  1068,  1068,    47,    48,    49,    52,
      54,    55,   326,   329,   331,   351,   361,   382,   405,   409,
     484,  1067,  1069,  1070,  1098,  1180,  1200,   600,   748,    26,
     455,  1051,   379,  1529,  1529,   194,   195,   491,   600,  1024,
    1438,  1439,  1481,  1479,  1479,  1479,  1376,  1479,  1479,  1024,
    1539,   223,   436,   450,   493,   504,   525,   532,   540,   562,
     639,   645,  1408,  1410,  1411,  1412,  1518,  1479,  1384,  1408,
    1410,  1605,  1605,   441,   995,  1180,   695,   696,   988,   989,
     990,   535,   678,   697,   698,   717,   998,   999,  1605,   828,
      26,   849,    20,  1024,   448,    26,   448,   962,    26,   962,
      24,    26,   448,   448,    24,    26,   679,  1518,   448,   451,
    1522,  1545,  1584,   416,   530,   639,  1470,  1522,  1525,  1470,
    1470,  1470,  1470,   673,  1525,  1520,   569,  1447,  1448,  1449,
    1479,   580,  1445,  1452,   389,   568,   579,  1394,  1513,  1024,
    1522,  1522,  1522,  1522,   679,   485,   679,  1579,   922,   448,
     448,   849,   858,  1317,  1307,   485,   485,   485,  1365,  1429,
     485,   485,   114,  1366,  1368,     5,  1360,  1361,   120,   355,
     375,   376,   377,   414,   426,   437,   453,   463,   478,   526,
     556,   566,   587,   591,   619,   628,  1471,  1472,  1473,  1475,
    1357,  1358,  1354,  1355,   717,  1352,   673,   643,   448,   673,
     643,   600,  1599,   485,   741,   742,  1024,  1335,   945,   925,
    1024,  1333,   670,  1224,  1254,  1254,   679,     5,     5,     5,
     633,   929,     5,   673,   537,   679,   678,   220,   222,   326,
     329,   812,   815,   816,  1098,   813,   814,  1024,   485,  1025,
     702,   703,  1225,     5,   481,   929,  1479,  1576,  1577,  1578,
     630,   670,  1228,  1024,  1024,  1013,  1014,   563,   972,   908,
       8,     8,   978,    26,    26,  1105,  1106,  1180,   375,  1242,
     122,   922,  1290,   274,  1292,  1298,  1605,     5,     5,   448,
     448,   779,  1024,   448,  1530,   775,   485,   485,   485,   791,
     787,   417,   785,   929,   397,   788,   792,   650,  1100,  1165,
    1161,   419,  1159,  1160,   927,   679,  1186,    20,  1024,  1194,
    1204,    14,   537,  1251,  1252,  1522,  1180,  1584,  1201,  1605,
    1047,  1048,   604,  1023,   600,  1081,  1080,  1079,  1078,  1083,
    1082,  1015,  1084,  1015,  1085,  1077,  1076,  1074,  1073,  1099,
     382,  1070,  1075,   972,    57,    58,    59,    60,    61,    62,
     154,   390,   403,   465,   471,   510,   534,   544,   545,   550,
     560,   582,   585,   586,   590,   647,   658,   749,   750,  1096,
    1097,     5,    26,  1530,   304,  1180,   525,  1511,  1512,  1530,
    1237,  1505,  1507,   156,   156,   649,  1235,  1440,  1441,   485,
    1418,   206,  1452,  1479,   230,   327,  1543,   673,   679,   485,
    1413,  1413,   600,   678,     5,  1508,  1559,   399,   408,   432,
     435,   451,   555,   608,   615,  1018,  1386,  1391,   679,   678,
     997,  1180,     5,   600,   991,   992,   692,   990,   996,  1024,
     996,  1000,  1001,   996,   382,   999,  1136,   481,   448,   643,
     962,   448,   643,   448,   448,   962,   962,   423,   508,   524,
     567,   606,   635,   644,  1493,  1519,     5,  1492,     5,   448,
       5,  1522,     5,   448,  1522,  1522,  1522,  1522,  1024,   448,
     485,  1449,     5,   670,  1024,  1485,     9,   350,   485,   497,
    1455,  1456,  1457,  1458,  1459,  1463,  1467,  1469,  1522,   425,
    1443,  1453,  1024,  1514,   672,  1470,   389,  1493,    26,  1493,
     481,   515,  1300,  1320,   515,  1261,  1294,   665,  1024,  1424,
    1426,  1479,  1483,  1484,  1428,  1483,  1428,     5,   448,  1366,
    1428,  1455,  1024,   448,  1369,     5,   448,   485,   485,   485,
    1492,  1492,   485,   485,   485,   485,   485,   262,   263,   264,
     455,  1430,  1432,     5,   448,     5,   448,  1024,  1024,    25,
    1024,  1024,    25,  1024,   929,  1024,  1345,  1346,     5,  1347,
    1348,   945,  1142,   673,  1347,   630,  1530,  1530,   929,   929,
    1012,   563,   929,  1597,     5,  1065,    20,  1483,  1530,   813,
     821,   820,   822,  1024,  1028,   823,  1028,   247,   816,   819,
       5,  1068,   673,   929,     8,  1588,   513,   673,     5,  1530,
     630,  1024,  1198,   945,   607,  1389,     5,   448,  1180,     5,
      26,  1180,   383,    25,  1322,   402,   402,   513,   673,   402,
     485,   764,   768,   761,   759,  1605,  1605,   793,   789,   785,
    1101,    25,  1023,  1166,  1180,  1605,   929,   480,   513,   945,
       5,  1054,  1049,  1050,    26,   746,  1024,  1605,  1605,  1605,
    1605,  1605,  1605,     5,  1071,     5,  1072,  1605,  1605,  1605,
    1605,  1104,  1605,  1023,    25,    14,    14,     5,   448,    26,
    1479,  1518,  1499,   649,   649,  1375,  1504,  1505,  1441,  1419,
    1483,   670,  1018,   485,  1379,  1024,  1540,  1539,  1414,  1483,
     517,  1415,  1416,  1481,  1479,  1412,  1519,   102,   103,   104,
     105,   106,   637,  1562,   929,   929,   607,  1387,  1018,  1415,
    1479,     5,  1180,   996,  1605,  1605,     5,  1003,  1004,  1605,
    1605,  1002,  1129,   892,   962,    26,   962,    24,    26,   962,
     962,   485,  1451,  1492,   679,  1492,  1492,   448,  1522,   448,
     448,   448,   448,  1448,  1450,  1448,  1485,  1458,  1517,  1455,
    1522,  1517,     6,     7,     9,    12,    13,    14,    15,    16,
      17,   428,   429,   483,   610,   676,   726,   727,  1466,  1468,
    1444,  1521,  1522,   502,  1442,  1454,   324,  1344,    26,  1395,
    1396,  1397,  1483,  1511,  1514,   448,   846,   130,   131,   133,
     134,   135,   232,   240,   274,   283,   312,   313,   357,   401,
     455,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,  1297,  1301,   193,   568,  1302,  1318,   216,   231,   232,
     240,   274,   283,   312,   357,   401,  1295,  1296,  1308,  1302,
    1484,   513,  1482,   448,     5,   673,     5,   448,   448,  1429,
     448,   448,  1361,    26,  1476,  1476,    26,   679,   485,   679,
      26,  1477,    26,    26,  1477,  1477,    25,  1486,   214,   314,
     352,   416,   430,   530,   546,  1423,  1433,  1434,  1435,  1436,
    1358,  1354,   673,   673,   592,   641,     5,   448,   742,     5,
     448,   927,   448,    20,   448,  1530,     5,   929,   620,   330,
     751,   752,   929,  1068,  1605,  1605,     5,   817,   513,   673,
       5,   818,  1605,   814,   600,    20,  1024,     5,  1024,  1215,
    1587,    20,  1483,  1577,     8,  1530,   446,   712,   927,  1390,
     977,  1106,   721,  1240,   922,     5,   775,  1180,   758,   740,
    1024,  1180,   766,   448,   775,   775,   775,  1605,  1605,  1104,
    1163,    25,  1167,  1180,   625,  1008,  1190,   537,   928,  1112,
    1252,   119,   596,  1055,  1041,  1042,   673,  1015,  1605,  1015,
    1605,   746,    26,  1180,    26,  1180,   750,   448,   485,  1531,
    1519,  1505,  1505,  1497,     5,   448,   525,  1516,  1380,  1483,
     533,  1377,  1516,   679,     5,   448,     5,   600,  1509,    18,
      19,   121,   482,   485,   498,   537,   538,   550,   591,   630,
     642,   654,   655,   662,   665,  1024,  1486,  1517,  1546,  1548,
    1567,  1568,  1569,  1570,  1571,  1572,  1584,  1567,  1567,  1567,
    1483,  1564,  1566,  1563,  1564,  1565,  1560,  1388,   679,  1180,
    1024,  1605,  1605,  1605,  1605,   677,   448,   643,   448,   448,
      26,   448,   679,  1493,   679,   679,     5,   448,   448,  1456,
    1457,  1461,  1523,  1461,   485,  1517,  1461,   485,  1517,  1461,
      10,   305,   443,   445,  1522,     5,  1455,     5,   592,   641,
    1398,  1344,   679,   677,  1298,  1298,  1298,    25,  1298,  1298,
    1298,  1298,  1298,  1298,    25,    25,  1298,  1301,  1180,  1206,
    1207,   672,   501,  1262,    25,    25,    26,    26,    26,    26,
      26,    25,  1180,  1296,  1262,    26,  1423,  1483,    20,  1024,
    1483,  1366,   448,   448,     5,   448,  1493,    26,  1493,     5,
    1474,     5,   448,   448,   448,  1474,  1425,  1479,   485,  1435,
    1366,  1024,  1024,  1346,   676,   730,  1340,  1341,  1342,  1348,
      65,   142,   143,   300,   676,  1336,  1337,  1338,   522,   907,
    1336,     5,   431,  1530,     5,   485,   448,   604,  1095,  1028,
    1605,   743,    20,  1024,  1028,  1605,   972,   929,   481,  1530,
       8,   972,  1201,  1605,    26,  1023,    25,  1323,  1198,   481,
     775,   765,   769,   448,   448,  1605,  1023,   929,  1006,   481,
    1057,  1056,   495,  1043,  1044,    20,  1024,  1532,  1533,   607,
    1515,  1500,  1498,  1483,  1518,   198,  1420,     5,   448,  1378,
    1540,  1483,  1416,  1415,  1515,  1570,  1570,  1569,   485,   485,
     485,   485,   485,   485,   485,  1024,   485,     5,   448,    18,
      19,    20,    21,  1544,   448,     5,   448,     5,    14,   206,
     580,  1561,  1201,  1415,   267,  1137,   888,   962,    24,    26,
     962,   962,   448,  1493,  1493,  1493,  1448,   496,  1460,  1460,
    1464,  1465,  1486,  1584,  1460,  1464,  1460,  1461,  1522,  1521,
    1396,  1493,   859,   592,   641,  1208,     5,  1206,   118,   192,
     254,   256,   272,   280,   284,   309,  1263,  1264,  1319,  1309,
       5,   481,  1482,    26,   448,    26,  1478,   448,    26,   448,
     485,  1455,  1339,  1604,    26,  1342,    26,    26,  1339,  1344,
    1338,  1015,   746,   431,  1530,   929,   753,   622,  1213,    26,
     746,   481,  1095,   448,  1530,   296,   746,   448,   448,   485,
     767,   402,   773,   448,   762,   760,  1162,  1605,   513,   929,
    1605,  1023,     5,   448,  1201,  1451,  1519,  1483,   485,  1451,
     448,  1545,  1470,  1569,  1573,  1470,  1470,  1470,  1470,   513,
     673,  1573,  1568,  1569,  1569,  1569,  1569,  1564,    14,  1565,
    1568,  1018,  1455,   199,   670,  1409,   448,   448,  1462,  1486,
    1526,     5,   448,   448,  1460,     7,  1207,  1265,  1266,  1180,
    1268,  1180,  1267,  1269,  1264,   295,   295,    26,   448,   679,
     448,  1426,   448,   906,  1530,   449,   258,   315,   340,   349,
     387,   395,   486,   656,   750,   754,   755,   485,   673,   746,
    1239,  1324,   770,   448,  1198,   773,   773,   773,  1605,  1007,
    1190,   629,  1092,  1533,  1513,  1451,   537,  1381,  1382,  1522,
    1513,   448,  1569,     5,   448,  1569,  1569,  1569,  1569,    26,
    1024,   448,   485,  1024,   962,   962,  1465,  1522,  1605,  1605,
    1270,  1605,  1271,  1605,  1605,   481,  1493,   448,   294,   405,
     409,   909,   910,   911,  1098,  1010,  1010,  1010,  1010,  1010,
    1010,    25,     5,   448,   929,    20,  1024,  1098,  1243,  1244,
    1245,   773,   775,   773,   297,   481,  1058,   746,     5,   448,
     343,   344,  1501,   448,  1569,   448,   448,   448,   448,     5,
     481,   513,  1567,  1605,  1605,   913,   912,   294,   911,   914,
     755,     5,  1246,   338,  1245,   771,  1605,  1382,    25,  1024,
    1502,  1503,    26,    26,   448,  1605,  1605,  1605,   929,  1605,
     448,  1055,   673,   673,     5,   481,     5,   481,   448,   772,
    1024,  1024,  1503,    26,   219,   402,   774,   673,   481,  1198,
    1024
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
#line 1011 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1014 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1018 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1024 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1029 "fgl.yacc"
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
#line 1041 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1046 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	//sprintf($<str>$, "A4GL_unregister_func(\"%s\",%s%s);\n", $<str>1, (char *)get_namespace($<str>1), $<str>1);
	sprintf(yyval.str, "A4GL_unregister_func(\"%s\");\n", yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1065 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1066 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1067 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1068 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1069 "fgl.yacc"
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
#line 1080 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1086 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1087 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1088 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1089 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1090 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1095 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1096 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1107 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1110 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1113 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1113 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1120 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1121 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1136 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1137 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1138 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1139 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1140 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1141 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1142 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1143 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1150 "fgl.yacc"
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
#line 1161 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1165 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1166 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1170 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1176 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1178 "fgl.yacc"
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
#line 1189 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1191 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1193 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1195 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1199 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1201 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1262 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1266 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1270 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1277 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1280 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1284 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1288 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1297 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1303 "fgl.yacc"
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
#line 1312 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1317 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1323 "fgl.yacc"
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
#line 1332 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 77:
#line 1339 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 78:
#line 1344 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 79:
#line 1348 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 80:
#line 1356 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 81:
#line 1360 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1364 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1366 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 84:
#line 1372 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 85:
#line 1377 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 86:
#line 1380 "fgl.yacc"
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
#line 1396 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 88:
#line 1403 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 89:
#line 1407 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 90:
#line 1411 "fgl.yacc"
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
#line 1433 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 92:
#line 1433 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 93:
#line 1437 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 94:
#line 1438 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 95:
#line 1439 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 96:
#line 1444 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 97:
#line 1447 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 98:
#line 1453 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 99:
#line 1456 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 101:
#line 1465 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 103:
#line 1469 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 104:
#line 1475 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 105:
#line 1478 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 106:
#line 1493 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 107:
#line 1503 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1509 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 109:
#line 1518 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 114:
#line 1531 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 116:
#line 1534 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 117:
#line 1536 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 119:
#line 1542 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 120:
#line 1544 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 121:
#line 1549 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 122:
#line 1554 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 123:
#line 1560 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 124:
#line 1564 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 125:
#line 1573 "fgl.yacc"
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
#line 1597 "fgl.yacc"
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
#line 1605 "fgl.yacc"
    { 
		pop_record();in_record--;
		read_class(yyvsp[-2].str); 
		print_variables(); 
		class_set_parent();
		}
    break;

  case 128:
#line 1611 "fgl.yacc"
    {
		class_cnt++; 
		CLASS_print_reflector();
		dump_class();
		}
    break;

  case 129:
#line 1621 "fgl.yacc"
    {
	static char buff[256];
		strcpy(buff,"default_object");
		CLASS_set_parent_name(buff);
		strcpy(yyval.str,buff);
	}
    break;

  case 130:
#line 1626 "fgl.yacc"
    {
		CLASS_set_parent_name(yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 134:
#line 1649 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 135:
#line 1652 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 136:
#line 1655 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 137:
#line 1658 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 138:
#line 1661 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 139:
#line 1664 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 145:
#line 1686 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 148:
#line 1695 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 149:
#line 1714 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 150:
#line 1719 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 151:
#line 1722 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 152:
#line 1731 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 153:
#line 1737 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 158:
#line 1752 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 159:
#line 1756 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 160:
#line 1761 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 163:
#line 1771 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 164:
#line 1771 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 165:
#line 1772 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 166:
#line 1772 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 167:
#line 1773 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 168:
#line 1773 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 169:
#line 1774 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 170:
#line 1774 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 171:
#line 1775 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 172:
#line 1775 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 173:
#line 1783 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 174:
#line 1787 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 175:
#line 1793 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 176:
#line 1797 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 177:
#line 1812 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 178:
#line 1815 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 179:
#line 1818 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 180:
#line 1821 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 181:
#line 1824 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 182:
#line 1827 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 183:
#line 1836 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 184:
#line 1844 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 185:
#line 1849 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 186:
#line 1862 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 187:
#line 1866 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 188:
#line 1881 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 189:
#line 1882 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 192:
#line 1890 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 193:
#line 1890 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 198:
#line 1899 "fgl.yacc"
    {in_define=1;}
    break;

  case 199:
#line 1899 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 200:
#line 1908 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 201:
#line 1909 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 202:
#line 1910 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 203:
#line 1913 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 205:
#line 1918 "fgl.yacc"
    { }
    break;

  case 206:
#line 1918 "fgl.yacc"
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
#line 1935 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 211:
#line 1939 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 216:
#line 1954 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 217:
#line 1955 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 218:
#line 1956 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 219:
#line 1957 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 220:
#line 1962 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 222:
#line 1968 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 224:
#line 1977 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 225:
#line 1981 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 231:
#line 1997 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 232:
#line 1999 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 233:
#line 2000 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 236:
#line 2009 "fgl.yacc"
    {
		sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 237:
#line 2011 "fgl.yacc"
    {
		sprintf(yyval.str,"%s@%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 238:
#line 2016 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 239:
#line 2016 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 240:
#line 2017 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 241:
#line 2018 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 242:
#line 2021 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 243:
#line 2023 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 245:
#line 2033 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 250:
#line 2048 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 251:
#line 2048 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 255:
#line 2054 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 256:
#line 2055 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 257:
#line 2056 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 258:
#line 2057 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 259:
#line 2058 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 260:
#line 2059 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 261:
#line 2060 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 262:
#line 2061 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 263:
#line 2062 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 264:
#line 2063 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 265:
#line 2066 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 266:
#line 2067 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 267:
#line 2068 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 268:
#line 2069 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 269:
#line 2073 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 270:
#line 2078 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 271:
#line 2083 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 272:
#line 2087 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 273:
#line 2090 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 274:
#line 2094 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 276:
#line 2095 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 278:
#line 2096 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 280:
#line 2097 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 281:
#line 2098 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 282:
#line 2099 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 283:
#line 2100 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 284:
#line 2101 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 285:
#line 2102 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 286:
#line 2105 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 287:
#line 2106 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 288:
#line 2107 "fgl.yacc"
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

  case 291:
#line 2142 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 292:
#line 2147 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2149 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 294:
#line 2151 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 295:
#line 2156 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 296:
#line 2160 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 297:
#line 2160 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 298:
#line 2164 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 299:
#line 2165 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 300:
#line 2166 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 301:
#line 2167 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 302:
#line 2168 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 303:
#line 2169 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 304:
#line 2171 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 305:
#line 2176 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 306:
#line 2176 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 307:
#line 2179 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 308:
#line 2181 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 309:
#line 2187 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 310:
#line 2189 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 311:
#line 2195 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 312:
#line 2203 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 313:
#line 2203 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 314:
#line 2206 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 315:
#line 2207 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 316:
#line 2208 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 317:
#line 2209 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 318:
#line 2210 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 319:
#line 2211 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 320:
#line 2213 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 324:
#line 2234 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 328:
#line 2243 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 329:
#line 2245 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 330:
#line 2246 "fgl.yacc"
    { dim_push_type("varchar",yyvsp[-1].str,0); }
    break;

  case 331:
#line 2247 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 332:
#line 2251 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 333:
#line 2252 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 334:
#line 2253 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 335:
#line 2254 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 336:
#line 2259 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 337:
#line 2266 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 338:
#line 2271 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 339:
#line 2273 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 340:
#line 2275 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 341:
#line 2276 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 342:
#line 2277 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 343:
#line 2278 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 344:
#line 2279 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 345:
#line 2280 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 346:
#line 2281 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 347:
#line 2284 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 348:
#line 2286 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 349:
#line 2292 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 350:
#line 2300 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 352:
#line 2308 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 353:
#line 2312 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 354:
#line 2320 "fgl.yacc"
    {dim_push_record();}
    break;

  case 355:
#line 2321 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 356:
#line 2322 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 357:
#line 2323 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 363:
#line 2342 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 364:
#line 2354 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 365:
#line 2358 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 366:
#line 2361 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 367:
#line 2364 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 368:
#line 2365 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 369:
#line 2366 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 370:
#line 2367 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 371:
#line 2368 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 372:
#line 2374 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 373:
#line 2381 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 374:
#line 2386 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 375:
#line 2391 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 376:
#line 2396 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 377:
#line 2400 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 378:
#line 2409 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 379:
#line 2411 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 380:
#line 2416 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 386:
#line 2428 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 387:
#line 2432 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 388:
#line 2435 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 389:
#line 2439 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 390:
#line 2442 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 391:
#line 2446 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 392:
#line 2453 "fgl.yacc"
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

  case 393:
#line 2471 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 394:
#line 2477 "fgl.yacc"
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

  case 395:
#line 2501 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 396:
#line 2504 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 397:
#line 2519 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 398:
#line 2522 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 399:
#line 2536 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 400:
#line 2538 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 401:
#line 2540 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 402:
#line 2542 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 403:
#line 2544 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 404:
#line 2546 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 405:
#line 2547 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 406:
#line 2554 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 407:
#line 2556 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 408:
#line 2560 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 409:
#line 2562 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 410:
#line 2564 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 411:
#line 2566 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 412:
#line 2568 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 413:
#line 2570 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 414:
#line 2572 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 415:
#line 2578 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 419:
#line 2597 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 422:
#line 2603 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 423:
#line 2607 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 424:
#line 2612 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 428:
#line 2622 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 429:
#line 2623 "fgl.yacc"
    {inc_counter();}
    break;

  case 435:
#line 2629 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 436:
#line 2636 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 437:
#line 2636 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 439:
#line 2641 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 440:
#line 2645 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 441:
#line 2651 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 442:
#line 2659 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 443:
#line 2665 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 444:
#line 2674 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 445:
#line 2676 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 446:
#line 2683 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 447:
#line 2704 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2709 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 449:
#line 2714 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 450:
#line 2718 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 451:
#line 2720 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 452:
#line 2723 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 453:
#line 2741 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 454:
#line 2747 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2753 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 458:
#line 2763 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 459:
#line 2769 "fgl.yacc"
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

  case 460:
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

  case 461:
#line 2852 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 462:
#line 2860 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 463:
#line 2868 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 464:
#line 2868 "fgl.yacc"
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

  case 465:
#line 2884 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 466:
#line 2888 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 467:
#line 2894 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 468:
#line 2897 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 469:
#line 2905 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 470:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 471:
#line 2912 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 472:
#line 2918 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 473:
#line 2928 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 474:
#line 2933 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 475:
#line 2940 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 476:
#line 2943 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 477:
#line 2946 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 478:
#line 2951 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 479:
#line 2958 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 480:
#line 2963 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 481:
#line 2968 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 482:
#line 2973 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 483:
#line 2984 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 484:
#line 2992 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 485:
#line 3000 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 486:
#line 3005 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 487:
#line 3009 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 488:
#line 3014 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 489:
#line 3018 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 490:
#line 3022 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 491:
#line 3028 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 492:
#line 3031 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 493:
#line 3035 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 494:
#line 3039 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 495:
#line 3043 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 496:
#line 3047 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 497:
#line 3051 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 498:
#line 3058 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 499:
#line 3068 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 500:
#line 3073 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 501:
#line 3079 "fgl.yacc"
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

  case 502:
#line 3089 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 503:
#line 3094 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 504:
#line 3097 "fgl.yacc"
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

  case 505:
#line 3108 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 506:
#line 3113 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 507:
#line 3116 "fgl.yacc"
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

  case 508:
#line 3134 "fgl.yacc"
    {chk4var=1;}
    break;

  case 509:
#line 3134 "fgl.yacc"
    {chk4var=0;}
    break;

  case 510:
#line 3134 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 511:
#line 3137 "fgl.yacc"
    {chk4var=1;}
    break;

  case 512:
#line 3137 "fgl.yacc"
    {chk4var=0;}
    break;

  case 513:
#line 3137 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 514:
#line 3141 "fgl.yacc"
    {chk4var=1;}
    break;

  case 515:
#line 3141 "fgl.yacc"
    {chk4var=0;}
    break;

  case 516:
#line 3141 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 517:
#line 3145 "fgl.yacc"
    {chk4var=1;}
    break;

  case 518:
#line 3145 "fgl.yacc"
    {chk4var=0;}
    break;

  case 519:
#line 3145 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 520:
#line 3149 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3155 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3161 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3167 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3175 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3181 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 526:
#line 3189 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 527:
#line 3195 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 528:
#line 3204 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 529:
#line 3210 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 530:
#line 3217 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 531:
#line 3224 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 532:
#line 3233 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 533:
#line 3239 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 534:
#line 3245 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 535:
#line 3252 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 536:
#line 3258 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 537:
#line 3264 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 538:
#line 3270 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 539:
#line 3278 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 540:
#line 3284 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 541:
#line 3290 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 542:
#line 3299 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 543:
#line 3305 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 544:
#line 3311 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 545:
#line 3321 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 546:
#line 3322 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 549:
#line 3330 "fgl.yacc"
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

  case 550:
#line 3341 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 551:
#line 3342 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 552:
#line 3348 "fgl.yacc"
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

  case 553:
#line 3359 "fgl.yacc"
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

  case 554:
#line 3369 "fgl.yacc"
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

  case 557:
#line 3382 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 558:
#line 3387 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 559:
#line 3394 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 560:
#line 3398 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 561:
#line 3401 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 562:
#line 3404 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 563:
#line 3410 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 564:
#line 3413 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 565:
#line 3416 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 566:
#line 3433 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 567:
#line 3436 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 568:
#line 3442 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 569:
#line 3443 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 570:
#line 3444 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 572:
#line 3449 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 573:
#line 3450 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 574:
#line 3451 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 575:
#line 3452 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 576:
#line 3454 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 577:
#line 3455 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 578:
#line 3456 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 579:
#line 3458 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 580:
#line 3459 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 582:
#line 3465 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 583:
#line 3469 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 584:
#line 3473 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 585:
#line 3478 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 586:
#line 3482 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 587:
#line 3497 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 588:
#line 3501 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 589:
#line 3507 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 590:
#line 3511 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 591:
#line 3520 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 592:
#line 3521 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 593:
#line 3533 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 594:
#line 3539 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 595:
#line 3547 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 602:
#line 3564 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 603:
#line 3566 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 604:
#line 3569 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 605:
#line 3571 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 610:
#line 3585 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 611:
#line 3587 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 612:
#line 3590 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 613:
#line 3592 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 626:
#line 3623 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 627:
#line 3625 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 628:
#line 3628 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 629:
#line 3630 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 630:
#line 3633 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 631:
#line 3635 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 632:
#line 3638 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 633:
#line 3640 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 634:
#line 3643 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 635:
#line 3645 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 636:
#line 3659 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 637:
#line 3663 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 638:
#line 3664 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 639:
#line 3671 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 641:
#line 3689 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 642:
#line 3705 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 643:
#line 3706 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 644:
#line 3707 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 645:
#line 3708 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 646:
#line 3709 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 647:
#line 3710 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 648:
#line 3711 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 652:
#line 3719 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 654:
#line 3725 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 655:
#line 3728 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 656:
#line 3733 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 657:
#line 3738 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 658:
#line 3741 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 659:
#line 3746 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 660:
#line 3751 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 661:
#line 3756 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 662:
#line 3763 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 663:
#line 3764 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 664:
#line 3771 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 665:
#line 3778 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 666:
#line 3780 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 667:
#line 3786 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 668:
#line 3791 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 669:
#line 3796 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 670:
#line 3801 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 671:
#line 3801 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 672:
#line 3804 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 673:
#line 3810 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 674:
#line 3815 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 675:
#line 3819 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 678:
#line 3827 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 679:
#line 3830 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 680:
#line 3833 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 681:
#line 3838 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 682:
#line 3843 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 683:
#line 3848 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 684:
#line 3855 "fgl.yacc"
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

  case 686:
#line 3866 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 687:
#line 3928 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 689:
#line 3937 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 690:
#line 3946 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 692:
#line 3953 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 693:
#line 3956 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 694:
#line 3962 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 695:
#line 3968 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 696:
#line 3972 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 697:
#line 3976 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 698:
#line 3982 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 699:
#line 3986 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 700:
#line 3990 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 701:
#line 3995 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 702:
#line 4000 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 721:
#line 4041 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 722:
#line 4048 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 723:
#line 4050 "fgl.yacc"
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

  case 725:
#line 4069 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 727:
#line 4072 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 728:
#line 4074 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 729:
#line 4077 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 730:
#line 4081 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 731:
#line 4084 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 732:
#line 4091 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 733:
#line 4096 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 734:
#line 4107 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 735:
#line 4108 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 736:
#line 4111 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 738:
#line 4117 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 739:
#line 4121 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 740:
#line 4122 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 741:
#line 4126 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 745:
#line 4141 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 746:
#line 4143 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 749:
#line 4152 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 750:
#line 4155 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 751:
#line 4159 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 752:
#line 4162 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 753:
#line 4165 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 754:
#line 4168 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 755:
#line 4171 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 756:
#line 4175 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 757:
#line 4178 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 758:
#line 4181 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 759:
#line 4184 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 760:
#line 4187 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 761:
#line 4190 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 762:
#line 4193 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 763:
#line 4196 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 764:
#line 4199 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 765:
#line 4200 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 766:
#line 4200 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 767:
#line 4201 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 768:
#line 4201 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 769:
#line 4202 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 770:
#line 4202 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 771:
#line 4203 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 772:
#line 4206 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 773:
#line 4207 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 774:
#line 4210 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 775:
#line 4218 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 776:
#line 4222 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 777:
#line 4228 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 778:
#line 4232 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 779:
#line 4237 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 780:
#line 4242 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 781:
#line 4247 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 782:
#line 4248 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 783:
#line 4249 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 784:
#line 4253 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 785:
#line 4257 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 786:
#line 4266 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 787:
#line 4271 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 788:
#line 4275 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 789:
#line 4282 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 790:
#line 4291 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 791:
#line 4297 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 792:
#line 4298 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 793:
#line 4299 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 794:
#line 4300 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 795:
#line 4301 "fgl.yacc"
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

  case 796:
#line 4311 "fgl.yacc"
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

  case 797:
#line 4325 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 799:
#line 4328 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 800:
#line 4335 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 801:
#line 4336 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 802:
#line 4337 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 803:
#line 4338 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 804:
#line 4339 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 805:
#line 4340 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 806:
#line 4341 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 807:
#line 4342 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 808:
#line 4343 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 809:
#line 4348 "fgl.yacc"
    {iskey=1;}
    break;

  case 810:
#line 4348 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 811:
#line 4350 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 812:
#line 4353 "fgl.yacc"
    {iskey=1;}
    break;

  case 813:
#line 4353 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 814:
#line 4355 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 815:
#line 4359 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 816:
#line 4362 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 817:
#line 4363 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 819:
#line 4366 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 825:
#line 4378 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 826:
#line 4379 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 827:
#line 4380 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 828:
#line 4381 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 829:
#line 4382 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 830:
#line 4383 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 831:
#line 4384 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 832:
#line 4385 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 833:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 834:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 835:
#line 4388 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 836:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 837:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 838:
#line 4391 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 839:
#line 4395 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 840:
#line 4413 "fgl.yacc"
    {chk4var=1;}
    break;

  case 841:
#line 4413 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 842:
#line 4416 "fgl.yacc"
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

  case 843:
#line 4440 "fgl.yacc"
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

  case 845:
#line 4458 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 846:
#line 4464 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 847:
#line 4470 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 848:
#line 4476 "fgl.yacc"
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

  case 849:
#line 4488 "fgl.yacc"
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

  case 853:
#line 4519 "fgl.yacc"
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

  case 856:
#line 4536 "fgl.yacc"
    {
	}
    break;

  case 866:
#line 4562 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 870:
#line 4570 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 884:
#line 4594 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 885:
#line 4595 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 886:
#line 4603 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 887:
#line 4609 "fgl.yacc"
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

  case 888:
#line 4625 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 889:
#line 4631 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 891:
#line 4646 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 892:
#line 4659 "fgl.yacc"
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

  case 893:
#line 4670 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 894:
#line 4677 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 895:
#line 4684 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 896:
#line 4690 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 897:
#line 4690 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 898:
#line 4695 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 899:
#line 4701 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 900:
#line 4709 "fgl.yacc"
    {
}
    break;

  case 904:
#line 4721 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 906:
#line 4729 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 907:
#line 4735 "fgl.yacc"
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

  case 910:
#line 4755 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 911:
#line 4761 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 912:
#line 4765 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 915:
#line 4777 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 916:
#line 4780 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 917:
#line 4784 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 918:
#line 4787 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 919:
#line 4799 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 920:
#line 4807 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 921:
#line 4813 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 922:
#line 4824 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 923:
#line 4828 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 924:
#line 4835 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
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

  case 926:
#line 4848 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 927:
#line 4853 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 930:
#line 4860 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 931:
#line 4861 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 932:
#line 4863 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 933:
#line 4864 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 934:
#line 4867 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 935:
#line 4868 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 936:
#line 4869 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 937:
#line 4871 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 938:
#line 4876 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 939:
#line 4881 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 940:
#line 4888 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 944:
#line 4895 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 945:
#line 4897 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 946:
#line 4899 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 948:
#line 4909 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 949:
#line 4912 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 950:
#line 4915 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 957:
#line 4931 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 958:
#line 4936 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 959:
#line 4936 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 960:
#line 4939 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 961:
#line 4967 "fgl.yacc"
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

  case 963:
#line 5024 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 965:
#line 5031 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 966:
#line 5035 "fgl.yacc"
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

  case 967:
#line 5078 "fgl.yacc"
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

  case 971:
#line 5126 "fgl.yacc"
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

  case 972:
#line 5140 "fgl.yacc"
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

  case 977:
#line 5164 "fgl.yacc"
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

  case 978:
#line 5228 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 979:
#line 5233 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 980:
#line 5241 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 981:
#line 5246 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 982:
#line 5254 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 983:
#line 5260 "fgl.yacc"
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

  case 984:
#line 5292 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 985:
#line 5295 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 986:
#line 5297 "fgl.yacc"
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

  case 987:
#line 5338 "fgl.yacc"
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

  case 992:
#line 5391 "fgl.yacc"
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

  case 993:
#line 5443 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 995:
#line 5452 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 996:
#line 5457 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 997:
#line 5468 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 998:
#line 5475 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1000:
#line 5483 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1001:
#line 5486 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 1002:
#line 5487 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1004:
#line 5489 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1005:
#line 5490 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1006:
#line 5493 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 1007:
#line 5496 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1008:
#line 5502 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 1009:
#line 5505 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1010:
#line 5509 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 1011:
#line 5514 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1012:
#line 5522 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 1013:
#line 5527 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 1014:
#line 5534 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1015:
#line 5536 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1020:
#line 5564 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1021:
#line 5571 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1022:
#line 5578 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1023:
#line 5581 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1024:
#line 5595 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1029:
#line 5612 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1030:
#line 5617 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1031:
#line 5623 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1033:
#line 5630 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1034:
#line 5635 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1035:
#line 5638 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1036:
#line 5639 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1037:
#line 5642 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1038:
#line 5643 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1039:
#line 5646 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1040:
#line 5647 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1041:
#line 5652 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1042:
#line 5659 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1043:
#line 5662 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1044:
#line 5668 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1045:
#line 5670 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1046:
#line 5672 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1047:
#line 5674 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1048:
#line 5677 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1049:
#line 5677 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1050:
#line 5678 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1051:
#line 5683 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1052:
#line 5691 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1053:
#line 5692 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1054:
#line 5697 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1055:
#line 5699 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1056:
#line 5701 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1060:
#line 5719 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1061:
#line 5720 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1062:
#line 5721 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1063:
#line 5722 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1064:
#line 5723 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1065:
#line 5724 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1066:
#line 5725 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1067:
#line 5726 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1068:
#line 5727 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1069:
#line 5728 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1070:
#line 5729 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1071:
#line 5730 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1072:
#line 5731 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1073:
#line 5732 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1074:
#line 5733 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1075:
#line 5734 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1076:
#line 5735 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1077:
#line 5736 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1078:
#line 5737 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1079:
#line 5738 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1080:
#line 5739 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1081:
#line 5740 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1082:
#line 5741 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1083:
#line 5742 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1084:
#line 5743 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1085:
#line 5744 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1086:
#line 5745 "fgl.yacc"
    { print_options('r',yyvsp[0].str); }
    break;

  case 1087:
#line 5746 "fgl.yacc"
    { print_options('|',yyvsp[0].str); }
    break;

  case 1088:
#line 5750 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1089:
#line 5751 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1090:
#line 5755 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1091:
#line 5756 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1092:
#line 5771 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1095:
#line 5780 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1096:
#line 5784 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1097:
#line 5788 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1098:
#line 5792 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1099:
#line 5796 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1101:
#line 5816 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1102:
#line 5821 "fgl.yacc"
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

  case 1103:
#line 5834 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1104:
#line 5835 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1105:
#line 5839 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1106:
#line 5844 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1107:
#line 5845 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1108:
#line 5849 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1112:
#line 5855 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1113:
#line 5858 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1115:
#line 5873 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1116:
#line 5877 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1117:
#line 5883 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1118:
#line 5884 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1119:
#line 5889 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1120:
#line 5890 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1121:
#line 5893 "fgl.yacc"
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

  case 1123:
#line 5920 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1124:
#line 5924 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1125:
#line 5928 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1126:
#line 5932 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1127:
#line 5939 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1128:
#line 5940 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1134:
#line 5952 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1135:
#line 5958 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1136:
#line 5966 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1137:
#line 5972 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1138:
#line 5974 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1142:
#line 5984 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1143:
#line 5984 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1144:
#line 5989 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1145:
#line 5993 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1146:
#line 5998 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1147:
#line 5998 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1148:
#line 6002 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1149:
#line 6002 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1150:
#line 6003 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1151:
#line 6003 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1152:
#line 6004 "fgl.yacc"
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

  case 1153:
#line 6017 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1154:
#line 6018 "fgl.yacc"
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

  case 1155:
#line 6034 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1162:
#line 6046 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1163:
#line 6046 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1164:
#line 6052 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1165:
#line 6052 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1166:
#line 6055 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1167:
#line 6055 "fgl.yacc"
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

  case 1168:
#line 6071 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1169:
#line 6072 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1170:
#line 6073 "fgl.yacc"
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

  case 1171:
#line 6082 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1172:
#line 6094 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1178:
#line 6105 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1179:
#line 6110 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1180:
#line 6110 "fgl.yacc"
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

  case 1182:
#line 6134 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1183:
#line 6140 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1184:
#line 6145 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1185:
#line 6151 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1186:
#line 6152 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1187:
#line 6153 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1188:
#line 6157 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1189:
#line 6158 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1190:
#line 6159 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1191:
#line 6160 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1192:
#line 6164 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1193:
#line 6174 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1194:
#line 6176 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1195:
#line 6181 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1196:
#line 6184 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1197:
#line 6189 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1198:
#line 6196 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1199:
#line 6203 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1200:
#line 6210 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1201:
#line 6219 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1202:
#line 6226 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1203:
#line 6233 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1204:
#line 6240 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1205:
#line 6247 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1210:
#line 6260 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1211:
#line 6261 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1212:
#line 6262 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1213:
#line 6263 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1214:
#line 6264 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1215:
#line 6265 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1216:
#line 6266 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1217:
#line 6267 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1218:
#line 6268 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1219:
#line 6269 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1222:
#line 6275 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1223:
#line 6276 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1224:
#line 6277 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1225:
#line 6278 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1230:
#line 6287 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1231:
#line 6288 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1232:
#line 6289 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1233:
#line 6290 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1234:
#line 6291 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1235:
#line 6292 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1236:
#line 6293 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1237:
#line 6294 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1238:
#line 6296 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1239:
#line 6297 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1240:
#line 6298 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1241:
#line 6299 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1242:
#line 6301 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1243:
#line 6302 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1244:
#line 6303 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1245:
#line 6304 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1249:
#line 6309 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1250:
#line 6310 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1254:
#line 6317 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1255:
#line 6326 "fgl.yacc"
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

  case 1256:
#line 6335 "fgl.yacc"
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

  case 1257:
#line 6348 "fgl.yacc"
    { 
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1258:
#line 6359 "fgl.yacc"
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

  case 1259:
#line 6370 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1260:
#line 6374 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1261:
#line 6378 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1262:
#line 6384 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1263:
#line 6389 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1264:
#line 6397 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1265:
#line 6400 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1266:
#line 6409 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1267:
#line 6420 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1269:
#line 6427 "fgl.yacc"
    {
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1270:
#line 6437 "fgl.yacc"
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

  case 1271:
#line 6447 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1272:
#line 6450 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1273:
#line 6454 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1274:
#line 6462 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1275:
#line 6465 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1276:
#line 6471 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1277:
#line 6475 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1278:
#line 6479 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1279:
#line 6483 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1280:
#line 6487 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1281:
#line 6493 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1282:
#line 6494 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1283:
#line 6495 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1284:
#line 6496 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1285:
#line 6501 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1286:
#line 6502 "fgl.yacc"
    { print_system_run(yyvsp[0].integer_val,0); }
    break;

  case 1287:
#line 6503 "fgl.yacc"
    { print_system_run(1,yyvsp[0].str); }
    break;

  case 1288:
#line 6504 "fgl.yacc"
    { print_system_run(2,0); }
    break;

  case 1289:
#line 6505 "fgl.yacc"
    { print_system_run(1+yyvsp[-2].integer_val,yyvsp[0].str); }
    break;

  case 1290:
#line 6506 "fgl.yacc"
    { print_system_run(2+yyvsp[-1].integer_val,0); }
    break;

  case 1291:
#line 6507 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1292:
#line 6508 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1293:
#line 6512 "fgl.yacc"
    {yyval.integer_val=512;}
    break;

  case 1294:
#line 6513 "fgl.yacc"
    {yyval.integer_val=256;}
    break;

  case 1295:
#line 6516 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1296:
#line 6521 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1297:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1298:
#line 6529 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 6535 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1301:
#line 6536 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1302:
#line 6542 "fgl.yacc"
    {insql=1;}
    break;

  case 1303:
#line 6542 "fgl.yacc"
    {insql=0;}
    break;

  case 1304:
#line 6542 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1305:
#line 6547 "fgl.yacc"
    {insql=1;}
    break;

  case 1306:
#line 6547 "fgl.yacc"
    {insql=0;}
    break;

  case 1307:
#line 6547 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1308:
#line 6555 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1309:
#line 6556 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1311:
#line 6561 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1312:
#line 6566 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1313:
#line 6567 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1314:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1315:
#line 6569 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1316:
#line 6570 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1318:
#line 6575 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1319:
#line 6575 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1321:
#line 6579 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1322:
#line 6583 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1323:
#line 6584 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1324:
#line 6587 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1325:
#line 6588 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1326:
#line 6591 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1327:
#line 6594 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1328:
#line 6597 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1329:
#line 6603 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1330:
#line 6605 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1332:
#line 6618 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1333:
#line 6622 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1334:
#line 6623 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1336:
#line 6628 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1337:
#line 6631 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1338:
#line 6637 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1339:
#line 6640 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1340:
#line 6648 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6655 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1343:
#line 6659 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1344:
#line 6663 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1345:
#line 6669 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1346:
#line 6672 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1347:
#line 6681 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1348:
#line 6684 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1349:
#line 6687 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1350:
#line 6690 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1351:
#line 6693 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1352:
#line 6696 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1353:
#line 6699 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1354:
#line 6706 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1355:
#line 6709 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1356:
#line 6716 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1357:
#line 6719 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1358:
#line 6725 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1359:
#line 6728 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1360:
#line 6735 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1361:
#line 6738 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1363:
#line 6746 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1365:
#line 6755 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1366:
#line 6758 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1367:
#line 6764 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1368:
#line 6767 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1369:
#line 6773 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1370:
#line 6780 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1371:
#line 6781 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1372:
#line 6785 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1373:
#line 6795 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1374:
#line 6798 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1375:
#line 6804 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1376:
#line 6806 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1377:
#line 6811 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1378:
#line 6812 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6817 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1380:
#line 6818 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1381:
#line 6824 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1382:
#line 6825 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6852 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6858 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1393:
#line 6861 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1394:
#line 6864 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1395:
#line 6870 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1397:
#line 6876 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1399:
#line 6887 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1400:
#line 6901 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1401:
#line 6910 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1402:
#line 6910 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1403:
#line 6915 "fgl.yacc"
    {insql=1;}
    break;

  case 1404:
#line 6915 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1405:
#line 6920 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1406:
#line 6923 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1407:
#line 6925 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6932 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6936 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1411:
#line 6940 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1412:
#line 6947 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1413:
#line 6950 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1414:
#line 6957 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1415:
#line 6961 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1416:
#line 6967 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1417:
#line 6972 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1418:
#line 6976 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1419:
#line 6982 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1420:
#line 6985 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1421:
#line 6991 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1422:
#line 6998 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1423:
#line 7002 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1424:
#line 7007 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1425:
#line 7017 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1426:
#line 7020 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1427:
#line 7022 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1428:
#line 7024 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1429:
#line 7026 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1430:
#line 7028 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1431:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1432:
#line 7032 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1433:
#line 7038 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1434:
#line 7048 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1435:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 7061 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7064 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7071 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1444:
#line 7076 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1445:
#line 7081 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1446:
#line 7088 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1447:
#line 7089 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1448:
#line 7096 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1449:
#line 7107 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1450:
#line 7108 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1451:
#line 7109 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1452:
#line 7112 "fgl.yacc"
    {insql=1;}
    break;

  case 1453:
#line 7112 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1454:
#line 7117 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1455:
#line 7122 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1457:
#line 7128 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1459:
#line 7132 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1460:
#line 7137 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1461:
#line 7142 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1462:
#line 7146 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1464:
#line 7152 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1465:
#line 7156 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1466:
#line 7163 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 7164 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7165 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7166 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7176 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 7177 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1475:
#line 7178 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1476:
#line 7182 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1477:
#line 7183 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1480:
#line 7190 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 7193 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7196 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1487:
#line 7201 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1488:
#line 7203 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1490:
#line 7209 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 7215 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 7225 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1496:
#line 7230 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1497:
#line 7232 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7238 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 7241 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1502:
#line 7247 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1503:
#line 7255 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1504:
#line 7260 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 7270 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 7276 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1510:
#line 7281 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1511:
#line 7284 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1512:
#line 7289 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1514:
#line 7295 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1515:
#line 7300 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1516:
#line 7303 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1517:
#line 7306 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1518:
#line 7313 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1519:
#line 7314 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1520:
#line 7315 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1521:
#line 7317 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1522:
#line 7330 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1523:
#line 7335 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1525:
#line 7339 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1526:
#line 7341 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1527:
#line 7348 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1528:
#line 7351 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1529:
#line 7357 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1530:
#line 7365 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1531:
#line 7369 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1532:
#line 7373 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1533:
#line 7377 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1534:
#line 7382 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1535:
#line 7385 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1536:
#line 7388 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1537:
#line 7396 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1538:
#line 7403 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1541:
#line 7412 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1542:
#line 7418 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1543:
#line 7421 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1544:
#line 7432 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1545:
#line 7439 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1546:
#line 7445 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1547:
#line 7448 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1548:
#line 7455 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1549:
#line 7462 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1551:
#line 7469 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1552:
#line 7475 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1553:
#line 7476 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1554:
#line 7477 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1556:
#line 7481 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1557:
#line 7488 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1559:
#line 7495 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1560:
#line 7502 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1561:
#line 7507 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1562:
#line 7508 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1563:
#line 7511 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1564:
#line 7514 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1565:
#line 7519 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1566:
#line 7520 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1567:
#line 7525 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1568:
#line 7528 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1569:
#line 7534 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1570:
#line 7537 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1571:
#line 7543 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1572:
#line 7546 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1573:
#line 7552 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1574:
#line 7555 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1575:
#line 7562 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1576:
#line 7563 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1577:
#line 7592 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1578:
#line 7593 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1579:
#line 7597 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1581:
#line 7610 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1582:
#line 7613 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1583:
#line 7616 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1584:
#line 7619 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1586:
#line 7627 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1587:
#line 7630 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1589:
#line 7636 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1591:
#line 7642 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1592:
#line 7645 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1593:
#line 7648 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1594:
#line 7651 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1595:
#line 7654 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1596:
#line 7657 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1597:
#line 7660 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1598:
#line 7663 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1599:
#line 7668 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1601:
#line 7675 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1605:
#line 7681 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1606:
#line 7682 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1607:
#line 7687 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1608:
#line 7690 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1609:
#line 7694 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7700 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1611:
#line 7701 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1612:
#line 7702 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1613:
#line 7703 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1618:
#line 7723 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1620:
#line 7727 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1621:
#line 7728 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1623:
#line 7731 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1624:
#line 7732 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1625:
#line 7741 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1632:
#line 7755 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1633:
#line 7757 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1634:
#line 7759 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1636:
#line 7762 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1638:
#line 7765 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1642:
#line 7770 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1643:
#line 7772 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1644:
#line 7775 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1645:
#line 7776 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1646:
#line 7783 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1650:
#line 7788 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1654:
#line 7804 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1655:
#line 7811 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1656:
#line 7815 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1657:
#line 7816 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1658:
#line 7817 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1659:
#line 7825 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1660:
#line 7826 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1661:
#line 7827 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1662:
#line 7838 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1663:
#line 7845 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1664:
#line 7850 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1665:
#line 7851 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1666:
#line 7852 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1667:
#line 7860 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1668:
#line 7861 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1669:
#line 7862 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1671:
#line 7888 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1672:
#line 7889 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1673:
#line 7890 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1674:
#line 7894 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1675:
#line 7897 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1676:
#line 7903 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1677:
#line 7908 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1678:
#line 7913 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1680:
#line 7924 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1684:
#line 7942 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1685:
#line 7945 "fgl.yacc"
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

  case 1686:
#line 7958 "fgl.yacc"
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

  case 1687:
#line 7973 "fgl.yacc"
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

  case 1688:
#line 7985 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1689:
#line 7987 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1690:
#line 7990 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1691:
#line 7990 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1692:
#line 7990 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1693:
#line 7990 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1694:
#line 7990 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1695:
#line 7990 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1696:
#line 7991 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1697:
#line 7994 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1712:
#line 8012 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1713:
#line 8015 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1714:
#line 8016 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1715:
#line 8017 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1716:
#line 8021 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1717:
#line 8029 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1718:
#line 8029 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1719:
#line 8035 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1720:
#line 8035 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1721:
#line 8042 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1722:
#line 8042 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1723:
#line 8048 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1724:
#line 8048 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1725:
#line 8056 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1726:
#line 8057 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1727:
#line 8058 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1728:
#line 8061 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1729:
#line 8061 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1731:
#line 8065 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1732:
#line 8066 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1733:
#line 8077 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1734:
#line 8080 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1735:
#line 8086 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1736:
#line 8091 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1737:
#line 8099 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1738:
#line 8111 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1739:
#line 8112 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1740:
#line 8115 "fgl.yacc"
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

  case 1741:
#line 8130 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1742:
#line 8141 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1743:
#line 8144 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1744:
#line 8152 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1745:
#line 8161 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1746:
#line 8164 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1747:
#line 8168 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1748:
#line 8171 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1749:
#line 8172 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1751:
#line 8185 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1752:
#line 8186 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1753:
#line 8195 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1754:
#line 8204 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1755:
#line 8209 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1756:
#line 8210 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1757:
#line 8211 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1758:
#line 8212 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1759:
#line 8219 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1760:
#line 8222 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1761:
#line 8228 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1762:
#line 8231 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1763:
#line 8238 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1764:
#line 8250 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1765:
#line 8259 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1766:
#line 8262 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1767:
#line 8265 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1768:
#line 8271 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1769:
#line 8279 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1770:
#line 8282 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1771:
#line 8283 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1772:
#line 8284 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1773:
#line 8285 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1774:
#line 8286 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1775:
#line 8289 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1776:
#line 8296 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1777:
#line 8298 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1778:
#line 8300 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1779:
#line 8302 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1780:
#line 8304 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1781:
#line 8305 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1782:
#line 8306 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1783:
#line 8307 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1784:
#line 8308 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1785:
#line 8309 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1786:
#line 8310 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1787:
#line 8312 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1788:
#line 8314 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1789:
#line 8316 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1790:
#line 8318 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1791:
#line 8320 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1792:
#line 8322 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1793:
#line 8324 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1794:
#line 8325 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1795:
#line 8327 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1796:
#line 8328 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1797:
#line 8329 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1798:
#line 8335 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1799:
#line 8336 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1801:
#line 8346 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1802:
#line 8354 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1803:
#line 8358 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1804:
#line 8365 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1805:
#line 8365 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1807:
#line 8369 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1808:
#line 8374 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1809:
#line 8374 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1811:
#line 8378 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1812:
#line 8382 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1815:
#line 8391 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1816:
#line 8391 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1821:
#line 8410 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1822:
#line 8411 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1825:
#line 8419 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1826:
#line 8425 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1829:
#line 8444 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1830:
#line 8445 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1831:
#line 8446 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1832:
#line 8447 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1833:
#line 8448 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1834:
#line 8449 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1835:
#line 8453 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1836:
#line 8454 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1837:
#line 8455 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1839:
#line 8460 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1840:
#line 8461 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1841:
#line 8465 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1842:
#line 8481 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1843:
#line 8482 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1844:
#line 8483 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1845:
#line 8487 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1846:
#line 8501 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1847:
#line 8505 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1849:
#line 8514 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1851:
#line 8519 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1852:
#line 8520 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1853:
#line 8844 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1854:
#line 8844 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1855:
#line 8851 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1856:
#line 8851 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1857:
#line 8939 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1858:
#line 8943 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1859:
#line 8945 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1860:
#line 8952 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1861:
#line 8956 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1862:
#line 8962 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1863:
#line 8970 "fgl.yacc"
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

  case 1864:
#line 8980 "fgl.yacc"
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

  case 1865:
#line 8990 "fgl.yacc"
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

  case 1866:
#line 9002 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1867:
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

  case 1868:
#line 9024 "fgl.yacc"
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

  case 1869:
#line 9050 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1870:
#line 9053 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1872:
#line 9062 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1873:
#line 9067 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1874:
#line 9070 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1875:
#line 9078 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1876:
#line 9086 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1877:
#line 9099 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1878:
#line 9102 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1879:
#line 9110 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1880:
#line 9113 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1881:
#line 9116 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1882:
#line 9124 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1883:
#line 9128 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1884:
#line 9129 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1885:
#line 9130 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1886:
#line 9131 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1887:
#line 9132 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1888:
#line 9133 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1889:
#line 9134 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1890:
#line 9135 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1891:
#line 9139 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1892:
#line 9140 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1893:
#line 9141 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1894:
#line 9142 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1895:
#line 9143 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1896:
#line 9149 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1897:
#line 9150 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1898:
#line 9151 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1899:
#line 9152 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1900:
#line 9153 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1901:
#line 9154 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1902:
#line 9155 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1903:
#line 9156 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1904:
#line 9157 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1905:
#line 9158 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1906:
#line 9159 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1907:
#line 9160 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1908:
#line 9161 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1909:
#line 9162 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1910:
#line 9163 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1911:
#line 9164 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1912:
#line 9169 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1913:
#line 9175 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1914:
#line 9176 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1915:
#line 9184 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1916:
#line 9186 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1918:
#line 9192 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1919:
#line 9196 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1920:
#line 9200 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1921:
#line 9216 "fgl.yacc"
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

  case 1922:
#line 9230 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1923:
#line 9236 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1924:
#line 9238 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1928:
#line 9252 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1929:
#line 9255 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1930:
#line 9262 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1931:
#line 9265 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1932:
#line 9295 "fgl.yacc"
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

  case 1933:
#line 9320 "fgl.yacc"
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

  case 1934:
#line 9375 "fgl.yacc"
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

  case 1935:
#line 9410 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1936:
#line 9419 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1937:
#line 9430 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1938:
#line 9433 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1939:
#line 9439 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1940:
#line 9452 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1941:
#line 9466 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1942:
#line 9469 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1943:
#line 9473 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1944:
#line 9488 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1945:
#line 9488 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1946:
#line 9494 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1947:
#line 9495 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1948:
#line 9498 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1949:
#line 9499 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1950:
#line 9500 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1951:
#line 9501 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1952:
#line 9502 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1953:
#line 9503 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1954:
#line 9504 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1955:
#line 9515 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1956:
#line 9519 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1957:
#line 9523 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1958:
#line 9527 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1959:
#line 9532 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1960:
#line 9536 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1961:
#line 9541 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1963:
#line 9549 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1965:
#line 9555 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1966:
#line 9561 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1967:
#line 9565 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1972:
#line 9583 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1973:
#line 9590 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1974:
#line 9600 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1975:
#line 9600 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18981 "y.tab.c"

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


#line 1011 "fgl.yacc"

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



