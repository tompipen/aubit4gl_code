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
     MATCHES = 1434,
     POWER = 1539,
     LESS_THAN = 1535,
     GREATER_THAN = 1451,
     EQUAL = 1611,
     GREATER_THAN_EQ = 1353,
     LESS_THAN_EQ = 1410,
     NOT_EQUAL = 1482,
     PLUS = 1647,
     MINUS = 1634,
     MULTIPLY = 1540,
     DIVIDE = 1567,
     MOD = 1635,
     COMMAND = 1417,
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
     MISC_INFX_SQL = 1001,
     DATETIME_VALUE = 1002,
     INTERVAL_VALUE = 1003,
     IN_LINE_MODE = 1004,
     IN_FORM_MODE = 1005,
     FGL_SIZEOF = 1006,
     IMPORT_PACKAGE = 1007,
     DYNAMIC_ARRAY = 1008,
     RESIZE_ARRAY = 1009,
     ALLOCATE_ARRAY = 1010,
     DEALLOCATE_ARRAY = 1011,
     AFTER_INSERT_DELETE = 1012,
     BEFORE_INSERT_DELETE = 1013,
     BEFORE_INSERT = 1014,
     AS_CONVERTABLE = 1015,
     CONCAT_PIPES = 1016,
     BEFORE_DELETE = 1017,
     DROP_TRIGGER = 1018,
     AFTER_INSERT = 1019,
     AFTER_DELETE = 1020,
     EXECUTE_IMMEDIATE = 1021,
     DELETE_ROW_EQUAL_TRUE = 1022,
     INSERT_ROW_EQUAL_TRUE = 1023,
     DELETE_ROW_EQUAL_FALSE = 1024,
     INSERT_ROW_EQUAL_FALSE = 1025,
     CURRENT_ROW_DISPLAY_EQUAL = 1026,
     MAXCOUNT = 1027,
     ALTER_TABLE = 1028,
     ALTER_INDEX = 1029,
     NEXT_SIZE = 1030,
     DISPLAY_ATTR_FORM = 1031,
     DISPLAY_ATTR_WINDOW = 1032,
     INPUT_ATTR_FORM = 1033,
     INPUT_ATTR_WINDOW = 1034,
     WHENEVER_ERROR_CONTINUE = 1035,
     WHENEVER_ANY_ERROR_CONTINUE = 1036,
     WHENEVER_WARNING_CONTINUE = 1037,
     WHENEVER_SQLSUCCESS_CONTINUE = 1038,
     WHENEVER_SQLWARNING_CONTINUE = 1039,
     WHENEVER_NOT_FOUND_CONTINUE = 1040,
     WHENEVER_SQLERROR_CONTINUE = 1041,
     WHENEVER_SUCCESS_CONTINUE = 1042,
     WHENEVER_ERROR_GOTO = 1043,
     WHENEVER_ANY_ERROR_GOTO = 1044,
     WHENEVER_WARNING_GOTO = 1045,
     WHENEVER_SQLSUCCESS_GOTO = 1046,
     WHENEVER_SQLWARNING_GOTO = 1047,
     WHENEVER_NOT_FOUND_GOTO = 1048,
     WHENEVER_SQLERROR_GOTO = 1049,
     WHENEVER_SUCCESS_GOTO = 1050,
     WHENEVER_ERROR_CALL = 1051,
     WHENEVER_ANY_ERROR_CALL = 1052,
     WHENEVER_WARNING_CALL = 1053,
     WHENEVER_SQLSUCCESS_CALL = 1054,
     WHENEVER_SQLWARNING_CALL = 1055,
     WHENEVER_NOT_FOUND_CALL = 1056,
     WHENEVER_SQLERROR_CALL = 1057,
     WHENEVER_SUCCESS_CALL = 1058,
     WHENEVER_ERROR_STOP = 1059,
     WHENEVER_ANY_ERROR_STOP = 1060,
     WHENEVER_WARNING_STOP = 1061,
     WHENEVER_SQLSUCCESS_STOP = 1062,
     WHENEVER_SQLWARNING_STOP = 1063,
     WHENEVER_NOT_FOUND_STOP = 1064,
     WHENEVER_SQLERROR_STOP = 1065,
     WHENEVER_SUCCESS_STOP = 1066,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1067,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1068,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1069,
     XSET_MULTIPLY_EQUAL = 1070,
     XSET_OPEN_BRACKET = 1071,
     NEWFORMATSHARED = 1072,
     CREATE_DATABASE = 1073,
     DROP_DATABASE = 1074,
     IMPORT_LEGACY_FUNCTION = 1075,
     ADD_CONSTRAINT = 1076,
     DROP_CONSTRAINT = 1077,
     DROP_SYNONYM = 1078,
     CONSTRAINT = 1079,
     AS_STATIC = 1080,
     NOT_FIELD_TOUCHED = 1081,
     LOCAL_FUNCTION = 1082,
     EVERY_ROW = 1083,
     ELIF = 1084,
     DOUBLE_PRECISION = 1085,
     COUNT_MULTIPLY = 1086,
     WAIT_FOR_KEY = 1087,
     AT_TERMINATION_CALL = 1088,
     TERMINATE_REPORT = 1089,
     TO_MAIN_CAPTION = 1090,
     CLEARSTAT = 1091,
     TO_MENUITEM = 1092,
     ID_TO_INT = 1093,
     TO_STATUSBOX = 1094,
     ASCII_HEIGHT_ALL = 1095,
     ASCII_WIDTH_ALL = 1096,
     IMPORT_DATATYPE = 1097,
     PAGE_TRAILER_SIZE = 1098,
     PAGE_HEADER_SIZE = 1099,
     FIRST_PAGE_HEADER_SIZE = 1100,
     BYTES_USE_AS_IMAGE = 1101,
     BYTES_USE_AS_ASCII = 1102,
     KWUP_BY = 1103,
     KWDOWN_BY = 1104,
     CLOSE_STATUSBOX = 1105,
     MODIFY_NEXT_SIZE = 1106,
     LOCK_MODE_PAGE = 1107,
     LOCK_MODE_ROW = 1108,
     TO_PIPE = 1109,
     TO_SCREEN = 1110,
     TO_PRINTER = 1111,
     STATUSBOX = 1112,
     FORMHANDLER_INPUT = 1113,
     UNITS_YEAR = 1114,
     UNITS_MONTH = 1115,
     UNITS_DAY = 1116,
     UNITS_HOUR = 1117,
     UNITS_MINUTE = 1118,
     UNITS_SECOND = 1119,
     NO_NEW_LINES = 1120,
     FIELDTOWIDGET = 1121,
     WITH_HOLD = 1122,
     SHOW_MENU = 1123,
     TO_CLUSTER = 1124,
     TO_NOT_CLUSTER = 1125,
     CWIS = 1126,
     CREATE_IDX = 1127,
     FORM_IS_COMPILED = 1128,
     PDF_REPORT = 1129,
     IMPORT_FUNCTION = 1130,
     PROMPT_MANY = 1131,
     POINTS = 1132,
     MM = 1133,
     INCHES = 1134,
     PREPEND = 1135,
     MEMBER_OF = 1136,
     APPEND = 1137,
     TEMPLATE = 1138,
     END_TEMPLATE = 1139,
     SQLSICS = 1140,
     CREATE_SCHEMA = 1141,
     SQLSIRR = 1142,
     UPDATESTATS_T = 1143,
     SQLSICR = 1144,
     WHENEVER_SQLSUCCESS = 1145,
     WHENEVER_SQLWARNING = 1146,
     WHENEVER_ANY_ERROR = 1147,
     WHENEVER_NOT_FOUND = 1148,
     WHENEVER_SQLERROR = 1149,
     WHENEVER_SUCCESS = 1150,
     WHENEVER_ERROR = 1151,
     START_EXTERN = 1152,
     CONTINUE_CONSTRUCT = 1153,
     FOUNCONSTR = 1154,
     SQLSIDR = 1155,
     CREATE_TEMP_TABLE = 1156,
     CURRENT_WINDOW_IS = 1157,
     FIRST_PAGE_HEADER = 1158,
     ORDER_EXTERNAL_BY = 1159,
     SCROLL_CURSOR_FOR = 1160,
     SCROLL_CURSOR = 1161,
     SQL_INTERRUPT_OFF = 1162,
     STOP_ALL_EXTERNAL = 1163,
     WITH_CHECK_OPTION = 1164,
     WITH_GRANT_OPTION = 1165,
     SQLSLMNW = 1166,
     ADDCONSTUNIQ = 1167,
     CONTINUE_DISPLAY = 1168,
     CONTINUE_FOREACH = 1169,
     OUTPUT_TO_REPORT = 1170,
     SQL_INTERRUPT_ON = 1171,
     WHERE_CURRENT_OF = 1172,
     WITHOUT_DEFAULTS = 1173,
     FOCONSTR = 1174,
     SCALED_BY = 1175,
     CONTINUE_PROMPT = 1176,
     PDF_FUNCTION = 1177,
     DEFER_INTERRUPT = 1178,
     DISPLAY_BY_NAME = 1179,
     NOT_NULL_UNIQUE = 1180,
     SKIP_TO_TOP = 1181,
     TOP_OF_PAGE = 1182,
     SKIP_TO = 1183,
     SKIP_BY = 1184,
     WITHOUT_WAITING = 1185,
     BEFCONSTRUCT = 1186,
     SQLSLMW = 1187,
     AFTCONSTRUCT = 1188,
     ALL_PRIVILEGES = 1189,
     CLOSE_DATABASE = 1190,
     CONTINUE_INPUT = 1191,
     CONTINUE_WHILE = 1192,
     CREATE_SYNONYM = 1193,
     DROP_TABLE = 1194,
     EXIT_CONSTRUCT = 1195,
     INEXCLUSIVE = 1196,
     REPORT_TO_PRINTER = 1197,
     REPORT_TO_PIPE = 1198,
     RETURN = 1199,
     SET_SESSION_TO = 1200,
     UPDATESTATS = 1201,
     WITHOUT_HEAD = 1202,
     CLEARSCR = 1203,
     WITH_B_LOG = 1204,
     AUTHORIZATION = 1205,
     BOTTOM_MARGIN = 1206,
     CLOSE_SESSION = 1207,
     CONTINUE_CASE = 1208,
     CONTINUE_MENU = 1209,
     DISPLAY_ARRAY = 1210,
     END_SQL = 1211,
     DOLLAR = 1212,
     END_CONSTRUCT = 1213,
     FIELD_TOUCHED = 1214,
     FINISH_REPORT = 1215,
     INFACC = 1216,
     INPUT_NO_WRAP = 1217,
     SETPMOFF = 1218,
     UNCONSTRAINED = 1219,
     PAGE_TRAILER = 1220,
     SETPMON = 1221,
     BEFGROUP = 1222,
     CLOSE_WINDOW = 1223,
     COMMENT_LINE = 1224,
     CONTINUE_FOR = 1225,
     CREATE_DB = 1226,
     CREATE_TABLE = 1227,
     DEFAULT_NULL = 1228,
     DEFAULT_TODAY = 1229,
     DEFAULT_USER = 1230,
     DELETE_USING = 1231,
     DISPLAY_FORM = 1232,
     END_FUNCTION = 1233,
     EXIT_DISPLAY = 1234,
     EXIT_FOREACH = 1235,
     EXIT_PROGRAM = 1236,
     INFCOLS = 1237,
     ON_EVERY_ROW = 1238,
     OPEN_SESSION = 1239,
     RIGHT_MARGIN = 1240,
     SELECT_USING = 1241,
     START_REPORT = 1242,
     UNLOCK_TABLE = 1243,
     UPDATE_USING = 1244,
     ACL_BUILTIN = 1245,
     AFTGROUP = 1246,
     INFIDX = 1247,
     INFSTAT = 1248,
     LEFT_MARGIN = 1249,
     PAGE_HEADER = 1250,
     ROLLBACK_W = 1251,
     SET_SESSION = 1252,
     SQLSEOFF = 1253,
     WITH_A_LOG = 1254,
     BEFDISP = 1255,
     BEFORE_MENU = 1256,
     CREATE_VIEW = 1257,
     DEFINE_TYPE = 1258,
     DELETE_FROM = 1259,
     END_DISPLAY = 1260,
     END_REPORT = 1261,
     END_FOREACH = 1262,
     END_FOR = 1263,
     END_GLOBALS = 1264,
     EXIT_PROMPT = 1265,
     EXTENT_SIZE = 1266,
     FOREIGN_KEY = 1267,
     HIDE_OPTION = 1268,
     HIDE_WINDOW = 1269,
     INSERT_INTO = 1270,
     IS_NOT_NULL = 1271,
     MOVE_WINDOW = 1272,
     NEXT_OPTION = 1273,
     NOT_MATCHES = 1274,
     ON_LAST_ROW = 1275,
     OPEN_WINDOW = 1276,
     OPEN_STATUSBOX = 1277,
     PAGE_LENGTH = 1278,
     PAGE_WIDTH = 1279,
     PRIMARY_KEY = 1280,
     PROMPT_LINE = 1281,
     RECORD_LIKE = 1282,
     ROLLFORWARD = 1283,
     SHOW_OPTION = 1284,
     SHOW_WINDOW = 1285,
     SQLSEON = 1286,
     TO_DATABASE = 1287,
     USE_SESSION = 1288,
     WITH_NO_LOG = 1289,
     AFTDISP = 1290,
     BEFFIELD = 1291,
     INSHARE = 1292,
     UNLOCKTAB = 1293,
     AFTFIELD = 1294,
     ATTRIBUTES = 1295,
     BEFINP = 1296,
     BEGIN_WORK = 1297,
     CLEARWIN = 1298,
     CLOSE_FORM = 1299,
     DEFER_QUIT = 1300,
     DESCENDING = 1301,
     DROP_INDEX = 1302,
     END_PROMPT = 1303,
     END_RECORD = 1304,
     ERROR_LINE = 1305,
     EXIT_INPUT = 1306,
     EXIT_WHILE = 1307,
     FOR_UPDATE_OF = 1308,
     FOR_UPDATE = 1309,
     GET_FLDBUF = 1310,
     INITIALIZE = 1311,
     INPUT_WRAP = 1312,
     LOCK_TABLE = 1313,
     MSG_LINE = 1314,
     NOT_EXISTS = 1315,
     ON_ANY_KEY = 1316,
     REFERENCES = 1317,
     RENCOL = 1318,
     SET_CURSOR = 1319,
     SMALLFLOAT = 1320,
     SQLSUCCESS = 1321,
     TOP_MARGIN = 1322,
     WITH_ARRAY = 1323,
     ACCEPTKEY = 1324,
     ACCEPT = 1325,
     AFTINP = 1326,
     CLEARFORMTODEFAULTS = 1327,
     CLEARFORM = 1328,
     CLEAR_X_FORM = 1329,
     COMMIT_W = 1330,
     NEXTPAGE = 1331,
     PREVPAGE = 1332,
     CTRL_KEY = 1333,
     INFTABS = 1334,
     NEXTFIELD = 1335,
     NEXTFORM = 1336,
     RENTAB = 1337,
     ASCENDING = 1338,
     ASSOCIATE = 1339,
     CHAR = 1340,
     NCHAR = 1341,
     NVARCHAR = 1342,
     CONSTRUCT = 1343,
     DELIMITER = 1344,
     DOWNSHIFT = 1345,
     DROP_VIEW = 1346,
     END_INPUT = 1347,
     END_WHILE = 1348,
     EXCLUSIVE = 1349,
     EXIT_CASE = 1350,
     EXIT_MENU = 1351,
     FORM_LINE = 1352,
     INTERRUPT = 1354,
     INTO_TEMP = 1355,
     INVISIBLE = 1356,
     IN_MEMORY = 1357,
     LINKED_TO = 1358,
     LOAD_FROM = 1359,
     LOCKTAB = 1360,
     MENU_LINE = 1361,
     OPEN_FORM = 1362,
     OTHERWISE = 1363,
     PRECISION = 1364,
     PRIOR = 1365,
     PROCEDURE = 1366,
     REPORT_TO = 1367,
     RETURNING = 1368,
     UNDERLINE = 1369,
     UNLOAD_TO = 1370,
     BEFROW = 1371,
     UNLOAD_T = 1372,
     VARIABLE = 1373,
     ABSOLUTE = 1374,
     AFTROW = 1375,
     BUFFERED = 1376,
     CONSTANT = 1377,
     CONST = 1378,
     DATABASE = 1379,
     DATETIME = 1380,
     DEFAULTS = 1381,
     DISTINCT = 1382,
     END_CASE = 1383,
     END_MAIN = 1384,
     END_MENU = 1385,
     END_TYPE = 1386,
     EXIT_FOR = 1387,
     EXTERNAL = 1388,
     FRACTION = 1389,
     FUNCTION = 1390,
     GROUP_BY = 1391,
     INTERVAL = 1392,
     KWMESSAGE = 1393,
     NOT_LIKE = 1394,
     NOT_ILIKE = 1395,
     NOT_NULL = 1396,
     PASSWORD = 1397,
     PREVIOUS = 1398,
     READONLY = 1399,
     REGISTER = 1400,
     RELATIVE = 1401,
     RESOURCE = 1402,
     SMALLINT = 1403,
     VALIDATE = 1404,
     WITH_LOG = 1405,
     WORDWRAP = 1406,
     BY_NAME = 1407,
     IN_FILE = 1408,
     IS_NULL = 1409,
     AVERAGE = 1411,
     BETWEEN = 1412,
     CAPTION = 1413,
     CLIPPED = 1414,
     CLOSE_BRACKET = 1415,
     COLUMNS = 1416,
     CONNECT = 1418,
     CURRENT = 1419,
     DBYNAME = 1420,
     DECIMAL = 1421,
     DECLARE = 1422,
     DEFAULT = 1423,
     DISPLAY = 1424,
     ENDCODE = 1425,
     EXECUTE = 1426,
     FOREACH = 1427,
     FOREIGN = 1428,
     GLOBALS = 1429,
     INFIELD = 1430,
     INTEGER = 1431,
     KWWINDOW = 1432,
     MAGENTA = 1433,
     OPTIONS = 1435,
     PERCENT = 1436,
     PREPARE = 1437,
     PROGRAM = 1438,
     RECOVER = 1439,
     REVERSE = 1440,
     SECTION = 1441,
     SESSION = 1442,
     SYNONYM = 1443,
     THRU = 1444,
     TRAILER = 1445,
     UPSHIFT = 1446,
     VARCHAR = 1447,
     WAITING = 1448,
     CLOSE_SHEV = 1449,
     CLOSE_SQUARE = 1450,
     KW_FALSE = 1452,
     NOT_IN = 1453,
     ONKEY = 1454,
     OPEN_BRACKET = 1455,
     BORDER = 1456,
     BOTTOM = 1457,
     COLUMN = 1458,
     COMMIT = 1459,
     CREATE = 1460,
     CURSOR = 1461,
     DEFINE = 1462,
     DELETE = 1463,
     DOUBLE = 1464,
     END_IF = 1465,
     ESCAPE = 1466,
     EXISTS = 1467,
     EXTEND = 1468,
     EXTENT = 1469,
     FINISH = 1470,
     FORMAT = 1471,
     HAVING = 1472,
     HEADER = 1473,
     INSERT = 1474,
     LOCATE = 1475,
     MARGIN = 1476,
     MEMORY = 1477,
     MINUTE = 1478,
     MODIFY = 1479,
     NORMAL = 1480,
     EQUAL_EQUAL = 1481,
     OPEN_SHEV = 1483,
     OPEN_SQUARE = 1484,
     OPTION = 1485,
     OUTPUT = 1486,
     PROMPT = 1487,
     PUBLIC = 1488,
     RECORD = 1489,
     REPORT = 1490,
     REVOKE = 1491,
     SCHEMA = 1492,
     SCROLL_USING = 1493,
     SCROLL = 1494,
     SECOND = 1495,
     SELECT = 1496,
     SERIAL = 1497,
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
#define MATCHES 1434
#define POWER 1539
#define LESS_THAN 1535
#define GREATER_THAN 1451
#define EQUAL 1611
#define GREATER_THAN_EQ 1353
#define LESS_THAN_EQ 1410
#define NOT_EQUAL 1482
#define PLUS 1647
#define MINUS 1634
#define MULTIPLY 1540
#define DIVIDE 1567
#define MOD 1635
#define COMMAND 1417
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
#define MISC_INFX_SQL 1001
#define DATETIME_VALUE 1002
#define INTERVAL_VALUE 1003
#define IN_LINE_MODE 1004
#define IN_FORM_MODE 1005
#define FGL_SIZEOF 1006
#define IMPORT_PACKAGE 1007
#define DYNAMIC_ARRAY 1008
#define RESIZE_ARRAY 1009
#define ALLOCATE_ARRAY 1010
#define DEALLOCATE_ARRAY 1011
#define AFTER_INSERT_DELETE 1012
#define BEFORE_INSERT_DELETE 1013
#define BEFORE_INSERT 1014
#define AS_CONVERTABLE 1015
#define CONCAT_PIPES 1016
#define BEFORE_DELETE 1017
#define DROP_TRIGGER 1018
#define AFTER_INSERT 1019
#define AFTER_DELETE 1020
#define EXECUTE_IMMEDIATE 1021
#define DELETE_ROW_EQUAL_TRUE 1022
#define INSERT_ROW_EQUAL_TRUE 1023
#define DELETE_ROW_EQUAL_FALSE 1024
#define INSERT_ROW_EQUAL_FALSE 1025
#define CURRENT_ROW_DISPLAY_EQUAL 1026
#define MAXCOUNT 1027
#define ALTER_TABLE 1028
#define ALTER_INDEX 1029
#define NEXT_SIZE 1030
#define DISPLAY_ATTR_FORM 1031
#define DISPLAY_ATTR_WINDOW 1032
#define INPUT_ATTR_FORM 1033
#define INPUT_ATTR_WINDOW 1034
#define WHENEVER_ERROR_CONTINUE 1035
#define WHENEVER_ANY_ERROR_CONTINUE 1036
#define WHENEVER_WARNING_CONTINUE 1037
#define WHENEVER_SQLSUCCESS_CONTINUE 1038
#define WHENEVER_SQLWARNING_CONTINUE 1039
#define WHENEVER_NOT_FOUND_CONTINUE 1040
#define WHENEVER_SQLERROR_CONTINUE 1041
#define WHENEVER_SUCCESS_CONTINUE 1042
#define WHENEVER_ERROR_GOTO 1043
#define WHENEVER_ANY_ERROR_GOTO 1044
#define WHENEVER_WARNING_GOTO 1045
#define WHENEVER_SQLSUCCESS_GOTO 1046
#define WHENEVER_SQLWARNING_GOTO 1047
#define WHENEVER_NOT_FOUND_GOTO 1048
#define WHENEVER_SQLERROR_GOTO 1049
#define WHENEVER_SUCCESS_GOTO 1050
#define WHENEVER_ERROR_CALL 1051
#define WHENEVER_ANY_ERROR_CALL 1052
#define WHENEVER_WARNING_CALL 1053
#define WHENEVER_SQLSUCCESS_CALL 1054
#define WHENEVER_SQLWARNING_CALL 1055
#define WHENEVER_NOT_FOUND_CALL 1056
#define WHENEVER_SQLERROR_CALL 1057
#define WHENEVER_SUCCESS_CALL 1058
#define WHENEVER_ERROR_STOP 1059
#define WHENEVER_ANY_ERROR_STOP 1060
#define WHENEVER_WARNING_STOP 1061
#define WHENEVER_SQLSUCCESS_STOP 1062
#define WHENEVER_SQLWARNING_STOP 1063
#define WHENEVER_NOT_FOUND_STOP 1064
#define WHENEVER_SQLERROR_STOP 1065
#define WHENEVER_SUCCESS_STOP 1066
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1067
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1068
#define XSET_ident_DOT_MULTIPLY_EQUAL 1069
#define XSET_MULTIPLY_EQUAL 1070
#define XSET_OPEN_BRACKET 1071
#define NEWFORMATSHARED 1072
#define CREATE_DATABASE 1073
#define DROP_DATABASE 1074
#define IMPORT_LEGACY_FUNCTION 1075
#define ADD_CONSTRAINT 1076
#define DROP_CONSTRAINT 1077
#define DROP_SYNONYM 1078
#define CONSTRAINT 1079
#define AS_STATIC 1080
#define NOT_FIELD_TOUCHED 1081
#define LOCAL_FUNCTION 1082
#define EVERY_ROW 1083
#define ELIF 1084
#define DOUBLE_PRECISION 1085
#define COUNT_MULTIPLY 1086
#define WAIT_FOR_KEY 1087
#define AT_TERMINATION_CALL 1088
#define TERMINATE_REPORT 1089
#define TO_MAIN_CAPTION 1090
#define CLEARSTAT 1091
#define TO_MENUITEM 1092
#define ID_TO_INT 1093
#define TO_STATUSBOX 1094
#define ASCII_HEIGHT_ALL 1095
#define ASCII_WIDTH_ALL 1096
#define IMPORT_DATATYPE 1097
#define PAGE_TRAILER_SIZE 1098
#define PAGE_HEADER_SIZE 1099
#define FIRST_PAGE_HEADER_SIZE 1100
#define BYTES_USE_AS_IMAGE 1101
#define BYTES_USE_AS_ASCII 1102
#define KWUP_BY 1103
#define KWDOWN_BY 1104
#define CLOSE_STATUSBOX 1105
#define MODIFY_NEXT_SIZE 1106
#define LOCK_MODE_PAGE 1107
#define LOCK_MODE_ROW 1108
#define TO_PIPE 1109
#define TO_SCREEN 1110
#define TO_PRINTER 1111
#define STATUSBOX 1112
#define FORMHANDLER_INPUT 1113
#define UNITS_YEAR 1114
#define UNITS_MONTH 1115
#define UNITS_DAY 1116
#define UNITS_HOUR 1117
#define UNITS_MINUTE 1118
#define UNITS_SECOND 1119
#define NO_NEW_LINES 1120
#define FIELDTOWIDGET 1121
#define WITH_HOLD 1122
#define SHOW_MENU 1123
#define TO_CLUSTER 1124
#define TO_NOT_CLUSTER 1125
#define CWIS 1126
#define CREATE_IDX 1127
#define FORM_IS_COMPILED 1128
#define PDF_REPORT 1129
#define IMPORT_FUNCTION 1130
#define PROMPT_MANY 1131
#define POINTS 1132
#define MM 1133
#define INCHES 1134
#define PREPEND 1135
#define MEMBER_OF 1136
#define APPEND 1137
#define TEMPLATE 1138
#define END_TEMPLATE 1139
#define SQLSICS 1140
#define CREATE_SCHEMA 1141
#define SQLSIRR 1142
#define UPDATESTATS_T 1143
#define SQLSICR 1144
#define WHENEVER_SQLSUCCESS 1145
#define WHENEVER_SQLWARNING 1146
#define WHENEVER_ANY_ERROR 1147
#define WHENEVER_NOT_FOUND 1148
#define WHENEVER_SQLERROR 1149
#define WHENEVER_SUCCESS 1150
#define WHENEVER_ERROR 1151
#define START_EXTERN 1152
#define CONTINUE_CONSTRUCT 1153
#define FOUNCONSTR 1154
#define SQLSIDR 1155
#define CREATE_TEMP_TABLE 1156
#define CURRENT_WINDOW_IS 1157
#define FIRST_PAGE_HEADER 1158
#define ORDER_EXTERNAL_BY 1159
#define SCROLL_CURSOR_FOR 1160
#define SCROLL_CURSOR 1161
#define SQL_INTERRUPT_OFF 1162
#define STOP_ALL_EXTERNAL 1163
#define WITH_CHECK_OPTION 1164
#define WITH_GRANT_OPTION 1165
#define SQLSLMNW 1166
#define ADDCONSTUNIQ 1167
#define CONTINUE_DISPLAY 1168
#define CONTINUE_FOREACH 1169
#define OUTPUT_TO_REPORT 1170
#define SQL_INTERRUPT_ON 1171
#define WHERE_CURRENT_OF 1172
#define WITHOUT_DEFAULTS 1173
#define FOCONSTR 1174
#define SCALED_BY 1175
#define CONTINUE_PROMPT 1176
#define PDF_FUNCTION 1177
#define DEFER_INTERRUPT 1178
#define DISPLAY_BY_NAME 1179
#define NOT_NULL_UNIQUE 1180
#define SKIP_TO_TOP 1181
#define TOP_OF_PAGE 1182
#define SKIP_TO 1183
#define SKIP_BY 1184
#define WITHOUT_WAITING 1185
#define BEFCONSTRUCT 1186
#define SQLSLMW 1187
#define AFTCONSTRUCT 1188
#define ALL_PRIVILEGES 1189
#define CLOSE_DATABASE 1190
#define CONTINUE_INPUT 1191
#define CONTINUE_WHILE 1192
#define CREATE_SYNONYM 1193
#define DROP_TABLE 1194
#define EXIT_CONSTRUCT 1195
#define INEXCLUSIVE 1196
#define REPORT_TO_PRINTER 1197
#define REPORT_TO_PIPE 1198
#define RETURN 1199
#define SET_SESSION_TO 1200
#define UPDATESTATS 1201
#define WITHOUT_HEAD 1202
#define CLEARSCR 1203
#define WITH_B_LOG 1204
#define AUTHORIZATION 1205
#define BOTTOM_MARGIN 1206
#define CLOSE_SESSION 1207
#define CONTINUE_CASE 1208
#define CONTINUE_MENU 1209
#define DISPLAY_ARRAY 1210
#define END_SQL 1211
#define DOLLAR 1212
#define END_CONSTRUCT 1213
#define FIELD_TOUCHED 1214
#define FINISH_REPORT 1215
#define INFACC 1216
#define INPUT_NO_WRAP 1217
#define SETPMOFF 1218
#define UNCONSTRAINED 1219
#define PAGE_TRAILER 1220
#define SETPMON 1221
#define BEFGROUP 1222
#define CLOSE_WINDOW 1223
#define COMMENT_LINE 1224
#define CONTINUE_FOR 1225
#define CREATE_DB 1226
#define CREATE_TABLE 1227
#define DEFAULT_NULL 1228
#define DEFAULT_TODAY 1229
#define DEFAULT_USER 1230
#define DELETE_USING 1231
#define DISPLAY_FORM 1232
#define END_FUNCTION 1233
#define EXIT_DISPLAY 1234
#define EXIT_FOREACH 1235
#define EXIT_PROGRAM 1236
#define INFCOLS 1237
#define ON_EVERY_ROW 1238
#define OPEN_SESSION 1239
#define RIGHT_MARGIN 1240
#define SELECT_USING 1241
#define START_REPORT 1242
#define UNLOCK_TABLE 1243
#define UPDATE_USING 1244
#define ACL_BUILTIN 1245
#define AFTGROUP 1246
#define INFIDX 1247
#define INFSTAT 1248
#define LEFT_MARGIN 1249
#define PAGE_HEADER 1250
#define ROLLBACK_W 1251
#define SET_SESSION 1252
#define SQLSEOFF 1253
#define WITH_A_LOG 1254
#define BEFDISP 1255
#define BEFORE_MENU 1256
#define CREATE_VIEW 1257
#define DEFINE_TYPE 1258
#define DELETE_FROM 1259
#define END_DISPLAY 1260
#define END_REPORT 1261
#define END_FOREACH 1262
#define END_FOR 1263
#define END_GLOBALS 1264
#define EXIT_PROMPT 1265
#define EXTENT_SIZE 1266
#define FOREIGN_KEY 1267
#define HIDE_OPTION 1268
#define HIDE_WINDOW 1269
#define INSERT_INTO 1270
#define IS_NOT_NULL 1271
#define MOVE_WINDOW 1272
#define NEXT_OPTION 1273
#define NOT_MATCHES 1274
#define ON_LAST_ROW 1275
#define OPEN_WINDOW 1276
#define OPEN_STATUSBOX 1277
#define PAGE_LENGTH 1278
#define PAGE_WIDTH 1279
#define PRIMARY_KEY 1280
#define PROMPT_LINE 1281
#define RECORD_LIKE 1282
#define ROLLFORWARD 1283
#define SHOW_OPTION 1284
#define SHOW_WINDOW 1285
#define SQLSEON 1286
#define TO_DATABASE 1287
#define USE_SESSION 1288
#define WITH_NO_LOG 1289
#define AFTDISP 1290
#define BEFFIELD 1291
#define INSHARE 1292
#define UNLOCKTAB 1293
#define AFTFIELD 1294
#define ATTRIBUTES 1295
#define BEFINP 1296
#define BEGIN_WORK 1297
#define CLEARWIN 1298
#define CLOSE_FORM 1299
#define DEFER_QUIT 1300
#define DESCENDING 1301
#define DROP_INDEX 1302
#define END_PROMPT 1303
#define END_RECORD 1304
#define ERROR_LINE 1305
#define EXIT_INPUT 1306
#define EXIT_WHILE 1307
#define FOR_UPDATE_OF 1308
#define FOR_UPDATE 1309
#define GET_FLDBUF 1310
#define INITIALIZE 1311
#define INPUT_WRAP 1312
#define LOCK_TABLE 1313
#define MSG_LINE 1314
#define NOT_EXISTS 1315
#define ON_ANY_KEY 1316
#define REFERENCES 1317
#define RENCOL 1318
#define SET_CURSOR 1319
#define SMALLFLOAT 1320
#define SQLSUCCESS 1321
#define TOP_MARGIN 1322
#define WITH_ARRAY 1323
#define ACCEPTKEY 1324
#define ACCEPT 1325
#define AFTINP 1326
#define CLEARFORMTODEFAULTS 1327
#define CLEARFORM 1328
#define CLEAR_X_FORM 1329
#define COMMIT_W 1330
#define NEXTPAGE 1331
#define PREVPAGE 1332
#define CTRL_KEY 1333
#define INFTABS 1334
#define NEXTFIELD 1335
#define NEXTFORM 1336
#define RENTAB 1337
#define ASCENDING 1338
#define ASSOCIATE 1339
#define CHAR 1340
#define NCHAR 1341
#define NVARCHAR 1342
#define CONSTRUCT 1343
#define DELIMITER 1344
#define DOWNSHIFT 1345
#define DROP_VIEW 1346
#define END_INPUT 1347
#define END_WHILE 1348
#define EXCLUSIVE 1349
#define EXIT_CASE 1350
#define EXIT_MENU 1351
#define FORM_LINE 1352
#define INTERRUPT 1354
#define INTO_TEMP 1355
#define INVISIBLE 1356
#define IN_MEMORY 1357
#define LINKED_TO 1358
#define LOAD_FROM 1359
#define LOCKTAB 1360
#define MENU_LINE 1361
#define OPEN_FORM 1362
#define OTHERWISE 1363
#define PRECISION 1364
#define PRIOR 1365
#define PROCEDURE 1366
#define REPORT_TO 1367
#define RETURNING 1368
#define UNDERLINE 1369
#define UNLOAD_TO 1370
#define BEFROW 1371
#define UNLOAD_T 1372
#define VARIABLE 1373
#define ABSOLUTE 1374
#define AFTROW 1375
#define BUFFERED 1376
#define CONSTANT 1377
#define CONST 1378
#define DATABASE 1379
#define DATETIME 1380
#define DEFAULTS 1381
#define DISTINCT 1382
#define END_CASE 1383
#define END_MAIN 1384
#define END_MENU 1385
#define END_TYPE 1386
#define EXIT_FOR 1387
#define EXTERNAL 1388
#define FRACTION 1389
#define FUNCTION 1390
#define GROUP_BY 1391
#define INTERVAL 1392
#define KWMESSAGE 1393
#define NOT_LIKE 1394
#define NOT_ILIKE 1395
#define NOT_NULL 1396
#define PASSWORD 1397
#define PREVIOUS 1398
#define READONLY 1399
#define REGISTER 1400
#define RELATIVE 1401
#define RESOURCE 1402
#define SMALLINT 1403
#define VALIDATE 1404
#define WITH_LOG 1405
#define WORDWRAP 1406
#define BY_NAME 1407
#define IN_FILE 1408
#define IS_NULL 1409
#define AVERAGE 1411
#define BETWEEN 1412
#define CAPTION 1413
#define CLIPPED 1414
#define CLOSE_BRACKET 1415
#define COLUMNS 1416
#define CONNECT 1418
#define CURRENT 1419
#define DBYNAME 1420
#define DECIMAL 1421
#define DECLARE 1422
#define DEFAULT 1423
#define DISPLAY 1424
#define ENDCODE 1425
#define EXECUTE 1426
#define FOREACH 1427
#define FOREIGN 1428
#define GLOBALS 1429
#define INFIELD 1430
#define INTEGER 1431
#define KWWINDOW 1432
#define MAGENTA 1433
#define OPTIONS 1435
#define PERCENT 1436
#define PREPARE 1437
#define PROGRAM 1438
#define RECOVER 1439
#define REVERSE 1440
#define SECTION 1441
#define SESSION 1442
#define SYNONYM 1443
#define THRU 1444
#define TRAILER 1445
#define UPSHIFT 1446
#define VARCHAR 1447
#define WAITING 1448
#define CLOSE_SHEV 1449
#define CLOSE_SQUARE 1450
#define KW_FALSE 1452
#define NOT_IN 1453
#define ONKEY 1454
#define OPEN_BRACKET 1455
#define BORDER 1456
#define BOTTOM 1457
#define COLUMN 1458
#define COMMIT 1459
#define CREATE 1460
#define CURSOR 1461
#define DEFINE 1462
#define DELETE 1463
#define DOUBLE 1464
#define END_IF 1465
#define ESCAPE 1466
#define EXISTS 1467
#define EXTEND 1468
#define EXTENT 1469
#define FINISH 1470
#define FORMAT 1471
#define HAVING 1472
#define HEADER 1473
#define INSERT 1474
#define LOCATE 1475
#define MARGIN 1476
#define MEMORY 1477
#define MINUTE 1478
#define MODIFY 1479
#define NORMAL 1480
#define EQUAL_EQUAL 1481
#define OPEN_SHEV 1483
#define OPEN_SQUARE 1484
#define OPTION 1485
#define OUTPUT 1486
#define PROMPT 1487
#define PUBLIC 1488
#define RECORD 1489
#define REPORT 1490
#define REVOKE 1491
#define SCHEMA 1492
#define SCROLL_USING 1493
#define SCROLL 1494
#define SECOND 1495
#define SELECT 1496
#define SERIAL 1497
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
#define YYLAST   9909

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  735
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  876
/* YYNRULES -- Number of rules. */
#define YYNRULES  2066
/* YYNRULES -- Number of states. */
#define YYNSTATES  3507

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
     386,   387,   388,    15,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
      16,   445,   446,   447,   448,   449,   450,    23,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,    10,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,    13,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,    17,   513,   514,   515,   516,   517,   518,   519,
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
    1879,  1881,  1884,  1886,  1890,  1892,  1896,  1898,  1902,  1903,
    1904,  1905,  1915,  1916,  1920,  1921,  1922,  1933,  1934,  1936,
    1937,  1939,  1941,  1944,  1945,  1949,  1950,  1954,  1955,  1957,
    1959,  1962,  1963,  1967,  1968,  1972,  1976,  1978,  1983,  1987,
    1989,  1993,  1995,  1999,  2001,  2005,  2007,  2010,  2011,  2015,
    2016,  2020,  2021,  2026,  2027,  2032,  2033,  2038,  2039,  2040,
    2052,  2053,  2056,  2059,  2063,  2065,  2069,  2071,  2073,  2075,
    2077,  2079,  2081,  2083,  2087,  2089,  2091,  2096,  2103,  2108,
    2112,  2119,  2123,  2130,  2132,  2134,  2136,  2138,  2140,  2142,
    2144,  2146,  2147,  2150,  2152,  2154,  2156,  2161,  2163,  2165,
    2167,  2172,  2176,  2183,  2187,  2194,  2196,  2198,  2201,  2204,
    2206,  2209,  2212,  2214,  2218,  2220,  2223,  2226,  2229,  2234,
    2237,  2240,  2245,  2246,  2255,  2256,  2258,  2260,  2262,  2263,
    2265,  2268,  2269,  2271,  2274,  2275,  2277,  2280,  2281,  2283,
    2287,  2288,  2291,  2292,  2293,  2302,  2303,  2304,  2308,  2309,
    2310,  2318,  2324,  2327,  2330,  2333,  2334,  2340,  2345,  2347,
    2351,  2355,  2359,  2361,  2362,  2365,  2367,  2368,  2370,  2372,
    2375,  2376,  2381,  2382,  2387,  2388,  2392,  2393,  2397,  2398,
    2402,  2403,  2407,  2408,  2412,  2413,  2417,  2418,  2422,  2423,
    2427,  2428,  2432,  2433,  2437,  2438,  2442,  2444,  2448,  2450,
    2454,  2457,  2462,  2464,  2466,  2468,  2469,  2474,  2480,  2487,
    2488,  2499,  2503,  2506,  2509,  2511,  2513,  2516,  2519,  2520,
    2523,  2525,  2528,  2532,  2536,  2540,  2544,  2546,  2548,  2550,
    2552,  2553,  2557,  2559,  2560,  2564,  2567,  2570,  2572,  2576,
    2578,  2582,  2584,  2586,  2588,  2590,  2592,  2594,  2596,  2598,
    2600,  2602,  2604,  2606,  2608,  2610,  2612,  2614,  2616,  2618,
    2620,  2622,  2623,  2624,  2632,  2634,  2636,  2639,  2642,  2645,
    2649,  2654,  2656,  2658,  2660,  2661,  2665,  2666,  2668,  2670,
    2673,  2675,  2677,  2679,  2681,  2683,  2685,  2687,  2688,  2690,
    2692,  2695,  2698,  2700,  2702,  2704,  2706,  2708,  2710,  2712,
    2714,  2716,  2718,  2719,  2721,  2723,  2725,  2727,  2728,  2729,
    2730,  2731,  2745,  2747,  2748,  2749,  2756,  2759,  2761,  2764,
    2767,  2770,  2772,  2774,  2777,  2779,  2780,  2784,  2787,  2789,
    2791,  2793,  2794,  2795,  2803,  2805,  2808,  2809,  2813,  2814,
    2819,  2820,  2826,  2828,  2829,  2833,  2834,  2842,  2843,  2849,
    2851,  2854,  2855,  2857,  2859,  2861,  2862,  2864,  2866,  2869,
    2872,  2875,  2877,  2879,  2881,  2883,  2887,  2889,  2891,  2894,
    2895,  2898,  2900,  2902,  2904,  2906,  2908,  2910,  2912,  2916,
    2917,  2919,  2921,  2923,  2925,  2928,  2931,  2934,  2940,  2949,
    2951,  2953,  2955,  2960,  2965,  2967,  2969,  2971,  2973,  2976,
    2980,  2987,  2989,  2993,  2995,  2997,  2999,  3003,  3010,  3020,
    3022,  3024,  3026,  3028,  3031,  3032,  3034,  3036,  3040,  3042,
    3046,  3048,  3052,  3054,  3058,  3060,  3062,  3064,  3066,  3070,
    3072,  3076,  3078,  3082,  3084,  3086,  3088,  3092,  3095,  3096,
    3098,  3100,  3102,  3106,  3108,  3112,  3120,  3121,  3129,  3130,
    3137,  3141,  3143,  3147,  3149,  3152,  3158,  3159,  3167,  3168,
    3171,  3172,  3174,  3180,  3183,  3189,  3190,  3196,  3203,  3208,
    3209,  3211,  3213,  3219,  3220,  3223,  3224,  3230,  3235,  3238,
    3240,  3244,  3247,  3250,  3253,  3256,  3259,  3262,  3264,  3267,
    3270,  3273,  3276,  3279,  3282,  3285,  3287,  3289,  3291,  3293,
    3296,  3299,  3301,  3303,  3305,  3307,  3309,  3311,  3314,  3317,
    3319,  3321,  3323,  3325,  3331,  3333,  3335,  3338,  3343,  3348,
    3355,  3358,  3360,  3361,  3373,  3374,  3377,  3383,  3384,  3386,
    3387,  3390,  3392,  3395,  3396,  3400,  3402,  3403,  3408,  3409,
    3412,  3414,  3418,  3420,  3422,  3427,  3433,  3439,  3445,  3449,
    3450,  3452,  3454,  3456,  3458,  3459,  3461,  3469,  3472,  3475,
    3478,  3481,  3484,  3486,  3489,  3490,  3494,  3495,  3499,  3500,
    3504,  3505,  3509,  3510,  3514,  3515,  3520,  3521,  3526,  3528,
    3530,  3532,  3534,  3536,  3538,  3539,  3544,  3545,  3547,  3548,
    3553,  3555,  3558,  3561,  3564,  3565,  3567,  3569,  3572,  3575,
    3576,  3579,  3580,  3585,  3587,  3591,  3595,  3601,  3602,  3605,
    3610,  3612,  3614,  3616,  3618,  3620,  3621,  3623,  3625,  3629,
    3632,  3638,  3641,  3647,  3653,  3659,  3665,  3671,  3677,  3678,
    3681,  3683,  3686,  3689,  3692,  3695,  3698,  3701,  3703,  3706,
    3709,  3712,  3715,  3717,  3720,  3723,  3726,  3729,  3731,  3733,
    3735,  3736,  3739,  3742,  3745,  3748,  3751,  3754,  3757,  3760,
    3763,  3765,  3767,  3769,  3771,  3773,  3775,  3777,  3779,  3782,
    3785,  3788,  3791,  3794,  3796,  3798,  3800,  3801,  3805,  3808,
    3809,  3810,  3811,  3812,  3813,  3814,  3830,  3831,  3834,  3837,
    3838,  3840,  3841,  3842,  3843,  3844,  3845,  3846,  3862,  3865,
    3866,  3867,  3868,  3879,  3880,  3882,  3886,  3890,  3893,  3897,
    3902,  3906,  3912,  3917,  3921,  3925,  3927,  3929,  3931,  3934,
    3937,  3940,  3943,  3945,  3947,  3948,  3949,  3958,  3959,  3960,
    3970,  3971,  3973,  3975,  3978,  3981,  3984,  3987,  3989,  3991,
    3993,  3994,  3996,  3998,  4001,  4004,  4007,  4016,  4019,  4022,
    4027,  4030,  4031,  4033,  4035,  4039,  4042,  4045,  4047,  4049,
    4053,  4055,  4057,  4060,  4062,  4066,  4070,  4074,  4076,  4080,
    4082,  4084,  4086,  4088,  4090,  4092,  4094,  4097,  4102,  4104,
    4108,  4110,  4114,  4117,  4122,  4124,  4128,  4130,  4133,  4138,
    4140,  4144,  4146,  4148,  4150,  4153,  4157,  4162,  4165,  4170,
    4171,  4174,  4177,  4182,  4184,  4188,  4190,  4192,  4194,  4197,
    4199,  4201,  4203,  4205,  4207,  4210,  4217,  4224,  4225,  4227,
    4228,  4230,  4233,  4235,  4236,  4242,  4243,  4249,  4251,  4252,
    4256,  4258,  4262,  4264,  4268,  4270,  4272,  4273,  4278,  4280,
    4283,  4285,  4286,  4287,  4291,  4292,  4293,  4297,  4299,  4301,
    4303,  4305,  4307,  4309,  4312,  4315,  4320,  4324,  4328,  4330,
    4334,  4337,  4339,  4341,  4342,  4344,  4346,  4348,  4350,  4351,
    4353,  4357,  4359,  4363,  4365,  4366,  4370,  4372,  4374,  4376,
    4378,  4380,  4382,  4384,  4386,  4388,  4390,  4392,  4394,  4396,
    4404,  4411,  4416,  4421,  4423,  4425,  4427,  4428,  4430,  4433,
    4435,  4437,  4439,  4441,  4445,  4448,  4450,  4452,  4455,  4457,
    4459,  4460,  4464,  4466,  4470,  4472,  4476,  4478,  4480,  4487,
    4488,  4492,  4494,  4498,  4499,  4501,  4506,  4512,  4515,  4517,
    4519,  4524,  4526,  4530,  4535,  4540,  4545,  4547,  4551,  4553,
    4555,  4557,  4560,  4562,  4564,  4566,  4571,  4572,  4574,  4575,
    4577,  4579,  4582,  4585,  4587,  4589,  4591,  4593,  4595,  4600,
    4602,  4606,  4608,  4610,  4612,  4615,  4617,  4619,  4622,  4625,
    4627,  4631,  4634,  4637,  4639,  4643,  4645,  4648,  4653,  4655,
    4658,  4662,  4664,  4668,  4673,  4674,  4676,  4677,  4679,  4680,
    4682,  4684,  4688,  4690,  4694,  4696,  4699,  4701,  4705,  4708,
    4711,  4712,  4715,  4717,  4719,  4725,  4729,  4735,  4739,  4741,
    4745,  4747,  4749,  4750,  4752,  4756,  4760,  4764,  4771,  4776,
    4781,  4786,  4791,  4797,  4799,  4801,  4803,  4805,  4807,  4809,
    4811,  4813,  4815,  4817,  4818,  4820,  4822,  4824,  4826,  4828,
    4830,  4832,  4837,  4838,  4840,  4845,  4847,  4853,  4859,  4861,
    4863,  4865,  4867,  4869,  4874,  4876,  4881,  4888,  4893,  4895,
    4900,  4902,  4910,  4912,  4914,  4916,  4921,  4928,  4929,  4932,
    4937,  4939,  4941,  4943,  4945,  4947,  4949,  4951,  4955,  4957,
    4959,  4963,  4969,  4973,  4979,  4987,  4991,  4993,  4995,  4999,
    5005,  5009,  5015,  5023,  5025,  5026,  5030,  5036,  5038,  5041,
    5044,  5049,  5053,  5055,  5057,  5059,  5061,  5063,  5066,  5069,
    5070,  5074,  5075,  5079,  5081,  5083,  5085,  5087,  5089,  5091,
    5093,  5098,  5100,  5102,  5104,  5106,  5108,  5110,  5112,  5114,
    5116,  5118,  5120,  5122,  5124,  5126,  5131,  5133,  5137,  5139,
    5143,  5144,  5152,  5153,  5162,  5163,  5170,  5171,  5180,  5181,
    5183,  5186,  5188,  5192,  5194,  5198,  5204,  5206,  5208,  5210,
    5212,  5214,  5215,  5216,  5226,  5232,  5234,  5236,  5243,  5244,
    5248,  5250,  5254,  5259,  5261,  5262,  5265,  5270,  5277,  5278,
    5280,  5282,  5284,  5286,  5290,  5292,  5295,  5299,  5301,  5303,
    5306,  5309,  5311,  5313,  5315,  5318,  5321,  5324,  5327,  5332,
    5336,  5339,  5343,  5347,  5351,  5353,  5355,  5357,  5359,  5361,
    5363,  5369,  5375,  5381,  5387,  5393,  5398,  5403,  5407,  5412,
    5414,  5416,  5418,  5422,  5424,  5430,  5438,  5444,  5445,  5448,
    5450,  5452,  5453,  5457,  5459,  5463,  5465,  5467,  5469,  5470,
    5474,  5476,  5478,  5480,  5482,  5487,  5494,  5496,  5498,  5501,
    5505,  5507,  5509,  5511,  5513,  5515,  5517,  5519,  5521,  5527,
    5533,  5538,  5544,  5546,  5551,  5553,  5555,  5563,  5568,  5570,
    5571,  5576,  5578,  5581,  5583,  5585,  5587,  5588,  5592,  5593,
    5597,  5598,  5599,  5606,  5607,  5610,  5613,  5621,  5625,  5629,
    5632,  5635,  5638,  5640,  5644,  5646,  5650,  5652,  5656,  5658,
    5662,  5664,  5666,  5668,  5671,  5674,  5676,  5678,  5681,  5686,
    5692,  5700,  5708,  5718,  5720,  5722,  5724,  5726,  5728,  5730,
    5734,  5737,  5741,  5745,  5749,  5755,  5761,  5767,  5773,  5779,
    5784,  5789,  5793,  5798,  5800,  5802,  5804,  5806,  5810,  5811,
    5817,  5819,  5823,  5827,  5831,  5833,  5835,  5838,  5840,  5842,
    5846,  5848,  5852,  5856,  5858,  5860,  5862,  5866,  5869,  5873,
    5880,  5882,  5886,  5888,  5890,  5891,  5892,  5899,  5900,  5903,
    5904,  5906,  5908,  5911,  5914,  5916,  5918,  5923,  5927,  5929,
    5932,  5938,  5941,  5944,  5950,  5951,  5954,  5956,  5958,  5961,
    5968,  5975,  5977,  5978,  5980,  5983,  5985,  5988,  5989,  5992,
    5994,  5996,  5998,  6000,  6002,  6004,  6006,  6008,  6010,  6012,
    6014,  6016,  6018,  6020,  6022,  6024,  6026,  6028,  6030,  6032,
    6034,  6036,  6038,  6040,  6042,  6044,  6046,  6048,  6050,  6052,
    6054,  6056,  6058,  6060,  6062,  6064,  6066,  6068,  6070,  6072,
    6074,  6076,  6078,  6080,  6082,  6084,  6086,  6088,  6090,  6092,
    6094,  6096,  6098,  6100,  6102,  6104,  6106,  6108,  6110,  6112,
    6114,  6116,  6118,  6120,  6122,  6124,  6126,  6128,  6130,  6132,
    6134,  6136,  6138,  6140,  6142,  6144,  6146,  6148,  6150,  6152,
    6154,  6156,  6158,  6160,  6162,  6164,  6166
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1117,     0,    -1,   257,    -1,   254,    -1,   188,   740,   482,
     649,   741,    -1,   199,    -1,  1180,    -1,    26,    -1,   742,
      -1,   741,     5,   742,    -1,  1024,    -1,   486,   743,   449,
      -1,   743,   744,   743,    -1,    26,    -1,   745,    26,    -1,
    1180,    -1,   964,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   747,
      -1,    -1,   331,   486,   748,   749,   449,    -1,   622,   486,
      26,     5,    26,   449,    -1,   750,    -1,   749,     5,   750,
      -1,   544,    -1,   585,    -1,   590,    -1,   560,    -1,   466,
      -1,   658,    -1,   582,    -1,   534,    -1,   472,    -1,   545,
      -1,   404,    -1,   586,    -1,   511,    -1,   391,    -1,   647,
      -1,   156,    -1,  1096,    -1,    -1,   752,    -1,    -1,   331,
     486,   753,   754,   449,    -1,   755,    -1,   754,     5,   755,
      -1,   750,    -1,   487,    -1,   656,    25,    -1,   260,  1010,
      -1,   388,  1010,    -1,   341,  1010,    -1,   396,  1010,    -1,
     350,  1010,    -1,   317,  1010,    -1,   588,   757,    -1,   953,
     403,  1180,    -1,    -1,   346,   486,   972,   449,   403,   758,
    1198,    -1,   164,   486,  1024,     5,    25,     5,    25,   449,
      -1,   463,   486,  1016,   449,   403,  1180,    -1,  1321,    -1,
     250,   486,   972,   449,   403,  1180,    -1,    -1,    -1,  1180,
     643,  1024,   486,   759,   775,   449,   760,   773,    -1,    -1,
      -1,  1180,    36,  1024,   486,   761,   775,   449,   762,   773,
      -1,    -1,    -1,    -1,  1024,   486,   763,   775,   764,   449,
     765,   773,    -1,    -1,    -1,   528,  1530,   676,  1530,   486,
     766,   775,   767,   449,   773,    -1,    -1,    -1,  1024,   575,
    1024,   486,   768,   775,   769,   449,   773,    -1,    -1,    -1,
      -1,   423,   778,   643,   779,   514,   740,   482,   486,   770,
     775,   771,   449,   772,   774,    -1,    -1,   403,  1198,    -1,
      -1,   403,  1198,    -1,   221,    -1,    -1,   776,    -1,   777,
      -1,   776,     5,   777,    -1,   922,    -1,   537,    -1,    25,
      -1,  1024,    -1,  1024,    -1,  1024,   673,  1024,    -1,    -1,
     589,   929,   781,   784,   788,   785,    -1,    -1,   589,   782,
     783,   786,   785,    -1,   790,    -1,   783,   790,    -1,   792,
      -1,   784,   792,    -1,   418,    -1,    -1,    -1,   398,   787,
    1605,    -1,    -1,    -1,   398,   789,  1605,    -1,    -1,   632,
     929,   791,  1605,    -1,    -1,   632,   929,   793,  1605,    -1,
      -1,    -1,    -1,   732,  1024,   795,   798,   796,   828,   797,
     799,   731,    -1,    -1,   733,  1024,    -1,   800,    -1,   799,
     800,    -1,  1132,    -1,   335,  1021,    -1,   259,  1019,    -1,
     141,  1019,    -1,   226,    -1,   243,  1536,    -1,   548,  1018,
      -1,    30,   803,    31,    -1,   804,    -1,   806,    -1,   805,
      -1,   804,   805,    -1,    29,    -1,   807,    -1,   806,   807,
      -1,    28,    -1,    -1,    -1,   379,   809,   811,   810,   812,
      -1,   442,  1180,   678,   813,  1068,  1095,   746,    -1,  1180,
     678,   813,  1068,   600,   972,  1095,   746,    -1,    -1,   815,
     249,    -1,   814,    -1,   813,     5,   814,    -1,  1024,    -1,
    1024,   673,  1024,    -1,  1024,   673,    20,    -1,   816,    -1,
     815,   816,    -1,    -1,   327,   822,   817,  1605,    -1,    -1,
     330,   823,   818,  1605,    -1,    -1,  1098,   819,  1605,    -1,
      -1,   224,   820,  1605,    -1,    -1,   222,   821,  1605,    -1,
    1028,    -1,   822,     5,  1028,    -1,  1028,    -1,   823,     5,
    1028,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,   155,    -1,   486,   922,   826,   449,    -1,    -1,
       5,   873,   679,   876,    -1,   214,    -1,   336,    -1,    -1,
     829,    -1,   830,    -1,   829,   830,    -1,    -1,    -1,   493,
     831,   833,   832,  1290,    -1,   886,    -1,   836,    -1,   833,
       5,   836,    -1,    -1,   835,  1024,    -1,   412,   834,   885,
      25,    -1,   412,   834,   885,  1024,    -1,   412,   834,   885,
    1030,    -1,   412,   834,   885,    26,    -1,   840,   859,    -1,
      -1,   834,   412,   837,   838,    -1,    26,    -1,    25,    -1,
    1030,    -1,    19,    26,    -1,   834,    -1,   839,    -1,   840,
       5,   839,    -1,    -1,   376,    -1,    -1,   723,    -1,   724,
      -1,   725,    -1,    -1,   541,   514,   850,   482,   844,   677,
     859,    -1,    -1,    44,   842,   845,   677,   859,    -1,    -1,
     375,   841,   847,    26,   848,   359,   514,   849,   482,   846,
     677,   859,    -1,   486,    -1,   513,    -1,   449,    -1,   481,
      -1,    26,    -1,   851,     5,   851,     5,   851,    -1,   851,
       5,   851,    -1,   851,    -1,    26,    -1,   834,    -1,   834,
     643,   834,    -1,   834,   665,   834,   643,   834,    -1,    -1,
     519,   854,   833,   340,    -1,    -1,   318,   855,   852,   673,
      20,    -1,    -1,   393,   856,   852,   316,   486,   857,   449,
      -1,   858,    -1,   857,     5,   858,    -1,   834,    -1,   861,
      -1,    -1,   116,    -1,    -1,    -1,   862,   864,   863,   860,
      -1,   843,    -1,   853,    -1,   376,    -1,   377,    -1,   376,
     486,    26,   449,    -1,   377,   486,    26,   449,    -1,   479,
     486,    26,   449,    -1,   479,   486,    26,     5,    26,   449,
      -1,   378,   486,    26,   449,    -1,   378,   486,    26,     5,
      26,   449,    -1,   464,    -1,   670,   834,    -1,   438,    -1,
     563,    -1,   148,    -1,   454,    -1,   454,   486,    26,   449,
      -1,   454,   486,    26,     5,    26,   449,    -1,   566,    -1,
     566,   486,    26,   449,    -1,   566,   486,    26,     5,    26,
     449,    -1,    -1,   556,   865,   868,    -1,    -1,   121,   866,
     868,    -1,    -1,   356,   867,   868,    -1,   591,    -1,   587,
      -1,   137,    -1,   138,    -1,   628,    -1,   415,   871,    -1,
     427,   872,    -1,   869,    -1,    32,    -1,    -1,   486,    26,
     449,    -1,   610,   852,   673,   870,    -1,   834,    -1,    -1,
     873,   679,   876,    -1,   881,   679,   884,    -1,    -1,   874,
     875,    -1,   635,    -1,   567,    -1,   644,    -1,   606,    -1,
     509,    -1,   525,    -1,   424,   878,    -1,    -1,   877,   875,
      -1,    -1,   486,   880,   449,    -1,    -1,   486,    26,   449,
      -1,    26,    -1,    -1,   882,   883,   879,    -1,   635,    -1,
     567,    -1,   644,    -1,   606,    -1,   509,    -1,   525,    -1,
     424,   878,    -1,   883,    -1,    -1,    14,    -1,    -1,   294,
    1024,   887,   670,   888,    -1,   890,    -1,   893,    -1,   376,
      -1,   376,   486,    26,   449,    -1,   479,   486,    26,   449,
      -1,   479,   486,    26,     5,    26,   449,    -1,   464,    -1,
     438,    -1,   563,    -1,   454,    -1,   454,   486,    26,   449,
      -1,   454,   486,    26,     5,    26,   449,    -1,   566,    -1,
     566,   486,    26,   449,    -1,   566,   486,    26,     5,    26,
     449,    -1,   556,    -1,   356,    -1,   591,    -1,   587,    -1,
     628,    -1,   415,   871,    -1,   427,   872,    -1,   889,    -1,
     610,   852,   673,   870,    -1,    -1,   541,   514,   850,   482,
     891,   677,   888,    -1,    -1,   375,   841,   847,    26,   848,
     359,   514,   849,   482,   892,   677,   888,    -1,    -1,   519,
     894,   896,   340,    -1,    -1,   318,   895,  1024,   673,    20,
      -1,   897,    -1,   896,     5,   897,    -1,   898,   888,    -1,
     899,    -1,   898,     5,   899,    -1,  1024,    -1,    -1,   671,
    1014,    -1,   128,  1024,    -1,   126,    -1,   679,   972,    -1,
     679,   563,  1024,   712,   972,    -1,   679,   563,  1024,   447,
      -1,   130,  1024,    -1,   215,   945,  1198,   908,    -1,   457,
     945,   927,   900,   908,    -1,   268,  1021,   908,    -1,    -1,
      -1,   246,   905,  1205,   679,  1024,   673,    20,   907,   746,
     906,   909,    -1,    -1,   523,  1015,    -1,   746,    -1,    -1,
     910,   296,    -1,   296,    -1,   911,    -1,   910,   911,    -1,
      -1,   410,   912,  1605,    -1,    -1,   406,   913,  1605,    -1,
      -1,  1098,   914,  1605,    -1,    46,  1180,    -1,    47,  1180,
      -1,    45,  1180,    -1,   552,   945,   928,   746,    -1,   552,
     945,   928,   746,   123,    -1,   272,    -1,   272,   929,    -1,
     343,    -1,   342,    -1,   271,    -1,   422,    -1,   231,    -1,
     270,    -1,   387,    -1,   386,    -1,   301,    -1,   228,    -1,
     227,    -1,   205,    -1,   261,    -1,   189,    -1,   204,    -1,
     245,    -1,   212,    -1,   930,    -1,   934,    -1,   964,    -1,
     922,   923,    -1,   965,    -1,   967,    -1,   931,    -1,    19,
     922,    -1,    18,   922,    -1,   936,    -1,   944,    -1,   938,
      -1,   529,    -1,   824,    -1,   939,    -1,   940,    -1,   941,
      -1,   942,    -1,   943,    -1,    52,   922,    -1,   945,    -1,
     945,   926,    -1,   929,    -1,   537,    -1,   925,    -1,   926,
       5,   925,    -1,   929,    -1,   927,     5,   929,    -1,   929,
      -1,   928,     5,   929,    -1,   922,    -1,     9,   922,    -1,
     538,    -1,   483,    -1,   486,   922,   449,    -1,   498,   486,
    1510,   449,    -1,   351,   486,  1510,   449,    -1,    25,    -1,
    1030,    -1,    26,    -1,   933,    -1,  1180,    -1,  1180,   476,
    1180,    -1,   932,    -1,   489,   922,    -1,   450,   922,    -1,
    1293,    -1,    -1,   561,   935,  1293,    -1,     7,   922,    -1,
       6,   922,    -1,   922,    -1,   937,     5,   922,    -1,   676,
     486,  1510,   449,    -1,   484,   486,  1510,   449,    -1,   676,
     486,   945,   937,   449,    -1,   484,   486,   945,   937,   449,
      -1,   444,    -1,   307,    -1,    10,   922,    -1,   310,   922,
      -1,    10,   922,   497,    25,    -1,   310,   922,   497,    25,
      -1,   610,   922,    -1,   429,   922,    -1,   610,   922,   497,
      25,    -1,   429,   922,   497,    25,    -1,   448,    -1,     8,
     922,    -1,    18,   922,    -1,    19,   922,    -1,    20,   922,
      -1,    21,   922,    -1,    22,   922,    -1,    11,   922,    -1,
      14,   922,    -1,   512,   922,    -1,    12,   922,    -1,    13,
     922,    -1,    17,   922,    -1,    16,   922,    -1,    15,   922,
      -1,    -1,    -1,    -1,  1024,   486,   947,   775,   948,   449,
      -1,    -1,    -1,  1024,   575,  1024,   486,   949,   775,   950,
     449,    -1,    -1,    -1,  1024,    36,  1024,   486,   951,   775,
     952,   449,    -1,    -1,    -1,   591,   486,   954,   922,   955,
     449,    -1,    -1,    -1,   567,   486,   956,   922,   957,   449,
      -1,    -1,    -1,   644,   486,   958,   922,   959,   449,    -1,
      -1,    -1,   635,   486,   960,   922,   961,   449,    -1,   427,
     486,   968,   449,   963,    -1,   415,   486,    25,   449,   962,
      -1,   415,   486,    26,   449,   962,    -1,   415,   486,    24,
     449,   962,    -1,   415,   486,    26,   643,    26,   449,   962,
      -1,   415,   486,    26,   643,    24,   449,   962,    -1,   415,
     486,    26,   643,    26,   643,    26,   449,   962,    -1,   415,
     486,    26,   643,    26,   643,    24,   449,   962,    -1,   415,
     486,    26,    26,   449,   962,    -1,   415,   486,    26,    26,
     643,    26,   449,   962,    -1,   415,   486,    26,    26,   643,
      26,   643,    26,   449,   962,    -1,   415,   486,    26,    26,
     643,    26,   643,    24,   449,   962,    -1,   415,   486,    26,
      19,    26,   449,   962,    -1,   415,   486,    26,    19,    26,
      19,    26,   449,   962,    -1,   415,   486,    26,    19,    26,
      26,   449,   962,    -1,   415,   486,    26,    19,    26,    19,
      26,    26,   449,   962,    -1,   415,   486,    26,    19,    26,
      19,    26,    26,   643,    26,   449,   962,    -1,   415,   486,
      26,    19,    26,    19,    26,    26,   643,    26,   643,    26,
     449,   962,    -1,   415,   486,    26,    19,    26,    19,    26,
      26,   643,    26,   643,    24,   449,   962,    -1,   415,   486,
      26,    19,    26,    26,   643,    26,   449,   962,    -1,   415,
     486,    26,    19,    26,    26,   643,    26,   643,    26,   449,
     962,    -1,   415,   486,    26,    19,    26,    26,   643,    26,
     643,    24,   449,   962,    -1,    42,   486,  1180,   449,    -1,
     728,   486,  1180,   449,    -1,   729,   486,  1180,     5,    26,
     449,    -1,    -1,   875,   679,   875,    -1,   872,    -1,   953,
      -1,   346,   486,   972,   449,    -1,   157,   486,  1015,   449,
      -1,   129,   486,  1015,   449,    -1,   463,   486,   973,   449,
      -1,   250,   486,   972,   449,    -1,   117,   486,   972,   449,
      -1,   966,    -1,   946,    -1,  1487,    -1,   591,    -1,   478,
     486,   922,   449,    -1,   381,   486,   922,   449,    -1,   542,
     922,    -1,   499,   825,    -1,   922,   168,    -1,   922,   169,
      -1,   922,   170,    -1,    25,    -1,   969,    -1,    19,   969,
      -1,   971,    -1,   970,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   643,    26,    -1,    26,    26,   643,    26,   643,
      26,    -1,    26,    26,   643,    26,   643,    24,    -1,    26,
     643,    26,    -1,    26,   643,    26,   643,    26,    -1,    26,
     643,    26,   643,    24,    -1,    26,   643,    24,    -1,    24,
      -1,   673,    26,    -1,    26,    -1,    26,    19,    26,    -1,
    1015,    -1,   972,     5,  1015,    -1,  1016,    -1,   973,     5,
    1016,    -1,    -1,    -1,    -1,   460,   975,  1018,   976,   978,
    1389,   977,  1605,   298,    -1,    -1,     8,   945,   927,    -1,
      -1,    -1,   691,  1024,   980,   828,   981,  1129,   983,   982,
     988,   692,    -1,    -1,   993,    -1,    -1,   984,    -1,   985,
      -1,   984,   985,    -1,    -1,   693,   986,  1605,    -1,    -1,
     694,   987,  1605,    -1,    -1,   989,    -1,   990,    -1,   989,
     990,    -1,    -1,   695,   991,  1605,    -1,    -1,   696,   992,
    1605,    -1,   994,   998,   383,    -1,   149,    -1,   149,   995,
     600,   996,    -1,   149,   442,   997,    -1,  1180,    -1,   995,
       5,  1180,    -1,  1024,    -1,   996,     5,  1024,    -1,  1180,
      -1,   997,     5,  1180,    -1,   999,    -1,   998,   999,    -1,
      -1,   697,  1000,  1605,    -1,    -1,   698,  1001,  1605,    -1,
      -1,   717,   996,  1002,  1605,    -1,    -1,   535,   996,  1003,
    1605,    -1,    -1,   678,   996,  1004,  1605,    -1,    -1,    -1,
     649,  1180,    14,   929,   679,   929,  1008,  1006,  1605,  1007,
     299,    -1,    -1,   625,   929,    -1,   599,  1017,    -1,   608,
      19,    26,    -1,   608,    -1,   555,    18,    26,    -1,   555,
      -1,    26,    -1,  1180,    -1,   722,    -1,    25,    -1,  1029,
      -1,   929,    -1,  1012,     5,  1012,    -1,  1013,    -1,  1024,
      -1,   720,   486,  1024,   449,    -1,  1024,   673,   720,   486,
    1024,   449,    -1,  1024,   514,   743,   482,    -1,  1024,   673,
      20,    -1,  1024,   514,   743,   482,   673,    20,    -1,  1024,
     673,  1024,    -1,  1024,   514,   743,   482,   673,  1024,    -1,
    1015,    -1,    25,    -1,  1025,    -1,  1025,    -1,  1025,    -1,
    1025,    -1,  1025,    -1,  1025,    -1,    -1,   604,    26,    -1,
    1604,    -1,  1026,    -1,  1604,    -1,   408,   486,  1027,   449,
      -1,  1183,    -1,    25,    -1,  1024,    -1,  1024,   514,   743,
     482,    -1,  1024,   673,    20,    -1,  1024,   514,   743,   482,
     673,    20,    -1,  1024,   673,  1024,    -1,  1024,   514,   743,
     482,   673,  1024,    -1,  1180,    -1,    24,    -1,   673,    26,
      -1,   601,  1032,    -1,  1024,    -1,   643,  1024,    -1,   705,
    1034,    -1,  1035,    -1,  1034,     5,  1035,    -1,  1024,    -1,
     716,  1034,    -1,   707,  1034,    -1,   708,   972,    -1,   706,
    1021,   712,   972,    -1,   710,  1034,    -1,   711,   972,    -1,
     709,  1021,   712,   972,    -1,    -1,   714,  1040,   927,  1045,
    1047,  1049,  1041,  1043,    -1,    -1,  1042,    -1,   702,    -1,
     703,    -1,    -1,  1044,    -1,   403,  1180,    -1,    -1,  1046,
      -1,   447,   927,    -1,    -1,  1048,    -1,   713,    26,    -1,
      -1,  1050,    -1,   704,    26,  1051,    -1,    -1,   456,    26,
      -1,    -1,    -1,   675,   929,   629,  1053,  1605,  1054,  1055,
     496,    -1,    -1,    -1,   596,  1056,  1605,    -1,    -1,    -1,
     120,  1057,   929,   629,  1058,  1605,  1055,    -1,   166,  1024,
     486,    26,   449,    -1,   111,  1024,    -1,    43,  1024,    -1,
     133,  1024,    -1,    -1,   347,  1209,  1063,   679,   537,    -1,
     347,  1209,   610,  1064,    -1,  1065,    -1,  1064,     5,  1065,
      -1,  1066,   673,  1483,    -1,  1066,   673,    20,    -1,  1479,
      -1,    -1,  1069,   383,    -1,   383,    -1,    -1,   209,    -1,
    1070,    -1,  1069,  1070,    -1,    -1,   327,  1084,  1071,  1605,
      -1,    -1,   330,  1085,  1072,  1605,    -1,    -1,   410,  1073,
    1605,    -1,    -1,   406,  1074,  1605,    -1,    -1,  1098,  1075,
    1605,    -1,    -1,   362,  1076,  1605,    -1,    -1,   332,  1077,
    1605,    -1,    -1,    53,  1078,  1605,    -1,    -1,    50,  1079,
    1605,    -1,    -1,    49,  1080,  1605,    -1,    -1,    48,  1081,
    1605,    -1,    -1,    56,  1082,  1605,    -1,    -1,    55,  1083,
    1605,    -1,  1015,    -1,  1084,     5,  1015,    -1,  1015,    -1,
    1085,     5,  1015,    -1,   371,  1088,    -1,   372,  1024,   712,
    1088,    -1,   615,    -1,   433,    -1,  1015,    -1,    -1,   718,
    1091,  1090,  1067,    -1,   442,  1198,  1068,  1023,   746,    -1,
    1198,  1068,   600,   972,  1023,   746,    -1,    -1,   541,  1205,
    1068,   600,  1024,   673,    20,  1023,  1092,   746,    -1,   524,
     972,  1094,    -1,   139,    26,    -1,   140,    26,    -1,   680,
      -1,   593,    -1,   139,  1180,    -1,   140,  1180,    -1,    -1,
     604,    26,    -1,  1097,    -1,    62,    25,    -1,   550,    14,
      26,    -1,   550,    14,  1180,    -1,    63,    14,    26,    -1,
      63,    14,  1180,    -1,    59,    -1,    61,    -1,    58,    -1,
      60,    -1,    -1,   485,  1099,  1104,    -1,   352,    -1,    -1,
     650,  1101,  1104,    -1,   360,  1106,    -1,   650,  1104,    -1,
    1106,    -1,   486,  1105,   449,    -1,  1106,    -1,  1105,     5,
    1106,    -1,  1107,    -1,   648,    -1,   369,    -1,   389,    -1,
     361,    -1,   539,    -1,   497,    -1,   680,    -1,   604,    -1,
     593,    -1,   235,    -1,   494,    -1,   505,    -1,   594,    -1,
     609,    -1,   574,    -1,   367,    -1,   368,    -1,    25,    -1,
     564,    -1,    -1,    -1,   652,  1110,  1203,  1111,    14,   945,
    1112,    -1,   537,    -1,   928,    -1,   277,  1180,    -1,   267,
    1180,    -1,   280,  1180,    -1,   506,  1201,   392,    -1,   506,
    1201,   443,  1011,    -1,  1118,    -1,  1119,    -1,   794,    -1,
      -1,  1121,  1120,  1124,    -1,    -1,  1122,    -1,  1123,    -1,
    1122,  1123,    -1,  1061,    -1,  1128,    -1,  1589,    -1,  1060,
      -1,  1144,    -1,  1130,    -1,  1143,    -1,    -1,  1125,    -1,
    1127,    -1,  1125,  1127,    -1,   124,  1024,    -1,  1132,    -1,
    1138,    -1,  1303,    -1,  1313,    -1,  1150,    -1,   979,    -1,
     802,    -1,  1059,    -1,  1589,    -1,   802,    -1,    -1,   802,
      -1,   829,    -1,   425,    -1,   118,    -1,    -1,    -1,    -1,
      -1,  1131,  1133,  1024,   486,  1134,  1196,   449,  1135,   828,
    1136,  1129,  1605,  1137,    -1,   269,    -1,    -1,    -1,   611,
    1139,   828,  1140,  1605,   419,    -1,   235,   924,    -1,   945,
      -1,   945,   927,    -1,   414,  1494,    -1,   522,  1494,    -1,
    1145,    -1,  1146,    -1,  1145,  1146,    -1,  1147,    -1,    -1,
     462,  1148,  1149,    -1,   828,   300,    -1,  1011,    -1,  1128,
      -1,  1143,    -1,    -1,    -1,   699,  1024,  1151,   828,  1152,
    1153,   700,    -1,  1154,    -1,  1153,  1154,    -1,    -1,   701,
    1155,  1605,    -1,    -1,   678,  1024,  1156,  1605,    -1,    -1,
     612,  1158,  1173,  1164,  1159,    -1,   420,    -1,    -1,   292,
    1161,  1605,    -1,    -1,    23,  1165,  1166,  1167,  1023,  1162,
    1605,    -1,    -1,    23,  1165,  1023,  1163,  1605,    -1,  1160,
      -1,  1164,  1160,    -1,    -1,  1100,    -1,    25,    -1,  1180,
      -1,    -1,  1180,    -1,    25,    -1,   309,  1171,    -1,   320,
    1172,    -1,   304,  1172,    -1,   639,    -1,    25,    -1,  1180,
      -1,  1171,    -1,  1172,     5,  1171,    -1,  1180,    -1,    25,
      -1,  1177,  1175,    -1,    -1,   747,  1178,    -1,  1179,    -1,
    1176,    -1,  1046,    -1,  1048,    -1,  1050,    -1,  1042,    -1,
    1044,    -1,   428,   945,   927,    -1,    -1,   123,    -1,   123,
      -1,  1181,    -1,  1183,    -1,   248,  1183,    -1,  1183,   673,
      -1,  1182,  1187,    -1,  1182,  1024,   514,  1190,   482,    -1,
    1182,  1024,   514,  1190,   482,   514,  1190,   482,    -1,  1188,
      -1,  1024,    -1,  1184,    -1,  1024,   513,  1186,   481,    -1,
    1024,   513,  1186,   481,    -1,  1180,    -1,    25,    -1,    20,
      -1,  1024,    -1,  1024,  1189,    -1,   514,  1190,   482,    -1,
     514,  1190,   482,   514,  1190,   482,    -1,  1191,    -1,  1190,
       5,  1191,    -1,   743,    -1,  1193,    -1,  1195,    -1,  1193,
     673,  1194,    -1,  1193,   673,  1024,   514,  1190,   482,    -1,
    1193,   673,  1024,   514,  1190,   482,   514,  1190,   482,    -1,
    1024,    -1,  1185,    -1,    20,    -1,  1024,    -1,  1024,  1189,
      -1,    -1,  1197,    -1,  1199,    -1,  1197,     5,  1199,    -1,
    1200,    -1,  1198,     5,  1200,    -1,  1024,    -1,  1024,   673,
    1024,    -1,  1180,    -1,  1180,   476,  1180,    -1,    25,    -1,
    1030,    -1,    26,    -1,  1202,    -1,  1201,     5,  1202,    -1,
    1180,    -1,  1180,   476,  1180,    -1,  1204,    -1,  1203,     5,
    1204,    -1,  1192,    -1,  1180,    -1,  1207,    -1,  1206,     5,
    1207,    -1,  1180,  1208,    -1,    -1,   641,    -1,   592,    -1,
    1210,    -1,  1209,     5,  1210,    -1,  1180,    -1,  1180,   476,
    1180,    -1,   312,  1020,   671,  1013,   633,  1597,   751,    -1,
      -1,   671,   486,   929,     5,   929,   449,  1213,    -1,    -1,
     622,   486,   929,     5,   929,   449,    -1,   313,  1024,  1212,
      -1,  1024,    -1,   397,  1022,  1217,    -1,  1218,    -1,   600,
     929,    -1,  1219,  1220,  1225,     8,  1215,    -1,    -1,   671,
    1221,   486,   929,     5,   929,   449,    -1,    -1,   610,  1025,
      -1,    -1,   409,    -1,   275,  1536,   323,  1578,  1224,    -1,
     617,  1017,    -1,   617,  1017,     8,   945,   927,    -1,    -1,
     670,   630,  1530,   432,  1530,    -1,   670,   630,  1530,     5,
     432,  1530,    -1,   670,  1530,     5,  1530,    -1,    -1,   702,
      -1,   703,    -1,   451,   679,  1578,  1227,  1228,    -1,    -1,
     670,  1578,    -1,    -1,   670,   630,  1530,     8,  1530,    -1,
     630,  1530,     8,  1530,    -1,   467,  1230,    -1,  1231,    -1,
    1230,     5,  1231,    -1,   260,  1010,    -1,   341,  1010,    -1,
     388,  1010,    -1,   396,  1010,    -1,   350,  1010,    -1,   317,
    1010,    -1,  1102,    -1,   494,  1103,    -1,   505,  1103,    -1,
     615,  1103,    -1,   433,  1103,    -1,   604,  1103,    -1,   602,
    1011,    -1,   603,  1011,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,   457,   747,    -1,   718,   747,    -1,   348,
      -1,   253,    -1,   210,    -1,   190,    -1,   198,    -1,   207,
      -1,   660,  1232,    -1,   734,  1233,    -1,    40,    -1,    41,
      -1,    40,    -1,    41,    -1,  1535,   469,  1237,   600,  1235,
      -1,  1180,    -1,    25,    -1,   459,  1237,    -1,   459,  1237,
       8,  1198,    -1,   459,  1237,   607,  1201,    -1,   459,  1237,
     607,  1201,     8,  1198,    -1,    57,  1235,    -1,  1025,    -1,
      -1,   517,  1247,   746,   649,  1242,  1180,  1240,  1023,   746,
    1239,  1243,    -1,    -1,   721,    26,    -1,   517,  1247,   746,
     403,  1180,    -1,    -1,   376,    -1,    -1,  1244,   339,    -1,
    1245,    -1,  1244,  1245,    -1,    -1,  1098,  1246,  1605,    -1,
     928,    -1,    -1,   657,  1017,  1249,  1250,    -1,    -1,   600,
    1251,    -1,  1252,    -1,  1251,     5,  1252,    -1,  1522,    -1,
     537,    -1,   278,  1256,   147,  1254,    -1,   278,  1256,   679,
    1255,  1254,    -1,   278,  1256,   145,  1255,  1254,    -1,   278,
    1256,   146,  1255,  1254,    -1,   278,  1256,  1254,    -1,    -1,
      51,    -1,    25,    -1,  1029,    -1,  1024,    -1,    -1,   533,
      -1,   206,  1256,  1257,   486,   945,  1142,   449,    -1,   251,
    1256,    -1,   125,  1256,    -1,  1294,  1302,    -1,   502,   119,
      -1,   502,  1263,    -1,  1264,    -1,  1263,  1264,    -1,    -1,
     194,  1265,  1605,    -1,    -1,   256,  1266,  1605,    -1,    -1,
     286,  1267,  1605,    -1,    -1,   274,  1268,  1605,    -1,    -1,
     311,  1269,  1605,    -1,    -1,   258,  1180,  1270,  1605,    -1,
      -1,   282,  1180,  1271,  1605,    -1,  1282,    -1,  1286,    -1,
    1285,    -1,  1273,    -1,  1311,    -1,  1276,    -1,    -1,   614,
     929,  1274,   536,    -1,    -1,   536,    -1,    -1,   623,    26,
    1277,  1275,    -1,   217,    -1,   682,  1298,    -1,   220,  1298,
      -1,   219,  1298,    -1,    -1,  1279,    -1,  1280,    -1,  1279,
    1280,    -1,  1291,  1281,    -1,    -1,   671,  1298,    -1,    -1,
     573,  1283,  1278,  1290,    -1,  1530,    -1,   486,  1530,   449,
      -1,   572,  1284,  1290,    -1,   571,  1289,  1288,  1287,  1290,
      -1,    -1,   211,   922,    -1,   211,   922,     5,   922,    -1,
     666,    -1,   667,    -1,   668,    -1,   669,    -1,  1180,    -1,
      -1,   576,    -1,  1292,    -1,  1291,     5,  1292,    -1,   929,
    1325,    -1,   662,   486,   922,   449,  1310,    -1,   122,  1310,
      -1,   550,   486,    20,   449,  1310,    -1,   468,   486,    20,
     449,  1310,    -1,   445,   486,   922,   449,  1310,    -1,   642,
     486,   922,   449,  1310,    -1,   655,   486,   922,   449,  1310,
      -1,   654,   486,   922,   449,  1310,    -1,    -1,   516,  1295,
      -1,  1296,    -1,  1295,  1296,    -1,   285,    26,    -1,   276,
      26,    -1,   358,    26,    -1,   242,    26,    -1,   314,    26,
      -1,   233,    -1,   402,    25,    -1,   402,  1180,    -1,   234,
      25,    -1,   218,    25,    -1,  1301,    -1,  1297,  1301,    -1,
    1299,   168,    -1,  1299,   170,    -1,  1299,   169,    -1,  1299,
      -1,  1030,    -1,    26,    -1,    -1,   516,  1297,    -1,   285,
    1298,    -1,   276,  1298,    -1,   358,  1298,    -1,   242,  1298,
      -1,   314,  1298,    -1,   315,  1298,    -1,   681,    25,    -1,
     682,  1298,    -1,   686,    -1,   683,    -1,   684,    -1,   685,
      -1,   690,    -1,   687,    -1,   688,    -1,   689,    -1,   134,
    1298,    -1,   135,  1298,    -1,   136,  1298,    -1,   402,    25,
      -1,   234,    25,    -1,   456,    -1,   131,    -1,   132,    -1,
      -1,   568,   672,  1206,    -1,   195,  1206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,  1304,  1024,   486,  1305,  1196,
     449,  1306,   828,  1307,  1261,  1308,  1262,  1309,   297,    -1,
      -1,   580,   922,    -1,   570,  1312,    -1,    -1,  1235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,  1314,  1024,   486,
    1315,  1196,   449,  1316,   828,  1317,  1320,  1318,  1262,  1319,
     297,    -1,  1300,  1302,    -1,    -1,    -1,    -1,   213,   486,
      25,     5,  1322,   775,  1323,   449,  1324,   773,    -1,    -1,
     441,    -1,   441,   276,    26,    -1,   441,   276,  1180,    -1,
     660,   929,    -1,   660,   929,  1327,    -1,   660,   929,   403,
    1180,    -1,   660,   929,   221,    -1,   660,   929,  1327,   403,
    1180,    -1,   660,   929,  1327,   221,    -1,   660,   929,   631,
      -1,   660,   929,   598,    -1,    41,    -1,    40,    -1,  1329,
      -1,   230,  1479,    -1,   382,  1479,    -1,   338,  1480,    -1,
      54,  1024,    -1,  1343,    -1,  1331,    -1,    -1,    -1,   263,
    1332,  1479,   486,  1333,  1347,   449,  1336,    -1,    -1,    -1,
     192,  1334,  1479,   486,  1335,  1347,   449,  1336,  1344,    -1,
      -1,  1337,    -1,  1338,    -1,  1337,  1338,    -1,   676,  1339,
      -1,   302,    26,    -1,    66,    26,    -1,   143,    -1,   144,
      -1,  1604,    -1,    -1,  1341,    -1,  1342,    -1,  1341,  1342,
      -1,   676,  1339,    -1,   730,    26,    -1,   163,  1480,   678,
    1479,   486,  1345,   449,  1340,    -1,   109,  1025,    -1,   110,
    1025,    -1,   229,  1479,   649,  1479,    -1,   114,  1479,    -1,
      -1,   325,    -1,  1346,    -1,  1345,     5,  1346,    -1,  1024,
     641,    -1,  1024,   592,    -1,  1024,    -1,  1348,    -1,  1347,
       5,  1348,    -1,  1431,    -1,  1429,    -1,   179,  1024,    -1,
     237,    -1,    64,  1024,  1351,    -1,    65,  1480,   160,    -1,
      65,  1480,   161,    -1,  1352,    -1,  1351,     5,  1352,    -1,
    1353,    -1,  1356,    -1,  1359,    -1,  1364,    -1,  1367,    -1,
    1363,    -1,  1362,    -1,   638,  1354,    -1,   638,   486,  1355,
     449,    -1,  1348,    -1,  1348,   717,  1024,    -1,  1354,    -1,
    1355,     5,  1354,    -1,   595,  1358,    -1,   595,   486,  1357,
     449,    -1,  1358,    -1,  1357,     5,  1358,    -1,  1024,    -1,
     510,  1361,    -1,   510,   486,  1360,   449,    -1,  1361,    -1,
    1360,     5,  1361,    -1,  1348,    -1,   143,    -1,   144,    -1,
     142,    26,    -1,   112,  1429,  1366,    -1,   112,   486,  1365,
     449,    -1,  1429,  1366,    -1,  1365,     5,  1429,  1366,    -1,
      -1,   115,  1024,    -1,   113,  1368,    -1,   113,   486,  1368,
     449,    -1,  1369,    -1,  1368,     5,  1369,    -1,  1024,    -1,
     322,    -1,   289,    -1,   223,  1372,    -1,   202,    -1,   191,
      -1,   178,    -1,   176,    -1,   180,    -1,   236,  1536,    -1,
     288,  1371,   515,  1530,   679,  1530,    -1,   355,  1017,   515,
    1530,   679,  1530,    -1,    -1,  1536,    -1,    -1,   929,    -1,
     577,   929,    -1,   287,    -1,    -1,   306,  1376,  1479,  1379,
    1377,    -1,    -1,   533,  1378,   486,  1381,   449,    -1,  1516,
      -1,    -1,   486,  1380,   449,    -1,  1483,    -1,  1380,     5,
    1483,    -1,  1382,    -1,  1381,     5,  1382,    -1,  1522,    -1,
     537,    -1,    -1,   554,  1384,  1386,  1387,    -1,  1025,    -1,
    1391,  1018,    -1,  1018,    -1,    -1,    -1,   607,  1388,  1201,
      -1,    -1,    -1,   607,  1390,  1201,    -1,   555,    -1,   608,
      -1,   615,    -1,   433,    -1,   400,    -1,   452,    -1,   436,
     929,    -1,   409,   929,    -1,   295,  1479,   208,  1018,    -1,
     295,  1479,  1452,    -1,   568,   672,  1395,    -1,  1396,    -1,
    1395,     5,  1396,    -1,  1397,  1398,    -1,    26,    -1,  1483,
      -1,    -1,   641,    -1,   592,    -1,   333,    -1,   366,    -1,
      -1,   385,    -1,   414,  1403,  1401,    -1,  1578,    -1,  1578,
     665,  1024,    -1,    25,    -1,    -1,  1535,  1405,  1406,    -1,
    1437,    -1,    37,    -1,  1441,    -1,  1400,    -1,  1537,    -1,
    1399,    -1,  1392,    -1,  1393,    -1,  1383,    -1,  1375,    -1,
    1374,    -1,  1506,    -1,  1558,    -1,   559,  1410,   678,  1479,
     679,  1415,  1409,    -1,   521,  1410,   678,  1479,   600,  1415,
      -1,   559,  1408,   679,  1415,    -1,   521,  1408,   600,  1415,
      -1,   451,    -1,   437,    -1,   645,    -1,    -1,   201,    -1,
     670,  1024,    -1,   225,    -1,   639,    -1,  1411,    -1,  1412,
      -1,  1411,     5,  1412,    -1,   526,  1413,    -1,   505,    -1,
     494,    -1,   532,  1413,    -1,   540,    -1,   562,    -1,    -1,
     486,  1414,   449,    -1,  1483,    -1,  1414,     5,  1483,    -1,
    1416,    -1,  1415,     5,  1416,    -1,   518,    -1,  1481,    -1,
     293,  1479,  1418,   670,  1516,  1420,    -1,    -1,   486,  1419,
     449,    -1,  1483,    -1,  1419,     5,  1483,    -1,    -1,   200,
      -1,   546,   486,  1455,   449,    -1,   303,   486,  1424,   449,
    1423,    -1,   353,  1425,    -1,  1426,    -1,  1479,    -1,  1479,
     486,  1426,   449,    -1,  1483,    -1,  1426,     5,  1483,    -1,
     530,   486,  1428,   449,    -1,   417,   486,  1428,   449,    -1,
     316,   486,  1428,   449,    -1,  1483,    -1,  1428,     5,  1483,
      -1,  1427,    -1,  1422,    -1,  1421,    -1,   456,  1486,    -1,
     266,    -1,   265,    -1,   264,    -1,  1024,  1471,  1432,  1433,
      -1,    -1,  1430,    -1,    -1,  1434,    -1,  1435,    -1,  1434,
    1435,    -1,  1436,  1366,    -1,   431,    -1,   216,    -1,   530,
      -1,   417,    -1,  1423,    -1,   546,   486,  1455,   449,    -1,
     316,    -1,   177,  1438,  1440,    -1,  1439,    -1,  1481,    -1,
    1441,    -1,  1440,  1441,    -1,  1417,    -1,  1407,    -1,   503,
    1455,    -1,   426,  1444,    -1,  1521,    -1,  1444,     5,  1521,
      -1,   580,  1455,    -1,   600,  1447,    -1,  1448,    -1,  1447,
       5,  1448,    -1,  1449,    -1,   569,  1449,    -1,   569,   486,
    1450,   449,    -1,  1479,    -1,  1479,  1485,    -1,  1479,   670,
    1485,    -1,  1448,    -1,  1450,     5,  1448,    -1,  1446,  1452,
    1453,  1454,    -1,    -1,  1445,    -1,    -1,  1443,    -1,    -1,
    1442,    -1,  1456,    -1,  1455,     6,  1456,    -1,  1457,    -1,
    1456,     7,  1457,    -1,  1458,    -1,     9,  1458,    -1,  1469,
      -1,   486,  1455,   449,    -1,   498,  1517,    -1,   351,  1517,
      -1,    -1,   497,  1462,    -1,  1523,    -1,  1526,    -1,  1522,
     676,   486,  1464,   449,    -1,  1522,   676,  1517,    -1,  1522,
     484,   486,  1464,   449,    -1,  1522,   484,  1517,    -1,  1465,
      -1,  1464,     5,  1465,    -1,  1584,    -1,  1486,    -1,    -1,
       9,    -1,  1522,  1466,   444,    -1,  1522,  1466,   307,    -1,
    1522,  1468,  1522,    -1,  1522,  1466,   446,  1522,     7,  1522,
      -1,  1522,   610,  1461,  1460,    -1,  1522,   429,  1461,  1460,
      -1,  1522,   727,  1461,  1460,    -1,  1522,   430,  1461,  1460,
      -1,  1522,  1466,    10,  1461,  1460,    -1,    14,    -1,    17,
      -1,    12,    -1,    13,    -1,   726,    -1,    16,    -1,    15,
      -1,  1467,    -1,  1463,    -1,  1459,    -1,    -1,   639,    -1,
     417,    -1,   530,    -1,  1472,    -1,  1473,    -1,  1475,    -1,
     376,    -1,   376,   486,  1476,   449,    -1,    -1,   527,    -1,
     527,   486,    26,   449,    -1,   454,    -1,   454,   486,  1477,
    1474,   449,    -1,   566,   486,  1477,  1474,   449,    -1,   566,
      -1,   591,    -1,   464,    -1,   438,    -1,   377,    -1,   377,
     486,  1476,   449,    -1,   378,    -1,   378,   486,    26,   449,
      -1,   378,   486,    26,     5,    26,   449,    -1,   415,  1492,
     679,  1493,    -1,   415,    -1,   427,  1492,   679,  1493,    -1,
     427,    -1,   427,  1492,   486,    26,   449,   679,  1493,    -1,
     628,    -1,   587,    -1,   479,    -1,   479,   486,    26,   449,
      -1,   479,   486,    26,     5,    26,   449,    -1,    -1,     5,
    1478,    -1,   556,   486,  1477,   449,    -1,   619,    -1,   356,
      -1,   556,    -1,   121,    -1,    26,    -1,    26,    -1,    26,
      -1,    25,   673,  1024,    -1,    25,    -1,  1024,    -1,  1024,
     643,  1024,    -1,  1024,   643,    25,   673,  1024,    -1,  1024,
     665,  1024,    -1,  1024,   665,  1024,   643,  1024,    -1,  1024,
     665,  1024,   643,    25,   673,  1024,    -1,    25,   673,  1024,
      -1,    25,    -1,  1024,    -1,  1024,   643,  1024,    -1,  1024,
     643,    25,   673,  1024,    -1,  1024,   665,  1024,    -1,  1024,
     665,  1024,   643,  1024,    -1,  1024,   665,  1024,   643,    25,
     673,  1024,    -1,  1024,    -1,    -1,   514,    26,   482,    -1,
     514,    26,     5,    26,   482,    -1,  1484,    -1,   665,  1484,
      -1,  1024,  1482,    -1,  1479,   673,  1024,  1482,    -1,  1479,
     673,    20,    -1,  1024,    -1,    25,    -1,  1030,    -1,    26,
      -1,  1488,    -1,   452,  1490,    -1,   452,  1489,    -1,    -1,
    1492,   679,  1493,    -1,    -1,  1491,   679,  1491,    -1,   635,
      -1,   567,    -1,   644,    -1,   606,    -1,   509,    -1,   525,
      -1,   424,    -1,   424,   486,    26,   449,    -1,   635,    -1,
     567,    -1,   644,    -1,   606,    -1,   509,    -1,   525,    -1,
     424,    -1,   635,    -1,   567,    -1,   644,    -1,   606,    -1,
     509,    -1,   525,    -1,   424,    -1,   424,   486,    26,   449,
      -1,  1024,    -1,  1024,   665,  1024,    -1,    25,    -1,  1535,
     557,  1018,    -1,    -1,  1535,   455,  1385,   492,   649,  1504,
    1497,    -1,    -1,  1535,   455,  1385,   492,   158,   649,  1505,
    1498,    -1,    -1,  1535,   455,  1385,   196,  1505,  1499,    -1,
      -1,  1535,   455,  1385,   197,   158,   649,  1505,  1500,    -1,
      -1,   345,    -1,   344,  1502,    -1,  1503,    -1,  1502,     5,
    1503,    -1,  1024,    -1,  1024,   673,  1024,    -1,    25,   673,
    1024,   673,  1024,    -1,  1505,    -1,  1375,    -1,  1237,    -1,
    1507,    -1,  1507,    -1,    -1,    -1,   526,  1518,  1508,  1519,
    1509,  1515,  1451,  1513,  1501,    -1,   526,  1518,  1519,  1451,
    1513,    -1,  1512,    -1,  1530,    -1,   526,  1518,  1519,  1515,
    1451,  1513,    -1,    -1,   579,  1470,  1511,    -1,  1394,    -1,
     390,  1514,  1344,    -1,  1394,   390,  1514,  1344,    -1,  1024,
      -1,    -1,   607,  1201,    -1,   526,  1518,  1519,  1451,    -1,
     486,   526,  1518,  1519,  1451,   449,    -1,    -1,   639,    -1,
     417,    -1,   530,    -1,  1520,    -1,  1519,     5,  1520,    -1,
    1522,    -1,  1522,  1024,    -1,  1522,   670,  1024,    -1,  1522,
      -1,  1523,    -1,    19,  1523,    -1,    18,  1523,    -1,  1524,
      -1,  1584,    -1,  1517,    -1,   639,  1517,    -1,   640,  1517,
      -1,   624,  1517,    -1,   665,  1024,    -1,   665,  1024,   673,
    1024,    -1,  1523,    21,  1522,    -1,  1523,  1544,    -1,  1523,
      20,  1522,    -1,  1523,    18,  1522,    -1,  1523,    19,  1522,
      -1,  1486,    -1,   538,    -1,   483,    -1,   630,    -1,    20,
      -1,   122,    -1,   642,   486,  1470,  1522,   449,    -1,   654,
     486,  1470,  1522,   449,    -1,   655,   486,  1470,  1522,   449,
      -1,   662,   486,  1470,  1522,   449,    -1,   550,   486,  1470,
    1522,   449,    -1,  1024,   486,  1525,   449,    -1,   591,   486,
    1525,   449,    -1,   486,  1522,   449,    -1,   499,   486,  1545,
     449,    -1,  1546,    -1,  1548,    -1,  1522,    -1,  1525,     5,
    1522,    -1,  1486,    -1,  1535,   405,  1534,  1529,  1511,    -1,
    1535,   394,  1534,  1529,   306,  1479,  1531,    -1,  1535,   394,
    1534,  1529,  1180,    -1,    -1,   380,  1530,    -1,    25,    -1,
    1180,    -1,    -1,   486,  1532,   449,    -1,  1533,    -1,  1532,
       5,  1533,    -1,  1024,    -1,    25,    -1,  1180,    -1,    -1,
     324,  1536,   649,    -1,  1025,    -1,  1542,    -1,  1541,    -1,
    1538,    -1,   373,  1539,   679,  1539,    -1,   354,  1479,   673,
    1540,   679,  1540,    -1,  1024,    -1,  1024,    -1,   279,  1479,
      -1,   349,  1479,  1543,    -1,   328,    -1,   232,    -1,   150,
      -1,   151,    -1,   152,    -1,   153,    -1,   154,    -1,   155,
      -1,   452,     5,  1492,   679,  1493,    -1,  1584,     5,  1492,
     679,  1493,    -1,   452,  1492,   679,  1493,    -1,  1522,     5,
    1492,   679,  1493,    -1,  1547,    -1,  1547,  1492,   679,  1493,
      -1,    38,    -1,  1549,    -1,  1549,  1492,   486,    26,   449,
     679,  1493,    -1,  1549,  1492,   679,  1493,    -1,    39,    -1,
      -1,   661,  1551,  1552,   247,    -1,  1553,    -1,  1552,  1553,
      -1,    33,    -1,  1554,    -1,  1556,    -1,    -1,   248,  1555,
    1584,    -1,    -1,   607,  1557,  1201,    -1,    -1,    -1,   532,
    1479,  1559,  1562,  1560,  1561,    -1,    -1,   208,  1018,    -1,
     580,  1455,    -1,   107,  1566,   449,    14,   486,  1567,   449,
      -1,   103,  1567,   449,    -1,   104,  1567,   449,    -1,   637,
    1563,    -1,   106,  1567,    -1,   105,  1567,    -1,  1565,    -1,
    1563,     5,  1565,    -1,  1483,    -1,  1564,    14,  1568,    -1,
    1564,    -1,  1566,     5,  1564,    -1,  1568,    -1,  1567,     5,
    1568,    -1,   537,    -1,  1569,    -1,  1570,    -1,    19,  1570,
      -1,    18,  1570,    -1,  1572,    -1,  1517,    -1,   665,  1024,
      -1,   665,  1024,   673,  1024,    -1,   665,  1024,   514,    26,
     482,    -1,   665,  1024,   673,  1024,   514,    26,   482,    -1,
     665,  1024,   514,    26,     5,    26,   482,    -1,   665,  1024,
     673,  1024,   514,    26,     5,    26,   482,    -1,  1571,    -1,
    1486,    -1,   538,    -1,   483,    -1,   630,    -1,   122,    -1,
    1570,    21,  1569,    -1,  1570,  1544,    -1,  1570,    20,  1569,
      -1,  1570,    18,  1569,    -1,  1570,    19,  1569,    -1,   642,
     486,  1470,  1569,   449,    -1,   654,   486,  1470,  1569,   449,
      -1,   655,   486,  1470,  1569,   449,    -1,   662,   486,  1470,
    1569,   449,    -1,   550,   486,  1470,  1569,   449,    -1,  1024,
     486,  1573,   449,    -1,   591,   486,  1573,   449,    -1,   486,
    1569,   449,    -1,   499,   486,  1545,   449,    -1,  1546,    -1,
    1548,    -1,  1584,    -1,  1569,    -1,  1573,     5,  1569,    -1,
      -1,   439,  1209,   610,  1575,  1576,    -1,  1577,    -1,  1576,
       5,  1577,    -1,  1479,   673,  1483,    -1,  1479,   673,    20,
      -1,  1580,    -1,  1580,    -1,   248,  1581,    -1,  1581,    -1,
    1582,    -1,    25,   673,  1582,    -1,  1583,    -1,  1582,   673,
    1583,    -1,  1582,   673,    20,    -1,  1585,    -1,  1024,    -1,
    1579,    -1,  1579,   476,  1579,    -1,  1024,  1586,    -1,   514,
    1587,   482,    -1,   514,  1587,   482,   514,  1587,   482,    -1,
    1588,    -1,  1587,     5,  1588,    -1,   743,    -1,    34,    -1,
      -1,    -1,   581,  1591,   929,  1592,  1605,   384,    -1,    -1,
     712,   972,    -1,    -1,   715,    -1,   239,    -1,   334,  1019,
      -1,   127,  1019,    -1,   364,    -1,   363,    -1,   365,  1021,
    1593,  1594,    -1,   547,   972,  1594,    -1,   162,    -1,   193,
    1019,    -1,   929,   620,     5,   929,   450,    -1,   563,   929,
      -1,   321,  1019,    -1,   159,  1600,     8,  1601,  1599,    -1,
      -1,   600,   929,    -1,  1024,    -1,  1024,    -1,   305,  1019,
      -1,   308,  1019,   679,   929,     5,   929,    -1,   308,  1019,
     672,   929,     5,   929,    -1,    27,    -1,    -1,  1607,    -1,
    1608,  1290,    -1,  1606,    -1,  1607,  1606,    -1,    -1,  1609,
    1610,    -1,   736,    -1,   737,    -1,   738,    -1,   739,    -1,
     756,    -1,   780,    -1,   801,    -1,   802,    -1,   808,    -1,
     827,    -1,   901,    -1,   902,    -1,   903,    -1,   904,    -1,
     915,    -1,   916,    -1,   917,    -1,   918,    -1,   919,    -1,
     920,    -1,   921,    -1,   974,    -1,  1005,    -1,  1009,    -1,
    1031,    -1,  1033,    -1,  1036,    -1,  1037,    -1,  1038,    -1,
    1039,    -1,  1052,    -1,  1062,    -1,  1086,    -1,  1087,    -1,
    1089,    -1,  1093,    -1,  1108,    -1,  1109,    -1,  1113,    -1,
    1114,    -1,  1115,    -1,  1116,    -1,  1126,    -1,  1141,    -1,
    1157,    -1,  1168,    -1,  1169,    -1,  1170,    -1,  1174,    -1,
    1211,    -1,  1214,    -1,  1216,    -1,  1222,    -1,  1223,    -1,
    1226,    -1,  1229,    -1,  1234,    -1,  1236,    -1,  1238,    -1,
    1241,    -1,  1248,    -1,  1253,    -1,  1258,    -1,  1259,    -1,
    1260,    -1,  1272,    -1,  1326,    -1,  1328,    -1,  1330,    -1,
    1349,    -1,  1350,    -1,  1370,    -1,  1373,    -1,  1402,    -1,
    1404,    -1,  1495,    -1,  1496,    -1,  1527,    -1,  1528,    -1,
    1550,    -1,  1574,    -1,  1589,    -1,  1590,    -1,  1595,    -1,
    1596,    -1,  1598,    -1,  1602,    -1,  1603,    -1
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
    3459,  3460,  3464,  3465,  3470,  3474,  3479,  3483,  3498,  3502,
    3508,  3497,  3521,  3522,  3534,  3540,  3534,  3554,  3554,  3556,
    3557,  3561,  3561,  3565,  3565,  3570,  3570,  3577,  3578,  3582,
    3582,  3586,  3586,  3591,  3591,  3598,  3602,  3603,  3604,  3609,
    3609,  3612,  3612,  3616,  3616,  3620,  3620,  3624,  3624,  3629,
    3629,  3634,  3634,  3639,  3639,  3644,  3644,  3660,  3664,  3659,
    3672,  3675,  3689,  3706,  3707,  3708,  3709,  3710,  3711,  3712,
    3715,  3715,  3718,  3720,  3723,  3726,  3729,  3734,  3739,  3742,
    3747,  3752,  3757,  3764,  3765,  3772,  3779,  3781,  3787,  3792,
    3797,  3802,  3802,  3805,  3811,  3816,  3819,  3826,  3826,  3828,
    3831,  3834,  3839,  3844,  3849,  3856,  3867,  3867,  3929,  3937,
    3938,  3946,  3953,  3953,  3957,  3962,  3968,  3972,  3976,  3982,
    3986,  3990,  3996,  3996,  4004,  4005,  4009,  4009,  4013,  4014,
    4017,  4020,  4020,  4023,  4025,  4025,  4028,  4030,  4030,  4031,
    4033,  4033,  4042,  4049,  4040,  4070,  4070,  4070,  4073,  4075,
    4073,  4082,  4085,  4092,  4097,  4108,  4108,  4112,  4118,  4118,
    4122,  4123,  4127,  4137,  4138,  4139,  4142,  4144,  4149,  4149,
    4153,  4152,  4160,  4159,  4166,  4166,  4172,  4172,  4179,  4179,
    4185,  4185,  4191,  4191,  4197,  4197,  4201,  4201,  4202,  4202,
    4203,  4203,  4204,  4204,  4208,  4208,  4219,  4223,  4229,  4233,
    4238,  4243,  4248,  4249,  4250,  4254,  4253,  4266,  4271,  4276,
    4276,  4292,  4298,  4299,  4300,  4301,  4302,  4312,  4326,  4326,
    4329,  4336,  4337,  4338,  4339,  4340,  4341,  4342,  4343,  4344,
    4349,  4349,  4351,  4354,  4354,  4356,  4360,  4363,  4364,  4367,
    4367,  4372,  4375,  4376,  4377,  4378,  4379,  4380,  4381,  4382,
    4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,  4391,  4392,
    4396,  4414,  4414,  4414,  4441,  4452,  4459,  4465,  4471,  4477,
    4489,  4512,  4513,  4516,  4520,  4519,  4537,  4537,  4541,  4542,
    4550,  4551,  4552,  4553,  4554,  4555,  4556,  4563,  4564,  4566,
    4567,  4571,  4576,  4577,  4578,  4579,  4580,  4581,  4582,  4583,
    4584,  4587,  4589,  4589,  4591,  4595,  4595,  4604,  4610,  4626,
    4632,  4603,  4646,  4660,  4671,  4659,  4684,  4691,  4691,  4696,
    4702,  4710,  4715,  4716,  4719,  4722,  4722,  4730,  4736,  4747,
    4748,  4756,  4762,  4756,  4773,  4774,  4778,  4778,  4785,  4785,
    4800,  4800,  4814,  4825,  4824,  4836,  4832,  4849,  4846,  4859,
    4859,  4861,  4862,  4864,  4865,  4868,  4869,  4870,  4872,  4877,
    4882,  4888,  4890,  4891,  4894,  4895,  4898,  4900,  4907,  4910,
    4913,  4916,  4920,  4924,  4925,  4926,  4927,  4928,  4932,  4937,
    4937,  4940,  4967,  5025,  5025,  5028,  5032,  5036,  5079,  5121,
    5122,  5123,  5126,  5140,  5152,  5152,  5157,  5158,  5164,  5229,
    5234,  5241,  5246,  5254,  5260,  5293,  5296,  5297,  5338,  5381,
    5382,  5386,  5387,  5391,  5444,  5449,  5453,  5458,  5469,  5476,
    5484,  5484,  5487,  5488,  5489,  5490,  5491,  5494,  5497,  5503,
    5506,  5510,  5515,  5523,  5528,  5535,  5537,  5543,  5545,  5545,
    5545,  5565,  5572,  5579,  5582,  5596,  5603,  5604,  5607,  5608,
    5612,  5618,  5623,  5629,  5630,  5635,  5639,  5639,  5643,  5644,
    5647,  5648,  5652,  5660,  5663,  5669,  5670,  5672,  5674,  5678,
    5678,  5679,  5684,  5692,  5693,  5698,  5699,  5701,  5714,  5716,
    5717,  5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,  5728,
    5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,  5738,
    5739,  5740,  5741,  5742,  5743,  5744,  5745,  5746,  5747,  5751,
    5752,  5756,  5757,  5771,  5779,  5779,  5781,  5785,  5789,  5793,
    5797,  5802,  5817,  5815,  5835,  5836,  5840,  5845,  5846,  5850,
    5851,  5853,  5854,  5856,  5856,  5865,  5874,  5874,  5884,  5885,
    5890,  5891,  5894,  5907,  5921,  5925,  5929,  5933,  5937,  5944,
    5945,  5948,  5948,  5952,  5955,  5955,  5957,  5963,  5971,  5977,
    5979,  5983,  5986,  5986,  5989,  5989,  5994,  5994,  6003,  6003,
    6007,  6007,  6008,  6008,  6009,  6009,  6023,  6023,  6043,  6044,
    6045,  6046,  6047,  6048,  6051,  6051,  6057,  6057,  6060,  6060,
    6076,  6077,  6078,  6087,  6099,  6100,  6103,  6104,  6107,  6110,
    6110,  6115,  6115,  6138,  6139,  6145,  6150,  6156,  6157,  6158,
    6162,  6163,  6164,  6165,  6169,  6179,  6181,  6186,  6189,  6194,
    6200,  6207,  6214,  6223,  6230,  6237,  6244,  6251,  6260,  6260,
    6262,  6262,  6265,  6266,  6267,  6268,  6269,  6270,  6271,  6272,
    6273,  6274,  6277,  6277,  6280,  6281,  6282,  6283,  6286,  6286,
    6289,  6289,  6292,  6293,  6294,  6295,  6296,  6297,  6298,  6299,
    6301,  6302,  6303,  6304,  6306,  6307,  6308,  6309,  6311,  6312,
    6313,  6314,  6315,  6316,  6317,  6318,  6322,  6330,  6340,  6353,
    6364,  6375,  6379,  6383,  6389,  6352,  6402,  6405,  6413,  6425,
    6427,  6432,  6442,  6452,  6455,  6459,  6467,  6431,  6476,  6480,
    6484,  6488,  6480,  6498,  6499,  6500,  6501,  6506,  6507,  6508,
    6509,  6510,  6511,  6512,  6513,  6517,  6518,  6521,  6526,  6533,
    6534,  6535,  6540,  6541,  6547,  6547,  6547,  6552,  6552,  6552,
    6560,  6561,  6565,  6566,  6571,  6572,  6573,  6574,  6575,  6578,
    6580,  6580,  6583,  6584,  6588,  6589,  6592,  6593,  6596,  6599,
    6602,  6608,  6609,  6621,  6622,  6627,  6628,  6629,  6633,  6636,
    6642,  6645,  6653,  6654,  6660,  6664,  6668,  6674,  6677,  6686,
    6689,  6692,  6695,  6698,  6701,  6704,  6711,  6714,  6721,  6724,
    6730,  6733,  6740,  6743,  6750,  6751,  6756,  6760,  6763,  6769,
    6772,  6778,  6785,  6786,  6790,  6800,  6803,  6809,  6811,  6816,
    6817,  6821,  6823,  6829,  6830,  6843,  6855,  6856,  6857,  6858,
    6859,  6860,  6861,  6862,  6863,  6866,  6869,  6875,  6875,  6881,
    6881,  6892,  6905,  6915,  6915,  6920,  6920,  6924,  6928,  6929,
    6935,  6936,  6941,  6945,  6952,  6955,  6962,  6961,  6972,  6976,
    6980,  6987,  6990,  6990,  7003,  7007,  7007,  7022,  7024,  7026,
    7028,  7030,  7032,  7034,  7036,  7042,  7052,  7059,  7064,  7065,
    7069,  7072,  7073,  7076,  7077,  7078,  7081,  7086,  7093,  7094,
    7101,  7113,  7114,  7115,  7118,  7118,  7123,  7128,  7133,  7138,
    7139,  7142,  7143,  7148,  7153,  7157,  7162,  7163,  7167,  7174,
    7175,  7176,  7177,  7182,  7183,  7184,  7187,  7188,  7189,  7193,
    7194,  7195,  7199,  7200,  7204,  7205,  7206,  7207,  7208,  7209,
    7212,  7213,  7218,  7219,  7224,  7225,  7230,  7231,  7236,  7241,
    7242,  7247,  7248,  7252,  7253,  7258,  7265,  7270,  7275,  7279,
    7280,  7285,  7286,  7292,  7295,  7299,  7304,  7305,  7311,  7314,
    7317,  7324,  7325,  7326,  7327,  7341,  7346,  7347,  7350,  7352,
    7359,  7362,  7368,  7376,  7380,  7384,  7388,  7393,  7396,  7399,
    7406,  7413,  7418,  7422,  7423,  7429,  7432,  7443,  7450,  7456,
    7459,  7466,  7473,  7479,  7480,  7486,  7487,  7488,  7491,  7492,
    7499,  7506,  7506,  7510,  7518,  7519,  7522,  7525,  7530,  7531,
    7536,  7539,  7545,  7548,  7554,  7557,  7563,  7566,  7573,  7574,
    7603,  7604,  7608,  7616,  7621,  7624,  7627,  7630,  7636,  7637,
    7641,  7644,  7647,  7648,  7653,  7656,  7659,  7662,  7665,  7668,
    7671,  7674,  7679,  7685,  7686,  7687,  7688,  7691,  7692,  7693,
    7698,  7701,  7705,  7711,  7712,  7713,  7714,  7726,  7727,  7728,
    7732,  7733,  7737,  7738,  7739,  7740,  7741,  7743,  7752,  7759,
    7760,  7761,  7762,  7763,  7764,  7765,  7767,  7769,  7771,  7772,
    7774,  7775,  7777,  7778,  7779,  7780,  7782,  7786,  7787,  7793,
    7795,  7796,  7797,  7798,  7803,  7807,  7811,  7815,  7822,  7826,
    7827,  7828,  7836,  7837,  7838,  7849,  7856,  7861,  7862,  7863,
    7871,  7872,  7873,  7890,  7899,  7900,  7901,  7905,  7908,  7913,
    7918,  7923,  7931,  7935,  7940,  7941,  7949,  7952,  7955,  7969,
    7983,  7996,  7997,  8001,  8001,  8001,  8001,  8001,  8001,  8002,
    8005,  8022,  8022,  8022,  8022,  8022,  8022,  8022,  8023,  8023,
    8023,  8023,  8023,  8023,  8023,  8023,  8026,  8027,  8028,  8031,
    8040,  8040,  8046,  8046,  8053,  8053,  8059,  8059,  8067,  8068,
    8069,  8072,  8072,  8075,  8076,  8077,  8088,  8091,  8097,  8102,
    8109,  8122,  8123,  8120,  8141,  8152,  8155,  8160,  8172,  8175,
    8179,  8182,  8183,  8193,  8196,  8197,  8206,  8215,  8220,  8221,
    8222,  8223,  8230,  8233,  8239,  8242,  8249,  8261,  8270,  8273,
    8276,  8282,  8290,  8293,  8294,  8295,  8296,  8297,  8300,  8306,
    8308,  8310,  8312,  8314,  8316,  8317,  8318,  8319,  8320,  8321,
    8322,  8324,  8326,  8328,  8330,  8332,  8334,  8336,  8337,  8339,
    8340,  8346,  8347,  8354,  8357,  8365,  8369,  8376,  8376,  8380,
    8380,  8385,  8385,  8389,  8389,  8393,  8399,  8399,  8402,  8402,
    8408,  8415,  8416,  8417,  8421,  8422,  8425,  8426,  8430,  8436,
    8446,  8447,  8455,  8456,  8457,  8458,  8459,  8460,  8464,  8465,
    8466,  8467,  8471,  8472,  8476,  8492,  8493,  8494,  8498,  8512,
    8512,  8524,  8525,  8529,  8530,  8531,  8855,  8855,  8862,  8862,
    8950,  8954,  8950,  8963,  8967,  8973,  8981,  8991,  9001,  9013,
    9016,  9035,  9061,  9064,  9070,  9073,  9078,  9081,  9089,  9097,
    9110,  9113,  9121,  9124,  9127,  9135,  9139,  9140,  9141,  9142,
    9143,  9144,  9145,  9146,  9150,  9151,  9152,  9153,  9154,  9160,
    9161,  9162,  9163,  9164,  9165,  9166,  9167,  9168,  9169,  9170,
    9171,  9172,  9173,  9174,  9175,  9180,  9186,  9187,  9195,  9195,
    9203,  9203,  9207,  9211,  9226,  9241,  9247,  9249,  9257,  9258,
    9262,  9263,  9266,  9273,  9276,  9305,  9331,  9385,  9421,  9430,
    9441,  9444,  9449,  9463,  9477,  9480,  9476,  9499,  9499,  9505,
    9506,  9509,  9510,  9511,  9512,  9513,  9514,  9515,  9526,  9529,
    9534,  9538,  9543,  9547,  9552,  9556,  9559,  9563,  9566,  9571,
    9575,  9586,  9592,  9592,  9593,  9594,  9601,  9611,  9611,  9613,
    9614,  9615,  9616,  9617,  9618,  9619,  9620,  9621,  9622,  9623,
    9624,  9625,  9626,  9627,  9628,  9629,  9630,  9631,  9632,  9633,
    9634,  9635,  9636,  9637,  9638,  9639,  9640,  9641,  9642,  9643,
    9644,  9645,  9646,  9647,  9648,  9649,  9650,  9651,  9652,  9653,
    9654,  9655,  9656,  9657,  9658,  9659,  9660,  9661,  9662,  9663,
    9664,  9665,  9666,  9667,  9668,  9669,  9670,  9671,  9672,  9673,
    9674,  9675,  9676,  9677,  9678,  9679,  9680,  9681,  9682,  9683,
    9684,  9685,  9686,  9687,  9688,  9689,  9690,  9691,  9692,  9693,
    9694,  9695,  9696,  9697,  9698,  9699,  9700
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
  "MEMBER_FUNCTION", "MISC_INFX_SQL", "DATETIME_VALUE", "INTERVAL_VALUE", 
  "IN_LINE_MODE", "IN_FORM_MODE", "FGL_SIZEOF", "IMPORT_PACKAGE", 
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
  "LOCK_MODE_ROW", "TO_PIPE", "TO_SCREEN", "TO_PRINTER", "STATUSBOX", 
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
  "ROLLFORWARD", "SHOW_OPTION", "SHOW_WINDOW", "SQLSEON", "TO_DATABASE", 
  "USE_SESSION", "WITH_NO_LOG", "AFTDISP", "BEFFIELD", "INSHARE", 
  "UNLOCKTAB", "AFTFIELD", "ATTRIBUTES", "BEFINP", "BEGIN_WORK", 
  "CLEARWIN", "CLOSE_FORM", "DEFER_QUIT", "DESCENDING", "DROP_INDEX", 
  "END_PROMPT", "END_RECORD", "ERROR_LINE", "EXIT_INPUT", "EXIT_WHILE", 
  "FOR_UPDATE_OF", "FOR_UPDATE", "GET_FLDBUF", "INITIALIZE", "INPUT_WRAP", 
  "LOCK_TABLE", "MSG_LINE", "NOT_EXISTS", "ON_ANY_KEY", "REFERENCES", 
  "RENCOL", "SET_CURSOR", "SMALLFLOAT", "SQLSUCCESS", "TOP_MARGIN", 
  "WITH_ARRAY", "ACCEPTKEY", "ACCEPT", "AFTINP", "CLEARFORMTODEFAULTS", 
  "CLEARFORM", "CLEAR_X_FORM", "COMMIT_W", "NEXTPAGE", "PREVPAGE", 
  "CTRL_KEY", "INFTABS", "NEXTFIELD", "NEXTFORM", "RENTAB", "ASCENDING", 
  "ASSOCIATE", "CHAR", "NCHAR", "NVARCHAR", "CONSTRUCT", "DELIMITER", 
  "DOWNSHIFT", "DROP_VIEW", "END_INPUT", "END_WHILE", "EXCLUSIVE", 
  "EXIT_CASE", "EXIT_MENU", "FORM_LINE", "INTERRUPT", "INTO_TEMP", 
  "INVISIBLE", "IN_MEMORY", "LINKED_TO", "LOAD_FROM", "LOCKTAB", 
  "MENU_LINE", "OPEN_FORM", "OTHERWISE", "PRECISION", "PRIOR", 
  "PROCEDURE", "REPORT_TO", "RETURNING", "UNDERLINE", "UNLOAD_TO", 
  "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", "AFTROW", "BUFFERED", 
  "CONSTANT", "CONST", "DATABASE", "DATETIME", "DEFAULTS", "DISTINCT", 
  "END_CASE", "END_MAIN", "END_MENU", "END_TYPE", "EXIT_FOR", "EXTERNAL", 
  "FRACTION", "FUNCTION", "GROUP_BY", "INTERVAL", "KWMESSAGE", "NOT_LIKE", 
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
  "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", "SHARED", 
  "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", "AFTER", 
  "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", "ASCII", 
  "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", "COUNT", 
  "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", "FOUND", 
  "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", "MONEY", 
  "MONTH", "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", "PRINT_FILE", 
  "PRINT", "RIGHT", "DOUBLE_COLON", "SEMICOLON", "SLEEP", "TUPLE", 
  "UNION", "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", "BOLD", 
  "BYTE", "FCALL", "CASE", "CYAN", "DATE", "DESC", "KWDOWN", "TAB", 
  "DROP", "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", "HELP_FILE", 
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
    1434,  1539,  1535,  1451,  1611,  1353,  1410,  1482,  1647,  1634,
    1540,  1567,  1635,  1417,  1721,  1722,  1723,  1724,  1725,  1726,
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
    1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1408,  1409,  1411,  1412,  1413,  1414,  1415,
    1416,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1450,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1481,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
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
     970,   970,   971,   971,   972,   972,   973,   973,   975,   976,
     977,   974,   978,   978,   980,   981,   979,   982,   982,   983,
     983,   984,   984,   986,   985,   987,   985,   988,   988,   989,
     989,   991,   990,   992,   990,   993,   994,   994,   994,   995,
     995,   996,   996,   997,   997,   998,   998,  1000,   999,  1001,
     999,  1002,   999,  1003,   999,  1004,   999,  1006,  1007,  1005,
    1008,  1008,  1009,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1011,  1011,  1012,  1013,  1014,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1016,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1023,  1024,  1025,  1026,  1026,  1027,  1027,  1028,
    1028,  1028,  1028,  1028,  1028,  1029,  1030,  1030,  1031,  1032,
    1032,  1033,  1034,  1034,  1035,  1036,  1037,  1037,  1037,  1038,
    1038,  1038,  1040,  1039,  1041,  1041,  1042,  1042,  1043,  1043,
    1044,  1045,  1045,  1046,  1047,  1047,  1048,  1049,  1049,  1050,
    1051,  1051,  1053,  1054,  1052,  1055,  1056,  1055,  1057,  1058,
    1055,  1059,  1059,  1060,  1061,  1063,  1062,  1062,  1064,  1064,
    1065,  1065,  1066,  1067,  1067,  1067,  1068,  1068,  1069,  1069,
    1071,  1070,  1072,  1070,  1073,  1070,  1074,  1070,  1075,  1070,
    1076,  1070,  1077,  1070,  1078,  1070,  1079,  1070,  1080,  1070,
    1081,  1070,  1082,  1070,  1083,  1070,  1084,  1084,  1085,  1085,
    1086,  1087,  1088,  1088,  1088,  1090,  1089,  1091,  1091,  1092,
    1091,  1093,  1094,  1094,  1094,  1094,  1094,  1094,  1095,  1095,
    1096,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,
    1099,  1098,  1098,  1101,  1100,  1102,  1103,  1104,  1104,  1105,
    1105,  1106,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,
    1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,  1107,
    1108,  1110,  1111,  1109,  1112,  1112,  1113,  1114,  1115,  1116,
    1116,  1117,  1117,  1118,  1120,  1119,  1121,  1121,  1122,  1122,
    1123,  1123,  1123,  1123,  1123,  1123,  1123,  1124,  1124,  1125,
    1125,  1126,  1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,
    1127,  1128,  1129,  1129,  1130,  1131,  1131,  1133,  1134,  1135,
    1136,  1132,  1137,  1139,  1140,  1138,  1141,  1142,  1142,  1143,
    1143,  1144,  1145,  1145,  1146,  1148,  1147,  1149,  1149,  1149,
    1149,  1151,  1152,  1150,  1153,  1153,  1155,  1154,  1156,  1154,
    1158,  1157,  1159,  1161,  1160,  1162,  1160,  1163,  1160,  1164,
    1164,  1165,  1165,  1166,  1166,  1167,  1167,  1167,  1168,  1169,
    1170,  1171,  1171,  1171,  1172,  1172,  1173,  1173,  1174,  1175,
    1175,  1175,  1175,  1176,  1176,  1176,  1176,  1176,  1177,  1178,
    1178,  1179,  1180,  1181,  1181,  1182,  1183,  1183,  1183,  1183,
    1183,  1183,  1184,  1185,  1186,  1186,  1187,  1187,  1188,  1189,
    1189,  1190,  1190,  1191,  1192,  1193,  1193,  1193,  1193,  1193,
    1193,  1194,  1194,  1195,  1196,  1196,  1197,  1197,  1198,  1198,
    1199,  1199,  1200,  1200,  1200,  1200,  1200,  1201,  1201,  1202,
    1202,  1203,  1203,  1204,  1205,  1206,  1206,  1207,  1208,  1208,
    1208,  1209,  1209,  1210,  1210,  1211,  1212,  1212,  1213,  1213,
    1214,  1215,  1216,  1217,  1217,  1218,  1219,  1219,  1220,  1220,
    1221,  1221,  1222,  1223,  1223,  1224,  1224,  1224,  1224,  1225,
    1225,  1225,  1226,  1227,  1227,  1228,  1228,  1228,  1229,  1230,
    1230,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,
    1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,
    1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1232,
    1232,  1233,  1233,  1234,  1235,  1235,  1236,  1236,  1236,  1236,
    1236,  1237,  1239,  1238,  1240,  1240,  1241,  1242,  1242,  1243,
    1243,  1244,  1244,  1246,  1245,  1247,  1249,  1248,  1250,  1250,
    1251,  1251,  1252,  1252,  1253,  1253,  1253,  1253,  1253,  1254,
    1254,  1255,  1255,  1256,  1257,  1257,  1258,  1259,  1260,  1261,
    1262,  1262,  1263,  1263,  1265,  1264,  1266,  1264,  1267,  1264,
    1268,  1264,  1269,  1264,  1270,  1264,  1271,  1264,  1272,  1272,
    1272,  1272,  1272,  1272,  1274,  1273,  1275,  1275,  1277,  1276,
    1276,  1276,  1276,  1276,  1278,  1278,  1279,  1279,  1280,  1281,
    1281,  1283,  1282,  1284,  1284,  1285,  1286,  1287,  1287,  1287,
    1288,  1288,  1288,  1288,  1289,  1290,  1290,  1291,  1291,  1292,
    1293,  1293,  1293,  1293,  1293,  1293,  1293,  1293,  1294,  1294,
    1295,  1295,  1296,  1296,  1296,  1296,  1296,  1296,  1296,  1296,
    1296,  1296,  1297,  1297,  1298,  1298,  1298,  1298,  1299,  1299,
    1300,  1300,  1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,
    1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,  1301,
    1301,  1301,  1301,  1301,  1301,  1301,  1302,  1302,  1302,  1304,
    1305,  1306,  1307,  1308,  1309,  1303,  1310,  1310,  1311,  1312,
    1312,  1314,  1315,  1316,  1317,  1318,  1319,  1313,  1320,  1322,
    1323,  1324,  1321,  1325,  1325,  1325,  1325,  1326,  1326,  1326,
    1326,  1326,  1326,  1326,  1326,  1327,  1327,  1328,  1329,  1329,
    1329,  1329,  1330,  1330,  1332,  1333,  1331,  1334,  1335,  1331,
    1336,  1336,  1337,  1337,  1338,  1338,  1338,  1338,  1338,  1339,
    1340,  1340,  1341,  1341,  1342,  1342,  1343,  1343,  1343,  1343,
    1343,  1344,  1344,  1345,  1345,  1346,  1346,  1346,  1347,  1347,
    1348,  1348,  1349,  1349,  1350,  1350,  1350,  1351,  1351,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1353,  1353,  1354,  1354,
    1355,  1355,  1356,  1356,  1357,  1357,  1358,  1359,  1359,  1360,
    1360,  1361,  1362,  1362,  1363,  1364,  1364,  1365,  1365,  1366,
    1366,  1367,  1367,  1368,  1368,  1369,  1370,  1370,  1370,  1370,
    1370,  1370,  1370,  1370,  1370,  1370,  1370,  1371,  1371,  1372,
    1372,  1373,  1374,  1376,  1375,  1378,  1377,  1377,  1379,  1379,
    1380,  1380,  1381,  1381,  1382,  1382,  1384,  1383,  1385,  1386,
    1386,  1387,  1388,  1387,  1389,  1390,  1389,  1391,  1391,  1391,
    1391,  1391,  1391,  1391,  1391,  1392,  1393,  1394,  1395,  1395,
    1396,  1397,  1397,  1398,  1398,  1398,  1399,  1400,  1401,  1401,
    1402,  1403,  1403,  1403,  1405,  1404,  1406,  1406,  1406,  1406,
    1406,  1406,  1406,  1406,  1406,  1406,  1406,  1406,  1406,  1407,
    1407,  1407,  1407,  1408,  1408,  1408,  1409,  1409,  1409,  1410,
    1410,  1410,  1411,  1411,  1412,  1412,  1412,  1412,  1412,  1412,
    1413,  1413,  1414,  1414,  1415,  1415,  1416,  1416,  1417,  1418,
    1418,  1419,  1419,  1420,  1420,  1421,  1422,  1423,  1424,  1425,
    1425,  1426,  1426,  1427,  1427,  1427,  1428,  1428,  1429,  1429,
    1429,  1430,  1430,  1430,  1430,  1431,  1432,  1432,  1433,  1433,
    1434,  1434,  1435,  1436,  1436,  1436,  1436,  1436,  1436,  1436,
    1437,  1438,  1439,  1440,  1440,  1441,  1441,  1442,  1443,  1444,
    1444,  1445,  1446,  1447,  1447,  1448,  1448,  1448,  1449,  1449,
    1449,  1450,  1450,  1451,  1452,  1452,  1453,  1453,  1454,  1454,
    1455,  1455,  1456,  1456,  1457,  1457,  1458,  1458,  1459,  1459,
    1460,  1460,  1461,  1462,  1463,  1463,  1463,  1463,  1464,  1464,
    1465,  1465,  1466,  1466,  1467,  1467,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1469,  1469,  1469,  1470,  1470,  1470,  1470,  1471,  1471,  1471,
    1472,  1472,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1474,  1474,  1475,
    1475,  1475,  1475,  1475,  1476,  1477,  1478,  1479,  1479,  1479,
    1479,  1479,  1479,  1479,  1479,  1480,  1480,  1480,  1480,  1480,
    1480,  1480,  1480,  1481,  1482,  1482,  1482,  1483,  1483,  1484,
    1484,  1484,  1485,  1486,  1486,  1486,  1486,  1487,  1488,  1489,
    1489,  1490,  1490,  1491,  1491,  1491,  1491,  1491,  1491,  1491,
    1491,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1494,  1494,  1494,  1495,
    1497,  1496,  1498,  1496,  1499,  1496,  1500,  1496,  1501,  1501,
    1501,  1502,  1502,  1503,  1503,  1503,  1504,  1504,  1505,  1505,
    1506,  1508,  1509,  1507,  1510,  1511,  1511,  1512,  1513,  1513,
    1513,  1513,  1513,  1514,  1515,  1515,  1516,  1517,  1518,  1518,
    1518,  1518,  1519,  1519,  1520,  1520,  1520,  1521,  1522,  1522,
    1522,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1524,
    1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,
    1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,  1524,
    1524,  1525,  1525,  1526,  1527,  1528,  1528,  1529,  1529,  1530,
    1530,  1531,  1531,  1532,  1532,  1533,  1534,  1534,  1535,  1535,
    1536,  1537,  1537,  1537,  1538,  1538,  1539,  1540,  1541,  1542,
    1543,  1543,  1544,  1544,  1544,  1544,  1544,  1544,  1545,  1545,
    1545,  1545,  1546,  1546,  1547,  1548,  1548,  1548,  1549,  1551,
    1550,  1552,  1552,  1553,  1553,  1553,  1555,  1554,  1557,  1556,
    1559,  1560,  1558,  1561,  1561,  1561,  1562,  1562,  1562,  1562,
    1562,  1562,  1563,  1563,  1564,  1565,  1566,  1566,  1567,  1567,
    1568,  1568,  1569,  1569,  1569,  1570,  1570,  1570,  1570,  1570,
    1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1571,
    1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,
    1571,  1571,  1571,  1571,  1571,  1572,  1573,  1573,  1575,  1574,
    1576,  1576,  1577,  1577,  1578,  1579,  1580,  1580,  1581,  1581,
    1582,  1582,  1582,  1583,  1583,  1584,  1584,  1585,  1586,  1586,
    1587,  1587,  1588,  1589,  1591,  1592,  1590,  1593,  1593,  1594,
    1594,  1595,  1595,  1595,  1595,  1595,  1595,  1595,  1596,  1596,
    1597,  1597,  1598,  1598,  1599,  1599,  1600,  1601,  1602,  1603,
    1603,  1604,  1605,  1605,  1606,  1607,  1607,  1609,  1608,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610
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
       1,     2,     1,     3,     1,     3,     1,     3,     0,     0,
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
       7,     5,     2,     2,     2,     0,     5,     4,     1,     3,
       3,     3,     1,     0,     2,     1,     0,     1,     1,     2,
       0,     4,     0,     4,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     1,     3,     1,     3,
       2,     4,     1,     1,     1,     0,     4,     5,     6,     0,
      10,     3,     2,     2,     1,     1,     2,     2,     0,     2,
       1,     2,     3,     3,     3,     3,     1,     1,     1,     1,
       0,     3,     1,     0,     3,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     7,     1,     1,     2,     2,     2,     3,
       4,     1,     1,     1,     0,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     0,     0,     0,
       0,    13,     1,     0,     0,     6,     2,     1,     2,     2,
       2,     1,     1,     2,     1,     0,     3,     2,     1,     1,
       1,     0,     0,     7,     1,     2,     0,     3,     0,     4,
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
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     5,     1,     1,     2,     4,     4,     6,
       2,     1,     0,    11,     0,     2,     5,     0,     1,     0,
       2,     1,     2,     0,     3,     1,     0,     4,     0,     2,
       1,     3,     1,     1,     4,     5,     5,     5,     3,     0,
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
       0,     0,    10,     0,     1,     3,     3,     2,     3,     4,
       3,     5,     4,     3,     3,     1,     1,     1,     2,     2,
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
       3,     1,     3,     4,     0,     1,     0,     1,     0,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     2,     2,
       0,     2,     1,     1,     5,     3,     5,     3,     1,     3,
       1,     1,     0,     1,     3,     3,     3,     6,     4,     4,
       4,     4,     5,     1,     1,     1,     1,     1,     1,     1,
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
       4,     1,     2,     1,     1,     1,     0,     3,     0,     3,
       0,     0,     6,     0,     2,     2,     7,     3,     3,     2,
       2,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     2,     2,     1,     1,     2,     4,     5,
       7,     7,     9,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     3,     5,     5,     5,     5,     5,     4,
       4,     3,     4,     1,     1,     1,     1,     3,     0,     5,
       1,     3,     3,     3,     1,     1,     2,     1,     1,     3,
       1,     3,     3,     1,     1,     1,     3,     2,     3,     6,
       1,     3,     1,     1,     0,     0,     6,     0,     2,     0,
       1,     1,     2,     2,     1,     1,     4,     3,     1,     2,
       5,     2,     2,     5,     0,     2,     1,     1,     2,     6,
       6,     1,     0,     1,     2,     1,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     856,     0,  1943,     0,     0,     0,     0,   905,   192,     0,
       0,   853,   881,   884,   190,   195,   863,   860,     0,   851,
     852,   854,   857,   858,   861,   865,   866,   864,   901,   902,
     904,   862,   148,   145,     0,   141,   143,   142,   146,  1971,
     733,   673,   734,   324,  1718,  1716,   899,   188,   198,   900,
     125,   191,     1,   867,   859,   903,   140,   144,   147,     0,
       0,   650,     0,     0,   189,   908,   970,   651,   909,   910,
     906,   685,   962,     0,   963,   971,   969,   198,   193,   211,
       0,   196,   212,   250,   129,     0,   886,  1271,     0,   885,
    1259,   893,     0,     0,   878,   877,   879,   855,   868,   869,
     887,   872,   873,   876,   874,   875,   880,     0,  1717,   964,
     907,     0,     0,   978,   976,   977,   966,   965,   322,   198,
    1195,   205,   199,   198,   204,   247,     0,     0,   126,   732,
       0,     0,     0,   188,   594,   911,   870,     0,   356,   342,
     214,   328,   293,   312,   333,   335,   332,     0,   354,     0,
     341,   334,   338,   344,   343,   198,   345,   325,   348,   326,
     327,   975,   974,     0,    22,    23,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   983,     0,   556,
     548,    16,   555,   970,    15,     0,   981,     0,   323,     0,
     197,  1196,   194,     0,   211,   213,   288,   216,   276,   282,
     283,   267,   240,   278,   214,   255,   256,     0,   242,   293,
     312,   265,   268,   263,     0,   238,     0,   274,   266,   271,
     281,   280,   198,   284,   198,   253,   254,   251,   287,   130,
     188,     0,     0,     0,   894,   188,   188,     0,     0,   215,
       0,     0,   346,     0,     0,   347,     0,     0,     0,     0,
       0,     0,     0,   235,     0,   972,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   562,
       0,     0,     0,   686,   453,   455,  1266,     0,     0,     0,
    1691,     0,   449,     0,     0,     0,   448,     0,   463,   558,
       0,     0,     0,     0,     0,   561,   416,   422,   459,   456,
     417,   418,   420,   421,   454,   457,   462,   557,   511,   508,
     517,   514,     0,     0,    17,    18,    19,    20,    21,     0,
      14,     0,   499,     0,     0,   979,     0,   200,   203,   201,
     202,     0,   208,   207,   206,   209,   217,   218,   219,   222,
     289,   198,   289,     0,     0,     0,     0,   198,   285,   286,
       0,     0,   198,     0,   289,     0,     0,   264,   248,   127,
    1272,     0,  1260,  1977,   595,   912,   888,     0,   226,   227,
       0,     0,   305,   307,   302,   303,   299,   301,   298,   300,
     297,     0,   307,   318,   319,   315,   317,   314,   316,   309,
       0,     0,     0,   358,     0,   361,   363,   234,     0,   233,
       0,   198,   198,   198,     0,     0,     0,   584,   655,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   580,   566,
     571,     0,     0,   567,   570,   569,   664,     0,   663,   586,
       0,    11,   184,   447,   424,   423,     0,  1201,     0,     0,
     461,  1699,  1697,  1698,  1694,  1696,  1693,  1695,  1687,     0,
       0,     0,   460,     0,     0,     0,     0,     0,     0,     0,
     687,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   563,   564,   565,   474,     0,     0,
     473,   483,     0,     0,   428,     0,     0,   429,   419,   425,
     427,   430,   431,   432,   433,   434,   426,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    96,     0,   982,     0,
     967,   210,     0,     0,   277,     0,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,   198,   249,
     252,     0,   994,   731,   994,     0,  1975,  1977,  1195,  1818,
     882,     0,   994,     0,     0,   329,   294,     0,     0,   304,
     321,   295,   320,     0,   313,     0,   336,     0,   330,     0,
     355,     0,   360,   350,     0,     0,   339,   236,     0,   292,
     349,   542,     0,     0,   554,     0,     0,   551,   550,   553,
     549,   560,   545,   545,     0,     0,   545,     0,   568,     0,
     572,     0,   581,   312,     0,   552,   559,   296,     0,  1267,
    1758,     0,     0,     0,     0,     0,   450,     0,     0,   464,
       0,     0,     0,     0,   466,   465,   484,   475,   490,   493,
     494,   491,   497,   496,   495,   485,   486,   487,   488,   489,
     435,   476,   480,   498,   492,   479,   498,   458,   512,   509,
     518,   515,   543,     0,   505,   101,   500,    97,    98,   100,
     502,     0,     0,   250,     0,     0,     0,   257,   258,     0,
     261,     0,     0,   269,     0,   259,   239,   220,     0,   272,
     291,     0,   131,   133,  1000,     0,   995,   996,     0,   895,
    1976,  1974,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1958,     0,  1392,
    1391,     0,  1393,     0,   412,  1390,  1307,     0,     5,  1389,
     413,   410,     0,   415,   186,   498,  1170,     0,     0,  1399,
     137,   409,   408,     0,     0,   403,   498,     0,  1343,  1951,
       0,   414,   375,     0,     3,     2,     0,   411,  1304,     0,
       0,   404,   401,   397,     0,     0,     0,     0,  1397,  1387,
     407,     0,     0,     0,     0,     0,     0,     0,     0,  1386,
       0,     0,     0,   187,     0,   400,   399,     0,     0,  1955,
    1954,     0,     0,     0,   149,     0,   406,   405,     0,     0,
     402,   498,     0,     0,   498,     0,   588,     0,     0,     0,
       0,     0,     0,   498,   840,  1269,     0,     0,  1181,     0,
    1944,     0,   108,     0,     0,   920,     0,     0,     0,     0,
     841,     0,     0,  1849,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   702,     0,     0,  1979,  1980,  1981,  1982,
    1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,
    1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,  2002,
    2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,  2012,
    2013,  2014,  2015,  2016,  2017,  2018,  2019,  2020,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,   949,  2028,  2029,  2030,  2031,
    2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,  2041,
    2042,  2043,  2044,  1161,  1163,  1158,  1160,  1159,  1162,  2045,
    2046,  1297,  2047,  1303,  1302,  2048,  2049,  2050,  2051,  2052,
    2053,  2054,  2055,  2056,  2057,  1454,  2058,  2059,  2060,  2061,
    2062,  2063,  2064,  2065,  2066,  1978,   883,   599,     0,   916,
       0,   914,     0,   357,   228,   229,     0,   306,   311,     0,
       0,     0,     0,   359,   362,     0,   232,     0,   198,     0,
     585,     0,   659,     0,   661,     0,   523,   521,     0,   545,
       0,   522,     0,     0,   583,     0,   579,   576,   547,   520,
     587,     0,   183,  1760,  1761,  1759,     0,   452,  1266,     0,
    1692,  1266,   451,  1266,  1266,  1266,  1266,  1266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,    96,   980,     0,   223,   290,   241,
       0,     0,   198,     0,     0,     0,     0,   128,   132,     0,
    1273,     0,  1261,   394,   392,   393,  1301,  1095,  1094,  1100,
       0,  1666,  1667,     0,     0,  1327,   674,   675,  1328,  1658,
    1659,  1330,   871,  1133,  1138,  1953,   667,   136,  1966,     0,
       0,  1342,     7,     0,     6,     0,  1959,  1134,     0,  1229,
    1228,  1173,  1227,  1172,   446,  1400,  1388,     0,  1298,   896,
     436,  1820,  1394,   138,     0,  1137,   135,     0,   847,    24,
     669,   398,     0,   846,  1129,   848,     0,  1398,   942,   941,
     944,   940,   943,  1968,     0,   938,     0,   668,  1026,   939,
    1962,     0,  1952,   134,  1300,  1023,   735,  1021,     0,   665,
    1947,   783,   782,   784,   780,     0,     0,  1299,  1036,   670,
    1453,     0,  1934,  1448,  1451,  1924,  1927,  1928,  1930,  1933,
       0,     0,     0,     0,  1101,  1096,     0,  1075,  1076,  1077,
    1078,  1084,  1085,  1086,  1083,  1082,     0,     0,     0,  1081,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1067,  1058,  1059,  1009,     0,
    1007,  1115,   444,    24,     0,  1949,   139,   666,     0,  1270,
    1268,  1194,     0,  1809,     0,  1810,  1195,  1183,  1174,  1401,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
     970,     0,    69,     0,   106,   642,     0,   689,   688,     0,
    1164,  1043,  1168,     0,     0,  1116,  1287,     0,     0,  1171,
     694,   691,   692,     0,   696,   697,     0,   699,   700,     0,
     695,  1004,  1006,     0,     0,  1005,   785,  1002,   746,   998,
     961,     0,     0,     0,     0,   706,   707,     0,     0,   959,
     956,   957,   953,   954,   955,   948,   952,   951,     0,     0,
       0,     0,     0,     0,   603,   605,   597,   600,   601,   918,
    1977,   913,   915,   889,     0,   308,   310,   337,   331,     0,
       0,   340,   237,   656,   658,     0,     0,     0,     0,   545,
     528,     0,   545,   545,     0,   573,     0,   305,     0,     0,
    1788,  1683,  1685,  1844,  1848,  1789,  1689,  1786,     0,     0,
    1785,     0,     0,     0,  1787,     0,     0,     0,     0,     0,
       0,     0,  1934,  1684,  1784,  1686,  1773,     0,  1762,  1764,
    1768,  1771,  1799,  1842,  1800,  1845,  1935,  1925,  1772,  1204,
    1700,  1203,  1202,  1205,  1207,  1206,  1200,   477,   478,   482,
     467,     0,   470,   481,     0,   469,   513,   510,   519,   516,
     544,   506,   501,    99,   503,   968,     0,   262,   246,     0,
     244,   270,   260,   250,   273,  1001,   188,   997,   188,     0,
       0,     0,  1372,  1373,     0,     0,     0,  1344,  1347,  1349,
    1350,  1351,  1355,  1354,  1352,  1353,     0,     0,     0,  1345,
    1346,     0,     0,     0,     0,     0,     0,     0,     0,  1135,
       0,    24,  1224,  1226,  1225,     0,   439,   440,   437,   438,
    1014,     0,     0,   380,    25,   374,     0,  1130,     0,     0,
    1129,     0,  1128,     0,     0,     0,     0,     0,     0,  1030,
    1819,     0,     0,     0,     0,     0,     0,  1949,     0,     0,
     150,     0,     0,  1040,  1032,  1033,  1038,     0,     0,  1926,
       0,  1937,  1449,  1450,     0,     0,   958,   442,  1918,  1053,
     364,     0,     0,   589,   647,   646,   644,   649,  1061,   648,
    1066,  1062,  1065,   839,   831,   825,   837,   838,   823,   824,
     832,   827,   833,   826,   836,   830,   834,   829,   835,   822,
     828,   815,   821,  1063,  1064,     0,  1071,  1079,  1068,  1069,
    1073,  1074,  1072,  1070,  1089,  1090,  1087,  1080,  1091,  1092,
    1088,     0,     0,     0,   849,     0,     0,     0,     0,     0,
     795,   794,   791,  1950,  1957,    24,  1190,  1191,  1192,  1193,
    1187,     0,  1185,  1283,  1195,  1175,  1176,  1179,  1197,  1945,
       0,     0,     0,     0,   102,     0,   103,     0,     0,     0,
      77,     0,     0,     0,     0,   115,   110,     0,   690,   947,
       0,   946,     0,   498,  1166,     0,   989,   990,  1013,   984,
     985,   842,  1011,  1118,  1296,  1295,  1290,     0,  1294,  1293,
    1288,  1853,  1856,  1858,     0,  1851,  1854,  1855,   722,     0,
       0,     0,   711,   746,   746,   743,     0,     0,   747,     0,
      26,   710,   713,     0,   720,   716,   960,   950,  1816,  1817,
    1807,  1807,  1418,     0,     0,  1719,  1457,     0,     0,  1402,
       0,     0,  1403,  1446,     0,     0,  1447,     0,     0,  1758,
       0,  1416,     0,  1466,  1465,  1464,  1462,  1463,  1461,  1459,
    1455,  1546,  1545,  1456,  1458,  1467,  1740,  1460,  1823,  1822,
    1821,  1468,  1977,  1977,   616,   607,   598,     0,   602,  1977,
     917,   188,     0,   351,   231,     0,     0,   546,     0,   545,
       0,   532,   545,     0,   525,   524,     0,     0,     0,   578,
     577,   185,  1770,  1769,  1707,  1705,  1706,  1702,  1704,  1701,
    1703,  1688,     0,  1758,     0,     0,  1613,     0,     0,  1776,
    1774,  1775,  1613,  1613,  1613,  1613,  1777,     0,     0,     0,
    1564,  1748,     0,  1765,     0,     0,     0,     0,  1832,  1833,
    1834,  1835,  1836,  1837,  1780,     0,     0,     0,     0,   472,
     471,     0,     0,     0,   198,   243,   221,  1274,  1262,     0,
       0,     0,     0,     0,     0,  1520,  1519,  1518,  1379,     0,
    1385,  1381,  1383,  1374,     0,  1622,  1371,  1367,  1341,  1340,
       0,  1366,  1362,     0,  1358,  1356,     0,  1665,     0,  1668,
    1670,   678,     0,   677,  1657,     0,  1660,  1662,  1967,  1964,
       0,     0,  1308,   498,   372,  1329,     0,     0,  1305,  1045,
    1131,  1132,  1129,  1129,  1124,  1129,     0,   945,     0,     0,
     652,     0,     0,     0,  1024,  1022,   737,   738,     0,   742,
       0,     0,  1948,  1956,   781,     0,   154,     0,  1034,  1041,
       0,     0,  1049,  1929,  1942,     0,  1940,  1452,  1932,  1931,
       0,     0,     0,  1055,   367,     0,     0,     0,     0,    24,
    1097,  1098,   592,     0,     0,     0,   816,   817,  1060,  1010,
    1008,   850,   445,     0,  1107,   792,   796,   793,   797,   395,
       0,  1195,  1184,  1284,  1199,  1182,  1177,     0,     0,  1178,
    1977,     0,     0,     0,     0,     0,     0,     0,    64,    96,
       0,     0,     0,   121,   116,     0,   111,     0,   118,   112,
     931,   923,   929,     0,  1165,     0,  1167,  1169,     0,     0,
     993,     0,     0,     0,     0,  1117,  1289,  1292,     0,     0,
       0,  1850,  1852,  1977,   693,   698,   701,   714,   712,   671,
       0,   770,   768,   766,   764,   774,   772,     0,     0,   762,
     812,   760,   745,   756,   754,   810,   786,     0,   748,   758,
    1003,   999,     0,     0,     0,     0,   719,     0,     0,     0,
       0,     0,     0,     0,  1673,     0,  1541,  1542,  1828,  1499,
    1564,     0,     0,     0,  1826,     0,  1479,  1474,  1473,  1486,
    1485,  1490,  1490,  1488,  1489,  1480,  1475,     0,     0,  1481,
    1482,  1741,  1860,     0,     0,     0,   604,   606,     0,     0,
     619,   611,   613,     0,   608,   609,     0,     0,   627,   629,
       0,     0,   625,   919,   890,   230,     0,   660,   662,   657,
       0,   545,   534,     0,   529,     0,     0,   545,   545,   575,
     574,     0,     0,  1797,  1689,     0,     0,  1772,  1615,  1616,
    1614,     0,  1801,     0,     0,     0,     0,     0,     0,     0,
    1763,     0,  1552,  1553,  1555,  1558,     0,  1565,  1566,     0,
       0,  1613,  1750,  1744,  1766,  1782,  1783,  1781,  1779,     0,
       0,     0,  1936,   468,   507,   504,     0,   245,  1230,  1208,
       0,     0,     0,     0,  1379,     0,     0,     0,  1375,     0,
       0,     0,  1369,  1653,  1651,  1620,  1632,  1634,  1638,  1640,
    1631,  1625,  1630,  1644,  1623,  1652,  1628,  1643,  1629,  1650,
    1642,  1526,  1617,  1618,  1619,     0,  1364,  1360,     0,     0,
    1348,     0,     0,   676,     0,     0,     0,  1963,     0,     4,
       8,    10,     0,   498,   441,     0,     0,     0,  1042,  1126,
    1127,  1125,     0,     0,     0,     0,     0,     0,     0,     0,
     736,     0,     0,   171,   169,     0,     0,   151,     0,   161,
     167,   746,   156,   158,     0,  1039,  1050,  1051,     0,     0,
    1938,   443,     0,  1919,  1920,  1054,     0,     0,  1052,   366,
     371,   654,   365,     0,   368,   373,     0,   498,  1424,   645,
     643,     0,   819,  1106,  1108,     0,   396,  1188,  1186,     0,
    1198,  1180,     0,     0,  1279,     0,     0,     0,   104,     0,
       0,    78,    84,    74,    71,  1977,  1977,   114,   109,   123,
     119,     0,   113,   813,   932,   671,  1977,   922,   921,   930,
    1044,     0,     0,   991,   992,   986,  1012,   498,  1123,  1119,
    1120,  1122,  1291,  1857,  1859,   723,   717,   715,     0,    24,
       0,  1977,  1977,  1977,  1977,  1977,  1977,   776,   750,   778,
     752,  1977,  1977,  1977,  1977,     0,   744,   749,  1977,   671,
     808,   806,   809,   807,     0,     0,    46,    44,    41,    35,
      39,    43,    38,    31,    40,     0,    34,    37,    32,    42,
      33,    45,    36,     0,    29,    47,   800,     0,   721,  1808,
       0,  1806,  1758,  1804,  1745,  1746,  1738,  1724,  1739,     0,
       0,     0,  1093,  1540,  1543,     0,     0,     0,  1436,  1408,
    1831,  1830,  1829,     0,     0,     0,  1484,  1487,     0,     0,
       0,     0,     0,  1431,     0,  1430,     0,  1432,  1427,  1428,
    1429,  1420,  1421,     0,     0,     0,   618,   623,     0,     0,
    1977,  1977,   596,   610,   633,   621,   635,  1977,  1977,   631,
     615,   626,   882,   352,   545,     0,   533,   545,     0,   545,
     545,   527,   526,  1714,  1712,  1713,  1709,  1711,  1708,  1710,
    1690,     0,     0,     0,     0,  1798,     0,     0,     0,  1796,
       0,     0,     0,     0,  1778,  1795,     0,  1556,     0,     0,
    1682,  1559,     0,     0,     0,     0,  1551,  1570,  1572,  1574,
    1612,  1611,  1610,  1576,  1592,     0,  1567,  1568,  1753,  1331,
       0,     0,     0,  1843,     0,  1847,   224,     0,  1256,  1275,
       0,  1263,  1256,     0,  1674,     0,  1508,     0,  1511,  1677,
       0,  1516,     0,     0,  1376,  1377,     0,     0,  1380,  1382,
    1384,     0,  1368,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1524,  1523,  1522,     0,  1527,  1528,     0,
    1363,     0,  1357,  1359,  1669,     0,  1671,  1661,     0,  1663,
    1965,  1337,     0,  1333,     0,     0,  1338,   897,     0,     0,
       0,     0,     0,  1395,  1970,  1969,   653,     0,     0,    48,
       0,   739,   741,   740,  1396,   746,  1977,  1977,   163,   679,
     173,   165,   175,   155,   162,  1977,     0,     0,     0,     0,
       0,  1941,     0,     0,     0,     0,     0,     0,  1099,     0,
    1425,   590,     0,   818,  1104,     0,  1285,  1286,  1946,     0,
      96,     0,    65,     0,     0,     0,    81,     0,    96,    96,
      96,   122,   117,  1977,  1977,   107,     0,   933,   927,   935,
     934,   924,   640,   973,     0,     0,     0,   725,   704,   718,
     672,   787,     0,   771,   769,   767,   765,   775,   773,     0,
    1977,     0,  1977,   763,   761,   757,   755,   811,   759,    24,
     801,     0,     0,     0,    27,     0,  1811,     0,  1725,     0,
       0,  1737,  1720,  1736,  1544,     0,  1501,     0,  1435,     0,
       0,  1827,     0,  1824,     0,  1492,  1496,  1472,  1494,  1497,
       0,  1483,  1742,     0,     0,     0,     0,     0,     0,  1861,
    1434,  1433,  1422,  1417,  1419,  1471,     0,     0,   620,   617,
     612,   614,     0,  1977,  1977,   628,   630,  1977,  1977,     0,
     535,     0,   539,     0,     0,   531,   530,     0,     0,     0,
       0,     0,     0,  1794,  1802,  1790,  1791,  1792,  1793,  1561,
       0,  1554,  1560,  1575,  1579,     0,  1592,  1578,     0,     0,
    1593,  1605,  1606,  1603,  1609,  1608,  1604,     0,     0,     0,
       0,     0,  1607,     0,     0,     0,  1548,  1549,  1767,     0,
    1569,  1563,  1332,  1751,  1441,  1437,  1438,  1443,  1442,  1749,
    1331,     0,     0,  1254,  1255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1253,     0,     0,  1241,
    1242,  1243,  1240,  1245,  1246,  1247,  1244,  1231,  1222,     0,
       0,  1278,     0,     0,  1217,     0,     0,     0,     0,     0,
       0,     0,  1209,  1210,     0,  1139,  1678,     0,  1679,     0,
       0,     0,     0,  1515,  1514,  1379,  1513,  1505,  1370,  1654,
       0,     0,     0,     0,     0,     0,  1655,  1647,     0,     0,
       0,  1647,  1683,  1521,  1534,  1539,     0,  1536,  1533,  1535,
       0,  1537,  1525,  1529,  1530,  1379,  1365,  1361,     0,     0,
    1336,  1335,     0,  1320,     9,     0,  1310,   898,  1136,   378,
    1310,     0,     0,  1961,     0,     0,  1025,    49,     0,   798,
     172,   170,     0,  1977,     0,     0,     0,  1977,   168,   157,
       0,   160,   159,     0,  1031,  1035,     0,  1923,  1922,  1921,
       0,     0,   370,     0,   593,     0,  1977,   820,     0,   671,
    1189,     0,  1280,    70,     0,     0,   105,    68,    96,    79,
      85,     0,     0,   124,   120,   814,  1977,   937,   671,   936,
       0,   637,     0,   844,   845,   843,  1121,   728,   726,     0,
     708,   705,     0,   777,   751,   779,   753,   788,   804,   805,
     802,   803,    30,    28,     0,  1805,  1754,  1726,  1722,  1721,
       0,  1500,  1758,  1503,     0,  1410,  1405,  1404,  1407,     0,
       0,  1491,     0,     0,  1754,     0,     0,  1898,  1896,     0,
       0,  1880,  1895,     0,     0,  1897,     0,     0,     0,     0,
       0,  1934,  1894,  1886,  1913,  1914,     0,  1878,  1881,  1882,
    1893,  1885,  1915,     0,  1871,  1870,  1874,  1876,     0,  1869,
       0,  1872,  1863,     0,     0,   624,   622,   634,   636,   632,
       0,     0,   545,     0,   545,   545,     0,  1757,     0,  1690,
       0,     0,     0,  1557,  1577,  1571,  1573,  1580,  1582,  1580,
       0,  1587,  1580,     0,  1585,  1580,     0,  1595,  1594,     0,
    1596,     0,  1547,     0,  1445,  1444,  1440,  1752,     0,   250,
    1248,  1249,  1250,  1252,  1235,  1233,  1232,  1236,  1237,  1234,
    1251,  1238,  1239,  1223,  1018,  1258,  1015,     0,     0,  1276,
    1221,  1220,  1215,  1213,  1212,  1216,  1214,  1218,  1219,  1211,
    1264,     0,  1506,  1512,  1681,  1674,  1517,  1378,  1621,  1633,
       0,  1635,  1637,     0,  1639,     0,     0,     0,  1645,  1624,
    1649,     0,  1507,  1509,     0,  1531,  1532,  1672,  1664,  1334,
       0,     0,  1326,  1321,  1322,  1339,     0,  1317,  1318,     0,
       0,  1331,  1311,  1312,     0,    24,  1306,     0,     0,  1048,
       0,    50,  1028,     0,    24,   174,   164,     0,   681,   683,
     176,   166,   798,     0,  1939,  1057,     0,   369,  1426,     0,
    1105,    24,     0,     0,    66,     0,    82,    91,     0,    75,
      72,   928,   925,   641,  1977,   987,     0,  1977,   724,   703,
     709,   671,  1815,     0,  1813,     0,     0,  1727,  1723,  1502,
       0,  1504,  1498,     0,  1409,     0,  1825,  1493,  1495,  1470,
       0,  1884,  1883,     0,     0,  1613,     0,  1613,  1613,  1613,
    1613,  1887,     0,     0,  1867,     0,     0,     0,     0,  1900,
    1868,     0,     0,     0,     0,     0,     0,  1862,  1423,  1476,
     892,   891,   353,   536,     0,     0,   541,   540,  1715,  1838,
    1841,  1839,  1562,     0,  1599,  1601,     0,  1588,  1591,  1590,
    1598,     0,  1600,  1580,     0,  1550,  1439,  1846,   225,  1020,
    1019,  1017,     0,  1257,  1140,  1144,  1146,     0,  1150,     0,
    1148,  1152,  1141,  1142,     0,     0,     0,  1675,  1680,     0,
       0,  1656,  1648,  1626,     0,  1627,     0,     0,  1324,  1319,
    1325,  1323,  1316,  1315,  1314,  1309,  1313,   379,   376,     0,
    1046,     0,     0,     0,  1027,   799,   152,   680,    24,  1037,
    1056,   591,  1102,    67,  1281,    87,     0,     0,    80,    91,
      91,    91,  1977,   638,     0,     0,   727,   789,     0,  1812,
    1755,  1748,     0,  1411,     0,  1748,  1911,     0,     0,  1916,
       0,     0,     0,     0,     0,     0,     0,     0,  1879,  1902,
    1903,  1901,  1899,  1877,     0,  1873,  1875,  1864,  1865,  1477,
       0,  1469,   545,   545,  1581,  1803,  1583,     0,  1586,  1584,
    1602,     0,  1016,  1977,  1977,  1154,  1977,  1156,  1977,  1977,
    1143,  1277,  1265,     0,  1636,     0,  1646,     0,  1538,   381,
    1047,  1960,     0,     0,     0,     0,     0,     0,    55,     0,
      54,     0,    52,     0,     0,   153,  1109,    91,    96,    91,
      92,    86,    76,    73,   926,     0,     0,   729,    24,  1814,
    1747,  1756,  1415,     0,  1412,  1414,  1728,  1912,     0,     0,
    1910,     0,     0,     0,     0,     0,  1888,  1909,     0,  1478,
     538,   537,  1589,  1597,  1145,  1147,  1977,  1151,  1977,  1149,
    1153,  1676,  1641,  1510,   383,   388,   386,   377,     0,   384,
     390,    57,    62,    59,    61,    58,    60,    56,     0,    51,
       0,   682,   684,  1113,  1103,     0,  1111,  1282,    88,    83,
     639,   988,  1977,   790,     0,  1406,     0,  1729,  1743,  1908,
    1917,  1904,  1905,  1906,  1907,     0,  1889,     0,     0,  1155,
    1157,  1977,  1977,   382,   385,  1977,    53,     0,  1977,  1110,
    1112,     0,   725,  1413,     0,  1733,  1730,  1731,     0,     0,
    1866,   389,   387,   391,     0,  1114,    89,   730,     0,     0,
       0,  1891,     0,  1890,  1029,    93,     0,  1734,  1732,     0,
      95,     0,    90,     0,  1892,    94,  1735
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   846,   847,   848,   849,  1073,  2149,  2150,   187,   329,
     188,  1443,  1444,  1973,  2313,  3360,  2836,  2837,  3262,  3361,
    3362,   850,  1218,  2874,  2570,  3281,  2569,  3280,  1909,  2567,
    3127,  2878,  3276,  2568,  3128,  3368,  3471,  3495,  3278,  3502,
     666,   667,   668,  1575,  2227,   851,  1587,  1223,  1585,  1918,
    2238,  1915,  2236,  2241,  2574,  1586,  2235,  1919,  2573,    11,
      84,   240,   551,   128,   691,   692,   852,    12,    34,    35,
      36,    37,    38,   854,  1136,  1846,  1470,  2177,  2181,  2182,
    2178,  2179,  2843,  2847,  2535,  2527,  2526,  2528,  2531,   507,
     279,   618,   855,    63,    64,    14,    48,   120,    78,   263,
      80,    81,   203,   344,    82,    83,   250,   349,   235,  1035,
     532,  2732,   380,   956,  2036,   408,   409,   264,   236,   362,
     351,   357,  1389,  1390,   124,   550,   125,   126,   368,   237,
     364,   350,   352,   534,   238,   590,   252,   255,   253,   254,
     975,   566,   567,   569,   574,   959,   256,   257,   399,   571,
     199,    15,    59,   157,   158,   159,   965,  2669,   160,   260,
     248,   402,   403,   404,   405,  1869,   856,   857,   858,   859,
    1094,  3349,  3095,  1445,  3417,  3418,  3419,  3462,  3461,  3465,
     860,   861,   862,   863,   864,   865,   866,  1084,   508,  1089,
    1437,  1438,  1486,  1191,  1487,   306,   307,   308,   309,   310,
     465,   509,  1371,   510,   511,   512,   513,   514,   515,   516,
    1011,   189,   526,  1022,  1024,  1762,  1021,  1761,   190,   519,
    1017,   518,  1016,   521,  1019,   520,  1018,   976,   989,   311,
     312,   192,   313,   432,   433,   434,   435,   416,   437,   867,
    1156,  1872,  2866,  2208,    95,   245,   560,  1685,  1286,  1287,
    1288,  1682,  1683,  2023,  2024,  2025,  2370,  2371,  1686,  1687,
    2019,  2374,  2366,  2031,  2032,  2377,  2378,  2667,  2663,  2664,
     868,  3134,  3375,  2891,   869,  1498,    65,  1831,  1832,  2202,
     417,   439,  1128,  1196,  1065,  1116,  1099,  1138,  2269,   193,
    1066,  1056,  1802,  2530,    67,   314,   870,  1228,   871,  1241,
    1242,   872,   873,   874,   875,  1249,  2900,  1270,  3139,  1271,
    1947,  1272,  2266,  1273,  2588,  1274,  1976,   876,  1943,  2587,
    2899,  3137,  3136,  3442,    96,    16,    17,   877,  1464,  1836,
    1837,  1838,  1966,  1629,  1967,  1968,  2600,  2602,  2284,  2283,
    2288,  2282,  2281,  2274,  2273,  2272,  2271,  2276,  2275,  2278,
    2280,   878,   879,  1134,   880,  1625,  1256,  3378,   881,  1552,
    3104,  2315,  2316,  1969,  2285,  2244,  2576,  1185,  1526,  1876,
    2211,  1877,  1522,   882,   883,  1234,  1933,  2895,   884,   885,
     886,   887,    18,    19,    20,    53,    21,    22,    23,    97,
      98,   888,    99,    24,   947,    25,   100,   101,   137,   562,
    1691,  2382,  3191,   102,   133,   373,   889,  2508,    26,    27,
      28,    29,    30,    47,    70,   103,   246,   561,   950,   951,
    1290,  1689,   890,  1229,  2248,  1922,  2246,  3282,  2886,  1923,
    2245,  2579,  2888,   891,   892,   893,  1110,  1111,  1590,   894,
    1275,  1276,   895,  1637,  1277,   315,    72,    73,    74,    75,
    1597,   163,   116,    76,   113,   195,   196,  1598,  1599,  2255,
    1600,   695,   696,  1258,   697,  1259,  1189,  1190,  1601,  1602,
    1441,  3035,  3036,  3221,  1126,  1127,   896,  1459,  3264,   897,
    2855,   898,  1474,  1475,  1476,  1852,  1850,   899,   900,  2158,
    2188,   901,  1863,  2198,   902,  1186,  1187,  1536,  1540,   903,
    1049,   904,  2326,   905,  3366,  2869,   906,  2215,  3434,  3435,
    3436,  3468,  1193,   907,  1603,  1935,  2259,  2260,   908,  1452,
    1822,  1064,  1430,   909,   910,   911,  2451,  3039,  3232,  3233,
    3333,  3334,  3338,  3336,  3339,  3406,  3408,   912,   913,  1592,
    1927,   914,  1594,  1564,  1565,  1566,  1899,   915,  1208,  1206,
     916,   917,  1891,  1560,  1202,   202,  1567,  1568,   316,  2452,
    2772,  2773,  2757,  1081,  1082,  2448,  2758,  2761,   104,   132,
     554,  1398,  2099,  2774,  3235,   447,   918,  1200,   105,   130,
     552,  1396,  2098,  2762,  3234,  2449,  1222,  2560,  3123,  3367,
    1894,   919,  1610,   920,   921,   922,   923,  1097,  2156,  1075,
    2152,  3091,  3092,  3093,  3248,  3082,  3083,  3084,   924,  2723,
    2502,  2503,  2505,  1786,   925,   926,  1407,  1408,  1409,  1795,
    2138,  1410,  2135,  1792,  1411,  2111,  1787,  1412,  1413,  1414,
    2103,  2108,  1415,  1781,  1782,   927,  1106,  1086,   928,  1663,
    1664,  1991,  2927,  3155,  2630,  2924,  3383,  3384,  1665,  2013,
    1643,  2362,  2653,  2973,  2551,  2865,  2363,  1666,  1667,  2082,
    2725,  2726,  2727,  3016,  1668,  1669,  1483,   929,  1143,   930,
    1283,  1670,  1671,  2007,  3321,  2008,  2009,  2010,  2346,  2634,
    2637,  2638,  1672,  2336,  2625,  3152,  1775,  1776,  2811,  2455,
    3072,  2456,  1777,  2460,  1788,  2487,  1789,  2488,  2812,  2813,
    2814,  2815,  1673,  1985,  1986,  2333,  1674,  2720,  2436,  2716,
    2077,  1740,  2072,  2073,  2074,  2690,  1741,  2078,  2437,  2721,
    2426,  2427,  2428,  2429,  2430,  3204,  2997,  3324,  2431,  3206,
    3207,  2714,  2432,  2715,  2433,  2061,  2131,  2132,  2133,  3066,
    2134,  2790,  2797,  3242,  2457,  1053,  2639,  2778,  2966,  2459,
    2421,  1344,   317,  1345,  1721,   458,   459,  1722,  2400,    46,
     931,   932,  2919,  3148,  2618,  3147,  3448,  3476,  3477,  2622,
    2327,  1675,  2328,  2351,  2934,   621,  2323,  2324,  2083,  2439,
    3146,  2923,  1346,   996,  1347,  1348,  2717,  2434,  1350,  1351,
    2063,  3326,   933,   934,  1978,  2325,  2915,  3143,  3144,  1640,
     935,  1092,  1677,  1678,  1995,  2632,  1679,  1680,  2342,  1754,
    2056,  1352,  1353,  1354,  1355,   936,  1237,  1614,  1615,  1616,
    1939,  1617,  1940,  1681,  2352,  2972,  3187,  2649,  2969,  2970,
    2971,  2968,  2956,  2957,  2958,  2959,  2960,  2961,  3300,   937,
    1861,  2193,  2194,  1144,  1356,  1357,  1146,  1147,  1148,  1358,
    1149,  1481,  1855,  1856,    31,   939,  1210,  1900,  1467,  1554,
     940,   941,  2519,   942,  2147,  1069,  1809,   943,   944,    41,
     555,   556,   557,   558,   559,   945
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2584
static const short yypact[] =
{
     190,   952, -2584,   382,   382,   382,  1123, -2584, -2584,  1123,
     382, -2584, -2584,   138, -2584, -2584, -2584, -2584,   447, -2584,
   -2584, -2584,  1218, -2584, -2584, -2584, -2584, -2584,     1, -2584,
   -2584, -2584, -2584, -2584,   475,   532, -2584,   528, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,   -32, -2584,  1093,   227, -2584,
   -2584, -2584, -2584,   422, -2584, -2584, -2584, -2584, -2584,   271,
     382, -2584,   382,   717,   138, -2584,   495, -2584, -2584, -2584,
   -2584, -2584, -2584,  1188,   251, -2584, -2584, -2584,  1022,   670,
     382, -2584, -2584,  1087,   407,   382, -2584, -2584,   382, -2584,
   -2584, -2584,   382,   382, -2584, -2584, -2584, -2584,   422, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,  2769, -2584,   251,
   -2584,   898,  3552, -2584, -2584,   615, -2584, -2584,  1180,   227,
     651, -2584, -2584, -2584, -2584, -2584,  9069,   382, -2584, -2584,
     382,   714,   382,   138, -2584, -2584, -2584,   382, -2584, -2584,
     904,   808,  1189, -2584, -2584,   814, -2584,   847, -2584,   825,
   -2584, -2584,   870, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,   880, -2584, -2584, -2584,   921,   931,   954,
     966,   986,   997,  1011,  1019,  1023,  1035,  1051,  3552,  1065,
    4994,  1071,  1075,  1098,  1128,  1134,  1152,  1727,  1616, -2584,
   -2584, -2584, -2584,   131, -2584,   179, -2584,  3552, -2584,   215,
   -2584, -2584, -2584,    87, -2584, -2584, -2584,  1007, -2584, -2584,
   -2584, -2584, -2584, -2584,   904,  1163,  1197,  1201, -2584,  1189,
   -2584, -2584,  1213, -2584,  1222, -2584,  1141, -2584, -2584,  1227,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
     138,  1235,  1639,  1241, -2584,   138,   138,  1293,   382, -2584,
      12,  1648, -2584,  1000,  1288, -2584,  1015,  1372,  1690,  1739,
     382,  1760,  1772,   332,  1130, -2584,   319,    15,    15,    15,
      15,    15,  4994,  1814,    96,    46,  4994,  1133,  4994, -2584,
    4994,  4994,  4994, -2584, -2584, -2584,  1226,  1323,  1350,  4994,
    1378,  1371, -2584,  4994,  4994,  1375, -2584,  1393, -2584,  1075,
    1400,  1407,  1413,  1424,  1894,  7593, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  1446, -2584, -2584, -2584, -2584,
   -2584, -2584,   319,   319, -2584, -2584, -2584, -2584, -2584,  3552,
   -2584,   382, -2584,   382,  3552,  1340,   182, -2584, -2584, -2584,
   -2584,  1898, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
    1441, -2584,  1441,    12,  1915,  1918,  1920, -2584, -2584, -2584,
    1922,  1927,   227,  1760,  1441,  1930,  1284, -2584,  1842, -2584,
   -2584,  1510, -2584,  1542, -2584, -2584, -2584,  1289, -2584, -2584,
    1937,  1516, -2584,  1480, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584,  1372,  1480, -2584, -2584, -2584, -2584, -2584, -2584,  1481,
     217,   285,   239, -2584,  1377, -2584, -2584, -2584,  1488,  1967,
     394, -2584, -2584, -2584,  1528,  1493,   402, -2584,  -200,  1532,
    1533,   411,   416,  6404,  1534,  1536,   236,   149, -2584, -2584,
      99,  1960,  1541, -2584, -2584, -2584, -2584,   426, -2584, -2584,
    6643, -2584,  5599,  8054,  2155,  2155,  4994, -2584,  1465,  4994,
    7593,  1507, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  1313,
    1974,  6666,  7593,  1465,  1976,   574,  4994,  4994,  4994,  4994,
   -2584,  4994,  4994,  4994,  4994,  4994,  4994,  4994,  4994,  4994,
    4994,  4994,  4994,  4994,  4994,  4994,  4994,  4994, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  4994,  4994,
   -2584, -2584,  1512,  4994, -2584,  4994,  1513, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,   319,  4994,  4994,
    4994,  4994,  1551,  1997,  1727,  1520,  3837,  1522, -2584,  3552,
    1489, -2584,  1334,  1986, -2584,  1341, -2584,  1991,  1569,  1570,
     431,  1705,   455,   463,   405,  1546, -2584,   464, -2584, -2584,
   -2584,   427,   382, -2584,   382,  1610, -2584,  5403,   651,  5930,
    2000,   479,   382,  2011,   583, -2584, -2584,  1288,  2006, -2584,
   -2584, -2584, -2584,  2007, -2584,  2008, -2584,  2012, -2584,   382,
   -2584,   382, -2584, -2584,  1760,  2013, -2584, -2584,  1394, -2584,
   -2584, -2584,   382,    15, -2584,  3552,    52, -2584, -2584, -2584,
   -2584, -2584,  1288,  1288,  2014,  -144,  1288,  1444, -2584,  2022,
    1409,  1517, -2584, -2584,    46, -2584, -2584, -2584,  1601,  7593,
     -48,  1606,  6713,  2030,  1378,  1611, -2584,  1618,  1620, -2584,
    6883,  6948,  7118,  7193,  7771,  7682,  8054,  8075,  8121,  7426,
    8162,  8242,  8445,  8525,  4272,  2155,  2155,   837,   837,   915,
    7593,  7283,  7498,  1465,  7593,  7519,  1465, -2584,  7593,  7593,
    7593,  7593, -2584,  2031, -2584, -2584, -2584,  2054, -2584,  7593,
   -2584,   212,  3552, -2584,  1621,  2051,   583, -2584, -2584,  2048,
   -2584,  1589,  2062, -2584,  2065, -2584, -2584, -2584,  2066, -2584,
   -2584,   -34, -2584, -2584,  1423,  1631,  2096, -2584,  1651, -2584,
   -2584, -2584,   319,   319,   319,   382,  1021,   382,  1730,   268,
     268,  1757,   382,   382,   268,   268,   382, -2584,  1730, -2584,
   -2584,   382, -2584,  1061, -2584, -2584, -2584,   268, -2584, -2584,
   -2584, -2584,   382, -2584, -2584, -2584, -2584,   102,   102,  4994,
   -2584, -2584, -2584,  1757,  1757, -2584, -2584,   268, -2584, -2584,
     268, -2584, -2584,   382, -2584, -2584,   268, -2584, -2584,   319,
     268, -2584, -2584,  4994,   268,   319,   382,   319,   268, -2584,
   -2584,   233,   268,   268,   233,   268,   382,   233,   268, -2584,
     268,   268,   268, -2584,  1730, -2584, -2584,   319,   268, -2584,
   -2584,   268,    83,   382, -2584,  1757, -2584, -2584,   268,  1070,
   -2584, -2584,   319,  1426, -2584,   268, -2584,  3728,   319,  4994,
      15,    15,   268, -2584, -2584,  1021,   319,   253, -2584,  4994,
   -2584,   614,  4994,   268,   134, -2584,  4994,   268,  2080,   319,
   -2584,   268,  4994, -2584,  4994,   102,   382,   268,   382,    15,
     268,   382,    15, -2584,   382,   275, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,   269, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  1166, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,   369,   382, -2584,
     779, -2584,  1659, -2584, -2584, -2584,  1750, -2584, -2584,  1664,
    1665,  1667,  1669, -2584, -2584,  1442,  2118,  1679, -2584,  1680,
   -2584,   516, -2584,  1644, -2584,  1452, -2584, -2584,   278,  1288,
    2108, -2584,  1686,  -111, -2584,  2111, -2584,  1497, -2584, -2584,
   -2584,  1464, -2584, -2584, -2584, -2584,  8739, -2584,  1226,  1698,
   -2584,  1226, -2584,  1226,  1226,  1226,  1226,  1226,  2123,  2125,
    2126,  4994,  1706,  2131,  4994,  1708,  1709,  1711,  1713,  1714,
    1718,  3837,  1722,  3837,  3837, -2584,   335, -2584, -2584, -2584,
    1805,  1729, -2584,  1731,  1733,  1502,  1734, -2584, -2584,   382,
   -2584,   382, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
     440,  1511,   595,  1153,  1699, -2584, -2584, -2584, -2584,  1514,
     665, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  2180,
    1518, -2584, -2584,  1707, -2584,  1757, -2584,  1657,   164, -2584,
   -2584, -2584,  1677, -2584,  7593, -2584, -2584,  1545, -2584, -2584,
    4512, -2584, -2584, -2584,   319, -2584, -2584,  1757, -2584,   -50,
   -2584, -2584,  1872, -2584,   104, -2584,  1682, -2584, -2584, -2584,
   -2584,  2196, -2584, -2584,   713, -2584,  1531, -2584,  1537,  2196,
   -2584,  1564, -2584, -2584, -2584,  1735,   187, -2584,  1691, -2584,
    1503, -2584, -2584, -2584, -2584,  1505,   392, -2584,  -125, -2584,
    1548,  1774,  1700,  1834,  1558, -2584, -2584,  1549, -2584, -2584,
    4994,   196,  1083,  4994, -2584,   125,   268, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584,    73,    73,    73, -2584,
      73,  3453,    73,    73,  1574,   -50,  1574,  1574,  1092,  1092,
    1574,  1574,  1557,   -50,  1562, -2584,  2221, -2584,  1751,   301,
   -2584,  2223, -2584,   -50,   114,    38, -2584, -2584,  4994, -2584,
   -2584, -2584,  1101, -2584,  1135, -2584,   651, -2584,  4994, -2584,
    4994,  1744,  1745,  1753,  1754,  1785,  1758,  1135, -2584,  1843,
     940,   103, -2584,  1613, -2584, -2584,   382, -2584, -2584,  1146,
   -2584,  2240, -2584,  2235,   382, -2584,   270,   118,  1625, -2584,
   -2584,  2250, -2584,  1544,  2250,  2253,  1547,  2250,  2253,  4994,
    2250, -2584, -2584,   164,   319, -2584, -2584,  1784,   413, -2584,
   -2584,  1775,   319,  4994,  1777, -2584, -2584,  2238,  2242,  2143,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  1193,  1193,
     268,   268,   268,  4219, -2584, -2584,  2120,   369, -2584, -2584,
     826, -2584, -2584, -2584,  1761, -2584, -2584, -2584, -2584,  2769,
    1760, -2584, -2584, -2584,  1599,   382,  1288,  2248,   513,  1288,
   -2584,   600,  1288,  1288,  1793,  1637,  1806, -2584,  8798,  8798,
   -2584,  1548, -2584, -2584, -2584, -2584,  1526, -2584,  5274,  1795,
   -2584,  1797,  1798,  1799, -2584,  1799,  1799,  1800,  1801,  1802,
    1804,   382,  -108, -2584, -2584, -2584, -2584,    88, -2584,    51,
    2440, -2584, -2584,  1526, -2584,  1526,  1815, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
    7593,   467, -2584, -2584,   471, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584,  1780, -2584, -2584,   472,
   -2584, -2584, -2584, -2584, -2584, -2584,   138, -2584,   138,  1113,
     194,  2269, -2584, -2584,   987,   225,   989,  2291, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584,   382,  1839,   382, -2584,
   -2584,  1845,   382,  1846,   382,   382,  1757,  1650,  1817, -2584,
    1818,   148, -2584, -2584, -2584,  1757, -2584, -2584,  2295, -2584,
   -2584,  1632,  1829, -2584, -2584, -2584,  1083, -2584,  1208,  1208,
    2263,  1208, -2584,  1135,   233,  4994,  4994,  4994,  1830, -2584,
   -2584,   319,   319,  1757,  1640,  1135,    15,  1603,    83,   319,
   -2584,  1642,  4994,  1912, -2584, -2584,  1717,   382,  1548, -2584,
    3552, -2584, -2584, -2584,   382,  1385,  2325, -2584, -2584,  1661,
     161,   164,   319, -2584, -2584,  2316,  2317, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  1909, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584,  3728,   319,   319, -2584,  1092,  4994,  -134,  1162,  1236,
   -2584, -2584, -2584, -2584, -2584,   188, -2584, -2584, -2584, -2584,
    2128,  1900, -2584,  1902,   651,  4994, -2584,    76, -2584, -2584,
     382,  2330,    15,    15, -2584,  1720, -2584,    46,  1681,   319,
   -2584,   382,   382,   382,  4994,   -91, -2584,  1737, -2584, -2584,
     220, -2584,  1831, -2584,  1838,  4994,  1224, -2584, -2584,  1702,
   -2584,  2371, -2584,  1779, -2584, -2584, -2584,   319, -2584, -2584,
     108, -2584, -2584, -2584,    70, -2584, -2584, -2584, -2584,   382,
      15,    15,   221,   413,  2168,  1279,   319,   164, -2584,  1788,
   -2584, -2584,  2325,  2363,  1935, -2584, -2584, -2584, -2584, -2584,
    2017,  2017, -2584,   238,  1794, -2584, -2584,   382,  1757, -2584,
    1757,  1757, -2584, -2584,  1757,  1757, -2584,   382,  1828,   -48,
    1757, -2584,  1828, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584,   308,   308,   597,  1055, -2584,   851, -2584,   826,
   -2584,   138,  2367, -2584, -2584,  1411,  1949, -2584,   205,  1288,
    2375, -2584,  1288,  1851, -2584, -2584,  1953,  1955,  1852, -2584,
   -2584, -2584,  1608,  1608, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584,  1728,   -48,  1959,  8756,   662,  8739,  1884, -2584,
   -2584, -2584,   662,   662,   662,   662,  1738,  8739,  8739,   261,
    1837,   666,   382, -2584,  8739,  8739,  8739,  8739, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  1741,   -93,  1083,  4994, -2584,
   -2584,  1969,  1977,  2367, -2584, -2584, -2584, -2584, -2584,  1941,
    1942,  1943,   962,  1947,  1956, -2584, -2584, -2584,  2320,   382,
   -2584,  2436, -2584, -2584,   568,  4365, -2584, -2584, -2584, -2584,
     382, -2584, -2584,   568,  1732, -2584,   440, -2584,  1778, -2584,
    1809, -2584,  1998,   251, -2584,  1781, -2584,  1812, -2584,  1856,
    1971,   382, -2584, -2584, -2584, -2584,  4512,   382, -2584,  1807,
   -2584, -2584,  2263,  2263, -2584,  2263,  1790, -2584,  2459,  2465,
   -2584,  2466,  1847,  4994, -2584, -2584,  2467, -2584,  1803, -2584,
    1944,  1808,  2253, -2584, -2584,  1811,  1453,   382, -2584, -2584,
    1992,   268,  1091,  1549,  1727,   362, -2584, -2584, -2584, -2584,
    4994,  1757,  1083,  -208, -2584,   382,   382,  4994,    71,   -50,
    2474,  1420,  2476,  2464,  2468,  3453, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,   319,  2115, -2584, -2584, -2584, -2584,  2369,
    4994,   651, -2584,  2222, -2584, -2584, -2584,  4994,   102, -2584,
    2116,  2494,  2499,   478,   481,   382,  2056,  1135, -2584,  3837,
    2020,  2021,  2023, -2584, -2584,  2092, -2584,  4994,   -89, -2584,
    1862, -2584, -2584,   833, -2584,  4994, -2584, -2584,  1840,   898,
   -2584,  1491,   382,  2506,  8678, -2584, -2584, -2584,   319,  1083,
     319, -2584, -2584,   323, -2584,  2253,  2253,  1810, -2584,  1917,
    1924, -2584, -2584, -2584, -2584, -2584, -2584,    15,    15, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,  2303, -2584, -2584,
   -2584, -2584,    15,  9026,  2517,  2501, -2584,  1135,   911,   299,
     202,  2374,    14,  1021, -2584,   758, -2584, -2584, -2584,  2039,
     354,  1757,   733,  1861, -2584,  1857, -2584, -2584, -2584, -2584,
   -2584,  2052,  2052, -2584, -2584, -2584, -2584,  1939,  1866,  2537,
   -2584, -2584, -2584,   622,  1867,  1869, -2584, -2584,   319,   159,
   -2584, -2584, -2584,  1858,  1055, -2584,   382,   382, -2584, -2584,
     382,   667, -2584, -2584, -2584, -2584,  2069, -2584, -2584, -2584,
     677,  1288, -2584,   709, -2584,  2099,  2103,  1288,  1288, -2584,
   -2584,  1585,  8739, -2584,   487,  2548,  2106,  2551, -2584, -2584,
   -2584,  8739, -2584,   482,  8739,  8739,  8739,  8739,   382,   484,
   -2584,   388,  2554, -2584, -2584,    56,  7987, -2584,  2138,   382,
    1893,   662,  2176, -2584, -2584, -2584, -2584, -2584, -2584,  1585,
    2541,  1585, -2584,  7593, -2584, -2584,  2086, -2584,  2053,  2055,
     122,   122,   122,   490,  2320,   122,  7987,   382, -2584,   497,
     382,   498, -2584, -2584, -2584,  2084,  2088,  2089,  1526,  1526,
   -2584,  2091, -2584,  2093,  2094,  2100,  2101, -2584, -2584, -2584,
   -2584,  1169, -2584, -2584, -2584,   500, -2584, -2584,   502,   382,
   -2584,   382,  1864, -2584,   382,  1865,  4994, -2584,   382,  2567,
   -2584, -2584,   568, -2584, -2584,  1905,   568,   246, -2584, -2584,
   -2584, -2584,  1135,  4994,  4994,  4994,  4577,  2576,  1757,   198,
   -2584,  1135,   382, -2584, -2584,   382,   382, -2584,  1046, -2584,
   -2584,   439, -2584,  1928,  4994, -2584, -2584, -2584,  2574,  3552,
    2074, -2584,  1929,  2592, -2584, -2584,  1135,  1982, -2584, -2584,
   -2584, -2584, -2584,   382,  2253, -2584,   164, -2584,  2016, -2584,
   -2584,   503, -2584, -2584, -2584,   319, -2584,  6318, -2584,  1246,
   -2584, -2584,  2229,  2590, -2584,  2217,  2218,  2110,  1952,  2224,
    2142, -2584, -2584, -2584, -2584,  -105,  2211, -2584, -2584, -2584,
   -2584,  2092, -2584, -2584, -2584,   249,   869, -2584, -2584, -2584,
    2325,  4994,  2150, -2584,  2124, -2584, -2584, -2584, -2584,  2627,
   -2584, -2584, -2584, -2584,  2629, -2584,  1933, -2584,  2626,   -50,
     382,  3066,  3066,  3066,  3066,  3066,  3066, -2584,  2648, -2584,
    2651,  3066,  3066,  3066,  3066,  1909, -2584, -2584,  3066,   154,
   -2584, -2584, -2584, -2584,  2632,  2644, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  2646, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,   512, -2584, -2584, -2584,  2635, -2584, -2584,
    1757, -2584,   -48, -2584, -2584, -2584, -2584, -2584, -2584,  2019,
    2024,    80, -2584,   758, -2584,   122,  1993,   268, -2584,  2183,
   -2584, -2584, -2584,   382,   382,   122, -2584, -2584,   151,  1757,
    1156,  8739,   229, -2584,  4994, -2584,  4994, -2584, -2584, -2584,
   -2584, -2584,  2063,   268,   151,  1757,  2666, -2584,   319,   382,
     941,   941, -2584, -2584,  2667, -2584,  2667,   789,   789,  2667,
   -2584, -2584,  2000, -2584,  1288,  2652, -2584,  1288,  1881,  1288,
    1288, -2584, -2584,  2188, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584,    88,  1526,  2002,  1526, -2584,  1526,  2228,  8739, -2584,
    2233,  2234,  2236,  2241, -2584, -2584,   261, -2584,   261,   382,
   -2584, -2584,  8316,  1799,  5238,  1799,  2681,  2682, -2584, -2584,
   -2584, -2584, -2584, -2584,   191,  8739, -2584,  2190, -2584,  2366,
     184,   299,   382, -2584,  2245, -2584, -2584,  3675,   146, -2584,
    2095, -2584,   146,  1757,   796,  2249,  2692,  2026, -2584, -2584,
     515, -2584,   519,   962, -2584, -2584,   525,   273, -2584, -2584,
   -2584,   568, -2584,  2674,  2674,  2675,  2027,   585,  2685,  2696,
    2697,  2685,  2685, -2584, -2584, -2584,   173, -2584,  1179,   382,
   -2584,   568, -2584, -2584, -2584,  2035, -2584, -2584,  2060, -2584,
   -2584,   685,   534, -2584,   382,   537, -2584,  4994,  2275,  2705,
     550,  1135,  2721, -2584, -2584, -2584, -2584,  4994,  2107,  2397,
    4994, -2584, -2584, -2584, -2584,   439,  1363,  1363,  2729,   136,
   -2584,  2730, -2584, -2584, -2584,  1363,   382,  2136,  1527,  2732,
     382, -2584,  3552,   250,  1757,  2731,  1135,  -139,  2474,  4994,
   -2584, -2584,  3453, -2584,  2025,  4994, -2584, -2584, -2584,  2733,
    3837,   319, -2584,  1061,   382,   319, -2584,  2292,  3837,  3837,
    3837, -2584, -2584,  -105,  2211, -2584,  1909, -2584, -2584,  1229,
   -2584, -2584,  2119, -2584,  3552,  4852,  8678,    93,  1140, -2584,
   -2584, -2584,  2067, -2584, -2584, -2584, -2584, -2584, -2584,    15,
    3066,    15,  3066, -2584, -2584, -2584, -2584, -2584, -2584,   -50,
   -2584,  1280,  1296,  9026, -2584,  2294,  2259,  8739, -2584,   202,
     202, -2584, -2584, -2584, -2584,   561, -2584,  2225, -2584,   122,
    1074, -2584,  2068, -2584,   564, -2584, -2584,  2743, -2584, -2584,
    2149, -2584,  2745,  3110,  3110,  3110,  3110,   122,   122, -2584,
   -2584, -2584, -2584, -2584, -2584,  2743,  2073,   319, -2584,  2667,
   -2584, -2584,   382,   789,   789, -2584, -2584,   789,  2486,  2081,
   -2584,   719, -2584,  2308,  2310, -2584, -2584,  2734,  2312,  2083,
    1585,  2085,  2087, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
     566, -2584, -2584, -2584, -2584,   424,   128, -2584,  7987,  7987,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,  8798,  8798,  2281,
    8798,  2283, -2584,  8798,   925,  8739,  2765, -2584, -2584,  7987,
   -2584, -2584, -2584, -2584, -2584,  2766, -2584,   712, -2584, -2584,
    2366,  2097,  2098, -2584, -2584,   102,   102,   102,  2747,   102,
     102,   102,   102,   102,   102,  2748, -2584,  2749,   102, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,  3675, -2584,   319,
    2109, -2584,  2278,  2757, -2584,  2758,  2761,  2763,  2764,  2767,
    2768,  1230,  2095, -2584,  2278, -2584, -2584,  2770, -2584,  2431,
     122,  1535,   122, -2584, -2584,  2320, -2584, -2584, -2584, -2584,
    2342,  2343,   569,  1585,  2771,  1585, -2584,  2793,   575,  2350,
    2351,  2793, -2584, -2584, -2584, -2584,  1757, -2584, -2584, -2584,
    2315, -2584, -2584,  1179, -2584,  2320, -2584, -2584,   382,   382,
   -2584, -2584,   382,  -305, -2584,   568,   172,  2325, -2584,  2279,
     172,   242,  1135, -2584,  2799,  2321, -2584, -2584,  2357,  2204,
   -2584, -2584,   382,  1363,  3552,  1581,   382,  1363, -2584, -2584,
      15, -2584, -2584,  4994, -2584, -2584,   368, -2584, -2584, -2584,
    1135,  2801, -2584,    15,  2325,   319,  2512, -2584,  2785,  1917,
    7593,  2787, -2584, -2584,   164,  2331, -2584, -2584,  3837, -2584,
   -2584,  2365,  2372, -2584, -2584, -2584,   869, -2584,  1917, -2584,
    4994, -2584,   379, -2584,  2223, -2584, -2584, -2584, -2584,  2322,
    2417, -2584,  2804, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584,   382, -2584,   158, -2584, -2584, -2584,
     122, -2584,   -48,  2625,   576, -2584, -2584, -2584, -2584,   382,
     122, -2584,   151,   151,  2219,  2580,  2580, -2584, -2584,  4545,
    2341, -2584, -2584,  2344,  2346, -2584,  2349,  2352,  2354,  2355,
     382,   -44, -2584, -2584, -2584, -2584,   591, -2584, -2584,  2496,
   -2584, -2584, -2584,   594,  2831,  2831, -2584, -2584,   596,  2832,
    2830, -2584,   360,   319,   151, -2584, -2584, -2584, -2584, -2584,
    2577,  2769,  1288,  1882,  1288,  1288,  2396, -2584,  1585,  2399,
    1585,  1585,   261, -2584, -2584,  2682, -2584,  2353,  2440,  2353,
     210, -2584,  2353,   210, -2584,  2353,  8798, -2584, -2584,  8739,
   -2584,  8739,  2681,   184, -2584, -2584, -2584, -2584,  1585, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584,   755,  2844, -2584,   319,  1715, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584,   396, -2584, -2584, -2584,  2337, -2584, -2584, -2584, -2584,
    2826, -2584, -2584,  2404, -2584,  2828,  2407,  2829, -2584, -2584,
   -2584,  2410, -2584,  2377,  7987, -2584, -2584, -2584, -2584, -2584,
     382,  2835, -2584,  -305, -2584, -2584,  2838, -2584, -2584,  2840,
     382,  2366,   172, -2584,    15,   -50, -2584,  2435,  1135, -2584,
    4994, -2584,  2246,  2843,   -50, -2584, -2584,   888, -2584, -2584,
   -2584, -2584,   207,  2421, -2584, -2584,  1135,  2253,  2629,  2575,
   -2584,   -50,  2423,  2425,  2474,  2389, -2584,  2473,  2428, -2584,
   -2584, -2584, -2584, -2584,  2579,  2370,  4994,  2383, -2584, -2584,
   -2584,  1917, -2584,   598, -2584,   319,  2280, -2584, -2584, -2584,
    8739, -2584, -2584,   122, -2584,  2395, -2584, -2584, -2584,  2743,
    2280,  1892,  1892,  2437,  8756,   662,  8876,   662,   662,   662,
     662,   423,  8876,  3110, -2584,  8876,  8876,  8876,  8876, -2584,
   -2584,   122,  2873,   122,  3110,   268,  7987, -2584,  2629,    91,
   -2584, -2584, -2584, -2584,  2439,  2441, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,   173, -2584, -2584,   603, -2584, -2584, -2584,
   -2584,   604, -2584,  2353,  2882, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584,   319,  2844, -2584, -2584, -2584,   319, -2584,   319,
   -2584, -2584,  2015, -2584,  2594,  2595,  2867, -2584, -2584,  2445,
    2216, -2584, -2584, -2584,  2447, -2584,   122,   444, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  1135,
   -2584,  2451,  9251,  2416, -2584, -2584, -2584,  2230,   -50, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584,  2455,   164, -2584,  2473,
    2473,  2473,   869, -2584,  3552,  2276, -2584, -2584,   382, -2584,
    2629,   666,    88, -2584,  8695,   666, -2584,  2457,  8876, -2584,
     608,  8876,  8876,  8876,  8876,  2881,   382,   611, -2584, -2584,
   -2584, -2584, -2584, -2584,  2422, -2584, -2584, -2584,  2681, -2584,
     382, -2584,  1288,  1288, -2584, -2584, -2584,   155, -2584, -2584,
   -2584,  8739, -2584,  2406,  2406, -2584,  2406, -2584,  2406,  2406,
   -2584, -2584, -2584,  2427, -2584,  1585, -2584,   624, -2584,  1220,
   -2584, -2584,    73,    73,    73,    73,    73,    73, -2584,  2885,
   -2584,   627, -2584,  4994,  1619, -2584,    59,  2473,  3837,  2473,
    2474, -2584, -2584, -2584, -2584,  2613,   399, -2584,   -50, -2584,
   -2584, -2584, -2584,   631, -2584, -2584,  1506, -2584,  2469,  8876,
   -2584,  2470,  2471,  2472,  2475,   400,  2400, -2584,  3110, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584,  2406, -2584,  2406, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  1367, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  9251, -2584,
    2908, -2584, -2584, -2584, -2584,   872, -2584, -2584, -2584, -2584,
   -2584, -2584,   323, -2584,  8695, -2584,  1890, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  2889, -2584,  2890,   637, -2584,
   -2584,  1368,  1368, -2584, -2584,  1368, -2584,  4994,  1029, -2584,
   -2584,  2479,    93, -2584,  2252,  2258,  2917, -2584,  2452,   403,
   -2584, -2584, -2584, -2584,  2488, -2584, -2584, -2584,   382,   382,
    1890, -2584,  2897, -2584, -2584,   244,  2262, -2584, -2584,  2456,
   -2584,   164, -2584,   382, -2584,  2474, -2584
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2584, -2584, -2584, -2584, -2584,   376, -2584,   436,  -169, -2584,
   -2584, -1179,     3, -2584, -2584, -1876, -2584, -2584, -2584, -2584,
    -487, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -1691, -2584,
   -1004, -2584,  1919, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
     702, -2584, -2584, -2584, -2584,  1359, -2584,  1028, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  2257, -2584,   -38, -2584, -2584,
    2914, -2584,  2916, -2584, -2584, -2584, -2584, -2584,   787,   425,
   -2584,   784, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,  -110,   944,   364, -2584, -2584,  2602,    27,
   -2584,  2846, -2584, -2584,  2845, -2584,  2752, -2584, -2584, -2584,
   -2584, -2584,  2614,  2293,  1209,  2610,  -548,   752, -2584, -2584,
   -2584, -2584, -2584,  1210,  -669, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,   843, -2584,  2429,  2756,   289,  2359, -2584,
    -199,  1662, -2584,  2586, -2584, -2584, -2584, -2584,  2593, -2584,
   -2584, -2584, -2584,  -396, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584,  2408, -2584,  2405, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -1255, -2584, -2584,  -433, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,  -124, -2584, -2584,
    1172, -2584, -1140, -1177,   365, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584,  1979, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
    -630, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  2174, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584,  -489, -2584,  -102,
   -2584, -2584, -2584, -2584,  2569, -2584, -2584,  -184, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
    1712, -2584, -2584, -2584, -2584,   974, -2584, -2584, -2584, -2584,
   -2584, -1771, -2584, -2584,   970, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -1119,  -650,   839,  1138, -2584,
    -229,  -583,   527, -1144,  1339, -2584,   935, -2584, -2198,    -3,
    -145, -2584, -2584, -2044,  -207,  1467, -2584, -2584, -2584,   866,
    1383, -2584, -2584, -2584, -2584, -2584, -2584,   419, -2584,   109,
   -2584,  1390, -2584,  1066, -2584,   748, -2584, -2584, -2584, -2584,
    -457, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
     848, -2584, -2584, -1589, -2584,  1050, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,  1550, -2584, -2584, -2584, -2584, -2584, -2584,
     -92, -2584, -2584, -1813, -2584, -2584, -2584, -2584,   492, -1982,
   -2584, -1152, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  2997, -2584,
   -2584, -2584,  2925,  2977,   644, -2584, -2584,  -224, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  2980, -2584,
   -2584,  3002, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  2102,
   -2584, -2584, -2584, -2584, -2584,  1108, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584,  -700,  2256, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  2288, -2584, -2584,   -46, -2584,
   -2584,  1107, -2584, -2584,  1443,  -192,  2703, -2584, -2584, -2584,
   -2584,  -182, -2584, -1067,  2001,  1414, -1474,  1495, -2584,  1111,
    1791,     7,  -176, -2584,  2247,  1586, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584,  1509, -2584, -2584, -2584,
    -787, -2584,  -493, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
    -384, -2584, -2584, -2584, -2584, -2584, -2584,   468, -2584,  -619,
     470,   658, -2584, -2584, -2584, -2584, -2584,   282, -2584,  -175,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  1496, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  -536, -2584,  1161,  2599, -2584,
   -2584,   288, -2584,  -658, -2584, -2584,   310,   616, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584,  1380, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584,   240, -2584,   -23,   -18, -2584, -2584,   -10, -2584, -2432,
   -2584,   252,   920, -1376, -2584, -2584, -2584,  1282, -2584, -1743,
   -2584, -2584, -2584, -1732, -2584, -2584, -1720, -2584, -2584, -2584,
   -2584, -2066, -2584,  1305,   975, -2584, -2584, -2584, -2584, -2584,
     757, -2584, -2584, -2584, -2584, -2584, -2584,  -351, -2584, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584,    84, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,
   -2584, -2584, -2584,  1436, -2584,  1437, -2584,   750,  1099, -2584,
   -2295,   170, -2584, -2584, -2584, -2584, -2584, -2584,   327, -2584,
   -2584,  -138, -2584,  -725, -1374, -2584, -2584, -2584, -2584, -2584,
     294, -2584, -2584, -2584, -2584, -2584, -1783, -2584, -2584, -2584,
   -2584, -2584, -2584, -2122,  1039, -2584, -2360,  1121, -2584, -2584,
   -2054,   414,   421,   701, -2584, -1820, -1687, -2584, -2584,   121,
    -201, -2584, -2584, -2584, -2584, -1667, -2584, -2584, -2584,   326,
   -2584,   657,  -599, -2584,  -549,  -133,  1485,    85, -1886,   686,
     722,   337, -2584, -2584, -2584, -2584,  2514, -1261, -2062,  3134,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  -344, -2584,
   -1373, -2584,  1868, -2584, -2584,   618,   711, -2584, -2179,   715,
     219,   524, -1051, -1635, -2020,  1417,   145,  -768, -1217, -2584,
    1421, -2584, -2584, -2584,  1519,  -686, -2584, -2584,  -129,  1883,
   -2584,   770, -2584, -2584,   820,   237, -2584, -2584, -2584, -1825,
      21,  -221, -2584,   254, -2584, -2584, -2584, -2584,  1553, -2584,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2399,
      -7, -2584, -2583, -1975, -1475,  -984, -2584, -2584,    16, -2584,
   -2584, -2584,   621, -1107,  1422,  -762,  2045,  1710,  1716,    86,
   -2584, -2584,   649,  1006,   132, -2584, -2584, -2584, -2584,  1736,
   -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584, -2584,  -327,
    1346,  2640, -2584, -2584, -2584, -2584
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1974
static const short yytable[] =
{
      40,    42,    43,    45,  1027,   336,    45,    50,   582,   277,
     191,  1431,  1493,  1490,  1547,    94,   109,  1381,  1871,  1521,
    1384,  1555,   701,   244,  2011,  1778,  1014,  2443,  1199,  2445,
    1794,   990,  2401,  2180,  1949,  1950,   966,  1145,  2465,   419,
     420,  2678,    39,   593,    66,  1489,   438,  2578,  1500,  1501,
    2137,  1502,  2467,  1523,  1524,   390,   305,   108,  2136,    66,
      94,  2963,  2964,  2965,  2112,  2064,  2065,  2066,  2067,  2655,
     115,   436,   972,    39,  1115,    79,   191,   122,    39,    39,
    1083,  1897,   129,    39,    86,   131,   421,   422,  2052,   134,
     135,  2609,  1755,  1738,  1756,   191,  2932,  2314,    39,  1494,
      39,  1712,  1713,  1611,   118,  1078,   341,    39,    66,  1622,
      39,   283,   342,   343,   977,   427,  1090,   981,   609,   593,
     428,   429,   430,  1632,   239,   610,   283,   241,  1079,   243,
     369,  1207,  2532,  1491,   247,   374,   375,  2700,  1645,  1582,
    2701,  2702,  2703,  2704,  2705,  2706,    79,  1059,   423,    39,
     204,  1611,   440,  1627,   442,  1447,   443,   444,   445,   593,
     524,    39,  1061,  1738,  2368,   450,  1860,   331,   427,   461,
     462,  1150,  2330,   428,  1153,   430,  1814,  1239,    39,   283,
    1321,  1322,    39,  1198,   334,   106,  1623,   334,   283,  1251,
    1252,    39,  1462,  1546,  1087,  1088,   339,   283,  2802,  1322,
    2700,  1462,  2334,  2701,  2702,  2703,  2704,  2705,  2706,  1059,
    2724,    39,   593,  2897,  2458,  2461,  2461,   334,  2522,  2461,
       1,    39,   575,  1059,     2,    39,  1860,   191,  1349,    39,
     106,  2040,   191,     3,   283,  1321,  1322,    39,  3086,   283,
     337,   338,    39,  1920,   579,   377,  1137,  3097,  2967,  1448,
    1449,  1450,    39,  1548,  1549,   604,  2376,   406,  1108,  2379,
      39,   367,   605,    66,   418,   418,   418,   418,   418,  1883,
    2857,  1203,   418,    39,  2577,  1059,    39,    39,  1203,  2698,
      39,  1261,  1729,  2523,  1730,  1731,  1059,  1864,    39,  1865,
     577,  1866,  3319, -1972,  2689,    39,  2691,  1307,  3017,   283,
    1251,  1252,    39,  2607,  1308,   979,  1543,  1914,  2862,  2240,
    1604,  1605,  1155, -1972,   595,  3087,  3088,  1941,  1612,    66,
      66,    62,   619,     4,  1203,   622,    39,   693,   525,  1937,
     527,  2642,  2643,  2644,  2645,  2646,  2647,   671,  1313,  1819,
     334,  2759,   630,   631,   632,   633,    39,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   970,  2180,  1612,  2189,   957,   993,
    2695,  3080,   698,  2189,   651,   652,  1889,    51,  1737,   654,
     952,   655,  1057,  1057,   334,   438,  1652,  1057,  1057,    79,
    1145,    89,  1260,  2090,   658,   659,   660,   661,  2104,   585,
    1057,  3236,   669,  1141,   334,  3455,  1480,   593,  3492,    39,
     119,  1960,    62,  1059,  2441,    39,   593,  1794,  1627,    39,
    1057,   593,  2196,  1057,  1870,  3081,   971,   191,    51,  1057,
    2698,   614,     5,  1057,  1980,  1981,   679,  1057,   587,   588,
     589,  1057,  3172, -1972,  2536,  1057,  1057,    52,  1057,  2626,
    2698,  1057,     1,  1057,  1057,  1057,     2, -1972,  1141,  2635,
     682,  1057,  2197,     7,  1057,  3500,  2264,   693,   684,   688,
    1480,  1057,  1758,   596,  3089,  1472,  1758,  1764,  1057,  1261,
    1026,    62,   994,   593,     5,  1057,   593,  2408,  1054,  2408,
    1310,  1606,  2402,   191,    62,  2463,  1057,    62,   378,   980,
    1057,    62,  2110,  2471,  1057,  2489,    56,  2491,  2552,   359,
    1057,  1938,  1921,  1057,    66,  1884,  1131,  2613,  1561,  1261,
    2782,   853,   946,    62,  2782,   379,  1428, -1972,  1530,  1531,
    2782,  1578,  1314,    85,   324,   325,   326,   327,   328,  2822,
      86,  1584,  2825,  1917,  1965,    86,  1473,    62,  1442,   694,
    2624,   694,  1399,  1400,  2728,  2825,    32,  2707,  2708,   694,
    1724,    33,  2337,  1133,  1055,  1058,  2920,    62,  3185,  2930,
     191,  2992,  1264,  2863,  3060,   589,   406,  2053,   406,   580,
    3067,  3153,  1401,  1402,  1403,  1070,  2091,    87,    88,   969,
     418,   995,  2537,   974,  2885,    39,  3173,  2916,  2659,  3173,
    1261,  3181,  1091,  3288,     6,  1091,  1659,  1326,  3327,  3327,
    1054,   418,  2709,  3389,  2205,  1100,  3389,   332,  2989,  1091,
    2707,  2708,  1628,  1091,    39,  1326,  1194,  1195,  1495,  2780,
    1117,     8,  3428,    60,  2203,  1091,  3444,  1100,  3159,    77,
      62,    39,  3173,  1129,   111,   112,  1100,  3501,  1628,    39,
    2844,  1124,     7,  1139,  2041,  1245,   167,  2858,  1248,  3255,
    1154,   335,  1326,  2331,   530,  3012,   576,  1197,  1263,  2636,
    1562,  3121,  1262,  1607,  3098,  2709,  1054,  1613,  1129,  3189,
    1779,  1496,  1129,     8,  1145,   606,  1129,  2617,  1739,  2898,
    3132,   938,  1100,  1544,  1025,  1100,   286,  1037,  1132,    66,
      66,    66,  1046,    66,  1050,  1052,   333,  1550,  1060,  1062,
    1063,  1790,     9,  1068,  2760,  1052,  1263,  1253,  1071,  3057,
      66,  1742,  2787,  2212,  1766,  1613,  2419,  1309,  1659,  1063,
    1982,  3062,  1492,  3064,   578,   415,  1723,  2912,  2710,  1204,
    1060,  1060,   611,  2925,  1545,   686,  1583,  1898,  2817,  3076,
    1063,  2788,  1694,  1553,  1827,  2195,    66,  2816,  2268,  2369,
     304,  3320,    66,  1063,    66,  3145,   415,  1826,    66,   431,
    1264,    66,   973,  1118,    66,   304,  2506,  1226,  1211,  1841,
    2506,  1052,  3313,  1451,    66,  2250,  3291,  2453,  1644,   418,
    1135,   415,  1060,  2403,  1551,  1497,  1142,  1463,  3105,    66,
    3295,  2710,  3110,   415,  2711,    66,  1488,   418,   418,  2845,
    1264,  3103,    66,    66,    66,  3458,  1254,  1385,  1220, -1972,
    1701,  1227,   431,  1704,  1705,  2322,    66,  1212,   304,  1057,
    2071,  1824,  1867,  1240,  1469,  1240,   418,   304,  1240,   418,
    1868,  1240,    66,   586,  2190,    62,   304,    89,  3090,  2453,
    3114,   594,    89,  2268,  2712,  2713,  1920,  2476,  2477,   486,
     599,  3135,    62,  2453,  1213,   600,  2648,  2711,  1608,  2361,
    3202,  1769,  1109,  2994,  2416,   615,  2511,  1810,  3237,   607,
     680,  3441,  3456,   304,  1770,  3493,  1815,  1370,   304,   487,
    1370,  1264, -1972,  3348,  3053,  1881,  3056,   669,  1269,   669,
     669,  1609,   988,  1693,   683,  2231,   324,   325,   326,   327,
     328,  1714,   685,   689,  1839,  2453,  1759,  2712,  2713, -1972,
    1760,  1765,    10,   161,   117,    39,  3199,  2225,  3200,  3201,
    2226,  2409,  3381,  2415,  2076,  3006,  2839,  3305,    39,  2464,
    3186,   107,    90,  3287,    13,  1289,  2469,  2472,   304,  2490,
    1404,  2492,  2553,  1057,  1057,  1057,  3217,  2055,  2623,  2062,
    1214,  2614,  1699,  1925,  2783,  2340,    13,   487,  2784,  2062,
    1349,  1265,  1266,  1267,  2786,   411,  2085,  2086,  2087,  2088,
      32,    33,  1268,  2823,   366,  1771,  2826,   488,   489,   490,
     491,   492,   493,  1342,  1906,  1302,  1715,   412,  1304,  2830,
   -1972, -1972, -1972, -1972, -1972,   494,   495,   496,   111,   112,
    2921,  1197,  1716,  2931,    39,  2993,    39,   110,  3061,   288,
    3247,  2999,  2353,  3002,  3068,  3154,  3005,   119,  1895,   174,
    1054,  2354,   954,    91,  3149,  1405,  1395,  1215,   694,  2018,
    3174,   175,   291,  3180,  3157,  3182,  1047,  3289,    39,  1702,
    2380,  1650,  3328,  3329,  1717,  2355,  2079,  3390,  2356,  1388,
    3397,  2341,  1284,  1285,   955,   488,   489,   490,   491,   492,
     493,  2794,  1060,  3413,  2357,    66,  3429,  1216,  1406,  2058,
    3445,   627,   121,   494,   495,   496,  3480,  1072,    39,  2785,
    2591,    66,   123,  1718,  1060,  1140,  3306,    39,  1773,  1988,
    1145,  1989,  1990,   535,  1085,  1992,  1993,  1697,  1478,   541,
      39,  2012,  3380,    92,  1774,  1794,  3386,    61,    61,    39,
      39,    93,  1719,     1,   297,  1921,  2384,  2728,  1101,   197,
    3292,  1720,  3318,    66,  3179,  1642,  1154,  1197,  1142,  2548,
     127,  2679,  1217,  2681,   497,  2682,    62,   498,    44,  1142,
      39,   324,   325,   326,   327,   328,  1700,   948,  2387,    62,
    1203, -1972,    39,    66,    66,    66,  2261,    66,  2982,    66,
      66,  1589, -1972,    39,  1192,    66,    66,  2358,  1527,  3205,
     949,   181,  3210,  2153,  1209,  3212,  1537,  1224,  1885,    39,
    2075,  1230,  2059,  2628,   198,   536,  2332,  1236,  3308,  1238,
     242,    66,  2026,  2159,  2160,   182,  2161,   546,   114,  3316,
    2042,  3469,  1576,  2044,    66,    39,   300,  2320,  1638,  2654,
      39,  2230,   497,  1588,  1960,   498,    66,   201,   301,   302,
    2359,  1596,  3007,  1820,  2080,    39,   303,  2360,  1417,  1133,
    2221,  1821,  1821,  1703,  1821,  2081,  2917,  2918,     1,   183,
      66,    66,     2,  2247,  2887,  3047,    39,    39,   184,    66,
    1418,     3,  1887,    39,  2795,  1769,   499,  3293,  2173,    62,
    2174,  1012,  2556,    39,  1015,    66,    66,  2820,  1770,  1658,
     249,   500,  1842,  3412,  1349,   501,  1767,  3150,  1768, -1972,
    1769,  2319,  1769,  2407,   251,  2533,  2410,  2411,  2412,  2413,
     258,  2060,  1696,  1770,  3014,  1770,  2908,    39,  1423,    62,
    2777,  1854,  2192,  1419,  1420,  1342,  1342,  1662,  1141,  3213,
    2385,   502,  2910,    39, -1972,  1342,  2821,  1951,  1952,  1953,
    1424,  1141,  1954,   259,  1955,  1956,  3179,  3179,  1736,   261,
      62,    62,   185,   186,   499,  2027,  1743,  3219,   438,   503,
    1225,     4,  2388,  3015,  1231,  2218,   262,  1965,  1235,   500,
    2458,   265,  2983,   501,  2028,  2029,   504,  2827, -1972,  3008,
    3267,  3009,  2694,  2175,  2697,  1803,  2176,  2462,   191,  1771,
    2466, -1972,   581,    62,  2030,  1455,  2026,     5,  1903,  1904,
    1077,  3118,  1456,  3330,    62,  2804,  3220,  1780,  1960,   502,
    2867,  1785,  1791,  1785,  1771,  1858,  1771,   266,  2894,  2864,
      62,  1095,    39,  1797,  1799,  1800,  1769,   267,    66,  1804,
    1806,  1807,  1808,  1060,  1104,  1543,  1580,   503,  2206,  1770,
    2907,  2037,  1060,  2483,  2484,  2485,  1945,  1946,    39,  1423,
     268,    62,  2339,  1142,   504,    66,    66,   505,    66,  3085,
      66,    66,   269,   111,   112,  1439,    62,   948,    66,    66,
    1060,  1424,    66,   418,  3163,   418,    66, -1972,   982, -1659,
     983,  2512,   270,  1784,  1142,  1793,  2513,    62,    62,  1291,
     949,  1857,  1142,   271,    62,  2524, -1972, -1972,    66,    66,
    2998,  2998,  1773,  2998,    62,  2805,  2998,   272,  3298,  3188,
    3301,  3302,  3303,  3304, -1972,   273, -1972,     6,  1774,   274,
    2545,  2253,     5,   506, -1972,  1581,  3414,  1773,    39,  1773,
    1093,   275,  2075,  2507,  1057,   505, -1972, -1972,    62,  2027,
    1771,  1965,  2806,  1774,  1102,  1774,  3420,   276,  1107,    66,
      66,   986,    66,   987,    62,    66,    66,  2851,  2028,  2029,
    1121,   278,  2386,  3433,    39,  3054,  2872,   318,  2391,  2392,
    1278,   319,    39,  1192,  2880,  2881,  2882,  1901,  2030,   418,
     418,  1279,  1960,  1563,   418,  1569,    66,  2549,  1910,  1911,
    1912,  2034,   441,  1349,   320, -1972,     8, -1972,  3371,  3372,
    3373,   506,  2953,  2953,  2953,  2953,  2807,  1534,  1535,  1772,
    2922,  3108,  1538,  1539,    66,  3420,  1957,  2926,    39,  1958,
    2808,  1959, -1972,  -296,   321,     9,  1240,   418,   418,  1839,
     322,  1280,  3433,    66,    66,  2486,  3415,  2585,  1746,  1747,
    3416,  1960,     6, -1972,  2093,  1281, -1972, -1972,   323,  3431,
    2684,  1961,   330,  1773,  1984,  1060,    39,  1060,  1060,   354,
    1999,  1060,  1060,  1057,  1994,   363,  2696,  1060,  3001,  1774,
    3004,  2000,  1962,  3463, -1972,   371,   340,  2718,  1528,  1529,
     345,  3290,  1532,  1533,   381,  2173,  3437,  2174,  3439,   382,
       7,    66,  2001,   355,  2204,  1963,  1057,   356,  2002,  1964,
   -1972,  3299,  2038, -1972,   391,   138,  2003,  3299,  -296,   360,
    3309,  3310,  3311,  3312,  1244,  1965,  2185,  1247,   361,  2809,
    1250,     8,   383,   365,  -296, -1972,   400,  1123,  2004,  1960,
   -1972,   370,  1342,  1282,  1342,  2810,  1130,   372,  2277,  2279,
     346,   347,   348,   139,  1342,  1342,  1060,  1929,   112,  2084,
       9,  1342,  1342,  1342,  1342,   324,   325,   326,   327,   328,
    2021,  2022,   140,   141,  1142,  1051,  -296,    39,  1748,  1749,
    1750,  1751,  1752,  1753,  1965,   401,  2217,  1556,  1557,  1558,
    1559,  2616,  1243,  3415, -1972,  1246,  1780,  3416, -1972,   376,
    2175,  1785,  1059,  2176,    39,   669,   407,  1791,  2289,  2998,
    1785,  1388,   142,  2186,  2187,  -296,   392,   384,   410,  1478,
    2640,    39,   451,   413,   143,  1960,   446,  3124,  2151,   448,
    1574,  2057,    39,   385,  2155,   144,  2656,  1706,  2261,  1707,
    1828,  1829,  1830,  3388,  -296,  2831,  3391,  3392,  3393,  3394,
    1709,   145,  1710,  -296,  3224,  1154,   449,  1848,   424,   425,
     426,   146,  1265,  1266,  2183,  1432,  1433,  1434, -1972,  1349,
    3446,  3447,  1965, -1972,   529,   386,   147,   460,  1060,  1142,
    2861,   463,  2199,  2200,  1798,   418,    39,  2075,  1197,  2075,
    1801,  1805,    39,    39,  3126,  2045,  2049,  2046,  2050,   464,
      66,   393,  2800,  2801,  2953,  2953,   466,   452,  2953,  2495,
    2498,    39,    39,   467,   387,  2670,   148,   394,  2672,   468,
    2675,  2676,  2228,   453,    66,  2673,  3194,  2674,  3195,  3225,
     469,  1882,  3177,  3178,  3450,  3474,  3258,    39,   149,  1823,
     470,  1825,   517,   388,   531,  3266,    66,   533,  2254,  1596,
    1563,  1342,   389,   150,  1503,    66,  1142,    66,  1965,   395,
     151,   538,  3272,   152,   539,   454,   540,  3010,   542,  1913,
    1714,  3161,  3162,   543,   418,   418,   547,   548,   549,   553,
    1928, -1972,   563,   564,   153,   565,   568,   573,   154,   418,
     583,  3226,   584,  3227,    66,    66,    66,   591,   396,   592,
      66,   597,   598,   602,   455,   603,   612,   155,  1060,  3228,
     613,   620,   624,   623,   625,  2192,   628,  3229,   653,   656,
     662,  3230,   663,   672,  1057,   156,   664,   397,   670,  2393,
    1057,   673,   674,   456,   675,    66,   398,   676,   677,   678,
    1854,   681,   457,  2375,  2375,  2263,  3231,  2375,   687,   699,
       1,   953,   958,   960,   961,  1715,  1057,   968,   962,   967,
     978,  3317,  1748,  1749,  1750,  1751,  1752,  1753,   984,  1342,
     992,  1716,   985,  1996,  1067,   997,   999,  1020,  1342,  1023,
    1001,  1342,  1342,  1342,  1342,  2414,  1076,  1002,  1060,  1003,
    1028,  1029,  2420,  1342,  1031,  1032,  2438,  3020,  3021,  3022,
    1040,  3024,  3025,  3026,  3027,  3028,  3029,   191,  1033,  3365,
    3032,  1034,  1036,  1717,  2394,  1096,  1039,  2454,  2454,  2454,
    1042,  1041,  2454,  1342,  2468,  1152,  1232,  1780,  1293,  1294,
    2395,  1113,  1114,  1295,  1296,  2953,  1297,  1120,  1298,  1299,
    1122,  2953,  2953,  1300,  2953,  2953,  2953,  2953,  1301,  1303,
    1305,  1306,  1718,  2953,  1311,  1312,  2493,  1315,  2494,  2496,
    1316,  2497,  2499,  1317,  1504,  2501,  3099,  1360,  1367,  1785,
    1368,  1369,  2396,  1785,    66,  1372,  1373,  1375,  1376,    66,
    1377,  1719,  1378,  1379,  1386,  1060,  2454,  1380,    66,  2183,
    1720,  1382,  2529,  2529,  3115,   484,   485,   486,  1387,  1393,
    1391,  1439,  1392,  1394,  1416,  1421,  1154,  1422,  1425,  1427,
    1429,  2397,  1197,    66,  1435,  1446,  1426,  1453,  2167,  3443,
    2547,  1454,  1457,    66,  1080,  1080,  1465,   487,  1458,  3225,
    3370,  1461,    66,  1460,  1480,  1466,    66,  1468,  1197,  1482,
    2398,  1477,  1485,  1484,  1525,  2191,  1541,  1542,  1546,  2399,
    1570,  1571,  1830,  3421,  3422,  3423,  3424,  3425,  3426,  1572,
    1573,  3214,    66,  2718,  1577,  1584,  1579,  2953,  1593,  1595,
    2953,  2953,  2953,  2953,  1618,  1619,  1620,  3073,   593,  1621,
    1626,  1630,  1563,  1633,  1634,  1997,  1636,  2592,  1635,  1684,
    1505,  3226,  1695,  3227,  1698,  1692,  1506,  1507,  1508,  1998,
    1708,  1725,  2239,  1726,  1727,  1728,  1732,  1733,  1734,  3228,
    1735,  1757,  1057,  1057,  1763,  1783,  1796,  3229,  1509,  1811,
    1816,  3230,  1080,  1812,  1813,   488,   489,   490,   491,   492,
     493,  1817,  1255,  2763,  1447,  1818,  1833,  1060,  1553,  1840,
    1847,  1849,  1999,   494,   495,   496,  3231,  1851,  2764,  2765,
    1860,  1862,  2454,  2000,  1873,    71,  1874,  2766,  2953,  1890,
    2631,  1994,  2454,  1893,   946,  1984,  1060,  2953,  1342,  1892,
    3218,  1951,  1952,  1953,  2001,  1902,  1954,  1907,  1955,  1956,
    2002,  1984,  1060,  1905,  3438,    66,  2375,  1924,  2003,  1917,
    2903,  2767,  2905,  1854,  1926,  1931,  1932,  1628,  1359,  1934,
    2768,  1361,  1349,  1362,  1363,  1364,  1365,  1366,  1972,  1974,
    2004,  1975,  2892,  2035,  1983,  1875,  2055,  1977,  2039,   162,
     194,  2043,  2047,  1510,  2048,  1342,  1511,  2051,  2053,  2769,
    1723,  2068,  3260,  1060,  1512,  1060,  2420,  2076,  2094,  1342,
    2089,  1342,  2954,  2954,  2954,  2954,  2095,  2100,  2101,  2102,
    3270,  2870,  1342,  2105,  3505,  2107,   669,  2454,    66,  2438,
     191,  2110,  2106,  2075,   669,   669,   669,  2143,  1513,  2139,
    2454,  2141,  2142,  2770,  2144,  2145,  2146,  2148,  1744,  1745,
    1746,  1747,   497,  1343,  2163,   498,   194,  2005,  1785,  2162,
    2164,  2165,  2168,  2006,  1154,  1154,  2169,  2157,  2184,  1627,
    2166,  2170,   191,  1514,  2207,   194,  1791,  2171,  1785,  2172,
    2209,  2214,  2216,  3193,  2210,  3196,  3197,  2771,  2219,  2223,
   -1972,  2151,  1515,  1516,  2224,  2229,  2232,  2233,    66,  2234,
    2237,  2500,  2243,  1517,  3175,  3176,  3177,  3178,  1518,  2251,
    2257,  2268,  2317,  1268,  2270,  2335,  3385,  2318,  2514,  2515,
    1830,  2518,  2329,  2183,  2343,  2852,  2344,  2854,  2345,  2348,
    2454,  1060,  2350,    66,  2349,  1255,  2364,  2365,  2389,  2539,
    2372,  2383,  2390,  2404,   414,  2405,  2406,  1519,    66,  2418,
      66,  2876,    66,  3403,  2435,  2440,  2442,  2444,  2446,  2447,
    2473,  2450,  2504,  3350,  2474,  2475,    66,  2478,  2509,  2479,
    2480,  2520,  2540,  1342,   499,  3192,  2481,  2482,  2542,  1520,
    1748,  1749,  1750,  1751,  1752,  1753,   418,  2544,   418,   500,
   -1972,  2538,  2543,   501,   283,  1321,  1322,    39,    66,    66,
     522,   523,  2546,  2558,  1342,  2559,  2582,   194,  1323,  1324,
    2561,  2562,   194,  2550,  2563,  2564,  2454,  2565,  2566, -1972,
    1957,  2583,  2586,  1958,  1543,  1959,  1690,  1267,  2584,   502,
    2951,  2951,  2951,  2951,  2454,  2454,  1748,  1749,  1750,  1751,
    1752,  1753,  2590,  2599,    66,  1960,  2601,  2610,  2611,  2976,
    2612,  2615, -1972,  2627, -1972,  1961,  3112,   503,  2619,  2629,
    2652,  2657,  2662,  2620,  2677,  3107,  3385,  2683,  2671,  3117,
   -1972,  2680,  2685,  2686,   504,  2687,  2286,  2698, -1972,  2699,
    2688,  2722, -1972,  2719,  2731,  1342,  1342,  2780,  2779,  2781,
    2789,  2792,  2937, -1972,  1342,  1342,  2793,  1342,  2818,  1963,
    1342,  2796,  1342,  1964,  2954,  2954,  1342, -1972,  2954,  2650,
    1255,  2651,  2798,  2799,  2828,  2829,  2832,  2834,  2835,  2962,
    2962,  2962,  2962,  2819,  2842,  2846,  2850,  2853,  2871,  2860,
    2902,  2879,   191,  2913,  2890,  2914,  2868,  2929,  2932,  2933,
    1738,  2922,  2974,  3249,   669, -1972,    66,  2984,  2981,  2985,
    2986,  2987,  2988,  3249,  2990,   505,  2991,  3000,    66,  3003,
    3011,  3013,  3023,  3030,  3031,  3019,  3018,  2454,  3055,  2454,
    3038,  3037,  3040,  3041,  2806,  1343,  1343,  3042,  1965,  3043,
    3044,  3058,  3059,  3045,  3046,  1343,  3051,  3063,  3065,  3069,
    3070,  3074,  3094,  1060,  3100,   657,  3102,  3101,  3103,  3116,
   -1972,  3120,  3122,  3125,  3129,  3077,  3078,   194,  3138,  2501,
    1262,  3130,  1785,  2803,  3141,  3151,  3145,  3164,  1141,    66,
    3165,   506,  3166,  3400,  3401,  3167,  3173,  3183,  3168,  2529,
    3169,  3170,  3109,  2529,  3184,  3198,  3190,   418, -1840,  3222,
    3203,  2777,  3239,  3240,  3241,  3244,  3243,    66,  1057,  3245,
     418,  3250,    66,  3246,  3252,  3257,  3253,  3259,  3263,  3265,
    3269,    66,  3273,  3271,  3274,  3275,  3277,  3279, -1972, -1972,
    1739,  3294,  2833,   194,  3284,  2838,  3296,  3314,  3322,  3331,
    3323,  3341,  3342,  3343,  3344,  3345,  3346,  2955,  2955,  2955,
    2955,  3351,  3363,  3364,  3369,  3377,  3387,  3395,  3398,  3411,
    3427,  3142,  3440,  3467,  3457,  3478,  3479,  2454,  3449,  3451,
    3452,  3453,  3490,  3499,  3454,  3488,  2631,  2454,  3486,  1984,
    1984,  3489,  2951,  2951,  3491,  3503,  2951,  3494,  3504,  2875,
    2824,  3466,  1383,  2575,  1916,  2954,  2242,  3171,  1038,    57,
    1192,  2954,  2954,    58,  2954,  2954,  2954,  2954,  1255,  2525,
     194,  2849,  2534,  2954,   544,   200,   353,   537,   205,  1030,
      66,  1984,  2096,   545,  2097,   358,   991,   690,   572,  1711,
    2952,  2952,  2952,  2952,   570,  3464,   964,   963,  2154,  1060,
    1043,  1044,  1045,  1374,  1048,  1219,   608,  1142,  2373,  1688,
    1142,  2381,  1944,  1342,  2516,  2201,  1342,  2901,  1342,  3140,
    2454,  1074,  1948,  2267,  2589,  3487,  2521,  2287,  1844,    54,
    3268,  2962,  2962,   136,    68,  2962,  2668,    69,  2016,  2017,
      55,  2249,  1326,  1119,    66,  2033,  2252,   528,  1880,  1930,
    1197,  1971,  1397,  2256,  3223,  1624,  3332,  1098,  1835,  1151,
    1878,  3470,  1292,  1103,  2896,  1105,  3050,  3340,  2220,  1112,
    3049,  1896,  1112,  2938,   629,  1112,  2939,  3033,  2775,  3256,
    3096,  1342,  3254,  3251,  3079,  1125,  2510,  2954,  2140,  2940,
    2954,  2954,  2954,  2954,  2109,  2470,  3209,   138,  2621,  3209,
    1125,   418,  3376,  3473,  1255,    66,  1188,  3216,  2014,  2015,
    2641,  2347,  3158,  1048,  1201,  1205,  3052,  3075,  3347,  1221,
    2417,  2338,  2995,    66, -1972, -1972, -1972,  1233,  2942, -1972,
    2996, -1972, -1972,  2693,  3211,   139,  3402,  3071,  2935,  2936,
    2943,  2791,  1987,  1257,   283,  1321,  1322,    39,  1000,  2776,
    3238,  2692,    66,    49,   140,   141,  3498,  1342,  1323,  1324,
    2454,  1676,  2729,  3160,  2928,  2070,  3215,  2730,  2069,  3379,
    1979,  1342,  1641,  2951,  2633,  2859,  3156,  1942,  2954,  2951,
    2951,  2944,  2951,  2951,  2951,  2951,  3315,  2954,  2454,  2092,
    2454,  2951,   191,  1342,   142,  3297,  1479,  1853,  3307,  2955,
    2955,  2856,  1343,  2955,  1343,  2541,   143,   700,     0,     0,
       0,  1859,     0,  1843,  1343,  1343,     0,   144,     0,     0,
    2945,  1343,  1343,  1343,  1343,     0,     0,     0,  3113,    66,
       0,     0,  2946,   145,    66,     0,    66,     0,     0,     0,
       0,     0,  2937,   146,  2947,  2948,     0,     0,     0,     0,
       0,     0,  2949,  2454,   669,  2950,  2222,     0,   147,     0,
    2057,     0,  2962,   304,     0,  3133,    66,     0,  2962,  2962,
       0,  2962,  2962,  2962,  2962,     0,     0,     0,     0,     0,
    2962,     0,  2952,  2952,    66,     0,  2952,     0,     0,     0,
       0,     0,     0,     0,     0,  3142,     0,     0,   148,  2265,
       0,  1342,     0,     0,     0,  2951,     0,     0,  2951,  2951,
    2951,  2951,     0,  3396,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,     0,     0,     0,  3399,     0,     0,
       0,     0,     0,     0,  1142,   150,     0,     0,  1342,     0,
       0,     0,   151,     0,     0,   152,     0,  3208,     0,     0,
    3208,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      66,    66,    66,    66,    66,     0,   153,     0,  1141,     0,
     154,  3432,     0,     0,     0,  1080,  1257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,  1440,     0,  2962,     0,  2951,  2962,  2962,  2962,
    2962,     0,     0, -1972,     0,  2951, -1972,   156, -1972,     0,
       0,  1343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3209,     0,     0,     0,     0, -1972,     0,
    2955,     0,     0,     0,  1471,     0,  2955,  2955, -1972,  2955,
    2955,  2955,  2955,     0,     0,     0,     0,     0,  2955,     0,
       0,  1342,     0,  3475,     0,     0,     0,     0,     0, -1972,
       0,     0,     0,     0,  1499,  1499,  1499,     0,  1499,     0,
    1499,  1499,     0,     0,     0,  3261,    71,    71,     0,     0,
       0,     0, -1972,     0,     0,  2962, -1972,     0,  1503,     0,
       0,     0,     0,     0,  2962,  3496,  3497,  3475,     0,     0,
       0,     0,  1205,     0,     0,     0,     0,     0,    66,     0,
    3506,  3285,     0,  2952,     0,  1205,     0,     0,     0,  2952,
    2952,     0,  2952,  2952,  2952,  2952,     0,  1591,     0,  1343,
       0,  2952,     0,     0,     0,     0,     0,     0,  1343,     0,
       0,  1343,  1343,  1343,  1343,     0,     0,     0,     0,     0,
    3325,  1257,  1440,  1343,     0,     0,     0,     0,     0,     0,
    1631, -1972,  2955,     0,     0,  2955,  2955,  2955,  2955,     0,
       0,     0,  1326,     0,     0,     0,  1639,  1639,     0,     0,
     164,   165,     0,  1343,     0,     0,     0,     0,   166,    39,
       0,  2571,  2572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2581,  2938,   167,     0,  2939,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2940,
       0,     0,     0,     0,     0,     0,     0,  2593,  2594,  2595,
    2596,  2597,  2598,     0,     0,     0,     0,  2603,  2604,  2605,
    2606,     0,     0,     0,  2608,  2952,     0,     0,  2952,  2952,
    2952,  2952,     0,  2955,     0,     0,     0,  2941,  2942,     0,
       0,     0,  2955,     0,     0,     0,     0,     0,     0,     0,
    2943,     0,     0,     0,  3208,     0,     0,     0,     0,   168,
       0,     0,     0,  1255,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,     0,     0,     0,  1504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2944,     0,     0,     0,     0,     0,     0,     0,   170,
       0,     0,     0,     0,     0,     0,  2660,  2661,     0,     0,
       0,     0,     0,  2665,  2666,     0,  2952,     0,  3430,     0,
       0,     0,     0,     0,     0,  2952,    71,    71,     0,    71,
    2945,  1205,  1112,     0,     0,     0,     0,     0,     0,  1834,
    1125,     0,  2946,  1205,     0,     0,     0,  1845,     0,     0,
       0,     0,     0,     0,  2947,  2948,     0,     0,   194,     0,
       0,     0,  2949,     0,     0,  2950,     0,     0,     0,  1257,
    1188,     0,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1157,  1158,  1159,  1160,     0,
      62,     0,   171,     0,     0,     0,  2733,  2734,     0,  2735,
    2736,  2737,     0,     0,  1505,     0,     0,     0,  1343,     0,
    1506,  1507,  1508,     0,     0,     0,     0,     0,     0,     0,
    1879,  1188,  3484,    71,     0,     0,  1886,  1888,     0,     0,
       0,     0,  1509,     0,     0,     0,   280,     0,     0,     0,
       0,     0,     0,     0,     0,   281,   282,     0,     0,     0,
       0,   283,   284,   285,    39,     0,     0,  1908,     0,     0,
       0,     0,  2840,  2841,     0,  1343,     0,     0,     0,   167,
       0,  2848,     0,     0,     0,     0,     0,     0,     0,  1343,
       0,  1343,     0,     0,     0,  1936,     0,     0,   172,     0,
       0,     0,  1343,     0,     0,     0,     0,     0,     0,  2738,
       0,     0,     0,     0,  1970,  1257,     0,  2739,  1161,  2883,
    2884,     0,     0,     0,     0,     0,  1162,     0,     0,     0,
       0,     0,     0,   173,     0,  1163,     0,     0,  1164,     0,
       0,     0,     0,     0,     0,     0,  2904,  1510,  2906,     0,
    1511,  2740,     0,  1343,   168,     0,     0,     0,  1512,   286,
    2741,     0,     0,     0,     0,     0,   169,   174,     0,     0,
       0,     0,  2020,     0,     0,     0,     0,     0,     0,   175,
       0,  1165,     0,     0,     0,     0,     0,     0,  1166,  2742,
    2743,     0,  1513,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2977,
    2978,     0,     0,  2979,  2980,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1514,     0,     0,
     177,     0,     0,  2744,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,  1167,  1515,  1516,     0,     0,
       0,   179,     0,  1343,     0,     0,     0,  1517,     0,     0,
       0,     0,  1518,     0,     0,     0,     0,     0,     0,  1168,
       0,     0,     0,     0,     0,     0,  1169,  2745,  1170,     0,
       0,     0,     0,     0,  1343,    62,     0,   171,  1171,     0,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,  1519,     0,     0,     0,     0,     0,     0,     0,     0,
    1343,  1343,  1343,  1343,     0,     0,  1172,     0,     0,   181,
       0,     0,     0,     0,  1173,     0,     0,     0,     0,     0,
       0,  2746,     0,  1520,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1174,     0,     0,     0,  1343,  1343,     0,     0,     0,
       0,  2213,     0,     0,  1343,  1343,     0,  1343,     0,     0,
    1343,     0,  1343,   172,     0,  1175,  1343,   183,   287,  3106,
       0,     0,     0,  3111,     0,  1205,   184,     0,     0,     0,
       0,     0,  1080,  1080,  1080,     0,  1080,  1080,  1080,  1080,
    1080,  1080,  3119,     0,     0,  1080,     0,   162,   173,     0,
       0,     0,  1176,     0,     0,     0,  2262,     0,  1188,     0,
       0,     0,  3131,  1177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,     0,     0,     0,  1646,     0,     0,     0,
       0,     0,     0,     0,   175,  1205,  2321,  1205,     0,     0,
       0,  1048,     0,     0,     0,     0,     0,     0,     0,     0,
     185,   186,   288,     0,     0,     0,     0,   289,     0,   290,
     482,   483,   484,   485,   486,     0,     0,     0,     0,     0,
     176,     0,     0,     0,     0,   291,  2367,     0,     0,     0,
       0,     0,     0,     0,     0,   177,     0,     0,     0,     0,
     292,     0,     0,   293,   487,     0,   294,     0,     0,     0,
    1178,  1179,  1180,     0,     0,   295,   179,     0,     0,     0,
       0,  1255,     0,  1181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2747,  2748,  2749,  2750,
    2751,  2752,  2753,  2754,  2755,  2756,     0,     0,     0,     0,
       0,     0,     0,     0,   665,   296,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,     0,   297,  1182,     0,
       0,     0,     0,     0,     0,     0,  1647,     0,   298,     0,
       0,     0,  1343,  1343,   181,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,   489,   490,   491,   492,   493,   299,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,   495,   496,     0,     0,  1205,  1183,     0,     0,     0,
    1205,     0,     0,     0,     0,     0,     0,     0,     0,  1205,
       0,     0,  1184,     0,     0,     0,     0,  1343,     0,     0,
    1343,     0,   183,  1343,     0,     0,  1343,   194,  1343,   300,
    3283,   184,     0,  3286,  1205,     0,  2113,     0,     0,     0,
       0,   301,   302,     0,  1257,     0,     0,     0,  1648,   303,
       0,     0,     0,  2554,     0,     0,  1649,  2557,     0,     0,
     304,     0,  1650,     0,  1651,     0,     0,     0,     0,     0,
       0,   280,     0,     0,     0,  1652,     0,     0,     0,     0,
     281,   282,     0,  2580,     0,     0,   283,   284,   285,    39,
       0,  1343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1653,     0,   167,     0,     0,     0,     0,     0,
       0,     0,     0,  2935,  2936,   185,   186,     0,  1654,   283,
    1321,  1322,    39,  1655,     0,     0,     0,     0,     0,   497,
       0,     0,   498,  1323,  1324,  1656,   280,     0,     0,     0,
       0,     0,  1657,     0,     0,   281,   282,     0,     0,     0,
       0,   283,   284,   285,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1343,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,  3374,   168,
       0,  1343,     0,  1343,   286,     0,     0,     0,     0,  1343,
    1343,   169,  1343,  1343,  1343,  1343,     0,     0,     0,     0,
       0,  1343,     0,  1343,     0,     0,  2658,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2937,     0,   170,
    1343,     0,     0,     0,     0,     0,     0,     0,     0,  3404,
    3405,     0,  3407,     0,  3409,  3410,     0,     0,     0,     0,
       0,     0,     0,     0,   168,     0,     0,     0,     0,   286,
       0,   499,     0,     0,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
     501,  2114,     0,     0,     0,     0,     0,     0,     0,  1205,
       0,     0,     0,     0,   170,     0,     0,     0,     0,     0,
    1658,  2115,  2116,  2117,  1255,  1659,     0,     0,     0,     0,
       0,  1660,  3459,     0,  3460,     0,   502,     0,     0,     0,
      62,  1343,   171,     0,     0,  1343,     0,     0,  1343,  1343,
    1343,  1343,     0,  1661,     0,     0,     0,     0,  1662,     0,
    2118,     0,     0,     0,   503,     0,     0,     0,  3472,     0,
       0,     0,  2119,  1141,  1343,     0,     0,     0,  1343,  1205,
       0,   504,     0,  2120,     0,     0,     0,  3481,  3482,     0,
       0,  3483,     0,     0,  3485,     0,     0,     0,     0,  2121,
       0,     0,     0,     0,     0,    62,     0,   171,     0,  2122,
     194,     0,     0,     0,  1205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2123,     0,     0,     0,     0,  2873,
       0,  1074,     0,  2877,     0,     0,  1343,     0,   172,     0,
       0,   280,     0,   287,     0,  1343,     0,  2889,     0,     0,
     281,   282,   194,     0,     0,     0,   283,   284,   285,    39,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2124,   173,   167,     0,     0,     0,     0,  2909,
    2911,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2125,     0,   172,     0,     0,     0,   174,   287,     0,
       0,  2126,     0,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,  2975,     0,     0,   506,     0,
       0,     0,  2127,     0,     0,     0,  2128,   288,   173,     0,
       0,     0,   289,     0,   290,     0,     0,     0,  1255,   168,
       0,     0,     0,     0,   286,   176,     0,     0,     0,     0,
     291,   169,     0,     0,  2129,     0,     0,     0,     0,     0,
     177,     0,   174,  2130,     0,   292,     0,  1326,   293,     0,
       0,   294,     0,   280,   175,     0,     0,     0,     0,   170,
     295,   179,   281,   282,     0,     0,     0,     0,   283,   284,
     285,    39,   288,     0,     0,     0,     0,   289,  2938,   290,
       0,  2939,     0,     0,     0,     0,   167,     0,     0,     0,
     176,     0,     0,     0,  2940,   291,     0,  3034,     0,  1436,
     296,     0,     0,     0,   180,   177,     0,     0,     0,  3048,
     292,     0,   297,   293,     0,     0,   294,     0,     0,     0,
       0,  1723,     0,   298,     0,   295,   179,     0,     0,   181,
       0,     0,     0,  2942,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2943,     0,     0,     0,     0,
      62,     0,   171,   299,     0,     0,     0,     0,     0,     0,
       0,   168,     0,     0,     0,   296,   286,     0,     0,   180,
    1205,     0,     0,   169,     0,     0,     0,   297,     0,     0,
       0,     0,   194,     0,     0,     0,  2944,     0,   298,     0,
    2517,     0,     0,     0,   181,     0,     0,   183,  1205,     0,
       0,   170,     0,  1188,   300,     0,   184,     0,     0,     0,
       0,     0,  1257,     0,     0,     0,   301,   302,   299,     0,
       0,     0,     0,     0,   303,  2945,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,     0,  2946,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,  2947,
    2948,     0,     0,   287,     0,     0,     0,  2949,     0,     0,
    2950,     0,   183,     0,     0,     0,     0,     0,   304,   300,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   301,   302,   173,     0,     0,     0,     0,     0,   303,
     185,   186,    62,     0,   171,     0,     0,  2422,     0,     0,
     304,     0,     0,     0,     0,     0,  1318,  1319,  1320,     0,
       0,  1188,   283,  1321,  1322,    39,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,  1323,  1324,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1318,  1319,  1320,     0,     0,   288,   283,  1321,
    1322,    39,   289,     0,   290,   185,   186,     0,     0,     0,
       0,     0,  1323,  1324,     0,   176,     0,     0,     0,     0,
     291,     0,     0,     0,     0,  3034,     0,     0,     0,     0,
     177,     0,     0,     0,     0,   292,     0,     0,   293,     0,
     172,   294,     0,     0,     0,   287,     0,     0,     0,     0,
     295,   179,     0,     0,     0,     0,     0,     0,     0,     0,
    1325,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1205,     0,     0,  2893,
     296,     0,     0,     0,   180,     0,  1325,     0,     0,     0,
       0,     0,   297,     0,  1205,     0,     0,     0,     0,   174,
       0,     0,     0,   298,     0,     0,     0,     0,     0,   181,
       0,   175,     0,     0,     0,     0, -1973,     0,     0,     0,
       0,     0,     0,  1188,     0,     0,     0,     0,     0,   288,
       0,     0,     0,   299,   289,     0,   290,     0,     0,     0,
       0, -1973, -1973, -1973,     0,     0, -1973,   176, -1973, -1973,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,     0,     0,     0,     0,   292,     0,     0,
     293,     0,     0,   294,     0,     0,  1141,   183,     0,     0,
       0,     0,   295,   179,   300,     0,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   301,   302,     0,     0,
    3034,     0,     0,     0,   303,  3335,     0,  3337,     0,     0,
       0,     0,  1141, -1973,     0,   304,     0,     0,     0,     0,
       0,     0,   296,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,  1205,     0,     0,
       0,     0, -1973,     0,     0,   298,     0,     0,     0,     0,
       0,   181,     0,     0,     0,  1257,     0,     0,     0,     0,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
     185,   186,     0,     0,     0,   299,     0,     0,     0,  2423,
       0,     0,     0,     0,     0,     0,     0, -1973,     0,     0,
       0,     0,     0,     0,   617,   471,   472,   473,     0,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,     0, -1973,     0, -1973,     0,   183,
       0,     0,     0,     0,     0,     0,   300,     0,   184,     0,
    1499,  1499,  1499,  1499,  1499,  1499,     0,     0,   301,   302,
       0,   487, -1973,     0,     0,     0,   303,     0,     0, -1973,
       0, -1973,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0, -1973,     0,     0,     0,     0, -1973,     0,     0,
       0,     0,     0,     0,     0, -1973,     0,     0,     0, -1973,
    1326,     0,     0,     0,     0, -1973,     0,     0,     0, -1973,
   -1973, -1973, -1973,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -1973,     0,     0,     0,     0,     0,
       0,  1327,   185,   186,  2424,     0,  1326,     0,     0,     0,
   -1973,     0,     0, -1973,     0, -1973,  2425,  1329,     0,     0,
       0,     0, -1973,     0,     0,     0,     0,     0,     0,   488,
     489,   490,   491,   492,   493, -1973,     0,  1327,     0,     0,
    1328,     0,     0,     0,  1723, -1973,     0,   494,   495,   496,
       0,     0,     0,  1329,     0,     0,  1330,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1973, -1973,  1331,  1257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1723, -1973,     0,     0,     0,     0,     0,     0,     0, -1973,
       0,     0,  1330, -1973,     0,     0,     0,     0,     0,     0,
       0, -1973, -1973, -1973,  1331,     0,     0,     0,     0,  1332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1333,     0,     0,  1332,     0,     0,  1334,     0,
       0,     0,     0,     0,     0,     0,     0,  1335,  1336,     0,
    1337,     0,     0,     0,     0,     0,     0,     0, -1973,     0,
       0,     0,  1338,  1339,     0,     0,     0,     0,  1333, -1973,
    1340,     0,     0,  1341,  1334,     0,   497,     0,     0,   498,
       0,   304,     0,  1335,  1336,     0,  1337,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1338,  1339,
       0,     0,     0,     0,     0,     0,  1340,     0, -1973,  1341,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   702,   703,   704,     0,     0,
       0,     0,     0,     0,   705,     0,     0,   706,     0,     0,
       0,     0,     0,     0,   707,   708,     0,     0,     0, -1973,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0, -1973,     0,     0,     0,   709,
     710,     0,     0,   500,   711,     0,     0,   501,     0,     0,
       0,     0,     0,     0,   712,   713,     0,   714,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   715,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1973,     0,   502,     0,     0,     0,     0,     0,   716,
       0,     0,   717,   718,     0, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973,     0, -1973, -1973,     0,   719,     0,   720,   721,
     722,   503,     0,     0,     0,     0,     0,     0,   723,   724,
   -1973,   725,   726,   727,     0,     0,     0,     0,   504,   728,
       0,     0,   729,     0,   730,   731,   732,     0,     0,     0,
       0,     0,   733,     0,   734,   735,     0,   736,     0,   737,
     738,     0,     0,   739,     0,     0,   740,   741,   742,   743,
     744,   745,     0,     0,     0,   746,   747,   748,     0,   749,
       0,     0,     0,   750,     0,   751,   752,     0,     0,     0,
       0,   753,     0,     0,   754,     0,     0,   755,     0,   756,
       0,   757,     0,   758,     0,     0,     0,   759,   760,     0,
     761,   762,   763,     0,     0,   764,     0,   765,   766,   505,
     767,     0,     0,     0,     0,     0,     0,     0,   768,   769,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   770,     0,     0,   771,   772,     0,     0,   773,   774,
       0,     0,   775,   776,     0,     0,     0,     0,     0,     0,
     777,   778,   779,     0,   780,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   781,   782,   783,     0,   784,     0,
       0,     0,   785,   786,     0,   506,     0,   787,     0,     0,
       0,     0,     0,     0,     0,   788,     0,     0,     0,     0,
       0,     0,     0,   789,   790,   791,     0,     0,     0,     0,
       0,   792,   793,     0,     0,     0,     0,     0,     0,   794,
       0,     0,   795,     0,     0,     0,   796,   797,     0,     0,
       0,     0,     0,  2555,   471,   472,   473,   798,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,     0,     0,     0,   799,     0,     0,     0,     0,     0,
       0,     0,   800,     0,     0,     0,     0,     0,   801,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   802,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   803,     0,     0,     0,     0,     0,   804,     0,   805,
     806,     0,     0,     0,     0,     0,     0,   807,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,   472,   473,     0,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   808,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   809,     0,     0,
       0,     0,     0,     0,   810,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,   489,
     490,   491,   492,   493,     0,     0,     0,   811,   812,     0,
       0,     0,   813,     0,     0,     0,   494,   495,   496,     0,
       0,     0,     0,     0,   814,     0,     0,     0,     0,     0,
     815,   816,   817,   818,     0,     0,     0,   819,     0,     0,
       0,   820,     0,     0,     0,     0,     0,     0,   821,   822,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   823,
       0,   824,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   825,     0,   826,     0,     0,   827,     0,     0,
       0,     0,     0,   828,   488,   489,   490,   491,   492,   493,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   494,   495,   496,     0,     0,     0,     0,   829,
       0,     0,   830,     0,     0,     0,     0,   831,     0,     0,
     832,   833,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   834,     0,     0,     0,     0,
       0,     0,   835,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   498,     0,
       0,     0,     0,     0,     0,   836,   837,   838,   839,   840,
     841,   842,     0,     0,   843,     0,   844,     0,   845,   471,
     472,   473,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,   471,   472,   473,     0,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   497,     0,     0,   498,     0,     0,     0,   487,   471,
     472,   473,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,     0,     0,   487,   501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,   502,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,     0,   499,   494,   495,   496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,   500,     0,
       0,     0,   501,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,     0,     0,   502,   471,
     472,   473,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,   504,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,     0,     0,   498,   471,   472,   473,     0,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,     0,     0,   497,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,     0,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
     497,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,   500,     0,     0,
       0,   501,   616,     0,     0,   499,     0,     0,   488,   489,
     490,   491,   492,   493,     0,     0,     0,     0,     0,     0,
     500,     0,     0,     0,   501,   626,   494,   495,   496,     0,
       0,     0,     0,     0,   471,   472,   473,   502,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,     0,   499,     0,     0,     0,     0,     0,     0,     0,
     502,     0,     0,     0,     0,   503,     0,   500,     0,     0,
       0,   501,   998,     0,     0,     0,     0,     0,     0,     0,
     487,     0,   504,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,     0,     0,   498,     0,   504,     0,   502,     0,   471,
     472,   473,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,   505,     0,   497,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,   489,
     490,   491,   492,   493,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,   495,   496,   471,
     472,   473,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,     0,     0,     0,   506,
       0,     0,     0,   505,     0,     0,     0,   500,     0,     0,
       0,   501,  1004,     0,     0,   487,     0,     0,     0,     0,
       0,     0,   506,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,     0,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,   500,     0,     0,   503,   501,  1005,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   498,     0,
       0,     0,   502,   488,   489,   490,   491,   492,   493,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     0,
       0,   494,   495,   496,     0,     0,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
     497,     0,     0,   498,   471,   472,   473,     0,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,     0,     0,     0,     0,   471,   472,   473,     0,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,     0,     0,     0,   499,     0,     0,
     487,     0,     0,     0,     0,     0,     0,     0,   505,   506,
       0,     0,   500,     0,     0,     0,   501,  1006,     0,     0,
       0,   487,     0,     0,     0,     0,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
     497,     0,     0,   498,   494,   495,   496,     0,     0,   471,
     472,   473,   502,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,   499,     0,   506,     0,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,   500,     0,     0,
       0,   501,  1007,     0,     0,   487,     0,   504,   488,   489,
     490,   491,   492,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,   495,   496,   488,
     489,   490,   491,   492,   493,     0,     0,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   494,   495,   496,
     473,     0,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   503,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,     0,   500,   505,     0,
       0,   501,     0,   497,   487,     0,   498,     0,     0,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,     0,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   472,   473,
    1009,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   506,   503,     0,     0,     0,     0,
       0,     0,     0,   505,     0,   497,     0,     0,   498,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,   497,     0,     0,   498,
       0,     0,   488,   489,   490,   491,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,   495,   496,     0,     0,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
     500,     0,     0,     0,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
     497,     0,     0,   498,     0,     0,     0,     0,     0,     0,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   488,   489,   490,   491,   492,   493,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,   494,
     495,   496,   500,     0,     0,     0,   501,     0,   499,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,   506,
       0,     0,     0,   500,     0,     0,     0,   501,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   502,     0,     0,     0,     0,     0,     0,   497,
       0,     0,   498,     0,     0,  1010,  2422,     0,     0,     0,
       0,     0,     0,   502,     0,  1318,  1319,  1320,     0,     0,
     503,   283,  1321,  1322,    39,     0,  1013,     0,     0,     0,
       0,     0,   499,     0,     0,  1323,  1324,   504,     0,     0,
       0,   503,     0,     0,     0,     0,   505,   500,     0,     0,
       0,   501,     0,     0,     0,     0,     0,     0,   504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   502,   497,     0,
       0,   498,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,     0,     0,
       0,     0,   506,     0,     0,   503,   487,     0,   505,  1325,
       0,   499,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,   500,   487,     0,   505,
     501,     0,     0,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,   487,   506,     0,   478,   479,   480,   481,
     482,   483,   484,   485,   486,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,   506,     0,     0,     0,     0,
     499,     0,     0,   505,   488,   489,   490,   491,   492,   493,
       0,   504,     0,     0,   487,   500,     0,     0,     0,   501,
       0,     0,   494,   495,   496,   488,   489,   490,   491,   492,
     493,     0,     0,     0,     0,  1141,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   496,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   502,     0,   479,   480,   481,
     482,   483,   484,   485,   486,     0,     0,     0,     0,   506,
       0,   488,   489,   490,   491,   492,   493,     0,     0,     0,
       0,     0,     0,   503,     0,     0,     0,     0,     0,   494,
     495,   496,   505,     0,   487,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,   489,   490,   491,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,   495,   496,     0,  1318,  1319,  1320,     0,  2423,     0,
     283,  1321,  1322,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1323,  1324,     0,     0,   506,     0,
       0,   497,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,   497,     0,     0,   498,     0,     0,     0,     0,
       0,     0,   488,   489,   490,   491,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,   495,   496,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
       0,   498,     0,     0,     0,     0,     0,     0,  1325,  1326,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,   481,   482,   483,   484,   485,   486,     0,   497,
    1327,     0,   498,  2424,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   499,     0,  2425,  1329,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,   500,     0,
       0,     0,   501,     0,   499,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,     0,     0,   501,     0,  1330,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1331,   502,     0,
       0,     0,   481,   482,   483,   484,   485,   486,     0,   497,
     499,     0,   498,     0,     0,     0,     0,     0,     0,   502,
       0,     0,     0,     0,  1141,   500,   503,     0,     0,   501,
       0,     0,  1008,     0,     0,     0,     0,   487,  1332,     0,
       0,     0,     0,   504,     0,     0,     0,   503,     0,     0,
       0,   499,     0,     0,     0,   488,   489,   490,   491,   492,
     493,     0,     0,     0,   504,   502,   500,     0,     0,     0,
     501,  1333,     0,   494,   495,   496,     0,  1334,     0,     0,
       0,     0,     0,     0,     0,     0,  1335,  1336,     0,  1337,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,  1338,  1339,     0,     0,     0,   502,     0,     0,  1340,
     504,     0,  1341,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,   505,     0,     0,  2423,     0,     0,
       0,   499,     0,     0,   503,   488,   489,   490,   491,   492,
     493,     0,     0,     0,     0,   505,   500,     0,     0,     0,
     501,   504,     0,   494,   495,   496,  1318,  1319,  1320,     0,
       0,     0,   283,  1321,  1322,    39,     0,     0,     0,     0,
       0,     0,     0,  1318,  1319,  1320,  1323,  1324,     0,   283,
    1321,  1322,    39,     0,     0,     0,   502,     0,     0,     0,
     506,   505,     0,  1323,  1324,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,   497,     0,   503,   498,     0,  1318,  1319,  1320,
       0,     0,     0,   283,  1321,  1322,    39,     0,  1326,     0,
       0,   504,   505,     0,  1318,  1319,  1320,  1323,  1324,     0,
     283,  1321,  1322,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1323,  1324,     0,   506,     0,  1327,
    1325,     0,  2424,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2425,  1329,     0,  1325,  1320,     0,
       0,     0,   283,  1321,  1322,    39,     0,     0,     0,     0,
       0,     0,   497,     0,     0,   498,  1323,  1324,   506,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,  1330,     0,     0,     0,     0,     0,
       0,  1325,     0,     0,     0,     0,  1331,     0,     0,     0,
       0,     0,     0,     0,   499,     0,     0,     0,  1325,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,     0,     0,   501,  2935,  2936,     0,     0,     0,     0,
     283,  1321,  1322,    39,     0,     0,     0,  1332,     0,     0,
       0,     0,     0,     0,  1323,  1324,     0,     0,   506,     0,
    1325,     0,     0,     0,     0,     0,  1141,     0,     0,   502,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1333,     0,     0,  1141,     0,     0,  1334,     0,     0,     0,
       0,     0,     0,     0,   499,  1335,  1336,   503,  1337,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
    1338,  1339,     0,   501,   504,     0,     0,     0,  1340,     0,
       0,  1341,     0,     0,     0,     0,     0,  1141,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,  2937,     0,
       0,     0,     0,     0,  1141,     0,     0,     0,     0,   502,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,     0,     0,  1141,     0,     0,     0,
       0,     0,     0,     0,   504,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2290,  2291,  2292,  2293,  2294,  2295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,  1141,     0,     0,     0,     0,     0,
    1326,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1326,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1327,     0,     0,  1328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1329,  1327,     0,
       0,  1328,  2296,     0,     0,     0,     0,     0,     0,     0,
     208,  1326,     0,     0,  1329,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,   209,   210,  2054,     0,
       0,     0,     0,     0,     0,  2258,  1330,   211,     0,     0,
       0,     0,  1327,     0,     0,  1328,     0,     0,  1331,     0,
       0,     0,  3382,  1330,     0,     0,     0,     0,  1329,  1327,
       0,     0,  1328,     0,     0,  1331,     0,     0,     0,     0,
    1326,     0,     0,     0,     0,  1329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1332,
       0,     0,     0,     0,     0,     0,     0,  1330,     0,     0,
       0,  1327,     0,     0,  1328,     0,  1332,     0,     0,  1331,
       0,     0,     0,     0,  1330,     0,     0,  1329,     0,     0,
       0,     0,  1333,     0,     0,     0,  1331,     0,  1334,  2290,
    2291,  2292,  2293,  2294,  2295,     0,     0,  1335,  1336,  1333,
    1337,     0,     0,     0,     0,  1334,     0,     0,  1326,     0,
    1332,     0,  1338,  1339,  1335,  1336,  1330,  1337,     0,     0,
    1340,     0,     0,  1341,     0,     0,     0,  1332,  1331,  1338,
    1339,   304,     0,     0,     0,     0,     0,  1340,     0,  2938,
    1341,     0,  2939,  1333,     0,     0,     0,     0,   304,  1334,
       0,     0,     0,     0,     0,  2940,     0,     0,  1335,  1336,
    1333,  1337,     0,     0,     0,     0,  1334,   212,     0,  1332,
       0,     0,     0,  1338,  1339,  1335,  1336,     0,  1337,     0,
       0,  1340,     0,     0,  1341,     0,     0,  2296,     0,     0,
    1338,  1339,   304,     0,  2942,     0,     0,  2297,  1340,     0,
       0,  1341,  1333,     0,     0,   213,  2943,     0,  1334,   304,
    2298,     0,     0,     0,     0,     0,     0,  1335,  1336,     0,
    1337,     0,     0,     0,   214,   215,   216,   217,     0,     0,
       0,     0,  1338,  1339,     0,     0,     0,     0,     0,     0,
    1340,     0,   218,  1341,     0,     0,     0,  2944,     0,     0,
       0,   304,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,  2299,     0,     0,     0,   220,     0,  2300,     0,
       0,     0,     0,     0,     0,     0,  2945,   221,     0,     0,
       0,  3352,     0,     0,     0,     0,     0,     0,  2946,     0,
       0,     0,     0,   222,     0,     0,     0,     0,     0,     0,
    2947,  2948,     0,   223,     0,     0,     0,  2301,  2949,     0,
       0,  2950,     0,     0,     0,     0,     0,     0,   224,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2302,     0,     0,     0,     0,     0,     0,     0,  3353,     0,
    2303,  2304,     0,     0,     0,     0,  2305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2306,     0,   225,     0,
       0,     0,  3354,     0,     0,     0,     0,     0,     0,     0,
       0,  3355,     0,     0,     0,     0,     0,     0,  2307,     0,
     226,  2308,  2309,     0,     0,     0,  2310,     0,     0,     0,
       0,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,     0,   228,     0,     0,   229,     0,     0,     0,  3356,
       0,     0,  2297,     0,     0,     0,     0,  3357,     0,     0,
       0,     0,     0,     0,     0,  2298,   230,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2311,     0,     0,     0,     0,     0,   232,
       0,     0,     0,     0,  2312,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2299,     0,     0,
       0,     0,     0,  2300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3358,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2302,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2303,  2304,     0,     0,     0,
       0,  2305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2307,     0,     0,  2308,  2309,     0,     0,
       0,  2310,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2311,     0,
       0,     0,     0,     0,     0,     0,     0,  3359,     0,  2312
};

static const short yycheck[] =
{
       3,     4,     5,     6,   673,   197,     9,    10,   404,   178,
     112,  1078,  1156,  1153,  1193,    53,    62,  1021,  1492,  1171,
    1024,  1198,   558,   133,  1659,  1399,   656,  2089,   815,  2091,
    1406,   614,  2052,  1846,  1623,  1624,   584,   799,  2104,   268,
     269,  2401,    27,     5,    47,  1152,   275,  2245,  1167,  1168,
    1793,  1170,  2106,  1172,  1173,   254,   180,    60,  1790,    62,
      98,  2644,  2645,  2646,  1784,  1732,  1733,  1734,  1735,  2364,
      73,    25,    20,    27,   774,    48,   178,    80,    27,    27,
     738,     5,    85,    27,   118,    88,   270,   271,  1723,    92,
      93,  2289,  1353,     5,  1355,   197,     5,  1973,    27,    26,
      27,  1318,  1319,    33,    77,   735,    19,    27,   111,  1249,
      27,    24,    25,    26,   603,    19,   746,   606,    19,     5,
      24,    25,    26,  1263,   127,    26,    24,   130,    26,   132,
     240,   817,  2176,     8,   137,   245,   246,     9,  1282,    36,
      12,    13,    14,    15,    16,    17,   119,    25,   272,    27,
     123,    33,   276,     5,   278,    51,   280,   281,   282,     5,
     329,    27,   711,     5,     5,   289,     5,    36,    19,   293,
     294,   801,   158,    24,   804,    26,  1431,   835,    27,    24,
      25,    26,    27,   813,     5,    53,  1253,     5,    24,    25,
      26,    27,     5,     5,   743,   744,   199,    24,    25,    26,
       9,     5,  1985,    12,    13,    14,    15,    16,    17,    25,
      26,    27,     5,   120,  2100,  2101,  2102,     5,    20,  2105,
      30,    27,     5,    25,    34,    27,     5,   329,   996,    27,
      98,    26,   334,    43,    24,    25,    26,    27,    66,    24,
      25,    26,    27,    23,     5,   248,   795,     5,  2647,   145,
     146,   147,    27,   139,   140,    19,  2027,   260,    25,  2030,
      27,   234,    26,   266,   267,   268,   269,   270,   271,   403,
      20,    25,   275,    27,    25,    25,    27,    27,    25,     6,
      27,   331,  1333,  2169,  1335,  1336,    25,   126,    27,   128,
       5,   130,   201,   398,  2416,    27,  2418,    19,  2730,    24,
      25,    26,    27,  2285,    26,   449,     5,   398,   447,   398,
      40,    41,   805,   418,   514,   143,   144,   247,   248,   322,
     323,   248,   446,   133,    25,   449,    27,   551,   331,   221,
     333,  2351,   103,   104,   105,   106,   107,   529,   449,  1446,
       5,   195,   466,   467,   468,   469,    27,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   593,  2178,   248,     5,   567,   417,
    2424,   676,   554,     5,   498,   499,  1555,    13,   486,   503,
     562,   505,   709,   710,     5,   614,   306,   714,   715,   362,
    1152,   425,   123,   486,   518,   519,   520,   521,  1772,     5,
     727,     5,   526,   248,     5,     5,   514,     5,     5,    27,
       5,   352,   248,    25,  2081,    27,     5,  1793,     5,    27,
     747,     5,   630,   750,  1491,   730,   595,   529,    64,   756,
       6,     5,   294,   760,   196,   197,     5,   764,   411,   412,
     413,   768,   486,   120,     5,   772,   773,     0,   775,  2335,
       6,   778,    30,   780,   781,   782,    34,   149,   248,  2345,
       5,   788,   670,   462,   791,   221,  1940,   691,     5,     5,
     514,   798,     5,   673,   302,   600,     5,     5,   805,   331,
     672,   248,   530,     5,   294,   812,     5,     5,   408,     5,
     979,   221,     5,   595,   248,     5,   823,   248,   486,   643,
     827,   248,     5,     5,   831,     5,    31,     5,     5,   220,
     837,   403,   292,   840,   517,   649,   433,     5,  1204,   331,
       5,   559,   560,   248,     5,   513,  1075,   632,  1178,  1179,
       5,  1217,   643,   111,    18,    19,    20,    21,    22,     5,
     118,   632,     5,   632,   485,   118,   671,   248,  1097,   552,
    2333,   554,   112,   113,  2440,     5,    28,   429,   430,   562,
    1328,    29,   208,   792,   709,   710,     5,   248,   208,     5,
     672,     5,   622,   712,     5,   548,   579,   449,   581,   340,
       5,     5,   142,   143,   144,   718,   679,   165,   166,   592,
     593,   639,  2181,   596,  2576,    27,     5,  2617,  2369,     5,
     331,     5,   747,     5,   414,   750,   526,   452,     5,     5,
     408,   614,   484,     5,  1869,   760,     5,   486,  2680,   764,
     429,   430,   209,   768,    27,   452,   810,   811,   555,     5,
     775,   493,     5,   665,   563,   780,     5,   782,  2933,   412,
     248,    27,     5,   788,   513,   514,   791,   403,   209,    27,
     514,   784,   462,   798,   449,   839,    42,  2543,   842,  3091,
     805,   482,   452,   649,   482,  2719,   449,   812,   447,   518,
    1206,  2869,   403,   403,   432,   484,   408,   607,   823,  2974,
     486,   608,   827,   493,  1446,   449,   831,  2322,   600,   596,
    2888,   559,   837,   392,   482,   840,   122,   731,   615,   702,
     703,   704,   705,   706,   707,   708,   575,   593,   711,   712,
     713,   486,   522,   716,   568,   718,   447,   442,   721,  2785,
     723,   670,   449,  1875,  1393,   607,   670,   449,   526,   732,
     492,  2793,   607,  2795,   449,   720,   526,  2613,   610,   486,
     743,   744,   643,  2629,   443,   340,   643,   671,  2491,  2815,
     753,  2471,  1300,   715,  1454,  1862,   759,  2489,   604,   600,
     673,   670,   765,   766,   767,   607,   720,  1453,   771,   673,
     622,   774,   720,   776,   777,   673,  2152,   643,   164,  1465,
    2156,   784,  3181,   679,   787,  1925,  3146,   665,  1281,   792,
     793,   720,   795,  2054,   680,   722,   799,   610,  2842,   802,
    3160,   610,  2846,   720,   676,   808,   610,   810,   811,   673,
     622,   604,   815,   816,   817,  3398,   541,   482,   821,   496,
    1309,   824,   673,  1312,  1313,   526,   829,   213,   673,  1156,
     569,  1450,   671,   836,   442,   838,   839,   673,   841,   842,
     679,   844,   845,   449,   482,   248,   673,   425,   676,   665,
     482,   449,   425,   604,   726,   727,    23,  2118,  2119,    22,
     449,   482,   248,   665,   250,   449,   637,   676,   598,  2013,
    2992,   303,   639,   449,   486,   449,   630,  1426,   482,   643,
     449,   482,   482,   673,   316,   482,  1435,  1011,   673,    52,
    1014,   622,    23,   449,  2780,  1545,  2782,  1021,   895,  1023,
    1024,   631,   613,  1299,   449,  1909,    18,    19,    20,    21,
      22,   424,   449,   449,  1463,   665,   449,   726,   727,   596,
     449,   449,   732,    25,   673,    27,  2988,   449,  2990,  2991,
     449,   449,  3292,   449,   580,    10,  2525,   514,    27,   449,
     580,   670,   520,  3141,     0,   948,   449,   449,   673,   449,
     510,   449,   449,  1280,  1281,  1282,  3018,  1725,  2331,  1727,
     346,   449,   449,  1593,   449,   232,    22,    52,   449,  1737,
    1738,   702,   703,   704,   449,   643,  1744,  1745,  1746,  1747,
      28,    29,   713,   449,   232,   417,   449,   150,   151,   152,
     153,   154,   155,   996,  1577,   968,   509,   665,   482,   449,
     692,   693,   694,   695,   696,   168,   169,   170,   513,   514,
     449,  1156,   525,   449,    27,   449,    27,   300,   449,   445,
    3074,  2708,   400,  2710,   449,   449,  2713,     5,  1564,   415,
     408,   409,   449,   611,  2920,   595,  1039,   423,  1041,   442,
     449,   427,   468,   449,  2930,   449,    25,   449,    27,   449,
     383,   293,   449,   449,   567,   433,   390,   449,   436,  1032,
     449,   328,   693,   694,   481,   150,   151,   152,   153,   154,
     155,   486,  1075,   449,   452,  1078,   449,   463,   638,   417,
     449,   463,   412,   168,   169,   170,   449,    26,    27,  2463,
    2269,  1094,     5,   606,  1097,    25,   673,    27,   530,  1648,
    1862,  1650,  1651,   351,   739,  1654,  1655,  1306,    25,   357,
      27,  1660,  3291,   691,   546,  2491,  3295,    25,    25,    27,
      27,   699,   635,    30,   550,   292,   449,  3013,   763,   514,
    3150,   644,  3186,  1136,  2959,  1280,  1281,  1282,  1141,  2206,
     733,  2402,   528,  2404,   307,  2406,   248,   310,    25,  1152,
      27,    18,    19,    20,    21,    22,   643,   678,   449,   248,
      25,   292,    27,  1166,  1167,  1168,  1934,  1170,   449,  1172,
    1173,    25,   383,    27,   809,  1178,  1179,   555,  1175,  2999,
     701,   567,  3002,  1813,   819,  3005,  1183,   822,    26,    27,
    1739,   826,   530,  2337,    14,   352,  1983,   832,  3173,   834,
     486,  1204,   535,  1822,  1823,   591,  1825,   364,    20,  3184,
    1699,   339,  1215,  1702,  1217,    27,   642,   306,    25,  2363,
      27,  1907,   307,  1226,   352,   310,  1229,   576,   654,   655,
     608,  1234,   307,    25,   568,    27,   662,   615,   643,  1468,
    1898,  1448,  1449,   643,  1451,   579,  2619,  2620,    30,   635,
    1253,  1254,    34,   420,    25,    25,    27,    27,   644,  1262,
     665,    43,    26,    27,   679,   303,   429,  3153,   222,   248,
     224,   653,    26,    27,   656,  1278,  1279,   592,   316,   521,
     376,   444,  1466,  3345,  2052,   448,  1396,  2922,  1398,   420,
     303,  1977,   303,  2061,   486,   249,  2064,  2065,  2066,  2067,
     486,   639,  1305,   316,   592,   316,    26,    27,   643,   248,
     514,  1480,  1861,   160,   161,  1318,  1319,   559,   248,  3006,
     643,   484,    26,    27,   535,  1328,   641,    48,    49,    50,
     665,   248,    53,   486,    55,    56,  3161,  3162,  1341,   514,
     248,   248,   728,   729,   429,   678,  1349,   592,  1577,   512,
     823,   133,   643,   641,   827,  1891,   486,   485,   831,   444,
    3246,   481,   643,   448,   697,   698,   529,  2507,   339,   444,
     482,   446,  2423,   327,  2425,  1421,   330,  2102,  1480,   417,
    2105,   352,     5,   248,   717,   672,   535,   294,  1572,  1573,
     732,  2865,   679,  3213,   248,   216,   641,  1400,   352,   484,
    2552,  1404,  1405,  1406,   417,    20,   417,   486,  2585,  2549,
     248,   753,    27,  1416,  1417,  1418,   303,   486,  1421,  1422,
    1423,  1424,  1425,  1426,   766,     5,   486,   512,     8,   316,
    2609,    20,  1435,   264,   265,   266,  1620,  1621,    27,   643,
     486,   248,  1991,  1446,   529,  1448,  1449,   610,  1451,  2825,
    1453,  1454,   486,   513,   514,  1090,   248,   678,  1461,  1462,
    1463,   665,  1465,  1466,  2939,  1468,  1469,   678,    24,   673,
      26,  2157,   486,   486,  1477,   486,  2162,   248,   248,   700,
     701,  1484,  1485,   486,   248,  2171,   697,   698,  1491,  1492,
    2707,  2708,   530,  2710,   248,   316,  2713,   486,  3165,  2973,
    3167,  3168,  3169,  3170,   678,   486,   717,   414,   546,   486,
    2196,    20,   294,   676,   485,   575,   296,   530,    27,   530,
     750,   486,  2071,  2153,  1851,   610,   700,   701,   248,   678,
     417,   485,   353,   546,   764,   546,  3349,   486,   768,  1542,
    1543,    24,  1545,    26,   248,  1548,  1549,    20,   697,   698,
     780,   486,  2041,  3366,    27,    20,  2560,   486,  2047,  2048,
     394,   486,    27,  1198,  2568,  2569,  2570,  1570,   717,  1572,
    1573,   405,   352,  1208,  1577,  1210,  1579,  2207,  1581,  1582,
    1583,  1691,   449,  2351,   486,   222,   493,   224,  3279,  3280,
    3281,   676,  2643,  2644,  2645,  2646,   417,    40,    41,   486,
     526,    20,    40,    41,  1607,  3418,   327,   533,    27,   330,
     431,   332,   249,   424,   486,   522,  1619,  1620,  1621,  2168,
     486,   455,  3435,  1626,  1627,   456,   406,  2257,    20,    21,
     410,   352,   414,   692,  1758,   469,   695,   696,   486,    20,
    2408,   362,    26,   530,  1647,  1648,    27,  1650,  1651,   486,
     494,  1654,  1655,  1980,  1657,   514,  2424,  1660,  2709,   546,
    2711,   505,   383,   296,   296,    26,   199,  2435,  1176,  1177,
     203,  3145,  1180,  1181,    26,   222,  3367,   224,  3369,   679,
     462,  1684,   526,   486,  1868,   406,  2013,   486,   532,   410,
     327,  3166,  1695,   330,   679,   318,   540,  3172,   509,   486,
    3175,  3176,  3177,  3178,   838,   485,  1851,   841,   486,   530,
     844,   493,   424,   486,   525,   352,    26,   782,   562,   352,
     352,   486,  1725,   557,  1727,   546,   791,   486,  1957,  1958,
     723,   724,   725,   356,  1737,  1738,  1739,   513,   514,  1742,
     522,  1744,  1745,  1746,  1747,    18,    19,    20,    21,    22,
     695,   696,   375,   376,  1757,    25,   567,    27,   150,   151,
     152,   153,   154,   155,   485,    26,  1890,   666,   667,   668,
     669,  2320,   837,   406,   406,   840,  1779,   410,   410,   486,
     327,  1784,    25,   330,    27,  1909,    26,  1790,  1972,  3006,
    1793,  1764,   415,   702,   703,   606,   424,   509,    26,    25,
    2349,    27,   424,   673,   427,   352,   580,  2874,  1811,   486,
      25,  1725,    27,   525,  1817,   438,  2365,    24,  2586,    26,
    1455,  1456,  1457,  3298,   635,  2511,  3301,  3302,  3303,  3304,
      24,   454,    26,   644,   119,  1980,   486,  1472,    24,    25,
      26,   464,   702,   703,  1847,   168,   169,   170,   485,  2617,
     344,   345,   485,   485,   514,   567,   479,   486,  1861,  1862,
    2546,   486,  1865,  1866,    25,  1868,    27,  2416,  2013,  2418,
      25,    25,    27,    27,  2878,    24,    24,    26,    26,   486,
    1883,   509,  2481,  2482,  2935,  2936,   486,   509,  2939,    25,
      25,    27,    27,   486,   606,  2384,   519,   525,  2387,   486,
    2389,  2390,  1905,   525,  1907,    24,    24,    26,    26,   194,
     486,  1546,    20,    21,  3389,    25,  3095,    27,   541,  1449,
      26,  1451,   476,   635,    26,  3104,  1929,   486,  1931,  1932,
    1565,  1934,   644,   556,    25,  1938,  1939,  1940,   485,   567,
     563,    26,  3121,   566,    26,   567,    26,  2715,    26,  1584,
     424,  2935,  2936,    26,  1957,  1958,    26,   673,   116,   449,
    1595,   419,   673,    26,   587,   449,   486,   486,   591,  1972,
     482,   256,     5,   258,  1977,  1978,  1979,   449,   606,   486,
    1983,   449,   449,   449,   606,   449,    26,   610,  1991,   274,
     449,   526,   679,   486,    20,  2544,    20,   282,   486,   486,
     449,   286,     5,   514,  2331,   628,   486,   635,   486,   424,
    2337,   677,    26,   635,   673,  2018,   644,    26,   449,   449,
    2189,   316,   644,  2026,  2027,  1939,   311,  2030,   482,   419,
      30,    20,    26,    26,    26,   509,  2363,   643,    26,    26,
      26,  3185,   150,   151,   152,   153,   154,   155,    26,  2052,
     449,   525,   643,   225,   715,   449,    26,    26,  2061,     5,
     449,  2064,  2065,  2066,  2067,  2068,   727,   449,  2071,   449,
     449,    20,  2075,  2076,    26,   486,  2079,  2735,  2736,  2737,
     449,  2739,  2740,  2741,  2742,  2743,  2744,  2189,    26,  3268,
    2748,    26,    26,   567,   509,   756,   673,  2100,  2101,  2102,
     449,     5,  2105,  2106,  2107,   679,    26,  2110,   449,   359,
     525,   772,   773,   449,   449,  3166,   449,   778,   449,   677,
     781,  3172,  3173,     5,  3175,  3176,  3177,  3178,   449,   449,
     486,   679,   606,  3184,    26,   449,  2139,    26,  2141,  2142,
     643,  2144,  2145,   679,   235,  2148,  2832,   449,    25,  2152,
      25,    25,   567,  2156,  2157,   449,    25,   449,   449,  2162,
     449,   635,   449,   449,   359,  2168,  2169,   449,  2171,  2172,
     644,   449,  2175,  2176,  2860,    20,    21,    22,   449,   677,
     449,  1816,   449,   449,   673,   486,  2331,   673,     8,   482,
     533,   606,  2337,  2196,   649,   323,   678,   515,  1833,  3378,
    2203,     5,   671,  2206,   737,   738,   515,    52,   671,   194,
    3277,   476,  2215,   649,   514,   712,  2219,   712,  2363,   385,
     635,   673,   673,   665,   650,  1860,     5,   476,     5,   644,
     486,   486,  1867,  3352,  3353,  3354,  3355,  3356,  3357,   486,
     486,  3009,  2245,  3011,   486,   632,   403,  3298,     8,    14,
    3301,  3302,  3303,  3304,   629,     5,   712,  2806,     5,   712,
     476,   486,  1897,   486,    26,   437,   123,  2270,    26,   149,
     361,   256,   673,   258,    26,   514,   367,   368,   369,   451,
     643,   486,  1917,   486,   486,   486,   486,   486,   486,   274,
     486,   476,  2619,  2620,   514,    26,     5,   282,   389,   649,
       5,   286,   835,   486,   486,   150,   151,   152,   153,   154,
     155,   679,   845,   218,    51,   486,   486,  2320,   715,   679,
     678,   409,   494,   168,   169,   170,   311,   610,   233,   234,
       5,   670,  2335,   505,    18,    47,    19,   242,  3389,   211,
    2343,  2344,  2345,   441,  2382,  2348,  2349,  3398,  2351,   449,
    3019,    48,    49,    50,   526,    25,    53,   676,    55,    56,
     532,  2364,  2365,   643,  3368,  2368,  2369,   536,   540,   632,
    2599,   276,  2601,  2542,   536,   673,     5,   209,   998,   600,
     285,  1001,  3150,  1003,  1004,  1005,  1006,  1007,   600,    26,
     562,   456,  2584,    26,   600,   486,  3164,   380,   449,   111,
     112,    26,   449,   494,   449,  2408,   497,   679,   449,   314,
     526,   673,  3098,  2416,   505,  2418,  2419,   580,   449,  2422,
     679,  2424,  2643,  2644,  2645,  2646,   449,   486,   486,   486,
    3116,  2555,  2435,   486,  3501,   115,  2560,  2440,  2441,  2442,
    2542,     5,   486,  2992,  2568,  2569,  2570,   449,   539,   717,
    2453,   673,   643,   358,   673,   643,   600,   486,    18,    19,
      20,    21,   307,   996,     5,   310,   178,   639,  2471,   679,
       5,     5,     5,   645,  2619,  2620,   673,   670,   486,     5,
     633,   537,  2584,   574,     8,   197,  2489,   679,  2491,   678,
      26,   376,   123,  2982,    26,  2984,  2985,   402,   276,     5,
     384,  2504,   593,   594,     5,   449,   486,   486,  2511,   486,
     418,  2146,   650,   604,    18,    19,    20,    21,   609,   679,
      14,   604,     5,   713,   600,   486,  3294,    26,  2163,  2164,
    2165,  2166,   158,  2536,   673,  2538,   679,  2540,   486,   600,
    2543,  2544,     5,  2546,   678,  1078,   679,   678,   449,  2184,
     692,   482,   449,     5,   266,   449,     5,   648,  2561,     5,
    2563,  2564,  2565,  3331,   426,   672,   390,    26,   482,   516,
     486,   516,     5,  3259,   486,   486,  2579,   486,   673,   486,
     486,     5,     8,  2586,   429,  2981,   486,   486,   514,   680,
     150,   151,   152,   153,   154,   155,  2599,     5,  2601,   444,
     194,   673,   673,   448,    24,    25,    26,    27,  2611,  2612,
     322,   323,   630,   384,  2617,    25,  2251,   329,    38,    39,
     403,   403,   334,   607,   514,   673,  2629,   403,   486,   418,
     327,   481,     5,   330,     5,   332,  1290,   704,   514,   484,
    2643,  2644,  2645,  2646,  2647,  2648,   150,   151,   152,   153,
     154,   155,    26,     5,  2657,   352,     5,    25,    14,  2662,
      14,    26,   256,   670,   258,   362,  2850,   512,   649,   486,
     607,     5,     5,   649,   486,  2844,  3444,   449,    26,  2863,
     274,   679,   449,   449,   529,   449,   383,     6,   282,     7,
     449,   325,   286,   503,   449,  2698,  2699,     5,   449,   673,
      26,    26,   122,   297,  2707,  2708,   679,  2710,   673,   406,
    2713,    26,  2715,   410,  2935,  2936,  2719,   311,  2939,  2354,
    1253,  2356,    26,    26,   449,    20,     5,   620,   331,  2643,
    2644,  2645,  2646,   673,     5,     5,   600,     5,     5,     8,
     673,   449,  2844,   449,   625,   486,   721,   679,     5,   600,
       5,   526,   679,  3080,  2878,   269,  2759,   449,   677,   449,
      26,   449,   679,  3090,   679,   610,   679,   486,  2771,   486,
       5,     5,    25,    25,    25,   677,   679,  2780,  2781,  2782,
     502,   672,    25,    25,   353,  1318,  1319,    26,   485,    26,
      26,   449,   449,    26,    26,  1328,    26,    26,     5,   449,
     449,   486,   523,  2806,     5,   517,   449,   486,   604,     8,
     298,    26,    25,   482,   449,  2818,  2819,   529,   496,  2822,
     403,   449,  2825,  2486,    20,   200,   607,   486,   248,  2832,
     486,   676,   486,  3322,  3323,   486,     5,     5,   486,  2842,
     486,   486,  2845,  2846,    14,   449,   269,  2850,   449,     5,
     497,   514,    26,   449,    26,    26,   449,  2860,  3185,   449,
    2863,    26,  2865,   486,    26,  3094,    26,   432,   622,    26,
     449,  2874,   449,   298,   449,   486,   403,   449,   299,   496,
     600,   486,  2517,   595,   514,  2520,   449,    14,   449,     7,
     449,   297,   297,    26,   449,   679,   449,  2643,  2644,  2645,
    2646,   450,   486,   673,   449,   629,   449,    26,   486,   482,
      25,  2914,   299,     5,   514,    26,    26,  2920,   449,   449,
     449,   449,     5,    26,   449,   673,  2929,  2930,   449,  2932,
    2933,   673,  2935,  2936,   482,   673,  2939,   449,   482,  2563,
    2504,  3428,  1023,  2241,  1585,  3166,  1918,  2950,   691,    35,
    2585,  3172,  3173,    37,  3175,  3176,  3177,  3178,  1491,  2172,
     672,  2536,  2178,  3184,   362,   119,   214,   353,   123,   676,
    2973,  2974,  1763,   363,  1764,   219,   617,   548,   392,  1317,
    2643,  2644,  2645,  2646,   391,  3418,   581,   579,  1816,  2992,
     702,   703,   704,  1014,   706,   821,   427,  3000,  2024,  1287,
    3003,  2031,  1619,  3006,  2165,  1867,  3009,  2588,  3011,  2900,
    3013,   723,  1622,  1947,  2266,  3472,  2168,  1967,  1468,    22,
    3112,  2935,  2936,    98,    47,  2939,  2382,    47,  1682,  1683,
      28,  1923,   452,   777,  3037,  1689,  1929,   334,  1543,  1596,
    3185,  1627,  1041,  1932,  3037,  1254,  3222,   759,  1462,   802,
    1541,  3435,   950,   765,  2586,   767,  2774,  3232,  1897,   771,
    2772,  1565,   774,   483,   465,   777,   486,  2757,  2452,  3092,
    2830,  3074,  3090,  3083,  2822,   787,  2156,  3298,  1796,   499,
    3301,  3302,  3303,  3304,  1779,  2110,  3000,   318,  2331,  3003,
     802,  3094,  3284,  3444,  1627,  3098,   808,  3013,  1662,  1662,
    2350,  2002,  2932,   815,   816,   817,  2779,  2813,  3246,   821,
    2071,  1990,  2698,  3116,    48,    49,    50,   829,   538,    53,
    2699,    55,    56,  2422,  3003,   356,  3327,  2801,    18,    19,
     550,  2474,  1647,   845,    24,    25,    26,    27,   624,  2453,
    3055,  2419,  3145,     9,   375,   376,  3490,  3150,    38,    39,
    3153,  1283,  2441,  2934,  2630,  1738,  3011,  2442,  1737,  3288,
    1641,  3164,  1279,  3166,  2344,  2544,  2929,  1614,  3389,  3172,
    3173,   591,  3175,  3176,  3177,  3178,  3183,  3398,  3181,  1757,
    3183,  3184,  3284,  3186,   415,  3164,  1141,  1477,  3172,  2935,
    2936,  2542,  1725,  2939,  1727,  2189,   427,   557,    -1,    -1,
      -1,  1485,    -1,  1467,  1737,  1738,    -1,   438,    -1,    -1,
     630,  1744,  1745,  1746,  1747,    -1,    -1,    -1,  2853,  3222,
      -1,    -1,   642,   454,  3227,    -1,  3229,    -1,    -1,    -1,
      -1,    -1,   122,   464,   654,   655,    -1,    -1,    -1,    -1,
      -1,    -1,   662,  3246,  3368,   665,  1900,    -1,   479,    -1,
    3164,    -1,  3166,   673,    -1,  2890,  3259,    -1,  3172,  3173,
      -1,  3175,  3176,  3177,  3178,    -1,    -1,    -1,    -1,    -1,
    3184,    -1,  2935,  2936,  3277,    -1,  2939,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3288,    -1,    -1,   519,  1943,
      -1,  3294,    -1,    -1,    -1,  3298,    -1,    -1,  3301,  3302,
    3303,  3304,    -1,  3306,    -1,    -1,    -1,    -1,    -1,    -1,
     541,    -1,    -1,    -1,    -1,    -1,    -1,  3320,    -1,    -1,
      -1,    -1,    -1,    -1,  3327,   556,    -1,    -1,  3331,    -1,
      -1,    -1,   563,    -1,    -1,   566,    -1,  3000,    -1,    -1,
    3003,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3352,
    3353,  3354,  3355,  3356,  3357,    -1,   587,    -1,   248,    -1,
     591,  3364,    -1,    -1,    -1,  1898,  1078,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,
      -1,    -1,  1094,    -1,  3298,    -1,  3389,  3301,  3302,  3303,
    3304,    -1,    -1,   327,    -1,  3398,   330,   628,   332,    -1,
      -1,  1934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3327,    -1,    -1,    -1,    -1,   352,    -1,
    3166,    -1,    -1,    -1,  1136,    -1,  3172,  3173,   362,  3175,
    3176,  3177,  3178,    -1,    -1,    -1,    -1,    -1,  3184,    -1,
      -1,  3444,    -1,  3446,    -1,    -1,    -1,    -1,    -1,   383,
      -1,    -1,    -1,    -1,  1166,  1167,  1168,    -1,  1170,    -1,
    1172,  1173,    -1,    -1,    -1,  3100,  1178,  1179,    -1,    -1,
      -1,    -1,   406,    -1,    -1,  3389,   410,    -1,    25,    -1,
      -1,    -1,    -1,    -1,  3398,  3488,  3489,  3490,    -1,    -1,
      -1,    -1,  1204,    -1,    -1,    -1,    -1,    -1,  3501,    -1,
    3503,  3136,    -1,  3166,    -1,  1217,    -1,    -1,    -1,  3172,
    3173,    -1,  3175,  3176,  3177,  3178,    -1,  1229,    -1,  2052,
      -1,  3184,    -1,    -1,    -1,    -1,    -1,    -1,  2061,    -1,
      -1,  2064,  2065,  2066,  2067,    -1,    -1,    -1,    -1,    -1,
    3203,  1253,  1254,  2076,    -1,    -1,    -1,    -1,    -1,    -1,
    1262,   485,  3298,    -1,    -1,  3301,  3302,  3303,  3304,    -1,
      -1,    -1,   452,    -1,    -1,    -1,  1278,  1279,    -1,    -1,
      18,    19,    -1,  2106,    -1,    -1,    -1,    -1,    26,    27,
      -1,  2235,  2236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2246,   483,    42,    -1,   486,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2271,  2272,  2273,
    2274,  2275,  2276,    -1,    -1,    -1,    -1,  2281,  2282,  2283,
    2284,    -1,    -1,    -1,  2288,  3298,    -1,    -1,  3301,  3302,
    3303,  3304,    -1,  3389,    -1,    -1,    -1,   537,   538,    -1,
      -1,    -1,  3398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     550,    -1,    -1,    -1,  3327,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,  2206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,    -1,  2370,  2371,    -1,    -1,
      -1,    -1,    -1,  2377,  2378,    -1,  3389,    -1,  3363,    -1,
      -1,    -1,    -1,    -1,    -1,  3398,  1448,  1449,    -1,  1451,
     630,  1453,  1454,    -1,    -1,    -1,    -1,    -1,    -1,  1461,
    1462,    -1,   642,  1465,    -1,    -1,    -1,  1469,    -1,    -1,
      -1,    -1,    -1,    -1,   654,   655,    -1,    -1,  1480,    -1,
      -1,    -1,   662,    -1,    -1,   665,    -1,    -1,    -1,  1491,
    1492,    -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,
     248,    -1,   250,    -1,    -1,    -1,   131,   132,    -1,   134,
     135,   136,    -1,    -1,   361,    -1,    -1,    -1,  2351,    -1,
     367,   368,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1542,  1543,  3467,  1545,    -1,    -1,  1548,  1549,    -1,    -1,
      -1,    -1,   389,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,  1579,    -1,    -1,
      -1,    -1,  2526,  2527,    -1,  2408,    -1,    -1,    -1,    42,
      -1,  2535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2422,
      -1,  2424,    -1,    -1,    -1,  1607,    -1,    -1,   346,    -1,
      -1,    -1,  2435,    -1,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,  1626,  1627,    -1,   242,   190,  2573,
    2574,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   381,    -1,   207,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2600,   494,  2602,    -1,
     497,   276,    -1,  2486,   117,    -1,    -1,    -1,   505,   122,
     285,    -1,    -1,    -1,    -1,    -1,   129,   415,    -1,    -1,
      -1,    -1,  1684,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,   260,   314,
     315,    -1,   539,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2663,
    2664,    -1,    -1,  2667,  2668,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,
     478,    -1,    -1,   358,    -1,    -1,    -1,    -1,   486,    -1,
      -1,    -1,    -1,    -1,    -1,   317,   593,   594,    -1,    -1,
      -1,   499,    -1,  2586,    -1,    -1,    -1,   604,    -1,    -1,
      -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,   341,
      -1,    -1,    -1,    -1,    -1,    -1,   348,   402,   350,    -1,
      -1,    -1,    -1,    -1,  2617,   248,    -1,   250,   360,    -1,
      -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,    -1,    -1,
      -1,   648,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2643,  2644,  2645,  2646,    -1,    -1,   388,    -1,    -1,   567,
      -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,
      -1,   456,    -1,   680,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   433,    -1,    -1,    -1,  2698,  2699,    -1,    -1,    -1,
      -1,  1883,    -1,    -1,  2707,  2708,    -1,  2710,    -1,    -1,
    2713,    -1,  2715,   346,    -1,   457,  2719,   635,   351,  2843,
      -1,    -1,    -1,  2847,    -1,  1907,   644,    -1,    -1,    -1,
      -1,    -1,  2735,  2736,  2737,    -1,  2739,  2740,  2741,  2742,
    2743,  2744,  2866,    -1,    -1,  2748,    -1,  1929,   381,    -1,
      -1,    -1,   494,    -1,    -1,    -1,  1938,    -1,  1940,    -1,
      -1,    -1,  2886,   505,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   415,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,  1977,  1978,  1979,    -1,    -1,
      -1,  1983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     728,   729,   445,    -1,    -1,    -1,    -1,   450,    -1,   452,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
     463,    -1,    -1,    -1,    -1,   468,  2018,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,
     483,    -1,    -1,   486,    52,    -1,   489,    -1,    -1,    -1,
     602,   603,   604,    -1,    -1,   498,   499,    -1,    -1,    -1,
      -1,  2874,    -1,   615,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,   538,    -1,    -1,    -1,   542,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   660,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,   561,    -1,
      -1,    -1,  2935,  2936,   567,    -1,  2939,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,   591,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,   170,    -1,    -1,  2157,   718,    -1,    -1,    -1,
    2162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2171,
      -1,    -1,   734,    -1,    -1,    -1,    -1,  3000,    -1,    -1,
    3003,    -1,   635,  3006,    -1,    -1,  3009,  2189,  3011,   642,
    3134,   644,    -1,  3137,  2196,    -1,   121,    -1,    -1,    -1,
      -1,   654,   655,    -1,  2206,    -1,    -1,    -1,   279,   662,
      -1,    -1,    -1,  2215,    -1,    -1,   287,  2219,    -1,    -1,
     673,    -1,   293,    -1,   295,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,
      18,    19,    -1,  2245,    -1,    -1,    24,    25,    26,    27,
      -1,  3074,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   333,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,   728,   729,    -1,   349,    24,
      25,    26,    27,   354,    -1,    -1,    -1,    -1,    -1,   307,
      -1,    -1,   310,    38,    39,   366,     9,    -1,    -1,    -1,
      -1,    -1,   373,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3150,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3282,   117,
      -1,  3164,    -1,  3166,   122,    -1,    -1,    -1,    -1,  3172,
    3173,   129,  3175,  3176,  3177,  3178,    -1,    -1,    -1,    -1,
      -1,  3184,    -1,  3186,    -1,    -1,  2368,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,   157,
    3203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3333,
    3334,    -1,  3336,    -1,  3338,  3339,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,   122,
      -1,   429,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,
     448,   356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2441,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
     521,   376,   377,   378,  3277,   526,    -1,    -1,    -1,    -1,
      -1,   532,  3406,    -1,  3408,    -1,   484,    -1,    -1,    -1,
     248,  3294,   250,    -1,    -1,  3298,    -1,    -1,  3301,  3302,
    3303,  3304,    -1,   554,    -1,    -1,    -1,    -1,   559,    -1,
     415,    -1,    -1,    -1,   512,    -1,    -1,    -1,  3442,    -1,
      -1,    -1,   427,   248,  3327,    -1,    -1,    -1,  3331,  2511,
      -1,   529,    -1,   438,    -1,    -1,    -1,  3461,  3462,    -1,
      -1,  3465,    -1,    -1,  3468,    -1,    -1,    -1,    -1,   454,
      -1,    -1,    -1,    -1,    -1,   248,    -1,   250,    -1,   464,
    2542,    -1,    -1,    -1,  2546,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,  2561,
      -1,  2563,    -1,  2565,    -1,    -1,  3389,    -1,   346,    -1,
      -1,     9,    -1,   351,    -1,  3398,    -1,  2579,    -1,    -1,
      18,    19,  2584,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   527,   381,    42,    -1,    -1,    -1,    -1,  2611,
    2612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   556,    -1,   346,    -1,    -1,    -1,   415,   351,    -1,
      -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,  2657,    -1,    -1,   676,    -1,
      -1,    -1,   587,    -1,    -1,    -1,   591,   445,   381,    -1,
      -1,    -1,   450,    -1,   452,    -1,    -1,    -1,  3501,   117,
      -1,    -1,    -1,    -1,   122,   463,    -1,    -1,    -1,    -1,
     468,   129,    -1,    -1,   619,    -1,    -1,    -1,    -1,    -1,
     478,    -1,   415,   628,    -1,   483,    -1,   452,   486,    -1,
      -1,   489,    -1,     9,   427,    -1,    -1,    -1,    -1,   157,
     498,   499,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,   445,    -1,    -1,    -1,    -1,   450,   483,   452,
      -1,   486,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
     463,    -1,    -1,    -1,   499,   468,    -1,  2759,    -1,   537,
     538,    -1,    -1,    -1,   542,   478,    -1,    -1,    -1,  2771,
     483,    -1,   550,   486,    -1,    -1,   489,    -1,    -1,    -1,
      -1,   526,    -1,   561,    -1,   498,   499,    -1,    -1,   567,
      -1,    -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,
     248,    -1,   250,   591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,   538,   122,    -1,    -1,   542,
    2832,    -1,    -1,   129,    -1,    -1,    -1,   550,    -1,    -1,
      -1,    -1,  2844,    -1,    -1,    -1,   591,    -1,   561,    -1,
     563,    -1,    -1,    -1,   567,    -1,    -1,   635,  2860,    -1,
      -1,   157,    -1,  2865,   642,    -1,   644,    -1,    -1,    -1,
      -1,    -1,  2874,    -1,    -1,    -1,   654,   655,   591,    -1,
      -1,    -1,    -1,    -1,   662,   630,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   673,    -1,   642,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,   654,
     655,    -1,    -1,   351,    -1,    -1,    -1,   662,    -1,    -1,
     665,    -1,   635,    -1,    -1,    -1,    -1,    -1,   673,   642,
      -1,   644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   654,   655,   381,    -1,    -1,    -1,    -1,    -1,   662,
     728,   729,   248,    -1,   250,    -1,    -1,     9,    -1,    -1,
     673,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,  2973,    24,    25,    26,    27,    -1,   415,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,   445,    24,    25,
      26,    27,   450,    -1,   452,   728,   729,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,   463,    -1,    -1,    -1,    -1,
     468,    -1,    -1,    -1,    -1,  3037,    -1,    -1,    -1,    -1,
     478,    -1,    -1,    -1,    -1,   483,    -1,    -1,   486,    -1,
     346,   489,    -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,
     498,   499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3098,    -1,    -1,   537,
     538,    -1,    -1,    -1,   542,    -1,   122,    -1,    -1,    -1,
      -1,    -1,   550,    -1,  3116,    -1,    -1,    -1,    -1,   415,
      -1,    -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,   567,
      -1,   427,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,  3145,    -1,    -1,    -1,    -1,    -1,   445,
      -1,    -1,    -1,   591,   450,    -1,   452,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    53,   463,    55,    56,
      -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   478,    -1,    -1,    -1,    -1,   483,    -1,    -1,
     486,    -1,    -1,   489,    -1,    -1,   248,   635,    -1,    -1,
      -1,    -1,   498,   499,   642,    -1,   644,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   654,   655,    -1,    -1,
    3222,    -1,    -1,    -1,   662,  3227,    -1,  3229,    -1,    -1,
      -1,    -1,   248,   120,    -1,   673,    -1,    -1,    -1,    -1,
      -1,    -1,   538,    -1,    -1,    -1,   542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   550,    -1,    -1,  3259,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   561,    -1,    -1,    -1,    -1,
      -1,   567,    -1,    -1,    -1,  3277,    -1,    -1,    -1,    -1,
      -1,    -1,  3284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     728,   729,    -1,    -1,    -1,   591,    -1,    -1,    -1,   351,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,   222,    -1,   224,    -1,   635,
      -1,    -1,    -1,    -1,    -1,    -1,   642,    -1,   644,    -1,
    3352,  3353,  3354,  3355,  3356,  3357,    -1,    -1,   654,   655,
      -1,    52,   249,    -1,    -1,    -1,   662,    -1,    -1,   256,
      -1,   258,    -1,    -1,    -1,    -1,    -1,   673,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,   286,
     452,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,   296,
     297,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,    -1,    -1,    -1,    -1,    -1,
      -1,   483,   728,   729,   486,    -1,   452,    -1,    -1,    -1,
     327,    -1,    -1,   330,    -1,   332,   498,   499,    -1,    -1,
      -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,   155,   352,    -1,   483,    -1,    -1,
     486,    -1,    -1,    -1,   526,   362,    -1,   168,   169,   170,
      -1,    -1,    -1,   499,    -1,    -1,   538,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   383,   384,   550,  3501,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     526,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,   538,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,   419,   420,   550,    -1,    -1,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   624,    -1,    -1,   591,    -1,    -1,   630,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   639,   640,    -1,
     642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,
      -1,    -1,   654,   655,    -1,    -1,    -1,    -1,   624,   496,
     662,    -1,    -1,   665,   630,    -1,   307,    -1,    -1,   310,
      -1,   673,    -1,   639,   640,    -1,   642,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   654,   655,
      -1,    -1,    -1,    -1,    -1,    -1,   662,    -1,   535,   665,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   673,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,   596,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,
      -1,    -1,    -1,    -1,    -1,   632,    -1,    -1,    -1,   109,
     110,    -1,    -1,   444,   114,    -1,    -1,   448,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   678,    -1,   484,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,   692,   693,   694,   695,   696,
     697,   698,    -1,   700,   701,    -1,   176,    -1,   178,   179,
     180,   512,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     717,   191,   192,   193,    -1,    -1,    -1,    -1,   529,   199,
      -1,    -1,   202,    -1,   204,   205,   206,    -1,    -1,    -1,
      -1,    -1,   212,    -1,   214,   215,    -1,   217,    -1,   219,
     220,    -1,    -1,   223,    -1,    -1,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,   235,   236,   237,    -1,   239,
      -1,    -1,    -1,   243,    -1,   245,   246,    -1,    -1,    -1,
      -1,   251,    -1,    -1,   254,    -1,    -1,   257,    -1,   259,
      -1,   261,    -1,   263,    -1,    -1,    -1,   267,   268,    -1,
     270,   271,   272,    -1,    -1,   275,    -1,   277,   278,   610,
     280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,    -1,   304,   305,    -1,    -1,   308,   309,
      -1,    -1,   312,   313,    -1,    -1,    -1,    -1,    -1,    -1,
     320,   321,   322,    -1,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   334,   335,   336,    -1,   338,    -1,
      -1,    -1,   342,   343,    -1,   676,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   363,   364,   365,    -1,    -1,    -1,    -1,
      -1,   371,   372,    -1,    -1,    -1,    -1,    -1,    -1,   379,
      -1,    -1,   382,    -1,    -1,    -1,   386,   387,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,   397,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   422,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,   457,    -1,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   506,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,    -1,    -1,
      -1,    -1,    -1,    -1,   524,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,   547,   548,    -1,
      -1,    -1,   552,    -1,    -1,    -1,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,
     570,   571,   572,   573,    -1,    -1,    -1,   577,    -1,    -1,
      -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,   588,   589,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
      -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   612,    -1,   614,    -1,    -1,   617,    -1,    -1,
      -1,    -1,    -1,   623,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,   170,    -1,    -1,    -1,    -1,   649,
      -1,    -1,   652,    -1,    -1,    -1,    -1,   657,    -1,    -1,
     660,   661,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   675,    -1,    -1,    -1,    -1,
      -1,    -1,   682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   307,    -1,    -1,   310,    -1,
      -1,    -1,    -1,    -1,    -1,   705,   706,   707,   708,   709,
     710,   711,    -1,    -1,   714,    -1,   716,    -1,   718,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   307,    -1,    -1,   310,    -1,    -1,    -1,    52,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   444,    -1,    -1,    52,   448,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,   170,    -1,    -1,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     512,    -1,    -1,   429,   168,   169,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,   444,    -1,
      -1,    -1,   448,   449,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,    -1,   484,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,
      -1,    -1,    -1,   529,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,   310,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   307,    -1,    -1,   310,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     676,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,   448,   449,    -1,    -1,   429,    -1,    -1,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,
     444,    -1,    -1,    -1,   448,   449,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,   484,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     484,    -1,    -1,    -1,    -1,   512,    -1,   444,    -1,    -1,
      -1,   448,   449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,   529,    -1,    -1,    -1,    -1,    -1,   512,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,   310,    -1,   529,    -1,   484,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   529,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,    -1,   307,    -1,    -1,   310,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,    -1,    -1,   610,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,   676,
      -1,    -1,    -1,   610,    -1,    -1,    -1,   444,    -1,    -1,
      -1,   448,   449,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,   676,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,
      -1,    -1,   444,    -1,    -1,   512,   448,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   307,    -1,    -1,   310,    -1,
      -1,    -1,   484,   150,   151,   152,   153,   154,   155,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,   310,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,   676,
      -1,    -1,   444,    -1,    -1,    -1,   448,   449,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,   310,   168,   169,   170,    -1,    -1,     6,
       7,     8,   484,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,   676,    -1,    -1,    -1,    -1,    -1,
     512,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,   448,   449,    -1,    -1,    52,    -1,   529,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,   150,
     151,   152,   153,   154,   155,    -1,    -1,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   512,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   529,    -1,    -1,    -1,    -1,   444,   610,    -1,
      -1,   448,    -1,   307,    52,    -1,   310,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
     497,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   676,   512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,    -1,   307,    -1,    -1,   310,    -1,
      -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,   307,    -1,    -1,   310,
      -1,    -1,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,   170,    -1,    -1,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,
     444,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,
     484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,   168,
     169,   170,   444,    -1,    -1,    -1,   448,    -1,   429,    -1,
      -1,    -1,    -1,    -1,    -1,   529,    -1,    -1,    -1,   676,
      -1,    -1,    -1,   444,    -1,    -1,    -1,   448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,   307,
      -1,    -1,   310,    -1,    -1,   497,     9,    -1,    -1,    -1,
      -1,    -1,    -1,   484,    -1,    18,    19,    20,    -1,    -1,
     512,    24,    25,    26,    27,    -1,   497,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    38,    39,   529,    -1,    -1,
      -1,   512,    -1,    -1,    -1,    -1,   610,   444,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,   529,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   484,   307,    -1,
      -1,   310,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,   676,    -1,    -1,   512,    52,    -1,   610,   122,
      -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   529,    -1,    -1,    -1,   444,    52,    -1,   610,
     448,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   484,    -1,    -1,    -1,
      -1,    -1,    -1,    52,   676,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   512,   676,    -1,    -1,    -1,    -1,
     429,    -1,    -1,   610,   150,   151,   152,   153,   154,   155,
      -1,   529,    -1,    -1,    52,   444,    -1,    -1,    -1,   448,
      -1,    -1,   168,   169,   170,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   484,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,   676,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,   168,
     169,   170,   610,    -1,    52,    -1,    -1,    -1,    -1,    -1,
     529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,   170,    -1,    18,    19,    20,    -1,   351,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,   676,    -1,
      -1,   307,    -1,    -1,   310,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   610,   307,    -1,    -1,   310,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,    -1,
      -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,   122,   452,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,   307,
     483,    -1,   310,   486,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,    -1,   498,   499,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,   444,    -1,
      -1,    -1,   448,    -1,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
      -1,    -1,    -1,   448,    -1,   538,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   484,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,   307,
     429,    -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,   484,
      -1,    -1,    -1,    -1,   248,   444,   512,    -1,    -1,   448,
      -1,    -1,   497,    -1,    -1,    -1,    -1,    52,   591,    -1,
      -1,    -1,    -1,   529,    -1,    -1,    -1,   512,    -1,    -1,
      -1,   429,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,   529,   484,   444,    -1,    -1,    -1,
     448,   624,    -1,   168,   169,   170,    -1,   630,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   639,   640,    -1,   642,
      -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   654,   655,    -1,    -1,    -1,   484,    -1,    -1,   662,
     529,    -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     673,    -1,    -1,    -1,   610,    -1,    -1,   351,    -1,    -1,
      -1,   429,    -1,    -1,   512,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   610,   444,    -1,    -1,    -1,
     448,   529,    -1,   168,   169,   170,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    38,    39,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,   484,    -1,    -1,    -1,
     676,   610,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   676,   307,    -1,   512,   310,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,   452,    -1,
      -1,   529,   610,    -1,    18,    19,    20,    38,    39,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,   676,    -1,   483,
     122,    -1,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,   499,    -1,   122,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,   307,    -1,    -1,   310,    38,    39,   676,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   610,    -1,   538,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
      -1,    -1,    -1,   448,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,   591,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,   676,    -1,
     122,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   484,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     624,    -1,    -1,   248,    -1,    -1,   630,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   429,   639,   640,   512,   642,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
     654,   655,    -1,   448,   529,    -1,    -1,    -1,   662,    -1,
      -1,   665,    -1,    -1,    -1,    -1,    -1,   248,    -1,   673,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   484,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   529,   610,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   676,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     452,    -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   483,    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,   483,    -1,
      -1,   486,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   452,    -1,    -1,   499,    -1,    -1,    -1,    -1,    -1,
      -1,   676,    -1,    -1,    -1,    -1,   137,   138,   452,    -1,
      -1,    -1,    -1,    -1,    -1,   537,   538,   148,    -1,    -1,
      -1,    -1,   483,    -1,    -1,   486,    -1,    -1,   550,    -1,
      -1,    -1,   537,   538,    -1,    -1,    -1,    -1,   499,   483,
      -1,    -1,   486,    -1,    -1,   550,    -1,    -1,    -1,    -1,
     452,    -1,    -1,    -1,    -1,   499,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,    -1,    -1,
      -1,   483,    -1,    -1,   486,    -1,   591,    -1,    -1,   550,
      -1,    -1,    -1,    -1,   538,    -1,    -1,   499,    -1,    -1,
      -1,    -1,   624,    -1,    -1,    -1,   550,    -1,   630,    58,
      59,    60,    61,    62,    63,    -1,    -1,   639,   640,   624,
     642,    -1,    -1,    -1,    -1,   630,    -1,    -1,   452,    -1,
     591,    -1,   654,   655,   639,   640,   538,   642,    -1,    -1,
     662,    -1,    -1,   665,    -1,    -1,    -1,   591,   550,   654,
     655,   673,    -1,    -1,    -1,    -1,    -1,   662,    -1,   483,
     665,    -1,   486,   624,    -1,    -1,    -1,    -1,   673,   630,
      -1,    -1,    -1,    -1,    -1,   499,    -1,    -1,   639,   640,
     624,   642,    -1,    -1,    -1,    -1,   630,   318,    -1,   591,
      -1,    -1,    -1,   654,   655,   639,   640,    -1,   642,    -1,
      -1,   662,    -1,    -1,   665,    -1,    -1,   156,    -1,    -1,
     654,   655,   673,    -1,   538,    -1,    -1,   391,   662,    -1,
      -1,   665,   624,    -1,    -1,   356,   550,    -1,   630,   673,
     404,    -1,    -1,    -1,    -1,    -1,    -1,   639,   640,    -1,
     642,    -1,    -1,    -1,   375,   376,   377,   378,    -1,    -1,
      -1,    -1,   654,   655,    -1,    -1,    -1,    -1,    -1,    -1,
     662,    -1,   393,   665,    -1,    -1,    -1,   591,    -1,    -1,
      -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   466,    -1,    -1,    -1,   427,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   630,   438,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,   642,    -1,
      -1,    -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,
     654,   655,    -1,   464,    -1,    -1,    -1,   511,   662,    -1,
      -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,   479,   673,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,
     544,   545,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,   519,    -1,
      -1,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,
     541,   585,   586,    -1,    -1,    -1,   590,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      -1,    -1,   563,    -1,    -1,   566,    -1,    -1,    -1,   388,
      -1,    -1,   391,    -1,    -1,    -1,    -1,   396,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   404,   587,    -1,    -1,    -1,
     591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   647,    -1,    -1,    -1,    -1,    -1,   610,
      -1,    -1,    -1,    -1,   658,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,    -1,    -1,
      -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,   670,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   544,   545,    -1,    -1,    -1,
      -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   582,    -1,    -1,   585,   586,    -1,    -1,
      -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,    -1,   658
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    43,   133,   294,   414,   462,   493,   522,
     732,   794,   802,   829,   830,   886,  1060,  1061,  1117,  1118,
    1119,  1121,  1122,  1123,  1128,  1130,  1143,  1144,  1145,  1146,
    1147,  1589,    28,    29,   803,   804,   805,   806,   807,    27,
    1024,  1604,  1024,  1024,    25,  1024,  1494,  1148,   831,  1494,
    1024,   830,     0,  1120,  1123,  1146,    31,   805,   807,   887,
     665,    25,   248,   828,   829,  1011,  1024,  1029,  1128,  1143,
    1149,  1180,  1181,  1182,  1183,  1184,  1188,   412,   833,   834,
     835,   836,   839,   840,   795,   111,   118,   165,   166,   425,
     520,   611,   691,   699,   802,   979,  1059,  1124,  1125,  1127,
    1131,  1132,  1138,  1150,  1303,  1313,  1589,   670,  1024,  1183,
     300,   513,   514,  1189,    20,  1024,  1187,   673,   834,     5,
     832,   412,  1024,     5,   859,   861,   862,   733,   798,  1024,
    1314,  1024,  1304,  1139,  1024,  1024,  1127,  1133,   318,   356,
     375,   376,   415,   427,   438,   454,   464,   479,   519,   541,
     556,   563,   566,   587,   591,   610,   628,   888,   889,   890,
     893,    25,  1180,  1186,    18,    19,    26,    42,   117,   129,
     157,   250,   346,   381,   415,   427,   463,   478,   486,   499,
     542,   567,   591,   635,   644,   728,   729,   743,   745,   946,
     953,   964,   966,  1024,  1180,  1190,  1191,   514,    14,   885,
     836,   576,  1290,   837,   834,   839,    32,    44,   121,   137,
     138,   148,   318,   356,   375,   376,   377,   378,   393,   415,
     427,   438,   454,   464,   479,   519,   541,   556,   563,   566,
     587,   591,   610,   628,   670,   843,   853,   864,   869,  1024,
     796,  1024,   486,  1024,   828,   980,  1151,  1024,   895,   376,
     841,   486,   871,   873,   874,   872,   881,   882,   486,   486,
     894,   514,   486,   834,   852,   481,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   743,   486,   825,
       9,    18,    19,    24,    25,    26,   122,   351,   445,   450,
     452,   468,   483,   486,   489,   498,   538,   550,   561,   591,
     642,   654,   655,   662,   673,   922,   930,   931,   932,   933,
     934,   964,   965,   967,  1030,  1180,  1293,  1487,   486,   486,
     486,   486,   486,   486,    18,    19,    20,    21,    22,   744,
      26,    36,   486,   575,     5,   482,  1190,    25,    26,  1024,
    1030,    19,    25,    26,   838,  1030,   723,   724,   725,   842,
     866,   855,   867,   841,   486,   486,   486,   856,   871,   872,
     486,   486,   854,   514,   865,   486,   852,   834,   863,   828,
     486,    26,   486,  1140,   828,   828,   486,  1024,   486,   513,
     847,    26,   679,   424,   509,   525,   567,   606,   635,   644,
     875,   679,   424,   509,   525,   567,   606,   635,   644,   883,
      26,    26,   896,   897,   898,   899,  1024,    26,   850,   851,
      26,   643,   665,   673,  1180,   720,   972,  1015,  1024,  1015,
    1015,   972,   972,   922,    24,    25,    26,    19,    24,    25,
      26,   673,   968,   969,   970,   971,    25,   973,  1015,  1016,
     922,   449,   922,   922,   922,   922,   580,  1310,   486,   486,
     922,   424,   509,   525,   567,   606,   635,   644,  1490,  1491,
     486,   922,   922,   486,   486,   935,   486,   486,   486,   486,
      26,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    52,   150,   151,
     152,   153,   154,   155,   168,   169,   170,   307,   310,   429,
     444,   448,   484,   512,   529,   610,   676,   824,   923,   936,
     938,   939,   940,   941,   942,   943,   944,   476,   956,   954,
     960,   958,  1180,  1180,   743,  1024,   947,  1024,  1191,   514,
     482,    26,   845,   486,   868,   852,   868,   847,    26,    26,
      26,   852,    26,    26,   833,   850,   868,    26,   673,   116,
     860,   797,  1315,   449,  1305,  1605,  1606,  1607,  1608,  1609,
     981,  1152,  1134,   673,    26,   449,   876,   877,   486,   878,
     883,   884,   878,   486,   879,     5,   449,     5,   449,     5,
     340,     5,   888,   482,     5,     5,   449,   834,   834,   834,
     870,   449,   486,     5,   449,   514,   673,   449,   449,   449,
     449,   449,   449,   449,    19,    26,   449,   643,   969,    19,
      26,   643,    26,   449,     5,   449,   449,     5,   826,   922,
     526,  1510,   922,   486,   679,    20,   449,  1510,    20,  1293,
     922,   922,   922,   922,   922,   922,   922,   922,   922,   922,
     922,   922,   922,   922,   922,   922,   922,   922,   922,   922,
     922,   922,   922,   486,   922,   922,   486,  1180,   922,   922,
     922,   922,   449,     5,   486,   537,   775,   776,   777,   922,
     486,  1190,   514,   677,    26,   673,    26,   449,   449,     5,
     449,   316,     5,   449,     5,   449,   340,   482,     5,   449,
     870,   799,   800,  1132,  1024,  1196,  1197,  1199,  1196,   419,
    1606,  1290,    45,    46,    47,    54,    57,    64,    65,   109,
     110,   114,   124,   125,   127,   141,   159,   162,   163,   176,
     178,   179,   180,   188,   189,   191,   192,   193,   199,   202,
     204,   205,   206,   212,   214,   215,   217,   219,   220,   223,
     226,   227,   228,   229,   230,   231,   235,   236,   237,   239,
     243,   245,   246,   251,   254,   257,   259,   261,   263,   267,
     268,   270,   271,   272,   275,   277,   278,   280,   288,   289,
     301,   304,   305,   308,   309,   312,   313,   320,   321,   322,
     324,   334,   335,   336,   338,   342,   343,   347,   355,   363,
     364,   365,   371,   372,   379,   382,   386,   387,   397,   414,
     422,   428,   439,   451,   457,   459,   460,   467,   506,   517,
     524,   547,   548,   552,   564,   570,   571,   572,   573,   577,
     581,   588,   589,   599,   601,   612,   614,   617,   623,   649,
     652,   657,   660,   661,   675,   682,   705,   706,   707,   708,
     709,   710,   711,   714,   716,   718,   736,   737,   738,   739,
     756,   780,   801,   802,   808,   827,   901,   902,   903,   904,
     915,   916,   917,   918,   919,   920,   921,   974,  1005,  1009,
    1031,  1033,  1036,  1037,  1038,  1039,  1052,  1062,  1086,  1087,
    1089,  1093,  1108,  1109,  1113,  1114,  1115,  1116,  1126,  1141,
    1157,  1168,  1169,  1170,  1174,  1177,  1211,  1214,  1216,  1222,
    1223,  1226,  1229,  1234,  1236,  1238,  1241,  1248,  1253,  1258,
    1259,  1260,  1272,  1273,  1276,  1282,  1285,  1286,  1311,  1326,
    1328,  1329,  1330,  1331,  1343,  1349,  1350,  1370,  1373,  1402,
    1404,  1495,  1496,  1527,  1528,  1535,  1550,  1574,  1589,  1590,
    1595,  1596,  1598,  1602,  1603,  1610,   802,  1129,   678,   701,
    1153,  1154,  1196,    20,   449,   481,   848,   875,    26,   880,
      26,    26,    26,   897,   899,   891,   851,    26,   643,  1024,
    1015,   743,    20,   720,  1024,   875,   962,   962,    26,   449,
     643,   962,    24,    26,    26,   643,    24,    26,   872,   963,
    1016,   873,   449,   417,   530,   639,  1518,   449,   449,    26,
    1491,   449,   449,   449,   449,   449,   449,   449,   497,   497,
     497,   945,  1510,   497,   945,  1510,   957,   955,   961,   959,
      26,   951,   948,     5,   949,   482,  1190,   859,   449,    20,
     848,    26,   486,    26,    26,   844,    26,   731,   800,   673,
     449,     5,   449,  1180,  1180,  1180,  1024,    25,  1180,  1235,
    1024,    25,  1024,  1480,   408,  1025,  1026,  1604,  1025,    25,
    1024,  1479,  1024,  1024,  1256,  1019,  1025,  1019,  1024,  1600,
    1480,  1024,    26,   740,  1180,  1334,  1019,  1256,   945,    26,
    1030,  1298,  1299,  1298,   922,   929,  1372,  1479,  1479,   924,
     945,  1025,  1536,  1536,   905,  1256,  1019,  1332,  1180,  1021,
    1025,   929,  1536,  1180,  1256,  1180,  1371,  1536,    25,   639,
    1171,  1172,  1180,  1019,  1019,  1171,  1020,  1025,  1024,  1172,
    1019,  1536,  1019,  1021,  1480,  1180,  1209,  1210,  1017,  1025,
    1021,   433,   615,  1015,  1088,  1024,   809,  1479,  1022,  1025,
      25,   248,  1024,  1403,  1578,  1580,  1581,  1582,  1583,  1585,
     945,  1209,   679,   945,  1025,  1237,   975,    67,    68,    69,
      70,   190,   198,   207,   210,   253,   260,   317,   341,   348,
     350,   360,   388,   396,   433,   457,   494,   505,   602,   603,
     604,   615,   660,   718,   734,  1102,  1230,  1231,  1180,  1201,
    1202,   928,   929,  1247,   972,   972,  1018,  1025,   945,  1235,
    1312,  1180,  1289,    25,   486,  1180,  1284,  1530,  1283,   929,
    1591,   164,   213,   250,   346,   423,   463,   528,   757,   953,
    1024,  1180,  1321,   782,   929,  1017,   643,  1024,  1032,  1158,
     929,  1017,    26,  1180,  1110,  1017,   929,  1551,   929,  1298,
    1024,  1034,  1035,  1021,  1034,   972,  1021,  1034,   972,  1040,
    1034,    25,    26,   442,   541,  1030,  1091,  1180,  1198,  1200,
     123,   331,   403,   447,   622,   702,   703,   704,   713,   747,
    1042,  1044,  1046,  1048,  1050,  1175,  1176,  1179,   394,   405,
     455,   469,   557,  1405,   693,   694,   983,   984,   985,  1024,
    1155,   700,  1154,   449,   359,   449,   449,   449,   449,   677,
       5,   449,   834,   449,   482,   486,   679,    19,    26,   449,
     962,    26,   449,   449,   643,    26,   643,   679,    18,    19,
      20,    25,    26,    38,    39,   122,   452,   483,   486,   499,
     538,   550,   591,   624,   630,   639,   640,   642,   654,   655,
     662,   665,  1024,  1030,  1486,  1488,  1517,  1519,  1520,  1522,
    1523,  1524,  1546,  1547,  1548,  1549,  1579,  1580,  1584,  1310,
     449,  1310,  1310,  1310,  1310,  1310,  1310,    25,    25,    25,
     922,   937,   449,    25,   937,   449,   449,   449,   449,   449,
     449,   775,   449,   777,   775,   482,   359,   449,   834,   857,
     858,   449,   449,   677,   449,  1024,  1316,  1199,  1306,   112,
     113,   142,   143,   144,   510,   595,   638,  1351,  1352,  1353,
    1356,  1359,  1362,  1363,  1364,  1367,   673,   643,   665,   160,
     161,   486,   673,   643,   665,     8,   678,   482,  1479,   533,
    1257,  1198,   168,   169,   170,   649,   537,   925,   926,   929,
    1180,  1205,  1479,   746,   747,   908,   323,    51,   145,   146,
     147,   679,  1254,   515,     5,   672,   679,   671,   671,  1212,
     649,   476,     5,   610,  1063,   515,   712,  1593,   712,   442,
     811,  1180,   600,   671,  1217,  1218,  1219,   673,    25,  1581,
     514,  1586,   385,  1401,   665,   673,   927,   929,   610,  1578,
     927,     8,   607,  1018,    26,   555,   608,   722,  1010,  1180,
    1010,  1010,  1010,    25,   235,   361,   367,   368,   369,   389,
     494,   497,   505,   539,   574,   593,   594,   604,   609,   648,
     680,  1106,  1107,  1010,  1010,   650,  1103,   747,  1103,  1103,
    1011,  1011,  1103,  1103,    40,    41,  1232,   747,    40,    41,
    1233,     5,   476,     5,   392,   443,     5,   746,   139,   140,
     593,   680,  1094,   715,  1594,   928,   666,   667,   668,   669,
    1288,  1530,  1290,   929,  1278,  1279,  1280,  1291,  1292,   929,
     486,   486,   486,   486,    25,   778,  1024,   486,  1530,   403,
     486,   575,    36,   643,   632,   783,   790,   781,  1024,    25,
    1173,  1180,  1274,     8,  1277,    14,  1024,  1185,  1192,  1193,
    1195,  1203,  1204,  1249,    40,    41,   221,   403,   598,   631,
    1327,    33,   248,   607,  1552,  1553,  1554,  1556,   629,     5,
     712,   712,   927,  1198,  1205,  1090,   476,     5,   209,  1068,
     486,  1180,   927,   486,    26,    26,   123,  1178,    25,  1180,
    1534,  1534,  1025,  1385,  1237,  1018,    37,   177,   279,   287,
     293,   295,   306,   333,   349,   354,   366,   373,   521,   526,
     532,   554,   559,  1374,  1375,  1383,  1392,  1393,  1399,  1400,
    1406,  1407,  1417,  1437,  1441,  1506,  1507,  1537,  1538,  1541,
    1542,  1558,   986,   987,   149,   982,   993,   994,   985,  1156,
    1605,  1135,   514,   888,   851,   673,  1024,   875,    26,   449,
     643,   962,   449,   643,   962,   962,    24,    26,   643,    24,
      26,   876,  1523,  1523,   424,   509,   525,   567,   606,   635,
     644,  1489,  1492,   526,  1522,   486,   486,   486,   486,  1517,
    1517,  1517,   486,   486,   486,   486,  1024,   486,     5,   600,
    1446,  1451,   670,  1024,    18,    19,    20,    21,   150,   151,
     152,   153,   154,   155,  1544,  1492,  1492,   476,     5,   449,
     449,   952,   950,   514,     5,   449,   859,   828,   828,   303,
     316,   417,   486,   530,   546,  1421,  1422,  1427,  1429,   486,
    1024,  1368,  1369,    26,   486,  1024,  1348,  1361,  1429,  1431,
     486,  1024,  1358,   486,  1348,  1354,     5,  1024,    25,  1024,
    1024,    25,  1027,  1183,  1024,    25,  1024,  1024,  1024,  1601,
    1479,   649,   486,   486,   908,  1479,     5,   679,   486,  1578,
      25,  1029,  1255,  1255,  1254,  1255,  1530,  1171,   929,   929,
     929,  1012,  1013,   486,  1180,  1210,  1064,  1065,  1066,  1479,
     679,  1530,   972,  1594,  1088,  1180,   810,   678,   929,   409,
    1221,   610,  1220,  1582,   743,  1587,  1588,  1024,    20,  1583,
       5,  1575,   670,  1227,   126,   128,   130,   671,   679,   900,
    1198,  1201,   976,    18,    19,   486,  1104,  1106,  1231,  1180,
    1202,  1011,   929,   403,   649,    26,  1180,    26,  1180,   746,
     211,  1287,   449,   441,  1325,  1290,  1280,     5,   671,  1281,
    1592,  1024,    25,   972,   972,   643,  1016,   676,  1180,   763,
    1024,  1024,  1024,   929,   398,   786,   790,   632,   784,   792,
      23,   292,  1160,  1164,   536,   945,   536,  1275,   929,   513,
    1189,   673,     5,  1111,   600,  1250,  1180,   221,   403,  1555,
    1557,   247,  1553,  1053,  1035,   972,   972,  1045,  1046,  1068,
    1068,    48,    49,    50,    53,    55,    56,   327,   330,   332,
     352,   362,   383,   406,   410,   485,  1067,  1069,  1070,  1098,
    1180,  1200,   600,   748,    26,   456,  1051,   380,  1529,  1529,
     196,   197,   492,   600,  1024,  1438,  1439,  1481,  1479,  1479,
    1479,  1376,  1479,  1479,  1024,  1539,   225,   437,   451,   494,
     505,   526,   532,   540,   562,   639,   645,  1408,  1410,  1411,
    1412,  1518,  1479,  1384,  1408,  1410,  1605,  1605,   442,   995,
    1180,   695,   696,   988,   989,   990,   535,   678,   697,   698,
     717,   998,   999,  1605,   828,    26,   849,    20,  1024,   449,
      26,   449,   962,    26,   962,    24,    26,   449,   449,    24,
      26,   679,  1518,   449,   452,  1522,  1545,  1584,   417,   530,
     639,  1470,  1522,  1525,  1470,  1470,  1470,  1470,   673,  1525,
    1520,   569,  1447,  1448,  1449,  1479,   580,  1445,  1452,   390,
     568,   579,  1394,  1513,  1024,  1522,  1522,  1522,  1522,   679,
     486,   679,  1579,   922,   449,   449,   849,   858,  1317,  1307,
     486,   486,   486,  1365,  1429,   486,   486,   115,  1366,  1368,
       5,  1360,  1361,   121,   356,   376,   377,   378,   415,   427,
     438,   454,   464,   479,   527,   556,   566,   587,   591,   619,
     628,  1471,  1472,  1473,  1475,  1357,  1358,  1354,  1355,   717,
    1352,   673,   643,   449,   673,   643,   600,  1599,   486,   741,
     742,  1024,  1335,   945,   925,  1024,  1333,   670,  1224,  1254,
    1254,  1254,   679,     5,     5,     5,   633,   929,     5,   673,
     537,   679,   678,   222,   224,   327,   330,   812,   815,   816,
    1098,   813,   814,  1024,   486,  1025,   702,   703,  1225,     5,
     482,   929,  1479,  1576,  1577,  1578,   630,   670,  1228,  1024,
    1024,  1013,  1014,   563,   972,   908,     8,     8,   978,    26,
      26,  1105,  1106,  1180,   376,  1242,   123,   922,  1290,   276,
    1292,  1298,  1605,     5,     5,   449,   449,   779,  1024,   449,
    1530,   775,   486,   486,   486,   791,   787,   418,   785,   929,
     398,   788,   792,   650,  1100,  1165,  1161,   420,  1159,  1160,
     927,   679,  1186,    20,  1024,  1194,  1204,    14,   537,  1251,
    1252,  1522,  1180,  1584,  1201,  1605,  1047,  1048,   604,  1023,
     600,  1081,  1080,  1079,  1078,  1083,  1082,  1015,  1084,  1015,
    1085,  1077,  1076,  1074,  1073,  1099,   383,  1070,  1075,   972,
      58,    59,    60,    61,    62,    63,   156,   391,   404,   466,
     472,   511,   534,   544,   545,   550,   560,   582,   585,   586,
     590,   647,   658,   749,   750,  1096,  1097,     5,    26,  1530,
     306,  1180,   526,  1511,  1512,  1530,  1237,  1505,  1507,   158,
     158,   649,  1235,  1440,  1441,   486,  1418,   208,  1452,  1479,
     232,   328,  1543,   673,   679,   486,  1413,  1413,   600,   678,
       5,  1508,  1559,   400,   409,   433,   436,   452,   555,   608,
     615,  1018,  1386,  1391,   679,   678,   997,  1180,     5,   600,
     991,   992,   692,   990,   996,  1024,   996,  1000,  1001,   996,
     383,   999,  1136,   482,   449,   643,   962,   449,   643,   449,
     449,   962,   962,   424,   509,   525,   567,   606,   635,   644,
    1493,  1519,     5,  1492,     5,   449,     5,  1522,     5,   449,
    1522,  1522,  1522,  1522,  1024,   449,   486,  1449,     5,   670,
    1024,  1485,     9,   351,   486,   498,  1455,  1456,  1457,  1458,
    1459,  1463,  1467,  1469,  1522,   426,  1443,  1453,  1024,  1514,
     672,  1470,   390,  1493,    26,  1493,   482,   516,  1300,  1320,
     516,  1261,  1294,   665,  1024,  1424,  1426,  1479,  1483,  1484,
    1428,  1483,  1428,     5,   449,  1366,  1428,  1455,  1024,   449,
    1369,     5,   449,   486,   486,   486,  1492,  1492,   486,   486,
     486,   486,   486,   264,   265,   266,   456,  1430,  1432,     5,
     449,     5,   449,  1024,  1024,    25,  1024,  1024,    25,  1024,
     929,  1024,  1345,  1346,     5,  1347,  1348,   945,  1142,   673,
    1347,   630,  1530,  1530,   929,   929,  1012,   563,   929,  1597,
       5,  1065,    20,  1483,  1530,   813,   821,   820,   822,  1024,
    1028,   823,  1028,   249,   816,   819,     5,  1068,   673,   929,
       8,  1588,   514,   673,     5,  1530,   630,  1024,  1198,   945,
     607,  1389,     5,   449,  1180,     5,    26,  1180,   384,    25,
    1322,   403,   403,   514,   673,   403,   486,   764,   768,   761,
     759,  1605,  1605,   793,   789,   785,  1101,    25,  1023,  1166,
    1180,  1605,   929,   481,   514,   945,     5,  1054,  1049,  1050,
      26,   746,  1024,  1605,  1605,  1605,  1605,  1605,  1605,     5,
    1071,     5,  1072,  1605,  1605,  1605,  1605,  1104,  1605,  1023,
      25,    14,    14,     5,   449,    26,  1479,  1518,  1499,   649,
     649,  1375,  1504,  1505,  1441,  1419,  1483,   670,  1018,   486,
    1379,  1024,  1540,  1539,  1414,  1483,   518,  1415,  1416,  1481,
    1479,  1412,  1519,   103,   104,   105,   106,   107,   637,  1562,
     929,   929,   607,  1387,  1018,  1415,  1479,     5,  1180,   996,
    1605,  1605,     5,  1003,  1004,  1605,  1605,  1002,  1129,   892,
     962,    26,   962,    24,    26,   962,   962,   486,  1451,  1492,
     679,  1492,  1492,   449,  1522,   449,   449,   449,   449,  1448,
    1450,  1448,  1485,  1458,  1517,  1455,  1522,  1517,     6,     7,
       9,    12,    13,    14,    15,    16,    17,   429,   430,   484,
     610,   676,   726,   727,  1466,  1468,  1444,  1521,  1522,   503,
    1442,  1454,   325,  1344,    26,  1395,  1396,  1397,  1483,  1511,
    1514,   449,   846,   131,   132,   134,   135,   136,   234,   242,
     276,   285,   314,   315,   358,   402,   456,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,  1297,  1301,   195,
     568,  1302,  1318,   218,   233,   234,   242,   276,   285,   314,
     358,   402,  1295,  1296,  1308,  1302,  1484,   514,  1482,   449,
       5,   673,     5,   449,   449,  1429,   449,   449,  1361,    26,
    1476,  1476,    26,   679,   486,   679,    26,  1477,    26,    26,
    1477,  1477,    25,  1486,   216,   316,   353,   417,   431,   530,
     546,  1423,  1433,  1434,  1435,  1436,  1358,  1354,   673,   673,
     592,   641,     5,   449,   742,     5,   449,   927,   449,    20,
     449,  1530,     5,   929,   620,   331,   751,   752,   929,  1068,
    1605,  1605,     5,   817,   514,   673,     5,   818,  1605,   814,
     600,    20,  1024,     5,  1024,  1215,  1587,    20,  1483,  1577,
       8,  1530,   447,   712,   927,  1390,   977,  1106,   721,  1240,
     922,     5,   775,  1180,   758,   740,  1024,  1180,   766,   449,
     775,   775,   775,  1605,  1605,  1104,  1163,    25,  1167,  1180,
     625,  1008,  1190,   537,   928,  1112,  1252,   120,   596,  1055,
    1041,  1042,   673,  1015,  1605,  1015,  1605,   746,    26,  1180,
      26,  1180,   750,   449,   486,  1531,  1519,  1505,  1505,  1497,
       5,   449,   526,  1516,  1380,  1483,   533,  1377,  1516,   679,
       5,   449,     5,   600,  1509,    18,    19,   122,   483,   486,
     499,   537,   538,   550,   591,   630,   642,   654,   655,   662,
     665,  1024,  1486,  1517,  1546,  1548,  1567,  1568,  1569,  1570,
    1571,  1572,  1584,  1567,  1567,  1567,  1483,  1564,  1566,  1563,
    1564,  1565,  1560,  1388,   679,  1180,  1024,  1605,  1605,  1605,
    1605,   677,   449,   643,   449,   449,    26,   449,   679,  1493,
     679,   679,     5,   449,   449,  1456,  1457,  1461,  1523,  1461,
     486,  1517,  1461,   486,  1517,  1461,    10,   307,   444,   446,
    1522,     5,  1455,     5,   592,   641,  1398,  1344,   679,   677,
    1298,  1298,  1298,    25,  1298,  1298,  1298,  1298,  1298,  1298,
      25,    25,  1298,  1301,  1180,  1206,  1207,   672,   502,  1262,
      25,    25,    26,    26,    26,    26,    26,    25,  1180,  1296,
    1262,    26,  1423,  1483,    20,  1024,  1483,  1366,   449,   449,
       5,   449,  1493,    26,  1493,     5,  1474,     5,   449,   449,
     449,  1474,  1425,  1479,   486,  1435,  1366,  1024,  1024,  1346,
     676,   730,  1340,  1341,  1342,  1348,    66,   143,   144,   302,
     676,  1336,  1337,  1338,   523,   907,  1336,     5,   432,  1530,
       5,   486,   449,   604,  1095,  1028,  1605,   743,    20,  1024,
    1028,  1605,   972,   929,   482,  1530,     8,   972,  1201,  1605,
      26,  1023,    25,  1323,  1198,   482,   775,   765,   769,   449,
     449,  1605,  1023,   929,  1006,   482,  1057,  1056,   496,  1043,
    1044,    20,  1024,  1532,  1533,   607,  1515,  1500,  1498,  1483,
    1518,   200,  1420,     5,   449,  1378,  1540,  1483,  1416,  1415,
    1515,  1570,  1570,  1569,   486,   486,   486,   486,   486,   486,
     486,  1024,   486,     5,   449,    18,    19,    20,    21,  1544,
     449,     5,   449,     5,    14,   208,   580,  1561,  1201,  1415,
     269,  1137,   888,   962,    24,    26,   962,   962,   449,  1493,
    1493,  1493,  1448,   497,  1460,  1460,  1464,  1465,  1486,  1584,
    1460,  1464,  1460,  1461,  1522,  1521,  1396,  1493,   859,   592,
     641,  1208,     5,  1206,   119,   194,   256,   258,   274,   282,
     286,   311,  1263,  1264,  1319,  1309,     5,   482,  1482,    26,
     449,    26,  1478,   449,    26,   449,   486,  1455,  1339,  1604,
      26,  1342,    26,    26,  1339,  1344,  1338,  1015,   746,   432,
    1530,   929,   753,   622,  1213,    26,   746,   482,  1095,   449,
    1530,   298,   746,   449,   449,   486,   767,   403,   773,   449,
     762,   760,  1162,  1605,   514,   929,  1605,  1023,     5,   449,
    1201,  1451,  1519,  1483,   486,  1451,   449,  1545,  1470,  1569,
    1573,  1470,  1470,  1470,  1470,   514,   673,  1573,  1568,  1569,
    1569,  1569,  1569,  1564,    14,  1565,  1568,  1018,  1455,   201,
     670,  1409,   449,   449,  1462,  1486,  1526,     5,   449,   449,
    1460,     7,  1207,  1265,  1266,  1180,  1268,  1180,  1267,  1269,
    1264,   297,   297,    26,   449,   679,   449,  1426,   449,   906,
    1530,   450,   260,   317,   341,   350,   388,   396,   487,   656,
     750,   754,   755,   486,   673,   746,  1239,  1324,   770,   449,
    1198,   773,   773,   773,  1605,  1007,  1190,   629,  1092,  1533,
    1513,  1451,   537,  1381,  1382,  1522,  1513,   449,  1569,     5,
     449,  1569,  1569,  1569,  1569,    26,  1024,   449,   486,  1024,
     962,   962,  1465,  1522,  1605,  1605,  1270,  1605,  1271,  1605,
    1605,   482,  1493,   449,   296,   406,   410,   909,   910,   911,
    1098,  1010,  1010,  1010,  1010,  1010,  1010,    25,     5,   449,
     929,    20,  1024,  1098,  1243,  1244,  1245,   773,   775,   773,
     299,   482,  1058,   746,     5,   449,   344,   345,  1501,   449,
    1569,   449,   449,   449,   449,     5,   482,   514,  1567,  1605,
    1605,   913,   912,   296,   911,   914,   755,     5,  1246,   339,
    1245,   771,  1605,  1382,    25,  1024,  1502,  1503,    26,    26,
     449,  1605,  1605,  1605,   929,  1605,   449,  1055,   673,   673,
       5,   482,     5,   482,   449,   772,  1024,  1024,  1503,    26,
     221,   403,   774,   673,   482,  1198,  1024
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

  case 581:
#line 3460 "fgl.yacc"
    {sprintf(yyval.str,"0.%s",yyvsp[0].str);}
    break;

  case 583:
#line 3466 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 584:
#line 3470 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 585:
#line 3474 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 586:
#line 3479 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 587:
#line 3483 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 588:
#line 3498 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 589:
#line 3502 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 590:
#line 3508 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 591:
#line 3512 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 592:
#line 3521 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 593:
#line 3522 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 594:
#line 3534 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 595:
#line 3540 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 596:
#line 3548 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 603:
#line 3565 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 604:
#line 3567 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 605:
#line 3570 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 606:
#line 3572 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 611:
#line 3586 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 612:
#line 3588 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 613:
#line 3591 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 614:
#line 3593 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 627:
#line 3624 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 628:
#line 3626 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 629:
#line 3629 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 630:
#line 3631 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 631:
#line 3634 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 632:
#line 3636 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 633:
#line 3639 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 634:
#line 3641 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 635:
#line 3644 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 636:
#line 3646 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 637:
#line 3660 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 638:
#line 3664 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 639:
#line 3665 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 640:
#line 3672 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 642:
#line 3690 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 643:
#line 3706 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 644:
#line 3707 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 645:
#line 3708 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 646:
#line 3709 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 647:
#line 3710 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 648:
#line 3711 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 649:
#line 3712 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 653:
#line 3720 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 655:
#line 3726 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 656:
#line 3729 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 657:
#line 3734 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 658:
#line 3739 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 659:
#line 3742 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 660:
#line 3747 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 661:
#line 3752 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 662:
#line 3757 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 663:
#line 3764 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 664:
#line 3765 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 665:
#line 3772 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 666:
#line 3779 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 667:
#line 3781 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 668:
#line 3787 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 669:
#line 3792 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 670:
#line 3797 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 671:
#line 3802 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 672:
#line 3802 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 673:
#line 3805 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 674:
#line 3811 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 675:
#line 3816 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 676:
#line 3820 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 679:
#line 3828 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 680:
#line 3831 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 681:
#line 3834 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 682:
#line 3839 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 683:
#line 3844 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 684:
#line 3849 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 685:
#line 3856 "fgl.yacc"
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

  case 687:
#line 3867 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 688:
#line 3929 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 690:
#line 3938 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 691:
#line 3947 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 693:
#line 3954 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 694:
#line 3957 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 695:
#line 3963 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 696:
#line 3969 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 697:
#line 3973 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 698:
#line 3977 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 699:
#line 3983 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 700:
#line 3987 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 701:
#line 3991 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 702:
#line 3996 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 703:
#line 4001 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 722:
#line 4042 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 723:
#line 4049 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 724:
#line 4051 "fgl.yacc"
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

  case 726:
#line 4070 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 728:
#line 4073 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 729:
#line 4075 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 730:
#line 4078 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 731:
#line 4082 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 732:
#line 4085 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 733:
#line 4092 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 734:
#line 4097 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 735:
#line 4108 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 736:
#line 4109 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 737:
#line 4112 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 739:
#line 4118 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 740:
#line 4122 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 741:
#line 4123 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 742:
#line 4127 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 746:
#line 4142 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 747:
#line 4144 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 750:
#line 4153 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 751:
#line 4156 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 752:
#line 4160 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 753:
#line 4163 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 754:
#line 4166 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 755:
#line 4169 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 756:
#line 4172 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 757:
#line 4176 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 758:
#line 4179 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 759:
#line 4182 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 760:
#line 4185 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 761:
#line 4188 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 762:
#line 4191 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 763:
#line 4194 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 764:
#line 4197 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 765:
#line 4200 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 766:
#line 4201 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 767:
#line 4201 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 768:
#line 4202 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 769:
#line 4202 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 770:
#line 4203 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 771:
#line 4203 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 772:
#line 4204 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 773:
#line 4207 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 774:
#line 4208 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 775:
#line 4211 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 776:
#line 4219 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 777:
#line 4223 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 778:
#line 4229 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 779:
#line 4233 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 780:
#line 4238 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 781:
#line 4243 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 782:
#line 4248 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 783:
#line 4249 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 784:
#line 4250 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 785:
#line 4254 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 786:
#line 4258 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 787:
#line 4267 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 788:
#line 4272 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 789:
#line 4276 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 790:
#line 4283 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 791:
#line 4292 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 792:
#line 4298 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 793:
#line 4299 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 794:
#line 4300 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 795:
#line 4301 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 796:
#line 4302 "fgl.yacc"
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
#line 4312 "fgl.yacc"
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

  case 798:
#line 4326 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 800:
#line 4329 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 801:
#line 4336 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 802:
#line 4337 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 803:
#line 4338 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 804:
#line 4339 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 805:
#line 4340 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 806:
#line 4341 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 807:
#line 4342 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 808:
#line 4343 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 809:
#line 4344 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 810:
#line 4349 "fgl.yacc"
    {iskey=1;}
    break;

  case 811:
#line 4349 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 812:
#line 4351 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 813:
#line 4354 "fgl.yacc"
    {iskey=1;}
    break;

  case 814:
#line 4354 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 815:
#line 4356 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 816:
#line 4360 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 817:
#line 4363 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 818:
#line 4364 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 820:
#line 4367 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 826:
#line 4379 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 827:
#line 4380 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 828:
#line 4381 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 829:
#line 4382 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 830:
#line 4383 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 831:
#line 4384 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 832:
#line 4385 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 833:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 834:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 835:
#line 4388 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 836:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 837:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 838:
#line 4391 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 839:
#line 4392 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 840:
#line 4396 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 841:
#line 4414 "fgl.yacc"
    {chk4var=1;}
    break;

  case 842:
#line 4414 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 843:
#line 4417 "fgl.yacc"
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

  case 844:
#line 4441 "fgl.yacc"
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

  case 846:
#line 4459 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 847:
#line 4465 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 848:
#line 4471 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 849:
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
	print_locate('M',get_bind_varname('o',a),"0");
}
}
    break;

  case 850:
#line 4489 "fgl.yacc"
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

  case 854:
#line 4520 "fgl.yacc"
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

  case 857:
#line 4537 "fgl.yacc"
    {
	}
    break;

  case 867:
#line 4563 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 871:
#line 4571 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 885:
#line 4595 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 886:
#line 4596 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 887:
#line 4604 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 888:
#line 4610 "fgl.yacc"
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

  case 889:
#line 4626 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 890:
#line 4632 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 892:
#line 4647 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 893:
#line 4660 "fgl.yacc"
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

  case 894:
#line 4671 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 895:
#line 4678 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 896:
#line 4685 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 897:
#line 4691 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 898:
#line 4691 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 899:
#line 4696 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 900:
#line 4702 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 901:
#line 4710 "fgl.yacc"
    {
}
    break;

  case 905:
#line 4722 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 907:
#line 4730 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 908:
#line 4736 "fgl.yacc"
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

  case 911:
#line 4756 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 912:
#line 4762 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 913:
#line 4766 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 916:
#line 4778 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 917:
#line 4781 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 918:
#line 4785 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 919:
#line 4788 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 920:
#line 4800 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 921:
#line 4808 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 922:
#line 4814 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 923:
#line 4825 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 924:
#line 4829 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 925:
#line 4836 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 926:
#line 4843 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 927:
#line 4849 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 928:
#line 4854 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 931:
#line 4861 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 932:
#line 4862 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 933:
#line 4864 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 934:
#line 4865 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 935:
#line 4868 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 936:
#line 4869 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 937:
#line 4870 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 938:
#line 4872 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 939:
#line 4877 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 940:
#line 4882 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 941:
#line 4889 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 945:
#line 4896 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 946:
#line 4898 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 947:
#line 4900 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 949:
#line 4910 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 950:
#line 4913 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 951:
#line 4916 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 958:
#line 4932 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 959:
#line 4937 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 960:
#line 4937 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 961:
#line 4940 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 962:
#line 4968 "fgl.yacc"
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

  case 964:
#line 5025 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 966:
#line 5032 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 967:
#line 5036 "fgl.yacc"
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

  case 968:
#line 5079 "fgl.yacc"
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

  case 972:
#line 5127 "fgl.yacc"
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

  case 973:
#line 5141 "fgl.yacc"
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

  case 978:
#line 5165 "fgl.yacc"
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

  case 979:
#line 5229 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 980:
#line 5234 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 981:
#line 5242 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 982:
#line 5247 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 983:
#line 5255 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 984:
#line 5261 "fgl.yacc"
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

  case 985:
#line 5293 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 986:
#line 5296 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 987:
#line 5298 "fgl.yacc"
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

  case 988:
#line 5339 "fgl.yacc"
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

  case 993:
#line 5392 "fgl.yacc"
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

  case 994:
#line 5444 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 996:
#line 5453 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 997:
#line 5458 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 998:
#line 5469 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 999:
#line 5476 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1001:
#line 5484 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1002:
#line 5487 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 1003:
#line 5488 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1005:
#line 5490 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1006:
#line 5491 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1007:
#line 5494 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 1008:
#line 5497 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1009:
#line 5503 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 1010:
#line 5506 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1011:
#line 5510 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 1012:
#line 5515 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1013:
#line 5523 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 1014:
#line 5528 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 1015:
#line 5535 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1016:
#line 5537 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1021:
#line 5565 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1022:
#line 5572 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1023:
#line 5579 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1024:
#line 5582 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1025:
#line 5596 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1030:
#line 5613 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1031:
#line 5618 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1032:
#line 5624 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1034:
#line 5631 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1035:
#line 5636 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1036:
#line 5639 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1037:
#line 5640 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1038:
#line 5643 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1039:
#line 5644 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1040:
#line 5647 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1041:
#line 5648 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1042:
#line 5653 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1043:
#line 5660 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1044:
#line 5663 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1045:
#line 5669 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1046:
#line 5671 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1047:
#line 5673 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1048:
#line 5675 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1049:
#line 5678 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1050:
#line 5678 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1051:
#line 5679 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1052:
#line 5684 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1053:
#line 5692 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1054:
#line 5693 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1055:
#line 5698 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1056:
#line 5700 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1057:
#line 5702 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1061:
#line 5720 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1062:
#line 5721 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1063:
#line 5722 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1064:
#line 5723 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1065:
#line 5724 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1066:
#line 5725 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1067:
#line 5726 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1068:
#line 5727 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1069:
#line 5728 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1070:
#line 5729 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1071:
#line 5730 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1072:
#line 5731 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1073:
#line 5732 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1074:
#line 5733 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1075:
#line 5734 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1076:
#line 5735 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1077:
#line 5736 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1078:
#line 5737 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1079:
#line 5738 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1080:
#line 5739 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1081:
#line 5740 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1082:
#line 5741 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1083:
#line 5742 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1084:
#line 5743 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1085:
#line 5744 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1086:
#line 5745 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1087:
#line 5746 "fgl.yacc"
    { print_options('r',yyvsp[0].str); }
    break;

  case 1088:
#line 5747 "fgl.yacc"
    { print_options('|',yyvsp[0].str); }
    break;

  case 1089:
#line 5751 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1090:
#line 5752 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1091:
#line 5756 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1092:
#line 5757 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1093:
#line 5772 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1096:
#line 5781 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1097:
#line 5785 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1098:
#line 5789 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1099:
#line 5793 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1100:
#line 5797 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1102:
#line 5817 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1103:
#line 5822 "fgl.yacc"
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

  case 1104:
#line 5835 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1105:
#line 5836 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1106:
#line 5840 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1107:
#line 5845 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1108:
#line 5846 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1109:
#line 5850 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1113:
#line 5856 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1114:
#line 5859 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1116:
#line 5874 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1117:
#line 5878 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1118:
#line 5884 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1119:
#line 5885 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1120:
#line 5890 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1121:
#line 5891 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1122:
#line 5894 "fgl.yacc"
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

  case 1124:
#line 5921 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1125:
#line 5925 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1126:
#line 5929 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1127:
#line 5933 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("S",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1128:
#line 5937 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1129:
#line 5944 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1130:
#line 5945 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1136:
#line 5957 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1137:
#line 5963 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1138:
#line 5971 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1139:
#line 5977 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1140:
#line 5979 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1144:
#line 5989 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1145:
#line 5989 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1146:
#line 5994 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1147:
#line 5998 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1148:
#line 6003 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1149:
#line 6003 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1150:
#line 6007 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1151:
#line 6007 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1152:
#line 6008 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1153:
#line 6008 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1154:
#line 6009 "fgl.yacc"
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

  case 1155:
#line 6022 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1156:
#line 6023 "fgl.yacc"
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

  case 1157:
#line 6039 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1164:
#line 6051 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1165:
#line 6051 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1166:
#line 6057 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1167:
#line 6057 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1168:
#line 6060 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1169:
#line 6060 "fgl.yacc"
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

  case 1170:
#line 6076 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1171:
#line 6077 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1172:
#line 6078 "fgl.yacc"
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

  case 1173:
#line 6087 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1174:
#line 6099 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1180:
#line 6110 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1181:
#line 6115 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1182:
#line 6115 "fgl.yacc"
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

  case 1184:
#line 6139 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1185:
#line 6145 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1186:
#line 6150 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1187:
#line 6156 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1188:
#line 6157 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1189:
#line 6158 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1190:
#line 6162 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1191:
#line 6163 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1192:
#line 6164 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1193:
#line 6165 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1194:
#line 6169 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1195:
#line 6179 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1196:
#line 6181 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1197:
#line 6186 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1198:
#line 6189 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1199:
#line 6194 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1200:
#line 6201 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1201:
#line 6208 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1202:
#line 6215 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1203:
#line 6224 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1204:
#line 6231 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1205:
#line 6238 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1206:
#line 6245 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1207:
#line 6252 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1212:
#line 6265 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1213:
#line 6266 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1214:
#line 6267 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1215:
#line 6268 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1216:
#line 6269 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1217:
#line 6270 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1218:
#line 6271 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1219:
#line 6272 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1220:
#line 6273 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1221:
#line 6274 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1224:
#line 6280 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1225:
#line 6281 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1226:
#line 6282 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1227:
#line 6283 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1232:
#line 6292 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1233:
#line 6293 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1234:
#line 6294 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1235:
#line 6295 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1236:
#line 6296 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1237:
#line 6297 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1238:
#line 6298 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1239:
#line 6299 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1240:
#line 6301 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1241:
#line 6302 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1242:
#line 6303 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1243:
#line 6304 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1244:
#line 6306 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1245:
#line 6307 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1246:
#line 6308 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1247:
#line 6309 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1251:
#line 6314 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1252:
#line 6315 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1256:
#line 6322 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1257:
#line 6331 "fgl.yacc"
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

  case 1258:
#line 6340 "fgl.yacc"
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

  case 1259:
#line 6353 "fgl.yacc"
    { 
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1260:
#line 6364 "fgl.yacc"
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

  case 1261:
#line 6375 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1262:
#line 6379 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1263:
#line 6383 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1264:
#line 6389 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1265:
#line 6394 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1266:
#line 6402 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1267:
#line 6405 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1268:
#line 6414 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1269:
#line 6425 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1271:
#line 6432 "fgl.yacc"
    {
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1272:
#line 6442 "fgl.yacc"
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

  case 1273:
#line 6452 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1274:
#line 6455 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1275:
#line 6459 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1276:
#line 6467 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1277:
#line 6470 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1278:
#line 6476 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1279:
#line 6480 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1280:
#line 6484 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1281:
#line 6488 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1282:
#line 6492 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1283:
#line 6498 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1284:
#line 6499 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1285:
#line 6500 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1286:
#line 6501 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1287:
#line 6506 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1288:
#line 6507 "fgl.yacc"
    { print_system_run(yyvsp[0].integer_val,0); }
    break;

  case 1289:
#line 6508 "fgl.yacc"
    { print_system_run(1,yyvsp[0].str); }
    break;

  case 1290:
#line 6509 "fgl.yacc"
    { print_system_run(2,0); }
    break;

  case 1291:
#line 6510 "fgl.yacc"
    { print_system_run(1+yyvsp[-2].integer_val,yyvsp[0].str); }
    break;

  case 1292:
#line 6511 "fgl.yacc"
    { print_system_run(2+yyvsp[-1].integer_val,0); }
    break;

  case 1293:
#line 6512 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1294:
#line 6513 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1295:
#line 6517 "fgl.yacc"
    {yyval.integer_val=512;}
    break;

  case 1296:
#line 6518 "fgl.yacc"
    {yyval.integer_val=256;}
    break;

  case 1297:
#line 6521 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1298:
#line 6526 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1299:
#line 6533 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 6534 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1301:
#line 6535 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1302:
#line 6540 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1303:
#line 6541 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1304:
#line 6547 "fgl.yacc"
    {insql=1;}
    break;

  case 1305:
#line 6547 "fgl.yacc"
    {insql=0;}
    break;

  case 1306:
#line 6547 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1307:
#line 6552 "fgl.yacc"
    {insql=1;}
    break;

  case 1308:
#line 6552 "fgl.yacc"
    {insql=0;}
    break;

  case 1309:
#line 6552 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1310:
#line 6560 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1311:
#line 6561 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1313:
#line 6566 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1314:
#line 6571 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1315:
#line 6572 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1316:
#line 6573 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1317:
#line 6574 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1318:
#line 6575 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1320:
#line 6580 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1321:
#line 6580 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1323:
#line 6584 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1324:
#line 6588 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1325:
#line 6589 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1326:
#line 6592 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1327:
#line 6593 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1328:
#line 6596 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1329:
#line 6599 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1330:
#line 6602 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1331:
#line 6608 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1332:
#line 6610 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1334:
#line 6623 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1335:
#line 6627 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1336:
#line 6628 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1338:
#line 6633 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1339:
#line 6636 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1340:
#line 6642 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1341:
#line 6645 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1342:
#line 6653 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6660 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1345:
#line 6664 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1346:
#line 6668 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1347:
#line 6674 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1348:
#line 6677 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1349:
#line 6686 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1350:
#line 6689 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1351:
#line 6692 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1352:
#line 6695 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1353:
#line 6698 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1354:
#line 6701 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1355:
#line 6704 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1356:
#line 6711 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1357:
#line 6714 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1358:
#line 6721 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1359:
#line 6724 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1360:
#line 6730 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1361:
#line 6733 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1362:
#line 6740 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1363:
#line 6743 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1365:
#line 6751 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1367:
#line 6760 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1368:
#line 6763 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1369:
#line 6769 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1370:
#line 6772 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1371:
#line 6778 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1372:
#line 6785 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1373:
#line 6786 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1374:
#line 6790 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1375:
#line 6800 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1376:
#line 6803 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1377:
#line 6809 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1378:
#line 6811 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1379:
#line 6816 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1380:
#line 6817 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6822 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1382:
#line 6823 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1383:
#line 6829 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1384:
#line 6830 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6857 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1394:
#line 6863 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1395:
#line 6866 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1396:
#line 6869 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1397:
#line 6875 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1399:
#line 6881 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1401:
#line 6892 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1402:
#line 6906 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1403:
#line 6915 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1404:
#line 6915 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1405:
#line 6920 "fgl.yacc"
    {insql=1;}
    break;

  case 1406:
#line 6920 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1407:
#line 6925 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1408:
#line 6928 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1409:
#line 6930 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6937 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1412:
#line 6941 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1413:
#line 6945 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1414:
#line 6952 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1415:
#line 6955 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1416:
#line 6962 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1417:
#line 6966 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1418:
#line 6972 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1419:
#line 6977 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1420:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1421:
#line 6987 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1422:
#line 6990 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1423:
#line 6996 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1424:
#line 7003 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1425:
#line 7007 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1426:
#line 7012 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1427:
#line 7022 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1428:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1429:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1430:
#line 7029 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1431:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1432:
#line 7033 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1433:
#line 7035 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_RELATIVE);}
    break;

  case 1434:
#line 7037 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_ABSOLUTE);}
    break;

  case 1435:
#line 7043 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1436:
#line 7053 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1437:
#line 7060 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 7066 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 7069 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7076 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1446:
#line 7081 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1447:
#line 7086 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1448:
#line 7093 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1449:
#line 7094 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1450:
#line 7102 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1451:
#line 7113 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1452:
#line 7114 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1453:
#line 7115 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1454:
#line 7118 "fgl.yacc"
    {insql=1;}
    break;

  case 1455:
#line 7118 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1456:
#line 7123 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1457:
#line 7128 "fgl.yacc"
    {
			print_exec_sql(convstrsql(yyvsp[0].str));
			printf("Warning: Informix specific SQL @ line %d\n",yylineno);
			strcpy(yyval.str,"InfxSpecificSql");
	}
    break;

  case 1458:
#line 7133 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1460:
#line 7139 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1462:
#line 7143 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1463:
#line 7148 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1464:
#line 7153 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1465:
#line 7157 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1467:
#line 7163 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1468:
#line 7167 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1469:
#line 7174 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7175 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 7176 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1472:
#line 7177 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1476:
#line 7187 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1477:
#line 7188 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1478:
#line 7189 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 7193 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1480:
#line 7194 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1483:
#line 7201 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7204 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1487:
#line 7207 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1490:
#line 7212 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1491:
#line 7214 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7220 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 7226 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7236 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1499:
#line 7241 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1500:
#line 7243 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7249 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1503:
#line 7252 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1505:
#line 7258 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1506:
#line 7266 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 7271 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1510:
#line 7281 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7287 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1513:
#line 7292 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1514:
#line 7295 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1515:
#line 7300 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 7306 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7311 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1519:
#line 7314 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1520:
#line 7317 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1521:
#line 7324 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 7325 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1523:
#line 7326 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1524:
#line 7328 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1525:
#line 7341 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1526:
#line 7346 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1528:
#line 7350 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1529:
#line 7352 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1530:
#line 7359 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1531:
#line 7362 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1532:
#line 7368 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1533:
#line 7376 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1534:
#line 7380 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1535:
#line 7384 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1536:
#line 7388 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1537:
#line 7393 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1538:
#line 7396 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1539:
#line 7399 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1540:
#line 7407 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1541:
#line 7414 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1544:
#line 7423 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1545:
#line 7429 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1546:
#line 7432 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1547:
#line 7443 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1548:
#line 7450 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1549:
#line 7456 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1550:
#line 7459 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1551:
#line 7466 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1552:
#line 7473 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1554:
#line 7480 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1555:
#line 7486 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1556:
#line 7487 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1557:
#line 7488 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1559:
#line 7492 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1560:
#line 7499 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1562:
#line 7506 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1563:
#line 7513 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1564:
#line 7518 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1565:
#line 7519 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1566:
#line 7522 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1567:
#line 7525 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1568:
#line 7530 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1569:
#line 7531 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1570:
#line 7536 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1571:
#line 7539 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1572:
#line 7545 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1573:
#line 7548 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1574:
#line 7554 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1575:
#line 7557 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1576:
#line 7563 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1577:
#line 7566 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1578:
#line 7573 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1579:
#line 7574 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1580:
#line 7603 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1581:
#line 7604 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1582:
#line 7608 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1584:
#line 7621 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1585:
#line 7624 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1586:
#line 7627 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1587:
#line 7630 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1589:
#line 7638 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1590:
#line 7641 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1592:
#line 7647 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1594:
#line 7653 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1595:
#line 7656 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1596:
#line 7659 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1597:
#line 7662 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1598:
#line 7665 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1599:
#line 7668 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1600:
#line 7671 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1601:
#line 7674 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1602:
#line 7679 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1604:
#line 7686 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1608:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1609:
#line 7693 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1610:
#line 7698 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1611:
#line 7701 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1612:
#line 7705 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1613:
#line 7711 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1614:
#line 7712 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1615:
#line 7713 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1616:
#line 7714 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1621:
#line 7734 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1623:
#line 7738 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1624:
#line 7739 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1626:
#line 7742 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1627:
#line 7743 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1628:
#line 7752 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1635:
#line 7766 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1636:
#line 7768 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1637:
#line 7770 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1639:
#line 7773 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1641:
#line 7776 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1645:
#line 7781 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1646:
#line 7783 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1647:
#line 7786 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1648:
#line 7787 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1649:
#line 7794 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1653:
#line 7799 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1657:
#line 7815 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1658:
#line 7822 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1659:
#line 7826 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1660:
#line 7827 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1661:
#line 7828 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1662:
#line 7836 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1663:
#line 7837 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1664:
#line 7838 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1665:
#line 7849 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1666:
#line 7856 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1667:
#line 7861 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1668:
#line 7862 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1669:
#line 7863 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1670:
#line 7871 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1671:
#line 7872 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1672:
#line 7873 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1674:
#line 7899 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1675:
#line 7900 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1676:
#line 7901 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1677:
#line 7905 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1678:
#line 7908 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1679:
#line 7914 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1680:
#line 7919 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1681:
#line 7924 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1683:
#line 7935 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1687:
#line 7953 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1688:
#line 7956 "fgl.yacc"
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

  case 1689:
#line 7969 "fgl.yacc"
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

  case 1690:
#line 7984 "fgl.yacc"
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

  case 1691:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1692:
#line 7998 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1693:
#line 8001 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1694:
#line 8001 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1695:
#line 8001 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1696:
#line 8001 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1697:
#line 8001 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1698:
#line 8001 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1699:
#line 8002 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1700:
#line 8005 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1715:
#line 8023 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1716:
#line 8026 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1717:
#line 8027 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1718:
#line 8028 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1719:
#line 8032 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1720:
#line 8040 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1721:
#line 8040 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1722:
#line 8046 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1723:
#line 8046 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1724:
#line 8053 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1725:
#line 8053 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1726:
#line 8059 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1727:
#line 8059 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1728:
#line 8067 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1729:
#line 8068 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1730:
#line 8069 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1731:
#line 8072 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1732:
#line 8072 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1734:
#line 8076 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1735:
#line 8077 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1736:
#line 8088 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1737:
#line 8091 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1738:
#line 8097 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1739:
#line 8102 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1740:
#line 8110 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1741:
#line 8122 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1742:
#line 8123 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1743:
#line 8126 "fgl.yacc"
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

  case 1744:
#line 8141 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1745:
#line 8152 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1746:
#line 8155 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1747:
#line 8163 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1748:
#line 8172 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1749:
#line 8175 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1750:
#line 8179 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1751:
#line 8182 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1752:
#line 8183 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1754:
#line 8196 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1755:
#line 8197 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1756:
#line 8206 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1757:
#line 8215 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1758:
#line 8220 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1759:
#line 8221 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1760:
#line 8222 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1761:
#line 8223 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1762:
#line 8230 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1763:
#line 8233 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1764:
#line 8239 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1765:
#line 8242 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1766:
#line 8249 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1767:
#line 8261 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1768:
#line 8270 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1769:
#line 8273 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1770:
#line 8276 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1771:
#line 8282 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1772:
#line 8290 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1773:
#line 8293 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1774:
#line 8294 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1775:
#line 8295 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1776:
#line 8296 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1777:
#line 8297 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1778:
#line 8300 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1779:
#line 8307 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1780:
#line 8309 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1781:
#line 8311 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1782:
#line 8313 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1783:
#line 8315 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1784:
#line 8316 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1785:
#line 8317 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1786:
#line 8318 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1787:
#line 8319 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1788:
#line 8320 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1789:
#line 8321 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1790:
#line 8323 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1791:
#line 8325 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1792:
#line 8327 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1793:
#line 8329 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1794:
#line 8331 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1795:
#line 8333 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1796:
#line 8335 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1797:
#line 8336 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1798:
#line 8338 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1799:
#line 8339 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1800:
#line 8340 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1801:
#line 8346 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1802:
#line 8347 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1804:
#line 8357 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1805:
#line 8365 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1806:
#line 8369 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1807:
#line 8376 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1808:
#line 8376 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1810:
#line 8380 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1811:
#line 8385 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1812:
#line 8385 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1814:
#line 8389 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1815:
#line 8393 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1818:
#line 8402 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1819:
#line 8402 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1824:
#line 8421 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1825:
#line 8422 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1828:
#line 8430 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1829:
#line 8436 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1832:
#line 8455 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1833:
#line 8456 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1834:
#line 8457 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1835:
#line 8458 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1836:
#line 8459 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1837:
#line 8460 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1838:
#line 8464 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1839:
#line 8465 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1840:
#line 8466 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1842:
#line 8471 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1843:
#line 8472 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1844:
#line 8476 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1845:
#line 8492 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1846:
#line 8493 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1847:
#line 8494 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1848:
#line 8498 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1849:
#line 8512 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1850:
#line 8516 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1852:
#line 8525 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1854:
#line 8530 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1855:
#line 8531 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1856:
#line 8855 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1857:
#line 8855 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1858:
#line 8862 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1859:
#line 8862 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1860:
#line 8950 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1861:
#line 8954 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1862:
#line 8956 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1863:
#line 8963 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1864:
#line 8967 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1865:
#line 8973 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1866:
#line 8981 "fgl.yacc"
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

  case 1867:
#line 8991 "fgl.yacc"
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

  case 1868:
#line 9001 "fgl.yacc"
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

  case 1869:
#line 9013 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1870:
#line 9016 "fgl.yacc"
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

  case 1871:
#line 9035 "fgl.yacc"
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

  case 1872:
#line 9061 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1873:
#line 9064 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1875:
#line 9073 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1876:
#line 9078 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1877:
#line 9081 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1878:
#line 9089 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1879:
#line 9097 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1880:
#line 9110 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1881:
#line 9113 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1882:
#line 9121 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1883:
#line 9124 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1884:
#line 9127 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1885:
#line 9135 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1886:
#line 9139 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1887:
#line 9140 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1888:
#line 9141 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1889:
#line 9142 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1890:
#line 9143 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1891:
#line 9144 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1892:
#line 9145 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1893:
#line 9146 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1894:
#line 9150 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1895:
#line 9151 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1896:
#line 9152 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1897:
#line 9153 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1898:
#line 9154 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1899:
#line 9160 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1900:
#line 9161 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1901:
#line 9162 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1902:
#line 9163 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1903:
#line 9164 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1904:
#line 9165 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1905:
#line 9166 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1906:
#line 9167 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1907:
#line 9168 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1908:
#line 9169 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1909:
#line 9170 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1910:
#line 9171 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1911:
#line 9172 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1912:
#line 9173 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1913:
#line 9174 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1914:
#line 9175 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1915:
#line 9180 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1916:
#line 9186 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1917:
#line 9187 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1918:
#line 9195 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1919:
#line 9197 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1921:
#line 9203 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1922:
#line 9207 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1923:
#line 9211 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1924:
#line 9227 "fgl.yacc"
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

  case 1925:
#line 9241 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1926:
#line 9247 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1927:
#line 9249 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1931:
#line 9263 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1932:
#line 9266 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1933:
#line 9273 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1934:
#line 9276 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1935:
#line 9306 "fgl.yacc"
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

  case 1936:
#line 9331 "fgl.yacc"
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

  case 1937:
#line 9386 "fgl.yacc"
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

  case 1938:
#line 9421 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1939:
#line 9430 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1940:
#line 9441 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1941:
#line 9444 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1942:
#line 9450 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1943:
#line 9463 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1944:
#line 9477 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1945:
#line 9480 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1946:
#line 9484 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1947:
#line 9499 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1948:
#line 9499 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1949:
#line 9505 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1950:
#line 9506 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1951:
#line 9509 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1952:
#line 9510 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1953:
#line 9511 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1954:
#line 9512 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1955:
#line 9513 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1956:
#line 9514 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1957:
#line 9515 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1958:
#line 9526 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1959:
#line 9530 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1960:
#line 9534 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1961:
#line 9538 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1962:
#line 9543 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1963:
#line 9547 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1964:
#line 9552 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1966:
#line 9560 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1968:
#line 9566 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1969:
#line 9572 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1970:
#line 9576 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1975:
#line 9594 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1976:
#line 9601 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1977:
#line 9611 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1978:
#line 9611 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19053 "y.tab.c"

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



