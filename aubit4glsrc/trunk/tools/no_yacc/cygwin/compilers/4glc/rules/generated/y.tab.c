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
     NAME = 1718,
     UMINUS = 1719,
     COMMA = 1620,
     KW_OR = 1660,
     KW_AND = 1615,
     KW_USING = 1552,
     NOT = 1635,
     MATCHES = 1433,
     POWER = 1538,
     LESS_THAN = 1534,
     GREATER_THAN = 1450,
     EQUAL = 1610,
     GREATER_THAN_EQ = 1352,
     LESS_THAN_EQ = 1409,
     NOT_EQUAL = 1481,
     PLUS = 1646,
     MINUS = 1633,
     MULTIPLY = 1539,
     DIVIDE = 1566,
     MOD = 1634,
     COMMAND = 1416,
     NUMBER_VALUE = 1720,
     CHAR_VALUE = 1721,
     INT_VALUE = 1722,
     NAMED_GEN = 1723,
     CLINE = 1724,
     SQLLINE = 1725,
     KW_CSTART = 1726,
     KW_CEND = 1727,
     USER_DTYPE = 1728,
     SQL_TEXT = 1729,
     KW_WHENEVER_SET = 1730,
     COMMENT = 1731,
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
     TO_PRINTER = 1110,
     STATUSBOX = 1111,
     FORMHANDLER_INPUT = 1112,
     UNITS_YEAR = 1113,
     UNITS_MONTH = 1114,
     UNITS_DAY = 1115,
     UNITS_HOUR = 1116,
     UNITS_MINUTE = 1117,
     UNITS_SECOND = 1118,
     NO_NEW_LINES = 1119,
     FIELDTOWIDGET = 1120,
     WITH_HOLD = 1121,
     SHOW_MENU = 1122,
     TO_CLUSTER = 1123,
     TO_NOT_CLUSTER = 1124,
     CWIS = 1125,
     CREATE_IDX = 1126,
     FORM_IS_COMPILED = 1127,
     PDF_REPORT = 1128,
     IMPORT_FUNCTION = 1129,
     PROMPT_MANY = 1130,
     POINTS = 1131,
     MM = 1132,
     INCHES = 1133,
     PREPEND = 1134,
     MEMBER_OF = 1135,
     APPEND = 1136,
     TEMPLATE = 1137,
     END_TEMPLATE = 1138,
     SQLSICS = 1139,
     CREATE_SCHEMA = 1140,
     SQLSIRR = 1141,
     UPDATESTATS_T = 1142,
     SQLSICR = 1143,
     WHENEVER_SQLSUCCESS = 1144,
     WHENEVER_SQLWARNING = 1145,
     WHENEVER_ANY_ERROR = 1146,
     WHENEVER_NOT_FOUND = 1147,
     WHENEVER_SQLERROR = 1148,
     WHENEVER_SUCCESS = 1149,
     WHENEVER_ERROR = 1150,
     START_EXTERN = 1151,
     CONTINUE_CONSTRUCT = 1152,
     FOUNCONSTR = 1153,
     SQLSIDR = 1154,
     CREATE_TEMP_TABLE = 1155,
     CURRENT_WINDOW_IS = 1156,
     FIRST_PAGE_HEADER = 1157,
     ORDER_EXTERNAL_BY = 1158,
     SCROLL_CURSOR_FOR = 1159,
     SCROLL_CURSOR = 1160,
     SQL_INTERRUPT_OFF = 1161,
     STOP_ALL_EXTERNAL = 1162,
     WITH_CHECK_OPTION = 1163,
     WITH_GRANT_OPTION = 1164,
     SQLSLMNW = 1165,
     ADDCONSTUNIQ = 1166,
     CONTINUE_DISPLAY = 1167,
     CONTINUE_FOREACH = 1168,
     OUTPUT_TO_REPORT = 1169,
     SQL_INTERRUPT_ON = 1170,
     WHERE_CURRENT_OF = 1171,
     WITHOUT_DEFAULTS = 1172,
     FOCONSTR = 1173,
     SCALED_BY = 1174,
     CONTINUE_PROMPT = 1175,
     PDF_FUNCTION = 1176,
     DEFER_INTERRUPT = 1177,
     DISPLAY_BY_NAME = 1178,
     NOT_NULL_UNIQUE = 1179,
     SKIP_TO_TOP = 1180,
     TOP_OF_PAGE = 1181,
     SKIP_TO = 1182,
     SKIP_BY = 1183,
     WITHOUT_WAITING = 1184,
     BEFCONSTRUCT = 1185,
     SQLSLMW = 1186,
     AFTCONSTRUCT = 1187,
     ALL_PRIVILEGES = 1188,
     CLOSE_DATABASE = 1189,
     CONTINUE_INPUT = 1190,
     CONTINUE_WHILE = 1191,
     CREATE_SYNONYM = 1192,
     DROP_TABLE = 1193,
     EXIT_CONSTRUCT = 1194,
     INEXCLUSIVE = 1195,
     REPORT_TO_PRINTER = 1196,
     REPORT_TO_PIPE = 1197,
     RETURN = 1198,
     SET_SESSION_TO = 1199,
     UPDATESTATS = 1200,
     WITHOUT_HEAD = 1201,
     CLEARSCR = 1202,
     WITH_B_LOG = 1203,
     AUTHORIZATION = 1204,
     BOTTOM_MARGIN = 1205,
     CLOSE_SESSION = 1206,
     CONTINUE_CASE = 1207,
     CONTINUE_MENU = 1208,
     DISPLAY_ARRAY = 1209,
     END_SQL = 1210,
     DOLLAR = 1211,
     END_CONSTRUCT = 1212,
     FIELD_TOUCHED = 1213,
     FINISH_REPORT = 1214,
     INFACC = 1215,
     INPUT_NO_WRAP = 1216,
     SETPMOFF = 1217,
     UNCONSTRAINED = 1218,
     PAGE_TRAILER = 1219,
     SETPMON = 1220,
     BEFGROUP = 1221,
     CLOSE_WINDOW = 1222,
     COMMENT_LINE = 1223,
     CONTINUE_FOR = 1224,
     CREATE_DB = 1225,
     CREATE_TABLE = 1226,
     DEFAULT_NULL = 1227,
     DEFAULT_TODAY = 1228,
     DEFAULT_USER = 1229,
     DELETE_USING = 1230,
     DISPLAY_FORM = 1231,
     END_FUNCTION = 1232,
     EXIT_DISPLAY = 1233,
     EXIT_FOREACH = 1234,
     EXIT_PROGRAM = 1235,
     INFCOLS = 1236,
     ON_EVERY_ROW = 1237,
     OPEN_SESSION = 1238,
     RIGHT_MARGIN = 1239,
     SELECT_USING = 1240,
     START_REPORT = 1241,
     UNLOCK_TABLE = 1242,
     UPDATE_USING = 1243,
     ACL_BUILTIN = 1244,
     AFTGROUP = 1245,
     INFIDX = 1246,
     INFSTAT = 1247,
     LEFT_MARGIN = 1248,
     PAGE_HEADER = 1249,
     ROLLBACK_W = 1250,
     SET_SESSION = 1251,
     SQLSEOFF = 1252,
     WITH_A_LOG = 1253,
     BEFDISP = 1254,
     BEFORE_MENU = 1255,
     CREATE_VIEW = 1256,
     DEFINE_TYPE = 1257,
     DELETE_FROM = 1258,
     END_DISPLAY = 1259,
     END_REPORT = 1260,
     END_FOREACH = 1261,
     END_FOR = 1262,
     END_GLOBALS = 1263,
     EXIT_PROMPT = 1264,
     EXTENT_SIZE = 1265,
     FOREIGN_KEY = 1266,
     HIDE_OPTION = 1267,
     HIDE_WINDOW = 1268,
     INSERT_INTO = 1269,
     IS_NOT_NULL = 1270,
     MOVE_WINDOW = 1271,
     NEXT_OPTION = 1272,
     NOT_MATCHES = 1273,
     ON_LAST_ROW = 1274,
     OPEN_WINDOW = 1275,
     OPEN_STATUSBOX = 1276,
     PAGE_LENGTH = 1277,
     PAGE_WIDTH = 1278,
     PRIMARY_KEY = 1279,
     PROMPT_LINE = 1280,
     RECORD_LIKE = 1281,
     ROLLFORWARD = 1282,
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
     SHARED = 1497,
     SPACES = 1498,
     UNIQUE = 1499,
     UNLOCK = 1500,
     UPDATE = 1501,
     VALUES = 1502,
     YELLOW = 1503,
     AFTER = 1504,
     KWLINE = 1505,
     KW_NULL = 1506,
     KW_TRUE = 1507,
     SINGLE_KEY = 1508,
     ALTER = 1509,
     ARRAY = 1510,
     ASCII = 1511,
     AUDIT = 1512,
     BLACK = 1513,
     BLINK = 1514,
     CHECK = 1515,
     CLEAR = 1516,
     CLOSE = 1517,
     CODE_C = 1518,
     COUNT = 1519,
     DEFER = 1520,
     ERROR = 1521,
     EVERY = 1522,
     FETCH = 1523,
     FIRST = 1524,
     FLOAT = 1525,
     FLUSH = 1526,
     FOUND = 1527,
     GRANT = 1528,
     GREEN = 1529,
     GROUP = 1530,
     INDEX = 1531,
     KWFORM = 1532,
     LABEL = 1533,
     LOCAL = 1535,
     MONEY = 1536,
     MONTH = 1537,
     ORDER = 1540,
     OUTER = 1541,
     PAUSE = 1542,
     PRINT_IMAGE = 1543,
     PRINT_FILE = 1544,
     PRINT = 1545,
     RIGHT = 1546,
     DOUBLE_COLON = 1547,
     SEMICOLON = 1548,
     SLEEP = 1549,
     TUPLE = 1550,
     UNION = 1551,
     WHERE = 1553,
     WHILE = 1554,
     WHITE = 1555,
     CCODE = 1556,
     ANSI = 1557,
     BLUE = 1558,
     BOLD = 1559,
     BYTE = 1560,
     FCALL = 1561,
     CASE = 1562,
     CYAN = 1563,
     DATE = 1564,
     DESC = 1565,
     KWDOWN = 1567,
     TAB = 1568,
     DROP = 1569,
     ELSE = 1570,
     EXEC = 1571,
     EXIT = 1572,
     FREE = 1573,
     FROM = 1574,
     GOTO = 1575,
     HELP_FILE = 1576,
     LANG_FILE = 1577,
     HELP = 1578,
     HIDE = 1579,
     HOUR = 1580,
     INTO = 1581,
     LAST = 1582,
     LEFT = 1583,
     LIKE = 1584,
     MAIN = 1585,
     MENU = 1586,
     MODE = 1587,
     NEED = 1588,
     NEXT = 1589,
     NOCR = 1590,
     OPEN = 1591,
     QUIT = 1592,
     REAL = 1593,
     ROWS = 1594,
     SHOW = 1595,
     SIZE = 1596,
     SKIP = 1597,
     SOME = 1598,
     STEP = 1599,
     STOP = 1600,
     TEMP = 1601,
     TEXT = 1602,
     THEN = 1603,
     USER = 1604,
     WAIT = 1605,
     WHEN = 1606,
     WITH = 1607,
     WORK = 1608,
     YEAR = 1609,
     KW_IS = 1611,
     XSET = 1612,
     ADD = 1613,
     ALL = 1614,
     ANY = 1616,
     ASC = 1617,
     AVG = 1618,
     COLON = 1619,
     DAY = 1621,
     DBA = 1622,
     DEC = 1623,
     DIM = 1624,
     FKEY = 1625,
     FOR = 1626,
     KEY = 1627,
     KWNO = 1628,
     LET = 1629,
     LOG = 1630,
     XMAX = 1631,
     XMIN = 1632,
     PAD = 1636,
     PUT = 1637,
     RED = 1638,
     ROW = 1639,
     RUN = 1640,
     SQL = 1641,
     SUM = 1642,
     TOP = 1643,
     USE = 1644,
     ATSIGN = 1645,
     AS_TIFF = 1647,
     AS_GIF = 1648,
     AS_PNG = 1649,
     AS_JPEG = 1650,
     AS = 1651,
     AT = 1652,
     BY = 1653,
     DOT = 1654,
     GO = 1655,
     IF = 1656,
     IN = 1657,
     OF = 1658,
     ON = 1659,
     TO = 1661,
     KWUP = 1662,
     FONT_NAME = 1663,
     FONT_SIZE = 1664,
     PAPER_SIZE_IS_LETTER = 1665,
     PAPER_SIZE_IS_LEGAL = 1666,
     PAPER_SIZE_IS_A5 = 1667,
     PAPER_SIZE_IS_A4 = 1668,
     PAPER_SIZE_IS_LETTER_L = 1669,
     PAPER_SIZE_IS_LEGAL_L = 1670,
     PAPER_SIZE_IS_A5_L = 1671,
     PAPER_SIZE_IS_A4_L = 1672,
     FORMHANDLER = 1673,
     END_FORMHANDLER = 1674,
     BEFORE_EVENT = 1675,
     BEFORE_OPEN_FORM = 1676,
     AFTER_EVENT = 1677,
     BEFORE_CLOSE_FORM = 1678,
     BEFORE_ANY = 1679,
     AFTER_ANY = 1680,
     MENUHANDLER = 1681,
     END_MENUHANDLER = 1682,
     BEFORE_SHOW_MENU = 1683,
     DISABLE_PROGRAM = 1684,
     DISABLE_ALL = 1685,
     BUTTONS = 1686,
     CHECK_MENUITEM = 1687,
     DISABLE_FORM = 1688,
     DISABLE_MENUITEMS = 1689,
     DISABLE = 1690,
     ENABLE_FORM = 1691,
     ENABLE_MENUITEMS = 1692,
     ENABLE = 1693,
     KWFIELD = 1694,
     ICON = 1695,
     MESSAGEBOX = 1696,
     TO_DEFAULTS = 1697,
     UNCHECK_MENUITEM = 1698,
     BEFORE = 1699,
     INPUT = 1700,
     END = 1701,
     INT_TO_ID = 1702,
     TIMEOUT = 1703,
     OFF = 1704,
     WITH_1_DIMENSION = 1705,
     WITH_2_DIMENSION = 1706,
     WITH_3_DIMENSION = 1707,
     TILDE = 1708,
     ILIKE = 1709,
     FGL_ISDYNARR_ALLOCATED = 1710,
     FGL_DYNARR_EXTENTSIZE = 1711,
     FILLFACTOR = 1712,
     END_CLASS = 1713,
     KW_CLASS = 1714,
     EXTENDS = 1715,
     PIPE = 1716
   };
#endif
#define NAME 1718
#define UMINUS 1719
#define COMMA 1620
#define KW_OR 1660
#define KW_AND 1615
#define KW_USING 1552
#define NOT 1635
#define MATCHES 1433
#define POWER 1538
#define LESS_THAN 1534
#define GREATER_THAN 1450
#define EQUAL 1610
#define GREATER_THAN_EQ 1352
#define LESS_THAN_EQ 1409
#define NOT_EQUAL 1481
#define PLUS 1646
#define MINUS 1633
#define MULTIPLY 1539
#define DIVIDE 1566
#define MOD 1634
#define COMMAND 1416
#define NUMBER_VALUE 1720
#define CHAR_VALUE 1721
#define INT_VALUE 1722
#define NAMED_GEN 1723
#define CLINE 1724
#define SQLLINE 1725
#define KW_CSTART 1726
#define KW_CEND 1727
#define USER_DTYPE 1728
#define SQL_TEXT 1729
#define KW_WHENEVER_SET 1730
#define COMMENT 1731
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
#define TO_PRINTER 1110
#define STATUSBOX 1111
#define FORMHANDLER_INPUT 1112
#define UNITS_YEAR 1113
#define UNITS_MONTH 1114
#define UNITS_DAY 1115
#define UNITS_HOUR 1116
#define UNITS_MINUTE 1117
#define UNITS_SECOND 1118
#define NO_NEW_LINES 1119
#define FIELDTOWIDGET 1120
#define WITH_HOLD 1121
#define SHOW_MENU 1122
#define TO_CLUSTER 1123
#define TO_NOT_CLUSTER 1124
#define CWIS 1125
#define CREATE_IDX 1126
#define FORM_IS_COMPILED 1127
#define PDF_REPORT 1128
#define IMPORT_FUNCTION 1129
#define PROMPT_MANY 1130
#define POINTS 1131
#define MM 1132
#define INCHES 1133
#define PREPEND 1134
#define MEMBER_OF 1135
#define APPEND 1136
#define TEMPLATE 1137
#define END_TEMPLATE 1138
#define SQLSICS 1139
#define CREATE_SCHEMA 1140
#define SQLSIRR 1141
#define UPDATESTATS_T 1142
#define SQLSICR 1143
#define WHENEVER_SQLSUCCESS 1144
#define WHENEVER_SQLWARNING 1145
#define WHENEVER_ANY_ERROR 1146
#define WHENEVER_NOT_FOUND 1147
#define WHENEVER_SQLERROR 1148
#define WHENEVER_SUCCESS 1149
#define WHENEVER_ERROR 1150
#define START_EXTERN 1151
#define CONTINUE_CONSTRUCT 1152
#define FOUNCONSTR 1153
#define SQLSIDR 1154
#define CREATE_TEMP_TABLE 1155
#define CURRENT_WINDOW_IS 1156
#define FIRST_PAGE_HEADER 1157
#define ORDER_EXTERNAL_BY 1158
#define SCROLL_CURSOR_FOR 1159
#define SCROLL_CURSOR 1160
#define SQL_INTERRUPT_OFF 1161
#define STOP_ALL_EXTERNAL 1162
#define WITH_CHECK_OPTION 1163
#define WITH_GRANT_OPTION 1164
#define SQLSLMNW 1165
#define ADDCONSTUNIQ 1166
#define CONTINUE_DISPLAY 1167
#define CONTINUE_FOREACH 1168
#define OUTPUT_TO_REPORT 1169
#define SQL_INTERRUPT_ON 1170
#define WHERE_CURRENT_OF 1171
#define WITHOUT_DEFAULTS 1172
#define FOCONSTR 1173
#define SCALED_BY 1174
#define CONTINUE_PROMPT 1175
#define PDF_FUNCTION 1176
#define DEFER_INTERRUPT 1177
#define DISPLAY_BY_NAME 1178
#define NOT_NULL_UNIQUE 1179
#define SKIP_TO_TOP 1180
#define TOP_OF_PAGE 1181
#define SKIP_TO 1182
#define SKIP_BY 1183
#define WITHOUT_WAITING 1184
#define BEFCONSTRUCT 1185
#define SQLSLMW 1186
#define AFTCONSTRUCT 1187
#define ALL_PRIVILEGES 1188
#define CLOSE_DATABASE 1189
#define CONTINUE_INPUT 1190
#define CONTINUE_WHILE 1191
#define CREATE_SYNONYM 1192
#define DROP_TABLE 1193
#define EXIT_CONSTRUCT 1194
#define INEXCLUSIVE 1195
#define REPORT_TO_PRINTER 1196
#define REPORT_TO_PIPE 1197
#define RETURN 1198
#define SET_SESSION_TO 1199
#define UPDATESTATS 1200
#define WITHOUT_HEAD 1201
#define CLEARSCR 1202
#define WITH_B_LOG 1203
#define AUTHORIZATION 1204
#define BOTTOM_MARGIN 1205
#define CLOSE_SESSION 1206
#define CONTINUE_CASE 1207
#define CONTINUE_MENU 1208
#define DISPLAY_ARRAY 1209
#define END_SQL 1210
#define DOLLAR 1211
#define END_CONSTRUCT 1212
#define FIELD_TOUCHED 1213
#define FINISH_REPORT 1214
#define INFACC 1215
#define INPUT_NO_WRAP 1216
#define SETPMOFF 1217
#define UNCONSTRAINED 1218
#define PAGE_TRAILER 1219
#define SETPMON 1220
#define BEFGROUP 1221
#define CLOSE_WINDOW 1222
#define COMMENT_LINE 1223
#define CONTINUE_FOR 1224
#define CREATE_DB 1225
#define CREATE_TABLE 1226
#define DEFAULT_NULL 1227
#define DEFAULT_TODAY 1228
#define DEFAULT_USER 1229
#define DELETE_USING 1230
#define DISPLAY_FORM 1231
#define END_FUNCTION 1232
#define EXIT_DISPLAY 1233
#define EXIT_FOREACH 1234
#define EXIT_PROGRAM 1235
#define INFCOLS 1236
#define ON_EVERY_ROW 1237
#define OPEN_SESSION 1238
#define RIGHT_MARGIN 1239
#define SELECT_USING 1240
#define START_REPORT 1241
#define UNLOCK_TABLE 1242
#define UPDATE_USING 1243
#define ACL_BUILTIN 1244
#define AFTGROUP 1245
#define INFIDX 1246
#define INFSTAT 1247
#define LEFT_MARGIN 1248
#define PAGE_HEADER 1249
#define ROLLBACK_W 1250
#define SET_SESSION 1251
#define SQLSEOFF 1252
#define WITH_A_LOG 1253
#define BEFDISP 1254
#define BEFORE_MENU 1255
#define CREATE_VIEW 1256
#define DEFINE_TYPE 1257
#define DELETE_FROM 1258
#define END_DISPLAY 1259
#define END_REPORT 1260
#define END_FOREACH 1261
#define END_FOR 1262
#define END_GLOBALS 1263
#define EXIT_PROMPT 1264
#define EXTENT_SIZE 1265
#define FOREIGN_KEY 1266
#define HIDE_OPTION 1267
#define HIDE_WINDOW 1268
#define INSERT_INTO 1269
#define IS_NOT_NULL 1270
#define MOVE_WINDOW 1271
#define NEXT_OPTION 1272
#define NOT_MATCHES 1273
#define ON_LAST_ROW 1274
#define OPEN_WINDOW 1275
#define OPEN_STATUSBOX 1276
#define PAGE_LENGTH 1277
#define PAGE_WIDTH 1278
#define PRIMARY_KEY 1279
#define PROMPT_LINE 1280
#define RECORD_LIKE 1281
#define ROLLFORWARD 1282
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
#define SHARED 1497
#define SPACES 1498
#define UNIQUE 1499
#define UNLOCK 1500
#define UPDATE 1501
#define VALUES 1502
#define YELLOW 1503
#define AFTER 1504
#define KWLINE 1505
#define KW_NULL 1506
#define KW_TRUE 1507
#define SINGLE_KEY 1508
#define ALTER 1509
#define ARRAY 1510
#define ASCII 1511
#define AUDIT 1512
#define BLACK 1513
#define BLINK 1514
#define CHECK 1515
#define CLEAR 1516
#define CLOSE 1517
#define CODE_C 1518
#define COUNT 1519
#define DEFER 1520
#define ERROR 1521
#define EVERY 1522
#define FETCH 1523
#define FIRST 1524
#define FLOAT 1525
#define FLUSH 1526
#define FOUND 1527
#define GRANT 1528
#define GREEN 1529
#define GROUP 1530
#define INDEX 1531
#define KWFORM 1532
#define LABEL 1533
#define LOCAL 1535
#define MONEY 1536
#define MONTH 1537
#define ORDER 1540
#define OUTER 1541
#define PAUSE 1542
#define PRINT_IMAGE 1543
#define PRINT_FILE 1544
#define PRINT 1545
#define RIGHT 1546
#define DOUBLE_COLON 1547
#define SEMICOLON 1548
#define SLEEP 1549
#define TUPLE 1550
#define UNION 1551
#define WHERE 1553
#define WHILE 1554
#define WHITE 1555
#define CCODE 1556
#define ANSI 1557
#define BLUE 1558
#define BOLD 1559
#define BYTE 1560
#define FCALL 1561
#define CASE 1562
#define CYAN 1563
#define DATE 1564
#define DESC 1565
#define KWDOWN 1567
#define TAB 1568
#define DROP 1569
#define ELSE 1570
#define EXEC 1571
#define EXIT 1572
#define FREE 1573
#define FROM 1574
#define GOTO 1575
#define HELP_FILE 1576
#define LANG_FILE 1577
#define HELP 1578
#define HIDE 1579
#define HOUR 1580
#define INTO 1581
#define LAST 1582
#define LEFT 1583
#define LIKE 1584
#define MAIN 1585
#define MENU 1586
#define MODE 1587
#define NEED 1588
#define NEXT 1589
#define NOCR 1590
#define OPEN 1591
#define QUIT 1592
#define REAL 1593
#define ROWS 1594
#define SHOW 1595
#define SIZE 1596
#define SKIP 1597
#define SOME 1598
#define STEP 1599
#define STOP 1600
#define TEMP 1601
#define TEXT 1602
#define THEN 1603
#define USER 1604
#define WAIT 1605
#define WHEN 1606
#define WITH 1607
#define WORK 1608
#define YEAR 1609
#define KW_IS 1611
#define XSET 1612
#define ADD 1613
#define ALL 1614
#define ANY 1616
#define ASC 1617
#define AVG 1618
#define COLON 1619
#define DAY 1621
#define DBA 1622
#define DEC 1623
#define DIM 1624
#define FKEY 1625
#define FOR 1626
#define KEY 1627
#define KWNO 1628
#define LET 1629
#define LOG 1630
#define XMAX 1631
#define XMIN 1632
#define PAD 1636
#define PUT 1637
#define RED 1638
#define ROW 1639
#define RUN 1640
#define SQL 1641
#define SUM 1642
#define TOP 1643
#define USE 1644
#define ATSIGN 1645
#define AS_TIFF 1647
#define AS_GIF 1648
#define AS_PNG 1649
#define AS_JPEG 1650
#define AS 1651
#define AT 1652
#define BY 1653
#define DOT 1654
#define GO 1655
#define IF 1656
#define IN 1657
#define OF 1658
#define ON 1659
#define TO 1661
#define KWUP 1662
#define FONT_NAME 1663
#define FONT_SIZE 1664
#define PAPER_SIZE_IS_LETTER 1665
#define PAPER_SIZE_IS_LEGAL 1666
#define PAPER_SIZE_IS_A5 1667
#define PAPER_SIZE_IS_A4 1668
#define PAPER_SIZE_IS_LETTER_L 1669
#define PAPER_SIZE_IS_LEGAL_L 1670
#define PAPER_SIZE_IS_A5_L 1671
#define PAPER_SIZE_IS_A4_L 1672
#define FORMHANDLER 1673
#define END_FORMHANDLER 1674
#define BEFORE_EVENT 1675
#define BEFORE_OPEN_FORM 1676
#define AFTER_EVENT 1677
#define BEFORE_CLOSE_FORM 1678
#define BEFORE_ANY 1679
#define AFTER_ANY 1680
#define MENUHANDLER 1681
#define END_MENUHANDLER 1682
#define BEFORE_SHOW_MENU 1683
#define DISABLE_PROGRAM 1684
#define DISABLE_ALL 1685
#define BUTTONS 1686
#define CHECK_MENUITEM 1687
#define DISABLE_FORM 1688
#define DISABLE_MENUITEMS 1689
#define DISABLE 1690
#define ENABLE_FORM 1691
#define ENABLE_MENUITEMS 1692
#define ENABLE 1693
#define KWFIELD 1694
#define ICON 1695
#define MESSAGEBOX 1696
#define TO_DEFAULTS 1697
#define UNCHECK_MENUITEM 1698
#define BEFORE 1699
#define INPUT 1700
#define END 1701
#define INT_TO_ID 1702
#define TIMEOUT 1703
#define OFF 1704
#define WITH_1_DIMENSION 1705
#define WITH_2_DIMENSION 1706
#define WITH_3_DIMENSION 1707
#define TILDE 1708
#define ILIKE 1709
#define FGL_ISDYNARR_ALLOCATED 1710
#define FGL_DYNARR_EXTENTSIZE 1711
#define FILLFACTOR 1712
#define END_CLASS 1713
#define KW_CLASS 1714
#define EXTENDS 1715
#define PIPE 1716




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
#line 1724 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1736 "y.tab.c"

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
#define YYLAST   9528

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  734
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  876
/* YYNRULES -- Number of rules. */
#define YYNRULES  2065
/* YYNRULES -- Number of states. */
#define YYNSTATES  3504

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1731

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
     560,   561,   562,   563,    12,   564,   565,   566,    11,    20,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,     8,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,    21,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
      14,   635,   636,   637,   638,     7,   639,   640,   641,   642,
       5,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,    19,    22,     9,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   664,    18,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
       6,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,     2,     3,     4,
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
    3412,  3414,  3418,  3420,  3422,  3427,  3433,  3439,  3443,  3444,
    3446,  3448,  3450,  3452,  3453,  3455,  3463,  3466,  3469,  3472,
    3475,  3478,  3480,  3483,  3484,  3488,  3489,  3493,  3494,  3498,
    3499,  3503,  3504,  3508,  3509,  3514,  3515,  3520,  3522,  3524,
    3526,  3528,  3530,  3532,  3533,  3538,  3539,  3541,  3542,  3547,
    3549,  3552,  3555,  3558,  3559,  3561,  3563,  3566,  3569,  3570,
    3573,  3574,  3579,  3581,  3585,  3589,  3595,  3596,  3599,  3604,
    3606,  3608,  3610,  3612,  3614,  3615,  3617,  3619,  3623,  3626,
    3632,  3635,  3641,  3647,  3653,  3659,  3665,  3671,  3672,  3675,
    3677,  3680,  3683,  3686,  3689,  3692,  3695,  3697,  3700,  3703,
    3706,  3709,  3711,  3714,  3717,  3720,  3723,  3725,  3727,  3729,
    3730,  3733,  3736,  3739,  3742,  3745,  3748,  3751,  3754,  3757,
    3759,  3761,  3763,  3765,  3767,  3769,  3771,  3773,  3776,  3779,
    3782,  3785,  3788,  3790,  3792,  3794,  3795,  3799,  3802,  3803,
    3804,  3805,  3806,  3807,  3808,  3824,  3825,  3828,  3831,  3832,
    3834,  3835,  3836,  3837,  3838,  3839,  3840,  3856,  3859,  3860,
    3861,  3862,  3873,  3874,  3876,  3880,  3884,  3887,  3891,  3896,
    3900,  3906,  3911,  3915,  3919,  3921,  3923,  3925,  3928,  3931,
    3934,  3937,  3939,  3941,  3942,  3943,  3952,  3953,  3954,  3964,
    3965,  3967,  3969,  3972,  3975,  3978,  3981,  3983,  3985,  3987,
    3988,  3990,  3992,  3995,  3998,  4001,  4010,  4013,  4016,  4021,
    4024,  4025,  4027,  4029,  4033,  4036,  4039,  4041,  4043,  4047,
    4049,  4051,  4054,  4056,  4060,  4064,  4068,  4070,  4074,  4076,
    4078,  4080,  4082,  4084,  4086,  4088,  4091,  4096,  4098,  4102,
    4104,  4108,  4111,  4116,  4118,  4122,  4124,  4127,  4132,  4134,
    4138,  4140,  4142,  4144,  4147,  4151,  4156,  4159,  4164,  4165,
    4168,  4171,  4176,  4178,  4182,  4184,  4186,  4188,  4191,  4193,
    4195,  4197,  4199,  4201,  4204,  4211,  4218,  4219,  4221,  4222,
    4224,  4227,  4229,  4230,  4236,  4237,  4243,  4245,  4246,  4250,
    4252,  4256,  4258,  4262,  4264,  4266,  4267,  4272,  4274,  4277,
    4279,  4280,  4281,  4285,  4286,  4287,  4291,  4293,  4295,  4297,
    4299,  4301,  4303,  4306,  4309,  4314,  4318,  4322,  4324,  4328,
    4331,  4333,  4335,  4336,  4338,  4340,  4342,  4344,  4345,  4347,
    4351,  4353,  4357,  4359,  4360,  4364,  4366,  4368,  4370,  4372,
    4374,  4376,  4378,  4380,  4382,  4384,  4386,  4388,  4390,  4398,
    4405,  4410,  4415,  4417,  4419,  4421,  4422,  4424,  4427,  4429,
    4431,  4433,  4435,  4439,  4442,  4444,  4446,  4449,  4451,  4453,
    4454,  4458,  4460,  4464,  4466,  4470,  4472,  4474,  4481,  4482,
    4486,  4488,  4492,  4493,  4495,  4500,  4506,  4509,  4511,  4513,
    4518,  4520,  4524,  4529,  4534,  4539,  4541,  4545,  4547,  4549,
    4551,  4554,  4556,  4558,  4560,  4565,  4566,  4568,  4569,  4571,
    4573,  4576,  4579,  4581,  4583,  4585,  4587,  4589,  4594,  4596,
    4600,  4602,  4604,  4606,  4609,  4611,  4613,  4616,  4619,  4621,
    4625,  4628,  4631,  4633,  4637,  4639,  4642,  4647,  4649,  4652,
    4656,  4658,  4662,  4667,  4668,  4670,  4671,  4673,  4674,  4676,
    4678,  4682,  4684,  4688,  4690,  4693,  4695,  4699,  4702,  4705,
    4706,  4709,  4711,  4713,  4719,  4723,  4729,  4733,  4735,  4739,
    4741,  4743,  4744,  4746,  4750,  4754,  4758,  4765,  4770,  4775,
    4780,  4785,  4791,  4793,  4795,  4797,  4799,  4801,  4803,  4805,
    4807,  4809,  4811,  4812,  4814,  4816,  4818,  4820,  4822,  4824,
    4826,  4831,  4832,  4834,  4839,  4841,  4847,  4853,  4855,  4857,
    4859,  4861,  4863,  4868,  4870,  4875,  4882,  4887,  4889,  4894,
    4896,  4904,  4906,  4908,  4910,  4915,  4922,  4923,  4926,  4931,
    4933,  4935,  4937,  4939,  4941,  4943,  4945,  4949,  4951,  4953,
    4957,  4963,  4967,  4973,  4981,  4985,  4987,  4989,  4993,  4999,
    5003,  5009,  5017,  5019,  5020,  5024,  5030,  5032,  5035,  5038,
    5043,  5047,  5049,  5051,  5053,  5055,  5057,  5060,  5063,  5064,
    5068,  5069,  5073,  5075,  5077,  5079,  5081,  5083,  5085,  5087,
    5092,  5094,  5096,  5098,  5100,  5102,  5104,  5106,  5108,  5110,
    5112,  5114,  5116,  5118,  5120,  5125,  5127,  5131,  5133,  5137,
    5138,  5146,  5147,  5156,  5157,  5164,  5165,  5174,  5175,  5177,
    5180,  5182,  5186,  5188,  5192,  5198,  5200,  5202,  5204,  5206,
    5208,  5209,  5210,  5220,  5226,  5228,  5230,  5237,  5238,  5242,
    5244,  5248,  5253,  5255,  5256,  5259,  5264,  5271,  5272,  5274,
    5276,  5278,  5280,  5284,  5286,  5289,  5293,  5295,  5297,  5300,
    5303,  5305,  5307,  5309,  5312,  5315,  5318,  5321,  5326,  5330,
    5333,  5337,  5341,  5345,  5347,  5349,  5351,  5353,  5355,  5357,
    5363,  5369,  5375,  5381,  5387,  5392,  5397,  5401,  5406,  5408,
    5410,  5412,  5416,  5418,  5424,  5432,  5438,  5439,  5442,  5444,
    5446,  5447,  5451,  5453,  5457,  5459,  5461,  5463,  5464,  5468,
    5470,  5472,  5474,  5476,  5481,  5488,  5490,  5492,  5495,  5499,
    5501,  5503,  5505,  5507,  5509,  5511,  5513,  5515,  5521,  5527,
    5532,  5538,  5540,  5545,  5547,  5549,  5557,  5562,  5564,  5565,
    5570,  5572,  5575,  5577,  5579,  5581,  5582,  5586,  5587,  5591,
    5592,  5593,  5600,  5601,  5604,  5607,  5615,  5619,  5623,  5626,
    5629,  5632,  5634,  5638,  5640,  5644,  5646,  5650,  5652,  5656,
    5658,  5660,  5662,  5665,  5668,  5670,  5672,  5675,  5680,  5686,
    5694,  5702,  5712,  5714,  5716,  5718,  5720,  5722,  5724,  5728,
    5731,  5735,  5739,  5743,  5749,  5755,  5761,  5767,  5773,  5778,
    5783,  5787,  5792,  5794,  5796,  5798,  5800,  5804,  5805,  5811,
    5813,  5817,  5821,  5825,  5827,  5829,  5832,  5834,  5836,  5840,
    5842,  5846,  5850,  5852,  5854,  5856,  5860,  5863,  5867,  5874,
    5876,  5880,  5882,  5884,  5885,  5886,  5893,  5894,  5897,  5898,
    5900,  5902,  5905,  5908,  5910,  5912,  5917,  5921,  5923,  5926,
    5932,  5935,  5938,  5944,  5945,  5948,  5950,  5952,  5955,  5962,
    5969,  5971,  5972,  5974,  5977,  5979,  5982,  5983,  5986,  5988,
    5990,  5992,  5994,  5996,  5998,  6000,  6002,  6004,  6006,  6008,
    6010,  6012,  6014,  6016,  6018,  6020,  6022,  6024,  6026,  6028,
    6030,  6032,  6034,  6036,  6038,  6040,  6042,  6044,  6046,  6048,
    6050,  6052,  6054,  6056,  6058,  6060,  6062,  6064,  6066,  6068,
    6070,  6072,  6074,  6076,  6078,  6080,  6082,  6084,  6086,  6088,
    6090,  6092,  6094,  6096,  6098,  6100,  6102,  6104,  6106,  6108,
    6110,  6112,  6114,  6116,  6118,  6120,  6122,  6124,  6126,  6128,
    6130,  6132,  6134,  6136,  6138,  6140,  6142,  6144,  6146,  6148,
    6150,  6152,  6154,  6156,  6158,  6160
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1116,     0,    -1,   256,    -1,   253,    -1,   187,   739,   481,
     648,   740,    -1,   198,    -1,  1179,    -1,    26,    -1,   741,
      -1,   740,     5,   741,    -1,  1023,    -1,   485,   742,   448,
      -1,   742,   743,   742,    -1,    26,    -1,   744,    26,    -1,
    1179,    -1,   963,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   746,
      -1,    -1,   330,   485,   747,   748,   448,    -1,   621,   485,
      26,     5,    26,   448,    -1,   749,    -1,   748,     5,   749,
      -1,   543,    -1,   584,    -1,   589,    -1,   559,    -1,   465,
      -1,   657,    -1,   581,    -1,   533,    -1,   471,    -1,   544,
      -1,   403,    -1,   585,    -1,   510,    -1,   390,    -1,   646,
      -1,   155,    -1,  1095,    -1,    -1,   751,    -1,    -1,   330,
     485,   752,   753,   448,    -1,   754,    -1,   753,     5,   754,
      -1,   749,    -1,   486,    -1,   655,    25,    -1,   259,  1009,
      -1,   387,  1009,    -1,   340,  1009,    -1,   395,  1009,    -1,
     349,  1009,    -1,   316,  1009,    -1,   587,   756,    -1,   952,
     402,  1179,    -1,    -1,   345,   485,   971,   448,   402,   757,
    1197,    -1,   163,   485,  1023,     5,    25,     5,    25,   448,
      -1,   462,   485,  1015,   448,   402,  1179,    -1,  1320,    -1,
     249,   485,   971,   448,   402,  1179,    -1,    -1,    -1,  1179,
     642,  1023,   485,   758,   774,   448,   759,   772,    -1,    -1,
      -1,  1179,    36,  1023,   485,   760,   774,   448,   761,   772,
      -1,    -1,    -1,    -1,  1023,   485,   762,   774,   763,   448,
     764,   772,    -1,    -1,    -1,   527,  1529,   675,  1529,   485,
     765,   774,   766,   448,   772,    -1,    -1,    -1,  1023,   574,
    1023,   485,   767,   774,   768,   448,   772,    -1,    -1,    -1,
      -1,   422,   777,   642,   778,   513,   739,   481,   485,   769,
     774,   770,   448,   771,   773,    -1,    -1,   402,  1197,    -1,
      -1,   402,  1197,    -1,   220,    -1,    -1,   775,    -1,   776,
      -1,   775,     5,   776,    -1,   921,    -1,   536,    -1,    25,
      -1,  1023,    -1,  1023,    -1,  1023,   672,  1023,    -1,    -1,
     588,   928,   780,   783,   787,   784,    -1,    -1,   588,   781,
     782,   785,   784,    -1,   789,    -1,   782,   789,    -1,   791,
      -1,   783,   791,    -1,   417,    -1,    -1,    -1,   397,   786,
    1604,    -1,    -1,    -1,   397,   788,  1604,    -1,    -1,   631,
     928,   790,  1604,    -1,    -1,   631,   928,   792,  1604,    -1,
      -1,    -1,    -1,   731,  1023,   794,   797,   795,   827,   796,
     798,   730,    -1,    -1,   732,  1023,    -1,   799,    -1,   798,
     799,    -1,  1131,    -1,   334,  1020,    -1,   258,  1018,    -1,
     141,  1018,    -1,   225,    -1,   242,  1535,    -1,   547,  1017,
      -1,    30,   802,    31,    -1,   803,    -1,   805,    -1,   804,
      -1,   803,   804,    -1,    29,    -1,   806,    -1,   805,   806,
      -1,    28,    -1,    -1,    -1,   378,   808,   810,   809,   811,
      -1,   441,  1179,   677,   812,  1067,  1094,   745,    -1,  1179,
     677,   812,  1067,   599,   971,  1094,   745,    -1,    -1,   814,
     248,    -1,   813,    -1,   812,     5,   813,    -1,  1023,    -1,
    1023,   672,  1023,    -1,  1023,   672,    20,    -1,   815,    -1,
     814,   815,    -1,    -1,   326,   821,   816,  1604,    -1,    -1,
     329,   822,   817,  1604,    -1,    -1,  1097,   818,  1604,    -1,
      -1,   223,   819,  1604,    -1,    -1,   221,   820,  1604,    -1,
    1027,    -1,   821,     5,  1027,    -1,  1027,    -1,   822,     5,
    1027,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
     153,    -1,   154,    -1,   485,   921,   825,   448,    -1,    -1,
       5,   872,   678,   875,    -1,   213,    -1,   335,    -1,    -1,
     828,    -1,   829,    -1,   828,   829,    -1,    -1,    -1,   492,
     830,   832,   831,  1289,    -1,   885,    -1,   835,    -1,   832,
       5,   835,    -1,    -1,   834,  1023,    -1,   411,   833,   884,
      25,    -1,   411,   833,   884,  1023,    -1,   411,   833,   884,
    1029,    -1,   411,   833,   884,    26,    -1,   839,   858,    -1,
      -1,   833,   411,   836,   837,    -1,    26,    -1,    25,    -1,
    1029,    -1,    19,    26,    -1,   833,    -1,   838,    -1,   839,
       5,   838,    -1,    -1,   375,    -1,    -1,   722,    -1,   723,
      -1,   724,    -1,    -1,   540,   513,   849,   481,   843,   676,
     858,    -1,    -1,    44,   841,   844,   676,   858,    -1,    -1,
     374,   840,   846,    26,   847,   358,   513,   848,   481,   845,
     676,   858,    -1,   485,    -1,   512,    -1,   448,    -1,   480,
      -1,    26,    -1,   850,     5,   850,     5,   850,    -1,   850,
       5,   850,    -1,   850,    -1,    26,    -1,   833,    -1,   833,
     642,   833,    -1,   833,   664,   833,   642,   833,    -1,    -1,
     518,   853,   832,   339,    -1,    -1,   317,   854,   851,   672,
      20,    -1,    -1,   392,   855,   851,   315,   485,   856,   448,
      -1,   857,    -1,   856,     5,   857,    -1,   833,    -1,   860,
      -1,    -1,   116,    -1,    -1,    -1,   861,   863,   862,   859,
      -1,   842,    -1,   852,    -1,   375,    -1,   376,    -1,   375,
     485,    26,   448,    -1,   376,   485,    26,   448,    -1,   478,
     485,    26,   448,    -1,   478,   485,    26,     5,    26,   448,
      -1,   377,   485,    26,   448,    -1,   377,   485,    26,     5,
      26,   448,    -1,   463,    -1,   669,   833,    -1,   437,    -1,
     562,    -1,   147,    -1,   453,    -1,   453,   485,    26,   448,
      -1,   453,   485,    26,     5,    26,   448,    -1,   565,    -1,
     565,   485,    26,   448,    -1,   565,   485,    26,     5,    26,
     448,    -1,    -1,   555,   864,   867,    -1,    -1,   121,   865,
     867,    -1,    -1,   355,   866,   867,    -1,   590,    -1,   586,
      -1,   137,    -1,   138,    -1,   627,    -1,   414,   870,    -1,
     426,   871,    -1,   868,    -1,    32,    -1,    -1,   485,    26,
     448,    -1,   609,   851,   672,   869,    -1,   833,    -1,    -1,
     872,   678,   875,    -1,   880,   678,   883,    -1,    -1,   873,
     874,    -1,   634,    -1,   566,    -1,   643,    -1,   605,    -1,
     508,    -1,   524,    -1,   423,   877,    -1,    -1,   876,   874,
      -1,    -1,   485,   879,   448,    -1,    -1,   485,    26,   448,
      -1,    26,    -1,    -1,   881,   882,   878,    -1,   634,    -1,
     566,    -1,   643,    -1,   605,    -1,   508,    -1,   524,    -1,
     423,   877,    -1,   882,    -1,    -1,    14,    -1,    -1,   293,
    1023,   886,   669,   887,    -1,   889,    -1,   892,    -1,   375,
      -1,   375,   485,    26,   448,    -1,   478,   485,    26,   448,
      -1,   478,   485,    26,     5,    26,   448,    -1,   463,    -1,
     437,    -1,   562,    -1,   453,    -1,   453,   485,    26,   448,
      -1,   453,   485,    26,     5,    26,   448,    -1,   565,    -1,
     565,   485,    26,   448,    -1,   565,   485,    26,     5,    26,
     448,    -1,   555,    -1,   355,    -1,   590,    -1,   586,    -1,
     627,    -1,   414,   870,    -1,   426,   871,    -1,   888,    -1,
     609,   851,   672,   869,    -1,    -1,   540,   513,   849,   481,
     890,   676,   887,    -1,    -1,   374,   840,   846,    26,   847,
     358,   513,   848,   481,   891,   676,   887,    -1,    -1,   518,
     893,   895,   339,    -1,    -1,   317,   894,  1023,   672,    20,
      -1,   896,    -1,   895,     5,   896,    -1,   897,   887,    -1,
     898,    -1,   897,     5,   898,    -1,  1023,    -1,    -1,   670,
    1013,    -1,   128,  1023,    -1,   126,    -1,   678,   971,    -1,
     678,   562,  1023,   711,   971,    -1,   678,   562,  1023,   446,
      -1,   130,  1023,    -1,   214,   944,  1197,   907,    -1,   456,
     944,   926,   899,   907,    -1,   267,  1020,   907,    -1,    -1,
      -1,   245,   904,  1204,   678,  1023,   672,    20,   906,   745,
     905,   908,    -1,    -1,   522,  1014,    -1,   745,    -1,    -1,
     909,   295,    -1,   295,    -1,   910,    -1,   909,   910,    -1,
      -1,   409,   911,  1604,    -1,    -1,   405,   912,  1604,    -1,
      -1,  1097,   913,  1604,    -1,    46,  1179,    -1,    47,  1179,
      -1,    45,  1179,    -1,   551,   944,   927,   745,    -1,   551,
     944,   927,   745,   123,    -1,   271,    -1,   271,   928,    -1,
     342,    -1,   341,    -1,   270,    -1,   421,    -1,   230,    -1,
     269,    -1,   386,    -1,   385,    -1,   300,    -1,   227,    -1,
     226,    -1,   204,    -1,   260,    -1,   188,    -1,   203,    -1,
     244,    -1,   211,    -1,   929,    -1,   933,    -1,   963,    -1,
     921,   922,    -1,   964,    -1,   966,    -1,   930,    -1,    19,
     921,    -1,    18,   921,    -1,   935,    -1,   943,    -1,   937,
      -1,   528,    -1,   823,    -1,   938,    -1,   939,    -1,   940,
      -1,   941,    -1,   942,    -1,    52,   921,    -1,   944,    -1,
     944,   925,    -1,   928,    -1,   536,    -1,   924,    -1,   925,
       5,   924,    -1,   928,    -1,   926,     5,   928,    -1,   928,
      -1,   927,     5,   928,    -1,   921,    -1,     9,   921,    -1,
     537,    -1,   482,    -1,   485,   921,   448,    -1,   497,   485,
    1509,   448,    -1,   350,   485,  1509,   448,    -1,    25,    -1,
    1029,    -1,    26,    -1,   932,    -1,  1179,    -1,  1179,   475,
    1179,    -1,   931,    -1,   488,   921,    -1,   449,   921,    -1,
    1292,    -1,    -1,   560,   934,  1292,    -1,     7,   921,    -1,
       6,   921,    -1,   921,    -1,   936,     5,   921,    -1,   675,
     485,  1509,   448,    -1,   483,   485,  1509,   448,    -1,   675,
     485,   944,   936,   448,    -1,   483,   485,   944,   936,   448,
      -1,   443,    -1,   306,    -1,    10,   921,    -1,   309,   921,
      -1,    10,   921,   496,    25,    -1,   309,   921,   496,    25,
      -1,   609,   921,    -1,   428,   921,    -1,   609,   921,   496,
      25,    -1,   428,   921,   496,    25,    -1,   447,    -1,     8,
     921,    -1,    18,   921,    -1,    19,   921,    -1,    20,   921,
      -1,    21,   921,    -1,    22,   921,    -1,    11,   921,    -1,
      14,   921,    -1,   511,   921,    -1,    12,   921,    -1,    13,
     921,    -1,    17,   921,    -1,    16,   921,    -1,    15,   921,
      -1,    -1,    -1,    -1,  1023,   485,   946,   774,   947,   448,
      -1,    -1,    -1,  1023,   574,  1023,   485,   948,   774,   949,
     448,    -1,    -1,    -1,  1023,    36,  1023,   485,   950,   774,
     951,   448,    -1,    -1,    -1,   590,   485,   953,   921,   954,
     448,    -1,    -1,    -1,   566,   485,   955,   921,   956,   448,
      -1,    -1,    -1,   643,   485,   957,   921,   958,   448,    -1,
      -1,    -1,   634,   485,   959,   921,   960,   448,    -1,   426,
     485,   967,   448,   962,    -1,   414,   485,    25,   448,   961,
      -1,   414,   485,    26,   448,   961,    -1,   414,   485,    24,
     448,   961,    -1,   414,   485,    26,   642,    26,   448,   961,
      -1,   414,   485,    26,   642,    24,   448,   961,    -1,   414,
     485,    26,   642,    26,   642,    26,   448,   961,    -1,   414,
     485,    26,   642,    26,   642,    24,   448,   961,    -1,   414,
     485,    26,    26,   448,   961,    -1,   414,   485,    26,    26,
     642,    26,   448,   961,    -1,   414,   485,    26,    26,   642,
      26,   642,    26,   448,   961,    -1,   414,   485,    26,    26,
     642,    26,   642,    24,   448,   961,    -1,   414,   485,    26,
      19,    26,   448,   961,    -1,   414,   485,    26,    19,    26,
      19,    26,   448,   961,    -1,   414,   485,    26,    19,    26,
      26,   448,   961,    -1,   414,   485,    26,    19,    26,    19,
      26,    26,   448,   961,    -1,   414,   485,    26,    19,    26,
      19,    26,    26,   642,    26,   448,   961,    -1,   414,   485,
      26,    19,    26,    19,    26,    26,   642,    26,   642,    26,
     448,   961,    -1,   414,   485,    26,    19,    26,    19,    26,
      26,   642,    26,   642,    24,   448,   961,    -1,   414,   485,
      26,    19,    26,    26,   642,    26,   448,   961,    -1,   414,
     485,    26,    19,    26,    26,   642,    26,   642,    26,   448,
     961,    -1,   414,   485,    26,    19,    26,    26,   642,    26,
     642,    24,   448,   961,    -1,    42,   485,  1179,   448,    -1,
     727,   485,  1179,   448,    -1,   728,   485,  1179,     5,    26,
     448,    -1,    -1,   874,   678,   874,    -1,   871,    -1,   952,
      -1,   345,   485,   971,   448,    -1,   156,   485,  1014,   448,
      -1,   129,   485,  1014,   448,    -1,   462,   485,   972,   448,
      -1,   249,   485,   971,   448,    -1,   117,   485,   971,   448,
      -1,   965,    -1,   945,    -1,  1486,    -1,   590,    -1,   477,
     485,   921,   448,    -1,   380,   485,   921,   448,    -1,   541,
     921,    -1,   498,   824,    -1,   921,   167,    -1,   921,   168,
      -1,   921,   169,    -1,    25,    -1,   968,    -1,    19,   968,
      -1,   970,    -1,   969,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   642,    26,    -1,    26,    26,   642,    26,   642,
      26,    -1,    26,    26,   642,    26,   642,    24,    -1,    26,
     642,    26,    -1,    26,   642,    26,   642,    26,    -1,    26,
     642,    26,   642,    24,    -1,    26,   642,    24,    -1,    24,
      -1,   672,    26,    -1,    26,    -1,    26,    19,    26,    -1,
    1014,    -1,   971,     5,  1014,    -1,  1015,    -1,   972,     5,
    1015,    -1,    -1,    -1,    -1,   459,   974,  1017,   975,   977,
    1388,   976,  1604,   297,    -1,    -1,     8,   944,   926,    -1,
      -1,    -1,   690,  1023,   979,   827,   980,  1128,   982,   981,
     987,   691,    -1,    -1,   992,    -1,    -1,   983,    -1,   984,
      -1,   983,   984,    -1,    -1,   692,   985,  1604,    -1,    -1,
     693,   986,  1604,    -1,    -1,   988,    -1,   989,    -1,   988,
     989,    -1,    -1,   694,   990,  1604,    -1,    -1,   695,   991,
    1604,    -1,   993,   997,   382,    -1,   148,    -1,   148,   994,
     599,   995,    -1,   148,   441,   996,    -1,  1179,    -1,   994,
       5,  1179,    -1,  1023,    -1,   995,     5,  1023,    -1,  1179,
      -1,   996,     5,  1179,    -1,   998,    -1,   997,   998,    -1,
      -1,   696,   999,  1604,    -1,    -1,   697,  1000,  1604,    -1,
      -1,   716,   995,  1001,  1604,    -1,    -1,   534,   995,  1002,
    1604,    -1,    -1,   677,   995,  1003,  1604,    -1,    -1,    -1,
     648,  1179,    14,   928,   678,   928,  1007,  1005,  1604,  1006,
     298,    -1,    -1,   624,   928,    -1,   598,  1016,    -1,   607,
      19,    26,    -1,   607,    -1,   554,    18,    26,    -1,   554,
      -1,    26,    -1,  1179,    -1,   721,    -1,    25,    -1,  1028,
      -1,   928,    -1,  1011,     5,  1011,    -1,  1012,    -1,  1023,
      -1,   719,   485,  1023,   448,    -1,  1023,   672,   719,   485,
    1023,   448,    -1,  1023,   513,   742,   481,    -1,  1023,   672,
      20,    -1,  1023,   513,   742,   481,   672,    20,    -1,  1023,
     672,  1023,    -1,  1023,   513,   742,   481,   672,  1023,    -1,
    1014,    -1,    25,    -1,  1024,    -1,  1024,    -1,  1024,    -1,
    1024,    -1,  1024,    -1,  1024,    -1,    -1,   603,    26,    -1,
    1603,    -1,  1025,    -1,  1603,    -1,   407,   485,  1026,   448,
      -1,  1182,    -1,    25,    -1,  1023,    -1,  1023,   513,   742,
     481,    -1,  1023,   672,    20,    -1,  1023,   513,   742,   481,
     672,    20,    -1,  1023,   672,  1023,    -1,  1023,   513,   742,
     481,   672,  1023,    -1,  1179,    -1,    24,    -1,   672,    26,
      -1,   600,  1031,    -1,  1023,    -1,   642,  1023,    -1,   704,
    1033,    -1,  1034,    -1,  1033,     5,  1034,    -1,  1023,    -1,
     715,  1033,    -1,   706,  1033,    -1,   707,   971,    -1,   705,
    1020,   711,   971,    -1,   709,  1033,    -1,   710,   971,    -1,
     708,  1020,   711,   971,    -1,    -1,   713,  1039,   926,  1044,
    1046,  1048,  1040,  1042,    -1,    -1,  1041,    -1,   701,    -1,
     702,    -1,    -1,  1043,    -1,   402,  1179,    -1,    -1,  1045,
      -1,   446,   926,    -1,    -1,  1047,    -1,   712,    26,    -1,
      -1,  1049,    -1,   703,    26,  1050,    -1,    -1,   455,    26,
      -1,    -1,    -1,   674,   928,   628,  1052,  1604,  1053,  1054,
     495,    -1,    -1,    -1,   595,  1055,  1604,    -1,    -1,    -1,
     120,  1056,   928,   628,  1057,  1604,  1054,    -1,   165,  1023,
     485,    26,   448,    -1,   111,  1023,    -1,    43,  1023,    -1,
     133,  1023,    -1,    -1,   346,  1208,  1062,   678,   536,    -1,
     346,  1208,   609,  1063,    -1,  1064,    -1,  1063,     5,  1064,
      -1,  1065,   672,  1482,    -1,  1065,   672,    20,    -1,  1478,
      -1,    -1,  1068,   382,    -1,   382,    -1,    -1,   208,    -1,
    1069,    -1,  1068,  1069,    -1,    -1,   326,  1083,  1070,  1604,
      -1,    -1,   329,  1084,  1071,  1604,    -1,    -1,   409,  1072,
    1604,    -1,    -1,   405,  1073,  1604,    -1,    -1,  1097,  1074,
    1604,    -1,    -1,   361,  1075,  1604,    -1,    -1,   331,  1076,
    1604,    -1,    -1,    53,  1077,  1604,    -1,    -1,    50,  1078,
    1604,    -1,    -1,    49,  1079,  1604,    -1,    -1,    48,  1080,
    1604,    -1,    -1,    56,  1081,  1604,    -1,    -1,    55,  1082,
    1604,    -1,  1014,    -1,  1083,     5,  1014,    -1,  1014,    -1,
    1084,     5,  1014,    -1,   370,  1087,    -1,   371,  1023,   711,
    1087,    -1,   614,    -1,   432,    -1,  1014,    -1,    -1,   717,
    1090,  1089,  1066,    -1,   441,  1197,  1067,  1022,   745,    -1,
    1197,  1067,   599,   971,  1022,   745,    -1,    -1,   540,  1204,
    1067,   599,  1023,   672,    20,  1022,  1091,   745,    -1,   523,
     971,  1093,    -1,   139,    26,    -1,   140,    26,    -1,   679,
      -1,   592,    -1,   139,  1179,    -1,   140,  1179,    -1,    -1,
     603,    26,    -1,  1096,    -1,    62,    25,    -1,   549,    14,
      26,    -1,   549,    14,  1179,    -1,    63,    14,    26,    -1,
      63,    14,  1179,    -1,    59,    -1,    61,    -1,    58,    -1,
      60,    -1,    -1,   484,  1098,  1103,    -1,   351,    -1,    -1,
     649,  1100,  1103,    -1,   359,  1105,    -1,   649,  1103,    -1,
    1105,    -1,   485,  1104,   448,    -1,  1105,    -1,  1104,     5,
    1105,    -1,  1106,    -1,   647,    -1,   368,    -1,   388,    -1,
     360,    -1,   538,    -1,   496,    -1,   679,    -1,   603,    -1,
     592,    -1,   234,    -1,   493,    -1,   504,    -1,   593,    -1,
     608,    -1,   573,    -1,   366,    -1,   367,    -1,    25,    -1,
     563,    -1,    -1,    -1,   651,  1109,  1202,  1110,    14,   944,
    1111,    -1,   536,    -1,   927,    -1,   276,  1179,    -1,   266,
    1179,    -1,   279,  1179,    -1,   505,  1200,   391,    -1,   505,
    1200,   442,  1010,    -1,  1117,    -1,  1118,    -1,   793,    -1,
      -1,  1120,  1119,  1123,    -1,    -1,  1121,    -1,  1122,    -1,
    1121,  1122,    -1,  1060,    -1,  1127,    -1,  1588,    -1,  1059,
      -1,  1143,    -1,  1129,    -1,  1142,    -1,    -1,  1124,    -1,
    1126,    -1,  1124,  1126,    -1,   124,  1023,    -1,  1131,    -1,
    1137,    -1,  1302,    -1,  1312,    -1,  1149,    -1,   978,    -1,
     801,    -1,  1058,    -1,  1588,    -1,   801,    -1,    -1,   801,
      -1,   828,    -1,   424,    -1,   118,    -1,    -1,    -1,    -1,
      -1,  1130,  1132,  1023,   485,  1133,  1195,   448,  1134,   827,
    1135,  1128,  1604,  1136,    -1,   268,    -1,    -1,    -1,   610,
    1138,   827,  1139,  1604,   418,    -1,   234,   923,    -1,   944,
      -1,   944,   926,    -1,   413,  1493,    -1,   521,  1493,    -1,
    1144,    -1,  1145,    -1,  1144,  1145,    -1,  1146,    -1,    -1,
     461,  1147,  1148,    -1,   827,   299,    -1,  1010,    -1,  1127,
      -1,  1142,    -1,    -1,    -1,   698,  1023,  1150,   827,  1151,
    1152,   699,    -1,  1153,    -1,  1152,  1153,    -1,    -1,   700,
    1154,  1604,    -1,    -1,   677,  1023,  1155,  1604,    -1,    -1,
     611,  1157,  1172,  1163,  1158,    -1,   419,    -1,    -1,   291,
    1160,  1604,    -1,    -1,    23,  1164,  1165,  1166,  1022,  1161,
    1604,    -1,    -1,    23,  1164,  1022,  1162,  1604,    -1,  1159,
      -1,  1163,  1159,    -1,    -1,  1099,    -1,    25,    -1,  1179,
      -1,    -1,  1179,    -1,    25,    -1,   308,  1170,    -1,   319,
    1171,    -1,   303,  1171,    -1,   638,    -1,    25,    -1,  1179,
      -1,  1170,    -1,  1171,     5,  1170,    -1,  1179,    -1,    25,
      -1,  1176,  1174,    -1,    -1,   746,  1177,    -1,  1178,    -1,
    1175,    -1,  1045,    -1,  1047,    -1,  1049,    -1,  1041,    -1,
    1043,    -1,   427,   944,   926,    -1,    -1,   123,    -1,   123,
      -1,  1180,    -1,  1182,    -1,   247,  1182,    -1,  1182,   672,
      -1,  1181,  1186,    -1,  1181,  1023,   513,  1189,   481,    -1,
    1181,  1023,   513,  1189,   481,   513,  1189,   481,    -1,  1187,
      -1,  1023,    -1,  1183,    -1,  1023,   512,  1185,   480,    -1,
    1023,   512,  1185,   480,    -1,  1179,    -1,    25,    -1,    20,
      -1,  1023,    -1,  1023,  1188,    -1,   513,  1189,   481,    -1,
     513,  1189,   481,   513,  1189,   481,    -1,  1190,    -1,  1189,
       5,  1190,    -1,   742,    -1,  1192,    -1,  1194,    -1,  1192,
     672,  1193,    -1,  1192,   672,  1023,   513,  1189,   481,    -1,
    1192,   672,  1023,   513,  1189,   481,   513,  1189,   481,    -1,
    1023,    -1,  1184,    -1,    20,    -1,  1023,    -1,  1023,  1188,
      -1,    -1,  1196,    -1,  1198,    -1,  1196,     5,  1198,    -1,
    1199,    -1,  1197,     5,  1199,    -1,  1023,    -1,  1023,   672,
    1023,    -1,  1179,    -1,  1179,   475,  1179,    -1,    25,    -1,
    1029,    -1,    26,    -1,  1201,    -1,  1200,     5,  1201,    -1,
    1179,    -1,  1179,   475,  1179,    -1,  1203,    -1,  1202,     5,
    1203,    -1,  1191,    -1,  1179,    -1,  1206,    -1,  1205,     5,
    1206,    -1,  1179,  1207,    -1,    -1,   640,    -1,   591,    -1,
    1209,    -1,  1208,     5,  1209,    -1,  1179,    -1,  1179,   475,
    1179,    -1,   311,  1019,   670,  1012,   632,  1596,   750,    -1,
      -1,   670,   485,   928,     5,   928,   448,  1212,    -1,    -1,
     621,   485,   928,     5,   928,   448,    -1,   312,  1023,  1211,
      -1,  1023,    -1,   396,  1021,  1216,    -1,  1217,    -1,   599,
     928,    -1,  1218,  1219,  1224,     8,  1214,    -1,    -1,   670,
    1220,   485,   928,     5,   928,   448,    -1,    -1,   609,  1024,
      -1,    -1,   408,    -1,   274,  1535,   322,  1577,  1223,    -1,
     616,  1016,    -1,   616,  1016,     8,   944,   926,    -1,    -1,
     669,   629,  1529,   431,  1529,    -1,   669,   629,  1529,     5,
     431,  1529,    -1,   669,  1529,     5,  1529,    -1,    -1,   701,
      -1,   702,    -1,   450,   678,  1577,  1226,  1227,    -1,    -1,
     669,  1577,    -1,    -1,   669,   629,  1529,     8,  1529,    -1,
     629,  1529,     8,  1529,    -1,   466,  1229,    -1,  1230,    -1,
    1229,     5,  1230,    -1,   259,  1009,    -1,   340,  1009,    -1,
     387,  1009,    -1,   395,  1009,    -1,   349,  1009,    -1,   316,
    1009,    -1,  1101,    -1,   493,  1102,    -1,   504,  1102,    -1,
     614,  1102,    -1,   432,  1102,    -1,   603,  1102,    -1,   601,
    1010,    -1,   602,  1010,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,   456,   746,    -1,   717,   746,    -1,   347,
      -1,   252,    -1,   209,    -1,   189,    -1,   197,    -1,   206,
      -1,   659,  1231,    -1,   733,  1232,    -1,    40,    -1,    41,
      -1,    40,    -1,    41,    -1,  1534,   468,  1236,   599,  1234,
      -1,  1179,    -1,    25,    -1,   458,  1236,    -1,   458,  1236,
       8,  1197,    -1,   458,  1236,   606,  1200,    -1,   458,  1236,
     606,  1200,     8,  1197,    -1,    57,  1234,    -1,  1024,    -1,
      -1,   516,  1246,   745,   648,  1241,  1179,  1239,  1022,   745,
    1238,  1242,    -1,    -1,   720,    26,    -1,   516,  1246,   745,
     402,  1179,    -1,    -1,   375,    -1,    -1,  1243,   338,    -1,
    1244,    -1,  1243,  1244,    -1,    -1,  1097,  1245,  1604,    -1,
     927,    -1,    -1,   656,  1016,  1248,  1249,    -1,    -1,   599,
    1250,    -1,  1251,    -1,  1250,     5,  1251,    -1,  1521,    -1,
     536,    -1,   277,  1255,   146,  1253,    -1,   277,  1255,   678,
    1254,  1253,    -1,   277,  1255,   145,  1254,  1253,    -1,   277,
    1255,  1253,    -1,    -1,    51,    -1,    25,    -1,  1028,    -1,
    1023,    -1,    -1,   532,    -1,   205,  1255,  1256,   485,   944,
    1141,   448,    -1,   250,  1255,    -1,   125,  1255,    -1,  1293,
    1301,    -1,   501,   119,    -1,   501,  1262,    -1,  1263,    -1,
    1262,  1263,    -1,    -1,   193,  1264,  1604,    -1,    -1,   255,
    1265,  1604,    -1,    -1,   285,  1266,  1604,    -1,    -1,   273,
    1267,  1604,    -1,    -1,   310,  1268,  1604,    -1,    -1,   257,
    1179,  1269,  1604,    -1,    -1,   281,  1179,  1270,  1604,    -1,
    1281,    -1,  1285,    -1,  1284,    -1,  1272,    -1,  1310,    -1,
    1275,    -1,    -1,   613,   928,  1273,   535,    -1,    -1,   535,
      -1,    -1,   622,    26,  1276,  1274,    -1,   216,    -1,   681,
    1297,    -1,   219,  1297,    -1,   218,  1297,    -1,    -1,  1278,
      -1,  1279,    -1,  1278,  1279,    -1,  1290,  1280,    -1,    -1,
     670,  1297,    -1,    -1,   572,  1282,  1277,  1289,    -1,  1529,
      -1,   485,  1529,   448,    -1,   571,  1283,  1289,    -1,   570,
    1288,  1287,  1286,  1289,    -1,    -1,   210,   921,    -1,   210,
     921,     5,   921,    -1,   665,    -1,   666,    -1,   667,    -1,
     668,    -1,  1179,    -1,    -1,   575,    -1,  1291,    -1,  1290,
       5,  1291,    -1,   928,  1324,    -1,   661,   485,   921,   448,
    1309,    -1,   122,  1309,    -1,   549,   485,    20,   448,  1309,
      -1,   467,   485,    20,   448,  1309,    -1,   444,   485,   921,
     448,  1309,    -1,   641,   485,   921,   448,  1309,    -1,   654,
     485,   921,   448,  1309,    -1,   653,   485,   921,   448,  1309,
      -1,    -1,   515,  1294,    -1,  1295,    -1,  1294,  1295,    -1,
     284,    26,    -1,   275,    26,    -1,   357,    26,    -1,   241,
      26,    -1,   313,    26,    -1,   232,    -1,   401,    25,    -1,
     401,  1179,    -1,   233,    25,    -1,   217,    25,    -1,  1300,
      -1,  1296,  1300,    -1,  1298,   167,    -1,  1298,   169,    -1,
    1298,   168,    -1,  1298,    -1,  1029,    -1,    26,    -1,    -1,
     515,  1296,    -1,   284,  1297,    -1,   275,  1297,    -1,   357,
    1297,    -1,   241,  1297,    -1,   313,  1297,    -1,   314,  1297,
      -1,   680,    25,    -1,   681,  1297,    -1,   685,    -1,   682,
      -1,   683,    -1,   684,    -1,   689,    -1,   686,    -1,   687,
      -1,   688,    -1,   134,  1297,    -1,   135,  1297,    -1,   136,
    1297,    -1,   401,    25,    -1,   233,    25,    -1,   455,    -1,
     131,    -1,   132,    -1,    -1,   567,   671,  1205,    -1,   194,
    1205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   519,  1303,
    1023,   485,  1304,  1195,   448,  1305,   827,  1306,  1260,  1307,
    1261,  1308,   296,    -1,    -1,   579,   921,    -1,   569,  1311,
      -1,    -1,  1234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,  1313,  1023,   485,  1314,  1195,   448,  1315,   827,  1316,
    1319,  1317,  1261,  1318,   296,    -1,  1299,  1301,    -1,    -1,
      -1,    -1,   212,   485,    25,     5,  1321,   774,  1322,   448,
    1323,   772,    -1,    -1,   440,    -1,   440,   275,    26,    -1,
     440,   275,  1179,    -1,   659,   928,    -1,   659,   928,  1326,
      -1,   659,   928,   402,  1179,    -1,   659,   928,   220,    -1,
     659,   928,  1326,   402,  1179,    -1,   659,   928,  1326,   220,
      -1,   659,   928,   630,    -1,   659,   928,   597,    -1,    41,
      -1,    40,    -1,  1328,    -1,   229,  1478,    -1,   381,  1478,
      -1,   337,  1479,    -1,    54,  1023,    -1,  1342,    -1,  1330,
      -1,    -1,    -1,   262,  1331,  1478,   485,  1332,  1346,   448,
    1335,    -1,    -1,    -1,   191,  1333,  1478,   485,  1334,  1346,
     448,  1335,  1343,    -1,    -1,  1336,    -1,  1337,    -1,  1336,
    1337,    -1,   675,  1338,    -1,   301,    26,    -1,    66,    26,
      -1,   143,    -1,   144,    -1,  1603,    -1,    -1,  1340,    -1,
    1341,    -1,  1340,  1341,    -1,   675,  1338,    -1,   729,    26,
      -1,   162,  1479,   677,  1478,   485,  1344,   448,  1339,    -1,
     109,  1024,    -1,   110,  1024,    -1,   228,  1478,   648,  1478,
      -1,   114,  1478,    -1,    -1,   324,    -1,  1345,    -1,  1344,
       5,  1345,    -1,  1023,   640,    -1,  1023,   591,    -1,  1023,
      -1,  1347,    -1,  1346,     5,  1347,    -1,  1430,    -1,  1428,
      -1,   178,  1023,    -1,   236,    -1,    64,  1023,  1350,    -1,
      65,  1479,   159,    -1,    65,  1479,   160,    -1,  1351,    -1,
    1350,     5,  1351,    -1,  1352,    -1,  1355,    -1,  1358,    -1,
    1363,    -1,  1366,    -1,  1362,    -1,  1361,    -1,   637,  1353,
      -1,   637,   485,  1354,   448,    -1,  1347,    -1,  1347,   716,
    1023,    -1,  1353,    -1,  1354,     5,  1353,    -1,   594,  1357,
      -1,   594,   485,  1356,   448,    -1,  1357,    -1,  1356,     5,
    1357,    -1,  1023,    -1,   509,  1360,    -1,   509,   485,  1359,
     448,    -1,  1360,    -1,  1359,     5,  1360,    -1,  1347,    -1,
     143,    -1,   144,    -1,   142,    26,    -1,   112,  1428,  1365,
      -1,   112,   485,  1364,   448,    -1,  1428,  1365,    -1,  1364,
       5,  1428,  1365,    -1,    -1,   115,  1023,    -1,   113,  1367,
      -1,   113,   485,  1367,   448,    -1,  1368,    -1,  1367,     5,
    1368,    -1,  1023,    -1,   321,    -1,   288,    -1,   222,  1371,
      -1,   201,    -1,   190,    -1,   177,    -1,   175,    -1,   179,
      -1,   235,  1535,    -1,   287,  1370,   514,  1529,   678,  1529,
      -1,   354,  1016,   514,  1529,   678,  1529,    -1,    -1,  1535,
      -1,    -1,   928,    -1,   576,   928,    -1,   286,    -1,    -1,
     305,  1375,  1478,  1378,  1376,    -1,    -1,   532,  1377,   485,
    1380,   448,    -1,  1515,    -1,    -1,   485,  1379,   448,    -1,
    1482,    -1,  1379,     5,  1482,    -1,  1381,    -1,  1380,     5,
    1381,    -1,  1521,    -1,   536,    -1,    -1,   553,  1383,  1385,
    1386,    -1,  1024,    -1,  1390,  1017,    -1,  1017,    -1,    -1,
      -1,   606,  1387,  1200,    -1,    -1,    -1,   606,  1389,  1200,
      -1,   554,    -1,   607,    -1,   614,    -1,   432,    -1,   399,
      -1,   451,    -1,   435,   928,    -1,   408,   928,    -1,   294,
    1478,   207,  1017,    -1,   294,  1478,  1451,    -1,   567,   671,
    1394,    -1,  1395,    -1,  1394,     5,  1395,    -1,  1396,  1397,
      -1,    26,    -1,  1482,    -1,    -1,   640,    -1,   591,    -1,
     332,    -1,   365,    -1,    -1,   384,    -1,   413,  1402,  1400,
      -1,  1577,    -1,  1577,   664,  1023,    -1,    25,    -1,    -1,
    1534,  1404,  1405,    -1,  1436,    -1,    37,    -1,  1440,    -1,
    1399,    -1,  1536,    -1,  1398,    -1,  1391,    -1,  1392,    -1,
    1382,    -1,  1374,    -1,  1373,    -1,  1505,    -1,  1557,    -1,
     558,  1409,   677,  1478,   678,  1414,  1408,    -1,   520,  1409,
     677,  1478,   599,  1414,    -1,   558,  1407,   678,  1414,    -1,
     520,  1407,   599,  1414,    -1,   450,    -1,   436,    -1,   644,
      -1,    -1,   200,    -1,   669,  1023,    -1,   224,    -1,   638,
      -1,  1410,    -1,  1411,    -1,  1410,     5,  1411,    -1,   525,
    1412,    -1,   504,    -1,   493,    -1,   531,  1412,    -1,   539,
      -1,   561,    -1,    -1,   485,  1413,   448,    -1,  1482,    -1,
    1413,     5,  1482,    -1,  1415,    -1,  1414,     5,  1415,    -1,
     517,    -1,  1480,    -1,   292,  1478,  1417,   669,  1515,  1419,
      -1,    -1,   485,  1418,   448,    -1,  1482,    -1,  1418,     5,
    1482,    -1,    -1,   199,    -1,   545,   485,  1454,   448,    -1,
     302,   485,  1423,   448,  1422,    -1,   352,  1424,    -1,  1425,
      -1,  1478,    -1,  1478,   485,  1425,   448,    -1,  1482,    -1,
    1425,     5,  1482,    -1,   529,   485,  1427,   448,    -1,   416,
     485,  1427,   448,    -1,   315,   485,  1427,   448,    -1,  1482,
      -1,  1427,     5,  1482,    -1,  1426,    -1,  1421,    -1,  1420,
      -1,   455,  1485,    -1,   265,    -1,   264,    -1,   263,    -1,
    1023,  1470,  1431,  1432,    -1,    -1,  1429,    -1,    -1,  1433,
      -1,  1434,    -1,  1433,  1434,    -1,  1435,  1365,    -1,   430,
      -1,   215,    -1,   529,    -1,   416,    -1,  1422,    -1,   545,
     485,  1454,   448,    -1,   315,    -1,   176,  1437,  1439,    -1,
    1438,    -1,  1480,    -1,  1440,    -1,  1439,  1440,    -1,  1416,
      -1,  1406,    -1,   502,  1454,    -1,   425,  1443,    -1,  1520,
      -1,  1443,     5,  1520,    -1,   579,  1454,    -1,   599,  1446,
      -1,  1447,    -1,  1446,     5,  1447,    -1,  1448,    -1,   568,
    1448,    -1,   568,   485,  1449,   448,    -1,  1478,    -1,  1478,
    1484,    -1,  1478,   669,  1484,    -1,  1447,    -1,  1449,     5,
    1447,    -1,  1445,  1451,  1452,  1453,    -1,    -1,  1444,    -1,
      -1,  1442,    -1,    -1,  1441,    -1,  1455,    -1,  1454,     6,
    1455,    -1,  1456,    -1,  1455,     7,  1456,    -1,  1457,    -1,
       9,  1457,    -1,  1468,    -1,   485,  1454,   448,    -1,   497,
    1516,    -1,   350,  1516,    -1,    -1,   496,  1461,    -1,  1522,
      -1,  1525,    -1,  1521,   675,   485,  1463,   448,    -1,  1521,
     675,  1516,    -1,  1521,   483,   485,  1463,   448,    -1,  1521,
     483,  1516,    -1,  1464,    -1,  1463,     5,  1464,    -1,  1583,
      -1,  1485,    -1,    -1,     9,    -1,  1521,  1465,   443,    -1,
    1521,  1465,   306,    -1,  1521,  1467,  1521,    -1,  1521,  1465,
     445,  1521,     7,  1521,    -1,  1521,   609,  1460,  1459,    -1,
    1521,   428,  1460,  1459,    -1,  1521,   726,  1460,  1459,    -1,
    1521,   429,  1460,  1459,    -1,  1521,  1465,    10,  1460,  1459,
      -1,    14,    -1,    17,    -1,    12,    -1,    13,    -1,   725,
      -1,    16,    -1,    15,    -1,  1466,    -1,  1462,    -1,  1458,
      -1,    -1,   638,    -1,   416,    -1,   529,    -1,  1471,    -1,
    1472,    -1,  1474,    -1,   375,    -1,   375,   485,  1475,   448,
      -1,    -1,   526,    -1,   526,   485,    26,   448,    -1,   453,
      -1,   453,   485,  1476,  1473,   448,    -1,   565,   485,  1476,
    1473,   448,    -1,   565,    -1,   590,    -1,   463,    -1,   437,
      -1,   376,    -1,   376,   485,  1475,   448,    -1,   377,    -1,
     377,   485,    26,   448,    -1,   377,   485,    26,     5,    26,
     448,    -1,   414,  1491,   678,  1492,    -1,   414,    -1,   426,
    1491,   678,  1492,    -1,   426,    -1,   426,  1491,   485,    26,
     448,   678,  1492,    -1,   627,    -1,   586,    -1,   478,    -1,
     478,   485,    26,   448,    -1,   478,   485,    26,     5,    26,
     448,    -1,    -1,     5,  1477,    -1,   555,   485,  1476,   448,
      -1,   618,    -1,   355,    -1,   555,    -1,   121,    -1,    26,
      -1,    26,    -1,    26,    -1,    25,   672,  1023,    -1,    25,
      -1,  1023,    -1,  1023,   642,  1023,    -1,  1023,   642,    25,
     672,  1023,    -1,  1023,   664,  1023,    -1,  1023,   664,  1023,
     642,  1023,    -1,  1023,   664,  1023,   642,    25,   672,  1023,
      -1,    25,   672,  1023,    -1,    25,    -1,  1023,    -1,  1023,
     642,  1023,    -1,  1023,   642,    25,   672,  1023,    -1,  1023,
     664,  1023,    -1,  1023,   664,  1023,   642,  1023,    -1,  1023,
     664,  1023,   642,    25,   672,  1023,    -1,  1023,    -1,    -1,
     513,    26,   481,    -1,   513,    26,     5,    26,   481,    -1,
    1483,    -1,   664,  1483,    -1,  1023,  1481,    -1,  1478,   672,
    1023,  1481,    -1,  1478,   672,    20,    -1,  1023,    -1,    25,
      -1,  1029,    -1,    26,    -1,  1487,    -1,   451,  1489,    -1,
     451,  1488,    -1,    -1,  1491,   678,  1492,    -1,    -1,  1490,
     678,  1490,    -1,   634,    -1,   566,    -1,   643,    -1,   605,
      -1,   508,    -1,   524,    -1,   423,    -1,   423,   485,    26,
     448,    -1,   634,    -1,   566,    -1,   643,    -1,   605,    -1,
     508,    -1,   524,    -1,   423,    -1,   634,    -1,   566,    -1,
     643,    -1,   605,    -1,   508,    -1,   524,    -1,   423,    -1,
     423,   485,    26,   448,    -1,  1023,    -1,  1023,   664,  1023,
      -1,    25,    -1,  1534,   556,  1017,    -1,    -1,  1534,   454,
    1384,   491,   648,  1503,  1496,    -1,    -1,  1534,   454,  1384,
     491,   157,   648,  1504,  1497,    -1,    -1,  1534,   454,  1384,
     195,  1504,  1498,    -1,    -1,  1534,   454,  1384,   196,   157,
     648,  1504,  1499,    -1,    -1,   344,    -1,   343,  1501,    -1,
    1502,    -1,  1501,     5,  1502,    -1,  1023,    -1,  1023,   672,
    1023,    -1,    25,   672,  1023,   672,  1023,    -1,  1504,    -1,
    1374,    -1,  1236,    -1,  1506,    -1,  1506,    -1,    -1,    -1,
     525,  1517,  1507,  1518,  1508,  1514,  1450,  1512,  1500,    -1,
     525,  1517,  1518,  1450,  1512,    -1,  1511,    -1,  1529,    -1,
     525,  1517,  1518,  1514,  1450,  1512,    -1,    -1,   578,  1469,
    1510,    -1,  1393,    -1,   389,  1513,  1343,    -1,  1393,   389,
    1513,  1343,    -1,  1023,    -1,    -1,   606,  1200,    -1,   525,
    1517,  1518,  1450,    -1,   485,   525,  1517,  1518,  1450,   448,
      -1,    -1,   638,    -1,   416,    -1,   529,    -1,  1519,    -1,
    1518,     5,  1519,    -1,  1521,    -1,  1521,  1023,    -1,  1521,
     669,  1023,    -1,  1521,    -1,  1522,    -1,    19,  1522,    -1,
      18,  1522,    -1,  1523,    -1,  1583,    -1,  1516,    -1,   638,
    1516,    -1,   639,  1516,    -1,   623,  1516,    -1,   664,  1023,
      -1,   664,  1023,   672,  1023,    -1,  1522,    21,  1521,    -1,
    1522,  1543,    -1,  1522,    20,  1521,    -1,  1522,    18,  1521,
      -1,  1522,    19,  1521,    -1,  1485,    -1,   537,    -1,   482,
      -1,   629,    -1,    20,    -1,   122,    -1,   641,   485,  1469,
    1521,   448,    -1,   653,   485,  1469,  1521,   448,    -1,   654,
     485,  1469,  1521,   448,    -1,   661,   485,  1469,  1521,   448,
      -1,   549,   485,  1469,  1521,   448,    -1,  1023,   485,  1524,
     448,    -1,   590,   485,  1524,   448,    -1,   485,  1521,   448,
      -1,   498,   485,  1544,   448,    -1,  1545,    -1,  1547,    -1,
    1521,    -1,  1524,     5,  1521,    -1,  1485,    -1,  1534,   404,
    1533,  1528,  1510,    -1,  1534,   393,  1533,  1528,   305,  1478,
    1530,    -1,  1534,   393,  1533,  1528,  1179,    -1,    -1,   379,
    1529,    -1,    25,    -1,  1179,    -1,    -1,   485,  1531,   448,
      -1,  1532,    -1,  1531,     5,  1532,    -1,  1023,    -1,    25,
      -1,  1179,    -1,    -1,   323,  1535,   648,    -1,  1024,    -1,
    1541,    -1,  1540,    -1,  1537,    -1,   372,  1538,   678,  1538,
      -1,   353,  1478,   672,  1539,   678,  1539,    -1,  1023,    -1,
    1023,    -1,   278,  1478,    -1,   348,  1478,  1542,    -1,   327,
      -1,   231,    -1,   149,    -1,   150,    -1,   151,    -1,   152,
      -1,   153,    -1,   154,    -1,   451,     5,  1491,   678,  1492,
      -1,  1583,     5,  1491,   678,  1492,    -1,   451,  1491,   678,
    1492,    -1,  1521,     5,  1491,   678,  1492,    -1,  1546,    -1,
    1546,  1491,   678,  1492,    -1,    38,    -1,  1548,    -1,  1548,
    1491,   485,    26,   448,   678,  1492,    -1,  1548,  1491,   678,
    1492,    -1,    39,    -1,    -1,   660,  1550,  1551,   246,    -1,
    1552,    -1,  1551,  1552,    -1,    33,    -1,  1553,    -1,  1555,
      -1,    -1,   247,  1554,  1583,    -1,    -1,   606,  1556,  1200,
      -1,    -1,    -1,   531,  1478,  1558,  1561,  1559,  1560,    -1,
      -1,   207,  1017,    -1,   579,  1454,    -1,   107,  1565,   448,
      14,   485,  1566,   448,    -1,   103,  1566,   448,    -1,   104,
    1566,   448,    -1,   636,  1562,    -1,   106,  1566,    -1,   105,
    1566,    -1,  1564,    -1,  1562,     5,  1564,    -1,  1482,    -1,
    1563,    14,  1567,    -1,  1563,    -1,  1565,     5,  1563,    -1,
    1567,    -1,  1566,     5,  1567,    -1,   536,    -1,  1568,    -1,
    1569,    -1,    19,  1569,    -1,    18,  1569,    -1,  1571,    -1,
    1516,    -1,   664,  1023,    -1,   664,  1023,   672,  1023,    -1,
     664,  1023,   513,    26,   481,    -1,   664,  1023,   672,  1023,
     513,    26,   481,    -1,   664,  1023,   513,    26,     5,    26,
     481,    -1,   664,  1023,   672,  1023,   513,    26,     5,    26,
     481,    -1,  1570,    -1,  1485,    -1,   537,    -1,   482,    -1,
     629,    -1,   122,    -1,  1569,    21,  1568,    -1,  1569,  1543,
      -1,  1569,    20,  1568,    -1,  1569,    18,  1568,    -1,  1569,
      19,  1568,    -1,   641,   485,  1469,  1568,   448,    -1,   653,
     485,  1469,  1568,   448,    -1,   654,   485,  1469,  1568,   448,
      -1,   661,   485,  1469,  1568,   448,    -1,   549,   485,  1469,
    1568,   448,    -1,  1023,   485,  1572,   448,    -1,   590,   485,
    1572,   448,    -1,   485,  1568,   448,    -1,   498,   485,  1544,
     448,    -1,  1545,    -1,  1547,    -1,  1583,    -1,  1568,    -1,
    1572,     5,  1568,    -1,    -1,   438,  1208,   609,  1574,  1575,
      -1,  1576,    -1,  1575,     5,  1576,    -1,  1478,   672,  1482,
      -1,  1478,   672,    20,    -1,  1579,    -1,  1579,    -1,   247,
    1580,    -1,  1580,    -1,  1581,    -1,    25,   672,  1581,    -1,
    1582,    -1,  1581,   672,  1582,    -1,  1581,   672,    20,    -1,
    1584,    -1,  1023,    -1,  1578,    -1,  1578,   475,  1578,    -1,
    1023,  1585,    -1,   513,  1586,   481,    -1,   513,  1586,   481,
     513,  1586,   481,    -1,  1587,    -1,  1586,     5,  1587,    -1,
     742,    -1,    34,    -1,    -1,    -1,   580,  1590,   928,  1591,
    1604,   383,    -1,    -1,   711,   971,    -1,    -1,   714,    -1,
     238,    -1,   333,  1018,    -1,   127,  1018,    -1,   363,    -1,
     362,    -1,   364,  1020,  1592,  1593,    -1,   546,   971,  1593,
      -1,   161,    -1,   192,  1018,    -1,   928,   619,     5,   928,
     449,    -1,   562,   928,    -1,   320,  1018,    -1,   158,  1599,
       8,  1600,  1598,    -1,    -1,   599,   928,    -1,  1023,    -1,
    1023,    -1,   304,  1018,    -1,   307,  1018,   678,   928,     5,
     928,    -1,   307,  1018,   671,   928,     5,   928,    -1,    27,
      -1,    -1,  1606,    -1,  1607,  1289,    -1,  1605,    -1,  1606,
    1605,    -1,    -1,  1608,  1609,    -1,   735,    -1,   736,    -1,
     737,    -1,   738,    -1,   755,    -1,   779,    -1,   800,    -1,
     801,    -1,   807,    -1,   826,    -1,   900,    -1,   901,    -1,
     902,    -1,   903,    -1,   914,    -1,   915,    -1,   916,    -1,
     917,    -1,   918,    -1,   919,    -1,   920,    -1,   973,    -1,
    1004,    -1,  1008,    -1,  1030,    -1,  1032,    -1,  1035,    -1,
    1036,    -1,  1037,    -1,  1038,    -1,  1051,    -1,  1061,    -1,
    1085,    -1,  1086,    -1,  1088,    -1,  1092,    -1,  1107,    -1,
    1108,    -1,  1112,    -1,  1113,    -1,  1114,    -1,  1115,    -1,
    1125,    -1,  1140,    -1,  1156,    -1,  1167,    -1,  1168,    -1,
    1169,    -1,  1173,    -1,  1210,    -1,  1213,    -1,  1215,    -1,
    1221,    -1,  1222,    -1,  1225,    -1,  1228,    -1,  1233,    -1,
    1235,    -1,  1237,    -1,  1240,    -1,  1247,    -1,  1252,    -1,
    1257,    -1,  1258,    -1,  1259,    -1,  1271,    -1,  1325,    -1,
    1327,    -1,  1329,    -1,  1348,    -1,  1349,    -1,  1369,    -1,
    1372,    -1,  1401,    -1,  1403,    -1,  1494,    -1,  1495,    -1,
    1526,    -1,  1527,    -1,  1549,    -1,  1573,    -1,  1588,    -1,
    1589,    -1,  1594,    -1,  1595,    -1,  1597,    -1,  1601,    -1,
    1602,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1010,  1010,  1013,  1016,  1022,  1028,  1035,  1039,  1039,
    1045,  1064,  1065,  1066,  1067,  1068,  1079,  1085,  1086,  1087,
    1088,  1089,  1094,  1095,  1106,  1109,  1112,  1112,  1116,  1119,
    1120,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1145,  1146,
    1149,  1149,  1164,  1165,  1168,  1174,  1176,  1187,  1189,  1191,
    1193,  1197,  1199,  1261,  1265,  1269,  1269,  1279,  1283,  1286,
    1287,  1296,  1302,  1296,  1316,  1322,  1316,  1338,  1343,  1347,
    1338,  1359,  1363,  1359,  1371,  1376,  1371,  1395,  1402,  1406,
    1394,  1432,  1432,  1436,  1437,  1438,  1443,  1446,  1451,  1455,
    1463,  1464,  1467,  1467,  1473,  1477,  1492,  1490,  1508,  1508,
    1523,  1523,  1526,  1526,  1530,  1533,  1533,  1533,  1540,  1541,
    1540,  1548,  1548,  1559,  1559,  1572,  1596,  1604,  1572,  1620,
    1625,  1633,  1634,  1638,  1648,  1651,  1654,  1657,  1660,  1663,
    1676,  1681,  1681,  1682,  1682,  1685,  1690,  1690,  1694,  1713,
    1718,  1712,  1729,  1735,  1743,  1744,  1747,  1747,  1750,  1754,
    1759,  1766,  1766,  1770,  1770,  1771,  1771,  1772,  1772,  1773,
    1773,  1774,  1774,  1782,  1786,  1792,  1796,  1811,  1814,  1817,
    1820,  1823,  1826,  1832,  1843,  1848,  1861,  1865,  1880,  1881,
    1885,  1885,  1889,  1889,  1889,  1890,  1895,  1895,  1898,  1898,
    1907,  1908,  1909,  1912,  1916,  1917,  1917,  1934,  1934,  1934,
    1934,  1938,  1945,  1946,  1949,  1949,  1953,  1954,  1955,  1956,
    1961,  1961,  1967,  1967,  1976,  1973,  1989,  1989,  1991,  1991,
    1993,  1995,  1997,  1999,  2002,  2007,  2008,  2010,  2015,  2015,
    2016,  2016,  2020,  2020,  2032,  2032,  2037,  2041,  2043,  2044,
    2047,  2047,  2047,  2051,  2052,  2053,  2054,  2055,  2056,  2057,
    2058,  2059,  2060,  2061,  2062,  2065,  2066,  2067,  2068,  2072,
    2077,  2082,  2086,  2089,  2093,  2093,  2094,  2094,  2095,  2095,
    2096,  2097,  2098,  2099,  2100,  2101,  2104,  2105,  2106,  2136,
    2136,  2141,  2146,  2148,  2148,  2155,  2159,  2159,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2175,  2175,  2178,  2180,  2186,
    2188,  2194,  2202,  2202,  2205,  2206,  2207,  2208,  2209,  2210,
    2211,  2217,  2220,  2220,  2233,  2233,  2240,  2241,  2242,  2244,
    2245,  2246,  2250,  2251,  2252,  2253,  2258,  2264,  2270,  2271,
    2273,  2275,  2276,  2277,  2278,  2279,  2280,  2283,  2284,  2291,
    2299,  2299,  2307,  2304,  2319,  2319,  2321,  2321,  2329,  2329,
    2332,  2335,  2336,  2341,  2353,  2357,  2360,  2363,  2364,  2365,
    2366,  2367,  2372,  2379,  2385,  2390,  2395,  2390,  2408,  2410,
    2415,  2420,  2420,  2420,  2424,  2424,  2427,  2427,  2434,  2434,
    2441,  2441,  2452,  2470,  2476,  2500,  2503,  2518,  2521,  2534,
    2536,  2538,  2540,  2542,  2544,  2546,  2552,  2554,  2558,  2560,
    2562,  2564,  2566,  2568,  2570,  2576,  2593,  2594,  2595,  2596,
    2600,  2601,  2602,  2606,  2611,  2618,  2619,  2620,  2621,  2622,
    2623,  2624,  2625,  2626,  2627,  2628,  2635,  2635,  2640,  2640,
    2643,  2649,  2657,  2663,  2673,  2674,  2682,  2703,  2707,  2712,
    2717,  2719,  2722,  2740,  2745,  2751,  2756,  2761,  2762,  2768,
    2839,  2850,  2859,  2867,  2867,  2882,  2886,  2893,  2896,  2904,
    2908,  2911,  2917,  2926,  2931,  2939,  2942,  2945,  2950,  2957,
    2962,  2967,  2972,  2982,  2990,  2998,  3003,  3007,  3012,  3016,
    3020,  3027,  3030,  3033,  3037,  3041,  3045,  3049,  3057,  3067,
    3072,  3065,  3088,  3093,  3088,  3107,  3112,  3107,  3133,  3133,
    3133,  3136,  3136,  3136,  3140,  3140,  3140,  3144,  3144,  3144,
    3148,  3154,  3160,  3166,  3174,  3180,  3188,  3194,  3203,  3209,
    3216,  3223,  3232,  3238,  3244,  3251,  3257,  3263,  3269,  3277,
    3283,  3289,  3298,  3304,  3310,  3320,  3320,  3324,  3328,  3329,
    3340,  3341,  3347,  3357,  3367,  3377,  3378,  3381,  3386,  3392,
    3396,  3400,  3403,  3409,  3412,  3415,  3432,  3435,  3441,  3442,
    3443,  3447,  3448,  3449,  3450,  3451,  3453,  3454,  3455,  3457,
    3458,  3459,  3463,  3464,  3469,  3473,  3478,  3482,  3497,  3501,
    3507,  3496,  3520,  3521,  3533,  3539,  3533,  3553,  3553,  3555,
    3556,  3560,  3560,  3564,  3564,  3569,  3569,  3576,  3577,  3581,
    3581,  3585,  3585,  3590,  3590,  3597,  3601,  3602,  3603,  3608,
    3608,  3611,  3611,  3615,  3615,  3619,  3619,  3623,  3623,  3628,
    3628,  3633,  3633,  3638,  3638,  3643,  3643,  3659,  3663,  3658,
    3671,  3674,  3688,  3705,  3706,  3707,  3708,  3709,  3710,  3711,
    3714,  3714,  3717,  3719,  3722,  3725,  3728,  3733,  3738,  3741,
    3746,  3751,  3756,  3763,  3764,  3771,  3778,  3780,  3786,  3791,
    3796,  3801,  3801,  3804,  3810,  3815,  3818,  3825,  3825,  3827,
    3830,  3833,  3838,  3843,  3848,  3855,  3866,  3866,  3928,  3936,
    3937,  3945,  3952,  3952,  3956,  3961,  3967,  3971,  3975,  3981,
    3985,  3989,  3995,  3995,  4003,  4004,  4008,  4008,  4012,  4013,
    4016,  4019,  4019,  4022,  4024,  4024,  4027,  4029,  4029,  4030,
    4032,  4032,  4041,  4048,  4039,  4069,  4069,  4069,  4072,  4074,
    4072,  4081,  4084,  4091,  4096,  4107,  4107,  4111,  4117,  4117,
    4121,  4122,  4126,  4136,  4137,  4138,  4141,  4143,  4148,  4148,
    4152,  4151,  4159,  4158,  4165,  4165,  4171,  4171,  4178,  4178,
    4184,  4184,  4190,  4190,  4196,  4196,  4200,  4200,  4201,  4201,
    4202,  4202,  4203,  4203,  4207,  4207,  4218,  4222,  4228,  4232,
    4237,  4242,  4247,  4248,  4249,  4253,  4252,  4265,  4270,  4275,
    4275,  4291,  4297,  4298,  4299,  4300,  4301,  4311,  4325,  4325,
    4328,  4335,  4336,  4337,  4338,  4339,  4340,  4341,  4342,  4343,
    4348,  4348,  4350,  4353,  4353,  4355,  4359,  4362,  4363,  4366,
    4366,  4371,  4374,  4375,  4376,  4377,  4378,  4379,  4380,  4381,
    4382,  4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,  4391,
    4395,  4413,  4413,  4413,  4440,  4451,  4458,  4464,  4470,  4476,
    4488,  4511,  4512,  4515,  4519,  4518,  4536,  4536,  4540,  4541,
    4549,  4550,  4551,  4552,  4553,  4554,  4555,  4562,  4563,  4565,
    4566,  4570,  4575,  4576,  4577,  4578,  4579,  4580,  4581,  4582,
    4583,  4586,  4588,  4588,  4590,  4594,  4594,  4603,  4609,  4625,
    4631,  4602,  4645,  4659,  4670,  4658,  4683,  4690,  4690,  4695,
    4701,  4709,  4714,  4715,  4718,  4721,  4721,  4729,  4735,  4746,
    4747,  4755,  4761,  4755,  4772,  4773,  4777,  4777,  4784,  4784,
    4799,  4799,  4813,  4824,  4823,  4835,  4831,  4848,  4845,  4858,
    4858,  4860,  4861,  4863,  4864,  4867,  4868,  4869,  4871,  4876,
    4881,  4887,  4889,  4890,  4893,  4894,  4897,  4899,  4906,  4909,
    4912,  4915,  4919,  4923,  4924,  4925,  4926,  4927,  4931,  4936,
    4936,  4939,  4966,  5024,  5024,  5027,  5031,  5035,  5078,  5120,
    5121,  5122,  5125,  5139,  5151,  5151,  5156,  5157,  5163,  5228,
    5233,  5240,  5245,  5253,  5259,  5292,  5295,  5296,  5337,  5380,
    5381,  5385,  5386,  5390,  5443,  5448,  5452,  5457,  5468,  5475,
    5483,  5483,  5486,  5487,  5488,  5489,  5490,  5493,  5496,  5502,
    5505,  5509,  5514,  5522,  5527,  5534,  5536,  5542,  5544,  5544,
    5544,  5564,  5571,  5578,  5581,  5595,  5602,  5603,  5606,  5607,
    5611,  5617,  5622,  5628,  5629,  5634,  5638,  5638,  5642,  5643,
    5646,  5647,  5651,  5659,  5662,  5668,  5669,  5671,  5673,  5677,
    5677,  5678,  5683,  5691,  5692,  5697,  5698,  5700,  5713,  5715,
    5716,  5719,  5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,
    5728,  5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,
    5738,  5739,  5740,  5741,  5742,  5743,  5744,  5745,  5746,  5750,
    5751,  5755,  5756,  5770,  5778,  5778,  5780,  5784,  5788,  5792,
    5796,  5801,  5816,  5814,  5834,  5835,  5839,  5844,  5845,  5849,
    5850,  5852,  5853,  5855,  5855,  5864,  5873,  5873,  5883,  5884,
    5889,  5890,  5893,  5906,  5920,  5924,  5928,  5932,  5939,  5940,
    5943,  5943,  5947,  5950,  5950,  5952,  5958,  5966,  5972,  5974,
    5978,  5981,  5981,  5984,  5984,  5989,  5989,  5998,  5998,  6002,
    6002,  6003,  6003,  6004,  6004,  6018,  6018,  6038,  6039,  6040,
    6041,  6042,  6043,  6046,  6046,  6052,  6052,  6055,  6055,  6071,
    6072,  6073,  6082,  6094,  6095,  6098,  6099,  6102,  6105,  6105,
    6110,  6110,  6133,  6134,  6140,  6145,  6151,  6152,  6153,  6157,
    6158,  6159,  6160,  6164,  6174,  6176,  6181,  6184,  6189,  6195,
    6202,  6209,  6218,  6225,  6232,  6239,  6246,  6255,  6255,  6257,
    6257,  6260,  6261,  6262,  6263,  6264,  6265,  6266,  6267,  6268,
    6269,  6272,  6272,  6275,  6276,  6277,  6278,  6281,  6281,  6284,
    6284,  6287,  6288,  6289,  6290,  6291,  6292,  6293,  6294,  6296,
    6297,  6298,  6299,  6301,  6302,  6303,  6304,  6306,  6307,  6308,
    6309,  6310,  6311,  6312,  6313,  6317,  6325,  6335,  6348,  6359,
    6370,  6374,  6378,  6384,  6347,  6397,  6400,  6408,  6420,  6422,
    6427,  6437,  6447,  6450,  6454,  6462,  6426,  6471,  6475,  6479,
    6483,  6475,  6493,  6494,  6495,  6496,  6501,  6502,  6503,  6504,
    6505,  6506,  6507,  6508,  6512,  6513,  6516,  6521,  6528,  6529,
    6530,  6535,  6536,  6542,  6542,  6542,  6547,  6547,  6547,  6555,
    6556,  6560,  6561,  6566,  6567,  6568,  6569,  6570,  6573,  6575,
    6575,  6578,  6579,  6583,  6584,  6587,  6588,  6591,  6594,  6597,
    6603,  6604,  6616,  6617,  6622,  6623,  6624,  6628,  6631,  6637,
    6640,  6648,  6649,  6655,  6659,  6663,  6669,  6672,  6681,  6684,
    6687,  6690,  6693,  6696,  6699,  6706,  6709,  6716,  6719,  6725,
    6728,  6735,  6738,  6745,  6746,  6751,  6755,  6758,  6764,  6767,
    6773,  6780,  6781,  6785,  6795,  6798,  6804,  6806,  6811,  6812,
    6816,  6818,  6824,  6825,  6838,  6850,  6851,  6852,  6853,  6854,
    6855,  6856,  6857,  6858,  6861,  6864,  6870,  6870,  6876,  6876,
    6887,  6900,  6910,  6910,  6915,  6915,  6919,  6923,  6924,  6930,
    6931,  6936,  6940,  6947,  6950,  6957,  6956,  6967,  6971,  6975,
    6982,  6985,  6985,  6998,  7002,  7002,  7017,  7019,  7021,  7023,
    7025,  7027,  7029,  7031,  7037,  7047,  7054,  7059,  7060,  7064,
    7067,  7068,  7071,  7072,  7073,  7076,  7081,  7088,  7089,  7096,
    7108,  7109,  7110,  7113,  7113,  7118,  7123,  7128,  7133,  7134,
    7137,  7138,  7143,  7148,  7152,  7157,  7158,  7162,  7169,  7170,
    7171,  7172,  7177,  7178,  7179,  7182,  7183,  7184,  7188,  7189,
    7190,  7194,  7195,  7199,  7200,  7201,  7202,  7203,  7204,  7207,
    7208,  7213,  7214,  7219,  7220,  7225,  7226,  7231,  7236,  7237,
    7242,  7243,  7247,  7248,  7253,  7260,  7265,  7270,  7274,  7275,
    7280,  7281,  7287,  7290,  7294,  7299,  7300,  7306,  7309,  7312,
    7319,  7320,  7321,  7322,  7336,  7341,  7342,  7345,  7347,  7354,
    7357,  7363,  7371,  7375,  7379,  7383,  7388,  7391,  7394,  7401,
    7408,  7413,  7417,  7418,  7424,  7427,  7438,  7445,  7451,  7454,
    7461,  7468,  7474,  7475,  7481,  7482,  7483,  7486,  7487,  7494,
    7501,  7501,  7505,  7513,  7514,  7517,  7520,  7525,  7526,  7531,
    7534,  7540,  7543,  7549,  7552,  7558,  7561,  7568,  7569,  7598,
    7599,  7603,  7611,  7616,  7619,  7622,  7625,  7631,  7632,  7636,
    7639,  7642,  7643,  7648,  7651,  7654,  7657,  7660,  7663,  7666,
    7669,  7674,  7680,  7681,  7682,  7683,  7686,  7687,  7688,  7693,
    7696,  7700,  7706,  7707,  7708,  7709,  7721,  7722,  7723,  7727,
    7728,  7732,  7733,  7734,  7735,  7736,  7738,  7747,  7754,  7755,
    7756,  7757,  7758,  7759,  7760,  7762,  7764,  7766,  7767,  7769,
    7770,  7772,  7773,  7774,  7775,  7777,  7781,  7782,  7788,  7790,
    7791,  7792,  7793,  7798,  7802,  7806,  7810,  7817,  7821,  7822,
    7823,  7831,  7832,  7833,  7844,  7851,  7856,  7857,  7858,  7866,
    7867,  7868,  7885,  7894,  7895,  7896,  7900,  7903,  7908,  7913,
    7918,  7926,  7930,  7935,  7936,  7944,  7947,  7950,  7964,  7978,
    7991,  7992,  7996,  7996,  7996,  7996,  7996,  7996,  7997,  8000,
    8017,  8017,  8017,  8017,  8017,  8017,  8017,  8018,  8018,  8018,
    8018,  8018,  8018,  8018,  8018,  8021,  8022,  8023,  8026,  8035,
    8035,  8041,  8041,  8048,  8048,  8054,  8054,  8062,  8063,  8064,
    8067,  8067,  8070,  8071,  8072,  8083,  8086,  8092,  8097,  8104,
    8117,  8118,  8115,  8136,  8147,  8150,  8155,  8167,  8170,  8174,
    8177,  8178,  8188,  8191,  8192,  8201,  8210,  8215,  8216,  8217,
    8218,  8225,  8228,  8234,  8237,  8244,  8256,  8265,  8268,  8271,
    8277,  8285,  8288,  8289,  8290,  8291,  8292,  8295,  8301,  8303,
    8305,  8307,  8309,  8311,  8312,  8313,  8314,  8315,  8316,  8317,
    8319,  8321,  8323,  8325,  8327,  8329,  8331,  8332,  8334,  8335,
    8341,  8342,  8349,  8352,  8360,  8364,  8371,  8371,  8375,  8375,
    8380,  8380,  8384,  8384,  8388,  8394,  8394,  8397,  8397,  8403,
    8410,  8411,  8412,  8416,  8417,  8420,  8421,  8425,  8431,  8441,
    8442,  8450,  8451,  8452,  8453,  8454,  8455,  8459,  8460,  8461,
    8462,  8466,  8467,  8471,  8487,  8488,  8489,  8493,  8507,  8507,
    8519,  8520,  8524,  8525,  8526,  8850,  8850,  8857,  8857,  8945,
    8949,  8945,  8958,  8962,  8968,  8976,  8986,  8996,  9008,  9011,
    9030,  9056,  9059,  9065,  9068,  9073,  9076,  9084,  9092,  9105,
    9108,  9116,  9119,  9122,  9130,  9134,  9135,  9136,  9137,  9138,
    9139,  9140,  9141,  9145,  9146,  9147,  9148,  9149,  9155,  9156,
    9157,  9158,  9159,  9160,  9161,  9162,  9163,  9164,  9165,  9166,
    9167,  9168,  9169,  9170,  9175,  9181,  9182,  9190,  9190,  9198,
    9198,  9202,  9206,  9221,  9236,  9242,  9244,  9252,  9253,  9257,
    9258,  9261,  9268,  9271,  9300,  9326,  9380,  9416,  9425,  9436,
    9439,  9444,  9458,  9472,  9475,  9471,  9494,  9494,  9500,  9501,
    9504,  9505,  9506,  9507,  9508,  9509,  9510,  9521,  9524,  9529,
    9533,  9538,  9542,  9547,  9551,  9554,  9558,  9561,  9566,  9570,
    9581,  9587,  9587,  9588,  9589,  9596,  9606,  9606,  9608,  9609,
    9610,  9611,  9612,  9613,  9614,  9615,  9616,  9617,  9618,  9619,
    9620,  9621,  9622,  9623,  9624,  9625,  9626,  9627,  9628,  9629,
    9630,  9631,  9632,  9633,  9634,  9635,  9636,  9637,  9638,  9639,
    9640,  9641,  9642,  9643,  9644,  9645,  9646,  9647,  9648,  9649,
    9650,  9651,  9652,  9653,  9654,  9655,  9656,  9657,  9658,  9659,
    9660,  9661,  9662,  9663,  9664,  9665,  9666,  9667,  9668,  9669,
    9670,  9671,  9672,  9673,  9674,  9675,  9676,  9677,  9678,  9679,
    9680,  9681,  9682,  9683,  9684,  9685,  9686,  9687,  9688,  9689,
    9690,  9691,  9692,  9693,  9694,  9695
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
       0,   256,  1717,  1718,  1719,  1620,  1660,  1615,  1552,  1635,
    1433,  1538,  1534,  1450,  1610,  1352,  1409,  1481,  1646,  1633,
    1539,  1566,  1634,  1416,  1720,  1721,  1722,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1000,  1001,  1002,  1003,
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
    1530,  1531,  1532,  1533,  1535,  1536,  1537,  1540,  1541,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1611,  1612,  1613,  1614,  1616,
    1617,  1618,  1619,  1621,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1636,  1637,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1645,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,
    1713,  1714,  1715,  1716
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   734,   735,   736,   737,   738,   739,   739,   740,   740,
     741,   742,   742,   742,   742,   742,   742,   743,   743,   743,
     743,   743,   744,   744,   745,   745,   747,   746,   746,   748,
     748,   749,   749,   749,   749,   749,   749,   749,   749,   749,
     749,   749,   749,   749,   749,   749,   749,   749,   750,   750,
     752,   751,   753,   753,   754,   754,   754,   754,   754,   754,
     754,   754,   754,   755,   756,   757,   756,   756,   756,   756,
     756,   758,   759,   756,   760,   761,   756,   762,   763,   764,
     756,   765,   766,   756,   767,   768,   756,   769,   770,   771,
     756,   772,   772,   773,   773,   773,   774,   774,   775,   775,
     776,   776,   777,   777,   778,   778,   780,   779,   781,   779,
     782,   782,   783,   783,   784,   785,   786,   785,   787,   788,
     787,   790,   789,   792,   791,   794,   795,   796,   793,   797,
     797,   798,   798,   799,   800,   800,   800,   800,   800,   800,
     801,   802,   802,   803,   803,   804,   805,   805,   806,   808,
     809,   807,   810,   810,   811,   811,   812,   812,   813,   813,
     813,   814,   814,   816,   815,   817,   815,   818,   815,   819,
     815,   820,   815,   821,   821,   822,   822,   823,   823,   823,
     823,   823,   823,   824,   825,   825,   826,   826,   827,   827,
     828,   828,   830,   831,   829,   829,   832,   832,   834,   833,
     835,   835,   835,   835,   835,   836,   835,   837,   837,   837,
     837,   838,   839,   839,   840,   840,   841,   841,   841,   841,
     843,   842,   844,   842,   845,   842,   846,   846,   847,   847,
     848,   849,   849,   849,   850,   851,   851,   851,   853,   852,
     854,   852,   855,   852,   856,   856,   857,   858,   859,   859,
     861,   862,   860,   863,   863,   863,   863,   863,   863,   863,
     863,   863,   863,   863,   863,   863,   863,   863,   863,   863,
     863,   863,   863,   863,   864,   863,   865,   863,   866,   863,
     863,   863,   863,   863,   863,   863,   863,   863,   863,   867,
     867,   868,   869,   870,   870,   871,   873,   872,   874,   874,
     874,   874,   874,   874,   874,   876,   875,   877,   877,   878,
     878,   879,   881,   880,   882,   882,   882,   882,   882,   882,
     882,   883,   884,   884,   886,   885,   887,   887,   887,   887,
     887,   887,   887,   887,   887,   887,   887,   887,   887,   887,
     887,   887,   887,   887,   887,   887,   887,   887,   887,   888,
     890,   889,   891,   889,   893,   892,   894,   892,   895,   895,
     896,   897,   897,   898,   899,   899,   899,   899,   899,   899,
     899,   899,   900,   901,   902,   904,   905,   903,   906,   906,
     907,   908,   908,   908,   909,   909,   911,   910,   912,   910,
     913,   910,   914,   915,   916,   917,   917,   918,   918,   919,
     919,   919,   919,   919,   919,   919,   919,   919,   920,   920,
     920,   920,   920,   920,   920,   920,   921,   921,   921,   921,
     921,   921,   921,   921,   921,   922,   922,   922,   922,   922,
     922,   922,   922,   922,   922,   922,   923,   923,   924,   924,
     925,   925,   926,   926,   927,   927,   928,   929,   929,   929,
     929,   929,   929,   930,   930,   930,   930,   931,   931,   932,
     933,   933,   933,   934,   933,   935,   935,   936,   936,   937,
     937,   937,   937,   938,   938,   939,   939,   939,   939,   939,
     939,   939,   939,   940,   941,   942,   942,   942,   942,   942,
     942,   943,   943,   943,   943,   943,   943,   943,   944,   946,
     947,   945,   948,   949,   945,   950,   951,   945,   953,   954,
     952,   955,   956,   952,   957,   958,   952,   959,   960,   952,
     952,   952,   952,   952,   952,   952,   952,   952,   952,   952,
     952,   952,   952,   952,   952,   952,   952,   952,   952,   952,
     952,   952,   952,   952,   952,   961,   961,   962,   963,   963,
     963,   963,   963,   963,   963,   963,   963,   964,   964,   965,
     965,   965,   965,   966,   966,   966,   967,   967,   968,   968,
     968,   969,   969,   969,   969,   969,   969,   969,   969,   969,
     969,   969,   970,   970,   971,   971,   972,   972,   974,   975,
     976,   973,   977,   977,   979,   980,   978,   981,   981,   982,
     982,   983,   983,   985,   984,   986,   984,   987,   987,   988,
     988,   990,   989,   991,   989,   992,   993,   993,   993,   994,
     994,   995,   995,   996,   996,   997,   997,   999,   998,  1000,
     998,  1001,   998,  1002,   998,  1003,   998,  1005,  1006,  1004,
    1007,  1007,  1008,  1009,  1009,  1009,  1009,  1009,  1009,  1009,
    1010,  1010,  1011,  1012,  1013,  1014,  1014,  1014,  1014,  1014,
    1014,  1014,  1014,  1015,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1022,  1023,  1024,  1025,  1025,  1026,  1026,  1027,
    1027,  1027,  1027,  1027,  1027,  1028,  1029,  1029,  1030,  1031,
    1031,  1032,  1033,  1033,  1034,  1035,  1036,  1036,  1036,  1037,
    1037,  1037,  1039,  1038,  1040,  1040,  1041,  1041,  1042,  1042,
    1043,  1044,  1044,  1045,  1046,  1046,  1047,  1048,  1048,  1049,
    1050,  1050,  1052,  1053,  1051,  1054,  1055,  1054,  1056,  1057,
    1054,  1058,  1058,  1059,  1060,  1062,  1061,  1061,  1063,  1063,
    1064,  1064,  1065,  1066,  1066,  1066,  1067,  1067,  1068,  1068,
    1070,  1069,  1071,  1069,  1072,  1069,  1073,  1069,  1074,  1069,
    1075,  1069,  1076,  1069,  1077,  1069,  1078,  1069,  1079,  1069,
    1080,  1069,  1081,  1069,  1082,  1069,  1083,  1083,  1084,  1084,
    1085,  1086,  1087,  1087,  1087,  1089,  1088,  1090,  1090,  1091,
    1090,  1092,  1093,  1093,  1093,  1093,  1093,  1093,  1094,  1094,
    1095,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,
    1098,  1097,  1097,  1100,  1099,  1101,  1102,  1103,  1103,  1104,
    1104,  1105,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,
    1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,
    1107,  1109,  1110,  1108,  1111,  1111,  1112,  1113,  1114,  1115,
    1115,  1116,  1116,  1117,  1119,  1118,  1120,  1120,  1121,  1121,
    1122,  1122,  1122,  1122,  1122,  1122,  1122,  1123,  1123,  1124,
    1124,  1125,  1126,  1126,  1126,  1126,  1126,  1126,  1126,  1126,
    1126,  1127,  1128,  1128,  1129,  1130,  1130,  1132,  1133,  1134,
    1135,  1131,  1136,  1138,  1139,  1137,  1140,  1141,  1141,  1142,
    1142,  1143,  1144,  1144,  1145,  1147,  1146,  1148,  1148,  1148,
    1148,  1150,  1151,  1149,  1152,  1152,  1154,  1153,  1155,  1153,
    1157,  1156,  1158,  1160,  1159,  1161,  1159,  1162,  1159,  1163,
    1163,  1164,  1164,  1165,  1165,  1166,  1166,  1166,  1167,  1168,
    1169,  1170,  1170,  1170,  1171,  1171,  1172,  1172,  1173,  1174,
    1174,  1174,  1174,  1175,  1175,  1175,  1175,  1175,  1176,  1177,
    1177,  1178,  1179,  1180,  1180,  1181,  1182,  1182,  1182,  1182,
    1182,  1182,  1183,  1184,  1185,  1185,  1186,  1186,  1187,  1188,
    1188,  1189,  1189,  1190,  1191,  1192,  1192,  1192,  1192,  1192,
    1192,  1193,  1193,  1194,  1195,  1195,  1196,  1196,  1197,  1197,
    1198,  1198,  1199,  1199,  1199,  1199,  1199,  1200,  1200,  1201,
    1201,  1202,  1202,  1203,  1204,  1205,  1205,  1206,  1207,  1207,
    1207,  1208,  1208,  1209,  1209,  1210,  1211,  1211,  1212,  1212,
    1213,  1214,  1215,  1216,  1216,  1217,  1218,  1218,  1219,  1219,
    1220,  1220,  1221,  1222,  1222,  1223,  1223,  1223,  1223,  1224,
    1224,  1224,  1225,  1226,  1226,  1227,  1227,  1227,  1228,  1229,
    1229,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,
    1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,
    1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1231,
    1231,  1232,  1232,  1233,  1234,  1234,  1235,  1235,  1235,  1235,
    1235,  1236,  1238,  1237,  1239,  1239,  1240,  1241,  1241,  1242,
    1242,  1243,  1243,  1245,  1244,  1246,  1248,  1247,  1249,  1249,
    1250,  1250,  1251,  1251,  1252,  1252,  1252,  1252,  1253,  1253,
    1254,  1254,  1255,  1256,  1256,  1257,  1258,  1259,  1260,  1261,
    1261,  1262,  1262,  1264,  1263,  1265,  1263,  1266,  1263,  1267,
    1263,  1268,  1263,  1269,  1263,  1270,  1263,  1271,  1271,  1271,
    1271,  1271,  1271,  1273,  1272,  1274,  1274,  1276,  1275,  1275,
    1275,  1275,  1275,  1277,  1277,  1278,  1278,  1279,  1280,  1280,
    1282,  1281,  1283,  1283,  1284,  1285,  1286,  1286,  1286,  1287,
    1287,  1287,  1287,  1288,  1289,  1289,  1290,  1290,  1291,  1292,
    1292,  1292,  1292,  1292,  1292,  1292,  1292,  1293,  1293,  1294,
    1294,  1295,  1295,  1295,  1295,  1295,  1295,  1295,  1295,  1295,
    1295,  1296,  1296,  1297,  1297,  1297,  1297,  1298,  1298,  1299,
    1299,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,
    1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,
    1300,  1300,  1300,  1300,  1300,  1301,  1301,  1301,  1303,  1304,
    1305,  1306,  1307,  1308,  1302,  1309,  1309,  1310,  1311,  1311,
    1313,  1314,  1315,  1316,  1317,  1318,  1312,  1319,  1321,  1322,
    1323,  1320,  1324,  1324,  1324,  1324,  1325,  1325,  1325,  1325,
    1325,  1325,  1325,  1325,  1326,  1326,  1327,  1328,  1328,  1328,
    1328,  1329,  1329,  1331,  1332,  1330,  1333,  1334,  1330,  1335,
    1335,  1336,  1336,  1337,  1337,  1337,  1337,  1337,  1338,  1339,
    1339,  1340,  1340,  1341,  1341,  1342,  1342,  1342,  1342,  1342,
    1343,  1343,  1344,  1344,  1345,  1345,  1345,  1346,  1346,  1347,
    1347,  1348,  1348,  1349,  1349,  1349,  1350,  1350,  1351,  1351,
    1351,  1351,  1351,  1351,  1351,  1352,  1352,  1353,  1353,  1354,
    1354,  1355,  1355,  1356,  1356,  1357,  1358,  1358,  1359,  1359,
    1360,  1361,  1361,  1362,  1363,  1363,  1364,  1364,  1365,  1365,
    1366,  1366,  1367,  1367,  1368,  1369,  1369,  1369,  1369,  1369,
    1369,  1369,  1369,  1369,  1369,  1369,  1370,  1370,  1371,  1371,
    1372,  1373,  1375,  1374,  1377,  1376,  1376,  1378,  1378,  1379,
    1379,  1380,  1380,  1381,  1381,  1383,  1382,  1384,  1385,  1385,
    1386,  1387,  1386,  1388,  1389,  1388,  1390,  1390,  1390,  1390,
    1390,  1390,  1390,  1390,  1391,  1392,  1393,  1394,  1394,  1395,
    1396,  1396,  1397,  1397,  1397,  1398,  1399,  1400,  1400,  1401,
    1402,  1402,  1402,  1404,  1403,  1405,  1405,  1405,  1405,  1405,
    1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1406,  1406,
    1406,  1406,  1407,  1407,  1407,  1408,  1408,  1408,  1409,  1409,
    1409,  1410,  1410,  1411,  1411,  1411,  1411,  1411,  1411,  1412,
    1412,  1413,  1413,  1414,  1414,  1415,  1415,  1416,  1417,  1417,
    1418,  1418,  1419,  1419,  1420,  1421,  1422,  1423,  1424,  1424,
    1425,  1425,  1426,  1426,  1426,  1427,  1427,  1428,  1428,  1428,
    1429,  1429,  1429,  1429,  1430,  1431,  1431,  1432,  1432,  1433,
    1433,  1434,  1435,  1435,  1435,  1435,  1435,  1435,  1435,  1436,
    1437,  1438,  1439,  1439,  1440,  1440,  1441,  1442,  1443,  1443,
    1444,  1445,  1446,  1446,  1447,  1447,  1447,  1448,  1448,  1448,
    1449,  1449,  1450,  1451,  1451,  1452,  1452,  1453,  1453,  1454,
    1454,  1455,  1455,  1456,  1456,  1457,  1457,  1458,  1458,  1459,
    1459,  1460,  1461,  1462,  1462,  1462,  1462,  1463,  1463,  1464,
    1464,  1465,  1465,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1468,
    1468,  1468,  1469,  1469,  1469,  1469,  1470,  1470,  1470,  1471,
    1471,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,
    1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,
    1472,  1472,  1472,  1472,  1472,  1472,  1473,  1473,  1474,  1474,
    1474,  1474,  1474,  1475,  1476,  1477,  1478,  1478,  1478,  1478,
    1478,  1478,  1478,  1478,  1479,  1479,  1479,  1479,  1479,  1479,
    1479,  1479,  1480,  1481,  1481,  1481,  1482,  1482,  1483,  1483,
    1483,  1484,  1485,  1485,  1485,  1485,  1486,  1487,  1488,  1488,
    1489,  1489,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,
    1491,  1491,  1491,  1491,  1491,  1491,  1491,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1493,  1493,  1493,  1494,  1496,
    1495,  1497,  1495,  1498,  1495,  1499,  1495,  1500,  1500,  1500,
    1501,  1501,  1502,  1502,  1502,  1503,  1503,  1504,  1504,  1505,
    1507,  1508,  1506,  1509,  1510,  1510,  1511,  1512,  1512,  1512,
    1512,  1512,  1513,  1514,  1514,  1515,  1516,  1517,  1517,  1517,
    1517,  1518,  1518,  1519,  1519,  1519,  1520,  1521,  1521,  1521,
    1522,  1522,  1522,  1522,  1522,  1522,  1522,  1522,  1523,  1523,
    1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,
    1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,
    1524,  1524,  1525,  1526,  1527,  1527,  1528,  1528,  1529,  1529,
    1530,  1530,  1531,  1531,  1532,  1533,  1533,  1534,  1534,  1535,
    1536,  1536,  1536,  1537,  1537,  1538,  1539,  1540,  1541,  1542,
    1542,  1543,  1543,  1543,  1543,  1543,  1543,  1544,  1544,  1544,
    1544,  1545,  1545,  1546,  1547,  1547,  1547,  1548,  1550,  1549,
    1551,  1551,  1552,  1552,  1552,  1554,  1553,  1556,  1555,  1558,
    1559,  1557,  1560,  1560,  1560,  1561,  1561,  1561,  1561,  1561,
    1561,  1562,  1562,  1563,  1564,  1565,  1565,  1566,  1566,  1567,
    1567,  1568,  1568,  1568,  1569,  1569,  1569,  1569,  1569,  1569,
    1569,  1569,  1569,  1569,  1569,  1569,  1569,  1569,  1570,  1570,
    1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,
    1570,  1570,  1570,  1570,  1571,  1572,  1572,  1574,  1573,  1575,
    1575,  1576,  1576,  1577,  1578,  1579,  1579,  1580,  1580,  1581,
    1581,  1581,  1582,  1582,  1583,  1583,  1584,  1585,  1585,  1586,
    1586,  1587,  1588,  1590,  1591,  1589,  1592,  1592,  1593,  1593,
    1594,  1594,  1594,  1594,  1594,  1594,  1594,  1595,  1595,  1596,
    1596,  1597,  1597,  1598,  1598,  1599,  1600,  1601,  1602,  1602,
    1603,  1604,  1604,  1605,  1606,  1606,  1608,  1607,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609
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
       1,     3,     1,     1,     4,     5,     5,     3,     0,     1,
       1,     1,     1,     0,     1,     7,     2,     2,     2,     2,
       2,     1,     2,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     1,     0,     4,     1,
       2,     2,     2,     0,     1,     1,     2,     2,     0,     2,
       0,     4,     1,     3,     3,     5,     0,     2,     4,     1,
       1,     1,     1,     1,     0,     1,     1,     3,     2,     5,
       2,     5,     5,     5,     5,     5,     5,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     0,     3,     2,     0,     0,
       0,     0,     0,     0,    15,     0,     2,     2,     0,     1,
       0,     0,     0,     0,     0,     0,    15,     2,     0,     0,
       0,    10,     0,     1,     3,     3,     2,     3,     4,     3,
       5,     4,     3,     3,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     0,     0,     8,     0,     0,     9,     0,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     8,     2,     2,     4,     2,
       0,     1,     1,     3,     2,     2,     1,     1,     3,     1,
       1,     2,     1,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     3,     1,
       3,     2,     4,     1,     3,     1,     2,     4,     1,     3,
       1,     1,     1,     2,     3,     4,     2,     4,     0,     2,
       2,     4,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     6,     6,     0,     1,     0,     1,
       2,     1,     0,     5,     0,     5,     1,     0,     3,     1,
       3,     1,     3,     1,     1,     0,     4,     1,     2,     1,
       0,     0,     3,     0,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     3,     1,     3,     2,
       1,     1,     0,     1,     1,     1,     1,     0,     1,     3,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     6,
       4,     4,     1,     1,     1,     0,     1,     2,     1,     1,
       1,     1,     3,     2,     1,     1,     2,     1,     1,     0,
       3,     1,     3,     1,     3,     1,     1,     6,     0,     3,
       1,     3,     0,     1,     4,     5,     2,     1,     1,     4,
       1,     3,     4,     4,     4,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     4,     0,     1,     0,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     1,     1,     2,     1,     1,     2,     2,     1,     3,
       2,     2,     1,     3,     1,     2,     4,     1,     2,     3,
       1,     3,     4,     0,     1,     0,     1,     0,     1,     1,
       3,     1,     3,     1,     2,     1,     3,     2,     2,     0,
       2,     1,     1,     5,     3,     5,     3,     1,     3,     1,
       1,     0,     1,     3,     3,     3,     6,     4,     4,     4,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     1,     4,     1,     5,     5,     1,     1,     1,
       1,     1,     4,     1,     4,     6,     4,     1,     4,     1,
       7,     1,     1,     1,     4,     6,     0,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       5,     3,     5,     7,     3,     1,     1,     3,     5,     3,
       5,     7,     1,     0,     3,     5,     1,     2,     2,     4,
       3,     1,     1,     1,     1,     1,     2,     2,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     3,     0,
       7,     0,     8,     0,     6,     0,     8,     0,     1,     2,
       1,     3,     1,     3,     5,     1,     1,     1,     1,     1,
       0,     0,     9,     5,     1,     1,     6,     0,     3,     1,
       3,     4,     1,     0,     2,     4,     6,     0,     1,     1,
       1,     1,     3,     1,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     2,     2,     4,     3,     2,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     4,     4,     3,     4,     1,     1,
       1,     3,     1,     5,     7,     5,     0,     2,     1,     1,
       0,     3,     1,     3,     1,     1,     1,     0,     3,     1,
       1,     1,     1,     4,     6,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     4,
       5,     1,     4,     1,     1,     7,     4,     1,     0,     4,
       1,     2,     1,     1,     1,     0,     3,     0,     3,     0,
       0,     6,     0,     2,     2,     7,     3,     3,     2,     2,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     2,     2,     1,     1,     2,     4,     5,     7,
       7,     9,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     3,     5,     5,     5,     5,     5,     4,     4,
       3,     4,     1,     1,     1,     1,     3,     0,     5,     1,
       3,     3,     3,     1,     1,     2,     1,     1,     3,     1,
       3,     3,     1,     1,     1,     3,     2,     3,     6,     1,
       3,     1,     1,     0,     0,     6,     0,     2,     0,     1,
       1,     2,     2,     1,     1,     4,     3,     1,     2,     5,
       2,     2,     5,     0,     2,     1,     1,     2,     6,     6,
       1,     0,     1,     2,     1,     2,     0,     2,     1,     1,
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
     856,     0,  1942,     0,     0,     0,     0,   905,   192,     0,
       0,   853,   881,   884,   190,   195,   863,   860,     0,   851,
     852,   854,   857,   858,   861,   865,   866,   864,   901,   902,
     904,   862,   148,   145,     0,   141,   143,   142,   146,  1970,
     733,   673,   734,   324,  1717,  1715,   899,   188,   198,   900,
     125,   191,     1,   867,   859,   903,   140,   144,   147,     0,
       0,   650,     0,     0,   189,   908,   970,   651,   909,   910,
     906,   685,   962,     0,   963,   971,   969,   198,   193,   211,
       0,   196,   212,   250,   129,     0,   886,  1270,     0,   885,
    1258,   893,     0,     0,   878,   877,   879,   855,   868,   869,
     887,   872,   873,   876,   874,   875,   880,     0,  1716,   964,
     907,     0,     0,   978,   976,   977,   966,   965,   322,   198,
    1194,   205,   199,   198,   204,   247,     0,     0,   126,   732,
       0,     0,     0,   188,   594,   911,   870,     0,   356,   342,
     214,   328,   293,   312,   333,   335,   332,     0,   354,     0,
     341,   334,   338,   344,   343,   198,   345,   325,   348,   326,
     327,   975,   974,     0,    22,    23,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   983,     0,   556,
     548,    16,   555,   970,    15,     0,   981,     0,   323,     0,
     197,  1195,   194,     0,   211,   213,   288,   216,   276,   282,
     283,   267,   240,   278,   214,   255,   256,     0,   242,   293,
     312,   265,   268,   263,     0,   238,     0,   274,   266,   271,
     281,   280,   198,   284,   198,   253,   254,   251,   287,   130,
     188,     0,     0,     0,   894,   188,   188,     0,     0,   215,
       0,     0,   346,     0,     0,   347,     0,     0,     0,     0,
       0,     0,     0,   235,     0,   972,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   562,
       0,     0,     0,   686,   453,   455,  1265,     0,     0,     0,
    1690,     0,   449,     0,     0,     0,   448,     0,   463,   558,
       0,     0,     0,     0,     0,   561,   416,   422,   459,   456,
     417,   418,   420,   421,   454,   457,   462,   557,   511,   508,
     517,   514,     0,     0,    17,    18,    19,    20,    21,     0,
      14,     0,   499,     0,     0,   979,     0,   200,   203,   201,
     202,     0,   208,   207,   206,   209,   217,   218,   219,   222,
     289,   198,   289,     0,     0,     0,     0,   198,   285,   286,
       0,     0,   198,     0,   289,     0,     0,   264,   248,   127,
    1271,     0,  1259,  1976,   595,   912,   888,     0,   226,   227,
       0,     0,   305,   307,   302,   303,   299,   301,   298,   300,
     297,     0,   307,   318,   319,   315,   317,   314,   316,   309,
       0,     0,     0,   358,     0,   361,   363,   234,     0,   233,
       0,   198,   198,   198,     0,     0,     0,   584,   655,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   580,   566,
     571,     0,     0,   567,   570,   569,   664,     0,   663,   586,
       0,    11,   184,   447,   424,   423,     0,  1200,     0,     0,
     461,  1698,  1696,  1697,  1693,  1695,  1692,  1694,  1686,     0,
       0,     0,   460,     0,     0,     0,     0,     0,     0,     0,
     687,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   563,   564,   565,   474,     0,     0,
     473,   483,     0,     0,   428,     0,     0,   429,   419,   425,
     427,   430,   431,   432,   433,   434,   426,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    96,     0,   982,     0,
     967,   210,     0,     0,   277,     0,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,   198,   249,
     252,     0,   994,   731,   994,     0,  1974,  1976,  1194,  1817,
     882,     0,   994,     0,     0,   329,   294,     0,     0,   304,
     321,   295,   320,     0,   313,     0,   336,     0,   330,     0,
     355,     0,   360,   350,     0,     0,   339,   236,     0,   292,
     349,   542,     0,     0,   554,     0,     0,   551,   550,   553,
     549,   560,   545,   545,     0,     0,   545,     0,   568,     0,
     572,     0,   581,   312,     0,   552,   559,   296,     0,  1266,
    1757,     0,     0,     0,     0,     0,   450,     0,     0,   464,
       0,     0,     0,     0,   466,   465,   484,   475,   490,   493,
     494,   491,   497,   496,   495,   485,   486,   487,   488,   489,
     435,   476,   480,   498,   492,   479,   498,   458,   512,   509,
     518,   515,   543,     0,   505,   101,   500,    97,    98,   100,
     502,     0,     0,   250,     0,     0,     0,   257,   258,     0,
     261,     0,     0,   269,     0,   259,   239,   220,     0,   272,
     291,     0,   131,   133,  1000,     0,   995,   996,     0,   895,
    1975,  1973,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1957,     0,  1391,
    1390,     0,  1392,     0,   412,  1389,  1306,     0,     5,  1388,
     413,   410,     0,   415,   186,   498,  1169,     0,     0,  1398,
     137,   409,   408,     0,     0,   403,   498,     0,  1342,  1950,
       0,   414,   375,     0,     3,     2,     0,   411,  1303,     0,
       0,   404,   401,   397,     0,     0,     0,     0,  1396,  1386,
     407,     0,     0,     0,     0,     0,     0,     0,     0,  1385,
       0,     0,     0,   187,     0,   400,   399,     0,     0,  1954,
    1953,     0,     0,     0,   149,     0,   406,   405,     0,     0,
     402,   498,     0,     0,   498,     0,   588,     0,     0,     0,
       0,     0,     0,   498,   840,  1268,     0,     0,  1180,     0,
    1943,     0,   108,     0,     0,   920,     0,     0,     0,     0,
     841,     0,     0,  1848,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   702,     0,     0,  1978,  1979,  1980,  1981,
    1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,
    1992,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,
    2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,
    2012,  2013,  2014,  2015,  2016,  2017,  2018,  2019,  2020,  2021,
    2022,  2023,  2024,  2025,  2026,   949,  2027,  2028,  2029,  2030,
    2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,
    2041,  2042,  2043,  1160,  1162,  1157,  1159,  1158,  1161,  2044,
    2045,  1296,  2046,  1302,  1301,  2047,  2048,  2049,  2050,  2051,
    2052,  2053,  2054,  2055,  2056,  1453,  2057,  2058,  2059,  2060,
    2061,  2062,  2063,  2064,  2065,  1977,   883,   599,     0,   916,
       0,   914,     0,   357,   228,   229,     0,   306,   311,     0,
       0,     0,     0,   359,   362,     0,   232,     0,   198,     0,
     585,     0,   659,     0,   661,     0,   523,   521,     0,   545,
       0,   522,     0,     0,   583,     0,   579,   576,   547,   520,
     587,     0,   183,  1759,  1760,  1758,     0,   452,  1265,     0,
    1691,  1265,   451,  1265,  1265,  1265,  1265,  1265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,    96,   980,     0,   223,   290,   241,
       0,     0,   198,     0,     0,     0,     0,   128,   132,     0,
    1272,     0,  1260,   394,   392,   393,  1300,  1095,  1094,  1100,
       0,  1665,  1666,     0,     0,  1326,   674,   675,  1327,  1657,
    1658,  1329,   871,  1132,  1137,  1952,   667,   136,  1965,     0,
       0,  1341,     7,     0,     6,     0,  1958,  1133,     0,  1228,
    1227,  1172,  1226,  1171,   446,  1399,  1387,     0,  1297,   896,
     436,  1819,  1393,   138,     0,  1136,   135,     0,   847,    24,
     669,   398,     0,   846,  1128,   848,     0,  1397,   942,   941,
     944,   940,   943,  1967,     0,   938,     0,   668,  1026,   939,
    1961,     0,  1951,   134,  1299,  1023,   735,  1021,     0,   665,
    1946,   783,   782,   784,   780,     0,     0,  1298,  1036,   670,
    1452,     0,  1933,  1447,  1450,  1923,  1926,  1927,  1929,  1932,
       0,     0,     0,     0,  1101,  1096,     0,  1075,  1076,  1077,
    1078,  1084,  1085,  1086,  1083,  1082,     0,     0,     0,  1081,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1067,  1058,  1059,  1009,     0,
    1007,  1115,   444,    24,     0,  1948,   139,   666,     0,  1269,
    1267,  1193,     0,  1808,     0,  1809,  1194,  1182,  1173,  1400,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
     970,     0,    69,     0,   106,   642,     0,   689,   688,     0,
    1163,  1043,  1167,     0,     0,  1116,  1286,     0,     0,  1170,
     694,   691,   692,     0,   696,   697,     0,   699,   700,     0,
     695,  1004,  1006,     0,     0,  1005,   785,  1002,   746,   998,
     961,     0,     0,     0,     0,   706,   707,     0,     0,   959,
     956,   957,   953,   954,   955,   948,   952,   951,     0,     0,
       0,     0,     0,     0,   603,   605,   597,   600,   601,   918,
    1976,   913,   915,   889,     0,   308,   310,   337,   331,     0,
       0,   340,   237,   656,   658,     0,     0,     0,     0,   545,
     528,     0,   545,   545,     0,   573,     0,   305,     0,     0,
    1787,  1682,  1684,  1843,  1847,  1788,  1688,  1785,     0,     0,
    1784,     0,     0,     0,  1786,     0,     0,     0,     0,     0,
       0,     0,  1933,  1683,  1783,  1685,  1772,     0,  1761,  1763,
    1767,  1770,  1798,  1841,  1799,  1844,  1934,  1924,  1771,  1203,
    1699,  1202,  1201,  1204,  1206,  1205,  1199,   477,   478,   482,
     467,     0,   470,   481,     0,   469,   513,   510,   519,   516,
     544,   506,   501,    99,   503,   968,     0,   262,   246,     0,
     244,   270,   260,   250,   273,  1001,   188,   997,   188,     0,
       0,     0,  1371,  1372,     0,     0,     0,  1343,  1346,  1348,
    1349,  1350,  1354,  1353,  1351,  1352,     0,     0,     0,  1344,
    1345,     0,     0,     0,     0,     0,     0,     0,     0,  1134,
       0,    24,  1223,  1225,  1224,     0,   439,   440,   437,   438,
    1014,     0,     0,   380,    25,   374,     0,  1129,     0,  1128,
       0,  1127,     0,     0,     0,     0,     0,     0,  1030,  1818,
       0,     0,     0,     0,     0,     0,  1948,     0,     0,   150,
       0,     0,  1040,  1032,  1033,  1038,     0,     0,  1925,     0,
    1936,  1448,  1449,     0,     0,   958,   442,  1917,  1053,   364,
       0,     0,   589,   647,   646,   644,   649,  1061,   648,  1066,
    1062,  1065,   839,   831,   825,   837,   838,   823,   824,   832,
     827,   833,   826,   836,   830,   834,   829,   835,   822,   828,
     815,   821,  1063,  1064,     0,  1071,  1079,  1068,  1069,  1073,
    1074,  1072,  1070,  1089,  1090,  1087,  1080,  1091,  1092,  1088,
       0,     0,     0,   849,     0,     0,     0,     0,     0,   795,
     794,   791,  1949,  1956,    24,  1189,  1190,  1191,  1192,  1186,
       0,  1184,  1282,  1194,  1174,  1175,  1178,  1196,  1944,     0,
       0,     0,     0,   102,     0,   103,     0,     0,     0,    77,
       0,     0,     0,     0,   115,   110,     0,   690,   947,     0,
     946,     0,   498,  1165,     0,   989,   990,  1013,   984,   985,
     842,  1011,  1118,  1295,  1294,  1289,     0,  1293,  1292,  1287,
    1852,  1855,  1857,     0,  1850,  1853,  1854,   722,     0,     0,
       0,   711,   746,   746,   743,     0,     0,   747,     0,    26,
     710,   713,     0,   720,   716,   960,   950,  1815,  1816,  1806,
    1806,  1417,     0,     0,  1718,  1456,     0,     0,  1401,     0,
       0,  1402,  1445,     0,     0,  1446,     0,     0,  1757,     0,
    1415,     0,  1465,  1464,  1463,  1461,  1462,  1460,  1458,  1454,
    1545,  1544,  1455,  1457,  1466,  1739,  1459,  1822,  1821,  1820,
    1467,  1976,  1976,   616,   607,   598,     0,   602,  1976,   917,
     188,     0,   351,   231,     0,     0,   546,     0,   545,     0,
     532,   545,     0,   525,   524,     0,     0,     0,   578,   577,
     185,  1769,  1768,  1706,  1704,  1705,  1701,  1703,  1700,  1702,
    1687,     0,  1757,     0,     0,  1612,     0,     0,  1775,  1773,
    1774,  1612,  1612,  1612,  1612,  1776,     0,     0,     0,  1563,
    1747,     0,  1764,     0,     0,     0,     0,  1831,  1832,  1833,
    1834,  1835,  1836,  1779,     0,     0,     0,     0,   472,   471,
       0,     0,     0,   198,   243,   221,  1273,  1261,     0,     0,
       0,     0,     0,     0,  1519,  1518,  1517,  1378,     0,  1384,
    1380,  1382,  1373,     0,  1621,  1370,  1366,  1340,  1339,     0,
    1365,  1361,     0,  1357,  1355,     0,  1664,     0,  1667,  1669,
     678,     0,   677,  1656,     0,  1659,  1661,  1966,  1963,     0,
       0,  1307,   498,   372,  1328,     0,     0,  1304,  1045,  1130,
    1131,  1128,  1124,  1128,     0,   945,     0,     0,   652,     0,
       0,     0,  1024,  1022,   737,   738,     0,   742,     0,     0,
    1947,  1955,   781,     0,   154,     0,  1034,  1041,     0,     0,
    1049,  1928,  1941,     0,  1939,  1451,  1931,  1930,     0,     0,
       0,  1055,   367,     0,     0,     0,     0,    24,  1097,  1098,
     592,     0,     0,     0,   816,   817,  1060,  1010,  1008,   850,
     445,     0,  1107,   792,   796,   793,   797,   395,     0,  1194,
    1183,  1283,  1198,  1181,  1176,     0,     0,  1177,  1976,     0,
       0,     0,     0,     0,     0,     0,    64,    96,     0,     0,
       0,   121,   116,     0,   111,     0,   118,   112,   931,   923,
     929,     0,  1164,     0,  1166,  1168,     0,     0,   993,     0,
       0,     0,     0,  1117,  1288,  1291,     0,     0,     0,  1849,
    1851,  1976,   693,   698,   701,   714,   712,   671,     0,   770,
     768,   766,   764,   774,   772,     0,     0,   762,   812,   760,
     745,   756,   754,   810,   786,     0,   748,   758,  1003,   999,
       0,     0,     0,     0,   719,     0,     0,     0,     0,     0,
       0,     0,  1672,     0,  1540,  1541,  1827,  1498,  1563,     0,
       0,     0,  1825,     0,  1478,  1473,  1472,  1485,  1484,  1489,
    1489,  1487,  1488,  1479,  1474,     0,     0,  1480,  1481,  1740,
    1859,     0,     0,     0,   604,   606,     0,     0,   619,   611,
     613,     0,   608,   609,     0,     0,   627,   629,     0,     0,
     625,   919,   890,   230,     0,   660,   662,   657,     0,   545,
     534,     0,   529,     0,     0,   545,   545,   575,   574,     0,
       0,  1796,  1688,     0,     0,  1771,  1614,  1615,  1613,     0,
    1800,     0,     0,     0,     0,     0,     0,     0,  1762,     0,
    1551,  1552,  1554,  1557,     0,  1564,  1565,     0,     0,  1612,
    1749,  1743,  1765,  1781,  1782,  1780,  1778,     0,     0,     0,
    1935,   468,   507,   504,     0,   245,  1229,  1207,     0,     0,
       0,     0,  1378,     0,     0,     0,  1374,     0,     0,     0,
    1368,  1652,  1650,  1619,  1631,  1633,  1637,  1639,  1630,  1624,
    1629,  1643,  1622,  1651,  1627,  1642,  1628,  1649,  1641,  1525,
    1616,  1617,  1618,     0,  1363,  1359,     0,     0,  1347,     0,
       0,   676,     0,     0,     0,  1962,     0,     4,     8,    10,
       0,   498,   441,     0,     0,     0,  1042,  1126,  1125,     0,
       0,     0,     0,     0,     0,     0,     0,   736,     0,     0,
     171,   169,     0,     0,   151,     0,   161,   167,   746,   156,
     158,     0,  1039,  1050,  1051,     0,     0,  1937,   443,     0,
    1918,  1919,  1054,     0,     0,  1052,   366,   371,   654,   365,
       0,   368,   373,     0,   498,  1423,   645,   643,     0,   819,
    1106,  1108,     0,   396,  1187,  1185,     0,  1197,  1179,     0,
       0,  1278,     0,     0,     0,   104,     0,     0,    78,    84,
      74,    71,  1976,  1976,   114,   109,   123,   119,     0,   113,
     813,   932,   671,  1976,   922,   921,   930,  1044,     0,     0,
     991,   992,   986,  1012,   498,  1123,  1119,  1120,  1122,  1290,
    1856,  1858,   723,   717,   715,     0,    24,     0,  1976,  1976,
    1976,  1976,  1976,  1976,   776,   750,   778,   752,  1976,  1976,
    1976,  1976,     0,   744,   749,  1976,   671,   808,   806,   809,
     807,     0,     0,    46,    44,    41,    35,    39,    43,    38,
      31,    40,     0,    34,    37,    32,    42,    33,    45,    36,
       0,    29,    47,   800,     0,   721,  1807,     0,  1805,  1757,
    1803,  1744,  1745,  1737,  1723,  1738,     0,     0,     0,  1093,
    1539,  1542,     0,     0,     0,  1435,  1407,  1830,  1829,  1828,
       0,     0,     0,  1483,  1486,     0,     0,     0,     0,     0,
    1430,     0,  1429,     0,  1431,  1426,  1427,  1428,  1419,  1420,
       0,     0,     0,   618,   623,     0,     0,  1976,  1976,   596,
     610,   633,   621,   635,  1976,  1976,   631,   615,   626,   882,
     352,   545,     0,   533,   545,     0,   545,   545,   527,   526,
    1713,  1711,  1712,  1708,  1710,  1707,  1709,  1689,     0,     0,
       0,     0,  1797,     0,     0,     0,  1795,     0,     0,     0,
       0,  1777,  1794,     0,  1555,     0,     0,  1681,  1558,     0,
       0,     0,     0,  1550,  1569,  1571,  1573,  1611,  1610,  1609,
    1575,  1591,     0,  1566,  1567,  1752,  1330,     0,     0,     0,
    1842,     0,  1846,   224,     0,  1255,  1274,     0,  1262,  1255,
       0,  1673,     0,  1507,     0,  1510,  1676,     0,  1515,     0,
       0,  1375,  1376,     0,     0,  1379,  1381,  1383,     0,  1367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1523,  1522,  1521,     0,  1526,  1527,     0,  1362,     0,  1356,
    1358,  1668,     0,  1670,  1660,     0,  1662,  1964,  1336,     0,
    1332,     0,     0,  1337,   897,     0,     0,     0,     0,     0,
    1394,  1969,  1968,   653,     0,     0,    48,     0,   739,   741,
     740,  1395,   746,  1976,  1976,   163,   679,   173,   165,   175,
     155,   162,  1976,     0,     0,     0,     0,     0,  1940,     0,
       0,     0,     0,     0,     0,  1099,     0,  1424,   590,     0,
     818,  1104,     0,  1284,  1285,  1945,     0,    96,     0,    65,
       0,     0,     0,    81,     0,    96,    96,    96,   122,   117,
    1976,  1976,   107,     0,   933,   927,   935,   934,   924,   640,
     973,     0,     0,     0,   725,   704,   718,   672,   787,     0,
     771,   769,   767,   765,   775,   773,     0,  1976,     0,  1976,
     763,   761,   757,   755,   811,   759,    24,   801,     0,     0,
       0,    27,     0,  1810,     0,  1724,     0,     0,  1736,  1719,
    1735,  1543,     0,  1500,     0,  1434,     0,     0,  1826,     0,
    1823,     0,  1491,  1495,  1471,  1493,  1496,     0,  1482,  1741,
       0,     0,     0,     0,     0,     0,  1860,  1433,  1432,  1421,
    1416,  1418,  1470,     0,     0,   620,   617,   612,   614,     0,
    1976,  1976,   628,   630,  1976,  1976,     0,   535,     0,   539,
       0,     0,   531,   530,     0,     0,     0,     0,     0,     0,
    1793,  1801,  1789,  1790,  1791,  1792,  1560,     0,  1553,  1559,
    1574,  1578,     0,  1591,  1577,     0,     0,  1592,  1604,  1605,
    1602,  1608,  1607,  1603,     0,     0,     0,     0,     0,  1606,
       0,     0,     0,  1547,  1548,  1766,     0,  1568,  1562,  1331,
    1750,  1440,  1436,  1437,  1442,  1441,  1748,  1330,     0,     0,
    1253,  1254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1252,     0,     0,  1240,  1241,  1242,  1239,
    1244,  1245,  1246,  1243,  1230,  1221,     0,     0,  1277,     0,
       0,  1216,     0,     0,     0,     0,     0,     0,     0,  1208,
    1209,     0,  1138,  1677,     0,  1678,     0,     0,     0,     0,
    1514,  1513,  1378,  1512,  1504,  1369,  1653,     0,     0,     0,
       0,     0,     0,  1654,  1646,     0,     0,     0,  1646,  1682,
    1520,  1533,  1538,     0,  1535,  1532,  1534,     0,  1536,  1524,
    1528,  1529,  1378,  1364,  1360,     0,     0,  1335,  1334,     0,
    1319,     9,     0,  1309,   898,  1135,   378,  1309,     0,     0,
    1960,     0,     0,  1025,    49,     0,   798,   172,   170,     0,
    1976,     0,     0,     0,  1976,   168,   157,     0,   160,   159,
       0,  1031,  1035,     0,  1922,  1921,  1920,     0,     0,   370,
       0,   593,     0,  1976,   820,     0,   671,  1188,     0,  1279,
      70,     0,     0,   105,    68,    96,    79,    85,     0,     0,
     124,   120,   814,  1976,   937,   671,   936,     0,   637,     0,
     844,   845,   843,  1121,   728,   726,     0,   708,   705,     0,
     777,   751,   779,   753,   788,   804,   805,   802,   803,    30,
      28,     0,  1804,  1753,  1725,  1721,  1720,     0,  1499,  1757,
    1502,     0,  1409,  1404,  1403,  1406,     0,     0,  1490,     0,
       0,  1753,     0,     0,  1897,  1895,     0,     0,  1879,  1894,
       0,     0,  1896,     0,     0,     0,     0,     0,  1933,  1893,
    1885,  1912,  1913,     0,  1877,  1880,  1881,  1892,  1884,  1914,
       0,  1870,  1869,  1873,  1875,     0,  1868,     0,  1871,  1862,
       0,     0,   624,   622,   634,   636,   632,     0,     0,   545,
       0,   545,   545,     0,  1756,     0,  1689,     0,     0,     0,
    1556,  1576,  1570,  1572,  1579,  1581,  1579,     0,  1586,  1579,
       0,  1584,  1579,     0,  1594,  1593,     0,  1595,     0,  1546,
       0,  1444,  1443,  1439,  1751,     0,   250,  1247,  1248,  1249,
    1251,  1234,  1232,  1231,  1235,  1236,  1233,  1250,  1237,  1238,
    1222,  1018,  1257,  1015,     0,     0,  1275,  1220,  1219,  1214,
    1212,  1211,  1215,  1213,  1217,  1218,  1210,  1263,     0,  1505,
    1511,  1680,  1673,  1516,  1377,  1620,  1632,     0,  1634,  1636,
       0,  1638,     0,     0,     0,  1644,  1623,  1648,     0,  1506,
    1508,     0,  1530,  1531,  1671,  1663,  1333,     0,     0,  1325,
    1320,  1321,  1338,     0,  1316,  1317,     0,     0,  1330,  1310,
    1311,     0,    24,  1305,     0,     0,  1048,     0,    50,  1028,
       0,    24,   174,   164,     0,   681,   683,   176,   166,   798,
       0,  1938,  1057,     0,   369,  1425,     0,  1105,    24,     0,
       0,    66,     0,    82,    91,     0,    75,    72,   928,   925,
     641,  1976,   987,     0,  1976,   724,   703,   709,   671,  1814,
       0,  1812,     0,     0,  1726,  1722,  1501,     0,  1503,  1497,
       0,  1408,     0,  1824,  1492,  1494,  1469,     0,  1883,  1882,
       0,     0,  1612,     0,  1612,  1612,  1612,  1612,  1886,     0,
       0,  1866,     0,     0,     0,     0,  1899,  1867,     0,     0,
       0,     0,     0,     0,  1861,  1422,  1475,   892,   891,   353,
     536,     0,     0,   541,   540,  1714,  1837,  1840,  1838,  1561,
       0,  1598,  1600,     0,  1587,  1590,  1589,  1597,     0,  1599,
    1579,     0,  1549,  1438,  1845,   225,  1020,  1019,  1017,     0,
    1256,  1139,  1143,  1145,     0,  1149,     0,  1147,  1151,  1140,
    1141,     0,     0,     0,  1674,  1679,     0,     0,  1655,  1647,
    1625,     0,  1626,     0,     0,  1323,  1318,  1324,  1322,  1315,
    1314,  1313,  1308,  1312,   379,   376,     0,  1046,     0,     0,
       0,  1027,   799,   152,   680,    24,  1037,  1056,   591,  1102,
      67,  1280,    87,     0,     0,    80,    91,    91,    91,  1976,
     638,     0,     0,   727,   789,     0,  1811,  1754,  1747,     0,
    1410,     0,  1747,  1910,     0,     0,  1915,     0,     0,     0,
       0,     0,     0,     0,     0,  1878,  1901,  1902,  1900,  1898,
    1876,     0,  1872,  1874,  1863,  1864,  1476,     0,  1468,   545,
     545,  1580,  1802,  1582,     0,  1585,  1583,  1601,     0,  1016,
    1976,  1976,  1153,  1976,  1155,  1976,  1976,  1142,  1276,  1264,
       0,  1635,     0,  1645,     0,  1537,   381,  1047,  1959,     0,
       0,     0,     0,     0,     0,    55,     0,    54,     0,    52,
       0,     0,   153,  1109,    91,    96,    91,    92,    86,    76,
      73,   926,     0,     0,   729,    24,  1813,  1746,  1755,  1414,
       0,  1411,  1413,  1727,  1911,     0,     0,  1909,     0,     0,
       0,     0,     0,  1887,  1908,     0,  1477,   538,   537,  1588,
    1596,  1144,  1146,  1976,  1150,  1976,  1148,  1152,  1675,  1640,
    1509,   383,   388,   386,   377,     0,   384,   390,    57,    62,
      59,    61,    58,    60,    56,     0,    51,     0,   682,   684,
    1113,  1103,     0,  1111,  1281,    88,    83,   639,   988,  1976,
     790,     0,  1405,     0,  1728,  1742,  1907,  1916,  1903,  1904,
    1905,  1906,     0,  1888,     0,     0,  1154,  1156,  1976,  1976,
     382,   385,  1976,    53,     0,  1976,  1110,  1112,     0,   725,
    1412,     0,  1732,  1729,  1730,     0,     0,  1865,   389,   387,
     391,     0,  1114,    89,   730,     0,     0,     0,  1890,     0,
    1889,  1029,    93,     0,  1733,  1731,     0,    95,     0,    90,
       0,  1891,    94,  1734
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   846,   847,   848,   849,  1073,  2147,  2148,   187,   329,
     188,  1443,  1444,  1971,  2310,  3357,  2833,  2834,  3259,  3358,
    3359,   850,  1218,  2871,  2567,  3278,  2566,  3277,  1907,  2564,
    3124,  2875,  3273,  2565,  3125,  3365,  3468,  3492,  3275,  3499,
     666,   667,   668,  1574,  2224,   851,  1586,  1223,  1584,  1916,
    2235,  1913,  2233,  2238,  2571,  1585,  2232,  1917,  2570,    11,
      84,   240,   551,   128,   691,   692,   852,    12,    34,    35,
      36,    37,    38,   854,  1136,  1844,  1469,  2174,  2178,  2179,
    2175,  2176,  2840,  2844,  2532,  2524,  2523,  2525,  2528,   507,
     279,   618,   855,    63,    64,    14,    48,   120,    78,   263,
      80,    81,   203,   344,    82,    83,   250,   349,   235,  1035,
     532,  2729,   380,   956,  2034,   408,   409,   264,   236,   362,
     351,   357,  1389,  1390,   124,   550,   125,   126,   368,   237,
     364,   350,   352,   534,   238,   590,   252,   255,   253,   254,
     975,   566,   567,   569,   574,   959,   256,   257,   399,   571,
     199,    15,    59,   157,   158,   159,   965,  2666,   160,   260,
     248,   402,   403,   404,   405,  1867,   856,   857,   858,   859,
    1094,  3346,  3092,  1445,  3414,  3415,  3416,  3459,  3458,  3462,
     860,   861,   862,   863,   864,   865,   866,  1084,   508,  1089,
    1437,  1438,  1485,  1191,  1486,   306,   307,   308,   309,   310,
     465,   509,  1371,   510,   511,   512,   513,   514,   515,   516,
    1011,   189,   526,  1022,  1024,  1761,  1021,  1760,   190,   519,
    1017,   518,  1016,   521,  1019,   520,  1018,   976,   989,   311,
     312,   192,   313,   432,   433,   434,   435,   416,   437,   867,
    1156,  1870,  2863,  2205,    95,   245,   560,  1684,  1286,  1287,
    1288,  1681,  1682,  2021,  2022,  2023,  2367,  2368,  1685,  1686,
    2017,  2371,  2363,  2029,  2030,  2374,  2375,  2664,  2660,  2661,
     868,  3131,  3372,  2888,   869,  1497,    65,  1829,  1830,  2199,
     417,   439,  1128,  1196,  1065,  1116,  1099,  1138,  2266,   193,
    1066,  1056,  1801,  2527,    67,   314,   870,  1228,   871,  1241,
    1242,   872,   873,   874,   875,  1249,  2897,  1270,  3136,  1271,
    1945,  1272,  2263,  1273,  2585,  1274,  1974,   876,  1941,  2584,
    2896,  3134,  3133,  3439,    96,    16,    17,   877,  1463,  1834,
    1835,  1836,  1964,  1628,  1965,  1966,  2597,  2599,  2281,  2280,
    2285,  2279,  2278,  2271,  2270,  2269,  2268,  2273,  2272,  2275,
    2277,   878,   879,  1134,   880,  1624,  1256,  3375,   881,  1551,
    3101,  2312,  2313,  1967,  2282,  2241,  2573,  1185,  1525,  1874,
    2208,  1875,  1521,   882,   883,  1234,  1931,  2892,   884,   885,
     886,   887,    18,    19,    20,    53,    21,    22,    23,    97,
      98,   888,    99,    24,   947,    25,   100,   101,   137,   562,
    1690,  2379,  3188,   102,   133,   373,   889,  2505,    26,    27,
      28,    29,    30,    47,    70,   103,   246,   561,   950,   951,
    1290,  1688,   890,  1229,  2245,  1920,  2243,  3279,  2883,  1921,
    2242,  2576,  2885,   891,   892,   893,  1110,  1111,  1589,   894,
    1275,  1276,   895,  1636,  1277,   315,    72,    73,    74,    75,
    1596,   163,   116,    76,   113,   195,   196,  1597,  1598,  2252,
    1599,   695,   696,  1258,   697,  1259,  1189,  1190,  1600,  1601,
    1441,  3032,  3033,  3218,  1126,  1127,   896,  1458,  3261,   897,
    2852,   898,  1473,  1474,  1475,  1850,  1848,   899,   900,  2156,
    2185,   901,  1861,  2195,   902,  1186,  1187,  1535,  1539,   903,
    1049,   904,  2323,   905,  3363,  2866,   906,  2212,  3431,  3432,
    3433,  3465,  1193,   907,  1602,  1933,  2256,  2257,   908,  1451,
    1821,  1064,  1430,   909,   910,   911,  2448,  3036,  3229,  3230,
    3330,  3331,  3335,  3333,  3336,  3403,  3405,   912,   913,  1591,
    1925,   914,  1593,  1563,  1564,  1565,  1897,   915,  1208,  1206,
     916,   917,  1889,  1559,  1202,   202,  1566,  1567,   316,  2449,
    2769,  2770,  2754,  1081,  1082,  2445,  2755,  2758,   104,   132,
     554,  1398,  2097,  2771,  3232,   447,   918,  1200,   105,   130,
     552,  1396,  2096,  2759,  3231,  2446,  1222,  2557,  3120,  3364,
    1892,   919,  1609,   920,   921,   922,   923,  1097,  2154,  1075,
    2150,  3088,  3089,  3090,  3245,  3079,  3080,  3081,   924,  2720,
    2499,  2500,  2502,  1785,   925,   926,  1407,  1408,  1409,  1794,
    2136,  1410,  2133,  1791,  1411,  2109,  1786,  1412,  1413,  1414,
    2101,  2106,  1415,  1780,  1781,   927,  1106,  1086,   928,  1662,
    1663,  1989,  2924,  3152,  2627,  2921,  3380,  3381,  1664,  2011,
    1642,  2359,  2650,  2970,  2548,  2862,  2360,  1665,  1666,  2080,
    2722,  2723,  2724,  3013,  1667,  1668,  1482,   929,  1143,   930,
    1283,  1669,  1670,  2005,  3318,  2006,  2007,  2008,  2343,  2631,
    2634,  2635,  1671,  2333,  2622,  3149,  1774,  1775,  2808,  2452,
    3069,  2453,  1776,  2457,  1787,  2484,  1788,  2485,  2809,  2810,
    2811,  2812,  1672,  1983,  1984,  2330,  1673,  2717,  2433,  2713,
    2075,  1739,  2070,  2071,  2072,  2687,  1740,  2076,  2434,  2718,
    2423,  2424,  2425,  2426,  2427,  3201,  2994,  3321,  2428,  3203,
    3204,  2711,  2429,  2712,  2430,  2059,  2129,  2130,  2131,  3063,
    2132,  2787,  2794,  3239,  2454,  1053,  2636,  2775,  2963,  2456,
    2418,  1344,   317,  1345,  1720,   458,   459,  1721,  2397,    46,
     931,   932,  2916,  3145,  2615,  3144,  3445,  3473,  3474,  2619,
    2324,  1674,  2325,  2348,  2931,   621,  2320,  2321,  2081,  2436,
    3143,  2920,  1346,   996,  1347,  1348,  2714,  2431,  1350,  1351,
    2061,  3323,   933,   934,  1976,  2322,  2912,  3140,  3141,  1639,
     935,  1092,  1676,  1677,  1993,  2629,  1678,  1679,  2339,  1753,
    2054,  1352,  1353,  1354,  1355,   936,  1237,  1613,  1614,  1615,
    1937,  1616,  1938,  1680,  2349,  2969,  3184,  2646,  2966,  2967,
    2968,  2965,  2953,  2954,  2955,  2956,  2957,  2958,  3297,   937,
    1859,  2190,  2191,  1144,  1356,  1357,  1146,  1147,  1148,  1358,
    1149,  1480,  1853,  1854,    31,   939,  1210,  1898,  1466,  1553,
     940,   941,  2516,   942,  2145,  1069,  1808,   943,   944,    41,
     555,   556,   557,   558,   559,   945
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2579
static const short yypact[] =
{
     148,   577, -2579,   311,   311,   311,   932, -2579, -2579,   932,
     311, -2579, -2579,    31, -2579, -2579, -2579, -2579,   409, -2579,
   -2579, -2579,  1556, -2579, -2579, -2579, -2579, -2579,     9, -2579,
   -2579, -2579, -2579, -2579,   465,   551, -2579,   649, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,    43, -2579,   614,   301, -2579,
   -2579, -2579, -2579,   439, -2579, -2579, -2579, -2579, -2579,   388,
     311, -2579,   311,   579,    31, -2579,   752, -2579, -2579, -2579,
   -2579, -2579, -2579,   882,   243, -2579, -2579, -2579,  1047,   671,
     311, -2579, -2579,  1082,   422,   311, -2579, -2579,   311, -2579,
   -2579, -2579,   311,   311, -2579, -2579, -2579, -2579,   439, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,  8629, -2579,   243,
   -2579,   425,  3596, -2579, -2579,   599, -2579, -2579,  1223,   301,
     678, -2579, -2579, -2579, -2579, -2579,  8599,   311, -2579, -2579,
     311,   804,   311,    31, -2579, -2579, -2579,   311, -2579, -2579,
     964,   873,  1158, -2579, -2579,   885, -2579,   901, -2579,   854,
   -2579, -2579,   910, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,   918, -2579, -2579, -2579,   946,   956,   961,
     966,   969,   998,  1026,  1031,  1036,  1042,  1045,  3596,  1051,
    5215,  1057,  1066,  1071,  1107,  1116,  1135,  1863,  1386, -2579,
   -2579, -2579, -2579,   381, -2579,   137, -2579,  3596, -2579,   213,
   -2579, -2579, -2579,    85, -2579, -2579, -2579,  1092, -2579, -2579,
   -2579, -2579, -2579, -2579,   964,  1139,  1142,  1151, -2579,  1158,
   -2579, -2579,  1184, -2579,  1196, -2579,   904, -2579, -2579,  1207,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
      31,  1215,  1681,  1226, -2579,    31,    31,  1237,   311, -2579,
     712,  1713, -2579,  1077,  1399, -2579,  1083,  1424,  1753,  1755,
     311,  1758,  1762,   404,  1126, -2579,   255,    35,    35,    35,
      35,    35,  5215,  1896,   155,    59,  5215,  1170,  5215, -2579,
    5215,  5215,  5215, -2579, -2579, -2579,  1224,  1315,  1324,  5215,
    1582,  1333, -2579,  5215,  5215,  1335, -2579,  1338, -2579,  1066,
    1347,  1349,  1351,  1356,  1817,  5711, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  1375, -2579, -2579, -2579, -2579,
   -2579, -2579,   255,   255, -2579, -2579, -2579, -2579, -2579,  3596,
   -2579,   311, -2579,   311,  3596,  1341,   145, -2579, -2579, -2579,
   -2579,  1836, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    1374, -2579,  1374,   712,  1838,  1853,  1862, -2579, -2579, -2579,
    1877,  1879,   301,  1758,  1374,  1880,  1217, -2579,  1792, -2579,
   -2579,  1462, -2579,  1493, -2579, -2579, -2579,  1243, -2579, -2579,
    1904,  1488, -2579,  1446, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,  1424,  1446, -2579, -2579, -2579, -2579, -2579, -2579,  1453,
     217,   238,   286, -2579,  8203, -2579, -2579, -2579,  1458,  1938,
     266, -2579, -2579, -2579,  1496,  1464,   268, -2579,  -173,  1502,
    1518,   372,   382,  4540,  1520,  1522,   118,    93, -2579, -2579,
     158,  1945,  1528, -2579, -2579, -2579, -2579,   383, -2579, -2579,
    5906, -2579,  3510,  7542,  4775,  4775,  5215, -2579,  1454,  5215,
    5711,  1492, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  1305,
    1960,  6550,  5711,  1454,  1961,   799,  5215,  5215,  5215,  5215,
   -2579,  5215,  5215,  5215,  5215,  5215,  5215,  5215,  5215,  5215,
    5215,  5215,  5215,  5215,  5215,  5215,  5215,  5215, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  5215,  5215,
   -2579, -2579,  1504,  5215, -2579,  5215,  1507, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,   255,  5215,  5215,
    5215,  5215,  1539,  1988,  1863,  1512,  3564,  1513, -2579,  3596,
    1486, -2579,  1325,  1974, -2579,  1330, -2579,  1977,  1558,  1559,
     395,  1695,   438,   444,   290,  1530, -2579,   466, -2579, -2579,
   -2579,   186,   311, -2579,   311,  1596, -2579,  5410,   678,  5937,
    1985,   634,   311,  1998,   -12, -2579, -2579,  1399,  1997, -2579,
   -2579, -2579, -2579,  2000, -2579,  2008, -2579,  2011, -2579,   311,
   -2579,   311, -2579, -2579,  1758,  2018, -2579, -2579,  1407, -2579,
   -2579, -2579,   311,    35, -2579,  3596,    48, -2579, -2579, -2579,
   -2579, -2579,  1399,  1399,  2026,  -122,  1399,  1147, -2579,  2027,
    1413,  1382, -2579, -2579,    59, -2579, -2579, -2579,  1576,  5711,
     -10,  1580,  6609,  2031,  1582,  1620, -2579,  1624,  1625, -2579,
    6656,  6715,  6774,  6821,  7360,  7381,  7542,  7563,  4654,  4593,
    6799,  7611,  5502,  7797,  7864,  4775,  4775,   700,   700,  1745,
    5711,  6997,  7193,  1454,  5711,  7301,  1454, -2579,  5711,  5711,
    5711,  5711, -2579,  2049, -2579, -2579, -2579,  2071, -2579,  5711,
   -2579,   236,  3596, -2579,  1632,  2065,   -12, -2579, -2579,  2060,
   -2579,  1602,  2072, -2579,  2073, -2579, -2579, -2579,  2077, -2579,
   -2579,     2, -2579, -2579,  1432,  1670,  2114, -2579,  1677, -2579,
   -2579, -2579,   255,   255,   255,   311,  1034,   311,  1302,   181,
     181,  1459,   311,   311,   181,   181,   311, -2579,  1302, -2579,
   -2579,   311, -2579,  1073, -2579, -2579, -2579,   181, -2579, -2579,
   -2579, -2579,   311, -2579, -2579, -2579, -2579,   123,   123,  5215,
   -2579, -2579, -2579,  1459,  1459, -2579, -2579,   181, -2579, -2579,
     181, -2579, -2579,   311, -2579, -2579,   181, -2579, -2579,   255,
     181, -2579, -2579,  5215,   181,   255,   311,   255,   181, -2579,
   -2579,   187,   181,   181,   187,   181,   311,   187,   181, -2579,
     181,   181,   181, -2579,  1302, -2579, -2579,   255,   181, -2579,
   -2579,   181,    66,   311, -2579,  1459, -2579, -2579,   181,  1093,
   -2579, -2579,   255,  1444, -2579,   181, -2579,  3739,   255,  5215,
      35,    35,   181, -2579, -2579,  1034,   255,   387, -2579,  5215,
   -2579,  1303,  5215,   181,   105, -2579,  5215,   181,  2104,   255,
   -2579,   181,  5215, -2579,  5215,   123,   311,   181,   311,    35,
     181,   311,    35, -2579,   311,   229, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,   823, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  1363, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,   807,   311, -2579,
     665, -2579,  1690, -2579, -2579, -2579,  1783, -2579, -2579,  1694,
    1696,  1697,  1698, -2579, -2579,  1474,  2150,  1710, -2579,  1712,
   -2579,   509, -2579,  1679, -2579,  1494, -2579, -2579,   456,  1399,
    2145, -2579,  1727,  -109, -2579,  2151, -2579,  1534, -2579, -2579,
   -2579,  1500, -2579, -2579, -2579, -2579,  8210, -2579,  1224,  1731,
   -2579,  1224, -2579,  1224,  1224,  1224,  1224,  1224,  2155,  2156,
    2157,  5215,  1735,  2160,  5215,  1743,  1748,  1750,  1763,  1764,
    1767,  3564,  1773,  3564,  3564, -2579,   330, -2579, -2579, -2579,
    1835,  1774, -2579,  1776,  1781,  1560,  1785, -2579, -2579,   311,
   -2579,   311, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
     429,  1562,   553,  1405,  1756, -2579, -2579, -2579, -2579,  1568,
     613, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  2234,
    1581, -2579, -2579,  1779, -2579,  1459, -2579,  1730,   192, -2579,
   -2579, -2579,  1795, -2579,  5711, -2579, -2579,  1619, -2579, -2579,
    3796, -2579, -2579, -2579,   255, -2579, -2579,  1459, -2579,   -13,
   -2579, -2579,  1941, -2579,   124, -2579,  1754, -2579, -2579, -2579,
   -2579,  2264, -2579, -2579,   314, -2579,  1600, -2579,  1601,  2264,
   -2579,  1626, -2579, -2579, -2579,  1804,   200, -2579,  1766, -2579,
    1570, -2579, -2579, -2579, -2579,  1571,   846, -2579,  -266, -2579,
    1612,  1557,  1772,  1902,  1627, -2579, -2579,  1616, -2579, -2579,
    5215,   228,  1094,  5215, -2579,   115,   181, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,    89,    89,    89, -2579,
      89,  2443,    89,    89,  1641,   -13,  1641,  1641,  1169,  1169,
    1641,  1641,  1674,   -13,  1678, -2579,  2287, -2579,  1818,   642,
   -2579,  2291, -2579,   -13,    96,    45, -2579, -2579,  5215, -2579,
   -2579, -2579,  1020, -2579,  1178, -2579,   678, -2579,  5215, -2579,
    5215,  1812,  1814,  1815,  1816,  1579,  1819,  1178, -2579,  1905,
    1183,   104, -2579,  1675, -2579, -2579,   311, -2579, -2579,  1179,
   -2579,  2300, -2579,  2295,   311, -2579,   265,   241,  1682, -2579,
   -2579,  2308, -2579,  1604,  2308,  2312,  1609,  2308,  2312,  5215,
    2308, -2579, -2579,   192,   255, -2579, -2579,  1851,   270, -2579,
   -2579,  1842,   255,  5215,  1843, -2579, -2579,  2305,  2307,  2207,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  1191,  1191,
     181,   181,   181,  3082, -2579, -2579,  2186,   807, -2579, -2579,
     814, -2579, -2579, -2579,  1823, -2579, -2579, -2579, -2579,  8629,
    1758, -2579, -2579, -2579,  1672,   311,  1399,  2320,   -40,  1399,
   -2579,   435,  1399,  1399,  1583,  1705,  1587, -2579,  8470,  8470,
   -2579,  1612, -2579, -2579, -2579, -2579,  1660, -2579,  7876,  1865,
   -2579,  1867,  1871,  1875, -2579,  1875,  1875,  1883,  1886,  1888,
    1889,   311,   661, -2579, -2579, -2579, -2579,   245, -2579,    54,
    1806, -2579, -2579,  1660, -2579,  1660,  1873, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    5711,   472, -2579, -2579,   479, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  1848, -2579, -2579,   485,
   -2579, -2579, -2579, -2579, -2579, -2579,    31, -2579,    31,  1008,
     177,  2355, -2579, -2579,   632,   355,  1069,  2378, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,   311,  1607,   311, -2579,
   -2579,  1615,   311,  1645,   311,   311,  1459,  1736,  1903, -2579,
    1906,   117, -2579, -2579, -2579,  1459, -2579, -2579,  2382, -2579,
   -2579,  1715,  1913, -2579, -2579, -2579,  1094, -2579,  1209,  2349,
    1209, -2579,  1178,   187,  5215,  5215,  5215,  1916, -2579, -2579,
     255,   255,  1459,  1726,  1178,    35,  1693,    66,   255, -2579,
    1737,  5215,  2003, -2579, -2579,  1799,   311,  1612, -2579,  3596,
   -2579, -2579, -2579,   311,  1297,  2412, -2579, -2579,  1757,    83,
     192,   255, -2579, -2579,  2404,  2405, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  2390, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    3739,   255,   255, -2579,  1169,  5215,   -84,  1089,  1097, -2579,
   -2579, -2579, -2579, -2579,   182, -2579, -2579, -2579, -2579,  2213,
    1979, -2579,  1992,   678,  5215, -2579,    74, -2579, -2579,   311,
    2400,    35,    35, -2579,  1797, -2579,    59,  1769,   255, -2579,
     311,   311,   311,  5215,   -94, -2579,  1820, -2579, -2579,   300,
   -2579,  1910, -2579,  1911,  5215,  1256, -2579, -2579,  1777, -2579,
    2445, -2579,  1849, -2579, -2579, -2579,   255, -2579, -2579,   173,
   -2579, -2579, -2579,   209, -2579, -2579, -2579, -2579,   311,    35,
      35,   178,   270,  2244,  1990,   255,   192, -2579,  1860, -2579,
   -2579,  2412,  2434,  2006, -2579, -2579, -2579, -2579, -2579,  2083,
    2083, -2579,   196,  1868, -2579, -2579,   311,  1459, -2579,  1459,
    1459, -2579, -2579,  1459,  1459, -2579,   311,  1628,   -10,  1459,
   -2579,  1628, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,    -2,    -2,   909,  1096, -2579,  1054, -2579,   814, -2579,
      31,  2438, -2579, -2579,  1369,  2021, -2579,   508,  1399,  2440,
   -2579,  1399,  1652, -2579, -2579,  2022,  2023,  1704, -2579, -2579,
   -2579,  2226,  2226, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,  1794,   -10,  2025,  8237,   512,  8210,  1950, -2579, -2579,
   -2579,   512,   512,   512,   512,  1805,  8210,  8210,   251,  1897,
     584,   311, -2579,  8210,  8210,  8210,  8210, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  1800,  -156,  1094,  5215, -2579, -2579,
    2032,  2033,  2438, -2579, -2579, -2579, -2579, -2579,  1999,  2001,
    2004,  1076,  2007,  2009, -2579, -2579, -2579,  2372,   311, -2579,
    2483, -2579, -2579,   603,  3873, -2579, -2579, -2579, -2579,   311,
   -2579, -2579,   603,  1775, -2579,   429, -2579,  1821, -2579,  1854,
   -2579,  2047,   243, -2579,  1825, -2579,  1857, -2579,  1901,  2016,
     311, -2579, -2579, -2579, -2579,  3796,   311, -2579,  1834, -2579,
   -2579,  2349, -2579,  2349,  1828, -2579,  2502,  2504, -2579,  2505,
    1890,  5215, -2579, -2579,  2507, -2579,  1856, -2579,  1984,  1845,
    2312, -2579, -2579,  1852,   992,   311, -2579, -2579,  2040,   181,
    1127,  1616,  1863,   341, -2579, -2579, -2579, -2579,  5215,  1459,
    1094,   -73, -2579,   311,   311,  5215,    60,   -13,  2526,   540,
    2527,  2510,  2513,  2443, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,   255,  2166, -2579, -2579, -2579, -2579,  2419,  5215,   678,
   -2579,  2272, -2579, -2579, -2579,  5215,   123, -2579,  2165,  2544,
    2547,   489,   496,   311,  2105,  1178, -2579,  3564,  2069,  2075,
    2076, -2579, -2579,  2146, -2579,  5215,   -76, -2579,  1917, -2579,
   -2579,   256, -2579,  5215, -2579, -2579,  1884,   425, -2579,  1372,
     311,  2553,  8137, -2579, -2579, -2579,   255,  1094,   255, -2579,
   -2579,   211, -2579,  2312,  2312,  1866, -2579,  1965,  1970, -2579,
   -2579, -2579, -2579, -2579, -2579,    35,    35, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  2182, -2579, -2579, -2579, -2579,
      35,  3589,  2567,  2548, -2579,  1178,   988,   126,   106,  2418,
       5,  1034, -2579,    42, -2579, -2579, -2579,  2094,    40,  1459,
     258,  1909, -2579,  1907, -2579, -2579, -2579, -2579, -2579,  2098,
    2098, -2579, -2579, -2579, -2579,  1987,  1915,  2579, -2579, -2579,
   -2579,   481,  1912,  1919, -2579, -2579,   255,   246, -2579, -2579,
   -2579,  1908,  1096, -2579,   311,   311, -2579, -2579,   311,   778,
   -2579, -2579, -2579, -2579,  2107, -2579, -2579, -2579,   628,  1399,
   -2579,   662, -2579,  2149,  2161,  1399,  1399, -2579, -2579,  1787,
    8210, -2579,   411,  2589,  2162,  2593, -2579, -2579, -2579,  8210,
   -2579,   500,  8210,  8210,  8210,  8210,   311,   501, -2579,   432,
    2598, -2579, -2579,    79,  7716, -2579,  2187,   311,  1942,   512,
    2227, -2579, -2579, -2579, -2579, -2579, -2579,  1787,  2591,  1787,
   -2579,  5711, -2579, -2579,  2134, -2579,  2103,  2106,   165,   165,
     165,   502,  2372,   165,  7716,   311, -2579,   504,   311,   505,
   -2579, -2579, -2579,  2135,  2137,  2140,  1660,  1660, -2579,  2141,
   -2579,  2142,  2143,  2144,  2147, -2579, -2579, -2579, -2579,  1254,
   -2579, -2579, -2579,   506, -2579, -2579,   513,   311, -2579,   311,
    1719, -2579,   311,  1722,  5215, -2579,   311,  2625, -2579, -2579,
     603, -2579, -2579,  1959,   603,   219, -2579, -2579, -2579,  1178,
    5215,  5215,  5215,  4611,  2628,  1459,    78, -2579,  1178,   311,
   -2579, -2579,   311,   311, -2579,  1006, -2579, -2579,   366, -2579,
    1962,  5215, -2579, -2579, -2579,  2627,  3596,  2123, -2579,  1972,
    2640, -2579, -2579,  1178,  2017, -2579, -2579, -2579, -2579, -2579,
     311,  2312, -2579,   192, -2579,  2041, -2579, -2579,   521, -2579,
   -2579, -2579,   255, -2579,  4765, -2579,  1182, -2579, -2579,  2265,
    2624, -2579,  2248,  2250,  2152,  1981,  2252,  2170, -2579, -2579,
   -2579, -2579,   688,  2245, -2579, -2579, -2579, -2579,  2146, -2579,
   -2579, -2579,   274,   263, -2579, -2579, -2579,  2412,  5215,  2183,
   -2579,  2158, -2579, -2579, -2579, -2579,  2659, -2579, -2579, -2579,
   -2579,  2664, -2579,  1967, -2579,  2646,   -13,   311,  2195,  2195,
    2195,  2195,  2195,  2195, -2579,  2675, -2579,  2676,  2195,  2195,
    2195,  2195,  2390, -2579, -2579,  2195,   198, -2579, -2579, -2579,
   -2579,  2657,  2669, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579,  2670, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
     527, -2579, -2579, -2579,  2660, -2579, -2579,  1459, -2579,   -10,
   -2579, -2579, -2579, -2579, -2579, -2579,  2037,  2039,   139, -2579,
      42, -2579,   165,  2020,   181, -2579,  2205, -2579, -2579, -2579,
     311,   311,   165, -2579, -2579,   144,  1459,  1159,  8210,   326,
   -2579,  5215, -2579,  5215, -2579, -2579, -2579, -2579, -2579,  2085,
     181,   144,  1459,  2691, -2579,   255,   311,   970,   970, -2579,
   -2579,  2695, -2579,  2695,   978,   978,  2695, -2579, -2579,  1985,
   -2579,  1399,  2677, -2579,  1399,  1734,  1399,  1399, -2579, -2579,
    2220, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   245,  1660,
    2028,  1660, -2579,  1660,  2260,  8210, -2579,  2262,  2263,  2266,
    2267, -2579, -2579,   251, -2579,   251,   311, -2579, -2579,  7815,
    1875,  7629,  1875,  2706,  2709, -2579, -2579, -2579, -2579, -2579,
   -2579,   299,  8210, -2579,  2215, -2579,  2394,   134,   126,   311,
   -2579,  2271, -2579, -2579,  2563,    68, -2579,  1634, -2579,    68,
    1459,   588,  2273,  2715,  2050, -2579, -2579,   530, -2579,   531,
    1076, -2579, -2579,   533,   278, -2579, -2579, -2579,   603, -2579,
    2697,  2697,  2699,  2051,   -32,  2701,  2702,  2704,  2701,  2701,
   -2579, -2579, -2579,   204, -2579,   756,   311, -2579,   603, -2579,
   -2579, -2579,  2059, -2579, -2579,  2061, -2579, -2579,  -215,   534,
   -2579,   311,   535, -2579,  5215,  2284,  2714,   538,  1178,  2730,
   -2579, -2579, -2579, -2579,  5215,  2117,  2407,  5215, -2579, -2579,
   -2579, -2579,   366,  1059,  1059,  2733,   -49, -2579,  2735, -2579,
   -2579, -2579,  1059,   311,  2148,  1415,  2736,   311, -2579,  3596,
     168,  1459,  2734,  1178,  -119,  2526,  5215, -2579, -2579,  2443,
   -2579,  2029,  5215, -2579, -2579, -2579,  2740,  3564,   255, -2579,
    1073,   311,   255, -2579,  2298,  3564,  3564,  3564, -2579, -2579,
     688,  2245, -2579,  2390, -2579, -2579,  1220, -2579, -2579,  2124,
   -2579,  3596,  4845,  8137,    47,  1137, -2579, -2579, -2579,  2080,
   -2579, -2579, -2579, -2579, -2579, -2579,    35,  2195,    35,  2195,
   -2579, -2579, -2579, -2579, -2579, -2579,   -13, -2579,  1231,  1235,
    3589, -2579,  2306,  2270,  8210, -2579,   106,   106, -2579, -2579,
   -2579, -2579,   539, -2579,  2235, -2579,   165,   947, -2579,  2081,
   -2579,   555, -2579, -2579,  2756, -2579, -2579,  2163, -2579,  2758,
    1355,  1355,  1355,  1355,   165,   165, -2579, -2579, -2579, -2579,
   -2579, -2579,  2756,  2086,   255, -2579,  2695, -2579, -2579,   311,
     978,   978, -2579, -2579,   978,  2498,  2091, -2579,   686, -2579,
    2321,  2322, -2579, -2579,  2742,  2323,  2095,  1787,  2099,  2101,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,   560, -2579, -2579,
   -2579, -2579,   282,   185, -2579,  7716,  7716, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  8470,  8470,  2296,  8470,  2297, -2579,
    8470,   664,  8210,  2767, -2579, -2579,  7716, -2579, -2579, -2579,
   -2579, -2579,  2775, -2579,  -154, -2579, -2579,  2394,  2108,  2112,
   -2579, -2579,   123,   123,   123,  2759,   123,   123,   123,   123,
     123,   123,  2760, -2579,  2764,   123, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  2563, -2579,   255,  2119, -2579,  2282,
    2766, -2579,  2768,  2769,  2771,  2772,  2773,  2779,  1221,  1634,
   -2579,  2282, -2579, -2579,  2780, -2579,  2442,   165,  1481,   165,
   -2579, -2579,  2372, -2579, -2579, -2579, -2579,  2344,  2353,   562,
    1787,  2781,  1787, -2579,  2803,   563,  2367,  2369,  2803, -2579,
   -2579, -2579, -2579,  1459, -2579, -2579, -2579,  2333, -2579, -2579,
     756, -2579,  2372, -2579, -2579,   311,   311, -2579, -2579,   311,
    -291, -2579,   603,   223,  2412, -2579,  2299,   223,   280,  1178,
   -2579,  2815,  2337, -2579, -2579,  2375,  2222, -2579, -2579,   311,
    1059,  3596,  1483,   311,  1059, -2579, -2579,    35, -2579, -2579,
    5215, -2579, -2579,   375, -2579, -2579, -2579,  1178,  2819, -2579,
      35,  2412,   255,  2533, -2579,  2808,  1965,  5711,  2810, -2579,
   -2579,   192,  2356, -2579, -2579,  3564, -2579, -2579,  2393,  2395,
   -2579, -2579, -2579,   263, -2579,  1965, -2579,  5215, -2579,   378,
   -2579,  2291, -2579, -2579, -2579, -2579,  2350,  2444, -2579,  2828,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,   311, -2579,   133, -2579, -2579, -2579,   165, -2579,   -10,
    2650,   564, -2579, -2579, -2579, -2579,   311,   165, -2579,   144,
     144,  2246,  8109,  8109, -2579, -2579,  8297,  2366, -2579, -2579,
    2368,  2370, -2579,  2371,  2373,  2376,  2379,   311,   736, -2579,
   -2579, -2579, -2579,   572, -2579, -2579,  2304, -2579, -2579, -2579,
     574,  2845,  2845, -2579, -2579,   578,  2855,  2849, -2579,   102,
     255,   144, -2579, -2579, -2579, -2579, -2579,  2597,  8629,  1399,
    1747,  1399,  1399,  2421, -2579,  1787,  2422,  1787,  1787,   251,
   -2579, -2579,  2709, -2579,  2377,  1806,  2377,   199, -2579,  2377,
     199, -2579,  2377,  8470, -2579, -2579,  8210, -2579,  8210,  2706,
     134, -2579, -2579, -2579, -2579,  1787, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,  -137,  2861, -2579,   255,  1876, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   384, -2579,
   -2579, -2579,  2354, -2579, -2579, -2579, -2579,  2846, -2579, -2579,
    2423, -2579,  2848,  2430,  2853, -2579, -2579, -2579,  2436, -2579,
    2402,  7716, -2579, -2579, -2579, -2579, -2579,   311,  2859, -2579,
    -291, -2579, -2579,  2863, -2579, -2579,  2864,   311,  2394,   223,
   -2579,    35,   -13, -2579,  2460,  1178, -2579,  5215, -2579,  2274,
    2866,   -13, -2579, -2579,  1160, -2579, -2579, -2579, -2579,   201,
    2448, -2579, -2579,  1178,  2312,  2664,  2596, -2579,   -13,  2449,
    2450,  2526,  2414, -2579,  2499,  2452, -2579, -2579, -2579, -2579,
   -2579,  2604,  2391,  5215,  2408, -2579, -2579, -2579,  1965, -2579,
     589, -2579,   255,  2310, -2579, -2579, -2579,  8210, -2579, -2579,
     165, -2579,  2420, -2579, -2579, -2579,  2756,  2310,  2365,  2365,
    2458,  8237,   512,  8404,   512,   512,   512,   512,   -34,  8404,
    1355, -2579,  8404,  8404,  8404,  8404, -2579, -2579,   165,  2893,
     165,  1355,   181,  7716, -2579,  2664,    97, -2579, -2579, -2579,
   -2579,  2462,  2464, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
     204, -2579, -2579,   594, -2579, -2579, -2579, -2579,   596, -2579,
    2377,  2906, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   255,
    2861, -2579, -2579, -2579,   255, -2579,   255, -2579, -2579,  2109,
   -2579,  2619,  2620,  2891, -2579, -2579,  2470,  2241, -2579, -2579,
   -2579,  2473, -2579,   165,   380, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  1178, -2579,  2476,  8871,
    2437, -2579, -2579, -2579,  2259,   -13, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,  2486,   192, -2579,  2499,  2499,  2499,   263,
   -2579,  3596,  2313, -2579, -2579,   311, -2579,  2664,   584,   245,
   -2579,  8165,   584, -2579,  2487,  8404, -2579,   602,  8404,  8404,
    8404,  8404,  2912,   311,   607, -2579, -2579, -2579, -2579, -2579,
   -2579,  2455, -2579, -2579, -2579,  2706, -2579,   311, -2579,  1399,
    1399, -2579, -2579, -2579,   234, -2579, -2579, -2579,  8210, -2579,
    2002,  2002, -2579,  2002, -2579,  2002,  2002, -2579, -2579, -2579,
    2461, -2579,  1787, -2579,   610, -2579,  1268, -2579, -2579,    89,
      89,    89,    89,    89,    89, -2579,  2918, -2579,   612, -2579,
    5215,  1547, -2579,   153,  2499,  3564,  2499,  2526, -2579, -2579,
   -2579, -2579,  2647,   393, -2579,   -13, -2579, -2579, -2579, -2579,
     615, -2579, -2579,  1452, -2579,  2500,  8404, -2579,  2501,  2508,
    2511,  2512,   394,  2433, -2579,  1355, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,  2002, -2579,  2002, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  1288, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  8871, -2579,  2947, -2579, -2579,
   -2579, -2579,   788, -2579, -2579, -2579, -2579, -2579, -2579,   211,
   -2579,  8165, -2579,  1749, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579,  2927, -2579,  2929,   616, -2579, -2579,  1294,  1294,
   -2579, -2579,  1294, -2579,  5215,   847, -2579, -2579,  2514,    47,
   -2579,  2286,  2289,  2965, -2579,  2494,   400, -2579, -2579, -2579,
   -2579,  2528, -2579, -2579, -2579,   311,   311,  1749, -2579,  2951,
   -2579, -2579,   225,  2318, -2579, -2579,  2497, -2579,   192, -2579,
     311, -2579,  2526, -2579
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2579, -2579, -2579, -2579, -2579,   419, -2579,   483,  -174, -2579,
   -2579, -1176,   -72, -2579, -2579, -1879, -2579, -2579, -2579, -2579,
    -445, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -1729, -2579,
    -995, -2579,  1969, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
     747, -2579, -2579, -2579, -2579,  1411, -2579,  1080, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  2311, -2579,   -44, -2579, -2579,
    2964, -2579,  2967, -2579, -2579, -2579, -2579, -2579,   832,   473,
   -2579,   834, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,  -110,  1274,   461, -2579, -2579,  2648,    49,
   -2579,  2892, -2579, -2579,  2889, -2579,  2799, -2579, -2579, -2579,
   -2579, -2579,  2661,  2339,  1255,  2656,  -542,   927, -2579, -2579,
   -2579, -2579, -2579,  1257,  -659, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,   892, -2579,  2474,  2802,    32,  2406, -2579,
    -202,  1707, -2579,  2633, -2579, -2579, -2579, -2579,  2635, -2579,
   -2579, -2579, -2579,  -396, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579,  2451, -2579,  2446, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -1211, -2579, -2579,  -387, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,  -124, -2579, -2579,
    1214, -2579, -1135, -1177,  -532, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579,  2019, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    -628, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  2211, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,  -576, -2579,  -102,
   -2579, -2579, -2579, -2579,  2607, -2579, -2579,  -258, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    1751, -2579, -2579, -2579, -2579,  1017, -2579, -2579, -2579, -2579,
   -2579, -1718, -2579, -2579,  1011, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -1148,  -886,   879,  1177, -2579,
    -229,  -571,   467, -1141,  1021, -2579,   922, -2579, -2187,    -3,
    -340, -2579, -2579, -2052,   337,  1833, -2579, -2579, -2579,   511,
    1425, -2579, -2579, -2579, -2579, -2579, -2579,   460, -2579,   150,
   -2579,  1427, -2579,  1104, -2579,   790, -2579, -2579, -2579, -2579,
    -415, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
     890, -2579, -2579, -1562, -2579,  1095, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,  1590, -2579, -2579, -2579, -2579, -2579, -2579,
     -51, -2579, -2579, -1753, -2579, -2579, -2579, -2579,   525, -1941,
   -2579, -1122, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  3039, -2579,
   -2579, -2579,  2966,  3016,   687, -2579, -2579,   617, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  3018, -2579,
   -2579,  3042, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  2121,
   -2579, -2579, -2579, -2579, -2579,  1146, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  -708,  2301, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  2285, -2579, -2579,   -31, -2579,
   -2579,  1148, -2579, -2579,  1478,  -192,  2743, -2579, -2579, -2579,
   -2579,   648, -2579, -1067,  2035,  1448, -1475,  1537, -2579,  1150,
    1827,    50,  -136, -2579,  2280,  1630, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  1545, -2579, -2579, -2579,
    -782, -2579,  -390, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    -338, -2579, -2579, -2579, -2579, -2579, -2579,   514, -2579, -1169,
    1646,   434, -2579, -2579, -2579, -2579, -2579,   324, -2579,  -130,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  1540, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  -523, -2579,  1208,  2642, -2579,
   -2579,   336, -2579,  -625, -2579, -2579,   354,   660, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,   867, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,   284, -2579,    23,    26, -2579, -2579,    36, -2579, -2506,
   -2579,   296,   963, -1374, -2579, -2579, -2579,  1323, -2579, -1739,
   -2579, -2579, -2579, -1709, -2579, -2579, -1725, -2579, -2579, -2579,
   -2579, -2057, -2579,  1342,  1013, -2579, -2579, -2579, -2579, -2579,
     795, -2579, -2579, -2579, -2579, -2579, -2579,  -316, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,   114, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,  1465, -2579,  1466, -2579,   781,  1129, -2579,
   -2236,   202, -2579, -2579, -2579, -2579, -2579, -2579,   356, -2579,
   -2579,  -108, -2579,  -948, -1358, -2579, -2579, -2579, -2579, -2579,
     323, -2579, -2579, -2579, -2579, -2579, -1735, -2579, -2579, -2579,
   -2579, -2579, -2579, -2270,  1065, -2579, -2360,  1149, -2579, -2579,
   -2053,   441,   442,   721, -2579, -1910, -1627, -2579, -2579,   142,
    -181, -2579, -2579, -2579, -2579, -1660, -2579, -2579, -2579,   347,
   -2579,   675,  -633, -2579,  -580,  -317,  1503,    98, -1069,   698,
     737, -1046, -2579, -2579, -2579, -2579,  2530, -1259, -2020,  3146,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  -331, -2579,
   -2030, -2579,  1874, -2579, -2579,   650,   724, -2579, -1888,   720,
     232,   537,    18, -1622, -2016,  1428,   160,  -504, -1271, -2579,
    1437, -2579, -2579, -2579,  1536,  -568, -2579, -2579,  -111,  1918,
   -2579,   377, -2579, -2579,   841,   257, -2579, -2579, -2579, -1891,
      24,    33, -2579,   331, -2579, -2579, -2579, -2579,  1573, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2505,
       4, -2579, -2578, -2510, -1081, -1056, -2579, -2579,    20, -2579,
   -2579, -2579,   653, -1074,  1439,  -762,  2057,  1724,  1717, -1641,
   -2579, -2579,   670,  1018,   136, -2579, -2579, -2579, -2579,  1744,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   216,
    1200,  2654, -2579, -2579, -2579, -2579
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1973
static const short yytable[] =
{
      40,    42,    43,    45,   277,   336,    45,    50,   582,    94,
     191,  1431,   421,   422,  1027,  1492,  1869,  1546,  1489,  1499,
    1500,  1554,  1501,   244,  1522,  1523,  1381,   977,  1014,  1384,
     981,   109,  1793,  1199,  2398,   701,  2009,  1145,  2675,   419,
     420,  1777,   966,   990,    66,  2462,   438,  1711,  1712,  1520,
     593,  2464,   390,  2135,    94,  2575,   305,   108,  2110,    66,
    1947,  1948,    39,  2960,  2961,  2962,  1115,  2440,   972,  2442,
     115,  2062,  2063,  2064,  2065,    39,   191,   122,  1488,  1895,
    2134,    39,   129,  2055,   436,   131,    39,    39,  1858,   134,
     135,  2177,  2311,    39,  1754,   191,  1755,    79,  2519,  2606,
    2050,   593,  2929,  1059,   341,    39,    39,  1078,    66,   283,
     342,   343,   427,  1083,  1621,  1493,    39,   428,  1090,   430,
      86,  2529,  1626,  1490,   239,  2652,   118,   241,  1631,   243,
     369,  1061,    39,    39,   247,   374,   375,   604,  1737,  2964,
    1581,  1644,   334,  2686,   605,  2688, -1971,   283,   423,  1079,
     334,  1203,   440,    39,   442,   524,   443,   444,   445,  1059,
    2721,    39,  2327,  1087,  1088,   450,    39,  2894,    79,   461,
     462,    39,   204,  1150,   427,  1447,  1153,   609,     1,   428,
     429,   430,     2,  1858,   610,  1198,  1622,  1545,  2854,   106,
    1059,     3,    39,  1059,  2697,    39,   339,  2698,  2699,  2700,
    2701,  2702,  2703,   593,    39,  1461,   593,  1085,    39,  1862,
    1239,  1863,  1108,  1864,    39,  1137,   283,  1251,  1252,    39,
    1813,  3014,   575,   283,  1321,  1322,    39,   191,   283,  2799,
    1322,  1101,   191,  1461,   106,  1547,  1548,   283,   337,   338,
      39,   334,  1610,   577,  1203,   377,    39,  2334,  2331,  1207,
    1737,  2365,   359,   283,  1251,  1252,    39,   406,   283,  1321,
    1322,    39,  2756,    66,   418,   418,   418,   418,   418,  1448,
    1449,   585,   418,   593,  1610,  1626,  1059,  1192,    39,  1918,
    1822,     4,    39,   367,  2695,  3094, -1971,  1209,  2695,  3083,
    1224,   579,  1529,  1530,  1230,   119,  2260,  3316,  2620,  2574,
    1236,    39,  1238,  1912,    86,  1603,  1604,  2373,  2697,  3182,
    2376,  2698,  2699,  2700,  2701,  2702,  2703,  1261,  1881,    66,
      66,  2237,   619,  1918,     5,   622,   979,  2859,   525,  2088,
     527, -1971,  2639,  1471,  1649,   334,    62,   671,    39,  1313,
     595,  2604,   630,   631,   632,   633,  2186,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   970,   957,  3084,  3085,  2692,  1055,
    1058,  2533,  1818,    62,   651,   652,  2817,   593,  1887,   654,
    2186,   655,    39,   334,  3077,   438,  2695,   593,   614,  3233,
    1145,  1978,  1979,  1935,   658,   659,   660,   661,   334,  3452,
     679,  1070,   669,  1310,  1472,  3489,   993,  1091,  1698,    52,
    1091,    79,  1203,  2102,    39,  1155,  2399,   331,  1793,  2438,
    1100,   971,  2177,  1868,  1091,  2818,    89,   191,  1091,  2640,
    2641,  2642,  2643,  2644,    62,  1117,   954,  3011,  3078,    62,
    1091,     5,  1100,   682,  1651,  3497,  1141,  1261,  1129,   684,
     161,  1100,    39,  2791,  3216,  1939,  1611,  1059,  1139,    39,
     587,   588,   589,  2261,  2841,  1154,    62,  1124,   955,     1,
       7,   688,  1197,     2,    51,  1307,    62,  1757,  1627,  3302,
    1026,  1141,  1308,  1129,  1757,  1605,  3012,  1129,  1611,  2337,
    1763,  1129,  1349,   191,   593,  1428,    56,  1100,  1131,   596,
    1100,   593,    62,  3217,  1958,  2405,  2405,  2460,    39,  2108,
    2468,  2486,  1261,  1054,    66,   853,   946,  1442,  2488,   994,
     980,    62,  2089,     8,  3086,    51,  2549,   324,   325,   326,
     327,   328,  2610,  1314,  2038,  2779,  2779,  1583,  2779,  2819,
    2822,  1399,  1400,  2822,  2917,  1542,  1054,  1919,  2203,   694,
      85,   694,  1194,  1195, -1971,  1915,  2193,    86,  1439,   694,
    2927,     6,  1657,  1133,  1882,  2989,   606,  3057,  3064,  3150,
     191,  1401,  1402,  1403,  1627,  1936,   406,  3170,   406,  3170,
      33,  1245,  3252,  3178,  1248,  2338,  2914,  2915,  1054,   969,
     418,  1919,  2860,   974,  3285,  2621,  2194,   589,  2913,  3324,
    1661,  3324,  1699,    87,    88,    32,    33,  3386,  1264,     7,
      89,   418,  3386,  2704,  2705,  2777,  2534,  3425,   335,  2074,
    3441,  3170,  2200,  2842,  1263,   580,   530,  3498,   995,   686,
      39,  1658,  2882,  2051,    62,  2757,  1560,  1963,  3303,    61,
       8,    39,  2895,  1494,     1,   988,  2792,  1542,  2656,  1577,
    1326,  2319,  2157,  2328,  2158,  1326,  2202,  2986,  1879,    39,
    3305,  2633,  1778,  3009,  1658,   576,  1192,  1606,  2706,     9,
    1253,  3313,    62,  3310,  3003,  2244,  1562,    32,  1568,  3118,
    1132,  3183, -1971,  1561,  1145,  1326,   578,  1980,  1549, -1971,
   -1971, -1971, -1971, -1971,  3156,   938,  1495,  2614,  3129,    66,
      66,    66,  1046,    66,  1050,  1052, -1971,    60,  1060,  1062,
    1063,  3095,    77,  1068,   586,  1052,   594,  1025,  1071,  3199,
      66,  1491,   486,  1741,  1722,  3054,  2784,  2704,  2705,  1063,
    2991,  2909,  1037,  1700,  1765,  3186,  1703,  1704,  1264,  3142,
    1060,  1060,  2450,  2785,  1896,  1825,  1582,  1226,  2416,  2814,
    1063,  2209,   487,  1865,   415,  3073,    66,   304,  1693,  1552,
     607,  1866,    66,  1063,    66,   431,  3317,   973,    66,  1254,
    3059,    66,  3061,  1118,    66,  1550,  2503,  2813,   415,   415,
    2503,  1052,  2706,  3288,    66,   415,  2192,  3102,  2247,   418,
    1135,  3107,  1060,  2400,  2707,   304,  1142,  3292,  2450,    66,
     611,  2265,  1450,  1264,  3100,    66, -1971,   418,   418,  1462,
    1496,  1385,    66,    66,    66,  1612,  1197,  3455,  1220,  2069,
     599,  1227,  2187,  1269,  1723,  1109,    66,   431,  3345,  2450,
     600,   615,  2450,  1240,  1713,  1240,   418,  1487,  1240,   418,
    1789,  1240,    66,   680,  1738,  2366,  1809,  1612,  2508,   488,
     489,   490,   491,   492,   493,  1814,  3111,  2473,  2474,  3132,
    2708,    62,  1607,    89,   304,  3234,   332,   494,   495,   496,
    2358,   304,  1204,    39,  3438,  3453,   304,  2265,   110,    10,
    2350,  3490,  1837,  1701,  1824,   304,   683,  1370,  1054,  2351,
    1370,  1643,   685,   111,   112,  1608,  1839,   669,  3087,   669,
     669,   304,   114,  1692,  1309,  1768,   304,     5,  2707,    39,
    2709,  2710,  2228,  2352,   689,   117,  2353,  2413,  1769,  1714,
    1758,   286,  1826,  1827,  1828,  1057,  1057,  1759,  2056,  3378,
    1057,  1057,  2354,  1764,  1768,  1715,    39,  2222,  1404,  1846,
    1641,  1154,  1197,  1057,  2223,  1289,  1260,  1769,  2406,  2412,
    2461,  3284,  2466,  2469,  2487,   333,  2039,    44,    90,    39,
    2836,  2489,  2645,  1057,  1923,  3196,  1057,  3197,  3198,  2550,
    3004,  2801,  1057,  2077,  2708,  2611,  1057,  1716,  2780,  2781,
    1057,  2783,  2820,  2823,  1057,  1454,  2827,  2918,  1057,  1057,
    1304,  1057,  1455,  1342,  1057,  3214,  1057,  1057,  1057,  2959,
    2959,  2959,  2959,  2928,  1057,  1904,   497,  1057,  2990,   498,
    3058,  3065,  3151,  1880,  1057,    39,  1717,  1302,  3244,  1770,
    3171,  1057,  3177,  1405,  2709,  2710,  3179,     6,  1057,  2455,
    2458,  2458,  1562,  1543,  2458,  2355,  1395,  3286,   694,  1057,
    1893,  2057,  3325,  1057,  3326,  1718,   411,  1057,  1770,    91,
    3387,  1911,   119,  1057,  1719,  3394,  1057,   107,  3410,  1047,
    3426,    39,  1926,  3442,  3477,  3176,  1406,  1986,   412,  1987,
    1988,  2802,  1060,  1990,  1991,    66,  2381,  1702,  2996,  2010,
    2999,  1388,   121,  3002,  1544, -1971,  3202,   123,  2356,  3207,
    2588,    66,  3209,    62,  1060,  2357,    39,  2520,  1145,  1072,
      39,  2774,  2782,  1526,  1696, -1971,     8,  3005,  2803,  3006,
    2384,  1536,   197,   627,  1793,  1883,    39,  1783,  1140,  1477,
      39,    39,  2040,  1885,    39,  2042,  3466,  1093,   499,    92,
    3315,  3289,  1772,    66,  2979,     9,  2545,    93,  1142,  1958,
    2676,  1102,  2678,   500,  2679,  1107,  1736,   501,  1773,  1142,
    2058,  2078,  2459,  1261,   127,  2463,    62,  1121,  2073,   366,
    2377,  1772,  2079,    66,    66,    66,  1077,    66,   693,    66,
      66,   982,  2804,   983,  1479,    66,    66,  1773,   324,   325,
     326,   327,   328,   502,  2151, -1971,  2805,  1095,   324,   325,
     326,   327,   328,  2625,    61,  1417,    39,   378, -1971,  2329,
    1104,    66,   698,  1203,  1588,    39,    39,  1840,  2553,    39,
     952,   503,  1575,  2170,    66,  2171,  1637,  1418,    39,  2651,
    2053,  3169,  2060,  1587,   379,  1262,    66,  2170,   504,  2171,
    1423,  1595,  2060,  1349,  1819,    62,    39,   198,  1133,  2083,
    2084,  2085,  2086,   288,   536,  2884,  3044,    39,    39,  1479,
      66,    66,  1424,   201,  2530,  1423,   546,  2905,    39,    66,
   -1658,  2907,    39,  2623,   111,   112,   291,  3176,  3176,  1263,
    2382,  2218,  1963,  2632,    13,    66,    66,  1424,   535,  2189,
   -1971,    62, -1971,  1439,   541,  2806,  1766,  1468,  1767,   242,
    1225,  2959,  2959,  2317,  1231,  2959,    13,  3147,  1235,  2164,
    3327,  2807,  1695,  1012,  2385,  1852,  1015, -1971,   693,   505,
    1768,   948,  2024,  1901,  1902,  1342,  1342,  1856,  2172, -1971,
      62,  2173,  3409,  1769,    39,  1342,  2188,  1051,  2980,    39,
      39, -1971,  2172,  1828,   949,  2173,    62,  2227,  1735,   249,
    1141,  1141,   948,  1958,    62,   167,  1742,   438,   297,  1244,
    2016,  1728,  1247,  1729,  1730,  1250,  3206,  1958,   251,  3206,
   -1971,  1943,  1944,  1562,  1291,   949,  2215,   261,  2725,  2824,
     258,  1768,  1057,  2932,  2933,   506,  3210,   191,  1768,   283,
    1321,  1322,    39,  2236,  1769, -1971,   259,  3115, -1971,  2035,
    1802,  1769,  2250,  1323,  1324,   262,    39,  1779,   265,    39,
    3377,  1784,  1790,  1784,  3383,  2891,   986,  2316,   987,  2336,
   -1971,  2861,   330,  1796,  1798,  1799,    62,   363,    66,  1803,
    1805,  1806,  1807,  1060,  1770,    62,    62,  2864,  2258,    62,
    2904,   266,  1060,  2995,  2995,  2848,  2995,  2800,    62,  2995,
     300,   267,    39,  1142,  1264,    66,   268,    66,  3082,    66,
      66,   269,   301,   302,   270,  2025,    62,    66,    66,  1060,
     303,    66,   418,  2383,   418,    66,  1211,    62,    62,  2388,
    2389,  2855,  2919,  1142,  2026,  2027,  1963,  2934,    62,  2923,
    1855,  1142,    62,   271,  1059,  1770,    39,    66,    66,  2073,
    1963, -1971,  1770,  1771,  2028,  3185,  1057,  1057,  1057,  1284,
    1285,  3051,  3295,  3105,  3298,  3299,  3300,  3301,    39,  2182,
      39,   272, -1971, -1971, -1971,  1212,   273,  2480,  2481,  2482,
    2055,   274,  2959,  2504,  1265,  1266,  1267,   275,  2959,  2959,
     276,  2959,  2959,  2959,  2959,  1268,   278,  1772,    66,    66,
    2959,    66,   318, -1971,    66,    66,  1349,  3368,  3369,  3370,
      62,   319,  1213,  1773,  1792,  2404,   320,  2922,  2407,  2408,
    2409,  2410,  2869,  3411,  1419,  1420,  1899,  3428,   418,   418,
    2877,  2878,  2879,   418,    39,    66,  2546,  1908,  1909,  1910,
    2032,  -296,  1477,  3460,    39,  1837,     1,  2509,  2024, -1971,
       2,  2510,   321,  3417,  2949,  2949,  2949,  2949,  1772,     3,
    2521,   322,  1141,    66,  1573,  1772,    39,  1705,  2201,  1706,
    3430,  1708,  2497,  1709,  1773,  1240,   418,   418,   441,  1958,
     323,  1773,    66,    66,   354,  2542,  2582,   355,  2511,  2512,
    1828,  2515,  1797,  2091,    39,  3434,   356,  3436,  1154,  1958,
    1800,  3264,    39,  1982,  1060, -1971,  1060,  1060,  1214,  2536,
    1060,  1060,  1997,  1992,  2959, -1971,  1060,  2959,  2959,  2959,
    2959, -1971,  3417,  1998, -1971, -1971,  -296,  3287,  1579,   360,
    1804,  1197,    39,  3412, -1971, -1971,  2043,  3413,  2044,  3430,
      66,   361,  -296,  3206,  1999,  1555,  1556,  1557,  1558,     4,
    2000,  2036,   365,  3412, -1971,   111,   112,  3413,  2001, -1971,
     370,  1527,  1528, -1971,  1123,  1531,  1532,   371,  3050,  2483,
    3053,   372,  2286,  1130,  1533,  1534,  2579,   174,  1537,  1538,
    2002,  1342,   376,  1342,  -296,  1215,  2274,  2276,  2047,   175,
    2048,  2025,  2995,  1342,  1342,  1060,  1067,  2613,  2082,   381,
    1342,  1342,  1342,  1342,  2492,  2959,    39,  2495,  1076,    39,
    2026,  2027,  1963,  1142,  2959,   382,  1278,  1580,  2670,  1243,
    2671,   391,  1246,  -296,  2214,  1216,  2637,  1279,  1927,   112,
    2028,  3191,  1963,  3192,  3471,  1779,    39,  1096, -1971,   400,
    1784,   401,  2653,   669,   407,  1820,  1790,  1820,   410,  1784,
    2019,  2020,  -296,  1113,  1114,  3443,  3444,   487,   413,  1120,
     448,  -296,  1122,   446,  3121,  2667,  1326,  2149,  2669,   449,
    2672,  2673,  1388,  2153,   346,   347,   348,  1280,   460,  2647,
     463,  2648,   383,   464,  1743,  1744,  1745,  1746,  2183,  2184,
    1217,  1281,   466,  2073,   467,  2073,   468,  2935,  1265,  1266,
    2936,   469,  2180,   470,  1349,  2797,  2798,   392,  3146,     5,
     517,  2760,  1994,  2937,   529,  3160,  1060,  1142,  3154,   533,
    2196,  2197,   531,   418,   538,  1359,  2761,  2762,  1361,   181,
    1362,  1363,  1364,  1365,  1366,  2763,  3158,  3159,    66,   539,
    3123,   324,   325,   326,   327,   328,  2949,  2949,   540,   548,
    2949,  2938,  2939,   182,   488,   489,   490,   491,   492,   493,
    2225,  2681,    66,   542,  2940,   543,   547,   384,   549,  2764,
     553, -1971,   494,   495,   496,   563,  3255,  2693,  2765,  1282,
     424,   425,   426,   385,    66,  3263,  2251,  1595,  2715,  1342,
     564,   568,   393,    66,  1142,    66,   565,   183,   573,   583,
    2828,  2725,  3269,   584,   591,  2941,   184,  2766,   394,   592,
     597,  3205,   418,   418,  3205,  1747,  1748,  1749,  1750,  1751,
    1752,  2189,  1432,  1433,  1434,   386,   598,   418,   602,     6,
     603,   612,    66,    66,    66,  2858,   613,   623,    66,   620,
     625,   628,  2830,   624,  2942,  2835,  1060,   662,  1154,   653,
     395,  2767,   656,   663,  1197,  3221,  2943,   664,   670,   672,
     674,   673,   675,   676,   387,   451,   677,   678,  2944,  2945,
     681,   687,  1852,    66,   699,     1,  2946,     7,   953,  2947,
    1197,  2372,  2372,   958,   992,  2372,   960,   304,   997,   396,
     185,   186,   340,   388,   961,  2768,   345,   962,  1949,  1950,
    1951,  3314,   389,  1952,   967,  1953,  1954,  1342,     8,   968,
    1192,   497,   978,   984,   498,   985,  1342,   999,   397,  1342,
    1342,  1342,  1342,  2411,  1995,  1057,  1060,   398,  1001,  3222,
    2417,  1342,  1002,  1003,  2435,  1020,  1023,     9,  1996,  2258,
    1028,  3290,  3296,  1713,   191,  1029,  1031,  1032,  3296,  3362,
     452,  3306,  3307,  3308,  3309,  2451,  2451,  2451,  1033,  1034,
    2451,  1342,  2465,  1036,  1039,  1779,   453,  3017,  3018,  3019,
    1349,  3021,  3022,  3023,  3024,  3025,  3026,  2949,  1040,  1041,
    3029,  1997,  1152,  2949,  2949,  1042,  2949,  2949,  2949,  2949,
    1232,  3223,  1998,  3224,  2490,  2949,  2491,  2493,  1293,  2494,
    2496,  1294,  1295,  2498,  1296,  1297,  1298,  1784,   454,  3225,
    1299,  1784,    66,  1999,  3322,  1300,    66,  3226,  1301,  2000,
    1303,  3227,  1060,  2451,  1305,    66,  2180,  2001,  1714,  2526,
    2526,  1311,  1306,   499,  2455,  1312,  1316,  1315,  1317,  1360,
    1367,  1368,  1369,  1372,  1715,  1373,  3228,   455,   500,  2002,
      66,  1375,   501,  1386,  1057, -1971,  1376,  2544,  1377,  3440,
      66,  3418,  3419,  3420,  3421,  3422,  3423,  3367,  3007,    66,
    2390,  1378,  1379,    66,  3385,  1380,   456,  3388,  3389,  3390,
    3391,  1382,  1387,  3070,  1391,   457,  1716,  1057,   502,  1392,
    1949,  1950,  1951,  1394,  1416,  1952,  1393,  1953,  1954,    66,
    1422,  1421,  1425, -1971, -1971, -1971,  1745,  1746, -1971,  2949,
   -1971, -1971,  2949,  2949,  2949,  2949,   503, -1971,  1426, -1971,
    1427,  3096,  1429,  1446,  2589,  1717,  2003,  1435,  1452,  1453,
    1456,  1457,  2004,   504,  1459, -1971,  1154,  1154,  3205,  1460,
    1464,  1465,  1467, -1971,  1476,  1479,  1481, -1971,  1484,  3112,
    1524,  1483,  1540,  1541,  1718,  2391,  1545,  1569, -1971,  1570,
    1571,  1572,  3222,  1719,  1576,  3447,  1583,  1578,  1592,  1594,
    1617,  2392, -1971,  1618,  1060,  1619,  1955,   593,  3110,  1956,
    1620,  1957,  3172,  3173,  3174,  3175,  1625,  1629,  1632,  2451,
    1635,  1633,    71,  1634,  1683,   946,  1691,  2628,  1992,  2451,
    2949,  1958,  1982,  1060,  1694,  1342,  1697,  1707,  1756,  2949,
    1724,  1959,  1725,  2393,   505,  3130,  1726,  3215,  1982,  1060,
    1727,  1762,    66,  2372,  3223,  1852,  3224,  2900,  1731,  2902,
    3435,  1732,  1960,  1733,  1734,  1747,  1748,  1749,  1750,  1751,
    1752,  1782,  3225,  1795,  1810,  3174,  3175,  1815,  1811,  2889,
    3226,  1812,  2394,  1816,  3227,  1961,   162,   194,  1817,  1962,
    1447,  1831,  1342,  3190,  1838,  3193,  3194,  1552,  1849,  2073,
    1060,  1847,  1060,  2417,  1845,  1502,  1342,  1858,  1342,  3228,
     506,  2395,  1871,  1888,  1872,  1900,  1860,  1890,  2867,  1342,
    2396,  3502,  1891,   669,  2451,    66,  2435,   191,  2691,  1903,
    2694,   669,   669,   669,  1905,  1922,  1924,  2451,  1932,  1929,
    1930,  1915,  1627,  1747,  1748,  1749,  1750,  1751,  1752,  1970,
    1972,  1973,  1975,   194,  2033,  1784,  2041,  1981,  1502,  2037,
    2045,  2046,  2049,  2051,  1963,  1722,  2074,  2066,  2087,   191,
    2092,  2093,   194,  1790,  2098,  1784,  2099,  2105,  2108,  2100,
    1689,  2137,  2103,  2139,  2104,  2141,  2140,  2142,  2149,  2143,
    2144,  2146,  3211,  2155,  2715,    66,  2159,  2160,  1955,  2161,
    2162,  1956,  2165,  1957,  1747,  1748,  1749,  1750,  1751,  1752,
    2167, -1971,  2163,  2168, -1971,  2181, -1971,  3257,  2166,  2169,
    2180,  1626,  2849,  1958,  2851,  2204,  2206,  2451,  1060,  2207,
      66,  2211,  2213,  1959,  1057,  3267, -1971,  2216, -1971,  2220,
    1057,   414,  2221,  2226,  2229,    66, -1971,    66,  2873,    66,
    2230,  2231,  2248,  2234,  2283,  3258,  2240,  2254,  2265,  2267,
    1080,  1080,  2314,    66,  2315,  2326,  1057, -1971,  1268,  2332,
    1342,  2340,  3189,  2342,  2347,  2341,  2345,  1961,  2380,  3109,
    2361,  1962,  2346,   418,  2401,   418,  2362,  2386,  2403,  2369,
   -1971,  3282,  3114,  2415, -1971,    66,    66,   522,   523,  2387,
    2402,  1342,  2432,  2437,   194,  2443,  2439,  2441,  2444,   194,
    2470,  2447,  2471,  2451,  1503,  2472,  2475,  2476,  2477,  2478,
    2501,  2506,  2479,  2517,  2535,  2537,  2539,  2948,  2948,  2948,
    2948,  2451,  2451,  1349,  2540,  2541,  2543,  2547,  2555,  2556,
    2558,    66,  2559,  2561,  2562,  2563,  2973,  2053,  2950,  2950,
    2950,  2950, -1971,  2580,  2583,  2560,  1963,  3104,  1080,  1542,
    1267,  2581,  2587,  2951,  2951,  2951,  2951,  1503,  1255, -1971,
    2596,  2598,  2607,  2608,  2609,  2616,  2612,  2617,  3347,  2624,
    2626,  2649,  1342,  1342,  2730,  2731,  2654,  2732,  2733,  2734,
    2659,  1342,  1342,  2668,  1342,  2674,  2677,  1342,  2680,  1342,
    2682,  2683,  2695,  1342,  2684,  2685,  2696,  2716,  2719,  2728,
    2777,  2776,  2778,  2786,  2998,  2789,  3001,  2793,  2795,  2790,
    2796,  2815,  2825,  2816,  2826,  2829,  2831,  2832,  2839,   191,
    2843,  2850,  2857,  3397,  3398,  2868,  2876,  2847,  2887,  2865,
    1504,   669,  2899,    66,  2910,  2911,  1505,  1506,  1507,  2926,
    2919,  2929,  2930,  1737,  2971,    66, -1971,  2978,  2983,  2981,
    2982,  2984,  3008,  2985,  2451,  3052,  2451,  2987,  1508,  2988,
    3010,  2997,  3000,  3035,  3020,  3027,  3015,  3382,  3016,  3028,
    3034,  3037,  3055,  3038,  2803,  3039,  2735,  3040,  3041,  3042,
    1060,  3056,   657,  1504,  2736,  3043,  3048,  3060,  3062,  1505,
    1506,  1507,  3074,  3075,   194,  3066,  2498,  3067,  3071,  1784,
    3097,  3091,  3098,  3099,  3400,  3100,    66,  3113,  3427,  1343,
   -1971,  1508,  1057,  1057,  3117,  3119,  2526,  3122,  2737,  3106,
    2526,  3126,  1197,  3127,   418,  3135,  1262,  2738,  3138,  3148,
    3170,  3161,  3142,  3162,    66,  3163,  3164,   418,  3165,    66,
    3180,  3166,  3254,  3181,  3167,  3187,  3219,  2774,    66,  3195,
   -1839,  3237,  3236,  3200,  3238,  1873,  2739,  2740,  3240,  3241,
     194,  2014,  2015,  1509,  3242,  3247,  1510,  3243,  2031,  3249,
    3250,  3256,  3262,  3268,  1511,  3260,  3266,  3270,  3271,  3272,
    3276,  3274, -1971, -1971,  3281,  3291,  3293,  3311,  3139,  1738,
    3319,  1255,  3320,  3328,  2451,  3338,  3339,  3340,  3341,  3342,
    2741,  3343,  3360,  2628,  2451,  3348,  1982,  1982,  1512,  2948,
    2948,  3361,  3481,  2948,  3366,  3384,  1509,  3382,  3392,  1510,
    3395,  3374,  3408,  3424,  3168,  3437,  3454,  1511,  3446,  3448,
    2950,  2950,  3464,  3475,  2950,  3476,  3449,   194,  3485,  3450,
    3451,  3486,  3483,  1513,  2742,  2951,  2951,    66,  1982,  2951,
    3487,  2952,  2952,  2952,  2952,  3488,  3491,  3496,  3501,  2872,
    3463,  1512,  1514,  1515,  2821,  2572,  1060,  1043,  1044,  1045,
    3500,  1048,  1383,  1516,  1142,  1914,  2239,  1142,  1517,    57,
    1342,  2522,  1038,  1342,    58,  1342,  2846,  2451,  1074,  2531,
     544,   200,   205,   353,   537,  1030,  1513,  2094,  2743,   545,
    2095,   358,   690,   991,  1710,   572,   570,   964,  3461,  2152,
     963,    66,  1219,  1374,   608,  1514,  1515,  1518,  1687,  2370,
    2378,  2513,  2198,  1942,  1098,  2898,  1516,  3137,  1946,  2264,
    1103,  1517,  1105,  2586,  3484,  2518,  1112,  1842,  3265,  1112,
    2284,    54,  1112,    68,   136,    69,  2665,  2246,  1342,  1519,
      55,  1292,  1125,  1928,  1969,  2249,  1397,   528,  1119,  1878,
    2253,  1623,  1151,  3329,  3220,  1876,  1255,  1125,   418,  3373,
    1518,  1833,    66,  1188,  3467,  3047,  1823,  2893,  2219,  3337,
    1048,  1201,  1205,  2217,  1894,  3046,  1221,   629,  3030,  2772,
      66,  3093,  3253,  3251,  1233,  3076,  3248,  2507,  2138,  1645,
    2107,  2467,  1519,  2618,  3213,  3470,  2012,  2013,  2638,  2344,
    1257,  3155,  3049,  3072,  2414,  3344,  2992,  2335,  2993,    66,
    2690,  2262,  3208,  3399,  1342,  3068,  2788,  2451,  2773,  1985,
    3235,  1343,  1343,  2689,  1000,    49,  3495,  1675,  1342,  2727,
    2948,  1343,  2726,  3157,  2925,  2068,  2948,  2948,  3212,  2948,
    2948,  2948,  2948,  2067,  3376,  2451,  1977,  2451,  2948,   191,
    1342,  2950,  2630,  3153,  3312,  3294,  1940,  2950,  2950,  3304,
    2950,  2950,  2950,  2950,  2856,  2090,  2951,  1640,  1478,  2950,
    1851,  1857,  2951,  2951,  2538,  2951,  2951,  2951,  2951,  2853,
    1841,   700,     0,     0,  2951,     0,    66,     0,     0,     0,
       0,    66,     0,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2451,   669,     0,  2744,  2745,  2746,  2747,  2748,  2749,  2750,
    2751,  2752,  2753,    66,     0,     0,     0,     0,  1646,     0,
       0,     0,     0,  2952,  2952,     0,     0,  2952,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3139,     0,     0,     0,     0,     0,  1342,     0,
       0,     0,  2948,  3246,     0,  2948,  2948,  2948,  2948,     0,
    3393,     0,     0,  3246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2950,  3396,     0,  2950,  2950,  2950,  2950,
       0,  1142,     0,  1255,     0,  1342,     0,     0,  2951,     0,
       0,  2951,  2951,  2951,  2951,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    66,    66,    66,
      66,    66,     0,     0,     0,     0,     0,     0,  3429,     0,
    1647,     0,     0,  1257,     0,     0,     0,     0,  1648,     0,
       0,     0,     0,     0,  1649,     0,  1650,     0,     0,  1440,
       0,     0,     0,  2948,     0,     0,     0,  1651,     0,     0,
       0,     0,  2948,     0,     0,     0,     0,     0,  1057,     0,
       0,     0,     0,     0,  2950,     0,     0,     0,     0,     0,
       0,     0,     0,  2950,  1652,     0,     0,     0,     0,  2951,
       0,  1470,     0,     0,     0,     0,     0,     0,  2951,     0,
    1653,     0,  2568,  2569,     0,  1654,     0,     0,  1342,     0,
    3472,     0,     0,  2578,     0,     0,     0,  1655,     0,     0,
       0,  1498,  1498,  1498,  1656,  1498,     0,  1498,  1498,  1255,
       0,     0,     0,    71,    71,     0,     0,     0,  2590,  2591,
    2592,  2593,  2594,  2595,     0,     0,     0,     0,  2600,  2601,
    2602,  2603,  3493,  3494,  3472,  2605,     0,     0,     0,  1205,
       0,     0,     0,     0,  2952,    66,     0,  3503,     0,     0,
    2952,  2952,  1205,  2952,  2952,  2952,  2952,     0,     0,     0,
       0,     0,  2952,     0,  1590,   617,   471,   472,   473,     0,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,     0,     0,     0,     0,     0,  1257,  1440,
       0,     0,     0,     0,     0,     0,     0,  1630,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1343,     0,  1343,
       0,     0,   487,  1638,  1638,     0,     0,  2657,  2658,  1343,
    1343,     0,     0,   280,  2662,  2663,  1343,  1343,  1343,  1343,
       0,     0,   281,   282,     0,     0,     0,     0,   283,   284,
     285,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1657,     0,     0,     0,   167,  1658,     0,     0,
       0,     0,     0,  1659,   164,   165,     0,     0,     0,     0,
       0,     0,   166,    39,     0,     0,  2952,     0,     0,  2952,
    2952,  2952,  2952,     0,     0,  1660,     0,     0,   167,     0,
    1661,     0,     0,     0,     0,     0,     0,  2287,  2288,  2289,
    2290,  2291,  2292,     0,     0,     0,     0,     0,     0,   488,
     489,   490,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   494,   495,   496,
       0,   168,     0,     0,     0,     0,   286,     0,     0,     0,
       0,     0,     0,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   168,     0,     0,     0,  2952,     0,     0,
     170,     0,     0,  2837,  2838,   169,  2952,     0,     0,  1080,
       0,     0,  2845,    71,     0,    71,     0,  1205,  1112,     0,
       0,     0,     0,     0,  2293,  1832,  1125,     0,     0,  1205,
       0,     0,   170,  1843,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,  1343,     0,     0,     0,     0,
    2880,  2881,     0,     0,     0,  1257,  1188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2901,     0,  2903,
       0,     0,     0,     0,     0,   280,  1157,  1158,  1159,  1160,
       0,    62,     0,   171,   281,   282,   497,     0,     0,   498,
     283,   284,   285,    39,     0,     0,  1877,  1188,     0,    71,
       0,     0,  1884,  1886,     0,     0,     0,     0,   167,     0,
       0,     0,     0,    62,     0,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2974,  2975,     0,  1906,  2976,  2977,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1343,     0,     0,     0,     0,     0,     0,
       0,  1934,  1343,     0,     0,  1343,  1343,  1343,  1343,     0,
       0,     0,     0,     0,     0,     0,     0,  1343,     0,   172,
    1968,  1257,     0,   168,   287,     0,     0,     0,   286,     0,
       0,     0,     0,     0,     0,   169,     0,     0,  1161,     0,
       0,     0,     0,     0,     0,     0,  1162,  1343,   499,     0,
       0,   172,     0,     0,   173,  1163,     0,     0,  1164,     0,
       0,     0,   170,   500,     0,     0,     0,   501,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2018,     0,
       0,     0,     0,     0,     0,     0,   173,     0,   174,  2294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,  1165,  2295,   502,  2111,     0,     0,     0,  1166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,     0,
     174,     0,     0,   289,     0,   290,     0,     0,     0,     0,
       0,   503,   175,     0,     0,     0,   176,     0,     0,     0,
       0,   291,     0,     0,     0,     0,  1255,     0,   504,     0,
    3103,   177,     0,    62,  3108,   171,   292,     0,     0,   293,
       0,     0,   294,     0,  2296,  1167,     0,     0,   176,     0,
    2297,   295,   179,  3116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,     0,     0,     0,     0,     0,  1168,
       0,   178,     0,  3128,     0,     0,  1169,     0,  1170,     0,
       0,     0,     0,     0,   179,     0,     0,     0,  1171,  2298,
     665,   296,     0,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,   505,
       0,     0,  2299,     0,   298,     0,  1172,     0,     0,     0,
     181,     0,  2300,  2301,  1173,     0,     0,   180,  2302,     0,
       0,   172,     0,     0,     0,     0,   287,     0,  2303,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,   181,     0,     0,     0,  2210,     0,     0,     0,
    2304,  1174,     0,  2305,  2306,     0,   173,     0,  2307,     0,
       0,  1343,     0,     0,     0,   506,   182,     0,     0,     0,
    1205,     0,     0,     0,     0,  1175,     0,     0,   183,     0,
       0,     0,     0,     0,     0,   300,     0,   184,     0,     0,
     174,     0,   162,     0,     0,     0,     0,   301,   302,     0,
       0,  2259,   175,  1188,     0,   303,     0,     0,  2112,     0,
     183,     0,  1176,     0,     0,  2308,   304,     0,  1343,   184,
     288,     0,     0,  1177,     0,   289,  2309,   290,  2113,  2114,
    2115,     0,  1343,     0,  1343,     0,     0,     0,   176,     0,
    1205,  2318,  1205,   291,     0,  1343,  1048,     0,     0,     0,
       0,     0,     0,   177,     0,     0,     0,     0,   292,     0,
       0,   293,     0,     0,   294,     0,     0,  2116,     0,     0,
       0,   185,   186,   295,   179,     0,     0,     0,     0,  2117,
       0,  2364,     0,     0,     0,     0,     0,     0,     0,     0,
    2118,     0,     0,     0,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,   185,   186,     0,  2119,     0,     0,     0,
       0,  3280,  1436,   296,  3283,     0,  2120,   180,     0,     0,
    1178,  1179,  1180,     0,     0,   297,     0,     0,     0,     0,
       0,  2121,     0,  1181,     0,     0,   298,     0,     0,     0,
       0,     0,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1182,  2122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2123,     0,
     183,     0,     0,     0,     0,     0,     0,   300,  2124,   184,
    1205,     0,     0,     0,  1205,     0,     0,  1343,     0,   301,
     302,     0,     0,  1205,     0,     0,  1183,   303,     0,  2125,
       0,     0,     0,  2126,     0,     0,     0,     0,   304,     0,
       0,   194,  1184,  1343,  1343,  1343,  1343,     0,  1205,  3371,
       0,     0,     0,     0,     0,     0,     0,     0,  1257,     0,
       0,  2127,     0,     0,     0,     0,     0,  2551,     0,     0,
    2128,  2554,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   186,     0,     0,  2577,  1343,  1343,
    3401,  3402,     0,  3404,     0,  3406,  3407,  1343,  1343,     0,
    1343,     0,     0,  1343,     0,  1343,   471,   472,   473,  1343,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,     0,     0,  1080,  1080,  1080,     0,  1080,
    1080,  1080,  1080,  1080,  1080,     0,     0,     0,  1080,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3456,     0,  3457,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     282,     0,     0,     0,     0,   283,   284,   285,    39,  3469,
       0,     0,     0,     0,     0,   487,     0,     0,     0,     0,
    2655,     0,     0,   167,     0,     0,     0,     0,  3478,  3479,
       0,     0,  3480,     0,     0,  3482,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
     489,   490,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1255,     0,   487,   494,   495,   496,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1205,     0,     0,     0,     0,   168,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,     0,
     169,     0,   488,   489,   490,   491,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,   495,   496,     0,     0,  1343,  1343,   170,     0,  1343,
    2552,   471,   472,   473,     0,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,     0,     0,
       0,     0,     0,  1205,     0,   484,   485,   486,     0,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,   487,     0,     0,
       0,   494,   495,   496,   194,     0,     0,   487,  1205,     0,
    1343,     0,     0,  1343,     0,     0,  1343,     0,     0,  1343,
       0,  1343,     0,  2870,     0,  1074,   497,  2874,     0,   498,
       0,     0,     0,     0,   280,     0,     0,     0,    62,     0,
     171,  2886,     0,   281,   282,     0,   194,     0,     0,   283,
     284,   285,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,     0,  2906,  2908,     0,     0,     0,     0,   497,
       0,     0,   498,     0,  1343,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,   489,   490,   491,   492,   493,
       0,     0,     0,     0,   488,   489,   490,   491,   492,   493,
       0,     0,   494,   495,   496,     0,     0,     0,     0,  2972,
       0,     0,   494,   495,   496,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,     0,
     497,   287,   168,   498,     0,     0,     0,   286,   499,     0,
       0,     0,     0,     0,   169,     0,     0,     0,     0,     0,
    1343,     0,     0,   500,     0,     0,     0,   501,   601,     0,
       0,   173,     0,     0,  1343,     0,  1343,     0,     0,     0,
       0,   170,  1343,  1343,     0,  1343,  1343,  1343,  1343,     0,
       0,     0,     0,     0,  1343,     0,  1343,     0,     0,     0,
       0,   499,     0,   502,     0,   174,     0,     0,     0,     0,
       0,     0,     0,  1343,     0,     0,   500,   175,     0,     0,
     501,  3031,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,  3045,     0,   288,     0,     0,     0,     0,
     289,     0,   290,     0,     0,     0,     0,     0,   504,     0,
       0,   497,     0,   176,   498,     0,   502,     0,   291,     0,
       0,   497,   499,     0,   498,     0,     0,     0,   177,     0,
       0,     0,    62,   292,   171,     0,   293,   500,     0,   294,
       0,   501,     0,     0,   503,     0,     0,  1255,   295,   179,
       0,     0,     0,     0,  1205,     0,     0,     0,     0,     0,
       0,   504,     0,     0,  1343,     0,   194,     0,  1343,     0,
       0,  1343,  1343,  1343,  1343,     0,     0,   502,     0,     0,
       0,     0,  1205,     0,     0,     0,     0,  1188,   296,   505,
       0,     0,   180,     0,     0,     0,  1257,  1343,     0,     0,
     297,  1343,     0,     0,     0,   503,     0,     0,     0,     0,
       0,   298,     0,  2514,     0,     0,     0,   181,     0,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
     172,     0,     0,   499,     0,   287,     0,     0,     0,     0,
       0,   299,   505,   499,     0,     0,     0,     0,   500,     0,
       0,     0,   501,     0,     0,   506,     0,     0,   500,  1343,
       0,     0,   501,     0,   280,   173,     0,     0,  1343,     0,
       0,     0,     0,   281,   282,     0,     0,     0,     0,   283,
     284,   285,    39,     0,     0,   183,     0,     0,   502,     0,
       0,     0,   300,     0,   184,  1188,     0,   167,   502,   174,
       0,     0,     0,   505,   301,   302,     0,     0,   506,     0,
       0,   175,   303,     0,  1343,     0,   503,     0,     0,     0,
       0,     0,     0,   304,     0,     0,   503,     0,     0,   288,
       0,     0,     0,   504,   289,     0,   290,     0,     0,     0,
       0,     0,     0,   504,     0,     0,     0,   176,     0,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,  3031,
       0,     0,   177,     0,     0,     0,     0,   292,     0,   506,
     293,  1255,   168,   294,     0,     0,     0,   286,   185,   186,
       0,     0,   295,   179,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,     0,     0,   505,     0,     0,     0,     0,     0,
    1205,  2890,   296,     0,   505,     0,   180,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,     0,  1205,     0,
       0,     0,     0,     0,     0,   298,     0,     0,     0,     0,
       0,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1188,     0,     0,
       0,     0,     0, -1972,     0,   299,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0, -1972, -1972,
   -1972,     0,    62, -1972,   171, -1972, -1972,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,     0,   300,     0,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,   302,
       0,     0,     0,     0,  3031,     0,   303,     0,     0,  3332,
       0,  3334,     0,     0,     0,     0,     0,   304,   480,   481,
     482,   483,   484,   485,   486,     0,     0,     0,     0,     0,
   -1972,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,     0,     0, -1972,  1257,
     172,     0,     0,     0,     0,   287,   194,     0,     0,     0,
       0,     0,   185,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0, -1972,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0, -1972,     0, -1972,  1498,  1498,  1498,  1498,  1498,  1498,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   488,   489,   490,   491,   492,   493,     0, -1972,   288,
       0,     0,     0,     0,   289, -1972,   290, -1972,     0,   494,
     495,   496,     0,     0,     0,     0,     0,   176, -1972,     0,
       0,     0,   291, -1972,     0,     0,     0,     0,     0,     0,
       0, -1972,   177,     0,     0, -1972,     0,   292,     0,     0,
     293, -1972,     0,   294,     0, -1972, -1972, -1972, -1972,     0,
       0,     0,   295,   179,     0,     0,     0,   471,   472,   473,
   -1972,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,     0,     0, -1972,     0,     0, -1972,
       0, -1972,     0,     0,     0,     0,     0,     0, -1972,     0,
       0,     0,   296,     0,     0,     0,   180,     0,     0,     0,
       0, -1972,     0,   487,   297,     0,     0,     0,     0,     0,
       0, -1972,     0,     0,     0,   298,     0,     0,     0,     0,
       0,   181,     0,  1257,     0,     0,     0,     0,     0,     0,
       0,     0, -1972, -1972,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0, -1972,   497,     0,
       0,   498,     0,     0,     0, -1972,     0,     0,     0, -1972,
       0,     0,     0,     0,     0,     0,     0, -1972, -1972, -1972,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,     0,   300,     0,   184,     0,
     488,   489,   490,   491,   492,   493,     0,     0,   301,   302,
       0,     0,     0,     0,     0,     0,   303,     0,   494,   495,
     496,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0, -1972,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1972,     0,     0,     0,     0,
       0,     0,   471,   472,   473,     0,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     0,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,   186, -1972,   500,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   702,   703,   704,   502,     0,     0,     0,     0,
       0,   705,     0,     0,   706,     0,     0,     0,     0,     0,
       0,   707,   708,     0,     0, -1972,     0,     0,     0,     0,
       0,     0,     0,   503,     0,     0,     0,   497,     0,     0,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1972,     0,     0,     0,     0,   709,   710,     0,     0,
       0,   711,     0,     0,     0,   488,   489,   490,   491,   492,
     493,   712,   713,     0,   714,     0,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   496,     0,     0,   715,     0,
       0,     0,     0,     0,     0,     0,     0, -1972,     0,     0,
       0,     0,     0,     0,     0,   716,     0,     0,   717,   718,
       0, -1972, -1972, -1972, -1972, -1972, -1972, -1972,     0, -1972,
   -1972,   505,   719,     0,   720,   721,   722,     0,     0,     0,
       0,     0,     0,     0,   723,   724, -1972,   725,   726,   727,
       0,     0,     0,     0,     0,   728,     0,     0,   729,   499,
     730,   731,   732,     0,     0,     0,     0,     0,   733,     0,
     734,   735,     0,   736,   500,   737,   738,     0,   501,   739,
       0,     0,   740,   741,   742,   743,   744,   745,     0,     0,
       0,   746,   747,   748,     0,   749,     0,   506,     0,   750,
       0,   751,   752,     0,     0,     0,     0,   753,     0,     0,
     754,     0,     0,   755,   502,   756,     0,   757,     0,   758,
       0,     0,     0,   759,   760,     0,   761,   762,   763,     0,
       0,   764,   497,   765,   766,   498,   767,     0,     0,     0,
       0,     0,   503,     0,   768,   769,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   770,     0,   504,
     771,   772,     0,     0,   773,   774,     0,     0,   775,   776,
       0,     0,     0,     0,     0,     0,   777,   778,   779,     0,
     780,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     781,   782,   783,     0,   784,     0,     0,     0,   785,   786,
       0,     0,     0,   787,     0,     0,     0,     0,     0,     0,
       0,   788,     0,     0,     0,     0,     0,     0,     0,   789,
     790,   791,     0,     0,     0,     0,     0,   792,   793,     0,
       0,     0,     0,     0,     0,   794,     0,     0,   795,     0,
     505,     0,   796,   797,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   798,   499,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
     799,     0,     0,   501,   616,     0,     0,     0,   800,     0,
       0,     0,     0,     0,   801,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   802,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,   803,     0,   502,
       0,     0,     0,   804,     0,   805,   806,     0,     0,     0,
       0,     0,     0,   807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,   808,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   809,     0,     0,     0,     0,     0,     0,
     810,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   811,   812,     0,     0,     0,   813,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     814,     0,     0,     0,     0,     0,   815,   816,   817,   818,
       0,     0,     0,   819,     0,   505,     0,   820,     0,     0,
       0,     0,     0,     0,   821,   822,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   823,     0,   824,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   825,     0,
     826,     0,     0,   827,     0,     0,   471,   472,   473,   828,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,   829,     0,     0,   830,     0,
       0,     0,     0,   831,     0,     0,   832,   833,     0,     0,
       0,     0,   487,     0,     0,     0,     0,     0,     0,     0,
       0,   834,     0,     0,     0,   471,   472,   473,   835,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   836,   837,   838,   839,   840,   841,   842,     0,     0,
     843,     0,   844,     0,   845,     0,     0,     0,     0,     0,
       0,   487,   471,   472,   473,     0,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
     489,   490,   491,   492,   493,     0,     0,     0,   487,     0,
       0,     0,     0,     0,     0,     0,     0,   494,   495,   496,
       0,   471,   472,   473,     0,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,   489,
     490,   491,   492,   493,     0,     0,     0,   487,     0,     0,
       0,     0,     0,     0,     0,     0,   494,   495,   496,     0,
     471,   472,   473,     0,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     0,     0,     0,
       0,     0,     0,     0,     0,   488,   489,   490,   491,   492,
     493,     0,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,   494,   495,   496,   487,   471,   472,   473,
       0,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,     0,   497,     0,     0,   498,
       0,     0,     0,     0,   488,   489,   490,   491,   492,   493,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,   494,   495,   496,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   498,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,     0,     0,   488,   489,
     490,   491,   492,   493,     0,     0,     0,     0,     0,     0,
       0,     0,   497,     0,     0,   498,   494,   495,   496,     0,
     488,   489,   490,   491,   492,   493,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   495,
     496,     0,     0,   500,     0,     0,     0,   501,   626,     0,
       0,     0,     0,   471,   472,   473,     0,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
       0,   497,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,   502,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,   500,     0,     0,     0,   501,   998,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   504,     0,
     497,     0,     0,   498,   499,     0,     0,     0,     0,     0,
       0,     0,   502,     0,     0,     0,     0,     0,     0,   500,
       0,     0,     0,   501,  1004,   497,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,   497,     0,     0,
     498,     0,     0,     0,     0,     0,     0,   504,     0,   502,
       0,     0,     0,   499,     0,     0,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,   500,   505,
       0,     0,   501,  1005,   494,   495,   496,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   502,   471,
     472,   473,   499,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,   500,   505,     0,
       0,   501,  1006,     0,     0,   506,   503,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,   504,     0,   487,   501,     0,     0,   499,
       0,     0,     0,     0,     0,     0,     0,   502,     0,     0,
       0,     0,     0,     0,   500,   505,     0,     0,   501,  1007,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   502,     0,   506,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,   497,   502,     0,   498,   471,   472,   473,
     503,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   505,     0,     0,   504,     0,     0,
       0,   506,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,   489,   490,   491,   492,   493,     0,   504,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
     494,   495,   496,     0,     0,     0,     0,   472,   473,     0,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   505,     0,     0,     0,     0,     0,   473,
     506,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,     0,     0,     0,     0,   505,     0,
       0,     0,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,     0,     0,
     505,     0,     0,   487,     0,     0,     0,     0,     0,     0,
     500,     0,     0,     0,   501,     0,     0,     0,     0,   506,
     488,   489,   490,   491,   492,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   495,
     496,     0,     0,     0,   506,     0,     0,     0,     0,     0,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1009,     0,     0,   506,     0,     0,   497,
       0,     0,   498,     0,     0,     0,     0,     0,   503,   488,
     489,   490,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,   494,   495,   496,
     488,   489,   490,   491,   492,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   495,
     496,     0,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   505,   497,     0,     0,
     498,     0,     0,     0,     0,   487,     0,     0,     0,     0,
       0,   499,     0,     0,     0,     0,   479,   480,   481,   482,
     483,   484,   485,   486,     0,     0,   500,     0,  2419,     0,
     501,     0,     0,     0,     0,     0,     0,  1318,  1319,  1320,
       0,     0,     0,   283,  1321,  1322,    39,     0,     0,     0,
       0,     0,     0,   487,     0,     0,   497,  1323,  1324,   498,
       0,     0,   506,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   497,     0,  1010,
     498,   488,   489,   490,   491,   492,   493,     0,     0,     0,
       0,     0,     0,     0,   503,     0,     0,     0,     0,   494,
     495,   496,   488,   489,   490,   491,   492,   493,     0,     0,
       0,   504,     0,     0,     0,  2419,     0,     0,     0,   499,
     494,   495,   496,     0,  1318,  1319,  1320,     0,     0,     0,
     283,  1321,  1322,    39,   500,     0,     0,     0,   501,     0,
       0,  1325,     0,     0,  1323,  1324,     0,     0,     0,     0,
     488,   489,   490,   491,   492,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   495,
     496,     0,     0,     0,   502,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,  1013,     0,     0,
       0,     0,   505,   500,     0,     0,     0,   501,     0,   499,
       0,     0,   503,     0,   481,   482,   483,   484,   485,   486,
       0,     0,     0,     0,   500,     0,     0,     0,   501,   504,
       0,     0,     0,  1318,  1319,  1320,     0,     0,  1325,   283,
    1321,  1322,    39,   502,     0,     0,     0,     0,   497,   487,
       0,   498,     0,  1323,  1324,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   502,     0,     0,     0,   506,   497,
       0,   503,   498,     0,     0,     0,  1141,     0,     0,     0,
       0,     0,   482,   483,   484,   485,   486,     0,   504,     0,
       0,     0,   503,     0,  1318,  1319,  1320,     0,     0,     0,
     283,  1321,  1322,    39,     0,     0,     0,     0,     0,   504,
     505,     0,     0,     0,  1323,  1324,   487,   497,     0,     0,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1325,     0,     0,
       0,     0,     0,     0,     0,     0,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1141,   494,   495,   496,     0,     0,   505,
     499,     0,     0,     0,     0,     0,   506,     0,     0,  2420,
       0,     0,     0,     0,     0,   500,     0,     0,     0,   501,
     505,   499,     0,     0,     0,     0,     0,     0,  1325,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
     501,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,   502,     0,     0,     0,     0,
       0,   494,   495,   496,     0,   506,     0,     0,     0,   499,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,   503,   500,     0,   506,     0,   501,  1008,
       0,     0,  1141,     0,     0,     0,  2420,     0,     0,     0,
     504,     0,     0,     0,   503,     0,     0,     0,     0,     0,
    1326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   504,     0,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,     0,   498,     0,     0,     0,
       0,  1327,     0,     0,  2421,     0,     0,     0,     0,     0,
       0,     0,   503,  1141,     0,     0,  2422,  1329,     0,     0,
       0,     0,     0,   283,  1321,  1322,    39,     0,     0,   504,
       0,     0,     0,     0,     0,     0,     0,  1323,  1324,     0,
       0,   505,     0,     0,  1722,  1318,  1319,  1320,     0,     0,
       0,   283,  1321,  1322,    39,  2420,  1330,  1326,     0,     0,
     497,     0,   505,   498,     0,  1323,  1324,     0,  1331,     0,
       0,     0,     0,  1318,  1319,  1320,     0,     0,     0,   283,
    1321,  1322,    39,     0,     0,     0,     0,     0,  1327,     0,
       0,  2421,     0,  1323,  1324,     0,     0,     0,   581,     0,
       0,     0,     0,  2422,  1329,     0,     0,   506,     0,  1332,
     505,     0,     0,     0,     0,   499,     0,     0,  1318,  1319,
    1320,  2934,     0,     0,   283,  1321,  1322,    39,   506,     0,
     500,     0,     0,     0,   501,     0,     0,     0,  1323,  1324,
       0,     0,  1333,  1330,     0,  1318,  1319,  1320,  1334,  1325,
       0,   283,  1321,  1322,    39,  1331,  1326,  1335,  1336,     0,
    1337,     0,     0,     0,     0,  1323,  1324,     0,     0,     0,
     502,     0,  1338,  1339,     0,     0,   506,  1325,     0,     0,
    1340,     0,   499,  1341,     0,     0,     0,  1327,     0,     0,
    2421,   304,     0,     0,     0,     0,  1332,   500,   503,     0,
       0,   501,  2422,  1329,     0,  2932,  2933,     0,     0,     0,
       0,   283,  1321,  1322,    39,   504,     0,  1326,     0,     0,
       0,     0,  1325,     0,     0,  1323,  1324,     0,     0,  1333,
       0,     0,     0,     0,     0,  1334,     0,   502,     0,     0,
       0,     0,  1330,     0,  1335,  1336,  1141,  1337,  1327,  1325,
       0,  1328,     0,     0,  1331,     0,     0,     0,     0,  1338,
    1339,     0,     0,     0,  1329,   503,     0,  1340,     0,     0,
    1341,     0,     0,     0,  1141,     0,     0,     0,   304,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
       0,  1722,     0,     0,     0,  1332,   505,     0,     0,     0,
       0,     0,  1141,  1330,     0,     0,     0,     0,     0,  2934,
       0,     0,  2932,  2933,     0,  1331,     0,     0,   283,  1321,
    1322,    39,     0,     0,     0,     0,     0,     0,  1333,     0,
       0,     0,  1323,  1324,  1334,     0,     0,     0,     0,     0,
       0,     0,     0,  1335,  1336,     0,  1337,  1141,     0,     0,
       0,     0,     0,     0,     0,     0,  1332,     0,  1338,  1339,
       0,     0,   506,   505,     0,     0,  1340,     0,     0,  1341,
       0,     0,     0,     0,  1141,     0,     0,   304,     0,     0,
    1320,     0,     0,     0,   283,  1321,  1322,    39,     0,  1333,
       0,     0,     0,     0,     0,  1334,     0,     0,  1323,  1324,
       0,     0,     0,     0,  1335,  1336,     0,  1337,     0,     0,
     138,     0,     0,     0,     0,     0,  2934,     0,     0,  1338,
    1339,     0,     0,     0,     0,     0,     0,  1340,     0,   506,
    1341,     0,     0,     0,  1141,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
    1326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1326,     0,
       0,  2935,  1325,     0,  2936,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2937,     0,     0,
       0,     0,     0,     0,     0,     0,  1326,   142,     0,  1327,
       0,     0,  1328,     0,     0,     0,     0,     0,     0,   143,
       0,   206,     0,     0,     0,  1329,     0,     0,     0,     0,
     144,     0,     0,   207,     0,     0,  2939,  1327,     0,     0,
    1328,  1141,     0,     0,     0,     0,   145,     0,  2940,     0,
       0,  1326,     0,  1329,     0,     0,   146,     0,     0,     0,
       0,     0,     0,  2255,  1330,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,  1331,     0,  2052,     0,
       0,     0,  1327,     0,     0,  1328,     0,     0,     0,  2941,
       0,  3379,  1330,     0,     0,     0,     0,     0,  1329,     0,
       0,     0,     0,     0,  1331,     0,     0,  1141,     0,  1327,
     208,   148,  1328,     0,     0,     0,     0,  1332,     0,     0,
       0,     0,     0,     0,     0,  1329,   209,   210,  2942,     0,
       0,     0,     0,   149,     0,     0,   211,  1330,  1326,     0,
    2943,     0,     0,     0,     0,  1332,     0,     0,   150,  1331,
    1333,     0,  2944,  2945,     0,   151,  1334,     0,   152,     0,
    2946,     0,     0,  2947,  1330,  1335,  1336,     0,  1337,  2935,
       0,   304,  2936,     0,     0,     0,  1331,     0,  1333,   153,
    1338,  1339,     0,   154,  1334,  2937,     0,     0,  1340,     0,
    1332,  1341,     0,  1335,  1336,     0,  1337,     0,     0,   304,
       0,     0,   155,     0,     0,     0,     0,     0,  1338,  1339,
       0,     0,  1722,     0,     0,     0,  1340,  1332,     0,  1341,
     156,     0,     0,  1333,  2939,     0,     0,   304,     0,  1334,
       0,     0,     0,     0,     0,     0,  2940,     0,  1335,  1336,
       0,  1337,     0,     0,     0,  1326,     0,     0,     0,     0,
    1333,     0,     0,  1338,  1339,     0,  1334,     0,     0,     0,
       0,  1340,     0,     0,  1341,  1335,  1336,     0,  1337,     0,
       0,     0,   304,     0,     0,     0,  2935,  2941,     0,  2936,
    1338,  1339,     0,     0,     0,     0,     0,     0,  1340,     0,
       0,  1341,  2937,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,   212,     0,     0,     0,
       0,  1326,     0,     0,     0,     0,  2942,     0,     0,  2287,
    2288,  2289,  2290,  2291,  2292,     0,     0,     0,  2943,     0,
       0,  2939,     0,     0,     0,     0,   138,     0,     0,     0,
    2944,  2945,  1327,  2940,   213,  1328,     0,     0,  2946,     0,
       0,  2947,     0,     0,     0,     0,     0,     0,  1329,   304,
       0,     0,     0,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,     0,
       0,   218,     0,     0,  2941,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,     0,     0,  1330,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,     0,  1331,
       0,     0,     0,     0,     0,   220,  2293,     0,     0,     0,
       0,     0,     0,  2942,     0,     0,   221,     0,     0,     0,
       0,     0,     0,   142,     0,  2943,     0,     0,     0,     0,
       0,     0,   222,     0,     0,   143,     0,  2944,  2945,     0,
    1332,     0,   223,     0,     0,  2946,   144,     0,  2947,     0,
       0,     0,     0,     0,     0,     0,   304,   224,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,  1333,     0,     0,     0,     0,     0,  1334,
       0,     0,     0,     0,     0,     0,     0,   147,  1335,  1336,
       0,  1337,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,  1338,  1339,     0,     0,     0,     0,     0,
    3349,  1340,     0,     0,  1341,     0,     0,     0,     0,   226,
       0,     0,   304,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,   227,     0,     0,     0,     0,     0,
       0,   228,     0,     0,   229,     0,     0,     0,     0,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   230,     0,  3350,     0,   231,
       0,   151,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   232,     0,
       0,  3351,     0,     0,     0,   153,     0,     0,     0,   154,
    3352,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,     0,  3353,     0,
       0,  2294,     0,     0,     0,     0,  3354,     0,   234,     0,
       0,     0,     0,     0,  2295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2296,     0,     0,     0,
       0,     0,  2297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2300,  2301,     0,     0,     0,     0,
    2302,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2304,     0,     0,  2305,  2306,     0,     0,     0,
    2307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2308,     0,     0,
       0,     0,     0,     0,     0,     0,  3356,     0,  2309
};

static const short yycheck[] =
{
       3,     4,     5,     6,   178,   197,     9,    10,   404,    53,
     112,  1078,   270,   271,   673,  1156,  1491,  1193,  1153,  1167,
    1168,  1198,  1170,   133,  1172,  1173,  1021,   603,   656,  1024,
     606,    62,  1406,   815,  2050,   558,  1658,   799,  2398,   268,
     269,  1399,   584,   614,    47,  2102,   275,  1318,  1319,  1171,
       5,  2104,   254,  1792,    98,  2242,   180,    60,  1783,    62,
    1622,  1623,    27,  2641,  2642,  2643,   774,  2087,    20,  2089,
      73,  1731,  1732,  1733,  1734,    27,   178,    80,  1152,     5,
    1789,    27,    85,  1724,    25,    88,    27,    27,     5,    92,
      93,  1844,  1971,    27,  1353,   197,  1355,    48,    20,  2286,
    1722,     5,     5,    25,    19,    27,    27,   735,   111,    24,
      25,    26,    19,   738,  1249,    26,    27,    24,   746,    26,
     118,  2173,     5,     8,   127,  2361,    77,   130,  1263,   132,
     240,   711,    27,    27,   137,   245,   246,    19,     5,  2644,
      36,  1282,     5,  2413,    26,  2415,   148,    24,   272,    26,
       5,    25,   276,    27,   278,   329,   280,   281,   282,    25,
      26,    27,   157,   743,   744,   289,    27,   120,   119,   293,
     294,    27,   123,   801,    19,    51,   804,    19,    30,    24,
      25,    26,    34,     5,    26,   813,  1253,     5,    20,    53,
      25,    43,    27,    25,     9,    27,   199,    12,    13,    14,
      15,    16,    17,     5,    27,     5,     5,   739,    27,   126,
     835,   128,    25,   130,    27,   795,    24,    25,    26,    27,
    1431,  2727,     5,    24,    25,    26,    27,   329,    24,    25,
      26,   763,   334,     5,    98,   139,   140,    24,    25,    26,
      27,     5,    33,     5,    25,   248,    27,   207,  1983,   817,
       5,     5,   220,    24,    25,    26,    27,   260,    24,    25,
      26,    27,   194,   266,   267,   268,   269,   270,   271,   145,
     146,     5,   275,     5,    33,     5,    25,   809,    27,    23,
    1449,   133,    27,   234,     6,     5,    23,   819,     6,    66,
     822,     5,  1178,  1179,   826,     5,  1937,   200,  2328,    25,
     832,    27,   834,   397,   118,    40,    41,  2025,     9,   207,
    2028,    12,    13,    14,    15,    16,    17,   330,   402,   322,
     323,   397,   446,    23,   293,   449,   448,   446,   331,   485,
     333,   120,  2348,   599,   292,     5,   247,   529,    27,   448,
     513,  2282,   466,   467,   468,   469,     5,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   593,   567,   143,   144,  2421,   709,
     710,     5,  1446,   247,   498,   499,   591,     5,  1554,   503,
       5,   505,    27,     5,   675,   614,     6,     5,     5,     5,
    1152,   195,   196,   220,   518,   519,   520,   521,     5,     5,
       5,   718,   526,   979,   670,     5,   416,   747,   448,     0,
     750,   362,    25,  1771,    27,   805,     5,    36,  1792,  2079,
     760,   595,  2175,  1490,   764,   640,   424,   529,   768,   103,
     104,   105,   106,   107,   247,   775,   448,   591,   729,   247,
     780,   293,   782,     5,   305,   220,   247,   330,   788,     5,
      25,   791,    27,   485,   591,   246,   247,    25,   798,    27,
     411,   412,   413,  1938,   513,   805,   247,   784,   480,    30,
     461,     5,   812,    34,    13,    19,   247,     5,   208,   513,
     672,   247,    26,   823,     5,   220,   640,   827,   247,   231,
       5,   831,   996,   595,     5,  1075,    31,   837,   432,   672,
     840,     5,   247,   640,   351,     5,     5,     5,    27,     5,
       5,     5,   330,   407,   517,   559,   560,  1097,     5,   529,
     642,   247,   678,   492,   301,    64,     5,    18,    19,    20,
      21,    22,     5,   642,    26,     5,     5,   631,     5,     5,
       5,   112,   113,     5,     5,     5,   407,   291,     8,   552,
     111,   554,   810,   811,   291,   631,   629,   118,  1090,   562,
       5,   413,   520,   792,   648,     5,   448,     5,     5,     5,
     672,   142,   143,   144,   208,   402,   579,     5,   581,     5,
      29,   839,  3088,     5,   842,   327,  2616,  2617,   407,   592,
     593,   291,   711,   596,     5,  2330,   669,   548,  2614,     5,
     558,     5,   642,   164,   165,    28,    29,     5,   621,   461,
     424,   614,     5,   428,   429,     5,  2178,     5,   481,   579,
       5,     5,   562,   672,   446,   339,   481,   402,   638,   339,
      27,   525,  2573,   448,   247,   567,  1204,   484,   672,    25,
     492,    27,   595,   554,    30,   613,   678,     5,  2366,  1217,
     451,   525,  1821,   648,  1823,   451,  1867,  2677,  1544,    27,
    3170,   517,   485,  2716,   525,   448,  1198,   402,   483,   521,
     441,  3181,   247,  3178,    10,   419,  1208,    28,  1210,  2866,
     614,   579,   419,  1206,  1446,   451,   448,   491,   592,   691,
     692,   693,   694,   695,  2930,   559,   607,  2319,  2885,   702,
     703,   704,   705,   706,   707,   708,   495,   664,   711,   712,
     713,   431,   411,   716,   448,   718,   448,   481,   721,  2989,
     723,   606,    22,   669,   525,  2782,   448,   428,   429,   732,
     448,  2610,   730,  1309,  1393,  2971,  1312,  1313,   621,   606,
     743,   744,   664,  2468,   670,  1453,   642,   642,   669,  2488,
     753,  1873,    52,   670,   719,  2812,   759,   672,  1300,   714,
     642,   678,   765,   766,   767,   672,   669,   719,   771,   540,
    2790,   774,  2792,   776,   777,   679,  2150,  2486,   719,   719,
    2154,   784,   483,  3143,   787,   719,  1860,  2839,  1923,   792,
     793,  2843,   795,  2052,   609,   672,   799,  3157,   664,   802,
     642,   603,   678,   621,   603,   808,   595,   810,   811,   609,
     721,   481,   815,   816,   817,   606,  1156,  3395,   821,   568,
     448,   824,   481,   895,  1328,   638,   829,   672,   448,   664,
     448,   448,   664,   836,   423,   838,   839,   609,   841,   842,
     485,   844,   845,   448,   599,   599,  1426,   606,   629,   149,
     150,   151,   152,   153,   154,  1435,   481,  2116,  2117,   481,
     675,   247,   597,   424,   672,   481,   485,   167,   168,   169,
    2011,   672,   485,    27,   481,   481,   672,   603,   299,   731,
     399,   481,  1462,   448,  1452,   672,   448,  1011,   407,   408,
    1014,  1281,   448,   512,   513,   630,  1464,  1021,   675,  1023,
    1024,   672,    20,  1299,   448,   302,   672,   293,   609,    27,
     725,   726,  1907,   432,   448,   672,   435,   485,   315,   508,
     448,   122,  1454,  1455,  1456,   709,   710,   448,   416,  3289,
     714,   715,   451,   448,   302,   524,    27,   448,   509,  1471,
    1280,  1281,  1282,   727,   448,   948,   123,   315,   448,   448,
     448,  3138,   448,   448,   448,   574,   448,    25,   519,    27,
    2522,   448,   636,   747,  1592,  2985,   750,  2987,  2988,   448,
     306,   215,   756,   389,   675,   448,   760,   566,   448,   448,
     764,   448,   448,   448,   768,   671,   448,   448,   772,   773,
     481,   775,   678,   996,   778,  3015,   780,   781,   782,  2640,
    2641,  2642,  2643,   448,   788,  1576,   306,   791,   448,   309,
     448,   448,   448,  1545,   798,    27,   605,   968,  3071,   416,
     448,   805,   448,   594,   725,   726,   448,   413,   812,  2098,
    2099,  2100,  1564,   391,  2103,   554,  1039,   448,  1041,   823,
    1563,   529,   448,   827,   448,   634,   642,   831,   416,   610,
     448,  1583,     5,   837,   643,   448,   840,   669,   448,    25,
     448,    27,  1594,   448,   448,  2956,   637,  1647,   664,  1649,
    1650,   315,  1075,  1653,  1654,  1078,   448,   642,  2705,  1659,
    2707,  1032,   411,  2710,   442,   397,  2996,     5,   607,  2999,
    2266,  1094,  3002,   247,  1097,   614,    27,  2166,  1860,    26,
      27,   513,  2460,  1175,  1306,   417,   492,   443,   352,   445,
     448,  1183,   513,   463,  2488,    26,    27,   485,    25,    25,
      27,    27,  1698,    26,    27,  1701,   338,   750,   428,   690,
    3183,  3147,   529,  1136,   448,   521,  2203,   698,  1141,   351,
    2399,   764,  2401,   443,  2403,   768,   485,   447,   545,  1152,
     638,   567,  2100,   330,   732,  2103,   247,   780,  1738,   232,
     382,   529,   578,  1166,  1167,  1168,   732,  1170,   551,  1172,
    1173,    24,   416,    26,   513,  1178,  1179,   545,    18,    19,
      20,    21,    22,   483,  1812,   338,   430,   753,    18,    19,
      20,    21,    22,  2334,    25,   642,    27,   485,   351,  1981,
     766,  1204,   554,    25,    25,    27,    27,  1465,    26,    27,
     562,   511,  1215,   221,  1217,   223,    25,   664,    27,  2360,
    1724,   485,  1726,  1226,   512,   402,  1229,   221,   528,   223,
     642,  1234,  1736,  1737,    25,   247,    27,    14,  1467,  1743,
    1744,  1745,  1746,   444,   352,    25,    25,    27,    27,   513,
    1253,  1254,   664,   575,   248,   642,   364,    26,    27,  1262,
     672,    26,    27,  2332,   512,   513,   467,  3158,  3159,   446,
     642,  1896,   484,  2342,     0,  1278,  1279,   664,   351,  1859,
     221,   247,   223,  1815,   357,   529,  1396,   441,  1398,   485,
     823,  2932,  2933,   305,   827,  2936,    22,  2919,   831,  1831,
    3210,   545,  1305,   653,   642,  1479,   656,   248,   691,   609,
     302,   677,   534,  1571,  1572,  1318,  1319,    20,   326,   631,
     247,   329,  3342,   315,    27,  1328,  1858,    25,   642,    27,
      27,   484,   326,  1865,   700,   329,   247,  1905,  1341,   375,
     247,   247,   677,   351,   247,    42,  1349,  1576,   549,   838,
     441,  1333,   841,  1335,  1336,   844,  2997,   351,   485,  3000,
     382,  1619,  1620,  1895,   699,   700,  1889,   513,  2437,  2504,
     485,   302,  1156,    18,    19,   675,  3003,  1479,   302,    24,
      25,    26,    27,  1915,   315,   326,   485,  2862,   329,    20,
    1421,   315,    20,    38,    39,   485,    27,  1400,   480,    27,
    3288,  1404,  1405,  1406,  3292,  2582,    24,  1975,    26,  1989,
     351,  2546,    26,  1416,  1417,  1418,   247,   513,  1421,  1422,
    1423,  1424,  1425,  1426,   416,   247,   247,  2549,  1932,   247,
    2606,   485,  1435,  2704,  2705,    20,  2707,  2483,   247,  2710,
     641,   485,    27,  1446,   621,  1448,   485,  1450,  2822,  1452,
    1453,   485,   653,   654,   485,   677,   247,  1460,  1461,  1462,
     661,  1464,  1465,  2039,  1467,  1468,   163,   247,   247,  2045,
    2046,  2540,   525,  1476,   696,   697,   484,   122,   247,   532,
    1483,  1484,   247,   485,    25,   416,    27,  1490,  1491,  2069,
     484,   677,   416,   485,   716,  2970,  1280,  1281,  1282,   692,
     693,    20,  3162,    20,  3164,  3165,  3166,  3167,    27,  1849,
      27,   485,   534,   699,   700,   212,   485,   263,   264,   265,
    3161,   485,  3163,  2151,   701,   702,   703,   485,  3169,  3170,
     485,  3172,  3173,  3174,  3175,   712,   485,   529,  1541,  1542,
    3181,  1544,   485,   484,  1547,  1548,  2050,  3276,  3277,  3278,
     247,   485,   249,   545,   485,  2059,   485,  2626,  2062,  2063,
    2064,  2065,  2557,   295,   159,   160,  1569,    20,  1571,  1572,
    2565,  2566,  2567,  1576,    27,  1578,  2204,  1580,  1581,  1582,
    1690,   423,    25,   295,    27,  2165,    30,  2155,   534,   295,
      34,  2159,   485,  3346,  2640,  2641,  2642,  2643,   529,    43,
    2168,   485,   247,  1606,    25,   529,    27,    24,  1866,    26,
    3363,    24,  2144,    26,   545,  1618,  1619,  1620,   448,   351,
     485,   545,  1625,  1626,   485,  2193,  2254,   485,  2160,  2161,
    2162,  2163,    25,  1757,    27,  3364,   485,  3366,  1978,   351,
      25,   481,    27,  1646,  1647,   351,  1649,  1650,   345,  2181,
    1653,  1654,   493,  1656,  3295,   677,  1659,  3298,  3299,  3300,
    3301,   691,  3415,   504,   694,   695,   508,  3142,   485,   485,
      25,  2011,    27,   405,   696,   697,    24,   409,    26,  3432,
    1683,   485,   524,  3324,   525,   665,   666,   667,   668,   133,
     531,  1694,   485,   405,   716,   512,   513,   409,   539,   405,
     485,  1176,  1177,   409,   782,  1180,  1181,    26,  2777,   455,
    2779,   485,  1970,   791,    40,    41,  2248,   414,    40,    41,
     561,  1724,   485,  1726,   566,   422,  1955,  1956,    24,   426,
      26,   677,  3003,  1736,  1737,  1738,   715,  2317,  1741,    26,
    1743,  1744,  1745,  1746,    25,  3386,    27,    25,   727,    27,
     696,   697,   484,  1756,  3395,   678,   393,   574,    24,   837,
      26,   678,   840,   605,  1888,   462,  2346,   404,   512,   513,
     716,    24,   484,    26,    25,  1778,    27,   756,   484,    26,
    1783,    26,  2362,  1907,    26,  1448,  1789,  1450,    26,  1792,
     694,   695,   634,   772,   773,   343,   344,    52,   672,   778,
     485,   643,   781,   579,  2871,  2381,   451,  1810,  2384,   485,
    2386,  2387,  1763,  1816,   722,   723,   724,   454,   485,  2351,
     485,  2353,   423,   485,    18,    19,    20,    21,   701,   702,
     527,   468,   485,  2413,   485,  2415,   485,   482,   701,   702,
     485,   485,  1845,    26,  2348,  2478,  2479,   423,  2917,   293,
     475,   217,   224,   498,   513,  2936,  1859,  1860,  2927,   485,
    1863,  1864,    26,  1866,    26,   998,   232,   233,  1001,   566,
    1003,  1004,  1005,  1006,  1007,   241,  2932,  2933,  1881,    26,
    2875,    18,    19,    20,    21,    22,  2932,  2933,    26,   672,
    2936,   536,   537,   590,   149,   150,   151,   152,   153,   154,
    1903,  2405,  1905,    26,   549,    26,    26,   508,   116,   275,
     448,   418,   167,   168,   169,   672,  3092,  2421,   284,   556,
      24,    25,    26,   524,  1927,  3101,  1929,  1930,  2432,  1932,
      26,   485,   508,  1936,  1937,  1938,   448,   634,   485,   481,
    2508,  3010,  3118,     5,   448,   590,   643,   313,   524,   485,
     448,  2997,  1955,  1956,  3000,   149,   150,   151,   152,   153,
     154,  2541,   167,   168,   169,   566,   448,  1970,   448,   413,
     448,    26,  1975,  1976,  1977,  2543,   448,   485,  1981,   525,
      20,    20,  2514,   678,   629,  2517,  1989,   448,  2328,   485,
     566,   357,   485,     5,  2334,   119,   641,   485,   485,   513,
      26,   676,   672,    26,   605,   423,   448,   448,   653,   654,
     315,   481,  2186,  2016,   418,    30,   661,   461,    20,   664,
    2360,  2024,  2025,    26,   448,  2028,    26,   672,   448,   605,
     727,   728,   199,   634,    26,   401,   203,    26,    48,    49,
      50,  3182,   643,    53,    26,    55,    56,  2050,   492,   642,
    2582,   306,    26,    26,   309,   642,  2059,    26,   634,  2062,
    2063,  2064,  2065,  2066,   436,  1849,  2069,   643,   448,   193,
    2073,  2074,   448,   448,  2077,    26,     5,   521,   450,  2583,
     448,  3150,  3163,   423,  2186,    20,    26,   485,  3169,  3265,
     508,  3172,  3173,  3174,  3175,  2098,  2099,  2100,    26,    26,
    2103,  2104,  2105,    26,   672,  2108,   524,  2732,  2733,  2734,
    2614,  2736,  2737,  2738,  2739,  2740,  2741,  3163,   448,     5,
    2745,   493,   678,  3169,  3170,   448,  3172,  3173,  3174,  3175,
      26,   255,   504,   257,  2137,  3181,  2139,  2140,   448,  2142,
    2143,   358,   448,  2146,   448,   448,   448,  2150,   566,   273,
     676,  2154,  2155,   525,  3200,     5,  2159,   281,   448,   531,
     448,   285,  2165,  2166,   485,  2168,  2169,   539,   508,  2172,
    2173,    26,   678,   428,  3243,   448,   642,    26,   678,   448,
      25,    25,    25,   448,   524,    25,   310,   605,   443,   561,
    2193,   448,   447,   358,  1978,   193,   448,  2200,   448,  3375,
    2203,  3349,  3350,  3351,  3352,  3353,  3354,  3274,  2712,  2212,
     423,   448,   448,  2216,  3295,   448,   634,  3298,  3299,  3300,
    3301,   448,   448,  2803,   448,   643,   566,  2011,   483,   448,
      48,    49,    50,   448,   672,    53,   676,    55,    56,  2242,
     672,   485,     8,    48,    49,    50,    20,    21,    53,  3295,
      55,    56,  3298,  3299,  3300,  3301,   511,   255,   677,   257,
     481,  2829,   532,   322,  2267,   605,   638,   648,   514,     5,
     670,   670,   644,   528,   648,   273,  2616,  2617,  3324,   475,
     514,   711,   711,   281,   672,   513,   384,   285,   672,  2857,
     649,   664,     5,   475,   634,   508,     5,   485,   296,   485,
     485,   485,   193,   643,   485,  3386,   631,   402,     8,    14,
     628,   524,   310,     5,  2317,   711,   326,     5,  2850,   329,
     711,   331,    18,    19,    20,    21,   475,   485,   485,  2332,
     123,    26,    47,    26,   148,  2379,   513,  2340,  2341,  2342,
    3386,   351,  2345,  2346,   672,  2348,    26,   642,   475,  3395,
     485,   361,   485,   566,   609,  2887,   485,  3016,  2361,  2362,
     485,   513,  2365,  2366,   255,  2539,   257,  2596,   485,  2598,
    3365,   485,   382,   485,   485,   149,   150,   151,   152,   153,
     154,    26,   273,     5,   648,    20,    21,     5,   485,  2581,
     281,   485,   605,   678,   285,   405,   111,   112,   485,   409,
      51,   485,  2405,  2979,   678,  2981,  2982,   714,   609,  2989,
    2413,   408,  2415,  2416,   677,    25,  2419,     5,  2421,   310,
     675,   634,    18,   210,    19,    25,   669,   448,  2552,  2432,
     643,  3498,   440,  2557,  2437,  2438,  2439,  2539,  2420,   642,
    2422,  2565,  2566,  2567,   675,   535,   535,  2450,   599,   672,
       5,   631,   208,   149,   150,   151,   152,   153,   154,   599,
      26,   455,   379,   178,    26,  2468,    26,   599,    25,   448,
     448,   448,   678,   448,   484,   525,   579,   672,   678,  2581,
     448,   448,   197,  2486,   485,  2488,   485,   115,     5,   485,
    1290,   716,   485,   672,   485,   448,   642,   672,  2501,   642,
     599,   485,  3006,   669,  3008,  2508,   678,     5,   326,     5,
       5,   329,     5,   331,   149,   150,   151,   152,   153,   154,
     536,   326,   632,   678,   329,   485,   331,  3095,   672,   677,
    2533,     5,  2535,   351,  2537,     8,    26,  2540,  2541,    26,
    2543,   375,   123,   361,  2328,  3113,   351,   275,   383,     5,
    2334,   266,     5,   448,   485,  2558,   361,  2560,  2561,  2562,
     485,   485,   678,   417,   382,  3097,   649,    14,   603,   599,
     737,   738,     5,  2576,    26,   157,  2360,   382,   712,   485,
    2583,   672,  2978,   485,     5,   678,   599,   405,   481,  2847,
     678,   409,   677,  2596,     5,  2598,   677,   448,     5,   691,
     405,  3133,  2860,     5,   409,  2608,  2609,   322,   323,   448,
     448,  2614,   425,   671,   329,   481,   389,    26,   515,   334,
     485,   515,   485,  2626,   234,   485,   485,   485,   485,   485,
       5,   672,   485,     5,   672,     8,   513,  2640,  2641,  2642,
    2643,  2644,  2645,  3147,   672,     5,   629,   606,   383,    25,
     402,  2654,   402,   672,   402,   485,  2659,  3161,  2640,  2641,
    2642,  2643,   417,   480,     5,   513,   484,  2841,   835,     5,
     703,   513,    26,  2640,  2641,  2642,  2643,   234,   845,   484,
       5,     5,    25,    14,    14,   648,    26,   648,  3256,   669,
     485,   606,  2695,  2696,   131,   132,     5,   134,   135,   136,
       5,  2704,  2705,    26,  2707,   485,   678,  2710,   448,  2712,
     448,   448,     6,  2716,   448,   448,     7,   502,   324,   448,
       5,   448,   672,    26,  2706,    26,  2708,    26,    26,   678,
      26,   672,   448,   672,    20,     5,   619,   330,     5,  2841,
       5,     5,     8,  3319,  3320,     5,   448,   599,   624,   720,
     360,  2875,   672,  2756,   448,   485,   366,   367,   368,   678,
     525,     5,   599,     5,   678,  2768,   268,   676,    26,   448,
     448,   448,     5,   678,  2777,  2778,  2779,   678,   388,   678,
       5,   485,   485,   501,    25,    25,   678,  3291,   676,    25,
     671,    25,   448,    25,   352,    26,   233,    26,    26,    26,
    2803,   448,   517,   360,   241,    26,    26,    26,     5,   366,
     367,   368,  2815,  2816,   529,   448,  2819,   448,   485,  2822,
       5,   522,   485,   448,  3328,   603,  2829,     8,  3360,   996,
     297,   388,  2616,  2617,    26,    25,  2839,   481,   275,  2842,
    2843,   448,  3182,   448,  2847,   495,   402,   284,    20,   199,
       5,   485,   606,   485,  2857,   485,   485,  2860,   485,  2862,
       5,   485,  3091,    14,   485,   268,     5,   513,  2871,   448,
     448,   448,    26,   496,    26,   485,   313,   314,   448,    26,
     595,  1681,  1682,   493,   448,    26,   496,   485,  1688,    26,
      26,   431,    26,   297,   504,   621,   448,   448,   448,   485,
     448,   402,   298,   495,   513,   485,   448,    14,  2911,   599,
     448,  1078,   448,     7,  2917,   296,   296,    26,   448,   678,
     357,   448,   485,  2926,  2927,   449,  2929,  2930,   538,  2932,
    2933,   672,  3464,  2936,   448,   448,   493,  3441,    26,   496,
     485,   628,   481,    25,  2947,   298,   513,   504,   448,   448,
    2932,  2933,     5,    26,  2936,    26,   448,   672,   672,   448,
     448,   672,   448,   573,   401,  2932,  2933,  2970,  2971,  2936,
       5,  2640,  2641,  2642,  2643,   481,   448,    26,   481,  2560,
    3425,   538,   592,   593,  2501,  2238,  2989,   702,   703,   704,
     672,   706,  1023,   603,  2997,  1584,  1916,  3000,   608,    35,
    3003,  2169,   691,  3006,    37,  3008,  2533,  3010,   723,  2175,
     362,   119,   123,   214,   353,   676,   573,  1762,   455,   363,
    1763,   219,   548,   617,  1317,   392,   391,   581,  3415,  1815,
     579,  3034,   821,  1014,   427,   592,   593,   647,  1287,  2022,
    2029,  2162,  1865,  1618,   759,  2585,   603,  2897,  1621,  1945,
     765,   608,   767,  2263,  3469,  2165,   771,  1467,  3109,   774,
    1965,    22,   777,    47,    98,    47,  2379,  1921,  3071,   679,
      28,   950,   787,  1595,  1626,  1927,  1041,   334,   777,  1542,
    1930,  1254,   802,  3219,  3034,  1540,  1253,   802,  3091,  3281,
     647,  1461,  3095,   808,  3432,  2771,  1450,  2583,  1898,  3229,
     815,   816,   817,  1895,  1564,  2769,   821,   465,  2754,  2449,
    3113,  2827,  3089,  3087,   829,  2819,  3080,  2154,  1795,    37,
    1778,  2108,   679,  2328,  3010,  3441,  1661,  1661,  2347,  2000,
     845,  2929,  2776,  2810,  2069,  3243,  2695,  1988,  2696,  3142,
    2419,  1941,  3000,  3324,  3147,  2798,  2471,  3150,  2450,  1646,
    3052,  1318,  1319,  2416,   624,     9,  3487,  1283,  3161,  2439,
    3163,  1328,  2438,  2931,  2627,  1737,  3169,  3170,  3008,  3172,
    3173,  3174,  3175,  1736,  3285,  3178,  1640,  3180,  3181,  3281,
    3183,  3163,  2341,  2926,  3180,  3161,  1613,  3169,  3170,  3169,
    3172,  3173,  3174,  3175,  2541,  1756,  3163,  1279,  1141,  3181,
    1476,  1484,  3169,  3170,  2186,  3172,  3173,  3174,  3175,  2539,
    1466,   557,    -1,    -1,  3181,    -1,  3219,    -1,    -1,    -1,
      -1,  3224,    -1,  3226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3243,  3365,    -1,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,  3256,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,  2932,  2933,    -1,    -1,  2936,    -1,    -1,
      -1,  3274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3285,    -1,    -1,    -1,    -1,    -1,  3291,    -1,
      -1,    -1,  3295,  3077,    -1,  3298,  3299,  3300,  3301,    -1,
    3303,    -1,    -1,  3087,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3295,  3317,    -1,  3298,  3299,  3300,  3301,
      -1,  3324,    -1,  1490,    -1,  3328,    -1,    -1,  3295,    -1,
      -1,  3298,  3299,  3300,  3301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3349,  3350,  3351,  3352,
    3353,  3354,    -1,    -1,    -1,    -1,    -1,    -1,  3361,    -1,
     278,    -1,    -1,  1078,    -1,    -1,    -1,    -1,   286,    -1,
      -1,    -1,    -1,    -1,   292,    -1,   294,    -1,    -1,  1094,
      -1,    -1,    -1,  3386,    -1,    -1,    -1,   305,    -1,    -1,
      -1,    -1,  3395,    -1,    -1,    -1,    -1,    -1,  3182,    -1,
      -1,    -1,    -1,    -1,  3386,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3395,   332,    -1,    -1,    -1,    -1,  3386,
      -1,  1136,    -1,    -1,    -1,    -1,    -1,    -1,  3395,    -1,
     348,    -1,  2232,  2233,    -1,   353,    -1,    -1,  3441,    -1,
    3443,    -1,    -1,  2243,    -1,    -1,    -1,   365,    -1,    -1,
      -1,  1166,  1167,  1168,   372,  1170,    -1,  1172,  1173,  1626,
      -1,    -1,    -1,  1178,  1179,    -1,    -1,    -1,  2268,  2269,
    2270,  2271,  2272,  2273,    -1,    -1,    -1,    -1,  2278,  2279,
    2280,  2281,  3485,  3486,  3487,  2285,    -1,    -1,    -1,  1204,
      -1,    -1,    -1,    -1,  3163,  3498,    -1,  3500,    -1,    -1,
    3169,  3170,  1217,  3172,  3173,  3174,  3175,    -1,    -1,    -1,
      -1,    -1,  3181,    -1,  1229,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,  1253,  1254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,  1726,
      -1,    -1,    52,  1278,  1279,    -1,    -1,  2367,  2368,  1736,
    1737,    -1,    -1,     9,  2374,  2375,  1743,  1744,  1745,  1746,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   520,    -1,    -1,    -1,    42,   525,    -1,    -1,
      -1,    -1,    -1,   531,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,  3295,    -1,    -1,  3298,
    3299,  3300,  3301,    -1,    -1,   553,    -1,    -1,    42,    -1,
     558,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
      -1,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,  3386,    -1,    -1,
     156,    -1,    -1,  2523,  2524,   129,  3395,    -1,    -1,  1896,
      -1,    -1,  2532,  1448,    -1,  1450,    -1,  1452,  1453,    -1,
      -1,    -1,    -1,    -1,   155,  1460,  1461,    -1,    -1,  1464,
      -1,    -1,   156,  1468,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1479,  1932,    -1,    -1,    -1,    -1,
    2570,  2571,    -1,    -1,    -1,  1490,  1491,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2597,    -1,  2599,
      -1,    -1,    -1,    -1,    -1,     9,    67,    68,    69,    70,
      -1,   247,    -1,   249,    18,    19,   306,    -1,    -1,   309,
      24,    25,    26,    27,    -1,    -1,  1541,  1542,    -1,  1544,
      -1,    -1,  1547,  1548,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,   247,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2660,  2661,    -1,  1578,  2664,  2665,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2050,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1606,  2059,    -1,    -1,  2062,  2063,  2064,  2065,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2074,    -1,   345,
    1625,  1626,    -1,   117,   350,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,  2104,   428,    -1,
      -1,   345,    -1,    -1,   380,   206,    -1,    -1,   209,    -1,
      -1,    -1,   156,   443,    -1,    -1,    -1,   447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1683,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,   414,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   252,   403,   483,   121,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,
     414,    -1,    -1,   449,    -1,   451,    -1,    -1,    -1,    -1,
      -1,   511,   426,    -1,    -1,    -1,   462,    -1,    -1,    -1,
      -1,   467,    -1,    -1,    -1,    -1,  2203,    -1,   528,    -1,
    2840,   477,    -1,   247,  2844,   249,   482,    -1,    -1,   485,
      -1,    -1,   488,    -1,   465,   316,    -1,    -1,   462,    -1,
     471,   497,   498,  2863,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   477,    -1,    -1,    -1,    -1,    -1,   340,
      -1,   485,    -1,  2883,    -1,    -1,   347,    -1,   349,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,   359,   510,
     536,   537,    -1,    -1,    -1,   541,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,   609,
      -1,    -1,   533,    -1,   560,    -1,   387,    -1,    -1,    -1,
     566,    -1,   543,   544,   395,    -1,    -1,   541,   549,    -1,
      -1,   345,    -1,    -1,    -1,    -1,   350,    -1,   559,    -1,
      -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   566,    -1,    -1,    -1,  1881,    -1,    -1,    -1,
     581,   432,    -1,   584,   585,    -1,   380,    -1,   589,    -1,
      -1,  2348,    -1,    -1,    -1,   675,   590,    -1,    -1,    -1,
    1905,    -1,    -1,    -1,    -1,   456,    -1,    -1,   634,    -1,
      -1,    -1,    -1,    -1,    -1,   641,    -1,   643,    -1,    -1,
     414,    -1,  1927,    -1,    -1,    -1,    -1,   653,   654,    -1,
      -1,  1936,   426,  1938,    -1,   661,    -1,    -1,   355,    -1,
     634,    -1,   493,    -1,    -1,   646,   672,    -1,  2405,   643,
     444,    -1,    -1,   504,    -1,   449,   657,   451,   375,   376,
     377,    -1,  2419,    -1,  2421,    -1,    -1,    -1,   462,    -1,
    1975,  1976,  1977,   467,    -1,  2432,  1981,    -1,    -1,    -1,
      -1,    -1,    -1,   477,    -1,    -1,    -1,    -1,   482,    -1,
      -1,   485,    -1,    -1,   488,    -1,    -1,   414,    -1,    -1,
      -1,   727,   728,   497,   498,    -1,    -1,    -1,    -1,   426,
      -1,  2016,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     437,    -1,    -1,    -1,    -1,    -1,  2483,    -1,    -1,    -1,
      -1,    -1,    -1,   727,   728,    -1,   453,    -1,    -1,    -1,
      -1,  3131,   536,   537,  3134,    -1,   463,   541,    -1,    -1,
     601,   602,   603,    -1,    -1,   549,    -1,    -1,    -1,    -1,
      -1,   478,    -1,   614,    -1,    -1,   560,    -1,    -1,    -1,
      -1,    -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   659,   526,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2583,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,    -1,
     634,    -1,    -1,    -1,    -1,    -1,    -1,   641,   565,   643,
    2155,    -1,    -1,    -1,  2159,    -1,    -1,  2614,    -1,   653,
     654,    -1,    -1,  2168,    -1,    -1,   717,   661,    -1,   586,
      -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,   672,    -1,
      -1,  2186,   733,  2640,  2641,  2642,  2643,    -1,  2193,  3279,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2203,    -1,
      -1,   618,    -1,    -1,    -1,    -1,    -1,  2212,    -1,    -1,
     627,  2216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   727,   728,    -1,    -1,  2242,  2695,  2696,
    3330,  3331,    -1,  3333,    -1,  3335,  3336,  2704,  2705,    -1,
    2707,    -1,    -1,  2710,    -1,  2712,     6,     7,     8,  2716,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,  2732,  2733,  2734,    -1,  2736,
    2737,  2738,  2739,  2740,  2741,    -1,    -1,    -1,  2745,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3403,    -1,  3405,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,  3439,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
    2365,    -1,    -1,    42,    -1,    -1,    -1,    -1,  3458,  3459,
      -1,    -1,  3462,    -1,    -1,  3465,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2871,    -1,    52,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2438,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,    -1,    -1,  2932,  2933,   156,    -1,  2936,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,  2508,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,   167,   168,   169,  2539,    -1,    -1,    52,  2543,    -1,
    2997,    -1,    -1,  3000,    -1,    -1,  3003,    -1,    -1,  3006,
      -1,  3008,    -1,  2558,    -1,  2560,   306,  2562,    -1,   309,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,   247,    -1,
     249,  2576,    -1,    18,    19,    -1,  2581,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,  2608,  2609,    -1,    -1,    -1,    -1,   306,
      -1,    -1,   309,    -1,  3071,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,  2654,
      -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,    -1,
     306,   350,   117,   309,    -1,    -1,    -1,   122,   428,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
    3147,    -1,    -1,   443,    -1,    -1,    -1,   447,   448,    -1,
      -1,   380,    -1,    -1,  3161,    -1,  3163,    -1,    -1,    -1,
      -1,   156,  3169,  3170,    -1,  3172,  3173,  3174,  3175,    -1,
      -1,    -1,    -1,    -1,  3181,    -1,  3183,    -1,    -1,    -1,
      -1,   428,    -1,   483,    -1,   414,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3200,    -1,    -1,   443,   426,    -1,    -1,
     447,  2756,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   511,    -1,  2768,    -1,   444,    -1,    -1,    -1,    -1,
     449,    -1,   451,    -1,    -1,    -1,    -1,    -1,   528,    -1,
      -1,   306,    -1,   462,   309,    -1,   483,    -1,   467,    -1,
      -1,   306,   428,    -1,   309,    -1,    -1,    -1,   477,    -1,
      -1,    -1,   247,   482,   249,    -1,   485,   443,    -1,   488,
      -1,   447,    -1,    -1,   511,    -1,    -1,  3274,   497,   498,
      -1,    -1,    -1,    -1,  2829,    -1,    -1,    -1,    -1,    -1,
      -1,   528,    -1,    -1,  3291,    -1,  2841,    -1,  3295,    -1,
      -1,  3298,  3299,  3300,  3301,    -1,    -1,   483,    -1,    -1,
      -1,    -1,  2857,    -1,    -1,    -1,    -1,  2862,   537,   609,
      -1,    -1,   541,    -1,    -1,    -1,  2871,  3324,    -1,    -1,
     549,  3328,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,
      -1,   560,    -1,   562,    -1,    -1,    -1,   566,    -1,    -1,
      -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,    -1,    -1,   428,    -1,   350,    -1,    -1,    -1,    -1,
      -1,   590,   609,   428,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,   447,    -1,    -1,   675,    -1,    -1,   443,  3386,
      -1,    -1,   447,    -1,     9,   380,    -1,    -1,  3395,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,   634,    -1,    -1,   483,    -1,
      -1,    -1,   641,    -1,   643,  2970,    -1,    42,   483,   414,
      -1,    -1,    -1,   609,   653,   654,    -1,    -1,   675,    -1,
      -1,   426,   661,    -1,  3441,    -1,   511,    -1,    -1,    -1,
      -1,    -1,    -1,   672,    -1,    -1,   511,    -1,    -1,   444,
      -1,    -1,    -1,   528,   449,    -1,   451,    -1,    -1,    -1,
      -1,    -1,    -1,   528,    -1,    -1,    -1,   462,    -1,    -1,
      -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,  3034,
      -1,    -1,   477,    -1,    -1,    -1,    -1,   482,    -1,   675,
     485,  3498,   117,   488,    -1,    -1,    -1,   122,   727,   728,
      -1,    -1,   497,   498,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,
    3095,   536,   537,    -1,   609,    -1,   541,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,  3113,    -1,
      -1,    -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,
      -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3142,    -1,    -1,
      -1,    -1,    -1,    23,    -1,   590,    -1,    -1,    -1,    -1,
     675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,   247,    53,   249,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   634,
      -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,   643,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   653,   654,
      -1,    -1,    -1,    -1,  3219,    -1,   661,    -1,    -1,  3224,
      -1,  3226,    -1,    -1,    -1,    -1,    -1,   672,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,   148,  3274,
     345,    -1,    -1,    -1,    -1,   350,  3281,    -1,    -1,    -1,
      -1,    -1,   727,   728,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,
      -1,   221,    -1,   223,  3349,  3350,  3351,  3352,  3353,  3354,
      -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   248,   444,
      -1,    -1,    -1,    -1,   449,   255,   451,   257,    -1,   167,
     168,   169,    -1,    -1,    -1,    -1,    -1,   462,   268,    -1,
      -1,    -1,   467,   273,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   281,   477,    -1,    -1,   285,    -1,   482,    -1,    -1,
     485,   291,    -1,   488,    -1,   295,   296,   297,   298,    -1,
      -1,    -1,   497,   498,    -1,    -1,    -1,     6,     7,     8,
     310,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   326,    -1,    -1,   329,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
      -1,    -1,   537,    -1,    -1,    -1,   541,    -1,    -1,    -1,
      -1,   351,    -1,    52,   549,    -1,    -1,    -1,    -1,    -1,
      -1,   361,    -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,
      -1,   566,    -1,  3498,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   382,   383,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   590,    -1,   397,   306,    -1,
      -1,   309,    -1,    -1,    -1,   405,    -1,    -1,    -1,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   417,   418,   419,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   634,
      -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,   643,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,   653,   654,
      -1,    -1,    -1,    -1,    -1,    -1,   661,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,   672,    -1,    -1,
      -1,    -1,    -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
     428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   727,   728,   534,   443,    -1,    -1,    -1,   447,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,   483,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,   595,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   511,    -1,    -1,    -1,   306,    -1,    -1,
     309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   631,    -1,    -1,    -1,    -1,   109,   110,    -1,    -1,
      -1,   114,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,   124,   125,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   677,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,   691,   692,   693,   694,   695,   696,   697,    -1,   699,
     700,   609,   175,    -1,   177,   178,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   716,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,   201,   428,
     203,   204,   205,    -1,    -1,    -1,    -1,    -1,   211,    -1,
     213,   214,    -1,   216,   443,   218,   219,    -1,   447,   222,
      -1,    -1,   225,   226,   227,   228,   229,   230,    -1,    -1,
      -1,   234,   235,   236,    -1,   238,    -1,   675,    -1,   242,
      -1,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
     253,    -1,    -1,   256,   483,   258,    -1,   260,    -1,   262,
      -1,    -1,    -1,   266,   267,    -1,   269,   270,   271,    -1,
      -1,   274,   306,   276,   277,   309,   279,    -1,    -1,    -1,
      -1,    -1,   511,    -1,   287,   288,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,   528,
     303,   304,    -1,    -1,   307,   308,    -1,    -1,   311,   312,
      -1,    -1,    -1,    -1,    -1,    -1,   319,   320,   321,    -1,
     323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     333,   334,   335,    -1,   337,    -1,    -1,    -1,   341,   342,
      -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,
     363,   364,    -1,    -1,    -1,    -1,    -1,   370,   371,    -1,
      -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,   381,    -1,
     609,    -1,   385,   386,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   396,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
     413,    -1,    -1,   447,   448,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   675,   450,    -1,   483,
      -1,    -1,    -1,   456,    -1,   458,   459,    -1,    -1,    -1,
      -1,    -1,    -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,
     523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   546,   547,    -1,    -1,    -1,   551,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     563,    -1,    -1,    -1,    -1,    -1,   569,   570,   571,   572,
      -1,    -1,    -1,   576,    -1,   609,    -1,   580,    -1,    -1,
      -1,    -1,    -1,    -1,   587,   588,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   598,    -1,   600,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   611,    -1,
     613,    -1,    -1,   616,    -1,    -1,     6,     7,     8,   622,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   675,    -1,    -1,    -1,   648,    -1,    -1,   651,    -1,
      -1,    -1,    -1,   656,    -1,    -1,   659,   660,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   674,    -1,    -1,    -1,     6,     7,     8,   681,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   704,   705,   706,   707,   708,   709,   710,    -1,    -1,
     713,    -1,   715,    -1,   717,    -1,    -1,    -1,    -1,    -1,
      -1,    52,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,   167,   168,   169,    52,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,   306,    -1,    -1,   309,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,   309,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   306,    -1,    -1,   309,   167,   168,   169,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,    -1,    -1,   443,    -1,    -1,    -1,   447,   448,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   306,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   483,    -1,    -1,    -1,   428,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,   443,    -1,    -1,    -1,   447,   448,    -1,    -1,
      -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,
     306,    -1,    -1,   309,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      -1,    -1,    -1,   447,   448,   306,    -1,    -1,   309,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,
     309,    -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,   483,
      -1,    -1,    -1,   428,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   443,   609,
      -1,    -1,   447,   448,   167,   168,   169,   511,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,     6,
       7,     8,   428,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   443,   609,    -1,
      -1,   447,   448,    -1,    -1,   675,   511,   428,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   528,    -1,    52,   447,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   609,    -1,    -1,   447,   448,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   483,    -1,   675,   511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528,   306,   483,    -1,   309,     6,     7,     8,
     511,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   609,    -1,    -1,   528,    -1,    -1,
      -1,   675,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   528,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,    -1,    -1,    -1,    -1,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   609,    -1,    -1,    -1,    -1,    -1,     8,
     675,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,   609,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,
     609,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,   675,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,   675,    -1,    -1,    -1,    -1,    -1,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   496,    -1,    -1,   675,    -1,    -1,   306,
      -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,   511,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   528,    -1,   167,   168,   169,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   609,   306,    -1,    -1,
     309,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,   428,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   443,    -1,     9,    -1,
     447,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,   306,    38,    39,   309,
      -1,    -1,   675,    -1,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,   496,
     309,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,   167,
     168,   169,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,   528,    -1,    -1,    -1,     9,    -1,    -1,    -1,   428,
     167,   168,   169,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,   443,    -1,    -1,    -1,   447,    -1,
      -1,   122,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,   483,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   496,    -1,    -1,
      -1,    -1,   609,   443,    -1,    -1,    -1,   447,    -1,   428,
      -1,    -1,   511,    -1,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,   447,   528,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,   122,    24,
      25,    26,    27,   483,    -1,    -1,    -1,    -1,   306,    52,
      -1,   309,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,   675,   306,
      -1,   511,   309,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,   528,    -1,
      -1,    -1,   511,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,   528,
     609,    -1,    -1,    -1,    38,    39,    52,   306,    -1,    -1,
     309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   167,   168,   169,    -1,    -1,   609,
     428,    -1,    -1,    -1,    -1,    -1,   675,    -1,    -1,   350,
      -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,   447,
     609,   428,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,
     447,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,   675,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,    -1,   511,   443,    -1,   675,    -1,   447,   496,
      -1,    -1,   247,    -1,    -1,    -1,   350,    -1,    -1,    -1,
     528,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   528,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,
      -1,   482,    -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,   247,    -1,    -1,   497,   498,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,   528,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,   609,    -1,    -1,   525,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,   350,   537,   451,    -1,    -1,
     306,    -1,   609,   309,    -1,    38,    39,    -1,   549,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,   482,    -1,
      -1,   485,    -1,    38,    39,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,   497,   498,    -1,    -1,   675,    -1,   590,
     609,    -1,    -1,    -1,    -1,   428,    -1,    -1,    18,    19,
      20,   122,    -1,    -1,    24,    25,    26,    27,   675,    -1,
     443,    -1,    -1,    -1,   447,    -1,    -1,    -1,    38,    39,
      -1,    -1,   623,   537,    -1,    18,    19,    20,   629,   122,
      -1,    24,    25,    26,    27,   549,   451,   638,   639,    -1,
     641,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
     483,    -1,   653,   654,    -1,    -1,   675,   122,    -1,    -1,
     661,    -1,   428,   664,    -1,    -1,    -1,   482,    -1,    -1,
     485,   672,    -1,    -1,    -1,    -1,   590,   443,   511,    -1,
      -1,   447,   497,   498,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,   528,    -1,   451,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    38,    39,    -1,    -1,   623,
      -1,    -1,    -1,    -1,    -1,   629,    -1,   483,    -1,    -1,
      -1,    -1,   537,    -1,   638,   639,   247,   641,   482,   122,
      -1,   485,    -1,    -1,   549,    -1,    -1,    -1,    -1,   653,
     654,    -1,    -1,    -1,   498,   511,    -1,   661,    -1,    -1,
     664,    -1,    -1,    -1,   247,    -1,    -1,    -1,   672,    -1,
      -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   525,    -1,    -1,    -1,   590,   609,    -1,    -1,    -1,
      -1,    -1,   247,   537,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    18,    19,    -1,   549,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,   623,    -1,
      -1,    -1,    38,    39,   629,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   638,   639,    -1,   641,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,   653,   654,
      -1,    -1,   675,   609,    -1,    -1,   661,    -1,    -1,   664,
      -1,    -1,    -1,    -1,   247,    -1,    -1,   672,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,   623,
      -1,    -1,    -1,    -1,    -1,   629,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,   638,   639,    -1,   641,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,   653,
     654,    -1,    -1,    -1,    -1,    -1,    -1,   661,    -1,   675,
     664,    -1,    -1,    -1,   247,    -1,    -1,    -1,   672,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,   375,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
      -1,   482,   122,    -1,   485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   451,   414,    -1,   482,
      -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,   426,
      -1,    32,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,
     437,    -1,    -1,    44,    -1,    -1,   537,   482,    -1,    -1,
     485,   247,    -1,    -1,    -1,    -1,   453,    -1,   549,    -1,
      -1,   451,    -1,   498,    -1,    -1,   463,    -1,    -1,    -1,
      -1,    -1,    -1,   536,   537,    -1,    -1,    -1,    -1,    -1,
      -1,   478,    -1,    -1,    -1,    -1,   549,    -1,   451,    -1,
      -1,    -1,   482,    -1,    -1,   485,    -1,    -1,    -1,   590,
      -1,   536,   537,    -1,    -1,    -1,    -1,    -1,   498,    -1,
      -1,    -1,    -1,    -1,   549,    -1,    -1,   247,    -1,   482,
     121,   518,   485,    -1,    -1,    -1,    -1,   590,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   137,   138,   629,    -1,
      -1,    -1,    -1,   540,    -1,    -1,   147,   537,   451,    -1,
     641,    -1,    -1,    -1,    -1,   590,    -1,    -1,   555,   549,
     623,    -1,   653,   654,    -1,   562,   629,    -1,   565,    -1,
     661,    -1,    -1,   664,   537,   638,   639,    -1,   641,   482,
      -1,   672,   485,    -1,    -1,    -1,   549,    -1,   623,   586,
     653,   654,    -1,   590,   629,   498,    -1,    -1,   661,    -1,
     590,   664,    -1,   638,   639,    -1,   641,    -1,    -1,   672,
      -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,   653,   654,
      -1,    -1,   525,    -1,    -1,    -1,   661,   590,    -1,   664,
     627,    -1,    -1,   623,   537,    -1,    -1,   672,    -1,   629,
      -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,   638,   639,
      -1,   641,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,
     623,    -1,    -1,   653,   654,    -1,   629,    -1,    -1,    -1,
      -1,   661,    -1,    -1,   664,   638,   639,    -1,   641,    -1,
      -1,    -1,   672,    -1,    -1,    -1,   482,   590,    -1,   485,
     653,   654,    -1,    -1,    -1,    -1,    -1,    -1,   661,    -1,
      -1,   664,   498,    -1,    -1,    -1,    -1,    -1,    -1,   672,
      -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,    -1,   629,    -1,    -1,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,   641,    -1,
      -1,   537,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,
     653,   654,   482,   549,   355,   485,    -1,    -1,   661,    -1,
      -1,   664,    -1,    -1,    -1,    -1,    -1,    -1,   498,   672,
      -1,    -1,    -1,   374,   375,   376,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,   375,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,   549,
      -1,    -1,    -1,    -1,    -1,   426,   155,    -1,    -1,    -1,
      -1,    -1,    -1,   629,    -1,    -1,   437,    -1,    -1,    -1,
      -1,    -1,    -1,   414,    -1,   641,    -1,    -1,    -1,    -1,
      -1,    -1,   453,    -1,    -1,   426,    -1,   653,   654,    -1,
     590,    -1,   463,    -1,    -1,   661,   437,    -1,   664,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   672,   478,    -1,    -1,
      -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   463,   623,    -1,    -1,    -1,    -1,    -1,   629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,   638,   639,
      -1,   641,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,
      -1,    -1,    -1,   653,   654,    -1,    -1,    -1,    -1,    -1,
     259,   661,    -1,    -1,   664,    -1,    -1,    -1,    -1,   540,
      -1,    -1,   672,    -1,    -1,    -1,    -1,   518,    -1,    -1,
      -1,    -1,    -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,
      -1,   562,    -1,    -1,   565,    -1,    -1,    -1,    -1,   540,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   555,   586,    -1,   316,    -1,   590,
      -1,   562,    -1,    -1,   565,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,
      -1,   340,    -1,    -1,    -1,   586,    -1,    -1,    -1,   590,
     349,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   627,    -1,   387,    -1,
      -1,   390,    -1,    -1,    -1,    -1,   395,    -1,   669,    -1,
      -1,    -1,    -1,    -1,   403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,
      -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   533,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   543,   544,    -1,    -1,    -1,    -1,
     549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,   584,   585,    -1,    -1,    -1,
     589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   646,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,   657
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    43,   133,   293,   413,   461,   492,   521,
     731,   793,   801,   828,   829,   885,  1059,  1060,  1116,  1117,
    1118,  1120,  1121,  1122,  1127,  1129,  1142,  1143,  1144,  1145,
    1146,  1588,    28,    29,   802,   803,   804,   805,   806,    27,
    1023,  1603,  1023,  1023,    25,  1023,  1493,  1147,   830,  1493,
    1023,   829,     0,  1119,  1122,  1145,    31,   804,   806,   886,
     664,    25,   247,   827,   828,  1010,  1023,  1028,  1127,  1142,
    1148,  1179,  1180,  1181,  1182,  1183,  1187,   411,   832,   833,
     834,   835,   838,   839,   794,   111,   118,   164,   165,   424,
     519,   610,   690,   698,   801,   978,  1058,  1123,  1124,  1126,
    1130,  1131,  1137,  1149,  1302,  1312,  1588,   669,  1023,  1182,
     299,   512,   513,  1188,    20,  1023,  1186,   672,   833,     5,
     831,   411,  1023,     5,   858,   860,   861,   732,   797,  1023,
    1313,  1023,  1303,  1138,  1023,  1023,  1126,  1132,   317,   355,
     374,   375,   414,   426,   437,   453,   463,   478,   518,   540,
     555,   562,   565,   586,   590,   609,   627,   887,   888,   889,
     892,    25,  1179,  1185,    18,    19,    26,    42,   117,   129,
     156,   249,   345,   380,   414,   426,   462,   477,   485,   498,
     541,   566,   590,   634,   643,   727,   728,   742,   744,   945,
     952,   963,   965,  1023,  1179,  1189,  1190,   513,    14,   884,
     835,   575,  1289,   836,   833,   838,    32,    44,   121,   137,
     138,   147,   317,   355,   374,   375,   376,   377,   392,   414,
     426,   437,   453,   463,   478,   518,   540,   555,   562,   565,
     586,   590,   609,   627,   669,   842,   852,   863,   868,  1023,
     795,  1023,   485,  1023,   827,   979,  1150,  1023,   894,   375,
     840,   485,   870,   872,   873,   871,   880,   881,   485,   485,
     893,   513,   485,   833,   851,   480,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   742,   485,   824,
       9,    18,    19,    24,    25,    26,   122,   350,   444,   449,
     451,   467,   482,   485,   488,   497,   537,   549,   560,   590,
     641,   653,   654,   661,   672,   921,   929,   930,   931,   932,
     933,   963,   964,   966,  1029,  1179,  1292,  1486,   485,   485,
     485,   485,   485,   485,    18,    19,    20,    21,    22,   743,
      26,    36,   485,   574,     5,   481,  1189,    25,    26,  1023,
    1029,    19,    25,    26,   837,  1029,   722,   723,   724,   841,
     865,   854,   866,   840,   485,   485,   485,   855,   870,   871,
     485,   485,   853,   513,   864,   485,   851,   833,   862,   827,
     485,    26,   485,  1139,   827,   827,   485,  1023,   485,   512,
     846,    26,   678,   423,   508,   524,   566,   605,   634,   643,
     874,   678,   423,   508,   524,   566,   605,   634,   643,   882,
      26,    26,   895,   896,   897,   898,  1023,    26,   849,   850,
      26,   642,   664,   672,  1179,   719,   971,  1014,  1023,  1014,
    1014,   971,   971,   921,    24,    25,    26,    19,    24,    25,
      26,   672,   967,   968,   969,   970,    25,   972,  1014,  1015,
     921,   448,   921,   921,   921,   921,   579,  1309,   485,   485,
     921,   423,   508,   524,   566,   605,   634,   643,  1489,  1490,
     485,   921,   921,   485,   485,   934,   485,   485,   485,   485,
      26,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    52,   149,   150,
     151,   152,   153,   154,   167,   168,   169,   306,   309,   428,
     443,   447,   483,   511,   528,   609,   675,   823,   922,   935,
     937,   938,   939,   940,   941,   942,   943,   475,   955,   953,
     959,   957,  1179,  1179,   742,  1023,   946,  1023,  1190,   513,
     481,    26,   844,   485,   867,   851,   867,   846,    26,    26,
      26,   851,    26,    26,   832,   849,   867,    26,   672,   116,
     859,   796,  1314,   448,  1304,  1604,  1605,  1606,  1607,  1608,
     980,  1151,  1133,   672,    26,   448,   875,   876,   485,   877,
     882,   883,   877,   485,   878,     5,   448,     5,   448,     5,
     339,     5,   887,   481,     5,     5,   448,   833,   833,   833,
     869,   448,   485,     5,   448,   513,   672,   448,   448,   448,
     448,   448,   448,   448,    19,    26,   448,   642,   968,    19,
      26,   642,    26,   448,     5,   448,   448,     5,   825,   921,
     525,  1509,   921,   485,   678,    20,   448,  1509,    20,  1292,
     921,   921,   921,   921,   921,   921,   921,   921,   921,   921,
     921,   921,   921,   921,   921,   921,   921,   921,   921,   921,
     921,   921,   921,   485,   921,   921,   485,  1179,   921,   921,
     921,   921,   448,     5,   485,   536,   774,   775,   776,   921,
     485,  1189,   513,   676,    26,   672,    26,   448,   448,     5,
     448,   315,     5,   448,     5,   448,   339,   481,     5,   448,
     869,   798,   799,  1131,  1023,  1195,  1196,  1198,  1195,   418,
    1605,  1289,    45,    46,    47,    54,    57,    64,    65,   109,
     110,   114,   124,   125,   127,   141,   158,   161,   162,   175,
     177,   178,   179,   187,   188,   190,   191,   192,   198,   201,
     203,   204,   205,   211,   213,   214,   216,   218,   219,   222,
     225,   226,   227,   228,   229,   230,   234,   235,   236,   238,
     242,   244,   245,   250,   253,   256,   258,   260,   262,   266,
     267,   269,   270,   271,   274,   276,   277,   279,   287,   288,
     300,   303,   304,   307,   308,   311,   312,   319,   320,   321,
     323,   333,   334,   335,   337,   341,   342,   346,   354,   362,
     363,   364,   370,   371,   378,   381,   385,   386,   396,   413,
     421,   427,   438,   450,   456,   458,   459,   466,   505,   516,
     523,   546,   547,   551,   563,   569,   570,   571,   572,   576,
     580,   587,   588,   598,   600,   611,   613,   616,   622,   648,
     651,   656,   659,   660,   674,   681,   704,   705,   706,   707,
     708,   709,   710,   713,   715,   717,   735,   736,   737,   738,
     755,   779,   800,   801,   807,   826,   900,   901,   902,   903,
     914,   915,   916,   917,   918,   919,   920,   973,  1004,  1008,
    1030,  1032,  1035,  1036,  1037,  1038,  1051,  1061,  1085,  1086,
    1088,  1092,  1107,  1108,  1112,  1113,  1114,  1115,  1125,  1140,
    1156,  1167,  1168,  1169,  1173,  1176,  1210,  1213,  1215,  1221,
    1222,  1225,  1228,  1233,  1235,  1237,  1240,  1247,  1252,  1257,
    1258,  1259,  1271,  1272,  1275,  1281,  1284,  1285,  1310,  1325,
    1327,  1328,  1329,  1330,  1342,  1348,  1349,  1369,  1372,  1401,
    1403,  1494,  1495,  1526,  1527,  1534,  1549,  1573,  1588,  1589,
    1594,  1595,  1597,  1601,  1602,  1609,   801,  1128,   677,   700,
    1152,  1153,  1195,    20,   448,   480,   847,   874,    26,   879,
      26,    26,    26,   896,   898,   890,   850,    26,   642,  1023,
    1014,   742,    20,   719,  1023,   874,   961,   961,    26,   448,
     642,   961,    24,    26,    26,   642,    24,    26,   871,   962,
    1015,   872,   448,   416,   529,   638,  1517,   448,   448,    26,
    1490,   448,   448,   448,   448,   448,   448,   448,   496,   496,
     496,   944,  1509,   496,   944,  1509,   956,   954,   960,   958,
      26,   950,   947,     5,   948,   481,  1189,   858,   448,    20,
     847,    26,   485,    26,    26,   843,    26,   730,   799,   672,
     448,     5,   448,  1179,  1179,  1179,  1023,    25,  1179,  1234,
    1023,    25,  1023,  1479,   407,  1024,  1025,  1603,  1024,    25,
    1023,  1478,  1023,  1023,  1255,  1018,  1024,  1018,  1023,  1599,
    1479,  1023,    26,   739,  1179,  1333,  1018,  1255,   944,    26,
    1029,  1297,  1298,  1297,   921,   928,  1371,  1478,  1478,   923,
     944,  1024,  1535,  1535,   904,  1255,  1018,  1331,  1179,  1020,
    1024,   928,  1535,  1179,  1255,  1179,  1370,  1535,    25,   638,
    1170,  1171,  1179,  1018,  1018,  1170,  1019,  1024,  1023,  1171,
    1018,  1535,  1018,  1020,  1479,  1179,  1208,  1209,  1016,  1024,
    1020,   432,   614,  1014,  1087,  1023,   808,  1478,  1021,  1024,
      25,   247,  1023,  1402,  1577,  1579,  1580,  1581,  1582,  1584,
     944,  1208,   678,   944,  1024,  1236,   974,    67,    68,    69,
      70,   189,   197,   206,   209,   252,   259,   316,   340,   347,
     349,   359,   387,   395,   432,   456,   493,   504,   601,   602,
     603,   614,   659,   717,   733,  1101,  1229,  1230,  1179,  1200,
    1201,   927,   928,  1246,   971,   971,  1017,  1024,   944,  1234,
    1311,  1179,  1288,    25,   485,  1179,  1283,  1529,  1282,   928,
    1590,   163,   212,   249,   345,   422,   462,   527,   756,   952,
    1023,  1179,  1320,   781,   928,  1016,   642,  1023,  1031,  1157,
     928,  1016,    26,  1179,  1109,  1016,   928,  1550,   928,  1297,
    1023,  1033,  1034,  1020,  1033,   971,  1020,  1033,   971,  1039,
    1033,    25,    26,   441,   540,  1029,  1090,  1179,  1197,  1199,
     123,   330,   402,   446,   621,   701,   702,   703,   712,   746,
    1041,  1043,  1045,  1047,  1049,  1174,  1175,  1178,   393,   404,
     454,   468,   556,  1404,   692,   693,   982,   983,   984,  1023,
    1154,   699,  1153,   448,   358,   448,   448,   448,   448,   676,
       5,   448,   833,   448,   481,   485,   678,    19,    26,   448,
     961,    26,   448,   448,   642,    26,   642,   678,    18,    19,
      20,    25,    26,    38,    39,   122,   451,   482,   485,   498,
     537,   549,   590,   623,   629,   638,   639,   641,   653,   654,
     661,   664,  1023,  1029,  1485,  1487,  1516,  1518,  1519,  1521,
    1522,  1523,  1545,  1546,  1547,  1548,  1578,  1579,  1583,  1309,
     448,  1309,  1309,  1309,  1309,  1309,  1309,    25,    25,    25,
     921,   936,   448,    25,   936,   448,   448,   448,   448,   448,
     448,   774,   448,   776,   774,   481,   358,   448,   833,   856,
     857,   448,   448,   676,   448,  1023,  1315,  1198,  1305,   112,
     113,   142,   143,   144,   509,   594,   637,  1350,  1351,  1352,
    1355,  1358,  1361,  1362,  1363,  1366,   672,   642,   664,   159,
     160,   485,   672,   642,   664,     8,   677,   481,  1478,   532,
    1256,  1197,   167,   168,   169,   648,   536,   924,   925,   928,
    1179,  1204,  1478,   745,   746,   907,   322,    51,   145,   146,
     678,  1253,   514,     5,   671,   678,   670,   670,  1211,   648,
     475,     5,   609,  1062,   514,   711,  1592,   711,   441,   810,
    1179,   599,   670,  1216,  1217,  1218,   672,    25,  1580,   513,
    1585,   384,  1400,   664,   672,   926,   928,   609,  1577,   926,
       8,   606,  1017,    26,   554,   607,   721,  1009,  1179,  1009,
    1009,  1009,    25,   234,   360,   366,   367,   368,   388,   493,
     496,   504,   538,   573,   592,   593,   603,   608,   647,   679,
    1105,  1106,  1009,  1009,   649,  1102,   746,  1102,  1102,  1010,
    1010,  1102,  1102,    40,    41,  1231,   746,    40,    41,  1232,
       5,   475,     5,   391,   442,     5,   745,   139,   140,   592,
     679,  1093,   714,  1593,   927,   665,   666,   667,   668,  1287,
    1529,  1289,   928,  1277,  1278,  1279,  1290,  1291,   928,   485,
     485,   485,   485,    25,   777,  1023,   485,  1529,   402,   485,
     574,    36,   642,   631,   782,   789,   780,  1023,    25,  1172,
    1179,  1273,     8,  1276,    14,  1023,  1184,  1191,  1192,  1194,
    1202,  1203,  1248,    40,    41,   220,   402,   597,   630,  1326,
      33,   247,   606,  1551,  1552,  1553,  1555,   628,     5,   711,
     711,   926,  1197,  1204,  1089,   475,     5,   208,  1067,   485,
    1179,   926,   485,    26,    26,   123,  1177,    25,  1179,  1533,
    1533,  1024,  1384,  1236,  1017,    37,   176,   278,   286,   292,
     294,   305,   332,   348,   353,   365,   372,   520,   525,   531,
     553,   558,  1373,  1374,  1382,  1391,  1392,  1398,  1399,  1405,
    1406,  1416,  1436,  1440,  1505,  1506,  1536,  1537,  1540,  1541,
    1557,   985,   986,   148,   981,   992,   993,   984,  1155,  1604,
    1134,   513,   887,   850,   672,  1023,   874,    26,   448,   642,
     961,   448,   642,   961,   961,    24,    26,   642,    24,    26,
     875,  1522,  1522,   423,   508,   524,   566,   605,   634,   643,
    1488,  1491,   525,  1521,   485,   485,   485,   485,  1516,  1516,
    1516,   485,   485,   485,   485,  1023,   485,     5,   599,  1445,
    1450,   669,  1023,    18,    19,    20,    21,   149,   150,   151,
     152,   153,   154,  1543,  1491,  1491,   475,     5,   448,   448,
     951,   949,   513,     5,   448,   858,   827,   827,   302,   315,
     416,   485,   529,   545,  1420,  1421,  1426,  1428,   485,  1023,
    1367,  1368,    26,   485,  1023,  1347,  1360,  1428,  1430,   485,
    1023,  1357,   485,  1347,  1353,     5,  1023,    25,  1023,  1023,
      25,  1026,  1182,  1023,    25,  1023,  1023,  1023,  1600,  1478,
     648,   485,   485,   907,  1478,     5,   678,   485,  1577,    25,
    1028,  1254,  1253,  1254,  1529,  1170,   928,   928,   928,  1011,
    1012,   485,  1179,  1209,  1063,  1064,  1065,  1478,   678,  1529,
     971,  1593,  1087,  1179,   809,   677,   928,   408,  1220,   609,
    1219,  1581,   742,  1586,  1587,  1023,    20,  1582,     5,  1574,
     669,  1226,   126,   128,   130,   670,   678,   899,  1197,  1200,
     975,    18,    19,   485,  1103,  1105,  1230,  1179,  1201,  1010,
     928,   402,   648,    26,  1179,    26,  1179,   745,   210,  1286,
     448,   440,  1324,  1289,  1279,     5,   670,  1280,  1591,  1023,
      25,   971,   971,   642,  1015,   675,  1179,   762,  1023,  1023,
    1023,   928,   397,   785,   789,   631,   783,   791,    23,   291,
    1159,  1163,   535,   944,   535,  1274,   928,   512,  1188,   672,
       5,  1110,   599,  1249,  1179,   220,   402,  1554,  1556,   246,
    1552,  1052,  1034,   971,   971,  1044,  1045,  1067,  1067,    48,
      49,    50,    53,    55,    56,   326,   329,   331,   351,   361,
     382,   405,   409,   484,  1066,  1068,  1069,  1097,  1179,  1199,
     599,   747,    26,   455,  1050,   379,  1528,  1528,   195,   196,
     491,   599,  1023,  1437,  1438,  1480,  1478,  1478,  1478,  1375,
    1478,  1478,  1023,  1538,   224,   436,   450,   493,   504,   525,
     531,   539,   561,   638,   644,  1407,  1409,  1410,  1411,  1517,
    1478,  1383,  1407,  1409,  1604,  1604,   441,   994,  1179,   694,
     695,   987,   988,   989,   534,   677,   696,   697,   716,   997,
     998,  1604,   827,    26,   848,    20,  1023,   448,    26,   448,
     961,    26,   961,    24,    26,   448,   448,    24,    26,   678,
    1517,   448,   451,  1521,  1544,  1583,   416,   529,   638,  1469,
    1521,  1524,  1469,  1469,  1469,  1469,   672,  1524,  1519,   568,
    1446,  1447,  1448,  1478,   579,  1444,  1451,   389,   567,   578,
    1393,  1512,  1023,  1521,  1521,  1521,  1521,   678,   485,   678,
    1578,   921,   448,   448,   848,   857,  1316,  1306,   485,   485,
     485,  1364,  1428,   485,   485,   115,  1365,  1367,     5,  1359,
    1360,   121,   355,   375,   376,   377,   414,   426,   437,   453,
     463,   478,   526,   555,   565,   586,   590,   618,   627,  1470,
    1471,  1472,  1474,  1356,  1357,  1353,  1354,   716,  1351,   672,
     642,   448,   672,   642,   599,  1598,   485,   740,   741,  1023,
    1334,   944,   924,  1023,  1332,   669,  1223,  1253,  1253,   678,
       5,     5,     5,   632,   928,     5,   672,   536,   678,   677,
     221,   223,   326,   329,   811,   814,   815,  1097,   812,   813,
    1023,   485,  1024,   701,   702,  1224,     5,   481,   928,  1478,
    1575,  1576,  1577,   629,   669,  1227,  1023,  1023,  1012,  1013,
     562,   971,   907,     8,     8,   977,    26,    26,  1104,  1105,
    1179,   375,  1241,   123,   921,  1289,   275,  1291,  1297,  1604,
       5,     5,   448,   448,   778,  1023,   448,  1529,   774,   485,
     485,   485,   790,   786,   417,   784,   928,   397,   787,   791,
     649,  1099,  1164,  1160,   419,  1158,  1159,   926,   678,  1185,
      20,  1023,  1193,  1203,    14,   536,  1250,  1251,  1521,  1179,
    1583,  1200,  1604,  1046,  1047,   603,  1022,   599,  1080,  1079,
    1078,  1077,  1082,  1081,  1014,  1083,  1014,  1084,  1076,  1075,
    1073,  1072,  1098,   382,  1069,  1074,   971,    58,    59,    60,
      61,    62,    63,   155,   390,   403,   465,   471,   510,   533,
     543,   544,   549,   559,   581,   584,   585,   589,   646,   657,
     748,   749,  1095,  1096,     5,    26,  1529,   305,  1179,   525,
    1510,  1511,  1529,  1236,  1504,  1506,   157,   157,   648,  1234,
    1439,  1440,   485,  1417,   207,  1451,  1478,   231,   327,  1542,
     672,   678,   485,  1412,  1412,   599,   677,     5,  1507,  1558,
     399,   408,   432,   435,   451,   554,   607,   614,  1017,  1385,
    1390,   678,   677,   996,  1179,     5,   599,   990,   991,   691,
     989,   995,  1023,   995,   999,  1000,   995,   382,   998,  1135,
     481,   448,   642,   961,   448,   642,   448,   448,   961,   961,
     423,   508,   524,   566,   605,   634,   643,  1492,  1518,     5,
    1491,     5,   448,     5,  1521,     5,   448,  1521,  1521,  1521,
    1521,  1023,   448,   485,  1448,     5,   669,  1023,  1484,     9,
     350,   485,   497,  1454,  1455,  1456,  1457,  1458,  1462,  1466,
    1468,  1521,   425,  1442,  1452,  1023,  1513,   671,  1469,   389,
    1492,    26,  1492,   481,   515,  1299,  1319,   515,  1260,  1293,
     664,  1023,  1423,  1425,  1478,  1482,  1483,  1427,  1482,  1427,
       5,   448,  1365,  1427,  1454,  1023,   448,  1368,     5,   448,
     485,   485,   485,  1491,  1491,   485,   485,   485,   485,   485,
     263,   264,   265,   455,  1429,  1431,     5,   448,     5,   448,
    1023,  1023,    25,  1023,  1023,    25,  1023,   928,  1023,  1344,
    1345,     5,  1346,  1347,   944,  1141,   672,  1346,   629,  1529,
    1529,   928,   928,  1011,   562,   928,  1596,     5,  1064,    20,
    1482,  1529,   812,   820,   819,   821,  1023,  1027,   822,  1027,
     248,   815,   818,     5,  1067,   672,   928,     8,  1587,   513,
     672,     5,  1529,   629,  1023,  1197,   944,   606,  1388,     5,
     448,  1179,     5,    26,  1179,   383,    25,  1321,   402,   402,
     513,   672,   402,   485,   763,   767,   760,   758,  1604,  1604,
     792,   788,   784,  1100,    25,  1022,  1165,  1179,  1604,   928,
     480,   513,   944,     5,  1053,  1048,  1049,    26,   745,  1023,
    1604,  1604,  1604,  1604,  1604,  1604,     5,  1070,     5,  1071,
    1604,  1604,  1604,  1604,  1103,  1604,  1022,    25,    14,    14,
       5,   448,    26,  1478,  1517,  1498,   648,   648,  1374,  1503,
    1504,  1440,  1418,  1482,   669,  1017,   485,  1378,  1023,  1539,
    1538,  1413,  1482,   517,  1414,  1415,  1480,  1478,  1411,  1518,
     103,   104,   105,   106,   107,   636,  1561,   928,   928,   606,
    1386,  1017,  1414,  1478,     5,  1179,   995,  1604,  1604,     5,
    1002,  1003,  1604,  1604,  1001,  1128,   891,   961,    26,   961,
      24,    26,   961,   961,   485,  1450,  1491,   678,  1491,  1491,
     448,  1521,   448,   448,   448,   448,  1447,  1449,  1447,  1484,
    1457,  1516,  1454,  1521,  1516,     6,     7,     9,    12,    13,
      14,    15,    16,    17,   428,   429,   483,   609,   675,   725,
     726,  1465,  1467,  1443,  1520,  1521,   502,  1441,  1453,   324,
    1343,    26,  1394,  1395,  1396,  1482,  1510,  1513,   448,   845,
     131,   132,   134,   135,   136,   233,   241,   275,   284,   313,
     314,   357,   401,   455,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,  1296,  1300,   194,   567,  1301,  1317,
     217,   232,   233,   241,   275,   284,   313,   357,   401,  1294,
    1295,  1307,  1301,  1483,   513,  1481,   448,     5,   672,     5,
     448,   448,  1428,   448,   448,  1360,    26,  1475,  1475,    26,
     678,   485,   678,    26,  1476,    26,    26,  1476,  1476,    25,
    1485,   215,   315,   352,   416,   430,   529,   545,  1422,  1432,
    1433,  1434,  1435,  1357,  1353,   672,   672,   591,   640,     5,
     448,   741,     5,   448,   926,   448,    20,   448,  1529,     5,
     928,   619,   330,   750,   751,   928,  1067,  1604,  1604,     5,
     816,   513,   672,     5,   817,  1604,   813,   599,    20,  1023,
       5,  1023,  1214,  1586,    20,  1482,  1576,     8,  1529,   446,
     711,   926,  1389,   976,  1105,   720,  1239,   921,     5,   774,
    1179,   757,   739,  1023,  1179,   765,   448,   774,   774,   774,
    1604,  1604,  1103,  1162,    25,  1166,  1179,   624,  1007,  1189,
     536,   927,  1111,  1251,   120,   595,  1054,  1040,  1041,   672,
    1014,  1604,  1014,  1604,   745,    26,  1179,    26,  1179,   749,
     448,   485,  1530,  1518,  1504,  1504,  1496,     5,   448,   525,
    1515,  1379,  1482,   532,  1376,  1515,   678,     5,   448,     5,
     599,  1508,    18,    19,   122,   482,   485,   498,   536,   537,
     549,   590,   629,   641,   653,   654,   661,   664,  1023,  1485,
    1516,  1545,  1547,  1566,  1567,  1568,  1569,  1570,  1571,  1583,
    1566,  1566,  1566,  1482,  1563,  1565,  1562,  1563,  1564,  1559,
    1387,   678,  1179,  1023,  1604,  1604,  1604,  1604,   676,   448,
     642,   448,   448,    26,   448,   678,  1492,   678,   678,     5,
     448,   448,  1455,  1456,  1460,  1522,  1460,   485,  1516,  1460,
     485,  1516,  1460,    10,   306,   443,   445,  1521,     5,  1454,
       5,   591,   640,  1397,  1343,   678,   676,  1297,  1297,  1297,
      25,  1297,  1297,  1297,  1297,  1297,  1297,    25,    25,  1297,
    1300,  1179,  1205,  1206,   671,   501,  1261,    25,    25,    26,
      26,    26,    26,    26,    25,  1179,  1295,  1261,    26,  1422,
    1482,    20,  1023,  1482,  1365,   448,   448,     5,   448,  1492,
      26,  1492,     5,  1473,     5,   448,   448,   448,  1473,  1424,
    1478,   485,  1434,  1365,  1023,  1023,  1345,   675,   729,  1339,
    1340,  1341,  1347,    66,   143,   144,   301,   675,  1335,  1336,
    1337,   522,   906,  1335,     5,   431,  1529,     5,   485,   448,
     603,  1094,  1027,  1604,   742,    20,  1023,  1027,  1604,   971,
     928,   481,  1529,     8,   971,  1200,  1604,    26,  1022,    25,
    1322,  1197,   481,   774,   764,   768,   448,   448,  1604,  1022,
     928,  1005,   481,  1056,  1055,   495,  1042,  1043,    20,  1023,
    1531,  1532,   606,  1514,  1499,  1497,  1482,  1517,   199,  1419,
       5,   448,  1377,  1539,  1482,  1415,  1414,  1514,  1569,  1569,
    1568,   485,   485,   485,   485,   485,   485,   485,  1023,   485,
       5,   448,    18,    19,    20,    21,  1543,   448,     5,   448,
       5,    14,   207,   579,  1560,  1200,  1414,   268,  1136,   887,
     961,    24,    26,   961,   961,   448,  1492,  1492,  1492,  1447,
     496,  1459,  1459,  1463,  1464,  1485,  1583,  1459,  1463,  1459,
    1460,  1521,  1520,  1395,  1492,   858,   591,   640,  1207,     5,
    1205,   119,   193,   255,   257,   273,   281,   285,   310,  1262,
    1263,  1318,  1308,     5,   481,  1481,    26,   448,    26,  1477,
     448,    26,   448,   485,  1454,  1338,  1603,    26,  1341,    26,
      26,  1338,  1343,  1337,  1014,   745,   431,  1529,   928,   752,
     621,  1212,    26,   745,   481,  1094,   448,  1529,   297,   745,
     448,   448,   485,   766,   402,   772,   448,   761,   759,  1161,
    1604,   513,   928,  1604,  1022,     5,   448,  1200,  1450,  1518,
    1482,   485,  1450,   448,  1544,  1469,  1568,  1572,  1469,  1469,
    1469,  1469,   513,   672,  1572,  1567,  1568,  1568,  1568,  1568,
    1563,    14,  1564,  1567,  1017,  1454,   200,   669,  1408,   448,
     448,  1461,  1485,  1525,     5,   448,   448,  1459,     7,  1206,
    1264,  1265,  1179,  1267,  1179,  1266,  1268,  1263,   296,   296,
      26,   448,   678,   448,  1425,   448,   905,  1529,   449,   259,
     316,   340,   349,   387,   395,   486,   655,   749,   753,   754,
     485,   672,   745,  1238,  1323,   769,   448,  1197,   772,   772,
     772,  1604,  1006,  1189,   628,  1091,  1532,  1512,  1450,   536,
    1380,  1381,  1521,  1512,   448,  1568,     5,   448,  1568,  1568,
    1568,  1568,    26,  1023,   448,   485,  1023,   961,   961,  1464,
    1521,  1604,  1604,  1269,  1604,  1270,  1604,  1604,   481,  1492,
     448,   295,   405,   409,   908,   909,   910,  1097,  1009,  1009,
    1009,  1009,  1009,  1009,    25,     5,   448,   928,    20,  1023,
    1097,  1242,  1243,  1244,   772,   774,   772,   298,   481,  1057,
     745,     5,   448,   343,   344,  1500,   448,  1568,   448,   448,
     448,   448,     5,   481,   513,  1566,  1604,  1604,   912,   911,
     295,   910,   913,   754,     5,  1245,   338,  1244,   770,  1604,
    1381,    25,  1023,  1501,  1502,    26,    26,   448,  1604,  1604,
    1604,   928,  1604,   448,  1054,   672,   672,     5,   481,     5,
     481,   448,   771,  1023,  1023,  1502,    26,   220,   402,   773,
     672,   481,  1197,  1023
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
#line 1010 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1013 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1017 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1023 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1028 "fgl.yacc"
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
#line 1040 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1045 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	//sprintf($<str>$, "A4GL_unregister_func(\"%s\",%s%s);\n", $<str>1, (char *)get_namespace($<str>1), $<str>1);
	sprintf(yyval.str, "A4GL_unregister_func(\"%s\");\n", yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1064 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1065 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1066 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1067 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1068 "fgl.yacc"
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
#line 1079 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1085 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1086 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1087 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1088 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1089 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1094 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1095 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1106 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1109 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1112 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1112 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1119 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1120 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1136 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1137 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1138 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1139 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1140 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1141 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1142 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1149 "fgl.yacc"
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
#line 1160 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1164 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1165 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1169 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1175 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1177 "fgl.yacc"
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
#line 1188 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1190 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1192 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1194 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1198 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1200 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1261 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1265 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1269 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1276 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1279 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1283 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1287 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1296 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1302 "fgl.yacc"
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
#line 1311 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1316 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1322 "fgl.yacc"
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
#line 1331 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 77:
#line 1338 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 78:
#line 1343 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 79:
#line 1347 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 80:
#line 1355 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 81:
#line 1359 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1363 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1365 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 84:
#line 1371 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 85:
#line 1376 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 86:
#line 1379 "fgl.yacc"
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
#line 1395 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 88:
#line 1402 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 89:
#line 1406 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 90:
#line 1410 "fgl.yacc"
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
#line 1432 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 92:
#line 1432 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 93:
#line 1436 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 94:
#line 1437 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 95:
#line 1438 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 96:
#line 1443 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 97:
#line 1446 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 98:
#line 1452 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 99:
#line 1455 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 101:
#line 1464 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 103:
#line 1468 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 104:
#line 1474 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 105:
#line 1477 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 106:
#line 1492 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 107:
#line 1502 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1508 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 109:
#line 1517 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 114:
#line 1530 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 116:
#line 1533 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 117:
#line 1535 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 119:
#line 1541 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 120:
#line 1543 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 121:
#line 1548 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 122:
#line 1553 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 123:
#line 1559 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 124:
#line 1563 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 125:
#line 1572 "fgl.yacc"
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
#line 1596 "fgl.yacc"
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
#line 1604 "fgl.yacc"
    { 
		pop_record();in_record--;
		read_class(yyvsp[-2].str); 
		print_variables(); 
		class_set_parent();
		}
    break;

  case 128:
#line 1610 "fgl.yacc"
    {
		class_cnt++; 
		CLASS_print_reflector();
		dump_class();
		}
    break;

  case 129:
#line 1620 "fgl.yacc"
    {
	static char buff[256];
		strcpy(buff,"default_object");
		CLASS_set_parent_name(buff);
		strcpy(yyval.str,buff);
	}
    break;

  case 130:
#line 1625 "fgl.yacc"
    {
		CLASS_set_parent_name(yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 134:
#line 1648 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 135:
#line 1651 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 136:
#line 1654 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 137:
#line 1657 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 138:
#line 1660 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 139:
#line 1663 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 145:
#line 1685 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 148:
#line 1694 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 149:
#line 1713 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 150:
#line 1718 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 151:
#line 1721 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 152:
#line 1730 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 153:
#line 1736 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 158:
#line 1751 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 159:
#line 1755 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 160:
#line 1760 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 163:
#line 1770 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 164:
#line 1770 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 165:
#line 1771 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 166:
#line 1771 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 167:
#line 1772 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 168:
#line 1772 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 169:
#line 1773 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 170:
#line 1773 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 171:
#line 1774 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 172:
#line 1774 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 173:
#line 1782 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 174:
#line 1786 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 175:
#line 1792 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 176:
#line 1796 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 177:
#line 1811 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 178:
#line 1814 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 179:
#line 1817 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 180:
#line 1820 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 181:
#line 1823 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 182:
#line 1826 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 183:
#line 1835 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 184:
#line 1843 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 185:
#line 1848 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 186:
#line 1861 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 187:
#line 1865 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 188:
#line 1880 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 189:
#line 1881 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 192:
#line 1889 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 193:
#line 1889 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 198:
#line 1898 "fgl.yacc"
    {in_define=1;}
    break;

  case 199:
#line 1898 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 200:
#line 1907 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 201:
#line 1908 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 202:
#line 1909 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 203:
#line 1912 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 205:
#line 1917 "fgl.yacc"
    { }
    break;

  case 206:
#line 1917 "fgl.yacc"
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
#line 1934 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 211:
#line 1938 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 216:
#line 1953 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 217:
#line 1954 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 218:
#line 1955 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 219:
#line 1956 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 220:
#line 1961 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 222:
#line 1967 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 224:
#line 1976 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 225:
#line 1980 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 231:
#line 1996 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 232:
#line 1998 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 233:
#line 1999 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 236:
#line 2008 "fgl.yacc"
    {
		sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 237:
#line 2010 "fgl.yacc"
    {
		sprintf(yyval.str,"%s@%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 238:
#line 2015 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 239:
#line 2015 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 240:
#line 2016 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 241:
#line 2017 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 242:
#line 2020 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 243:
#line 2022 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 245:
#line 2032 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 250:
#line 2047 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 251:
#line 2047 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 255:
#line 2053 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 256:
#line 2054 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 257:
#line 2055 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 258:
#line 2056 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 259:
#line 2057 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 260:
#line 2058 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 261:
#line 2059 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 262:
#line 2060 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 263:
#line 2061 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 264:
#line 2062 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 265:
#line 2065 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 266:
#line 2066 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 267:
#line 2067 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 268:
#line 2068 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 269:
#line 2072 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 270:
#line 2077 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 271:
#line 2082 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 272:
#line 2086 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 273:
#line 2089 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 274:
#line 2093 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 276:
#line 2094 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 278:
#line 2095 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 280:
#line 2096 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 281:
#line 2097 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 282:
#line 2098 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 283:
#line 2099 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 284:
#line 2100 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 285:
#line 2101 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 286:
#line 2104 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 287:
#line 2105 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 288:
#line 2106 "fgl.yacc"
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
#line 2141 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 292:
#line 2146 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2148 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 294:
#line 2150 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 295:
#line 2155 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 296:
#line 2159 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 297:
#line 2159 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 298:
#line 2163 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 299:
#line 2164 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 300:
#line 2165 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 301:
#line 2166 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 302:
#line 2167 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 303:
#line 2168 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 304:
#line 2170 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 305:
#line 2175 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 306:
#line 2175 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 307:
#line 2178 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 308:
#line 2180 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 309:
#line 2186 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 310:
#line 2188 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 311:
#line 2194 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 312:
#line 2202 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 313:
#line 2202 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 314:
#line 2205 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 315:
#line 2206 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 316:
#line 2207 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 317:
#line 2208 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 318:
#line 2209 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 319:
#line 2210 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 320:
#line 2212 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 324:
#line 2233 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 328:
#line 2242 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 329:
#line 2244 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 330:
#line 2245 "fgl.yacc"
    { dim_push_type("varchar",yyvsp[-1].str,0); }
    break;

  case 331:
#line 2246 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 332:
#line 2250 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 333:
#line 2251 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 334:
#line 2252 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 335:
#line 2253 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 336:
#line 2258 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 337:
#line 2265 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 338:
#line 2270 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 339:
#line 2272 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 340:
#line 2274 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 341:
#line 2275 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 342:
#line 2276 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 343:
#line 2277 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 344:
#line 2278 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 345:
#line 2279 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 346:
#line 2280 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 347:
#line 2283 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 348:
#line 2285 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 349:
#line 2291 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 350:
#line 2299 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 352:
#line 2307 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 353:
#line 2311 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 354:
#line 2319 "fgl.yacc"
    {dim_push_record();}
    break;

  case 355:
#line 2320 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 356:
#line 2321 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 357:
#line 2322 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 363:
#line 2341 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 364:
#line 2353 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 365:
#line 2357 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 366:
#line 2360 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 367:
#line 2363 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 368:
#line 2364 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 369:
#line 2365 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 370:
#line 2366 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 371:
#line 2367 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 372:
#line 2373 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 373:
#line 2380 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 374:
#line 2385 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 375:
#line 2390 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 376:
#line 2395 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 377:
#line 2399 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 378:
#line 2408 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 379:
#line 2410 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 380:
#line 2415 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 386:
#line 2427 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 387:
#line 2431 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 388:
#line 2434 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 389:
#line 2438 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 390:
#line 2441 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 391:
#line 2445 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 392:
#line 2452 "fgl.yacc"
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
#line 2470 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 394:
#line 2476 "fgl.yacc"
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
#line 2500 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 396:
#line 2503 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 397:
#line 2518 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 398:
#line 2521 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 399:
#line 2535 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 400:
#line 2537 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 401:
#line 2539 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 402:
#line 2541 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 403:
#line 2543 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 404:
#line 2545 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 405:
#line 2546 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 406:
#line 2553 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 407:
#line 2555 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 408:
#line 2559 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 409:
#line 2561 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 410:
#line 2563 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 411:
#line 2565 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 412:
#line 2567 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 413:
#line 2569 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 414:
#line 2571 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 415:
#line 2577 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 419:
#line 2596 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 422:
#line 2602 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 423:
#line 2606 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 424:
#line 2611 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 428:
#line 2621 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 429:
#line 2622 "fgl.yacc"
    {inc_counter();}
    break;

  case 435:
#line 2628 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 436:
#line 2635 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 437:
#line 2635 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 439:
#line 2640 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 440:
#line 2644 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 441:
#line 2650 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 442:
#line 2658 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 443:
#line 2664 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 444:
#line 2673 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 445:
#line 2675 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 446:
#line 2682 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 447:
#line 2703 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2708 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 449:
#line 2713 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 450:
#line 2717 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 451:
#line 2719 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 452:
#line 2722 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 453:
#line 2740 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 454:
#line 2746 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2752 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 458:
#line 2762 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 459:
#line 2768 "fgl.yacc"
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
#line 2840 "fgl.yacc"
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
#line 2851 "fgl.yacc"
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
#line 2859 "fgl.yacc"
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
#line 2867 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 464:
#line 2867 "fgl.yacc"
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
#line 2883 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 466:
#line 2887 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 467:
#line 2893 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 468:
#line 2896 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 469:
#line 2904 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 470:
#line 2908 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 471:
#line 2911 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 472:
#line 2917 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 473:
#line 2927 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 474:
#line 2932 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 475:
#line 2939 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 476:
#line 2942 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 477:
#line 2945 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 478:
#line 2950 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 479:
#line 2957 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 480:
#line 2962 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 481:
#line 2967 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 482:
#line 2972 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 483:
#line 2983 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 484:
#line 2991 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 485:
#line 2999 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 486:
#line 3004 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 487:
#line 3008 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 488:
#line 3013 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 489:
#line 3017 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 490:
#line 3021 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 491:
#line 3027 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 492:
#line 3030 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 493:
#line 3034 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 494:
#line 3038 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 495:
#line 3042 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 496:
#line 3046 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 497:
#line 3050 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 498:
#line 3057 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 499:
#line 3067 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 500:
#line 3072 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 501:
#line 3078 "fgl.yacc"
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
#line 3088 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 503:
#line 3093 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 504:
#line 3096 "fgl.yacc"
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
#line 3107 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 506:
#line 3112 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 507:
#line 3115 "fgl.yacc"
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
#line 3133 "fgl.yacc"
    {chk4var=1;}
    break;

  case 509:
#line 3133 "fgl.yacc"
    {chk4var=0;}
    break;

  case 510:
#line 3133 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 511:
#line 3136 "fgl.yacc"
    {chk4var=1;}
    break;

  case 512:
#line 3136 "fgl.yacc"
    {chk4var=0;}
    break;

  case 513:
#line 3136 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 514:
#line 3140 "fgl.yacc"
    {chk4var=1;}
    break;

  case 515:
#line 3140 "fgl.yacc"
    {chk4var=0;}
    break;

  case 516:
#line 3140 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 517:
#line 3144 "fgl.yacc"
    {chk4var=1;}
    break;

  case 518:
#line 3144 "fgl.yacc"
    {chk4var=0;}
    break;

  case 519:
#line 3144 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 520:
#line 3148 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3154 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3160 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3166 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3174 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3180 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 526:
#line 3188 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 527:
#line 3194 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 528:
#line 3203 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 529:
#line 3209 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 530:
#line 3216 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 531:
#line 3223 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 532:
#line 3232 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 533:
#line 3238 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 534:
#line 3244 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 535:
#line 3251 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 536:
#line 3257 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 537:
#line 3263 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 538:
#line 3269 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 539:
#line 3277 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 540:
#line 3283 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 541:
#line 3289 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 542:
#line 3298 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 543:
#line 3304 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 544:
#line 3310 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 545:
#line 3320 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 546:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 549:
#line 3329 "fgl.yacc"
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
#line 3340 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 551:
#line 3341 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 552:
#line 3347 "fgl.yacc"
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
#line 3358 "fgl.yacc"
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
#line 3368 "fgl.yacc"
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
#line 3381 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 558:
#line 3386 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 559:
#line 3393 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 560:
#line 3397 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 561:
#line 3400 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 562:
#line 3403 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 563:
#line 3409 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 564:
#line 3412 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 565:
#line 3415 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 566:
#line 3432 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 567:
#line 3435 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 568:
#line 3441 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 569:
#line 3442 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 570:
#line 3443 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 572:
#line 3448 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 573:
#line 3449 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 574:
#line 3450 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 575:
#line 3451 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 576:
#line 3453 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 577:
#line 3454 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 578:
#line 3455 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 579:
#line 3457 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 580:
#line 3458 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 581:
#line 3459 "fgl.yacc"
    {sprintf(yyval.str,"0.%s",yyvsp[0].str);}
    break;

  case 583:
#line 3465 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 584:
#line 3469 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 585:
#line 3473 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 586:
#line 3478 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 587:
#line 3482 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 588:
#line 3497 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 589:
#line 3501 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 590:
#line 3507 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 591:
#line 3511 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 592:
#line 3520 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 593:
#line 3521 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 594:
#line 3533 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 595:
#line 3539 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 596:
#line 3547 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 603:
#line 3564 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 604:
#line 3566 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 605:
#line 3569 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 606:
#line 3571 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 611:
#line 3585 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 612:
#line 3587 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 613:
#line 3590 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 614:
#line 3592 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 627:
#line 3623 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 628:
#line 3625 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 629:
#line 3628 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 630:
#line 3630 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 631:
#line 3633 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 632:
#line 3635 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 633:
#line 3638 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 634:
#line 3640 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 635:
#line 3643 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 636:
#line 3645 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 637:
#line 3659 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 638:
#line 3663 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 639:
#line 3664 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 640:
#line 3671 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 642:
#line 3689 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 643:
#line 3705 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 644:
#line 3706 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 645:
#line 3707 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 646:
#line 3708 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 647:
#line 3709 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 648:
#line 3710 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 649:
#line 3711 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 653:
#line 3719 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 655:
#line 3725 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 656:
#line 3728 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 657:
#line 3733 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 658:
#line 3738 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 659:
#line 3741 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 660:
#line 3746 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 661:
#line 3751 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 662:
#line 3756 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 663:
#line 3763 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 664:
#line 3764 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 665:
#line 3771 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 666:
#line 3778 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 667:
#line 3780 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 668:
#line 3786 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 669:
#line 3791 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 670:
#line 3796 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 671:
#line 3801 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 672:
#line 3801 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 673:
#line 3804 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 674:
#line 3810 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 675:
#line 3815 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 676:
#line 3819 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 679:
#line 3827 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 680:
#line 3830 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 681:
#line 3833 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 682:
#line 3838 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 683:
#line 3843 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 684:
#line 3848 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 685:
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

  case 687:
#line 3866 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 688:
#line 3928 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 690:
#line 3937 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 691:
#line 3946 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 693:
#line 3953 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 694:
#line 3956 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 695:
#line 3962 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 696:
#line 3968 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 697:
#line 3972 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 698:
#line 3976 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 699:
#line 3982 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 700:
#line 3986 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 701:
#line 3990 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 702:
#line 3995 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 703:
#line 4000 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 722:
#line 4041 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 723:
#line 4048 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 724:
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

  case 726:
#line 4069 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 728:
#line 4072 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 729:
#line 4074 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 730:
#line 4077 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 731:
#line 4081 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 732:
#line 4084 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 733:
#line 4091 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 734:
#line 4096 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 735:
#line 4107 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 736:
#line 4108 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 737:
#line 4111 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 739:
#line 4117 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 740:
#line 4121 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 741:
#line 4122 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 742:
#line 4126 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 746:
#line 4141 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 747:
#line 4143 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 750:
#line 4152 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 751:
#line 4155 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 752:
#line 4159 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 753:
#line 4162 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 754:
#line 4165 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 755:
#line 4168 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 756:
#line 4171 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 757:
#line 4175 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 758:
#line 4178 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 759:
#line 4181 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 760:
#line 4184 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 761:
#line 4187 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 762:
#line 4190 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 763:
#line 4193 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 764:
#line 4196 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 765:
#line 4199 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 766:
#line 4200 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 767:
#line 4200 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 768:
#line 4201 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 769:
#line 4201 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 770:
#line 4202 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 771:
#line 4202 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 772:
#line 4203 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 773:
#line 4206 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 774:
#line 4207 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 775:
#line 4210 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 776:
#line 4218 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 777:
#line 4222 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 778:
#line 4228 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 779:
#line 4232 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 780:
#line 4237 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 781:
#line 4242 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 782:
#line 4247 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 783:
#line 4248 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 784:
#line 4249 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 785:
#line 4253 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 786:
#line 4257 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 787:
#line 4266 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 788:
#line 4271 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 789:
#line 4275 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 790:
#line 4282 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 791:
#line 4291 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 792:
#line 4297 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 793:
#line 4298 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 794:
#line 4299 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 795:
#line 4300 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 796:
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

  case 797:
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

  case 798:
#line 4325 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 800:
#line 4328 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 801:
#line 4335 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 802:
#line 4336 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 803:
#line 4337 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 804:
#line 4338 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 805:
#line 4339 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 806:
#line 4340 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 807:
#line 4341 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 808:
#line 4342 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 809:
#line 4343 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 810:
#line 4348 "fgl.yacc"
    {iskey=1;}
    break;

  case 811:
#line 4348 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 812:
#line 4350 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 813:
#line 4353 "fgl.yacc"
    {iskey=1;}
    break;

  case 814:
#line 4353 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 815:
#line 4355 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 816:
#line 4359 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 817:
#line 4362 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 818:
#line 4363 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 820:
#line 4366 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 826:
#line 4378 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 827:
#line 4379 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 828:
#line 4380 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 829:
#line 4381 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 830:
#line 4382 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 831:
#line 4383 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 832:
#line 4384 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 833:
#line 4385 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 834:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 835:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 836:
#line 4388 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 837:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 838:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 839:
#line 4391 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 840:
#line 4395 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 841:
#line 4413 "fgl.yacc"
    {chk4var=1;}
    break;

  case 842:
#line 4413 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 843:
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

  case 844:
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

  case 846:
#line 4458 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 847:
#line 4464 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 848:
#line 4470 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 849:
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

  case 850:
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

  case 854:
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

  case 857:
#line 4536 "fgl.yacc"
    {
	}
    break;

  case 867:
#line 4562 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 871:
#line 4570 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 885:
#line 4594 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 886:
#line 4595 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 887:
#line 4603 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 888:
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

  case 889:
#line 4625 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 890:
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

  case 892:
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

  case 893:
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

  case 894:
#line 4670 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 895:
#line 4677 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 896:
#line 4684 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 897:
#line 4690 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 898:
#line 4690 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 899:
#line 4695 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 900:
#line 4701 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 901:
#line 4709 "fgl.yacc"
    {
}
    break;

  case 905:
#line 4721 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 907:
#line 4729 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 908:
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

  case 911:
#line 4755 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 912:
#line 4761 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 913:
#line 4765 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 916:
#line 4777 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 917:
#line 4780 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 918:
#line 4784 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 919:
#line 4787 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 920:
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

  case 921:
#line 4807 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 922:
#line 4813 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 923:
#line 4824 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 924:
#line 4828 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 925:
#line 4835 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 926:
#line 4842 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 927:
#line 4848 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 928:
#line 4853 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 931:
#line 4860 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 932:
#line 4861 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 933:
#line 4863 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 934:
#line 4864 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 935:
#line 4867 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 936:
#line 4868 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 937:
#line 4869 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 938:
#line 4871 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 939:
#line 4876 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 940:
#line 4881 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 941:
#line 4888 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 945:
#line 4895 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 946:
#line 4897 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 947:
#line 4899 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 949:
#line 4909 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 950:
#line 4912 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 951:
#line 4915 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 958:
#line 4931 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 959:
#line 4936 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 960:
#line 4936 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 961:
#line 4939 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 962:
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

  case 964:
#line 5024 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 966:
#line 5031 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 967:
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

  case 968:
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

  case 972:
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

  case 973:
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

  case 978:
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

  case 979:
#line 5228 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 980:
#line 5233 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 981:
#line 5241 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 982:
#line 5246 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 983:
#line 5254 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 984:
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

  case 985:
#line 5292 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 986:
#line 5295 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 987:
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

  case 988:
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

  case 993:
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

  case 994:
#line 5443 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 996:
#line 5452 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 997:
#line 5457 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 998:
#line 5468 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 999:
#line 5475 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1001:
#line 5483 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1002:
#line 5486 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 1003:
#line 5487 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1005:
#line 5489 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1006:
#line 5490 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1007:
#line 5493 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 1008:
#line 5496 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1009:
#line 5502 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 1010:
#line 5505 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1011:
#line 5509 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 1012:
#line 5514 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1013:
#line 5522 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 1014:
#line 5527 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 1015:
#line 5534 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1016:
#line 5536 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1021:
#line 5564 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1022:
#line 5571 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1023:
#line 5578 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1024:
#line 5581 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1025:
#line 5595 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1030:
#line 5612 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1031:
#line 5617 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1032:
#line 5623 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1034:
#line 5630 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1035:
#line 5635 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1036:
#line 5638 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1037:
#line 5639 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1038:
#line 5642 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1039:
#line 5643 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1040:
#line 5646 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1041:
#line 5647 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1042:
#line 5652 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1043:
#line 5659 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1044:
#line 5662 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1045:
#line 5668 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1046:
#line 5670 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1047:
#line 5672 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1048:
#line 5674 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1049:
#line 5677 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1050:
#line 5677 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1051:
#line 5678 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1052:
#line 5683 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1053:
#line 5691 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1054:
#line 5692 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1055:
#line 5697 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1056:
#line 5699 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1057:
#line 5701 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1061:
#line 5719 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1062:
#line 5720 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1063:
#line 5721 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1064:
#line 5722 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1065:
#line 5723 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1066:
#line 5724 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1067:
#line 5725 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1068:
#line 5726 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1069:
#line 5727 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1070:
#line 5728 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1071:
#line 5729 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1072:
#line 5730 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1073:
#line 5731 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1074:
#line 5732 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1075:
#line 5733 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1076:
#line 5734 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1077:
#line 5735 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1078:
#line 5736 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1079:
#line 5737 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1080:
#line 5738 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1081:
#line 5739 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1082:
#line 5740 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1083:
#line 5741 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1084:
#line 5742 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1085:
#line 5743 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1086:
#line 5744 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1087:
#line 5745 "fgl.yacc"
    { print_options('r',yyvsp[0].str); }
    break;

  case 1088:
#line 5746 "fgl.yacc"
    { print_options('|',yyvsp[0].str); }
    break;

  case 1089:
#line 5750 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1090:
#line 5751 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1091:
#line 5755 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1092:
#line 5756 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1093:
#line 5771 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1096:
#line 5780 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1097:
#line 5784 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1098:
#line 5788 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1099:
#line 5792 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1100:
#line 5796 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1102:
#line 5816 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1103:
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

  case 1104:
#line 5834 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1105:
#line 5835 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1106:
#line 5839 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1107:
#line 5844 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1108:
#line 5845 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1109:
#line 5849 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1113:
#line 5855 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1114:
#line 5858 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1116:
#line 5873 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1117:
#line 5877 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1118:
#line 5883 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1119:
#line 5884 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1120:
#line 5889 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1121:
#line 5890 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1122:
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

  case 1124:
#line 5920 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1125:
#line 5924 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1126:
#line 5928 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1127:
#line 5932 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1128:
#line 5939 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1129:
#line 5940 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1135:
#line 5952 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1136:
#line 5958 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1137:
#line 5966 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1138:
#line 5972 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1139:
#line 5974 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1143:
#line 5984 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1144:
#line 5984 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1145:
#line 5989 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1146:
#line 5993 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1147:
#line 5998 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1148:
#line 5998 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1149:
#line 6002 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1150:
#line 6002 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1151:
#line 6003 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1152:
#line 6003 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1153:
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

  case 1154:
#line 6017 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1155:
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

  case 1156:
#line 6034 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1163:
#line 6046 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1164:
#line 6046 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1165:
#line 6052 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1166:
#line 6052 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1167:
#line 6055 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1168:
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

  case 1169:
#line 6071 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1170:
#line 6072 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1171:
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

  case 1172:
#line 6082 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1173:
#line 6094 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1179:
#line 6105 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1180:
#line 6110 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1181:
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

  case 1183:
#line 6134 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1184:
#line 6140 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1185:
#line 6145 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1186:
#line 6151 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1187:
#line 6152 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1188:
#line 6153 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1189:
#line 6157 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1190:
#line 6158 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1191:
#line 6159 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1192:
#line 6160 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1193:
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

  case 1194:
#line 6174 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1195:
#line 6176 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1196:
#line 6181 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1197:
#line 6184 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1198:
#line 6189 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1199:
#line 6196 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1200:
#line 6203 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1201:
#line 6210 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1202:
#line 6219 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1203:
#line 6226 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1204:
#line 6233 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1205:
#line 6240 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1206:
#line 6247 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1211:
#line 6260 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1212:
#line 6261 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1213:
#line 6262 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1214:
#line 6263 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1215:
#line 6264 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1216:
#line 6265 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1217:
#line 6266 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1218:
#line 6267 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1219:
#line 6268 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1220:
#line 6269 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1223:
#line 6275 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1224:
#line 6276 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1225:
#line 6277 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1226:
#line 6278 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1231:
#line 6287 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1232:
#line 6288 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1233:
#line 6289 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1234:
#line 6290 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1235:
#line 6291 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1236:
#line 6292 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1237:
#line 6293 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1238:
#line 6294 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1239:
#line 6296 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1240:
#line 6297 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1241:
#line 6298 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1242:
#line 6299 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1243:
#line 6301 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1244:
#line 6302 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1245:
#line 6303 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1246:
#line 6304 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1250:
#line 6309 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1251:
#line 6310 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1255:
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

  case 1256:
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

  case 1257:
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

  case 1258:
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

  case 1259:
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

  case 1260:
#line 6370 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1261:
#line 6374 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1262:
#line 6378 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1263:
#line 6384 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1264:
#line 6389 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1265:
#line 6397 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1266:
#line 6400 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1267:
#line 6409 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1268:
#line 6420 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1270:
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

  case 1271:
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

  case 1272:
#line 6447 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1273:
#line 6450 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1274:
#line 6454 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1275:
#line 6462 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1276:
#line 6465 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1277:
#line 6471 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1278:
#line 6475 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1279:
#line 6479 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1280:
#line 6483 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1281:
#line 6487 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1282:
#line 6493 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1283:
#line 6494 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1284:
#line 6495 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1285:
#line 6496 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1286:
#line 6501 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1287:
#line 6502 "fgl.yacc"
    { print_system_run(yyvsp[0].integer_val,0); }
    break;

  case 1288:
#line 6503 "fgl.yacc"
    { print_system_run(1,yyvsp[0].str); }
    break;

  case 1289:
#line 6504 "fgl.yacc"
    { print_system_run(2,0); }
    break;

  case 1290:
#line 6505 "fgl.yacc"
    { print_system_run(1+yyvsp[-2].integer_val,yyvsp[0].str); }
    break;

  case 1291:
#line 6506 "fgl.yacc"
    { print_system_run(2+yyvsp[-1].integer_val,0); }
    break;

  case 1292:
#line 6507 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1293:
#line 6508 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1294:
#line 6512 "fgl.yacc"
    {yyval.integer_val=512;}
    break;

  case 1295:
#line 6513 "fgl.yacc"
    {yyval.integer_val=256;}
    break;

  case 1296:
#line 6516 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1297:
#line 6521 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1298:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 6529 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1301:
#line 6535 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1302:
#line 6536 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1303:
#line 6542 "fgl.yacc"
    {insql=1;}
    break;

  case 1304:
#line 6542 "fgl.yacc"
    {insql=0;}
    break;

  case 1305:
#line 6542 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1306:
#line 6547 "fgl.yacc"
    {insql=1;}
    break;

  case 1307:
#line 6547 "fgl.yacc"
    {insql=0;}
    break;

  case 1308:
#line 6547 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1309:
#line 6555 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1310:
#line 6556 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1312:
#line 6561 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1313:
#line 6566 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1314:
#line 6567 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1315:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1316:
#line 6569 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1317:
#line 6570 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1319:
#line 6575 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1320:
#line 6575 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1322:
#line 6579 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1323:
#line 6583 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1324:
#line 6584 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1325:
#line 6587 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1326:
#line 6588 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1327:
#line 6591 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1328:
#line 6594 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1329:
#line 6597 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1330:
#line 6603 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1331:
#line 6605 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1333:
#line 6618 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1334:
#line 6622 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1335:
#line 6623 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1337:
#line 6628 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1338:
#line 6631 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1339:
#line 6637 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1340:
#line 6640 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1341:
#line 6648 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1343:
#line 6655 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1344:
#line 6659 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1345:
#line 6663 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1346:
#line 6669 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1347:
#line 6672 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1348:
#line 6681 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1349:
#line 6684 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1350:
#line 6687 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1351:
#line 6690 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1352:
#line 6693 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1353:
#line 6696 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1354:
#line 6699 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1355:
#line 6706 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1356:
#line 6709 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1357:
#line 6716 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1358:
#line 6719 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1359:
#line 6725 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1360:
#line 6728 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1361:
#line 6735 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1362:
#line 6738 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1364:
#line 6746 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1366:
#line 6755 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1367:
#line 6758 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1368:
#line 6764 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1369:
#line 6767 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1370:
#line 6773 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1371:
#line 6780 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1372:
#line 6781 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1373:
#line 6785 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1374:
#line 6795 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1375:
#line 6798 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1376:
#line 6804 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1377:
#line 6806 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1378:
#line 6811 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1379:
#line 6812 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6817 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1381:
#line 6818 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1382:
#line 6824 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1383:
#line 6825 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6852 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6858 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1394:
#line 6861 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1395:
#line 6864 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1396:
#line 6870 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1398:
#line 6876 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1400:
#line 6887 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1401:
#line 6901 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1402:
#line 6910 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1403:
#line 6910 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1404:
#line 6915 "fgl.yacc"
    {insql=1;}
    break;

  case 1405:
#line 6915 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1406:
#line 6920 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1407:
#line 6923 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1408:
#line 6925 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6932 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6936 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1412:
#line 6940 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1413:
#line 6947 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1414:
#line 6950 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1415:
#line 6957 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1416:
#line 6961 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1417:
#line 6967 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1418:
#line 6972 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1419:
#line 6976 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1420:
#line 6982 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1421:
#line 6985 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1422:
#line 6991 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1423:
#line 6998 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1424:
#line 7002 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1425:
#line 7007 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1426:
#line 7017 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1427:
#line 7020 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1428:
#line 7022 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1429:
#line 7024 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1430:
#line 7026 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1431:
#line 7028 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1432:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_RELATIVE);}
    break;

  case 1433:
#line 7032 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_ABSOLUTE);}
    break;

  case 1434:
#line 7038 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1435:
#line 7048 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1436:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7061 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 7064 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7071 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1445:
#line 7076 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1446:
#line 7081 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1447:
#line 7088 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1448:
#line 7089 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1449:
#line 7097 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1450:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1451:
#line 7109 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1452:
#line 7110 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1453:
#line 7113 "fgl.yacc"
    {insql=1;}
    break;

  case 1454:
#line 7113 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1455:
#line 7118 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1456:
#line 7123 "fgl.yacc"
    {
			print_exec_sql(convstrsql(yyvsp[0].str));
			printf("Warning: Informix specific SQL @ line %d\n",yylineno);
			strcpy(yyval.str,"InfxSpecificSql");
	}
    break;

  case 1457:
#line 7128 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1459:
#line 7134 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1461:
#line 7138 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1462:
#line 7143 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1463:
#line 7148 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1464:
#line 7152 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1466:
#line 7158 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1467:
#line 7162 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1468:
#line 7169 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7170 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7171 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 7172 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1475:
#line 7182 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1476:
#line 7183 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1477:
#line 7184 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 7188 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1479:
#line 7189 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1482:
#line 7196 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7199 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1486:
#line 7202 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7207 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1490:
#line 7209 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 7215 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 7221 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7231 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1498:
#line 7236 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1499:
#line 7238 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 7244 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7247 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1504:
#line 7253 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1505:
#line 7261 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1506:
#line 7266 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 7276 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7282 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7287 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1513:
#line 7290 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1514:
#line 7295 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7301 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 7306 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1518:
#line 7309 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1519:
#line 7312 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1520:
#line 7319 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1521:
#line 7320 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1522:
#line 7321 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1523:
#line 7323 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1524:
#line 7336 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1525:
#line 7341 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1527:
#line 7345 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1528:
#line 7347 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1529:
#line 7354 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1530:
#line 7357 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1531:
#line 7363 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1532:
#line 7371 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1533:
#line 7375 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1534:
#line 7379 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1535:
#line 7383 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1536:
#line 7388 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1537:
#line 7391 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1538:
#line 7394 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1539:
#line 7402 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1540:
#line 7409 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1543:
#line 7418 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1544:
#line 7424 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1545:
#line 7427 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1546:
#line 7438 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1547:
#line 7445 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1548:
#line 7451 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1549:
#line 7454 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1550:
#line 7461 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1551:
#line 7468 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1553:
#line 7475 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1554:
#line 7481 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1555:
#line 7482 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1556:
#line 7483 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1558:
#line 7487 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1559:
#line 7494 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1561:
#line 7501 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1562:
#line 7508 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1563:
#line 7513 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1564:
#line 7514 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1565:
#line 7517 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1566:
#line 7520 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1567:
#line 7525 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1568:
#line 7526 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1569:
#line 7531 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1570:
#line 7534 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1571:
#line 7540 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1572:
#line 7543 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1573:
#line 7549 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1574:
#line 7552 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1575:
#line 7558 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1576:
#line 7561 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1577:
#line 7568 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1578:
#line 7569 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1579:
#line 7598 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1580:
#line 7599 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1581:
#line 7603 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1583:
#line 7616 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1584:
#line 7619 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1585:
#line 7622 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1586:
#line 7625 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1588:
#line 7633 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1589:
#line 7636 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1591:
#line 7642 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1593:
#line 7648 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1594:
#line 7651 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1595:
#line 7654 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1596:
#line 7657 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
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
#line 7666 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1600:
#line 7669 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1601:
#line 7674 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1603:
#line 7681 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1607:
#line 7687 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1608:
#line 7688 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1609:
#line 7693 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7696 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1611:
#line 7700 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1612:
#line 7706 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1613:
#line 7707 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1614:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1615:
#line 7709 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1620:
#line 7729 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1622:
#line 7733 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1623:
#line 7734 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1625:
#line 7737 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1626:
#line 7738 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1627:
#line 7747 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1634:
#line 7761 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1635:
#line 7763 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1636:
#line 7765 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1638:
#line 7768 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1640:
#line 7771 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1644:
#line 7776 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1645:
#line 7778 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1646:
#line 7781 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1647:
#line 7782 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1648:
#line 7789 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1652:
#line 7794 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1656:
#line 7810 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1657:
#line 7817 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1658:
#line 7821 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1659:
#line 7822 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1660:
#line 7823 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1661:
#line 7831 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1662:
#line 7832 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1663:
#line 7833 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1664:
#line 7844 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1665:
#line 7851 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1666:
#line 7856 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1667:
#line 7857 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1668:
#line 7858 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1669:
#line 7866 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1670:
#line 7867 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1671:
#line 7868 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1673:
#line 7894 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1674:
#line 7895 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1675:
#line 7896 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1676:
#line 7900 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1677:
#line 7903 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1678:
#line 7909 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1679:
#line 7914 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1680:
#line 7919 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1682:
#line 7930 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1686:
#line 7948 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1687:
#line 7951 "fgl.yacc"
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

  case 1688:
#line 7964 "fgl.yacc"
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

  case 1689:
#line 7979 "fgl.yacc"
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

  case 1690:
#line 7991 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1691:
#line 7993 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1692:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1693:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1694:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1695:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1696:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1697:
#line 7996 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1698:
#line 7997 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1699:
#line 8000 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1714:
#line 8018 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1715:
#line 8021 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1716:
#line 8022 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1717:
#line 8023 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1718:
#line 8027 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1719:
#line 8035 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1720:
#line 8035 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1721:
#line 8041 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1722:
#line 8041 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
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
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1725:
#line 8054 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1726:
#line 8054 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1727:
#line 8062 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1728:
#line 8063 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1729:
#line 8064 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1730:
#line 8067 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1731:
#line 8067 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1733:
#line 8071 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1734:
#line 8072 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1735:
#line 8083 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1736:
#line 8086 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1737:
#line 8092 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1738:
#line 8097 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1739:
#line 8105 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1740:
#line 8117 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1741:
#line 8118 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1742:
#line 8121 "fgl.yacc"
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

  case 1743:
#line 8136 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1744:
#line 8147 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1745:
#line 8150 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1746:
#line 8158 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1747:
#line 8167 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1748:
#line 8170 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1749:
#line 8174 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1750:
#line 8177 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1751:
#line 8178 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1753:
#line 8191 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1754:
#line 8192 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1755:
#line 8201 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1756:
#line 8210 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1757:
#line 8215 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1758:
#line 8216 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1759:
#line 8217 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1760:
#line 8218 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1761:
#line 8225 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1762:
#line 8228 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1763:
#line 8234 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1764:
#line 8237 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1765:
#line 8244 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1766:
#line 8256 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1767:
#line 8265 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1768:
#line 8268 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1769:
#line 8271 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1770:
#line 8277 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1771:
#line 8285 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1772:
#line 8288 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1773:
#line 8289 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1774:
#line 8290 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1775:
#line 8291 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1776:
#line 8292 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1777:
#line 8295 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1778:
#line 8302 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1779:
#line 8304 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1780:
#line 8306 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1781:
#line 8308 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1782:
#line 8310 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1783:
#line 8311 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1784:
#line 8312 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1785:
#line 8313 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1786:
#line 8314 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1787:
#line 8315 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1788:
#line 8316 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1789:
#line 8318 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1790:
#line 8320 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1791:
#line 8322 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1792:
#line 8324 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1793:
#line 8326 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1794:
#line 8328 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1795:
#line 8330 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1796:
#line 8331 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1797:
#line 8333 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1798:
#line 8334 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1799:
#line 8335 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1800:
#line 8341 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1801:
#line 8342 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1803:
#line 8352 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1804:
#line 8360 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1805:
#line 8364 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1806:
#line 8371 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1807:
#line 8371 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1809:
#line 8375 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1810:
#line 8380 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1811:
#line 8380 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1813:
#line 8384 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1814:
#line 8388 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1817:
#line 8397 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1818:
#line 8397 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1823:
#line 8416 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1824:
#line 8417 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1827:
#line 8425 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1828:
#line 8431 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1831:
#line 8450 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1832:
#line 8451 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1833:
#line 8452 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1834:
#line 8453 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1835:
#line 8454 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1836:
#line 8455 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1837:
#line 8459 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1838:
#line 8460 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1839:
#line 8461 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1841:
#line 8466 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1842:
#line 8467 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1843:
#line 8471 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1844:
#line 8487 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1845:
#line 8488 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1846:
#line 8489 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1847:
#line 8493 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1848:
#line 8507 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1849:
#line 8511 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1851:
#line 8520 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1853:
#line 8525 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1854:
#line 8526 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1855:
#line 8850 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1856:
#line 8850 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1857:
#line 8857 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1858:
#line 8857 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1859:
#line 8945 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1860:
#line 8949 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1861:
#line 8951 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1862:
#line 8958 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1863:
#line 8962 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1864:
#line 8968 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1865:
#line 8976 "fgl.yacc"
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

  case 1866:
#line 8986 "fgl.yacc"
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

  case 1867:
#line 8996 "fgl.yacc"
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
#line 9008 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1869:
#line 9011 "fgl.yacc"
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

  case 1870:
#line 9030 "fgl.yacc"
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
#line 9056 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1872:
#line 9059 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1874:
#line 9068 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1875:
#line 9073 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1876:
#line 9076 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1877:
#line 9084 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1878:
#line 9092 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1879:
#line 9105 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1880:
#line 9108 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1881:
#line 9116 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1882:
#line 9119 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1883:
#line 9122 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1884:
#line 9130 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1885:
#line 9134 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1886:
#line 9135 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1887:
#line 9136 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1888:
#line 9137 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1889:
#line 9138 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1890:
#line 9139 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1891:
#line 9140 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1892:
#line 9141 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1893:
#line 9145 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1894:
#line 9146 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1895:
#line 9147 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1896:
#line 9148 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1897:
#line 9149 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1898:
#line 9155 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1899:
#line 9156 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1900:
#line 9157 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1901:
#line 9158 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1902:
#line 9159 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1903:
#line 9160 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1904:
#line 9161 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1905:
#line 9162 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1906:
#line 9163 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1907:
#line 9164 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1908:
#line 9165 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1909:
#line 9166 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1910:
#line 9167 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1911:
#line 9168 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1912:
#line 9169 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1913:
#line 9170 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1914:
#line 9175 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1915:
#line 9181 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1916:
#line 9182 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1917:
#line 9190 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1918:
#line 9192 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1920:
#line 9198 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1921:
#line 9202 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1922:
#line 9206 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1923:
#line 9222 "fgl.yacc"
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

  case 1924:
#line 9236 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1925:
#line 9242 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1926:
#line 9244 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1930:
#line 9258 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1931:
#line 9261 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1932:
#line 9268 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1933:
#line 9271 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1934:
#line 9301 "fgl.yacc"
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

  case 1935:
#line 9326 "fgl.yacc"
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

  case 1936:
#line 9381 "fgl.yacc"
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

  case 1937:
#line 9416 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1938:
#line 9425 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1939:
#line 9436 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1940:
#line 9439 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1941:
#line 9445 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1942:
#line 9458 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1943:
#line 9472 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1944:
#line 9475 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1945:
#line 9479 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1946:
#line 9494 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1947:
#line 9494 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1948:
#line 9500 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1949:
#line 9501 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1950:
#line 9504 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1951:
#line 9505 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1952:
#line 9506 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1953:
#line 9507 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1954:
#line 9508 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1955:
#line 9509 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1956:
#line 9510 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1957:
#line 9521 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1958:
#line 9525 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1959:
#line 9529 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1960:
#line 9533 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1961:
#line 9538 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1962:
#line 9542 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1963:
#line 9547 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1965:
#line 9555 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1967:
#line 9561 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1968:
#line 9567 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1969:
#line 9571 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1974:
#line 9589 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1975:
#line 9596 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1976:
#line 9606 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1977:
#line 9606 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18967 "y.tab.c"

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


#line 1010 "fgl.yacc"

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



